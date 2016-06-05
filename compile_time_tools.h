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

#ifndef SUBDETECTION_COMPILE_TIME_TOOLS_H
#define SUBDETECTION_COMPILE_TIME_TOOLS_H

#include <type_traits>

#include "fundamental_types.h"

struct NullType {};

//-- -- -- -- -- -- -- -- -- --

template <size_t size_, typename T_> struct HasSameSize;///< Member value is true if size_ = sizeof(T_)
template <size_t size_, typename T_> struct HasLessOrEqualSize;///< Member value is true if size_ <= sizeof(T_)

//-- -- -- -- -- -- -- -- -- --

/*! Template struct allowing to select a Type given a condition.
    \param size_ size to select.
    \param Condition_ condition template struct. Must hold a value member.
    \param Args_ types to select.*/
template <size_t size_, template <size_t cSize_, typename U_> class Condition_, typename... Args_> struct TypeSelector;

//-- -- -- -- -- -- -- -- -- --

/*! Template struct allowing to select a type among others given a byte size.
    \param size_ size to select.
    \param Condition_ condition template struct. Must hold a value member.
    \param Args_ types to select.*/
template <size_t size_, typename T_, typename... Args_> struct ExactSizeTypeSelector;

//-- -- -- -- -- -- -- -- -- --

/*! Template struct allowing to select the best integer type given a byte size.
    \param size_ size to select.
    \param Condition_ condition template struct. Must hold a value member.
    \param Args_ types to select.*/
template <size_t size_, bool signed_ = true> struct BestIntegerSizeSelector;

//-- -- -- -- -- -- -- -- -- --

/*! Template struct allowing to get an integer byte size (value member) given his bit size.*/
template <uint8 bitsize_> struct IntegerBitSizeToByteSize;

//-- -- -- -- -- -- -- -- -- --

/*! Template struct allowing to get an integer type (Type member) given his bit size.
    \param bitsize_ integer bit size.
    \param signed_ false: Type will be unsigned.*/
template <uint8 bitsize_, bool signed_ = true> struct BestIntegerBitSizeSelector;

//-- -- -- -- -- -- -- -- -- --

//-------------------------------------------------------------------
//-------------------       DEFINITIONS      ------------------------
//-------------------------------------------------------------------

template <size_t size_, typename T_>
struct HasSameSize
{
    enum {value = (size_==sizeof(T_))};
};//HasSameSize

//---------------------------------

template <size_t size_, typename T_>
struct HasLessOrEqualSize
{
    enum {value = (size_<=sizeof(T_))};
};//HasLessOrEqualSize

//---------------------------------

template <size_t size_, template <size_t cSize_, typename U_> class Condition_, typename... Args_>
struct TypeSelector
{
    typedef NullType Type;
};//TypeSelector no type args

//+++++++++++++++++++++++++++++++++

template <size_t size_, template <size_t cSize_, typename U_> class SizeCondition_, typename T_, typename... Args_>
struct TypeSelector<size_,SizeCondition_,T_,Args_...>
{
    typedef typename std::conditional<SizeCondition_<size_,T_>::value,T_,typename TypeSelector<size_,SizeCondition_,Args_...>::Type>::type Type;

    static_assert(!std::is_same<Type,NullType>::value,"TypeSelector : invalid type!");
};//TypeSelector

//---------------------------------

template <size_t size_, typename T_, typename... Args_>
struct ExactSizeTypeSelector
{
    typedef typename TypeSelector<size_,HasSameSize,T_,Args_...>::Type Type;
};//ExactSizeTypeSelector

//---------------------------------

template <size_t size_, bool signed_>
struct BestIntegerSizeSelector
{
    typedef typename TypeSelector<size_,HasLessOrEqualSize,int8,int16,int32,int64>::Type Type;
};//BestIntegerSizeSelector

//+++++++++++++++++++++++++

template <size_t size_>
struct BestIntegerSizeSelector<size_,false>
{
    typedef typename std::make_unsigned<typename BestIntegerSizeSelector<size_,true>::Type>::type Type;
};//BestIntegerSizeSelector

//---------------------------------

template <uint8 bitsize_>
struct IntegerBitSizeToByteSize
{
    enum {value = bitsize_ / 8 +1};

    static_assert(bitsize_ <= 64,"IntegerBitSizeToByteSize : invalid integer bit size!");
};//IntegerBitSizeToByteSize

//+++++++++++++++++++++++++

template <>
struct IntegerBitSizeToByteSize<8>
{
    enum {value = 1};
};//IntegerBitSizeToByteSize 8

//+++++++++++++++++++++++++

template <>
struct IntegerBitSizeToByteSize<16>
{
    enum {value = 2};
};//IntegerBitSizeToByteSize 16

//+++++++++++++++++++++++++

template <>
struct IntegerBitSizeToByteSize<32>
{
    enum {value = 4};
};//IntegerBitSizeToByteSize 32

//+++++++++++++++++++++++++

template <>
struct IntegerBitSizeToByteSize<64>
{
    enum {value = 8};
};//IntegerBitSizeToByteSize 64

//-------------------------

template <uint8 bitsize_, bool signed_>
struct BestIntegerBitSizeSelector
{
    typedef typename BestIntegerSizeSelector<IntegerBitSizeToByteSize<bitsize_>::value,signed_>::Type Type;
};//BestIntegerBitSizeSelector

//-------------------------

#endif // SUBDETECTION_COMPILE_TIME_TOOLS_H
