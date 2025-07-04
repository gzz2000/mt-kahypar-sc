#ifndef BOOST_DESCRIBE_DETAIL_BASES_HPP_INCLUDED
#define BOOST_DESCRIBE_DETAIL_BASES_HPP_INCLUDED

// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/describe/detail/compute_base_modifiers.hpp>
#include <boost_kahypar/describe/detail/pp_for_each.hpp>
#include <boost_kahypar/describe/detail/list.hpp>
#include <type_traits>

namespace boost_kahypar
{
namespace describe
{
namespace detail
{

// base_descriptor
template<class C, class B> struct base_descriptor
{
    static_assert( std::is_base_of<B, C>::value, "A type listed as a base is not one" );

    using type = B;
    static constexpr unsigned modifiers = compute_base_modifiers<C, B>();
};

#ifndef __cpp_inline_variables
template<class C, class B> constexpr unsigned base_descriptor<C, B>::modifiers;
#endif

template<class... T> auto base_descriptor_fn_impl( int, T... )
{
    return list<T...>();
}

#define BOOST_DESCRIBE_BASE_IMPL(C, B) , boost_kahypar::describe::detail::base_descriptor<C, B>()

#if defined(_MSC_VER) && !defined(__clang__)

#define BOOST_DESCRIBE_BASES(C, ...) inline auto boost_base_descriptor_fn( C** ) \
{ return boost_kahypar::describe::detail::base_descriptor_fn_impl( 0 BOOST_DESCRIBE_PP_FOR_EACH(BOOST_DESCRIBE_BASE_IMPL, C, __VA_ARGS__) ); }

#else

#define BOOST_DESCRIBE_BASES(C, ...) inline auto boost_base_descriptor_fn( C** ) \
{ return boost_kahypar::describe::detail::base_descriptor_fn_impl( 0 BOOST_DESCRIBE_PP_FOR_EACH(BOOST_DESCRIBE_BASE_IMPL, C, ##__VA_ARGS__) ); }

#endif

} // namespace detail
} // namespace describe
} // namespace boost_kahypar

#endif // #ifndef BOOST_DESCRIBE_DETAIL_BASES_HPP_INCLUDED
