// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOST_CONCEPT_USAGE_DWA2006919_HPP
# define BOOST_CONCEPT_USAGE_DWA2006919_HPP

# include <boost_kahypar/concept/assert.hpp>
# include <boost_kahypar/config/workaround.hpp>
# include <boost_kahypar/concept/detail/backward_compatibility.hpp>

namespace boost_kahypar { namespace concepts { 

template <class Model>
struct usage_requirements
{
#   if defined(BOOST_GCC) && (BOOST_GCC >= 110000)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wnonnull"
#   endif
    ~usage_requirements() { ((Model*)0)->~Model(); }
#   if defined(BOOST_GCC) && (BOOST_GCC >= 110000)
#   pragma GCC diagnostic pop
#   endif
};

#  if BOOST_WORKAROUND(__GNUC__, <= 3)

#   define BOOST_CONCEPT_USAGE(model)                                    \
      model(); /* at least 2.96 and 3.4.3 both need this :( */           \
      BOOST_CONCEPT_ASSERT((boost_kahypar::concepts::usage_requirements<model>)); \
      ~model()

#  else

#   define BOOST_CONCEPT_USAGE(model)                                    \
      BOOST_CONCEPT_ASSERT((boost_kahypar::concepts::usage_requirements<model>)); \
      ~model()

#  endif

}} // namespace boost_kahypar::concepts

#endif // BOOST_CONCEPT_USAGE_DWA2006919_HPP
