#ifndef BOOST_CORE_IS_SAME_HPP_INCLUDED
#define BOOST_CORE_IS_SAME_HPP_INCLUDED

// is_same<T1,T2>::value is true when T1 == T2
//
// Copyright 2014 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/core/detail/is_same.hpp>

#if defined(BOOST_HAS_PRAGMA_ONCE)
# pragma once
#endif

#include <boost_kahypar/config/header_deprecated.hpp>

BOOST_HEADER_DEPRECATED("<boost_kahypar/type_traits/is_same.hpp>")

namespace boost_kahypar
{

namespace core
{

using boost_kahypar::core::detail::is_same;

} // namespace core

} // namespace boost_kahypar

#endif // #ifndef BOOST_CORE_IS_SAME_HPP_INCLUDED
