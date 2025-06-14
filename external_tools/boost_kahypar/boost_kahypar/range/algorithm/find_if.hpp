//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_FIND_IF_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_FIND_IF_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/detail/range_return.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function find_if
///
/// range-based version of the find_if std algorithm
///
/// \pre SinglePassRange is a model of the SinglePassRangeConcept
/// \pre UnaryPredicate is a model of the UnaryPredicateConcept
template< class SinglePassRange, class UnaryPredicate >
inline BOOST_DEDUCED_TYPENAME disable_if<
    is_const<SinglePassRange>,
    BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type
>::type
find_if( SinglePassRange& rng, UnaryPredicate pred )
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<SinglePassRange> ));
    return std::find_if(boost_kahypar::begin(rng), boost_kahypar::end(rng), pred);
}

/// \overload
template< class SinglePassRange, class UnaryPredicate >
inline BOOST_DEDUCED_TYPENAME range_iterator<const SinglePassRange>::type
find_if( const SinglePassRange& rng, UnaryPredicate pred )
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange> ));
    return std::find_if(boost_kahypar::begin(rng), boost_kahypar::end(rng), pred);
}

// range_return overloads

/// \overload
template< range_return_value re, class SinglePassRange, class UnaryPredicate >
inline BOOST_DEDUCED_TYPENAME disable_if<
    is_const<SinglePassRange>,
    BOOST_DEDUCED_TYPENAME range_return<SinglePassRange,re>::type
>::type
find_if( SinglePassRange& rng, UnaryPredicate pred )
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<SinglePassRange> ));
    return range_return<SinglePassRange,re>::
        pack(std::find_if(boost_kahypar::begin(rng), boost_kahypar::end(rng), pred),
             rng);
}

/// \overload
template< range_return_value re, class SinglePassRange, class UnaryPredicate >
inline BOOST_DEDUCED_TYPENAME range_return<const SinglePassRange,re>::type
find_if( const SinglePassRange& rng, UnaryPredicate pred )
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange> ));
    return range_return<const SinglePassRange,re>::
        pack(std::find_if(boost_kahypar::begin(rng), boost_kahypar::end(rng), pred),
             rng);
}

    } // namespace range
    using range::find_if;
} // namespace boost_kahypar

#endif // include guard
