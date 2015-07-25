//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// Created by Tim Little & Chuck Walbourn
//
// esmetabx.cpp
//
// Contains the code for the EschMetabox class.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschMetabox - Constructor                                                �
//���������������������������������������������������������������������������
EschMetabox::EschMetabox() :
    EschDrawable(ESCH_DRWT_METABOX),
    alpha_level(255)
{
    check_workspace();
    for(int i=0; i < (sizeof(txt) / sizeof(EschTexture*)); i++)
        txt[i];

    u[0] = Flx16(0.01);
    u[1] = Flx16(0.90);
    u[2] = Flx16(0.01);
    u[3] = Flx16(0.90);

    v[0] = Flx16(0.01);
    v[1] = Flx16(0.01);
    v[2] = Flx16(0.90);
    v[3] = Flx16(0.90);
}


//�������������������������������������������������������������������������Ŀ
// EschMetabox - Destructor                                                 �
//���������������������������������������������������������������������������
EschMetabox::~EschMetabox()
{
    release();
}


//�������������������������������������������������������������������������Ŀ
//                          ��� Protected ���                               �
// EschMetabox - check_workspace                                            �
//���������������������������������������������������������������������������
void EschMetabox::check_workspace()
{
    assertMyth("EschMetabox needs Escher initialized",EschSysInstance != 0);

    //�� Update wspace_mbytes diags
    dword needed = (sizeof(VngoPoint)+sizeof(dword)+(sizeof(EschVertex)))*8;

    assertMyth("EschMetabox needs more workspace than is available",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschMetabox - operator =                                                 �
//���������������������������������������������������������������������������
const EschMetabox &EschMetabox::operator = (const EschMetabox &that)
{
    if (this != &that)
    {
        release();

        EschDrawable::operator = (that);

        world = that.world;
        memcpy(corner,that.corner,sizeof(corner));
        memcpy(color,that.color,sizeof(color));
        memcpy(txt,that.txt,sizeof(txt));
        memcpy(u,that.u,sizeof(u));
        memcpy(v,that.v,sizeof(v));
    }
    return *this;
}


//�������������������������������������������������������������������������Ŀ
// EschMetabox - draw                                                       �
//���������������������������������������������������������������������������
void EschMetabox::draw()
{
    ulong           i;
    dword           cflags;
    dword           level;
    dword           *vflags;
    VngoPoint       *vpt;
    EschCamera      *cam;
    EschFace        face;
    EschFrameRef    frame(0);

//��� Clear arena
    ivory_arena_clear(EschSysInstance->wspace);
    
//��� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschMetabox::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschMetabox::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    cflags = cam->flags;
    level = cflags & limits;

    assertMyth("EschMetabox::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    int mp = cam->vport->vbuff.pal->shd_pal->mid_point;

//������������������������������������������������������������� Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = new (EschSysInstance->wspace) EschVertex[8];
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 8);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[8];
    ec.faces = &face;
    ec.fflags = 0;
    ec.txts = txt;
    ec.push();

//���������������������������������������������������������������� Misc Setup
    //��� Create local->world->eye transform
    world.orient.concat(&cam->eye.iorient,&frame.orient);
    cam->eye.orient.concat(&world.iorient,&frame.iorient);

    face.flags = (limits & (ESCH_FACE_WIRE
                            | ESCH_FACE_SOLID
                            | ESCH_FACE_ONESIDED
                            | ESCH_FACE_TEXTURED))
                 | ESCH_FACE_ABLINE
                 | ESCH_FACE_BCLINE
                 | ESCH_FACE_CALINE;

    if ((limits & ESCH_FACE_ALPHA) && alpha_level < 255)
    {
        face.flags |= ESCH_FACE_ALPHA;
        face.set_alpha(alpha_level);
    }

    dword ctrlfl = ESCH_CDF_CLIP | ((cam->flags & face.flags & ESCH_FACE_ONESIDED)
                                    ? ESCH_CDF_BFCULL : 0);

//��� Transform and light (if possible) the verticies
    for(i=0; i < 8; i++)
    {
        ec.verts[i].x = corner[i].x;
        ec.verts[i].y = corner[i].y;
        ec.verts[i].z = corner[i].z;

        vflags[i] = ESCH_VVERT_TRANSFORMED;
        ec.verts[i].transform(&frame,(EschPoint*)&vpt[i]);
        vpt[i].shade=mp;
    }

//���������������������������������������������������������� Setup/Draw Faces
    if (flags & ESCH_MBOX_TOP)
    {
        if (txt[ESCH_MBOX_FACE_TOP])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 1;

        face.a     = 0;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 3;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 1;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_TOP];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 3;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 2;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 1;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_TOP];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_BOTTOM)
    {
        if (txt[ESCH_MBOX_FACE_BOTTOM])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 2;

        face.a     = 5;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 6;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 4;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_BOTTOM];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 6;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 7;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 4;
        face.u[2]  = u[2];
        face.v[2]  = v[2];
        
        vpt[face.a].clr = color[ESCH_MBOX_FACE_BOTTOM];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_FRONT)
    {
        if (txt[ESCH_MBOX_FACE_FRONT])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 3;

        face.a     = 0;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 1;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 4;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_FRONT];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 1;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 5;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 4;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_FRONT];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_BACK)
    {
        if (txt[ESCH_MBOX_FACE_BACK])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 4;

        face.a     = 2;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 3;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 6;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_BACK];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 3;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 7;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 6;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_BACK];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_LEFT)
    {
        if (txt[ESCH_MBOX_FACE_LEFT])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 5;

        face.a     = 3;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 0;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 7;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_LEFT];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 0;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 4;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 7;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_LEFT];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_RIGHT)
    {
        if (txt[ESCH_MBOX_FACE_RIGHT])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 6;

        face.a     = 1;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 2;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 5;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_RIGHT];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 2;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 6;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 5;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_RIGHT];
        esch_clipdraw_face(0,ctrlfl);
    }

//��� Pop drawing context
    ec.pop();
}


//�������������������������������������������������������������������������Ŀ
// EschMetabox - animate                                                    �
//���������������������������������������������������������������������������
void EschMetabox::animate()
{
    for(int i=0; i < 6; i++)
    {
        if (txt[i] && !(txt[i]->flags & ESCH_TXT_SKIPANIMATE))
            txt[i]->animate();
    }
}


//�������������������������������������������������������������������������Ŀ
// EschMetabox - release                                                    �
//���������������������������������������������������������������������������
void EschMetabox::release()
{
    for(int i=0; i < (sizeof(txt) / sizeof(EschTexture*)); i++)
    {
        if (!txt[i])
            continue;

        if (flags & ESCH_DRW_OWNSDATA)
            delete txt[i];

        txt[i]=0;
    }
    flags &= ~ESCH_DRW_OWNSDATA;
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschMetabox - set_top                                                    �
//���������������������������������������������������������������������������
void EschMetabox::set_top(Flx16 ii, Flx16 ij, Flx16 ik, dword update)
{
    EschVector v(ii,ij,ik);
    v.normalize();

    EschVector  right;

    world.ortho_count=0;

//��� Create right vector 
    right = v CROSS world.dir;

//��� Fill in matrix for ortho rotation

    //��� Transform
    world.orient.mtx[ESCH_MTX_A].flx = right.i.flx;
    world.orient.mtx[ESCH_MTX_B].flx = right.j.flx;
    world.orient.mtx[ESCH_MTX_C].flx = right.k.flx;

    world.orient.mtx[ESCH_MTX_D].flx = v.i.flx;
    world.orient.mtx[ESCH_MTX_E].flx = v.j.flx;
    world.orient.mtx[ESCH_MTX_F].flx = v.k.flx;

    //��� Inverse Transform
    if (update & ESCH_UPD_INVERSE)
        world.compute_inverse();
}


//�������������������������������������������������������������������������Ŀ
// EschMetabox - set_direction                                              �
//���������������������������������������������������������������������������
void EschMetabox::set_direction(Flx16 ii, Flx16 ij, Flx16 ik, dword update)
{
    world.dir.i = ii;
    world.dir.j = ij;
    world.dir.k = ik;
    world.dir.normalize();

    EschVector  right;
    EschVector  top(world.orient.mtx[ESCH_MTX_D],
                    world.orient.mtx[ESCH_MTX_E],
                    world.orient.mtx[ESCH_MTX_F]);

    world.ortho_count=0;

//��� Create right vector 
    right = top CROSS world.dir;

//��� Fill in matrix for ortho rotation

    //��� Transform
    world.orient.mtx[ESCH_MTX_A].flx = right.i.flx;
    world.orient.mtx[ESCH_MTX_B].flx = right.j.flx;
    world.orient.mtx[ESCH_MTX_C].flx = right.k.flx;

    world.orient.mtx[ESCH_MTX_G] = world.dir.i;
    world.orient.mtx[ESCH_MTX_H] = world.dir.j;
    world.orient.mtx[ESCH_MTX_I] = world.dir.k;

    //��� Inverse Transform
    if (update & ESCH_UPD_INVERSE)
        world.compute_inverse();
}


//�������������������������������������������������������������������������Ŀ
// EschMetabox - set_color                                                  �
//���������������������������������������������������������������������������
void EschMetabox::set_color(dword clr, int face)
{
    if (face > 5)
        return;

    if (face >= 0)
    {
        color[face] = clr;
    }
    else
    {
        for(int i=0; i < 6; i++)
            color[i] = clr;
    }
}


//�������������������������������������������������������������������������Ŀ
// EschMetabox - set_texture                                                �
//���������������������������������������������������������������������������
void EschMetabox::set_texture(EschTexture *t, int face)
{
    if (face > 5)
        return;

    if (face >= 0)
    {
        txt[face] = t;
    }
    else
    {
        for(int i=0; i < 6; i++)
        {
            txt[i] = t;
        }
    }
}


//�������������������������������������������������������������������������Ŀ
// EschMetabox - create_cube                                                �
//���������������������������������������������������������������������������
void EschMetabox::create_cube(Flx16 size)
{
    flags |= ESCH_MBOX_TOP   
             | ESCH_MBOX_BOTTOM
             | ESCH_MBOX_FRONT 
             | ESCH_MBOX_BACK  
             | ESCH_MBOX_LEFT  
             | ESCH_MBOX_RIGHT;

    Flx16 s = Flx16(size.flx>>1,0);

    corner[0].x = -s;
    corner[0].y = s;
    corner[0].z = -s;

    corner[1].x = s;
    corner[1].y = s;
    corner[1].z = -s;

    corner[2].x = s;
    corner[2].y = s;
    corner[2].z = s;

    corner[3].x = -s;
    corner[3].y = s;
    corner[3].z = s;

    corner[4].x = -s;
    corner[4].y = -s;
    corner[4].z = -s;

    corner[5].x = s;
    corner[5].y = -s;
    corner[5].z = -s;

    corner[6].x = s;
    corner[6].y = -s;
    corner[6].z = s;

    corner[7].x = -s;
    corner[7].y = -s;
    corner[7].z = s;
}

//��� End of module - esmetabx.cpp ���
