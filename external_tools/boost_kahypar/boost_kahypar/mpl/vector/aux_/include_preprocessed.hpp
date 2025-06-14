
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

// Copyright Aleksey Gurtovoy 2000-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost_kahypar/mpl/aux_/config/typeof.hpp>
#include <boost_kahypar/mpl/aux_/config/ctps.hpp>
#include <boost_kahypar/mpl/aux_/config/preprocessor.hpp>
#include <boost_kahypar/mpl/aux_/config/workaround.hpp>

#include <boost_kahypar/preprocessor/cat.hpp>
#include <boost_kahypar/preprocessor/stringize.hpp>

#if defined(BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)
#   define AUX778076_INCLUDE_DIR typeof_based
#elif defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
   || defined(BOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC)
#   define AUX778076_INCLUDE_DIR no_ctps
#else
#   define AUX778076_INCLUDE_DIR plain
#endif

#if !defined(BOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_HEADER \
    AUX778076_INCLUDE_DIR/BOOST_MPL_PREPROCESSED_HEADER \
/**/
#else
#   define AUX778076_HEADER \
    BOOST_PP_CAT(AUX778076_INCLUDE_DIR,/)##BOOST_MPL_PREPROCESSED_HEADER \
/**/
#endif


#if BOOST_WORKAROUND(__IBMCPP__, BOOST_TESTED_AT(700))
#   define AUX778076_INCLUDE_STRING BOOST_PP_STRINGIZE(boost_kahypar/mpl/vector/aux_/preprocessed/AUX778076_HEADER)
#   include AUX778076_INCLUDE_STRING
#   undef AUX778076_INCLUDE_STRING
#else
#   include BOOST_PP_STRINGIZE(boost_kahypar/mpl/vector/aux_/preprocessed/AUX778076_HEADER)
#endif

#   undef AUX778076_HEADER
#   undef AUX778076_INCLUDE_DIR

#undef BOOST_MPL_PREPROCESSED_HEADER
