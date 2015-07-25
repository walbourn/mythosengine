//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
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
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
//                        http://www.mythos-engine.org/
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// Created by Tim Little
//
//                              O B S O L E T E
//
// CL3Dscrn.cpp
//
// Cirrus Clear3D
//
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <windows.h>
#include <ddraw.h>
#include "debug.h"
#include "portable.h"
#include "vngdefs.h"

// This is so this module will build whether _OEMS are defined or not!
#ifndef _OEMS
#define TEMP_OEMS
#define _OEMS
#endif

#ifndef _CLEAR_3D
#define TEMP_CLEAR_3D
#define _CLEAR_3D
#endif


#include "vangogh.hpp"
#include "vngscrn.hpp"

#ifdef TEMP_OEMS
#undef TEMP_OEMS
#undef _OEMS
#endif

#ifdef TEMP_CLEAR_3D
#undef TEMP_CLEAR_3D
#undef _CLEAR_3D
#endif

// #define RENDER_FRONT

extern VngoSystem   VgSystem;


VngoClear3D::VngoClear3D(HWND hwndclient):
    pContext(NULL),
    pBatchRef(NULL),
    pBatch(NULL),
    BatchCount(0),
    dd(NULL),
    Primary(NULL),
    FrontBuffer(NULL),
    BackBuffer(NULL),
    ZBuffer(NULL),
    SurfaceManager(NULL),
    Palette(NULL),
    hWndClient(hwndclient)
{
    pal = NULL;
    init_state = init();
}

VngoClear3D::~VngoClear3D()
{
    if ((lflags & VNGO_SET_RESOLUTION) && dd != NULL)
        dd->RestoreDisplayMode();

    term();
}


#define DEBUG_ALL      6
#define DEBUG_WARNINGS 2
#define DEBUG_ERROR    1
#define DEBUG_OFF      0

VNGError VngoClear3D::init()
{
    strcpy(hwName,"Clear3D");

    if (clrInitLib(CLR_INIT_NORMAL | DEBUG_OFF))
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

    err = DirectDrawCreate(NULL, &dd, NULL);

    if (err != DD_OK)
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

    pContext = clrCreateContext();

    VertPool = (IvoryArena*)ivory_alloc(CLEAR3D_MAX_BATCH * 8 * sizeof (LL_Vert));
    if (VertPool == NULL)
    {
        term();
        return VNGO_MEMALLOC_ERROR;
    }

    ivory_arena_initialize(VertPool,CLEAR3D_MAX_BATCH * 8 * sizeof (LL_Vert));

    VgSystem.CL3DTx = new VngoTextureManager;
    if (VgSystem.CL3DTx == NULL)
    {
        term();
        return VNGO_MEMALLOC_ERROR;
    }
    VgSystem.CL3DTx->screen = this;

    type_info = SCREENTYPE_CLEAR3D;
    return VNGO_NO_ERROR;
}


VNGError VngoClear3D::reinit(Flx16 brightness)
{
    if (!pal)
        return VNGO_INTERNAL_ERROR;

    set_palette(pal,brightness);
    return VNGO_NO_ERROR;
}

VNGError VngoClear3D::check_mode(int _width, int _height, int bpp, dword _flags, VngoPixelInfo *pinfo)
{
    assert (dd != 0);

    return (VNGO_NOT_SUPPORTED);
}



VNGError VngoClear3D::set_mode(int _width, int _height, int bpp, VngoPal *_pal,dword flags)
{
    width = _width;
    height = _height;
    lflags = flags;
    startx = 0;
    starty = 0;
    bit_depth = bpp;

    if (!(pal->flags & VNGO_16BIT))
    {
        return VNGO_NEEDS_PAL16;
    }

    assert (dd != 0);

    if (lflags & VNGO_SET_RESOLUTION)
    {
        err = dd->SetCooperativeLevel(hWndClient,
            DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN | DDSCL_ALLOWMODEX);
        if (err == DD_OK)
            err = dd->SetDisplayMode(width, height, bpp);
    }
    else
    {
        err = dd->SetCooperativeLevel(hWndClient,DDSCL_NORMAL);
    }

    if (err != DD_OK)
        return VNGO_INTERNAL_ERROR;

    // Get rid of any previous surfaces.
    if (BackBuffer)
    {
        BackBuffer->Release();
        BackBuffer = NULL;
    }
    if (FrontBuffer)
    {
        FrontBuffer->Release();
        FrontBuffer = NULL;
    }
    if (ZBuffer)
    {
        ZBuffer->Release();
        ZBuffer = NULL;
    }
    if (Palette)
    {
        Palette->Release();
        Palette = NULL;
    }

    // Creat surfaces.
    ZeroMemory (&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    if (lflags & VNGO_TRUE_FLIP)
    {
        ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
        ddsd.dwBackBufferCount = 1;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
                              DDSCAPS_FLIP |
                              DDSCAPS_COMPLEX |
                              DDSCAPS_VIDEOMEMORY;
    }
    else
    {
        ddsd.dwFlags = DDSD_CAPS;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE
                              | DDSCAPS_VIDEOMEMORY;
    }


    // try to get a double buffered video memory surface.
    err = dd->CreateSurface(&ddsd, &Primary, NULL);

    if (err != DD_OK)
    {
        return VNGO_INTERNAL_ERROR;
    }



    // get a pointer to the back buffer.
    if (lflags & VNGO_TRUE_FLIP)
    {
        DDSCAPS caps;
        caps.dwCaps = DDSCAPS_BACKBUFFER;
        err = Primary->GetAttachedSurface(&caps, &BackBuffer);

        if (err != DD_OK)
            return VNGO_INTERNAL_ERROR;

        FrontBuffer = BackBuffer;
    }
    else
    {
        ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

        if (lflags & VNGO_FORCE_SYSTEMMEMORY)
            ddsd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY;
        else
            ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_VIDEOMEMORY;

        ddsd.dwHeight = height;
        ddsd.dwWidth = width;
        err = dd->CreateSurface (&ddsd, &BackBuffer, NULL);

        FrontBuffer = BackBuffer;

        if (err != DD_OK)
            return VNGO_INTERNAL_ERROR;
    }

    if (flags & VNGO_ALLOC_ZBUFFER)
    {
        memset( &ddsd, 0, sizeof(ddsd) );
        ddsd.dwSize = sizeof(ddsd);
        ddsd.dwFlags           = DDSD_WIDTH
                               | DDSD_HEIGHT
                               | DDSD_CAPS
                               | DDSD_ZBUFFERBITDEPTH;
        ddsd.dwWidth           = _width;
        ddsd.dwHeight          = _height;
        ddsd.ddsCaps.dwCaps    = DDSCAPS_ZBUFFER;
        ddsd.dwZBufferBitDepth = 16;
        err = dd->CreateSurface( &ddsd, &ZBuffer, NULL );

#ifndef RENDER_FRONT
        err = BackBuffer->AddAttachedSurface( ZBuffer );
#else
        err = Primary->AddAttachedSurface( ZBuffer );
#endif
    }


#ifndef RENDER_FRONT
    SurfaceManager = new VngoSurfaceManager(BackBuffer,ZBuffer);
#else
    SurfaceManager = new VngoSurfaceManager(Primary,ZBuffer);
#endif

    if (SurfaceManager == NULL)
    {
        return VNGO_MEMALLOC_ERROR;
    }
    // set the context.

    pContext->ContextFlags = 0;
#ifndef RENDER_FRONT
    pContext->lpRSurface = BackBuffer;
#else
    pContext->lpRSurface = Primary;
#endif
    pContext->lpZSurface = ZBuffer;
    pContext->SurfaceRect = NULL;

    clrSetZMode(LL_Z_MODE_NORMAL);
    clrSetZCompareMode(LL_Z_WRITE_LESS_EQUAL);
    clrSetAlphaMode(LL_ALPHA_CONST);
    clrSetAlphaDestColor(LL_ALPHA_DEST_FRAME);

    // see control.c for info.

    ClrErr rc = LL_OK;

    rc = clrSetContext(pContext);

    if (rc != LL_OK)
        return VNGO_INTERNAL_ERROR;

    pBatchRef = new LL_Batch [CLEAR3D_MAX_BATCH];
    pBatch = pBatchRef;

    return VNGO_NO_ERROR;
}

VNGError VngoClear3D::flip()
{

    if (frame_is_open)
        close_frame();

    flush();


#ifndef RENDER_FRONT
//#if 0   // rendering to primary for Bruce.
    if (FrontBuffer->IsLost() == DDERR_SURFACELOST)
        FrontBuffer->Restore();

    if (BackBuffer->IsLost() == DDERR_SURFACELOST)
        BackBuffer->Restore();

    if (Primary->IsLost() == DDERR_SURFACELOST)
        Primary->Restore();


    if (lflags & VNGO_TRUE_FLIP)
    {
        Primary->Flip(NULL,DDFLIP_WAIT);
    }
    else
    {
#if 1
        RECT rcRect;
        rcRect.left = 0;
        rcRect.top = 0;
        rcRect.right = width;
        rcRect.bottom = height;
#endif
        RECT srcRect;
        srcRect.left = startx + damage_rect.left;
        srcRect.top = starty + damage_rect.top;
        srcRect.right = startx + damage_rect.right;
        srcRect.bottom = starty + damage_rect.bottom;

        while (1)
        {
            HRESULT ddrval = Primary->Blt(&rcRect,
                                          BackBuffer,
//                                          &damage_rect,
                                          &rcRect,
                                          0, NULL);
            if (ddrval == DD_OK)
            {
                break;
            }
            if (ddrval != DDERR_WASSTILLDRAWING)
            {
                return VNGO_INTERNAL_ERROR;
            }
        }
    }
#endif
    return VngoScreenManager::flip();
}

VNGError VngoClear3D::set_palette(VngoPal *p,Flx16 brightness)
{
    return VNGO_NOT_SUPPORTED;
}


void VngoClear3D::open_frame()
{
    if (!frame_is_open)
    {
    }
    frame_is_open = TRUE;
}


void VngoClear3D::close_frame()
{
    flush();
    frame_is_open = FALSE;
}

void VngoClear3D::flush()
{
    run_dl();
    clrFlush();
    wait_busy();
}
void VngoClear3D::run_dl()
{
    // start the next display list running.

    pBatch->bOp = LL_IDLE;

    clrExecute(pBatchRef);
    ivory_arena_clear (VertPool);
    pBatch = pBatchRef;
    BatchCount = 0;
}

void VngoClear3D::wait_busy()
{
    // wait until the GP is idle.
    // this is not actualy needed at this time.
//    clrIdle3D();
}

LL_Batch *VngoClear3D::get_batch(int num_batches)
{
    if ((BatchCount + num_batches) < CLEAR3D_MAX_BATCH - 1)
    {
        BatchCount += num_batches;
        LL_Batch *ret_val = pBatch;
        pBatch += num_batches;
        return ret_val;
    }
    else
    {
        run_dl();
        return get_batch(num_batches);
    }
}

VNGError VngoClear3D::term()
{

    if (SurfaceManager)
    {
        delete SurfaceManager;
        SurfaceManager = NULL;
    }

    if (FrontBuffer)
    {
        if (BackBuffer && (FrontBuffer != BackBuffer))
        {
            FrontBuffer->Release();
            FrontBuffer = NULL;
        }
    }

    if (BackBuffer)
    {
        BackBuffer->Release();
        BackBuffer = NULL;
    }

    if (ZBuffer)
    {
        ZBuffer->Release();
        ZBuffer = NULL;
    }


    if (Primary)
    {
        Primary->Release();
        Primary = NULL;
    }


    if (Palette)
    {
        Palette->Release();
        Palette = NULL;
    }
    if (VgSystem.CL3DTx)
    {
        delete VgSystem.CL3DTx;
        VgSystem.CL3DTx = NULL;
    }

    if (dd)
    {
        dd->SetCooperativeLevel(hWndClient,DDSCL_NORMAL);
        dd->Release();
        dd = NULL;
    }

    if (pBatchRef)
    {
        delete [] pBatchRef;
        pBatchRef = NULL;
        pBatch = NULL;
    }

    if (VertPool)
    {
        ivory_arena_clear(VertPool);
        ivory_free((void **)&VertPool);
    }

    if (pContext != NULL)
    {
        clrDeleteContext(pContext);
        pContext = NULL;
    }
    clrCloseLib();

    return VNGO_NO_ERROR;
}

VNGError VngoClear3D::dump_textures()
{
    return VNGO_NO_ERROR;
}

