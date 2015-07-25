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
// esplndrw.cpp
//
// Contains the code for the EschPlaneDraw class which is a colored and
// optionally textured plane in 3-space.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define LEFT    0x1
#define RIGHT   0x2
#define TOP     0x4
#define BOTTOM  0x8
#define FRONT   0x10
#define BACK    0x20

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - Constructor                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschPlaneDraw::EschPlaneDraw() :
    alpha_level(255),
    EschDrawable(ESCH_DRWT_PLANEDRAW),
    txt(0),
    uvec(1,0,0),
    vvec(0,0,1),
    uvpos(0,0,0),
    ustep(100),
    vstep(100)
{
}

EschPlaneDraw::EschPlaneDraw(float ia, float ib, float ic, float id,
                             dword c) :
    EschDrawable(ESCH_DRWT_PLANEDRAW),
    alpha_level(255),
    plane(ia,ib,ic,id),
    color(c),
    txt(0),
    uvec(1,0,0),
    vvec(0,0,1),
    uvpos(0,0,0),
    ustep(100),
    vstep(100)
{
}

EschPlaneDraw::EschPlaneDraw(float ia, float ib, float ic,
                             float ix, float iy, float iz,
                             dword c) :
    EschDrawable(ESCH_DRWT_PLANEDRAW),
    alpha_level(255),
    plane(ia,ib,ic,ix,iy,iz),
    color(c),
    txt(0),
    uvec(1,0,0),
    vvec(0,0,1),
    uvpos(0,0,0),
    ustep(100),
    vstep(100)
{
}

EschPlaneDraw::EschPlaneDraw(const EschVector &in, float id, dword c) :
    EschDrawable(ESCH_DRWT_PLANEDRAW),
    alpha_level(255),
    plane(in,id),
    color(c),
    txt(0),
    uvec(1,0,0),
    vvec(0,0,1),
    uvpos(0,0,0),
    ustep(100),
    vstep(100)
{
}

EschPlaneDraw::EschPlaneDraw(const EschPlane *pl, dword c) :
    EschDrawable(ESCH_DRWT_PLANEDRAW),
    alpha_level(255),
    plane(*pl),
    color(c),
    txt(0),
    uvec(1,0,0),
    vvec(0,0,1),
    uvpos(0,0,0),
    ustep(100),
    vstep(100)
{
}

EschPlaneDraw::EschPlaneDraw(const EschVector &v1,
                             const EschVector &v2,
                             const EschPoint &pos,
                             dword c, float us, float vs) :
    EschDrawable(ESCH_DRWT_PLANEDRAW),
    alpha_level(255),
    color(c),
    txt(0),
    uvec(v1),
    vvec(v2),
    uvpos(pos),
    ustep(us),
    vstep(vs)
{
    plane.normal = v1 CROSS v2;
    plane.normal.normalize();

    plane.dist = -(plane.normal.i*pos.x
                    + plane.normal.j*pos.y
                    + plane.normal.k*pos.z);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - Destructor                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschPlaneDraw::~EschPlaneDraw()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - operator =                                               ³
//                                                                          ³
// Copies the data from another PlaneDraw.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
const EschPlaneDraw &EschPlaneDraw::operator = (const EschPlaneDraw &s)
{
    if (this != &s)
    {
        release();

        EschDrawable::operator = (s);

        alpha_level = s.alpha_level;
        plane = s.plane;
        color = s.color;
        txt = s.txt;
    }
    return *this;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - draw                                                     ³
//                                                                          ³
// Draws the given plane using the current drawing context.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPlaneDraw::draw()
{
    int             i, j;
    int             count;
    float           dot, t;
    dword           cflags;
    dword           level;
    dword           *vflags;
    VngoPointF3     *vpt;
    EschCamera      *cam;
    dword           af;
    float           tx, ty, maxt;
    EschPoint       p;
    EschVector      vec;
    EschFace        face;
    EschPlane       tplane;
    EschVector      tuvec;
    EschVector      tvvec;
    EschPoint       tuvpos;
    float           u[12];
    float           v[12];
    dword           aflags[12];
    int             ngon[12];

//ÄÄÄ Clear arena
    ivory_arena_clear(EschSysInstance->wspace);

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschPlaneDraw::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschPlaneDraw::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    cflags = cam->flags;
    level = cflags & limits;

    assertMyth("EschPlaneDraw::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    int mp = cam->vport->vbuff.pal->shd_pal->mid_point;

//ÄÄÄ Back-cull
    if (level & ESCH_CAM_BACKCULL)
    {
        EschVector fview(0,0,1);
        fview.transform(&cam->eye.orient);

        if ((fview DOT plane.normal) > 0)
            return;
    }

//ÄÄÄ Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 12);
    assertMyth("EschPlaneDraw::draw failed to allocate needed workspace",
               ec.vflags != 0);

    vpt = new (EschSysInstance->wspace) VngoPointF3[12];

    ec.vpoints = (VngoPoint*)vpt;
    assertMyth("EschPlaneDraw::draw failed to allocate needed workspace",
               ec.vpoints != 0);

    ec.faces = &face;
    ec.fflags = 0;
    ec.txts = &txt;
    ec.push();

//ÄÄÄ Misc Setup
    face.flags = (limits & (ESCH_FACE_WIRE
                            | ESCH_FACE_SOLID
                            | ESCH_FACE_FLAT
                            | ESCH_FACE_SMOOTH
                            | ESCH_FACE_SPECULAR
                            | ESCH_FACE_ONESIDED
                            | ESCH_FACE_ALLOWPERSP))
                 | ESCH_FACE_ABLINE
                 | ESCH_FACE_BCLINE
                 | ESCH_FACE_CALINE;

    if ((limits & ESCH_FACE_ALPHA) && alpha_level < 255)
    {
        face.flags |= ESCH_FACE_ALPHA;
        face.set_alpha(alpha_level);
    }

    if ((limits & ESCH_FACE_TEXTURED) && txt)
    {
        face.flags |= ESCH_FACE_TEXTURED;
        face.txt   = 1;
    }

//ÄÄÄ Transform
    plane.transform(&cam->eye.iorient,&cam->eye.orient,&tplane);

    if (face.flags & ESCH_FACE_TEXTURED)
    {
        uvec.transform(&cam->eye.iorient,&tuvec);
        vvec.transform(&cam->eye.iorient,&tvvec);
        uvpos.transform(&cam->eye.iorient,&tuvpos);
    }

//ÄÄÄ Intersect plane with view frustrum lines to obtain verticies
//ÄÄÄ in view coords
    count=0;

    for(i=0; i < 12; i++)
    {
        //ÄÄÄ Determine line of frustrum
        if (cflags & ESCH_CAM_ORTHO)
        {
            switch (i)
            {
                case 0:                 // Left/Top
                    af = LEFT | TOP;
                    vec.i = 0;          vec.j = 0;          vec.k = 1;
                    p.x = -cam->xsize;  p.y = cam->ysize;   p.z = 1;
                    maxt = cam->yon - 1;
                    break;
                case 1:                 // Right/Top
                    af = RIGHT | TOP;
                    vec.i = 0;          vec.j = 0;          vec.k = 1;
                    p.x = cam->xsize;   p.y = cam->ysize;   p.z = 1;
                    maxt = cam->yon - 1;
                    break;
                case 2:                 // Right/Bottom
                    af = RIGHT | BOTTOM;
                    vec.i = 0;          vec.j = 0;          vec.k = 1;
                    p.x = cam->xsize;   p.y = -cam->ysize;  p.z = 1;
                    maxt = cam->yon - 1;
                    break;
                case 3:                 // Left/Bottom
                    af = LEFT | BOTTOM;
                    vec.i = 0;          vec.j = 0;          vec.k = 1;
                    p.x = -cam->xsize;  p.y = -cam->ysize;  p.z = 1;
                    maxt = cam->yon - 1;
                    break;
                case 4:                 // Front/Top
                    af = FRONT | TOP;
                    vec.i = 1;          vec.j = 0;          vec.k = 0;
                    p.x = -cam->xsize;  p.y = cam->ysize;   p.z = 1;
                    maxt = cam->xsize*2;
                    break;
                case 5:                 // Front/Left
                    af = FRONT | LEFT;
                    vec.i = 0;          vec.j = -1;         vec.k = 0;
                    p.x = -cam->xsize;  p.y = cam->ysize;   p.z = 1;
                    maxt = cam->ysize*2;
                    break;
                case 6:                 // Front/Right
                    af = FRONT | RIGHT;
                    vec.i = 0;          vec.j = -1;         vec.k = 0;
                    p.x = cam->xsize;   p.y = cam->ysize;   p.z = 1;
                    maxt = cam->ysize*2;
                    break;
                case 7:                 // Front/Bottom
                    af = FRONT | BOTTOM;
                    vec.i = 1;          vec.j = 0;          vec.k = 0;
                    p.x = -cam->xsize;  p.y = -cam->ysize;  p.z = 1;
                    maxt = cam->xsize*2;
                    break;
                case 8:                 // Back/Top
                    af = BACK | TOP;
                    vec.i = 1;          vec.j = 0;          vec.k = 0;
                    p.x = -cam->xsize;  p.y = cam->ysize;   p.z = cam->yon;
                    maxt = cam->xsize*2;
                    break;
                case 9:                 // Back/Left
                    af = BACK | LEFT;
                    vec.i = 0;          vec.j = -1;         vec.k = 0;
                    p.x = -cam->xsize;  p.y = cam->ysize;   p.z = cam->yon;
                    maxt = cam->ysize*2;
                    break;
                case 10:                // Back/Right
                    af = BACK | RIGHT;
                    vec.i = 0;          vec.j = -1;         vec.k = 0;
                    p.x = cam->xsize;   p.y = cam->ysize;   p.z = cam->yon;
                    maxt = cam->ysize*2;
                    break;
                case 11:                // Back/Bottom
                    af = BACK | BOTTOM;
                    vec.i = 1;          vec.j = 0;          vec.k = 0;
                    p.x = -cam->xsize;  p.y = -cam->ysize;  p.z = cam->yon;
                    maxt = cam->xsize*2;
                    break;
            }
        }
        else
        {
            tx = cam->xsize * cam->yon;
            ty = cam->ysize * cam->yon;

            switch (i)
            {
                case 0:                 // Left/Top
                    af = LEFT | TOP;
                    p.x = -cam->xsize;  p.y = cam->ysize;   p.z = 1;
                    vec.i = -tx - p.x;
                    vec.j = ty - p.y;
                    vec.k = cam->yon - p.z;
                    maxt = vec.magnitude();
                    if (maxt > 0)
                        vec /= maxt;
                    break;
                case 1:                 // Right/Top
                    af = RIGHT | TOP;
                    p.x = cam->xsize;   p.y = cam->ysize;   p.z = 1;
                    vec.i = tx - p.x;
                    vec.j = ty - p.y;
                    vec.k = cam->yon - p.z;
                    maxt = vec.magnitude();
                    if (maxt > 0)
                        vec /= maxt;
                    break;
                case 2:                 // Right/Bottom
                    af = RIGHT | BOTTOM;
                    p.x = cam->xsize;   p.y = -cam->ysize;  p.z = 1;
                    vec.i = tx - p.x;
                    vec.j = -ty - p.y;
                    vec.k = cam->yon - p.z;
                    maxt = vec.magnitude();
                    if (maxt > 0)
                        vec /= maxt;
                    break;
                case 3:                 // Left/Bottom
                    af = LEFT | BOTTOM;
                    p.x = -cam->xsize;  p.y = -cam->ysize;  p.z = 1;
                    vec.i = -tx - p.x;
                    vec.j = -ty - p.y;
                    vec.k = cam->yon - p.z;
                    maxt = vec.magnitude();
                    if (maxt > 0)
                        vec /= maxt;
                    break;
                case 4:                 // Front/Top
                    af = FRONT | TOP;
                    vec.i = 1;          vec.j = 0;          vec.k = 0;
                    p.x = -cam->xsize;  p.y = cam->ysize;   p.z = 1;
                    maxt = cam->xsize*2;
                    break;
                case 5:                 // Front/Left
                    af = FRONT | LEFT;
                    vec.i = 0;          vec.j = -1;         vec.k = 0;
                    p.x = -cam->xsize;  p.y = cam->ysize;   p.z = 1;
                    maxt = cam->ysize*2;
                    break;
                case 6:                 // Front/Right
                    af = FRONT | RIGHT;
                    vec.i = 0;          vec.j = -1;         vec.k = 0;
                    p.x = cam->xsize;   p.y = cam->ysize;   p.z = 1;
                    maxt = cam->ysize*2;
                    break;
                case 7:                 // Front/Bottom
                    af = FRONT | BOTTOM;
                    vec.i = 1;          vec.j = 0;          vec.k = 0;
                    p.x = -cam->xsize;  p.y = -cam->ysize;  p.z = 1;
                    maxt = cam->xsize*2;
                    break;
                case 8:                 // Back/Top
                    af = BACK | TOP;
                    vec.i = 1;          vec.j = 0;          vec.k = 0;
                    p.x = -tx;          p.y = ty;           p.z = cam->yon;
                    maxt = tx*2;
                    break;
                case 9:                 // Back/Left
                    af = BACK | LEFT;
                    vec.i = 0;          vec.j = -1;         vec.k = 0;
                    p.x = -tx;          p.y = ty;           p.z = cam->yon;
                    maxt = ty*2;
                    break;
                case 10:                // Back/Right
                    af = BACK | RIGHT;
                    vec.i = 0;          vec.j = -1;         vec.k = 0;
                    p.x = tx;           p.y = ty;           p.z = cam->yon;
                    maxt = ty*2;
                    break;
                case 11:                // Back/Bottom
                    af = BACK | BOTTOM;
                    vec.i = 1;          vec.j = 0;          vec.k = 0;
                    p.x = -tx;          p.y = -ty;          p.z = cam->yon;
                    maxt = tx*2;
                    break;
            }
        }

        //ÄÄÄ Compute intersection
        dot = (vec DOT tplane.normal);
        if (dot != 0)
        {
            t = - ((tplane.dist + (*((EschVector*)&p) DOT tplane.normal)) / dot);

            if (t < 0 || t > maxt)
                continue;

            //ÄÄÄ Add intersection
            vpt[count].wx = p.x + t*vec.i;
            vpt[count].wy = p.y + t*vec.j;
            vpt[count].wz = p.z + t*vec.k;
            vpt[count].clr = color;
            aflags[count] = af;

            //ÄÄÄ Determine mapping coordinates, if needed
            if (face.flags & ESCH_CAM_TEXTURED)
            {
                vec.i = (vpt[count].wx - tuvpos.x);
                vec.j = (vpt[count].wy - tuvpos.y);
                vec.k = (vpt[count].wz - tuvpos.z);

                u[count] = ::esch_dot(&tuvec,&vec) / ustep;
                v[count] = ::esch_dot(&tvvec,&vec) / vstep;
            }
            else
            {
                u[count] =
                v[count] = 0;
            }

            count++;
        }
    }

    if (count <= 0)
    {
        ec.pop();
        return;
    }

    assertMyth("EschPlaneDraw::draw() failed to find at least 3 intersections",
               count >= 3);

//ÄÄÄ Ensure mapping coordinates in best possible UV range...
    if (face.flags & ESCH_CAM_TEXTURED)
    {
        tx = u[0];
        ty = v[0];
        for(i=1; i < count; i++)
        {
            if (u[i] < tx)
                tx = u[i];
            if (v[i] < ty)
                ty = v[i];
        }

        tx = (float)floor(tx);
        ty = (float)floor(ty);

        for(i=0; i < count; i++)
        {
            u[i] -= tx;
            v[i] -= ty;
        }
    }

//ÄÄÄ Build n-gon based on adjacency bits
    ngon[0] = 0;
    af = aflags[0];

    for(i=1; i < count; i++)
    {
        for(j=1; j < count; j++)
        {
            if (af & aflags[j])
            {
                ngon[i] = j;
                af = aflags[j];
                aflags[j] = 0;
                break;
            }
        }
    }

//ÄÄÄ Break into smaller triangles...

//ÄÄÄ Light
    if ((level & (ESCH_CAM_SHADE_FLAT|ESCH_CAM_SHADE_SMOOTH))
        && EschCurrent->lights)
    {
        EschLight *lights = EschCurrent->lights;

        lights->setup(NULL);

        //ÄÄÄ Shade verticies
        int revnormal = !(level & ESCH_FACE_ONESIDED);
        EschVertex  vtx;
        vtx.normal = plane.normal;

        for(i=0; i < count; i++)
        {
            vpt[i].shade = 0;

            ((EschPoint*)&vpt[i])->transform(&cam->eye, &vtx);

            if (level & ESCH_CAM_SHADE_SPECULAR)
            {
                lights->hishine(&vtx, (VngoPoint*)&vpt[i], revnormal);
            }
            else
            {
                lights->shine(&vtx, (VngoPoint*)&vpt[i], revnormal);
            }
        }
    }
    else
    {
        for(i=0; i < count; i++)
           vpt[i].shade = mp;
    }

//ÄÄÄ Draw faces from n-gon
    for(i=1; i < count-1; i++)
    {
        face.a     = ngon[0];
        face.u[0]  = u[face.a];
        face.v[0]  = v[face.a];
        face.b     = ngon[i];
        face.u[1]  = u[face.b];
        face.v[1]  = v[face.b];
        face.c     = ngon[i+1];
        face.u[2]  = u[face.c];
        face.v[2]  = v[face.c];

        esch_clipdraw_face(0, 0);
    }

//ÄÄÄ Cleanup
    ec.pop();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - ray                                                      ³
//                                                                          ³
// Performs a ray/plane intersection test.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
float EschPlaneDraw::ray(const EschPoint *pt, const EschVector *v, int coarse) const
{
    assertMyth("EschPlaneDraw::ray needs point and vector",
               pt != 0 && v != 0);

    return plane.ray(pt,v);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - hit                                                      ³
//                                                                          ³
// Performs a sphere/plane intersection test.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschPlaneDraw::hit(const EschPoint *pt, const float r, int coarse) const
{
    assertMyth("EschPlaneDraw::hit needs point and radius",
               pt != 0 && r >= 0);

    float dist = plane.distance(pt);

    return (dist >= -r && dist <= r) ? 1 : 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - animate                                                  ³
//                                                                          ³
// Animates the texture.                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPlaneDraw::animate()
{
    if (!txt)
        return;

    if (!(txt->flags & ESCH_TXT_SKIPANIMATE))
        txt->animate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - release                                                  ³
//                                                                          ³
// Releases the PlaneDraw data.                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPlaneDraw::release()
{
    if (flags & ESCH_DRW_OWNSDATA)
    {
        delete txt;
    }
    txt=0;

    flags &= ~ESCH_DRW_OWNSDATA;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - set_plane                                                ³
//                                                                          ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPlaneDraw::set_plane(const EschPlane &pln)
{
    plane = pln;
    plane.normalize();
}

void EschPlaneDraw::set_plane(float ia, float ib, float ic, float id)
{
    plane.normal.i = ia;
    plane.normal.j = ib;
    plane.normal.k = ic;
    plane.dist = id;
    plane.normalize();
}

void EschPlaneDraw::set_plane(float ia, float ib, float ic,
                              float ix, float iy, float iz)
{
    plane.normal.i = ia;
    plane.normal.j = ib;
    plane.normal.k = ic;
    plane.normal.normalize();

    plane.dist = -(ia*ix + ib*iy + ic*iz);
}

void EschPlaneDraw::set_plane(const EschVector &v1,
                              const EschVector &v2,
                              const EschPoint &pos)
{
    plane.normal = v1 CROSS v2;
    plane.normal.normalize();

    plane.dist = -(plane.normal.i*pos.x
                    + plane.normal.j*pos.y
                    + plane.normal.k*pos.z);

    uvec = v1;
    vvec = v2;
    uvpos = pos;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - set_mapping                                              ³
//                                                                          ³
// Sets the mapping parameters for texturing.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPlaneDraw::set_mapping(const EschVector &_uvec,
                                const EschVector &_vvec,
                                const EschPoint &_uvpos,
                                float us, float vs)
{
    uvec = _uvec;
    uvec.normalize();

    vvec = _vvec;
    vvec.normalize();

    uvpos = _uvpos;

    ustep = us;
    vstep = vs;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlaneDraw - set_texture                                              ³
//                                                                          ³
// Attaches a texture to the PlaneDraw.                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPlaneDraw::set_texture(EschTexture *t)
{
    if (!t)
        return;

    release();

    txt = t;
}

//°±² End of module - esplndrw.cpp ²±°
