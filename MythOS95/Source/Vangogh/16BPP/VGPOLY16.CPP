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

VNGError VngoVVport16::poly (int count,VngoPointF pts[])
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i = 0; i < count; i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = long(pts[i].shade) << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_poly16(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::poly (int count,VngoPoint pts[])
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
    vngo_poly16(this,count,tpts);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gpoly (int count,VngoPoint pts[])
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
    vngo_gpoly16(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly (int count,VngoPointF pts[])
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = long(pts[i].shade) << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_gpoly16(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly_persp (int count,VngoPoint pts[])
{
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly(count,pts));
}

VNGError VngoVVport16::gpoly_persp (int count,VngoPointF pts[])
{
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly(count,pts));
}

VNGError VngoVVport16::tpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
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
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly16(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000)) << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = long(pts[i].v * float(0x10000)) << ((VngoMemTexture3D*)tptr)->heightshift;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }

    vngo_tpoly16(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
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
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly_persp16 (this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }


    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = dword(pts[i].w * float(0x3fffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000)) << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = long(pts[i].v * float(0x10000)) << ((VngoMemTexture3D*)tptr)->heightshift;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }

    vngo_tpoly_persp16 (this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert( lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
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
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_tgpoly16(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gtpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert( lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }


    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000)) << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = long(pts[i].v * float(0x10000)) << ((VngoMemTexture3D*)tptr)->heightshift;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_tgpoly16(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
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
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_tgpoly_persp16(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }


    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = dword(pts[i].w * float(0x3fffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000)) << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = long(pts[i].v * float(0x10000)) << ((VngoMemTexture3D*)tptr)->heightshift;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_tgpoly_persp16 (this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::grpoly (int count,VngoPoint pts[])
{
    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    VngoShadePal16   *tp = (VngoShadePal16*)(((VngoPal16*)vbuff.pal)->shd_pal);
    word            *tc = (word*)(&(*tp)[0]);
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            int t = tc[(pts[i].clr << 5) + (pts[i].shade >> 3)];
            VngoColor24bit tclr( ((t & (0x1f << 11)) >> 8), ((t & (0x3f << 5)) >> 3),((t & 0x1f) << 3));
            tpts[i].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
        }
        else
        {
            tpts[i].clr = pts[i].clr;
        }
    }
    vngo_grpoly16(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::grpoly (int count,VngoPointF pts[])
{
    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    VngoShadePal16  *tp = (VngoShadePal16*)(((VngoPal16*)vbuff.pal)->shd_pal);
    word            *tc = (word*)(&(*tp)[0]);
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            int t = tc[(pts[i].clr << 5) + (long(pts[i].shade) >> 3)];
            VngoColor24bit tclr( ((t & (0x1f << 11)) >> 8), ((t & (0x3f << 5)) >> 3), ((t & 0x1f) << 3));
            tpts[i].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
        }
        else
        {
            tpts[i].clr = pts[i].clr;
        }
    }
    vngo_grpoly16(this,count,tpts);
    return VNGO_NO_ERROR;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This is the alpa blended portion of the polygon functions.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

VNGError VngoVVport16::poly_a (int count,
                              VngoPointF pts[],
                              long alpha)
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i = 0; i < count; i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = long(pts[i].shade) << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_apoly16(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::poly_a (int count,
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
    vngo_apoly16(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gpoly_a (int count,
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
    vngo_agpoly16(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly_a (int count,
                               VngoPointF pts[],
                               long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = long(pts[i].shade) << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_agpoly16(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly_persp_a (int count,
                                     VngoPoint pts[],
                                     long alpha)
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport16::gpoly_persp_a (int count,
                                     VngoPointF pts[],
                                     long alpha)
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport16::tpoly_a (int count,VngoPoint pts[],
                               VngoTexture *tex,
                               long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
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
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_atpoly16(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly_a (int count,VngoPointF pts[],
                               VngoTexture *tex,
                               long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000)) << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = long(pts[i].v * float(0x10000)) << ((VngoMemTexture3D*)tptr)->heightshift;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }

    vngo_atpoly16(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::tpoly_persp_a (int count,VngoPoint pts[],
                                     VngoTexture *tex,
                                     long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
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
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_atpoly_persp16(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly_persp_a (int count,VngoPointF pts[],
                                     VngoTexture *tex,
                                     long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }


    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = dword(pts[i].w * float(0x3fffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000)) << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = long(pts[i].v * float(0x10000)) << ((VngoMemTexture3D*)tptr)->heightshift;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }

    vngo_atpoly_persp16(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_a (int count,VngoPoint pts[],
                                VngoTexture *tex,
                                long alpha)
{
    assert( lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
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
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_atgpoly16(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gtpoly_a (int count,VngoPointF pts[],
                                VngoTexture *tex,
                                long alpha)
{
    assert( lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }


    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000)) << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = long(pts[i].v * float(0x10000)) << ((VngoMemTexture3D*)tptr)->heightshift;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_atgpoly16(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp_a (int count,VngoPoint pts[],
                                      VngoTexture *tex,
                                      long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
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
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_atgpoly_persp16(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp_a (int count,VngoPointF pts[],
                                      VngoTexture *tex,
                                      long  alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }


    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = dword(pts[i].w * float(0x3fffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000)) << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = long(pts[i].v * float(0x10000)) << ((VngoMemTexture3D*)tptr)->heightshift;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_atgpoly_persp16(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

//°±² End of module - vgpoly16.cpp ²±°

