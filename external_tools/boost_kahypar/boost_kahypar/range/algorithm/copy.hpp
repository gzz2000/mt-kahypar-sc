//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_COPY_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_COPY_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/iterator_range.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function copy
///
/// range-based version of the copy std algorithm
///
/// \pre SinglePassRange is a model of the SinglePassRangeConcept
/// \pre OutputIterator is a model of the OutputIteratorConcept
template< class SinglePassRange, class OutputIterator >
inline OutputIterator copy(const SinglePassRange& rng, OutputIterator out)
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange> ));
    return std::copy(boost_kahypar::begin(rng),boost_kahypar::end(rng),out);
}

    } // namespace range
    using range::copy;
} // namespace boost_kahypar

#endif // include guard
