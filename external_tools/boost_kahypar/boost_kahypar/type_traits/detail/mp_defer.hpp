#ifndef BOOST_TYPE_TRAITS_DETAIL_MP_DEFER_HPP_INCLUDED
#define BOOST_TYPE_TRAITS_DETAIL_MP_DEFER_HPP_INCLUDED

//
//  Copyright 2015 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#include <boost_kahypar/type_traits/integral_constant.hpp>
#include <boost_kahypar/type_traits/conditional.hpp>

namespace boost_kahypar
{

namespace type_traits_detail
{

// mp_valid
// implementation by Bruno Dutra (by the name is_evaluable)

template<template<class...> class F, class... T>
struct mp_valid_impl
{
    template<template<class...> class G, class = G<T...>>
    static boost_kahypar::true_type check_s(int);

    template<template<class...> class>
    static boost_kahypar::false_type check_s(...);

    using type = decltype(check_s<F>(0));
};

template<template<class...> class F, class... T>
using mp_valid = typename mp_valid_impl<F, T...>::type;

// mp_defer

struct mp_empty
{
};

template<template<class...> class F, class... T> struct mp_defer_impl
{
    using type = F<T...>;
};

template<template<class...> class F, class... T> using mp_defer = typename boost_kahypar::conditional<mp_valid<F, T...>::value, mp_defer_impl<F, T...>, mp_empty>::type;

} // namespace type_traits_detail

} // namespace boost_kahypar

#endif // #ifndef BOOST_TYPE_TRAITS_DETAIL_MP_DEFER_HPP_INCLUDED
