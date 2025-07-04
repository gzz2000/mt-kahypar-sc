//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2014-2014.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_DETAIL_CONSTRUCT_IN_PLACE_HPP
#define BOOST_CONTAINER_DETAIL_CONSTRUCT_IN_PLACE_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/container/allocator_traits.hpp>
#include <boost_kahypar/container/detail/iterators.hpp>
#include <boost_kahypar/container/detail/value_init.hpp>
#include <boost_kahypar/container/detail/is_pair.hpp>

namespace boost_kahypar {
namespace container {

//In place construction

struct iterator_arg_t{};

template<class Allocator, class T, class InpIt>
BOOST_CONTAINER_FORCEINLINE void construct_in_place(Allocator &a, T* dest, InpIt source)
{     boost_kahypar::container::allocator_traits<Allocator>::construct(a, dest, *source);  }

template<class Allocator, class T, class U>
BOOST_CONTAINER_FORCEINLINE void construct_in_place(Allocator &a, T *dest, value_init_construct_iterator<U>)
{
   boost_kahypar::container::allocator_traits<Allocator>::construct(a, dest);
}

template <class T>
class default_init_construct_iterator;

template<class Allocator, class T, class U>
BOOST_CONTAINER_FORCEINLINE void construct_in_place(Allocator &a, T *dest, default_init_construct_iterator<U>)
{
   boost_kahypar::container::allocator_traits<Allocator>::construct(a, dest, default_init);
}

template <class T, class EmplaceFunctor>
class emplace_iterator;

template<class Allocator, class T, class U, class EF>
BOOST_CONTAINER_FORCEINLINE void construct_in_place(Allocator &a, T *dest, emplace_iterator<U, EF> ei)
{
   ei.construct_in_place(a, dest);
}

//Assignment

template<class T, class U>
BOOST_CONTAINER_FORCEINLINE
   typename dtl::disable_if_c
      <  dtl::is_pair<typename dtl::remove_reference<T>::type>::value
      && dtl::is_pair<typename dtl::remove_reference<U>::type>::value
      , void>::type
assign_in_place_ref(T &t, BOOST_FWD_REF(U) u)
{  t = ::boost_kahypar::forward<U>(u);  }

template<class T, class U>
BOOST_CONTAINER_FORCEINLINE
   typename dtl::enable_if_c
      <  dtl::is_pair<typename dtl::remove_reference<T>::type>::value
      && dtl::is_pair<typename dtl::remove_reference<U>::type>::value
      , void>::type
assign_in_place_ref(T &t, const U &u)
{
   assign_in_place_ref(t.first, u.first);
   assign_in_place_ref(t.second, u.second);
}

template<class T, class U>
BOOST_CONTAINER_FORCEINLINE
   typename dtl::enable_if_c
      <  dtl::is_pair<typename dtl::remove_reference<T>::type>::value
      && dtl::is_pair<typename dtl::remove_reference<U>::type>::value
      , void>::type
assign_in_place_ref(T &t, BOOST_RV_REF(U) u)
{
   assign_in_place_ref(t.first,  ::boost_kahypar::move(u.first));
   assign_in_place_ref(t.second, ::boost_kahypar::move(u.second));
}

template<class DstIt, class InpIt>
BOOST_CONTAINER_FORCEINLINE void assign_in_place(DstIt dest, InpIt source)
{  assign_in_place_ref(*dest, *source);  }

template<class DstIt, class U>
BOOST_CONTAINER_FORCEINLINE void assign_in_place(DstIt dest, value_init_construct_iterator<U>)
{
   dtl::value_init<U> val;
   *dest = boost_kahypar::move(val.get());
}

template <class DstIt>
class default_init_construct_iterator;

template<class DstIt, class U, class D>
BOOST_CONTAINER_FORCEINLINE void assign_in_place(DstIt dest, default_init_construct_iterator<U>)
{
   U u;
   *dest = boost_kahypar::move(u);
}

template <class T, class EmplaceFunctor>
class emplace_iterator;

template<class DstIt, class U, class EF>
BOOST_CONTAINER_FORCEINLINE void assign_in_place(DstIt dest, emplace_iterator<U, EF> ei)
{
   ei.assign_in_place(dest);
}

}  //namespace container {
}  //namespace boost_kahypar {

#endif   //#ifndef BOOST_CONTAINER_DETAIL_CONSTRUCT_IN_PLACE_HPP
