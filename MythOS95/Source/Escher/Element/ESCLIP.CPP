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
//ששששששששששששששששש Microsoft Windows 95/98/NT Version שששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
//                        http://www.mythos-engine.org/
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
        if (x > tx)
        {
            lclip_flags |= (0x1 << (i<<2));
        }
        else if (x < -tx)
        {
            lclip_flags |= (0x2 << (i<<2));
        }

        y = pts[i].wy;
        if (y > ty)
        {
            lclip_flags |= (0x4 << (i<<2));
        }
        else if (y < -ty)
        {
            lclip_flags |= (0x8 << (i<<2));
        }
    }

//ִִִ If any of the bits are set, then it is off the screen.
    if (lclip_flags)
    {
        dword r=0xf;
        dword t=lclip_flags;
        for(i=0; i < count; i++)
        {
            r &= (t & 0xf);
            t >>= 4;
        }
        if (r)  // it is fully clipped if anything is still in r.
            return 0;
    }
    else if (!ycount && !hcount)
    {
        // this indicates that none of the verts are out of the frustrum.
        return -1;
    }

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

//ִִִ Hack!
lclip_flags = 0xf;

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
            t = work1;
            work1 = work2;
            work2 = t;
        }
    }

    if (work1 != outpts)
    {
        memcpy(outpts,work1,(count * sizeof(VngoPoint)));
    }

    *rcount = ulong(count);
    if (!modified)
        modified=-1;

    return modified;
}



//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// esch_clip_to_plane                                                       ³
//                                                                          ³
// This code is take from Abrash's 3D-clipping example                      ³
// DDJ Source Book March/April '95                                          ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
extern "C" int esch_clip_to_plane(int *count, VngoPointF3 *in, VngoPointF3 *out,
                                  EschPlane *plane, dword level)
{
    int         i,curin,nextin;
    int         modified = -1;
    float       curdot,nextdot,scale,f1,f2;
    VngoPointF3 *cvert,*nvert;
    int         local_count=0;

    assertMyth("esch_clip_to_plane needs valid input",
               count != 0 && in != 0 && out != 0 && plane != 0);

    assertMyth("esch_clip_to_plane() needs valid count",
               *count >= 2);

    if (*count > 2)  // Work on a convex polygon
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
                    out->u = cvert->u + (nvert->u - cvert->u) * scale;
                    out->v = cvert->v + (nvert->v - cvert->v) * scale;
                }
                if (level & ESCH_CAM_SHADE_SMOOTH)
                {
                    //!!! shade values are still integer!
                    out->shade = cvert->shade + long(float(nvert->shade - cvert->shade) * scale);
                }
                else
                {
                    out->shade = cvert->shade;
                }

                if (cvert->clr & VNGO_COLOR_24BIT)
                {
                    out->clr = VNGO_COLOR_24BIT;

                    f1 = float(cvert->clr & 0xff);
                    f2 = float(nvert->clr & 0xff);
                    out->clr |= dword(f1 + long(float(f2 - f1) * scale));

                    f1 = float((cvert->clr & 0xff00) >> 8);
                    f2 = float((nvert->clr & 0xff00) >> 8);
                    out->clr |= dword(f1 + long(float(f2 - f1) * scale)) << 8;

                    f1 = float((cvert->clr & 0xff0000) >> 16);
                    f2 = float((nvert->clr & 0xff0000) >> 16);
                    out->clr |= dword(f1 + long(float(f2 - f1) * scale)) << 16;
                }
                else
                {
                    out->clr = cvert->clr;
                }

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
    else  // Now working on a line not a convex polygon.
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

            if (cvert->clr & VNGO_COLOR_24BIT)
            {
                out->clr = VNGO_COLOR_24BIT;

                f1 = float(cvert->clr & 0xff);
                f2 = float(nvert->clr & 0xff);
                out->clr |= dword(f1 + long(float(f2 - f1) * scale));

                f1 = float((cvert->clr & 0xff00) >> 8);
                f2 = float((nvert->clr & 0xff00) >> 8);
                out->clr |= dword(f1 + long(float(f2 - f1) * scale)) << 8;

                f1 = float((cvert->clr & 0xff0000) >> 16);
                f2 = float((nvert->clr & 0xff0000) >> 16);
                out->clr |= dword(f1 + long(float(f2 - f1) * scale)) << 16;
            }
            else
            {
                out->clr = cvert->clr;
            }

            out++;
            modified = 1;
            local_count++;
        }
    }
    return modified;
}

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// esch_rotate_check                                                        ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
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


        EschVector  a,b;
        a.i = pts[0].wx - pts[1].wx;
        a.j = pts[0].wy - pts[1].wy;
        a.k = pts[0].wz - pts[1].wz;

        b.i = pts[2].wx - pts[1].wx;
        b.j = pts[2].wy - pts[1].wy;
        b.k = pts[2].wz - pts[1].wz;

        // Start AMD grouping.
        view.normalize();
        EschVector f = b CROSS a;
        f.normalize();
        float res = view DOT f;

        // End AMD grouping.
        if (res > 0.025f)
            return 0;
        else
            return 1;
    }
}

//°±² End of module - esclip.cpp ²±°
