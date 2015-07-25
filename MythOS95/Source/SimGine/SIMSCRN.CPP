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
// simscrn.cpp
//
// This module contains the screen management class
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
// SimScreen - Constructor
//���������������������������������������������������������������������������
SimScreen::SimScreen() :
    gvport (0),
    pal (0),
    vgs (0),
    brightness (0.0)
{
}


//���������������������������������������������������������������������������
// SimScreen - Destructor
//���������������������������������������������������������������������������
SimScreen::~SimScreen()
{
    release();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimScreen - init
//���������������������������������������������������������������������������
SimScreen::error_codes SimScreen::init (ushort w, ushort h,
                                        ushort bd, dword flags)
{
    width = w;
    height = h;
    bit_depth = bd;

    return ERROR_NONE;
}


//���������������������������������������������������������������������������
// SimScreen - release
//���������������������������������������������������������������������������
void SimScreen::release()
{
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
}


//���������������������������������������������������������������������������
// SimScreen - lock
//���������������������������������������������������������������������������
long SimScreen::lock ()
{
    assertMyth("SimScreen::lock needs viewport", gvport != 0);

    return gvport->lock();
}


//���������������������������������������������������������������������������
// SimScreen - unlock
//���������������������������������������������������������������������������
int SimScreen::unlock ()
{
    assertMyth("SimScreen::unlock needs viewport", gvport != 0);

    return gvport->unlock();
}


//���������������������������������������������������������������������������
// SimScreen - clear
//���������������������������������������������������������������������������
void SimScreen::clear ()
{
    assertMyth("SimScreen::clear needs viewport and palette",
               gvport != 0 && pal != 0);

    int was_locked = lock();
    if (was_locked != -1)
    {
        gvport->reset(pal->get_index (VngoColor24bit (0,0,0)));
        if (!was_locked)
            unlock();
    }
    invalidate();
}


//���������������������������������������������������������������������������
// SimScreen - load_palette
//���������������������������������������������������������������������������
BOOL SimScreen::load_palette (const char *fname, const char *name,
                              BOOL freeold)
{
    assertMyth("SimScreen::load_palette needs viewport", gvport != 0);

    assertMyth("SimScreen::load_palette needs input filename", fname != 0);

    VngoPal *temp_pal = pal;

//��� Initialize the Vangogh palette
    switch (bit_depth)
    {
        case 8:
            {
                pal = new VngoPal8;
                if (!pal)
                    return FALSE;

                if (((VngoPal8*)pal)->init(0) != 0)
                    return FALSE;

                VngoPalIFF8 loadpal(pal);
                if (name)
                    strncpy(loadpal.name,name,16);

                if (loadpal.load(fname) != 0)
                    return FALSE;
            }
            break;
        case 15:
            {
                pal = new VngoPal15;
                if (!pal)
                    return FALSE;

                if (((VngoPal15*)pal)->init(0) != 0)
                    return FALSE;

                VngoPalIFF15 loadpal(pal);
                if (name)
                    strncpy(loadpal.name,name,16);

                if (loadpal.load(fname) != 0)
                    return FALSE;
            }
            break;
        case 16:
            {
                pal = new VngoPal16;
                if (!pal)
                    return FALSE;

                if (((VngoPal16*)pal)->init(0) != 0)
                    return FALSE;

                VngoPalIFF16 loadpal(pal);
                if (name)
                    strncpy(loadpal.name,name,16);

                if (loadpal.load(fname) != 0)
                    return FALSE;
            }
            break;
        default:
            return FALSE;
    }

//��� Set palette
    BOOL retval = set_palette(pal);

//��� Clean up any old palette information that is still around.
    if (freeold && temp_pal)
        delete temp_pal;

    return retval;
}


//���������������������������������������������������������������������������
// SimScreen - set_palette
//���������������������������������������������������������������������������
BOOL SimScreen::set_palette (VngoPal *p, BOOL clr)
{
    assertMyth("SimScreen::set_palette needs screen manager and viewport",
               vgs != 0 && gvport != 0);

//��� Clear if needed
    if (clr)
    {
        clear();
        flip();
    }

//��� Set palette
    vgs->set_palette(p,brightness);
    pal = p;
    gvport->vbuff.pal = pal;

//��� Clear again if needed
    if (clr)
    {
        clear();
        flip();
    }

    return TRUE;
}


//���������������������������������������������������������������������������
// SimScreen - set_brightness
//���������������������������������������������������������������������������
void SimScreen::set_brightness(float b)
{
    brightness = b;
    reinit();
}


//���������������������������������������������������������������������������
// SimScreen - capture
//���������������������������������������������������������������������������
BOOL SimScreen::capture()
{
    assertMyth("SimScreen::capture needs viewport and pal",
               gvport != 0 && pal != 0);

    XFBitmap    bm;

//��� Copy data into bitmap
    if (!gvport)
    {
        if (gvport->capture(&bm) != VNGO_NO_ERROR)
            return FALSE;
    }

//��� Write it out
    XFParseBMP  bmp (&bm);

    // Assign filenames
    for (int i = 0; i < 10000; i++)
    {
        char fname[XF_MAX_FNAME];

        wsprintf (fname, "snap%04d.bmp", i);
        if (!xf_exist (fname))
        {
            if (bmp.namewrite (fname))
                return FALSE;

            return TRUE;
        }
    }

    return FALSE;
}

//��� End of module - simscrn.cpp ���