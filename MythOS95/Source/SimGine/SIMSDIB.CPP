//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
//                     A Simluator Framework for MythOS(tm)
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1997-1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//���������������������������������������������������������������������������
//
// simsdib.cpp
//
// This module contains the screen management class for DIBs
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "simgine.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimScreenDIB - Constructor
//���������������������������������������������������������������������������
SimScreenDIB::SimScreenDIB() :
    SimScreen()
{
}


//���������������������������������������������������������������������������
// SimScreenDIB - Destructor
//���������������������������������������������������������������������������
SimScreenDIB::~SimScreenDIB()
{
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimScreenDIB - init
//���������������������������������������������������������������������������
SimScreen::error_codes SimScreenDIB::init (ushort w, ushort h,
                                           ushort bd, dword flags)
{
    assertMyth("SimScreenDIB::init needs SimApp", SimApp != 0);

    release();

//��� Verify bit-depth
    switch (bd)
    {
        case 8:
        case 15:
            break;
        default:
            return ERROR_INVALIDPARMS;
    }

//��� Call base
    error_codes err = SimScreen::init(w,h,bd,flags);
    if (err)
        return err;

//��� Create screen manager
    vgs = new VngoDIB(SimApp->hWndClient);
    if (!vgs)
        return ERROR_NOMEMORY;

    if (vgs->get_initstate())
    {
        release();
        return ERROR_SCNRMNGRINIT;
    }

//��� Create palette
    switch(bd)
    {
        case 8:
            pal = new VngoPal8;
            if (!pal)
            {
                release();
                return ERROR_NOMEMORY;
            }
            if (((VngoPal8*)pal)->init(0) != 0)
            {
                release();
                return ERROR_PALINIT;
            }
            break;
        case 15:
            pal = new VngoPal15;
            if (!pal)
            {
                release();
                return ERROR_NOMEMORY;
            }
            if (((VngoPal15*)pal)->init(0) != 0)
            {
                release();
                return ERROR_PALINIT;
            }
            break;
        default:
            release();
            return ERROR_INVALIDPARMS;
    }

//��� Setup mode
    {
        dword init_flags = 0;

        if (flags & FULLSCREEN)
            init_flags |= VNGO_SET_RESOLUTION;

        int cdepth = 8;
        if (bd != 8)
            cdepth = 16;

        if (vgs->set_mode (w, h, cdepth, pal, init_flags))
        {
            release();
            return ERROR_MODEFAIL;
        }
    }

    BYTE *bits = ((VngoDIB*)vgs)->gmap;
    if (!bits)
    {
        release();
        return ERROR_MODEFAIL;
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
            release();
            return ERROR_MODENOTSUPP;
        }
        else
            primary->Release();
    }

//��� Setup viewport
    if (bd == 8)
    {
        gvport = new VngoVportDB8 (w, h, bits, NULL, pal, 0);
    }
    else
    {
        gvport = new VngoVportDB16 (w, h, bits, NULL, pal, 0);
    }
    if (!gvport)
    {
        release();
        return ERROR_NOMEMORY;
    }

    if (gvport->get_init_state())
    {
        release();
        return ERROR_VPORTINIT;
    }

    clear();

    return ERROR_NONE;
}


//���������������������������������������������������������������������������
// SimScreenDIB - create_subviewport
//���������������������������������������������������������������������������
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
        dword t = dword(gvport->vbuff.scrn_ptr)
                  + (srect.x << 1)
                  + gvport->vbuff.ytable[srect.y];
        vport = new VngoVportDB16 (srect.dx, srect.dy,
                                  (void*)t,
                                  NULL, pal, flags, gvport->vbuff.pitch);
    }

    if (!waslocked)
        unlock();

    return vport;
}

//��� End of module - simsdib.cpp ���
