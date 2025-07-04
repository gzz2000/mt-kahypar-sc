
#ifndef BOOST_MPL_DISTANCE_HPP_INCLUDED
#define BOOST_MPL_DISTANCE_HPP_INCLUDED

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

#include <boost_kahypar/mpl/distance_fwd.hpp>
#include <boost_kahypar/mpl/iter_fold.hpp>
#include <boost_kahypar/mpl/iterator_range.hpp>
#include <boost_kahypar/mpl/long.hpp>
#include <boost_kahypar/mpl/next.hpp>
#include <boost_kahypar/mpl/tag.hpp>
#include <boost_kahypar/mpl/apply_wrap.hpp>
#include <boost_kahypar/mpl/aux_/msvc_eti_base.hpp>
#include <boost_kahypar/mpl/aux_/value_wknd.hpp>
#include <boost_kahypar/mpl/aux_/na_spec.hpp>
#include <boost_kahypar/mpl/aux_/config/forwarding.hpp>
#include <boost_kahypar/mpl/aux_/config/static_constant.hpp>


namespace boost_kahypar { namespace mpl {

// default implementation for forward/bidirectional iterators
template< typename Tag > struct distance_impl
{
    template< typename First, typename Last > struct apply
#if !defined(BOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : aux::msvc_eti_base< typename iter_fold<
              iterator_range<First,Last>
            , mpl::long_<0>
            , next<>
            >::type >
    {
#else
    {
        typedef typename iter_fold<
              iterator_range<First,Last>
            , mpl::long_<0>
            , next<>
            >::type type;
        
        BOOST_STATIC_CONSTANT(long, value =
              (iter_fold<
                  iterator_range<First,Last>
                , mpl::long_<0>
                , next<>
                >::type::value)
            );
#endif
    };
};

template<
      typename BOOST_MPL_AUX_NA_PARAM(First)
    , typename BOOST_MPL_AUX_NA_PARAM(Last)
    >
struct distance
    : distance_impl< typename tag<First>::type >
        ::template apply<First, Last>
{
    BOOST_MPL_AUX_LAMBDA_SUPPORT(2, distance, (First, Last))
};

BOOST_MPL_AUX_NA_SPEC(2, distance)

}}

#endif // BOOST_MPL_DISTANCE_HPP_INCLUDED
