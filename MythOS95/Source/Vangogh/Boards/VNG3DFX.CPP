//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
// vngvp8.cpp
//
//     The C pluss pluss 8bpp view port classes.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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

#ifndef _3DFX
#define TEMP_3DFX
#define _3DFX
#endif

#include "vangogh.hpp"

#ifdef TEMP_OEMS
#undef TEMP_OEMS
#undef _OEMS
#endif

#ifdef TEMP_3DFX
#undef TEMP_3DFX
#undef _3DFX
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MIN(a,b)  ((a) < (b)) ? (a) : (b)

#define ZCONST ((float)65535.0)
//#define ZCONST ((float)(65535.0 * 65535.0))

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


VngoVport3Dfx::VngoVport3Dfx (VngoRect &dim,VngoPal *my_pal,dword flags)
{
    init_status = init (dim,my_pal,flags);
}

VNGError VngoVport3Dfx::init (VngoRect &dim,VngoPal *my_pal,dword flags)
{
    vbuff.pal = my_pal;
    vbuff.width = dim.dx;
    vbuff.height = dim.dy;
//    vbuff.left = dim.x;
//    vbuff.top = dim.y;
    vflags = flags;


    grCullMode(GR_CULL_DISABLE);
    grDitherMode(GR_DITHER_4x4);
//    if (vflags &= VNGO_ZBUFFER_DEV)
    {
        grDepthBufferMode(GR_DEPTHBUFFER_ZBUFFER);
        grDepthBufferFunction(GR_CMP_LEQUAL);
        grDepthMask(FXTRUE);
//        guColorCombineFunction(GR_COLORCOMBINE_CCRGB);
        zbuffer_on();
    }

    reset();

    return (VNGO_NO_ERROR);
}

VngoVport3Dfx::~VngoVport3Dfx()
{
}

void VngoVport3Dfx::reset(dword c,dword farz)
{
    VngoColor24bit rgb = vbuff.pal->get_RGB(c);
    grBufferClear(rgb.compress16(),0,0xffff);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the start of the draw function block of the VngoVport3Dfx class. ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VNGError VngoVport3Dfx::clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val, VngoRect *clip_rect)
{
    assert(lock_status);
    assert (pt->x < vbuff.width);
    assert (pt->x >= 0);
    assert (pt->y < vbuff.height);
    assert (pt->y >= 0);

    guColorCombineFunction(GR_COLORCOMBINE_ITRGB);
    grTexCombineFunction( GR_TMU0, GR_TEXTURECOMBINE_ZERO);

    GrVertex vtx;
    vtx.x = (float)pt->x;
    vtx.y = (float)pt->y;
    vtx.z = ZCONST/(float)((dword)pt->z >> 16);
    vtx.r = (float)rgb_val->r;
    vtx.g = (float)rgb_val->g;
    vtx.b = (float)rgb_val->b;
    vtx.a = (float)255.0;
    VngoRect vprect(0 /*vbuff.left*/,0/*vbuff.top*/,vbuff.width,vbuff.height);

    if (clip_rect)
    {
        vprect.clip_to(*clip_rect);
    }
    if (vprect.point_in(*pt))
        grDrawPoint(&vtx);

    return VNGO_NO_ERROR;
}

VNGError VngoVport3Dfx::pixel(VngoPoint *pt, VngoColor24bit *rgb_val)
{
    assert(lock_status);
    assert (pt->x < vbuff.width);
    assert (pt->x >= 0);
    assert (pt->y < vbuff.height);
    assert (pt->y >= 0);

    guColorCombineFunction(GR_COLORCOMBINE_ITRGB);
    grTexCombineFunction( GR_TMU0, GR_TEXTURECOMBINE_ZERO);

    GrVertex vtx;
    if (!rgb_val)
    {
        int t = ((VngoShadePal16*)(vbuff.pal->shd_pal))->get_shaded_index(pt->clr,pt->shade);
        if (vbuff.pal->flags & VNGO_15BIT)
        {
            vtx.r = float((t >> 7) & 0xf8);
            vtx.g = float((t >> 2) & 0xf8);
            vtx.b = float((t << 3) & 0xf8);
        }
        else
        {
            vtx.r = float((t >> 8) & 0xf8);
            vtx.g = float((t >> 2) & 0xfc);
            vtx.b = float((t << 3) & 0xf8);
        }
    }
    else
    {
        vtx.r = (float)rgb_val->r;
        vtx.g = (float)rgb_val->g;
        vtx.b = (float)rgb_val->b;
    }
    vtx.x = (float)pt->x;
    vtx.y = (float)pt->y;
    vtx.ooz = (float)((dword)pt->z >> 16);
//    vtx.ooz = (1.f/(float)((dword)pt->z >> 16)) * 65535.f;
    vtx.a = (float)255.0;
    grDrawPoint(&vtx);

    return VNGO_NO_ERROR;
}

dword VngoVport3Dfx::read_pixel(int x, int y, VngoPoint *dest)
{
    assert(lock_status);

    //
    // This may be a little tricky....
    //
    return VNGO_NOT_SUPPORTED;
}


dword VngoVport3Dfx::read_pixel(VngoPoint *pt, VngoPoint *dest)
{
    assert(lock_status);

    return read_pixel(pt->x,pt->y,dest);
}

VNGError VngoVport3Dfx::frect(VngoRect *rect,VngoColor24bit *rgb_val)
{
    assert(lock_status);

    //
    // This will need to be handled as either a polygon or 2 triangles.
    //

    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVport3Dfx::frect(VngoRect *rect,dword color)
{
    assert(lock_status);

    return frect(rect,&(vbuff.pal->get_RGB(color)));
}

VNGError VngoVport3Dfx::clip_frect(VngoRect *rect,VngoColor24bit *rgb_val, VngoRect *clip)
{
    assert(lock_status);


    VngoRect vprect(0/*vbuff.left*/,0/*vbuff.top*/,vbuff.width,vbuff.height);
    VngoRect trect = *rect;
    if (clip)
    {
        if (trect.clip_to(*clip) == VNGO_FULLY_CLIPPED)
            return VNGO_NO_ERROR;
    }

    if (trect.clip_to(vprect) == VNGO_FULLY_CLIPPED)
        return VNGO_NO_ERROR;

    return (frect(&trect,rgb_val));
}

VNGError VngoVport3Dfx::clip_frect(VngoRect *rect,dword color, VngoRect *clip)
{
    assert(lock_status);
    return (clip_frect(rect,&(vbuff.pal->get_RGB(color)),clip));
}


VNGError VngoVport3Dfx::line(VngoPoint *p1,VngoPoint *p2, VngoColor24bit *rgb_val)
{
    assert(lock_status);

    assert (p1->x >=0);
    assert (p1->x < vbuff.width);
    assert (p1->y >=0);
    assert (p1->y < vbuff.height);
    assert (p2->x >=0);
    assert (p2->x < vbuff.width);
    assert (p2->y >=0);
    assert (p2->y < vbuff.height);

    VngoColor24bit  tclr;

    if (!rgb_val)
    {
        int t = ((VngoShadePal16*)(vbuff.pal->shd_pal))->get_shaded_index(p1->clr,p1->shade);
        if (vbuff.pal->flags & VNGO_15BIT)
        {
            tclr.r = ((t >> 7) & 0xf8);
            tclr.g = ((t >> 2) & 0xf8);
            tclr.b = ((t << 3) & 0xf8);
        }
        else
        {
            tclr.r = ((t >> 8) & 0xf8);
            tclr.g = ((t >> 2) & 0xfc);
            tclr.b = ((t << 3) & 0xf8);
        }
    }
    else
    {
        tclr = *rgb_val;
    }
    GrVertex    tp1, tp2;
    tp1.x = (float) p1->x;
    tp1.y = (float) p1->y;
//    tp1.ooz = (1.f/(float)((dword)p1->z >> 16)) * 65535.f;
    tp1.ooz = (float)((dword)p1->z >> 16);
    tp1.r = (float) tclr.r;
    tp1.g = (float) tclr.g;
    tp1.b = (float) tclr.b;
    tp1.a = (float) 255.0;

    tp2.x = (float) p2->x;
    tp2.y = (float) p2->y;
//    tp2.ooz = (1.f/(float)((dword)p2->z >> 16)) * 65535.f;
    tp2.ooz = (float)((dword)p2->z >> 16);
    tp2.r = (float) tclr.r;
    tp2.g = (float) tclr.g;
    tp2.b = (float) tclr.b;
    tp2.a = (float) 255.0;

    guColorCombineFunction(GR_COLORCOMBINE_ITRGB);
    grTexCombineFunction( GR_TMU0, GR_TEXTURECOMBINE_ZERO);

    grDrawLine(&tp1,&tp2);
    return VNGO_NO_ERROR;
}


VNGError VngoVport3Dfx::clip_line(VngoPoint *p1,VngoPoint *p2,
                                VngoColor24bit *rgb_val,
                                VngoRect *clip_rect)
{
    assert(lock_status);

    VngoRect    crect(0,0,vbuff.width-1,vbuff.height-1);

    if (clip_rect)
        crect.clip_to(*clip_rect);

    int top = crect.y;
    int bottom = crect.y + crect.dy;
    int left = crect.x;
    int right = crect.x + crect.dx;

    VngoPoint   tp1 = *p1;
    VngoPoint   tp2 = *p2;

    if (p1->x > p2->x)
    {
        tp1 = *p2;
        tp2 = *p1;
    }

    if ((tp2.x < left) || (tp1.x > right))
    {
        return VNGO_NO_ERROR;
    }
    if (tp1.y < tp2.y)
    {
        if ((tp2.y < top) || (tp1.y > bottom))
            return VNGO_NO_ERROR;

        if (tp1.y < top)
        {
            // clip to the top.
            Flx16   dy1 = Flx16(tp2.y - tp1.y);
            Flx16   dy2 = Flx16(tp2.y - top);
            Flx16   dx  = Flx16(tp2.x - tp1.x);
            Flx16   dz  = Flx16(tp2.z - tp1.z,0);

            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx, scale);

            if (vflags & VNGO_ZBUFFER_ACTIVE)
            {
                dz = flx_16mul16(dz,scale);
                tp1.z += dz.flx;
            }
            tp1.y = top;
            tp1.x = tp2.x - (int) dx;
        }
        if (tp2.y > bottom)
        {
            // clip to the bottom.
            Flx16   dy1 = Flx16(tp2.y - tp1.y);
            Flx16   dy2 = Flx16(tp2.y - bottom);
            Flx16   dx  = Flx16(tp2.x - tp1.x);
            Flx16   dz  = Flx16(tp2.z - tp1.z,0);

            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx, scale);

            if (vflags & VNGO_ZBUFFER_ACTIVE)
            {
                dz = flx_16mul16(dz, scale);
                tp2.z += dz.flx;
            }
            tp2.y = bottom;
            tp2.x = tp2.x - (int) dx;
        }
    }
    else
    {
        if ((tp1.y < top) || (tp2.y > bottom))
            return VNGO_NO_ERROR;

        if (tp2.y < top)
        {
            // clip to the top.
            Flx16   dy1 = Flx16(tp1.y - tp2.y);
            Flx16   dy2 = Flx16(tp1.y - top);
            Flx16   dx  = Flx16(tp1.x - tp2.x);
            Flx16   dz  = Flx16(tp1.z - tp2.z,0);

            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx, scale);

            if (vflags & VNGO_ZBUFFER_ACTIVE)
            {
                dz = flx_16mul16(dz, scale);
                tp2.z += dz.flx;
            }
            tp2.y = top;
            tp2.x = tp1.x - (int) dx;
        }
        if (tp1.y > bottom)
        {
            // clip to the bottom.
            Flx16   dy1 = Flx16(tp1.y - tp2.y);
            Flx16   dy2 = Flx16(tp1.y - bottom);
            Flx16   dx  = Flx16(tp1.x - tp2.x);
            Flx16   dz  = Flx16(tp1.z - tp2.z,0);

            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx, scale);

            if (vflags & VNGO_ZBUFFER_ACTIVE)
            {
                dz = flx_16mul16(dz, scale);
                tp1.z += dz.flx;
            }
            tp1.y = bottom;
            tp1.x = tp1.x - (int) dx;
        }
    }

    if (tp1.x < left)
    {
        // clip to the left.
        Flx16   dx1 = Flx16(tp2.x - tp1.x);
        Flx16   dx2 = Flx16(tp2.x - left);
        Flx16   dy  = Flx16(tp2.y - tp1.y);
        Flx16   dz  = Flx16(tp2.z - tp1.z,0);

        Flx16   scale = flx_16div16(dx2,dx1);
        dy = flx_16mul16(dy, scale);

        if (vflags & VNGO_ZBUFFER_ACTIVE)
        {
            dz = flx_16mul16(dz,scale);
            tp1.z += dz.flx;
        }
        tp1.x = left;
        tp1.y = tp2.y - (int) dy;
    }
    if (tp2.x > right)
    {
        // clip to the right.
        Flx16   dx1 = Flx16(tp2.x - tp1.x);
        Flx16   dx2 = Flx16(tp2.x - right);
        Flx16   dy  = Flx16(tp2.y - tp1.y);
        Flx16   dz  = Flx16(tp2.z - tp1.z,0);

        Flx16   scale = flx_16div16(dx2,dx1);
        dy = flx_16mul16(dy, scale);

        if (vflags & VNGO_ZBUFFER_ACTIVE)
        {
            dz = flx_16mul16(dz,scale);
            tp2.z += dz.flx;
        }
        tp2.x = right;
        tp2.y = tp2.y - (int) dy;
    }

    // Now that the line has been clipped, do a second
    // trivial rejection test.

    if ((tp1.x >= right) || (tp2.x < left)
        || ((tp1.y >= bottom) && (tp2.y >= bottom))
        || ((tp1.y < top) && (tp2.y < top)))
    {
        return VNGO_NO_ERROR;
    }

    line(&tp1,&tp2,rgb_val);

    return VNGO_NO_ERROR;
}

VNGError VngoVport3Dfx::gline(VngoPoint *p1,VngoPoint *p2)
{
    assert(lock_status);

    assert (p1->x >=0);
    assert (p1->x < vbuff.width);
    assert (p1->y >=0);
    assert (p1->y < vbuff.height);
    assert (p2->x >=0);
    assert (p2->x < vbuff.width);
    assert (p2->y >=0);
    assert (p2->y < vbuff.height);

    VngoColor24bit  tclr,tclr2;

    int t = ((VngoShadePal16*)(vbuff.pal->shd_pal))->get_shaded_index(p1->clr,p1->shade);
    int t2 = ((VngoShadePal16*)(vbuff.pal->shd_pal))->get_shaded_index(p2->clr,p2->shade);
    if (vbuff.pal->flags & VNGO_15BIT)
    {
        tclr.r = ((t >> 7) & 0xf8);
        tclr.g = ((t >> 2) & 0xf8);
        tclr.b = ((t << 3) & 0xf8);

        tclr2.r = ((t2 >> 7) & 0xf8);
        tclr2.g = ((t2 >> 2) & 0xf8);
        tclr2.b = ((t2 << 3) & 0xf8);

    }
    else
    {
        tclr.r = ((t >> 8) & 0xf8);
        tclr.g = ((t >> 2) & 0xfc);
        tclr.b = ((t << 3) & 0xf8);

        tclr2.r = ((t2 >> 8) & 0xf8);
        tclr2.g = ((t2 >> 2) & 0xfc);
        tclr2.b = ((t2 << 3) & 0xf8);
    }

//    tclr = vbuff.pal->get_RGB(((VngoShadePal8*)(vbuff.pal->shd_pal))->get_shaded_index(p1->clr,p1->shade));
//    tclr2 = vbuff.pal->get_RGB(((VngoShadePal8*)(vbuff.pal->shd_pal))->get_shaded_index(p2->clr,p2->shade));

    GrVertex    tp1, tp2;
    tp1.x = (float) p1->x;
    tp1.y = (float) p1->y;
//    tp1.ooz = (1.f/(float)((dword)p1->z >> 16)) * 65535.f;
    tp1.ooz = (float)((dword)p1->z >> 16);
    tp1.r = (float) tclr.r;
    tp1.g = (float) tclr.g;
    tp1.b = (float) tclr.b;
    tp1.a = (float) 255.0;

    tp2.x = (float) p2->x;
    tp2.y = (float) p2->y;
//    tp2.ooz = (1.f/(float)((dword)p2->z >> 16)) * 65535.f;
    tp2.ooz = (float)((dword)p2->z >> 16);
    tp2.r = (float) tclr2.r;
    tp2.g = (float) tclr2.g;
    tp2.b = (float) tclr2.b;
    tp2.a = (float) 255.0;

    guColorCombineFunction(GR_COLORCOMBINE_ITRGB);
    grTexCombineFunction( GR_TMU0, GR_TEXTURECOMBINE_ZERO);

    grDrawLine(&tp1,&tp2);

    return VNGO_NO_ERROR;
}

VNGError VngoVport3Dfx::clip_gline(VngoPoint *p1, VngoPoint *p2, VngoRect *clip_rect)
{
    assert(lock_status);

    VngoRect    crect(0/*vbuff.left*/,0/*vbuff.top*/,vbuff.width-1,vbuff.height-1);

    if (clip_rect)
        crect.clip_to(*clip_rect);

    int top = crect.y;
    int bottom = crect.y + crect.dy;
    int left = crect.x;
    int right = crect.x + crect.dx;

    VngoPoint   tp1 = *p1;
    VngoPoint   tp2 = *p2;

    if (p1->x > p2->x)
    {
        tp1 = *p2;
        tp2 = *p1;
    }

    if ((tp2.x < left) || (tp1.x > right))
    {
        return VNGO_NO_ERROR;
    }
    if (tp1.y < tp2.y)
    {
        if ((tp2.y < top) || (tp1.y > bottom))
            return VNGO_NO_ERROR;

        if (tp1.y < top)
        {
            // clip to the top.
            Flx16   dy1 = Flx16(tp2.y - tp1.y);
            Flx16   dy2 = Flx16(tp2.y - top);
            Flx16   dx  = Flx16(tp2.x - tp1.x);
            Flx16   dz  = Flx16(tp2.z - tp1.z,0);
            Flx16   ds  = Flx16(tp2.shade - tp1.shade);

            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx,scale);
            ds = flx_16mul16(ds,scale);

            if (vflags & VNGO_ZBUFFER_ACTIVE)
            {
                dz = flx_16mul16(dz,scale);
                tp1.z += dz.flx;
            }


            tp1.y = top;
            tp1.x = tp2.x - (int) dx;
            tp1.shade = tp2.shade - (int)ds;
        }
        if (tp2.y > bottom)
        {
            // clip to the bottom.
            Flx16   dy1 = Flx16(tp2.y - tp1.y);
            Flx16   dy2 = Flx16(tp2.y - bottom);
            Flx16   dx  = Flx16(tp2.x - tp1.x);
            Flx16   ds  = Flx16(tp2.shade - tp2.shade);
            Flx16   dz  = Flx16(tp2.z - tp1.z,0);

            Flx16 scale = flx_16div16(dy2,dy1);

            dx = flx_16mul16(dx,scale);
            ds = flx_16mul16(ds,scale);

            if (vflags & VNGO_ZBUFFER_ACTIVE)
            {
                dz = flx_16mul16(dz,scale);
                tp2.z = tp2.z + dz.flx;
            }

            tp2.y = bottom;
            tp2.x = tp2.x - (int) dx;
            tp2.shade = tp2.shade - (int) ds;
        }
    }
    else
    {
        if ((tp1.y < top) || (tp2.y > bottom))
            return VNGO_NO_ERROR;

        if (tp2.y < top)
        {
            // clip to the top.
            Flx16   dy1 = Flx16(tp1.y - tp2.y);
            Flx16   dy2 = Flx16(tp1.y - top);
            Flx16   dx  = Flx16(tp1.x - tp2.x);
            Flx16   ds  = Flx16(tp1.shade - tp2.shade);
            Flx16   dz  = Flx16(tp1.z - tp2.z,0);

            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx,scale);
            ds = flx_16mul16(ds,scale);

            if (vflags & VNGO_ZBUFFER_ACTIVE)
            {
                dz = flx_16mul16(dz,scale);
                tp2.z += dz.flx;
            }

            tp2.y = top;
            tp2.x = tp1.x - (int) dx;
            tp2.shade = tp1.shade - (int) ds;
        }
        if (tp1.y > bottom)
        {
            // clip to the bottom.
            Flx16   dy1 = Flx16(tp1.y - tp2.y);
            Flx16   dy2 = Flx16(tp1.y - bottom);
            Flx16   dx  = Flx16(tp1.x - tp2.x);
            Flx16   ds  = Flx16(tp1.shade - tp2.shade);
            Flx16   dz  = Flx16(tp1.z - tp2.z,0);

            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx,scale);
            ds = flx_16mul16(ds,scale);

            if (vflags & VNGO_ZBUFFER_ACTIVE)
            {
                dz = flx_16mul16(dz,scale);
                tp1.z += dz.flx;
            }
            tp1.y = bottom;
            tp1.x = tp1.x - (int) dx;
            tp1.shade = tp1.shade - (int) ds;
        }
    }

    if (tp1.x < left)
    {
        // clip to the left.
        Flx16   dx1 = Flx16(tp2.x - tp1.x);
        Flx16   dx2 = Flx16(tp2.x - left);
        Flx16   dy  = Flx16(tp2.y - tp1.y);
        Flx16   ds  = Flx16(tp2.shade - tp1.shade);
        Flx16   dz  = Flx16(tp2.z - tp1.z,0);

        Flx16   scale = flx_16div16(dx2,dx1);
        dy = flx_16mul16(dy, scale);
        ds = flx_16mul16(ds, scale);

        if (vflags & VNGO_ZBUFFER_ACTIVE)
        {
            dz = flx_16mul16(dz, scale);
            tp1.z += dz.flx;
        }
        tp1.x = left;
        tp1.y = tp2.y - (int) dy;
        tp1.shade = tp2.shade - (int) ds;
    }
    if (tp2.x > right)
    {
        // clip to the right.
        Flx16   dx1 = Flx16(tp2.x - tp1.x);
        Flx16   dx2 = Flx16(tp2.x - right);
        Flx16   dy  = Flx16(tp2.y - tp1.y);
        Flx16   ds  = Flx16(tp2.shade - tp1.shade);
        Flx16   dz  = Flx16(tp2.z - tp1.z,0);

        Flx16   scale = flx_16div16(dx2,dx1);
        dy = flx_16mul16(dy, scale);
        ds = flx_16mul16(ds, scale);

        if (vflags & VNGO_ZBUFFER_ACTIVE)
        {
            dz = flx_16mul16(dz, scale);
            tp2.z += dz.flx;
        }
        tp2.x = right;
        tp2.y = tp2.y - (int) dy;
        tp2.shade = tp2.shade - (int) ds;
    }


    // Now that the line has been clipped, do a second
    // trivial rejection test.

    if ((tp1.x >= right) || (tp2.x < left)
        || ((tp1.y >= bottom) && (tp2.y >= bottom))
        || ((tp1.y < top) && (tp2.y < top)))
    {
        return VNGO_NO_ERROR;
    }

    return (gline(&tp1,&tp2));
}


VNGError VngoVport3Dfx::gline_persp(VngoPoint *p1,VngoPoint *p2)
{
    assert(lock_status);
    gline(p1,p2);
    return VNGO_NOT_SUPPORTED;
}


VNGError VngoVport3Dfx::clip_gline_persp(VngoPoint *p1,VngoPoint *p2,VngoRect *clip_rect)
{
    assert(lock_status);
    clip_gline(p1,p2,clip_rect);
    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVport3Dfx::image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags)
{
    assert(lock_status);
    return VNGO_NOT_SUPPORTED;

}


VNGError VngoVport3Dfx::zblit_mono (VngoRect *dest_rect,VngoZMap *img,dword fgcol,dword bgcol)
{
    assert(lock_status);
    return VNGO_NOT_SUPPORTED;

    //
    // It appears that this may be used the same way if we setup the
    // write pointer to the Z-Buffer correctly.
    //

    long    w,h,x,y;

    w = MIN(img->zmap.width,dest_rect->dx);
    h = MIN(img->zmap.height,dest_rect->dy);

    long    pitch;
    long    xskip,yskip,t2;
    byte    *ptr;
    dword   t;

    if (!(img->zmap.flags & VNGO_TEXTURE_MONO))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    xskip = yskip = 0;

    if ((dest_rect->x < vbuff.width) && (dest_rect->y < vbuff.height) &&
        (dest_rect->x + w >= 0) && (dest_rect->y + h >= 0))
    {
        pitch = img->zmap.width >> 3;
        if (img->zmap.width & 0x7)
        {
            ++pitch;
        }

        // Clip to negative conditions.
        if (dest_rect->y >=0)
        {   // Starting Y is on the screen.
            y = dest_rect->y;
        }
        else
        {   // Starting Y is off the screen (negative).
            t2 = h + (dest_rect->y); // Since dest_rect->y is always negative.
            yskip = h - t2;
            h = t2;
            y = 0;
        }

        t = vbuff.ytable[y];

        if (dest_rect->x >= 0)
        {   // Starting X is on the screen.
            x = dest_rect->x;
        }
        else
        {   // Starting X is off the screen (negative).
            t2 = w + (dest_rect->x); // Since dest_rect->x is always negative.
            xskip = w - t2;
            w = t2;
            x = 0;
        }

        // Clip to positive conditions.
        if ((y + h) > vbuff.height)
        {
            h = vbuff.height - y;
        }
        if ((x + w) > vbuff.width)
        {
            w = vbuff.width - x;
        }

        t += x;

        if ((dest_rect->x + w) > vbuff.width)
        {   // Ending X is off the screen.
            w = w - (dest_rect->x - vbuff.width);
        }
        if ((dest_rect->y + h) > vbuff.height)
        {   // Ending Y is off the screen.
            h = h - (dest_rect->y - vbuff.height);
        }

        ptr = (byte*)img->zmap.tex;
        ptr += (yskip * pitch);
        t = (t << 1) + (dword)vbuff.zbuff_ptr;
        while (h > 0)
        {
            vngo_zlinemono16 ((word *)t,ptr,w,xskip,fgcol,bgcol);
            ptr += pitch;
            t += vbuff.zpitch;
            --h;
        }

    }
    return VNGO_NO_ERROR;
}


VNGError VngoVport3Dfx::image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword fgcol,dword bgcol)
{
    assert(lock_status);
    return VNGO_NOT_SUPPORTED;

    //
    // This may work the same way, we need to see.
    //
    long    w,h,x,y;

    if (!(img->flags & VNGO_TEXTURE_MONO) || 1)
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    w = MIN(img->width,dest_rect->dx);
    h = MIN(img->height,dest_rect->dy);

    long    pitch;
    long    xskip,yskip,t2;
    byte    *ptr;
    dword   t;

    xskip = yskip = 0;

    if ((dest_rect->x < vbuff.width) && (dest_rect->y < vbuff.height) &&
        (dest_rect->x + w >= 0) && (dest_rect->y + h >= 0))
    {
        pitch = img->width >> 3;
        if (img->width & 0x7)
        {
            ++pitch;
        }

        // Clip to negative conditions.
        if (dest_rect->y >=0)
        {   // Starting Y is on the screen.
            y = dest_rect->y;
        }
        else
        {   // Starting Y is off the screen (negative).
            t2 = h + (dest_rect->y); // Since dest_rect->y is always negative.
            yskip = h - t2;
            h = t2;
            y = 0;
        }

        t = vbuff.ytable[y];

        if (dest_rect->x >= 0)
        {   // Starting X is on the screen.
            x = dest_rect->x;
        }
        else
        {   // Starting X is off the screen (negative).
            t2 = w + (dest_rect->x); // Since dest_rect->x is always negative.
            xskip = w - t2;
            w = t2;
            x = 0;
        }

        // Clip to positive conditions.
        if ((y + h) > vbuff.height)
        {
            h = vbuff.height - y;
        }
        if ((x + w) > vbuff.width)
        {
            w = vbuff.width - x;
        }

        t += x;

        if ((dest_rect->x + w) > vbuff.width)
        {   // Ending X is off the screen.
            w = w - (dest_rect->x - vbuff.width);
        }
        if ((dest_rect->y + h) > vbuff.height)
        {   // Ending Y is off the screen.
            h = h - (dest_rect->y - vbuff.height);
        }

        ptr = (byte*)img->tex;
        ptr += (yskip * pitch);
        t += (dword)vbuff.scrn_ptr;
        while (h > 0)
        {
            vngo_ilinemono8((byte *)t,ptr,w,xskip,fgcol,bgcol);
            ptr += pitch;
            t += vbuff.pitch;
            --h;
        }

    }
    return VNGO_NO_ERROR;
}


VNGError VngoVport3Dfx::vpcopy(int destx,int desty,VngoVport *vp)
{
    assert(lock_status);
    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVport3Dfx::poly (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    GrVertex tpts[VNGO_MAX_VERTCOUNT];
    for (int i = 0; i < count; i++)
    {
        VngoColor24bit  tclr;
        int t = ((VngoShadePal16*)(vbuff.pal->shd_pal))->get_shaded_index(pts[i].clr,pts[i].shade);
        if (vbuff.pal->flags & VNGO_15BIT)
        {
            tclr.r = ((t >> 7) & 0xf8);
            tclr.g = ((t >> 2) & 0xf8);
            tclr.b = ((t << 3) & 0xf8);
        }
        else
        {
            tclr.r = ((t >> 8) & 0xf8);
            tclr.g = ((t >> 2) & 0xfc);
            tclr.b = ((t << 3) & 0xf8);
        }

//        VngoColor24bit tclr = vbuff.pal->get_RGB(((VngoShadePal8*)(vbuff.pal->shd_pal))->get_shaded_index(pts[i].clr,pts[i].shade));
        tpts[i].x = (float)pts[i].x;
        tpts[i].y = (float)pts[i].y;
//        tpts[i].ooz = (1.f/(float)((dword)pts[i].z >> 16)) * 65535.f;
        tpts[i].ooz = (float)((dword)pts[i].z >> 16);
        tpts[i].r = (float)tclr.r;
        tpts[i].g = (float)tclr.g;
        tpts[i].b = (float)tclr.b;
        tpts[i].a = (float)255.0;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    guColorCombineFunction(GR_COLORCOMBINE_ITRGB);
//    grTexCombineFunction( GR_TMU0, GR_TEXTURECOMBINE_ZERO);

    if (count > 3)
    {
        // if there are more than three vertices, break it into a series
        // of triangles.
        for (int i=1;i < count-1;i++)
        {
            GrVertex tpts2[3];
            tpts2[0] = tpts[0];
            tpts2[1] = tpts[i];
            tpts2[2] = tpts[i+1];
            grDrawTriangle(&tpts[0],&tpts[1],&tpts[2]);
        }
    }
    return VNGO_NO_ERROR;
}

VNGError VngoVport3Dfx::gpoly (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    GrVertex tpts[VNGO_MAX_VERTCOUNT];
    for (int i = 0; i < count; i++)
    {
        VngoColor24bit  tclr;
        int t = ((VngoShadePal16*)(vbuff.pal->shd_pal))->get_shaded_index(pts[i].clr,pts[i].shade);
        if (vbuff.pal->flags & VNGO_15BIT)
        {
            tclr.r = ((t >> 7) & 0xf8);
            tclr.g = ((t >> 2) & 0xf8);
            tclr.b = ((t << 3) & 0xf8);
        }
        else
        {
            tclr.r = ((t >> 8) & 0xf8);
            tclr.g = ((t >> 2) & 0xfc);
            tclr.b = ((t << 3) & 0xf8);
        }
//        VngoColor24bit tclr = vbuff.pal->get_RGB(((VngoShadePal8*)(vbuff.pal->shd_pal))->get_shaded_index(pts[i].clr,pts[i].shade));
        tpts[i].x = (float)pts[i].x;
        tpts[i].y = (float)pts[i].y;
//        tpts[i].ooz = (1.f/(float)((dword)pts[i].z >> 16)) * 65535.f;
        tpts[i].ooz = (float)((dword)pts[i].z >> 16);
        tpts[i].r = (float)tclr.r;
        tpts[i].g = (float)tclr.g;
        tpts[i].b = (float)tclr.b;
        tpts[i].a = (float)255.0;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }


    guColorCombineFunction(GR_COLORCOMBINE_ITRGB);
    grTexCombineFunction( GR_TMU0, GR_TEXTURECOMBINE_ZERO);

    if (count > 3)
    {
        // if there are more than three vertices, break it into a series
        // of triangles.
        for (int i=1;i < count-1;i++)
        {
            GrVertex tpts2[3];
            tpts2[0] = tpts[0];
            tpts2[1] = tpts[i];
            tpts2[2] = tpts[i+1];
            grDrawTriangle(&tpts2[0],&tpts2[1],&tpts2[2]);
        }
    }
    else
    {
        grDrawTriangle(&tpts[0],&tpts[1],&tpts[2]);
    }
    return VNGO_NO_ERROR;
}

VNGError VngoVport3Dfx::gpoly_persp (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    gpoly(count,pts);
    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVport3Dfx::tpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);
    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVport3Dfx::tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);
    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVport3Dfx::gtpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);
    return VNGO_NOT_SUPPORTED;
}


VNGError VngoVport3Dfx::gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);
    return VNGO_NOT_SUPPORTED;
}



//°±² End of module - vngvvp8.cpp ²±°
