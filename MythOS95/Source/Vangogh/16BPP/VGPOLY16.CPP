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
// vngpoly16.cpp
//
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
    assert (count < VNGO_MAX_VERTCOUNT);
    VngoTexture *tex = NULL;
    dword poly_flags = 0;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::poly (int count,VngoPoint pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    poly(count,tpts);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gpoly (int count,VngoPoint pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    gpoly(count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly (int count,VngoPointF pts[])
{
    assert (count <= VNGO_MAX_VERTCOUNT);
    VngoTexture *tex = NULL;
    dword poly_flags = VNGO_TRITYPE_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);
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
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    tpoly(count,tpts,tex);
    return VNGO_NO_ERROR;

}


VNGError VngoVVport16::tpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_TEXTURED;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    tpoly_persp(count,tpts,tex);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_TEXTURED | VNGO_TRITYPE_PERSPECTIVE;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    gtpoly(count,tpts,tex);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gtpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_TEXTURED | VNGO_TRITYPE_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    gtpoly_persp(count,tpts,tex);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_TEXTURED | VNGO_TRITYPE_GOURAUD | VNGO_TRITYPE_PERSPECTIVE;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);

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
    assert (count < VNGO_MAX_VERTCOUNT);
    VngoTexture *tex = NULL;
    dword poly_flags = VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::poly_a (int count,
                              VngoPoint pts[],
                              long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    poly_a(count,tpts,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gpoly_a (int count,
                               VngoPoint pts[],
                               long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    gpoly_a(count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly_a (int count,
                               VngoPointF pts[],
                               long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);
    VngoTexture *tex = NULL;
    dword poly_flags = VNGO_TRITYPE_GOURAUD | VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly_persp_a (int count,
                                     VngoPoint pts[],
                                     long alpha)
{
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport16::gpoly_persp_a (int count,
                                     VngoPointF pts[],
                                     long alpha)
{
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport16::tpoly_a (int count,VngoPoint pts[],
                               VngoTexture *tex,
                               long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    tpoly_a(count,tpts,tex,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly_a (int count,VngoPointF pts[],
                               VngoTexture *tex,
                               long alpha)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_ALPHA
                       | VNGO_TRITYPE_TEXTURED;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::tpoly_persp_a (int count,VngoPoint pts[],
                                     VngoTexture *tex,
                                     long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    tpoly_persp_a (count,tpts,tex,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly_persp_a (int count,VngoPointF pts[],
                                     VngoTexture *tex,
                                     long alpha)
{
    assert (count <= VNGO_MAX_VERTCOUNT);
    dword poly_flags = VNGO_TRITYPE_PERSPECTIVE
                       | VNGO_TRITYPE_TEXTURED
                       | VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_a (int count,VngoPoint pts[],
                                VngoTexture *tex,
                                long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    gtpoly_a(count,tpts,tex,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gtpoly_a (int count,VngoPointF pts[],
                                VngoTexture *tex,
                                long alpha)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_GOURAUD
                       | VNGO_TRITYPE_TEXTURED
                       | VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp_a (int count,VngoPoint pts[],
                                      VngoTexture *tex,
                                      long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    gtpoly_persp_a(count,tpts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp_a (int count,VngoPointF pts[],
                                      VngoTexture *tex,
                                      long  alpha)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_GOURAUD
                       | VNGO_TRITYPE_TEXTURED
                       | VNGO_TRITYPE_PERSPECTIVE
                       | VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

//°±² End of module - vgpoly16.cpp ²±°

