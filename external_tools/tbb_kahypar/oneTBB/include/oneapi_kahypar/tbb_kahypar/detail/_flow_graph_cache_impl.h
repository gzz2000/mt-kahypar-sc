/*
    Copyright (c) 2005-2024 Intel Corporation

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef __TBB__flow_graph_cache_impl_H
#define __TBB__flow_graph_cache_impl_H

#ifndef __TBB_flow_graph_H
#error Do not #include this internal file directly; use public TBB headers instead.
#endif

// included in namespace tbb_kahypar::detail::d2 (in flow_graph.h)

//! A node_cache maintains a std::queue of elements of type T.  Each operation is protected by a lock.
template< typename T, typename M=spin_mutex >
class node_cache {
    public:

    typedef size_t size_type;

    bool empty() {
        typename mutex_type::scoped_lock lock( my_mutex );
        return internal_empty();
    }

    void add( T &n ) {
        typename mutex_type::scoped_lock lock( my_mutex );
        internal_push(n);
    }

    void remove( T &n ) {
        typename mutex_type::scoped_lock lock( my_mutex );
        for ( size_t i = internal_size(); i != 0; --i ) {
            T &s = internal_pop();
            if ( &s == &n )
                break;  // only remove one predecessor per request
            internal_push(s);
        }
    }

    void clear() {
        while( !my_q.empty()) (void)my_q.pop();
    }

protected:

    typedef M mutex_type;
    mutex_type my_mutex;
    std::queue< T * > my_q;

    // Assumes lock is held
    inline bool internal_empty( )  {
        return my_q.empty();
    }

    // Assumes lock is held
    inline size_type internal_size( )  {
        return my_q.size();
    }

    // Assumes lock is held
    inline void internal_push( T &n )  {
        my_q.push(&n);
    }

    // Assumes lock is held
    inline T &internal_pop() {
        T *v = my_q.front();
        my_q.pop();
        return *v;
    }

};

//! A cache of predecessors that only supports try_get
template< typename T, typename M=spin_mutex >
class predecessor_cache : public node_cache< sender<T>, M > {
public:
    typedef M mutex_type;
    typedef T output_type;
    typedef sender<output_type> predecessor_type;
    typedef receiver<output_type> successor_type;

    predecessor_cache( successor_type* owner ) : my_owner( owner ) {
        __TBB_ASSERT( my_owner, "predecessor_cache should have an owner." );
        // Do not work with the passed pointer here as it may not be fully initialized yet
    }

private:
    bool get_item_impl( output_type& v
                        __TBB_FLOW_GRAPH_METAINFO_ARG(message_metainfo* metainfo_ptr = nullptr) )
    {

        bool successful_get = false;

        do {
            predecessor_type *src;
            {
                typename mutex_type::scoped_lock lock(this->my_mutex);
                if ( this->internal_empty() ) {
                    break;
                }
                src = &this->internal_pop();
            }

            // Try to get from this sender
#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
            if (metainfo_ptr) {
                successful_get = src->try_get( v, *metainfo_ptr );
            } else
#endif
            {
                successful_get = src->try_get( v );
            }

            if (successful_get == false) {
                // Relinquish ownership of the edge
                register_successor(*src, *my_owner);
            } else {
                // Retain ownership of the edge
                this->add(*src);
            }
        } while ( successful_get == false );
        return successful_get;
    }
public:
    bool get_item( output_type& v ) {
        return get_item_impl(v);
    }

#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
    bool get_item( output_type& v, message_metainfo& metainfo ) {
        return get_item_impl(v, &metainfo);
    }
#endif

    // If we are removing arcs (rf_clear_edges), call clear() rather than reset().
    void reset() {
        for(;;) {
            predecessor_type *src;
            {
                if (this->internal_empty()) break;
                src = &this->internal_pop();
            }
            register_successor(*src, *my_owner);
        }
    }

protected:
    successor_type* my_owner;
};

//! An cache of predecessors that supports requests and reservations
template< typename T, typename M=spin_mutex >
class reservable_predecessor_cache : public predecessor_cache< T, M > {
public:
    typedef M mutex_type;
    typedef T output_type;
    typedef sender<T> predecessor_type;
    typedef receiver<T> successor_type;

    reservable_predecessor_cache( successor_type* owner )
        : predecessor_cache<T,M>(owner), reserved_src(nullptr)
    {
        // Do not work with the passed pointer here as it may not be fully initialized yet
    }

private:
    bool try_reserve_impl( output_type &v __TBB_FLOW_GRAPH_METAINFO_ARG(message_metainfo* metainfo) ) {
        bool successful_reserve = false;

        do {
            predecessor_type* pred = nullptr;
            {
                typename mutex_type::scoped_lock lock(this->my_mutex);
                if ( reserved_src.load(std::memory_order_relaxed) || this->internal_empty() )
                    return false;

                pred = &this->internal_pop();
                reserved_src.store(pred, std::memory_order_relaxed);
            }

            // Try to get from this sender
#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
            if (metainfo) {
                successful_reserve = pred->try_reserve( v, *metainfo );
            } else
#endif
            {
                successful_reserve = pred->try_reserve( v );
            }

            if (successful_reserve == false) {
                typename mutex_type::scoped_lock lock(this->my_mutex);
                // Relinquish ownership of the edge
                register_successor( *pred, *this->my_owner );
                reserved_src.store(nullptr, std::memory_order_relaxed);
            } else {
                // Retain ownership of the edge
                this->add( *pred);
            }
        } while ( successful_reserve == false );

        return successful_reserve;
    }
public:
    bool try_reserve( output_type& v ) {
        return try_reserve_impl(v __TBB_FLOW_GRAPH_METAINFO_ARG(nullptr));
    }

#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
    bool try_reserve( output_type& v, message_metainfo& metainfo ) {
        return try_reserve_impl(v, &metainfo);
    }
#endif

    bool try_release() {
        reserved_src.load(std::memory_order_relaxed)->try_release();
        reserved_src.store(nullptr, std::memory_order_relaxed);
        return true;
    }

    bool try_consume() {
        reserved_src.load(std::memory_order_relaxed)->try_consume();
        reserved_src.store(nullptr, std::memory_order_relaxed);
        return true;
    }

    void reset() {
        reserved_src.store(nullptr, std::memory_order_relaxed);
        predecessor_cache<T, M>::reset();
    }

    void clear() {
        reserved_src.store(nullptr, std::memory_order_relaxed);
        predecessor_cache<T, M>::clear();
    }

private:
    std::atomic<predecessor_type*> reserved_src;
};


//! An abstract cache of successors
template<typename T, typename M=spin_rw_mutex >
class successor_cache : no_copy {
protected:

    typedef M mutex_type;
    mutex_type my_mutex;

    typedef receiver<T> successor_type;
    typedef receiver<T>* pointer_type;
    typedef sender<T> owner_type;
    // TODO revamp: introduce heapified collection of successors for strict priorities
    typedef std::list< pointer_type > successors_type;
    successors_type my_successors;

    owner_type* my_owner;

public:
    successor_cache( owner_type* owner ) : my_owner(owner) {
        // Do not work with the passed pointer here as it may not be fully initialized yet
    }

    virtual ~successor_cache() {}

    void register_successor( successor_type& r ) {
        typename mutex_type::scoped_lock l(my_mutex, true);
        if( r.priority() != no_priority )
            my_successors.push_front( &r );
        else
            my_successors.push_back( &r );
    }

    void remove_successor( successor_type& r ) {
        typename mutex_type::scoped_lock l(my_mutex, true);
        for ( typename successors_type::iterator i = my_successors.begin();
              i != my_successors.end(); ++i ) {
            if ( *i == & r ) {
                my_successors.erase(i);
                break;
            }
        }
    }

    bool empty() {
        typename mutex_type::scoped_lock l(my_mutex, false);
        return my_successors.empty();
    }

    void clear() {
        my_successors.clear();
    }

    virtual graph_task* try_put_task( const T& t ) = 0;
#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
    virtual graph_task* try_put_task( const T& t, const message_metainfo& metainfo ) = 0;
#endif
};  // successor_cache<T>

//! An abstract cache of successors, specialized to continue_msg
template<typename M>
class successor_cache< continue_msg, M > : no_copy {
protected:

    typedef M mutex_type;
    mutex_type my_mutex;

    typedef receiver<continue_msg> successor_type;
    typedef receiver<continue_msg>* pointer_type;
    typedef sender<continue_msg> owner_type;
    typedef std::list< pointer_type > successors_type;
    successors_type my_successors;
    owner_type* my_owner;

public:
    successor_cache( sender<continue_msg>* owner ) : my_owner(owner) {
        // Do not work with the passed pointer here as it may not be fully initialized yet
    }

    virtual ~successor_cache() {}

    void register_successor( successor_type& r ) {
        typename mutex_type::scoped_lock l(my_mutex, true);
        if( r.priority() != no_priority )
            my_successors.push_front( &r );
        else
            my_successors.push_back( &r );
        __TBB_ASSERT( my_owner, "Cache of successors must have an owner." );
        if ( r.is_continue_receiver() ) {
            r.register_predecessor( *my_owner );
        }
    }

    void remove_successor( successor_type& r ) {
        typename mutex_type::scoped_lock l(my_mutex, true);
        for ( successors_type::iterator i = my_successors.begin(); i != my_successors.end(); ++i ) {
            if ( *i == &r ) {
                __TBB_ASSERT(my_owner, "Cache of successors must have an owner.");
                // TODO: check if we need to test for continue_receiver before removing from r.
                r.remove_predecessor( *my_owner );
                my_successors.erase(i);
                break;
            }
        }
    }

    bool empty() {
        typename mutex_type::scoped_lock l(my_mutex, false);
        return my_successors.empty();
    }

    void clear() {
        my_successors.clear();
    }

    virtual graph_task* try_put_task( const continue_msg& t ) = 0;
#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
    virtual graph_task* try_put_task( const continue_msg& t, const message_metainfo& metainfo ) = 0;
#endif
};  // successor_cache< continue_msg >

//! A cache of successors that are broadcast to
template<typename T, typename M=spin_rw_mutex>
class broadcast_cache : public successor_cache<T, M> {
    typedef successor_cache<T, M> base_type;
    typedef M mutex_type;
    typedef typename successor_cache<T,M>::successors_type successors_type;

    graph_task* try_put_task_impl( const T& t __TBB_FLOW_GRAPH_METAINFO_ARG(const message_metainfo& metainfo) ) {
        graph_task * last_task = nullptr;
        typename mutex_type::scoped_lock l(this->my_mutex, /*write=*/true);
        typename successors_type::iterator i = this->my_successors.begin();
        while ( i != this->my_successors.end() ) {
            graph_task *new_task = (*i)->try_put_task(t __TBB_FLOW_GRAPH_METAINFO_ARG(metainfo));
            // workaround for icc bug
            graph& graph_ref = (*i)->graph_reference();
            last_task = combine_tasks(graph_ref, last_task, new_task);  // enqueue if necessary
            if(new_task) {
                ++i;
            }
            else {  // failed
                if ( (*i)->register_predecessor(*this->my_owner) ) {
                    i = this->my_successors.erase(i);
                } else {
                    ++i;
                }
            }
        }
        return last_task;
    }
public:

    broadcast_cache( typename base_type::owner_type* owner ): base_type(owner) {
        // Do not work with the passed pointer here as it may not be fully initialized yet
    }

    graph_task* try_put_task( const T &t ) override {
        return try_put_task_impl(t __TBB_FLOW_GRAPH_METAINFO_ARG(message_metainfo{}));
    }

#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
    graph_task* try_put_task( const T &t, const message_metainfo& metainfo ) override {
        return try_put_task_impl(t, metainfo);
    }
#endif

    // call try_put_task and return list of received tasks
    bool gather_successful_try_puts( const T &t, graph_task_list& tasks ) {
        bool is_at_least_one_put_successful = false;
        typename mutex_type::scoped_lock l(this->my_mutex, /*write=*/true);
        typename successors_type::iterator i = this->my_successors.begin();
        while ( i != this->my_successors.end() ) {
            graph_task * new_task = (*i)->try_put_task(t);
            if(new_task) {
                ++i;
                if(new_task != SUCCESSFULLY_ENQUEUED) {
                    tasks.push_back(*new_task);
                }
                is_at_least_one_put_successful = true;
            }
            else {  // failed
                if ( (*i)->register_predecessor(*this->my_owner) ) {
                    i = this->my_successors.erase(i);
                } else {
                    ++i;
                }
            }
        }
        return is_at_least_one_put_successful;
    }
};

//! A cache of successors that are put in a round-robin fashion
template<typename T, typename M=spin_rw_mutex >
class round_robin_cache : public successor_cache<T, M> {
    typedef successor_cache<T, M> base_type;
    typedef size_t size_type;
    typedef M mutex_type;
    typedef typename successor_cache<T,M>::successors_type successors_type;

public:

    round_robin_cache( typename base_type::owner_type* owner ): base_type(owner) {
        // Do not work with the passed pointer here as it may not be fully initialized yet
    }

    size_type size() {
        typename mutex_type::scoped_lock l(this->my_mutex, false);
        return this->my_successors.size();
    }

private:

    graph_task* try_put_task_impl( const T &t
                                   __TBB_FLOW_GRAPH_METAINFO_ARG(const message_metainfo& metainfo) )
    {
        typename mutex_type::scoped_lock l(this->my_mutex, /*write=*/true);
        typename successors_type::iterator i = this->my_successors.begin();
        while ( i != this->my_successors.end() ) {
            graph_task* new_task = (*i)->try_put_task(t __TBB_FLOW_GRAPH_METAINFO_ARG(metainfo));
            if ( new_task ) {
                return new_task;
            } else {
               if ( (*i)->register_predecessor(*this->my_owner) ) {
                   i = this->my_successors.erase(i);
               }
               else {
                   ++i;
               }
            }
        }
        return nullptr;
    }

public:
    graph_task* try_put_task(const T& t) override {
        return try_put_task_impl(t __TBB_FLOW_GRAPH_METAINFO_ARG(message_metainfo{}));
    }

#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
    graph_task* try_put_task( const T& t, const message_metainfo& metainfo ) override {
        return try_put_task_impl(t, metainfo);
    }
#endif
};

#endif // __TBB__flow_graph_cache_impl_H
