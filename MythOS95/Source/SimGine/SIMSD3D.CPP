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
// simsd3d.cpp
//
// This module contains the screen management class for Microsoft Direct3D.
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
// SimScreenD3D - Constructor
//���������������������������������������������������������������������������
SimScreenD3D::SimScreenD3D() :
    SimScreen()
{
}


//���������������������������������������������������������������������������
// SimScreenD3D - Destructor
//���������������������������������������������������������������������������
SimScreenD3D::~SimScreenD3D()
{
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimScreenD3D - init
//���������������������������������������������������������������������������
SimScreen::error_codes SimScreenD3D::init (ushort w, ushort h,
                                           ushort bd, dword flags)
{
    assertMyth("SimScreenD3D::init needs SimApp", SimApp != 0);

//��� Verify bit-depth
    switch (bd)
    {
        case 15:
        case 16:
            break;
        default:
            return ERROR_INVALIDPARMS;
    }

//��� Determine screen manager init flags
    dword init_flags = VNGO_3DDEVICE | VNGO_ALLOC_ZBUFFER;

    if (flags & FULLSCREEN)
    {
        init_flags |= VNGO_SET_RESOLUTION;

        if (w == 320 && h == 240)
            init_flags |= VNGO_TRUE_FLIP | VNGO_FORCE_SYSTEMMEMORY;
    }

    if (flags & TRUEFLIP)
        init_flags |= VNGO_TRUE_FLIP;

//��� Bit-depth error retry loop
    for (;;)
    {
        release();

        //��� Create screen manager
        vgs = new VngoDirect3D (SimApp->hWndClient);
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
        VNGError err = vgs->set_mode (w, h, 16, pal, init_flags);
        if (err == VNGO_NEEDS_PAL16)
            bd = 16;
        else if (err == VNGO_NEEDS_PAL15)
            bd = 15;
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
    gvport = new VngoVportD3D (VngoRect(0,0,w,h), pal, VNGO_ZBUFFER_DEV, vgs);
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

    gvport->zbuffer_off();

    clear();

    return ERROR_NONE;
}


//���������������������������������������������������������������������������
// SimScreenD3D - create_subviewport
//���������������������������������������������������������������������������
VngoVport *SimScreenD3D::create_subviewport(VngoRect &srect, dword flags)
{
    assertMyth("SimScreenD3D::create_subviewport needs screen manager and palette",
               vgs != 0 && pal != 0);

    // Why always allocate at zbuffer?
    // Shouldn't the app be able to control this?

    VngoVport *vport = new VngoVportD3D (srect, pal,
                                         flags | VNGO_ZBUFFER_DEV, vgs);
    if (!vport)
        return 0;

    if (!(flags & VNGO_ZBUFFER_DEV))
        vport->zbuffer_off();

    return vport;
}


//���������������������������������������������������������������������������
// SimScreenD3D - lock
//���������������������������������������������������������������������������
long SimScreenD3D::lock ()
{
    return 1;
}


//���������������������������������������������������������������������������
// SimScreenD3D - unlock
//���������������������������������������������������������������������������
int SimScreenD3D::unlock ()
{
    return 0;
}

//��� End of module - simsd3d.cpp ���
