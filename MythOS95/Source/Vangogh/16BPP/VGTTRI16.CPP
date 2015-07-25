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
// vngttri8.cpp
//
//     The 8bpp specific linear texture mapping routines for polygons in
//     the VanGogh Draw library.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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

extern "C" void vngo_ttriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,
                                  VngoTexture3D *tex);
extern "C" void vngo_zttriangle16 (VngoVbuffer *vbb,VngoPoint2 *pts,
                                   VngoTexture3D *tex);
extern "C" void vngo_tgtriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,
                                   VngoTexture3D *tex);
extern "C" void vngo_ztgtriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,
                                    VngoTexture3D *tex);
extern "C" void vngo_aztgtriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,
                                     VngoTexture3D *tex,long alpha);
extern "C" void vngo_azttriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,
                                    VngoTexture3D *tex, long alpha);
extern "C" void vngo_tazttriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,
                                     VngoTexture3D *tex, long alpha);
extern "C" void vngo_attriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,
                                   VngoTexture3D *tex,long alpha);
extern "C" void vngo_tattriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,
                                    VngoTexture3D *tex,long alpha);
extern "C" void vngo_atgtriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,
                                    VngoTexture3D *tex,long alpha);

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
//  vngo_tpoly(VngoVport *vb, int count, VngoPoint2 *pts,
//              VngoTexture3D *tex);
//      Draws an N sided convex polygon, by breaking it down into triangles
//      if it is not already a triangle.  It draws with flat shading, and
//      texture mapping.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void vngo_tpoly16 (VngoVport *vp,int count,VngoPoint2 *pts, VngoTexture3D *tex)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint2 tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                    vngo_zttriangle16 (&vp->vbuff,tpts,tex);
                else
                    vngo_ttriangle16 (&vp->vbuff,tpts,tex);
            }
        }
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_zttriangle16 (&vp->vbuff,pts,tex);
        else
            vngo_ttriangle16 (&vp->vbuff,pts,tex);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  vngo_tpoly(VngoVport *vb, int count, VngoPoint2 *pts,
//              VngoTexture3D *tex);
//      Draws an N sided convex polygon, by breaking it down into triangles
//      if it is not already a triangle.  It draws with flat shading, and
//      texture mapping.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void vngo_atpoly16 (VngoVport *vp,int count,VngoPoint2 *pts,
                   VngoTexture3D *tex, long alpha)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint2 tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                {
                    if (vp->vflags & VNGO_TRUE_ALPHA)
                    {
                        vngo_tazttriangle16 (&vp->vbuff,tpts,tex,alpha);
                    }
                    else
                    {
                        vngo_azttriangle16 (&vp->vbuff,tpts,tex,alpha);
                    }
                }
                else
                {
                    if (vp->vflags & VNGO_TRUE_ALPHA)
                    {
                        vngo_tattriangle16 (&vp->vbuff,tpts,tex,alpha);
                    }
                    else
                    {
                        vngo_attriangle16 (&vp->vbuff,tpts,tex,alpha);
                    }
                }

            }
        }
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
        {
            if (vp->vflags & VNGO_TRUE_ALPHA)
            {
                vngo_tazttriangle16 (&vp->vbuff,pts,tex,alpha);
            }
            else
            {
                vngo_azttriangle16 (&vp->vbuff,pts,tex,alpha);
            }
        }
        else
        {
            if (vp->vflags & VNGO_TRUE_ALPHA)
            {
                vngo_tattriangle16 (&vp->vbuff,pts,tex,alpha);
            }
            else
            {
                vngo_attriangle16 (&vp->vbuff,pts,tex,alpha);
            }
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  vngo_tgpoly(VngoVport *vp, int count, VngoPoint2 *pts,
//              VngoTexture3D *tex);
//      Draws an N sided convex polygon, by breaking it down into triangles
//      if it is not already a triangle.  It draws with Gouraud shading and
//      texture mapping.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void vngo_tgpoly16 (VngoVport *vp,int count,VngoPoint2 *pts, VngoTexture3D *tex)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint2 tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                    vngo_ztgtriangle16 (&vp->vbuff,tpts,tex);
                else
                    vngo_tgtriangle16 (&vp->vbuff,tpts,tex);
            }
        }
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_ztgtriangle16 (&vp->vbuff,pts,tex);
        else
            vngo_tgtriangle16 (&vp->vbuff,pts,tex);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  vngo_tgpoly(VngoVport *vp, int count, VngoPoint2 *pts,
//              VngoTexture3D *tex);
//      Draws an N sided convex polygon, by breaking it down into triangles
//      if it is not already a triangle.  It draws with Gouraud shading and
//      texture mapping.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void vngo_atgpoly16 (VngoVport *vp,int count,VngoPoint2 *pts,
                     VngoTexture3D *tex, long alpha)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint2 tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                    vngo_aztgtriangle16 (&vp->vbuff,tpts,tex,alpha);
                else
                    vngo_atgtriangle16 (&vp->vbuff,tpts,tex,alpha);
            }
        }
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_aztgtriangle16 (&vp->vbuff,pts,tex,alpha);
        else
            vngo_atgtriangle16 (&vp->vbuff,pts,tex,alpha);
    }
}







//°±² End of module - vngttri.cpp ²±°
