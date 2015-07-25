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
// vngpoly8.cpp
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the non-alpa blended portion of the polygon functions.           ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VNGError VngoVVport8::poly (int count,VngoPoint2 pts[])
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i = 0; i < count; i++)
    {
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_poly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::poly (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;

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
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_gpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly (int count,VngoPoint2 pts[])
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_gpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly_persp (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly(count,pts));
}

VNGError VngoVVport8::gpoly_persp (int count,VngoPoint2 pts[])
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly(count,pts));
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
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
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


VNGError VngoVVport8::tpoly (int count,VngoPoint2 pts[],VngoTexture *tex)
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
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
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
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
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


VNGError VngoVVport8::tpoly_persp (int count,VngoPoint2 pts[],VngoTexture *tex)
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
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
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
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
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


VNGError VngoVVport8::gtpoly (int count,VngoPoint2 pts[],VngoTexture *tex)
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
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
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
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
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

VNGError VngoVVport8::gtpoly_persp (int count,VngoPoint2 pts[],VngoTexture *tex)
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
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_tgpoly_persp8(this,count,tpts,&tptr);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::grpoly (int count,VngoPoint pts[])
{
    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    VngoShadePal8   *tp = (VngoShadePal8*)(((VngoPal8*)vbuff.pal)->shd_pal);
    byte            *tc = (byte*)(&(*tp)[0]);
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            int t = tc[(pts[i].clr << 5) + (pts[i].shade >> 3)];
            VngoColor24bit tclr= vbuff.pal->get_RGB(t);
            tpts[i].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
        }
        else
        {
            tpts[i].clr = pts[i].clr;
        }
    }
    vngo_grpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::grpoly (int count,VngoPoint2 pts[])
{
    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    VngoShadePal8   *tp = (VngoShadePal8*)(((VngoPal8*)vbuff.pal)->shd_pal);
    byte            *tc = (byte*)(&(*tp)[0]);
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            int t = tc[(pts[i].clr << 5) + (pts[i].shade >> 19)];
            VngoColor24bit tclr= vbuff.pal->get_RGB(t);
            tpts[i].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
        }
        else
        {
            tpts[i].clr = pts[i].clr;
        }
    }
    vngo_grpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This is the alpa blended portion of the polygon functions.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

VNGError VngoVVport8::poly_a (int count,
                              VngoPoint2 pts[],
                              long alpha)
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i = 0; i < count; i++)
    {
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_apoly8(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::poly_a (int count,
                              VngoPoint pts[],
                              long alpha)
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_apoly8(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::gpoly_a (int count,
                               VngoPoint pts[],
                               long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_agpoly8(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly_a (int count,
                               VngoPoint2 pts[],
                               long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_agpoly8(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly_persp_a (int count,
                                     VngoPoint pts[],
                                     long alpha)
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport8::gpoly_persp_a (int count,
                                     VngoPoint2 pts[],
                                     long alpha)
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport8::tpoly_a (int count,VngoPoint pts[],
                               VngoTexture *tex,
                               long alpha)
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
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_atpoly8(this,count,tpts,&tptr,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::tpoly_a (int count,VngoPoint2 pts[],
                               VngoTexture *tex,
                               long alpha)
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
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }

    vngo_atpoly8(this,count,tpts,&tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::tpoly_persp_a (int count,VngoPoint pts[],
                                     VngoTexture *tex,
                                     long alpha)
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
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
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


VNGError VngoVVport8::tpoly_persp_a (int count,VngoPoint2 pts[],
                                     VngoTexture *tex,
                                     long alpha)
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
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }

    vngo_tpoly_persp8(this,count,tpts,&tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gtpoly_a (int count,VngoPoint pts[],
                                VngoTexture *tex,
                                long alpha)
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
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_atgpoly8(this,count,tpts,&tptr,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::gtpoly_a (int count,VngoPoint2 pts[],
                                VngoTexture *tex,
                                long alpha)
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
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_atgpoly8(this,count,tpts,&tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gtpoly_persp_a (int count,VngoPoint pts[],
                                      VngoTexture *tex,
                                      long alpha)
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
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
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

VNGError VngoVVport8::gtpoly_persp_a (int count,VngoPoint2 pts[],
                                      VngoTexture *tex,
                                      long  alpha)
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
        tpts[i].x = pts[i].x;
        tpts[i].y = pts[i].y;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << tptr.widthshift;
        tpts[i].v = pts[i].v << tptr.heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_tgpoly_persp8(this,count,tpts,&tptr);
    return VNGO_NO_ERROR;
}

//°±² End of module - vngpoly8.cpp ²±°

