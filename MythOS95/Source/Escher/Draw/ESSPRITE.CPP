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
// essprite.cpp
//
// Contains the code for the EschSprite class which implements
// a 2D bitmap drawable.
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

#define max(a,b)  (((a) > (b)) ? (a) : (b))

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern EschPoint EschTempPoint;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSprite - Destructor                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschSprite::~EschSprite()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSprite - operator =                                                  ³
//                                                                          ³
// Copies the data from another sprite.                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
const EschSprite &EschSprite::operator = (const EschSprite &s)
{
    if (this != &s)
    {
        release();

        EschDrawable::operator = (s);

        alpha_level = s.alpha_level;
        txt = s.txt;
        pos = s.pos;
        width = s.width;
        height = s.height;
    }
    return *this;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSprite - draw                                                        ³
//                                                                          ³
// Draws the sprite using the current drawing context.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschSprite::draw()
{
    int             i;
    float           _width, _height;
    dword           level;
    dword           ctrlfl;
    int             mp;
    EschCamera      *cam;
    EschLight       *lights;
    dword           cflags;
    float           yon, hither;
    float           tx, ty;
    float           t1, t2;
    float           c, s;
    float           wh, hh, xc, yc, xs, ys;
    float           r;
    EschFrameRef    world(0);

    static EschFace faces[2] = { EschFace( 0,
                                           0, 1, 2,
                                           1,
                                           float(0.01), float(0.99), float(0.99),
                                           float(0.99), float(0.99), float(0.01),
                                           0, 0, 0, 0 ),
                                 EschFace( 0,
                                           0, 2, 3,
                                           1,
                                           float(0.01), float(0.99), float(0.01),
                                           float(0.99), float(0.01), float(0.01),
                                           0, 0, 0, 0 ) };

    if (!txt)
        return;

    assertMyth("EschSprite::draw needs valid scale",
               scale > 0);


    _width = width * scale;
    _height = height * scale;

    assertMyth("EschSprite::draw needs valid size",
               _width > 0 && _height > 0);

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschSprite::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam = EschCurrent->camera;

    cflags = cam->flags;

    assertMyth("EschSprite::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    yon = cam->yon;
    hither = cam->hither;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Transform
    //ÄÄÄ Transform into copy of point
    if (flags & ESCH_SPRITE_INFINITE)
    {
        //ÄÄÄ If no depth, only account for rotation

        ((EschVector*)&pos)->transform(&cam->eye.iorient,
                                       (EschVector*)&EschTempPoint);

        // Left/right/top/bottom clipping
        if (cflags & ESCH_CAM_ORTHO)
        {
            tx = cam->xsize;
            ty = cam->ysize;
        }
        else
        {
            tx = EschTempPoint.z * cam->xsize;
            ty = EschTempPoint.z * cam->ysize;
        }

        if (EschTempPoint.z > 0)
        {
            r = max(_width,_height) * cam->radius_factor;

            // Check for fully invisible against left/right/top/bottom
            if ( ((EschTempPoint.x + r) < -tx)
                 || ((EschTempPoint.x - r) > tx)
                 || ((EschTempPoint.y + r) < -ty)
                 || ((EschTempPoint.y - r) > ty) )
                return;

            ctrlfl = ESCH_CDF_INFINITEZ | ESCH_CDF_MUSTTXT;
        }
        else ctrlfl = ESCH_CDF_CLIP | ESCH_CDF_INFINITEZ | ESCH_CDF_MUSTTXT;
    }
    else
    {
        //ÄÄÄ Otherwise, perform standard transform and clip of sprite
        //ÄÄÄ position

        pos.transform(&cam->eye.iorient,&EschTempPoint);

        // Near/far clipping
        if (EschTempPoint.z > yon
            || EschTempPoint.z < hither)
            return;

        // Left/right/top/bottom clipping
        if (cflags & ESCH_CAM_ORTHO)
        {
            tx = cam->xsize;
            ty = cam->ysize;
        }
        else
        {
            tx = EschTempPoint.z * cam->xsize;
            ty = EschTempPoint.z * cam->ysize;
        }

        if (EschTempPoint.z > 0)
        {
            r = max(_width,_height) * cam->radius_factor;

            // Check for fully invisible against left/right/top/bottom
            if ( ((EschTempPoint.x + r) < -tx)
                 || ((EschTempPoint.x - r) > tx)
                 || ((EschTempPoint.y + r) < -ty)
                 || ((EschTempPoint.y - r) > ty) )
                return;

            ctrlfl = ESCH_CDF_MUSTTXT;
        }
        else ctrlfl = ESCH_CDF_CLIP | ESCH_CDF_MUSTTXT;
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup
    level = cflags & limits;

    assertMyth("EschSprite::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    mp = cam->vport->vbuff.pal->shd_pal->mid_point;

    //ÄÄÄ Clear arena
    ivory_arena_clear(EschSysInstance->wspace);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;

    ec.vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,
                                           sizeof(dword) * 4);
    assertMyth("EschSprite::draw failed to allocate needed workspace",
               ec.vflags != 0);

    ec.vpoints = (VngoPoint*)ivory_arena_alloc(EschSysInstance->wspace,
                                               sizeof(VngoPoint) * 4);
    assertMyth("EschSprite::draw failed to allocate needed workspace",
               ec.vpoints != 0);

    ec.faces = faces;

    ec.fflags = 0;
    ec.txts = (EschTexture**) &txt;
    ec.push();

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup Rectangle
//ÄÄÄ Create 4 (transformed) verticies in view space based on transformed
//ÄÄÄ center point, scaled width/height, camera transform, and rotation
//ÄÄÄ value.
//
// 3-----2
// | A   |
// |  *  |
// |   B |
// 0-----1

#if 1
    //ÄÄÄ Determine rotation
    EschVector top(0,1,0);
    top.transform(&cam->eye.iorient);
    if (rotation != 0.0f)
        top.rotatez(rotation);

    if (top.i > -0.0001f && top.i < 0.0001f
        && top.j > -0.0001f && top.j < 0.0001f)
    {
        top.i = 0;
        top.j = (top.k < 0) ? -1.0f : 1.0f;
        top.k = 0;
    }
    else
    {
        top.k=0;
        top.normalize();
    }

    // Get cos with DOT vs. 0, 1, 0
    c = top.j;
    s = esch_sin((top.i > 0) ? -esch_acos(c) : esch_acos(c));

    //ÄÄÄ Apply rotation
    wh = _width / 2;
    hh = _height / 2;

    xc = wh*c;
    yc = hh*c;

    xs = wh*s;
    ys = hh*s;

    t1 = EschTempPoint.x - xc + ys;
    t2 = EschTempPoint.y - xs - yc;
    if (!(ctrlfl & ESCH_CDF_CLIP))
    {
        if ( (t1 < -tx) || (t1 > tx) || (t2 < -ty) || (t2 > ty))
            ctrlfl |= ESCH_CDF_CLIP;
    }
    ((EschPoint*)(&ec.vpoints[0]))->x = t1;
    ((EschPoint*)(&ec.vpoints[0]))->y = t2;
    ((EschPoint*)(&ec.vpoints[0]))->z = EschTempPoint.z;

    t1 = EschTempPoint.x + xc + ys;
    t2 = EschTempPoint.y + xs - yc;
    if (!(ctrlfl & ESCH_CDF_CLIP))
    {
        if ( (t1 < -tx) || (t1 > tx) || (t2 < -ty) || (t2 > ty))
            ctrlfl |= ESCH_CDF_CLIP;
    }
    ((EschPoint*)(&ec.vpoints[1]))->x = t1;
    ((EschPoint*)(&ec.vpoints[1]))->y = t2;
    ((EschPoint*)(&ec.vpoints[1]))->z = EschTempPoint.z;

    t1 = EschTempPoint.x + xc - ys;
    t2 = EschTempPoint.y + xs + yc;
    if (!(ctrlfl & ESCH_CDF_CLIP))
    {
        if ( (t1 < -tx) || (t1 > tx) || (t2 < -ty) || (t2 > ty))
            ctrlfl |= ESCH_CDF_CLIP;
    }
    ((EschPoint*)(&ec.vpoints[2]))->x = t1;
    ((EschPoint*)(&ec.vpoints[2]))->y = t2;
    ((EschPoint*)(&ec.vpoints[2]))->z = EschTempPoint.z;

    t1 = EschTempPoint.x - xc - ys;
    t2 = EschTempPoint.y - xs + yc;
    if (!(ctrlfl & ESCH_CDF_CLIP))
    {
        if ( (t1 < -tx) || (t1 > tx) || (t2 < -ty) || (t2 > ty))
            ctrlfl |= ESCH_CDF_CLIP;
    }
    ((EschPoint*)(&ec.vpoints[3]))->x = t1;
    ((EschPoint*)(&ec.vpoints[3]))->y = t2;
    ((EschPoint*)(&ec.vpoints[3]))->z = EschTempPoint.z;
#else
    ti = cam->top.i;
    tj = cam->top.j;

    c = tj / esch_sqrt(ti*ti + tj*tj);
    s = esch_sqrt(1.0f - (c*c));
    if (ti < 0)
        s = -s;

    wh = _width / 2;
    hh = _height / 2;

    xc = wh*c;
    yc = hh*c;

    xs = wh*s;
    ys = hh*s;

    EschPoint temp(-xc+ys, -xs-yc, 0);
    if (rotation != 0)
        temp.rotatez (rotation);
    if (!(ctrlfl & ESCH_CDF_CLIP))
    {
        if ( ((EschTempPoint.x - temp.x) < -tx)
             || ((EschTempPoint.x + temp.x) > tx)
             || ((EschTempPoint.y - temp.y) < -ty)
             || ((EschTempPoint.y + temp.y) > ty) )
            ctrlfl |= ESCH_CDF_CLIP;
    }
    ((EschPoint*)(&ec.vpoints[0]))->x = EschTempPoint.x + temp.x;
    ((EschPoint*)(&ec.vpoints[0]))->y = EschTempPoint.y + temp.y;
    ((EschPoint*)(&ec.vpoints[0]))->z = EschTempPoint.z;

    temp.x = xc+ys;
    temp.y = xs-yc;
    if (rotation != 0)
        temp.rotatez (rotation);
    if (!(ctrlfl & ESCH_CDF_CLIP))
    {
        if ( ((EschTempPoint.x - temp.x) < -tx)
             || ((EschTempPoint.x + temp.x) > tx)
             || ((EschTempPoint.y - temp.y) < -ty)
             || ((EschTempPoint.y + temp.y) > ty) )
            ctrlfl |= ESCH_CDF_CLIP;
    }
    ((EschPoint*)(&ec.vpoints[1]))->x = EschTempPoint.x + temp.x;
    ((EschPoint*)(&ec.vpoints[1]))->y = EschTempPoint.y + temp.y;
    ((EschPoint*)(&ec.vpoints[1]))->z = EschTempPoint.z;

    temp.x = xc - ys;
    temp.y = xs + yc;
    if (rotation != 0)
        temp.rotatez (rotation);
    if (!(ctrlfl & ESCH_CDF_CLIP))
    {
        if ( ((EschTempPoint.x - temp.x) < -tx)
             || ((EschTempPoint.x + temp.x) > tx)
             || ((EschTempPoint.y - temp.y) < -ty)
             || ((EschTempPoint.y + temp.y) > ty) )
            ctrlfl |= ESCH_CDF_CLIP;
    }
    ((EschPoint*)(&ec.vpoints[2]))->x = EschTempPoint.x + temp.x;
    ((EschPoint*)(&ec.vpoints[2]))->y = EschTempPoint.y + temp.y;
    ((EschPoint*)(&ec.vpoints[2]))->z = EschTempPoint.z;

    temp.x = -xc - ys;
    temp.y = -xs + yc;
    if (rotation != 0)
        temp.rotatez (rotation);
    if (!(ctrlfl & ESCH_CDF_CLIP))
    {
        if ( ((EschTempPoint.x - temp.x) < -tx)
             || ((EschTempPoint.x + temp.x) > tx)
             || ((EschTempPoint.y - temp.y) < -ty)
             || ((EschTempPoint.y + temp.y) > ty) )
            ctrlfl |= ESCH_CDF_CLIP;
    }
    ((EschPoint*)(&ec.vpoints[3]))->x = EschTempPoint.x + temp.x;
    ((EschPoint*)(&ec.vpoints[3]))->y = EschTempPoint.y + temp.y;
    ((EschPoint*)(&ec.vpoints[3]))->z = EschTempPoint.z;
#endif

//ÄÄÄ Create 2 faces
    faces[0].flags = (limits & (ESCH_FACE_WIRE
                                | ESCH_FACE_SOLID
                                | ESCH_FACE_FLAT
                                | ESCH_FACE_TEXTURED))
                                | ESCH_FACE_ABLINE
                                | ESCH_FACE_BCLINE
                                | ESCH_FACE_CALINE;

    if ((limits & ESCH_FACE_ALPHA) && alpha_level < 255)
    {
        faces[0].flags |= ESCH_FACE_ALPHA;
        faces[0].set_alpha(alpha_level);
        faces[1].set_alpha(alpha_level);
    }
    faces[1].flags = faces[0].flags;

//ÄÄÄ Handle shading
    ec.vpoints[0].clr = 0;
    ec.vpoints[0].shade = mp;

    lights = EschCurrent->lights;
    if ((level & ESCH_CAM_SHADE_FLAT)
        && !(flags & ESCH_SPRITE_INFINITE)
        && lights)
    {
        world.reset();
        world.set_position(&pos);
        lights->setup(&world);

        EschVertex  vtx;

        if (cam->flags & ESCH_CAM_MODELSPACE)
        {
            vtx.x = 0; vtx.y = 0; vtx.z = 0;
            vtx.normal.i = 0;
            vtx.normal.j = 0;
            vtx.normal.k = -1;
        }
        else
        {
            vtx.x = pos.x;
            vtx.y = pos.y;
            vtx.z = pos.z;
            vtx.normal = -cam->eye.dir;
        }

        ec.vpoints[0].shade = 0;
        lights->shine(&vtx,&ec.vpoints[0],1);
    }

    for(i=0; i < 4; i++)
    {
        ec.vpoints[i].clr = ec.vpoints[0].clr;
        ec.vpoints[i].shade = ec.vpoints[0].shade;
    }

//ÄÄÄ Draw Faces
    esch_clipdraw_face(0,ctrlfl);
    esch_clipdraw_face(1,ctrlfl);

//ÄÄÄ Pop drawing context
    ec.pop();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSprite - get_extents                                                 ³
//                                                                          ³
// Returns the extent of the sprite in world coords.                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschSprite::get_extents(EschSphereExtents *sp) const
{
    if (flags & ESCH_SPRITE_INFINITE)
        return -1;

    assertMyth("EschSprite::get_extents needs return sphere extents",
               sp != 0);

    assertMyth("EschSprite::get_extents needs valid size",
               width > 0 && height > 0);

    sp->center = pos;
    sp->radius = max(width,height);

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSprite - animate                                                     ³
//                                                                          ³
// Animates the texture.                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschSprite::animate()
{
    if (!txt)
        return;

    if (!(txt->flags & ESCH_TXT_SKIPANIMATE))
        txt->animate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSprite - release                                                     ³
//                                                                          ³
// Releases the sprite data.                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschSprite::release()
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
// EschSprite - attach                                                      ³
//                                                                          ³
// Attaches a texture as a sprite.                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschSprite::attach(EschTexture *t)
{
    if (!t)
        return;

    release();

    txt = t;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSprite - create                                                      ³
//                                                                          ³
// Creates a sprite from a (appropriate) bitmap.                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschSprite::create(XFBitmap *bm, float w, float h,
                                    int trans, VngoPal *pal)
{
//ÄÄÄ Verify valid input
    if (w <= 0 || h <= 0)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ Prepare sprite
    release();

    width=w;
    height=h;

//ÄÄÄ Create texture
    flags |= ESCH_DRW_OWNSDATA;

    txt = new EschStaticTexture;
    if (!txt)
        return ESCH_ERR_NOMEMORY;

    esch_error_codes err=((EschStaticTexture*)txt)->create(bm,trans,pal);
    if (err)
        return err;

    return ESCH_ERR_NONE;
}

//°±² End of module - essprite.cpp ²±°

