//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_REPLACE_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_REPLACE_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function replace
///
/// range-based version of the replace std algorithm
///
/// \pre ForwardRange is a model of the ForwardRangeConcept
template< class ForwardRange, class Value >
inline ForwardRange&
replace(ForwardRange& rng, const Value& what,
        const Value& with_what)
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<ForwardRange> ));
    std::replace(boost_kahypar::begin(rng), boost_kahypar::end(rng), what, with_what);
    return rng;
}

/// \overload
template< class ForwardRange, class Value >
inline const ForwardRange&
replace(const ForwardRange& rng, const Value& what,
        const Value& with_what)
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<const ForwardRange> ));
    std::replace(boost_kahypar::begin(rng), boost_kahypar::end(rng), what, with_what);
    return rng;
}

    } // namespace range
    using range::replace;
} // namespace boost_kahypar;

#endif // include guard
