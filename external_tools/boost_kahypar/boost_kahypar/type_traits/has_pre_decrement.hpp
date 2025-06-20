//  (C) Copyright 2009-2011 Frederic Bron.
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_HAS_PRE_DECREMENT_HPP_INCLUDED
#define BOOST_TT_HAS_PRE_DECREMENT_HPP_INCLUDED

#include <boost_kahypar/type_traits/is_array.hpp>

#define BOOST_TT_TRAIT_NAME has_pre_decrement
#define BOOST_TT_TRAIT_OP --
#define BOOST_TT_FORBIDDEN_IF\
   (\
      /* bool */\
      ::boost_kahypar::is_same< bool, Rhs_nocv >::value || \
      /* void* */\
      (\
         ::boost_kahypar::is_pointer< Rhs_noref >::value && \
         ::boost_kahypar::is_void< Rhs_noptr >::value\
      ) || \
      /* (fundamental or pointer) and const */\
      (\
         ( \
            ::boost_kahypar::is_fundamental< Rhs_nocv >::value || \
            ::boost_kahypar::is_pointer< Rhs_noref >::value\
         ) && \
         ::boost_kahypar::is_const< Rhs_noref >::value\
      )||\
      /* Arrays */ \
      ::boost_kahypar::is_array<Rhs_noref>::value\
      )


#include <boost_kahypar/type_traits/detail/has_prefix_operator.hpp>

#undef BOOST_TT_TRAIT_NAME
#undef BOOST_TT_TRAIT_OP
#undef BOOST_TT_FORBIDDEN_IF

#if defined(BOOST_TT_HAS_ACCURATE_BINARY_OPERATOR_DETECTION)

namespace boost_kahypar {

   template <class R>
   struct has_pre_decrement<bool, R> : public false_type {};
   template <>
   struct has_pre_decrement<bool, boost_kahypar::binary_op_detail::dont_care> : public false_type {};
   template <>
   struct has_pre_decrement<bool, void> : public false_type {};

   template <class R>
   struct has_pre_decrement<bool&, R> : public false_type {};
   template <>
   struct has_pre_decrement<bool&, boost_kahypar::binary_op_detail::dont_care> : public false_type {};
   template <>
   struct has_pre_decrement<bool&, void> : public false_type {};

}

#endif
#endif
