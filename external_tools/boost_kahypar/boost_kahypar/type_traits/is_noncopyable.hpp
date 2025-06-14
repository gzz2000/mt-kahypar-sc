#ifndef BOOST_TYPE_TRAITS_IS_NONCOPYABLE_HPP_INCLUDED
#define BOOST_TYPE_TRAITS_IS_NONCOPYABLE_HPP_INCLUDED

//
//  Copyright 2018 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//  is_noncopyable<T> returns whether T is derived from boost_kahypar::noncopyable
//

#include <boost_kahypar/type_traits/is_base_and_derived.hpp>

namespace boost_kahypar
{

#ifndef BOOST_NONCOPYABLE_BASE_TOKEN_DEFINED
#define BOOST_NONCOPYABLE_BASE_TOKEN_DEFINED

// boost_kahypar::noncopyable derives from noncopyable_::base_token to enable us
// to recognize it. The definition is macro-guarded so that we can replicate
// it here without including boost/core/noncopyable.hpp, which is in Core.

namespace noncopyable_
{
    struct base_token {};
}

#endif // #ifndef BOOST_NONCOPYABLE_BASE_TOKEN_DEFINED

template<class T> struct is_noncopyable: is_base_and_derived<noncopyable_::base_token, T>
{
};

} // namespace boost_kahypar

#endif // #ifndef BOOST_TYPE_TRAITS_IS_NONCOPYABLE_HPP_INCLUDED
