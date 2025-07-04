
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_HAS_NOTHROW_COPY_HPP_INCLUDED
#define BOOST_TT_HAS_NOTHROW_COPY_HPP_INCLUDED

#include <boost_kahypar/type_traits/intrinsics.hpp>
#include <boost_kahypar/type_traits/integral_constant.hpp>

#ifdef BOOST_HAS_NOTHROW_COPY

#if defined(BOOST_CLANG) || defined(__GNUC__) || defined(__ghs__) || defined(BOOST_CODEGEARC) || defined(__SUNPRO_CC)
#include <boost_kahypar/type_traits/is_volatile.hpp>
#include <boost_kahypar/type_traits/is_copy_constructible.hpp>
#include <boost_kahypar/type_traits/is_reference.hpp>
#include <boost_kahypar/type_traits/is_array.hpp>
#ifdef BOOST_INTEL
#include <boost_kahypar/type_traits/is_pod.hpp>
#endif
#elif defined(BOOST_MSVC) || defined(BOOST_INTEL)
#include <boost_kahypar/type_traits/has_trivial_copy.hpp>
#include <boost_kahypar/type_traits/is_array.hpp>
#ifdef BOOST_INTEL
#include <boost_kahypar/type_traits/add_lvalue_reference.hpp>
#include <boost_kahypar/type_traits/add_const.hpp>
#endif
#endif

namespace boost_kahypar {

template <class T> struct has_nothrow_copy_constructor : public integral_constant<bool, BOOST_HAS_NOTHROW_COPY(T)>{};

#elif !defined(BOOST_NO_CXX11_NOEXCEPT)

#include <boost_kahypar/type_traits/declval.hpp>
#include <boost_kahypar/type_traits/is_copy_constructible.hpp>

namespace boost_kahypar{

namespace detail{

template <class T, bool b>
struct has_nothrow_copy_constructor_imp : public boost_kahypar::integral_constant<bool, false>{};
template <class T>
struct has_nothrow_copy_constructor_imp<T, true> : public boost_kahypar::integral_constant<bool, noexcept(T(boost_kahypar::declval<const T&>()))>{};

}

template <class T> struct has_nothrow_copy_constructor : public detail::has_nothrow_copy_constructor_imp<T, boost_kahypar::is_copy_constructible<T>::value>{};

#else

#include <boost_kahypar/type_traits/has_trivial_copy.hpp>

namespace boost_kahypar{

template <class T> struct has_nothrow_copy_constructor : public integral_constant<bool, ::boost_kahypar::has_trivial_copy<T>::value>{};

#endif

template <> struct has_nothrow_copy_constructor<void> : public false_type{};
template <class T> struct has_nothrow_copy_constructor<T volatile> : public false_type{};
template <class T> struct has_nothrow_copy_constructor<T&> : public false_type{};
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) 
template <class T> struct has_nothrow_copy_constructor<T&&> : public false_type{};
#endif
#ifndef BOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct has_nothrow_copy_constructor<void const> : public false_type{};
template <> struct has_nothrow_copy_constructor<void volatile> : public false_type{};
template <> struct has_nothrow_copy_constructor<void const volatile> : public false_type{};
#endif

template <class T> struct has_nothrow_copy : public has_nothrow_copy_constructor<T>{};

} // namespace boost_kahypar

#endif // BOOST_TT_HAS_NOTHROW_COPY_HPP_INCLUDED
