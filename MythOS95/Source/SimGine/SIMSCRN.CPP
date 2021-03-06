//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                     A Simluator Framework for MythOS(tm)
//
//                     Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1997-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Dan Higdon and Chuck Walbourn
//
// simscrn.cpp
//
// This module contains the screen management class
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "simgine.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SimScreen::SimScreen() :
    gvport (0),
    pal (0),
    vgs (0),
    brightness (0.0)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SimScreen::~SimScreen()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - init
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SimScreen::error_codes SimScreen::init (ushort w, ushort h,
                                        ushort bd, dword flags)
{
    width = w;
    height = h;
    bit_depth = bd;

    return ERROR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - release
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - lock
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
long SimScreen::lock ()
{
    assertMyth("SimScreen::lock needs viewport", gvport != 0);

    return gvport->lock();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - unlock
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int SimScreen::unlock ()
{
    assertMyth("SimScreen::unlock needs viewport", gvport != 0);

    return gvport->unlock();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - clear
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - load_palette
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL SimScreen::load_palette (const char *fname, const char *name,
                              BOOL freeold)
{
    assertMyth("SimScreen::load_palette needs viewport", gvport != 0);

    assertMyth("SimScreen::load_palette needs input filename", fname != 0);

    VngoPal *temp_pal = pal;

//陳� Initialize the Vangogh palette
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

//陳� Set palette
    BOOL retval = set_palette(pal);

//陳� Clean up any old palette information that is still around.
    if (freeold && temp_pal)
        delete temp_pal;

    return retval;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - set_palette
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL SimScreen::set_palette (VngoPal *p, BOOL clr)
{
    assertMyth("SimScreen::set_palette needs screen manager and viewport",
               vgs != 0 && gvport != 0);

//陳� Clear if needed
    if (clr)
    {
        clear();
        flip();
    }

//陳� Set palette
    vgs->set_palette(p,brightness);
    pal = p;
    gvport->vbuff.pal = pal;

//陳� Clear again if needed
    if (clr)
    {
        clear();
        flip();
    }

    return TRUE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - set_brightness
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void SimScreen::set_brightness(float b)
{
    brightness = b;
    reinit();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreen - capture
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL SimScreen::capture()
{
    assertMyth("SimScreen::capture needs viewport and pal",
               gvport != 0 && pal != 0);

    XFBitmap    bm;

//陳� Copy data into bitmap
    if (!gvport)
    {
        if (gvport->capture(&bm) != VNGO_NO_ERROR)
            return FALSE;
    }

//陳� Write it out
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

//葦� End of module - simscrn.cpp 憶�
