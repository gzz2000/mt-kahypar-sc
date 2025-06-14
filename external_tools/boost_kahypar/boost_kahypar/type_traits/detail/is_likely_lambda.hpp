/* Copyright 2017 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/poly_collection for library home page.
 */

#ifndef BOOST_TT_DETAIL_IS_LIKELY_STATELESS_LAMBDA_HPP
#define BOOST_TT_DETAIL_IS_LIKELY_STATELESS_LAMBDA_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <boost_kahypar/type_traits/detail/config.hpp>
#include <boost_kahypar/type_traits/integral_constant.hpp>

#if defined(BOOST_TT_HAS_ACCURATE_BINARY_OPERATOR_DETECTION)
//
// We don't need or use this, just define a dummy class:
//
namespace boost_kahypar{ namespace type_traits_detail{

template<typename T>
struct is_likely_stateless_lambda : public false_type {};

}}

#elif !defined(BOOST_NO_CXX11_LAMBDAS) && !defined(BOOST_NO_CXX11_DECLTYPE) && !defined(BOOST_NO_CXX11_TEMPLATE_ALIASES) && !BOOST_WORKAROUND(BOOST_MSVC, < 1900)\
         && !(BOOST_WORKAROUND(BOOST_MSVC, == 1900) && defined(_MANAGED))

#include <boost_kahypar/type_traits/is_convertible.hpp>
#include <boost_kahypar/type_traits/enable_if.hpp>

namespace boost_kahypar{

namespace type_traits_detail{

/* Stateless lambda expressions have one (and only one) call operator and are
 * convertible to a function pointer with the same signature. Non-lambda types
 * could satisfy this too, hence the "likely" qualifier.
 */

template<typename T>
struct has_one_operator_call_helper
{
  template<typename Q> static boost_kahypar::true_type  test(decltype(&Q::operator())*);
  template<typename>   static boost_kahypar::false_type test(...);

  using type=decltype(test<T>(nullptr));
};

template<typename T>
using has_one_operator_call=typename has_one_operator_call_helper<T>::type;

template<typename T>
struct equivalent_function_pointer
{
  template<typename Q,typename R,typename... Args>
  static auto helper(R (Q::*)(Args...)const)->R(*)(Args...);
  template<typename Q,typename R,typename... Args>
  static auto helper(R (Q::*)(Args...))->R(*)(Args...);

  using type=decltype(helper(&T::operator()));
};

template<typename T,typename=void>
struct is_likely_stateless_lambda : false_type{};

template<typename T>
struct is_likely_stateless_lambda<
  T,
  typename boost_kahypar::enable_if_<has_one_operator_call<T>::value>::type> :
     boost_kahypar::is_convertible<T, typename equivalent_function_pointer<T>::type
>{};

} /* namespace type_traits_detail */

} /* namespace boost_kahypar */

#else
 //
 // Can't implement this:
 //
namespace boost_kahypar {
   namespace type_traits_detail {

      template<typename T>
      struct is_likely_stateless_lambda : public boost_kahypar::integral_constant<bool, false> {};
}}

#endif
#endif

