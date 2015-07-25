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
// vngsmth.cpp
//
//     A smooth shaded rectangle that can have different colors at each
//     vertex.
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


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
extern long RedDitherMatrix[4][4];
extern long GreenDitherMatrix[4][4];
extern long BlueDitherMatrix[4][4];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

void vngo_smooth_rect (VngoVport *vp,
                       VngoPoint *pts,
                       VngoRect  *clip)
{
    int prestepx=0,prestepy=0;
    int dy = pts[2].y - pts[0].y;
    int dx = pts[1].x - pts[0].x;

    VngoColor24bit colors[4];
    for (int corners=0;corners < 4;corners++)
    {
        if (pts[corners].clr & VNGO_COLOR_24BIT)
        {
            int t = pts[corners].clr;
            colors[corners].r = t >> 16;
            colors[corners].g = (t >> 8) & 0xff;
            colors[corners].b = t & 0xff;
        }
        else if ( pts[corners].clr & VNGO_COLOR_16BIT)
        {
            int t = pts[corners].clr;
            colors[corners].r = (t >> 8) & 0xf8;
            colors[corners].g = (t >> 3) & 0xfc;
            colors[corners].b = (t << 3) & 0xf8;
        }
        else if ( pts[corners].clr & VNGO_COLOR_15BIT)
        {
            int t = pts[corners].clr;
            colors[corners].r = (t >> 7) & 0xf8;
            colors[corners].g = (t >> 2) & 0xf8;
            colors[corners].b = (t << 3) & 0xf8;
        }
        else
        {
            VngoShadePal *shade=(VngoShadePal*)vp->vbuff.pal->shd_pal;
            int t;
            if (vp->vbuff.pal->flags & VNGO_15BIT)
            {
                t = ((VngoShadePal16*)shade)->get_shaded_index(pts[corners].clr,pts[corners].shade);
                colors[corners].r = (t >> 7) & 0xf8;
                colors[corners].g = (t >> 2) & 0xf8;
                colors[corners].b = (t << 3) & 0xf8;
            }
            else if (vp->vbuff.pal->flags & VNGO_16BIT)
            {
                t = ((VngoShadePal16*)shade)->get_shaded_index(pts[corners].clr,pts[corners].shade);
                colors[corners].r = (t >> 8) & 0xf8;
                colors[corners].g = (t >> 3) & 0xfc;
                colors[corners].b = (t << 3) & 0xf8;
            }
            else
            {
                t = ((VngoShadePal8*)shade)->get_shaded_index(pts[corners].clr,pts[corners].shade);
                colors[corners] = vp->vbuff.pal->get_RGB(t);
            }
        }

    }

    if (dx < 1 && dy < 1)
    {
        if ((pts[0].x >= 0) && (pts[0].y >= 0)
            && (pts[0].x < vp->vbuff.width)
            && (pts[0].y < vp->vbuff.height))
        {
            if (clip)
            {
                if ((pts[0].x < clip->x) || (pts[0].y < clip->y)
                    || (pts[0].x > (clip->x + clip->dx))
                    || (pts[0].y > (clip->y + clip->dy)))
                {
                    return;
                }
            }
            vp->pixel(pts,&colors[0]);
        }
        return;
    }

    VngoRect    trect (0,0,vp->vbuff.width,vp->vbuff.height);


// Clip to the viewport and the rectangle.

    int xrun = dx;
    int yrun = dy;
    int xstart = pts[0].x;
    int ystart = pts[0].y;


    if (clip)
    {
        trect.clip_to(*clip);
    }
    if (ystart > (trect.y + trect.dy))
        return;
    if ((ystart + yrun) < trect.y)
        return;
    if (xstart > (trect.x + trect.dx))
        return;
    if ((xstart + yrun) < trect.x)
        return;

    if (xstart < trect.x)
    {
        prestepx += (trect.x - xstart);
        xrun -= trect.x - xstart;
        xstart = trect.x;
    }
    if ((xstart + xrun) >= (trect.x + trect.dx))
    {
        xrun = (trect.x + trect.dx - 1) - xstart;
    }

    if (ystart < trect.y)
    {
        prestepy += trect.y - ystart;
        yrun -= trect.y - ystart;
        ystart = trect.y;
    }
    if ((ystart + yrun) >= (trect.y + trect.dy))
    {
        yrun = (trect.y + trect.dy - 1) - ystart;

    }

    if (yrun == 0 || xrun == 0)
        return;

    VngoPal *lpal = vp->vbuff.pal;


    VngoPoint   tpoint;
    tpoint.shade = lpal->shd_pal->mid_point;

    int lr,lrs,rr,rrs;
    int lg,lgs,rg,rgs;
    int lb,lbs,rb,rbs;

    VngoShadePal8 *tshd = (VngoShadePal8 *)lpal->shd_pal;

    VngoColor24bit lstart = colors[0];
    VngoColor24bit lend   = colors[3];
    VngoColor24bit rstart = colors[1];
    VngoColor24bit rend   = colors[2];


    int tr,tg,tb;
    int trs,tgs,tbs;
    int ler,leg,leb,rer,reg,reb;

    lr = (int)lstart.r << 16;
    lg = (int)lstart.g << 16;
    lb = (int)lstart.b << 16;
    ler = (int) lend.r << 16;
    leg = (int) lend.g << 16;
    leb = (int) lend.b << 16;

    rr = (int)rstart.r << 16;
    rg = (int)rstart.g << 16;
    rb = (int)rstart.b << 16;
    rer = (int) rend.r << 16;
    reg = (int) rend.g << 16;
    reb = (int) rend.b << 16;

    int yshift = 0;
    int xshift = 0;

    if (dx == 2)
        xshift = 1;
    else if (dx == 4)
        xshift = 2;
    else if (dx == 8)
        xshift = 3;
    else if (dx == 16)
        xshift = 4;
    else if (dx == 32)
        xshift = 5;


    if (dy == 2)
        yshift = 1;
    else if (dy == 4)
        yshift = 2;
    else if (dy == 8)
        yshift = 3;
    else if (dy == 16)
        yshift = 4;
    else if (dy == 32)
        yshift = 5;

    if (prestepx)
    {
        if (xshift)
        {
            trs = (rr - lr) >> xshift;
            lr = lr + (trs * prestepx);

            tgs = (rg - lg) >> xshift;
            lg = lg + (tgs * prestepx);

            tbs = (rb - lb) >> xshift;
            lb = lb + (tbs * prestepx);

            tbs = (rer - ler) >> xshift;
            ler = ler + (tbs * prestepx);

            tbs = (reg - leg) >> xshift;
            leg = leg + (tbs * prestepx);

            tbs = (reb - leb) >> xshift;
            leb = leb + (tbs * prestepx);
        }
        else
        {
            trs = (rr - lr) / dx;
            lr = lr + (trs * prestepx);

            tgs = (rg - lg) / dx;
            lg = lg + (tgs * prestepx);

            tbs = (rb - lb) / dx;
            lb = lb + (tbs * prestepx);


            tbs = (rer - ler) / dx;
            ler = ler + (tbs * prestepx);

            tbs = (reg - leg) / dx;
            leg = leg + (tbs * prestepx);

            tbs = (reb - leb) / dx;
            leb = leb + (tbs * prestepx);
        }
        dx -= prestepx;

        if (dx == 2)
            xshift = 1;
        else if (dx == 4)
            xshift = 2;
        else if (dx == 8)
            xshift = 3;
        else if (dx == 16)
            xshift = 4;
        else if (dx == 32)
            xshift = 5;
        else
            xshift = 0;
    }

    if (yshift)
    {
        lrs = (ler - lr) >> yshift;
        lgs = (leg - lg) >> yshift;
        lbs = (leb - lb) >> yshift;
        rrs = (rer - rr) >> yshift;
        rgs = (reg - rg) >> yshift;
        rbs = (reb - rb) >> yshift;
    }
    else
    {
        lrs = (ler - lr + 1) / dy;
        lgs = (leg - lg + 1) / dy;
        lbs = (leb - lb + 1) / dy;
        rrs = (rer - rr) / dy;
        rgs = (reg - rg) / dy;
        rbs = (reb - rb) / dy;
    }

    if (prestepy)
    {
        lr = lr + (lrs * prestepy);
        lg = lg + (lgs * prestepy);
        lb = lb + (lbs * prestepy);
        rr = rr + (rrs * prestepy);
        rg = rg + (rgs * prestepy);
        rb = rb + (rbs * prestepy);
    }

    if (xshift)
    {
        for (int i=0; i <= yrun;i++)
        {
            tr = lr;
            tg = lg;
            tb = lb;
            trs = (rr - lr) >> xshift;
            tgs = (rg - lg) >> xshift;
            tbs = (rb - lb) >> xshift;

            for (int j=0;j <= xrun; j++)
            {
                tpoint.x = xstart + j;
                tpoint.y = ystart + i;
                VngoColor24bit tclr;
                int t;
                if (tclr.r < 0)
                    tclr.r = 0;
                if (tclr.g < 0)
                    tclr.g = 0;
                if (tclr.b < 0)
                    tclr.b = 0;

                tclr.r = ((t = ((tr + RedDitherMatrix[tpoint.x&3][tpoint.y&3]) >> 16)) > 255) ? 255 : t;
                tclr.g = ((t = ((tg + GreenDitherMatrix[tpoint.x&3][tpoint.y&3]) >> 16)) > 255) ? 255 : t;
                tclr.b = ((t = ((tb + BlueDitherMatrix[tpoint.x&3][tpoint.y&3]) >> 16)) > 255) ? 255 : t;

                vp->pixel(&tpoint,&tclr);

                tr += trs;
                tg += tgs;
                tb += tbs;
            }
            lr += lrs;
            lg += lgs;
            lb += lbs;
            rr += rrs;
            rg += rgs;
            rb += rbs;
        }
    }
    else
    {
        for (int i=0; i <= yrun;i++)
        {
            tr = lr;
            tg = lg;
            tb = lb;
            trs = (rr - lr) / dx;
            tgs = (rg - lg) / dx;
            tbs = (rb - lb) / dx;

            for (int j=0;j <= xrun; j++)
            {
                tpoint.x = xstart + j;
                tpoint.y = ystart + i;

//                VngoColor24bit tclr (byte((tr + RedDitherMatrix[tpoint.x&3][tpoint.y&3]) >> 16),
//                                     byte((tg + GreenDitherMatrix[tpoint.x&3][tpoint.y&3]) >> 16),
//                                     byte((tb + BlueDitherMatrix[tpoint.x&3][tpoint.y&3]) >> 16));
                VngoColor24bit tclr;
                int t;
                if (tclr.r < 0)
                    tclr.r = 0;
                if (tclr.g < 0)
                    tclr.g = 0;
                if (tclr.b < 0)
                    tclr.b = 0;

                tclr.r = ((t = ((tr + RedDitherMatrix[tpoint.x&3][tpoint.y&3]) >> 16)) > 255) ? 255 : t;
                tclr.g = ((t = ((tg + GreenDitherMatrix[tpoint.x&3][tpoint.y&3]) >> 16)) > 255) ? 255 : t;
                tclr.b = ((t = ((tb + BlueDitherMatrix[tpoint.x&3][tpoint.y&3]) >> 16)) > 255) ? 255 : t;

                vp->pixel(&tpoint,&tclr);

                tr += trs;
                tg += tgs;
                tb += tbs;
            }
            lr += lrs;
            lg += lgs;
            lb += lbs;
            rr += rrs;
            rg += rgs;
            rb += rbs;
        }
    }
}

VNGError vngo_smooth_blit(VngoVport *vp, VngoTexture *img,
                      VngoRect  *target,VngoRect *clip)
{
    if ((target->dx <  img->width) || (target->dy < img->height))
    {
        // this is compressing the image, and we don't do that yet.
        return VNGO_NOT_SUPPORTED;
    }
    else if (target->dx == img->width && target->dy == img->height)
    {
        return vp->image_trans(target,img);
    }
    // we now know that at least one dimention is being stretched.

    VngoPoint   pts[4];

    float       wstep,hstep;
    dword       cflags = 0;

    wstep = float(target->dx)/float(img->width);
    hstep = float(target->dy)/float(img->height);

    if (!(img->flags & VNGO_TEXTURE_8BIT))
        return VNGO_NOT_SUPPORTED;

    byte *topclr = (byte*)img->tex;
    byte *botclr = topclr + img->width;
    float   tx,ty,rtx,rty;
    rtx = tx = float(target->x);
    rty = ty = float(target->y);
    int mp = vp->vbuff.pal->shd_pal->mid_point;


    pts[0].shade = pts[1].shade = pts[2].shade = pts[3].shade = mp;
    pts[0].z = pts[1].z = pts[2].z = pts[3].z = 0;

    for (int y=0;y < img->height-1;y++)
    {
        tx = rtx;
        ty = rty;
        for (int x=0;x < img->width -1;x++)
        {
            pts[0].x = int(tx + 0.5f);
            pts[0].y = int(ty + 0.5f);
            pts[0].clr = topclr[x];

            pts[3].x = int(tx + 0.5f);
            pts[3].y = int(ty + hstep + 0.5f);
            pts[3].clr = topclr[x];

            tx += wstep;

            pts[1].x = int(tx + 0.5f);
            pts[1].y = int(ty + 0.5f);
            pts[1].clr = topclr[x+1];

            pts[2].x = int(tx + 0.5f);
            pts[2].y = int(ty + hstep + 0.5f);
            pts[2].clr = botclr[x+1];

            vngo_smooth_rect (vp,pts,clip);
        }
        topclr = botclr;
        botclr += img->width;
        rty += hstep;
    }
    return VNGO_NO_ERROR;
}


//°±² End of module - vngsmth.cpp ²±°

