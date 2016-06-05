#include <type_traits>
#include <cstdint>
#include <cstdio>

#include <qflags.h>

#include "flags.h"

//------------------------------

DECLARE_BW_ENUM_CLASS(My1bitEnum,e1)
DECLARE_BW_ENUM_CLASS(My2bitEnum,e1,e2)


DECLARE_BITWISE_ENUM_FLAGS(My7bitEnum, My7bitFlags,
              e1, e2, e3, e4, e5, e6, e7)

DECLARE_BITWISE_ENUM_FLAGS(My8bitEnum, My8bitFlags,
              e1, e2, e3, e4, e5, e6, e7, e8)

DECLARE_BITWISE_ENUM_FLAGS(My32bitEnum, My32bitFlags,
              e1, e2, e3, e4, e5, e6, e7, e8, e9,e10,
              e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,
              e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,
              e31,e32)

DECLARE_BITWISE_ENUM_FLAGS(My64bitEnum, My64bitFlags,
              e1, e2, e3, e4, e5, e6, e7, e8, e9,e10,
              e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,
              e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,
              e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,
              e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,
              e51,e52,e53,e54,e55,e56,e57,e58,e59,e60,
              e61,e62,e63,e64)

//------------------------------

My64bitFlags set_64b_flags(My64bitEnum _flag);
My64bitFlags set_64b_flags(My64bitFlags _flags);

//------------------------------

int main(int , char **)
{
    printf("\n");

    printf("0x%02x\n",My1bitEnum::e1);

    printf("0x%02x\n",My2bitEnum::e1);
    printf("0x%02x\n",My2bitEnum::e2);

    printf("0x%02x\n",My7bitEnum::e1);
    printf("0x%02x\n",My7bitEnum::e2);
    printf("0x%02x\n",My7bitEnum::e3);
    printf("0x%02x\n",My7bitEnum::e4);
    printf("0x%02x\n",My7bitEnum::e5);
    printf("0x%02x\n",My7bitEnum::e6);
    printf("0x%02x\n",My7bitEnum::e7);

    printf("My7bitFlags : Size of UnderlyingType = %d\n",sizeof(My7bitFlags::UnderlyingType));
    printf("My7bitFlags : Size of ValueType = %d\n",sizeof(My7bitFlags::ValueType));

    printf("0x%02x\n",My8bitEnum::e1);
    printf("0x%02x\n",My8bitEnum::e2);
    printf("0x%02x\n",My8bitEnum::e3);
    printf("0x%02x\n",My8bitEnum::e4);
    printf("0x%02x\n",My8bitEnum::e5);
    printf("0x%02x\n",My8bitEnum::e6);
    printf("0x%02x\n",My8bitEnum::e7);
    printf("0x%02x\n",My8bitEnum::e8);

    printf("My8bitFlags : Size of UnderlyingType = %d\n",sizeof(My8bitFlags::UnderlyingType));
    printf("My8bitFlags : Size of ValueType = %d\n",sizeof(My8bitFlags::ValueType));

    printf("0x%08x\n",My32bitEnum::e1);
    printf("0x%08x\n",My32bitEnum::e2);
    printf("0x%08x\n",My32bitEnum::e3);
    printf("0x%08x\n",My32bitEnum::e4);
    printf("0x%08x\n",My32bitEnum::e5);
    printf("0x%08x\n",My32bitEnum::e6);
    printf("0x%08x\n",My32bitEnum::e7);
    printf("0x%08x\n",My32bitEnum::e8);
    printf("0x%08x\n",My32bitEnum::e9);
    printf("0x%08x\n",My32bitEnum::e10);
    printf("0x%08x\n",My32bitEnum::e11);
    printf("0x%08x\n",My32bitEnum::e12);
    printf("0x%08x\n",My32bitEnum::e13);
    printf("0x%08x\n",My32bitEnum::e14);
    printf("0x%08x\n",My32bitEnum::e15);
    printf("0x%08x\n",My32bitEnum::e16);
    printf("0x%08x\n",My32bitEnum::e17);
    printf("0x%08x\n",My32bitEnum::e18);
    printf("0x%08x\n",My32bitEnum::e19);
    printf("0x%08x\n",My32bitEnum::e20);
    printf("0x%08x\n",My32bitEnum::e21);
    printf("0x%08x\n",My32bitEnum::e22);
    printf("0x%08x\n",My32bitEnum::e23);
    printf("0x%08x\n",My32bitEnum::e24);
    printf("0x%08x\n",My32bitEnum::e25);
    printf("0x%08x\n",My32bitEnum::e26);
    printf("0x%08x\n",My32bitEnum::e27);
    printf("0x%08x\n",My32bitEnum::e28);
    printf("0x%08x\n",My32bitEnum::e29);
    printf("0x%08x\n",My32bitEnum::e30);
    printf("0x%08x\n",My32bitEnum::e31);
    printf("0x%08x\n",My32bitEnum::e32);

    printf("My32bitFlags : Size of UnderlyingType = %d\n",sizeof(My32bitFlags::UnderlyingType));
    printf("My32bitFlags : Size of ValueType = %d\n",sizeof(My32bitFlags::ValueType));

    printf("0x%016llx\n",My64bitEnum::e1);
    printf("0x%016llx\n",My64bitEnum::e2);
    printf("0x%016llx\n",My64bitEnum::e3);
    printf("0x%016llx\n",My64bitEnum::e4);
    printf("0x%016llx\n",My64bitEnum::e5);
    printf("0x%016llx\n",My64bitEnum::e6);
    printf("0x%016llx\n",My64bitEnum::e7);
    printf("0x%016llx\n",My64bitEnum::e8);
    printf("0x%016llx\n",My64bitEnum::e9);
    printf("0x%016llx\n",My64bitEnum::e10);
    printf("0x%016llx\n",My64bitEnum::e11);
    printf("0x%016llx\n",My64bitEnum::e12);
    printf("0x%016llx\n",My64bitEnum::e13);
    printf("0x%016llx\n",My64bitEnum::e14);
    printf("0x%016llx\n",My64bitEnum::e15);
    printf("0x%016llx\n",My64bitEnum::e16);
    printf("0x%016llx\n",My64bitEnum::e17);
    printf("0x%016llx\n",My64bitEnum::e18);
    printf("0x%016llx\n",My64bitEnum::e19);
    printf("0x%016llx\n",My64bitEnum::e20);
    printf("0x%016llx\n",My64bitEnum::e21);
    printf("0x%016llx\n",My64bitEnum::e22);
    printf("0x%016llx\n",My64bitEnum::e23);
    printf("0x%016llx\n",My64bitEnum::e24);
    printf("0x%016llx\n",My64bitEnum::e25);
    printf("0x%016llx\n",My64bitEnum::e26);
    printf("0x%016llx\n",My64bitEnum::e27);
    printf("0x%016llx\n",My64bitEnum::e28);
    printf("0x%016llx\n",My64bitEnum::e29);
    printf("0x%016llx\n",My64bitEnum::e30);
    printf("0x%016llx\n",My64bitEnum::e31);
    printf("0x%016llx\n",My64bitEnum::e32);
    printf("0x%016llx\n",My64bitEnum::e33);
    printf("0x%016llx\n",My64bitEnum::e34);
    printf("0x%016llx\n",My64bitEnum::e35);
    printf("0x%016llx\n",My64bitEnum::e36);
    printf("0x%016llx\n",My64bitEnum::e37);
    printf("0x%016llx\n",My64bitEnum::e38);
    printf("0x%016llx\n",My64bitEnum::e39);
    printf("0x%016llx\n",My64bitEnum::e40);
    printf("0x%016llx\n",My64bitEnum::e41);
    printf("0x%016llx\n",My64bitEnum::e42);
    printf("0x%016llx\n",My64bitEnum::e43);
    printf("0x%016llx\n",My64bitEnum::e44);
    printf("0x%016llx\n",My64bitEnum::e45);
    printf("0x%016llx\n",My64bitEnum::e46);
    printf("0x%016llx\n",My64bitEnum::e47);
    printf("0x%016llx\n",My64bitEnum::e48);
    printf("0x%016llx\n",My64bitEnum::e49);
    printf("0x%016llx\n",My64bitEnum::e50);
    printf("0x%016llx\n",My64bitEnum::e51);
    printf("0x%016llx\n",My64bitEnum::e52);
    printf("0x%016llx\n",My64bitEnum::e53);
    printf("0x%016llx\n",My64bitEnum::e54);
    printf("0x%016llx\n",My64bitEnum::e55);
    printf("0x%016llx\n",My64bitEnum::e56);
    printf("0x%016llx\n",My64bitEnum::e57);
    printf("0x%016llx\n",My64bitEnum::e58);
    printf("0x%016llx\n",My64bitEnum::e59);
    printf("0x%016llx\n",My64bitEnum::e60);
    printf("0x%016llx\n",My64bitEnum::e61);
    printf("0x%016llx\n",My64bitEnum::e62);
    printf("0x%016llx\n",My64bitEnum::e63);
    printf("0x%016llx\n",My64bitEnum::e64);

    printf("My64bitFlags : Size of UnderlyingType = %d\n",sizeof(My64bitFlags::UnderlyingType));
    printf("My64bitFlags : Size of ValueType = %d\n",sizeof(My64bitFlags::ValueType));

    My64bitFlags testFlags64b;

    testFlags64b = set_64b_flags(My64bitEnum::e58 | My64bitEnum::e32);

    My64bitFlags testFlags64b2 = My64bitEnum::e25 | testFlags64b;
    testFlags64b |= My64bitEnum::e25;

    if (testFlags64b2 == testFlags64b) printf("OK\n");

    return 0;
}//main

//------------------------------

My64bitFlags set_64b_flags(My64bitEnum _flag)
{
    return My64bitFlags(_flag);
}//set_64b_flags My64bitEnum

//------------------------------

My64bitFlags set_64b_flags(My64bitFlags _flags)
{
    return _flags;
}//set_64b_flags My64bitFlags

//------------------------------
