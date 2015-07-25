//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little
//
// vngmsi.cpp
//                              O B S O L E T E
//
// Matrox Simple Interface
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


#include <string.h>
#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "ivory.h"
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
#include "vngoems.hpp"

#ifdef TEMP_OEMS
#undef TEMP_OEMS
#undef _OEMS
#endif

#ifdef TEMP_MSI
#undef TEMP_MSI
#undef _MSI
#endif


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MIN(a,b)  ((a) < (b)) ? (a) : (b)

#define ZCONST (1.f/65535.0f)
#define FIXED16CONV (1.f/65536.f)

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the Virtual View Port stuff.                                     ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ


VngoVportMSI::VngoVportMSI (VngoRect &dim,VngoPal *my_pal,dword flags,VngoScreenManager *_screen)
{
    init_status = init (dim,my_pal,flags,_screen);
}

VNGError VngoVportMSI::init (VngoRect &dim,VngoPal *my_pal,dword flags,VngoScreenManager *_screen)
{
    screen = (VngoMSI*)_screen;
    vflags = flags;

    screen->msiParms.msiTexture.Enable                 = FALSE;
    screen->msiParms.msiTexture.Width                  = 0;
    screen->msiParms.msiTexture.Height                 = 0;
    screen->msiParms.msiTexture.Planes                 = 16;
    screen->msiParms.msiTexture.pMem                   = NULL;
    screen->msiParms.msiTexture.pHeap                  = NULL;
    screen->msiParms.msiTexture.CacheOffset            = 0;
    screen->msiParms.msiTexture.Clamp_u                = FALSE;
    screen->msiParms.msiTexture.Clamp_v                = FALSE;
    screen->msiParms.msiTexture.Modulate               = FALSE;
    screen->msiParms.msiTexture.Decal                  = FALSE;
    screen->msiParms.msiTexture.Transparency           = FALSE;
    screen->msiParms.msiTexture.KeyingColor            = 0x0000;
    screen->msiParms.msiTexture.KeyingColorMask        = 0xFFFF;
    screen->msiParms.msiTexture.KeyingAlpha            = 0x0001;
    screen->msiParms.msiTexture.KeyingAlphaMask        = 0x0000;

    screen->msiParms.msiTexture.msiLUT.pMem            = NULL;
    screen->msiParms.msiTexture.msiLUT.pHeap           = NULL;
    screen->msiParms.msiTexture.msiLUT.CacheOffset     = 0;

    screen->msiParms.msiDepth.Enable                   = TRUE;
    screen->msiParms.msiDepth.Compare                  = msiCMP_ALWAYS;
    screen->msiParms.msiDepth.Protect                  = FALSE;

    screen->msiParms.msiColor.Dither                   = TRUE;
    screen->msiParms.msiColor.Protect                  = FALSE;


    if (!msiSetParameters(&screen->msiParms))
        return VNGO_INTERNAL_ERROR;

    reset();

    return (VNGO_NO_ERROR);
}

VngoVportMSI::~VngoVportMSI()
{
}

void VngoVportMSI::reset(dword c,dword farz)
{
    screen->open_frame();
    {
        if (msiSetParameters(&screen->msiParms))
        {
#if 0
            VngoColor24bit bcolor = vbuff.pal->get_RGB(c);
            float z = float(dword(farz) >> 16) * ZCONST;
            msiClearBack(float(bcolor.r),float(bcolor.g),float(bcolor.b));
            msiClearZ (z);
#else
            msiClearBack(0.f,0.f,0.f);
            msiClearZ (1.f);
#endif
        }
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the start of the draw function block of the VngoVportMSI class.  ³
// all fucntions in this class draw to a 8 bit device regardless of the size³
// of the input color information.                                          ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VNGError VngoVportMSI::poly (int count,VngoPoint pts[])
{
    screen->open_frame();
    {
        T_msiVertex     tpts[VNGO_MAX_VERTCOUNT];
        VngoColor24bit tclr = vbuff.pal->get_RGB(((VngoShadePal8*)(vbuff.pal->shd_pal))->get_shaded_index(pts[0].clr,pts[0].shade));
        for (int i = 0; i < count; i++)
        {
            tpts[i].x = float(pts[i].x);
            tpts[i].y = float(pts[i].y);
            tpts[i].z = 0.5f;
//            tpts[i].z = (float)((dword)pts[i].z >> 16) * ZCONST;
            tpts[i].r = (float)tclr.r;
            tpts[i].g = (float)tclr.g;
            tpts[i].b = (float)tclr.b;
        }

//        screen->msiParms.msiTexture.Enable = FALSE;

//        if (!msiSetParameters(&screen->msiParms))
//            return VNGO_INTERNAL_ERROR;


        // if there are more than three vertices, break it into a series
        // of triangles.
        for (i=1;i < count-1;i++)
        {
             msiRenderTriangle(&tpts[0],&tpts[i],&tpts[i+1],100);
        }
        return VNGO_NO_ERROR;
    }
    return VNGO_INTERNAL_ERROR;
}

VNGError VngoVportMSI::poly (int count,VngoPointF pts[])
{
    return VNGO_NOT_SUPPORTED;
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    {
        T_msiVertex     tpts[VNGO_MAX_VERTCOUNT];
        VngoColor24bit tclr = vbuff.pal->get_RGB(((VngoShadePal8*)(vbuff.pal->shd_pal))->get_shaded_index(pts[0].clr,int(pts[0].shade * 255)));
        for (int i = 0; i < count; i++)
        {
            tpts[i].x = float(pts[i].x) * FIXED16CONV;
            tpts[i].y = float(pts[i].y) * FIXED16CONV;
            tpts[i].z = 0.5f;
//            tpts[i].z = (float)((dword)pts[i].z >> 16) * ZCONST;
            tpts[i].r = (float)tclr.r;
            tpts[i].g = (float)tclr.g;
            tpts[i].b = (float)tclr.b;

            assert (pts[i].x >= 0);
            assert (pts[i].x < (vbuff.width << 16));
            assert (pts[i].y >= 0);
            assert (pts[i].y < (vbuff.height << 16));
        }

//        screen->msiParms.msiTexture.Enable = FALSE;

//        if (!msiSetParameters(&screen->msiParms))
//            return VNGO_INTERNAL_ERROR;


        // if there are more than three vertices, break it into a series
        // of triangles.
        for (i=1;i < count-1;i++)
        {
             msiRenderTriangle(&tpts[0],&tpts[i],&tpts[i+1],100);
        }
        return VNGO_NO_ERROR;
    }
    return VNGO_INTERNAL_ERROR;
}

VNGError VngoVportMSI::gpoly (int count,VngoPoint pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    {
        T_msiVertex     tpts[VNGO_MAX_VERTCOUNT];
        for (int i = 0; i < count; i++)
        {
            VngoColor24bit tclr = vbuff.pal->get_RGB(((VngoShadePal8*)(vbuff.pal->shd_pal))->get_shaded_index(pts[i].clr,pts[i].shade));
            tpts[i].x = float(pts[i].x);
            tpts[i].y = float(pts[i].y);
            tpts[i].z = 0.5f;
//            tpts[i].z = (float)((dword)pts[i].z >> 16) * ZCONST;
            tpts[i].r = (float)tclr.r;
            tpts[i].g = (float)tclr.g;
            tpts[i].b = (float)tclr.b;
        }

//        screen->msiParms.msiTexture.Enable = FALSE;

//        if (!msiSetParameters(&screen->msiParms))
//            return VNGO_INTERNAL_ERROR;


        // if there are more than three vertices, break it into a series
        // of triangles.
        for (i=1;i < count-1;i++)
        {
             msiRenderTriangle(&tpts[0],&tpts[i],&tpts[i+1],100);
        }
        return VNGO_NO_ERROR;
    }
    return VNGO_INTERNAL_ERROR;
}

VNGError VngoVportMSI::gpoly (int count,VngoPointF pts[])
{
    return VNGO_NOT_SUPPORTED;
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    {
        T_msiVertex     tpts[VNGO_MAX_VERTCOUNT];
        for (int i = 0; i < count; i++)
        {
            VngoColor24bit tclr = vbuff.pal->get_RGB(((VngoShadePal8*)(vbuff.pal->shd_pal))->get_shaded_index(pts[i].clr,int(pts[i].shade * 255)));
            tpts[i].x = float(pts[i].x) * FIXED16CONV;
            tpts[i].y = float(pts[i].y) * FIXED16CONV;
            tpts[i].z = 0.5f;
//            tpts[i].z = (float)((dword)pts[i].z >> 16) * ZCONST;
            tpts[i].r = (float)tclr.r;
            tpts[i].g = (float)tclr.g;
            tpts[i].b = (float)tclr.b;

            assert (pts[i].x >= 0);
            assert (pts[i].x < (vbuff.width << 16));
            assert (pts[i].y >= 0);
            assert (pts[i].y < (vbuff.height << 16));
        }

//        screen->msiParms.msiTexture.Enable = FALSE;

//        if (!msiSetParameters(&screen->msiParms))
//            return VNGO_INTERNAL_ERROR;


        // if there are more than three vertices, break it into a series
        // of triangles.
        for (i=1;i < count-1;i++)
        {
             msiRenderTriangle(&tpts[0],&tpts[i],&tpts[i+1],100);
        }
        return VNGO_NO_ERROR;
    }
    return VNGO_INTERNAL_ERROR;
}


//°±² End of module - vngvvp8.cpp ²±°
