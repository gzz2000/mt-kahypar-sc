# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
# /* Revised by Edward Diener (2020) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef BOOST_PREPROCESSOR_LIST_DETAIL_FOLD_RIGHT_HPP
# define BOOST_PREPROCESSOR_LIST_DETAIL_FOLD_RIGHT_HPP
#
# include <boost_kahypar/preprocessor/config/config.hpp>
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_STRICT()
#
# include <boost_kahypar/preprocessor/list/fold_left.hpp>
# include <boost_kahypar/preprocessor/list/reverse.hpp>
#
# define BOOST_PP_LIST_FOLD_RIGHT_1(o, s, l) BOOST_PP_LIST_FOLD_LEFT_1(o, s, BOOST_PP_LIST_REVERSE_D(1, l))
# define BOOST_PP_LIST_FOLD_RIGHT_2(o, s, l) BOOST_PP_LIST_FOLD_LEFT_2(o, s, BOOST_PP_LIST_REVERSE_D(2, l))
# define BOOST_PP_LIST_FOLD_RIGHT_3(o, s, l) BOOST_PP_LIST_FOLD_LEFT_3(o, s, BOOST_PP_LIST_REVERSE_D(3, l))
# define BOOST_PP_LIST_FOLD_RIGHT_4(o, s, l) BOOST_PP_LIST_FOLD_LEFT_4(o, s, BOOST_PP_LIST_REVERSE_D(4, l))
# define BOOST_PP_LIST_FOLD_RIGHT_5(o, s, l) BOOST_PP_LIST_FOLD_LEFT_5(o, s, BOOST_PP_LIST_REVERSE_D(5, l))
# define BOOST_PP_LIST_FOLD_RIGHT_6(o, s, l) BOOST_PP_LIST_FOLD_LEFT_6(o, s, BOOST_PP_LIST_REVERSE_D(6, l))
# define BOOST_PP_LIST_FOLD_RIGHT_7(o, s, l) BOOST_PP_LIST_FOLD_LEFT_7(o, s, BOOST_PP_LIST_REVERSE_D(7, l))
# define BOOST_PP_LIST_FOLD_RIGHT_8(o, s, l) BOOST_PP_LIST_FOLD_LEFT_8(o, s, BOOST_PP_LIST_REVERSE_D(8, l))
# define BOOST_PP_LIST_FOLD_RIGHT_9(o, s, l) BOOST_PP_LIST_FOLD_LEFT_9(o, s, BOOST_PP_LIST_REVERSE_D(9, l))
# define BOOST_PP_LIST_FOLD_RIGHT_10(o, s, l) BOOST_PP_LIST_FOLD_LEFT_10(o, s, BOOST_PP_LIST_REVERSE_D(10, l))
# define BOOST_PP_LIST_FOLD_RIGHT_11(o, s, l) BOOST_PP_LIST_FOLD_LEFT_11(o, s, BOOST_PP_LIST_REVERSE_D(11, l))
# define BOOST_PP_LIST_FOLD_RIGHT_12(o, s, l) BOOST_PP_LIST_FOLD_LEFT_12(o, s, BOOST_PP_LIST_REVERSE_D(12, l))
# define BOOST_PP_LIST_FOLD_RIGHT_13(o, s, l) BOOST_PP_LIST_FOLD_LEFT_13(o, s, BOOST_PP_LIST_REVERSE_D(13, l))
# define BOOST_PP_LIST_FOLD_RIGHT_14(o, s, l) BOOST_PP_LIST_FOLD_LEFT_14(o, s, BOOST_PP_LIST_REVERSE_D(14, l))
# define BOOST_PP_LIST_FOLD_RIGHT_15(o, s, l) BOOST_PP_LIST_FOLD_LEFT_15(o, s, BOOST_PP_LIST_REVERSE_D(15, l))
# define BOOST_PP_LIST_FOLD_RIGHT_16(o, s, l) BOOST_PP_LIST_FOLD_LEFT_16(o, s, BOOST_PP_LIST_REVERSE_D(16, l))
# define BOOST_PP_LIST_FOLD_RIGHT_17(o, s, l) BOOST_PP_LIST_FOLD_LEFT_17(o, s, BOOST_PP_LIST_REVERSE_D(17, l))
# define BOOST_PP_LIST_FOLD_RIGHT_18(o, s, l) BOOST_PP_LIST_FOLD_LEFT_18(o, s, BOOST_PP_LIST_REVERSE_D(18, l))
# define BOOST_PP_LIST_FOLD_RIGHT_19(o, s, l) BOOST_PP_LIST_FOLD_LEFT_19(o, s, BOOST_PP_LIST_REVERSE_D(19, l))
# define BOOST_PP_LIST_FOLD_RIGHT_20(o, s, l) BOOST_PP_LIST_FOLD_LEFT_20(o, s, BOOST_PP_LIST_REVERSE_D(20, l))
# define BOOST_PP_LIST_FOLD_RIGHT_21(o, s, l) BOOST_PP_LIST_FOLD_LEFT_21(o, s, BOOST_PP_LIST_REVERSE_D(21, l))
# define BOOST_PP_LIST_FOLD_RIGHT_22(o, s, l) BOOST_PP_LIST_FOLD_LEFT_22(o, s, BOOST_PP_LIST_REVERSE_D(22, l))
# define BOOST_PP_LIST_FOLD_RIGHT_23(o, s, l) BOOST_PP_LIST_FOLD_LEFT_23(o, s, BOOST_PP_LIST_REVERSE_D(23, l))
# define BOOST_PP_LIST_FOLD_RIGHT_24(o, s, l) BOOST_PP_LIST_FOLD_LEFT_24(o, s, BOOST_PP_LIST_REVERSE_D(24, l))
# define BOOST_PP_LIST_FOLD_RIGHT_25(o, s, l) BOOST_PP_LIST_FOLD_LEFT_25(o, s, BOOST_PP_LIST_REVERSE_D(25, l))
# define BOOST_PP_LIST_FOLD_RIGHT_26(o, s, l) BOOST_PP_LIST_FOLD_LEFT_26(o, s, BOOST_PP_LIST_REVERSE_D(26, l))
# define BOOST_PP_LIST_FOLD_RIGHT_27(o, s, l) BOOST_PP_LIST_FOLD_LEFT_27(o, s, BOOST_PP_LIST_REVERSE_D(27, l))
# define BOOST_PP_LIST_FOLD_RIGHT_28(o, s, l) BOOST_PP_LIST_FOLD_LEFT_28(o, s, BOOST_PP_LIST_REVERSE_D(28, l))
# define BOOST_PP_LIST_FOLD_RIGHT_29(o, s, l) BOOST_PP_LIST_FOLD_LEFT_29(o, s, BOOST_PP_LIST_REVERSE_D(29, l))
# define BOOST_PP_LIST_FOLD_RIGHT_30(o, s, l) BOOST_PP_LIST_FOLD_LEFT_30(o, s, BOOST_PP_LIST_REVERSE_D(30, l))
# define BOOST_PP_LIST_FOLD_RIGHT_31(o, s, l) BOOST_PP_LIST_FOLD_LEFT_31(o, s, BOOST_PP_LIST_REVERSE_D(31, l))
# define BOOST_PP_LIST_FOLD_RIGHT_32(o, s, l) BOOST_PP_LIST_FOLD_LEFT_32(o, s, BOOST_PP_LIST_REVERSE_D(32, l))
# define BOOST_PP_LIST_FOLD_RIGHT_33(o, s, l) BOOST_PP_LIST_FOLD_LEFT_33(o, s, BOOST_PP_LIST_REVERSE_D(33, l))
# define BOOST_PP_LIST_FOLD_RIGHT_34(o, s, l) BOOST_PP_LIST_FOLD_LEFT_34(o, s, BOOST_PP_LIST_REVERSE_D(34, l))
# define BOOST_PP_LIST_FOLD_RIGHT_35(o, s, l) BOOST_PP_LIST_FOLD_LEFT_35(o, s, BOOST_PP_LIST_REVERSE_D(35, l))
# define BOOST_PP_LIST_FOLD_RIGHT_36(o, s, l) BOOST_PP_LIST_FOLD_LEFT_36(o, s, BOOST_PP_LIST_REVERSE_D(36, l))
# define BOOST_PP_LIST_FOLD_RIGHT_37(o, s, l) BOOST_PP_LIST_FOLD_LEFT_37(o, s, BOOST_PP_LIST_REVERSE_D(37, l))
# define BOOST_PP_LIST_FOLD_RIGHT_38(o, s, l) BOOST_PP_LIST_FOLD_LEFT_38(o, s, BOOST_PP_LIST_REVERSE_D(38, l))
# define BOOST_PP_LIST_FOLD_RIGHT_39(o, s, l) BOOST_PP_LIST_FOLD_LEFT_39(o, s, BOOST_PP_LIST_REVERSE_D(39, l))
# define BOOST_PP_LIST_FOLD_RIGHT_40(o, s, l) BOOST_PP_LIST_FOLD_LEFT_40(o, s, BOOST_PP_LIST_REVERSE_D(40, l))
# define BOOST_PP_LIST_FOLD_RIGHT_41(o, s, l) BOOST_PP_LIST_FOLD_LEFT_41(o, s, BOOST_PP_LIST_REVERSE_D(41, l))
# define BOOST_PP_LIST_FOLD_RIGHT_42(o, s, l) BOOST_PP_LIST_FOLD_LEFT_42(o, s, BOOST_PP_LIST_REVERSE_D(42, l))
# define BOOST_PP_LIST_FOLD_RIGHT_43(o, s, l) BOOST_PP_LIST_FOLD_LEFT_43(o, s, BOOST_PP_LIST_REVERSE_D(43, l))
# define BOOST_PP_LIST_FOLD_RIGHT_44(o, s, l) BOOST_PP_LIST_FOLD_LEFT_44(o, s, BOOST_PP_LIST_REVERSE_D(44, l))
# define BOOST_PP_LIST_FOLD_RIGHT_45(o, s, l) BOOST_PP_LIST_FOLD_LEFT_45(o, s, BOOST_PP_LIST_REVERSE_D(45, l))
# define BOOST_PP_LIST_FOLD_RIGHT_46(o, s, l) BOOST_PP_LIST_FOLD_LEFT_46(o, s, BOOST_PP_LIST_REVERSE_D(46, l))
# define BOOST_PP_LIST_FOLD_RIGHT_47(o, s, l) BOOST_PP_LIST_FOLD_LEFT_47(o, s, BOOST_PP_LIST_REVERSE_D(47, l))
# define BOOST_PP_LIST_FOLD_RIGHT_48(o, s, l) BOOST_PP_LIST_FOLD_LEFT_48(o, s, BOOST_PP_LIST_REVERSE_D(48, l))
# define BOOST_PP_LIST_FOLD_RIGHT_49(o, s, l) BOOST_PP_LIST_FOLD_LEFT_49(o, s, BOOST_PP_LIST_REVERSE_D(49, l))
# define BOOST_PP_LIST_FOLD_RIGHT_50(o, s, l) BOOST_PP_LIST_FOLD_LEFT_50(o, s, BOOST_PP_LIST_REVERSE_D(50, l))
# define BOOST_PP_LIST_FOLD_RIGHT_51(o, s, l) BOOST_PP_LIST_FOLD_LEFT_51(o, s, BOOST_PP_LIST_REVERSE_D(51, l))
# define BOOST_PP_LIST_FOLD_RIGHT_52(o, s, l) BOOST_PP_LIST_FOLD_LEFT_52(o, s, BOOST_PP_LIST_REVERSE_D(52, l))
# define BOOST_PP_LIST_FOLD_RIGHT_53(o, s, l) BOOST_PP_LIST_FOLD_LEFT_53(o, s, BOOST_PP_LIST_REVERSE_D(53, l))
# define BOOST_PP_LIST_FOLD_RIGHT_54(o, s, l) BOOST_PP_LIST_FOLD_LEFT_54(o, s, BOOST_PP_LIST_REVERSE_D(54, l))
# define BOOST_PP_LIST_FOLD_RIGHT_55(o, s, l) BOOST_PP_LIST_FOLD_LEFT_55(o, s, BOOST_PP_LIST_REVERSE_D(55, l))
# define BOOST_PP_LIST_FOLD_RIGHT_56(o, s, l) BOOST_PP_LIST_FOLD_LEFT_56(o, s, BOOST_PP_LIST_REVERSE_D(56, l))
# define BOOST_PP_LIST_FOLD_RIGHT_57(o, s, l) BOOST_PP_LIST_FOLD_LEFT_57(o, s, BOOST_PP_LIST_REVERSE_D(57, l))
# define BOOST_PP_LIST_FOLD_RIGHT_58(o, s, l) BOOST_PP_LIST_FOLD_LEFT_58(o, s, BOOST_PP_LIST_REVERSE_D(58, l))
# define BOOST_PP_LIST_FOLD_RIGHT_59(o, s, l) BOOST_PP_LIST_FOLD_LEFT_59(o, s, BOOST_PP_LIST_REVERSE_D(59, l))
# define BOOST_PP_LIST_FOLD_RIGHT_60(o, s, l) BOOST_PP_LIST_FOLD_LEFT_60(o, s, BOOST_PP_LIST_REVERSE_D(60, l))
# define BOOST_PP_LIST_FOLD_RIGHT_61(o, s, l) BOOST_PP_LIST_FOLD_LEFT_61(o, s, BOOST_PP_LIST_REVERSE_D(61, l))
# define BOOST_PP_LIST_FOLD_RIGHT_62(o, s, l) BOOST_PP_LIST_FOLD_LEFT_62(o, s, BOOST_PP_LIST_REVERSE_D(62, l))
# define BOOST_PP_LIST_FOLD_RIGHT_63(o, s, l) BOOST_PP_LIST_FOLD_LEFT_63(o, s, BOOST_PP_LIST_REVERSE_D(63, l))
# define BOOST_PP_LIST_FOLD_RIGHT_64(o, s, l) BOOST_PP_LIST_FOLD_LEFT_64(o, s, BOOST_PP_LIST_REVERSE_D(64, l))
# define BOOST_PP_LIST_FOLD_RIGHT_65(o, s, l) BOOST_PP_LIST_FOLD_LEFT_65(o, s, BOOST_PP_LIST_REVERSE_D(65, l))
# define BOOST_PP_LIST_FOLD_RIGHT_66(o, s, l) BOOST_PP_LIST_FOLD_LEFT_66(o, s, BOOST_PP_LIST_REVERSE_D(66, l))
# define BOOST_PP_LIST_FOLD_RIGHT_67(o, s, l) BOOST_PP_LIST_FOLD_LEFT_67(o, s, BOOST_PP_LIST_REVERSE_D(67, l))
# define BOOST_PP_LIST_FOLD_RIGHT_68(o, s, l) BOOST_PP_LIST_FOLD_LEFT_68(o, s, BOOST_PP_LIST_REVERSE_D(68, l))
# define BOOST_PP_LIST_FOLD_RIGHT_69(o, s, l) BOOST_PP_LIST_FOLD_LEFT_69(o, s, BOOST_PP_LIST_REVERSE_D(69, l))
# define BOOST_PP_LIST_FOLD_RIGHT_70(o, s, l) BOOST_PP_LIST_FOLD_LEFT_70(o, s, BOOST_PP_LIST_REVERSE_D(70, l))
# define BOOST_PP_LIST_FOLD_RIGHT_71(o, s, l) BOOST_PP_LIST_FOLD_LEFT_71(o, s, BOOST_PP_LIST_REVERSE_D(71, l))
# define BOOST_PP_LIST_FOLD_RIGHT_72(o, s, l) BOOST_PP_LIST_FOLD_LEFT_72(o, s, BOOST_PP_LIST_REVERSE_D(72, l))
# define BOOST_PP_LIST_FOLD_RIGHT_73(o, s, l) BOOST_PP_LIST_FOLD_LEFT_73(o, s, BOOST_PP_LIST_REVERSE_D(73, l))
# define BOOST_PP_LIST_FOLD_RIGHT_74(o, s, l) BOOST_PP_LIST_FOLD_LEFT_74(o, s, BOOST_PP_LIST_REVERSE_D(74, l))
# define BOOST_PP_LIST_FOLD_RIGHT_75(o, s, l) BOOST_PP_LIST_FOLD_LEFT_75(o, s, BOOST_PP_LIST_REVERSE_D(75, l))
# define BOOST_PP_LIST_FOLD_RIGHT_76(o, s, l) BOOST_PP_LIST_FOLD_LEFT_76(o, s, BOOST_PP_LIST_REVERSE_D(76, l))
# define BOOST_PP_LIST_FOLD_RIGHT_77(o, s, l) BOOST_PP_LIST_FOLD_LEFT_77(o, s, BOOST_PP_LIST_REVERSE_D(77, l))
# define BOOST_PP_LIST_FOLD_RIGHT_78(o, s, l) BOOST_PP_LIST_FOLD_LEFT_78(o, s, BOOST_PP_LIST_REVERSE_D(78, l))
# define BOOST_PP_LIST_FOLD_RIGHT_79(o, s, l) BOOST_PP_LIST_FOLD_LEFT_79(o, s, BOOST_PP_LIST_REVERSE_D(79, l))
# define BOOST_PP_LIST_FOLD_RIGHT_80(o, s, l) BOOST_PP_LIST_FOLD_LEFT_80(o, s, BOOST_PP_LIST_REVERSE_D(80, l))
# define BOOST_PP_LIST_FOLD_RIGHT_81(o, s, l) BOOST_PP_LIST_FOLD_LEFT_81(o, s, BOOST_PP_LIST_REVERSE_D(81, l))
# define BOOST_PP_LIST_FOLD_RIGHT_82(o, s, l) BOOST_PP_LIST_FOLD_LEFT_82(o, s, BOOST_PP_LIST_REVERSE_D(82, l))
# define BOOST_PP_LIST_FOLD_RIGHT_83(o, s, l) BOOST_PP_LIST_FOLD_LEFT_83(o, s, BOOST_PP_LIST_REVERSE_D(83, l))
# define BOOST_PP_LIST_FOLD_RIGHT_84(o, s, l) BOOST_PP_LIST_FOLD_LEFT_84(o, s, BOOST_PP_LIST_REVERSE_D(84, l))
# define BOOST_PP_LIST_FOLD_RIGHT_85(o, s, l) BOOST_PP_LIST_FOLD_LEFT_85(o, s, BOOST_PP_LIST_REVERSE_D(85, l))
# define BOOST_PP_LIST_FOLD_RIGHT_86(o, s, l) BOOST_PP_LIST_FOLD_LEFT_86(o, s, BOOST_PP_LIST_REVERSE_D(86, l))
# define BOOST_PP_LIST_FOLD_RIGHT_87(o, s, l) BOOST_PP_LIST_FOLD_LEFT_87(o, s, BOOST_PP_LIST_REVERSE_D(87, l))
# define BOOST_PP_LIST_FOLD_RIGHT_88(o, s, l) BOOST_PP_LIST_FOLD_LEFT_88(o, s, BOOST_PP_LIST_REVERSE_D(88, l))
# define BOOST_PP_LIST_FOLD_RIGHT_89(o, s, l) BOOST_PP_LIST_FOLD_LEFT_89(o, s, BOOST_PP_LIST_REVERSE_D(89, l))
# define BOOST_PP_LIST_FOLD_RIGHT_90(o, s, l) BOOST_PP_LIST_FOLD_LEFT_90(o, s, BOOST_PP_LIST_REVERSE_D(90, l))
# define BOOST_PP_LIST_FOLD_RIGHT_91(o, s, l) BOOST_PP_LIST_FOLD_LEFT_91(o, s, BOOST_PP_LIST_REVERSE_D(91, l))
# define BOOST_PP_LIST_FOLD_RIGHT_92(o, s, l) BOOST_PP_LIST_FOLD_LEFT_92(o, s, BOOST_PP_LIST_REVERSE_D(92, l))
# define BOOST_PP_LIST_FOLD_RIGHT_93(o, s, l) BOOST_PP_LIST_FOLD_LEFT_93(o, s, BOOST_PP_LIST_REVERSE_D(93, l))
# define BOOST_PP_LIST_FOLD_RIGHT_94(o, s, l) BOOST_PP_LIST_FOLD_LEFT_94(o, s, BOOST_PP_LIST_REVERSE_D(94, l))
# define BOOST_PP_LIST_FOLD_RIGHT_95(o, s, l) BOOST_PP_LIST_FOLD_LEFT_95(o, s, BOOST_PP_LIST_REVERSE_D(95, l))
# define BOOST_PP_LIST_FOLD_RIGHT_96(o, s, l) BOOST_PP_LIST_FOLD_LEFT_96(o, s, BOOST_PP_LIST_REVERSE_D(96, l))
# define BOOST_PP_LIST_FOLD_RIGHT_97(o, s, l) BOOST_PP_LIST_FOLD_LEFT_97(o, s, BOOST_PP_LIST_REVERSE_D(97, l))
# define BOOST_PP_LIST_FOLD_RIGHT_98(o, s, l) BOOST_PP_LIST_FOLD_LEFT_98(o, s, BOOST_PP_LIST_REVERSE_D(98, l))
# define BOOST_PP_LIST_FOLD_RIGHT_99(o, s, l) BOOST_PP_LIST_FOLD_LEFT_99(o, s, BOOST_PP_LIST_REVERSE_D(99, l))
# define BOOST_PP_LIST_FOLD_RIGHT_100(o, s, l) BOOST_PP_LIST_FOLD_LEFT_100(o, s, BOOST_PP_LIST_REVERSE_D(100, l))
# define BOOST_PP_LIST_FOLD_RIGHT_101(o, s, l) BOOST_PP_LIST_FOLD_LEFT_101(o, s, BOOST_PP_LIST_REVERSE_D(101, l))
# define BOOST_PP_LIST_FOLD_RIGHT_102(o, s, l) BOOST_PP_LIST_FOLD_LEFT_102(o, s, BOOST_PP_LIST_REVERSE_D(102, l))
# define BOOST_PP_LIST_FOLD_RIGHT_103(o, s, l) BOOST_PP_LIST_FOLD_LEFT_103(o, s, BOOST_PP_LIST_REVERSE_D(103, l))
# define BOOST_PP_LIST_FOLD_RIGHT_104(o, s, l) BOOST_PP_LIST_FOLD_LEFT_104(o, s, BOOST_PP_LIST_REVERSE_D(104, l))
# define BOOST_PP_LIST_FOLD_RIGHT_105(o, s, l) BOOST_PP_LIST_FOLD_LEFT_105(o, s, BOOST_PP_LIST_REVERSE_D(105, l))
# define BOOST_PP_LIST_FOLD_RIGHT_106(o, s, l) BOOST_PP_LIST_FOLD_LEFT_106(o, s, BOOST_PP_LIST_REVERSE_D(106, l))
# define BOOST_PP_LIST_FOLD_RIGHT_107(o, s, l) BOOST_PP_LIST_FOLD_LEFT_107(o, s, BOOST_PP_LIST_REVERSE_D(107, l))
# define BOOST_PP_LIST_FOLD_RIGHT_108(o, s, l) BOOST_PP_LIST_FOLD_LEFT_108(o, s, BOOST_PP_LIST_REVERSE_D(108, l))
# define BOOST_PP_LIST_FOLD_RIGHT_109(o, s, l) BOOST_PP_LIST_FOLD_LEFT_109(o, s, BOOST_PP_LIST_REVERSE_D(109, l))
# define BOOST_PP_LIST_FOLD_RIGHT_110(o, s, l) BOOST_PP_LIST_FOLD_LEFT_110(o, s, BOOST_PP_LIST_REVERSE_D(110, l))
# define BOOST_PP_LIST_FOLD_RIGHT_111(o, s, l) BOOST_PP_LIST_FOLD_LEFT_111(o, s, BOOST_PP_LIST_REVERSE_D(111, l))
# define BOOST_PP_LIST_FOLD_RIGHT_112(o, s, l) BOOST_PP_LIST_FOLD_LEFT_112(o, s, BOOST_PP_LIST_REVERSE_D(112, l))
# define BOOST_PP_LIST_FOLD_RIGHT_113(o, s, l) BOOST_PP_LIST_FOLD_LEFT_113(o, s, BOOST_PP_LIST_REVERSE_D(113, l))
# define BOOST_PP_LIST_FOLD_RIGHT_114(o, s, l) BOOST_PP_LIST_FOLD_LEFT_114(o, s, BOOST_PP_LIST_REVERSE_D(114, l))
# define BOOST_PP_LIST_FOLD_RIGHT_115(o, s, l) BOOST_PP_LIST_FOLD_LEFT_115(o, s, BOOST_PP_LIST_REVERSE_D(115, l))
# define BOOST_PP_LIST_FOLD_RIGHT_116(o, s, l) BOOST_PP_LIST_FOLD_LEFT_116(o, s, BOOST_PP_LIST_REVERSE_D(116, l))
# define BOOST_PP_LIST_FOLD_RIGHT_117(o, s, l) BOOST_PP_LIST_FOLD_LEFT_117(o, s, BOOST_PP_LIST_REVERSE_D(117, l))
# define BOOST_PP_LIST_FOLD_RIGHT_118(o, s, l) BOOST_PP_LIST_FOLD_LEFT_118(o, s, BOOST_PP_LIST_REVERSE_D(118, l))
# define BOOST_PP_LIST_FOLD_RIGHT_119(o, s, l) BOOST_PP_LIST_FOLD_LEFT_119(o, s, BOOST_PP_LIST_REVERSE_D(119, l))
# define BOOST_PP_LIST_FOLD_RIGHT_120(o, s, l) BOOST_PP_LIST_FOLD_LEFT_120(o, s, BOOST_PP_LIST_REVERSE_D(120, l))
# define BOOST_PP_LIST_FOLD_RIGHT_121(o, s, l) BOOST_PP_LIST_FOLD_LEFT_121(o, s, BOOST_PP_LIST_REVERSE_D(121, l))
# define BOOST_PP_LIST_FOLD_RIGHT_122(o, s, l) BOOST_PP_LIST_FOLD_LEFT_122(o, s, BOOST_PP_LIST_REVERSE_D(122, l))
# define BOOST_PP_LIST_FOLD_RIGHT_123(o, s, l) BOOST_PP_LIST_FOLD_LEFT_123(o, s, BOOST_PP_LIST_REVERSE_D(123, l))
# define BOOST_PP_LIST_FOLD_RIGHT_124(o, s, l) BOOST_PP_LIST_FOLD_LEFT_124(o, s, BOOST_PP_LIST_REVERSE_D(124, l))
# define BOOST_PP_LIST_FOLD_RIGHT_125(o, s, l) BOOST_PP_LIST_FOLD_LEFT_125(o, s, BOOST_PP_LIST_REVERSE_D(125, l))
# define BOOST_PP_LIST_FOLD_RIGHT_126(o, s, l) BOOST_PP_LIST_FOLD_LEFT_126(o, s, BOOST_PP_LIST_REVERSE_D(126, l))
# define BOOST_PP_LIST_FOLD_RIGHT_127(o, s, l) BOOST_PP_LIST_FOLD_LEFT_127(o, s, BOOST_PP_LIST_REVERSE_D(127, l))
# define BOOST_PP_LIST_FOLD_RIGHT_128(o, s, l) BOOST_PP_LIST_FOLD_LEFT_128(o, s, BOOST_PP_LIST_REVERSE_D(128, l))
# define BOOST_PP_LIST_FOLD_RIGHT_129(o, s, l) BOOST_PP_LIST_FOLD_LEFT_129(o, s, BOOST_PP_LIST_REVERSE_D(129, l))
# define BOOST_PP_LIST_FOLD_RIGHT_130(o, s, l) BOOST_PP_LIST_FOLD_LEFT_130(o, s, BOOST_PP_LIST_REVERSE_D(130, l))
# define BOOST_PP_LIST_FOLD_RIGHT_131(o, s, l) BOOST_PP_LIST_FOLD_LEFT_131(o, s, BOOST_PP_LIST_REVERSE_D(131, l))
# define BOOST_PP_LIST_FOLD_RIGHT_132(o, s, l) BOOST_PP_LIST_FOLD_LEFT_132(o, s, BOOST_PP_LIST_REVERSE_D(132, l))
# define BOOST_PP_LIST_FOLD_RIGHT_133(o, s, l) BOOST_PP_LIST_FOLD_LEFT_133(o, s, BOOST_PP_LIST_REVERSE_D(133, l))
# define BOOST_PP_LIST_FOLD_RIGHT_134(o, s, l) BOOST_PP_LIST_FOLD_LEFT_134(o, s, BOOST_PP_LIST_REVERSE_D(134, l))
# define BOOST_PP_LIST_FOLD_RIGHT_135(o, s, l) BOOST_PP_LIST_FOLD_LEFT_135(o, s, BOOST_PP_LIST_REVERSE_D(135, l))
# define BOOST_PP_LIST_FOLD_RIGHT_136(o, s, l) BOOST_PP_LIST_FOLD_LEFT_136(o, s, BOOST_PP_LIST_REVERSE_D(136, l))
# define BOOST_PP_LIST_FOLD_RIGHT_137(o, s, l) BOOST_PP_LIST_FOLD_LEFT_137(o, s, BOOST_PP_LIST_REVERSE_D(137, l))
# define BOOST_PP_LIST_FOLD_RIGHT_138(o, s, l) BOOST_PP_LIST_FOLD_LEFT_138(o, s, BOOST_PP_LIST_REVERSE_D(138, l))
# define BOOST_PP_LIST_FOLD_RIGHT_139(o, s, l) BOOST_PP_LIST_FOLD_LEFT_139(o, s, BOOST_PP_LIST_REVERSE_D(139, l))
# define BOOST_PP_LIST_FOLD_RIGHT_140(o, s, l) BOOST_PP_LIST_FOLD_LEFT_140(o, s, BOOST_PP_LIST_REVERSE_D(140, l))
# define BOOST_PP_LIST_FOLD_RIGHT_141(o, s, l) BOOST_PP_LIST_FOLD_LEFT_141(o, s, BOOST_PP_LIST_REVERSE_D(141, l))
# define BOOST_PP_LIST_FOLD_RIGHT_142(o, s, l) BOOST_PP_LIST_FOLD_LEFT_142(o, s, BOOST_PP_LIST_REVERSE_D(142, l))
# define BOOST_PP_LIST_FOLD_RIGHT_143(o, s, l) BOOST_PP_LIST_FOLD_LEFT_143(o, s, BOOST_PP_LIST_REVERSE_D(143, l))
# define BOOST_PP_LIST_FOLD_RIGHT_144(o, s, l) BOOST_PP_LIST_FOLD_LEFT_144(o, s, BOOST_PP_LIST_REVERSE_D(144, l))
# define BOOST_PP_LIST_FOLD_RIGHT_145(o, s, l) BOOST_PP_LIST_FOLD_LEFT_145(o, s, BOOST_PP_LIST_REVERSE_D(145, l))
# define BOOST_PP_LIST_FOLD_RIGHT_146(o, s, l) BOOST_PP_LIST_FOLD_LEFT_146(o, s, BOOST_PP_LIST_REVERSE_D(146, l))
# define BOOST_PP_LIST_FOLD_RIGHT_147(o, s, l) BOOST_PP_LIST_FOLD_LEFT_147(o, s, BOOST_PP_LIST_REVERSE_D(147, l))
# define BOOST_PP_LIST_FOLD_RIGHT_148(o, s, l) BOOST_PP_LIST_FOLD_LEFT_148(o, s, BOOST_PP_LIST_REVERSE_D(148, l))
# define BOOST_PP_LIST_FOLD_RIGHT_149(o, s, l) BOOST_PP_LIST_FOLD_LEFT_149(o, s, BOOST_PP_LIST_REVERSE_D(149, l))
# define BOOST_PP_LIST_FOLD_RIGHT_150(o, s, l) BOOST_PP_LIST_FOLD_LEFT_150(o, s, BOOST_PP_LIST_REVERSE_D(150, l))
# define BOOST_PP_LIST_FOLD_RIGHT_151(o, s, l) BOOST_PP_LIST_FOLD_LEFT_151(o, s, BOOST_PP_LIST_REVERSE_D(151, l))
# define BOOST_PP_LIST_FOLD_RIGHT_152(o, s, l) BOOST_PP_LIST_FOLD_LEFT_152(o, s, BOOST_PP_LIST_REVERSE_D(152, l))
# define BOOST_PP_LIST_FOLD_RIGHT_153(o, s, l) BOOST_PP_LIST_FOLD_LEFT_153(o, s, BOOST_PP_LIST_REVERSE_D(153, l))
# define BOOST_PP_LIST_FOLD_RIGHT_154(o, s, l) BOOST_PP_LIST_FOLD_LEFT_154(o, s, BOOST_PP_LIST_REVERSE_D(154, l))
# define BOOST_PP_LIST_FOLD_RIGHT_155(o, s, l) BOOST_PP_LIST_FOLD_LEFT_155(o, s, BOOST_PP_LIST_REVERSE_D(155, l))
# define BOOST_PP_LIST_FOLD_RIGHT_156(o, s, l) BOOST_PP_LIST_FOLD_LEFT_156(o, s, BOOST_PP_LIST_REVERSE_D(156, l))
# define BOOST_PP_LIST_FOLD_RIGHT_157(o, s, l) BOOST_PP_LIST_FOLD_LEFT_157(o, s, BOOST_PP_LIST_REVERSE_D(157, l))
# define BOOST_PP_LIST_FOLD_RIGHT_158(o, s, l) BOOST_PP_LIST_FOLD_LEFT_158(o, s, BOOST_PP_LIST_REVERSE_D(158, l))
# define BOOST_PP_LIST_FOLD_RIGHT_159(o, s, l) BOOST_PP_LIST_FOLD_LEFT_159(o, s, BOOST_PP_LIST_REVERSE_D(159, l))
# define BOOST_PP_LIST_FOLD_RIGHT_160(o, s, l) BOOST_PP_LIST_FOLD_LEFT_160(o, s, BOOST_PP_LIST_REVERSE_D(160, l))
# define BOOST_PP_LIST_FOLD_RIGHT_161(o, s, l) BOOST_PP_LIST_FOLD_LEFT_161(o, s, BOOST_PP_LIST_REVERSE_D(161, l))
# define BOOST_PP_LIST_FOLD_RIGHT_162(o, s, l) BOOST_PP_LIST_FOLD_LEFT_162(o, s, BOOST_PP_LIST_REVERSE_D(162, l))
# define BOOST_PP_LIST_FOLD_RIGHT_163(o, s, l) BOOST_PP_LIST_FOLD_LEFT_163(o, s, BOOST_PP_LIST_REVERSE_D(163, l))
# define BOOST_PP_LIST_FOLD_RIGHT_164(o, s, l) BOOST_PP_LIST_FOLD_LEFT_164(o, s, BOOST_PP_LIST_REVERSE_D(164, l))
# define BOOST_PP_LIST_FOLD_RIGHT_165(o, s, l) BOOST_PP_LIST_FOLD_LEFT_165(o, s, BOOST_PP_LIST_REVERSE_D(165, l))
# define BOOST_PP_LIST_FOLD_RIGHT_166(o, s, l) BOOST_PP_LIST_FOLD_LEFT_166(o, s, BOOST_PP_LIST_REVERSE_D(166, l))
# define BOOST_PP_LIST_FOLD_RIGHT_167(o, s, l) BOOST_PP_LIST_FOLD_LEFT_167(o, s, BOOST_PP_LIST_REVERSE_D(167, l))
# define BOOST_PP_LIST_FOLD_RIGHT_168(o, s, l) BOOST_PP_LIST_FOLD_LEFT_168(o, s, BOOST_PP_LIST_REVERSE_D(168, l))
# define BOOST_PP_LIST_FOLD_RIGHT_169(o, s, l) BOOST_PP_LIST_FOLD_LEFT_169(o, s, BOOST_PP_LIST_REVERSE_D(169, l))
# define BOOST_PP_LIST_FOLD_RIGHT_170(o, s, l) BOOST_PP_LIST_FOLD_LEFT_170(o, s, BOOST_PP_LIST_REVERSE_D(170, l))
# define BOOST_PP_LIST_FOLD_RIGHT_171(o, s, l) BOOST_PP_LIST_FOLD_LEFT_171(o, s, BOOST_PP_LIST_REVERSE_D(171, l))
# define BOOST_PP_LIST_FOLD_RIGHT_172(o, s, l) BOOST_PP_LIST_FOLD_LEFT_172(o, s, BOOST_PP_LIST_REVERSE_D(172, l))
# define BOOST_PP_LIST_FOLD_RIGHT_173(o, s, l) BOOST_PP_LIST_FOLD_LEFT_173(o, s, BOOST_PP_LIST_REVERSE_D(173, l))
# define BOOST_PP_LIST_FOLD_RIGHT_174(o, s, l) BOOST_PP_LIST_FOLD_LEFT_174(o, s, BOOST_PP_LIST_REVERSE_D(174, l))
# define BOOST_PP_LIST_FOLD_RIGHT_175(o, s, l) BOOST_PP_LIST_FOLD_LEFT_175(o, s, BOOST_PP_LIST_REVERSE_D(175, l))
# define BOOST_PP_LIST_FOLD_RIGHT_176(o, s, l) BOOST_PP_LIST_FOLD_LEFT_176(o, s, BOOST_PP_LIST_REVERSE_D(176, l))
# define BOOST_PP_LIST_FOLD_RIGHT_177(o, s, l) BOOST_PP_LIST_FOLD_LEFT_177(o, s, BOOST_PP_LIST_REVERSE_D(177, l))
# define BOOST_PP_LIST_FOLD_RIGHT_178(o, s, l) BOOST_PP_LIST_FOLD_LEFT_178(o, s, BOOST_PP_LIST_REVERSE_D(178, l))
# define BOOST_PP_LIST_FOLD_RIGHT_179(o, s, l) BOOST_PP_LIST_FOLD_LEFT_179(o, s, BOOST_PP_LIST_REVERSE_D(179, l))
# define BOOST_PP_LIST_FOLD_RIGHT_180(o, s, l) BOOST_PP_LIST_FOLD_LEFT_180(o, s, BOOST_PP_LIST_REVERSE_D(180, l))
# define BOOST_PP_LIST_FOLD_RIGHT_181(o, s, l) BOOST_PP_LIST_FOLD_LEFT_181(o, s, BOOST_PP_LIST_REVERSE_D(181, l))
# define BOOST_PP_LIST_FOLD_RIGHT_182(o, s, l) BOOST_PP_LIST_FOLD_LEFT_182(o, s, BOOST_PP_LIST_REVERSE_D(182, l))
# define BOOST_PP_LIST_FOLD_RIGHT_183(o, s, l) BOOST_PP_LIST_FOLD_LEFT_183(o, s, BOOST_PP_LIST_REVERSE_D(183, l))
# define BOOST_PP_LIST_FOLD_RIGHT_184(o, s, l) BOOST_PP_LIST_FOLD_LEFT_184(o, s, BOOST_PP_LIST_REVERSE_D(184, l))
# define BOOST_PP_LIST_FOLD_RIGHT_185(o, s, l) BOOST_PP_LIST_FOLD_LEFT_185(o, s, BOOST_PP_LIST_REVERSE_D(185, l))
# define BOOST_PP_LIST_FOLD_RIGHT_186(o, s, l) BOOST_PP_LIST_FOLD_LEFT_186(o, s, BOOST_PP_LIST_REVERSE_D(186, l))
# define BOOST_PP_LIST_FOLD_RIGHT_187(o, s, l) BOOST_PP_LIST_FOLD_LEFT_187(o, s, BOOST_PP_LIST_REVERSE_D(187, l))
# define BOOST_PP_LIST_FOLD_RIGHT_188(o, s, l) BOOST_PP_LIST_FOLD_LEFT_188(o, s, BOOST_PP_LIST_REVERSE_D(188, l))
# define BOOST_PP_LIST_FOLD_RIGHT_189(o, s, l) BOOST_PP_LIST_FOLD_LEFT_189(o, s, BOOST_PP_LIST_REVERSE_D(189, l))
# define BOOST_PP_LIST_FOLD_RIGHT_190(o, s, l) BOOST_PP_LIST_FOLD_LEFT_190(o, s, BOOST_PP_LIST_REVERSE_D(190, l))
# define BOOST_PP_LIST_FOLD_RIGHT_191(o, s, l) BOOST_PP_LIST_FOLD_LEFT_191(o, s, BOOST_PP_LIST_REVERSE_D(191, l))
# define BOOST_PP_LIST_FOLD_RIGHT_192(o, s, l) BOOST_PP_LIST_FOLD_LEFT_192(o, s, BOOST_PP_LIST_REVERSE_D(192, l))
# define BOOST_PP_LIST_FOLD_RIGHT_193(o, s, l) BOOST_PP_LIST_FOLD_LEFT_193(o, s, BOOST_PP_LIST_REVERSE_D(193, l))
# define BOOST_PP_LIST_FOLD_RIGHT_194(o, s, l) BOOST_PP_LIST_FOLD_LEFT_194(o, s, BOOST_PP_LIST_REVERSE_D(194, l))
# define BOOST_PP_LIST_FOLD_RIGHT_195(o, s, l) BOOST_PP_LIST_FOLD_LEFT_195(o, s, BOOST_PP_LIST_REVERSE_D(195, l))
# define BOOST_PP_LIST_FOLD_RIGHT_196(o, s, l) BOOST_PP_LIST_FOLD_LEFT_196(o, s, BOOST_PP_LIST_REVERSE_D(196, l))
# define BOOST_PP_LIST_FOLD_RIGHT_197(o, s, l) BOOST_PP_LIST_FOLD_LEFT_197(o, s, BOOST_PP_LIST_REVERSE_D(197, l))
# define BOOST_PP_LIST_FOLD_RIGHT_198(o, s, l) BOOST_PP_LIST_FOLD_LEFT_198(o, s, BOOST_PP_LIST_REVERSE_D(198, l))
# define BOOST_PP_LIST_FOLD_RIGHT_199(o, s, l) BOOST_PP_LIST_FOLD_LEFT_199(o, s, BOOST_PP_LIST_REVERSE_D(199, l))
# define BOOST_PP_LIST_FOLD_RIGHT_200(o, s, l) BOOST_PP_LIST_FOLD_LEFT_200(o, s, BOOST_PP_LIST_REVERSE_D(200, l))
# define BOOST_PP_LIST_FOLD_RIGHT_201(o, s, l) BOOST_PP_LIST_FOLD_LEFT_201(o, s, BOOST_PP_LIST_REVERSE_D(201, l))
# define BOOST_PP_LIST_FOLD_RIGHT_202(o, s, l) BOOST_PP_LIST_FOLD_LEFT_202(o, s, BOOST_PP_LIST_REVERSE_D(202, l))
# define BOOST_PP_LIST_FOLD_RIGHT_203(o, s, l) BOOST_PP_LIST_FOLD_LEFT_203(o, s, BOOST_PP_LIST_REVERSE_D(203, l))
# define BOOST_PP_LIST_FOLD_RIGHT_204(o, s, l) BOOST_PP_LIST_FOLD_LEFT_204(o, s, BOOST_PP_LIST_REVERSE_D(204, l))
# define BOOST_PP_LIST_FOLD_RIGHT_205(o, s, l) BOOST_PP_LIST_FOLD_LEFT_205(o, s, BOOST_PP_LIST_REVERSE_D(205, l))
# define BOOST_PP_LIST_FOLD_RIGHT_206(o, s, l) BOOST_PP_LIST_FOLD_LEFT_206(o, s, BOOST_PP_LIST_REVERSE_D(206, l))
# define BOOST_PP_LIST_FOLD_RIGHT_207(o, s, l) BOOST_PP_LIST_FOLD_LEFT_207(o, s, BOOST_PP_LIST_REVERSE_D(207, l))
# define BOOST_PP_LIST_FOLD_RIGHT_208(o, s, l) BOOST_PP_LIST_FOLD_LEFT_208(o, s, BOOST_PP_LIST_REVERSE_D(208, l))
# define BOOST_PP_LIST_FOLD_RIGHT_209(o, s, l) BOOST_PP_LIST_FOLD_LEFT_209(o, s, BOOST_PP_LIST_REVERSE_D(209, l))
# define BOOST_PP_LIST_FOLD_RIGHT_210(o, s, l) BOOST_PP_LIST_FOLD_LEFT_210(o, s, BOOST_PP_LIST_REVERSE_D(210, l))
# define BOOST_PP_LIST_FOLD_RIGHT_211(o, s, l) BOOST_PP_LIST_FOLD_LEFT_211(o, s, BOOST_PP_LIST_REVERSE_D(211, l))
# define BOOST_PP_LIST_FOLD_RIGHT_212(o, s, l) BOOST_PP_LIST_FOLD_LEFT_212(o, s, BOOST_PP_LIST_REVERSE_D(212, l))
# define BOOST_PP_LIST_FOLD_RIGHT_213(o, s, l) BOOST_PP_LIST_FOLD_LEFT_213(o, s, BOOST_PP_LIST_REVERSE_D(213, l))
# define BOOST_PP_LIST_FOLD_RIGHT_214(o, s, l) BOOST_PP_LIST_FOLD_LEFT_214(o, s, BOOST_PP_LIST_REVERSE_D(214, l))
# define BOOST_PP_LIST_FOLD_RIGHT_215(o, s, l) BOOST_PP_LIST_FOLD_LEFT_215(o, s, BOOST_PP_LIST_REVERSE_D(215, l))
# define BOOST_PP_LIST_FOLD_RIGHT_216(o, s, l) BOOST_PP_LIST_FOLD_LEFT_216(o, s, BOOST_PP_LIST_REVERSE_D(216, l))
# define BOOST_PP_LIST_FOLD_RIGHT_217(o, s, l) BOOST_PP_LIST_FOLD_LEFT_217(o, s, BOOST_PP_LIST_REVERSE_D(217, l))
# define BOOST_PP_LIST_FOLD_RIGHT_218(o, s, l) BOOST_PP_LIST_FOLD_LEFT_218(o, s, BOOST_PP_LIST_REVERSE_D(218, l))
# define BOOST_PP_LIST_FOLD_RIGHT_219(o, s, l) BOOST_PP_LIST_FOLD_LEFT_219(o, s, BOOST_PP_LIST_REVERSE_D(219, l))
# define BOOST_PP_LIST_FOLD_RIGHT_220(o, s, l) BOOST_PP_LIST_FOLD_LEFT_220(o, s, BOOST_PP_LIST_REVERSE_D(220, l))
# define BOOST_PP_LIST_FOLD_RIGHT_221(o, s, l) BOOST_PP_LIST_FOLD_LEFT_221(o, s, BOOST_PP_LIST_REVERSE_D(221, l))
# define BOOST_PP_LIST_FOLD_RIGHT_222(o, s, l) BOOST_PP_LIST_FOLD_LEFT_222(o, s, BOOST_PP_LIST_REVERSE_D(222, l))
# define BOOST_PP_LIST_FOLD_RIGHT_223(o, s, l) BOOST_PP_LIST_FOLD_LEFT_223(o, s, BOOST_PP_LIST_REVERSE_D(223, l))
# define BOOST_PP_LIST_FOLD_RIGHT_224(o, s, l) BOOST_PP_LIST_FOLD_LEFT_224(o, s, BOOST_PP_LIST_REVERSE_D(224, l))
# define BOOST_PP_LIST_FOLD_RIGHT_225(o, s, l) BOOST_PP_LIST_FOLD_LEFT_225(o, s, BOOST_PP_LIST_REVERSE_D(225, l))
# define BOOST_PP_LIST_FOLD_RIGHT_226(o, s, l) BOOST_PP_LIST_FOLD_LEFT_226(o, s, BOOST_PP_LIST_REVERSE_D(226, l))
# define BOOST_PP_LIST_FOLD_RIGHT_227(o, s, l) BOOST_PP_LIST_FOLD_LEFT_227(o, s, BOOST_PP_LIST_REVERSE_D(227, l))
# define BOOST_PP_LIST_FOLD_RIGHT_228(o, s, l) BOOST_PP_LIST_FOLD_LEFT_228(o, s, BOOST_PP_LIST_REVERSE_D(228, l))
# define BOOST_PP_LIST_FOLD_RIGHT_229(o, s, l) BOOST_PP_LIST_FOLD_LEFT_229(o, s, BOOST_PP_LIST_REVERSE_D(229, l))
# define BOOST_PP_LIST_FOLD_RIGHT_230(o, s, l) BOOST_PP_LIST_FOLD_LEFT_230(o, s, BOOST_PP_LIST_REVERSE_D(230, l))
# define BOOST_PP_LIST_FOLD_RIGHT_231(o, s, l) BOOST_PP_LIST_FOLD_LEFT_231(o, s, BOOST_PP_LIST_REVERSE_D(231, l))
# define BOOST_PP_LIST_FOLD_RIGHT_232(o, s, l) BOOST_PP_LIST_FOLD_LEFT_232(o, s, BOOST_PP_LIST_REVERSE_D(232, l))
# define BOOST_PP_LIST_FOLD_RIGHT_233(o, s, l) BOOST_PP_LIST_FOLD_LEFT_233(o, s, BOOST_PP_LIST_REVERSE_D(233, l))
# define BOOST_PP_LIST_FOLD_RIGHT_234(o, s, l) BOOST_PP_LIST_FOLD_LEFT_234(o, s, BOOST_PP_LIST_REVERSE_D(234, l))
# define BOOST_PP_LIST_FOLD_RIGHT_235(o, s, l) BOOST_PP_LIST_FOLD_LEFT_235(o, s, BOOST_PP_LIST_REVERSE_D(235, l))
# define BOOST_PP_LIST_FOLD_RIGHT_236(o, s, l) BOOST_PP_LIST_FOLD_LEFT_236(o, s, BOOST_PP_LIST_REVERSE_D(236, l))
# define BOOST_PP_LIST_FOLD_RIGHT_237(o, s, l) BOOST_PP_LIST_FOLD_LEFT_237(o, s, BOOST_PP_LIST_REVERSE_D(237, l))
# define BOOST_PP_LIST_FOLD_RIGHT_238(o, s, l) BOOST_PP_LIST_FOLD_LEFT_238(o, s, BOOST_PP_LIST_REVERSE_D(238, l))
# define BOOST_PP_LIST_FOLD_RIGHT_239(o, s, l) BOOST_PP_LIST_FOLD_LEFT_239(o, s, BOOST_PP_LIST_REVERSE_D(239, l))
# define BOOST_PP_LIST_FOLD_RIGHT_240(o, s, l) BOOST_PP_LIST_FOLD_LEFT_240(o, s, BOOST_PP_LIST_REVERSE_D(240, l))
# define BOOST_PP_LIST_FOLD_RIGHT_241(o, s, l) BOOST_PP_LIST_FOLD_LEFT_241(o, s, BOOST_PP_LIST_REVERSE_D(241, l))
# define BOOST_PP_LIST_FOLD_RIGHT_242(o, s, l) BOOST_PP_LIST_FOLD_LEFT_242(o, s, BOOST_PP_LIST_REVERSE_D(242, l))
# define BOOST_PP_LIST_FOLD_RIGHT_243(o, s, l) BOOST_PP_LIST_FOLD_LEFT_243(o, s, BOOST_PP_LIST_REVERSE_D(243, l))
# define BOOST_PP_LIST_FOLD_RIGHT_244(o, s, l) BOOST_PP_LIST_FOLD_LEFT_244(o, s, BOOST_PP_LIST_REVERSE_D(244, l))
# define BOOST_PP_LIST_FOLD_RIGHT_245(o, s, l) BOOST_PP_LIST_FOLD_LEFT_245(o, s, BOOST_PP_LIST_REVERSE_D(245, l))
# define BOOST_PP_LIST_FOLD_RIGHT_246(o, s, l) BOOST_PP_LIST_FOLD_LEFT_246(o, s, BOOST_PP_LIST_REVERSE_D(246, l))
# define BOOST_PP_LIST_FOLD_RIGHT_247(o, s, l) BOOST_PP_LIST_FOLD_LEFT_247(o, s, BOOST_PP_LIST_REVERSE_D(247, l))
# define BOOST_PP_LIST_FOLD_RIGHT_248(o, s, l) BOOST_PP_LIST_FOLD_LEFT_248(o, s, BOOST_PP_LIST_REVERSE_D(248, l))
# define BOOST_PP_LIST_FOLD_RIGHT_249(o, s, l) BOOST_PP_LIST_FOLD_LEFT_249(o, s, BOOST_PP_LIST_REVERSE_D(249, l))
# define BOOST_PP_LIST_FOLD_RIGHT_250(o, s, l) BOOST_PP_LIST_FOLD_LEFT_250(o, s, BOOST_PP_LIST_REVERSE_D(250, l))
# define BOOST_PP_LIST_FOLD_RIGHT_251(o, s, l) BOOST_PP_LIST_FOLD_LEFT_251(o, s, BOOST_PP_LIST_REVERSE_D(251, l))
# define BOOST_PP_LIST_FOLD_RIGHT_252(o, s, l) BOOST_PP_LIST_FOLD_LEFT_252(o, s, BOOST_PP_LIST_REVERSE_D(252, l))
# define BOOST_PP_LIST_FOLD_RIGHT_253(o, s, l) BOOST_PP_LIST_FOLD_LEFT_253(o, s, BOOST_PP_LIST_REVERSE_D(253, l))
# define BOOST_PP_LIST_FOLD_RIGHT_254(o, s, l) BOOST_PP_LIST_FOLD_LEFT_254(o, s, BOOST_PP_LIST_REVERSE_D(254, l))
# define BOOST_PP_LIST_FOLD_RIGHT_255(o, s, l) BOOST_PP_LIST_FOLD_LEFT_255(o, s, BOOST_PP_LIST_REVERSE_D(255, l))
# define BOOST_PP_LIST_FOLD_RIGHT_256(o, s, l) BOOST_PP_LIST_FOLD_LEFT_256(o, s, BOOST_PP_LIST_REVERSE_D(256, l))
#
# else
#
# include <boost_kahypar/preprocessor/list/fold_left.hpp>
# include <boost_kahypar/preprocessor/list/reverse.hpp>
# include <boost_kahypar/preprocessor/config/limits.hpp>
#
# if BOOST_PP_LIMIT_WHILE == 256
# include <boost_kahypar/preprocessor/list/detail/limits/fold_right_256.hpp>
# elif BOOST_PP_LIMIT_WHILE == 512
# include <boost_kahypar/preprocessor/list/detail/limits/fold_right_256.hpp>
# include <boost_kahypar/preprocessor/list/detail/limits/fold_right_512.hpp>
# elif BOOST_PP_LIMIT_WHILE == 1024
# include <boost_kahypar/preprocessor/list/detail/limits/fold_right_256.hpp>
# include <boost_kahypar/preprocessor/list/detail/limits/fold_right_512.hpp>
# include <boost_kahypar/preprocessor/list/detail/limits/fold_right_1024.hpp>
# else
# error Incorrect value for the BOOST_PP_LIMIT_WHILE limit
# endif
#
# endif
#
# endif
