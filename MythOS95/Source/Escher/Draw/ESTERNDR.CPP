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
//ùùùùùùùùùùùùùùùùùùù Microsoft Windows 95/NT Version ùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùCopyrightù(c)ù1994-1998ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
// Created by Tim Little
//
// esternex.cpp
//
// The EschTerrain class is a height-field polygonal terrain system which
// uses a 2D array of 8-bit height values to create a realistic "outdoor"
// terrain.  The terrain may have textures and be drawn with multiple
// levels of detail.  This derived version is optimized for use when you
// will always be close to the ground.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"
#include "esfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define TERRAIN_DEBUG_AID
// #define TERRAIN_NO_FRUSTRUM_WALK
//#define TERRAIN_NO_PATCHUP

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern char EschNoName[];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - draw_terrain_trans_rect                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::draw_terrain_trans_rect (VngoRect *rect, int dlevel,dword lflags)
{
    ulong                   needed;
    int                     texture_shift;
    int                     texture_shift2;
    int                     leftx,curx,curz;
    int                     step,cstep;
    VngoPoint               *vpt;
    EschVector              _wvec;
    EschVector              _dvec;

    dword                   *vflags;
    dword                   fflags1 = ESCH_FACE_ALLOWPERSP
                                    | ESCH_FACE_TEXTURED
                                    | ESCH_FACE_SPECULAR
                                    | ESCH_FACE_SMOOTH
                                    | ESCH_FACE_FLAT
                                    | ESCH_FACE_SOLID
                                    | ESCH_FACE_WIRE
                                    | ESCH_FACE_ABLINE
                                    | ESCH_FACE_BCLINE
                                    | ESCH_FACE_CALINE;

    dword                   fflags2 = ESCH_FACE_ALLOWPERSP
                                    | ESCH_FACE_TEXTURED
                                    | ESCH_FACE_SPECULAR
                                    | ESCH_FACE_SMOOTH
                                    | ESCH_FACE_FLAT
                                    | ESCH_FACE_SOLID
                                    | ESCH_FACE_WIRE
                                    | ESCH_FACE_ABLINE
                                    | ESCH_FACE_BCLINE
                                    | ESCH_FACE_CALINE;

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    static EschFace         face[3];

    if (dlevel > int(surfshift))
        texture_shift = dlevel - surfshift;
    else
        texture_shift = 0;

    if ((dlevel+1) > int(surfshift))
        texture_shift2 = dlevel - surfshift + 1;
    else
        texture_shift2 = 0;


    if ((rect->x > (darea.x + darea.dx)) ||
        ((rect->x + rect->dx) < darea.x) ||
        (rect->y > (darea.y + darea.dy)) ||
        ((rect->y + rect->dy) < darea.y))
        return;

    if (rect->x + rect->dx >= width)
    {
        rect->dx = width - 1 - rect->x;
    }
    if (rect->y + rect->dy >= depth)
    {
        rect->dy = depth - 1- rect->y;
    }

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        fflags1 &=~ESCH_FACE_TEXTURED;
        fflags2 &=~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        fflags1 &=~ESCH_FACE_ALLOWPERSP;
        fflags2 &=~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        fflags1 &=~ESCH_FACE_SMOOTH;
        fflags2 &=~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        fflags1 &=~ESCH_FACE_SPECULAR;
        fflags2 &=~ESCH_FACE_SPECULAR;
    }



    leftx = rect->x;
    curz = rect->y;
    curx = leftx;
    cstep = 2 << dlevel;
    step = 1 << dlevel;

    assertMyth("EschLowTerrain::draw_terrain_rect needs an in-clip region",
                rect != NULL);
    assertMyth("EschLowTerrain::draw_terrain_rect needs camera.",
                cam != NULL);

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    int dx = (rect->dx >> dlevel) + 1;

    // Initialize all of the faces.
    int     rowa = 0;
    int     rowb = dx;
    int     rowc = dx + dx;

    // Setup the stepping vectors for the correct detail level.

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    // Update workspace metrics; no other place is reasonable to do this

    needed = (((sizeof(dword)+sizeof(VngoPoint)) * dx) * 3);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

//ÄÄÄ Push drawing context

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * (dx * 3));
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[dx * 3];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();


    int endy = rect->dy >> dlevel;
    int endx = rect->dx >> dlevel;
    int tstep = (1 << dlevel);
    int i,j;

    VngoPoint   work_points[3];
    EschPoint   *rpt = (EschPoint*) (&work_points[2]);
    EschPoint   *cpt = (EschPoint*) (&work_points[0]);
    EschPoint   *cpt2 = (EschPoint*) (&work_points[1]);
    EschPoint   pd,pw;

    cpt->x = origin.x + float(rect->x << scaleshift);
    cpt->y = origin.y;
    cpt->z = origin.z + float(rect->y << scaleshift);

    ::esch_transform(cpt,&cam->eye.iorient,cpt);

    rpt->x = cpt->x;
    rpt->y = cpt->y;
    rpt->z = cpt->z;

    VngoPoint   *vA = &vpt[rowa];
    VngoPoint   *vB = &vpt[rowb];
    VngoPoint   *vC = &vpt[rowc];

    long            t = (width * rect->y) + rect->x;
    byte            *ptr = hfield + t;
    byte            *rptr = ptr;
    long            st = ((width >> surfshift) * (rect->y >> surfshift)) + (rect->x >> surfshift);
    esch_surf_type  *sptr = surfinfo + st;
    esch_surf_type  *rsptr = sptr;
    long            pstep = 1 << dlevel;


    VngoPoint       tpt;
    VngoColor24bit  clr(0,255,255);
    if (dlevel == 1)
    {
        clr.r = 0;
        clr.g = 255;
        clr.b = 0;
    }
    else if (dlevel == 2)
    {
        clr.r = 0;
        clr.g = 0;
        clr.b = 255;
    }
    else if (dlevel == 3)
    {
        clr.r = 255;
        clr.g = 255;
        clr.b = 255;
    }
    else if (dlevel == 4)
    {
        clr.r = 255;
        clr.g = 255;
        clr.b = 0;
    }

    for (i=0; i <= endx; i++)
    {   // Setup the first line A
        float h = htable[*ptr];
        ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vA->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vA->clr = sptr->cind;
        }

        vA->shade = sptr->shd;
        cpt->x = cpt->x + _wvec.i;
        cpt->y = cpt->y + _wvec.j;
        cpt->z = cpt->z + _wvec.k;
        vA++;
        ptr +=pstep;
        sptr += pstep >> surfshift;
    }
    rpt->x = rpt->x + _dvec.i;
    rpt->y = rpt->y + _dvec.j;
    rpt->z = rpt->z + _dvec.k;

    sptr = rsptr;

    vA = &vpt[rowa];

    rptr += (width << dlevel);
    rsptr += (width << dlevel) >> surfshift;
    ptr = rptr;
    sptr = rsptr;

    for (i=1; i <= endy;)
    {
        cpt->x = rpt->x;
        cpt->y = rpt->y;
        cpt->z = rpt->z;
        cpt2->x = rpt->x + _dvec.i;
        cpt2->y = rpt->y + _dvec.j;
        cpt2->z = rpt->z + _dvec.k;

        for (j=0; j <= endx; j++)
        {   // Process lines ABC.
            float h = htable[*ptr];
            ((EschPoint*)vB)->x = cpt->x + (h * hvec.i);
            ((EschPoint*)vB)->y = cpt->y + (h * hvec.j);
            ((EschPoint*)vB)->z = cpt->z + (h * hvec.k);

            if (sptr->flags & ESCH_SURF_CINDISTXT)
            {
                vB->clr = txtcolor[sptr->cind-1];
            }
            else
            {
                vB->clr = sptr->cind;
            }

            vB->shade = sptr->shd;

            cpt->x = cpt->x + _wvec.i;
            cpt->y = cpt->y + _wvec.j;
            cpt->z = cpt->z + _wvec.k;
            vB++;

            if (i + 1 <= endy)
            {
                h = htable[ptr[width << dlevel]];
                ((EschPoint*)vC)->x = cpt2->x + (h * hvec.i);
                ((EschPoint*)vC)->y = cpt2->y + (h * hvec.j);
                ((EschPoint*)vC)->z = cpt2->z + (h * hvec.k);

                if (sptr->flags & ESCH_SURF_CINDISTXT)
                {
                    vC->clr = txtcolor[sptr[width << (dlevel - surfshift)].cind-1];
                }
                else
                {
                    vC->clr = sptr[width << (dlevel - surfshift)].cind;
                }
                vC->shade = sptr[width << (dlevel - surfshift)].shd;

                cpt2->x = cpt2->x + _wvec.i;
                cpt2->y = cpt2->y + _wvec.j;
                cpt2->z = cpt2->z + _wvec.k;
                vC++;
            }
            ptr+=pstep;
            sptr += pstep >> surfshift;
        }
        vA = &vpt[rowa];
        vB = &vpt[rowb];
        vC = &vpt[rowc];

        //
        // Now spew out the faces....tl
        //
#ifdef TERRAIN_DEBUG_AID
        if (flags & ESCH_TRN_DOTS)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Dots
            display_pixel_row(vA,endx, 0);
            display_pixel_row(vB,endx, 0);
            if (i+1 <= endy)
                display_pixel_row(vC,endx, 0);
        }
        else
#endif
        {
            float u_left,u_right,v_top,v_bottom;
            esch_surf_type      *lsptr;
            lsptr = &rsptr[-((width >> surfshift) << dlevel)];
            dword tlflags;
            curx = leftx;

            for (int k=0; k < endx;k++)
            {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                if ((curx >= (left_edge[curz] - cstep)
                    || curx >= (left_edge[curz+step] - cstep))
                    && (curx <= (right_edge[curz] + cstep)
                    || curx <= (right_edge[curz+step] + cstep)))
#endif
                {
                    tlflags = lsptr->flags;
                    if (!(tlflags & ESCH_SURF_HIDDEN))
                    {
                        // draw the tri strip formed by rows a & b;
                        face[0].flags = fflags1;
                        face[1].flags = fflags2;

                        face[0].a = k;
                        face[0].b = k + rowb;
                        face[0].c = k + rowb + 1;

                        face[1].a = k;
                        face[1].b = k + rowb + 1;
                        face[1].c = k + 1;

                        if ((tlflags & ESCH_SURF_CINDISTXT) &&
                            (!texture_shift || !(tlflags & ESCH_SURF_NOTILE)))
                        {
                            face[0].txt = lsptr->cind;
                            face[1].txt = face[0].txt;

                            if (face[0].flags & ESCH_FACE_TEXTURED)
                            {
                                compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                                    tlflags,rect->x + (k << dlevel),
                                                    rect->y + (i << dlevel),
                                                    texture_shift);
                            }
                            else
                            {
                                u_left=u_right=v_bottom=v_top=0;
                            }
                            face[0].u[0] = u_left;
                            face[0].v[0] = v_bottom;
                            face[0].u[1] = u_left;
                            face[0].v[1] = v_top;
                            face[0].u[2] = u_right;
                            face[0].v[2] = v_top;

    //                        face[1].flags = face[0].flags;
                            face[1].u[0] = u_left;
                            face[1].v[0] = v_bottom;
                            face[1].u[1] = u_right;
                            face[1].v[1] = v_top;
                            face[1].u[2] = u_right;
                            face[1].v[2] = v_bottom;
                        }
                        else
                        {
                            face[0].flags &= ~ESCH_FACE_TEXTURED;
                            face[1].flags &= ~ESCH_FACE_TEXTURED;
                        }
                        esch_clipdraw_face(0,ctrlfl);
                        esch_clipdraw_face(1,ctrlfl);
                    }
                    else
                    {
                        int debug_trap = TRUE;
                    }
#ifdef TERRAIN_DEBUG_AID
                    if (flags & ESCH_TRN_DEBUG)
                    {
                        tpt.x = curx;
                        tpt.y = curz;
                        tpt.z = 0x10000;
                        cam->vport->clip_pixel(&tpt,&clr);
                    }
#endif
                }
                if( i+1 <= endy)
                {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                    if ((curx >= (left_edge[curz+step] - cstep)
                        || curx >= (left_edge[curz+step+step] - cstep))
                        && (curx <= (right_edge[curz+step] + cstep)
                        || curx <= (right_edge[curz+step+step] + cstep)))
#endif
                    {
                        int t = (width >> surfshift) << dlevel;
                        tlflags = lsptr[t].flags;
                        if (!(tlflags & ESCH_SURF_HIDDEN))
                        {

                            // draw the tri strip formed by rows b & c;
                            face[0].flags = fflags1;
                            face[0].a = k + rowb;
                            face[0].b = k + rowc;
                            face[0].c = k + rowc + 1;

                            face[1].flags = fflags2;
                            face[1].a = k + rowb;
                            face[1].b = k + rowc + 1;
                            face[1].c = k + rowb + 1;


                            if ((tlflags & ESCH_SURF_CINDISTXT) &&
                                (!texture_shift || !(tlflags & ESCH_SURF_NOTILE)))
                            {
                                face[0].txt = lsptr[t].cind;
                                face[1].txt = face[0].txt;

                                if (face[0].flags & ESCH_FACE_TEXTURED)
                                {
                                    compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                                        tlflags,rect->x  + (k << dlevel),
                                                        rect->y + ((i+1) << dlevel),
                                                        texture_shift);
                                }
                                else
                                {
                                    u_left=u_right=v_top=v_bottom=0;
                                }

                                face[0].u[0] = u_left;
                                face[0].v[0] = v_bottom;
                                face[0].u[1] = u_left;
                                face[0].v[1] = v_top;
                                face[0].u[2] = u_right;
                                face[0].v[2] = v_top;

    //                            face[1].flags = face[0].flags;
                                face[1].u[0] = u_left;
                                face[1].v[0] = v_bottom;
                                face[1].u[1] = u_right;
                                face[1].v[1] = v_top;
                                face[1].u[2] = u_right;
                                face[1].v[2] = v_bottom;
                            }
                            else
                            {
                                face[0].flags &= ~ESCH_FACE_TEXTURED;
                                face[1].flags &= ~ESCH_FACE_TEXTURED;
                            }
                            esch_clipdraw_face(0,ctrlfl);
                            esch_clipdraw_face(1,ctrlfl);
                        }
                        else
                        {
                            int debug_trap = TRUE;
                        }
#ifdef TERRAIN_DEBUG_AID
                        if (flags & ESCH_TRN_DEBUG)
                        {
                            tpt.x = curx;
                            tpt.y = curz + step;
                            tpt.z = 0x10000;
                            cam->vport->clip_pixel(&tpt,&clr);
                        }
#endif
                    }
                }
                curx += step;
                lsptr += pstep >> surfshift;
            }
            curz += step << 1;
            for (int l = 0;l <= endx;l++)
            {
                vflags[l] = vflags[l+rowb] = 0;
            }
        }


        //
        // Update all of the stuff to do the next two rows of points.
        //
        i += 2;

        rptr = rptr + (width << (dlevel + 1));
        ptr = rptr;

        rsptr = rsptr + ((width << (dlevel + 1)) >> surfshift);
        sptr = rsptr;

        rpt->x = rpt->x + _dvec.i + _dvec.i;
        rpt->y = rpt->y + _dvec.j + _dvec.j;
        rpt->z = rpt->z + _dvec.k + _dvec.k;
        cpt->x = rpt->x;
        cpt->y = rpt->y;
        cpt->z = rpt->z;
        cpt2->x = rpt->x + _dvec.i;
        cpt2->y = rpt->y + _dvec.j;
        cpt2->z = rpt->z + _dvec.k;

        if (i  <= endy)
        {
            for (j=0; j <= endx; j++)
            {   // Process lines CBA.
                float h = htable[*ptr];
                ((EschPoint*)vB)->x = cpt->x + (h * hvec.i);
                ((EschPoint*)vB)->y = cpt->y + (h * hvec.j);
                ((EschPoint*)vB)->z = cpt->z + (h * hvec.k);

                if (sptr->flags & ESCH_SURF_CINDISTXT)
                {
                    vB->clr = txtcolor[sptr->cind-1];
                }
                else
                {
                    vB->clr = sptr->cind;
                }
                vB->shade = sptr->shd;
                cpt->x = cpt->x + _wvec.i;
                cpt->y = cpt->y + _wvec.j;
                cpt->z = cpt->z + _wvec.k;
                vB++;
                if (i+1 <= endy)
                {
                    h = htable[ptr[width << dlevel]];
                    ((EschPoint*)vA)->x = cpt2->x + (h * hvec.i);
                    ((EschPoint*)vA)->y = cpt2->y + (h * hvec.j);
                    ((EschPoint*)vA)->z = cpt2->z + (h * hvec.k);

                    if (sptr->flags & ESCH_SURF_CINDISTXT)
                    {
                        vA->clr = txtcolor[sptr[width << (dlevel - surfshift)].cind-1];
                    }
                    else
                    {
                        vA->clr = sptr[width << (dlevel - surfshift)].cind;
                    }

                    vA->shade = sptr[width << (dlevel - surfshift)].shd;
                    cpt2->x = cpt2->x + _wvec.i;
                    cpt2->y = cpt2->y + _wvec.j;
                    cpt2->z = cpt2->z + _wvec.k;
                    vA++;
                }
                ptr += pstep;
                sptr += pstep >> surfshift;

            }
            vA = &vpt[rowa];
            vB = &vpt[rowb];
            vC = &vpt[rowc];
        }
#ifdef TERRAIN_DEBUG_AID
        if (flags & ESCH_TRN_DOTS)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Dots
            if (i <= endy)
                display_pixel_row(vB,endx, 0);
        }
        else
#endif
        {
            float u_left,u_right,v_top,v_bottom;
            esch_surf_type      *lsptr;
            lsptr = &rsptr[-((width >> surfshift) << dlevel)];
            dword tlflags;


            curx = leftx;
            for (int k=0; k < endx;k++)
            {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                if ((curx >= (left_edge[curz] - cstep)
                    || curx >= (left_edge[curz+step] - cstep))
                    && (curx <= (right_edge[curz] + cstep)
                    || curx <= (right_edge[curz+step] + cstep)))
#endif
                {
                    if (i <= endy)
                    {
                        tlflags = lsptr->flags;

                        if (!(tlflags & ESCH_SURF_HIDDEN))
                        {

                            // draw the tri strip formed by rows c & b;
                            face[0].flags = fflags1;
                            face[1].flags = fflags2;

                            face[0].a = k + rowc;
                            face[0].b = k + rowb;
                            face[0].c = k + rowb + 1;

                            face[1].a = k + rowc;
                            face[1].b = k + rowb + 1;
                            face[1].c = k + rowc + 1;

                            if ((tlflags & ESCH_SURF_CINDISTXT) &&
                                (!texture_shift || !(tlflags & ESCH_SURF_NOTILE)))
                            {
                                face[0].txt = lsptr->cind;
                                face[1].txt = face[0].txt;

                                if (face[0].flags & ESCH_FACE_TEXTURED)
                                {
                                    compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                                        tlflags,rect->x  + (k << dlevel),
                                                        rect->y + (i << dlevel),
                                                        texture_shift);
                                }
                                else
                                {
                                    u_left=u_right=v_top=v_bottom=0;
                                }

                                face[0].u[0] = u_left;
                                face[0].v[0] = v_bottom;
                                face[0].u[1] = u_left;
                                face[0].v[1] = v_top;
                                face[0].u[2] = u_right;
                                face[0].v[2] = v_top;

    //                            face[1].flags = face[0].flags;
                                face[1].u[0] = u_left;
                                face[1].v[0] = v_bottom;
                                face[1].u[1] = u_right;
                                face[1].v[1] = v_top;
                                face[1].u[2] = u_right;
                                face[1].v[2] = v_bottom;
                            }
                            else
                            {
                                face[0].flags &= ~ESCH_FACE_TEXTURED;
                                face[1].flags &= ~ESCH_FACE_TEXTURED;
                            }
                            esch_clipdraw_face(0,ctrlfl);
                            esch_clipdraw_face(1,ctrlfl);
                        }
                        else
                        {
                            int debug_trap = TRUE;
                        }
#ifdef TERRAIN_DEBUG_AID
                        if (flags & ESCH_TRN_DEBUG)
                        {
                            tpt.x = curx;
                            tpt.y = curz;
                            tpt.z = 0x10000;

                            cam->vport->clip_pixel(&tpt,&clr);
                        }
#endif
                    }
                }
                if( i+1 <= endy)
                {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                    if ((curx >= (left_edge[curz+step] - cstep)
                        || curx >= (left_edge[curz+step+step] - cstep))
                        && (curx <= (right_edge[curz+step] + cstep)
                        || curx <= (right_edge[curz+step+step] + cstep)))
#endif
                    {
                        int t = (width >> surfshift) << dlevel;
                        tlflags = lsptr[t].flags;

                        if (!(tlflags & ESCH_SURF_HIDDEN))
                        {

                            // draw the tri strip formed by rows b & a;
                            face[0].flags = fflags1;
                            face[1].flags = fflags2;

                            face[0].a = k + rowb;
                            face[0].b = k + rowa;
                            face[0].c = k + rowa + 1;

                            face[1].a = k + rowb;
                            face[1].b = k + rowa + 1;
                            face[1].c = k + rowb + 1;

                            if ((tlflags & ESCH_SURF_CINDISTXT) &&
                                (!texture_shift || !(tlflags & ESCH_SURF_NOTILE)))
                            {
                                face[0].txt = lsptr[t].cind;
                                face[1].txt = face[0].txt;

                                if (face[0].flags & ESCH_FACE_TEXTURED)
                                {
                                    compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                                        tlflags,rect->x + (k << dlevel),
                                                        rect->y + ((i+1) << dlevel),
                                                        texture_shift);
                                }
                                else
                                {
                                    u_left=u_right=v_top=v_bottom=0;
                                }

                                face[0].u[0] = u_left;
                                face[0].v[0] = v_bottom;
                                face[0].u[1] = u_left;
                                face[0].v[1] = v_top;
                                face[0].u[2] = u_right;
                                face[0].v[2] = v_top;

    //                            face[1].flags = face[0].flags;
                                face[1].u[0] = u_left;
                                face[1].v[0] = v_bottom;
                                face[1].u[1] = u_right;
                                face[1].v[1] = v_top;
                                face[1].u[2] = u_right;
                                face[1].v[2] = v_bottom;
                            }
                            else
                            {
                                face[0].flags &= ~ESCH_FACE_TEXTURED;
                                face[1].flags &= ~ESCH_FACE_TEXTURED;
                            }

                            esch_clipdraw_face(0,ctrlfl);
                            esch_clipdraw_face(1,ctrlfl);
                        }
                        else
                        {
                            int debug_trap = TRUE;
                        }

#ifdef TERRAIN_DEBUG_AID
                        if (flags & ESCH_TRN_DEBUG)
                        {
                            tpt.x = curx;
                            tpt.y = curz + step;
                            tpt.z = 0x10000;
                            cam->vport->clip_pixel(&tpt,&clr);
                        }
#endif
                    }
                }
                curx += step;
                lsptr += pstep >> surfshift;
            }
            curz += step << 1;
            for (int l = 0;l <= endx;l++)
            {
                vflags[rowc+l] = vflags[l+rowb] = 0;
            }
        }

        rptr += (width << (dlevel + 1));
        ptr = rptr;

        rsptr = rsptr + ((width << (dlevel + 1)) >> surfshift);
        sptr = rsptr;

        rpt->x = rpt->x + _dvec.i + _dvec.i;
        rpt->y = rpt->y + _dvec.j + _dvec.j;
        rpt->z = rpt->z + _dvec.k + _dvec.k;
        i += 2;

    }
#ifdef TERRAIN_DEBUG_AID
    if(flags & ESCH_TRN_DEBUG)
    {

        VngoColor24bit color(255,0,0);
        // go ahead and draw the rect.
        if (dlevel == 1)
        {
            color.r = 0;
            color.g = 255;
            color.b = 0;
        }
        else if (dlevel == 2)
        {
            color.r = 0;
            color.g = 0;
            color.b = 255;
        }
        else if (dlevel == 3)
        {
            color.r = 255;
            color.g = 255;
            color.b = 255;
        }
        else if (dlevel == 4)
        {
            color.r = 255;
            color.g = 255;
            color.b = 0;
        }

        VngoPoint   pts[4];
        pts[0].x = rect->x;
        pts[1].x = rect->x + rect->dx;
        pts[2].x = rect->x + rect->dx;
        pts[3].x = rect->x;

        pts[0].y = rect->y;
        pts[1].y = rect->y;
        pts[2].y = rect->y + rect->dy;
        pts[3].y = rect->y + rect->dy;

        pts[0].z = 0x10000 + (dlevel << 16);
        pts[1].z = 0x10000 + (dlevel << 16);
        pts[2].z = 0x10000 + (dlevel << 16);
        pts[3].z = 0x10000 + (dlevel << 16);

        cam->vport->clip_line(&pts[0],&pts[1],&color);
        cam->vport->clip_line(&pts[1],&pts[2],&color);
        cam->vport->clip_line(&pts[2],&pts[3],&color);
        cam->vport->clip_line(&pts[3],&pts[0],&color);
    }
#endif

//ÄÄÄ Pop drawing context
    ec.pop();
}

void EschTerrainEx::draw_terrain_trans_top (VngoRect *rect,
                                            EschPoint *orig,
                                            byte *dptr,
                                            esch_surf_type *_sptr,
                                            int dlevel,
                                            ulong _count,
                                            dword lflags)
{
    int     count = int(_count >> 1);
    float   u_left,u_right,u_mid;
    float   v_top,v_bottom,v_mid;
    dword   flag_state = ESCH_FACE_ALLOWPERSP
                         | ESCH_FACE_TEXTURED
                         | ESCH_FACE_SPECULAR
                         | ESCH_FACE_SMOOTH
                         | ESCH_FACE_FLAT
                         | ESCH_FACE_SOLID
                         | ESCH_FACE_WIRE;
    dword   flags1 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags2 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE;
    dword   flags3 = ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags4 = ESCH_FACE_BCLINE;

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        flag_state &= ~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        flag_state &= ~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        flag_state &= ~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        flag_state &= ~ESCH_FACE_SPECULAR;
    }


    EschPoint       work_point;
    EschPoint       *cpt=&work_point;
    dword           *vflags;
    VngoPoint       *vA,*vB,*vC;
    esch_surf_type  *sptr = _sptr;
    esch_surf_type  *rsptr = sptr;
    byte            *rptr = dptr;
    long            pstep = 1 << dlevel;

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    ulong   needed;
    int     texture_shift;
    VngoPoint       *vpt;
    EschVector      _wvec;
    EschVector      _dvec;

    static EschFace face[7];

    if ((dlevel + 1) > int(surfshift))
        texture_shift = (dlevel + 1)- surfshift;
    else
        texture_shift = 0;

    // Drawing an x-stepping strip of terrain blocks.
    // Blocks are comprised of 8 points and 7 polys.

    // 0 1 2 3 4
    // --------- A
    // |\ /|\ /|
    // |---+---| B
    // |/|/|/|/|
    // --------- C

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    byte *ptr = rptr;

    cpt->x = orig->x;
    cpt->y = orig->y;
    cpt->z = orig->z;

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    ulong vert_count = (_count<<1) + 1;

    needed = (((sizeof(dword)+sizeof(VngoPoint)) * vert_count) * 3);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * (vert_count * 3));
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[vert_count * 3];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();

    int rowa = 0;
    int rowb = vert_count;
    int rowc = vert_count + vert_count;
    byte *visflags=(byte*)ivory_arena_alloc(EschSysInstance->wspace,(vert_count >> 1) * sizeof(byte));
    memset(visflags,3,vert_count>>1);

    vA = &vpt[rowa];
    vB = &vpt[rowb];
    vC = &vpt[rowc];

    for (ulong i=0; i< vert_count; i++)
    {
        float h = htable[*ptr];
        // build A
        ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

        if(!(sptr->flags & ESCH_SURF_HIDDEN))
            visflags[i>>1] &= ~1;

        if(sptr->flags & ESCH_SURF_NOTILE)
            visflags[i>>1] &= ~2;


        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vA->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vA->clr = sptr->cind;
        }

        vA->shade = sptr->shd;
        cpt->x += _wvec.i;
        cpt->y += _wvec.j;
        cpt->z += _wvec.k;

        vA++;
        ptr += pstep;
        sptr += pstep >> surfshift;
    }

    ptr = rptr + (width << dlevel);
    sptr = rsptr + ((width << dlevel) >> surfshift);

    rptr = ptr;
    rsptr = sptr;

    cpt->x = orig->x + _dvec.i;
    cpt->y = orig->y + _dvec.j;
    cpt->z = orig->z + _dvec.k;

    for (i=0; i< vert_count; i++)
    {
        float h = htable[*ptr];
        ((EschPoint *)vB)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vB)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vB)->z = cpt->z + (h * hvec.k);

        if(!(sptr->flags & ESCH_SURF_HIDDEN))
            visflags[i>>1] &= ~1;

        if(sptr->flags & ESCH_SURF_NOTILE)
            visflags[i>>1] &= ~2;

        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vB->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vB->clr = sptr->cind;
        }

        vB->shade = sptr->shd;
        cpt->x += _wvec.i;
        cpt->y += _wvec.j;
        cpt->z += _wvec.k;

        vB++;
        ptr += pstep;
        sptr += (pstep >> surfshift);
    }

    cpt->x = orig->x + _dvec.i + _dvec.i;
    cpt->y = orig->y + _dvec.j + _dvec.j;
    cpt->z = orig->z + _dvec.k + _dvec.k;

    ptr = rptr + (width << dlevel);
    sptr = rsptr + ((width << dlevel) >> surfshift);

    for (i = 0; i<vert_count; i++)
    {
        float h = htable[*ptr];
        // build C
        ((EschPoint *)vC)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vC)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vC)->z = cpt->z + (h * hvec.k);
        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vC->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vC->clr = sptr->cind;
        }

        vC->shade = sptr->shd;
        cpt->x += _wvec.i;
        cpt->y += _wvec.j;
        cpt->z += _wvec.k;

        vC++;
        ptr += pstep;
        sptr += (pstep >> surfshift);
    }

    vA = &vpt[rowa];
    vB = &vpt[rowb];
    vC = &vpt[rowc];

    for (i=0; i<vert_count; i++)
    {
        point_average ((EschPoint *)vB, ((EschPoint *)vA), ((EschPoint *)vC));
        vA++;
        vB++;
        vC++;
    }

    rsptr = _sptr;
    esch_surf_type  *lsptr;
    lsptr = rsptr;
//    lsptr = &rsptr[-((width >> surfshift) << dlevel)];

    dword tlflags;

    for (ushort j=0; j < _count; j+=2)
    {
        // build and draw polys
        if (   (   (( rect->x + ((j+2) << dlevel)) >= left_edge[rect->y])
                || (( rect->x + ((j+2) << dlevel)) >= left_edge[rect->y + (2 << dlevel)])
               )
            ||
               (   (( rect->x + (j << dlevel)) <= right_edge[rect->y])
                || (( rect->x + (j << dlevel)) <= right_edge[rect->y + (2 << dlevel)])
               )
           )
        {
            tlflags = lsptr->flags;
            if (!(visflags[j>>1] & 1))
            {
                // draw the tri-conglomerate formed by a, b, & c
                face[0].flags = flag_state | flags1;
                face[1].flags = flag_state | flags1;
                face[2].flags = flag_state | flags1;
                face[3].flags = flag_state | flags1;
                face[4].flags = flag_state | flags1;
                face[5].flags = flag_state | flags1;
                face[6].flags = flag_state | flags1;

                face[0].a = j + rowb;
                face[0].b = j + rowc;
                face[0].c = j + rowc + 1;

                face[1].a = j + rowb;
                face[1].b = j + rowc + 1;
                face[1].c = j + rowb + 1;

                face[2].a = j + rowb + 1;
                face[2].b = j + rowc + 1;
                face[2].c = j + rowc + 2;

                face[3].a = j + rowb + 1;
                face[3].b = j + rowc + 2;
                face[3].c = j + rowb + 2;

                face[4].a = j + rowa;
                face[4].b = j + rowb;
                face[4].c = j + rowb + 1;

                face[5].a = j + rowa;
                face[5].b = j + rowb + 1;
                face[5].c = j + rowa + 2;

                face[6].a = j + rowb + 1;
                face[6].b = j + rowb + 2;
                face[6].c = j + rowa + 2;

                if ((tlflags & ESCH_SURF_CINDISTXT) &&
                    ((visflags[j>>1] & 0x2) || !texture_shift))
                {
                    // heheheh
                    face[6].txt=
                    face[5].txt=
                    face[4].txt=
                    face[3].txt=
                    face[2].txt=
                    face[1].txt=
                    face[0].txt=lsptr->cind;

                    if (face[0].flags & ESCH_FACE_TEXTURED)
                    {
                        compute_texture_uv(u_left, u_right, v_top, v_bottom,
                                           tlflags, rect->x + (j << dlevel),
                                           rect->y,
                                           texture_shift);
                        u_mid = (u_left+u_right)/2.0f;
                        v_mid = (v_top+v_bottom)/2.0f;
                    }
                    else
                    {
                        u_left=u_right=v_bottom=v_top=u_mid=v_mid=0.0f;
                    }

                    face[0].u[0] = u_left;
                    face[0].v[0] = v_mid;
                    face[0].u[1] = u_left;
                    face[0].v[1] = v_top;
                    face[0].u[2] = u_mid;
                    face[0].v[2] = v_top;

                    face[1].u[0] = u_left;
                    face[1].v[0] = v_mid;
                    face[1].u[1] = u_mid;
                    face[1].v[1] = v_top;
                    face[1].u[2] = u_mid;
                    face[1].v[2] = v_mid;

                    face[2].u[0] = u_mid;
                    face[2].v[0] = v_mid;
                    face[2].u[1] = u_mid;
                    face[2].v[1] = v_top;
                    face[2].u[2] = u_right;
                    face[2].v[2] = v_top;

                    face[3].u[0] = u_mid;
                    face[3].v[0] = v_mid;
                    face[3].u[1] = u_right;
                    face[3].v[1] = v_top;
                    face[3].u[2] = u_right;
                    face[3].v[2] = v_mid;

                    face[4].u[0] = u_left;
                    face[4].v[0] = v_bottom;
                    face[4].u[1] = u_left;
                    face[4].v[1] = v_mid;
                    face[4].u[2] = u_mid;
                    face[4].v[2] = v_mid;

                    face[5].u[0] = u_left;
                    face[5].v[0] = v_bottom;
                    face[5].u[1] = u_mid;
                    face[5].v[1] = v_mid;
                    face[5].u[2] = u_right;
                    face[5].v[2] = v_bottom;

                    face[6].u[0] = u_mid;
                    face[6].v[0] = v_mid;
                    face[6].u[1] = u_right;
                    face[6].v[1] = v_mid;
                    face[6].u[2] = u_right;
                    face[6].v[2] = v_bottom;
                }
                else
                {
                    face[0].flags &= ~ESCH_FACE_TEXTURED;
                    face[1].flags &= ~ESCH_FACE_TEXTURED;
                    face[2].flags &= ~ESCH_FACE_TEXTURED;
                    face[3].flags &= ~ESCH_FACE_TEXTURED;
                    face[4].flags &= ~ESCH_FACE_TEXTURED;
                    face[5].flags &= ~ESCH_FACE_TEXTURED;
                    face[6].flags &= ~ESCH_FACE_TEXTURED;
                }
                esch_clipdraw_face (0, ctrlfl);
                esch_clipdraw_face (1, ctrlfl);
                esch_clipdraw_face (2, ctrlfl);
                esch_clipdraw_face (3, ctrlfl);
                esch_clipdraw_face (4, ctrlfl);
                esch_clipdraw_face (5, ctrlfl);
                esch_clipdraw_face (6, ctrlfl);
            }
        }
        lsptr = &rsptr[(((j+2) << dlevel)>>surfshift)];
    }
    ec.pop();
}

void EschTerrainEx::draw_terrain_trans_bottom (VngoRect *rect,
                                               EschPoint *orig,
                                               byte *dptr,
                                               esch_surf_type *_sptr,
                                               int dlevel,
                                               ulong _count,
                                               dword lflags)
{
    int     count = int(_count >> 1);
    float   u_left,u_right,u_mid;
    float   v_top,v_bottom,v_mid;
    dword   flag_state = ESCH_FACE_ALLOWPERSP
                         | ESCH_FACE_TEXTURED
                         | ESCH_FACE_SPECULAR
                         | ESCH_FACE_SMOOTH
                         | ESCH_FACE_FLAT
                         | ESCH_FACE_SOLID
                         | ESCH_FACE_WIRE;
    dword   flags1 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags2 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE;
    dword   flags3 = ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags4 = ESCH_FACE_BCLINE;

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        flag_state &= ~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        flag_state &= ~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        flag_state &= ~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        flag_state &= ~ESCH_FACE_SPECULAR;
    }


    EschPoint       work_point;
    EschPoint       *cpt=&work_point;
    dword           *vflags;
    VngoPoint       *vA,*vB,*vC;
    esch_surf_type  *sptr = _sptr;
    esch_surf_type  *rsptr = sptr;
    byte            *rptr = dptr;
    long            pstep = 1 << dlevel;

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    ulong   needed;
    int     texture_shift;
    VngoPoint       *vpt;
    EschVector      _wvec;
    EschVector      _dvec;

    static EschFace face[7];

    if ((dlevel + 1) > int(surfshift))
        texture_shift = (dlevel + 1) - surfshift;
    else
        texture_shift = 0;

    // Drawing an x-stepping strip of terrain blocks.
    // Blocks are comprised of 8 points and 7 polys.

    // 0 1 2 3 4
    // --------- A
    // |/|/|/|/|
    // |---+---| B
    // |/ \|/ \|
    // --------- C

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    byte *ptr = rptr;

    cpt->x = orig->x;
    cpt->y = orig->y;
    cpt->z = orig->z;

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    ulong vert_count = (_count<<1) + 1;

    needed = (((sizeof(dword)+sizeof(VngoPoint)) * vert_count) * 3);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * (vert_count * 3));
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[vert_count * 3];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();

    int rowa = 0;
    int rowb = vert_count;
    int rowc = vert_count + vert_count;
    byte *visflags=(byte*)ivory_arena_alloc(EschSysInstance->wspace,(vert_count >> 1) * sizeof(byte));
    memset(visflags,3,vert_count>>1);

    vA = &vpt[rowa];
    vB = &vpt[rowb];
    vC = &vpt[rowc];

    for (ulong i=0; i< vert_count; i++)
    {
        float h = htable[*ptr];
        // build A
        ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

        if(!(sptr->flags & ESCH_SURF_HIDDEN))
            visflags[i>>1] &= ~1;

        if(sptr->flags & ESCH_SURF_NOTILE)
            visflags[i>>1] &= ~2;

        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vA->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vA->clr = sptr->cind;
        }

        vA->shade = sptr->shd;
        cpt->x += _wvec.i;
        cpt->y += _wvec.j;
        cpt->z += _wvec.k;

        vA++;
        ptr += pstep;
        sptr += pstep >> surfshift;
    }

    ptr = rptr + (width << dlevel);
    sptr = rsptr + ((width << dlevel) >> surfshift);

    rptr = ptr;
    rsptr = sptr;

    cpt->x = orig->x + _dvec.i;
    cpt->y = orig->y + _dvec.j;
    cpt->z = orig->z + _dvec.k;

    for (i=0; i< vert_count; i++)
    {
        float h = htable[*ptr];
        ((EschPoint *)vB)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vB)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vB)->z = cpt->z + (h * hvec.k);

        if(!(sptr->flags & ESCH_SURF_HIDDEN))
            visflags[i>>1] &= ~1;

        if(sptr->flags & ESCH_SURF_NOTILE)
            visflags[i>>1] &= ~2;

        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vB->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vB->clr = sptr->cind;
        }

        vB->shade = sptr->shd;
        cpt->x += _wvec.i;
        cpt->y += _wvec.j;
        cpt->z += _wvec.k;

        vB++;
        ptr += pstep;
        sptr += (pstep >> surfshift);
    }

    cpt->x = orig->x + _dvec.i + _dvec.i;
    cpt->y = orig->y + _dvec.j + _dvec.j;
    cpt->z = orig->z + _dvec.k + _dvec.k;

    ptr = rptr + (width << dlevel);
    sptr = rsptr + ((width << dlevel) >> surfshift);

    for (i = 0; i<vert_count; i++)
    {
        float h = htable[*ptr];
        // build C
        ((EschPoint *)vC)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vC)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vC)->z = cpt->z + (h * hvec.k);
        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vC->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vC->clr = sptr->cind;
        }

        vC->shade = sptr->shd;
        cpt->x += _wvec.i;
        cpt->y += _wvec.j;
        cpt->z += _wvec.k;

        vC++;
        ptr += pstep;
        sptr += (pstep >> surfshift);
    }

    vA = &vpt[rowa];
    vB = &vpt[rowb];
    vC = &vpt[rowc];

    for (i=0; i<vert_count; i++)
    {
        point_average ((EschPoint *)vB, ((EschPoint *)vA), ((EschPoint *)vC));
        vA++;
        vB++;
        vC++;
    }

    rsptr = _sptr;
    esch_surf_type  *lsptr;
    lsptr = rsptr;
//    lsptr = &rsptr[-((width >> surfshift) << dlevel)];
    dword tlflags;

    for (ushort j=0; j<_count; j+=2)
    {
        // build and draw polys
#if 1
        if (   (   (( rect->x + ((j+2) << dlevel)) >= left_edge[rect->y])
                || (( rect->x + ((j+2) << dlevel)) >= left_edge[rect->y + (2 << dlevel)])
               )
            ||
               (   (( rect->x + (j << dlevel)) <= right_edge[rect->y])
                || (( rect->x + (j << dlevel)) <= right_edge[rect->y + (2 << dlevel)])
               )
           )
#endif
        {
            tlflags = lsptr->flags;
            if (!(visflags[j>>1] & 1))
            {
                // draw the tri-conglomerate formed by a, b, & c
                face[0].flags = flag_state | flags1;
                face[1].flags = flag_state | flags1;
                face[2].flags = flag_state | flags1;
                face[3].flags = flag_state | flags1;
                face[4].flags = flag_state | flags1;
                face[5].flags = flag_state | flags1;
                face[6].flags = flag_state | flags1;

                face[0].a = j + rowb;
                face[0].b = j + rowc;
                face[0].c = j + rowb + 1;

                face[1].a = j + rowb + 1;
                face[1].b = j + rowc;
                face[1].c = j + rowc + 2;

                face[2].a = j + rowb + 1;
                face[2].b = j + rowc + 2;
                face[2].c = j + rowb + 2;

                face[3].a = j + rowa;
                face[3].b = j + rowb;
                face[3].c = j + rowb + 1;

                face[4].a = j + rowa;
                face[4].b = j + rowb + 1;
                face[4].c = j + rowa + 1;

                face[5].a = j + rowa + 1;
                face[5].b = j + rowb + 1;
                face[5].c = j + rowb + 2;

                face[6].a = j + rowa + 1;
                face[6].b = j + rowb + 2;
                face[6].c = j + rowa + 2;

                if ((tlflags & ESCH_SURF_CINDISTXT) &&
                    ((visflags[j>>1] & 0x2) || !texture_shift))
                {
                    // heheheh
                    face[6].txt=
                    face[5].txt=
                    face[4].txt=
                    face[3].txt=
                    face[2].txt=
                    face[1].txt=
                    face[0].txt=lsptr->cind;

                    if (face[0].flags & ESCH_FACE_TEXTURED)
                    {
                        compute_texture_uv(u_left, u_right, v_top, v_bottom,
                                           tlflags, rect->x + (i << dlevel),
                                           rect->y + (i << dlevel),
                                           texture_shift);
                        u_mid = (u_left+u_right)/2.0f;
                        v_mid = (v_top+v_bottom)/2.0f;
                    }
                    else
                    {
                        u_left=u_right=v_bottom=v_top=u_mid=v_mid=0.f;
                    }

                    face[0].u[0] = u_left;
                    face[0].v[0] = v_mid;
                    face[0].u[1] = u_left;
                    face[0].v[1] = v_top;
                    face[0].u[2] = u_mid;
                    face[0].v[2] = v_mid;

                    face[1].u[0] = u_mid;
                    face[1].v[0] = v_mid;
                    face[1].u[1] = u_left;
                    face[1].v[1] = v_top;
                    face[1].u[2] = u_right;
                    face[1].v[2] = v_top;

                    face[2].u[0] = u_mid;
                    face[2].v[0] = v_mid;
                    face[2].u[1] = u_right;
                    face[2].v[1] = v_top;
                    face[2].u[2] = u_right;
                    face[2].v[2] = v_mid;

                    face[3].u[0] = u_left;
                    face[3].v[0] = v_bottom;
                    face[3].u[1] = u_left;
                    face[3].v[1] = v_mid;
                    face[3].u[2] = u_mid;
                    face[3].v[2] = v_mid;

                    face[4].u[0] = u_left;
                    face[4].v[0] = v_bottom;
                    face[4].u[1] = u_mid;
                    face[4].v[1] = v_mid;
                    face[4].u[2] = u_mid;
                    face[4].v[2] = v_bottom;

                    face[5].u[0] = u_mid;
                    face[5].v[0] = v_bottom;
                    face[5].u[1] = u_mid;
                    face[5].v[1] = v_mid;
                    face[5].u[2] = u_right;
                    face[5].v[2] = v_mid;

                    face[6].u[0] = u_mid;
                    face[6].v[0] = v_bottom;
                    face[6].u[1] = u_right;
                    face[6].v[1] = v_mid;
                    face[6].u[2] = u_right;
                    face[6].v[2] = v_bottom;
                }
                else
                {
                    face[0].flags &= ~ESCH_FACE_TEXTURED;
                    face[1].flags &= ~ESCH_FACE_TEXTURED;
                    face[2].flags &= ~ESCH_FACE_TEXTURED;
                    face[3].flags &= ~ESCH_FACE_TEXTURED;
                    face[4].flags &= ~ESCH_FACE_TEXTURED;
                    face[5].flags &= ~ESCH_FACE_TEXTURED;
                    face[6].flags &= ~ESCH_FACE_TEXTURED;
                }
                esch_clipdraw_face (0, ctrlfl);
                esch_clipdraw_face (1, ctrlfl);
                esch_clipdraw_face (2, ctrlfl);
                esch_clipdraw_face (3, ctrlfl);
                esch_clipdraw_face (4, ctrlfl);
                esch_clipdraw_face (5, ctrlfl);
                esch_clipdraw_face (6, ctrlfl);
            }
        }
        lsptr = &rsptr[(((j+2) << dlevel)>>surfshift)];
    }
    ec.pop();
}

void EschTerrainEx::draw_terrain_trans_left (VngoRect *rect,
                                             EschPoint *orig,
                                             byte *dptr,
                                             esch_surf_type *_sptr,
                                             int dlevel,
                                             ulong _count,
                                             dword lflags)
{
    int     count = int(_count >> 1);
    float   u_left,u_right,u_mid;
    float   v_top,v_bottom,v_mid;
    dword   flag_state = ESCH_FACE_ALLOWPERSP
                         | ESCH_FACE_TEXTURED
                         | ESCH_FACE_SPECULAR
                         | ESCH_FACE_SMOOTH
                         | ESCH_FACE_FLAT
                         | ESCH_FACE_SOLID
                         | ESCH_FACE_WIRE;
    dword   flags1 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags2 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE;
    dword   flags3 = ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags4 = ESCH_FACE_BCLINE;

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        flag_state &= ~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        flag_state &= ~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        flag_state &= ~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        flag_state &= ~ESCH_FACE_SPECULAR;
    }


    EschPoint       work_point;
    EschPoint       *cpt=&work_point;
    dword           *vflags;
    VngoPoint       *vA,*vB,*vC;
    esch_surf_type  *sptr = _sptr;
    esch_surf_type  *rsptr = sptr;
    byte            *rptr = dptr;
    long            pstep = width << dlevel;

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    ulong   needed;
    int     texture_shift;
    VngoPoint       *vpt;
    EschVector      _wvec;
    EschVector      _dvec;

    static EschFace face[7];

    if ((dlevel + 1) > int(surfshift))
        texture_shift = (dlevel + 1) - surfshift;
    else
        texture_shift = 0;

    // Drawing a z-stepping strip of terrain blocks.
    // Blocks are comprised of 8 points and 7 polys.

    // A B C
    // -----
    // |\|/|
    // | --+
    // |/|/|
    // -----

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    byte *ptr = dptr;

    cpt->x = orig->x;
    cpt->y = orig->y;
    cpt->z = orig->z;

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    ulong vert_count = (_count<<1) + 1;

    needed = (((sizeof(dword)+sizeof(VngoPoint)) * vert_count) * 3);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * (vert_count * 3));
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[vert_count * 3];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();

    int rowa = 0;
    int rowb = vert_count;
    int rowc = vert_count + vert_count;
    byte *visflags=(byte*)ivory_arena_alloc(EschSysInstance->wspace,(vert_count >> 1) * sizeof(byte));
    memset(visflags,3,vert_count>>1);

    vA = &vpt[rowa];
    vB = &vpt[rowb];
    vC = &vpt[rowc];


    // A ignores odd columns in loop
    for (ulong i=0; i< vert_count; i++)
    {
        float h = htable[*ptr];
        // build A
        ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

        if(!(sptr->flags & ESCH_SURF_HIDDEN))
            visflags[i>>1] &= ~1;

        if(sptr->flags & ESCH_SURF_NOTILE)
            visflags[i>>1] &= ~2;

        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vA->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vA->clr = sptr->cind;
        }

        vA->shade = sptr->shd;
        cpt->x += _dvec.i; // + _dvec.i;
        cpt->y += _dvec.j; // + _dvec.j;
        cpt->z += _dvec.k; // + _dvec.k;

        vA++;
        ptr += pstep;
        sptr += pstep >> surfshift;
//        ptr += pstep;
//        sptr += pstep >> surfshift;
    }

    ptr = rptr + (1 << dlevel);
    sptr = rsptr + ((1 << dlevel) >> surfshift);

    rptr = ptr;
    rsptr = sptr;

    cpt->x = orig->x + _wvec.i;
    cpt->y = orig->y + _wvec.j;
    cpt->z = orig->z + _wvec.k;

    for (i=0; i< vert_count; i++)
    {
        // build B
        float h = htable[*ptr];
        ((EschPoint *)vB)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vB)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vB)->z = cpt->z + (h * hvec.k);

        if(!(sptr->flags & ESCH_SURF_HIDDEN))
            visflags[i>>1] &= ~1;

        if(sptr->flags & ESCH_SURF_NOTILE)
            visflags[i>>1] &= ~2;

        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vB->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vB->clr = sptr->cind;
        }

        vB->shade = sptr->shd;
        cpt->x += _dvec.i;
        cpt->y += _dvec.j;
        cpt->z += _dvec.k;

        vB++;
        ptr += pstep;
        sptr += (pstep >> surfshift);
    }

    cpt->x = orig->x + _wvec.i + _wvec.i;
    cpt->y = orig->y + _wvec.j + _wvec.j;
    cpt->z = orig->z + _wvec.k + _wvec.k;

    ptr = rptr + (1 << dlevel);
    sptr = rsptr + ((1 << dlevel) >> surfshift);

    for (i = 0; i<vert_count; i++)
    {
        float h = htable[*ptr];
        // build C
        ((EschPoint *)vC)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vC)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vC)->z = cpt->z + (h * hvec.k);
        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vC->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vC->clr = sptr->cind;
        }

        vC->shade = sptr->shd;
        cpt->x += _dvec.i;
        cpt->y += _dvec.j;
        cpt->z += _dvec.k;

        vC++;
        ptr += pstep;
        sptr += (pstep >> surfshift);
    }

    vA = &vpt[rowa];
    vB = &vpt[rowb];
    vC = &vpt[rowc];

    for (i=0; i<vert_count; i++)
    {
        // average B based on A-1,C+1 points
        point_average ((EschPoint *)vB, ((EschPoint *)vA), ((EschPoint *)vC));
        vA++;
        vB++;
        vC++;
    }

    rsptr = _sptr;
    esch_surf_type  *lsptr;
    lsptr = rsptr;
//    lsptr = &rsptr[-((width >> surfshift) << dlevel)];
    dword tlflags;

    for (ushort j=0; j<_count; j+=2)
    {
        // build and draw polys

        tlflags = lsptr->flags;
        if (   (   (( rect->x + (2 << dlevel)) >= left_edge[rect->y + (j << dlevel)])
                || (( rect->x + (2 << dlevel)) >= left_edge[rect->y + ((j+2) << dlevel)])
               )
            ||
               (   ( rect->x <= right_edge[rect->y + (j << dlevel)])
                || ( rect->x <= right_edge[rect->y + ((j+2) << dlevel)])
               )
           )
        {
            if (!(visflags[j>>1] & 1))
            {
                // draw the tri-conglomerate formed by a, b, & c
                face[0].flags = flag_state | flags1;
                face[1].flags = flag_state | flags1;
                face[2].flags = flag_state | flags1;
                face[3].flags = flag_state | flags1;
                face[4].flags = flag_state | flags1;
                face[5].flags = flag_state | flags1;
                face[6].flags = flag_state | flags1;

                face[0].a = j + rowa + 2;
                face[0].b = j + rowb + 1;
                face[0].c = j + rowa;

                face[1].a = j + rowa + 2;
                face[1].b = j + rowb + 2;
                face[1].c = j + rowb + 1;

                face[2].a = j + rowb + 2;
                face[2].b = j + rowc + 2;
                face[2].c = j + rowb + 1;

                face[3].a = j + rowc + 2;
                face[3].b = j + rowc + 1;
                face[3].c = j + rowb + 1;

                face[4].a = j + rowb + 1;
                face[4].b = j + rowb;
                face[4].c = j + rowa;

                face[5].a = j + rowb + 1;
                face[5].b = j + rowc + 1;
                face[5].c = j + rowb;

                face[6].a = j + rowc + 1;
                face[6].b = j + rowc;
                face[6].c = j + rowb;

                if ((tlflags & ESCH_SURF_CINDISTXT) &&
                    ((visflags[j>>1] & 0x2) || !texture_shift))
                {
                    // heheheh
                    face[6].txt=
                    face[5].txt=
                    face[4].txt=
                    face[3].txt=
                    face[2].txt=
                    face[1].txt=
                    face[0].txt=lsptr->cind;

                    if (face[0].flags & ESCH_FACE_TEXTURED)
                    {
                        compute_texture_uv(u_left, u_right, v_top, v_bottom,
                                           tlflags, rect->x + (i << dlevel),
                                           rect->y + (i << dlevel),
                                           texture_shift);
                        u_mid = (u_left+u_right)/2.0f;
                        v_mid = (v_top+v_bottom)/2.0f;
                    }
                    else
                    {
                        u_left=u_right=v_bottom=v_top=u_mid=v_mid=0.f;
                    }

                    face[0].u[0] = u_left;
                    face[0].v[0] = v_top;
                    face[0].u[1] = u_mid;
                    face[0].v[1] = v_mid;
                    face[0].u[2] = u_left;
                    face[0].v[2] = v_bottom;

                    face[1].u[0] = u_left;
                    face[1].v[0] = v_top;
                    face[1].u[1] = u_mid;
                    face[1].v[1] = v_top;
                    face[1].u[2] = u_mid;
                    face[1].v[2] = v_mid;

                    face[2].u[0] = u_mid;
                    face[2].v[0] = v_top;
                    face[2].u[1] = u_right;
                    face[2].v[1] = v_top;
                    face[2].u[2] = u_mid;
                    face[2].v[2] = v_mid;

                    face[3].u[0] = u_right;
                    face[3].v[0] = v_top;
                    face[3].u[1] = u_right;
                    face[3].v[1] = v_mid;
                    face[3].u[2] = u_mid;
                    face[3].v[2] = v_mid;

                    face[4].u[0] = u_mid;
                    face[4].v[0] = v_mid;
                    face[4].u[1] = u_mid;
                    face[4].v[1] = v_bottom;
                    face[4].u[2] = u_left;
                    face[4].v[2] = v_bottom;

                    face[5].u[0] = u_mid;
                    face[5].v[0] = v_mid;
                    face[5].u[1] = u_right;
                    face[5].v[1] = v_mid;
                    face[5].u[2] = u_mid;
                    face[5].v[2] = v_bottom;

                    face[6].u[0] = u_right;
                    face[6].v[0] = v_mid;
                    face[6].u[1] = u_right;
                    face[6].v[1] = v_bottom;
                    face[6].u[2] = u_mid;
                    face[6].v[2] = v_bottom;
                }
                else
                {
                    face[0].flags &= ~ESCH_FACE_TEXTURED;
                    face[1].flags &= ~ESCH_FACE_TEXTURED;
                    face[2].flags &= ~ESCH_FACE_TEXTURED;
                    face[3].flags &= ~ESCH_FACE_TEXTURED;
                    face[4].flags &= ~ESCH_FACE_TEXTURED;
                    face[5].flags &= ~ESCH_FACE_TEXTURED;
                    face[6].flags &= ~ESCH_FACE_TEXTURED;
                }
                esch_clipdraw_face (0, ctrlfl);
                esch_clipdraw_face (1, ctrlfl);
                esch_clipdraw_face (2, ctrlfl);
                esch_clipdraw_face (3, ctrlfl);
                esch_clipdraw_face (4, ctrlfl);
                esch_clipdraw_face (5, ctrlfl);
                esch_clipdraw_face (6, ctrlfl);
            }
        }
        lsptr = &rsptr[(((j+2) << dlevel)>>surfshift) * width];
    }
    ec.pop();
}

void EschTerrainEx::draw_terrain_trans_right (VngoRect *rect,
                                              EschPoint *orig,
                                              byte *dptr,
                                              esch_surf_type *_sptr,
                                              int dlevel,
                                              ulong _count,
                                              dword lflags)
{
    int     count = int(_count >> 1);
    float   u_left,u_right,u_mid;
    float   v_top,v_bottom,v_mid;
    dword   flag_state = ESCH_FACE_ALLOWPERSP
                         | ESCH_FACE_TEXTURED
                         | ESCH_FACE_SPECULAR
                         | ESCH_FACE_SMOOTH
                         | ESCH_FACE_FLAT
                         | ESCH_FACE_SOLID
                         | ESCH_FACE_WIRE;
    dword   flags1 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags2 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE;
    dword   flags3 = ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags4 = ESCH_FACE_BCLINE;

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        flag_state &= ~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        flag_state &= ~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        flag_state &= ~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        flag_state &= ~ESCH_FACE_SPECULAR;
    }


    EschPoint       work_point;
    EschPoint       *cpt=&work_point;
    dword           *vflags;
    VngoPoint       *vA,*vB,*vC;
    esch_surf_type  *sptr = _sptr;
    esch_surf_type  *rsptr = sptr;
    byte            *rptr = dptr;
    long            pstep = width << dlevel;

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    ulong   needed;
    int     texture_shift;
    VngoPoint       *vpt;
    EschVector      _wvec;
    EschVector      _dvec;

    static EschFace face[7];

    if ((dlevel + 1)> int(surfshift))
        texture_shift = (dlevel + 1) - surfshift;
    else
        texture_shift = 0;

    // Drawing a z-stepping strip of terrain blocks.
    // Blocks are comprised of 8 points and 7 polys.

    // A B C
    // -----
    // |/|/|
    // +-- |
    // |/|\|
    // -----

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    byte *ptr = dptr;

    cpt->x = orig->x;
    cpt->y = orig->y;
    cpt->z = orig->z;

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    ulong vert_count = (_count<<1) + 1;

    needed = (((sizeof(dword)+sizeof(VngoPoint)) * vert_count) * 3);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * (vert_count * 3));
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[vert_count * 3];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();

    int rowa = 0;
    int rowb = vert_count;
    int rowc = vert_count + vert_count;
    byte *visflags=(byte*)ivory_arena_alloc(EschSysInstance->wspace,(vert_count >> 1) * sizeof(byte));
    memset(visflags,3,vert_count>>1);

    vA = &vpt[rowa];
    vB = &vpt[rowb];
    vC = &vpt[rowc];


    // A ignores odd columns in loop
    for (ulong i=0; i< vert_count; i++)
    {
        float h = htable[*ptr];
        // build A
        ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

        if(!(sptr->flags & ESCH_SURF_HIDDEN))
            visflags[i>>1] &= ~1;

        if(sptr->flags & ESCH_SURF_NOTILE)
            visflags[i>>1] &= ~2;

        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vA->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vA->clr = sptr->cind;
        }

        vA->shade = sptr->shd;
        cpt->x += _dvec.i; // + _dvec.i;
        cpt->y += _dvec.j; // + _dvec.j;
        cpt->z += _dvec.k; // + _dvec.k;

        vA++;
        ptr += pstep;
        sptr += pstep >> surfshift;
//        ptr += pstep;
//        sptr += pstep >> surfshift;
    }

    ptr = rptr + (1 << dlevel);
    sptr = rsptr + ((1 << dlevel) >> surfshift);

    rptr = ptr;
    rsptr = sptr;

    cpt->x = orig->x + _wvec.i;
    cpt->y = orig->y + _wvec.j;
    cpt->z = orig->z + _wvec.k;

    for (i=0; i< vert_count; i++)
    {
        // build B
        float h = htable[*ptr];
        ((EschPoint *)vB)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vB)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vB)->z = cpt->z + (h * hvec.k);

        if(!(sptr->flags & ESCH_SURF_HIDDEN))
            visflags[i>>1] &= ~1;

        if(sptr->flags & ESCH_SURF_NOTILE)
            visflags[i>>1] &= ~2;

        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vB->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vB->clr = sptr->cind;
        }

        vB->shade = sptr->shd;
        cpt->x += _dvec.i;
        cpt->y += _dvec.j;
        cpt->z += _dvec.k;

        vB++;
        ptr += pstep;
        sptr += (pstep >> surfshift);
    }

    cpt->x = orig->x + _wvec.i + _wvec.i;
    cpt->y = orig->y + _wvec.j + _wvec.j;
    cpt->z = orig->z + _wvec.k + _wvec.k;

    ptr = rptr + (1 << dlevel);
    sptr = rsptr + ((1 << dlevel) >> surfshift);

    for (i = 0; i<vert_count; i++)
    {
        float h = htable[*ptr];
        // build C
        ((EschPoint *)vC)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vC)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vC)->z = cpt->z + (h * hvec.k);
        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vC->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vC->clr = sptr->cind;
        }

        vC->shade = sptr->shd;
        cpt->x += _dvec.i;
        cpt->y += _dvec.j;
        cpt->z += _dvec.k;

        vC++;
        ptr += pstep;
        sptr += (pstep >> surfshift);
    }

    vA = &vpt[rowa];
    vB = &vpt[rowb];
    vC = &vpt[rowc];

    for (i=0; i<vert_count; i++)
    {
        // average B based on A-1,C+1 points
        point_average ((EschPoint *)vB, ((EschPoint *)vA), ((EschPoint *)vC));
        vA++;
        vB++;
        vC++;
    }

    rsptr = _sptr;
    esch_surf_type  *lsptr;
    lsptr = &rsptr[-((width >> surfshift) << dlevel)];
    dword tlflags;

    for (ushort j=0; j<_count; j+=2)
    {
        // build and draw polys

        tlflags = lsptr->flags;
        if (   (   (( rect->x + (2 << dlevel)) >= left_edge[rect->y + (j << dlevel)])
                || (( rect->x + (2 << dlevel)) >= left_edge[rect->y + ((j+2) << dlevel)])
               )
            ||
               (   ( rect->x <= right_edge[rect->y + (j << dlevel)])
                || ( rect->x <= right_edge[rect->y + ((j+2) << dlevel)])
               )
           )
        {
            if (!(visflags[j>>1] & 1))
            {
                // draw the tri-conglomerate formed by a, b, & c
                face[0].flags = flag_state | flags1;
                face[1].flags = flag_state | flags1;
                face[2].flags = flag_state | flags1;
                face[3].flags = flag_state | flags1;
                face[4].flags = flag_state | flags1;
                face[5].flags = flag_state | flags1;
                face[6].flags = flag_state | flags1;

                face[0].a = j + rowa + 2;
                face[0].b = j + rowb + 2;
                face[0].c = j + rowa + 1;

                face[1].a = j + rowb + 2;
                face[1].b = j + rowb + 1;
                face[1].c = j + rowa + 1;

                face[2].a = j + rowb + 2;
                face[2].b = j + rowc + 2;
                face[2].c = j + rowb + 1;

                face[3].a = j + rowc + 2;
                face[3].b = j + rowc;
                face[3].c = j + rowb + 1;

                face[4].a = j + rowa + 1;
                face[4].b = j + rowb + 1;
                face[4].c = j + rowa;

                face[5].a = j + rowb + 1;
                face[5].b = j + rowb;
                face[5].c = j + rowa;

                face[6].a = j + rowb + 1;
                face[6].b = j + rowc;
                face[6].c = j + rowb;

                if ((tlflags & ESCH_SURF_CINDISTXT) &&
                    ((visflags[j>>1] & 0x2) || !texture_shift))
                {
                    // heheheh
                    face[6].txt=
                    face[5].txt=
                    face[4].txt=
                    face[3].txt=
                    face[2].txt=
                    face[1].txt=
                    face[0].txt=lsptr->cind;

                    if (face[0].flags & ESCH_FACE_TEXTURED)
                    {
                        compute_texture_uv(u_left, u_right, v_top, v_bottom,
                                           tlflags, rect->x + (i << dlevel),
                                           rect->y + (i << dlevel),
                                           texture_shift);
                        u_mid = (u_left+u_right)/2.0f;
                        v_mid = (v_top+v_bottom)/2.0f;
                    }
                    else
                    {
                        u_left=u_right=v_bottom=v_top=u_mid=v_mid=0.f;
                    }

                    face[0].u[0] = u_left;
                    face[0].v[0] = v_top;
                    face[0].u[1] = u_mid;
                    face[0].v[1] = v_top;
                    face[0].u[2] = u_left;
                    face[0].v[2] = v_mid;

                    face[1].u[0] = u_mid;
                    face[1].v[0] = v_top;
                    face[1].u[1] = u_mid;
                    face[1].v[1] = v_mid;
                    face[1].u[2] = u_left;
                    face[1].v[2] = v_mid;

                    face[2].u[0] = u_mid;
                    face[2].v[0] = v_top;
                    face[2].u[1] = u_right;
                    face[2].v[1] = v_top;
                    face[2].u[2] = u_mid;
                    face[2].v[2] = v_mid;

                    face[3].u[0] = u_right;
                    face[3].v[0] = v_top;
                    face[3].u[1] = u_right;
                    face[3].v[1] = v_bottom;
                    face[3].u[2] = u_mid;
                    face[3].v[2] = v_mid;

                    face[4].u[0] = u_left;
                    face[4].v[0] = v_mid;
                    face[4].u[1] = u_mid;
                    face[4].v[1] = v_mid;
                    face[4].u[2] = u_left;
                    face[4].v[2] = v_bottom;

                    face[5].u[0] = u_mid;
                    face[5].v[0] = v_mid;
                    face[5].u[1] = u_mid;
                    face[5].v[1] = v_bottom;
                    face[5].u[2] = u_left;
                    face[5].v[2] = v_bottom;

                    face[6].u[0] = u_mid;
                    face[6].v[0] = v_mid;
                    face[6].u[1] = u_right;
                    face[6].v[1] = v_bottom;
                    face[6].u[2] = u_mid;
                    face[6].v[2] = v_bottom;
                }
                else
                {
                    face[0].flags &= ~ESCH_FACE_TEXTURED;
                    face[1].flags &= ~ESCH_FACE_TEXTURED;
                    face[2].flags &= ~ESCH_FACE_TEXTURED;
                    face[3].flags &= ~ESCH_FACE_TEXTURED;
                    face[4].flags &= ~ESCH_FACE_TEXTURED;
                    face[5].flags &= ~ESCH_FACE_TEXTURED;
                    face[6].flags &= ~ESCH_FACE_TEXTURED;
                }
                esch_clipdraw_face (0, ctrlfl);
                esch_clipdraw_face (1, ctrlfl);
                esch_clipdraw_face (2, ctrlfl);
                esch_clipdraw_face (3, ctrlfl);
                esch_clipdraw_face (4, ctrlfl);
                esch_clipdraw_face (5, ctrlfl);
                esch_clipdraw_face (6, ctrlfl);
            }
        }
        lsptr = &rsptr[(((j+2) << dlevel)>>surfshift) * width];
    }
    ec.pop();
}

void EschTerrainEx::draw_terrain_trans_ul (VngoRect *rect,
                                           EschPoint *orig,
                                           byte *dptr,
                                           esch_surf_type *sptr,
                                           int dlevel,
                                           dword lflags)
{
    if (!(
            ( (( rect->x + (2 << dlevel)) >= left_edge[rect->y])
            || (( rect->x + (2 << dlevel)) >= left_edge[rect->y + (2 << dlevel)])
            )
         || 
            ( ((rect->x) <= right_edge[rect->y])
            || (( rect->x) <= right_edge[rect->y + (2 << dlevel)])
            )
         )
       ) 
    {
        return;
    }

    float   u_left,u_right,u_mid;
    float   v_top,v_bottom,v_mid;
    ulong       needed;
    int         texture_shift;
    VngoPoint   *vpt;
    EschVector  _wvec;
    EschVector  _dvec;

    dword       *vflags;
    dword   flag_state = ESCH_FACE_ALLOWPERSP
                         | ESCH_FACE_TEXTURED
                         | ESCH_FACE_SPECULAR
                         | ESCH_FACE_SMOOTH
                         | ESCH_FACE_FLAT
                         | ESCH_FACE_SOLID
                         | ESCH_FACE_WIRE;
    dword   flags1 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags2 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE;
    dword   flags3 = ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags4 = ESCH_FACE_BCLINE;

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    static EschFace         face[6];

    if ((dlevel+1) > int(surfshift))
        texture_shift = (dlevel + 1) - surfshift;
    else
        texture_shift = 0;

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        flag_state &= ~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        flag_state &= ~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        flag_state &= ~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        flag_state &= ~ESCH_FACE_SPECULAR;
    }

    assertMyth("EschLowTerrain::draw_terrain_rect needs camera.",
                cam != NULL);

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    // Setup the stepping vectors for the correct detail level.

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    // Update workspace metrics; no other place is reasonable to do this

    needed = ((sizeof(dword)+sizeof(VngoPoint)) * 9);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

//ÄÄÄ Push drawing context

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 9);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[9];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();


    VngoPoint *vA = &vpt[0];

    // Point 0
    ((EschPoint*)vA)->x = orig->x + (htable[*dptr] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + (htable[*dptr] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + (htable[*dptr] * hvec.k);
    if (sptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[sptr->cind-1];
    }
    else
    {
        vA->clr = sptr->cind;
    }
    vA->shade = sptr->shd;


    vA++;
    // Point 1
    ((EschPoint*)vA)->x = orig->x + _wvec.i + _wvec.i + (htable[*(dptr+(2 << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + _wvec.j + (htable[*(dptr+(2 << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + _wvec.k + (htable[*(dptr+(2 << dlevel))] * hvec.k);

    esch_surf_type *tsptr = sptr+((2 << dlevel) >> surfshift);

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 2
    ((EschPoint*)vA)->x = orig->x + _wvec.i + _dvec.i + (htable[*(dptr+((width + 1) << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + _dvec.j + (htable[*(dptr+((width + 1) << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + _dvec.k + (htable[*(dptr+((width + 1) << dlevel))] * hvec.k);

    tsptr = sptr+(((width+1) << dlevel) >> surfshift);
    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 3
    ((EschPoint*)vA)->x = orig->x + _wvec.i + _wvec.i + _dvec.i + (htable[*(dptr+((width+2) << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + _wvec.j + _dvec.j + (htable[*(dptr+((width+2) << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + _wvec.k + _dvec.k + (htable[*(dptr+((width+2) << dlevel))] * hvec.k);

    tsptr = sptr+(((width+2) << dlevel) >> surfshift);
    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 4
    ((EschPoint*)vA)->x = orig->x + _dvec.i + _dvec.i + (htable[*(dptr+((width *2)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _dvec.j + _dvec.j + (htable[*(dptr+((width *2)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _dvec.k + _dvec.k + (htable[*(dptr+((width *2)<<dlevel))] * hvec.k);

    tsptr = (sptr + (((width *2) << dlevel)>>surfshift));
    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 5
    ((EschPoint*)vA)->x = orig->x +
                          _dvec.i + _dvec.i
                          + _wvec.i
                          + (htable[*(dptr+(((width * 2) + 1)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y
                          + _dvec.j + _dvec.j
                          + _wvec.j
                          + (htable[*(dptr+(((width * 2) + 1)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z
                          + _dvec.k + _dvec.k
                          + _wvec.k
                          + (htable[*(dptr+(((width * 2) + 1)<<dlevel))] * hvec.k);

    tsptr = (sptr + ((((width *2)+1) << dlevel)>>surfshift));
    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 6
    ((EschPoint*)vA)->x = orig->x
                          + _dvec.i + _dvec.i
                          + _wvec.i + _wvec.i
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y
                          + _dvec.j + _dvec.j
                          + _wvec.j + _wvec.j
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z
                          + _dvec.k + _dvec.k
                          + _wvec.k + _wvec.k
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.k);

    tsptr = (sptr + ((((width*2)+2) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    int t = (2<<dlevel);
    int t2 = (width << (dlevel+1));

    dword viewflags = 0x3;
    if (!(sptr->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if (sptr->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t2)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t2)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t+t2)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t+t2)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    point_average ((EschPoint *)&vpt[5], (EschPoint *)&vpt[4], (EschPoint *)&vpt[6]);
    point_average ((EschPoint *)&vpt[3], (EschPoint *)&vpt[1], (EschPoint *)&vpt[6]);
    point_average ((EschPoint *)&vpt[2], (EschPoint *)&vpt[0], (EschPoint *)&vpt[6]);

    esch_surf_type  *rsptr = sptr;
    esch_surf_type  *lsptr;
    lsptr = &rsptr[-((width >> surfshift) << dlevel)];
    dword tlflags;
    tlflags = lsptr->flags;

    if (!(viewflags & 1))
    {
        face[0].flags = flag_state | flags1;
        face[1].flags = flag_state | flags1;
        face[2].flags = flag_state | flags1;
        face[3].flags = flag_state | flags1;
        face[4].flags = flag_state | flags1;
        face[5].flags = flag_state | flags1;

        face[0].a = 4;
        face[0].b = 2;
        face[0].c = 0;

        face[1].a = 2;
        face[1].b = 1;
        face[1].c = 0;

        face[2].a = 2;
        face[2].b = 3;
        face[2].c = 1;

        face[3].a = 6;
        face[3].b = 3;
        face[3].c = 2;

        face[4].a = 5;
        face[4].b = 6;
        face[4].c = 2;

        face[5].a = 4;
        face[5].b = 5;
        face[5].c = 2;

        if ((tlflags & ESCH_SURF_CINDISTXT) &&
            (!texture_shift || (viewflags & 0x2)))
        {
            // heheheh
            face[5].txt=
            face[4].txt=
            face[3].txt=
            face[2].txt=
            face[1].txt=
            face[0].txt=lsptr->cind;

            if (face[0].flags & ESCH_FACE_TEXTURED)
            {
                compute_texture_uv(u_left, u_right, v_top, v_bottom,
                                    tlflags, rect->x,
                                    rect->y,
                                    texture_shift);
                u_mid = (u_left+u_right)/2.0f;
                v_mid = (v_top+v_bottom)/2.0f;
            }
            else
            {
                u_left=u_right=v_bottom=v_top=u_mid=v_mid=0.0f;
            }

            face[0].u[0] = u_left;
            face[0].v[0] = v_top;
            face[0].u[1] = u_mid;
            face[0].v[1] = v_mid;
            face[0].u[2] = u_left;
            face[0].v[2] = v_bottom;

            face[1].u[0] = u_mid;
            face[1].v[0] = v_mid;
            face[1].u[1] = u_right;
            face[1].v[1] = v_bottom;
            face[1].u[2] = u_left;
            face[1].v[2] = v_bottom;

            face[2].u[0] = u_mid;
            face[2].v[0] = v_mid;
            face[2].u[1] = u_right;
            face[2].v[1] = v_mid;
            face[2].u[2] = u_right;
            face[2].v[2] = v_bottom;

            face[3].u[0] = u_right;
            face[3].v[0] = v_top;
            face[3].u[1] = u_right;
            face[3].v[1] = v_mid;
            face[3].u[2] = u_mid;
            face[3].v[2] = v_mid;

            face[4].u[0] = u_mid;
            face[4].v[0] = v_top;
            face[4].u[1] = u_right;
            face[4].v[1] = v_top;
            face[4].u[2] = u_mid;
            face[4].v[2] = v_mid;

            face[5].u[0] = u_left;
            face[5].v[0] = v_top;
            face[5].u[1] = u_mid;
            face[5].v[1] = v_top;
            face[5].u[2] = u_mid;
            face[5].v[2] = v_mid;
        }
        else
        {
            face[0].flags &= ~ESCH_FACE_TEXTURED;
            face[1].flags &= ~ESCH_FACE_TEXTURED;
            face[2].flags &= ~ESCH_FACE_TEXTURED;
            face[3].flags &= ~ESCH_FACE_TEXTURED;
            face[4].flags &= ~ESCH_FACE_TEXTURED;
            face[5].flags &= ~ESCH_FACE_TEXTURED;
        }
        esch_clipdraw_face (0, ctrlfl);
        esch_clipdraw_face (1, ctrlfl);
        esch_clipdraw_face (2, ctrlfl);
        esch_clipdraw_face (3, ctrlfl);
        esch_clipdraw_face (4, ctrlfl);
        esch_clipdraw_face (5, ctrlfl);
    }
//ÄÄÄ Pop drawing context
    ec.pop();
}

void EschTerrainEx::draw_terrain_trans_ur (VngoRect *rect,
                                           EschPoint *orig,
                                           byte *dptr,
                                           esch_surf_type *sptr,
                                           int dlevel,
                                           dword lflags)
{
#if 1
    if (!(
            ( (( rect->x + (2 << dlevel)) >= left_edge[rect->y])
            || (( rect->x + (2 << dlevel)) >= left_edge[rect->y + (2 << dlevel)])
            )
         || 
            ( ((rect->x) <= right_edge[rect->y])
            || (( rect->x) <= right_edge[rect->y + (2 << dlevel)])
            )
         )
       ) 
#else
    if (!((((   rect->x + (2 << dlevel)) >= left_edge[rect->y])
          || (( rect->x + (2 << dlevel)) >= left_edge[rect->y + (2 << dlevel)]))
          && (((rect->x) <= right_edge[rect->y])
          || (( rect->x) <= right_edge[rect->y + (2 << dlevel)]))))
#endif
    {
        return;
    }

    float   u_left,u_right,u_mid;
    float   v_top,v_bottom,v_mid;
    ulong       needed;
    int         texture_shift;
    VngoPoint   *vpt;
    EschVector  _wvec;
    EschVector  _dvec;

    dword       *vflags;
    dword   flag_state = ESCH_FACE_ALLOWPERSP
                         | ESCH_FACE_TEXTURED
                         | ESCH_FACE_SPECULAR
                         | ESCH_FACE_SMOOTH
                         | ESCH_FACE_FLAT
                         | ESCH_FACE_SOLID
                         | ESCH_FACE_WIRE;
    dword   flags1 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags2 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE;
    dword   flags3 = ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags4 = ESCH_FACE_BCLINE;

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    static EschFace         face[6];

    if ((dlevel + 1)> int(surfshift))
        texture_shift = (dlevel + 1) - surfshift;
    else
        texture_shift = 0;

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        flag_state &= ~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        flag_state &= ~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        flag_state &= ~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        flag_state &= ~ESCH_FACE_SPECULAR;
    }

    assertMyth("EschLowTerrain::draw_terrain_rect needs camera.",
                cam != NULL);

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    // Setup the stepping vectors for the correct detail level.

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    // Update workspace metrics; no other place is reasonable to do this

    needed = ((sizeof(dword)+sizeof(VngoPoint)) * 9);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

//ÄÄÄ Push drawing context

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 9);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[9];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();


    VngoPoint *vA = &vpt[0];

    // Point 0
    ((EschPoint*)vA)->x = orig->x + (htable[*dptr] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + (htable[*dptr] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + (htable[*dptr] * hvec.k);
    if (sptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[sptr->cind-1];
    }
    else
    {
        vA->clr = sptr->cind;
    }
    vA->shade = sptr->shd;

    vA++;
    // Point 1
    ((EschPoint*)vA)->x = orig->x + _wvec.i + _wvec.i + (htable[*(dptr+(2 << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + _wvec.j + (htable[*(dptr+(2 << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + _wvec.k + (htable[*(dptr+(2 << dlevel))] * hvec.k);

    esch_surf_type *tsptr = (sptr + ((2 << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 2
    ((EschPoint*)vA)->x = orig->x + _dvec.i + (htable[*(dptr+(width << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _dvec.j + (htable[*(dptr+(width << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _dvec.k + (htable[*(dptr+(width << dlevel))] * hvec.k);

    tsptr = (sptr+((width<<dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 3
    ((EschPoint*)vA)->x = orig->x + _wvec.i + _dvec.i + (htable[*(dptr+((width + 1) << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + _dvec.j + (htable[*(dptr+((width + 1) << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + _dvec.k + (htable[*(dptr+((width + 1) << dlevel))] * hvec.k);

    tsptr = (sptr + (((width + 1) << dlevel)>>surfshift));
    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 4
    ((EschPoint*)vA)->x = orig->x + _dvec.i + _dvec.i + (htable[*(dptr+((width *2)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _dvec.j + _dvec.j + (htable[*(dptr+((width *2)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _dvec.k + _dvec.k + (htable[*(dptr+((width *2)<<dlevel))] * hvec.k);

    tsptr = (sptr + (((width *2) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 5
    ((EschPoint*)vA)->x = orig->x +
                          _dvec.i + _dvec.i
                          + _wvec.i
                          + (htable[*(dptr+(((width * 2) + 1)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y
                          + _dvec.j + _dvec.j
                          + _wvec.j
                          + (htable[*(dptr+(((width * 2) + 1)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z
                          + _dvec.k + _dvec.k
                          + _wvec.k
                          + (htable[*(dptr+(((width * 2) + 1)<<dlevel))] * hvec.k);

    tsptr = (sptr + ((((width *2)+1) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 6
    ((EschPoint*)vA)->x = orig->x
                          + _dvec.i + _dvec.i
                          + _wvec.i + _wvec.i
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y
                          + _dvec.j + _dvec.j
                          + _wvec.j + _wvec.j
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z
                          + _dvec.k + _dvec.k
                          + _wvec.k + _wvec.k
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.k);

    tsptr = (sptr + ((((width*2)+2) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    int t = (2<<dlevel);
    int t2 = (width << (dlevel+1));
    dword viewflags = 0x3;

    if (!(sptr->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if (sptr->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t2)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t2)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t+t2)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t+t2)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    point_average ((EschPoint *)&vpt[5], (EschPoint *)&vpt[4], (EschPoint *)&vpt[6]);
    point_average ((EschPoint *)&vpt[2], (EschPoint *)&vpt[0], (EschPoint *)&vpt[4]);
    point_average ((EschPoint *)&vpt[3], (EschPoint *)&vpt[1], (EschPoint *)&vpt[4]);

    esch_surf_type  *rsptr = sptr;
    esch_surf_type  *lsptr;
    lsptr = &rsptr[-((width >> surfshift) << dlevel)];
    dword tlflags;
    tlflags = lsptr->flags;

    if (!(viewflags & 1))
    {
        face[0].flags = flag_state | flags1;
        face[1].flags = flag_state | flags1;
        face[2].flags = flag_state | flags1;
        face[3].flags = flag_state | flags1;
        face[4].flags = flag_state | flags1;
        face[5].flags = flag_state | flags1;

        face[0].a = 4;
        face[0].b = 5;
        face[0].c = 2;

        face[1].a = 5;
        face[1].b = 3;
        face[1].c = 2;

        face[2].a = 2;
        face[2].b = 3;
        face[2].c = 0;

        face[3].a = 3;
        face[3].b = 1;
        face[3].c = 0;

        face[4].a = 6;
        face[4].b = 1;
        face[4].c = 3;

        face[5].a = 5;
        face[5].b = 6;
        face[5].c = 3;

        if ((tlflags & ESCH_SURF_CINDISTXT) &&
            (!texture_shift || (viewflags & 0x2)))
        {
            // heheheh
            face[5].txt=
            face[4].txt=
            face[3].txt=
            face[2].txt=
            face[1].txt=
            face[0].txt=lsptr->cind;

            if (face[0].flags & ESCH_FACE_TEXTURED)
            {
                compute_texture_uv(u_left, u_right, v_top, v_bottom,
                                    tlflags, rect->x,
                                    rect->y,
                                    texture_shift);
                u_mid = (u_left+u_right)/2.0f;
                v_mid = (v_top+v_bottom)/2.0f;
            }
            else
            {
                u_left=u_right=v_bottom=v_top=u_mid=v_mid=0.0f;
            }

            face[0].u[0] = u_left;
            face[0].v[0] = v_top;
            face[0].u[1] = u_mid;
            face[0].v[1] = v_top;
            face[0].u[2] = u_left;
            face[0].v[2] = v_mid;

            face[1].u[0] = u_mid;
            face[1].v[0] = v_top;
            face[1].u[1] = u_mid;
            face[1].v[1] = v_mid;
            face[1].u[2] = u_left;
            face[1].v[2] = v_mid;

            face[2].u[0] = u_left;
            face[2].v[0] = v_mid;
            face[2].u[1] = u_mid;
            face[2].v[1] = v_mid;
            face[2].u[2] = u_left;
            face[2].v[2] = v_bottom;

            face[3].u[0] = u_mid;
            face[3].v[0] = v_mid;
            face[3].u[1] = u_right;
            face[3].v[1] = v_bottom;
            face[3].u[2] = u_left;
            face[3].v[2] = v_bottom;

            face[4].u[0] = u_right;
            face[4].v[0] = v_top;
            face[4].u[1] = u_right;
            face[4].v[1] = v_bottom;
            face[4].u[2] = u_mid;
            face[4].v[2] = v_mid;

            face[5].u[0] = u_mid;
            face[5].v[0] = v_top;
            face[5].u[1] = u_right;
            face[5].v[1] = v_top;
            face[5].u[2] = u_mid;
            face[5].v[2] = v_mid;
        }
        else
        {
            face[0].flags &= ~ESCH_FACE_TEXTURED;
            face[1].flags &= ~ESCH_FACE_TEXTURED;
            face[2].flags &= ~ESCH_FACE_TEXTURED;
            face[3].flags &= ~ESCH_FACE_TEXTURED;
            face[4].flags &= ~ESCH_FACE_TEXTURED;
            face[5].flags &= ~ESCH_FACE_TEXTURED;
        }
        esch_clipdraw_face (0, ctrlfl);
        esch_clipdraw_face (1, ctrlfl);
        esch_clipdraw_face (2, ctrlfl);
        esch_clipdraw_face (3, ctrlfl);
        esch_clipdraw_face (4, ctrlfl);
        esch_clipdraw_face (5, ctrlfl);
    }
//ÄÄÄ Pop drawing context
    ec.pop();
}

void EschTerrainEx::draw_terrain_trans_bl (VngoRect *rect,
                                           EschPoint *orig,
                                           byte *dptr,
                                           esch_surf_type *sptr,
                                           int dlevel,
                                           dword lflags)
{
#if 1
    if (!(
            ( (( rect->x + (2 << dlevel)) >= left_edge[rect->y])
            || (( rect->x + (2 << dlevel)) >= left_edge[rect->y + (2 << dlevel)])
            )
         || 
            ( ((rect->x) <= right_edge[rect->y])
            || (( rect->x) <= right_edge[rect->y + (2 << dlevel)])
            )
         )
       ) 
#else
    if (!((((   rect->x + (2 << dlevel)) >= left_edge[rect->y])
          || (( rect->x + (2 << dlevel)) >= left_edge[rect->y + (2 << dlevel)]))
          && (((rect->x) <= right_edge[rect->y])
          || (( rect->x) <= right_edge[rect->y + (2 << dlevel)]))))
#endif
    {
        return;
    }

    float   u_left,u_right,u_mid;
    float   v_top,v_bottom,v_mid;
    ulong       needed;
    int         texture_shift;
    VngoPoint   *vpt;
    EschVector  _wvec;
    EschVector  _dvec;

    dword       *vflags;
    dword   flag_state = ESCH_FACE_ALLOWPERSP
                         | ESCH_FACE_TEXTURED
                         | ESCH_FACE_SPECULAR
                         | ESCH_FACE_SMOOTH
                         | ESCH_FACE_FLAT
                         | ESCH_FACE_SOLID
                         | ESCH_FACE_WIRE;
    dword   flags1 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags2 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE;
    dword   flags3 = ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags4 = ESCH_FACE_BCLINE;

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    static EschFace         face[6];

    if ((dlevel + 1)> int(surfshift))
        texture_shift = (dlevel + 1) - surfshift;
    else
        texture_shift = 0;

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        flag_state &= ~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        flag_state &= ~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        flag_state &= ~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        flag_state &= ~ESCH_FACE_SPECULAR;
    }

    assertMyth("EschLowTerrain::draw_terrain_rect needs camera.",
                cam != NULL);

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    // Setup the stepping vectors for the correct detail level.

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    // Update workspace metrics; no other place is reasonable to do this

    needed = ((sizeof(dword)+sizeof(VngoPoint)) * 9);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

//ÄÄÄ Push drawing context

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 9);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[9];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();


    VngoPoint *vA = &vpt[0];

    // Point 0
    ((EschPoint*)vA)->x = orig->x + (htable[*dptr] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + (htable[*dptr] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + (htable[*dptr] * hvec.k);
    if (sptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[sptr->cind-1];
    }
    else
    {
        vA->clr = sptr->cind;
    }
    vA->shade = sptr->shd;

    vA++;
    // Point 1
    ((EschPoint*)vA)->x = orig->x + _wvec.i + (htable[*(dptr+(1 << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + (htable[*(dptr+(1 << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + (htable[*(dptr+(1 << dlevel))] * hvec.k);

    esch_surf_type *tsptr = (sptr + ((2 << dlevel)>>surfshift));
    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 2
    ((EschPoint*)vA)->x = orig->x + _wvec.i + _wvec.i + (htable[*(dptr+(2 << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + _wvec.j + (htable[*(dptr+(2 << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + _wvec.k + (htable[*(dptr+(2 << dlevel))] * hvec.k);

    tsptr = (sptr+((2<<dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 3
    ((EschPoint*)vA)->x = orig->x + _wvec.i + _dvec.i + (htable[*(dptr+((width + 1) << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + _dvec.j + (htable[*(dptr+((width + 1) << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + _dvec.k + (htable[*(dptr+((width + 1) << dlevel))] * hvec.k);

    tsptr = (sptr + (((width + 1) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 4
    ((EschPoint*)vA)->x = orig->x + _dvec.i + _wvec.i + _wvec.i +(htable[*(dptr+((width + 2)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _dvec.j + _wvec.j + _wvec.j +(htable[*(dptr+((width + 2)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _dvec.k + _wvec.k + _wvec.k +(htable[*(dptr+((width + 2)<<dlevel))] * hvec.k);

    tsptr = (sptr + (((width + 2) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 5
    ((EschPoint*)vA)->x = orig->x +
                          _dvec.i + _dvec.i
                          + (htable[*(dptr+((width * 2)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y
                          + _dvec.j + _dvec.j
                          + (htable[*(dptr+((width * 2)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z
                          + _dvec.k + _dvec.k
                          + (htable[*(dptr+((width * 2)<<dlevel))] * hvec.k);

    tsptr = (sptr + (((width * 2) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 6
    ((EschPoint*)vA)->x = orig->x
                          + _dvec.i + _dvec.i
                          + _wvec.i + _wvec.i
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y
                          + _dvec.j + _dvec.j
                          + _wvec.j + _wvec.j
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z
                          + _dvec.k + _dvec.k
                          + _wvec.k + _wvec.k
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.k);

    tsptr = (sptr + ((((width*2)+2) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    int t = (2<<dlevel);
    int t2 = (width << (dlevel+1));

    dword viewflags = 0x3;

    if (!(sptr->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if (sptr->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t2)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t2)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t+t2)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t+t2)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    point_average ((EschPoint *)&vpt[1], (EschPoint *)&vpt[0], (EschPoint *)&vpt[2]);
    point_average ((EschPoint *)&vpt[4], (EschPoint *)&vpt[2], (EschPoint *)&vpt[6]);
    point_average ((EschPoint *)&vpt[3], (EschPoint *)&vpt[2], (EschPoint *)&vpt[5]);

    esch_surf_type  *rsptr = sptr;
    esch_surf_type  *lsptr;
    lsptr = &rsptr[-((width >> surfshift) << dlevel)];
    dword tlflags;
    tlflags = sptr->flags;

    if (!(viewflags & 1))
    {
        face[0].flags = flag_state | flags1;
        face[1].flags = flag_state | flags1;
        face[2].flags = flag_state | flags1;
        face[3].flags = flag_state | flags1;
        face[4].flags = flag_state | flags1;
        face[5].flags = flag_state | flags1;

        face[0].a = 5;
        face[0].b = 3;
        face[0].c = 0;

        face[1].a = 3;
        face[1].b = 1;
        face[1].c = 0;

        face[2].a = 3;
        face[2].b = 4;
        face[2].c = 1;

        face[3].a = 4;
        face[3].b = 2;
        face[3].c = 1;

        face[4].a = 6;
        face[4].b = 4;
        face[4].c = 3;

        face[5].a = 5;
        face[5].b = 6;
        face[5].c = 3;

        if ((tlflags & ESCH_SURF_CINDISTXT) &&
            (!texture_shift || (viewflags & 0x2)))
        {
            // heheheh
            face[5].txt=
            face[4].txt=
            face[3].txt=
            face[2].txt=
            face[1].txt=
            face[0].txt=lsptr->cind;

            if (face[0].flags & ESCH_FACE_TEXTURED)
            {
                compute_texture_uv(u_left, u_right, v_top, v_bottom,
                                    tlflags, rect->x,
                                    rect->y,
                                    texture_shift);
                u_mid = (u_left+u_right)/2.0f;
                v_mid = (v_top+v_bottom)/2.0f;
            }
            else
            {
                u_left=u_right=v_bottom=v_top=u_mid=v_mid=0.0f;
            }

            face[0].u[0] = u_left;
            face[0].v[0] = v_top;
            face[0].u[1] = u_mid;
            face[0].v[1] = v_mid;
            face[0].u[2] = u_left;
            face[0].v[2] = v_bottom;

            face[1].u[0] = u_mid;
            face[1].v[0] = v_mid;
            face[1].u[1] = u_mid;
            face[1].v[1] = v_bottom;
            face[1].u[2] = u_left;
            face[1].v[2] = v_bottom;

            face[2].u[0] = u_mid;
            face[2].v[0] = v_mid;
            face[2].u[1] = u_right;
            face[2].v[1] = v_mid;
            face[2].u[2] = u_mid;
            face[2].v[2] = v_bottom;

            face[3].u[0] = u_right;
            face[3].v[0] = v_mid;
            face[3].u[1] = u_right;
            face[3].v[1] = v_bottom;
            face[3].u[2] = u_mid;
            face[3].v[2] = v_bottom;

            face[4].u[0] = u_right;
            face[4].v[0] = v_top;
            face[4].u[1] = u_right;
            face[4].v[1] = v_mid;
            face[4].u[2] = u_mid;
            face[4].v[2] = v_mid;

            face[5].u[0] = u_left;
            face[5].v[0] = v_top;
            face[5].u[1] = u_right;
            face[5].v[1] = v_top;
            face[5].u[2] = u_mid;
            face[5].v[2] = v_mid;
        }
        else
        {
            face[0].flags &= ~ESCH_FACE_TEXTURED;
            face[1].flags &= ~ESCH_FACE_TEXTURED;
            face[2].flags &= ~ESCH_FACE_TEXTURED;
            face[3].flags &= ~ESCH_FACE_TEXTURED;
            face[4].flags &= ~ESCH_FACE_TEXTURED;
            face[5].flags &= ~ESCH_FACE_TEXTURED;
        }
        esch_clipdraw_face (0, ctrlfl);
        esch_clipdraw_face (1, ctrlfl);
        esch_clipdraw_face (2, ctrlfl);
        esch_clipdraw_face (3, ctrlfl);
        esch_clipdraw_face (4, ctrlfl);
        esch_clipdraw_face (5, ctrlfl);
    }
//ÄÄÄ Pop drawing context
    ec.pop();
}

void EschTerrainEx::draw_terrain_trans_br (VngoRect *rect,
                                           EschPoint *orig,
                                           byte *dptr,
                                           esch_surf_type *sptr,
                                           int dlevel,
                                           dword lflags)
{
#if 1
    if (!(
            ( (( rect->x + (2 << dlevel)) >= left_edge[rect->y])
            || (( rect->x + (2 << dlevel)) >= left_edge[rect->y + (2 << dlevel)])
            )
         || 
            ( ((rect->x) <= right_edge[rect->y])
            || (( rect->x) <= right_edge[rect->y + (2 << dlevel)])
            )
         )
       ) 
#else
    if (!((((   rect->x + (2 << dlevel)) >= left_edge[rect->y])
          || (( rect->x + (2 << dlevel)) >= left_edge[rect->y + (2 << dlevel)]))
          && (((rect->x) <= right_edge[rect->y])
          || (( rect->x) <= right_edge[rect->y + (2 << dlevel)]))))
#endif
    {
        return;
    }

    float   u_left,u_right,u_mid;
    float   v_top,v_bottom,v_mid;
    ulong       needed;
    int         texture_shift;
    VngoPoint   *vpt;
    EschVector  _wvec;
    EschVector  _dvec;

    dword       *vflags;
    dword   flag_state = ESCH_FACE_ALLOWPERSP
                         | ESCH_FACE_TEXTURED
                         | ESCH_FACE_SPECULAR
                         | ESCH_FACE_SMOOTH
                         | ESCH_FACE_FLAT
                         | ESCH_FACE_SOLID
                         | ESCH_FACE_WIRE;
    dword   flags1 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags2 = ESCH_FACE_ABLINE
                     | ESCH_FACE_BCLINE;
    dword   flags3 = ESCH_FACE_BCLINE
                     | ESCH_FACE_CALINE;
    dword   flags4 = ESCH_FACE_BCLINE;

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    static EschFace         face[6];

    if ((dlevel + 1) > int(surfshift))
        texture_shift = (dlevel + 1) - surfshift;
    else
        texture_shift = 0;

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        flag_state &= ~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        flag_state &= ~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        flag_state &= ~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        flag_state &= ~ESCH_FACE_SPECULAR;
    }

    assertMyth("EschLowTerrain::draw_terrain_rect needs camera.",
                cam != NULL);

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    // Setup the stepping vectors for the correct detail level.

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    // Update workspace metrics; no other place is reasonable to do this

    needed = ((sizeof(dword)+sizeof(VngoPoint)) * 9);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

//ÄÄÄ Push drawing context

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 9);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[9];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();


    VngoPoint *vA = &vpt[0];

    // Point 0
    ((EschPoint*)vA)->x = orig->x + (htable[*dptr] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + (htable[*dptr] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + (htable[*dptr] * hvec.k);
    if (sptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[sptr->cind-1];
    }
    else
    {
        vA->clr = sptr->cind;
    }

    vA->shade = sptr->shd;

    vA++;
    // Point 1
    ((EschPoint*)vA)->x = orig->x + _wvec.i + (htable[*(dptr+(1 << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + (htable[*(dptr+(1 << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + (htable[*(dptr+(1 << dlevel))] * hvec.k);

    esch_surf_type *tsptr = (sptr + ((2 << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 2
    ((EschPoint*)vA)->x = orig->x + _wvec.i + _wvec.i + (htable[*(dptr+(2 << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _wvec.j + _wvec.j + (htable[*(dptr+(2 << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _wvec.k + _wvec.k + (htable[*(dptr+(2 << dlevel))] * hvec.k);

    tsptr = (sptr+((2<<dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 3
    ((EschPoint*)vA)->x = orig->x + _dvec.i + (htable[*(dptr+(width << dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _dvec.j + (htable[*(dptr+(width << dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _dvec.k + (htable[*(dptr+(width << dlevel))] * hvec.k);

    tsptr = (sptr + ((width << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 4
    ((EschPoint*)vA)->x = orig->x + _dvec.i + _wvec.i +(htable[*(dptr+((width + 1)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y + _dvec.j + _wvec.j +(htable[*(dptr+((width + 1)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z + _dvec.k + _wvec.k +(htable[*(dptr+((width + 1)<<dlevel))] * hvec.k);

    tsptr = (sptr + (((width + 1) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 5
    ((EschPoint*)vA)->x = orig->x +
                          _dvec.i + _dvec.i
                          + (htable[*(dptr+((width * 2)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y
                          + _dvec.j + _dvec.j
                          + (htable[*(dptr+((width * 2)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z
                          + _dvec.k + _dvec.k
                          + (htable[*(dptr+((width * 2)<<dlevel))] * hvec.k);

    tsptr = (sptr + (((width * 2) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    vA++;
    // Point 6
    ((EschPoint*)vA)->x = orig->x
                          + _dvec.i + _dvec.i
                          + _wvec.i + _wvec.i
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.i);
    ((EschPoint*)vA)->y = orig->y
                          + _dvec.j + _dvec.j
                          + _wvec.j + _wvec.j
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.j);
    ((EschPoint*)vA)->z = orig->z
                          + _dvec.k + _dvec.k
                          + _wvec.k + _wvec.k
                          + (htable[*(dptr+(((width * 2) + 2)<<dlevel))] * hvec.k);

    tsptr = (sptr + ((((width*2)+2) << dlevel)>>surfshift));

    if (tsptr->flags & ESCH_SURF_CINDISTXT)
    {
        vA->clr = txtcolor[tsptr->cind-1];
    }
    else
    {
        vA->clr = tsptr->cind;
    }
    vA->shade = tsptr->shd;

    int t = (2<<dlevel);
    int t2 = (width << (dlevel+1));
    dword viewflags = 0x3;

    if (!(sptr->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if (sptr->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t2)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t2)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    if (!((sptr+t+t2)->flags & ESCH_SURF_HIDDEN))
        viewflags &=~1;
    if ((sptr+t+t2)->flags & ESCH_SURF_NOTILE)
        viewflags &= ~2;

    point_average ((EschPoint *)&vpt[3], (EschPoint *)&vpt[0], (EschPoint *)&vpt[5]);
    point_average ((EschPoint *)&vpt[1], (EschPoint *)&vpt[0], (EschPoint *)&vpt[2]);
    point_average ((EschPoint *)&vpt[4], (EschPoint *)&vpt[0], (EschPoint *)&vpt[6]);

    esch_surf_type  *rsptr = sptr;
    esch_surf_type  *lsptr;
    lsptr = &rsptr[-((width >> surfshift) << dlevel)];
    dword tlflags;
    tlflags = sptr->flags;
    if (!(viewflags & 1))
    {
        face[0].flags = flag_state | flags1;
        face[1].flags = flag_state | flags1;
        face[2].flags = flag_state | flags1;
        face[3].flags = flag_state | flags1;
        face[4].flags = flag_state | flags1;
        face[5].flags = flag_state | flags1;

        face[0].a = 5;
        face[0].b = 4;
        face[0].c = 3;

        face[1].a = 3;
        face[1].b = 4;
        face[1].c = 0;

        face[2].a = 4;
        face[2].b = 1;
        face[2].c = 0;

        face[3].a = 4;
        face[3].b = 2;
        face[3].c = 1;

        face[4].a = 6;
        face[4].b = 2;
        face[4].c = 4;

        face[5].a = 5;
        face[5].b = 6;
        face[5].c = 4;

        if ((tlflags & ESCH_SURF_CINDISTXT) &&
            (!texture_shift || (viewflags & 0x2)))
        {
            // heheheh
            face[5].txt=
            face[4].txt=
            face[3].txt=
            face[2].txt=
            face[1].txt=
            face[0].txt=lsptr->cind;

            if (face[0].flags & ESCH_FACE_TEXTURED)
            {
                compute_texture_uv(u_left, u_right, v_top, v_bottom,
                                    tlflags, rect->x,
                                    rect->y,
                                    texture_shift);
                u_mid = (u_left+u_right)/2.0f;
                v_mid = (v_top+v_bottom)/2.0f;
            }
            else
            {
                u_left=u_right=v_bottom=v_top=u_mid=v_mid=0.0f;
            }

            face[0].u[0] = u_left;
            face[0].v[0] = v_top;
            face[0].u[1] = u_mid;
            face[0].v[1] = v_mid;
            face[0].u[2] = u_left;
            face[0].v[2] = v_mid;

            face[1].u[0] = u_left;
            face[1].v[0] = v_mid;
            face[1].u[1] = u_mid;
            face[1].v[1] = v_mid;
            face[1].u[2] = u_left;
            face[1].v[2] = v_bottom;

            face[2].u[0] = u_mid;
            face[2].v[0] = v_mid;
            face[2].u[1] = u_mid;
            face[2].v[1] = v_bottom;
            face[2].u[2] = u_left;
            face[2].v[2] = v_bottom;

            face[3].u[0] = u_mid;
            face[3].v[0] = v_mid;
            face[3].u[1] = u_right;
            face[3].v[1] = v_bottom;
            face[3].u[2] = u_mid;
            face[3].v[2] = v_bottom;

            face[4].u[0] = u_right;
            face[4].v[0] = v_top;
            face[4].u[1] = u_right;
            face[4].v[1] = v_bottom;
            face[4].u[2] = u_mid;
            face[4].v[2] = v_mid;

            face[5].u[0] = u_left;
            face[5].v[0] = v_top;
            face[5].u[1] = u_right;
            face[5].v[1] = v_top;
            face[5].u[2] = u_mid;
            face[5].v[2] = v_mid;
        }
        else
        {
            face[0].flags &= ~ESCH_FACE_TEXTURED;
            face[1].flags &= ~ESCH_FACE_TEXTURED;
            face[2].flags &= ~ESCH_FACE_TEXTURED;
            face[3].flags &= ~ESCH_FACE_TEXTURED;
            face[4].flags &= ~ESCH_FACE_TEXTURED;
            face[5].flags &= ~ESCH_FACE_TEXTURED;
        }
        esch_clipdraw_face (0, ctrlfl);
        esch_clipdraw_face (1, ctrlfl);
        esch_clipdraw_face (2, ctrlfl);
        esch_clipdraw_face (3, ctrlfl);
        esch_clipdraw_face (4, ctrlfl);
        esch_clipdraw_face (5, ctrlfl);
    }
//ÄÄÄ Pop drawing context
    ec.pop();
}

//°±² End of module - esterndr.cpp ²±°

