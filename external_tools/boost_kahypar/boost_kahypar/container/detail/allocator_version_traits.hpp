//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2012-2013. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_DETAIL_ALLOCATOR_VERSION_TRAITS_HPP
#define BOOST_CONTAINER_DETAIL_ALLOCATOR_VERSION_TRAITS_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/container/detail/config_begin.hpp>
#include <boost_kahypar/container/detail/workaround.hpp>

#include <boost_kahypar/container/allocator_traits.hpp>             //allocator_traits
#include <boost_kahypar/container/throw_exception.hpp>
#include <boost_kahypar/container/detail/multiallocation_chain.hpp> //multiallocation_chain
#include <boost_kahypar/container/detail/version_type.hpp>          //version_type
#include <boost_kahypar/container/detail/allocation_type.hpp>       //allocation_type
#include <boost_kahypar/container/detail/mpl.hpp>                   //integral_constant
#include <boost_kahypar/intrusive/pointer_traits.hpp>               //pointer_traits

namespace boost_kahypar {
namespace container {
namespace dtl {

template<class Allocator, unsigned Version = boost_kahypar::container::dtl::version<Allocator>::value>
struct allocator_version_traits
{
   typedef ::boost_kahypar::container::dtl::integral_constant
      <unsigned, Version> alloc_version;

   typedef typename Allocator::multiallocation_chain multiallocation_chain;

   typedef typename boost_kahypar::container::allocator_traits<Allocator>::pointer    pointer;
   typedef typename boost_kahypar::container::allocator_traits<Allocator>::size_type  size_type;

   //Node allocation interface
   inline static pointer allocate_one(Allocator &a)
   {  return a.allocate_one();   }

   inline static void deallocate_one(Allocator &a, const pointer &p)
   {  a.deallocate_one(p);   }

   inline static void allocate_individual(Allocator &a, size_type n, multiallocation_chain &m)
   {  return a.allocate_individual(n, m);   }

   inline static void deallocate_individual(Allocator &a, multiallocation_chain &holder)
   {  a.deallocate_individual(holder);   }

   inline static pointer allocation_command(Allocator &a, allocation_type command,
                         size_type limit_size, size_type &prefer_in_recvd_out_size, pointer &reuse)
   {  return a.allocation_command(command, limit_size, prefer_in_recvd_out_size, reuse);  }
};

template<class Allocator>
struct allocator_version_traits<Allocator, 1>
{
   typedef ::boost_kahypar::container::dtl::integral_constant
      <unsigned, 1> alloc_version;

   typedef typename boost_kahypar::container::allocator_traits<Allocator>::pointer    pointer;
   typedef typename boost_kahypar::container::allocator_traits<Allocator>::size_type  size_type;
   typedef typename boost_kahypar::container::allocator_traits<Allocator>::value_type value_type;

   typedef typename boost_kahypar::intrusive::pointer_traits<pointer>::
         template rebind_pointer<void>::type                void_ptr;
   typedef dtl::basic_multiallocation_chain
      <void_ptr>                                            multialloc_cached_counted;
   typedef boost_kahypar::container::dtl::
      transform_multiallocation_chain
         < multialloc_cached_counted, value_type>           multiallocation_chain;

   //Node allocation interface
   inline static pointer allocate_one(Allocator &a)
   {  return a.allocate(1);   }

   inline static void deallocate_one(Allocator &a, const pointer &p)
   {  a.deallocate(p, 1);   }

   static void deallocate_individual(Allocator &a, multiallocation_chain &holder)
   {
      size_type n = holder.size();
      typename multiallocation_chain::iterator it = holder.begin();
      while(n){
         --n;
         pointer p = boost_kahypar::intrusive::pointer_traits<pointer>::pointer_to(*it);
         ++it;
         a.deallocate(p, 1);
      }
   }

   struct allocate_individual_rollback
   {
      inline allocate_individual_rollback(Allocator &a, multiallocation_chain &chain)
         : mr_a(a), mp_chain(&chain)
      {}

      inline ~allocate_individual_rollback()
      {
         if(mp_chain)
            allocator_version_traits::deallocate_individual(mr_a, *mp_chain);
      }

      inline void release()
      {
         mp_chain = 0;
      }

      Allocator &mr_a;
      multiallocation_chain * mp_chain;
   };

   static void allocate_individual(Allocator &a, size_type n, multiallocation_chain &m)
   {
      allocate_individual_rollback rollback(a, m);
      while(n--){
         m.push_front(a.allocate(1));
      }
      rollback.release();
   }

   static pointer allocation_command(Allocator &a, allocation_type command,
                         size_type, size_type &prefer_in_recvd_out_size, pointer &reuse)
   {
      pointer ret = pointer();
      if(BOOST_UNLIKELY(!(command & allocate_new) && !(command & nothrow_allocation))){
         throw_logic_error("version 1 allocator without allocate_new flag");
      }
      else{
         BOOST_CONTAINER_TRY{
            ret = a.allocate(prefer_in_recvd_out_size);
         }
         BOOST_CONTAINER_CATCH(...){
            if(!(command & nothrow_allocation)){
               BOOST_CONTAINER_RETHROW
            }
         }
         BOOST_CONTAINER_CATCH_END
         reuse = pointer();
      }
      return ret;
   }
};

}  //namespace dtl {
}  //namespace container {
}  //namespace boost_kahypar {

#include <boost_kahypar/container/detail/config_end.hpp>

#endif // ! defined(BOOST_CONTAINER_DETAIL_ALLOCATOR_VERSION_TRAITS_HPP)
