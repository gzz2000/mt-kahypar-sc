//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_LEXICOGRAPHICAL_COMPARE_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_LEXICOGRAPHICAL_COMPARE_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function lexicographic_compare
///
/// range-based version of the lexicographic_compare std algorithm
///
/// \pre SinglePassRange1 is a model of the SinglePassRangeConcept
/// \pre SinglePassRange2 is a model of the SinglePassRangeConcept
template<class SinglePassRange1, class SinglePassRange2>
inline bool lexicographical_compare(const SinglePassRange1& rng1,
                                    const SinglePassRange2& rng2)
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange1> ));
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange2> ));
    return std::lexicographical_compare(
        boost_kahypar::begin(rng1), boost_kahypar::end(rng1),
        boost_kahypar::begin(rng2), boost_kahypar::end(rng2));
}

/// \overload
template<class SinglePassRange1, class SinglePassRange2,
         class BinaryPredicate>
inline bool lexicographical_compare(const SinglePassRange1& rng1,
                                    const SinglePassRange2& rng2,
                                    BinaryPredicate pred)
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange1> ));
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange2> ));
    return std::lexicographical_compare(
        boost_kahypar::begin(rng1), boost_kahypar::end(rng1),
        boost_kahypar::begin(rng2), boost_kahypar::end(rng2), pred);
}

    } // namespace range
    using range::lexicographical_compare;
} // namespace boost_kahypar

#endif // include guard
