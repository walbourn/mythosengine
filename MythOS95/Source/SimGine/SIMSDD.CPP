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
// simsdd.cpp
//
// This module contains the screen management class for DirectDraw
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
// SimScreenDD - Constructor
//���������������������������������������������������������������������������
SimScreenDD::SimScreenDD() :
    SimScreen()
{
}


//���������������������������������������������������������������������������
// SimScreenDD - Destructor
//���������������������������������������������������������������������������
SimScreenDD::~SimScreenDD()
{
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimScreenDD - init
//���������������������������������������������������������������������������
SimScreen::error_codes SimScreenDD::init (ushort w, ushort h,
                                          ushort bd, dword flags)
{
    assertMyth("SimScreenDD::init needs SimApp", SimApp != 0);

//��� Verify bit-depth
    switch (bd)
    {
        case 8:
        case 15:
        case 16:
            break;
        default:
            return ERROR_INVALIDPARMS;
    }

//��� Determine screen manager init flags
    dword init_flags = 0;
    if (flags & FULLSCREEN)
    {
        init_flags |= VNGO_SET_RESOLUTION;

        if (w == 320 && h == 240)
            init_flags |= VNGO_TRUE_FLIP | VNGO_FORCE_SYSTEMMEMORY;
    }
    if (flags & TRUEFLIP)
    {
        init_flags |= VNGO_TRUE_FLIP;
    }

//��� Bit-depth error retry loop
    for (;;)
    {
        release();

        //��� Create screen manager
        vgs = new VngoDirectDraw (SimApp->hWndClient);
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
            case 16:
                pal = new VngoPal16;
                if (!pal)
                {
                    release();
                    return ERROR_NOMEMORY;
                }
                if (((VngoPal16*)pal)->init(0) != 0)
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
        int cdepth = (bd != 8) ? 16 : 8;

        VNGError err = vgs->set_mode (w, h, cdepth, pal, init_flags);
        if (err == VNGO_NEEDS_PAL16)
            bd = 16;
        else if (err == VNGO_NEEDS_PAL15)
            bd = 15;
        else if (err == VNGO_NEEDS_PAL8)
            bd = 8;
        else if (err)
        {
            release();
            return ERROR_MODEFAIL;
        }
        else
            break;
    }

//��� Call base
    error_codes err = SimScreen::init(w,h,bd,flags);
    if (err)
        return err;

//��� Setup viewport
    if (bd == 8)
    {
        gvport = new VngoVportDD8 (((VngoDirectDraw*)vgs)->SurfaceManager,
                                   NULL, pal, 0);
    }
    else
    {
        gvport = new VngoVportDD16 (((VngoDirectDraw*)vgs)->SurfaceManager,
                                    NULL, pal, 0);
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
// SimScreenDD - create_subviewport
//���������������������������������������������������������������������������
VngoVport *SimScreenDD::create_subviewport(VngoRect &srect, dword flags)
{
    assertMyth("SimScreenDD::create_subviewport needs screen manager and palette",
               vgs != 0 && pal != 0);

    if (bit_depth == 8)
    {
        return new VngoVportDD8(((VngoDirectDraw*)vgs)->SurfaceManager,
                                NULL,srect,
                                pal, flags);
    }
    else
    {
        return new VngoVportDD16(((VngoDirectDraw*)vgs)->SurfaceManager,
                                 NULL,srect,
                                 pal, flags);
    }
}


//���������������������������������������������������������������������������
// SimScreenDD - lock
//���������������������������������������������������������������������������
long SimScreenDD::lock ()
{
    return 1;
}


//���������������������������������������������������������������������������
// SimScreenDD - unlock
//���������������������������������������������������������������������������
int SimScreenDD::unlock ()
{
    return 0;
}

//��� End of module - simsdd.cpp ���
