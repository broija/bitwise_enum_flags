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

#ifndef SUBDETECTION_FLAGS_H
#define SUBDETECTION_FLAGS_H

#include <type_traits>
#include <limits>

#include "macros/bit_flag_enum.h"
#include "fundamental_types.h"

template <typename Enum_>
class Flags
{
public:
    typedef Flags<Enum_> Type;
    typedef Enum_ EnumType;
    typedef typename std::underlying_type<Enum_>::type UnderlyingType;
    typedef UnderlyingType ValueType;
//    typedef typename std::make_unsigned<UnderlyingType>::type ValueType;

    constexpr Flags(): m_value(0) {}
    constexpr Flags(Enum_ _flag): m_value(static_cast<ValueType>(_flag)) {}

    constexpr inline bool operator !() const {return !m_value;}
    constexpr inline operator bool() const {return m_value;}

    /// Tests if _flag is set. \warning Only works if Enum_ is a bit flag enum type.
//    constexpr inline bool isSet(Enum_ _flag) const {return (m_value & static_cast<ValueType>(_flag));}

    constexpr inline bool operator ==(Flags & _other) const {return m_value == _other.m_value;}
    constexpr inline bool operator !=(Flags & _other) const {return m_value != _other.m_value;}

    constexpr inline Flags operator ~() const {return Flags(~m_value);}

    constexpr inline Flags operator &(Flags _other) const {return Flags(m_value & _other.m_value);}
    constexpr inline Flags operator &(Enum_ _flag) const {return Flags(m_value & static_cast<ValueType>(_flag));}

    constexpr inline Flags operator |(Flags _other) const {return Flags(m_value | _other.m_value);}
    constexpr inline Flags operator |(Enum_ _flag) const {return Flags(m_value | static_cast<ValueType>(_flag));}

    constexpr inline Flags operator ^(Flags _other) const {return Flags(m_value ^ _other.m_value);}
    constexpr inline Flags operator ^(Enum_ _flag) const {return Flags(m_value ^ static_cast<ValueType>(_flag));}

    inline Flags & operator &=(Flags & _other) {m_value &= _other.m_value; return *this;}
    inline Flags & operator &=(Enum_ _flag) {m_value |= static_cast<ValueType>(_flag); return *this;}

    inline Flags & operator |=(Flags & _other) {m_value |= _other.m_value; return *this;}
    inline Flags & operator |=(Enum_ _flag) {m_value |= static_cast<ValueType>(_flag); return *this;}

    inline Flags & operator ^=(Flags & _other) {m_value &= _other.m_value; return *this;}
    inline Flags & operator ^=(Enum_ _flag) {m_value |= static_cast<ValueType>(_flag); return *this;}

    inline void set() {return std::numeric_limits<ValueType>::max();}///< Sets all bits.
    inline void set(Enum_ _flag) {m_value |= static_cast<ValueType>(_flag);}///< Sets a specific bit.

    inline void clear() {m_value = 0;}///< Clears all bits.
    inline void clear(Enum_ _flag) {m_value &= ~static_cast<ValueType>(_flag);}///< Clears specific bits.

protected:
    ValueType m_value;

private:
    constexpr Flags(ValueType _value): m_value(_value) {}

    static_assert(std::is_enum<Enum_>::value,"Flags<Enum_> : type is not an enum type.");
};//Flags

//---------------------------------

template <typename Enum_>
constexpr inline Flags<Enum_> operator |(Enum_ _flag1, Enum_ _flag2)
{
    static_assert(std::is_enum<Enum_>::value,"Flags<Enum_> operator | Enum_ Enum_ : type is not an enum type.");

    return Flags<Enum_>(_flag1) | _flag2;
}//operator | Enum_ Enum_

//---------------------------------

template <typename Enum_>
constexpr inline Flags<Enum_> operator |(Enum_ _flag, Flags<Enum_> _flags)
{
    static_assert(std::is_enum<Enum_>::value,"Flags<Enum_> operator | Enum_ Flags<Enum_> : type is not an enum type.");

    return _flags | _flag;
}//operator | Enum_ Flags<Enum_>

//---------------------------------

#define FLAGS_TYPEDEF_FOR_ENUM(_ENUM,_FLAGS) \
    typedef Flags<_ENUM> _FLAGS;

/*! Declares a bit flag enum _ENUM and his associated Flags<_ENUM>, named _FLAGS. Follows enum members.
    First declared enum member is associated to the least significant bit.*/
#define DECLARE_BIT_FLAG_ENUM_AND_FLAGS(_ENUM, _FLAGS, _FLAG1, ...) \
    DECLARE_BIT_FLAG_ENUM_CLASS(_ENUM, _FLAG1, __VA_ARGS__) \
    FLAGS_TYPEDEF_FOR_ENUM(_ENUM,_FLAGS)

/*! Declares a bit flag enum _ENUM and his associated Flags<_ENUM>, named _FLAGS. Follows enum members.
    First declared enum member is associated to the most significant bit.*/
#define DECLARE_BIT_FLAG_ENUM_AND_FLAGS_1ST_IS_MSB(_ENUM, _FLAGS, _FLAG1, ...) \
    DECLARE_BIT_FLAG_ENUM_CLASS_1ST_IS_MSB(_ENUM, _FLAG1, __VA_ARGS__) \
    FLAGS_TYPEDEF_FOR_ENUM(_ENUM,_FLAGS)

#endif // SUBDETECTION_FLAGS_H
