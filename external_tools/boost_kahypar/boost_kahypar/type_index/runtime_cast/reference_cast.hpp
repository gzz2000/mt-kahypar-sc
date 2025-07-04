//
// Copyright (c) Chris Glover, 2016.
//
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_TYPE_INDEX_RUNTIME_CAST_REFERENCE_CAST_HPP
#define BOOST_TYPE_INDEX_RUNTIME_CAST_REFERENCE_CAST_HPP

/// \file reference_cast.hpp
/// \brief Contains the overload of boost_kahypar::typeindex::runtime_cast for
/// reference types.

#include <boost_kahypar/type_index/runtime_cast/detail/runtime_cast_impl.hpp>
#include <boost_kahypar/throw_exception.hpp>

#include <memory>
#include <type_traits>

#ifdef BOOST_HAS_PRAGMA_ONCE
# pragma once
#endif

namespace boost_kahypar { namespace typeindex {

/// \brief Indicates that runtime_cast was unable to perform the desired cast operation
/// because the source instance was not also an instance of the target type.
struct BOOST_SYMBOL_VISIBLE bad_runtime_cast : std::exception
{};

/// \brief Safely converts references to classes up, down, and sideways along the inheritance hierarchy.
/// \tparam T The desired target type. Like dynamic_cast, must be a pointer to complete class type.
/// \tparam U A complete class type of the source instance, u.
/// \return If there exists a valid conversion from U& to T, returns a T that references an address
/// suitably offset from u. If no such conversion exists, throws boost_kahypar::typeindex::bad_runtime_cast.
template<typename T, typename U>
typename std::add_lvalue_reference<T>::type runtime_cast(U& u) {
    typedef typename std::remove_reference<T>::type impl_type;
    impl_type* value = detail::runtime_cast_impl<impl_type>(
        std::addressof(u), std::is_base_of<T, U>());
    if(!value)
        BOOST_THROW_EXCEPTION(bad_runtime_cast());
    return *value;
}

/// \brief Safely converts references to classes up, down, and sideways along the inheritance hierarchy.
/// \tparam T The desired target type. Like dynamic_cast, must be a pointer to complete class type.
/// \tparam U A complete class type of the source instance, u.
/// \return If there exists a valid conversion from U const& to T const, returns a T const that references an address
/// suitably offset from u. If no such conversion exists, throws boost_kahypar::typeindex::bad_runtime_cast.
template<typename T, typename U>
typename std::add_lvalue_reference<const T>::type runtime_cast(U const& u) {
    typedef typename std::remove_reference<T>::type impl_type;
    impl_type* value = detail::runtime_cast_impl<impl_type>(
        std::addressof(u), std::is_base_of<T, U>());
    if(!value)
        BOOST_THROW_EXCEPTION(bad_runtime_cast());
    return *value;
}

}} // namespace boost_kahypar::typeindex

#endif // BOOST_TYPE_INDEX_RUNTIME_CAST_REFERENCE_CAST_HPP
