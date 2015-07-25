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
#include <stdio.h>
#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "ivory.h"

// This file always needs _D3D defined.
#ifndef _OEMS
#define _OEMS
#define _OEMS_TEMP
#endif

#ifndef _CLEAR_3D
#define _CLEAR_3D_TEMP
#define _CLEAR_3D
#endif

#include "vangogh.hpp"
#include "vngd3d.hpp"

#ifdef  _CLEAR_3D_TEMP
#undef  _CLEAR_3D
#undef  _CLEAR_3D_TEMP
#endif

#ifdef  _OEMS_TEMP
#undef  _OEMS
#undef  _OEMS_TEMP
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MIN(a,b)  ((a) < (b)) ? (a) : (b)

#define ZCONST ((float)1.f/65535.0f)
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

extern "C" void vngo_wordcopy(void *dest,void *src,dword count);

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


VngoVportCL3D::VngoVportCL3D (long width,long height,long org_x,long org_y,VngoPal *my_pal,dword flags,VngoScreenManager *_screen)
{
    init_status = init (width,height,org_x,org_y,my_pal,flags,_screen);
}

VNGError VngoVportCL3D::init (long _left,long _top,long width,long height,VngoPal *my_pal,dword flags,VngoScreenManager *_screen)
{
    screen = (VngoClear3D*)_screen;

    vflags = flags;
    vbuff.pal = my_pal;
    vbuff.width = width;
    vbuff.height = height;
    top = _top;
    left = _left;

    int was_locked = plock();
    if (was_locked == -1)
        return (VNGO_INTERNAL_ERROR);

    if (!was_locked)
        punlock();


    if (vflags & VNGO_ZBUFFER_DEV)
    {
        zbuffer_on();
    }

    vbuff.ytable = (dword *)ivory_alloc(vbuff.height * sizeof(dword));
    if (!vbuff.ytable)
    {
        return (VNGO_MEMALLOC_ERROR);
    }
    if (vflags & VNGO_ZBUFFER_DEV)
    {
        vbuff.ztable = (dword *)ivory_alloc(vbuff.height * sizeof(dword));
        if (!vbuff.ztable)
        {
            ivory_free((void **)&(vbuff.ytable));
            return (VNGO_MEMALLOC_ERROR);
        }
    }
    long max_dem = vbuff.width;
    if (vbuff.height > vbuff.width)
        max_dem = vbuff.height;

    vbuff.edge1 = (VngoPoint2 *)ivory_alloc(max_dem * sizeof(VngoPoint2));
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

    vbuff.edge2 = (VngoPoint2 *)ivory_alloc(max_dem * sizeof(VngoPoint2));
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
        was_locked = lock();
        if (was_locked != -1)
        {
            reset();
            if (!was_locked)
                unlock();
        }
    }


    return (VNGO_NO_ERROR);
}

VngoVportCL3D::~VngoVportCL3D()
{
    if (vbuff.ytable)
    {
        ivory_free((void **)&vbuff.ytable);
    }
    if (vbuff.ztable)
    {
        ivory_free((void **)&vbuff.ztable);
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

void VngoVportCL3D::reset(dword c,dword farz)
{
    // Please note that the ZMap is not supported by this device.

    // make sure there is nothing pending before
    // we try to use DDraw on the surfaces.
    screen->flush();

    LL_Batch *pB;
    dword   clear_flags = LL_RECT_LIST;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        pB = screen->get_batch(3);
        clear_flags |= LL_Z_BUFFER;     // zbuffer needs to be cleared.
    }
    else
    {
        pB = screen->get_batch(1);
    }


    VngoColor24bit rgb = vbuff.pal->get_RGB(c);
    dword   raw_rgb = (rgb.r << 16) | (rgb.g << 8) | rgb.b;

    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));


    dword   z_flags = LL_Z_MODE_ALWAYS;

//    if (vflags & VNGO_NOCLEAR_VBUFFER)  // we are not clearing the display buffer.
//        z_flags |= LL_Z_MODE_ONLY;

    pts[0].x = dword(left) << 16;
    pts[0].y = dword(top) << 16;
    pts[0].z = farz;
    pts[0].dwColor = raw_rgb;
    pts[1].x = dword(left + vbuff.width) << 16;
    pts[1].y = dword(top + vbuff.height) << 16;
    pts[1].z = farz;
    pts[1].dwColor = raw_rgb;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        pB->bOp     = LL_SET_Z_MODE;
        pB->dwFlags = z_flags;
        pB++;
    }

    pB->bOp     = LL_RECT;
    pB->wCount  = 1;
    pB->dwFlags = clear_flags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;
    pB++;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        pB->bOp     = LL_SET_Z_MODE;
        pB->dwFlags = LL_Z_MODE_NORMAL;
    }

//    screen->flush();

}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the start of the draw function block of the VngoVportCL3D class. ³
// all fucntions in this class draw to a 8 bit device regardless of the size³
// of the input color information.                                          ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VNGError VngoVportCL3D::image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags)
{
#if 1
    long        w,h;
    VngoRect    dr;

    if (flags & VNGO_STRETCH)
    {
        return (VNGO_NOT_SUPPORTED);
    }

    if ((img->flags & VNGO_TEXTURE_15BIT && vbuff.pal->flags & VNGO_16BIT)
        || (img->flags & VNGO_TEXTURE_16BIT && vbuff.pal->flags & VNGO_15BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    w = MIN(img->width,dest_rect->dx);
    h = MIN(img->height,dest_rect->dy);

    dr.x = dest_rect->x;
    dr.y = dest_rect->y;
    dr.dx = w;
    dr.dy = h;

    int was_locked = plock();
    if (was_locked == -1)
        return VNGO_INTERNAL_ERROR;

    if (((dest_rect->x + w) <= vbuff.width) &&
        ((dest_rect->y + h) <= vbuff.height) &&
        (dest_rect->x >= 0) && (dest_rect->y >= 0))
    {
        if (img->flags & VNGO_TEXTURE_COMPRESSED && !(img->flags & VNGO_TEXTURE_8BIT))
        {
            for (int y=0;y < img->height;y++)
            {
                word *ptr = (word*)(ulong(img->tex) + (((VngoCTexture*)img)->ytable[y]));
//                &(img->tex[((VngoCTexture*)img)->ytable[y]]);
                long cnt = *ptr;
                ptr++;
                word *destptr = (word*)(vbuff.scrn_ptr + vbuff.ytable[dest_rect->y + y]) + dest_rect->x;
                long dcount = 0;
                while (dcount < img->width)
                {
                    vngo_wordcopy(destptr,ptr,cnt);
//                    memcpy(destptr,ptr,cnt*sizeof(word));
                    dcount += cnt;
                    ptr += cnt;
                    destptr += cnt;
                    cnt = *ptr;
                    ptr++;
                    destptr += cnt;
                    dcount += cnt;
                    cnt = *ptr;
                    ptr++;
                }
            }
            if (!was_locked)
                punlock();
            return VNGO_NO_ERROR;
        }
    }
#if 0       // For now we will clip everything.
    else
#endif
    {
        if (img->flags & VNGO_TEXTURE_COMPRESSED)
        {
            if (!was_locked)
                punlock();
            return VNGO_UNSUPPORTED_TEXTURE;
        }

        if ((dest_rect->x < vbuff.width) && (dest_rect->y < vbuff.height) &&
            (dest_rect->x + w >= 0) && (dest_rect->y + h >= 0))
        {
            word    *lptr,*tptr;
            dword   t;
            dword   tx=0,ty=0;
            long    xcount,ycount;

            if (dest_rect->y >= 0)
            {
                t = vbuff.ytable[dest_rect->y];
                if ((dest_rect->y + h) < vbuff.height)
                    ycount = h;
                else
                    ycount = (vbuff.height) - dest_rect->y;
//                    ycount = (vbuff.height-1) - dest_rect->y;
            }
            else        // starting Y is negative in this case.
            {
                ty = -dest_rect->y;
                t = vbuff.ytable[0];
                if ((dest_rect->y + h) > vbuff.height)
                {
                    ycount = vbuff.height;
//                    ycount = vbuff.height-1;
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
                t += (dest_rect->x << 1);
                if ((dest_rect->x + w) < vbuff.width)
                    xcount = w;
                else
                    xcount = (vbuff.width) - dest_rect->x;
//                    xcount = (vbuff.width-1) - dest_rect->x;
            }
            else        // starting X is negative in this case.
            {
                tx = -dest_rect->x;
                if ((dest_rect->x + w) > vbuff.width)
                {
                    xcount = vbuff.width;
//                    xcount = vbuff.width-1;
                }
                else
                {
                    xcount = w + dest_rect->x;
                }
            }
            if (img->flags & VNGO_TEXTURE_16BIT)
            {
                lptr = (word *)t;
                tptr = (word *)((ty * (img->width << 1)) + (tx << 1) + (dword)img->tex);
                for (int i=0;i < ycount;i++)
                {
                    vngo_iline16(lptr,tptr,xcount,flags);
                    lptr += (vbuff.pitch >> 1);
                    tptr += img->width;
                }
            }
            else if (img->flags & VNGO_TEXTURE_15BIT)
            {
                lptr = (word *)t;
                tptr = (word *)((ty * (img->width << 1)) + (tx << 1) + (dword)img->tex);
                for (int i=0;i < ycount;i++)
                {
                    vngo_iline15(lptr,tptr,xcount,flags);
                    lptr += (vbuff.pitch >> 1);
                    tptr += img->width;
                }
            }
            else if (img->flags & VNGO_TEXTURE_8BIT)
            {
                lptr = (word *)t;
                byte *btptr = (byte *)((ty * img->width) + tx + (dword)img->tex);
                VngoShadePal16   *tp = (VngoShadePal16 *)vbuff.pal->shd_pal;
                VngoColorShade16 *tc = &(*tp)[0];
                word             *stable = &tc->shl[(vbuff.pal->shd_pal->mid_point-1) >> 3];
                for (int i=0;i < ycount;i++)
                {
                    vngo_iline8to16(lptr,btptr,xcount,stable,flags);
                    lptr  += (vbuff.pitch >> 1);
                    btptr += img->width;
                }
            }

        }
        if (!was_locked)
            punlock();
    }
    return VNGO_NO_ERROR;

#else
    assert(lock_status);

    long        w,h;
    VngoRect    dr;

    if (flags & VNGO_STRETCH)
    {
        return (VNGO_NOT_SUPPORTED);
    }

    if ((img->flags & VNGO_TEXTURE_15BIT && vbuff.pal->flags & VNGO_16BIT)
        || (img->flags & VNGO_TEXTURE_16BIT && vbuff.pal->flags & VNGO_15BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    int was_locked = plock();
    VNGError retval = VNGO_INTERNAL_ERROR;

    if (was_locked != -1)
    {
        w = MIN(img->width,dest_rect->dx);
        h = MIN(img->height,dest_rect->dy);

        dr.x = dest_rect->x;
        dr.y = dest_rect->y;
        dr.dx = w;
        dr.dy = h;

        if (((dest_rect->x + w) <= vbuff.width) &&
            ((dest_rect->y + h) <= vbuff.height) &&
            (dest_rect->x >= 0) && (dest_rect->y >= 0))
        {
            if (img->flags & VNGO_TEXTURE_COMPRESSED && !(img->flags & VNGO_TEXTURE_8BIT))
            {
                for (int y=0;y < img->height;y++)
                {
                    word *ptr = (word*)(ulong(img->tex) + (((VngoCTexture*)img)->ytable[y]));
    //                &(img->tex[((VngoCTexture*)img)->ytable[y]]);
                    long cnt = *ptr;
                    ptr++;
                    word *destptr = (word*)(vbuff.scrn_ptr + vbuff.ytable[dest_rect->y + y]) + dest_rect->x;
                    long dcount = 0;
                    while (dcount < img->width)
                    {
                        vngo_wordcopy(destptr,ptr,cnt);
    //                    memcpy(destptr,ptr,cnt*sizeof(word));
                        dcount += cnt;
                        ptr += cnt;
                        destptr += cnt;
                        cnt = *ptr;
                        ptr++;
                        destptr += cnt;
                        dcount += cnt;
                        cnt = *ptr;
                        ptr++;
                    }
                }
                if (!was_locked)
                    punlock();
                return VNGO_NO_ERROR;
            }
        }
    #if 0       // For now we will clip everything.
        else
    #endif
        {
            if (img->flags & VNGO_TEXTURE_COMPRESSED)
            {
                if (!was_locked)
                    punlock();
                return VNGO_UNSUPPORTED_TEXTURE;
            }

            if ((dest_rect->x < vbuff.width) && (dest_rect->y < vbuff.height) &&
                (dest_rect->x + w >= 0) && (dest_rect->y + h >= 0))
            {
                word    *lptr,*tptr;
                dword   t;
                dword   tx=0,ty=0;
                long    xcount,ycount;

                if (dest_rect->y >= 0)
                {
                    t = vbuff.ytable[dest_rect->y];
                    if ((dest_rect->y + h) < vbuff.height)
                        ycount = h;
                    else
                        ycount = (vbuff.height) - dest_rect->y;
//                        ycount = (vbuff.height-1) - dest_rect->y;
                }
                else        // starting Y is negative in this case.
                {
                    ty = -dest_rect->y;
                    t = vbuff.ytable[0];
                    if ((dest_rect->y + h) > vbuff.height)
                    {
                        ycount = vbuff.height;
//                        ycount = vbuff.height-1;
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
                    t += (dest_rect->x << 1);
                    if ((dest_rect->x + w) < vbuff.width)
                        xcount = w;
                    else
                        xcount = (vbuff.width) - dest_rect->x;
//                        xcount = (vbuff.width-1) - dest_rect->x;
                }
                else        // starting X is negative in this case.
                {
                    tx = -dest_rect->x;
                    if ((dest_rect->x + w) > vbuff.width)
                    {
                        xcount = vbuff.width;
//                        xcount = vbuff.width-1;
                    }
                    else
                    {
                        xcount = w + dest_rect->x;
                    }
                }
                if (img->flags & VNGO_TEXTURE_16BIT)
                {
                    lptr = (word *)t;
                    tptr = (word *)((ty * (img->width << 1)) + (tx << 1) + (dword)img->tex);
                    for (int i=0;i < ycount;i++)
                    {
                        vngo_iline16(lptr,tptr,xcount,flags);
                        lptr += (vbuff.pitch >> 1);
                        tptr += img->width;
                    }
                }
                else if (img->flags & VNGO_TEXTURE_15BIT)
                {
                    lptr = (word *)t;
                    tptr = (word *)((ty * (img->width << 1)) + (tx << 1) + (dword)img->tex);
                    for (int i=0;i < ycount;i++)
                    {
                        vngo_iline15(lptr,tptr,xcount,flags);
                        lptr += (vbuff.pitch >> 1);
                        tptr += img->width;
                    }
                }
                else if (img->flags & VNGO_TEXTURE_8BIT)
                {
                    lptr = (word *)t;
                    byte *btptr = (byte *)((ty * img->width) + tx + (dword)img->tex);
                    VngoShadePal16   *tp = (VngoShadePal16 *)vbuff.pal->shd_pal;
                    VngoColorShade16 *tc = &(*tp)[0];
                    word             *stable = &tc->shl[(vbuff.pal->shd_pal->mid_point-1) >> 3];
                    for (int i=0;i < ycount;i++)
                    {
                        vngo_iline8to16(lptr,btptr,xcount,stable,flags);
                        lptr  += (vbuff.pitch >> 1);
                        btptr += img->width;
                    }
                }

            }
        }
        if (!was_locked)
            punlock();
    }

    return VNGO_NO_ERROR;
#endif
}



VNGError VngoVportCL3D::zblit_mono (VngoRect *dest_rect,VngoZMap *img,dword fgcol,dword bgcol)
{
    return VNGO_NOT_SUPPORTED;

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

    int was_locked = plock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
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

            t = vbuff.ztable[y];

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

            t += (x << 1);

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
            t = t + (dword)vbuff.zbuff_ptr;
            while (h > 0)
            {
                vngo_zlinemono16 ((word *)t,ptr,w,xskip,fgcol,bgcol);
                ptr += pitch;
                t += vbuff.zpitch;
                --h;
            }

        }
        if (!was_locked)
            punlock();
    }
    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword _fgcol,dword _bgcol)
{
    assert(lock_status);

    dword   fgcol,bgcol;
    long    w,h,x,y;

    if (_fgcol == VNGO_TRANSPARENT || _fgcol == VNGO_TRANSPARENT_COLOR)
    {
        fgcol = VNGO_TRANSPARENT;
    }
    else
    {
        VngoColor24bit tclr = vbuff.pal->get_RGB(_fgcol);
        if (vbuff.pal->flags & VNGO_15BIT)
        {
            fgcol = tclr.compress();
        }
        else
        {
            fgcol = tclr.compress16();
        }
    }

    if (_bgcol == VNGO_TRANSPARENT || _bgcol == VNGO_TRANSPARENT_COLOR)
    {
        bgcol = VNGO_TRANSPARENT;
    }
    else
    {
        VngoColor24bit tclr = vbuff.pal->get_RGB(_bgcol);
        if (vbuff.pal->flags & VNGO_15BIT)
        {
            bgcol = tclr.compress();
        }
        else
        {
            bgcol = tclr.compress16();
        }
    }

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


    int was_locked = plock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {

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
            if ((y + h) >= vbuff.height)
            {
                h = vbuff.height - y - 1;
            }
            if ((x + w) >= vbuff.width)
            {
                w = vbuff.width - x - 1;
            }


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
            t += (dword)vbuff.scrn_ptr + (x << 1);
            while (h > 0)
            {
                vngo_ilinemono16((word *)t,ptr,w,xskip,fgcol,bgcol);
                ptr += pitch;
                t += vbuff.pitch;
                --h;
            }

        }
        if (!was_locked)
            punlock();
    }
    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::vpcopy(int destx,int desty,VngoVport *vp)
{
    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVportCL3D::pixel (VngoPoint *pt,VngoColor24bit *rgb_val)
{
    dword   raw_rgb=0;
    if (rgb_val)
    {
        raw_rgb = (rgb_val->r << 16) | (rgb_val->g << 8) | (rgb_val->b);
    }
    else
    {
        word *shades = (word*)vbuff.pal->shd_pal->ptr;
        shades += (pt->clr << 5);
        int tclr = shades[pt->shade >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            raw_rgb  = (tclr << 9) & 0xf80000;
            raw_rgb |= (tclr << 6) & 0xf800;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
        else
        {
            raw_rgb  = (tclr << 8) & 0xf80000;
            raw_rgb |= (tclr << 5) & 0xfc00;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
    }

    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    pts[0].x = (left + dword(pt->x)) << 16;
    pts[0].y = (top + dword(pt->y)) << 16;
    pts[0].z = pt->z;
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left + dword(pt->x)) << 16;
    pts[1].y = (top + dword(pt->y)) << 16;
    pts[1].z = pts[0].z;
    pts[1].dwColor = raw_rgb;

    dword tflags = LL_RECT_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
        tflags |= LL_Z_BUFFER;

    pB->bOp     = LL_RECT;
    pB->wCount  = 1;
    pB->dwFlags = tflags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::pixel (VngoPointF *pt,VngoColor24bit *rgb_val)
{
    dword   raw_rgb=0;
    if (rgb_val)
    {
        raw_rgb = (rgb_val->r << 16) | (rgb_val->g << 8) | (rgb_val->b);
    }
    else
    {
        word *shades = (word*)vbuff.pal->shd_pal->ptr;
        shades += (pt->clr << 5);
        int tclr = shades[int(pt->shade) >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            raw_rgb  = (tclr << 9) & 0xf80000;
            raw_rgb |= (tclr << 6) & 0xf800;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
        else
        {
            raw_rgb  = (tclr << 8) & 0xf80000;
            raw_rgb |= (tclr << 5) & 0xfc00;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
    }

    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    pts[0].x = (left + dword(pt->x)) << 16;
    pts[0].y = (top + dword(pt->y)) << 16;
    pts[0].z = dword (pt->z * dword (0xffffffff));
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left + dword(pt->x)) << 16;
    pts[1].y = (top + dword(pt->y)) << 16;
    pts[1].z = pts[0].z;
    pts[1].dwColor = raw_rgb;

    dword tflags = LL_RECT_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
        tflags |= LL_Z_BUFFER;

    pB->bOp     = LL_RECT;
    pB->wCount  = 1;
    pB->dwFlags = tflags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::clip_pixel (VngoPoint *pt,VngoColor24bit *rgb_val,VngoRect *clip_rect)
{
    VngoRect    drect(0,0,vbuff.width,vbuff.height);
    if (clip_rect)
    {
        if (drect.clip_to(*clip_rect) == VNGO_FULLY_CLIPPED)
            return VNGO_NO_ERROR;
    }
    if ((pt->x < 0)
        || (pt->x > drect.dx)
        || (pt->y < 0)
        || (pt->y > drect.dy))
        return VNGO_NO_ERROR;
    else
        return pixel(pt,rgb_val);
}

VNGError VngoVportCL3D::clip_pixel (VngoPointF *pt,VngoColor24bit *rgb_val,VngoRect *clip_rect)
{
    VngoRect    drect(0,0,vbuff.width,vbuff.height);
    if (clip_rect)
    {
        if (drect.clip_to(*clip_rect) == VNGO_FULLY_CLIPPED)
            return VNGO_NO_ERROR;
    }
    if ((pt->x < 0)
        || (pt->x > drect.dx)
        || (pt->y < 0)
        || (pt->y > drect.dy))
        return VNGO_NO_ERROR;
    else
        return pixel(pt,rgb_val);
}


VNGError VngoVportCL3D::clip_frect(VngoRect *rect,VngoColor24bit *rgb_val, VngoRect *clip)
{
    VngoRect trect = *rect;
    VngoRect vprect(0,0,vbuff.width,vbuff.height);

    if (clip)
    {
        if (trect.clip_to(*clip) == VNGO_FULLY_CLIPPED)
            return VNGO_NO_ERROR;
    }

    if (trect.clip_to(vprect) == VNGO_FULLY_CLIPPED)
        return VNGO_NO_ERROR;

    return frect(&trect,rgb_val);
}


VNGError VngoVportCL3D::clip_frect(VngoRect *rect,dword color, VngoRect *clip)
{
    VngoRect trect = *rect;
    VngoRect vprect(0,0,vbuff.width,vbuff.height);

    if (clip)
    {
        if (trect.clip_to(*clip) == VNGO_FULLY_CLIPPED)
            return VNGO_NO_ERROR;
    }

    if (trect.clip_to(vprect) == VNGO_FULLY_CLIPPED)
        return VNGO_NO_ERROR;

    return frect(&trect,color);
}


VNGError VngoVportCL3D::frect(VngoRect *rect,VngoColor24bit *rgb_val)
{
    assert (rect->x >= 0);
    assert ((rect->x + rect->dx) <= vbuff.width);
    assert (rect->y >= 0);
    assert ((rect->y + rect->dy) <= vbuff.height);

    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    dword raw_rgb = (rgb_val->r << 16) | (rgb_val->g << 8) | rgb_val->b;

    pts[0].x = (left + dword(rect->x)) << 16;
    pts[0].y = (top + dword(rect->y)) << 16;
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left + dword(rect->x + rect->dx)) << 16;
    pts[1].y = (top + dword(rect->y + rect->dy)) << 16;
    pts[1].dwColor = raw_rgb;

    pB->bOp     = LL_RECT;
    pB->wCount  = 1;
    pB->dwFlags = LL_RECT_LIST;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::frect(VngoRect *rect,dword color)
{
    assert (rect->x >= 0);
    assert ((rect->x + rect->dx) <= vbuff.width);
    assert (rect->y >= 0);
    assert ((rect->y + rect->dy) <= vbuff.height);

    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    VngoColor24bit rgb = vbuff.pal->get_RGB(color);
    dword raw_rgb = (rgb.r << 16) | (rgb.g << 8) | rgb.b;

    pts[0].x = (left + dword(rect->x)) << 16;
    pts[0].y = (top + dword(rect->y)) << 16;
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left + dword(rect->x + rect->dx)) << 16;
    pts[1].y = (top + dword(rect->y + rect->dy)) << 16;
    pts[1].dwColor = raw_rgb;

    pB->bOp     = LL_RECT;
    pB->wCount  = 1;
    pB->dwFlags = LL_RECT_LIST;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;
    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::line (VngoPoint *p1, VngoPoint *p2,VngoColor24bit *rgb_val)
{
    screen->open_frame();

    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    dword raw_rgb;
    if (rgb_val)
    {
        raw_rgb = (rgb_val->r << 16) | (rgb_val->g << 8) | rgb_val->b;
    }
    else
    {
        word *shades = (word*)vbuff.pal->shd_pal->ptr;
        shades += (p1->clr << 5);
        int tclr = shades[p1->shade >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            raw_rgb  = (tclr << 9) & 0xf80000;
            raw_rgb |= (tclr << 6) & 0xf800;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
        else
        {
            raw_rgb  = (tclr << 8) & 0xf80000;
            raw_rgb |= (tclr << 5) & 0xfc00;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
    }

    pts[0].x = (left + p1->x) << 16;
    pts[0].y = (top + p1->y) << 16;
    pts[0].z = p1->z;
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left + p2->x) << 16;
    pts[1].y = (top + p2->y) << 16;
    pts[1].z = p2->z;
    pts[1].dwColor = raw_rgb;

    dword flags = LL_LINE_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        flags |= LL_Z_BUFFER;
    }

    pB->bOp     = LL_LINE;
    pB->wCount  = 1;
    pB->dwFlags = flags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;

}


VNGError VngoVportCL3D::clip_line (VngoPoint *p1, VngoPoint *p2,VngoColor24bit *rgb_val,VngoRect *clip_rect)
{


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

#if 1
    return line(&tp1,&tp2,rgb_val);
#else
    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    dword raw_rgb;
    if (rgb_val)
    {
        raw_rgb = (rgb_val->r << 16) | (rgb_val->g << 8) | rgb_val->b;
    }
    else
    {
        word *shades = (word*)vbuff.pal->shd_pal->ptr;
        shades += (tp1.clr << 5);
        int tclr = shades[int(tp1.shade) >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            raw_rgb  = (tclr << 9) & 0xf80000;
            raw_rgb |= (tclr << 6) & 0xf800;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
        else
        {
            raw_rgb  = (tclr << 8) & 0xf80000;
            raw_rgb |= (tclr << 5) & 0xfc00;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
    }

    pts[0].x = (left << 16) + Flx16(tp1.x).flx;
    pts[0].y = (top << 16) +  Flx16(tp1.y).flx;
    pts[0].z = tp1.z;
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left << 16) + Flx16(tp2.x).flx;
    pts[1].y = (top << 16) +  Flx16(tp2.y).flx;
    pts[1].z = tp2.z;
    pts[1].dwColor = raw_rgb;

    dword flags = LL_LINE_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        flags |= LL_Z_BUFFER;
    }

    pB->bOp     = LL_LINE;
    pB->wCount  = 1;
    pB->dwFlags = flags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
#endif
}


VNGError VngoVportCL3D::line (VngoPointF *p1, VngoPointF *p2,VngoColor24bit *rgb_val)
{
    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));


    dword raw_rgb;
    if (rgb_val)
    {
        raw_rgb = (rgb_val->r << 16) | (rgb_val->g << 8) | rgb_val->b;
    }
    else
    {
        word *shades = (word*)vbuff.pal->shd_pal->ptr;
        shades += (p1->clr << 5);
        int tclr = shades[int(p1->shade) >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            raw_rgb  = (tclr << 9) & 0xf80000;
            raw_rgb |= (tclr << 6) & 0xf800;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
        else
        {
            raw_rgb  = (tclr << 8) & 0xf80000;
            raw_rgb |= (tclr << 5) & 0xfc00;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
    }

    pts[0].x = (left << 16) + Flx16(p1->x).flx;
    pts[0].y = (top << 16) +  Flx16(p1->y).flx;
    pts[0].z = dword(p1->z * float(0xffffffff));
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left << 16) + Flx16(p2->x).flx;
    pts[1].y = (top << 16) +  Flx16(p2->y).flx;
    pts[1].z = dword(p2->z * float(0xffffffff));
    pts[1].dwColor = raw_rgb;

    dword flags = LL_LINE_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        flags |= LL_Z_BUFFER;
    }

    pB->bOp     = LL_LINE;
    pB->wCount  = 1;
    pB->dwFlags = flags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::clip_line (VngoPointF *p1, VngoPointF *p2,VngoColor24bit *rgb_val,VngoRect *clip_rect)
{
    screen->open_frame();
#if 1
    VngoPoint tp1,tp2;

    tp1.x = long(p1->x + .5f);
    tp1.y = long(p1->y + .5f);
    tp1.z = dword(p1->z * float(0xffffffff));
    tp1.clr = p1->clr;
    tp1.shade = long(p1->shade);

    tp2.x = long(p2->x + .5f);
    tp2.y = long(p2->y + .5f);
    tp2.z = dword(p2->z * float(0xffffffff));
    tp2.clr = p2->clr;
    tp2.shade = long(p2->shade);

    return clip_line(&tp1,&tp2,rgb_val,clip_rect);
#else
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));
    LL_Vert *clip = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    VngoRect    tclip(0,0,vbuff.width,vbuff.height);

    if (clip_rect)
    {
        if (tclip.clip_to(*clip_rect)==VNGO_FULLY_CLIPPED)
            return VNGO_NO_ERROR;
    }
    clip->x = (tclip.x + left) << 16;
    clip->y = (tclip.y + top) << 16;
    clip->u = (tclip.x + tclip.dx + left) << 16;
    clip->v = (tclip.y + tclip.dy + top) << 16;

    pB->bOp     = LL_SET_CLIP_REGION;
    pB->dwFlags = LL_SW_CLIP;
    pB->pVert   = clip;
    pB++;


    dword raw_rgb;
    if (rgb_val)
    {
        raw_rgb = (rgb_val->r << 16) | (rgb_val->g << 8) | rgb_val->b;
    }
    else
    {
        word *shades = (word*)vbuff.pal->shd_pal->ptr;
        shades += (p1->clr << 5);
        int tclr = shades[int(p1->shade) >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            raw_rgb  = (tclr << 9) & 0xf80000;
            raw_rgb |= (tclr << 6) & 0xf800;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
        else
        {
            raw_rgb  = (tclr << 8) & 0xf80000;
            raw_rgb |= (tclr << 5) & 0xfc00;
            raw_rgb |= (tclr << 3) & 0xf8;
        }
    }

    pts[0].x = (left << 16) + Flx16(p1->x).flx;
    pts[0].y = (top << 16) +  Flx16(p1->y).flx;
    pts[0].z = dword(p1->z * float(0xffffffff));
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left << 16) + Flx16(p2->x).flx;
    pts[1].y = (top << 16) +  Flx16(p2->y).flx;
    pts[1].z = dword(p2->z * float(0xffffffff));
    pts[1].dwColor = raw_rgb;

    dword flags = LL_LINE_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        flags |= LL_Z_BUFFER;
    }

    pB->bOp     = LL_LINE_CLIP;
    pB->wCount  = 1;
    pB->dwFlags = flags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
#endif
}




VNGError VngoVportCL3D::gline (VngoPoint *p1, VngoPoint *p2)
{
    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    dword raw_rgb,raw_rgb2;

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    word *tshades = shades + (p1->clr << 5);
    int tclr = tshades[int(p1->shade) >> 3];

    tshades = shades + (p2->clr << 5);
    int tclr2 = tshades[int(p2->shade) >> 3];

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        raw_rgb  = (tclr << 9) & 0xf80000;
        raw_rgb |= (tclr << 6) & 0xf800;
        raw_rgb |= (tclr << 3) & 0xf8;

        raw_rgb2  = (tclr2 << 9) & 0xf80000;
        raw_rgb2 |= (tclr2 << 6) & 0xf800;
        raw_rgb2 |= (tclr2 << 3) & 0xf8;
    }
    else
    {
        raw_rgb  = (tclr << 8) & 0xf80000;
        raw_rgb |= (tclr << 5) & 0xfc00;
        raw_rgb |= (tclr << 3) & 0xf8;

        raw_rgb2  = (tclr2 << 8) & 0xf80000;
        raw_rgb2 |= (tclr2 << 5) & 0xfc00;
        raw_rgb2 |= (tclr2 << 3) & 0xf8;
    }


    pts[0].x = (left << 16) + Flx16(p1->x).flx;
    pts[0].y = (top << 16) +  Flx16(p1->y).flx;
    pts[0].z = dword(p1->z);
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left << 16) + Flx16(p2->x).flx;
    pts[1].y = (top << 16) +  Flx16(p2->y).flx;
    pts[1].z = dword(p2->z);
    pts[1].dwColor = raw_rgb2;

    dword flags = LL_LINE_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        flags |= LL_Z_BUFFER;
    }

    pB->bOp     = LL_LINE;
    pB->wCount  = 1;
    pB->dwFlags = flags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
}
VNGError VngoVportCL3D::gline (VngoPointF *p1, VngoPointF *p2)
{
    screen->open_frame();
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));
    LL_Batch *pB = screen->get_batch(1);

    dword raw_rgb,raw_rgb2;

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    word *tshades = shades + (p1->clr << 5);
    int tclr = tshades[int(p1->shade) >> 3];

    tshades = shades + (p2->clr << 5);
    int tclr2 = tshades[int(p2->shade) >> 3];

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        raw_rgb  = (tclr << 9) & 0xf80000;
        raw_rgb |= (tclr << 6) & 0xf800;
        raw_rgb |= (tclr << 3) & 0xf8;

        raw_rgb2  = (tclr2 << 9) & 0xf80000;
        raw_rgb2 |= (tclr2 << 6) & 0xf800;
        raw_rgb2 |= (tclr2 << 3) & 0xf8;
    }
    else
    {
        raw_rgb  = (tclr << 8) & 0xf80000;
        raw_rgb |= (tclr << 5) & 0xfc00;
        raw_rgb |= (tclr << 3) & 0xf8;

        raw_rgb2  = (tclr2 << 8) & 0xf80000;
        raw_rgb2 |= (tclr2 << 5) & 0xfc00;
        raw_rgb2 |= (tclr2 << 3) & 0xf8;
    }


    pts[0].x = (left << 16) + Flx16(p1->x).flx;
    pts[0].y = (top << 16) +  Flx16(p1->y).flx;
    pts[0].z = dword(p1->z * float(0xffffffff));
//    pts[0].z = dword(p1->z);
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left << 16) + Flx16(p2->x).flx;
    pts[1].y = (top << 16) +  Flx16(p2->y).flx;
    pts[1].z = dword(p2->z * float(0xffffffff));
//    pts[1].z = dword(p2->z);
    pts[1].dwColor = raw_rgb2;

    dword flags = LL_LINE_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        flags |= LL_Z_BUFFER;
    }

    pB->bOp     = LL_LINE;
    pB->wCount  = 1;
    pB->dwFlags = flags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::clip_gline (VngoPoint *p1, VngoPoint *p2,VngoRect *clip_rect)
{

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

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    dword raw_rgb,raw_rgb2;

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    word *tshades = shades + (tp1.clr << 5);
    int tclr = tshades[int(tp1.shade) >> 3];

    tshades = shades + (tp2.clr << 5);
    int tclr2 = tshades[int(tp2.shade) >> 3];

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        raw_rgb  = (tclr << 9) & 0xf80000;
        raw_rgb |= (tclr << 6) & 0xf800;
        raw_rgb |= (tclr << 3) & 0xf8;

        raw_rgb2  = (tclr2 << 9) & 0xf80000;
        raw_rgb2 |= (tclr2 << 6) & 0xf800;
        raw_rgb2 |= (tclr2 << 3) & 0xf8;
    }
    else
    {
        raw_rgb  = (tclr << 8) & 0xf80000;
        raw_rgb |= (tclr << 5) & 0xfc00;
        raw_rgb |= (tclr << 3) & 0xf8;

        raw_rgb2  = (tclr2 << 8) & 0xf80000;
        raw_rgb2 |= (tclr2 << 5) & 0xfc00;
        raw_rgb2 |= (tclr2 << 3) & 0xf8;
    }


    pts[0].x = (left << 16) + Flx16(tp1.x).flx;
    pts[0].y = (top << 16) +  Flx16(tp1.y).flx;
    pts[0].z = dword(tp1.z);
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left << 16) + Flx16(tp2.x).flx;
    pts[1].y = (top << 16) +  Flx16(tp2.y).flx;
    pts[1].z = dword(tp2.z);
    pts[1].dwColor = raw_rgb2;

    dword flags = LL_LINE_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        flags |= LL_Z_BUFFER;
    }

    pB->bOp     = LL_LINE;
    pB->wCount  = 1;
    pB->dwFlags = flags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
}
VNGError VngoVportCL3D::clip_gline (VngoPointF *p1, VngoPointF *p2,VngoRect *clip_rect)
{
    screen->open_frame();
#if 1
    VngoPoint tp1,tp2;

    tp1.x = long(p1->x + .5f);
    tp1.y = long(p1->y + .5f);
    tp1.z = dword(p1->z * float(0xffffffff));
    tp1.clr = p1->clr;
    tp1.shade = long(p1->shade);

    tp2.x = long(p2->x + .5f);
    tp2.y = long(p2->y + .5f);
    tp2.z = dword(p2->z * float(0xffffffff));
    tp2.clr = p2->clr;
    tp2.shade = long(p2->shade);

    return clip_gline(&tp1,&tp2,clip_rect);
#else
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *pts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));
    LL_Vert *clip = (LL_Vert*)ivory_arena_alloc (screen->VertPool,2*sizeof( LL_Vert ));

    VngoRect    tclip(0,0,vbuff.width,vbuff.height);

    if (clip_rect)
    {
        if (tclip.clip_to(*clip_rect)==VNGO_FULLY_CLIPPED)
            return VNGO_NO_ERROR;
    }
    clip->x = (tclip.x + left) << 16;
    clip->y = (tclip.y + top) << 16;
    clip->u = (tclip.x + tclip.dx + left) << 16;
    clip->v = (tclip.y + tclip.dy + top) << 16;

    pB->bOp     = LL_SET_CLIP_REGION;
    pB->dwFlags = LL_SW_CLIP;
    pB->pVert   = clip;
    pB++;

    dword raw_rgb,raw_rgb2;

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    word *tshades = shades + (p1->clr << 5);
    int tclr = tshades[int(p1->shade) >> 3];

    tshades = shades + (p2->clr << 5);
    int tclr2 = tshades[int(p2->shade) >> 3];

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        raw_rgb  = (tclr << 9) & 0xf80000;
        raw_rgb |= (tclr << 6) & 0xf800;
        raw_rgb |= (tclr << 3) & 0xf8;

        raw_rgb2  = (tclr2 << 9) & 0xf80000;
        raw_rgb2 |= (tclr2 << 6) & 0xf800;
        raw_rgb2 |= (tclr2 << 3) & 0xf8;
    }
    else
    {
        raw_rgb  = (tclr << 8) & 0xf80000;
        raw_rgb |= (tclr << 5) & 0xfc00;
        raw_rgb |= (tclr << 3) & 0xf8;

        raw_rgb2  = (tclr2 << 8) & 0xf80000;
        raw_rgb2 |= (tclr2 << 5) & 0xfc00;
        raw_rgb2 |= (tclr2 << 3) & 0xf8;
    }


    pts[0].x = (left << 16) + Flx16(p1->x).flx;
    pts[0].y = (top << 16) +  Flx16(p1->y).flx;
    pts[0].z = dword(p1->z * float(0xffffffff));
//    pts[0].z = dword(p1->z);
    pts[0].dwColor = raw_rgb;

    pts[1].x = (left << 16) + Flx16(p2->x).flx;
    pts[1].y = (top << 16) +  Flx16(p2->y).flx;
    pts[1].z = dword(p2->z * float(0xffffffff));
//    pts[1].z = dword(p2->z);
    pts[1].dwColor = raw_rgb2;

    dword flags = LL_LINE_LIST;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        flags |= LL_Z_BUFFER;
    }

    pB->bOp     = LL_LINE_CLIP;
    pB->wCount  = 1;
    pB->dwFlags = flags;
    pB->dwBuf   = NULL;
    pB->pVert   = pts;

    return VNGO_NO_ERROR;
#endif
}


VNGError VngoVportCL3D::gline_persp (VngoPoint *p1, VngoPoint *p2)
{
    return gline(p1,p2);
}
VNGError VngoVportCL3D::gline_persp (VngoPointF *p1, VngoPointF *p2)
{
    return gline(p1,p2);
}

VNGError VngoVportCL3D::clip_gline_persp (VngoPoint *p1, VngoPoint *p2,VngoRect *clip_rect)
{
    return clip_gline(p1,p2,clip_rect);
}
VNGError VngoVportCL3D::clip_gline_persp (VngoPointF *p1, VngoPointF *p2,VngoRect *clip_rect)
{
    return clip_gline(p1,p2,clip_rect);
}


int VngoVportCL3D::plock()
{
    screen->flush();

    int fail_safe=0;
    int ret_val = screen->SurfaceManager->lock();
    DDSURFACEDESC   ddsd;
    ZeroMemory (&ddsd,sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);

    if (ret_val != 1)
    {
        int locked=0;
        HRESULT hr;
        while (!locked && (fail_safe < 1000))
        {
            fail_safe++;    // just so we can't loop infinately.
            if ((hr = screen->BackBuffer->Lock (NULL, &ddsd,
                                     DDLOCK_SURFACEMEMORYPTR
                                     | DDLOCK_WAIT, NULL)) == DD_OK)
            {
                vbuff.pitch = ddsd.lPitch;
                long    offset = ((top) * vbuff.pitch) + (left * 2);
                vbuff.scrn_ptr = (byte *) ((dword)ddsd.lpSurface) + offset;
                locked = 1;
            }
            if (hr == DDERR_SURFACELOST)
            {
                hr = screen->BackBuffer->Restore();
                if (hr != DD_OK)
                    locked = 1; // an error occured while
                                // restoring the surface, so it cannot be locked.
            }
        }

        if (hr != DD_OK)
        {
            screen->SurfaceManager->unlock();
            return (-1);        // failure to lock;
        }

        vbuff.zpitch = 640;

#if 0
        // Now do the zbuffer if needed.
        if (screen->SurfaceManager->zddsurf)
        {
            locked = 0;
            fail_safe = 0;
            while (!locked && (fail_safe < 1000))
            {
                fail_safe++;    // just so we can't loop infinately.
                if ((hr = screen->ZBuffer->Lock (NULL, &ddsd,
                                                 DDLOCK_SURFACEMEMORYPTR
                                                 | DDLOCK_WAIT, NULL)) == DD_OK)
                {
                    vbuff.zpitch = ddsd.lPitch;
                    long    offset = (top * vbuff.zpitch) + (left * 2);
                    vbuff.zbuff_ptr = (word *) ((dword)ddsd.lpSurface + offset);
                    locked = 1;
                }
                if (hr == DDERR_SURFACELOST)
                {
                    hr = screen->ZBuffer->Restore();
                    if (hr != DD_OK)
                        locked = 1; // an error occured while
                                    // restoring the surface, so it cannot be locked.
                }
            }

            if (hr != DD_OK)
            {
                screen->BackBuffer->Unlock(NULL);
                screen->SurfaceManager->unlock();
                return (-1);        // failure to lock;
            }
        }
#endif

    }

    lock_status = 1;
    return(ret_val);
}


int VngoVportCL3D::punlock()
{
    vbuff.scrn_ptr = NULL;

    int ret_val= screen->SurfaceManager->unlock();
    if (ret_val != 0)
    {
        screen->BackBuffer->Unlock( NULL );
        vbuff.scrn_ptr = NULL;
    }
    lock_status = 0;

    return (ret_val);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the start of the Polygon functions for the D3D Vport.            ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VNGError VngoVportCL3D::poly (int count,VngoPoint pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));

    dword dflags = LL_POLY_FAN | LL_DITHER;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr = shades[pts[0].shade >> 3];


    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb = ((tclr << 9) & 0xf80000);
        rgb |= ((tclr >> 2) & 0xf800);
        rgb |= ((tclr & 0x1f) << 3);
    }
    else
    {
        rgb = ((tclr << 8) & 0xf80000);
        rgb |= ((tclr << 5) & 0xfc00);
        rgb |= ((tclr & 0x1f) << 3);
    }

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + (pts[i].x << 16);
        tpts[i].y = (top << 16) +  (pts[i].y << 16);
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::poly (int count,VngoPointF pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();


    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *rshades = (word*)vbuff.pal->shd_pal->ptr;
    word *shades;
    shades = rshades + (pts[0].clr << 5);
    int tclr = shades[int(pts[0].shade) >> 3];


    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb = ((tclr << 9) & 0xf80000);
        rgb |= ((tclr >> 2) & 0xf800);
        rgb |= ((tclr & 0x1f) << 3);
    }
    else
    {
        rgb = ((tclr << 8) & 0xf80000);
        rgb |= ((tclr << 5) & 0xfc00);
        rgb |= ((tclr & 0x1f) << 3);
    }

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gpoly (int count,VngoPoint pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *rshades = (word*)vbuff.pal->shd_pal->ptr;
    word *shades;

    for (int i=0;i < count;i++)
    {
        shades = rshades + (pts[0].clr << 5);
        int tclr = shades[pts[i].shade >> 3];


        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb = ((tclr << 9) & 0xf80000);
            rgb |= ((tclr >> 2) & 0xf800);
            rgb |= ((tclr & 0x1f) << 3);
        }
        else
        {
            rgb = ((tclr << 8) & 0xf80000);
            rgb |= ((tclr << 5) & 0xfc00);
            rgb |= ((tclr & 0x1f) << 3);
        }
        tpts[i].x = (left << 16) + (pts[i].x << 16);
        tpts[i].y = (top << 16) +  (pts[i].y << 16);
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gpoly (int count,VngoPointF pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();


    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));
    ZeroMemory(tpts,count * sizeof(LL_Vert));

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *rshades = (word*)vbuff.pal->shd_pal->ptr;
    word *shades;

    for (int i=0;i < count;i++)
    {
        shades = rshades + (pts[0].clr << 5);
        int tclr = shades[int(pts[i].shade) >> 3];


        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb = ((tclr << 9) & 0xf80000);
            rgb |= ((tclr >> 2) & 0xf800);
            rgb |= ((tclr & 0x1f) << 3);
        }
        else
        {
            rgb = ((tclr << 8) & 0xf80000);
            rgb |= ((tclr << 5) & 0xfc00);
            rgb |= ((tclr & 0x1f) << 3);
        }
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gpoly_persp (int count,VngoPoint pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);
    return gpoly(count,pts);
}
VNGError VngoVportCL3D::gpoly_persp (int count,VngoPointF pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);
    return gpoly(count,pts);
}


VNGError VngoVportCL3D::tpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING | LL_LIGHTING_INTERP_RGB;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    int shade = pts[0].shade;

    if (shade > mp)
        shade= mp;

    float modifier = (255.f / float(mp));
    shade = int(float(shade) * modifier);
    if (shade > 255)
        shade = 255;
    else if (shade < 0)
        shade = 0;

    rgb = shade | (shade << 8) | (shade << 16);

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
        tpts[i].u = pts[i].u * tex->width;
        tpts[i].v = pts[i].v * tex->height;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::tpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING | LL_LIGHTING_INTERP_RGB;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
//    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    int shade = int(pts[0].shade);

    if (shade > mp)
        shade= mp;

    float modifier = (255.f / float(mp));
    shade = int(float(shade) * modifier);
    if (shade > 255)
        shade = 255;
    else if (shade < 0)
        shade = 0;

    rgb = shade | (shade << 8) | (shade << 16);

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
        tpts[i].u = Flx16(pts[i].u * float(tex->width)).flx;
        tpts[i].v = Flx16(pts[i].v * float(tex->height)).flx;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING
                   | LL_LIGHTING_INTERP_RGB | LL_PERSPECTIVE;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    int shade = pts[0].shade;

    if (shade > mp)
        shade= mp;

    float modifier = (255.f / float(mp));
    shade = int(float(shade) * modifier);
    if (shade > 255)
        shade = 255;
    else if (shade < 0)
        shade = 0;

    rgb = shade | (shade << 8) | (shade << 16);

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
        tpts[i].u = pts[i].u * tex->width;
        tpts[i].v = pts[i].v * tex->height;
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::tpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING
                   | LL_LIGHTING_INTERP_RGB | LL_PERSPECTIVE;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    int shade = int(pts[0].shade);

    if (shade > mp)
        shade= mp;

    float modifier = (255.f / float(mp));
    shade = int(float(shade) * modifier);
    if (shade > 255)
        shade = 255;
    else if (shade < 0)
        shade = 0;

    rgb = shade | (shade << 8) | (shade << 16);

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
        tpts[i].u = Flx16(pts[i].u * float(tex->width)).flx;
        tpts[i].v = Flx16(pts[i].v * float(tex->height)).flx;
        tpts[i].w = pts[i].w;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gtpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING | LL_LIGHTING_INTERP_RGB | LL_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));


    for (int i=0;i < count;i++)
    {
        int shade = pts[i].shade;

        if (shade > mp)
            shade= mp;

        shade = int(float(shade) * modifier);
        if (shade > 255)
            shade = 255;
        else if (shade < 0)
            shade = 0;

        rgb = shade | (shade << 8) | (shade << 16);

        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
        tpts[i].u = pts[i].u * tex->width;
        tpts[i].v = pts[i].v * tex->height;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::gtpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING | LL_LIGHTING_INTERP_RGB | LL_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));


    for (int i=0;i < count;i++)
    {
        int shade = int(pts[i].shade);

        if (shade > mp)
            shade= mp;

        shade = int(float(shade) * modifier);
        if (shade > 255)
            shade = 255;
        else if (shade < 0)
            shade = 0;

        rgb = shade | (shade << 8) | (shade << 16);

        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
        tpts[i].u = Flx16(pts[i].u * float(tex->width)).flx;
        tpts[i].v = Flx16(pts[i].v * float(tex->height)).flx;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING
                   | LL_LIGHTING_INTERP_RGB | LL_GOURAUD | LL_PERSPECTIVE;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));


    for (int i=0;i < count;i++)
    {
        int shade = pts[i].shade;

        if (shade > mp)
            shade= mp;

        shade = int(float(shade) * modifier);
        if (shade > 255)
            shade = 255;
        else if (shade < 0)
            shade = 0;

        rgb = shade | (shade << 8) | (shade << 16);

        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
        tpts[i].u = pts[i].u * tex->width;
        tpts[i].v = pts[i].v * tex->height;
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::gtpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_GOURAUD
                   | LL_LIGHTING | LL_LIGHTING_INTERP_RGB | LL_PERSPECTIVE;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));


    for (int i=0;i < count;i++)
    {
        int shade = int(pts[i].shade);

        if (shade > mp)
            shade= mp;

        shade = int(float(shade) * modifier);
        if (shade > 255)
            shade = 255;
        else if (shade < 0)
            shade = 0;

        rgb = shade | (shade << 8) | (shade << 16);

        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
        tpts[i].u = Flx16(pts[i].u * float(tex->width)).flx;
        tpts[i].v = Flx16(pts[i].v * float(tex->height)).flx;
        tpts[i].w = pts[i].w;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::grpoly (int count, VngoPoint pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *rshades = (word*)vbuff.pal->shd_pal->ptr;
    word *shades;

    for (int i=0;i < count;i++)
    {
        int t = pts[i].clr;
        if (t & VNGO_COLOR_24BIT)
            rgb = t & ~VNGO_COLOR_24BIT;
        else
        {
            shades = rshades + (t << 5);
            int tclr = shades[pts[i].shade >> 3];


            if (vbuff.pal->flags & VNGO_15BIT)
            {
                rgb = ((tclr << 9) & 0xf80000);
                rgb |= ((tclr >> 2) & 0xf800);
                rgb |= ((tclr & 0x1f) << 3);
            }
            else
            {
                rgb = ((tclr << 8) & 0xf80000);
                rgb |= ((tclr << 5) & 0xfc00);
                rgb |= ((tclr & 0x1f) << 3);
            }
        }
        tpts[i].x = (left << 16) + (pts[i].x << 16);
        tpts[i].y = (top << 16) +  (pts[i].y << 16);
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::grpoly (int count, VngoPointF pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();


    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));
    ZeroMemory(tpts,count * sizeof(LL_Vert));

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *rshades = (word*)vbuff.pal->shd_pal->ptr;
    word *shades;

    for (int i=0;i < count;i++)
    {
        int t = pts[i].clr;
        if (t & VNGO_COLOR_24BIT)
            rgb = t & ~VNGO_COLOR_24BIT;
        else
        {
            shades = rshades + (t << 5);
            int tclr = shades[int (pts[i].shade) >> 3];


            if (vbuff.pal->flags & VNGO_15BIT)
            {
                rgb = ((tclr << 9) & 0xf80000);
                rgb |= ((tclr >> 2) & 0xf800);
                rgb |= ((tclr & 0x1f) << 3);
            }
            else
            {
                rgb = ((tclr << 8) & 0xf80000);
                rgb |= ((tclr << 5) & 0xfc00);
                rgb |= ((tclr & 0x1f) << 3);
            }
        }
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the start of the Alpha Blennded Polygon                          ³
// functions for the D3D Vport.                                             ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VNGError VngoVportCL3D::poly_a (int count,VngoPoint pts[],long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr = shades[pts[0].shade >> 3];


    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb = ((tclr << 9) & 0xf80000);
        rgb |= ((tclr >> 2) & 0xf800);
        rgb |= ((tclr & 0x1f) << 3);
    }
    else
    {
        rgb = ((tclr << 8) & 0xf80000);
        rgb |= ((tclr << 5) & 0xfc00);
        rgb |= ((tclr & 0x1f) << 3);
    }

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + (pts[i].x << 16);
        tpts[i].y = (top << 16) +  (pts[i].y << 16);
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = (alpha << 16) | 0x00ff;
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::poly_a (int count,VngoPointF pts[],long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();


    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_GOURAUD | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *rshades = (word*)vbuff.pal->shd_pal->ptr;
    word *shades;
    shades = rshades + (pts[0].clr << 5);
    int tclr = shades[int(pts[0].shade) >> 3];


    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb = ((tclr << 9) & 0xf80000);
        rgb |= ((tclr >> 2) & 0xf800);
        rgb |= ((tclr & 0x1f) << 3);
    }
    else
    {
        rgb = ((tclr << 8) & 0xf80000);
        rgb |= ((tclr << 5) & 0xfc00);
        rgb |= ((tclr & 0x1f) << 3);
    }

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = (alpha << 16) | 0x00ff;
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gpoly_a (int count,VngoPoint pts[],long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_GOURAUD | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *rshades = (word*)vbuff.pal->shd_pal->ptr;
    word *shades;

    for (int i=0;i < count;i++)
    {
        shades = rshades + (pts[i].clr << 5);
        int tclr = shades[pts[i].shade >> 3];


        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb = ((tclr << 9) & 0xf80000);
            rgb |= ((tclr >> 2) & 0xf800);
            rgb |= ((tclr & 0x1f) << 3);
        }
        else
        {
            rgb = ((tclr << 8) & 0xf80000);
            rgb |= ((tclr << 5) & 0xfc00);
            rgb |= ((tclr & 0x1f) << 3);
        }
        tpts[i].x = (left << 16) + (pts[i].x << 16);
        tpts[i].y = (top << 16) +  (pts[i].y << 16);
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = (alpha << 16) | 0x00ff;
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gpoly_a (int count,VngoPointF pts[],long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();


    LL_Batch *pB = screen->get_batch(1);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));
    ZeroMemory(tpts,count * sizeof(LL_Vert));

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_GOURAUD | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    dword rgb;

    word *rshades = (word*)vbuff.pal->shd_pal->ptr;
    word *shades;

    for (int i=0;i < count;i++)
    {
        shades = rshades + (pts[i].clr << 5);
        int tclr = shades[int(pts[i].shade) >> 3];


        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb = ((tclr << 9) & 0xf80000);
            rgb |= ((tclr >> 2) & 0xf800);
            rgb |= ((tclr & 0x1f) << 3);
        }
        else
        {
            rgb = ((tclr << 8) & 0xf80000);
            rgb |= ((tclr << 5) & 0xfc00);
            rgb |= ((tclr & 0x1f) << 3);
        }
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = (alpha << 16) | 0x00ff;
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = NULL;
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gpoly_persp_a (int count,VngoPoint pts[],long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);
    return gpoly_a(count,pts,alpha);
}
VNGError VngoVportCL3D::gpoly_persp_a (int count,VngoPointF pts[],long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);
    return gpoly_a(count,pts,alpha);
}


VNGError VngoVportCL3D::tpoly_a (int count,VngoPoint pts[],VngoTexture *tex,long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING
                   | LL_LIGHTING_INTERP_RGB | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    int shade = pts[0].shade;

    if (shade > mp)
        shade= mp;

    float modifier = (255.f / float(mp));
    shade = int(float(shade) * modifier);
    if (shade > 255)
        shade = 255;
    else if (shade < 0)
        shade = 0;

    rgb = shade | (shade << 8) | (shade << 16);

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
        tpts[i].u = pts[i].u * tex->width;
        tpts[i].v = pts[i].v * tex->height;
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = (alpha << 16) | 0x00ff;
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::tpoly_a (int count,VngoPointF pts[],VngoTexture *tex,long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING
                   | LL_LIGHTING_INTERP_RGB | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    int shade = int(pts[0].shade);

    if (shade > mp)
        shade= mp;

    float modifier = (255.f / float(mp));
    shade = int(float(shade) * modifier);
    if (shade > 255)
        shade = 255;
    else if (shade < 0)
        shade = 0;

    rgb = shade | (shade << 8) | (shade << 16);

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
        tpts[i].u = Flx16(pts[i].u * float(tex->width)).flx;
        tpts[i].v = Flx16(pts[i].v * float(tex->height)).flx;
    }

    // clip the apha to a valid range.

    if (alpha < 0)
        alpha = 0;
    else if (alpha > 255)
        alpha = 255;

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = ((255-alpha) << 16) | (alpha);
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::tpoly_persp_a (int count,VngoPoint pts[],VngoTexture *tex,long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING
                   | LL_LIGHTING_INTERP_RGB | LL_PERSPECTIVE | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    int shade = int(pts[0].shade);

    if (shade > mp)
        shade= mp;

    float modifier = (255.f / float(mp));
    shade = int(float(shade) * modifier);
    if (shade > 255)
        shade = 255;
    else if (shade < 0)
        shade = 0;

    rgb = shade | (shade << 8) | (shade << 16);

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
        tpts[i].u = pts[i].u * tex->width;
        tpts[i].v = pts[i].v * tex->height;
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = ((255-alpha) << 16) | (alpha);
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::tpoly_persp_a (int count,VngoPointF pts[],VngoTexture *tex,long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING
                   | LL_LIGHTING_INTERP_RGB | LL_PERSPECTIVE | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    int shade = int(pts[0].shade);

    if (shade > mp)
        shade= mp;

    float modifier = (255.f / float(mp));
    shade = int(float(shade) * modifier);
    if (shade > 255)
        shade = 255;
    else if (shade < 0)
        shade = 0;

    rgb = shade | (shade << 8) | (shade << 16);

    for (int i=0;i < count;i++)
    {
        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword (pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
        tpts[i].u = Flx16(pts[i].u * float(tex->width)).flx;
        tpts[i].v = Flx16(pts[i].v * float(tex->height)).flx;
        tpts[i].w = pts[i].w;
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = ((255-alpha) << 16) | (alpha);
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gtpoly_a (int count,VngoPoint pts[],VngoTexture *tex,long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING
                   | LL_LIGHTING_INTERP_RGB | LL_GOURAUD | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));


    for (int i=0;i < count;i++)
    {
        int shade = int(pts[i].shade);

        if (shade > mp)
            shade= mp;

        shade = int(float(shade) * modifier);
        if (shade > 255)
            shade = 255;
        else if (shade < 0)
            shade = 0;

        rgb = shade | (shade << 8) | (shade << 16);

        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
        tpts[i].u = pts[i].u * tex->width;
        tpts[i].v = pts[i].v * tex->height;
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = (alpha << 16) | 0x00ff;
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}


VNGError VngoVportCL3D::gtpoly_a (int count,VngoPointF pts[],VngoTexture *tex,long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_LIGHTING
                   | LL_LIGHTING_INTERP_RGB | LL_GOURAUD | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));


    for (int i=0;i < count;i++)
    {
        int shade = int(pts[i].shade);

        if (shade > mp)
            shade= mp;

        shade = int(float(shade) * modifier);
        if (shade > 255)
            shade = 255;
        else if (shade < 0)
            shade = 0;

        rgb = shade | (shade << 8) | (shade << 16);

        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
        tpts[i].u = Flx16(pts[i].u * float(tex->width)).flx;
        tpts[i].v = Flx16(pts[i].v * float(tex->height)).flx;
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = (alpha << 16) | 0x00ff;
    pB++;

    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gtpoly_persp_a (int count,VngoPoint pts[],VngoTexture *tex,long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_GOURAUD | LL_ALPHA
                   | LL_LIGHTING | LL_LIGHTING_INTERP_RGB | LL_PERSPECTIVE;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));


    for (int i=0;i < count;i++)
    {
        int shade = int(pts[i].shade);

        if (shade > mp)
            shade= mp;

        shade = int(float(shade) * modifier);
        if (shade > 255)
            shade = 255;
        else if (shade < 0)
            shade = 0;

        rgb = shade | (shade << 8) | (shade << 16);

        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = pts[i].z;
        tpts[i].dwColor = rgb;
        tpts[i].u = pts[i].u * tex->width;
        tpts[i].v = pts[i].v * tex->height;
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = (alpha << 16) | 0x00ff;
    pB++;


    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

VNGError VngoVportCL3D::gtpoly_persp_a (int count,VngoPointF pts[],VngoTexture *tex,long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    LL_Batch *pB = screen->get_batch(2);
    LL_Vert *tpts = (LL_Vert*)ivory_arena_alloc (screen->VertPool,count*sizeof( LL_Vert ));


    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_CLEAR3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoCL3DTexture3D(tex,vbuff.pal);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoCL3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    dword dflags = LL_POLY_FAN | LL_DITHER | LL_TEXTURE | LL_GOURAUD
                   | LL_LIGHTING | LL_LIGHTING_INTERP_RGB | LL_PERSPECTIVE | LL_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        dflags |= LL_Z_BUFFER;
    }
    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
        dflags |= LL_TEX_DECAL;

    dword rgb;

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));


    for (int i=0;i < count;i++)
    {
        int shade = int(pts[i].shade);

        if (shade > mp)
            shade= mp;

        shade = int(float(shade) * modifier);
        if (shade > 255)
            shade = 255;
        else if (shade < 0)
            shade = 0;

        rgb = shade | (shade << 8) | (shade << 16);

        tpts[i].x = (left << 16) + Flx16(pts[i].x).flx;
        tpts[i].y = (top << 16) +  Flx16(pts[i].y).flx;
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].dwColor = rgb;
        tpts[i].u = Flx16(pts[i].u * float(tex->width)).flx;
        tpts[i].v = Flx16(pts[i].v * float(tex->height)).flx;
        tpts[i].w = pts[i].w;
    }

    pB->bOp     = LL_SET_CONSTANT_ALPHA;
    pB->dwFlags = (alpha << 16) | 0x00ff;
    pB++;


    pB->bOp     = LL_POLY;
    pB->wCount  = count - 2;
    pB->dwFlags = dflags;
    pB->dwBuf   = dword(((VngoCL3DTexture3D*)tptr)->DeviceSurface);
    pB->pVert   = tpts;

    return VNGO_NO_ERROR;
}

//°±² End of module - vngvvp8.cpp ²±°
