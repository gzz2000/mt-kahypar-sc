/*
    Copyright (c) 2005-2025 Intel Corporation

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

#ifndef __TBB_concurrent_queue_H
#define __TBB_concurrent_queue_H

#include "detail/_namespace_injection.h"
#include "detail/_concurrent_queue_base.h"
#include "detail/_allocator_traits.h"
#include "detail/_exception.h"
#include "detail/_containers_helpers.h"
#include "cache_aligned_allocator.h"

namespace tbb_kahypar {
namespace detail {
namespace d2 {

template <typename QueueRep, typename Allocator>
std::pair<bool, ticket_type> internal_try_pop_impl(void* dst, QueueRep& queue, Allocator& alloc ) {
    ticket_type ticket{};
    do {
        // Basically, we need to read `head_counter` before `tail_counter`. To achieve it we build happens-before on `head_counter`
        ticket = queue.head_counter.load(std::memory_order_acquire);
        do {
            if (static_cast<std::ptrdiff_t>(queue.tail_counter.load(std::memory_order_relaxed) - ticket) <= 0) { // queue is empty
                // Queue is empty
                return { false, ticket };
            }
            // Queue had item with ticket k when we looked.  Attempt to get that item.
            // Another thread snatched the item, retry.
        } while (!queue.head_counter.compare_exchange_strong(ticket, ticket + 1));
    } while (!queue.choose(ticket).pop(dst, ticket, queue, alloc));
    return { true, ticket };
}

// A high-performance thread-safe non-blocking concurrent queue.
// Multiple threads may each push and pop concurrently.
template <typename T, typename Allocator = tbb_kahypar::cache_aligned_allocator<T>>
class concurrent_queue {
    using allocator_traits_type = tbb_kahypar::detail::allocator_traits<Allocator>;
    using queue_representation_type = concurrent_queue_rep<T, Allocator>;
    using queue_allocator_type = typename allocator_traits_type::template rebind_alloc<queue_representation_type>;
    using queue_allocator_traits = tbb_kahypar::detail::allocator_traits<queue_allocator_type>;
public:
    using size_type = std::size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using difference_type = std::ptrdiff_t;

    using allocator_type = Allocator;
    using pointer = typename allocator_traits_type::pointer;
    using const_pointer = typename allocator_traits_type::const_pointer;

    using iterator = concurrent_queue_iterator<concurrent_queue, T, Allocator>;
    using const_iterator = concurrent_queue_iterator<concurrent_queue, const T, Allocator>;

    concurrent_queue() : concurrent_queue(allocator_type()) {}

    explicit concurrent_queue(const allocator_type& a) :
        my_allocator(a), my_queue_representation(nullptr)
    {
        my_queue_representation = static_cast<queue_representation_type*>(r1::cache_aligned_allocate(sizeof(queue_representation_type)));
        queue_allocator_traits::construct(my_allocator, my_queue_representation);

        __TBB_ASSERT(is_aligned(my_queue_representation, max_nfs_size), "alignment error" );
        __TBB_ASSERT(is_aligned(&my_queue_representation->head_counter, max_nfs_size), "alignment error" );
        __TBB_ASSERT(is_aligned(&my_queue_representation->tail_counter, max_nfs_size), "alignment error" );
        __TBB_ASSERT(is_aligned(&my_queue_representation->array, max_nfs_size), "alignment error" );
    }

    template <typename InputIterator>
    concurrent_queue(InputIterator begin, InputIterator end, const allocator_type& a = allocator_type()) :
        concurrent_queue(a)
    {
        for (; begin != end; ++begin)
            push(*begin);
    }

    concurrent_queue( std::initializer_list<value_type> init, const allocator_type& alloc = allocator_type() ) :
        concurrent_queue(init.begin(), init.end(), alloc)
    {}

    concurrent_queue(const concurrent_queue& src, const allocator_type& a) :
        concurrent_queue(a)
    {
        my_queue_representation->assign(*src.my_queue_representation, my_allocator, copy_construct_item);
    }

    concurrent_queue(const concurrent_queue& src) :
        concurrent_queue(queue_allocator_traits::select_on_container_copy_construction(src.get_allocator()))
    {
        my_queue_representation->assign(*src.my_queue_representation, my_allocator, copy_construct_item);
    }

    // Move constructors
    concurrent_queue(concurrent_queue&& src) :
        concurrent_queue(std::move(src.my_allocator))
    {
        internal_swap(src);
    }

    concurrent_queue(concurrent_queue&& src, const allocator_type& a) :
        concurrent_queue(a)
    {
        // checking that memory allocated by one instance of allocator can be deallocated
        // with another
        if (my_allocator == src.my_allocator) {
            internal_swap(src);
        } else {
            // allocators are different => performing per-element move
            my_queue_representation->assign(*src.my_queue_representation, my_allocator, move_construct_item);
            src.clear();
        }
    }

    // Destroy queue
    ~concurrent_queue() {
        clear();
        my_queue_representation->clear(my_allocator);
        queue_allocator_traits::destroy(my_allocator, my_queue_representation);
        r1::cache_aligned_deallocate(my_queue_representation);
    }

    concurrent_queue& operator=( const concurrent_queue& other ) {
        //TODO: implement support for std::allocator_traits::propagate_on_container_copy_assignment
        if (my_queue_representation != other.my_queue_representation) {
            clear();
            my_allocator = other.my_allocator;
            my_queue_representation->assign(*other.my_queue_representation, my_allocator, copy_construct_item);
        }
        return *this;
    }

    concurrent_queue& operator=( concurrent_queue&& other ) {
        //TODO: implement support for std::allocator_traits::propagate_on_container_move_assignment
        if (my_queue_representation != other.my_queue_representation) {
            clear();
            if (my_allocator == other.my_allocator) {
                internal_swap(other);
            } else {
                my_queue_representation->assign(*other.my_queue_representation, other.my_allocator, move_construct_item);
                other.clear();
                my_allocator = std::move(other.my_allocator);
            }
        }
        return *this;
    }

    concurrent_queue& operator=( std::initializer_list<value_type> init ) {
        assign(init);
        return *this;
    }

    template <typename InputIterator>
    void assign( InputIterator first, InputIterator last ) {
        concurrent_queue src(first, last);
        clear();
        my_queue_representation->assign(*src.my_queue_representation, my_allocator, move_construct_item);
    }

    void assign( std::initializer_list<value_type> init ) {
        assign(init.begin(), init.end());
    }

    void swap ( concurrent_queue& other ) {
        //TODO: implement support for std::allocator_traits::propagate_on_container_swap
        __TBB_ASSERT(my_allocator == other.my_allocator, "unequal allocators");
        internal_swap(other);
    }

    // Enqueue an item at tail of queue.
    void push(const T& value) {
        internal_push(value);
    }

    void push(T&& value) {
        internal_push(std::move(value));
    }

    template <typename... Args>
    void emplace( Args&&... args ) {
        internal_push(std::forward<Args>(args)...);
    }

    // Attempt to dequeue an item from head of queue.
    /** Does not wait for item to become available.
        Returns true if successful; false otherwise. */
    bool try_pop( T& result ) {
        return internal_try_pop(&result);
    }

    // Return the number of items in the queue; thread unsafe
    size_type unsafe_size() const {
        std::ptrdiff_t size = my_queue_representation->size();
        return size < 0 ? 0 :  size_type(size);
    }

    // Equivalent to size()==0.
    __TBB_nodiscard bool empty() const {
        return my_queue_representation->empty();
    }

    // Clear the queue. not thread-safe.
    void clear() {
        my_queue_representation->clear(my_allocator);
    }

    // Return allocator object
    allocator_type get_allocator() const { return my_allocator; }

    //------------------------------------------------------------------------
    // The iterators are intended only for debugging.  They are slow and not thread safe.
    //------------------------------------------------------------------------

    iterator unsafe_begin() { return concurrent_queue_iterator_provider::get<iterator>(*this); }
    iterator unsafe_end() { return iterator(); }
    const_iterator unsafe_begin() const { return concurrent_queue_iterator_provider::get<const_iterator>(*this); }
    const_iterator unsafe_end() const { return const_iterator(); }
    const_iterator unsafe_cbegin() const { return concurrent_queue_iterator_provider::get<const_iterator>(*this); }
    const_iterator unsafe_cend() const { return const_iterator(); }

private:
    void internal_swap(concurrent_queue& src) {
        using std::swap;
        swap(my_queue_representation, src.my_queue_representation);
    }

    template <typename... Args>
    void internal_push( Args&&... args ) {
        ticket_type k = my_queue_representation->tail_counter++;
        my_queue_representation->choose(k).push(k, *my_queue_representation, my_allocator, std::forward<Args>(args)...);
    }

    bool internal_try_pop( void* dst ) {
        return internal_try_pop_impl(dst, *my_queue_representation, my_allocator).first;
    }

    template <typename Container, typename Value, typename A>
    friend class concurrent_queue_iterator;

    static void copy_construct_item(T* location, const void* src) {
        // TODO: use allocator_traits for copy construction
        new (location) value_type(*static_cast<const value_type*>(src));
        // queue_allocator_traits::construct(my_allocator, location, *static_cast<const T*>(src));
    }

    static void move_construct_item(T* location, const void* src) {
        // TODO: use allocator_traits for move construction
        new (location) value_type(std::move(*static_cast<value_type*>(const_cast<void*>(src))));
    }

    queue_allocator_type my_allocator;
    queue_representation_type* my_queue_representation;

    friend void swap( concurrent_queue& lhs, concurrent_queue& rhs ) {
        lhs.swap(rhs);
    }

    friend bool operator==( const concurrent_queue& lhs, const concurrent_queue& rhs ) {
        return lhs.unsafe_size() == rhs.unsafe_size() && std::equal(lhs.unsafe_begin(), lhs.unsafe_end(), rhs.unsafe_begin());
    }

#if !__TBB_CPP20_COMPARISONS_PRESENT
    friend bool operator!=( const concurrent_queue& lhs,  const concurrent_queue& rhs ) {
        return !(lhs == rhs);
    }
#endif // __TBB_CPP20_COMPARISONS_PRESENT
}; // class concurrent_queue

#if __TBB_CPP17_DEDUCTION_GUIDES_PRESENT
// Deduction guide for the constructor from two iterators
template <typename It, typename Alloc = tbb_kahypar::cache_aligned_allocator<iterator_value_t<It>>,
          typename = std::enable_if_t<is_input_iterator_v<It>>,
          typename = std::enable_if_t<is_allocator_v<Alloc>>>
concurrent_queue( It, It, Alloc = Alloc() )
-> concurrent_queue<iterator_value_t<It>, Alloc>;

#endif /* __TBB_CPP17_DEDUCTION_GUIDES_PRESENT */

class concurrent_monitor;

// The concurrent monitor tags for concurrent_bounded_queue.
static constexpr std::size_t cbq_slots_avail_tag = 0;
static constexpr std::size_t cbq_items_avail_tag = 1;
} // namespace d2


namespace r1 {
    class concurrent_monitor;

    TBB_EXPORT std::uint8_t* __TBB_EXPORTED_FUNC allocate_bounded_queue_rep( std::size_t queue_rep_size );
    TBB_EXPORT void __TBB_EXPORTED_FUNC deallocate_bounded_queue_rep( std::uint8_t* mem, std::size_t queue_rep_size );
    TBB_EXPORT void __TBB_EXPORTED_FUNC abort_bounded_queue_monitors( concurrent_monitor* monitors );
    TBB_EXPORT void __TBB_EXPORTED_FUNC notify_bounded_queue_monitor( concurrent_monitor* monitors, std::size_t monitor_tag
                                                            , std::size_t ticket );
    TBB_EXPORT void __TBB_EXPORTED_FUNC wait_bounded_queue_monitor( concurrent_monitor* monitors, std::size_t monitor_tag,
                                                            std::ptrdiff_t target, d1::delegate_base& predicate );
} // namespace r1


namespace d2 {
// A high-performance thread-safe blocking concurrent bounded queue.
// Supports boundedness and blocking semantics.
// Multiple threads may each push and pop concurrently.
template <typename T, typename Allocator = tbb_kahypar::cache_aligned_allocator<T>>
class concurrent_bounded_queue {
    using allocator_traits_type = tbb_kahypar::detail::allocator_traits<Allocator>;
    using queue_representation_type = concurrent_queue_rep<T, Allocator>;
    using queue_allocator_type = typename allocator_traits_type::template rebind_alloc<queue_representation_type>;
    using queue_allocator_traits = tbb_kahypar::detail::allocator_traits<queue_allocator_type>;

    template <typename FuncType>
    void internal_wait(r1::concurrent_monitor* monitors, std::size_t monitor_tag, std::ptrdiff_t target, FuncType pred) {
        d1::delegated_function<FuncType> func(pred);
        r1::wait_bounded_queue_monitor(monitors, monitor_tag, target, func);
    }
public:
    using size_type = std::ptrdiff_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using difference_type = std::ptrdiff_t;

    using allocator_type = Allocator;
    using pointer = typename allocator_traits_type::pointer;
    using const_pointer = typename allocator_traits_type::const_pointer;

    using iterator = concurrent_queue_iterator<concurrent_bounded_queue, T, Allocator>;
    using const_iterator = concurrent_queue_iterator<concurrent_bounded_queue, const T, Allocator> ;

    concurrent_bounded_queue() : concurrent_bounded_queue(allocator_type()) {}

    explicit concurrent_bounded_queue( const allocator_type& a ) :
        my_allocator(a), my_capacity(0), my_abort_counter(0), my_queue_representation(nullptr)
    {
        my_queue_representation = reinterpret_cast<queue_representation_type*>(
            r1::allocate_bounded_queue_rep(sizeof(queue_representation_type)));
        my_monitors = reinterpret_cast<r1::concurrent_monitor*>(my_queue_representation + 1);
        queue_allocator_traits::construct(my_allocator, my_queue_representation);
        my_capacity = std::size_t(-1) / (queue_representation_type::item_size > 1 ? queue_representation_type::item_size : 2);

        __TBB_ASSERT(is_aligned(my_queue_representation, max_nfs_size), "alignment error" );
        __TBB_ASSERT(is_aligned(&my_queue_representation->head_counter, max_nfs_size), "alignment error" );
        __TBB_ASSERT(is_aligned(&my_queue_representation->tail_counter, max_nfs_size), "alignment error" );
        __TBB_ASSERT(is_aligned(&my_queue_representation->array, max_nfs_size), "alignment error" );
    }

    template <typename InputIterator>
    concurrent_bounded_queue( InputIterator begin, InputIterator end, const allocator_type& a = allocator_type() ) :
        concurrent_bounded_queue(a)
    {
        for (; begin != end; ++begin)
            push(*begin);
    }

    concurrent_bounded_queue( std::initializer_list<value_type> init, const allocator_type& alloc = allocator_type() ):
        concurrent_bounded_queue(init.begin(), init.end(), alloc)
    {}

    concurrent_bounded_queue( const concurrent_bounded_queue& src, const allocator_type& a ) :
        concurrent_bounded_queue(a)
    {
        my_capacity = src.my_capacity;
        my_queue_representation->assign(*src.my_queue_representation, my_allocator, copy_construct_item);
    }

    concurrent_bounded_queue( const concurrent_bounded_queue& src ) :
        concurrent_bounded_queue(queue_allocator_traits::select_on_container_copy_construction(src.get_allocator()))
    {
        my_capacity = src.my_capacity;
        my_queue_representation->assign(*src.my_queue_representation, my_allocator, copy_construct_item);
    }

    // Move constructors
    concurrent_bounded_queue( concurrent_bounded_queue&& src ) :
        concurrent_bounded_queue(std::move(src.my_allocator))
    {
        internal_swap(src);
    }

    concurrent_bounded_queue( concurrent_bounded_queue&& src, const allocator_type& a ) :
        concurrent_bounded_queue(a)
    {
        // checking that memory allocated by one instance of allocator can be deallocated
        // with another
        if (my_allocator == src.my_allocator) {
            internal_swap(src);
        } else {
            // allocators are different => performing per-element move
            my_queue_representation->assign(*src.my_queue_representation, my_allocator, move_construct_item);
            src.clear();
        }
    }

    // Destroy queue
    ~concurrent_bounded_queue() {
        clear();
        my_queue_representation->clear(my_allocator);
        queue_allocator_traits::destroy(my_allocator, my_queue_representation);
        r1::deallocate_bounded_queue_rep(reinterpret_cast<std::uint8_t*>(my_queue_representation),
                                         sizeof(queue_representation_type));
    }

    concurrent_bounded_queue& operator=( const concurrent_bounded_queue& other ) {
        //TODO: implement support for std::allocator_traits::propagate_on_container_copy_assignment
        if (my_queue_representation != other.my_queue_representation) {
            clear();
            my_allocator = other.my_allocator;
            my_capacity = other.my_capacity;
            my_queue_representation->assign(*other.my_queue_representation, my_allocator, copy_construct_item);
        }
        return *this;
    }

    concurrent_bounded_queue& operator=( concurrent_bounded_queue&& other ) {
        //TODO: implement support for std::allocator_traits::propagate_on_container_move_assignment
        if (my_queue_representation != other.my_queue_representation) {
            clear();
            if (my_allocator == other.my_allocator) {
                internal_swap(other);
            } else {
                my_queue_representation->assign(*other.my_queue_representation, other.my_allocator, move_construct_item);
                other.clear();
                my_allocator = std::move(other.my_allocator);
                my_capacity = other.my_capacity;
            }
        }
        return *this;
    }

    concurrent_bounded_queue& operator=( std::initializer_list<value_type> init ) {
        assign(init);
        return *this;
    }

    template <typename InputIterator>
    void assign( InputIterator first, InputIterator last ) {
        concurrent_bounded_queue src(first, last);
        clear();
        my_queue_representation->assign(*src.my_queue_representation, my_allocator, move_construct_item);
    }

    void assign( std::initializer_list<value_type> init ) {
        assign(init.begin(), init.end());
    }

    void swap ( concurrent_bounded_queue& other ) {
        //TODO: implement support for std::allocator_traits::propagate_on_container_swap
        __TBB_ASSERT(my_allocator == other.my_allocator, "unequal allocators");
        internal_swap(other);
    }

    // Enqueue an item at tail of queue.
    void push( const T& value ) {
        internal_push(value);
    }

    void push( T&& value ) {
        internal_push(std::move(value));
    }

    // Enqueue an item at tail of queue if queue is not already full.
    // Does not wait for queue to become not full.
    // Returns true if item is pushed; false if queue was already full.
    bool try_push( const T& value ) {
        return internal_push_if_not_full(value);
    }

    bool try_push( T&& value ) {
        return internal_push_if_not_full(std::move(value));
    }

    template <typename... Args>
    void emplace( Args&&... args ) {
        internal_push(std::forward<Args>(args)...);
    }

    template <typename... Args>
    bool try_emplace( Args&&... args ) {
        return internal_push_if_not_full(std::forward<Args>(args)...);
    }

    // Attempt to dequeue an item from head of queue.
    void pop( T& result ) {
        internal_pop(&result);
    }

    /** Does not wait for item to become available.
        Returns true if successful; false otherwise. */
    bool try_pop( T& result ) {
        return internal_pop_if_present(&result);
    }

    void abort() {
        internal_abort();
    }

    // Return the number of items in the queue; thread unsafe
    std::ptrdiff_t size() const {
        return my_queue_representation->size();
    }

    void set_capacity( size_type new_capacity ) {
        std::ptrdiff_t c = new_capacity < 0 ? infinite_capacity : new_capacity;
        my_capacity = c;
    }

    size_type capacity() const {
        return my_capacity;
    }

    // Equivalent to size()==0.
    __TBB_nodiscard bool empty() const {
        return my_queue_representation->empty();
    }

    // Clear the queue. not thread-safe.
    void clear() {
        my_queue_representation->clear(my_allocator);
    }

    // Return allocator object
    allocator_type get_allocator() const { return my_allocator; }

    //------------------------------------------------------------------------
    // The iterators are intended only for debugging.  They are slow and not thread safe.
    //------------------------------------------------------------------------

    iterator unsafe_begin() { return concurrent_queue_iterator_provider::get<iterator>(*this); }
    iterator unsafe_end() { return iterator(); }
    const_iterator unsafe_begin() const { return concurrent_queue_iterator_provider::get<const_iterator>(*this); }
    const_iterator unsafe_end() const { return const_iterator(); }
    const_iterator unsafe_cbegin() const { return concurrent_queue_iterator_provider::get<const_iterator>(*this); }
    const_iterator unsafe_cend() const { return const_iterator(); }

private:
    void internal_swap( concurrent_bounded_queue& src ) {
        using std::swap;
        swap(my_queue_representation, src.my_queue_representation);
        swap(my_capacity, src.my_capacity);
        swap(my_monitors, src.my_monitors);
    }

    static constexpr std::ptrdiff_t infinite_capacity = std::ptrdiff_t(~size_type(0) / 2);

    template <typename... Args>
    void internal_push( Args&&... args ) {
        unsigned old_abort_counter = my_abort_counter.load(std::memory_order_relaxed);
        ticket_type ticket = my_queue_representation->tail_counter++;
        std::ptrdiff_t target = ticket - my_capacity;

        if (static_cast<std::ptrdiff_t>(my_queue_representation->head_counter.load(std::memory_order_relaxed)) <= target) { // queue is full
            auto pred = [&] {
                if (my_abort_counter.load(std::memory_order_relaxed) != old_abort_counter) {
                    throw_exception(exception_id::user_abort);
                }

                return static_cast<std::ptrdiff_t>(my_queue_representation->head_counter.load(std::memory_order_relaxed)) <= target;
            };

            try_call( [&] {
                internal_wait(my_monitors, cbq_slots_avail_tag, target, pred);
            }).on_exception( [&] {
                my_queue_representation->choose(ticket).abort_push(ticket, *my_queue_representation, my_allocator);
            });

        }
        __TBB_ASSERT((static_cast<std::ptrdiff_t>(my_queue_representation->head_counter.load(std::memory_order_relaxed)) > target), nullptr);
        my_queue_representation->choose(ticket).push(ticket, *my_queue_representation, my_allocator, std::forward<Args>(args)...);
        r1::notify_bounded_queue_monitor(my_monitors, cbq_items_avail_tag, ticket);
    }

    template <typename... Args>
    bool internal_push_if_not_full( Args&&... args ) {
        ticket_type ticket = my_queue_representation->tail_counter.load(std::memory_order_relaxed);
        do {
            if (static_cast<std::ptrdiff_t>(ticket - my_queue_representation->head_counter.load(std::memory_order_relaxed)) >= my_capacity) {
                // Queue is full
                return false;
            }
            // Queue had empty slot with ticket k when we looked. Attempt to claim that slot.
            // Another thread claimed the slot, so retry.
        } while (!my_queue_representation->tail_counter.compare_exchange_strong(ticket, ticket + 1));

        my_queue_representation->choose(ticket).push(ticket, *my_queue_representation, my_allocator, std::forward<Args>(args)...);
        r1::notify_bounded_queue_monitor(my_monitors, cbq_items_avail_tag, ticket);
        return true;
    }

    void internal_pop( void* dst ) {
        std::ptrdiff_t target;
        // This loop is a single pop operation; abort_counter should not be re-read inside
        unsigned old_abort_counter = my_abort_counter.load(std::memory_order_relaxed);

        do {
            target = my_queue_representation->head_counter++;
            if (static_cast<std::ptrdiff_t>(my_queue_representation->tail_counter.load(std::memory_order_relaxed)) <= target) {
                auto pred = [&] {
                    if (my_abort_counter.load(std::memory_order_relaxed) != old_abort_counter) {
                            throw_exception(exception_id::user_abort);
                    }

                    return static_cast<std::ptrdiff_t>(my_queue_representation->tail_counter.load(std::memory_order_relaxed)) <= target;
                };

                try_call( [&] {
                    internal_wait(my_monitors, cbq_items_avail_tag, target, pred);
                }).on_exception( [&] {
                    my_queue_representation->head_counter--;
                });
            }
            __TBB_ASSERT(static_cast<std::ptrdiff_t>(my_queue_representation->tail_counter.load(std::memory_order_relaxed)) > target, nullptr);
        } while (!my_queue_representation->choose(target).pop(dst, target, *my_queue_representation, my_allocator));

        r1::notify_bounded_queue_monitor(my_monitors, cbq_slots_avail_tag, target);
    }

    bool internal_pop_if_present( void* dst ) {
        bool present{};
        ticket_type ticket{};
        std::tie(present, ticket) = internal_try_pop_impl(dst, *my_queue_representation, my_allocator);

        if (present) {
            r1::notify_bounded_queue_monitor(my_monitors, cbq_slots_avail_tag, ticket);
        }
        return present;
    }

    void internal_abort() {
        ++my_abort_counter;
        r1::abort_bounded_queue_monitors(my_monitors);
    }

    static void copy_construct_item(T* location, const void* src) {
        // TODO: use allocator_traits for copy construction
        new (location) value_type(*static_cast<const value_type*>(src));
    }

    static void move_construct_item(T* location, const void* src) {
        // TODO: use allocator_traits for move construction
        new (location) value_type(std::move(*static_cast<value_type*>(const_cast<void*>(src))));
    }

    template <typename Container, typename Value, typename A>
    friend class concurrent_queue_iterator;

    queue_allocator_type my_allocator;
    std::ptrdiff_t my_capacity;
    std::atomic<unsigned> my_abort_counter;
    queue_representation_type* my_queue_representation;

    r1::concurrent_monitor* my_monitors;

    friend void swap( concurrent_bounded_queue& lhs, concurrent_bounded_queue& rhs ) {
        lhs.swap(rhs);
    }

    friend bool operator==( const concurrent_bounded_queue& lhs, const concurrent_bounded_queue& rhs ) {
        return lhs.size() == rhs.size() && std::equal(lhs.unsafe_begin(), lhs.unsafe_end(), rhs.unsafe_begin());
    }

#if !__TBB_CPP20_COMPARISONS_PRESENT
    friend bool operator!=( const concurrent_bounded_queue& lhs, const concurrent_bounded_queue& rhs ) {
        return !(lhs == rhs);
    }
#endif // __TBB_CPP20_COMPARISONS_PRESENT
}; // class concurrent_bounded_queue

#if __TBB_CPP17_DEDUCTION_GUIDES_PRESENT
// Deduction guide for the constructor from two iterators
template <typename It, typename Alloc = tbb_kahypar::cache_aligned_allocator<iterator_value_t<It>>>
concurrent_bounded_queue( It, It, Alloc = Alloc() )
-> concurrent_bounded_queue<iterator_value_t<It>, Alloc>;

#endif /* __TBB_CPP17_DEDUCTION_GUIDES_PRESENT */

} //namespace d2
} // namespace detail

inline namespace v1 {

using detail::d2::concurrent_queue;
using detail::d2::concurrent_bounded_queue;
using detail::r1::user_abort;
using detail::r1::bad_last_alloc;

} // inline namespace v1
} // namespace tbb

#endif // __TBB_concurrent_queue_H
