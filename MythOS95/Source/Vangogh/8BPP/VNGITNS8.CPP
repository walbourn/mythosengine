
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
// vngitns8.cpp
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
// This is more Virtual View Port stuff.                                    ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ


VNGError VngoVVport8::image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags)
{
    assert(lock_status);

    long        w,h;
    VngoRect    dr;

    if (flags & VNGO_STRETCH)
    {
        if (img->flags & VNGO_TEXTURE_8BIT)
        {
            vngo_stretch_blt8(this, dest_rect,img);
            return (VNGO_NO_ERROR);
        }
        else
        {
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }

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

    if (((dest_rect->x + w) <= vbuff.width) &&
        ((dest_rect->y + h) <= vbuff.height) &&
        (dest_rect->x >= 0) && (dest_rect->y >= 0))
    {
        if (img->flags & VNGO_TEXTURE_COMPRESSED)
        {
            for (int y=0;y < img->height;y++)
            {
                byte *ptr = &(((byte*)img->tex)[((VngoCTexture*)img)->ytable[y]]);
                long cnt = *((short *)ptr);
                ptr += 2;
                byte *destptr = vbuff.scrn_ptr + vbuff.ytable[dest_rect->y + y] + dest_rect->x;
                long dcount = 0;
                while (dcount < img->width)
                {
                    memcpy(destptr,ptr,cnt);
                    dcount += cnt;
                    ptr += cnt;
                    destptr += cnt;
                    cnt = *((short *)ptr);
                    ptr +=2;
                    destptr += cnt;
                    dcount += cnt;
                    cnt = *((short *)ptr);
                    ptr +=2;
                }
            }
        }
        else
            vngo_itrans8 (&vbuff,&dr,img,flags);
    }
    else
    {
        if (img->flags & VNGO_TEXTURE_COMPRESSED)
            return VNGO_UNSUPPORTED_TEXTURE;

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
                    ycount = (vbuff.height) - dest_rect->y;
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
                    xcount = (vbuff.width) - dest_rect->x;
            }
            else        // starting X is negative in this case.
            {
                tx = -dest_rect->x;
                if ((dest_rect->x + w) > vbuff.width)
                {
                    xcount = (vbuff.width);
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

#if 0
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
#endif


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
        if ((y + h) >= vbuff.height)
        {
            h = vbuff.height - y;
        }
        if ((x + w) >= vbuff.width)
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
        ptr += (yskip * pitch + ((xskip - (xskip & 0x7)) >> 3));
        t += (dword)vbuff.scrn_ptr;
        xskip &= 0x7;
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


VNGError VngoVVport8::vpcopy(int destx,int desty,VngoVport *vp)
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

//°±² End of module - vngitns8.cpp ²±°

