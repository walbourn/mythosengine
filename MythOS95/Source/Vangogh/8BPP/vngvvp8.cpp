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
#include "vangogh.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MIN(a,b)  ((a) < (b)) ? (a) : (b)


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


VngoVVport8::VngoVVport8 (long width,long height,long org_x,long org_y,VngoPal *my_pal,dword flags)
{
    init_status = init (width,height,org_x,org_y,my_pal,flags);
}

VNGError VngoVVport8::init (long width,long height,long org_x,long org_y,VngoPal *my_pal,dword flags)
{
    persp_pixcount = VNGO_PERSP_PRECISION;
    vbuff.width = width;
    vbuff.pitch = width;
    vbuff.height = height;
    vbuff.zpitch = vbuff.pitch << 1;
    vflags = flags;
    vflags |= VNGO_PAL_MAPPED_DEV;
    size_in_bytes = width * height;
    vbuff.zbuff_ptr = NULL;

    vbuff.scrn_ptr = (byte *)ivory_alloc (size_in_bytes);

    if (vflags & VNGO_ZBUFFER_DEV)
    {
        vzdepth_in_bits = 16;
        int z_size_shift = vzdepth_in_bits >> 4;
        vbuff.zbuff_ptr = (word *)ivory_alloc(size_in_bytes << z_size_shift);
        if (!vbuff.zbuff_ptr)
        {
            return (VNGO_MEMALLOC_ERROR);
        }
        assert(vbuff.zbuff_ptr != 0);
        vflags |= VNGO_ZBUFFER_ACTIVE;
    }

    // allocate all tables.

    vbuff.ytable = (dword *)ivory_alloc(height * sizeof(dword));
    if (!vbuff.ytable)
    {
        if (vflags & VNGO_ZBUFFER_DEV)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
        }
        return (VNGO_MEMALLOC_ERROR);
    }
    if (vflags & VNGO_ZBUFFER_DEV)
    {
        vbuff.ztable = (dword *)ivory_alloc(height * sizeof(dword));
        if (!vbuff.ztable)
        {
            if (vflags & VNGO_ZBUFFER_DEV)
            {
                ivory_free((void **)&(vbuff.zbuff_ptr));
            }
            ivory_free((void **)&(vbuff.ytable));
            return (VNGO_MEMALLOC_ERROR);
        }
    }
    long max_dem = width;
    if (height > width)
        max_dem = height;

    vbuff.edge1 = (VngoPoint2*)ivory_alloc(max_dem * sizeof(VngoPoint2));
    if (vbuff.edge1 == NULL)
    {
        if(vflags & VNGO_ZBUFFER_DEV)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
            ivory_free((void **)&(vbuff.ztable));
        }
        ivory_free((void**)&(vbuff.ytable));
        return (VNGO_MEMALLOC_ERROR);
    }

    vbuff.edge2 = (VngoPoint2*)ivory_alloc(max_dem * sizeof(VngoPoint2));
    if (vbuff.edge2 == NULL)
    {
        if(vflags & VNGO_ZBUFFER_DEV)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
            ivory_free((void **)&(vbuff.ztable));
        }
        ivory_free((void**)&(vbuff.ytable));
        ivory_free((void**)&(vbuff.edge1));
        return (VNGO_MEMALLOC_ERROR);
    }


    if (my_pal)
    {
        vbuff.pal = my_pal;
    }
    else
    {
        // here you will normaly build a new default palette.
        vbuff.pal = NULL;
    }

    // Fill all tables.

    vbuff.ytable[0] = 0;
    if (vflags & VNGO_ZBUFFER_DEV)
        vbuff.ztable[0] = 0;

    for (int i=1; i < vbuff.height; i++)
    {
        vbuff.ytable[i] = vbuff.ytable[i-1] + vbuff.pitch;
        if (vflags & VNGO_ZBUFFER_DEV)
            vbuff.ztable[i] = vbuff.ztable[i-1] + vbuff.zpitch;
    }

    if (!(vflags & VNGO_INIT_NO_RESET))
    {
        lock();
        reset();
        unlock();
    }
    return (VNGO_NO_ERROR);
}

VngoVVport8::~VngoVVport8()
{
    if (vbuff.scrn_ptr)
    {
        ivory_free((void **)&(vbuff.scrn_ptr));
    }
    if (vflags & VNGO_ZBUFFER_DEV)
    {
        if (vbuff.zbuff_ptr)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
        }
    }
    if (vbuff.ytable)
    {
        ivory_free((void **)&(vbuff.ytable));
    }
    if (vbuff.ztable && vflags & VNGO_ZBUFFER_DEV)
    {
        ivory_free((void **)&(vbuff.ztable));
    }
    if (vbuff.edge1)
    {
        ivory_free((void **)&vbuff.edge1);
    }
    if (vbuff.edge2)
    {
        ivory_free((void **)&vbuff.edge2);
    }
}

void VngoVVport8::reset(dword c,dword farz)
{
    VngoRect    trect;
    trect.x = trect.y = 0;
    trect.dx = vbuff.width;
    trect.dy = vbuff.height;

    assert(lock_status);

    dword           t;


    if (!(vflags & VNGO_NOCLEAR_VBUFFER))
    {
        if (zmap)
        {
            assert (zmap->zmap.flags & VNGO_TEXTURE_ZMAP);
            assert (zmap->zmap.flags & VNGO_TEXTURE_MONO);
            image_trans_mono (&trect,&zmap->zmap ,c,zmap->color);
        }
        else
        {
            frect(&trect,c);
        }
    }

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        if (vzdepth_in_bits == 32)
        {
            return; // no longer supported.
        }
        else if (vzdepth_in_bits == 16)
        {

            t = farz & 0xffff0000;
            t |= ((farz & 0xffff0000) >> 16);

            if (zmap)
            {
                assert (zmap->zmap.flags & VNGO_TEXTURE_ZMAP);
                assert (zmap->zmap.flags & VNGO_TEXTURE_MONO);
                zblit_mono (&trect,zmap,t,zmap->depth);
            }
            else
                zbuff_reset_rect16(&vbuff,&trect,t);
        }
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the start of the draw function block of the VngoVVport8 class.   ³
// all fucntions in this class draw to a 8 bit device regardless of the size³
// of the input color information.                                          ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VNGError VngoVVport8::clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val, VngoRect *clip_rect)
{
    VngoRect vprect(0,0,vbuff.width,vbuff.height);

    if (clip_rect)
    {
        vprect.clip_to(*clip_rect);
    }
    if (vprect.point_in(*pt))
        return pixel(pt,rgb_val);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::pixel(VngoPoint *pt, VngoColor24bit *rgb_val)
{
    assert(lock_status);

    assert (pt->x < vbuff.width);
    assert (pt->x >= 0);
    assert (pt->y < vbuff.height);
    assert (pt->y >= 0);
    if (!rgb_val)
    {
        if (vflags & VNGO_ZBUFFER_ACTIVE)
        {
            vngo_zpixel8(&vbuff,pt);
        }
        else
        {
            vngo_pixel8(&vbuff,pt);
        }
    }
    else
    {
        VngoPoint   tpt = *pt;
        tpt.clr = vbuff.pal->get_index(*rgb_val);
        tpt.shade = vbuff.pal->shd_pal->mid_point - 1;

        if (vflags & VNGO_ZBUFFER_ACTIVE)
        {
            vngo_zpixel8(&vbuff,&tpt);
        }
        else
        {
            vngo_pixel8(&vbuff,&tpt);
        }
    }
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::clip_pixel (VngoPoint2 *pt, VngoColor24bit *rgb_val, VngoRect *clip_rect)
{
    VngoRect vprect(0,0,vbuff.width,vbuff.height);

    VngoPoint   tpt;
    tpt.x = (pt->x + 0x8000) >> 16;
    tpt.x = (pt->y + 0x8000) >> 16;
    tpt.z = pt->z;
    tpt.clr = pt->clr;
    tpt.shade = pt->shade;

    if (clip_rect)
    {
        vprect.clip_to(*clip_rect);
    }
    if (vprect.point_in(tpt))
        return pixel(&tpt,rgb_val);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::pixel(VngoPoint2 *pt, VngoColor24bit *rgb_val)
{
    VngoPoint   tpt;
    tpt.x = (pt->x + 0x8000) >> 16;
    tpt.x = (pt->y + 0x8000) >> 16;
    tpt.z = pt->z;
    tpt.clr = pt->clr;
    tpt.shade = pt->shade;

    return pixel(&tpt,rgb_val);
}

dword VngoVVport8::read_pixel(int x, int y, VngoPoint *dest)
{
    assert(lock_status);

    dest->x = x;
    dest->y = y;
    dest->clr = vbuff.scrn_ptr[vbuff.ytable[y] + x];
    dest->shade = vbuff.pal->shd_pal->mid_point - 1;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dest->z = vbuff.zbuff_ptr[vbuff.ztable[y] + x];
    }
    return dest->clr;
}


dword VngoVVport8::read_pixel(VngoPoint *pt, VngoPoint *dest)
{
    assert(lock_status);

    return read_pixel(pt->x,pt->y,dest);
}

VNGError VngoVVport8::frect(VngoRect *rect,VngoColor24bit *rgb_val)
{
    assert(lock_status);

    vngo_rect8 (&vbuff,rect,vbuff.pal->get_index(*rgb_val));
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::frect(VngoRect *rect,dword color)
{
    assert(lock_status);

    vngo_rect8(&vbuff,rect,color);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::clip_frect(VngoRect *rect,VngoColor24bit *rgb_val, VngoRect *clip)
{
    assert(lock_status);

    return clip_frect(rect,vbuff.pal->get_index(*rgb_val),clip);
}

VNGError VngoVVport8::clip_frect(VngoRect *rect,dword color, VngoRect *clip)
{
    assert(lock_status);

    VngoRect vprect(0,0,vbuff.width,vbuff.height);
    VngoRect trect = *rect;
    if (clip)
    {
        if (trect.clip_to(*clip) == VNGO_FULLY_CLIPPED)
            return VNGO_NO_ERROR;
    }

    if (trect.clip_to(vprect) == VNGO_FULLY_CLIPPED)
        return VNGO_NO_ERROR;

    vngo_rect8(&vbuff,&trect,color);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::line(VngoPoint *p1,VngoPoint *p2, VngoColor24bit *rgb_val)
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


    VngoPoint   tp1 = *p1;

    if (rgb_val)
    {
        tp1.clr = vbuff.pal->get_index(*rgb_val);
        tp1.shade = vbuff.pal->shd_pal->mid_point - 1;
    }

    vngo_line(this,&tp1,p2);

    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::line(VngoPoint2 *p1,VngoPoint2 *p2, VngoColor24bit *rgb_val)
{
    VngoPoint tp1,tp2;

    tp1.x = (p1->x + 0x8000) >> 16;
    tp1.y = (p1->y + 0x8000) >> 16;
    tp1.z = p1->z;
    tp1.clr = p1->clr;
    tp1.shade = p1->clr;

    tp2.x = (p2->x + 0x8000) >> 16;
    tp2.y = (p2->y + 0x8000) >> 16;
    tp2.z = p2->z;
    tp2.clr = p2->clr;
    tp2.shade = p2->clr;

    return line(&tp1,&tp2,rgb_val);
}

VNGError VngoVVport8::clip_line(VngoPoint2 *p1,VngoPoint2 *p2,
                                VngoColor24bit *rgb_val,
                                VngoRect *clip_rect)
{
    VngoPoint tp1,tp2;

    tp1.x = (p1->x + 0x8000) >> 16;
    tp1.y = (p1->y + 0x8000) >> 16;
    tp1.z = p1->z;
    tp1.clr = p1->clr;
    tp1.shade = p1->clr;

    tp2.x = (p2->x + 0x8000) >> 16;
    tp2.y = (p2->y + 0x8000) >> 16;
    tp2.z = p2->z;
    tp2.clr = p2->clr;
    tp2.shade = p2->clr;

    return clip_line(&tp1,&tp2,rgb_val,clip_rect);
}



VNGError VngoVVport8::clip_line(VngoPoint *p1,VngoPoint *p2,
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

    if (rgb_val)
    {
        tp1.clr = vbuff.pal->get_index(*rgb_val);
        tp2.clr = tp1.clr;
        tp1.shade = vbuff.pal->shd_pal->mid_point - 1;
        tp2.shade = tp1.shade;
    }

    vngo_line(this,&tp1,&tp2);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gline(VngoPoint *p1,VngoPoint *p2)
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



    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        vngo_gline(this,p1,p2);
    }
    else
    {
        vngo_gline(this,p1,p2);
    }
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gline(VngoPoint2 *p1,VngoPoint2 *p2)
{
    VngoPoint tp1,tp2;

    tp1.x = (p1->x + 0x8000) >> 16;
    tp1.y = (p1->y + 0x8000) >> 16;
    tp1.z = p1->z;
    tp1.clr = p1->clr;
    tp1.shade = p1->clr;

    tp2.x = (p2->x + 0x8000) >> 16;
    tp2.y = (p2->y + 0x8000) >> 16;
    tp2.z = p2->z;
    tp2.clr = p2->clr;
    tp2.shade = p2->clr;

    return gline(&tp1,&tp2);
}

VNGError VngoVVport8::clip_gline(VngoPoint2 *p1,VngoPoint2 *p2,
                                VngoRect *clip_rect)
{
    VngoPoint tp1,tp2;

    tp1.x = (p1->x + 0x8000) >> 16;
    tp1.y = (p1->y + 0x8000) >> 16;
    tp1.z = p1->z;
    tp1.clr = p1->clr;
    tp1.shade = p1->clr;

    tp2.x = (p2->x + 0x8000) >> 16;
    tp2.y = (p2->y + 0x8000) >> 16;
    tp2.z = p2->z;
    tp2.clr = p2->clr;
    tp2.shade = p2->clr;

    return clip_gline(&tp1,&tp2,clip_rect);
}

VNGError VngoVVport8::clip_gline(VngoPoint *p1, VngoPoint *p2, VngoRect *clip_rect)
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

    vngo_gline(this,&tp1,&tp2);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::gline_persp(VngoPoint *p1,VngoPoint *p2)
{
    assert(lock_status);
    gline(p1,p2);
    return VNGO_NOT_SUPPORTED;
}


VNGError VngoVVport8::clip_gline_persp(VngoPoint *p1,VngoPoint *p2,VngoRect *clip_rect)
{
    assert(lock_status);
    clip_gline(p1,p2,clip_rect);
    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVVport8::gline_persp(VngoPoint2 *p1,VngoPoint2 *p2)
{
    VngoPoint tp1,tp2;

    tp1.x = (p1->x + 0x8000) >> 16;
    tp1.y = (p1->y + 0x8000) >> 16;
    tp1.z = p1->z;
    tp1.clr = p1->clr;
    tp1.shade = p1->clr;

    tp2.x = (p2->x + 0x8000) >> 16;
    tp2.y = (p2->y + 0x8000) >> 16;
    tp2.z = p2->z;
    tp2.clr = p2->clr;
    tp2.shade = p2->clr;

    return gline_persp(&tp1,&tp2);
}

VNGError VngoVVport8::clip_gline_persp(VngoPoint2 *p1,VngoPoint2 *p2,VngoRect *clip_rect)
{
    VngoPoint tp1,tp2;

    tp1.x = (p1->x + 0x8000) >> 16;
    tp1.y = (p1->y + 0x8000) >> 16;
    tp1.z = p1->z;
    tp1.clr = p1->clr;
    tp1.shade = p1->clr;

    tp2.x = (p2->x + 0x8000) >> 16;
    tp2.y = (p2->y + 0x8000) >> 16;
    tp2.z = p2->z;
    tp2.clr = p2->clr;
    tp2.shade = p2->clr;

    return clip_gline_persp(&tp1,&tp2,clip_rect);
}


//°±² End of module - vngvvp8.cpp ²±°
