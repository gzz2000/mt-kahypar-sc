//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_REVERSE_COPY_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_REVERSE_COPY_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/iterator/iterator_concepts.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function reverse_copy
///
/// range-based version of the reverse_copy std algorithm
///
/// \pre BidirectionalRange is a model of the BidirectionalRangeConcept
template<class BidirectionalRange, class OutputIterator>
inline OutputIterator reverse_copy(const BidirectionalRange& rng, OutputIterator out)
{
    BOOST_RANGE_CONCEPT_ASSERT(( BidirectionalRangeConcept<const BidirectionalRange> ));
    return std::reverse_copy(boost_kahypar::begin(rng), boost_kahypar::end(rng), out);
}

    } // namespace range
    using range::reverse_copy;
} // namespace boost_kahypar

#endif // include guard
