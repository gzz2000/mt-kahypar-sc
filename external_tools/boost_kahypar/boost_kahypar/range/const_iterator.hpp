// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef BOOST_RANGE_CONST_ITERATOR_HPP
#define BOOST_RANGE_CONST_ITERATOR_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <boost_kahypar/range/config.hpp>

#include <boost_kahypar/range/range_fwd.hpp>
#include <boost_kahypar/range/detail/extract_optional_type.hpp>
#include <boost_kahypar/type_traits/remove_const.hpp>
#include <boost_kahypar/type_traits/remove_reference.hpp>
#include <cstddef>
#include <utility>

namespace boost_kahypar
{
    //////////////////////////////////////////////////////////////////////////
    // default
    //////////////////////////////////////////////////////////////////////////
    
    namespace range_detail
    {

BOOST_RANGE_EXTRACT_OPTIONAL_TYPE( const_iterator )

template< typename C >
struct range_const_iterator_helper
        : extract_const_iterator<C>
{};

//////////////////////////////////////////////////////////////////////////
// pair
//////////////////////////////////////////////////////////////////////////

template< typename Iterator >
struct range_const_iterator_helper<std::pair<Iterator,Iterator> >
{
    typedef Iterator type;
};

//////////////////////////////////////////////////////////////////////////
// array
//////////////////////////////////////////////////////////////////////////

template< typename T, std::size_t sz >
struct range_const_iterator_helper< T[sz] >
{
    typedef const T* type;
};

    } // namespace range_detail

template<typename C, typename Enabler=void>
struct range_const_iterator
        : range_detail::range_const_iterator_helper<
            BOOST_DEDUCED_TYPENAME remove_reference<C>::type
        >
{
};

} // namespace boost_kahypar


#endif
