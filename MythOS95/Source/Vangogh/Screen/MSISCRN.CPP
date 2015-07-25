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
// MSIscrn.cpp
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


BOOL VngoMSI::init()
{
    return init(NULL);
}

BOOL VngoMSI::init( WNDPROC lpWindowProc)
{
    if (!msiQueryInfo(QueryInfoStructMinSize, (LPBYTE)&BoardInfo))
    {
        return FALSE;
    }
    lpWinProc = lpWindowProc;
    type_info = SCREENTYPE_MSI;
    return (TRUE);
}


BOOL VngoMSI::set_mode(int width, int height, int bpp, VngoPal *pal, dword flags)
{
    bit_depth = bpp;

    pInfo = msiInit(width,height,16,1,msiDBG_DumpToFile,lpWinProc);
    if (!pInfo)
        return FALSE;

// Clear all of the buffers.
    if (!msiStartFrame(1,0.f,0.f,0.f,1,1.f))
        return FALSE;


// Now do a quick flip.
    if (!msiEndFrame(0,0,1))
        return FALSE;


    return TRUE;
}


void VngoMSI::flip()
{
    if (frame_is_open)
        close_frame(0,0,1);
}


void VngoMSI::term()
{
    if (frame_is_open)
        close_frame(0,0,1);
    msiExit();
}
