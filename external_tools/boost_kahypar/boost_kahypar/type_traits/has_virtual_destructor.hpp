
//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef BOOST_TT_HAS_VIRTUAL_DESTRUCTOR_HPP_INCLUDED
#define BOOST_TT_HAS_VIRTUAL_DESTRUCTOR_HPP_INCLUDED

#include <boost_kahypar/type_traits/intrinsics.hpp>
#include <boost_kahypar/type_traits/integral_constant.hpp>

namespace boost_kahypar {

#ifdef BOOST_HAS_VIRTUAL_DESTRUCTOR
   template <class T> struct has_virtual_destructor : public integral_constant<bool, BOOST_HAS_VIRTUAL_DESTRUCTOR(T)>{};
#else
   template <class T> struct has_virtual_destructor : public integral_constant<bool, false>{};
#endif

} // namespace boost_kahypar

#endif // BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
