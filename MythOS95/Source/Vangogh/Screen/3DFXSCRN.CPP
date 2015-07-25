//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  |
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
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
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// 3dfx.cpp
//
//
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ


#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "vngdefs.h"

// This is so this module will build whether _OEMS are defined or not!
#ifndef _OEMS
#define TEMP_OEMS
#define _OEMS
#endif

#ifndef _3DFX
#define TEMP_3DFX
#define _3DFX
#endif

#include "vangogh.hpp"
#include "vngscrn.hpp"

#ifdef TEMP_OEMS
#undef TEMP_OEMS
#undef _OEMS
#endif

#ifdef TEMP_3DFX
#undef TEMP_3DFX
#undef _3DFX
#endif

Vngo3Dfx::Vngo3Dfx()
{
    strcpy(hwName,"3dfx");
    init_state = init();
}

Vngo3Dfx::~Vngo3Dfx()
{
    term();
}


VNGError Vngo3Dfx::init()
{
    grGlideInit();
    if (!grSstQueryHardware (&hwconfig))
    {
        term();
        return (VNGO_MISSING_HARDWARE);
    }

    type_info = SCREENTYPE_3DFX;

    grSstSelect(0);
    return (VNGO_NO_ERROR);
}


VNGError Vngo3Dfx::set_mode(int width, int height, int bpp, VngoPal *pal, dword flags)
{
    bit_depth = bpp;

    if (width == 640 && height == 480)
        screenRes = GR_RESOLUTION_640x480;
    else if (width = 320 && height == 240)
        screenRes = GR_RESOLUTION_320x240;

    if (!grSstOpen(screenRes,
                   GR_REFRESH_60Hz,
                   GR_COLORFORMAT_ARGB,
                   GR_ORIGIN_UPPER_LEFT,
                   GR_SMOOTHING_DISABLE,
                   2))
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

    grBufferClear(0,0,GR_WDEPTHVALUE_FARTHEST);
    grBufferSwap(1);
    grBufferClear(0,0,GR_WDEPTHVALUE_FARTHEST);

    return VNGO_NO_ERROR;
}


VNGError Vngo3Dfx::flip()
{
    grBufferSwap(1);
    return VNGO_NO_ERROR;
}


VNGError Vngo3Dfx::term()
{
    grGlideShutdown();
    return VNGO_NO_ERROR;
}

VNGError Vngo3Dfx::dump_textures()
{
    return VNGO_NO_ERROR;
}
