//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_INPLACE_MERGE_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_INPLACE_MERGE_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function inplace_merge
///
/// range-based version of the inplace_merge std algorithm
///
/// \pre BidirectionalRange is a model of the BidirectionalRangeConcept
/// \pre BinaryPredicate is a model of the BinaryPredicateConcept
template<class BidirectionalRange>
inline BidirectionalRange& inplace_merge(BidirectionalRange& rng,
    BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type middle)
{
    BOOST_RANGE_CONCEPT_ASSERT(( BidirectionalRangeConcept<BidirectionalRange> ));
    std::inplace_merge(boost_kahypar::begin(rng), middle, boost_kahypar::end(rng));
    return rng;
}

/// \overload
template<class BidirectionalRange>
inline const BidirectionalRange& inplace_merge(const BidirectionalRange& rng,
    BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<const BidirectionalRange>::type middle)
{
    BOOST_RANGE_CONCEPT_ASSERT(( BidirectionalRangeConcept<const BidirectionalRange> ));
    std::inplace_merge(boost_kahypar::begin(rng), middle, boost_kahypar::end(rng));
    return rng;
}

/// \overload
template<class BidirectionalRange, class BinaryPredicate>
inline BidirectionalRange& inplace_merge(BidirectionalRange& rng,
    BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<BidirectionalRange>::type middle,
    BinaryPredicate pred)
{
    BOOST_RANGE_CONCEPT_ASSERT(( BidirectionalRangeConcept<BidirectionalRange> ));
    std::inplace_merge(boost_kahypar::begin(rng), middle, boost_kahypar::end(rng), pred);
    return rng;
}

/// \overload
template<class BidirectionalRange, class BinaryPredicate>
inline const BidirectionalRange& inplace_merge(const BidirectionalRange& rng,
    BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<const BidirectionalRange>::type middle,
    BinaryPredicate pred)
{
    BOOST_RANGE_CONCEPT_ASSERT(( BidirectionalRangeConcept<const BidirectionalRange> ));
    std::inplace_merge(boost_kahypar::begin(rng), middle, boost_kahypar::end(rng), pred);
    return rng;
}

    } // namespace range
    using range::inplace_merge;
} // namespace boost_kahypar

#endif // include guard
