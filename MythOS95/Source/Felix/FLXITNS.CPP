//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//
//            _,'|             _.-''``-...___..--';)
//           /_ \'.      __..-' ,      ,--...--'''
//          <\    .`--'''       `     /'
//           `-';'               ;   ; ;  Felix the Fixed-point Library
//     __...--''     ___...--_..'  .;.'
//    (,__....----'''       (,..--''
//
//                      Microsoft Windows '95 Version
//
//           Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// flxitns.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"
#include "assert.h"
#include "felix.hpp"


Flx16 flx_asin (const Flx16 a)
{
    int     top = SIN_TABLE_SIZE;
    int     target;
    int     bottom = 0;
    Flx16   *data = &Flx16_sin_data;
    Flx16   t = flx_abs(a);

    for (;;)
    {
        target = (top + bottom) >> 1;
        if (target == bottom || target == top)
            break;

        const Flx16 current = data[target];
        if (t == current)
            break;

        else if (t > current)
            bottom = target;

        else
            top = target;
    }

    t = target;
    t.flx >>= FLX_DEGREES_SHIFT;

    if (a < 0)
        return -t;
    else
        return t;
}


// This is non-recursive, but harder to follow.  See the
// recursive version for insights into how this works
Flx16 flx_atan (const Flx16 a)
{
    const Flx16 PI_2 = Flx16 (1.570796327);
    Flx16   x   = a;
    int     neg = x < 0;
    Flx16   ax  = neg ? -x: x;
    Flx16   c   = 0;

    if (ax > FLX16_ONE)             // tan(45) deg, or tan(pi/4) in radians
    {
        // If we're out of range, fold back into the range
        ax = FLX16_ONE / ax;

        // Adjust the constant, x, and our negative flag
        if (neg)
        {
            c   = -PI_2;
            x   = ax;
            neg = 0;
        }
        else
        {
            c   = PI_2;
            x   = -ax;
            neg = 1;
        }
    }

    if (ax >= Flx16 (0.2679492))    // tan(15) deg
    {
        // If we are still out of range, fold in further
        // The nearly duplicate functions are represented to
        // allow more efficient code generation (no negate step, no extra copy)
        // This can be done, because we no longer need a consistent 'ax' value.
        // (VC++ folds out the divisor -- not too shabby!)
        if (neg)
        {
            x  = (Flx16 (-1.73205081) * ax + FLX16_ONE) / (ax + Flx16 (1.73205081));
            c -= Flx16 (0.523598776);
        }
        else
        {
            x  = (Flx16 (1.73205081) * ax - FLX16_ONE) / (ax + Flx16 (1.73205081));
            c += Flx16 (0.523598776);
        }
    }

    // Compute the atan, now that we're in range
    const Flx16 x2  = x * x;
    const Flx16 res = x * (Flx16 (0.60310579)
                           + Flx16 (0.55913709) / (Flx16 (1.4087812) + x2)
                           - Flx16 (0.05160454) * x2);

    // Return the adjusted atan
    return (c + res) * Flx16 (90) / PI_2;
}

// eof - Flxitns.cpp
