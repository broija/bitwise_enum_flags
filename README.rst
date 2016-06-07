Enum bit flags
==============

Contains:
 - enum bit flags and enum class bit flags declaration macros.
 - **Flags** template class, which stores enum bit as flags.
 
See main.cpp for some examples.

Enum bit flags declaration:

.. code:: cpp

  DECLARE_BIT_FLAG_ENUM_CLASS(My7bitEnum, e1, e2, e3, e4, e5, e6, e7)
  
is equivalent to:

.. code:: cpp

  enum class My7bitEnum : BestIntegerBitSizeSelector<7,false>::Type {
    e1 = 0x01,
    e2 = 0x02,
    e3 = 0x04,
    e4 = 0x08,
    e5 = 0x10,
    e6 = 0x20,
    e7 = 0x40
  };
  
which is equivalent to:

.. code:: cpp

  enum class My7bitEnum : uint8 {
    e1 = 0x01,
    e2 = 0x02,
    e3 = 0x04,
    e4 = 0x08,
    e5 = 0x10,
    e6 = 0x20,
    e7 = 0x40
  };
  
Flags declaration:
  
.. code:: cpp

  typedef Flags<My7bitEnum> My7bitFlags;

Then you can use **My7bitFlags** class this way:

.. code:: cpp

    My7bitFlags flags7b = My7bitEnum::e3 | My7bitEnum::e5;

    flags7b |= My7bitEnum::e1;

    if (flags7b & My7bitEnum::e5) printf("My7bitEnum::e5 is set!\n");//Writes My7bitEnum::e5 is set!
    if (!(flags7b & My7bitEnum::e2)) printf("My7bitEnum::e2 is not set!\n");//Writes My7bitEnum::e2 is not set!
      
.. contents::

Fundamental types
.................

File : **fundamental_types.h**/

C fixed-size types redeclared.

 - int8 : int8_t
 - int16 : int16_t
 - int32 : int32_t
 - int64 : int64_t

 - uint8 : uint8_t
 - uint16 : uint16_t
 - uint32 : uint32_t
 - uint64 : uint64_t

Templates
.........

BestIntegerSizeSelector
-----------------------

File : **compile_time_tools.h**.

Type : template class.

Chooses the best type, represented by its **Type** member, according to a given size (**size_**).

Parameters:
 - size_t, **size_**.
 - bool, **signed_**. Indicates whether **Type** must be signed or not.

Result:
 - **Type** member.

Uses:
 - `HasLessOrEqualSize`_

BestIntegerBitSizeSelector
--------------------------

File : **compile_time_tools.h**.

Type : template class.

Chooses the best type, represented by its **Type** member, according to a given number of bits.

Parameters:
 - uint8, number of bits.
 - bool, **signed_**. Indicates whether **Type** must signed or not.

Result:
 - **Type** member.

Uses:

 - `IntegerBitSizeToByteSize`_
 - `BestIntegerSizeSelector`_
 
Flags
-----

File : **flags.h**.

Type : template class.
 
HasLessOrEqualSize
------------------
 
File : **compile_time_tools.h**.

Type : template class.

Its **value** members indicates whether **size_** is less or equal to **T_** size.

Parameters:
 - size_t, **size_**.
 - typename, **T_**. 

Result:
 - **value** member.
 
IntegerBitSizeToByteSize
------------------------

File : **compile_time_tools.h**.

Type : template class.

Its **value** member is equal to the minimum integer size that can contain the given number of bits.

Parameters:
 - uint8, number of bits.

Result:
 - **value** member.
 
TypeSelector
------------

File : **compile_time_tools.h**.

Type : variadic template class.

Selects the first type, among types parameters (**T_** and **Args_**), that fits **SizeCondition_**.

Parameters:
 - size_t, **size_**.
 - 2 parameter (size_t, typename) template class, **SizeCondition_**. Must have a value parameter which tells whether given parameters respect its condition.
 - typename, **T_**.
 - typename... (variadic), **Args_***.

Result:
 - **Type** member.

Macros
......

BASIC_CONCAT
------------

File : **basics.h**.

Simple concatenation for 2 arguments.

CONCAT
------

File : **basics.h**.

Allows concatenation for up to 7 arguments.

Uses `BASIC_CONCAT`_ and `VA_ARG_NUMBER`_.

DECLARE_BIT_FLAG_ENUM
---------------------

File : **bit_flag_enum.h**.

Declares enum bit flags. First parameter is enum type name. Others are enum members.

 - Supports up to 64 enum members.
 - Each member value equals (1 << (member_index -1)). 

Usage:

.. code:: cpp

  DECLARE_BIT_FLAG_ENUM(MyEnum, e1, e2, e3)

expands to:
  
.. code:: cpp

  enum MyEnum : uint8 {
    e1 = 0x01,
    e2 = 0x02,
    e3 = 0x04
  };

Uses:
 - `BASIC_CONCAT`_
 - `VA_ARG_NUMBER`_
 - `PRV_LEFT_SHIFT_1`_
 - `PRV_SUBTRACT`_
 - `BestIntegerBitSizeSelector`_

DECLARE_BIT_FLAG_ENUM_CLASS
---------------------------

File : **bit_flag_enum.h**.

Same as `DECLARE_BIT_FLAG_ENUM`_ but declares an enum class.

Usage:

.. code:: cpp

  DECLARE_BIT_FLAG_ENUM_CLASS(MyEnum, e1, e2, e3)

expands to:
  
.. code:: cpp

  enum class MyEnum : uint8 {
    e1 = 0x01,
    e2 = 0x02,
    e3 = 0x04
  };

Uses:
 - `BASIC_CONCAT`_
 - `VA_ARG_NUMBER`_
 - `PRV_LEFT_SHIFT_1`_
 - `PRV_SUBTRACT`_
 - `BestIntegerBitSizeSelector`_

DECLARE_BIT_FLAG_ENUM_1ST_IS_MSB
--------------------------------

File : **bit_flag_enum.h**.

Declares enum bit flags. First parameter is enum type name. Others are enum members.

 - Supports up to 64 enum members.
 - Each member value equals 2^(member_count - member_index -1). 

Usage:

.. code:: cpp

  DECLARE_BIT_FLAG_ENUM_1ST_IS_MSB(MyEnum, e1, e2, e3)

expands to:
  
.. code:: cpp

  enum MyEnum : uint8 {
    e1 = 0x04,
    e2 = 0x02,
    e3 = 0x01
  };

Uses:
 - `BASIC_CONCAT`_
 - `VA_ARG_NUMBER`_
 - `BestIntegerBitSizeSelector`_

DECLARE_BIT_FLAG_ENUM_CLASS_1ST_IS_MSB
--------------------------------------

File : **bit_flag_enum.h**.

Same as `DECLARE_BIT_FLAG_ENUM`_ but declares an enum class.

Usage:

.. code:: cpp

  DECLARE_BIT_FLAG_ENUM_CLASS_1ST_IS_MSB(MyEnum, e1, e2, e3)

expands to:
  
.. code:: cpp

  enum class MyEnum : uint8 {
    e1 = 0x04,
    e2 = 0x02,
    e3 = 0x01
  };

Uses:
 - `BASIC_CONCAT`_
 - `VA_ARG_NUMBER`_
 - `BestIntegerBitSizeSelector`_

PRV_LEFT_SHIFT_1
----------------

File : **prv_bitwise_op.h**.

**Warning** : not intended to be used!

Left shifts '1' N times.

Uses `BASIC_CONCAT`_.

PRV_SUBTRACT
------------

File : **prv_subtract.h**.

**Warning** : not intended to be used!

Subtracts 2 arguments.

Uses `CONCAT`_.

VA_ARG_NUMBER
-------------

File : **va_arg_number.h**.

Allows to count arguments in variadic macros. Many thanks to **Laurent Deniau**. See his post_.
 
.. _post: https://groups.google.com/forum/#!topic/comp.std.c/d-6Mj5Lko_s