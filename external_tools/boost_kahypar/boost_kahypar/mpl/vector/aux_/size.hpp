
#ifndef BOOST_MPL_VECTOR_AUX_SIZE_HPP_INCLUDED
#define BOOST_MPL_VECTOR_AUX_SIZE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost_kahypar/mpl/size_fwd.hpp>
#include <boost_kahypar/mpl/vector/aux_/O1_size.hpp>
#include <boost_kahypar/mpl/vector/aux_/tag.hpp>
#include <boost_kahypar/mpl/aux_/config/typeof.hpp>
#include <boost_kahypar/mpl/aux_/config/ctps.hpp>

namespace boost_kahypar { namespace mpl {

#if defined(BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

template<>
struct size_impl< aux::vector_tag >
    : O1_size_impl< aux::vector_tag >
{
};

#else

#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< long N >
struct size_impl< aux::vector_tag<N> >
    : O1_size_impl< aux::vector_tag<N> >
{
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

}}

#endif // BOOST_MPL_VECTOR_AUX_SIZE_HPP_INCLUDED
