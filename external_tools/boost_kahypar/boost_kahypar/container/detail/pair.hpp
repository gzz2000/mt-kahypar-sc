//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2013.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_CONTAINER_DETAIL_PAIR_HPP
#define BOOST_CONTAINER_CONTAINER_DETAIL_PAIR_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/container/detail/config_begin.hpp>
#include <boost_kahypar/container/container_fwd.hpp>
#include <boost_kahypar/container/detail/workaround.hpp>

#include <boost_kahypar/container/detail/mpl.hpp>
#include <boost_kahypar/container/detail/type_traits.hpp>
#include <boost_kahypar/container/detail/mpl.hpp>
#include <boost_kahypar/container/detail/std_fwd.hpp>
#include <boost_kahypar/container/detail/is_pair.hpp>   //Forward declares boost_kahypar::tuples::tuple
#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#  include <boost_kahypar/container/detail/variadic_templates_tools.hpp>
#endif
#include <boost_kahypar/move/adl_move_swap.hpp> //swap

#include <boost_kahypar/intrusive/detail/minimal_pair_header.hpp>      //pair
#include <boost_kahypar/move/utility_core.hpp>
#include <boost_kahypar/move/detail/fwd_macros.hpp>

namespace boost_kahypar {
namespace container {
namespace pair_impl {

template <class TupleClass>
struct is_boost_tuple
{
   BOOST_STATIC_CONSTEXPR bool value = false;
};

template <
  class T0, class T1, class T2,
  class T3, class T4, class T5,
  class T6, class T7, class T8,
  class T9>
struct is_boost_tuple< boost_kahypar::tuples::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9> >
{
   BOOST_STATIC_CONSTEXPR bool value = true;
};

template<class Tuple>
struct disable_if_boost_tuple
   : boost_kahypar::container::dtl::disable_if< is_boost_tuple<Tuple> >
{};

template<class T>
struct is_tuple_null
{
   BOOST_STATIC_CONSTEXPR bool value = false;
};

template<>
struct is_tuple_null<boost_kahypar::tuples::null_type>
{
   BOOST_STATIC_CONSTEXPR bool value = true;
};

}  //namespace detail {

#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

   template <int Dummy = 0>
   struct std_piecewise_construct_holder
   {
      static ::std::piecewise_construct_t *dummy;
   };

   template <int Dummy>
   ::std::piecewise_construct_t *std_piecewise_construct_holder<Dummy>::dummy =
      reinterpret_cast< ::std::piecewise_construct_t *>(0x01234);  //Avoid sanitizer errors on references to null pointers

#else

//! The piecewise_construct_t struct is an empty structure type used as a unique type to
//! disambiguate used to disambiguate between different functions that take two tuple arguments.
typedef unspecified piecewise_construct_t;

#endif   //#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

//! A instance of type
//! piecewise_construct_t
static piecewise_construct_t piecewise_construct = BOOST_CONTAINER_DOC1ST(unspecified, *std_piecewise_construct_holder<>::dummy);

///@cond

namespace dtl {

struct piecewise_construct_use
{
   //Avoid warnings of unused "piecewise_construct"
   piecewise_construct_use()
   {  (void)&::boost_kahypar::container::piecewise_construct;   }
};

struct pair_nat;

template<typename T, typename U, typename V>
void get(T); //to enable ADL

///@endcond

#ifdef  _LIBCPP_DEPRECATED_ABI_DISABLE_PAIR_TRIVIAL_COPY_CTOR
//Libc++, in some versions, has an ABI breakage that needs some
//padding in dtl::pair, as "std::pair::first" is not at offset zero.
//See: https://reviews.llvm.org/D56357 for more information.
//
template <class T1, class T2, std::size_t N>
struct pair_padding
{
   char padding[N];
};

template <class T1, class T2>
struct pair_padding<T1, T2, 0>
{
};

template <class T1, class T2>
struct simple_pair
{
   T1 first;
   T2 second;
};

#endif

template <class T1, class T2>
struct pair
#ifdef  _LIBCPP_DEPRECATED_ABI_DISABLE_PAIR_TRIVIAL_COPY_CTOR
   : pair_padding<T1, T2, sizeof(std::pair<T1, T2>) - sizeof(simple_pair<T1, T2>)>
#endif
{
   private:
   BOOST_COPYABLE_AND_MOVABLE(pair)

   public:
   typedef T1 first_type;
   typedef T2 second_type;

   T1 first;
   T2 second;

   //Default constructor
   pair()
      : first(), second()
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   //pair copy assignment
   pair(const pair& x)
      : first(x.first), second(x.second)
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   //pair move constructor
   pair(BOOST_RV_REF(pair) p)
      : first(::boost_kahypar::move(BOOST_MOVE_TO_LV(p).first)), second(::boost_kahypar::move(BOOST_MOVE_TO_LV(p).second))
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   template <class D, class S>
   pair(const pair<D, S> &p)
      : first(p.first), second(p.second)
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   template <class D, class S>
   pair(BOOST_RV_REF_BEG pair<D, S> BOOST_RV_REF_END p)
      : first(::boost_kahypar::move(BOOST_MOVE_TO_LV(p).first)), second(::boost_kahypar::move(BOOST_MOVE_TO_LV(p).second))
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   //pair from two values
   pair(const T1 &t1, const T2 &t2)
      : first(t1)
      , second(t2)
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   template<class U, class V>
   pair(BOOST_FWD_REF(U) u, BOOST_FWD_REF(V) v)
      : first(::boost_kahypar::forward<U>(u))
      , second(::boost_kahypar::forward<V>(v))
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   //And now compatibility with std::pair
   pair(const std::pair<T1, T2>& x)
      : first(x.first), second(x.second)
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   template <class D, class S>
   pair(const std::pair<D, S>& p)
      : first(p.first), second(p.second)
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   pair(BOOST_RV_REF_BEG std::pair<T1, T2> BOOST_RV_REF_END p)
      : first(::boost_kahypar::move(BOOST_MOVE_TO_LV(p).first)), second(::boost_kahypar::move(BOOST_MOVE_TO_LV(p).second))
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   template <class D, class S>
   pair(BOOST_RV_REF_BEG std::pair<D, S> BOOST_RV_REF_END p)
      : first(::boost_kahypar::move(BOOST_MOVE_TO_LV(p).first)), second(::boost_kahypar::move(BOOST_MOVE_TO_LV(p).second))
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }

   #if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
   template< class KeyType, class ...Args>
   pair(try_emplace_t, BOOST_FWD_REF(KeyType) k, Args && ...args)
      : first(boost_kahypar::forward<KeyType>(k)), second(::boost_kahypar::forward<Args>(args)...)\
   {
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
   }
   #else

   //piecewise construction from boost_kahypar::tuple
   #define BOOST_PAIR_TRY_EMPLACE_CONSTRUCT_CODE(N)\
   template< class KeyType BOOST_MOVE_I##N BOOST_MOVE_CLASS##N > \
   pair( try_emplace_t, BOOST_FWD_REF(KeyType) k BOOST_MOVE_I##N BOOST_MOVE_UREF##N )\
      : first(boost_kahypar::forward<KeyType>(k)), second(BOOST_MOVE_FWD##N)\
   {\
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));\
   }\
   //
   BOOST_MOVE_ITERATE_0TO9(BOOST_PAIR_TRY_EMPLACE_CONSTRUCT_CODE)
   #undef BOOST_PAIR_TRY_EMPLACE_CONSTRUCT_CODE

   #endif   //BOOST_NO_CXX11_VARIADIC_TEMPLATES

   //piecewise construction from boost_kahypar::tuple
   #define BOOST_PAIR_PIECEWISE_CONSTRUCT_BOOST_TUPLE_CODE(N,M)\
   template< template<class, class, class, class, class, class, class, class, class, class> class BoostTuple \
            BOOST_MOVE_I_IF(BOOST_MOVE_OR(N,M)) BOOST_MOVE_CLASS##N BOOST_MOVE_I_IF(BOOST_MOVE_AND(N,M)) BOOST_MOVE_CLASSQ##M > \
   pair( piecewise_construct_t\
       , BoostTuple<BOOST_MOVE_TARG##N  BOOST_MOVE_I##N BOOST_MOVE_REPEAT(BOOST_MOVE_SUB(10,N),::boost_kahypar::tuples::null_type)> p\
       , BoostTuple<BOOST_MOVE_TARGQ##M BOOST_MOVE_I##M BOOST_MOVE_REPEAT(BOOST_MOVE_SUB(10,M),::boost_kahypar::tuples::null_type)> q\
       , typename dtl::enable_if_c\
         < pair_impl::is_boost_tuple< BoostTuple<BOOST_MOVE_TARG##N  BOOST_MOVE_I##N BOOST_MOVE_REPEAT(BOOST_MOVE_SUB(10,N),::boost_kahypar::tuples::null_type)> >::value &&\
           !(pair_impl::is_tuple_null<BOOST_MOVE_LAST_TARG##N>::value || pair_impl::is_tuple_null<BOOST_MOVE_LAST_TARGQ##M>::value) \
         >::type* = 0\
       )\
      : first(BOOST_MOVE_TMPL_GET##N), second(BOOST_MOVE_TMPL_GETQ##M)\
   { (void)p; (void)q;\
      BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));\
   }\
   //
   BOOST_MOVE_ITER2D_0TOMAX(9, BOOST_PAIR_PIECEWISE_CONSTRUCT_BOOST_TUPLE_CODE)
   #undef BOOST_PAIR_PIECEWISE_CONSTRUCT_BOOST_TUPLE_CODE

   //piecewise construction from variadic tuple (with delegating constructors)
   #if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
   #  if !defined(BOOST_CONTAINER_NO_CXX11_DELEGATING_CONSTRUCTORS)
      private:
      template<template<class ...> class Tuple, class... Args1, class... Args2, size_t... Indexes1, size_t... Indexes2>
      pair(Tuple<Args1...>& t1, Tuple<Args2...>& t2, index_tuple<Indexes1...>, index_tuple<Indexes2...>)
         : first (::boost_kahypar::forward<Args1>(get<Indexes1>(t1))...)
         , second(::boost_kahypar::forward<Args2>(get<Indexes2>(t2))...)
      {  (void) t1; (void)t2; }

      public:
      template< template<class ...> class Tuple, class... Args1, class... Args2
              , class = typename pair_impl::disable_if_boost_tuple< Tuple<Args1...> >::type>
      pair(piecewise_construct_t, Tuple<Args1...> t1, Tuple<Args2...> t2)
         : pair(t1, t2, typename build_number_seq<sizeof...(Args1)>::type(), typename build_number_seq<sizeof...(Args2)>::type())
      {
         BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
      }
   #  else
      //piecewise construction from variadic tuple (suboptimal, without delegating constructors)
      private:
      template<typename T, template<class ...> class Tuple, typename... Args>
      static T build_from_args(Tuple<Args...>&& t)
      {  return do_build_from_args<T>(::boost_kahypar::move(t), typename build_number_seq<sizeof...(Args)>::type());   }

      template<typename T, template<class ...> class Tuple, typename... Args, std::size_t... Indexes>
      static T do_build_from_args(Tuple<Args...> && t, const index_tuple<Indexes...>&)
      {  (void)t; return T(::boost_kahypar::forward<Args>(get<Indexes>(t))...);  }

      public:
      template< template<class ...> class Tuple, class... Args1, class... Args2
              , class = typename pair_impl::disable_if_boost_tuple< Tuple<Args1...> >::type>
      pair(piecewise_construct_t, Tuple<Args1...> t1, Tuple<Args2...> t2)
         : first  (build_from_args<first_type> (::boost_kahypar::move(t1)))
         , second (build_from_args<second_type>(::boost_kahypar::move(t2)))
      {
         BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));
      }
   #  endif   //BOOST_NO_CXX11_VARIADIC_TEMPLATES
   #elif defined(BOOST_MSVC) && (_CPPLIB_VER == 520)
      //MSVC 2010 tuple implementation
      #define BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2010_TUPLE_CODE(N,M)\
      template< template<class, class, class, class, class, class, class, class, class, class> class StdTuple \
               BOOST_MOVE_I_IF(BOOST_MOVE_OR(N,M)) BOOST_MOVE_CLASS##N BOOST_MOVE_I_IF(BOOST_MOVE_AND(N,M)) BOOST_MOVE_CLASSQ##M > \
      pair( piecewise_construct_t\
          , StdTuple<BOOST_MOVE_TARG##N  BOOST_MOVE_I##N BOOST_MOVE_REPEAT(BOOST_MOVE_SUB(10,N),::std::tr1::_Nil)> p\
          , StdTuple<BOOST_MOVE_TARGQ##M BOOST_MOVE_I##M BOOST_MOVE_REPEAT(BOOST_MOVE_SUB(10,M),::std::tr1::_Nil)> q)\
         : first(BOOST_MOVE_GET_IDX##N), second(BOOST_MOVE_GET_IDXQ##M)\
      { (void)p; (void)q;\
         BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));\
      }\
      //
      BOOST_MOVE_ITER2D_0TOMAX(9, BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2010_TUPLE_CODE)
      #undef BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2010_TUPLE_CODE
   #elif defined(BOOST_MSVC) && (_CPPLIB_VER == 540)
      #if _VARIADIC_MAX >= 9
      #define BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2012_TUPLE_MAX_IT 9
      #else
      #define BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2012_TUPLE_MAX_IT BOOST_MOVE_ADD(_VARIADIC_MAX, 1)
      #endif

      //MSVC 2012 tuple implementation
      #define BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2012_TUPLE_CODE(N,M)\
      template< template<BOOST_MOVE_REPEAT(_VARIADIC_MAX, class), class, class, class> class StdTuple \
               BOOST_MOVE_I_IF(BOOST_MOVE_OR(N,M)) BOOST_MOVE_CLASS##N BOOST_MOVE_I_IF(BOOST_MOVE_AND(N,M)) BOOST_MOVE_CLASSQ##M > \
      pair( piecewise_construct_t\
          , StdTuple<BOOST_MOVE_TARG##N  BOOST_MOVE_I##N BOOST_MOVE_REPEAT(BOOST_MOVE_SUB(BOOST_MOVE_ADD(_VARIADIC_MAX, 3),N),::std::_Nil) > p\
          , StdTuple<BOOST_MOVE_TARGQ##M BOOST_MOVE_I##M BOOST_MOVE_REPEAT(BOOST_MOVE_SUB(BOOST_MOVE_ADD(_VARIADIC_MAX, 3),M),::std::_Nil) > q)\
         : first(BOOST_MOVE_GET_IDX##N), second(BOOST_MOVE_GET_IDXQ##M)\
      { (void)p; (void)q;\
         BOOST_CONTAINER_STATIC_ASSERT((sizeof(std::pair<T1, T2>) == sizeof(pair<T1, T2>)));\
      }\
      //
      BOOST_MOVE_ITER2D_0TOMAX(BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2012_TUPLE_MAX_IT, BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2012_TUPLE_CODE)
      #undef BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2010_TUPLE_CODE
      #undef BOOST_PAIR_PIECEWISE_CONSTRUCT_MSVC2012_TUPLE_MAX_IT
   #endif

   //pair copy assignment
   pair& operator=(BOOST_COPY_ASSIGN_REF(pair) p)
   {
      first  = p.first;
      second = p.second;
      return *this;
   }

   //pair move assignment
   pair& operator=(BOOST_RV_REF(pair) p)
   {
      first  = ::boost_kahypar::move(BOOST_MOVE_TO_LV(p).first);
      second = ::boost_kahypar::move(BOOST_MOVE_TO_LV(p).second);
      return *this;
   }

   template <class D, class S>
   typename ::boost_kahypar::container::dtl::disable_if_or
      < pair &
      , ::boost_kahypar::container::dtl::is_same<T1, D>
      , ::boost_kahypar::container::dtl::is_same<T2, S>
      >::type
      operator=(const pair<D, S>&p)
   {
      first  = p.first;
      second = p.second;
      return *this;
   }

   template <class D, class S>
   typename ::boost_kahypar::container::dtl::disable_if_or
      < pair &
      , ::boost_kahypar::container::dtl::is_same<T1, D>
      , ::boost_kahypar::container::dtl::is_same<T2, S>
      >::type
      operator=(BOOST_RV_REF_BEG pair<D, S> BOOST_RV_REF_END p)
   {
      first  = ::boost_kahypar::move(BOOST_MOVE_TO_LV(p).first);
      second = ::boost_kahypar::move(BOOST_MOVE_TO_LV(p).second);
      return *this;
   }
//std::pair copy assignment
   pair& operator=(const std::pair<T1, T2> &p)
   {
      first  = p.first;
      second = p.second;
      return *this;
   }

   template <class D, class S>
   pair& operator=(const std::pair<D, S> &p)
   {
      first  = ::boost_kahypar::move(p.first);
      second = ::boost_kahypar::move(p.second);
      return *this;
   }

   //std::pair move assignment
   pair& operator=(BOOST_RV_REF_BEG std::pair<T1, T2> BOOST_RV_REF_END p)
   {
      first  = ::boost_kahypar::move(BOOST_MOVE_TO_LV(p).first);
      second = ::boost_kahypar::move(BOOST_MOVE_TO_LV(p).second);
      return *this;
   }

   template <class D, class S>
   pair& operator=(BOOST_RV_REF_BEG std::pair<D, S> BOOST_RV_REF_END p)
   {
      first  = ::boost_kahypar::move(BOOST_MOVE_TO_LV(p).first);
      second = ::boost_kahypar::move(BOOST_MOVE_TO_LV(p).second);
      return *this;
   }

   //swap
   void swap(pair& p)
   {
      ::boost_kahypar::adl_move_swap(this->first, p.first);
      ::boost_kahypar::adl_move_swap(this->second, p.second);
   }
};

template <class T1, class T2>
inline bool operator==(const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(x.first == y.first && x.second == y.second);  }

template <class T1, class T2>
inline bool operator< (const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(x.first < y.first ||
                         (!(y.first < x.first) && x.second < y.second)); }

template <class T1, class T2>
inline bool operator!=(const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(!(x == y));  }

template <class T1, class T2>
inline bool operator> (const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return y < x;  }

template <class T1, class T2>
inline bool operator>=(const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(!(x < y)); }

template <class T1, class T2>
inline bool operator<=(const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(!(y < x)); }

template <class T1, class T2>
inline pair<T1, T2> make_pair(T1 x, T2 y)
{  return pair<T1, T2>(x, y); }

template <class T1, class T2>
inline void swap(pair<T1, T2>& x, pair<T1, T2>& y)
{  x.swap(y);  }

}  //namespace dtl {
}  //namespace container {

#ifdef BOOST_NO_CXX11_RVALUE_REFERENCES

template<class T1, class T2>
struct has_move_emulation_enabled< ::boost_kahypar::container::dtl::pair<T1, T2> >
{
   BOOST_STATIC_CONSTEXPR bool value = true;
};

#endif

namespace move_detail{

template<class T>
struct is_class_or_union;

template <class T1, class T2>
struct is_class_or_union< ::boost_kahypar::container::dtl::pair<T1, T2> >
//This specialization is needed to avoid instantiation of pair in
//is_class, and allow recursive maps.
{
   BOOST_STATIC_CONSTEXPR bool value = true;
};

template <class T1, class T2>
struct is_class_or_union< std::pair<T1, T2> >
//This specialization is needed to avoid instantiation of pair in
//is_class, and allow recursive maps.
{
   BOOST_STATIC_CONSTEXPR bool value = true;
};

template<class T>
struct is_union;

template <class T1, class T2>
struct is_union< ::boost_kahypar::container::dtl::pair<T1, T2> >
//This specialization is needed to avoid instantiation of pair in
//is_class, and allow recursive maps.
{
   BOOST_STATIC_CONSTEXPR bool value = false;
};

template <class T1, class T2>
struct is_union< std::pair<T1, T2> >
//This specialization is needed to avoid instantiation of pair in
//is_class, and allow recursive maps.
{
   BOOST_STATIC_CONSTEXPR bool value = false;
};

template<class T>
struct is_class;

template <class T1, class T2>
struct is_class< ::boost_kahypar::container::dtl::pair<T1, T2> >
//This specialization is needed to avoid instantiation of pair in
//is_class, and allow recursive maps.
{
   BOOST_STATIC_CONSTEXPR bool value = true;
};

template <class T1, class T2>
struct is_class< std::pair<T1, T2> >
//This specialization is needed to avoid instantiation of pair in
//is_class, and allow recursive maps.
{
   BOOST_STATIC_CONSTEXPR bool value = true;
};


//Triviality of pair
template<class T>
struct is_trivially_copy_constructible;

template<class A, class B>
struct is_trivially_copy_assignable
   <boost_kahypar::container::dtl::pair<A,B> >
{
   BOOST_STATIC_CONSTEXPR bool value = false ;
};

template<class T>
struct is_trivially_move_constructible;

template<class A, class B>
struct is_trivially_move_assignable
   <boost_kahypar::container::dtl::pair<A,B> >
{
   BOOST_STATIC_CONSTEXPR bool value = false;
};

template<class T>
struct is_trivially_copy_assignable;

template<class A, class B>
struct is_trivially_copy_constructible<boost_kahypar::container::dtl::pair<A,B> >
{
   BOOST_STATIC_CONSTEXPR bool value = false;
};

template<class T>
struct is_trivially_move_assignable;

template<class A, class B>
struct is_trivially_move_constructible<boost_kahypar::container::dtl::pair<A,B> >
{
   BOOST_STATIC_CONSTEXPR bool value = false;
};

template<class T>
struct is_trivially_destructible;

template<class A, class B>
struct is_trivially_destructible<boost_kahypar::container::dtl::pair<A,B> >
{
   BOOST_STATIC_CONSTEXPR bool value = boost_kahypar::move_detail::is_trivially_destructible<A>::value &&
                             boost_kahypar::move_detail::is_trivially_destructible<B>::value ;
};


}  //namespace move_detail{

}  //namespace boost_kahypar {

#include <boost_kahypar/container/detail/config_end.hpp>

#endif   //#ifndef BOOST_CONTAINER_DETAIL_PAIR_HPP
