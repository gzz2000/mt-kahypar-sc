// Copyright (C) 2017 Michel Morin.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_ITERATOR_ADVANCE_HPP
#define BOOST_ITERATOR_ADVANCE_HPP

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/detail/workaround.hpp>
#include <boost_kahypar/iterator/iterator_categories.hpp>

namespace boost_kahypar {
namespace iterators {

    namespace detail {
        template <typename InputIterator, typename Distance>
        inline BOOST_CXX14_CONSTEXPR void
        advance_impl(
            InputIterator& it
          , Distance n
          , incrementable_traversal_tag
        )
        {
            while (n > 0) {
                ++it;
                --n;
            }
        }

#if BOOST_WORKAROUND(BOOST_GCC_VERSION, >= 40600)
// type-limits warning issued below when n is an unsigned integral
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif

        template <typename BidirectionalIterator, typename Distance>
        inline BOOST_CXX14_CONSTEXPR void
        advance_impl(
            BidirectionalIterator& it
          , Distance n
          , bidirectional_traversal_tag
        )
        {
            if (n >= 0) {
                while (n > 0) {
                    ++it;
                    --n;
                }
            }
            else {
                while (n < 0) {
                    --it;
                    ++n;
                }
            }
        }

#if BOOST_WORKAROUND(BOOST_GCC_VERSION, >= 40600)
#pragma GCC diagnostic pop
#endif

        template <typename RandomAccessIterator, typename Distance>
        inline BOOST_CXX14_CONSTEXPR void
        advance_impl(
            RandomAccessIterator& it
          , Distance n
          , random_access_traversal_tag
        )
        {
            it += n;
        }
    }

    namespace advance_adl_barrier {
        template <typename InputIterator, typename Distance>
        inline BOOST_CXX14_CONSTEXPR void
        advance(InputIterator& it, Distance n)
        {
            detail::advance_impl(
                it, n, typename iterator_traversal<InputIterator>::type()
            );
        }
    }

    using namespace advance_adl_barrier;

} // namespace iterators

using namespace iterators::advance_adl_barrier;

} // namespace boost_kahypar

#endif
