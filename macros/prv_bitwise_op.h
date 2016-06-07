/*!
    Copyright 2016 Broija

    This file is part of subdetection library.

    subdetection is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    subdetection is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with subdetection library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SUBDETECTION_MACROS_BITWISE_OP_H
#define SUBDETECTION_MACROS_BITWISE_OP_H

#include "macros/basics.h"

/* ++++++++++++++++++++++++++++++++++++
 *        BITWISE OPERATION MACROS
 * ++++++++++++++++++++++++++++++++++++*/

/*! Macro for left shifting '1' _NB times.
    \warning Not intended to be used.*/
#define PRV_LEFT_SHIFT_1(_NB) PRV_LEFT_SHIFT_1_(_NB)

//------------------------------------------------------------------------------
//-------------------------------PRV_LEFT_SHIFT_1 helpers---------------------------
//------------------------------------------------------------------------------

#define PRV_LEFT_SHIFT_1_64 0

#define PRV_LEFT_SHIFT_1_63 0x8000000000000000
#define PRV_LEFT_SHIFT_1_62 0x4000000000000000
#define PRV_LEFT_SHIFT_1_61 0x2000000000000000
#define PRV_LEFT_SHIFT_1_60 0x1000000000000000
#define PRV_LEFT_SHIFT_1_59 0x800000000000000
#define PRV_LEFT_SHIFT_1_58 0x400000000000000
#define PRV_LEFT_SHIFT_1_57 0x200000000000000
#define PRV_LEFT_SHIFT_1_56 0x100000000000000
#define PRV_LEFT_SHIFT_1_55 0x80000000000000
#define PRV_LEFT_SHIFT_1_54 0x40000000000000
#define PRV_LEFT_SHIFT_1_53 0x20000000000000
#define PRV_LEFT_SHIFT_1_52 0x10000000000000
#define PRV_LEFT_SHIFT_1_51 0x8000000000000
#define PRV_LEFT_SHIFT_1_50 0x4000000000000
#define PRV_LEFT_SHIFT_1_49 0x2000000000000
#define PRV_LEFT_SHIFT_1_48 0x1000000000000
#define PRV_LEFT_SHIFT_1_47 0x800000000000
#define PRV_LEFT_SHIFT_1_46 0x400000000000
#define PRV_LEFT_SHIFT_1_45 0x200000000000
#define PRV_LEFT_SHIFT_1_44 0x100000000000
#define PRV_LEFT_SHIFT_1_43 0x80000000000
#define PRV_LEFT_SHIFT_1_42 0x40000000000
#define PRV_LEFT_SHIFT_1_41 0x20000000000
#define PRV_LEFT_SHIFT_1_40 0x10000000000
#define PRV_LEFT_SHIFT_1_39 0x8000000000
#define PRV_LEFT_SHIFT_1_38 0x4000000000
#define PRV_LEFT_SHIFT_1_37 0x2000000000
#define PRV_LEFT_SHIFT_1_36 0x1000000000
#define PRV_LEFT_SHIFT_1_35 0x800000000
#define PRV_LEFT_SHIFT_1_34 0x400000000
#define PRV_LEFT_SHIFT_1_33 0x200000000
#define PRV_LEFT_SHIFT_1_32 0x100000000
#define PRV_LEFT_SHIFT_1_31 0x80000000
#define PRV_LEFT_SHIFT_1_30 0x40000000
#define PRV_LEFT_SHIFT_1_29 0x20000000
#define PRV_LEFT_SHIFT_1_28 0x10000000
#define PRV_LEFT_SHIFT_1_27 0x8000000
#define PRV_LEFT_SHIFT_1_26 0x4000000
#define PRV_LEFT_SHIFT_1_25 0x2000000
#define PRV_LEFT_SHIFT_1_24 0x1000000
#define PRV_LEFT_SHIFT_1_23 0x800000
#define PRV_LEFT_SHIFT_1_22 0x400000
#define PRV_LEFT_SHIFT_1_21 0x200000
#define PRV_LEFT_SHIFT_1_20 0x100000
#define PRV_LEFT_SHIFT_1_19 0x80000
#define PRV_LEFT_SHIFT_1_18 0x40000
#define PRV_LEFT_SHIFT_1_17 0x20000
#define PRV_LEFT_SHIFT_1_16 0x10000
#define PRV_LEFT_SHIFT_1_15 0x8000
#define PRV_LEFT_SHIFT_1_14 0x4000
#define PRV_LEFT_SHIFT_1_13 0x2000
#define PRV_LEFT_SHIFT_1_12 0x1000
#define PRV_LEFT_SHIFT_1_11 0x800
#define PRV_LEFT_SHIFT_1_10 0x400
#define PRV_LEFT_SHIFT_1_9  0x200
#define PRV_LEFT_SHIFT_1_8  0x100
#define PRV_LEFT_SHIFT_1_7  0x80
#define PRV_LEFT_SHIFT_1_6  0x40
#define PRV_LEFT_SHIFT_1_5  0x20
#define PRV_LEFT_SHIFT_1_4  0x10
#define PRV_LEFT_SHIFT_1_3  0x08
#define PRV_LEFT_SHIFT_1_2  0x04
#define PRV_LEFT_SHIFT_1_1  0x02
#define PRV_LEFT_SHIFT_1_0  0x01

#define PRV_LEFT_SHIFT_1_(_NB) BASIC_CONCAT(PRV_LEFT_SHIFT_1_,_NB)

#endif // SUBDETECTION_MACROS_BITWISE_OP_H
