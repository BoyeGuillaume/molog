/**
 * @file foreach.hpp
 * @author Guillaume Boyé
 * @brief 
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * 
 * Copyright (c) 2021 Guillaume Boyé
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the 
 * ), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED 
 * , WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#pragma once

#include <molog/mologexcept.hpp>

/*! \cond PRIVATE */
#pragma region Private Implementation
#define MO_FOR_EACH_P0_0(WHAT)
#define MO_FOR_EACH_P0_1(WHAT, x)                                                                  WHAT(x)
#define MO_FOR_EACH_P0_2(WHAT, x, ...)                                                             WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_1(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_3(WHAT, x, ...)                                                             WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_2(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_4(WHAT, x, ...)                                                             WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_3(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_5(WHAT, x, ...)                                                             WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_4(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_6(WHAT, x, ...)                                                             WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_5(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_7(WHAT, x, ...)                                                             WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_6(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_8(WHAT, x, ...)                                                             WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_7(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_9(WHAT, x, ...)                                                             WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_8(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_10(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_9(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_11(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_10(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_12(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_11(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_13(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_12(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_14(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_13(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_15(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_14(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_16(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_15(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_17(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_16(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_18(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_17(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_19(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_18(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_20(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_19(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_21(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_20(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_22(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_21(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_23(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_22(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_24(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_23(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_25(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_24(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_26(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_25(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_27(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_26(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_28(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_27(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_29(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_28(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_30(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_29(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_31(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_30(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_32(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_31(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_33(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_32(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_34(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_33(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_35(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_34(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_36(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_35(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_37(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_36(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_38(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_37(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_39(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_38(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_40(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_39(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_41(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_40(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_42(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_41(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_43(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_42(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_44(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_43(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_45(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_44(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_46(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_45(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_47(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_46(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_48(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_47(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_49(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_48(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_50(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_49(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_51(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_50(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_52(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_51(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_53(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_52(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_54(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_53(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_55(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_54(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_56(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_55(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_57(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_56(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_58(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_57(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_59(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_58(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_60(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_59(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_61(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_60(WHAT, __VA_ARGS__))
#define MO_FOR_EACH_P0_62(WHAT, x, ...)                                                            WHAT(x) MO_EXPAND(MO_FOR_EACH_P0_61(WHAT, __VA_ARGS__))

#define MO_FOR_EACH_P0_(IT, WHAT, ...)                                                             MO_EXPAND(IT(WHAT, __VA_ARGS__))



#define MO_FOR_EACH_P1_0(WHAT, p0)
#define MO_FOR_EACH_P1_1(WHAT, p0, x)                                                              WHAT(p0, x)
#define MO_FOR_EACH_P1_2(WHAT, p0, x, ...)                                                         WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_1(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_3(WHAT, p0, x, ...)                                                         WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_2(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_4(WHAT, p0, x, ...)                                                         WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_3(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_5(WHAT, p0, x, ...)                                                         WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_4(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_6(WHAT, p0, x, ...)                                                         WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_5(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_7(WHAT, p0, x, ...)                                                         WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_6(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_8(WHAT, p0, x, ...)                                                         WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_7(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_9(WHAT, p0, x, ...)                                                         WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_8(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_10(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_9(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_11(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_10(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_12(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_11(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_13(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_12(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_14(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_13(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_15(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_14(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_16(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_15(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_17(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_16(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_18(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_17(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_19(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_18(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_20(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_19(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_21(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_20(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_22(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_21(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_23(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_22(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_24(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_23(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_25(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_24(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_26(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_25(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_27(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_26(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_28(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_27(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_29(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_28(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_30(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_29(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_31(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_30(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_32(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_31(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_33(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_32(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_34(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_33(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_35(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_34(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_36(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_35(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_37(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_36(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_38(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_37(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_39(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_38(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_40(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_39(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_41(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_40(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_42(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_41(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_43(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_42(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_44(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_43(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_45(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_44(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_46(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_45(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_47(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_46(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_48(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_47(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_49(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_48(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_50(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_49(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_51(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_50(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_52(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_51(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_53(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_52(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_54(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_53(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_55(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_54(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_56(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_55(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_57(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_56(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_58(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_57(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_59(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_58(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_60(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_59(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_61(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_60(WHAT, p0, __VA_ARGS__))
#define MO_FOR_EACH_P1_62(WHAT, p0, x, ...)                                                        WHAT(p0, x) MO_EXPAND(MO_FOR_EACH_P1_61(WHAT, p0, __VA_ARGS__))

#define MO_FOR_EACH_P1_(IT, WHAT, p0, ...)                                                         MO_EXPAND(IT(WHAT, p0, __VA_ARGS__))



#define MO_FOR_EACH_P2_0(WHAT, p0, p1)
#define MO_FOR_EACH_P2_1(WHAT, p0, p1, x)                                                          WHAT(p0, p1, x)
#define MO_FOR_EACH_P2_2(WHAT, p0, p1, x, ...)                                                     WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_1(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_3(WHAT, p0, p1, x, ...)                                                     WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_2(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_4(WHAT, p0, p1, x, ...)                                                     WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_3(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_5(WHAT, p0, p1, x, ...)                                                     WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_4(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_6(WHAT, p0, p1, x, ...)                                                     WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_5(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_7(WHAT, p0, p1, x, ...)                                                     WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_6(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_8(WHAT, p0, p1, x, ...)                                                     WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_7(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_9(WHAT, p0, p1, x, ...)                                                     WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_8(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_10(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_9(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_11(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_10(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_12(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_11(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_13(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_12(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_14(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_13(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_15(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_14(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_16(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_15(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_17(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_16(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_18(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_17(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_19(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_18(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_20(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_19(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_21(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_20(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_22(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_21(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_23(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_22(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_24(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_23(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_25(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_24(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_26(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_25(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_27(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_26(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_28(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_27(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_29(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_28(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_30(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_29(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_31(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_30(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_32(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_31(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_33(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_32(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_34(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_33(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_35(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_34(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_36(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_35(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_37(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_36(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_38(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_37(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_39(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_38(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_40(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_39(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_41(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_40(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_42(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_41(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_43(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_42(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_44(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_43(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_45(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_44(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_46(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_45(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_47(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_46(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_48(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_47(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_49(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_48(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_50(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_49(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_51(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_50(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_52(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_51(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_53(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_52(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_54(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_53(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_55(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_54(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_56(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_55(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_57(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_56(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_58(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_57(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_59(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_58(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_60(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_59(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_61(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_60(WHAT, p0, p1, __VA_ARGS__))
#define MO_FOR_EACH_P2_62(WHAT, p0, p1, x, ...)                                                    WHAT(p0, p1, x) MO_EXPAND(MO_FOR_EACH_P2_61(WHAT, p0, p1, __VA_ARGS__))

#define MO_FOR_EACH_P2_(IT, WHAT, p0, p1, ...)                                                     MO_EXPAND(IT(WHAT, p0, p1, __VA_ARGS__))


#define MO_FOR_EACH_P3_0(WHAT, p0, p1, p2)
#define MO_FOR_EACH_P3_1(WHAT, p0, p1, p2, x)                                                      WHAT(p0, p1, p2, x)
#define MO_FOR_EACH_P3_2(WHAT, p0, p1, p2, x, ...)                                                 WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_1(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_3(WHAT, p0, p1, p2, x, ...)                                                 WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_2(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_4(WHAT, p0, p1, p2, x, ...)                                                 WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_3(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_5(WHAT, p0, p1, p2, x, ...)                                                 WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_4(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_6(WHAT, p0, p1, p2, x, ...)                                                 WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_5(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_7(WHAT, p0, p1, p2, x, ...)                                                 WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_6(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_8(WHAT, p0, p1, p2, x, ...)                                                 WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_7(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_9(WHAT, p0, p1, p2, x, ...)                                                 WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_8(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_10(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_9(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_11(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_10(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_12(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_11(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_13(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_12(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_14(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_13(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_15(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_14(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_16(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_15(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_17(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_16(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_18(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_17(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_19(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_18(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_20(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_19(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_21(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_20(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_22(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_21(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_23(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_22(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_24(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_23(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_25(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_24(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_26(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_25(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_27(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_26(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_28(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_27(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_29(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_28(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_30(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_29(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_31(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_30(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_32(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_31(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_33(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_32(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_34(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_33(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_35(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_34(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_36(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_35(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_37(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_36(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_38(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_37(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_39(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_38(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_40(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_39(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_41(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_40(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_42(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_41(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_43(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_42(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_44(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_43(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_45(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_44(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_46(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_45(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_47(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_46(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_48(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_47(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_49(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_48(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_50(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_49(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_51(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_50(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_52(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_51(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_53(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_52(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_54(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_53(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_55(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_54(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_56(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_55(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_57(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_56(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_58(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_57(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_59(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_58(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_60(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_59(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_61(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_60(WHAT, p0, p1, p2, __VA_ARGS__))
#define MO_FOR_EACH_P3_62(WHAT, p0, p1, p2, x, ...)                                                WHAT(p0, p1, p2, x) MO_EXPAND(MO_FOR_EACH_P3_61(WHAT, p0, p1, p2, __VA_ARGS__))

#define MO_FOR_EACH_P3_(IT, WHAT, p0, p1, p2, ...)                                                 MO_EXPAND(IT(WHAT, p0, p1, p2, __VA_ARGS__))



#define MO_FOR_EACH_P4_0(WHAT, p0, p1, p2, p3)
#define MO_FOR_EACH_P4_1(WHAT, p0, p1, p2, p3, x)                                                  WHAT(p0, p1, p2, p3, x)
#define MO_FOR_EACH_P4_2(WHAT, p0, p1, p2, p3, x, ...)                                             WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_1(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_3(WHAT, p0, p1, p2, p3, x, ...)                                             WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_2(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_4(WHAT, p0, p1, p2, p3, x, ...)                                             WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_3(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_5(WHAT, p0, p1, p2, p3, x, ...)                                             WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_4(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_6(WHAT, p0, p1, p2, p3, x, ...)                                             WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_5(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_7(WHAT, p0, p1, p2, p3, x, ...)                                             WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_6(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_8(WHAT, p0, p1, p2, p3, x, ...)                                             WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_7(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_9(WHAT, p0, p1, p2, p3, x, ...)                                             WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_8(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_10(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_9(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_11(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_10(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_12(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_11(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_13(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_12(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_14(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_13(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_15(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_14(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_16(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_15(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_17(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_16(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_18(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_17(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_19(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_18(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_20(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_19(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_21(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_20(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_22(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_21(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_23(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_22(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_24(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_23(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_25(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_24(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_26(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_25(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_27(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_26(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_28(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_27(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_29(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_28(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_30(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_29(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_31(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_30(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_32(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_31(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_33(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_32(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_34(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_33(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_35(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_34(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_36(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_35(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_37(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_36(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_38(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_37(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_39(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_38(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_40(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_39(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_41(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_40(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_42(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_41(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_43(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_42(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_44(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_43(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_45(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_44(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_46(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_45(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_47(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_46(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_48(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_47(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_49(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_48(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_50(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_49(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_51(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_50(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_52(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_51(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_53(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_52(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_54(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_53(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_55(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_54(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_56(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_55(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_57(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_56(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_58(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_57(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_59(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_58(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_60(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_59(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_61(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_60(WHAT, p0, p1, p2, p3, __VA_ARGS__))
#define MO_FOR_EACH_P4_62(WHAT, p0, p1, p2, p3, x, ...)                                            WHAT(p0, p1, p2, p3, x) MO_EXPAND(MO_FOR_EACH_P4_61(WHAT, p0, p1, p2, p3, __VA_ARGS__))

#define MO_FOR_EACH_P4_(IT, WHAT, p0, p1, p2, p3, ...)                                             MO_EXPAND(IT(WHAT, p0, p1, p2, p3, __VA_ARGS__))



#define MO_FOR_EACH_P5_0(WHAT, p0, p1, p2, p3, p4)
#define MO_FOR_EACH_P5_1(WHAT, p0, p1, p2, p3, p4, x)                                              WHAT(p0, p1, p2, p3, p4, x)
#define MO_FOR_EACH_P5_2(WHAT, p0, p1, p2, p3, p4, x, ...)                                         WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_1(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_3(WHAT, p0, p1, p2, p3, p4, x, ...)                                         WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_2(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_4(WHAT, p0, p1, p2, p3, p4, x, ...)                                         WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_3(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_5(WHAT, p0, p1, p2, p3, p4, x, ...)                                         WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_4(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_6(WHAT, p0, p1, p2, p3, p4, x, ...)                                         WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_5(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_7(WHAT, p0, p1, p2, p3, p4, x, ...)                                         WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_6(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_8(WHAT, p0, p1, p2, p3, p4, x, ...)                                         WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_7(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_9(WHAT, p0, p1, p2, p3, p4, x, ...)                                         WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_8(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_10(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_9(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_11(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_10(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_12(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_11(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_13(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_12(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_14(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_13(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_15(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_14(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_16(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_15(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_17(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_16(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_18(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_17(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_19(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_18(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_20(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_19(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_21(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_20(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_22(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_21(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_23(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_22(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_24(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_23(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_25(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_24(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_26(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_25(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_27(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_26(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_28(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_27(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_29(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_28(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_30(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_29(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_31(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_30(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_32(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_31(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_33(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_32(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_34(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_33(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_35(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_34(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_36(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_35(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_37(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_36(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_38(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_37(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_39(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_38(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_40(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_39(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_41(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_40(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_42(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_41(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_43(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_42(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_44(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_43(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_45(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_44(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_46(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_45(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_47(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_46(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_48(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_47(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_49(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_48(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_50(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_49(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_51(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_50(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_52(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_51(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_53(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_52(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_54(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_53(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_55(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_54(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_56(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_55(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_57(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_56(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_58(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_57(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_59(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_58(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_60(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_59(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_61(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_60(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))
#define MO_FOR_EACH_P5_62(WHAT, p0, p1, p2, p3, p4, x, ...)                                        WHAT(p0, p1, p2, p3, p4, x) MO_EXPAND(MO_FOR_EACH_P5_61(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))

#define MO_FOR_EACH_P5_(IT, WHAT, p0, p1, p2, p3, p4, ...)                                         MO_EXPAND(IT(WHAT, p0, p1, p2, p3, p4, __VA_ARGS__))



#define MO_FOR_EACH_P6_0(WHAT, p0, p1, p2, p3, p4, p5)
#define MO_FOR_EACH_P6_1(WHAT, p0, p1, p2, p3, p4, p5, x)                                          WHAT(p0, p1, p2, p3, p4, p5, x)
#define MO_FOR_EACH_P6_2(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                     WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_1(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_3(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                     WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_2(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_4(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                     WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_3(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_5(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                     WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_4(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_6(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                     WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_5(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_7(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                     WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_6(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_8(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                     WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_7(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_9(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                     WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_8(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_10(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_9(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_11(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_10(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_12(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_11(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_13(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_12(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_14(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_13(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_15(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_14(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_16(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_15(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_17(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_16(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_18(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_17(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_19(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_18(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_20(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_19(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_21(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_20(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_22(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_21(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_23(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_22(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_24(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_23(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_25(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_24(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_26(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_25(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_27(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_26(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_28(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_27(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_29(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_28(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_30(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_29(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_31(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_30(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_32(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_31(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_33(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_32(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_34(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_33(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_35(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_34(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_36(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_35(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_37(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_36(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_38(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_37(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_39(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_38(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_40(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_39(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_41(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_40(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_42(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_41(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_43(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_42(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_44(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_43(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_45(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_44(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_46(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_45(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_47(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_46(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_48(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_47(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_49(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_48(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_50(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_49(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_51(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_50(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_52(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_51(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_53(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_52(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_54(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_53(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_55(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_54(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_56(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_55(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_57(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_56(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_58(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_57(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_59(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_58(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_60(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_59(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_61(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_60(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))
#define MO_FOR_EACH_P6_62(WHAT, p0, p1, p2, p3, p4, p5, x, ...)                                    WHAT(p0, p1, p2, p3, p4, p5, x) MO_EXPAND(MO_FOR_EACH_P6_61(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))

#define MO_FOR_EACH_P6_(IT, WHAT, p0, p1, p2, p3, p4, p5, ...)                                     MO_EXPAND(IT(WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__))



#define MO_FOR_EACH_P7_0(WHAT, p0, p1, p2, p3, p4, p5, p6)
#define MO_FOR_EACH_P7_1(WHAT, p0, p1, p2, p3, p4, p5, p6, x)                                      WHAT(p0, p1, p2, p3, p4, p5, p6, x)
#define MO_FOR_EACH_P7_2(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                 WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_1(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_3(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                 WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_2(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_4(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                 WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_3(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_5(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                 WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_4(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_6(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                 WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_5(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_7(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                 WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_6(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_8(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                 WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_7(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_9(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                 WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_8(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_10(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_9(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_11(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_10(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_12(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_11(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_13(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_12(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_14(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_13(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_15(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_14(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_16(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_15(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_17(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_16(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_18(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_17(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_19(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_18(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_20(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_19(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_21(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_20(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_22(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_21(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_23(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_22(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_24(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_23(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_25(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_24(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_26(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_25(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_27(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_26(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_28(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_27(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_29(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_28(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_30(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_29(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_31(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_30(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_32(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_31(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_33(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_32(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_34(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_33(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_35(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_34(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_36(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_35(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_37(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_36(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_38(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_37(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_39(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_38(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_40(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_39(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_41(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_40(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_42(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_41(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_43(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_42(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_44(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_43(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_45(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_44(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_46(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_45(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_47(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_46(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_48(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_47(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_49(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_48(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_50(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_49(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_51(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_50(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_52(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_51(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_53(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_52(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_54(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_53(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_55(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_54(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_56(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_55(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_57(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_56(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_58(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_57(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_59(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_58(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_60(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_59(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_61(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_60(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#define MO_FOR_EACH_P7_62(WHAT, p0, p1, p2, p3, p4, p5, p6, x, ...)                                WHAT(p0, p1, p2, p3, p4, p5, p6, x) MO_EXPAND(MO_FOR_EACH_P7_61(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))

#define MO_FOR_EACH_P7_(IT, WHAT, p0, p1, p2, p3, p4, p5, p6, ...)                                 MO_EXPAND(IT(WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__))
#pragma endregion
/*! \endcond */

/**
 * @brief macro that implement a crude macro-looping utility. It enable the user to call a macro for each of the variadic parameters
 * 
 * To use this macro you have to create a helper macro first that take only one argument x (we iterate over x)
 * @code {.cpp}
 * #define __HELPER_DO_STUFF(x)                                      doStuff(x, sizeof(x))
 * #define DO_STUFF_FOR_EACH(...)                                    MO_FOR_EACH_P0(__HELPER_DO_STUFF, __VA_ARGS__)
 * @endcode
 *  
 */
#define MO_FOR_EACH_P0(WHAT, ...)                                                                  MO_FOR_EACH_P0_(MO_CONCATENATE(MO_FOR_EACH_P0_, MO_PP_NARGS(__VA_ARGS__)), WHAT, __VA_ARGS__)

/**
 * @brief macro that implement a crude macro-looping utility. It enable the user to call a macro for each of the variadic parameters using one additional parameters
 * 
 * To use this macro you have to create a helper macro first that take one argument x (we iterate over x) and the p0 parameters passed to the MO_FOR_EACH_P1 macro
 * @code {.cpp}
 * #define __HELPER_DO_STUFF(p0, x)                                 doStuff(p0, x, sizeof(x))
 * #define DO_STUFF_FOR_EACH(p0, ...)                               MO_FOR_EACH_P1(__HELPER_DO_STUFF, p0, __VA_ARGS__)
 * @endcode
 * 
 */
#define MO_FOR_EACH_P1(WHAT, p0, ...)                                                              MO_FOR_EACH_P1_(MO_CONCATENATE(MO_FOR_EACH_P1_, MO_PP_NARGS(__VA_ARGS__)), WHAT, p0, __VA_ARGS__)

/**
 * @brief macro that implement a crude macro-looping utility. It enable the user to call a macro for each of the variadic parameters using one additional parameters
 * 
 * To use this macro you have to create a helper macro first that take one argument x (we iterate over x) and p0,p1 parameters passed to the MO_FOR_EACH_P2 macro
 * @code {.cpp}
 * #define __HELPER_DO_STUFF(p0, p1, x)                             doStuff(p0, p1, x, sizeof(x))
 * #define DO_STUFF_FOR_EACH(p0, p1, ...)                           MO_FOR_EACH_P2(__HELPER_DO_STUFF, p0, p1, __VA_ARGS__)
 * @endcode
 * 
 */
#define MO_FOR_EACH_P2(WHAT, p0, p1, ...)                                                          MO_FOR_EACH_P2_(MO_CONCATENATE(MO_FOR_EACH_P2_, MO_PP_NARGS(__VA_ARGS__)), WHAT, p0, p1, __VA_ARGS__)

/**
 * @brief macro that implement a crude macro-looping utility. It enable the user to call a macro for each of the variadic parameters using one additional parameters
 * 
 * To use this macro you have to create a helper macro first that take one argument x (we iterate over x) and the p0,p1,p2 parameters passed to the MO_FOR_EACH_P3 macro
 * @code {.cpp}
 * #define __HELPER_DO_STUFF(p0, p1, p2, x)                         doStuff(p0, p1, p2, x, sizeof(x))
 * #define DO_STUFF_FOR_EACH(p0, p1, p2, ...)                       MO_FOR_EACH_P3(__HELPER_DO_STUFF, p0, p1, p2, __VA_ARGS__)
 * @endcode
 * 
 */
#define MO_FOR_EACH_P3(WHAT, p0, p1, p2, ...)                                                      MO_FOR_EACH_P3_(MO_CONCATENATE(MO_FOR_EACH_P3_, MO_PP_NARGS(__VA_ARGS__)), WHAT, p0, p1, p2, __VA_ARGS__)

/**
 * @brief macro that implement a crude macro-looping utility. It enable the user to call a macro for each of the variadic parameters using one additional parameters
 * 
 * To use this macro you have to create a helper macro first that take one argument x (we iterate over x) and the p0,p1,p2 parameters passed to the MO_FOR_EACH_P4 macro
 * @code {.cpp}
 * #define __HELPER_DO_STUFF(p0, p1, p2, p3, x)                     doStuff(p0, p1, p2, p3, x, sizeof(x))
 * #define DO_STUFF_FOR_EACH(p0, p1, p2, p3, ...)                   MO_FOR_EACH_P3(__HELPER_DO_STUFF, p0, p1, p2, p3, __VA_ARGS__)
 * @endcode
 * 
 */
#define MO_FOR_EACH_P4(WHAT, p0, p1, p2, p3, ...)                                                  MO_FOR_EACH_P4_(MO_CONCATENATE(MO_FOR_EACH_P4_, MO_PP_NARGS(__VA_ARGS__)), WHAT, p0, p1, p2, p3, __VA_ARGS__)

/**
 * @brief macro that implement a crude macro-looping utility. It enable the user to call a macro for each of the variadic parameters using one additional parameters
 * 
 * To use this macro you have to create a helper macro first that take one argument x (we iterate over x) and the p0,p1,p2,p3,p4 parameters passed to the MO_FOR_EACH_P5 macro
 * @code {.cpp}
 * #define __HELPER_DO_STUFF(p0, p1, p2, p3, p4, x)                 doStuff(p0, p1, p2, p3, p4, x, sizeof(x))
 * #define DO_STUFF_FOR_EACH(p0, p1, p2, p3, p4, ...)               MO_FOR_EACH_P3(__HELPER_DO_STUFF, p0, p1, p2, p3, p4, __VA_ARGS__)
 * @endcode
 * 
 */
#define MO_FOR_EACH_P5(WHAT, p0, p1, p2, p3, p4, ...)                                              MO_FOR_EACH_P5_(MO_CONCATENATE(MO_FOR_EACH_P5_, MO_PP_NARGS(__VA_ARGS__)), WHAT, p0, p1, p2, p3, p4, __VA_ARGS__)

/**
 * @brief macro that implement a crude macro-looping utility. It enable the user to call a macro for each of the variadic parameters using one additional parameters
 * 
 * To use this macro you have to create a helper macro first that take one argument x (we iterate over x) and the p0,p1,p2,p3,p4,p5 parameters passed to the MO_FOR_EACH_P6 macro
 * @code {.cpp}
 * #define __HELPER_DO_STUFF(p0, p1, p2, p3, p4, p5, x)              doStuff(p0, p1, p2, p3, p4, p5, x, sizeof(x))
 * #define DO_STUFF_FOR_EACH(p0, p1, p2, p3, p4, p5, ...)            MO_FOR_EACH_P3(__HELPER_DO_STUFF, p0, p1, p2, p3, p4, p5, __VA_ARGS__)
 * @endcode
 * 
 */
#define MO_FOR_EACH_P6(WHAT, p0, p1, p2, p3, p4, p5, ...)                                          MO_FOR_EACH_P6_(MO_CONCATENATE(MO_FOR_EACH_P6_, MO_PP_NARGS(__VA_ARGS__)), WHAT, p0, p1, p2, p3, p4, p5, __VA_ARGS__)

/**
 * @brief macro that implement a crude macro-looping utility. It enable the user to call a macro for each of the variadic parameters using one additional parameters
 * 
 * To use this macro you have to create a helper macro first that take one argument x (we iterate over x) and the p0,p1,p2,p3,p4,p5,p6 parameters passed to the MO_FOR_EACH_P7 macro
 * @code {.cpp}
 * #define __HELPER_DO_STUFF(p0, p1, p2, p3, p4, p5, p6, x)          doStuff(p0, p1, p2, p3, p4, p5, p6, x, sizeof(x))
 * #define DO_STUFF_FOR_EACH(p0, p1, p2, p3, p4, p5, p6, ...)        MO_FOR_EACH_P3(__HELPER_DO_STUFF, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__)
 * @endcode
 * 
 */
#define MO_FOR_EACH_P7(WHAT, p0, p1, p2, p3, p4, p5, p6, ...)                                      MO_FOR_EACH_P7_(MO_CONCATENATE(MO_FOR_EACH_P7_, MO_PP_NARGS(__VA_ARGS__)), WHAT, p0, p1, p2, p3, p4, p5, p6, __VA_ARGS__)
