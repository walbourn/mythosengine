//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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
    vbuff.left = org_x;
    vbuff.top = org_y;
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

    vbuff.invert = vngo_get_invert();

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
    VngoRect vprect(vbuff.left,vbuff.top,vbuff.width,vbuff.height);

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

    VngoRect vprect(vbuff.left,vbuff.top,vbuff.width,vbuff.height);
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
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        vngo_line(this,&tp1,p2);
    }
    else
    {
        vngo_line8(&vbuff,&tp1,p2);
    }
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::clip_line(VngoPoint *p1,VngoPoint *p2, 
                                VngoColor24bit *rgb_val,
                                VngoRect *clip_rect)
{
    assert(lock_status);

    VngoRect    crect(vbuff.left,vbuff.top,vbuff.width-1,vbuff.height-1);

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
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        vngo_line(this,&tp1,&tp2);
    }
    else
    {
        vngo_line8(&vbuff,&tp1,&tp2);
    }
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

VNGError VngoVVport8::clip_gline(VngoPoint *p1, VngoPoint *p2, VngoRect *clip_rect)
{
    assert(lock_status);

    VngoRect    crect(vbuff.left,vbuff.top,vbuff.width-1,vbuff.height-1);

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

VNGError VngoVVport8::image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags)
{
    assert(lock_status);

    long        w,h;
    VngoRect    dr;

    if (!(img->flags & VNGO_TEXTURE_8BIT))
    {
        // For now, we only support 8bpp textures here.
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    w = MIN(img->width,dest_rect->dx);
    h = MIN(img->height,dest_rect->dy);

    dr.x = dest_rect->x;
    dr.y = dest_rect->y;
    dr.dx = w;
    dr.dy = h;

    if (((dest_rect->x + w) < vbuff.width) &&
        ((dest_rect->y + h) < vbuff.height) &&
        (dest_rect->x >= 0) && (dest_rect->y >= 0))
    {
        vngo_itrans8 (&vbuff,&dr,img,flags);
    }
    else
    {
        if ((dest_rect->x < vbuff.width) && (dest_rect->y < vbuff.height) &&
            (dest_rect->x + w >= 0) && (dest_rect->y + h >= 0))
        {
            char    *lptr,*tptr;
            dword   t;
            dword   tx=0,ty=0;
            long    xcount,ycount;

            if (dest_rect->y >= 0)
            {
                t = vbuff.ytable[dest_rect->y];
                if ((dest_rect->y + h) < vbuff.height)
                    ycount = h;
                else
                    ycount = vbuff.height - dest_rect->y;
            }
            else        // starting Y is negative in this case.
            {
                ty = -dest_rect->y;
                t = vbuff.ytable[0];
                if ((dest_rect->y + h) > vbuff.height)
                {
                    ycount = vbuff.height;
                }
                else
                {
                    ycount = h + dest_rect->y;  
                }

            }
            t += (dword)(vbuff.scrn_ptr);

            // At this point t = the pointer to the begining of the first
            // scan line to be drawn.

            if (dest_rect->x >= 0)
            {
                t += dest_rect->x;
                if ((dest_rect->x + w) < vbuff.width)
                    xcount = w;
                else
                    xcount = vbuff.width - dest_rect->x;
            }
            else        // starting X is negative in this case.
            {
                tx = -dest_rect->x;
                if ((dest_rect->x + w) > vbuff.width)
                {
                    xcount = vbuff.width;
                }
                else
                {
                    xcount = w + dest_rect->x;  
                }
            }
            lptr = (char *)t;
            tptr = (char *)((ty * img->width) + tx + (dword)img->tex);
            for (int i=0;i < ycount;i++)
            {
                vngo_iline8(lptr,tptr,xcount,flags);
                lptr += vbuff.pitch;
                tptr += img->width;
            }

        }
    }
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::image_trans_s (VngoRect *dest_rect,VngoTexture *img,
                                 dword shade, dword flags)
{
    assert(lock_status);

    long        w,h;
    VngoRect    dr;

    if (!(img->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    w = MIN(img->width,dest_rect->dx);
    h = MIN(img->height,dest_rect->dy);

    dr.x = dest_rect->x;
    dr.y = dest_rect->y;
    dr.dx = w;
    dr.dy = h;

    if (((dest_rect->x + w) < vbuff.width) &&
        ((dest_rect->y + h) < vbuff.height) &&
        (dest_rect->x >= 0) && (dest_rect->y >= 0))
    {
        vngo_itrans_s8 (&vbuff,&dr,img,shade,flags);
    }
    else
    {
        if ((dest_rect->x < vbuff.width) && (dest_rect->y < vbuff.height) &&
            (dest_rect->x + w >= 0) && (dest_rect->y + h >= 0))
        {
            char    *lptr,*tptr;
            dword   t;
            dword   tx=0,ty=0;
            long    xcount,ycount;

            if (dest_rect->y >= 0)
            {
                t = vbuff.ytable[dest_rect->y];
                if ((dest_rect->y + h) < vbuff.height)
                    ycount = h;
                else
                    ycount = vbuff.height - dest_rect->y;
            }
            else        // starting Y is negative in this case.
            {
                ty = -dest_rect->y;
                t = vbuff.ytable[0];
                if ((dest_rect->y + h) > vbuff.height)
                {
                    ycount = vbuff.height;
                }
                else
                {
                    ycount = h + dest_rect->y;  
                }

            }
            t += (dword)(vbuff.scrn_ptr);

            // At this point t = the pointer to the begining of the first
            // scan line to be drawn.

            if (dest_rect->x >= 0)
            {
                t += dest_rect->x;
                if ((dest_rect->x + w) < vbuff.width)
                    xcount = w;
                else
                    xcount = vbuff.width - dest_rect->x;
            }
            else        // starting X is negative in this case.
            {
                tx = -dest_rect->x;
                if ((dest_rect->x + w) > vbuff.width)
                {
                    xcount = vbuff.width;
                }
                else
                {
                    xcount = w + dest_rect->x;  
                }
            }
            lptr = (char *)t;
            tptr = (char *)((ty * img->width) + tx + (dword)img->tex);
            for (int i=0;i < ycount;i++)
            {
                vngo_iline_s8(lptr,tptr,xcount,(void *)shade,flags);
                lptr += vbuff.pitch;
                tptr += img->width;
            }

        }
    }
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::image_trans_z (VngoRect *dest_rect,VngoTexture *img,
                                 dword depth, dword flags)
{
#if 1
    assert(lock_status);

    long        w,h;
    VngoRect    dr;

    if (!(img->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    w = MIN(img->width,dest_rect->dx);
    h = MIN(img->height,dest_rect->dy);

    dr.x = dest_rect->x;
    dr.y = dest_rect->y;
    dr.dx = w;
    dr.dy = h;

#if 0   // for now draw it all by scan lines.
    if (((dest_rect->x + w) < vbuff.width) &&
        ((dest_rect->y + h) < vbuff.height) &&
        (dest_rect->x >= 0) && (dest_rect->y >= 0))
    {
        vngo_itrans_z8 (&vbuff,&dr,img,depth,flags);
    }
    else
#endif
    {
        if ((dest_rect->x < vbuff.width) && (dest_rect->y < vbuff.height) &&
            (dest_rect->x + w >= 0) && (dest_rect->y + h >= 0))
        {
            char    *lptr,*tptr;
            dword   t,tz;
            dword   tx=0,ty=0;
            long    xcount,ycount;

            if (dest_rect->y >= 0)
            {
                t = vbuff.ytable[dest_rect->y];
                tz = vbuff.ztable[dest_rect->y];
                if ((dest_rect->y + h) < vbuff.height)
                    ycount = h;
                else
                    ycount = vbuff.height - dest_rect->y;
            }
            else        // starting Y is negative in this case.
            {
                ty = -dest_rect->y;
                t = vbuff.ytable[0];
                tz = vbuff.ztable[0];
                if ((dest_rect->y + h) > vbuff.height)
                {
                    ycount = vbuff.height;
                }
                else
                {
                    ycount = h + dest_rect->y;  
                }

            }
            t += (dword)(vbuff.scrn_ptr);
            tz += (dword)(vbuff.zbuff_ptr);

            // At this point t = the pointer to the begining of the first
            // scan line to be drawn.

            if (dest_rect->x >= 0)
            {
                t += dest_rect->x;
                // Don't shift if zbuffer is 8 bits deep.
                if (vzdepth_in_bits == 16)
                    tz += (dest_rect->x << 1);
                else if (vzdepth_in_bits == 32)
                    tz += dest_rect->x << 2;

                if ((dest_rect->x + w) < vbuff.width)
                    xcount = w;
                else
                    xcount = vbuff.width - dest_rect->x;
            }
            else        // starting X is negative in this case.
            {
                tx = -dest_rect->x;
                if ((dest_rect->x + w) > vbuff.width)
                {
                    xcount = vbuff.width;
                }
                else
                {
                    xcount = w + dest_rect->x;  
                }
            }
            lptr = (char *)t;
            tptr = (char *)((ty * img->width) + tx + (dword)img->tex);
            for (int i=0;i < ycount;i++)
            {
                vngo_iline_z8(lptr,(void *)tz,tptr,xcount,depth,flags);
                lptr += vbuff.pitch;
                tz   += vbuff.zpitch;
                tptr += img->width;
            }

        }
    }
    return VNGO_NO_ERROR;
#else
    assert(lock_status);
    return VNGO_NOT_SUPPORTED;
#endif
}

VNGError VngoVVport8::image_trans_zs (VngoRect *dest_rect,VngoTexture *img, 
                                 dword depth, dword shade, dword flags)
{
    assert(lock_status);
    if (!(img->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    return VNGO_NOT_SUPPORTED;
}



VNGError VngoVVport8::zblit_mono (VngoRect *dest_rect,VngoZMap *img,dword fgcol,dword bgcol)
{
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

        ptr = img->zmap.tex;
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


VNGError VngoVVport8::image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword fgcol,dword bgcol)
{
    assert(lock_status);

    long    w,h,x,y;

    if (!(img->flags & VNGO_TEXTURE_MONO))
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

        ptr = img->tex;
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


VNGError VngoVVport8::vpcopy(int destx,int desty,VngoBaseDev *vp)
{
    assert(lock_status);

#if 0   // This function is now obsolete, and not guarantied to work.
    VngoRect r;
    VngoTexture t;

    sync();

    if ((vp->vflags & VNGO_PAL_MAPPED_DEV) || 1)
    {
        r.x = destx;
        r.y = desty;
        r.dx = vbuff.width;
        r.dy = vbuff.height;
        t.width = (short)r.dx;
        t.height = (short)r.dy;
        t.tex = vbuff.scrn_ptr;
        vp->image_trans(&r,&t);
    }
    return VNGO_NO_ERROR;
#endif
    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVVport8::poly (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i = 0; i < count; i++)
    {
        tpts[i].x = pts[i].x << 20;
        tpts[i].y = pts[i].y << 20;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_poly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = pts[i].x << 20;
        tpts[i].y = pts[i].y << 20;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 20;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_gpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly_persp (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = pts[i].x << 20;
        tpts[i].y = pts[i].y << 20;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 20;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_gpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::tpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    if (!(tex->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoTextureInfo tptr;

    tptr.vtxt = tex;
    switch (tex->width)
    {
        case    32:
            tptr.widthshift     = 5;
            tptr.u_upshift      = 11;
            break;
        case    64:
            tptr.widthshift     = 6;
            tptr.u_upshift      = 10;
            break;
        case    128:
            tptr.widthshift     = 7;
            tptr.u_upshift      = 9;
            break;
        case    256:        
            tptr.widthshift     = 8;
            tptr.u_upshift      = 8;
            break;
        case    16:
            tptr.widthshift     = 4;
            tptr.u_upshift      = 12;
            break;
        default:
            return (VNGO_UNSUPPORTED_TEXTURE);
    }
    tptr.u_downshift    = 32 - tptr.widthshift;

    switch (tex->height)
    {
        case    32:
            tptr.heightshift    = 5;
            tptr.v_upshift      = 11;
            tptr.v_downshift    = 27;
            break;
        case    64:
            tptr.heightshift    = 6;
            tptr.v_upshift      = 10;
            tptr.v_downshift    = 26;
            break;
        case    128:
            tptr.heightshift    = 7;
            tptr.v_upshift      = 9;
            tptr.v_downshift    = 25;
            break;
        case    256:        
            tptr.heightshift    = 8;
            tptr.v_upshift      = 8;
            tptr.v_downshift    = 24;
            break;
        case    16:
            tptr.heightshift    = 4;
            tptr.v_upshift      = 12;
            tptr.v_downshift    = 28;
            break;
        default:
            return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 20;
        tpts[i].y = pts[i].y << 20;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly8(this,count,tpts,&tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    if (!(tex->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoTextureInfo tptr;

    tptr.vtxt = tex;
    switch (tex->width)
    {
        case    32:
            tptr.widthshift     = 5;
            tptr.u_upshift      = 11;
            break;
        case    64:
            tptr.widthshift     = 6;
            tptr.u_upshift      = 10;
            break;
        case    128:
            tptr.widthshift     = 7;
            tptr.u_upshift      = 9;
            break;
        case    256:        
            tptr.widthshift     = 8;
            tptr.u_upshift      = 8;
            break;
        case    16:
            tptr.widthshift     = 4;
            tptr.u_upshift      = 12;
            break;
        default:
            return (VNGO_UNSUPPORTED_TEXTURE);
    }
    tptr.u_downshift    = 32 - tptr.widthshift;

    switch (tex->height)
    {
        case    32:
            tptr.heightshift    = 5;
            tptr.v_upshift      = 11;
            tptr.v_downshift    = 27;
            break;
        case    64:
            tptr.heightshift    = 6;
            tptr.v_upshift      = 10;
            tptr.v_downshift    = 26;
            break;
        case    128:
            tptr.heightshift    = 7;
            tptr.v_upshift      = 9;
            tptr.v_downshift    = 25;
            break;
        case    256:        
            tptr.heightshift    = 8;
            tptr.v_upshift      = 8;
            tptr.v_downshift    = 24;
            break;
        case    16:
            tptr.heightshift    = 4;
            tptr.v_upshift      = 12;
            tptr.v_downshift    = 28;
            break;
        default:
            return (VNGO_UNSUPPORTED_TEXTURE);
    }


    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 20;
        tpts[i].y = pts[i].y << 20;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly_persp8(this,count,tpts,&tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gtpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert( lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    if (!(tex->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoTextureInfo tptr;

    tptr.vtxt = tex;
    switch (tex->width)
    {
        case    32:
            tptr.widthshift     = 5;
            tptr.u_upshift      = 11;
            break;
        case    64:
            tptr.widthshift     = 6;
            tptr.u_upshift      = 10;
            break;
        case    128:
            tptr.widthshift     = 7;
            tptr.u_upshift      = 9;
            break;
        case    256:        
            tptr.widthshift     = 8;
            tptr.u_upshift      = 8;
            break;
        case    16:
            tptr.widthshift     = 4;
            tptr.u_upshift      = 12;
            break;
        default:
            return (VNGO_UNSUPPORTED_TEXTURE);
    }
    tptr.u_downshift    = 32 - tptr.widthshift;

    switch (tex->height)
    {
        case    32:
            tptr.heightshift    = 5;
            tptr.v_upshift      = 11;
            tptr.v_downshift    = 27;
            break;
        case    64:
            tptr.heightshift    = 6;
            tptr.v_upshift      = 10;
            tptr.v_downshift    = 26;
            break;
        case    128:
            tptr.heightshift    = 7;
            tptr.v_upshift      = 9;
            tptr.v_downshift    = 25;
            break;
        case    256:        
            tptr.heightshift    = 8;
            tptr.v_upshift      = 8;
            tptr.v_downshift    = 24;
            break;
        case    16:
            tptr.heightshift    = 4;
            tptr.v_upshift      = 12;
            tptr.v_downshift    = 28;
            break;
        default:
            return (VNGO_UNSUPPORTED_TEXTURE);
    }


    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 20;
        tpts[i].y = pts[i].y << 20;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 20;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_tgpoly8(this,count,tpts,&tptr);
    return VNGO_NO_ERROR;
}
VNGError VngoVVport8::gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    if (!(tex->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoTextureInfo tptr;

    tptr.vtxt = tex;
    switch (tex->width)
    {
        case    32:
            tptr.widthshift     = 5;
            tptr.u_upshift      = 11;
            break;
        case    64:
            tptr.widthshift     = 6;
            tptr.u_upshift      = 10;
            break;
        case    128:
            tptr.widthshift     = 7;
            tptr.u_upshift      = 9;
            break;
        case    256:        
            tptr.widthshift     = 8;
            tptr.u_upshift      = 8;
            break;
        case    16:
            tptr.widthshift     = 4;
            tptr.u_upshift      = 12;
            break;
        default:
            return (VNGO_UNSUPPORTED_TEXTURE);
    }
    tptr.u_downshift    = 32 - tptr.widthshift;

    switch (tex->height)
    {
        case    32:
            tptr.heightshift    = 5;
            tptr.v_upshift      = 11;
            tptr.v_downshift    = 27;
            break;
        case    64:
            tptr.heightshift    = 6;
            tptr.v_upshift      = 10;
            tptr.v_downshift    = 26;
            break;
        case    128:
            tptr.heightshift    = 7;
            tptr.v_upshift      = 9;
            tptr.v_downshift    = 25;
            break;
        case    256:        
            tptr.heightshift    = 8;
            tptr.v_upshift      = 8;
            tptr.v_downshift    = 24;
            break;
        case    16:
            tptr.heightshift    = 4;
            tptr.v_upshift      = 12;
            tptr.v_downshift    = 28;
            break;
        default:
            return (VNGO_UNSUPPORTED_TEXTURE);
    }


    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 20;
        tpts[i].y = pts[i].y << 20;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 20;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_tgpoly_persp8(this,count,tpts,&tptr);
    return VNGO_NO_ERROR;
}

//°±² End of module - vngvvp8.cpp ²±°
