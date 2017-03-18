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
// vngsblt8.cpp
//
//     Stretch blit routines.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#include <assert.h>

#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


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

void vngo_stretch_zblt_copy8 (VngoVbuffer *vb,VngoRect *dest,VngoTexture *tex,word *zsrc);
void vngo_stretch_zblt_cmp8 (VngoVbuffer *vb,VngoRect *dest,VngoTexture *tex,word *zsrc);
void vngo_stretch_zblt_cmp_eq8 (VngoVbuffer *vb,VngoRect *dest,VngoTexture *tex,word *zsrc);

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



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  void vngo_stretch_blt8 (VngoVport *vp, VngoRect *dest_rect,
//                          VngoTexture *img, dword flags);
//
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

void vngo_stretch_blt8 (VngoVport *vp, VngoRect *dest_rect,
                        VngoTexture *img, dword flags)
{
    Flx16 ustep;
    Flx16 vstep;
    Flx16 cur_u = 0;
    Flx16 cur_v = 0;

    ustep = Flx16 (img->width) / Flx16(dest_rect->dx);
    vstep = Flx16 (img->height) / Flx16(dest_rect->dy);

    byte    *hptr = vp->vbuff.scrn_ptr
                    + vp->vbuff.ytable[dest_rect->y]
                    + dest_rect->x;

    if (flags & VNGO_TRANSPARENT)
    {
        for (int y=0;y < dest_rect->dy;y++)
        {
            byte    *sptr = (byte*)img->tex + (((cur_v.flx + 0x8000) >> 16) * img->width);
            cur_u = 0;
            for (int x=0; x < dest_rect->dx;x++)
            {
                byte    t = sptr[(cur_u.flx + 0x8000) >> 16];
                if (t != VNGO_TRANSPARENT_COLOR)
                    hptr[x] = t;
                cur_u += ustep;
            }
            hptr += vp->vbuff.pitch;
            cur_v += vstep;
        }
    }
    else
    {
        for (int y=0;y < dest_rect->dy;y++)
        {
            byte    *sptr = (byte*)img->tex + (((cur_v.flx + 0x8000) >> 16) * img->width);
            cur_u = 0;
            for (int x=0; x < dest_rect->dx;x++)
            {
                hptr[x] = sptr[(cur_u.flx + 0x8000) >> 16];
                cur_u += ustep;
            }
            hptr += vp->vbuff.pitch;
            cur_v += vstep;
        }
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  void vngo_stretch_zblt8 (VngoVport *vp, VngoRect *dest_rect,
//                           VngoTexture *img, word *zsource, dword flags);
//
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

void vngo_stretch_zblt8 (VngoVport *vp, VngoRect *dest_rect,
                         VngoTexture *img, word *zsource, dword flags)
{
#if 0
    if (!(flags & VNGO_TRANSPARENT))
    {
        if (flags & VNGO_COMPARE_EQUAL)
        {
            vngo_stretch_zblt_cmp_eq8 (&(vp->vbuff),dest_rect,img,zsource);
        }
        else if (flags & VNGO_COMPARE)
        {
            vngo_stretch_zblt_cmp8 (&(vp->vbuff),dest_rect,img,zsource);
        }
        else
        {
            vngo_stretch_zblt_copy8 (&(vp->vbuff),dest_rect,img,zsource);
        }
    }
#endif

    Flx16 ustep;
    Flx16 vstep;
    Flx16 cur_u = 0;
    Flx16 cur_v = 0;

    ustep = Flx16 (img->width) / Flx16(dest_rect->dx);
    vstep = Flx16 (img->height) / Flx16(dest_rect->dy);

    byte    *hptr = vp->vbuff.scrn_ptr
                    + vp->vbuff.ytable[dest_rect->y]
                    + dest_rect->x;

    word    *zptr = vp->vbuff.zbuff_ptr
                    + vp->vbuff.ztable[dest_rect->y]
                    + dest_rect->x;

    long    Ivstep = long(vstep) * img->width;
    long    Fvstep = vstep.flx & 0xffff;
    long    fstep = 0;
    long    twidth = img->width;

    byte    *sptr = (byte*)img->tex;
    word    tz;
    long    pitch = vp->vbuff.pitch;
    long    zpitch = vp->vbuff.zpitch >> 1;
    long    width = dest_rect->dx;

    if (flags & VNGO_COMPARE_EQUAL)
    {
        if (flags & VNGO_TRANSPARENT)
        {
            for (int y=0;y < dest_rect->dy;y++)
            {
                dword   offset = ((cur_v.flx >> 16) * img->width);
                cur_u = 0;
                for (int x=0; x < dest_rect->dx;x++)
                {
                    if ((word)zptr[x] >= (tz = zsource[offset + (cur_u.flx >> 16)]))
                    {
                        byte    t = sptr[offset + (cur_u.flx >> 16)];
                        if (t != VNGO_TRANSPARENT_COLOR)
                        {
                            zptr[x] = tz;
                            hptr[x] = t;
                        }
                    }
                    cur_u += ustep;
                }
                hptr += vp->vbuff.pitch;
                zptr += vp->vbuff.zpitch >> 1;
                cur_v += vstep;
            }
        }
        else
        {
            for (int y=0;y < dest_rect->dy;y++)
            {
                dword   offset = ((cur_v.flx >> 16) * img->width);
                cur_u = 0;
                for (int x=0; x < dest_rect->dx;x++)
                {
                    if ((word)zptr[x] >= (tz = zsource[offset + (cur_u.flx >> 16)]))
                    {
                        zptr[x] = tz;
                        hptr[x] = sptr[offset + (cur_u.flx >> 16)];
                    }

                    cur_u += ustep;
                }
                hptr += vp->vbuff.pitch;
                zptr += vp->vbuff.zpitch >> 1;
                cur_v += vstep;
            }
        }
    }
    else if (flags & VNGO_COMPARE)
    {
        if (flags & VNGO_TRANSPARENT)
        {
            for (int y=0;y < dest_rect->dy;y++)
            {
                dword   offset = ((cur_v.flx >> 16) * img->width);
                cur_u = 0;
                for (int x=0; x < dest_rect->dx;x++)
                {
                    if ((word)zptr[x] > (tz = zsource[offset + (cur_u.flx >> 16)]))
                    {
                        byte    t = sptr[offset + (cur_u.flx >> 16)];
                        if (t != VNGO_TRANSPARENT_COLOR)
                        {
                            zptr[x] = tz;
                            hptr[x] = t;
                        }
                    }
                    cur_u += ustep;
                }
                hptr += vp->vbuff.pitch;
                zptr += vp->vbuff.zpitch >> 1;
                cur_v += vstep;
            }
        }
        else
        {
            for (int y=0;y < dest_rect->dy;y++)
            {
                dword   offset = ((cur_v.flx >> 16) * img->width);
                cur_u = 0;
                for (int x=0; x < dest_rect->dx;x++)
                {
                    if ((word)zptr[x] > (tz = zsource[offset + (cur_u.flx >> 16)]))
                    {
                        zptr[x] = tz;
                        hptr[x] = sptr[offset + (cur_u.flx >> 16)];
                    }

                    cur_u += ustep;
                }
                hptr += vp->vbuff.pitch;
                zptr += vp->vbuff.zpitch >> 1;
                cur_v += vstep;
            }
        }
    }
    else
    {

        if (flags & VNGO_TRANSPARENT)
        {
            for (int y=0;y < dest_rect->dy;y++)
            {
                dword   offset = ((cur_v.flx >> 16) * img->width);
                cur_u = 0;
                for (int x=0; x < dest_rect->dx;x++)
                {
                    byte    t = sptr[offset + (cur_u.flx >> 16)];
                    if (t != VNGO_TRANSPARENT_COLOR)
                    {
                        hptr[x] = t;
                        zptr[x] = zsource[offset + (cur_u.flx >> 16)];
                    }
                    cur_u += ustep;
                }
                hptr += vp->vbuff.pitch;
                zptr += vp->vbuff.zpitch >> 1;
                cur_v += vstep;
            }
        }
        else
        {
            word *zsrc = zsource;
            int     x;
            for (int y=0;y < dest_rect->dy;y++)
            {
                cur_u = 0;
                if (width >= 4)
                {
                    for (x=0; x < width;x+=4)
                    {
                        long    t1 = cur_u.flx >> 16;
                        long    t2 = (cur_u += ustep).flx >> 16;
                        long    t3 = (cur_u += ustep).flx >> 16;
                        long    t4 = (cur_u += ustep).flx >> 16;

                        dword   tclr = sptr[t4];
                        tclr <<= 8;
                        tclr |= sptr[t3];
                        tclr <<=8;
                        tclr |= sptr[t2];
                        tclr <<=8;
                        tclr |= sptr[t1];
                        *((dword *)&(hptr[x])) = tclr;

                        tclr = zsrc[t2];
                        tclr <<= 16;
                        tclr |= zsrc[t1];
                        *((dword *)&(zptr[x])) = tclr;

                        tclr = zsrc[t4];
                        tclr <<= 16;
                        tclr |= zsrc[t3];
                        *((dword *)&(zptr[x+2])) = tclr;

                        cur_u += ustep;
                    }
                }
                else
                {
                    x = 4;
                }
                for (x-=4; x <= width;x++)
                {
                    long    t = cur_u.flx >> 16;
                    zptr[x] = zsrc[t];
                    hptr[x] = sptr[t];

                    cur_u += ustep;
                }
                hptr += pitch;
                zptr += zpitch;
                zsrc += Ivstep;
                sptr += Ivstep;
                fstep += Fvstep;
                if (fstep > 0xffff)
                {
                    fstep -= 0xffff;
                    zsrc += twidth;
                    sptr += twidth;
                }
            }
        }
    }
}

