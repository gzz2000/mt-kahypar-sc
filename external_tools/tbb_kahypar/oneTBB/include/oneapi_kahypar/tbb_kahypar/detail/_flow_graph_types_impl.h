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

#ifndef __TBB__flow_graph_types_impl_H
#define __TBB__flow_graph_types_impl_H

#ifndef __TBB_flow_graph_H
#error Do not #include this internal file directly; use public TBB headers instead.
#endif

// included in namespace tbb_kahypar::detail::d2

// the change to key_matching (adding a K and KHash template parameter, making it a class)
// means we have to pass this data to the key_matching_port.  All the ports have only one
// template parameter, so we have to wrap the following types in a trait:
//
//    . K == key_type
//    . KHash == hash and compare for Key
//    . TtoK == function_body that given an object of T, returns its K
//    . T == type accepted by port, and stored in the hash table
//
// The port will have an additional parameter on node construction, which is a function_body
// that accepts a const T& and returns a K which is the field in T which is its K.
template<typename Kp, typename KHashp, typename Tp>
struct KeyTrait {
    typedef Kp K;
    typedef Tp T;
    typedef type_to_key_function_body<T,K> TtoK;
    typedef KHashp KHash;
};

// wrap each element of a tuple in a template, and make a tuple of the result.
template<int N, template<class> class PT, typename TypeTuple>
struct wrap_tuple_elements;

// A wrapper that generates the traits needed for each port of a key-matching join,
// and the type of the tuple of input ports.
template<int N, template<class> class PT, typename KeyTraits, typename TypeTuple>
struct wrap_key_tuple_elements;

template<int N, template<class> class PT,  typename... Args>
struct wrap_tuple_elements<N, PT, std::tuple<Args...> >{
    typedef typename std::tuple<PT<Args>... > type;
};

template<int N, template<class> class PT, typename KeyTraits, typename... Args>
struct wrap_key_tuple_elements<N, PT, KeyTraits, std::tuple<Args...> > {
    typedef typename KeyTraits::key_type K;
    typedef typename KeyTraits::hash_compare_type KHash;
    typedef typename std::tuple<PT<KeyTrait<K, KHash, Args> >... > type;
};

template< int... S > class sequence {};

template< int N, int... S >
struct make_sequence : make_sequence < N - 1, N - 1, S... > {};

template< int... S >
struct make_sequence < 0, S... > {
    typedef sequence<S...> type;
};

template<class U> struct alignment_of {
    typedef struct { char t; U    padded; } test_alignment;
    static const size_t value = sizeof(test_alignment) - sizeof(U);
};

template <typename... Types>
struct max_alignment_helper;

template <typename T1, typename... Types>
struct max_alignment_helper<T1, Types...> {
    using type = typename max_alignment_helper<T1, typename max_alignment_helper<Types...>::type>::type;
};

template <typename T1, typename T2>
struct max_alignment_helper<T1, T2> {
    using type = typename std::conditional<alignof(T1) < alignof(T2), T2, T1>::type;
};

template <typename... Types>
using max_alignment_helper_t = typename max_alignment_helper<Types...>::type;

#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#pragma warning(push)
#pragma warning(disable: 4324) // warning C4324: structure was padded due to alignment specifier
#endif

// T1, T2 are actual types stored.  The space defined for T1 in the type returned
// is a char array of the correct size.  Type T2 should be trivially-constructible,
// T1 must be explicitly managed.

template <typename T1, typename T2>
struct alignas(alignof(max_alignment_helper_t<T1, T2>)) aligned_pair {
    char first[sizeof(T1)];
    T2 second;
};

#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
template <typename T1, typename T2, typename T3>
struct alignas(alignof(max_alignment_helper_t<T1, T2, T3>)) aligned_triple {
    char first[sizeof(T1)];
    T2 second;
    T3 third;
};
#endif


#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#pragma warning(pop) // warning 4324 is back
#endif

// support for variant type
// type we use when we're not storing a value
struct default_constructed { };

// type which contains another type, tests for what type is contained, and references to it.
// Wrapper<T>
//     void CopyTo( void *newSpace) : builds a Wrapper<T> copy of itself in newSpace

// struct to allow us to copy and test the type of objects
struct WrapperBase {
    virtual ~WrapperBase() {}
    virtual void CopyTo(void* /*newSpace*/) const = 0;
};

// Wrapper<T> contains a T, with the ability to test what T is.  The Wrapper<T> can be
// constructed from a T, can be copy-constructed from another Wrapper<T>, and can be
// examined via value(), but not modified.
template<typename T>
struct Wrapper: public WrapperBase {
    typedef T value_type;
    typedef T* pointer_type;
private:
    T value_space;
public:
    const value_type &value() const { return value_space; }

private:
    Wrapper();

    // on exception will ensure the Wrapper will contain only a trivially-constructed object
    struct _unwind_space {
        pointer_type space;
        _unwind_space(pointer_type p) : space(p) {}
        ~_unwind_space() {
            if(space) (void) new (space) Wrapper<default_constructed>(default_constructed());
        }
    };
public:
    explicit Wrapper( const T& other ) : value_space(other) { }
    explicit Wrapper(const Wrapper& other) = delete;

    void CopyTo(void* newSpace) const override {
        _unwind_space guard((pointer_type)newSpace);
        (void) new(newSpace) Wrapper(value_space);
        guard.space = nullptr;
    }
    ~Wrapper() { }
};

// specialization for array objects
template<typename T, size_t N>
struct Wrapper<T[N]> : public WrapperBase {
    typedef T value_type;
    typedef T* pointer_type;
    // space must be untyped.
    typedef T ArrayType[N];
private:
    // The space is not of type T[N] because when copy-constructing, it would be
    // default-initialized and then copied to in some fashion, resulting in two
    // constructions and one destruction per element.  If the type is char[ ], we
    // placement new into each element, resulting in one construction per element.
    static const size_t space_size = sizeof(ArrayType);
    char value_space[space_size];


    // on exception will ensure the already-built objects will be destructed
    // (the value_space is a char array, so it is already trivially-destructible.)
    struct _unwind_class {
        pointer_type space;
        int    already_built;
        _unwind_class(pointer_type p) : space(p), already_built(0) {}
        ~_unwind_class() {
            if(space) {
                for(size_t i = already_built; i > 0 ; --i ) space[i-1].~value_type();
                (void) new(space) Wrapper<default_constructed>(default_constructed());
            }
        }
    };
public:
    const ArrayType &value() const {
        char *vp = const_cast<char *>(value_space);
        return reinterpret_cast<ArrayType &>(*vp);
    }

private:
    Wrapper();
public:
    // have to explicitly construct because other decays to a const value_type*
    explicit Wrapper(const ArrayType& other) {
        _unwind_class guard((pointer_type)value_space);
        pointer_type vp = reinterpret_cast<pointer_type>(&value_space);
        for(size_t i = 0; i < N; ++i ) {
            (void) new(vp++) value_type(other[i]);
            ++(guard.already_built);
        }
        guard.space = nullptr;
    }
    explicit Wrapper(const Wrapper& other) : WrapperBase() {
        // we have to do the heavy lifting to copy contents
        _unwind_class guard((pointer_type)value_space);
        pointer_type dp = reinterpret_cast<pointer_type>(value_space);
        pointer_type sp = reinterpret_cast<pointer_type>(const_cast<char *>(other.value_space));
        for(size_t i = 0; i < N; ++i, ++dp, ++sp) {
            (void) new(dp) value_type(*sp);
            ++(guard.already_built);
        }
        guard.space = nullptr;
    }

    void CopyTo(void* newSpace) const override {
        (void) new(newSpace) Wrapper(*this);  // exceptions handled in copy constructor
    }

    ~Wrapper() {
        // have to destroy explicitly in reverse order
        pointer_type vp = reinterpret_cast<pointer_type>(&value_space);
        for(size_t i = N; i > 0 ; --i ) vp[i-1].~value_type();
    }
};

// given a tuple, return the type of the element that has the maximum alignment requirement.
// Given a tuple and that type, return the number of elements of the object with the max
// alignment requirement that is at least as big as the largest object in the tuple.

template<bool, class T1, class T2> struct pick_one;
template<class T1, class T2> struct pick_one<true , T1, T2> { typedef T1 type; };
template<class T1, class T2> struct pick_one<false, T1, T2> { typedef T2 type; };

template< template<class> class Selector, typename T1, typename T2 >
struct pick_max {
    typedef typename pick_one< (Selector<T1>::value > Selector<T2>::value), T1, T2 >::type type;
};

template<typename T> struct size_of { static const int value = sizeof(T); };

template< size_t N, class Tuple, template<class> class Selector > struct pick_tuple_max {
    typedef typename pick_tuple_max<N-1, Tuple, Selector>::type LeftMaxType;
    typedef typename std::tuple_element<N-1, Tuple>::type ThisType;
    typedef typename pick_max<Selector, LeftMaxType, ThisType>::type type;
};

template< class Tuple, template<class> class Selector > struct pick_tuple_max<0, Tuple, Selector> {
    typedef typename std::tuple_element<0, Tuple>::type type;
};

// is the specified type included in a tuple?
template<class Q, size_t N, class Tuple>
struct is_element_of {
    typedef typename std::tuple_element<N-1, Tuple>::type T_i;
    static const bool value = std::is_same<Q,T_i>::value || is_element_of<Q,N-1,Tuple>::value;
};

template<class Q, class Tuple>
struct is_element_of<Q,0,Tuple> {
    typedef typename std::tuple_element<0, Tuple>::type T_i;
    static const bool value = std::is_same<Q,T_i>::value;
};

// allow the construction of types that are listed tuple.  If a disallowed type
// construction is written, a method involving this type is created.  The
// type has no definition, so a syntax error is generated.
template<typename T> struct ERROR_Type_Not_allowed_In_Tagged_Msg_Not_Member_Of_Tuple;

template<typename T, bool BUILD_IT> struct do_if;
template<typename T>
struct do_if<T, true> {
    static void construct(void *mySpace, const T& x) {
        (void) new(mySpace) Wrapper<T>(x);
    }
};
template<typename T>
struct do_if<T, false> {
    static void construct(void * /*mySpace*/, const T& x) {
        // This method is instantiated when the type T does not match any of the
        // element types in the Tuple in variant<Tuple>.
        ERROR_Type_Not_allowed_In_Tagged_Msg_Not_Member_Of_Tuple<T>::bad_type(x);
    }
};

// Tuple tells us the allowed types that variant can hold.  It determines the alignment of the space in
// Wrapper, and how big Wrapper is.
//
// the object can only be tested for type, and a read-only reference can be fetched by cast_to<T>().

using tbb_kahypar::detail::punned_cast;
struct tagged_null_type {};
template<typename TagType, typename T0, typename T1=tagged_null_type, typename T2=tagged_null_type, typename T3=tagged_null_type,
                           typename T4=tagged_null_type, typename T5=tagged_null_type, typename T6=tagged_null_type,
                           typename T7=tagged_null_type, typename T8=tagged_null_type, typename T9=tagged_null_type>
class tagged_msg {
    typedef std::tuple<T0, T1, T2, T3, T4
                  //TODO: Should we reject lists longer than a tuple can hold?
                  #if __TBB_VARIADIC_MAX >= 6
                  , T5
                  #endif
                  #if __TBB_VARIADIC_MAX >= 7
                  , T6
                  #endif
                  #if __TBB_VARIADIC_MAX >= 8
                  , T7
                  #endif
                  #if __TBB_VARIADIC_MAX >= 9
                  , T8
                  #endif
                  #if __TBB_VARIADIC_MAX >= 10
                  , T9
                  #endif
                  > Tuple;

private:
    class variant {
        static const size_t N = std::tuple_size<Tuple>::value;
        typedef typename pick_tuple_max<N, Tuple, alignment_of>::type AlignType;
        typedef typename pick_tuple_max<N, Tuple, size_of>::type MaxSizeType;
        static const size_t MaxNBytes = (sizeof(Wrapper<MaxSizeType>)+sizeof(AlignType)-1);
        static const size_t MaxNElements = MaxNBytes/sizeof(AlignType);
        typedef aligned_space<AlignType, MaxNElements> SpaceType;
        SpaceType my_space;
        static const size_t MaxSize = sizeof(SpaceType);

    public:
        variant() { (void) new(&my_space) Wrapper<default_constructed>(default_constructed()); }

        template<typename T>
        variant( const T& x ) {
            do_if<T, is_element_of<T, N, Tuple>::value>::construct(&my_space,x);
        }

        variant(const variant& other) {
            const WrapperBase * h = punned_cast<const WrapperBase *>(&(other.my_space));
            h->CopyTo(&my_space);
        }

        // assignment must destroy and re-create the Wrapper type, as there is no way
        // to create a Wrapper-to-Wrapper assign even if we find they agree in type.
        void operator=( const variant& rhs ) {
            if(&rhs != this) {
                WrapperBase *h = punned_cast<WrapperBase *>(&my_space);
                h->~WrapperBase();
                const WrapperBase *ch = punned_cast<const WrapperBase *>(&(rhs.my_space));
                ch->CopyTo(&my_space);
            }
        }

        template<typename U>
        const U& variant_cast_to() const {
            const Wrapper<U> *h = dynamic_cast<const Wrapper<U>*>(punned_cast<const WrapperBase *>(&my_space));
            if(!h) {
                throw_exception(exception_id::bad_tagged_msg_cast);
            }
            return h->value();
        }
        template<typename U>
        bool variant_is_a() const { return dynamic_cast<const Wrapper<U>*>(punned_cast<const WrapperBase *>(&my_space)) != nullptr; }

        bool variant_is_default_constructed() const {return variant_is_a<default_constructed>();}

        ~variant() {
            WrapperBase *h = punned_cast<WrapperBase *>(&my_space);
            h->~WrapperBase();
        }
    }; //class variant

    TagType my_tag;
    variant my_msg;

public:
    tagged_msg(): my_tag(TagType(~0)), my_msg(){}

    template<typename T, typename R>
    tagged_msg(T const &index, R const &value) : my_tag(index), my_msg(value) {}

    template<typename T, typename R, size_t N>
    tagged_msg(T const &index,  R (&value)[N]) : my_tag(index), my_msg(value) {}

    void set_tag(TagType const &index) {my_tag = index;}
    TagType tag() const {return my_tag;}

    template<typename V>
    const V& cast_to() const {return my_msg.template variant_cast_to<V>();}

    template<typename V>
    bool is_a() const {return my_msg.template variant_is_a<V>();}

    bool is_default_constructed() const {return my_msg.variant_is_default_constructed();}
}; //class tagged_msg

// template to simplify cast and test for tagged_msg in template contexts
template<typename V, typename T>
const V& cast_to(T const &t) { return t.template cast_to<V>(); }

template<typename V, typename T>
bool is_a(T const &t) { return t.template is_a<V>(); }

enum op_stat { WAIT = 0, SUCCEEDED, FAILED };

#endif  /* __TBB__flow_graph_types_impl_H */
