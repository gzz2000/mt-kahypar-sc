//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_REPLACE_COPY_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_REPLACE_COPY_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function replace_copy
///
/// range-based version of the replace_copy std algorithm
///
/// \pre ForwardRange is a model of the ForwardRangeConcept
template< class ForwardRange, class OutputIterator, class Value >
inline OutputIterator
replace_copy(const ForwardRange& rng, OutputIterator out_it, const Value& what,
        const Value& with_what)
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<const ForwardRange> ));
    return std::replace_copy(boost_kahypar::begin(rng), boost_kahypar::end(rng), out_it,
        what, with_what);
}

    } // namespace range
    using range::replace_copy;
} // namespace boost_kahypar

#endif // include guard
