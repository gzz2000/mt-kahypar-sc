
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost_kahypar/mpl/vector/vector10.hpp" header
// -- DO NOT modify by hand!

namespace boost_kahypar { namespace mpl {

template< typename V >
struct v_at< V,0 >
{
    typedef typename V::item0 type;
};

template<
      typename T0
    >
struct vector1
{
    typedef aux::vector_tag<1> tag;
    typedef vector1 type;
    typedef T0 item0;
    typedef void_ item1;
    typedef T0 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,1 > end;
};

template<>
struct push_front_impl< aux::vector_tag<0> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector1<
              T
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<1> >
{
    template< typename Vector > struct apply
    {
        typedef vector0<
             
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<0> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector1<
             
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<1> >
{
    template< typename Vector > struct apply
    {
        typedef vector0<
             
            > type;
    };
};

template< typename V >
struct v_at< V,1 >
{
    typedef typename V::item1 type;
};

template<
      typename T0, typename T1
    >
struct vector2
{
    typedef aux::vector_tag<2> tag;
    typedef vector2 type;
    typedef T0 item0;
    typedef T1 item1;
    

    typedef void_ item2;
    typedef T1 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,2 > end;
};

template<>
struct push_front_impl< aux::vector_tag<1> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector2<
              T
              ,
              typename Vector::item0
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<2> >
{
    template< typename Vector > struct apply
    {
        typedef vector1<
              typename Vector::item1
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<1> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector2<
              typename Vector::item0
              ,
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<2> >
{
    template< typename Vector > struct apply
    {
        typedef vector1<
              typename Vector::item0
            > type;
    };
};

template< typename V >
struct v_at< V,2 >
{
    typedef typename V::item2 type;
};

template<
      typename T0, typename T1, typename T2
    >
struct vector3
{
    typedef aux::vector_tag<3> tag;
    typedef vector3 type;
    typedef T0 item0;
    typedef T1 item1;
    typedef T2 item2;
    

    typedef void_ item3;
    typedef T2 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,3 > end;
};

template<>
struct push_front_impl< aux::vector_tag<2> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector3<
              T
              ,
              typename Vector::item0, typename Vector::item1
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<3> >
{
    template< typename Vector > struct apply
    {
        typedef vector2<
              typename Vector::item1, typename Vector::item2
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<2> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector3<
              typename Vector::item0, typename Vector::item1
              ,
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<3> >
{
    template< typename Vector > struct apply
    {
        typedef vector2<
              typename Vector::item0, typename Vector::item1
            > type;
    };
};

template< typename V >
struct v_at< V,3 >
{
    typedef typename V::item3 type;
};

template<
      typename T0, typename T1, typename T2, typename T3
    >
struct vector4
{
    typedef aux::vector_tag<4> tag;
    typedef vector4 type;
    typedef T0 item0;
    typedef T1 item1;
    typedef T2 item2;
    typedef T3 item3;
    

    typedef void_ item4;
    typedef T3 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,4 > end;
};

template<>
struct push_front_impl< aux::vector_tag<3> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector4<
              T
              ,
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<4> >
{
    template< typename Vector > struct apply
    {
        typedef vector3<
              typename Vector::item1, typename Vector::item2
            , typename Vector::item3
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<3> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector4<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2
              ,
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<4> >
{
    template< typename Vector > struct apply
    {
        typedef vector3<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2
            > type;
    };
};

template< typename V >
struct v_at< V,4 >
{
    typedef typename V::item4 type;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    >
struct vector5
{
    typedef aux::vector_tag<5> tag;
    typedef vector5 type;
    typedef T0 item0;
    typedef T1 item1;
    typedef T2 item2;
    typedef T3 item3;
    typedef T4 item4;
    

    typedef void_ item5;
    typedef T4 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,5 > end;
};

template<>
struct push_front_impl< aux::vector_tag<4> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector5<
              T
              ,
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<5> >
{
    template< typename Vector > struct apply
    {
        typedef vector4<
              typename Vector::item1, typename Vector::item2
            , typename Vector::item3, typename Vector::item4
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<4> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector5<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
              ,
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<5> >
{
    template< typename Vector > struct apply
    {
        typedef vector4<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            > type;
    };
};

template< typename V >
struct v_at< V,5 >
{
    typedef typename V::item5 type;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5
    >
struct vector6
{
    typedef aux::vector_tag<6> tag;
    typedef vector6 type;
    typedef T0 item0;
    typedef T1 item1;
    typedef T2 item2;
    typedef T3 item3;
    typedef T4 item4;
    typedef T5 item5;
    

    typedef void_ item6;
    typedef T5 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,6 > end;
};

template<>
struct push_front_impl< aux::vector_tag<5> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector6<
              T
              ,
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<6> >
{
    template< typename Vector > struct apply
    {
        typedef vector5<
              typename Vector::item1, typename Vector::item2
            , typename Vector::item3, typename Vector::item4
            , typename Vector::item5
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<5> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector6<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4
              ,
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<6> >
{
    template< typename Vector > struct apply
    {
        typedef vector5<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4
            > type;
    };
};

template< typename V >
struct v_at< V,6 >
{
    typedef typename V::item6 type;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6
    >
struct vector7
{
    typedef aux::vector_tag<7> tag;
    typedef vector7 type;
    typedef T0 item0;
    typedef T1 item1;
    typedef T2 item2;
    typedef T3 item3;
    typedef T4 item4;
    typedef T5 item5;
    typedef T6 item6;
    

    typedef void_ item7;
    typedef T6 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,7 > end;
};

template<>
struct push_front_impl< aux::vector_tag<6> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector7<
              T
              ,
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<7> >
{
    template< typename Vector > struct apply
    {
        typedef vector6<
              typename Vector::item1, typename Vector::item2
            , typename Vector::item3, typename Vector::item4
            , typename Vector::item5, typename Vector::item6
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<6> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector7<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
              ,
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<7> >
{
    template< typename Vector > struct apply
    {
        typedef vector6<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            > type;
    };
};

template< typename V >
struct v_at< V,7 >
{
    typedef typename V::item7 type;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7
    >
struct vector8
{
    typedef aux::vector_tag<8> tag;
    typedef vector8 type;
    typedef T0 item0;
    typedef T1 item1;
    typedef T2 item2;
    typedef T3 item3;
    typedef T4 item4;
    typedef T5 item5;
    typedef T6 item6;
    typedef T7 item7;
    

    typedef void_ item8;
    typedef T7 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,8 > end;
};

template<>
struct push_front_impl< aux::vector_tag<7> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector8<
              T
              ,
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            , typename Vector::item6
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<8> >
{
    template< typename Vector > struct apply
    {
        typedef vector7<
              typename Vector::item1, typename Vector::item2
            , typename Vector::item3, typename Vector::item4
            , typename Vector::item5, typename Vector::item6
            , typename Vector::item7
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<7> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector8<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            , typename Vector::item6
              ,
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<8> >
{
    template< typename Vector > struct apply
    {
        typedef vector7<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            , typename Vector::item6
            > type;
    };
};

template< typename V >
struct v_at< V,8 >
{
    typedef typename V::item8 type;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8
    >
struct vector9
{
    typedef aux::vector_tag<9> tag;
    typedef vector9 type;
    typedef T0 item0;
    typedef T1 item1;
    typedef T2 item2;
    typedef T3 item3;
    typedef T4 item4;
    typedef T5 item5;
    typedef T6 item6;
    typedef T7 item7;
    typedef T8 item8;
    

    typedef void_ item9;
    typedef T8 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,9 > end;
};

template<>
struct push_front_impl< aux::vector_tag<8> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector9<
              T
              ,
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            , typename Vector::item6, typename Vector::item7
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<9> >
{
    template< typename Vector > struct apply
    {
        typedef vector8<
              typename Vector::item1, typename Vector::item2
            , typename Vector::item3, typename Vector::item4
            , typename Vector::item5, typename Vector::item6
            , typename Vector::item7, typename Vector::item8
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<8> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector9<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            , typename Vector::item6, typename Vector::item7
              ,
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<9> >
{
    template< typename Vector > struct apply
    {
        typedef vector8<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            , typename Vector::item6, typename Vector::item7
            > type;
    };
};

template< typename V >
struct v_at< V,9 >
{
    typedef typename V::item9 type;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    >
struct vector10
{
    typedef aux::vector_tag<10> tag;
    typedef vector10 type;
    typedef T0 item0;
    typedef T1 item1;
    typedef T2 item2;
    typedef T3 item3;
    typedef T4 item4;
    typedef T5 item5;
    typedef T6 item6;
    typedef T7 item7;
    typedef T8 item8;
    typedef T9 item9;
    

    typedef void_ item10;
    typedef T9 back;
    typedef v_iter< type,0 > begin;
    typedef v_iter< type,10 > end;
};

template<>
struct push_front_impl< aux::vector_tag<9> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector10<
              T
              ,
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            , typename Vector::item6, typename Vector::item7
            , typename Vector::item8
            > type;
    };
};

template<>
struct pop_front_impl< aux::vector_tag<10> >
{
    template< typename Vector > struct apply
    {
        typedef vector9<
              typename Vector::item1, typename Vector::item2
            , typename Vector::item3, typename Vector::item4
            , typename Vector::item5, typename Vector::item6
            , typename Vector::item7, typename Vector::item8
            , typename Vector::item9
            > type;
    };
};

template<>
struct push_back_impl< aux::vector_tag<9> >
{
    template< typename Vector, typename T > struct apply
    {
        typedef vector10<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            , typename Vector::item6, typename Vector::item7
            , typename Vector::item8
              ,
              T
            > type;
    };
};

template<>
struct pop_back_impl< aux::vector_tag<10> >
{
    template< typename Vector > struct apply
    {
        typedef vector9<
              typename Vector::item0, typename Vector::item1
            , typename Vector::item2, typename Vector::item3
            , typename Vector::item4, typename Vector::item5
            , typename Vector::item6, typename Vector::item7
            , typename Vector::item8
            > type;
    };
};

template< typename V >
struct v_at< V,10 >
{
    typedef typename V::item10 type;
};

}}
