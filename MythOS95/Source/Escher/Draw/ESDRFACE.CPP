//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששש°°°°°°°°°°ש°°°°°°°°ששש°°°°°°°°שש°°°שששש°°°ש°°°°°°°°°°ש°°°°°°°°°שש
//ששששששששש°±°ששששששש°±°שששש°±°ש°±°שששש°±°ש°±°שששש°±°ש°±°שששששששש°±°שששש°±°שש
//שששששששש±°±ששששששש±°±שששששששש±°±שששששששש±°±שששש±°±ש±°±שששששששש±°±שששש±°±ששש
//ששששששש±²±±°±±²שש±²±±°±±²±±ש±²±שששששששש±²±±°±±²±±ש±²±±°±±²ששש±²±±°±±²°ששששש
//שששששש±²±שששששששששששששש±²±ש±²±שששששששש±²±שששש±²±ש±²±שששששששש±²±שששש±²±ששששש
//ששששש²±²ששששששש²±²שששש²±²ש²±²שששש²±²ש²±²שששש²±²ש²±²שששששששש²±²שששש²±²שששששש
//שששש²²²²²²²²²²ש²²²²²²²²ששש²²²²²²²²שש²²²שששש²²²ש²²²²²²²²²²ש²²²שששש²²²ששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששששCopyrightש(c)ש1994-1997שbyשCharybdisשEnterprises,שInc.שששששששששש
//ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ששששששששששששששששששששש Microsoft Windows '95 Version ששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
// Created by Tim Little & Chuck Walbourn
//
// esdrface.cpp
//
// Contains the C++ implementation of the clip/draw function for faces
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"
#include <limits.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                 Data
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

ulong EschProposedTris=0;
ulong EschDrawnTris=0;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" int esch_clip_to_frustrum (ulong *count, VngoPoint *pts,
                                       VngoPoint *outpts,
                                       EschCamera *cam, dword flags);


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define ES_MAX_VERTS 9
#define ES_SNAP_VERTS

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// esch_clipdraw_face                                                       ³
//                                                                          ³
// Draws a face using the current object information in the context.        ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
extern "C" void esch_clipdraw_face(ulong ind, dword ctrlfl)
{
    ulong               i;
    Flx16               tx, ty;
    dword               lclip_flags=0;

    // Static work-space
    static VngoPoint    *vpt[ES_MAX_VERTS];
    static dword        *vflags[ES_MAX_VERTS];
    static dword        flags[ES_MAX_VERTS];
#ifdef ES_SNAP_VERTS
    static VngoPoint    vpoly2[ES_MAX_VERTS]; 
#else
    static VngoPoint2   vpoly2[ES_MAX_VERTS];
#endif
    static VngoPoint    vpoly[ES_MAX_VERTS];
    static VngoPoint    tvpoly[ES_MAX_VERTS];

//ִִִ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("esch_clipdraw_face needs camera in current context",
               EschCurrent != 0 && EschCurrent->camera != 0);

    EschProposedTris++;

    EschCamera *cam=EschCurrent->camera;

//ִִִ Setup values/quick references
    assertMyth("esch_clipdraw_face needs valid draw data in context",
               EschCurrent != 0 && EschCurrent->faces != 0
               && EschCurrent->vpoints != 0 && EschCurrent->vflags != 0
               && EschCurrent->current != 0);

    EschDrawable *current=EschCurrent->current;

    EschFace *face=&EschCurrent->faces[ind];

    dword cflags = cam->flags;

    vpt[0] = &EschCurrent->vpoints[face->a];
    vpt[1] = &EschCurrent->vpoints[face->b];
    vpt[2] = &EschCurrent->vpoints[face->c];

    vpt[0]->u = face->u[0].flx;
    vpt[0]->v = face->v[0].flx;

    vpt[1]->u = face->u[1].flx;
    vpt[1]->v = face->v[1].flx;

    vpt[2]->u = face->u[2].flx;
    vpt[2]->v = face->v[2].flx;

    vflags[0]=&EschCurrent->vflags[face->a];
    vflags[1]=&EschCurrent->vflags[face->b];
    vflags[2]=&EschCurrent->vflags[face->c];

    ulong edge_count = 3;

    //ִִִ Figure out shade level (take minimum of shade levels for
    //ִִִ camera, drawable limits, and face limits)

    dword level = ( (cflags & current->limits)
                    | ((ctrlfl & ESCH_CDF_MUSTTXT) ? ESCH_CAM_TEXTURED : 0) )
                  & face->flags;


    for (i=0;i < edge_count;i++)
    {
        tvpoly[i] = *vpt[i]; // copy content to work space.
        tvpoly[i].clr = vpt[0]->clr;
        if (!(level & ESCH_CAM_SHADE_SMOOTH))
            tvpoly[i].shade = vpt[0]->shade;
    }

#if 1
//ִִִ Back Face Cull if needed.
    if (ctrlfl & ESCH_CDF_BFCULL)
    {
        if (!esch_rotate_check(edge_count,tvpoly,cam))
            return;
    }
#endif


//ִִִ Clip if needed
    if (ctrlfl & ESCH_CDF_CLIP)
    {
        // call the new 3d-clip here.
        int cstate = esch_clip_to_frustrum(&edge_count,tvpoly,vpoly,cam,level);
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

//ִִִ Setup local copies of frequently used data
    assertMyth("esch_clipdraw_face expects current context's camera to have a viewport",
               cam->vport != 0);
    VngoVport *vp=cam->vport;

    Flx16 height(vp->vbuff.height >> 1);
    Flx16 width(vp->vbuff.width >> 1);

    tx = cam->xscalar;
    ty = cam->yscalar;


//ִִִ Project vertecies
    for(i=0; i < edge_count; i++)
    {
        if (!(*vflags[i] & ESCH_VVERT_PROJECTED))
        {

            Flx16 z= Flx16(vpt[i]->wz,1);

            Flx16 tv = flx_muldiv(Flx16(vpt[i]->wx,1),tx,z);
#ifdef ES_SNAP_VERTS 
            vpt[i]->x = (width.flx + tv.flx) >> 16;
#else
            vpt[i]->x = (width.flx + tv.flx);
#endif
            tv = flx_muldiv(Flx16(vpt[i]->wy,1),ty,z);

#ifdef ES_SNAP_VERTS 
            vpt[i]->y = (height.flx - tv.flx) >> 16;
#else
            vpt[i]->y = (height.flx - tv.flx);
#endif

            vpt[i]->w = flx_recip230(z);

            *vflags[i] |= ESCH_VVERT_PROJECTED;
        }
    }
    int swidth = cam->vport->vbuff.width;
    int sheight = cam->vport->vbuff.height;

    for(i=0; i < edge_count; i++)
    {
//        vpoly2[i].wz     = vpt[i]->wz;
        vpoly2[i].x      = vpt[i]->x;
        vpoly2[i].y      = vpt[i]->y;
        vpoly2[i].z      = vpt[i]->z;
        vpoly2[i].shade  = vpt[i]->shade;
        vpoly2[i].u      = vpt[i]->u;
        vpoly2[i].v      = vpt[i]->v;
        vpoly2[i].w      = vpt[i]->w;

        vpoly2[i].clr = EschCurrent->vpoints[face->a].clr;

        if (!(level & ESCH_CAM_SHADE_SMOOTH))
            vpoly2[i].shade = EschCurrent->vpoints[face->a].shade;

#ifdef ES_SNAP_VERTS 
        if (vpoly2[i].x < 0)
            vpoly2[i].x = 0;
        else if (vpoly2[i].x >= swidth)
            vpoly2[i].x = swidth-1;
        if (vpoly2[i].y < 0)
            vpoly2[i].y = 0;
        else if (vpoly2[i].y >= sheight)
            vpoly2[i].y = sheight - 1;
#else
        int tswidth = (swidth << 16) - 0x8080;
        int tsheight = (sheight << 16) - 0x8080;

        if (vpoly2[i].x < 0)
            vpoly2[i].x = 0;
        else if (vpoly2[i].x > tswidth)
            vpoly2[i].x = tswidth;
        if (vpoly2[i].y < 0)
            vpoly2[i].y = 0;
        else if (vpoly2[i].y > tsheight)
            vpoly2[i].y = tsheight;
#endif
    }

#if 0
//ִִִ Back Face Cull if needed.
    if (ctrlfl & ESCH_CDF_BFCULL)
    {
        if (!esch_rotate_check(edge_count,vpoly2))
        {
            return;
        }
    }
#endif

//ִִִ Draw triangle
    assertMyth ("esch_clipdraw_face has invalid polygon before clipping",
                (edge_count > 2) && (edge_count < ES_MAX_VERTS));

    if ((edge_count < 3) || (edge_count > ES_MAX_VERTS))
    {
        return;
    }
    assertMyth ("esch_clipdraw_face has invalid polygon post clipping",
                (edge_count > 2) && (edge_count < ES_MAX_VERTS));

    //ִִִ Scale Z between hither & yon
    if (ctrlfl & ESCH_CDF_INFINITEZ)
    {
        for (i=0; i < edge_count; i++)
            vpoly2[i].z = 0xfffeffff;
    }
    else
    {
        for (i=0; i < edge_count; i++)
            vpoly2[i].z = flx_16mul16(Flx16(vpt[i]->wz,1),cam->z_factor).flx << 1;
    }

    EschDrawnTris++;
    current->flags |= ESCH_DRW_VISIBLE;

    //ִִִ Need to draw with Gouraud-shading
    if (level & ESCH_CAM_SHADE_SMOOTH)
    {
        if (level & ESCH_CAM_TEXTURED)
        {
            assertMyth("esch_clipdraw_face needs textures in current context",
                       EschCurrent->txts);

            EschTexture *texture=EschCurrent->txts[face->txt-1];

            texture->lock();

            if (level & ESCH_CAM_PERSPECTIVE)
            {
                if (level & ESCH_CAM_ALPHA)
                {
                    vp->gtpoly_persp_a(edge_count,vpoly2,texture->ptr,face->get_alpha());
                }
                else
                {
                    vp->gtpoly_persp(edge_count,vpoly2,texture->ptr);
                }
            }
            else
            {
                if (level & ESCH_CAM_ALPHA)
                    vp->gtpoly_a(edge_count,vpoly2,texture->ptr,face->get_alpha());
                else
                    vp->gtpoly(edge_count,vpoly2,texture->ptr);
            }
            texture->unlock();
        }
        else
        {
            if (level & ESCH_CAM_PERSPECTIVE)
            {
                if (level & ESCH_CAM_ALPHA)
                    vp->gpoly_persp_a(edge_count,vpoly2,face->get_alpha());
                else
                    vp->gpoly_persp(edge_count,vpoly2);
            }
            else
            {
                if (level & ESCH_CAM_ALPHA)
                    vp->gpoly_a(edge_count,vpoly2,face->get_alpha());
                else
                    vp->gpoly(edge_count,vpoly2);
            }
        }

        return;
    }

    //ִִִ Draw with single-color polygon
    else if (level & (ESCH_CAM_SHADE_FLAT | ESCH_CAM_SHADE_SOLID))
    {
        if (level & ESCH_CAM_TEXTURED)
        {
            assertMyth("esch_clipdraw_face needs textures in current context",
                       EschCurrent->txts);

            EschTexture *texture=EschCurrent->txts[face->txt-1];

            texture->lock();

            if (level & ESCH_CAM_PERSPECTIVE)
            {
                if (level & ESCH_CAM_ALPHA)
                    vp->tpoly_persp_a(edge_count,vpoly2,texture->ptr,face->get_alpha());
                else
                    vp->tpoly_persp(edge_count,vpoly2,texture->ptr);
            }
            else
            {
                if (level & ESCH_CAM_ALPHA)
                    vp->tpoly_a(edge_count,vpoly2,texture->ptr,face->get_alpha());
                else
                    vp->tpoly(edge_count,vpoly2,texture->ptr);
            }
            texture->unlock();
        }
        else
        {
            if (level & ESCH_CAM_ALPHA)
                vp->poly_a(edge_count,vpoly2,face->get_alpha());
            else
                vp->poly(edge_count,vpoly2);
        }

        return;
    }

    //ִִִ Draw wireframe
    if (!lclip_flags)
    {
        if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_ABLINE))
            vp->line(&vpoly2[0],&vpoly2[1]);

        if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_BCLINE))
            vp->line(&vpoly2[1],&vpoly2[2]);

        if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_CALINE))
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



//°±² End of module - esdrface.cpp ²±°

