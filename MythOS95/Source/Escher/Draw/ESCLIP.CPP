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

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define ES_MAX_VERTS 9

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" int esch_clip_to_plane(int *count, VngoPoint *in, VngoPoint *out,
                                  EschPlane *plane, dword flags);

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
extern "C" int esch_clip_to_frustrum (ulong *rcount, VngoPoint *pts,
                                       VngoPoint *outpts,
                                       EschCamera *cam, dword flags)
{
    int i;
    int modified=0;
    int ycount=0;
    int hcount=0;
    int count = int(*rcount);
    int cstate;
    VngoPoint *work1;
    VngoPoint *work2;
    VngoPoint *t;

    // Trivialy accept/reject of near/far first.
    for (i=0;i < count;i++)
    {
        if (pts[i].wz > cam->yon.flx)
            ycount++;
        if (pts[i].wz < cam->hither.flx)
            hcount++;
    }
    if ((ycount >= count) || (hcount >= count))
    {
        return 0;
    }

    Flx16 tx;
    Flx16 ty;

    dword lclip_flags=0;

    for(i=0; i < count; i++)
    {
        tx.flx = flx_16mul16( Flx16(pts[i].wz,1) , cam->xsize ).flx;
        ty.flx = flx_16mul16( Flx16(pts[i].wz,1) , cam->ysize ).flx;

        long x = pts[i].wx;

        if (x < -tx.flx)
        {
            lclip_flags |= 0x1 << (4*i);
        }
        else if (x > tx.flx)
        {
            lclip_flags |= 0x2 << (4*i);
        }

        long y = pts[i].wy;
        if (y < -ty.flx)
        {
            lclip_flags |= 0x4 << (4*i);
        }
        else if (y > ty.flx)
        {
            lclip_flags |= 0x8 << (4*i);
        }
    }
    // if any of the bits are set, then it is off the screen.
    if (lclip_flags)
    {
        i=0;
        dword r=0xffffffff;
        for(dword t=lclip_flags; i < count; i++)
        {
            r &= (t & 0xf);
            t >>= 4;
        }
        if (r)
            return 0;
    }
    else if (!ycount && !hcount)
    {
        return -1;
    }

    lclip_flags = 0xf;


    work1 = pts;
    work2 = outpts;

    // Clip to the YON plane.
    if (ycount)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_YON],
                                    flags);

        if (!cstate)
            return 0;
        else if (cstate == 1)
        {
            modified=1;
            t = work1;
            work1 = work2;
            work2 = t;
        }
    }
    // Clip to the HITHER plane.
    if (hcount)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_HITHER],
                                    flags);

        if (!cstate)
            return 0;
        else if (cstate == 1)
        {
            modified=1;
            t = work1;
            work1 = work2;
            work2 = t;
        }
    }

    // Clip to the TOP plane.
    if (lclip_flags & 0x44444444)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                        &cam->frustrum[ESCH_CAM_FRUSTRUM_TOP],
                                        flags);
        if (!cstate)
            return 0;
        else if (cstate == 1)
        {
            modified=1;
            t = work1;
            work1 = work2;
            work2 = t;
        }
    }

    // Clip to the BOTTOM plane.
    if (lclip_flags & 0x88888888)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_BOTTOM],
                                    flags);
        if (!cstate)
            return 0;
        else if (cstate == 1)
        {
            modified=1;
            t = work1;
            work1 = work2;
            work2 = t;
        }
    }

    // Clip to the RIGHT plane.
    if (lclip_flags & 0x11111111)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_RIGHT],
                                    flags);
        if (!cstate)
            return 0;
        else if (cstate == 1)
        {
            modified=1;
            t = work1;
            work1 = work2;
            work2 = t;
        }
    }

    // Clip to the LEFT plane.
    if (lclip_flags & 0x22222222)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_LEFT],
                                    flags);
        if (!cstate)
            return 0;
        else if (cstate == 1)
        {
            modified=1;
        }
    }

    if (work2 != outpts)
    {
        memcpy(outpts,work2,(count * sizeof(VngoPoint)));
    }

    *rcount = ulong(count);
    if (!modified)
        modified=-1;

    return modified;
}


extern "C" int esch_clip_to_plane(int *count, VngoPoint *in, VngoPoint *out,
                                  EschPlane *plane, dword flags)
{
// This code is take from Abrash's 3D-clipping example 
// DDJ Source Book March/April '95

    int         i,curin,nextin;
    int         modified = -1;
    Flx16       curdot,nextdot,scale;
    VngoPoint   *cvert,*nvert;
    int         local_count=0;

    cvert = &in[*count-1];

    curdot = *((EschVector *)cvert) DOT plane->normal;
    curin = (curdot >= plane->dist);

    for (i=0; i < *count; i++)
    {
        nvert = &in[i];

        if (curin)
        {
            *out++ = *cvert;
            local_count++;
        }

        nextdot = *((EschVector *)nvert) DOT plane->normal;
        nextin = (nextdot >= plane->dist);

        if (curin != nextin)
        {   // It crossed the plane.
            scale = (plane->dist - curdot) / (nextdot - curdot);

            // Calc the new components.
            out->wx = (Flx16(cvert->wx,0) + (Flx16(nvert->wx - cvert->wx,0) * scale)).flx;
            out->wy = (Flx16(cvert->wy,0) + (Flx16(nvert->wy - cvert->wy,0) * scale)).flx;
            out->wz = (Flx16(cvert->wz,0) + (Flx16(nvert->wz - cvert->wz,0) * scale)).flx;

            if (flags & ESCH_CAM_TEXTURED)
            {
                out->u = (Flx16(cvert->u,0) + (Flx16(nvert->u - cvert->u,0) * scale)).flx;
                out->v = (Flx16(cvert->v,0) + (Flx16(nvert->v - cvert->v,0) * scale)).flx;
            }
            if (flags & ESCH_CAM_SHADE_SMOOTH)
            {
                out->shade = (Flx16(cvert->shade) + (Flx16(nvert->shade - cvert->shade) * scale)); 
            }
            else
            {
                out->shade = cvert->shade;
            }
            out->clr = cvert->clr;
            out++;
            modified = 1;
            local_count++;
        }
        curdot = nextdot;
        curin = nextin;
        cvert = nvert;
    }
    if (local_count < 3)
        return 0;

    *count = local_count;

    return modified;
}


int esch_rotate_check(ulong count, VngoPoint2 *pts)
{
    if (count < 3)
        return 0;

    long v1i,v1j,v2i,v2j;
    long t;

    v1i = (pts[0].x - pts[1].x) >> 12;
    v1j = (pts[0].y - pts[1].y) >> 12;
    v2i = (pts[2].x - pts[1].x) >> 12;
    v2j = (pts[2].y - pts[1].y) >> 12;

    t = (v1i * v2j) - (v1j * v2i);

    if (t <= 0)
        return 1;
    else
        return 0;
}

int esch_rotate_check(ulong count, VngoPoint *pts, EschCamera *cam)
{
    if (count < 3)
        return 0;

    if (cam == NULL)
    {
        long v1i,v1j,v2i,v2j;
        long t;

        v1i = (pts[0].x - pts[1].x);
        v1j = (pts[0].y - pts[1].y);
        v2i = (pts[2].x - pts[1].x);
        v2j = (pts[2].y - pts[1].y);

        t = (v1i * v2j) - (v1j * v2i);

        if (t > 0)
            return 0;
        else
            return 1;
    }
    else
    {
#if 1
        static double flxcnv = (1. / 65536.);

        // for now we need to normalize all 3 vectors 
        // to make sure they stay in range.
        double vi = double(pts[0].wx) * flxcnv;
        double vj = double(pts[0].wy) * flxcnv;
        double vk = double(pts[0].wz) * flxcnv;

        // For Abrams, we can assume that the vectors of the polygon are always less than
        // 128 units big.  That ensures that the cross product will not overflow.
        double ai = double(pts[0].wx - pts[1].wx) * flxcnv;
        double aj = double(pts[0].wy - pts[1].wy) * flxcnv;
        double ak = double(pts[0].wz - pts[1].wz) * flxcnv;

        double bi = double(pts[2].wx - pts[1].wx) * flxcnv;
        double bj = double(pts[2].wy - pts[1].wy) * flxcnv;
        double bk = double(pts[2].wz - pts[1].wz) * flxcnv;

        double fi = (aj * bk) - (ak * bj);
        double fj = (ak * bi) - (ai * bk);
        double fk = (ai * bj) - (aj * bi);

        double dir = (vi * fi) + (vj * fj) + (vk * fk);

        if (dir < 0)
            return 0;
        else
            return 1;
#else
        // for now we need to normalize all 3 vectors 
        // to make sure they stay in range.
        EschVector  view;
        view.i.flx = pts[0].wx;
        view.j.flx = pts[0].wy;
        view.k.flx = pts[0].wz;

        view.normalize();

        // For Abrams, we can assume that the vectors of the polygon are always less than
        // 128 units big.  That ensures that the cross product will not overflow.
        EschVector  a,b;
        a.i.flx = pts[0].wx - pts[1].wx;
        a.j.flx = pts[0].wy - pts[1].wy;
        a.k.flx = pts[0].wz - pts[1].wz;
        a.normalize();

        b.i.flx = pts[2].wx - pts[1].wx;
        b.j.flx = pts[2].wy - pts[1].wy;
        b.k.flx = pts[2].wz - pts[1].wz;
        b.normalize();

        EschVector f = b CROSS a;

        if ((view DOT f).flx > 0)
            return 0;
        else
            return 1;
#endif
    }
}
