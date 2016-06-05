#ifndef SUBDETECTION_VA_ARG_NUMBER_H
#define SUBDETECTION_VA_ARG_NUMBER_H

/*! Variadic macro argument number, thanks to Laurent Deniau:
 *  https://groups.google.com/forum/#!topic/comp.std.c/d-6Mj5Lko_s */

#define VA_ARG_NUMBER(...) VA_ARG_NUMBER_(__VA_ARGS__,REV_ARG_SEQUENCE())///< Allows to retrieve variadic macro argument number.

//------------------------------------------------------------------------------
//------------------------------VA_ARG_NUMBER helpers---------------------------
//------------------------------------------------------------------------------

#define VA_ARG_NUMBER_(...) VA_ARGS_TO_ARG_NUMBER(__VA_ARGS__)

#define VA_ARGS_TO_ARG_NUMBER( \
     _ARG1, _ARG2, _ARG3, _ARG4, _ARG5, _ARG6, _ARG7, _ARG8, _ARG9,_ARG10, \
    _ARG11,_ARG12,_ARG13,_ARG14,_ARG15,_ARG16,_ARG17,_ARG18,_ARG19,_ARG20, \
    _ARG21,_ARG22,_ARG23,_ARG24,_ARG25,_ARG26,_ARG27,_ARG28,_ARG29,_ARG30, \
    _ARG31,_ARG32,_ARG33,_ARG34,_ARG35,_ARG36,_ARG37,_ARG38,_ARG39,_ARG40, \
    _ARG41,_ARG42,_ARG43,_ARG44,_ARG45,_ARG46,_ARG47,_ARG48,_ARG49,_ARG50, \
    _ARG51,_ARG52,_ARG53,_ARG54,_ARG55,_ARG56,_ARG57,_ARG58,_ARG59,_ARG60, \
    _ARG61,_ARG62,_ARG63,_ARG64,_N,...) _N

#define REV_ARG_SEQUENCE() \
                   64,63,62,61,60, \
    59,58,57,56,55,54,53,52,51,50, \
    49,48,47,46,45,44,43,42,41,40, \
    39,38,37,36,35,34,33,32,31,30, \
    29,28,27,26,25,24,23,22,21,20, \
    19,18,17,16,15,14,13,12,11,10, \
     9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#endif//SUBDETECTION_VA_ARG_NUMBER_H
