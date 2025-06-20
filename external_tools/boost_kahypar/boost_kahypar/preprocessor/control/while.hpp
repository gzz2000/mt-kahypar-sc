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
# ifndef BOOST_PREPROCESSOR_CONTROL_WHILE_HPP
# define BOOST_PREPROCESSOR_CONTROL_WHILE_HPP
#
# include <boost_kahypar/preprocessor/config/config.hpp>
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_STRICT()
#
# include <boost_kahypar/preprocessor/cat.hpp>
# include <boost_kahypar/preprocessor/config/config.hpp>
# include <boost_kahypar/preprocessor/debug/error.hpp>
# include <boost_kahypar/preprocessor/detail/auto_rec.hpp>
# include <boost_kahypar/preprocessor/list/fold_left.hpp>
# include <boost_kahypar/preprocessor/list/fold_right.hpp>
# include <boost_kahypar/preprocessor/logical/bitand.hpp>
#
# /* BOOST_PP_WHILE */
#
# if 0
#    define BOOST_PP_WHILE(pred, op, state)
# endif
#
# define BOOST_PP_WHILE BOOST_PP_CAT(BOOST_PP_WHILE_, BOOST_PP_AUTO_REC(BOOST_PP_WHILE_P, 256))
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    define BOOST_PP_WHILE_P(n) BOOST_PP_BITAND(BOOST_PP_CAT(BOOST_PP_WHILE_CHECK_, BOOST_PP_WHILE_ ## n(BOOST_PP_WHILE_F, BOOST_PP_NIL, BOOST_PP_NIL)), BOOST_PP_BITAND(BOOST_PP_CAT(BOOST_PP_LIST_FOLD_LEFT_CHECK_, BOOST_PP_LIST_FOLD_LEFT_ ## n(BOOST_PP_NIL, BOOST_PP_NIL, BOOST_PP_NIL)), BOOST_PP_CAT(BOOST_PP_LIST_FOLD_RIGHT_CHECK_, BOOST_PP_LIST_FOLD_RIGHT_ ## n(BOOST_PP_NIL, BOOST_PP_NIL, BOOST_PP_NIL))))
# else
#    define BOOST_PP_WHILE_P(n) BOOST_PP_BITAND(BOOST_PP_CAT(BOOST_PP_WHILE_CHECK_, BOOST_PP_WHILE_ ## n(BOOST_PP_WHILE_F, BOOST_PP_NIL, BOOST_PP_NIL)), BOOST_PP_CAT(BOOST_PP_LIST_FOLD_LEFT_CHECK_, BOOST_PP_LIST_FOLD_LEFT_ ## n(BOOST_PP_NIL, BOOST_PP_NIL, BOOST_PP_NIL)))
# endif
#
# define BOOST_PP_WHILE_F(d, _) 0
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    include <boost_kahypar/preprocessor/control/detail/edg/while.hpp>
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    include <boost_kahypar/preprocessor/control/detail/msvc/while.hpp>
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_DMC()
#    include <boost_kahypar/preprocessor/control/detail/dmc/while.hpp>
# else
#    include <boost_kahypar/preprocessor/control/detail/while.hpp>
# endif
#
# define BOOST_PP_WHILE_257(p, o, s) BOOST_PP_ERROR(0x0001)
#
# define BOOST_PP_WHILE_CHECK_BOOST_PP_NIL 1
#
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_1(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_2(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_3(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_4(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_5(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_6(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_7(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_8(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_9(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_10(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_11(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_12(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_13(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_14(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_15(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_16(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_17(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_18(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_19(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_20(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_21(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_22(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_23(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_24(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_25(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_26(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_27(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_28(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_29(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_30(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_31(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_32(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_33(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_34(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_35(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_36(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_37(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_38(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_39(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_40(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_41(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_42(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_43(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_44(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_45(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_46(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_47(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_48(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_49(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_50(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_51(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_52(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_53(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_54(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_55(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_56(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_57(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_58(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_59(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_60(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_61(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_62(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_63(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_64(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_65(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_66(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_67(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_68(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_69(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_70(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_71(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_72(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_73(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_74(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_75(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_76(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_77(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_78(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_79(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_80(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_81(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_82(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_83(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_84(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_85(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_86(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_87(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_88(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_89(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_90(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_91(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_92(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_93(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_94(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_95(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_96(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_97(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_98(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_99(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_100(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_101(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_102(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_103(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_104(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_105(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_106(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_107(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_108(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_109(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_110(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_111(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_112(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_113(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_114(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_115(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_116(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_117(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_118(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_119(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_120(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_121(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_122(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_123(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_124(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_125(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_126(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_127(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_128(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_129(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_130(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_131(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_132(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_133(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_134(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_135(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_136(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_137(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_138(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_139(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_140(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_141(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_142(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_143(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_144(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_145(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_146(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_147(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_148(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_149(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_150(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_151(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_152(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_153(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_154(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_155(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_156(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_157(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_158(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_159(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_160(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_161(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_162(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_163(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_164(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_165(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_166(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_167(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_168(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_169(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_170(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_171(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_172(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_173(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_174(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_175(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_176(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_177(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_178(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_179(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_180(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_181(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_182(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_183(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_184(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_185(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_186(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_187(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_188(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_189(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_190(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_191(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_192(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_193(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_194(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_195(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_196(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_197(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_198(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_199(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_200(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_201(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_202(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_203(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_204(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_205(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_206(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_207(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_208(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_209(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_210(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_211(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_212(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_213(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_214(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_215(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_216(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_217(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_218(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_219(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_220(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_221(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_222(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_223(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_224(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_225(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_226(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_227(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_228(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_229(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_230(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_231(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_232(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_233(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_234(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_235(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_236(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_237(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_238(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_239(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_240(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_241(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_242(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_243(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_244(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_245(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_246(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_247(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_248(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_249(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_250(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_251(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_252(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_253(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_254(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_255(p, o, s) 0
# define BOOST_PP_WHILE_CHECK_BOOST_PP_WHILE_256(p, o, s) 0
#
# else
#
# include <boost_kahypar/preprocessor/arithmetic/dec.hpp>
# include <boost_kahypar/preprocessor/cat.hpp>
# include <boost_kahypar/preprocessor/debug/error.hpp>
# include <boost_kahypar/preprocessor/detail/auto_rec.hpp>
# include <boost_kahypar/preprocessor/list/fold_left.hpp>
# include <boost_kahypar/preprocessor/list/fold_right.hpp>
# include <boost_kahypar/preprocessor/logical/bitand.hpp>
# include <boost_kahypar/preprocessor/config/limits.hpp>
#
# /* BOOST_PP_WHILE */
#
# if 0
#    define BOOST_PP_WHILE(pred, op, state)
# endif
#
# if BOOST_PP_LIMIT_WHILE == 256
# define BOOST_PP_WHILE BOOST_PP_CAT(BOOST_PP_WHILE_, BOOST_PP_DEC(BOOST_PP_AUTO_REC(BOOST_PP_WHILE_P, 256)))
# elif BOOST_PP_LIMIT_WHILE == 512
# define BOOST_PP_WHILE BOOST_PP_CAT(BOOST_PP_WHILE_, BOOST_PP_DEC(BOOST_PP_AUTO_REC(BOOST_PP_WHILE_P, 512)))
# elif BOOST_PP_LIMIT_WHILE == 1024
# define BOOST_PP_WHILE BOOST_PP_CAT(BOOST_PP_WHILE_, BOOST_PP_DEC(BOOST_PP_AUTO_REC(BOOST_PP_WHILE_P, 1024)))
# else
# error Incorrect value for the BOOST_PP_LIMIT_WHILE limit
# endif
#
# define BOOST_PP_WHILE_P(n) BOOST_PP_WHILE_P_DEC(BOOST_PP_DEC(n))
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    define BOOST_PP_WHILE_P_DEC(n) BOOST_PP_BITAND(BOOST_PP_CAT(BOOST_PP_WHILE_CHECK_, BOOST_PP_CAT(BOOST_PP_WHILE_ , n)(BOOST_PP_WHILE_F, BOOST_PP_NIL, BOOST_PP_NIL)), BOOST_PP_BITAND(BOOST_PP_CAT(BOOST_PP_LIST_FOLD_LEFT_CHECK_, BOOST_PP_CAT(BOOST_PP_LIST_FOLD_LEFT_ , n)(BOOST_PP_NIL, BOOST_PP_NIL, BOOST_PP_NIL)), BOOST_PP_CAT(BOOST_PP_LIST_FOLD_RIGHT_CHECK_, BOOST_PP_CAT(BOOST_PP_LIST_FOLD_RIGHT_ , n)(BOOST_PP_NIL, BOOST_PP_NIL, BOOST_PP_NIL))))
# else
#    define BOOST_PP_WHILE_P_DEC(n) BOOST_PP_BITAND(BOOST_PP_CAT(BOOST_PP_WHILE_CHECK_, BOOST_PP_CAT(BOOST_PP_WHILE_ , n)(BOOST_PP_WHILE_F, BOOST_PP_NIL, BOOST_PP_NIL)), BOOST_PP_CAT(BOOST_PP_LIST_FOLD_LEFT_CHECK_, BOOST_PP_CAT(BOOST_PP_LIST_FOLD_LEFT_ , n)(BOOST_PP_NIL, BOOST_PP_NIL, BOOST_PP_NIL)))
# endif
#
# define BOOST_PP_WHILE_F(d, _) 0
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    include <boost_kahypar/preprocessor/control/detail/edg/while.hpp>
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    include <boost_kahypar/preprocessor/control/detail/msvc/while.hpp>
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_DMC()
#    include <boost_kahypar/preprocessor/control/detail/dmc/while.hpp>
# else
#    include <boost_kahypar/preprocessor/control/detail/while.hpp>
# endif
#
# if BOOST_PP_LIMIT_WHILE == 256
# define BOOST_PP_WHILE_257(p, o, s) BOOST_PP_ERROR(0x0001)
# elif BOOST_PP_LIMIT_WHILE == 512
# define BOOST_PP_WHILE_513(p, o, s) BOOST_PP_ERROR(0x0001)
# elif BOOST_PP_LIMIT_WHILE == 1024
# define BOOST_PP_WHILE_1025(p, o, s) BOOST_PP_ERROR(0x0001)
# endif
#
# define BOOST_PP_WHILE_CHECK_BOOST_PP_NIL 1
#
# if BOOST_PP_LIMIT_WHILE == 256
# include <boost_kahypar/preprocessor/control/limits/while_256.hpp>
# elif BOOST_PP_LIMIT_WHILE == 512
# include <boost_kahypar/preprocessor/control/limits/while_256.hpp>
# include <boost_kahypar/preprocessor/control/limits/while_512.hpp>
# elif BOOST_PP_LIMIT_WHILE == 1024
# include <boost_kahypar/preprocessor/control/limits/while_256.hpp>
# include <boost_kahypar/preprocessor/control/limits/while_512.hpp>
# include <boost_kahypar/preprocessor/control/limits/while_1024.hpp>
# endif
#
# endif
#
# endif
