//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Tim Little & Chuck Walbourn
//
// essprite.cpp
//
// Contains the code for the EschSprite class which implements
// a 2D bitmap drawable.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define max(a,b)  (((a) > (b)) ? (a) : (b))

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern EschPoint EschTempPoint;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSprite - Destructor                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschSprite::~EschSprite()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSprite - operator =                                                  �
//                                                                          �
// Copies the data from another sprite.                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSprite - draw                                                        �
//                                                                          �
// Draws the sprite using the current drawing context.                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

//陳� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschSprite::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam = EschCurrent->camera;

    cflags = cam->flags;

    assertMyth("EschSprite::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    yon = cam->yon;
    hither = cam->hither;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Transform
    //陳� Transform into copy of point
    if (flags & ESCH_SPRITE_INFINITE)
    {
        //陳� If no depth, only account for rotation

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
        //陳� Otherwise, perform standard transform and clip of sprite
        //陳� position

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

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Setup
    level = cflags & limits;

    assertMyth("EschSprite::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    mp = cam->vport->vbuff.pal->shd_pal->mid_point;

    //陳� Clear arena
    ivory_arena_clear(EschSysInstance->wspace);

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Setup Context
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

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Setup Rectangle
//陳� Create 4 (transformed) verticies in view space based on transformed
//陳� center point, scaled width/height, camera transform, and rotation
//陳� value.
//
// 3-----2
// | A   |
// |  *  |
// |   B |
// 0-----1

#if 1
    //陳� Determine rotation
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

    //陳� Apply rotation
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

//陳� Create 2 faces
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

//陳� Handle shading
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

//陳� Draw Faces
    esch_clipdraw_face(0,ctrlfl);
    esch_clipdraw_face(1,ctrlfl);

//陳� Pop drawing context
    ec.pop();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSprite - get_extents                                                 �
//                                                                          �
// Returns the extent of the sprite in world coords.                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSprite - animate                                                     �
//                                                                          �
// Animates the texture.                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschSprite::animate()
{
    if (!txt)
        return;

    if (!(txt->flags & ESCH_TXT_SKIPANIMATE))
        txt->animate();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSprite - release                                                     �
//                                                                          �
// Releases the sprite data.                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschSprite::release()
{
    if (flags & ESCH_DRW_OWNSDATA)
    {
        delete txt;
    }
    txt=0;

    flags &= ~ESCH_DRW_OWNSDATA;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSprite - attach                                                      �
//                                                                          �
// Attaches a texture as a sprite.                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschSprite::attach(EschTexture *t)
{
    if (!t)
        return;

    release();

    txt = t;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSprite - create                                                      �
//                                                                          �
// Creates a sprite from a (appropriate) bitmap.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschSprite::create(XFBitmap *bm, float w, float h,
                                    int trans, VngoPal *pal)
{
//陳� Verify valid input
    if (w <= 0 || h <= 0)
        return ESCH_ERR_INVALIDPARMS;

//陳� Prepare sprite
    release();

    width=w;
    height=h;

//陳� Create texture
    flags |= ESCH_DRW_OWNSDATA;

    txt = new EschStaticTexture;
    if (!txt)
        return ESCH_ERR_NOMEMORY;

    esch_error_codes err=((EschStaticTexture*)txt)->create(bm,trans,pal);
    if (err)
        return err;

    return ESCH_ERR_NONE;
}

//葦� End of module - essprite.cpp 憶�

