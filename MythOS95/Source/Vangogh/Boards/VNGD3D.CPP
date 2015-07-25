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
// vngd3d.cpp
//
//     The C pluss pluss Direct3D view port classes.
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
#include "vngd3d.hpp"

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

extern VngoSystem   VgSystem;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Some service classes first.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

void VngoHazeInfoD3D::setup(VngoHazeInfo *info)
{
    int start_index = int(info->start_depth * 256.f);
    int mid_index = int(info->mid_depth * 256.f);
    for (int i=0;i < start_index;i++)
    {
        fog_lut[i]=255;
    }
    float step1 = 0.5f / float(mid_index - start_index);
    float step2 = 0.5f / float(256-mid_index);
    float accumulator=0.f;
    for (i=start_index;i < mid_index; i++)
    {
        fog_lut[i] = int((1.f - accumulator)*255);
        accumulator += step1;
    }

    for (i=mid_index;i < 256; i++)
    {
        fog_lut[i] = int((1.f - accumulator)*255);
        accumulator += step2;
    }
    target_color = info->target_color;

};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This is the D3D View Port stuff.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ


VngoVportD3D::VngoVportD3D (VngoRect &dim,VngoPal *my_pal,dword flags,VngoScreenManager *_screen)
{
    init_status = init (dim,my_pal,flags,_screen);
}

VNGError VngoVportD3D::init (VngoRect &dim,VngoPal *my_pal,dword flags,VngoScreenManager *_screen)
{
    screen = (VngoDirect3D*)_screen;

    vflags = flags;
    vflags |= VNGO_SKIPS_LAST_PIX;
    vbuff.pal = my_pal;
    vbuff.width = dim.dx;
    vbuff.height = dim.dy;
    top = dim.y;
    left = dim.x;

    if (!(_screen->sins & VNGO_NO_VERTEX_FOG))
        vflags |= VNGO_ACTIVE_HAZE_DEV;

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
        was_locked = plock();
        if (was_locked != -1)
        {
            reset();
            if (!was_locked)
                punlock();
        }
    }

    return (VNGO_NO_ERROR);
}

VngoVportD3D::~VngoVportD3D()
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

void VngoVportD3D::zbuffer_on()
{
    VngoVport::zbuffer_on();
    VgSystem.cur_vport = NULL;
    make_current();
}

void VngoVportD3D::zbuffer_off()
{
    VngoVport::zbuffer_off();
    VgSystem.cur_vport = NULL;
    make_current();
}

void VngoVportD3D::make_current()
{
    if (VgSystem.cur_vport != this)
    {
        VgSystem.cur_vport = this;
        if ((vflags & VNGO_ZBUFFER_DEV)
            && (vflags & VNGO_ZBUFFER_ACTIVE))
        {
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_ZENABLE,TRUE);
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE,TRUE);
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_ZFUNC,D3DCMP_LESSEQUAL);
        }
        else
        {
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_ZENABLE,FALSE);
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE,FALSE);
        }
        if (((vflags & VNGO_TRUE_ALPHA)
            && !(screen->sins & VNGO_NO_TRUE_ALPHA))
            || (screen->sins & VNGO_NO_STIPPLE_ALPHA))
        {
            // setup true alpha here!
        }

        if ((vflags & VNGO_ACTIVE_HAZE_DEV) && (vflags & VNGO_HAZE_ON))
        {
            float one = 1.f;
            float zero = 0.0f;
            float two55 = 255.f;
#if 1
            screen->d3dDevice->SetLightState(D3DLIGHTSTATE_FOGMODE,D3DFOG_LINEAR);
            screen->d3dDevice->SetLightState(D3DLIGHTSTATE_FOGSTART,*((dword *)&one));
            screen->d3dDevice->SetLightState(D3DLIGHTSTATE_FOGEND,*((dword *)&two55));
            screen->d3dDevice->SetLightState(D3DLIGHTSTATE_FOGDENSITY,*((dword*)&one));
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGCOLOR,dword(fog_table.target_color.r<<16 |
                                                                              fog_table.target_color.g<< 8 |
                                                                              fog_table.target_color.b));
/*
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGCOLOR,D3DRGBA(fog_table.target_color.r,
                                                                              fog_table.target_color.g,
                                                                              fog_table.target_color.b,
                                                                              0));
*/
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE,TRUE);
#else
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE,TRUE);
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGCOLOR,D3DRGB(fog_table.target_color.r,fog_table.target_color.g,fog_table.target_color.b));
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGTABLEMODE,D3DFOG_LINEAR);
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGTABLESTART,*((dword *)&zero));
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGTABLEEND,*((dword *)&one));
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGTABLEDENSITY,*((dword*)&one));
#endif
            // Setup the hazing info from the viewport....
        }
        else
        {
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE,FALSE);
        }

        if (vflags & VNGO_TEXTURE_FILTER)
        {
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMAG, D3DFILTER_LINEAR);
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMIN, D3DFILTER_LINEAR);
        }
        else
        {
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMAG, D3DFILTER_NEAREST);
            screen->d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMIN, D3DFILTER_NEAREST);
        }
    }
}


void VngoVportD3D::reset(dword c,dword farz)
{
    make_current();

    HRESULT         ddrval;
    DDBLTFX         ddbltfx;
    RECT            destRect;
    // Use direct draw to clear the screen.

    memset(&ddbltfx, 0,sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);

    VngoColor24bit rgb = vbuff.pal->get_RGB(c);
    if (vbuff.pal->flags & VNGO_15BIT)
        ddbltfx.dwFillColor = rgb.compress();
    else
        ddbltfx.dwFillColor = rgb.compress16();

    destRect.left   = left;
    destRect.top    = top;
    destRect.right  = left + vbuff.width;
    destRect.bottom = top + vbuff.height;

    int t = punlock();

    int try1=0;
    if (!(vflags & VNGO_NOCLEAR_VBUFFER))
    {
        do
        {
            ddrval = screen->SurfaceManager->ddsurf->Blt( &destRect,
                                              NULL, NULL,
                                              DDBLT_COLORFILL | DDBLT_WAIT,
                                              &ddbltfx );

            if( ddrval == DDERR_SURFACELOST ) {
                ddrval = screen->SurfaceManager->ddsurf->Restore();
            }
            try1++;

        } while((ddrval != DD_OK) && (try1 < 150));
    }

    ddbltfx.dwFillColor = 0;
    ddbltfx.dwFillDepth = farz >> 16;
    try1 = 0;
    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        if( screen->ZBuffer )
        {
            // Use direct draw to clear the ZBuffer.
            do
            {
                ddrval = screen->SurfaceManager->zddsurf->Blt( NULL,
                                               NULL, NULL,
                                               DDBLT_DEPTHFILL | DDBLT_WAIT,
                                               &ddbltfx );

                if( ddrval == DDERR_SURFACELOST )
                {
                    ddrval = screen->SurfaceManager->zddsurf->Restore();
                }
                try1++;
            } while( ddrval != DD_OK && try1 < 150 );
        }
    }
    if (t)
        plock();
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the start of the draw function block of the VngoVportD3D class.  ³
// all fucntions in this class draw to a 8 bit device regardless of the size³
// of the input color information.                                          ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VNGError VngoVportD3D::image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags)
{

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
                    long cnt = *ptr;
                    ptr++;
                    word *destptr = (word*)(vbuff.scrn_ptr + vbuff.ytable[dest_rect->y + y]) + dest_rect->x;
                    long dcount = 0;
                    while (dcount < img->width)
                    {
                        vngo_wordcopy(destptr,ptr,cnt);
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
                    t += (dest_rect->x << 1);
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
                        xcount = vbuff.width;
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
        if (!was_locked)
            punlock();
    }

    return VNGO_NO_ERROR;
}



VNGError VngoVportD3D::zblit_mono (VngoRect *dest_rect,VngoZMap *img,dword fgcol,dword bgcol)
{
    return VNGO_NOT_SUPPORTED;
}


VNGError VngoVportD3D::image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword _fgcol,dword _bgcol)
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
        if (!was_locked)
            punlock();
    }
    return VNGO_NO_ERROR;
}


VNGError VngoVportD3D::vpcopy(int destx,int desty,VngoVport *vp)
{
    return VNGO_NOT_SUPPORTED;
}

VNGError VngoVportD3D::clip_frect(VngoRect *rect,VngoColor24bit *rgb_val, VngoRect *clip)
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

    int t;
    t = punlock();

    RECT    wtrect;
    DDBLTFX ddbltfx;
    wtrect.left = trect.x + left;
    wtrect.right = wtrect.left + trect.dx;
    wtrect.top = trect.y + top;
    wtrect.bottom = wtrect.top + trect.dy;

    ddbltfx.dwSize = sizeof(ddbltfx);
    if (vbuff.pal->flags & VNGO_15BIT)
        ddbltfx.dwFillColor = rgb_val->compress();
    else
        ddbltfx.dwFillColor = rgb_val->compress16();

    screen->SurfaceManager->ddsurf->Blt( &wtrect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);

    if (t)
        plock();
    return VNGO_NO_ERROR;
}


VNGError VngoVportD3D::clip_frect(VngoRect *rect,dword color, VngoRect *clip)
{
    VngoColor24bit tclr;
    if (color & VNGO_COLOR_15BIT)
    {
        tclr.r = byte((color & 0x7c00) >> 7);
        tclr.g = byte((color & 0x3e0) >> 2);
        tclr.b = byte((color & 0x1f) << 3);
    }
    else if (color & VNGO_COLOR_16BIT)
    {
        tclr.r = byte((color & 0xf800) >> 8);
        tclr.g = byte((color & 0x7e0) >> 3);
        tclr.b = byte((color & 0x1f) << 3);
    }
    else
    {
        tclr = vbuff.pal->get_RGB(color);
    }
    return clip_frect(rect,&tclr,clip);
}


VNGError VngoVportD3D::frect(VngoRect *rect,VngoColor24bit *rgb_val)
{
    VngoRect trect = *rect;
    VngoRect vprect(0,0,vbuff.width,vbuff.height);

    int t;
    t = punlock();

    RECT    wtrect;
    DDBLTFX ddbltfx;
    wtrect.left = trect.x + left;
    wtrect.right = wtrect.left + trect.dx;
    wtrect.top = trect.y + top;
    wtrect.bottom = wtrect.top + trect.dy;

    ddbltfx.dwSize = sizeof(ddbltfx);
    if (vbuff.pal->flags & VNGO_15BIT)
        ddbltfx.dwFillColor = rgb_val->compress();
    else
        ddbltfx.dwFillColor = rgb_val->compress16();

    screen->SurfaceManager->ddsurf->Blt( &wtrect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);

    if (t)
        plock();
    return VNGO_NO_ERROR;
}


VNGError VngoVportD3D::frect(VngoRect *rect,dword color)
{
    VngoColor24bit tclr;
    if (color & VNGO_COLOR_15BIT)
    {
        tclr.r = byte((color & 0x7c00) >> 7);
        tclr.g = byte((color & 0x3e0) >> 2);
        tclr.b = byte((color & 0x1f) << 3);
    }
    else if (color & VNGO_COLOR_16BIT)
    {
        tclr.r = byte((color & 0xf800) >> 8);
        tclr.g = byte((color & 0x7e0) >> 3);
        tclr.b = byte((color & 0x1f) << 3);
    }
    else
    {
        tclr = vbuff.pal->get_RGB(color);
    }
    return frect(rect,&tclr);
}


VNGError VngoVportD3D::pixel (VngoPoint *pt, VngoColor24bit *rgb_val)
{
    VngoPoint  p2 = *pt;
    if (p2.x + 1 < vbuff.width)
        p2.x += 1;
    else
        p2.x -= 1;
    return line(pt,&p2,rgb_val);
}
VNGError VngoVportD3D::pixel (VngoPointF *pt, VngoColor24bit *rgb_val)
{
    VngoPointF  p2 = *pt;

    if (p2.x + 1.f < float(vbuff.width))
        p2.x += 1.f;
    else
        p2.x -= 1.f;
    return line(pt,&p2,rgb_val);
}

VNGError VngoVportD3D::clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val,
                     VngoRect *clip_rect)
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

VNGError VngoVportD3D::clip_pixel (VngoPointF *pt, VngoColor24bit *rgb_val,
                     VngoRect *clip_rect)
{
    VngoRect vprect(0,0,vbuff.width,vbuff.height);

    VngoPoint   tpt;
    tpt.x = long(pt->x + .5f);
    tpt.x = long(pt->y + .5f);
    tpt.z = dword(pt->z * float(0xffffffff));
    tpt.clr = pt->clr;
    tpt.shade = long(pt->shade);

    if (clip_rect)
    {
        vprect.clip_to(*clip_rect);
    }
    if (vprect.point_in(tpt))
        return pixel(&tpt,rgb_val);

    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::line (VngoPoint *p1, VngoPoint *p2,VngoColor24bit *rgb_val)
{
    make_current();

    screen->open_frame();
    D3DTLVERTEX verts[2];

    VngoColor24bit rgb;
    if (rgb_val)
        rgb = *rgb_val;
    else
    {
        word *shades = (word*)vbuff.pal->shd_pal->ptr;
        shades += (p1->clr << 5);
        int tclr = shades[p1->shade >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb.r = (tclr >> 7) & 0xf8;
            rgb.g = (tclr >> 2) & 0xf8;
            rgb.b = (tclr & 0x1f) << 3;
        }
        else
        {
            rgb.r = (tclr >> 8) & 0xf8;
            rgb.g = (tclr >> 3) & 0xfc;
            rgb.b = (tclr & 0x1f) << 3;
        }
    }

    verts[0].sx = (D3DVALUE)p1->x+left;
    verts[0].sy = (D3DVALUE)p1->y+top;
    verts[0].sz = (D3DVALUE)float(ulong(p1->z) >> 16)*ZCONST;
    verts[0].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
    verts[0].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[0].sz));

    verts[1].sx = (D3DVALUE)p2->x+left;
    verts[1].sy = (D3DVALUE)p2->y+top;
    verts[1].sz = (D3DVALUE)float(ulong(p2->z) >> 16)*ZCONST;
    verts[1].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
    verts[1].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[1].sz));

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    screen->set_draw_state(dflags);
    screen->d3dDevice->DrawPrimitive(D3DPT_LINELIST,D3DVT_TLVERTEX,verts,2,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}
VNGError VngoVportD3D::line (VngoPointF *p1, VngoPointF *p2,VngoColor24bit *rgb_val)
{
    make_current();

    screen->open_frame();
    D3DTLVERTEX verts[2];

    VngoColor24bit rgb;
    if (rgb_val)
        rgb = *rgb_val;
    else
    {
        word *shades = (word*)vbuff.pal->shd_pal->ptr;
        shades += (p1->clr << 5);
        int tclr = shades[int(p1->shade) >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb.r = (tclr >> 7) & 0xf8;
            rgb.g = (tclr >> 2) & 0xf8;
            rgb.b = (tclr & 0x1f) << 3;
        }
        else
        {
            rgb.r = (tclr >> 8) & 0xf8;
            rgb.g = (tclr >> 3) & 0xfc;
            rgb.b = (tclr & 0x1f) << 3;
        }
    }

    verts[0].sx = (D3DVALUE)p1->x+left;
    verts[0].sy = (D3DVALUE)p1->y+top;
    verts[0].sz = (D3DVALUE)p1->z;
    verts[0].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
    verts[0].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[0].sz));

    verts[1].sx = (D3DVALUE)p2->x+left;
    verts[1].sy = (D3DVALUE)p2->y+top;
    verts[1].sz = (D3DVALUE)p2->z;
    verts[1].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
    verts[1].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[1].sz));

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    screen->set_draw_state(dflags);
    screen->d3dDevice->DrawPrimitive(D3DPT_LINELIST,D3DVT_TLVERTEX,verts,2,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::clip_line (VngoPoint *p1, VngoPoint *p2, VngoColor24bit *rgb_val,
                    VngoRect *clip_rect)
{
    make_current();
    VngoPoint tp1,tp2;

    tp1 = *p1;
    tp2 = *p2;

    VngoRect    crect(0,0,vbuff.width-1,vbuff.height-1);

    if (clip_rect)
        crect.clip_to(*clip_rect);

    int cflags = 0;
    if (VNGO_ZBUFFER_ACTIVE & vflags)
        cflags |= VNGO_CLIP_Z;

    VNGError err = crect.clip_to(&tp1,&tp2,cflags);
    if (err == VNGO_FULLY_CLIPPED)
        return VNGO_NO_ERROR;
    else
        return line(&tp1,&tp2,rgb_val);

}
VNGError VngoVportD3D::clip_line (VngoPointF *p1, VngoPointF *p2, VngoColor24bit *rgb_val,
                    VngoRect *clip_rect)
{
    make_current();
    VngoPointF tp1,tp2;

    tp1 = *p1;
    tp2 = *p2;

    VngoRect    crect(0,0,vbuff.width-1,vbuff.height-1);

    if (clip_rect)
        crect.clip_to(*clip_rect);

    int cflags = 0;
    if (VNGO_ZBUFFER_ACTIVE & vflags)
        cflags |= VNGO_CLIP_Z;

    VNGError err = crect.clip_to(&tp1,&tp2,cflags);
    if (err == VNGO_FULLY_CLIPPED)
        return VNGO_NO_ERROR;
    else
        return line(&tp1,&tp2,rgb_val);
}



VNGError VngoVportD3D::gline (VngoPoint *p1, VngoPoint *p2)
{
    make_current();

    screen->open_frame();
    D3DTLVERTEX verts[2];

    VngoColor24bit rgb1,rgb2;

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    int tclr1 = shades[(p1->clr << 5) + (p1->shade >> 3)];
    int tclr2 = shades[(p2->clr << 5) + (p2->shade >> 3)];

    VngoColor24bit rgb;

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb1.r = (tclr1 >> 7) & 0xf8;
        rgb1.g = (tclr1 >> 2) & 0xf8;
        rgb1.b = (tclr1 & 0x1f) << 3;

        rgb2.r = (tclr2 >> 7) & 0xf8;
        rgb2.g = (tclr2 >> 2) & 0xf8;
        rgb2.b = (tclr2 & 0x1f) << 3;
    }
    else
    {
        rgb1.r = (tclr1 >> 8) & 0xf8;
        rgb1.g = (tclr1 >> 3) & 0xfc;
        rgb1.b = (tclr1 & 0x1f) << 3;

        rgb2.r = (tclr2 >> 8) & 0xf8;
        rgb2.g = (tclr2 >> 3) & 0xfc;
        rgb2.b = (tclr2 & 0x1f) << 3;
    }


    verts[0].sx = (D3DVALUE)p1->x+left;
    verts[0].sy = (D3DVALUE)p1->y+top;
    verts[0].sz = (D3DVALUE)float(ulong(p1->z) >> 16)*ZCONST;
    verts[0].color = RGB_MAKE(rgb1.r,rgb1.g,rgb1.b);
    verts[0].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[0].sz));

    verts[1].sx = (D3DVALUE)p2->x+left;
    verts[1].sy = (D3DVALUE)p2->y+top;
    verts[1].sz = (D3DVALUE)float(ulong(p2->z) >> 16)*ZCONST;
    verts[1].color = RGB_MAKE(rgb2.r,rgb2.g,rgb2.b);
    verts[1].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[1].sz));

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    screen->set_draw_state(dflags);
    screen->d3dDevice->DrawPrimitive(D3DPT_LINELIST,D3DVT_TLVERTEX,verts,2,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}
VNGError VngoVportD3D::gline (VngoPointF *p1, VngoPointF *p2)
{
    make_current();

    screen->open_frame();
    D3DTLVERTEX verts[2];

    VngoColor24bit rgb1,rgb2;

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    int tclr1 = shades[(p1->clr << 5) + (int(p1->shade) >> 3)];
    int tclr2 = shades[(p2->clr << 5) + (int(p2->shade) >> 3)];

    VngoColor24bit rgb;

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb1.r = (tclr1 >> 7) & 0xf8;
        rgb1.g = (tclr1 >> 2) & 0xf8;
        rgb1.b = (tclr1 & 0x1f) << 3;

        rgb2.r = (tclr2 >> 7) & 0xf8;
        rgb2.g = (tclr2 >> 2) & 0xf8;
        rgb2.b = (tclr2 & 0x1f) << 3;
    }
    else
    {
        rgb1.r = (tclr1 >> 8) & 0xf8;
        rgb1.g = (tclr1 >> 3) & 0xfc;
        rgb1.b = (tclr1 & 0x1f) << 3;

        rgb2.r = (tclr2 >> 8) & 0xf8;
        rgb2.g = (tclr2 >> 3) & 0xfc;
        rgb2.b = (tclr2 & 0x1f) << 3;
    }


    verts[0].sx = (D3DVALUE)p1->x+left;
    verts[0].sy = (D3DVALUE)p1->y+top;
    verts[0].sz = (D3DVALUE)p1->z;
    verts[0].color = RGB_MAKE(rgb1.r,rgb1.g,rgb1.b);
    verts[0].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[0].sz));

    verts[1].sx = (D3DVALUE)p2->x+left;
    verts[1].sy = (D3DVALUE)p2->y+top;
    verts[1].sz = (D3DVALUE)p2->z;
    verts[1].color = RGB_MAKE(rgb2.r,rgb2.g,rgb2.b);
    verts[1].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[1].sz));

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    screen->set_draw_state(dflags);
    screen->d3dDevice->DrawPrimitive(D3DPT_LINELIST,D3DVT_TLVERTEX,verts,2,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}


VNGError VngoVportD3D::clip_gline (VngoPoint *p1, VngoPoint *p2,VngoRect *clip_rect)
{
    make_current();

    VngoPoint tp1,tp2;

    tp1 = *p1;
    tp2 = *p2;

    VngoRect    crect(0,0,vbuff.width-1,vbuff.height-1);

    if (clip_rect)
        crect.clip_to(*clip_rect);

    int cflags = VNGO_CLIP_SHADE;
    if (VNGO_ZBUFFER_ACTIVE & vflags)
        cflags |= VNGO_CLIP_Z;

    VNGError err = crect.clip_to(&tp1,&tp2,cflags);
    if (err == VNGO_FULLY_CLIPPED)
        return VNGO_NO_ERROR;
    else
        return gline(&tp1,&tp2);

}
VNGError VngoVportD3D::clip_gline (VngoPointF *p1, VngoPointF *p2,VngoRect *clip_rect)
{
    make_current();
    VngoPointF tp1,tp2;

    tp1 = *p1;
    tp2 = *p2;

    VngoRect    crect(0,0,vbuff.width-1,vbuff.height-1);

    if (clip_rect)
        crect.clip_to(*clip_rect);

    int cflags = VNGO_CLIP_SHADE;
    if (VNGO_ZBUFFER_ACTIVE & vflags)
        cflags |= VNGO_CLIP_Z;

    VNGError err = crect.clip_to(&tp1,&tp2,cflags);
    if (err == VNGO_FULLY_CLIPPED)
        return VNGO_NO_ERROR;
    else
        return gline(&tp1,&tp2);
}


VNGError VngoVportD3D::gline_persp (VngoPoint *p1, VngoPoint *p2)
{
    make_current();

    return gline(p1,p2);
}
VNGError VngoVportD3D::gline_persp (VngoPointF *p1, VngoPointF *p2)
{
    make_current();

    return gline(p1,p2);
}
VNGError VngoVportD3D::clip_gline_persp (VngoPoint *p1, VngoPoint *p2,VngoRect *clip_rect)
{
    make_current();

    return clip_gline(p1,p2,clip_rect);
}
VNGError VngoVportD3D::clip_gline_persp (VngoPointF *p1, VngoPointF *p2,VngoRect *clip_rect)
{
    make_current();

    return clip_gline(p1,p2,clip_rect);
}



int VngoVportD3D::plock()
{
    int fail_safe=0;
    int ret_val = screen->SurfaceManager->lock();
    DDSURFACEDESC   ddsd;
    ZeroMemory (&ddsd,sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);

    if (ret_val != 1)
    {   // This is a hack to get Microsoft to flush their bogus ExecuteBuffer!!!!

        {   // We shouldn't be here if the screen is locked!
            screen->close_frame();
        }

        int locked=0;
        HRESULT hr;
        while (!locked && (fail_safe < 1000))
        {
            fail_safe++;    // just so we can't loop infinately.
            if ((hr = screen->SurfaceManager->ddsurf->Lock (NULL, &ddsd,
                                     DDLOCK_SURFACEMEMORYPTR
                                     | DDLOCK_WAIT, NULL)) == DD_OK)
            {
                vbuff.pitch = ddsd.lPitch;
                long    offset = (top * vbuff.pitch) + (left * 2);
                vbuff.scrn_ptr = (byte *) ((dword)ddsd.lpSurface);
                vbuff.scrn_ptr = (byte *)(dword(vbuff.scrn_ptr) + offset);
                locked = 1;
            }
            if (hr == DDERR_SURFACELOST)
            {
                hr = screen->SurfaceManager->ddsurf->Restore();
                if (hr != DD_OK)
                {
                    locked = 0; // an error occured while
                    return -1;  // restoring the surface, so it cannot be locked.
                }
            }
        }

        if (hr != DD_OK)
        {
            screen->SurfaceManager->unlock();
            return (-1);        // failure to lock;
        }
    }

    lock_status = 1;
    return(ret_val);
}


int VngoVportD3D::punlock()
{
    vbuff.scrn_ptr = NULL;

    int ret_val= screen->SurfaceManager->unlock();
    if (ret_val != 0)
    {
        screen->SurfaceManager->ddsurf->Unlock( NULL );
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

VNGError VngoVportD3D::poly (int count,VngoPoint pts[])
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr = shades[pts[0].shade >> 3];

    VngoColor24bit rgb;

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb.r = (tclr >> 7) & 0xf8;
        rgb.g = (tclr >> 2) & 0xf8;
        rgb.b = (tclr & 0x1f) << 3;
    }
    else
    {
        rgb.r = (tclr >> 8) & 0xf8;
        rgb.g = (tclr >> 3) & 0xfc;
        rgb.b = (tclr & 0x1f) << 3;
    }

    for (int i=0;i < count;i++)
    {
        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        if (pts[i].z > 0)
            verts[i].sz = (D3DVALUE)float(ulong(pts[i].z)) / float(0xffffffff);
        else
            verts[i].sz = 0.f;
        verts[i].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);

    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::poly (int count,VngoPointF pts[])
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr = shades[dword(pts[0].shade) >> 3];

    VngoColor24bit rgb;

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb.r = (tclr >> 7) & 0xf8;
        rgb.g = (tclr >> 2) & 0xf8;
        rgb.b = (tclr & 0x1f) << 3;
    }
    else
    {
        rgb.r = (tclr >> 8) & 0xf8;
        rgb.g = (tclr >> 3) & 0xfc;
        rgb.b = (tclr & 0x1f) << 3;
    }

    for (int i=0;i < count;i++)
    {
        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        verts[i].sz = (D3DVALUE)pts[i].z;
        verts[i].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gpoly (int count,VngoPoint pts[])
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr;
    VngoColor24bit rgb;
    for (int i=0;i < count;i++)
    {
        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        if (pts[i].z > 0)
            verts[i].sz = (D3DVALUE)float(ulong(pts[i].z)) / float(0xffffffff);
        else
            verts[i].sz = 0.f;

        tclr = shades[pts[i].shade >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb.r = (tclr >> 7) & 0xf8;
            rgb.g = (tclr >> 2) & 0xf8;
            rgb.b = (tclr & 0x1f) << 3;
        }
        else
        {
            rgb.r = (tclr >> 8) & 0xf8;
            rgb.g = (tclr >> 3) & 0xfc;
            rgb.b = (tclr & 0x1f) << 3;
        }

        verts[i].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gpoly (int count,VngoPointF pts[])
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr;
    VngoColor24bit rgb;
    for (int i=0;i < count;i++)
    {
        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        verts[i].sz = (D3DVALUE)pts[i].z;

        tclr = shades[int(pts[i].shade) >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb.r = (tclr >> 7) & 0xf8;
            rgb.g = (tclr >> 2) & 0xf8;
            rgb.b = (tclr & 0x1f) << 3;
        }
        else
        {
            rgb.r = (tclr >> 8) & 0xf8;
            rgb.g = (tclr >> 3) & 0xfc;
            rgb.b = (tclr & 0x1f) << 3;
        }

        verts[i].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gpoly_persp (int count,VngoPoint pts[])
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);
    return gpoly(count,pts);
}
VNGError VngoVportD3D::gpoly_persp (int count,VngoPointF pts[])
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);
    return gpoly(count,pts);
}


VNGError VngoVportD3D::tpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;


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

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;

        if (pts[i].z > 0)
            tpts[i].sz = (D3DVALUE)float(ulong(pts[i].z)) / float(0xffffffff);
        else
            tpts[i].sz = 0.f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;


        tpts[i].color = RGB_MAKE (shade,shade,shade);
        tpts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = float(pts[i].u) / float(0x10000);
        tpts[i].tv = float(pts[i].v) / float(0x10000);
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }


    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::tpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                tptr = NULL;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

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

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;
        tpts[i].sz = (D3DVALUE)pts[i].z;

        tpts[i].rhw = (D3DVALUE) pts[i].w;


        tpts[i].color = RGB_MAKE (shade,shade,shade);
        tpts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = pts[i].u;
        tpts[i].tv = pts[i].v;

        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

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

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;

        if (pts[i].z > 0)
            tpts[i].sz = (D3DVALUE)float(ulong(pts[i].z)) / float(0xffffffff);
        else
            tpts[i].sz = 0.f;

        if (tpts[i].sz > 0.99999f)
            tpts[i].sz = 0.99999f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;


        tpts[i].color = RGB_MAKE (shade,shade,shade);
        tpts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = float(pts[i].u) / float(0x10000);
        tpts[i].tv = float(pts[i].v) / float(0x10000);
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_PERSPECTIVE;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}


VNGError VngoVportD3D::tpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;


    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

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

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;
        tpts[i].sz = (D3DVALUE)pts[i].z;
        if (tpts[i].sz > 0.99999f)
            tpts[i].sz = 0.99999f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;


        tpts[i].color = RGB_MAKE (shade,shade,shade);
        tpts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = pts[i].u;
        tpts[i].tv = pts[i].v;
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_PERSPECTIVE;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gtpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;

        if (pts[i].z > 0)
            tpts[i].sz = (D3DVALUE)float(ulong(pts[i].z)) / float(0xffffffff);
        else
            tpts[i].sz = 0.f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        int specular = 0;
        shade = pts[i].shade;

        if (shade > mp)
        {
            specular = int(float(shade - mp) * specmod);
            shade= mp;
        }
        shade = int(float(shade) * modifier);
        tpts[i].color = RGB_MAKE (shade,shade,shade);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = float(pts[i].u) / float(0x10000);
        tpts[i].tv = float(pts[i].v) / float(0x10000);
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}


VNGError VngoVportD3D::gtpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;
        tpts[i].sz = (D3DVALUE)pts[i].z;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        int specular = 0;
        shade = int(pts[i].shade);

        if (shade > mp)
        {
            specular = int(float(shade - mp) * specmod);
            shade= mp;
        }
        shade = int(float(shade) * modifier);
        tpts[i].color = RGB_MAKE (shade,shade,shade);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = pts[i].u;
        tpts[i].tv = pts[i].v;
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;

        if (pts[i].z > 0)
            tpts[i].sz = (D3DVALUE)float(ulong(pts[i].z)) / float(0xffffffff);
        else
            tpts[i].sz = 0.f;

        if (tpts[i].sz > 0.99999f)
            tpts[i].sz = 0.99999f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        int specular = 0;
        shade = pts[i].shade;

        if (shade > mp)
        {
            specular = int(float(shade - mp) * specmod);
            shade= mp;
        }
        shade = int(float(shade) * modifier);
        tpts[i].color = RGB_MAKE (shade,shade,shade);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = float(pts[i].u) / float(0x10000);
        tpts[i].tv = float(pts[i].v) / float(0x10000);
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_PERSPECTIVE |
                   VNGO_D3DSFLAGS_GOURAUD;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}


VNGError VngoVportD3D::gtpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;
        tpts[i].sz = (D3DVALUE)pts[i].z;

        if (tpts[i].sz > 0.99999f)
            tpts[i].sz = 0.99999f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        int specular = 0;
        shade = int(pts[i].shade);

        if (shade > mp)
        {
            specular = int(float(shade - mp) * specmod);
            shade= mp;
        }
        shade = int(float(shade) * modifier);
        tpts[i].color = RGB_MAKE (shade,shade,shade);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = pts[i].u;
        tpts[i].tv = pts[i].v;
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_PERSPECTIVE |
                   VNGO_D3DSFLAGS_GOURAUD;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::grpoly (int count, VngoPoint pts[])
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    int tclr;
    VngoColor24bit rgb;
    for (int i=0;i < count;i++)
    {

        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        if (pts[i].z > 0)
            verts[i].sz = (D3DVALUE)float(ulong(pts[i].z)) / float(0xffffffff);
        else
            verts[i].sz = 0.f;

        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            word *shades = (word*)vbuff.pal->shd_pal->ptr;
            shades += (pts[i].clr << 5);
            tclr = shades[pts[i].shade >> 3];

            if (vbuff.pal->flags & VNGO_15BIT)
            {
                rgb.r = (tclr >> 7) & 0xf8;
                rgb.g = (tclr >> 2) & 0xf8;
                rgb.b = (tclr & 0x1f) << 3;
            }
            else
            {
                rgb.r = (tclr >> 8) & 0xf8;
                rgb.g = (tclr >> 3) & 0xfc;
                rgb.b = (tclr & 0x1f) << 3;
            }
        }
        else
        {
            rgb.r = byte((pts[i].clr & 0xff0000) >> 16);
            rgb.g = byte((pts[i].clr & 0xff00) >> 8);
            rgb.b = byte(pts[i].clr & 0xff);
        }

        verts[i].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::grpoly (int count, VngoPointF pts[])
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    int tclr;
    VngoColor24bit rgb;
    for (int i=0;i < count;i++)
    {

        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        verts[i].sz = (D3DVALUE)pts[i].z;

        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            word *shades = (word*)vbuff.pal->shd_pal->ptr;
            shades += (pts[i].clr << 5);
            tclr = shades[int(pts[i].shade) >> 3];

            if (vbuff.pal->flags & VNGO_15BIT)
            {
                rgb.r = (tclr >> 7) & 0xf8;
                rgb.g = (tclr >> 2) & 0xf8;
                rgb.b = (tclr & 0x1f) << 3;
            }
            else
            {
                rgb.r = (tclr >> 8) & 0xf8;
                rgb.g = (tclr >> 3) & 0xfc;
                rgb.b = (tclr & 0x1f) << 3;
            }
        }
        else
        {
            rgb.r = byte((pts[i].clr & 0xff0000) >> 16);
            rgb.g = byte((pts[i].clr & 0xff00) >> 8);
            rgb.b = byte(pts[i].clr & 0xff);
        }

        verts[i].color = RGB_MAKE(rgb.r,rgb.g,rgb.b);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}


//
// Alpha blended versions.
//

VNGError VngoVportD3D::poly_a (int count,VngoPoint pts[],long alpha)
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr = shades[pts[0].shade >> 3];

    VngoColor24bit rgb;

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb.r = (tclr >> 7) & 0xf8;
        rgb.g = (tclr >> 2) & 0xf8;
        rgb.b = (tclr & 0x1f) << 3;
    }
    else
    {
        rgb.r = (tclr >> 8) & 0xf8;
        rgb.g = (tclr >> 3) & 0xfc;
        rgb.b = (tclr & 0x1f) << 3;
    }

    for (int i=0;i < count;i++)
    {
        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        if (pts[i].z > 0)
            verts[i].sz = (D3DVALUE)float(ulong(pts[i].z)) / float(0xffffffff);
        else
            verts[i].sz = 0.f;
        verts[i].color = RGBA_MAKE(rgb.r,rgb.g,rgb.b,alpha);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::poly_a (int count,VngoPointF pts[],long alpha)
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr = shades[dword(pts[0].shade) >> 3];

    VngoColor24bit rgb;

    if (vbuff.pal->flags & VNGO_15BIT)
    {
        rgb.r = (tclr >> 7) & 0xf8;
        rgb.g = (tclr >> 2) & 0xf8;
        rgb.b = (tclr & 0x1f) << 3;
    }
    else
    {
        rgb.r = (tclr >> 8) & 0xf8;
        rgb.g = (tclr >> 3) & 0xfc;
        rgb.b = (tclr & 0x1f) << 3;
    }

    for (int i=0;i < count;i++)
    {
        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        verts[i].sz = (D3DVALUE)pts[i].z;
        verts[i].color = RGBA_MAKE(rgb.r,rgb.g,rgb.b,alpha);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gpoly_a (int count,VngoPoint pts[],long alpha)
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr;
    VngoColor24bit rgb;
    for (int i=0;i < count;i++)
    {
        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        if (pts[i].z > 0)
            verts[i].sz = (D3DVALUE)float(ulong(pts[i].z)) / float(0xffffffff);
        else
            verts[i].sz = 0.f;

        tclr = shades[pts[i].shade >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb.r = (tclr >> 7) & 0xf8;
            rgb.g = (tclr >> 2) & 0xf8;
            rgb.b = (tclr & 0x1f) << 3;
        }
        else
        {
            rgb.r = (tclr >> 8) & 0xf8;
            rgb.g = (tclr >> 3) & 0xfc;
            rgb.b = (tclr & 0x1f) << 3;
        }

        verts[i].color = RGBA_MAKE(rgb.r,rgb.g,rgb.b,alpha);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gpoly_a (int count,VngoPointF pts[],long alpha)
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);

    screen->open_frame();
    D3DTLVERTEX verts[VNGO_MAX_VERTCOUNT];

    word *shades = (word*)vbuff.pal->shd_pal->ptr;
    shades += (pts[0].clr << 5);
    int tclr;
    VngoColor24bit rgb;
    for (int i=0;i < count;i++)
    {
        verts[i].sx = (D3DVALUE)pts[i].x+left;
        verts[i].sy = (D3DVALUE)pts[i].y+top;
        verts[i].sz = (D3DVALUE)pts[i].z;

        tclr = shades[int(pts[i].shade) >> 3];

        if (vbuff.pal->flags & VNGO_15BIT)
        {
            rgb.r = (tclr >> 7) & 0xf8;
            rgb.g = (tclr >> 2) & 0xf8;
            rgb.b = (tclr & 0x1f) << 3;
        }
        else
        {
            rgb.r = (tclr >> 8) & 0xf8;
            rgb.g = (tclr >> 3) & 0xfc;
            rgb.b = (tclr & 0x1f) << 3;
        }

        verts[i].color = RGBA_MAKE(rgb.r,rgb.g,rgb.b,alpha);
        verts[i].specular = RGBA_MAKE(0,0,0,fog_table.get_fog(verts[i].sz));
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    screen->set_draw_state(dflags);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,verts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gpoly_persp_a (int count,VngoPoint pts[],long alpha)
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);
    return gpoly_a(count,pts,alpha);
}
VNGError VngoVportD3D::gpoly_persp_a (int count,VngoPointF pts[],long alpha)
{
    make_current();

    assert (count < VNGO_MAX_VERTCOUNT);
    return gpoly_a(count,pts,alpha);
}

VNGError VngoVportD3D::tpoly_a (int count,VngoPoint pts[],VngoTexture *tex,long alpha)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;
    int specular = 0;
    shade = pts[0].shade;

    if (shade > mp)
    {
        specular = int(float(shade - mp) * specmod);
        shade= mp;
    }
    shade = int(float(shade) * modifier);


    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;

        if (pts[i].z > 0)
            tpts[i].sz = (D3DVALUE)float(ulong(pts[i].z) >> 16)*ZCONST;
        else
            tpts[i].sz = 0.f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        tpts[i].color = RGBA_MAKE (shade,shade,shade,alpha);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = float(pts[i].u) / float(0x10000);
        tpts[i].tv = float(pts[i].v) / float(0x10000);
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::tpoly_a (int count,VngoPointF pts[],VngoTexture *tex,long alpha)
{

    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;
    int specular = 0;
    shade = int(pts[0].shade);

    if (shade > mp)
    {
        specular = int(float(shade - mp) * specmod);
        shade= mp;
    }
    shade = int(float(shade) * modifier);


    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;
        tpts[i].sz = (D3DVALUE)pts[i].z;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        tpts[i].color = RGBA_MAKE (shade,shade,shade,alpha);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = pts[i].u;
        tpts[i].tv = pts[i].v;

        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::tpoly_persp_a (int count,VngoPoint pts[],VngoTexture *tex,long alpha)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    int specular = 0;
    shade = pts[0].shade;

    if (shade > mp)
    {
        specular = int(float(shade - mp) * specmod);
        shade= mp;
    }
    shade = int(float(shade) * modifier);

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;

        if (pts[i].z > 0)
            tpts[i].sz = (D3DVALUE)float(ulong(pts[i].z) >> 16)*ZCONST;
        else
            tpts[i].sz = 0.f;

        if (tpts[i].sz > 0.99999f)
            tpts[i].sz = 0.99999f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        tpts[i].color = RGBA_MAKE (shade,shade,shade,alpha);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = float(pts[i].u) / float(0x10000);
        tpts[i].tv = float(pts[i].v) / float(0x10000);
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }


    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_PERSPECTIVE;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::tpoly_persp_a (int count,VngoPointF pts[],VngoTexture *tex,long alpha)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    int specular = 0;
    shade = int(pts[0].shade);

    if (shade > mp)
    {
        specular = int(float(shade - mp) * specmod);
        shade= mp;
    }
    shade = int(float(shade) * modifier);

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;
        tpts[i].sz = (D3DVALUE)pts[i].z;

        if (tpts[i].sz > 0.99999f)
            tpts[i].sz = 0.99999f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        tpts[i].color = RGBA_MAKE (shade,shade,shade,alpha);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = pts[i].u;
        tpts[i].tv = pts[i].v;
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_PERSPECTIVE;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gtpoly_a (int count,VngoPoint pts[],VngoTexture *tex,long alpha)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;

        if (pts[i].z > 0)
            tpts[i].sz = (D3DVALUE)float(ulong(pts[i].z) >> 16)*ZCONST;
        else
            tpts[i].sz = 0.f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        int specular = 0;
        shade = pts[i].shade;

        if (shade > mp)
        {
            specular = int(float(shade - mp) * specmod);
            shade= mp;
        }
        shade = int(float(shade) * modifier);
        tpts[i].color = RGBA_MAKE (shade,shade,shade,alpha);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = float(pts[i].u) / float(0x10000);
        tpts[i].tv = float(pts[i].v) / float(0x10000);
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}


VNGError VngoVportD3D::gtpoly_a (int count,VngoPointF pts[],VngoTexture *tex,long alpha)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;
        tpts[i].sz = (D3DVALUE)pts[i].z;
        tpts[i].rhw = (D3DVALUE) pts[i].w;

        int specular = 0;
        shade = int(pts[i].shade);

        if (shade > mp)
        {
            specular = int(float(shade - mp) * specmod);
            shade= mp;
        }
        shade = int(float(shade) * modifier);
        tpts[i].color = RGBA_MAKE (shade,shade,shade,alpha);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = pts[i].u;
        tpts[i].tv = pts[i].v;
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_GOURAUD;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gtpoly_persp_a (int count,VngoPointF pts[],VngoTexture *tex,long alpha)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;
        tpts[i].sz = (D3DVALUE)pts[i].z;

        if (tpts[i].sz > 0.99999f)
            tpts[i].sz = 0.99999f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        int specular = 0;
        shade = int(pts[i].shade);

        if (shade > mp)
        {
            specular = int(float(shade - mp) * specmod);
            shade= mp;
        }
        shade = int(float(shade) * modifier);
        tpts[i].color = RGBA_MAKE (shade,shade,shade,alpha);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = pts[i].u;
        tpts[i].tv = pts[i].v;

        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_PERSPECTIVE |
                   VNGO_D3DSFLAGS_GOURAUD;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

VNGError VngoVportD3D::gtpoly_persp_a (int count,VngoPoint pts[],VngoTexture *tex,long alpha)
{
    make_current();

    assert (count <= VNGO_MAX_VERTCOUNT);

    screen->open_frame();

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_D3D_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        if (tex->pal_ptr == NULL)
            tex->pal_ptr = vbuff.pal;

        tptr = new VngoD3DTexture3D(tex,tex->pal_ptr);
        if (tptr)
        {
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return (VNGO_UNSUPPORTED_TEXTURE);
            }
        }
        else
            return VNGO_MEMALLOC_ERROR;
    }


    if (!(((VngoD3DTexture3D*)tptr)->ref->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    if (tptr->ready_texture() != VNGO_NO_ERROR)
        return VNGO_INTERNAL_ERROR;

    D3DTLVERTEX tpts[VNGO_MAX_VERTCOUNT];

    int mp = vbuff.pal->shd_pal->mid_point;
    float modifier = (255.f / float(mp));
    float specmod = (255.f / (255.f - float(mp)));
    int shade;

    for (int i=0;i < count;i++)
    {
        tpts[i].sx = (D3DVALUE)pts[i].x+left;
        tpts[i].sy = (D3DVALUE)pts[i].y+top;

        if (pts[i].z > 0)
            tpts[i].sz = (D3DVALUE)float(ulong(pts[i].z) >> 16)*ZCONST;
        else
            tpts[i].sz = 0.f;

        if (tpts[i].sz > 0.99999f)
            tpts[i].sz = 0.99999f;

        tpts[i].rhw = (D3DVALUE) pts[i].w;

        int specular = 0;
        shade = pts[i].shade;

        if (shade > mp)
        {
            specular = int(float(shade - mp) * specmod);
            shade= mp;
        }
        shade = int(float(shade) * modifier);
        tpts[i].color = RGBA_MAKE (shade,shade,shade,alpha);
        tpts[i].specular = RGBA_MAKE(specular,specular,specular,fog_table.get_fog(tpts[i].sz));
        tpts[i].tu = float(pts[i].u) / float(0x10000);
        tpts[i].tv = float(pts[i].v) / float(0x10000);
        assert (pts[i].x >= 0);
        assert (pts[i].x <= vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y <= vbuff.height);
    }

    dword dflags = VNGO_D3DSFLAGS_ALPHA |
                   VNGO_D3DSFLAGS_TBLEND_MOD |
                   VNGO_D3DSFLAGS_DITHER |
                   VNGO_D3DSFLAGS_PERSPECTIVE |
                   VNGO_D3DSFLAGS_GOURAUD;

    if (tex->flags & VNGO_TEXTURE_TRANSPARENT)
    {
        dflags |= VNGO_D3DSFLAGS_CKEY_ENABLE;
    }

    screen->set_draw_state(dflags,((VngoD3DTexture3D*)tptr)->handle);

    screen->d3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,D3DVT_TLVERTEX,tpts,count,D3DDP_DONOTCLIP);
    return VNGO_NO_ERROR;
}

//°±² End of module - vngd3d.cpp ²±°
