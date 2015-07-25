//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùù°°°°°°°°°°ù°°°°°°°°ùùù°°°°°°°°ùù°°°ùùùù°°°ù°°°°°°°°°°ù°°°°°°°°°ùù
//ùùùùùùùùù°±°ùùùùùùù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùùùùùù°±°ùùùù°±°ùù
//ùùùùùùùù±°±ùùùùùùù±°±ùùùùùùùù±°±ùùùùùùùù±°±ùùùù±°±ù±°±ùùùùùùùù±°±ùùùù±°±ùùù
//ùùùùùùù±²±±°±±²ùù±²±±°±±²±±ù±²±ùùùùùùùù±²±±°±±²±±ù±²±±°±±²ùùù±²±±°±±²°ùùùùù
//ùùùùùù±²±ùùùùùùùùùùùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ùùùùù
//ùùùùù²±²ùùùùùùù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùùùùùù²±²ùùùù²±²ùùùùùù
//ùùùù²²²²²²²²²²ù²²²²²²²²ùùù²²²²²²²²ùù²²²ùùùù²²²ù²²²²²²²²²²ù²²²ùùùù²²²ùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little & Chuck Walbourn
//
// esdrface.cpp
//
// Contains the C++ implementation of the clip/draw function for faces
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"
#include <limits.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define ES_MAX_VERTS    9
#define ES_SNAP_VERTS

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

STATIC int iesch_immediate(VngoVport *vp,
                           dword level, EschFace *face,
                           long edge_count, VngoPointF *vpoly, dword ctrlfl);

STATIC int iesch_elmlist(VngoVport *vp,
                         dword level, EschFace *face,
                         long edge_count, VngoPointF *vpoly, dword ctrlfl);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

ulong EschProposedTris=0;
ulong EschDrawnTris=0;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_clipdraw_face                                                       ³
//                                                                          ³
// Draws a face using the current object information in the context.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_clipdraw_face(ulong ind, dword ctrlfl)
{
    ulong               i;
    dword               lclip_flags=0;
    ulong               edge_count;
    dword               level;
    dword               cflags;
    dword               color;
    float               height;
    float               width;
    float               tx;
    float               ty;
    float               z;
    float               tv;
    EschCamera          *cam;
    VngoVport           *vp;
    EschDrawable        *current;
    EschFace            *face;
    int                 edge_adj = 0;
    VngoPointF3         *points;

    // Static work-space
    static VngoPointF3  *vpt[ES_MAX_VERTS];
    static dword        *vflags[ES_MAX_VERTS];
    static dword        flags[ES_MAX_VERTS];
    static VngoPointF   vpoly2[ES_MAX_VERTS];
    static VngoPointF3  vpoly[ES_MAX_VERTS];
    static VngoPointF3  tvpoly[ES_MAX_VERTS];


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("esch_clipdraw_face needs camera in current context",
               EschCurrent != 0 && EschCurrent->camera != 0);

    EschProposedTris++;

    cam=EschCurrent->camera;

//ÄÄÄ Setup values/quick references
    assertMyth("esch_clipdraw_face needs valid draw data in context",
               EschCurrent != 0 && EschCurrent->faces != 0
               && EschCurrent->vpoints != 0 && EschCurrent->vflags != 0
               && EschCurrent->current != 0);

    current=EschCurrent->current;

    face=&EschCurrent->faces[ind];

    cflags = cam->flags;

    points = (VngoPointF3 *)EschCurrent->vpoints;

    // take EschCurrent->vpoints[face->a,b,c] and stuff them into an array
    vpt[0] = &points[face->a];
    vpt[1] = &points[face->b];
    vpt[2] = &points[face->c];

    vpt[0]->u = face->u[0];
    vpt[0]->v = face->v[0];

    vpt[1]->u = face->u[1];
    vpt[1]->v = face->v[1];

    vpt[2]->u = face->u[2];
    vpt[2]->v = face->v[2];

    vflags[0]=&EschCurrent->vflags[face->a];
    vflags[1]=&EschCurrent->vflags[face->b];
    vflags[2]=&EschCurrent->vflags[face->c];

    color = (ctrlfl & ESCH_CDF_COLOR)
            ? EschCurrent->color : vpt[0]->clr;

    vpt[0]->clr = color;
    vpt[1]->clr = color;
    vpt[2]->clr = color;

    edge_count = 3;

//ÄÄÄ Figure out shade level (take minimum of shade levels for
//ÄÄÄ camera, drawable limits, and face limits)

    level = ( (cflags & current->limits)
              | ((ctrlfl & ESCH_CDF_MUSTTXT) ? ESCH_CAM_TEXTURED : 0) )
            & face->flags;

    //ÄÄÄ Perspective mode invalid for ortho cameras
    if (cflags & ESCH_CAM_ORTHO)
        level &= ~ESCH_CAM_PERSPECTIVE;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Perform Backface and/or Clip
    if ((ctrlfl & (ESCH_CDF_BFCULL | ESCH_CDF_CLIP)))
    {
        for (i = 0; i < edge_count; i++)
        {
            tvpoly[i] = *vpt[i]; // copy content to work space so we have solid data instead of pointers
            tvpoly[i].clr = color;
            if (!(level & ESCH_CAM_SHADE_SMOOTH))
                tvpoly[i].shade = points[face->a].shade;
        }

        //ÄÄÄ Back Face Cull if needed.
        if (ctrlfl & ESCH_CDF_BFCULL)
        {
            if (!esch_rotate_check(edge_count,tvpoly,cam))
            {
                return;
            }
        }

        //ÄÄÄ Clip if needed
        if (ctrlfl & ESCH_CDF_CLIP)
        {
            // call the new 3d-clip here.
            int clip_test = esch_clip_to_frustrum(&edge_count, tvpoly, vpoly, cam, level);
            if (clip_test == 1)
            {
                // we've got new points.
                // we need new flags
                lclip_flags = 1;
                for (i=0; i<edge_count; i++)
                {
                    vpt[i] = &vpoly[i];
                    flags[i] = 0;
                    vflags[i] = &flags[i];
                    vpt[i]->clr = color;
                }
            }
            else if (!clip_test)
            {
                // it is fully clipped.
                return;
            }
            // a return of -1 means that the poly was fully visible.
        }
    }

//ÄÄÄ Setup local copies of frequently used data
    assertMyth("esch_clipdraw_face expects current context's camera to have a viewport",
               cam->vport != 0);
    vp=cam->vport;

    edge_adj = vp->skips_last_pix();

    height = float(vp->vbuff.height >> 1);
    width = float(vp->vbuff.width >> 1);

    tx = cam->xscalar;
    ty = cam->yscalar;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Project vertecies
    for(i=0; i < edge_count; i++)
    {
        if (!(*vflags[i] & ESCH_VVERT_PROJECTED))
        {
            *vflags[i] |= ESCH_VVERT_PROJECTED;

            z = vpt[i]->wz;

            if (cflags & ESCH_CAM_ORTHO)
            {
#ifdef ES_SNAP_VERTS
                vpt[i]->x = float(floor((vpt[i]->wx * tx) + width + 0.5f));
                vpt[i]->y = float(floor(height - (vpt[i]->wy * ty) + 0.5f));
#else
                vpt[i]->x = ((vpt[i]->wx * tx) + width);
                vpt[i]->y = (height - (vpt[i]->wy * ty));
#endif
            }
            else
            {
                tv = (vpt[i]->wx * tx) / z;

#ifdef ES_SNAP_VERTS
                vpt[i]->x = float(floor(tv + width + 0.5f));
#else
                vpt[i]->x = tv + width;
#endif
                tv = (vpt[i]->wy * ty) / z;

#ifdef ES_SNAP_VERTS
                vpt[i]->y = float(floor(height - tv + 0.5f));
#else
                vpt[i]->y = height - tv;
#endif
            }

            //!!! w is 2.30 fixed instead of float  (not!)
//            vpt[i]->w = flx_recip230(Flx16(z));
            assert((vpt[i]->wz + 0.000001f) >= cam->hither);
            // MATTL - added .0000001f above as wz projected to 1 was occasionally fractionally under.
            vpt[i]->w = 1.f / vpt[i]->wz;
        }
    }

    int swidth = vp->vbuff.width + edge_adj;
    int sheight = vp->vbuff.height + edge_adj;

    color = (ctrlfl & ESCH_CDF_COLOR)
            ? EschCurrent->color
            : points[face->a].clr;

    float shade;
//    shade = float(EschCurrent->vpoints[face->a].shade);
//    shade = float(((VngoPoint*)points)[face->a].shade);
//    if (*vflags[0] & ESCH_VVERT_SHADE_CONVERT)
        shade = float(points[face->a].shade);
//    else
//        shade = float(((VngoPoint *)points)[face->a].shade);

    for(i=0; i < edge_count; i++)
    {
        vpoly2[i].x      = vpt[i]->x;
        vpoly2[i].y      = vpt[i]->y;
        vpoly2[i].z      = vpt[i]->z;
        vpoly2[i].shade  = vpt[i]->shade;
        vpoly2[i].u      = vpt[i]->u;
        vpoly2[i].v      = vpt[i]->v;

        vpoly2[i].w      = vpt[i]->w;

        vpoly2[i].clr = color;

        if (!(level & ESCH_CAM_SHADE_SMOOTH))
            vpoly2[i].shade = shade; //float(((VngoPoint *)points)[face->a].shade);

        if (vpoly2[i].x < 0.f)
            vpoly2[i].x = 0.f;
        else if (vpoly2[i].x >= swidth)
            vpoly2[i].x = float(swidth-1);
        if (vpoly2[i].y < 0.f)
            vpoly2[i].y = 0.f;
        else if (vpoly2[i].y >= sheight)
            vpoly2[i].y = float(sheight - 1);
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Scale Zs
    assertMyth ("esch_clipdraw_face has invalid polygon after clipping",
                (edge_count > 2) && (edge_count < ES_MAX_VERTS));

    if ((edge_count < 3) || (edge_count > ES_MAX_VERTS))
    {
        return;
    }

    //ÄÄÄ Scale Z between hither & yon
    if (ctrlfl & ESCH_CDF_INFINITEZ)
    {
        for (i=0; i < edge_count; i++)
            vpoly2[i].z = 0.99998f;
    }
    else
    {
        for (i=0; i < edge_count; i++)
        {
            vpoly2[i].z = vpt[i]->wz * cam->z_factor;
        }
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw triangle
    EschDrawnTris++;
    current->flags |= ESCH_DRW_VISIBLE;

    if ((ctrlfl & ESCH_CDF_DONTSORT)
        || (!(cam->flags & ESCH_CAM_SORT) && !(level & ESCH_CAM_ALPHA)))
    {
        if (iesch_immediate(vp, level, face, edge_count, vpoly2, ctrlfl))
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw wireframe
            if (level & ESCH_CAM_SHADE_WIRE)
            {
                if (!lclip_flags)
                {
                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES)
                        || (face->flags & ESCH_FACE_ABLINE))
                        vp->line(&vpoly2[0],&vpoly2[1]);

                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES)
                        || (face->flags & ESCH_FACE_BCLINE))
                        vp->line(&vpoly2[1],&vpoly2[2]);

                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES)
                        || (face->flags & ESCH_FACE_CALINE))
                        vp->line(&vpoly2[2],&vpoly2[0]);
                }
                else
                {
                    for (i=0;i < edge_count-1;i++)
                    {
                        vp->line(&vpoly2[i],&vpoly2[i+1]);
                    }
                    vp->line(&vpoly2[i],&vpoly2[0]);
                }
            }
        }
    }
    else
    {
        if (iesch_elmlist(vp, level, face, edge_count, vpoly2, ctrlfl))
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Wireframe
            if (level & ESCH_CAM_SHADE_WIRE)
            {
                if (!lclip_flags)
                {
                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_ABLINE))
                    {
                        //ÄÄÄ line
                        EschElement *elm = new (EschSysInstance->sspace)
                                        EschLineElement(&vpoly2[0],&vpoly2[1]);

                        assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                                elm != 0);
                        if (elm)
                            elm->insert();
                    }

                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_BCLINE))
                    {
                        //ÄÄÄ line
                        EschElement *elm = new (EschSysInstance->sspace)
                                        EschLineElement(&vpoly2[1],&vpoly2[2]);

                        assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                                elm != 0);
                        if (elm)
                            elm->insert();
                    }

                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_CALINE))
                    {
                        //ÄÄÄ line
                        EschElement *elm = new (EschSysInstance->sspace)
                                        EschLineElement(&vpoly2[2],&vpoly2[0]);

                        assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                                elm != 0);
                        if (elm)
                            elm->insert();
                    }
                }
                else
                {
                    for (i=0;i < edge_count-1;i++)
                    {
                        //ÄÄÄ line
                        EschElement *elm = new (EschSysInstance->sspace)
                                        EschLineElement(&vpoly2[i],&vpoly2[i+1]);

                        assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                                elm != 0);
                        if (elm)
                            elm->insert();
                    }

                    //ÄÄÄ line
                    EschElement *elm = new (EschSysInstance->sspace)
                                            EschLineElement(&vpoly2[i],&vpoly2[0]);

                    assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                            elm != 0);
                    if (elm)
                        elm->insert();
                }
            }
        }
    }
}


#if 0
extern "C" void esch_clipdraw_face(ulong ind, dword ctrlfl)
{
    ulong               i;
    dword               lclip_flags=0;
    ulong               edge_count;
    dword               level;
    dword               cflags;
    dword               color;
    long                height;
    long                width;
    float               tx;
    float               ty;
    float               z;
    float               tv;
    EschCamera          *cam;
    VngoVport           *vp;
    EschDrawable        *current;
    EschFace            *face;
    int                 edge_adj = 0;

    // Static work-space
    static VngoPoint    *vpt[ES_MAX_VERTS];
    static dword        *vflags[ES_MAX_VERTS];
    static dword        flags[ES_MAX_VERTS];
    static VngoPointF   vpoly2[ES_MAX_VERTS];
    static VngoPoint    vpoly[ES_MAX_VERTS];
    static VngoPoint    tvpoly[ES_MAX_VERTS];

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("esch_clipdraw_face needs camera in current context",
               EschCurrent != 0 && EschCurrent->camera != 0);

    EschProposedTris++;

    cam=EschCurrent->camera;

//ÄÄÄ Setup values/quick references
    assertMyth("esch_clipdraw_face needs valid draw data in context",
               EschCurrent != 0 && EschCurrent->faces != 0
               && EschCurrent->vpoints != 0 && EschCurrent->vflags != 0
               && EschCurrent->current != 0);

    current=EschCurrent->current;

    face=&EschCurrent->faces[ind];

    cflags = cam->flags;

    vpt[0] = &EschCurrent->vpoints[face->a];
    vpt[1] = &EschCurrent->vpoints[face->b];
    vpt[2] = &EschCurrent->vpoints[face->c];

//!!! Convert float to Flx16 for Van Gogh
    vpt[0]->u = long(face->u[0] * 65536.0f);
    vpt[0]->v = long(face->v[0] * 65536.0f);

    vpt[1]->u = long(face->u[1] * 65536.0f);
    vpt[1]->v = long(face->v[1] * 65536.0f);

    vpt[2]->u = long(face->u[2] * 65536.0f);
    vpt[2]->v = long(face->v[2] * 65536.0f);

    vflags[0]=&EschCurrent->vflags[face->a];
    vflags[1]=&EschCurrent->vflags[face->b];
    vflags[2]=&EschCurrent->vflags[face->c];

    edge_count = 3;

//ÄÄÄ Figure out shade level (take minimum of shade levels for
//ÄÄÄ camera, drawable limits, and face limits)

    level = ( (cflags & current->limits)
              | ((ctrlfl & ESCH_CDF_MUSTTXT) ? ESCH_CAM_TEXTURED : 0) )
            & face->flags;

    //ÄÄÄ Perspective mode invalid for ortho cameras
    if (cflags & ESCH_CAM_ORTHO)
        level &= ~ESCH_CAM_PERSPECTIVE;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Perform Backface and/or Clip
    if (ctrlfl & (ESCH_CDF_BFCULL | ESCH_CDF_CLIP))
    {
        color = (ctrlfl & ESCH_CDF_COLOR)
                ? EschCurrent->color : vpt[0]->clr;

        for (i=0;i < edge_count;i++)
        {
            tvpoly[i] = *vpt[i]; // copy content to work space.
            tvpoly[i].clr = color;
            if (!(level & ESCH_CAM_SHADE_SMOOTH))
                tvpoly[i].shade = vpt[0]->shade;
        }

        //ÄÄÄ Back Face Cull if needed.
        if (ctrlfl & ESCH_CDF_BFCULL)
        {
            if (!esch_rotate_check(edge_count,tvpoly,cam))
            {
                return;
            }
        }

        //ÄÄÄ Clip if needed
        if (ctrlfl & ESCH_CDF_CLIP)
        {
            // call the new 3d-clip here.
            int cstate = esch_clip_to_frustrum(&edge_count, tvpoly, vpoly,
                                               cam, level);
            if (cstate == 1) // The poly was modified.
            {
                lclip_flags = 1;
                for (i=0;i < edge_count;i++)
                {
                    vpt[i] = &vpoly[i];
                    flags[i] = 0;
                    vflags[i] = &flags[i];
                }
            }
            else if (cstate == 0)   // it is fully clipped.
            {
                return;
            }
            // the return of -1 means that the poly was fully visible.
        }
    }

//ÄÄÄ Setup local copies of frequently used data
    assertMyth("esch_clipdraw_face expects current context's camera to have a viewport",
               cam->vport != 0);
    vp=cam->vport;

    edge_adj = vp->skips_last_pix();

    height = vp->vbuff.height >> 1;
    width = vp->vbuff.width >> 1;

    tx = cam->xscalar;
    ty = cam->yscalar;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Project vertecies
    for(i=0; i < edge_count; i++)
    {
        if (!(*vflags[i] & ESCH_VVERT_PROJECTED))
        {
            *vflags[i] |= ESCH_VVERT_PROJECTED;

            z = ((const EschPoint*)(vpt[i]))->z;

            if (cflags & ESCH_CAM_ORTHO)
            {
                tv = (((const EschPoint*)(vpt[i]))->x * tx);

#ifdef ES_SNAP_VERTS
                vpt[i]->x = long(tv) + width;
#else
                vpt[i]->x = long(tv * 65536.0f) + (width<<16);
#endif
                tv = (((const EschPoint*)(vpt[i]))->y * ty);

#ifdef ES_SNAP_VERTS
                vpt[i]->y = height - long(tv);
#else
                vpt[i]->y = (height<<16) - long(tv * 65536.0f);
#endif
            }
            else
            {
                tv = (((const EschPoint*)(vpt[i]))->x * tx) / z;

#ifdef ES_SNAP_VERTS
                vpt[i]->x = long(tv) + width;
#else
                vpt[i]->x = long(tv * 65536.0f) + (width<<16);
#endif
                tv = (((const EschPoint*)(vpt[i]))->y * ty) / z;

#ifdef ES_SNAP_VERTS
                vpt[i]->y = height - long(tv);
#else
                vpt[i]->y = (height<<16) - long(tv * 65536.0f);
#endif
            }

            //!!! w is 2.30 fixed instead of float
            vpt[i]->w = flx_recip230(Flx16(z));
        }
    }

    int swidth = vp->vbuff.width + edge_adj;
    int sheight = vp->vbuff.height + edge_adj;

    color = (ctrlfl & ESCH_CDF_COLOR)
            ? EschCurrent->color
            : EschCurrent->vpoints[face->a].clr;

    float shade = float(EschCurrent->vpoints[face->a].shade);

    for(i=0; i < edge_count; i++)
    {
        vpoly2[i].x      = float(vpt[i]->x);
        vpoly2[i].y      = float(vpt[i]->y);
        vpoly2[i].z      = float(vpt[i]->z);
        vpoly2[i].shade  = float(vpt[i]->shade);
        vpoly2[i].u      = float(vpt[i]->u) / float(0x10000);
        vpoly2[i].v      = float(vpt[i]->v) / float(0x10000);

        vpoly2[i].w      = float(vpt[i]->w / float(0x3fffffff));

        vpoly2[i].clr = color;

        if (!(level & ESCH_CAM_SHADE_SMOOTH))
            vpoly2[i].shade = shade;

        if (vpoly2[i].x < 0.f)
            vpoly2[i].x = 0.f;
        else if (vpoly2[i].x >= swidth)
            vpoly2[i].x = float(swidth-1);
        if (vpoly2[i].y < 0.f)
            vpoly2[i].y = 0.f;
        else if (vpoly2[i].y >= sheight)
            vpoly2[i].y = float(sheight - 1);
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Scale Zs
    assertMyth ("esch_clipdraw_face has invalid polygon after clipping",
                (edge_count > 2) && (edge_count < ES_MAX_VERTS));

    if ((edge_count < 3) || (edge_count > ES_MAX_VERTS))
    {
        return;
    }

    //ÄÄÄ Scale Z between hither & yon
    if (ctrlfl & ESCH_CDF_INFINITEZ)
    {
        for (i=0; i < edge_count; i++)
            vpoly2[i].z = 0.99998f;
    }
    else
    {
        for (i=0; i < edge_count; i++)
        {
            vpoly2[i].z = (((const EschPoint*)(vpt[i]))->z * cam->z_factor);
        }
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw triangle
    EschDrawnTris++;
    current->flags |= ESCH_DRW_VISIBLE;

    if ((ctrlfl & ESCH_CDF_DONTSORT)
        || (!(cam->flags & ESCH_CAM_SORT) && !(level & ESCH_CAM_ALPHA)))
    {
        if (iesch_immediate(vp, level, face, edge_count, vpoly2, ctrlfl))
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw wireframe
            if (level & ESCH_CAM_SHADE_WIRE)
            {
                if (!lclip_flags)
                {
                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES)
                        || (face->flags & ESCH_FACE_ABLINE))
                        vp->line(&vpoly2[0],&vpoly2[1]);

                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES)
                        || (face->flags & ESCH_FACE_BCLINE))
                        vp->line(&vpoly2[1],&vpoly2[2]);

                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES)
                        || (face->flags & ESCH_FACE_CALINE))
                        vp->line(&vpoly2[2],&vpoly2[0]);
                }
                else
                {
                    for (i=0;i < edge_count-1;i++)
                    {
                        vp->line(&vpoly2[i],&vpoly2[i+1]);
                    }
                    vp->line(&vpoly2[i],&vpoly2[0]);
                }
            }
        }
    }
    else
    {
        if (iesch_elmlist(vp, level, face, edge_count, vpoly2, ctrlfl))
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Wireframe
            if (level & ESCH_CAM_SHADE_WIRE)
            {
                if (!lclip_flags)
                {
                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_ABLINE))
                    {
                        //ÄÄÄ line
                        EschElement *elm = new (EschSysInstance->sspace)
                                        EschLineElement(&vpoly2[0],&vpoly2[1]);

                        assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                                elm != 0);
                        if (elm)
                            elm->insert();
                    }

                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_BCLINE))
                    {
                        //ÄÄÄ line
                        EschElement *elm = new (EschSysInstance->sspace)
                                        EschLineElement(&vpoly2[1],&vpoly2[2]);

                        assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                                elm != 0);
                        if (elm)
                            elm->insert();
                    }

                    if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_CALINE))
                    {
                        //ÄÄÄ line
                        EschElement *elm = new (EschSysInstance->sspace)
                                        EschLineElement(&vpoly2[2],&vpoly2[0]);

                        assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                                elm != 0);
                        if (elm)
                            elm->insert();
                    }
                }
                else
                {
                    for (i=0;i < edge_count-1;i++)
                    {
                        //ÄÄÄ line
                        EschElement *elm = new (EschSysInstance->sspace)
                                        EschLineElement(&vpoly2[i],&vpoly2[i+1]);

                        assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                                elm != 0);
                        if (elm)
                            elm->insert();
                    }

                    //ÄÄÄ line
                    EschElement *elm = new (EschSysInstance->sspace)
                                            EschLineElement(&vpoly2[i],&vpoly2[0]);

                    assertMyth("esch_clipdraw_face() can't allocate sort area memory",
                            elm != 0);
                    if (elm)
                        elm->insert();
                }
            }
        }
    }
}
#endif

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// iesch_immediate                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int iesch_immediate(VngoVport *vp,
                           dword level, EschFace *face,
                           long edge_count, VngoPointF *vpoly, dword ctrlfl)
{
    assertMyth("iesch_immediate() needs vport, face, and vpoly",
               vp != 0 && face != 0 && vpoly != 0);

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Color override mode
    if (ctrlfl & ESCH_CDF_COLOR)
    {
        if (level & (ESCH_CAM_SHADE_FLAT | ESCH_CAM_SHADE_SOLID))
        {
            if (ctrlfl & ESCH_CDF_ALPHA)
            {
                vp->poly_a(edge_count, vpoly, EschCurrent->alpha);
            }
            else if (level & ESCH_CAM_ALPHA)
            {
                vp->poly_a(edge_count, vpoly, face->get_alpha());
            }
            else
            {
                vp->poly(edge_count, vpoly);
            }

            return 0;
        }

        return 1;
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Need to draw with Gouraud-shading
    if (level & ESCH_CAM_SHADE_SMOOTH)
    {
        if (level & ESCH_CAM_TEXTURED)
        {
            assertMyth("iesch_immediate needs textures in current context",
                       EschCurrent->txts);

            EschTexture *texture=EschCurrent->txts[face->txt-1];

            texture->lock();

            if (level & ESCH_CAM_PERSPECTIVE)
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    vp->gtpoly_persp_a(edge_count, vpoly, texture->ptr,
                                       EschCurrent->alpha);
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    vp->gtpoly_persp_a(edge_count, vpoly, texture->ptr,
                                       face->get_alpha());
                }
                else
                {
                    vp->gtpoly_persp(edge_count, vpoly, texture->ptr);
                }
            }
            else
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    vp->gtpoly_a(edge_count, vpoly, texture->ptr,
                                 EschCurrent->alpha);
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    vp->gtpoly_a(edge_count, vpoly, texture->ptr,
                                 face->get_alpha());
                }
                else
                {
                    vp->gtpoly(edge_count, vpoly, texture->ptr);
                }
            }

            texture->unlock();
        }
        else
        {
            if (level & ESCH_CAM_PERSPECTIVE)
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    vp->gpoly_persp_a(edge_count, vpoly, EschCurrent->alpha);
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    vp->gpoly_persp_a(edge_count, vpoly, face->get_alpha());
                }
                else
                {
                    vp->gpoly_persp(edge_count, vpoly);
                }
            }
            else
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    vp->gpoly_a(edge_count, vpoly, EschCurrent->alpha);
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    vp->gpoly_a(edge_count, vpoly, face->get_alpha());
                }
                else
                {
                    vp->gpoly(edge_count,vpoly);
                }
            }
        }

        return 0;
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw with single-color polygon
    else if (level & (ESCH_CAM_SHADE_FLAT | ESCH_CAM_SHADE_SOLID))
    {
        if (level & ESCH_CAM_TEXTURED)
        {
            assertMyth("iesch_immediate needs textures in current context",
                       EschCurrent->txts);

            EschTexture *texture=EschCurrent->txts[face->txt-1];

            texture->lock();

            if (level & ESCH_CAM_PERSPECTIVE)
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    vp->tpoly_persp_a(edge_count, vpoly, texture->ptr,
                                      EschCurrent->alpha);
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    vp->tpoly_persp_a(edge_count, vpoly, texture->ptr,
                                      face->get_alpha());
                }
                else
                {
                    vp->tpoly_persp(edge_count, vpoly, texture->ptr);
                }
            }
            else
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    vp->tpoly_a(edge_count, vpoly, texture->ptr,
                                EschCurrent->alpha);
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    vp->tpoly_a(edge_count, vpoly, texture->ptr,
                                face->get_alpha());
                }
                else
                {
                    vp->tpoly(edge_count, vpoly, texture->ptr);
                }
            }
            texture->unlock();
        }
        else
        {
            if (ctrlfl & ESCH_CDF_ALPHA)
            {
                vp->poly_a(edge_count, vpoly, EschCurrent->alpha);
            }
            else if (level & ESCH_CAM_ALPHA)
            {
                vp->poly_a(edge_count, vpoly, face->get_alpha());
            }
            else
            {
                vp->poly(edge_count, vpoly);
            }
        }

        return 0;
    }

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// iesch_elmlist                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int iesch_elmlist(VngoVport *vp,
                         dword level, EschFace *face,
                         long edge_count, VngoPointF *vpoly, dword ctrlfl)
{
    assertMyth("iesch_elmlist() needs vport, face, and vpoly",
               vp != 0 && face != 0 && vpoly != 0);

    assertMyth("iesch_elmlist() needs EschSysInstance and sort area",
                EschSysInstance && EschSysInstance->sspace);

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Color override mode
    if (ctrlfl & ESCH_CDF_COLOR)
    {
        if (level & (ESCH_CAM_SHADE_FLAT | ESCH_CAM_SHADE_SOLID))
        {
            if (ctrlfl & ESCH_CDF_ALPHA)
            {
                //ÄÄÄ poly_a
                EschPolyAElement *elm = (EschPolyAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                     sizeof(EschPolyAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                assertMyth("iesch_elmlist() can't allocate sort area memory",
                            elm != 0);
                if (elm)
                {
                    elm->EschPolyAElement::EschPolyAElement(edge_count,
                                                                 vpoly,
                                                    EschCurrent->alpha);
                    elm->insert();
                }
            }
            else if (level & ESCH_CAM_ALPHA)
            {
                //ÄÄÄ poly_a
                EschPolyAElement *elm = (EschPolyAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                     sizeof(EschPolyAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                assertMyth("iesch_elmlist() can't allocate sort area memory",
                            elm != 0);
                if (elm)
                {
                    elm->EschPolyAElement::EschPolyAElement(edge_count,
                                                                 vpoly,
                                                     face->get_alpha());
                    elm->insert();
                }
            }
            else
            {
                //ÄÄÄ poly
                EschPolyElement *elm = (EschPolyElement*)
                                ivory_arena_alloc(EschSysInstance->sspace,
                                                    sizeof(EschPolyElement)
                                    + ((edge_count-1)*sizeof(VngoPointF)));

                assertMyth("iesch_elmlist() can't allocate sort area memory",
                            elm != 0);
                if (elm)
                {
                    elm->EschPolyElement::EschPolyElement(edge_count, vpoly);
                    elm->insert();
                }
            }

            return 0;
        }

        return 1;
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Need to draw with Gouraud-shading
    if (level & ESCH_CAM_SHADE_SMOOTH)
    {
        if (level & ESCH_CAM_TEXTURED)
        {
            assertMyth("iesch_elmlist needs textures in current context",
                       EschCurrent->txts);

            EschTexture *texture=EschCurrent->txts[face->txt-1];

            if (level & ESCH_CAM_PERSPECTIVE)
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    //ÄÄÄ gtpoly_persp_a
                    EschPolyTxtAElement *elm = (EschPolyTxtAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                  sizeof(EschPolyTxtAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtAElement::EschPolyTxtAElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                          EschCurrent->alpha,
                                                 ESCH_ELMNT_GTXTPOLY_PERSP_A);
                        elm->insert();
                    }
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    //ÄÄÄ gtpoly_persp_a
                    EschPolyTxtAElement *elm = (EschPolyTxtAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                  sizeof(EschPolyTxtAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtAElement::EschPolyTxtAElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                           face->get_alpha(),
                                                 ESCH_ELMNT_GTXTPOLY_PERSP_A);
                        elm->insert();
                    }
                }
                else
                {
                    //ÄÄÄ gtpoly_persp
                    EschPolyTxtElement *elm = (EschPolyTxtElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                   sizeof(EschPolyTxtElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtElement::EschPolyTxtElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                   ESCH_ELMNT_GTXTPOLY_PERSP);
                        elm->insert();
                    }
                }
            }
            else
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    //ÄÄÄ gtpoly_a
                    EschPolyTxtAElement *elm = (EschPolyTxtAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                  sizeof(EschPolyTxtAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtAElement::EschPolyTxtAElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                          EschCurrent->alpha,
                                                       ESCH_ELMNT_GTXTPOLY_A);
                        elm->insert();
                    }
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    //ÄÄÄ gtpoly_a
                    EschPolyTxtAElement *elm = (EschPolyTxtAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                  sizeof(EschPolyTxtAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtAElement::EschPolyTxtAElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                           face->get_alpha(),
                                                       ESCH_ELMNT_GTXTPOLY_A);
                        elm->insert();
                    }
                }
                else
                {
                    //ÄÄÄ gtpoly
                    EschPolyTxtElement *elm = (EschPolyTxtElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                   sizeof(EschPolyTxtElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtElement::EschPolyTxtElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                         ESCH_ELMNT_GTXTPOLY);
                        elm->insert();
                    }
                }
            }
        }
        else
        {
            if (level & ESCH_CAM_PERSPECTIVE)
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    //ÄÄÄ gpoly_persp_a
                    EschPolyAElement *elm = (EschPolyAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                     sizeof(EschPolyAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyAElement::EschPolyAElement(edge_count,
                                                                     vpoly,
                                                        EschCurrent->alpha,
                                                  ESCH_ELMNT_GPOLY_PERSP_A);
                        elm->insert();
                    }
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    //ÄÄÄ gpoly_persp_a
                    EschPolyAElement *elm = (EschPolyAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                     sizeof(EschPolyAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyAElement::EschPolyAElement(edge_count,
                                                                     vpoly,
                                                         face->get_alpha(),
                                                  ESCH_ELMNT_GPOLY_PERSP_A);
                        elm->insert();
                    }
                }
                else
                {
                    //ÄÄÄ gpoly_persp
                    EschPolyElement *elm = (EschPolyElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                      sizeof(EschPolyElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyElement::EschPolyElement(edge_count,
                                                                   vpoly,
                                                  ESCH_ELMNT_GPOLY_PERSP);
                        elm->insert();
                    }
                }
            }
            else
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    //ÄÄÄ gpoly_a
                    EschPolyAElement *elm = (EschPolyAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                     sizeof(EschPolyAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyAElement::EschPolyAElement(edge_count,
                                                                     vpoly,
                                                        EschCurrent->alpha,
                                                        ESCH_ELMNT_GPOLY_A);
                        elm->insert();
                    }
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    //ÄÄÄ gpoly_a
                    EschPolyAElement *elm = (EschPolyAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                     sizeof(EschPolyAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyAElement::EschPolyAElement(edge_count,
                                                                     vpoly,
                                                         face->get_alpha(),
                                                        ESCH_ELMNT_GPOLY_A);
                        elm->insert();
                    }
                }
                else
                {
                    //ÄÄÄ gpoly
                    EschPolyElement *elm = (EschPolyElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                      sizeof(EschPolyElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyElement::EschPolyElement(edge_count,
                                                                   vpoly,
                                                        ESCH_ELMNT_GPOLY);
                        elm->insert();
                    }
                }
            }
        }

        return 0;
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw with single-color polygon
    else if (level & (ESCH_CAM_SHADE_FLAT | ESCH_CAM_SHADE_SOLID))
    {
        if (level & ESCH_CAM_TEXTURED)
        {
            assertMyth("iesch_elmlist needs textures in current context",
                    EschCurrent->txts);

            EschTexture *texture=EschCurrent->txts[face->txt-1];

            if (level & ESCH_CAM_PERSPECTIVE)
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    //ÄÄÄ tpoly_persp_a
                    EschPolyTxtAElement *elm = (EschPolyTxtAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                  sizeof(EschPolyTxtAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtAElement::EschPolyTxtAElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                          EschCurrent->alpha,
                                                  ESCH_ELMNT_TXTPOLY_PERSP_A);
                        elm->insert();
                    }
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    //ÄÄÄ tpoly_persp_a
                    EschPolyTxtAElement *elm = (EschPolyTxtAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                  sizeof(EschPolyTxtAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtAElement::EschPolyTxtAElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                           face->get_alpha(),
                                                  ESCH_ELMNT_TXTPOLY_PERSP_A);
                        elm->insert();
                    }
                }
                else
                {
                    //ÄÄÄ tpoly_persp
                    EschPolyTxtElement *elm = (EschPolyTxtElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                   sizeof(EschPolyTxtElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtElement::EschPolyTxtElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                    ESCH_ELMNT_TXTPOLY_PERSP);
                        elm->insert();
                    }
                }
            }
            else
            {
                if (ctrlfl & ESCH_CDF_ALPHA)
                {
                    //ÄÄÄ tpoly_a
                    EschPolyTxtAElement *elm = (EschPolyTxtAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                  sizeof(EschPolyTxtAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtAElement::EschPolyTxtAElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                          EschCurrent->alpha);
                        elm->insert();
                    }
                }
                else if (level & ESCH_CAM_ALPHA)
                {
                    //ÄÄÄ tpoly_a
                    EschPolyTxtAElement *elm = (EschPolyTxtAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                  sizeof(EschPolyTxtAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtAElement::EschPolyTxtAElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture,
                                                           face->get_alpha());
                        elm->insert();
                    }
                }
                else
                {
                    //ÄÄÄ tpoly
                    EschPolyTxtElement *elm = (EschPolyTxtElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                   sizeof(EschPolyTxtElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                    assertMyth("iesch_elmlist() can't allocate sort area memory",
                                elm != 0);
                    if (elm)
                    {
                        elm->EschPolyTxtElement::EschPolyTxtElement(
                                                                  edge_count,
                                                                       vpoly,
                                                                     texture);
                        elm->insert();
                    }
                }
            }
        }
        else
        {
            if (ctrlfl & ESCH_CDF_ALPHA)
            {
                //ÄÄÄ poly_a
                EschPolyAElement *elm = (EschPolyAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                     sizeof(EschPolyAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                assertMyth("iesch_elmlist() can't allocate sort area memory",
                            elm != 0);
                if (elm)
                {
                    elm->EschPolyAElement::EschPolyAElement(edge_count,
                                                                 vpoly,
                                                    EschCurrent->alpha);
                    elm->insert();
                }
            }
            else if (level & ESCH_CAM_ALPHA)
            {
                //ÄÄÄ poly_a
                EschPolyAElement *elm = (EschPolyAElement*)
                                   ivory_arena_alloc(EschSysInstance->sspace,
                                                     sizeof(EschPolyAElement)
                                       + ((edge_count-1)*sizeof(VngoPointF)));

                assertMyth("iesch_elmlist() can't allocate sort area memory",
                            elm != 0);
                if (elm)
                {
                    elm->EschPolyAElement::EschPolyAElement(edge_count,
                                                                 vpoly,
                                                     face->get_alpha());
                    elm->insert();
                }
            }
            else
            {
                //ÄÄÄ poly
                EschPolyElement *elm = (EschPolyElement*)
                                ivory_arena_alloc(EschSysInstance->sspace,
                                                    sizeof(EschPolyElement)
                                    + ((edge_count-1)*sizeof(VngoPointF)));

                assertMyth("iesch_elmlist() can't allocate sort area memory",
                            elm != 0);
                if (elm)
                {
                    elm->EschPolyElement::EschPolyElement(edge_count, vpoly);
                    elm->insert();
                }
            }
        }

        return 0;
    }

    return 1;
}

//°±² End of module - esdrface.cpp ²±°

