//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
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

// #define NOT_IMPLEMENTED
                     
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

vngo_error_codes VngoVVport8::init (long width,long height,long org_x,long org_y,VngoPal *my_pal,dword flags)
{
    vbuff.width = width;
    vbuff.height = height;
    vbuff.left = org_x;
    vbuff.top = org_y;
    vflags = flags;
    vflags |= VNGO_PAL_MAPPED_DEV;
    size_in_bytes = width * height;
    vbuff.zbuff_ptr = NULL;
    damage_list = NULL;
    last_damage_list = NULL;

    vbuff.scrn_ptr = (byte *)ivory_alloc (size_in_bytes);

    if (vflags & VNGO_ZBUFFER_DEV)
    {
        vzdepth_in_bits = 16;
        int z_size_shift = vzdepth_in_bits >> 4;
        vbuff.zbuff_ptr = (dword *)ivory_alloc(size_in_bytes << z_size_shift);
        if (!vbuff.zbuff_ptr)
        {
            return (VNGO_MEMALLOC_ERROR);
        }
        assert(vbuff.zbuff_ptr != 0);
        vflags |= VNGO_ZBUFFER_ACTIVE;
    }

    // allocate all tables.

    vbuff.ytable = (dword *)ivory_alloc(4096 * sizeof(dword));
    if (!vbuff.ytable)
    {
        if (vflags & VNGO_ZBUFFER_DEV)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
        }
        return (VNGO_MEMALLOC_ERROR);
    }
    vbuff.invert = (dword *)ivory_alloc(4096 * sizeof(dword));
    if (!vbuff.invert)
    {
        if (vflags & VNGO_ZBUFFER_DEV)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
        }
        ivory_free((void **)&(vbuff.ytable));
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
    vngo_fill_y_table(&vbuff, 1);
    vngo_fill_invert_table(vbuff.invert);

    if (!(vflags & VNGO_INIT_NO_RESET))
    {
        reset();
    }
    return (VNGO_NO_ERROR);
}

VngoVVport8::~VngoVVport8()
{
    if (!(vflags & VNGO_PHYSICAL_DEV) && (vbuff.scrn_ptr))
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
    if (vbuff.invert)
    {
        ivory_free((void **)&(vbuff.invert));
    }
}

void VngoVVport8::reset(dword c,dword farz)
{
    VngoRectList    *t2;
    dword           t;


    if (!(vflags & VNGO_NOCLEAR_VBUFFER))
    {
        t2 = damage_list;
        if (damage_list !=NULL)
        {
            while (t2 !=NULL)
            {
                frect((VngoRect *)t2,c);
                t2 = t2->next;
            }
        }
        else
        {
            vbuff_reset(vbuff.scrn_ptr,size_in_bytes,c);
        }
    }

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        if (vzdepth_in_bits == 32)
            zbuff_reset32(vbuff.zbuff_ptr,size_in_bytes,farz);
        else if (vzdepth_in_bits == 16)
        {
            t2=damage_list;
            t = farz & 0xffff0000;
            t |= ((farz & 0xffff0000) >> 16);
//            t = 0xffffffff;

            if (damage_list !=NULL)
            {
                while(t2 != NULL)
                {
                    zbuff_reset_rect16(&vbuff,(VngoRect *)t2,t);
                    t2 = t2->next;

                }
            }
            else
            {
                zbuff_reset32(vbuff.zbuff_ptr,size_in_bytes>>1,t);
            }
        }
    }
    free_hot_rects();
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the start of the draw function block of the VngoVVport8 class.   ³
// all fucntions in this class draw to a 8 bit device regardless of the size³
// of the input color information.                                          ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

void VngoVVport8::pixel(VngoPoint *pt)
{
    assert (pt->x < vbuff.width);  
    assert (pt->x >= 0);
    assert (pt->y < vbuff.height); 
    assert (pt->y >= 0);
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        vngo_zpixel8(&vbuff,pt);
    }
    else
    {
        vngo_pixel8(&vbuff,pt);
    }
}


void VngoVVport8::frect(VngoRect *rect,dword color)
{
#ifdef DEBUG
    if (rect->x < 0)
        assert (rect->x >= 0);
    if ((rect->x + rect->dx) >= vbuff.width)
        assert ((rect->x + rect->dx) < vbuff.width);
    if (rect->y < 0)
        assert (rect->y >= 0);
    if ((rect->y + rect->dy) >= vbuff.height)
        assert ((rect->y + rect->dy) < vbuff.height);
#endif
    assert (rect->x >= 0);
    assert ((rect->x + rect->dx) < vbuff.width);
    assert (rect->y >= 0);
    assert ((rect->y + rect->dy) < vbuff.height);
    vngo_rect8(&vbuff,rect,color);
}


void VngoVVport8::line(VngoPoint *p1,VngoPoint *p2)
{
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
        vngo_zline8(&vbuff,p1,p2);
    }
    else
    {
        vngo_line8(&vbuff,p1,p2);
    }
}

void VngoVVport8::gline(VngoPoint *p1,VngoPoint *p2)
{
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
        vngo_zline8(&vbuff,p1,p2);
    }
    else
    {
        vngo_line8(&vbuff,p1,p2);
    }
}

void VngoVVport8::gline_persp(VngoPoint *p1,VngoPoint *p2)
{
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
        vngo_zline8(&vbuff,p1,p2);
    }
    else
    {
        vngo_line8(&vbuff,p1,p2);
    }
}

void VngoVVport8::image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags)
{
    long        w,h;
    VngoRect    dr;

    w = MIN(img->width,dest_rect->dx);
    h = MIN(img->height,dest_rect->dy);

    dr.x = dest_rect->x;
    dr.y = dest_rect->y;
    dr.dx = w;
    dr.dy = h;
    add_hot_rect(new VngoRectList(dr));

    if (((dest_rect->x + w) <= vbuff.width) &&
        ((dest_rect->y + h) <= vbuff.height) &&
        (dest_rect->x >= 0) && (dest_rect->y >= 0))
    {
        vngo_itrans8 (&vbuff,dest_rect,img,flags);
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
                    xcount = dest_rect->dx;
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
                lptr += vbuff.width;
                tptr += img->width;
            }

        }
    }
}


void VngoVVport8::image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword fgcol,dword bgcol)
{
    long    w,h,x,y;

    w = MIN(img->width,dest_rect->dx);
    h = MIN(img->height,dest_rect->dy);

#if 1
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
            t += vbuff.width;
            --h;
        }

    }
#else
    if ((dest_rect->x < vbuff.width) && (dest_rect->y < vbuff.height) &&
        (dest_rect->x + w >= 0) && (dest_rect->y + h >= 0))
    {
        char    *lptr,*tptr;
        dword   t;
        dword   tx=0,ty=0;
        dword   xcount,ycount;

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
                xcount = dest_rect->dx;
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
        t = ty * img->width + tx;
        dword t2 = t & 0x7;
        tptr = (char *)((t >> 3) + (dword)img->tex);
        for (int i=0;i < ycount;i++)
        {
            vngo_ilinemono8(lptr,tptr,xcount,t2,fgcol,bgcol);
            lptr += vbuff.width;
            ty++;
            t = ty * img->width + tx;
            t2 = t & 0x7;
            tptr = (char *)((t>>3) + (dword)img->tex);

        }
    }

#endif
}


void VngoVVport8::vpcopy(int destx,int desty,VngoBaseDev *vp)
{
    VngoRect r;
    VngoTexture t;


    if ((vp->vflags & VNGO_PAL_MAPPED_DEV) || 1)
    {
        if (damage_list != NULL)
        {
            dword           ycnt;
            VngoRectList    *t2 = damage_list;

            r.dy = 1;
            t.height = 1;

            while (t2 !=NULL)
            {
                ycnt = t2->rect.dy;
                r.x = destx + t2->rect.x;            
                r.y = desty + t2->rect.y;            
                r.dx = t2->rect.dx;
                t.width = (short)r.dx;
                t.tex = (vbuff.scrn_ptr + vbuff.ytable[t2->rect.y] + t2->rect.x);
                dword   t3 = vbuff.width;

                while (ycnt-- > 0)
                {
                    vp->image_trans(&r,&t);
                    r.y++;
                    t.tex += t3;
                }
                t2 = t2->next;
            }
            if (vflags & VNGO_BACKBUFFER)
            {
                if (last_damage_list != NULL)
                {
                    compress_last_list();
                    t2 = last_damage_list;
                    while (t2 !=NULL)
                    {
                        ycnt = t2->rect.dy;
                        r.x = destx + t2->rect.x;            
                        r.y = desty + t2->rect.y;            
                        r.dx = t2->rect.dx;
                        t.width = (short)r.dx;
                        t.height = 1;
                        t.tex = (vbuff.scrn_ptr + vbuff.ytable[t2->rect.y] + t2->rect.x);
                        dword   t3 = vbuff.width;

                        while (ycnt-- !=0)
                        {
                            vp->image_trans(&r,&t);
                            r.y++;
                            t.tex += t3;
                        }
                        t2 = t2->next;
                    }
                }
                else
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
            }
        }
        else
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
    }
    sync();
}

void VngoVVport8::poly (int count,VngoPoint pts[])
{
#ifdef DEBUG
    for (int i=0;i < count; i++)
    {
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
#endif

    vngo_poly8(this,count,pts);
}

void VngoVVport8::gpoly (int count,VngoPoint pts[])
{
#ifdef DEBUG
    for (int i=0;i < count; i++)
    {
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
#endif
    vngo_gpoly8(this,count,pts);
}

void VngoVVport8::gpoly_persp (int count,VngoPoint pts[])
{
#ifdef DEBUG
    for (int i=0;i < count; i++)
    {
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
#endif
    vngo_gpoly8(this,count,pts);
}

void VngoVVport8::tpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    for (int i=0;i < count;i++)
    {
        pts[i].u *= tex->width;
        pts[i].v *= tex->height;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly8(this,count,pts,tex);
}

void VngoVVport8::tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    for (int i=0;i < count;i++)
    {
        pts[i].u *= tex->width;
        pts[i].v *= tex->height;
    
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly_persp8(this,count,pts,tex);
}

void VngoVVport8::gtpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    for (int i=0;i < count;i++)
    {
        pts[i].u *= tex->width;
        pts[i].v *= tex->height;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tgpoly8(this,count,pts,tex);

}

void VngoVVport8::gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    for (int i=0;i < count;i++)
    {
        pts[i].u *= tex->width;
        pts[i].v *= tex->height;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tgpoly_persp8(this,count,pts,tex);

}


//°±² End of module - vngbase.cpp ²±°
