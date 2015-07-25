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
//ששששששששששששששששששש Microsoft Windows 95/NT Version ששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששששCopyrightש(c)ש1994-1998שbyשCharybdisשEnterprises,שInc.שששששששששש
//ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
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
// esclip.cpp
//
// Contains the implementation of the clip support functions
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// esch_clip_to_frustrum                                                    ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
extern "C" int esch_clip_to_frustrum (ulong *rcount, VngoPointF3 *pts,
                                      VngoPointF3 *outpts,
                                      EschCamera *cam, dword level)
{
    assertMyth("esch_clip_to_frustrum needs valid input",
               rcount != 0 && pts != 0 && outpts != 0 && cam != 0);

    int         i;
    int         modified=0;
    int         ycount=0;
    int         hcount=0;
    int         count = int(*rcount);
    int         cstate;
    dword       lclip_flags=0;
    VngoPointF3 *work1;
    VngoPointF3 *work2;
    VngoPointF3 *t;
    float       x, y, tx, ty;
    dword       cflags;

//ִִִ Trivial accept/reject of near/far first.
    for (i=0; i < count; i++)
    {
        if (pts[i].wz > cam->yon)
            ycount++;
        if (pts[i].wz < cam->hither)
            hcount++;
    }
    if ((ycount >= count) || (hcount >= count))
    {
        return 0;
    }

//ִִִ Determine clip flags
    cflags = cam->flags;

    for(i=0; i < count; i++)
    {
        if (cflags & ESCH_CAM_ORTHO)
        {
            tx = cam->xsize;
            ty = cam->ysize;
        }
        else
        {
            tx = pts[i].wz * cam->xsize;
            ty = pts[i].wz * cam->ysize;
        }

        x = pts[i].wx;
        if (x < -tx)
        {
            lclip_flags |= 0x1 << (4*i);
        }
        else if (x > tx)
        {
            lclip_flags |= 0x2 << (4*i);
        }

        y = pts[i].wy;
        if (y < -ty)
        {
            lclip_flags |= 0x4 << (4*i);
        }
        else if (y > ty)
        {
            lclip_flags |= 0x8 << (4*i);
        }
    }

//ִִִ If any of the bits are set, then it is off the screen.
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

    // HACK:  If you do only partial clip tests, things get way out of
    //        whack for some reason...  this forces all four tests if
    //        any are needed.
    lclip_flags = 0xf;

    work1 = pts;
    work2 = outpts;

//ִִִ Clip to the YON plane.
    if (ycount)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_YON],
                                    level);

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

//ִִִ Clip to the HITHER plane.
    if (hcount)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_HITHER],
                                    level);

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

//ִִִ Clip to the TOP plane.
    if (lclip_flags & 0x44444444)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_TOP],
                                    level);
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

//ִִִ Clip to the BOTTOM plane.
    if (lclip_flags & 0x88888888)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_BOTTOM],
                                    level);
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

//ִִִ Clip to the RIGHT plane.
    if (lclip_flags & 0x11111111)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_RIGHT],
                                    level);
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

//ִִִ Clip to the LEFT plane.
    if (lclip_flags & 0x22222222)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_LEFT],
                                    level);
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


#if 0
extern "C" int esch_clip_to_frustrum (ulong *rcount, VngoPoint *pts,
                                      VngoPoint *outpts,
                                      EschCamera *cam, dword level)
{
    assertMyth("esch_clip_to_frustrum needs valid input",
               rcount != 0 && pts != 0 && outpts != 0 && cam != 0);

    int         i;
    int         modified=0;
    int         ycount=0;
    int         hcount=0;
    int         count = int(*rcount);
    int         cstate;
    dword       lclip_flags=0;
    VngoPoint   *work1;
    VngoPoint   *work2;
    VngoPoint   *t;
    float       x, y, tx, ty;
    dword       cflags;

//ִִִ Trivialy accept/reject of near/far first.
    for (i=0; i < count; i++)
    {
        if (((const EschPoint*)(&pts[i]))->z > cam->yon)
            ycount++;
        if (((const EschPoint*)(&pts[i]))->z < cam->hither)
            hcount++;
    }
    if ((ycount >= count) || (hcount >= count))
    {
        return 0;
    }

//ִִִ Determine clip flags
    cflags = cam->flags;

    for(i=0; i < count; i++)
    {
        if (cflags & ESCH_CAM_ORTHO)
        {
            tx = cam->xsize;
            ty = cam->ysize;
        }
        else
        {
            tx = ((const EschPoint*)(&pts[i]))->z * cam->xsize;
            ty = ((const EschPoint*)(&pts[i]))->z * cam->ysize;
        }

        x = ((const EschPoint*)(&pts[i]))->x;
        if (x < -tx)
        {
            lclip_flags |= 0x1 << (4*i);
        }
        else if (x > tx)
        {
            lclip_flags |= 0x2 << (4*i);
        }

        y = ((const EschPoint*)(&pts[i]))->y;
        if (y < -ty)
        {
            lclip_flags |= 0x4 << (4*i);
        }
        else if (y > ty)
        {
            lclip_flags |= 0x8 << (4*i);
        }
    }

//ִִִ If any of the bits are set, then it is off the screen.
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

    // HACK:  If you do only partial clip tests, things get way out of
    //        whack for some reason...  this forces all four tests if
    //        any are needed.
    lclip_flags = 0xf;

    work1 = pts;
    work2 = outpts;

//ִִִ Clip to the YON plane.
    if (ycount)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_YON],
                                    level);

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

//ִִִ Clip to the HITHER plane.
    if (hcount)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_HITHER],
                                    level);

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

//ִִִ Clip to the TOP plane.
    if (lclip_flags & 0x44444444)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_TOP],
                                    level);
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

//ִִִ Clip to the BOTTOM plane.
    if (lclip_flags & 0x88888888)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_BOTTOM],
                                    level);
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

//ִִִ Clip to the RIGHT plane.
    if (lclip_flags & 0x11111111)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_RIGHT],
                                    level);
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

//ִִִ Clip to the LEFT plane.
    if (lclip_flags & 0x22222222)
    {
        cstate = esch_clip_to_plane(&count,work1,work2,
                                    &cam->frustrum[ESCH_CAM_FRUSTRUM_LEFT],
                                    level);
        if (!cstate)
            return 0;
        else if (cstate == 1)
        {
            modified=1;
        }
    }

    if (work2 != outpts)
    {
        memcpy(outpts,work2,(count * sizeof(VngoPointF3)));
    }

    *rcount = ulong(count);
    if (!modified)
        modified=-1;

    return modified;
}
#endif


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// esch_clip_to_plane                                                       ³
//                                                                          ³
// This code is take from Abrash's 3D-clipping example                      ³
// DDJ Source Book March/April '95                                          ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
#if 1
extern "C" int esch_clip_to_plane(int *count, VngoPointF3 *in, VngoPointF3 *out,
                                  EschPlane *plane, dword level)
{
    int         i,curin,nextin;
    int         modified = -1;
    float       curdot,nextdot,scale;
    VngoPointF3 *cvert,*nvert;
    int         local_count=0;

    assertMyth("esch_clip_to_plane needs valid input",
               count != 0 && in != 0 && out != 0 && plane != 0);

    assertMyth("esch_clip_to_plane() needs valid count",
               *count >= 2);

    if (*count > 2)
    {
        cvert = &in[*count-1];

        curdot = *((EschVector *)cvert) DOT plane->normal;
        curin = (curdot >= plane->dist);

        for (i=0; i < *count; i++)
        {
            nvert = &in[i];

            if (curin)
            {
                *out = *cvert;
                out++;
                local_count++;
            }

            nextdot = *((EschVector *)nvert) DOT plane->normal;
            nextin = (nextdot >= plane->dist);

            if (curin != nextin)
            {
                // It crossed the plane.
                scale = (plane->dist - curdot) / (nextdot - curdot);

                // Calc the new components.
                out->wx = cvert->wx + ( ( nvert->wx - cvert->wx ) * scale );
                out->wy = cvert->wy + ( ( nvert->wy - cvert->wy ) * scale );
                out->wz = cvert->wz + ( ( nvert->wz - cvert->wz ) * scale );

                if (level & ESCH_CAM_TEXTURED)
                {
                    //!!! u/v are still fixed point!
                    out->u = cvert->u + (nvert->u - cvert->u) * scale;
                    out->v = cvert->v + (nvert->v - cvert->v) * scale;
                }
                if (level & ESCH_CAM_SHADE_SMOOTH)
                {
                    out->shade = cvert->shade + long(float(nvert->shade - cvert->shade) * scale);
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
    }
    else
    {
        cvert = &in[0];
        curdot = *((EschVector *)cvert) DOT plane->normal;
        curin = (curdot >= plane->dist);
        if (curin)
        {
            *out = *cvert;
            out++;
            local_count++;
        }

        nvert = &in[1];
        nextdot = *((EschVector *)nvert) DOT plane->normal;
        nextin = (nextdot >= plane->dist);

        if (nextin)
        {
            *out = *nvert;
            out++;
            local_count ++;
        }

        if (curin != nextin
            && local_count < 2)
        {
            // It crossed the plane.
            scale = (plane->dist - curdot) / (nextdot - curdot);

            // Calc the new components.
            out->wx = cvert->wx + ( ( nvert->wx - cvert->wx ) * scale );
            out->wy = cvert->wy + ( ( nvert->wy - cvert->wy ) * scale );
            out->wz = cvert->wz + ( ( nvert->wz - cvert->wz ) * scale );

            if (level & ESCH_CAM_TEXTURED)
            {
                //!!! u/v are still fixed point!
                out->u = cvert->u + (nvert->u - cvert->u) * scale;
                out->v = cvert->v + (nvert->v - cvert->v) * scale;
            }
            if (level & ESCH_CAM_SHADE_SMOOTH)
            {
                out->shade = cvert->shade + long(float(nvert->shade - cvert->shade) * scale);
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
    }
    return modified;
}
#else
extern "C" int esch_clip_to_plane(int *count, VngoPoint *in, VngoPoint *out,
                                  EschPlane *plane, dword level)
{
    int         i,curin,nextin;
    int         modified = -1;
    float       curdot,nextdot,scale;
    VngoPoint   *cvert,*nvert;
    int         local_count=0;

    assertMyth("esch_clip_to_plane needs valid input",
               count != 0 && in != 0 && out != 0 && plane != 0);

    assertMyth("esch_clip_to_plane() needs valid count",
               *count >= 2);

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
        {
            // It crossed the plane.
            scale = (plane->dist - curdot) / (nextdot - curdot);

            // Calc the new components.
            ((EschPoint*)out)->x = ((const EschPoint*)cvert)->x
                                   + ( ( ((const EschPoint*)nvert)->x
                                         - ((const EschPoint*)cvert)->x ) * scale );
            ((EschPoint*)out)->y = ((const EschPoint*)cvert)->y
                                   + ( ( ((const EschPoint*)nvert)->y
                                         - ((const EschPoint*)cvert)->y ) * scale );
            ((EschPoint*)out)->z = ((const EschPoint*)cvert)->z
                                   + ( ( ((const EschPoint*)nvert)->z
                                         - ((const EschPoint*)cvert)->z ) * scale );

            if (level & ESCH_CAM_TEXTURED)
            {
                //!!! u/v are still fixed point!
                out->u = (Flx16(cvert->u,0) + (Flx16(nvert->u - cvert->u,0) * Flx16(scale))).flx;
                out->v = (Flx16(cvert->v,0) + (Flx16(nvert->v - cvert->v,0) * Flx16(scale))).flx;
            }
            if (level & ESCH_CAM_SHADE_SMOOTH)
            {
                out->shade = long(float(cvert->shade)
                                  + (float(nvert->shade - cvert->shade) * scale));
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
    if ((local_count < 3) && (local_count < *count))
        return 0;

    *count = local_count;

    return modified;
}
#endif


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// esch_rotate_check                                                        ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
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
#if 0
        // for now we need to normalize all 3 vectors
        // to make sure they stay in range.
        float vi = ((const EschPoint*)(&pts[0]))->x;
        float vj = ((const EschPoint*)(&pts[0]))->y;
        float vk = ((const EschPoint*)(&pts[0]))->z;

        // For Abrams, we can assume that the vectors of the polygon are always less than
        // 128 units big.  That ensures that the cross product will not overflow.
        float ai = ((const EschPoint*)(&pts[0]))->x - ((const EschPoint*)(&pts[1]))->x;
        float aj = ((const EschPoint*)(&pts[0]))->y - ((const EschPoint*)(&pts[1]))->y;
        float ak = ((const EschPoint*)(&pts[0]))->z - ((const EschPoint*)(&pts[1]))->z;

        float bi = ((const EschPoint*)(&pts[2]))->x - ((const EschPoint*)(&pts[1]))->x;
        float bj = ((const EschPoint*)(&pts[2]))->y - ((const EschPoint*)(&pts[1]))->y;
        float bk = ((const EschPoint*)(&pts[2]))->z - ((const EschPoint*)(&pts[1]))->z;

        float fi = (aj * bk) - (ak * bj);
        float fj = (ak * bi) - (ai * bk);
        float fk = (ai * bj) - (aj * bi);

        float dir = (vi * fi) + (vj * fj) + (vk * fk);

        if (dir < 0)
            return 0;
        else
            return 1;
#else
        // for now we need to normalize all 3 vectors
        // to make sure they stay in range.
        EschVector  view;
        view.i = pts[0].wx;
        view.j = pts[0].wy;
        view.k = pts[0].wz;

        view.normalize();

        // For Abrams, we can assume that the vectors of the polygon are always less than
        // 128 units big.  That ensures that the cross product will not overflow.
        EschVector  a,b;
        a.i = pts[0].wx - pts[1].wx;
        a.j = pts[0].wy - pts[1].wy;
        a.k = pts[0].wz - pts[1].wz;
        a.normalize();

        b.i = pts[2].wx - pts[1].wx;
        b.j = pts[2].wy - pts[1].wy;
        b.k = pts[2].wz - pts[1].wz;
        b.normalize();

        EschVector f = b CROSS a;

        if ((view DOT f) > 0.025f)
            return 0;
        else
            return 1;
#endif
    }
}

int esch_rotate_check(ulong count, VngoPointF3 *pts)
{
    if (count < 3)
        return 0;

    float v1i,v1j,v2i,v2j;
    float t;

    v1i = (pts[0].wx - pts[1].wx);
    v1j = (pts[0].wy - pts[1].wy);
    v2i = (pts[2].wx - pts[1].wx);
    v2j = (pts[2].wy - pts[1].wy);

    t = (v1i * v2j) - (v1j * v2i);

    if (t <= 0)
        return 1;
    else
        return 0;
}

int esch_rotate_check(ulong count, VngoPointF3 *pts, EschCamera *cam)
{
    if (count < 3)
        return 0;

    if (cam == NULL)
    {
        float v1i,v1j,v2i,v2j;
        float t;

        v1i = (pts[0].wx - pts[1].wx);
        v1j = (pts[0].wy - pts[1].wy);
        v2i = (pts[2].wx - pts[1].wx);
        v2j = (pts[2].wy - pts[1].wy);

        t = (v1i * v2j) - (v1j * v2i);

        if (t > 0)
            return 0;
        else
            return 1;
    }
    else
    {
        // for now we need to normalize all 3 vectors
        // to make sure they stay in range.
        EschVector  view;
        view.i = pts[0].wx;
        view.j = pts[0].wy;
        view.k = pts[0].wz;

        view.normalize();

        // For Abrams, we can assume that the vectors of the polygon are always less than
        // 128 units big.  That ensures that the cross product will not overflow.
        EschVector  a,b;
        a.i = pts[0].wx - pts[1].wx;
        a.j = pts[0].wy - pts[1].wy;
        a.k = pts[0].wz - pts[1].wz;
        a.normalize();

        b.i = pts[2].wx - pts[1].wx;
        b.j = pts[2].wy - pts[1].wy;
        b.k = pts[2].wz - pts[1].wz;
        b.normalize();

        EschVector f = b CROSS a;

        if ((view DOT f) > 0.025f)
            return 0;
        else
            return 1;
    }
}

//°±² End of module - esclip.cpp ²±°
