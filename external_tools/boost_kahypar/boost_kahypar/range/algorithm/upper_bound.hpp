//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_UPPER_BOUND_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_UPPER_BOUND_HPP_INCLUDED

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

/// \brief template function upper_bound
///
/// range-based version of the upper_bound std algorithm
///
/// \pre ForwardRange is a model of the ForwardRangeConcept
template< class ForwardRange, class Value >
inline
BOOST_DEDUCED_TYPENAME disable_if<
    is_const<ForwardRange>,
    BOOST_DEDUCED_TYPENAME range_iterator<ForwardRange>::type
>::type
upper_bound( ForwardRange& rng, const Value& val )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<ForwardRange> ));
    return std::upper_bound(boost_kahypar::begin(rng), boost_kahypar::end(rng), val);
}

/// \overload
template< class ForwardRange, class Value >
BOOST_DEDUCED_TYPENAME range_iterator<const ForwardRange>::type
upper_bound( const ForwardRange& rng, const Value& val )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<const ForwardRange> ));
    return std::upper_bound(boost_kahypar::begin(rng), boost_kahypar::end(rng), val);
}

/// \overload
template< class ForwardRange, class Value, class SortPredicate >
inline BOOST_DEDUCED_TYPENAME disable_if<
    is_const<ForwardRange>,
    BOOST_DEDUCED_TYPENAME range_iterator<ForwardRange>::type
>::type
upper_bound( ForwardRange& rng, const Value& val, SortPredicate pred )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<ForwardRange> ));
    return std::upper_bound(boost_kahypar::begin(rng), boost_kahypar::end(rng), val, pred);
}

/// \overload
template< class ForwardRange, class Value, class SortPredicate >
inline BOOST_DEDUCED_TYPENAME range_iterator<const ForwardRange>::type
upper_bound( const ForwardRange& rng, const Value& val, SortPredicate pred )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<const ForwardRange> ));
    return std::upper_bound(boost_kahypar::begin(rng), boost_kahypar::end(rng), val, pred);
}

/// \overload
template< range_return_value re, class ForwardRange, class Value >
inline BOOST_DEDUCED_TYPENAME disable_if<
    is_const<ForwardRange>,
    BOOST_DEDUCED_TYPENAME range_return<ForwardRange,re>::type
>::type
upper_bound( ForwardRange& rng, const Value& val )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<ForwardRange> ));
    return range_return<ForwardRange,re>::
        pack(std::upper_bound(boost_kahypar::begin(rng), boost_kahypar::end(rng), val),
             rng);
}

/// \overload
template< range_return_value re, class ForwardRange, class Value >
inline BOOST_DEDUCED_TYPENAME range_return<const ForwardRange,re>::type
upper_bound( const ForwardRange& rng, const Value& val )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<const ForwardRange> ));
    return range_return<const ForwardRange,re>::
        pack(std::upper_bound(boost_kahypar::begin(rng), boost_kahypar::end(rng), val),
             rng);
}

/// \overload
template< range_return_value re, class ForwardRange, class Value,
          class SortPredicate >
inline BOOST_DEDUCED_TYPENAME disable_if<
    is_const<ForwardRange>,
    BOOST_DEDUCED_TYPENAME range_return<ForwardRange,re>::type
>::type
upper_bound( ForwardRange& rng, const Value& val, SortPredicate pred )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<ForwardRange> ));
    return range_return<ForwardRange,re>::
        pack(std::upper_bound(boost_kahypar::begin(rng), boost_kahypar::end(rng), val, pred),
             rng);
}

/// \overload
template< range_return_value re, class ForwardRange, class Value,
          class SortPredicate >
inline BOOST_DEDUCED_TYPENAME range_return<const ForwardRange,re>::type
upper_bound( const ForwardRange& rng, const Value& val, SortPredicate pred )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<const ForwardRange> ));
    return range_return<const ForwardRange,re>::
        pack(std::upper_bound(boost_kahypar::begin(rng), boost_kahypar::end(rng), val, pred),
             rng);
}

    } // namespace range
    using range::upper_bound;
} // namespace boost_kahypar

#endif // include guard
