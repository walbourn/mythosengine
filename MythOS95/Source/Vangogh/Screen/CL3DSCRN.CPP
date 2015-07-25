//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
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
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
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
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// CL3Dscrn.cpp
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
    term();
}


BOOL VngoClear3D::init()
{
    strcpy(hwName,"Clear3D");
    err = DirectDrawCreate(NULL, &dd, NULL);

    if (err != DD_OK)
        return FALSE;

    pContext = clrCreateContext();

    VertPool = (IvoryArena*)ivory_alloc(CLEAR3D_MAX_BATCH_COPROCESSOR * 8 * sizeof (LL_Vert));
    if (VertPool == NULL)
        return FALSE;

    ivory_arena_initialize(VertPool,CLEAR3D_MAX_BATCH_COPROCESSOR * 8 * sizeof (LL_Vert));

    VgSystem.CL3DTx = new VngoTextureManager;
    VgSystem.CL3DTx->screen = this;

    type_info = SCREENTYPE_CLEAR3D;
    return TRUE;
}


void VngoClear3D::reinit(Flx16 brightness)
{
    if (!pal)
        return;

    set_palette(pal,brightness);
}

BOOL VngoClear3D::check_mode(int _width, int _height, int bpp)
{
    assert (dd != 0);

    return (FALSE);
}



BOOL VngoClear3D::set_mode(int _width, int _height, int bpp, VngoPal *_pal,dword flags)
{
    width = _width;
    height = _height;
    lflags = flags;
    startx = 0;
    starty = 0;
    bit_depth = bpp;

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
        return FALSE;

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

#if 0
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

        err = Primary->AddAttachedSurface( ZBuffer );
    }


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
            return FALSE;
    }
    SurfaceManager = new VngoSurfaceManager(BackBuffer,ZBuffer);

    if (SurfaceManager == NULL)
    {
        return FALSE;
    }
    // set the context.

    pContext->ContextFlags = 0;
    pContext->lpRSurface = Primary;
    pContext->lpZSurface = ZBuffer;
    pContext->SurfaceRect = NULL;
#else
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
            return FALSE;

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
            return FALSE;
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

        err = BackBuffer->AddAttachedSurface( ZBuffer );
    }

    SurfaceManager = new VngoSurfaceManager(FrontBuffer,ZBuffer);

    if (SurfaceManager == NULL)
    {
        return FALSE;
    }
    // set the context.

    pContext->ContextFlags = 0;
    pContext->lpRSurface = BackBuffer;
    pContext->lpZSurface = ZBuffer;
    pContext->SurfaceRect = NULL;
#endif

    clrSetZMode(LL_Z_MODE_NORMAL);
    clrSetZCompareMode(LL_Z_WRITE_LESS_EQUAL);
    clrSetAlphaMode(LL_ALPHA_CONST);
    clrSetAlphaDestColor(LL_ALPHA_DEST_FRAME);

    // see control.c for info.

#if 0
    LL_Color    c;

    c.r = 255;
    c.g = 0;
    c.b = 255;
    c.a = 0;
    clrSetTextureColorBounds(LL_COLOR_COMPARE_INCLUSIVE,&c,&c);
#endif


    ClrErr rc = LL_OK;

    rc = clrSetContext(pContext);

    if (rc != LL_OK)
        return FALSE;

    pBatchRef = new LL_Batch [CLEAR3D_MAX_BATCH_COPROCESSOR];
    pBatch = pBatchRef;

    return TRUE;
}

void VngoClear3D::flip()
{

    if (frame_is_open)
        close_frame();

    flush();

    clrWait3D();

#if 1   // rendering to primary for Bruce.
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
                return;
            }
        }
    }
#endif
    VngoScreenManager::flip();
}

void VngoClear3D::set_palette(VngoPal *p,Flx16 brightness)
{
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
}

LL_Batch *VngoClear3D::get_batch(int num_batches)
{
    if ((BatchCount + num_batches) < CLEAR3D_MAX_BATCH_COPROCESSOR - 1)
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

void VngoClear3D::term()
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
}
