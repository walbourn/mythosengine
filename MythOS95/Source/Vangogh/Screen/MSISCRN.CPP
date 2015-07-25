//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
//                        http://www.mythos-engine.org/
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// Created by Tim Little
//
//                              O B S O L E T E
//
// MSIscrn.cpp
//
// Matrox Simple Interface
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

#ifndef _MSI
#define TEMP_MSI
#define _MSI
#endif


#include "vangogh.hpp"
#include "vngscrn.hpp"


#ifdef TEMP_OEMS
#undef TEMP_OEMS
#undef _OEMS
#endif

#ifdef TEMP_MSI
#undef TEMP_MSI
#undef _MSI
#endif

VngoMSI::VngoMSI()
{
    frame_is_open = FALSE;
    strcpy(hwName,"MSI95");
    init_state = init(NULL);
}

VngoMSI::VngoMSI(WNDPROC lpWindowProc)
{
    strcpy(hwName,"MSI95");
    frame_is_open = FALSE;
    init_state = init(lpWindowProc);
}

VngoMSI::~VngoMSI()
{
    term();
}


VNGError VngoMSI::init()
{
    return init(NULL);
}

VNGError VngoMSI::init( WNDPROC lpWindowProc)
{
    if (!msiQueryInfo(QueryInfoStructMinSize, (LPBYTE)&BoardInfo))
    {
        return VNGO_INTERNAL_ERROR;
    }
    lpWinProc = lpWindowProc;
    type_info = SCREENTYPE_MSI;
    return (VNGO_NO_ERROR);
}


VNGError VngoMSI::set_mode(int width, int height, int bpp, VngoPal *pal, dword flags)
{
    bit_depth = bpp;

    pInfo = msiInit(width,height,16,1,msiDBG_DumpToFile,lpWinProc);
    if (!pInfo)
        return VNGO_INTERNAL_ERROR;

// Clear all of the buffers.
    if (!msiStartFrame(1,0.f,0.f,0.f,1,1.f))
        return VNGO_INTERNAL_ERROR;


// Now do a quick flip.
    if (!msiEndFrame(0,0,1))
        return VNGO_INTERNAL_ERROR;


    return VNGO_NO_ERROR;
}


VNGError VngoMSI::flip()
{
    if (frame_is_open)
        close_frame(0,0,1);

    return VNGO_NO_ERROR;
}


VNGError VngoMSI::term()
{
    if (frame_is_open)
        close_frame(0,0,1);
    msiExit();

    return VNGO_NO_ERROR;
}

VNGError VngoMSI::dump_textures()
{
    return VNGO_NO_ERROR;
}

