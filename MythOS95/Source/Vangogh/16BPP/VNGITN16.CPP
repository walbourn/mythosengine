//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  |
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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
// vngitn16.cpp
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
// This is more Virtual View Port stuff.                                    ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ


VNGError VngoVVport16::image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags)
{
    long        w,h;
    VNGError    ret_val = VNGO_NO_ERROR;
    VngoRect    dr;

    VngoPal *temp_pal = vbuff.pal;
    if (img->pal_ptr)
        vbuff.pal = img->pal_ptr;

    if (flags & VNGO_STRETCH)
    {
        ret_val = VNGO_NOT_SUPPORTED;
        goto DONE;
//        return (VNGO_NOT_SUPPORTED);
    }

    if ((img->flags & VNGO_TEXTURE_15BIT && vbuff.pal->flags & VNGO_16BIT)
        || (img->flags & VNGO_TEXTURE_16BIT && vbuff.pal->flags & VNGO_15BIT))
    {
        ret_val = VNGO_UNSUPPORTED_TEXTURE;
        goto DONE;
//        return (VNGO_UNSUPPORTED_TEXTURE);
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
            goto DONE;
//            return VNGO_NO_ERROR;
        }
    }
#if 0       // For now we will clip everything.
    else
#endif
    {
        if (img->flags & VNGO_TEXTURE_COMPRESSED)
        {
            ret_val = VNGO_UNSUPPORTED_TEXTURE;
            goto DONE;
//            return VNGO_UNSUPPORTED_TEXTURE;
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
            if (xcount > 0)
            {
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
                    word             *stable = &tc->shl[vbuff.pal->shd_pal->mid_point >> 3];
                    for (int i=0;i < ycount;i++)
                    {
                        vngo_iline8to16(lptr,btptr,xcount,stable,flags);
                        lptr  += (vbuff.pitch >> 1);
                        btptr += img->width;
                    }
                }
            }
        }
    }
DONE:
    vbuff.pal = temp_pal;
    return ret_val;
}



VNGError VngoVVport16::zblit_mono (VngoRect *dest_rect,VngoZMap *img,dword fgcol,dword bgcol)
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


VNGError VngoVVport16::image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword _fgcol,dword _bgcol)
{
    dword   fgcol,bgcol;
    long    w,h,x,y;

    if (_fgcol == VNGO_TRANSPARENT || _fgcol == VNGO_TRANSPARENT_COLOR)
    {
        fgcol = VNGO_TRANSPARENT;
    }
    else
    {
        if (_fgcol & (VNGO_COLOR_24BIT | VNGO_COLOR_15BIT | VNGO_COLOR_16BIT))
        {
            if ((_fgcol & VNGO_COLOR_15BIT)
                && (vbuff.pal->flags & VNGO_15BIT))
            {
                fgcol = _fgcol;
            }
            else if ((_fgcol & VNGO_COLOR_16BIT)
                     && (vbuff.pal->flags & VNGO_16BIT))
            {
                fgcol = _fgcol;
            }
            else
                return VNGO_INTERNAL_ERROR;
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
    }

    if (_bgcol == VNGO_TRANSPARENT || _bgcol == VNGO_TRANSPARENT_COLOR)
    {
        bgcol = VNGO_TRANSPARENT;
    }
    else
    {
        if (_bgcol & (VNGO_COLOR_24BIT | VNGO_COLOR_15BIT | VNGO_COLOR_16BIT))
        {
            if ((_bgcol & VNGO_COLOR_15BIT)
                && (vbuff.pal->flags & VNGO_15BIT))
            {
                bgcol = _bgcol;
            }
            else if ((_bgcol & VNGO_COLOR_16BIT)
                     && (vbuff.pal->flags & VNGO_16BIT))
            {
                bgcol = _bgcol;
            }
            else
                return VNGO_INTERNAL_ERROR;
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
        t += (dword)vbuff.scrn_ptr + (x << 1);
        xskip &= 0x7;
        while (h > 0)
        {
            vngo_ilinemono16((word *)t,ptr,w,xskip,fgcol,bgcol);
            ptr += pitch;
            t += vbuff.pitch;
            --h;
        }

    }
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::vpcopy(int destx,int desty,VngoVport *vp)
{
    return VNGO_NOT_SUPPORTED;
}

//°±² End of module - vngitns8.cpp ²±°

