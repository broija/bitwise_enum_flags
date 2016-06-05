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

#ifndef SUBDETECTION_MACROS_BASICS_H
#define SUBDETECTION_MACROS_BASICS_H

#include "macros/va_arg_number.h"
#include "compile_time_tools.h"

/* ++++++++++++++++++++++++++++++++++++
 *        BASIC MACROS
 * ++++++++++++++++++++++++++++++++++++*/

/// Concatenation for 2 arguments.
#define BASIC_CONCAT(_A, _B) _A ## _B

/// Concatenation for n arguments.
#define CONCAT(...) CONCAT_(VA_ARG_NUMBER(__VA_ARGS__),__VA_ARGS__)

//-------------------------------------------------------------------------------------------------
//---------------------------------CONCAT helpers--------------------------------------------------
//-------------------------------------------------------------------------------------------------

#define CONCAT_2(_A, _B) BASIC_CONCAT(_A,_B)
#define CONCAT_3(_A, _B, _C) CONCAT_2(_A ## _B, _C)
#define CONCAT_4(_A, _B, _C, _D) CONCAT_3(_A ## _B, _C, _D)
#define CONCAT_5(_A, _B, _C, _D, _E) CONCAT_4(_A ## _B, _C, _D, _E)
#define CONCAT_6(_A, _B, _C, _D, _E, _F) CONCAT_5(_A ## _B, _C, _D, _E, _F)
#define CONCAT_7(_A, _B, _C, _D, _E, _F, _G) CONCAT_6(_A ## _B, _C, _D, _E, _F, _G)

#define CONCAT_(_NB,...) BASIC_CONCAT(CONCAT_,_NB)(__VA_ARGS__)

#endif//SUBDETECTION_MACROS_BASICS_H
