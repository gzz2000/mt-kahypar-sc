
#if !defined(BOOST_PP_IS_ITERATING)

///// header body

#ifndef BOOST_MPL_AUX778076_ADVANCE_BACKWARD_HPP_INCLUDED
#define BOOST_MPL_AUX778076_ADVANCE_BACKWARD_HPP_INCLUDED

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

#if !defined(BOOST_MPL_PREPROCESSING_MODE)
#   include <boost_kahypar/mpl/prior.hpp>
#   include <boost_kahypar/mpl/apply_wrap.hpp>
#endif

#include <boost_kahypar/mpl/aux_/config/use_preprocessed.hpp>

#if    !defined(BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(BOOST_MPL_PREPROCESSING_MODE)

#   define BOOST_MPL_PREPROCESSED_HEADER advance_backward.hpp
#   include <boost_kahypar/mpl/aux_/include_preprocessed.hpp>

#else

#   include <boost_kahypar/mpl/limits/unrolling.hpp>
#   include <boost_kahypar/mpl/aux_/nttp_decl.hpp>
#   include <boost_kahypar/mpl/aux_/config/eti.hpp>

#   include <boost_kahypar/preprocessor/iterate.hpp>
#   include <boost_kahypar/preprocessor/cat.hpp>
#   include <boost_kahypar/preprocessor/inc.hpp>

namespace boost_kahypar { namespace mpl { namespace aux {

// forward declaration
template< BOOST_MPL_AUX_NTTP_DECL(long, N) > struct advance_backward;

#   define BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, BOOST_MPL_LIMIT_UNROLLING, <boost_kahypar/mpl/aux_/advance_backward.hpp>))
#   include BOOST_PP_ITERATE()

// implementation for N that exceeds BOOST_MPL_LIMIT_UNROLLING
template< BOOST_MPL_AUX_NTTP_DECL(long, N) >
struct advance_backward
{
    template< typename Iterator > struct apply
    {
        typedef typename apply_wrap1<
              advance_backward<BOOST_MPL_LIMIT_UNROLLING>
            , Iterator
            >::type chunk_result_;

        typedef typename apply_wrap1<
              advance_backward<(
                (N - BOOST_MPL_LIMIT_UNROLLING) < 0
                    ? 0
                    : N - BOOST_MPL_LIMIT_UNROLLING
                    )>
            , chunk_result_
            >::type type;
    };
};

}}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_AUX778076_ADVANCE_BACKWARD_HPP_INCLUDED

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // BOOST_PP_IS_ITERATING
#if BOOST_PP_ITERATION_DEPTH() == 1
#define i_ BOOST_PP_FRAME_ITERATION(1)

template<>
struct advance_backward< BOOST_PP_FRAME_ITERATION(1) >
{
    template< typename Iterator > struct apply
    {
        typedef Iterator iter0;

#if i_ > 0
#   define BOOST_PP_ITERATION_PARAMS_2 \
    (3,(1, BOOST_PP_FRAME_ITERATION(1), <boost_kahypar/mpl/aux_/advance_backward.hpp>))
#   include BOOST_PP_ITERATE()
#endif

        typedef BOOST_PP_CAT(iter,BOOST_PP_FRAME_ITERATION(1)) type;
    };

#if defined(BOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct apply<int>
    {
        typedef int type;
    };
#endif
};

#undef i_

///// iteration, depth == 2

#elif BOOST_PP_ITERATION_DEPTH() == 2

#   define AUX778076_ITER_0 BOOST_PP_CAT(iter,BOOST_PP_DEC(BOOST_PP_FRAME_ITERATION(2)))
#   define AUX778076_ITER_1 BOOST_PP_CAT(iter,BOOST_PP_FRAME_ITERATION(2))

        typedef typename prior<AUX778076_ITER_0>::type AUX778076_ITER_1;
        
#   undef AUX778076_ITER_1
#   undef AUX778076_ITER_0

#endif // BOOST_PP_ITERATION_DEPTH()
#endif // BOOST_PP_IS_ITERATING
