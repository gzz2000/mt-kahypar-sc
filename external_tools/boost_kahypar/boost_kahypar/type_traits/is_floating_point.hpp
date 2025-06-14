//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000-2005.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TYPE_TRAITS_IS_FLOATING_HPP_INCLUDED
#define BOOST_TYPE_TRAITS_IS_FLOATING_HPP_INCLUDED

#include <boost_kahypar/type_traits/integral_constant.hpp>

#ifndef BOOST_NO_CXX23_HDR_STDFLOAT
#include <stdfloat>
#endif

namespace boost_kahypar {

//* is a type T a floating-point type described in the standard (3.9.1p8)
   template <class T> struct is_floating_point : public false_type{};
   template <class T> struct is_floating_point<const T> : public is_floating_point<T>{};
   template <class T> struct is_floating_point<volatile const T> : public is_floating_point<T>{};
   template <class T> struct is_floating_point<volatile T> : public is_floating_point<T>{};
   template<> struct is_floating_point<float> : public true_type{};
   template<> struct is_floating_point<double> : public true_type{};
   template<> struct is_floating_point<long double> : public true_type{};
   
#if defined(BOOST_HAS_FLOAT128)
   template<> struct is_floating_point<__float128> : public true_type{};
#endif

#ifndef BOOST_NO_CXX23_HDR_STDFLOAT
#if defined(__STDCPP_FLOAT16_T__)
   template<> struct is_floating_point<std::float16_t> : public true_type {};
#endif
#if defined(__STDCPP_FLOAT32_T__)
   template<> struct is_floating_point<std::float32_t> : public true_type {};
#endif
#if defined(__STDCPP_FLOAT64_T__)
   template<> struct is_floating_point<std::float64_t> : public true_type {};
#endif
#if defined(__STDCPP_FLOAT128_T__)
   template<> struct is_floating_point<std::float128_t> : public true_type {};
#endif
#if defined(__STDCPP_BFLOAT16_T__)
   template<> struct is_floating_point<std::bfloat16_t> : public true_type {};
#endif
#endif

} // namespace boost_kahypar

#endif // BOOST_TYPE_TRAITS_IS_FLOAT_HPP_INCLUDED
