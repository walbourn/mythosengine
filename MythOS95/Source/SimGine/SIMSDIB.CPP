//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                              S I M   G I N E
//
//             __               ___   ______,-------
//           __==__,------------/|\--|      | .-.-.|    ___________
//         (|     |--------------|---|------| '-`-`|  _/___________\_
//         (|_____|      _       _   |   _  | 6000 | |               |
//          |__\\_|`-._/___\___/___\_|_/___\|      | |               |
//         __/ |===|--|_____|_|_____|_|___  |\_____|=|_______________|
//      |=|[_]==[_]    \ _ /   \ _ /   \ _ /          [_]   [_]   [_]
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                     A Simluator Framework for MythOS(tm)
//
//                        Microsoft Windows '95 Version
//
//               Copyright (c) 1997 by Charybdis Enterprises, Inc.
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
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// simsdib.cpp
//
// This module contains the screen management class for DIBs
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "simgine.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimScreenDIB - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
SimScreenDIB::SimScreenDIB() :
    SimScreen()
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimScreenDIB - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
SimScreenDIB::~SimScreenDIB()
{
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimScreenDIB - init
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
SimScreen::error_codes SimScreenDIB::init (ushort w, ushort h,
                                           ushort bd, dword flags)
{
    BYTE *bits;

    assertMyth("SimScreenDIB::init needs SimApp", SimApp != 0);

//ÄÄÄ Call base
    error_codes err = SimScreen::init(w,h,bd,flags);
    if (err)
        return err;

//ÄÄÄ Create screen manager
    vgs = new VngoDIB(SimApp->hWndClient);
    if (!vgs)
        return ERROR_NOMEMORY;

//ÄÄÄ Create palette
    switch(bit_depth)
    {
        case 8:
            pal = new VngoPal8;
            if (!pal)
            {
                err = ERROR_NOMEMORY;
                goto leave_error;
            }
            if (((VngoPal8*)pal)->init(0) != 0)
            {
                err = ERROR_PALINIT;
                goto leave_error;
            }
            break;
        case 15:
            pal = new VngoPal15;
            if (!pal)
            {
                err = ERROR_NOMEMORY;
                goto leave_error;
            }
            if (((VngoPal15*)pal)->init(0) != 0)
            {
                err = ERROR_PALINIT;
                goto leave_error;
            }
            break;
        case 16:
            pal = new VngoPal16;
            if (!pal)
            {
                err = ERROR_NOMEMORY;
                goto leave_error;
            }
            if (((VngoPal16*)pal)->init(0) != 0)
            {
                err = ERROR_PALINIT;
                goto leave_error;
            }
            break;
        default:
            err = ERROR_MODENOTSUPP;
            goto leave_error;
    }

//ÄÄÄ Setup mode
    {
        int tbd = 8;
        if (bit_depth != 8)
            tbd = 16;

        vgs->set_mode (width, height, tbd, pal, (flags & FULLSCREEN));
    }

    bits = ((VngoDIB*)vgs)->gmap;
    if (!bits)
    {
        err = ERROR_MODEFAIL;
        goto leave_error;
    }

    if (w == 320 && h == 240 && (flags & FULLSCREEN))
    {
        // Here we need to verify that we can do a SetDIBits successfully.
        // the only thing I know that seems to answer that question is
        // attempting to create a primary surface, and if it can be created
        // in video memory, then the SetDIBits always seems to work.

        DDSURFACEDESC   ddsd;
        ZeroMemory(&ddsd,sizeof(ddsd));
        ddsd.dwSize=sizeof(ddsd);
        ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
        ddsd.dwBackBufferCount = 1;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE
                              | DDSCAPS_FLIP
                              | DDSCAPS_COMPLEX
                              | DDSCAPS_VIDEOMEMORY;

        LPDIRECTDRAWSURFACE     primary;

        HRESULT err = ((VngoDIB*)vgs)->dd->CreateSurface(&ddsd,&primary,NULL);

        if (err != DD_OK)
        {
            err = ERROR_MODENOTSUPP;
            goto leave_error;
        }
        else
            primary->Release();
    }

//ÄÄÄ Setup viewport
    if (bit_depth == 8)
    {
        gvport = new VngoVportDB8 (width, height, bits, NULL, pal, 0);
    }
    else
    {
        gvport = new VngoVportDB16 (width, height, bits, NULL, pal, 0);
    }
    if (!bits || !gvport)
    {
        err = ERROR_NOMEMORY;
        goto leave_error;
    }

    if (gvport->get_init_state())
    {
        err = ERROR_VPORTINIT;
        goto leave_error;
    }

    clear();

    return ERROR_NONE;

leave_error: ;
    if (gvport)
    {
        delete gvport;
        gvport=0;
    }
    if (pal)
    {
        delete pal;
        pal=0;
    }
    if (vgs)
    {
        delete vgs;
        vgs=0;
    }

    return err;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimScreenDIB - create_subviewport
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoVport *SimScreenDIB::create_subviewport(VngoRect &srect, dword flags)
{
    assertMyth("SimScreenDIB::create_subviewport needs viewport and palette",
               gvport != 0 && pal != 0);

    int waslocked = lock();
    
    VngoVport *vport;

    if (bit_depth == 8)
    {
        vport = new VngoVportDB8 (srect.dx, srect.dy,
                                  gvport->vbuff.scrn_ptr
                                  + srect.x
                                  + gvport->vbuff.ytable[srect.y],
                                  NULL, pal, flags, gvport->vbuff.pitch);
    }
    else
    {
        dword t = dword(gvport->vbuff.scrn_ptr) + (srect.x << 1) + gvport->vbuff.ytable[srect.y];
        vport = new VngoVportDB16 (srect.dx, srect.dy,
                                  (void*)t,
                                  NULL, pal, flags, gvport->vbuff.pitch);
    }

    if (!waslocked)
        unlock();

    return vport;
}

//°±² End of module - simsdib.cpp ²±°

