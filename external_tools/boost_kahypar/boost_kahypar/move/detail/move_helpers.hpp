//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2010-2016.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/move for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_MOVE_MOVE_HELPERS_HPP
#define BOOST_MOVE_MOVE_HELPERS_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/move/core.hpp>
#include <boost_kahypar/move/utility_core.hpp>
#include <boost_kahypar/move/detail/type_traits.hpp>

#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

#define BOOST_MOVE_CATCH_CONST(U)  \
   typename ::boost_kahypar::move_detail::if_< ::boost_kahypar::move_detail::is_class<U>, BOOST_CATCH_CONST_RLVALUE(U), const U &>::type
#define BOOST_MOVE_CATCH_RVALUE(U)\
   typename ::boost_kahypar::move_detail::if_< ::boost_kahypar::move_detail::is_class<U>, BOOST_RV_REF(U), ::boost_kahypar::move_detail::nat>::type
#define BOOST_MOVE_CATCH_FWD(U) BOOST_FWD_REF(U)
#else
#define BOOST_MOVE_CATCH_CONST(U)  const U &
#define BOOST_MOVE_CATCH_RVALUE(U) U &&
#define BOOST_MOVE_CATCH_FWD(U)    U &&
#endif

////////////////////////////////////////
//
// BOOST_MOVE_CONVERSION_AWARE_CATCH
//
////////////////////////////////////////

#ifdef BOOST_NO_CXX11_RVALUE_REFERENCES

   template<class RETURN_VALUE, class BOOST_MOVE_TEMPL_PARAM, class TYPE>
   struct boost_move_conversion_aware_catch_1
      : public ::boost_kahypar::move_detail::enable_if_and
                        < RETURN_VALUE
                        , ::boost_kahypar::move_detail::is_same<TYPE, BOOST_MOVE_TEMPL_PARAM>
                        , ::boost_kahypar::move_detail::is_class<TYPE>
                        , ::boost_kahypar::has_move_emulation_disabled<BOOST_MOVE_TEMPL_PARAM>
                        >
   {};

   template<class RETURN_VALUE, class BOOST_MOVE_TEMPL_PARAM, class TYPE>
   struct boost_move_conversion_aware_catch_2
      : public ::boost_kahypar::move_detail::disable_if_or
                        < RETURN_VALUE
                        , ::boost_kahypar::move_detail::is_same<TYPE, BOOST_MOVE_TEMPL_PARAM> 
                        , ::boost_kahypar::move_detail::is_rv_impl<BOOST_MOVE_TEMPL_PARAM>
                        , ::boost_kahypar::move_detail::and_
                                    < ::boost_kahypar::move_detail::is_rv_impl<BOOST_MOVE_TEMPL_PARAM>
                                    , ::boost_kahypar::move_detail::is_class<BOOST_MOVE_TEMPL_PARAM>
                                    >
                        >
   {};

   #define BOOST_MOVE_CONVERSION_AWARE_CATCH_COMMON(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION)\
      inline RETURN_VALUE PUB_FUNCTION(BOOST_MOVE_CATCH_CONST(TYPE) x)\
      {  return FWD_FUNCTION(static_cast<const TYPE&>(x)); }\
      \
      inline RETURN_VALUE PUB_FUNCTION(BOOST_MOVE_CATCH_RVALUE(TYPE) x) \
      {  return FWD_FUNCTION(::boost_kahypar::move(x));  }\
      \
      inline RETURN_VALUE PUB_FUNCTION(TYPE &x)\
      {  return FWD_FUNCTION(const_cast<const TYPE &>(x)); }\
   //
   #if defined(BOOST_MOVE_HELPERS_RETURN_SFINAE_BROKEN)
      #define BOOST_MOVE_CONVERSION_AWARE_CATCH(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION)\
         BOOST_MOVE_CONVERSION_AWARE_CATCH_COMMON(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION)\
         \
         template<class BOOST_MOVE_TEMPL_PARAM>\
         inline RETURN_VALUE PUB_FUNCTION(const BOOST_MOVE_TEMPL_PARAM &u,\
            typename boost_move_conversion_aware_catch_1< ::boost_kahypar::move_detail::nat, BOOST_MOVE_TEMPL_PARAM, TYPE>::type* = 0)\
         { return FWD_FUNCTION(u); }\
         \
         template<class BOOST_MOVE_TEMPL_PARAM>\
         inline RETURN_VALUE PUB_FUNCTION(const BOOST_MOVE_TEMPL_PARAM &u,\
            typename boost_move_conversion_aware_catch_2< ::boost_kahypar::move_detail::nat, BOOST_MOVE_TEMPL_PARAM, TYPE>::type* = 0)\
         {\
            TYPE t((u));\
            return FWD_FUNCTION(::boost_kahypar::move(t));\
         }\
      //
   #else
      #define BOOST_MOVE_CONVERSION_AWARE_CATCH(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION)\
         BOOST_MOVE_CONVERSION_AWARE_CATCH_COMMON(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION)\
         \
         template<class BOOST_MOVE_TEMPL_PARAM>\
         inline typename boost_move_conversion_aware_catch_1<RETURN_VALUE, BOOST_MOVE_TEMPL_PARAM, TYPE>::type\
            PUB_FUNCTION(const BOOST_MOVE_TEMPL_PARAM &u)\
         { return FWD_FUNCTION(u); }\
         \
         template<class BOOST_MOVE_TEMPL_PARAM>\
         inline typename boost_move_conversion_aware_catch_2<RETURN_VALUE, BOOST_MOVE_TEMPL_PARAM, TYPE>::type\
            PUB_FUNCTION(const BOOST_MOVE_TEMPL_PARAM &u)\
         {\
            TYPE t((u));\
            return FWD_FUNCTION(::boost_kahypar::move(t));\
         }\
      //
   #endif
#elif (defined(_MSC_VER) && (_MSC_VER == 1600))

   #define BOOST_MOVE_CONVERSION_AWARE_CATCH(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION)\
      inline RETURN_VALUE PUB_FUNCTION(BOOST_MOVE_CATCH_CONST(TYPE) x)\
      {  return FWD_FUNCTION(static_cast<const TYPE&>(x)); }\
      \
      inline RETURN_VALUE PUB_FUNCTION(BOOST_MOVE_CATCH_RVALUE(TYPE) x) \
      {  return FWD_FUNCTION(::boost_kahypar::move(x));  }\
      \
      template<class BOOST_MOVE_TEMPL_PARAM>\
      inline typename ::boost_kahypar::move_detail::enable_if_c\
                        < !::boost_kahypar::move_detail::is_same<TYPE, BOOST_MOVE_TEMPL_PARAM>::value\
                        , RETURN_VALUE >::type\
      PUB_FUNCTION(const BOOST_MOVE_TEMPL_PARAM &u)\
      {\
         TYPE t((u));\
         return FWD_FUNCTION(::boost_kahypar::move(t));\
      }\
   //

#else    //BOOST_NO_CXX11_RVALUE_REFERENCES

   #define BOOST_MOVE_CONVERSION_AWARE_CATCH(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION)\
      inline RETURN_VALUE PUB_FUNCTION(BOOST_MOVE_CATCH_CONST(TYPE) x)\
      {  return FWD_FUNCTION(x); }\
      \
      inline RETURN_VALUE PUB_FUNCTION(BOOST_MOVE_CATCH_RVALUE(TYPE) x) \
      {  return FWD_FUNCTION(::boost_kahypar::move(x));  }\
   //

#endif   //BOOST_NO_CXX11_RVALUE_REFERENCES

////////////////////////////////////////
//
// BOOST_MOVE_CONVERSION_AWARE_CATCH_1ARG
//
////////////////////////////////////////

#ifdef BOOST_NO_CXX11_RVALUE_REFERENCES

   template<class RETURN_VALUE, class BOOST_MOVE_TEMPL_PARAM, class UNLESS_CONVERTIBLE_TO, class TYPE>
   struct boost_move_conversion_aware_catch_1arg_1
      : public ::boost_kahypar::move_detail::enable_if_and
                        < RETURN_VALUE
                        , ::boost_kahypar::move_detail::not_< ::boost_kahypar::move_detail::is_same_or_convertible<BOOST_MOVE_TEMPL_PARAM, UNLESS_CONVERTIBLE_TO> >
                        , ::boost_kahypar::move_detail::is_same<TYPE, BOOST_MOVE_TEMPL_PARAM>
                        , ::boost_kahypar::has_move_emulation_disabled<BOOST_MOVE_TEMPL_PARAM>
                        >
   {};

   template<class RETURN_VALUE, class BOOST_MOVE_TEMPL_PARAM, class UNLESS_CONVERTIBLE_TO, class TYPE>
   struct boost_move_conversion_aware_catch_1arg_2
      : public ::boost_kahypar::move_detail::disable_if_or
                        < RETURN_VALUE
                        , ::boost_kahypar::move_detail::is_same_or_convertible< BOOST_MOVE_TEMPL_PARAM, UNLESS_CONVERTIBLE_TO>
                        , ::boost_kahypar::move_detail::is_rv_impl<BOOST_MOVE_TEMPL_PARAM>
                        , ::boost_kahypar::move_detail::is_same<TYPE, BOOST_MOVE_TEMPL_PARAM>
                        >
   {};

   #define BOOST_MOVE_CONVERSION_AWARE_CATCH_1ARG_COMMON(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION, ARG1, UNLESS_CONVERTIBLE_TO)\
      inline RETURN_VALUE PUB_FUNCTION(ARG1 arg1, BOOST_MOVE_CATCH_CONST(TYPE) x)\
      {  return FWD_FUNCTION(arg1, static_cast<const TYPE&>(x)); }\
      \
      inline RETURN_VALUE PUB_FUNCTION(ARG1 arg1, BOOST_MOVE_CATCH_RVALUE(TYPE) x) \
      {  return FWD_FUNCTION(arg1, ::boost_kahypar::move(x));  }\
      \
      inline RETURN_VALUE PUB_FUNCTION(ARG1 arg1, TYPE &x)\
      {  return FWD_FUNCTION(arg1, const_cast<const TYPE &>(x)); }\
   //
   #if defined(BOOST_MOVE_HELPERS_RETURN_SFINAE_BROKEN)
      #define BOOST_MOVE_CONVERSION_AWARE_CATCH_1ARG(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION, ARG1, UNLESS_CONVERTIBLE_TO)\
         BOOST_MOVE_CONVERSION_AWARE_CATCH_1ARG_COMMON(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION, ARG1, UNLESS_CONVERTIBLE_TO)\
         \
         template<class BOOST_MOVE_TEMPL_PARAM>\
         inline RETURN_VALUE PUB_FUNCTION(ARG1 arg1, const BOOST_MOVE_TEMPL_PARAM &u,\
            typename boost_move_conversion_aware_catch_1arg_1<void, BOOST_MOVE_TEMPL_PARAM, UNLESS_CONVERTIBLE_TO, TYPE>::type* = 0)\
         { return FWD_FUNCTION(arg1, u); }\
         \
         template<class BOOST_MOVE_TEMPL_PARAM>\
         inline RETURN_VALUE PUB_FUNCTION(ARG1 arg1, const BOOST_MOVE_TEMPL_PARAM &u,\
            typename boost_move_conversion_aware_catch_1arg_2<void, BOOST_MOVE_TEMPL_PARAM, UNLESS_CONVERTIBLE_TO, TYPE>::type* = 0)\
         {\
            TYPE t((u));\
            return FWD_FUNCTION(arg1, ::boost_kahypar::move(t));\
         }\
      //
   #else
      #define BOOST_MOVE_CONVERSION_AWARE_CATCH_1ARG(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION, ARG1, UNLESS_CONVERTIBLE_TO)\
         BOOST_MOVE_CONVERSION_AWARE_CATCH_1ARG_COMMON(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION, ARG1, UNLESS_CONVERTIBLE_TO)\
         \
         template<class BOOST_MOVE_TEMPL_PARAM>\
         inline typename boost_move_conversion_aware_catch_1arg_1<RETURN_VALUE, BOOST_MOVE_TEMPL_PARAM, UNLESS_CONVERTIBLE_TO, TYPE>::type\
            PUB_FUNCTION(ARG1 arg1, const BOOST_MOVE_TEMPL_PARAM &u)\
         { return FWD_FUNCTION(arg1, u); }\
         \
         template<class BOOST_MOVE_TEMPL_PARAM>\
         inline typename boost_move_conversion_aware_catch_1arg_2<RETURN_VALUE, BOOST_MOVE_TEMPL_PARAM, UNLESS_CONVERTIBLE_TO, TYPE>::type\
            PUB_FUNCTION(ARG1 arg1, const BOOST_MOVE_TEMPL_PARAM &u)\
         {\
            TYPE t((u));\
            return FWD_FUNCTION(arg1, ::boost_kahypar::move(t));\
         }\
      //
   #endif

#elif (defined(_MSC_VER) && (_MSC_VER == 1600))

   #define BOOST_MOVE_CONVERSION_AWARE_CATCH_1ARG(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION, ARG1, UNLESS_CONVERTIBLE_TO)\
      inline RETURN_VALUE PUB_FUNCTION(ARG1 arg1, BOOST_MOVE_CATCH_CONST(TYPE) x)\
      {  return FWD_FUNCTION(arg1, static_cast<const TYPE&>(x)); }\
      \
      inline RETURN_VALUE PUB_FUNCTION(ARG1 arg1, BOOST_MOVE_CATCH_RVALUE(TYPE) x) \
      {  return FWD_FUNCTION(arg1, ::boost_kahypar::move(x));  }\
      \
      template<class BOOST_MOVE_TEMPL_PARAM>\
      inline typename ::boost_kahypar::move_detail::disable_if_or\
                        < RETURN_VALUE \
                        , ::boost_kahypar::move_detail::is_same<TYPE, BOOST_MOVE_TEMPL_PARAM> \
                        , ::boost_kahypar::move_detail::is_same_or_convertible<BOOST_MOVE_TEMPL_PARAM, UNLESS_CONVERTIBLE_TO> \
                        >::type\
      PUB_FUNCTION(ARG1 arg1, const BOOST_MOVE_TEMPL_PARAM &u)\
      {\
         TYPE t((u));\
         return FWD_FUNCTION(arg1, ::boost_kahypar::move(t));\
      }\
   //

#else

   #define BOOST_MOVE_CONVERSION_AWARE_CATCH_1ARG(PUB_FUNCTION, TYPE, RETURN_VALUE, FWD_FUNCTION, ARG1, UNLESS_CONVERTIBLE_TO)\
      inline RETURN_VALUE PUB_FUNCTION(ARG1 arg1, BOOST_MOVE_CATCH_CONST(TYPE) x)\
      {  return FWD_FUNCTION(arg1, static_cast<const TYPE&>(x)); }\
      \
      inline RETURN_VALUE PUB_FUNCTION(ARG1 arg1, BOOST_MOVE_CATCH_RVALUE(TYPE) x) \
      {  return FWD_FUNCTION(arg1, ::boost_kahypar::move(x));  }\
   //

#endif

#endif //#ifndef BOOST_MOVE_MOVE_HELPERS_HPP
