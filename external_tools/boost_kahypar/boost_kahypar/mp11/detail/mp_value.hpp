#ifndef BOOST_MP11_DETAIL_MP_VALUE_HPP_INCLUDED
#define BOOST_MP11_DETAIL_MP_VALUE_HPP_INCLUDED

// Copyright 2023 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/mp11/detail/config.hpp>
#include <type_traits>

#if defined(BOOST_MP11_HAS_TEMPLATE_AUTO)

namespace boost_kahypar
{
namespace mp11
{

template<auto A> using mp_value = std::integral_constant<decltype(A), A>;

} // namespace mp11
} // namespace boost_kahypar

#endif // #if defined(BOOST_MP11_HAS_TEMPLATE_AUTO)

#endif // #ifndef BOOST_MP11_DETAIL_MP_VALUE_HPP_INCLUDED
