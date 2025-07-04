#ifndef BOOST_CORE_REF_HPP
#define BOOST_CORE_REF_HPP

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/workaround.hpp>
#include <boost_kahypar/core/addressof.hpp>
#include <boost_kahypar/core/enable_if.hpp>

#if defined(BOOST_HAS_PRAGMA_ONCE)
# pragma once
#endif

//
//  ref.hpp - ref/cref, useful helper functions
//
//  Copyright (C) 1999, 2000 Jaakko Jarvi (jaakko.jarvi@cs.utu.fi)
//  Copyright (C) 2001, 2002 Peter Dimov
//  Copyright (C) 2002 David Abrahams
//
//  Copyright (C) 2014 Glen Joseph Fernandes
//  (glenjofe@gmail.com)
//
//  Copyright (C) 2014 Agustin Berge
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/core/doc/html/core/ref.html for documentation.
//

/**
 @file
*/

/**
 Boost namespace.
*/
namespace boost_kahypar
{

#if defined( BOOST_MSVC ) && BOOST_WORKAROUND( BOOST_MSVC, == 1600 )

    struct ref_workaround_tag {};

#endif

namespace detail
{

template< class Y, class T > struct ref_convertible
{
    typedef char (&yes) [1];
    typedef char (&no)  [2];

    static yes f( T* );
    static no  f( ... );

    enum _vt { value = sizeof( (f)( static_cast<Y*>(0) ) ) == sizeof(yes) };
};

#if defined(BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS)
struct ref_empty
{
};
#endif

} // namespace detail

// reference_wrapper

/**
 @brief Contains a reference to an object of type `T`.

 `reference_wrapper` is primarily used to "feed" references to
 function templates (algorithms) that take their parameter by
 value. It provides an implicit conversion to `T&`, which
 usually allows the function templates to work on references
 unmodified.
*/
template<class T> class reference_wrapper
{
public:
    /**
     Type `T`.
    */
    typedef T type;

    /**
     Constructs a `reference_wrapper` object that stores a
     reference to `t`.

     @remark Does not throw.
    */
    BOOST_FORCEINLINE explicit reference_wrapper(T& t) BOOST_NOEXCEPT : t_(boost_kahypar::addressof(t)) {}

#if defined( BOOST_MSVC ) && BOOST_WORKAROUND( BOOST_MSVC, == 1600 )

    BOOST_FORCEINLINE explicit reference_wrapper( T & t, ref_workaround_tag ) BOOST_NOEXCEPT : t_( boost_kahypar::addressof( t ) ) {}

#endif

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    /**
     @remark Construction from a temporary object is disabled.
    */
    BOOST_DELETED_FUNCTION(reference_wrapper(T&& t))
public:
#endif

    template<class Y> friend class reference_wrapper;

    /**
     Constructs a `reference_wrapper` object that stores the
     reference stored in the compatible `reference_wrapper` `r`.

     @remark Only enabled when `Y*` is convertible to `T*`.
     @remark Does not throw.
    */
#if !defined(BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS)
    template<class Y, class = typename enable_if_c<boost_kahypar::detail::ref_convertible<Y, T>::value>::type>
    reference_wrapper( reference_wrapper<Y> r ) BOOST_NOEXCEPT : t_( r.t_ )
    {
    }
#else
    template<class Y> reference_wrapper( reference_wrapper<Y> r,
        typename enable_if_c<boost_kahypar::detail::ref_convertible<Y, T>::value,
            boost_kahypar::detail::ref_empty>::type = boost_kahypar::detail::ref_empty() ) BOOST_NOEXCEPT : t_( r.t_ )
    {
    }
#endif

    /**
     @return The stored reference.
     @remark Does not throw.
    */
    BOOST_FORCEINLINE operator T& () const BOOST_NOEXCEPT { return *t_; }

    /**
     @return The stored reference.
     @remark Does not throw.
    */
    BOOST_FORCEINLINE T& get() const BOOST_NOEXCEPT { return *t_; }

    /**
     @return A pointer to the object referenced by the stored
       reference.
     @remark Does not throw.
    */
    BOOST_FORCEINLINE T* get_pointer() const BOOST_NOEXCEPT { return t_; }

private:

    T* t_;
};

// ref

/**
 @cond
*/
#if defined( BOOST_BORLANDC ) && BOOST_WORKAROUND( BOOST_BORLANDC, BOOST_TESTED_AT(0x581) )
#  define BOOST_REF_CONST
#else
#  define BOOST_REF_CONST const
#endif
/**
 @endcond
*/

/**
 @return `reference_wrapper<T>(t)`
 @remark Does not throw.
*/
template<class T> BOOST_FORCEINLINE reference_wrapper<T> BOOST_REF_CONST ref( T & t ) BOOST_NOEXCEPT
{
#if defined( BOOST_MSVC ) && BOOST_WORKAROUND( BOOST_MSVC, == 1600 )

    return reference_wrapper<T>( t, ref_workaround_tag() );

#else

    return reference_wrapper<T>( t );

#endif
}

// cref

/**
 @return `reference_wrapper<T const>(t)`
 @remark Does not throw.
*/
template<class T> BOOST_FORCEINLINE reference_wrapper<T const> BOOST_REF_CONST cref( T const & t ) BOOST_NOEXCEPT
{
    return reference_wrapper<T const>(t);
}

#undef BOOST_REF_CONST

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

/**
 @cond
*/
#if defined(BOOST_NO_CXX11_DELETED_FUNCTIONS)
#  define BOOST_REF_DELETE
#else
#  define BOOST_REF_DELETE = delete
#endif
/**
 @endcond
*/

/**
 @remark Construction from a temporary object is disabled.
*/
template<class T> void ref(T const&&) BOOST_REF_DELETE;

/**
 @remark Construction from a temporary object is disabled.
*/
template<class T> void cref(T const&&) BOOST_REF_DELETE;

#undef BOOST_REF_DELETE

#endif

// is_reference_wrapper

/**
 @brief Determine if a type `T` is an instantiation of
 `reference_wrapper`.

 The value static constant will be true if the type `T` is a
 specialization of `reference_wrapper`.
*/
template<typename T> struct is_reference_wrapper
{
    BOOST_STATIC_CONSTANT( bool, value = false );
};

/**
 @cond
*/
template<typename T> struct is_reference_wrapper< reference_wrapper<T> >
{
    BOOST_STATIC_CONSTANT( bool, value = true );
};

#if !defined(BOOST_NO_CV_SPECIALIZATIONS)

template<typename T> struct is_reference_wrapper< reference_wrapper<T> const >
{
    BOOST_STATIC_CONSTANT( bool, value = true );
};

template<typename T> struct is_reference_wrapper< reference_wrapper<T> volatile >
{
    BOOST_STATIC_CONSTANT( bool, value = true );
};

template<typename T> struct is_reference_wrapper< reference_wrapper<T> const volatile >
{
    BOOST_STATIC_CONSTANT( bool, value = true );
};

#endif // !defined(BOOST_NO_CV_SPECIALIZATIONS)

/**
 @endcond
*/


// unwrap_reference

/**
 @brief Find the type in a `reference_wrapper`.

 The `typedef` type is `T::type` if `T` is a
 `reference_wrapper`, `T` otherwise.
*/
template<typename T> struct unwrap_reference
{
    typedef T type;
};

/**
 @cond
*/
template<typename T> struct unwrap_reference< reference_wrapper<T> >
{
    typedef T type;
};

#if !defined(BOOST_NO_CV_SPECIALIZATIONS)

template<typename T> struct unwrap_reference< reference_wrapper<T> const >
{
    typedef T type;
};

template<typename T> struct unwrap_reference< reference_wrapper<T> volatile >
{
    typedef T type;
};

template<typename T> struct unwrap_reference< reference_wrapper<T> const volatile >
{
    typedef T type;
};

#endif // !defined(BOOST_NO_CV_SPECIALIZATIONS)

/**
 @endcond
*/

// unwrap_ref

/**
 @return `unwrap_reference<T>::type&(t)`
 @remark Does not throw.
*/
template<class T> BOOST_FORCEINLINE typename unwrap_reference<T>::type& unwrap_ref( T & t ) BOOST_NOEXCEPT
{
    return t;
}

// get_pointer

/**
 @cond
*/
template<class T> BOOST_FORCEINLINE T* get_pointer( reference_wrapper<T> const & r ) BOOST_NOEXCEPT
{
    return r.get_pointer();
}
/**
 @endcond
*/

} // namespace boost_kahypar

#endif // #ifndef BOOST_CORE_REF_HPP
