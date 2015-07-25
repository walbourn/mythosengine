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
//ùùùùùùùùùùùCopyrightù(c)ù1994-1997ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùù Microsoft Windows '95 Version ùùùùùùùùùùùùùùùùùùùùùùù
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
// Created by Tim Little & Chuck Walbourn
//
// esmetabx.cpp
//
// Contains the code for the EschMetabox class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

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

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - Constructor                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschMetabox::EschMetabox() :
    EschDrawable(ESCH_DRWT_METABOX),
    alpha_level(255)
{
    check_workspace();
    for(int i=0; i < (sizeof(txt) / sizeof(EschTexture*)); i++)
        txt[i];

    u[0] = float(0.01);
    u[1] = float(0.90);
    u[2] = float(0.01);
    u[3] = float(0.90);

    v[0] = float(0.01);
    v[1] = float(0.01);
    v[2] = float(0.90);
    v[3] = float(0.90);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - Destructor                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschMetabox::~EschMetabox()
{
    release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                          °°° Protected °°°                               ³
// EschMetabox - check_workspace                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschMetabox::check_workspace()
{
    assertMyth("EschMetabox needs Escher initialized",EschSysInstance != 0);

    //ÄÄ Update wspace_mbytes diags
    dword needed = (sizeof(VngoPoint)+sizeof(dword)+(sizeof(EschVertex)))*8;

    assertMyth("EschMetabox needs more workspace than is available",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - operator =                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - draw                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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

//ÄÄÄ Clear arena
    ivory_arena_clear(EschSysInstance->wspace);
    
//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = new (EschSysInstance->wspace) EschVertex[8];
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 8);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[8];
    ec.faces = &face;
    ec.fflags = 0;
    ec.txts = txt;
    ec.push();

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Misc Setup
    //ÄÄÄ Create local->world->eye transform
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

//ÄÄÄ Transform and light (if possible) the verticies
    for(i=0; i < 8; i++)
    {
        ec.verts[i].x = corner[i].x;
        ec.verts[i].y = corner[i].y;
        ec.verts[i].z = corner[i].z;

        vflags[i] = ESCH_VVERT_TRANSFORMED;
        ec.verts[i].transform(&frame,(EschPoint*)(&vpt[i]));
        vpt[i].shade=mp;
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup/Draw Faces
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

//ÄÄÄ Pop drawing context
    ec.pop();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - animate                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschMetabox::animate()
{
    for(int i=0; i < 6; i++)
    {
        if (txt[i] && !(txt[i]->flags & ESCH_TXT_SKIPANIMATE))
            txt[i]->animate();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - release                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - set_top                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschMetabox::set_top(float ii, float ij, float ik, dword update)
{
    EschVector v(ii,ij,ik);
    v.normalize();

    EschVector  right;

    world.ortho_count=0;

//ÄÄÄ Create right vector 
    right = v CROSS world.dir;

//ÄÄÄ Fill in matrix for ortho rotation

    //ÄÄÄ Transform
    world.orient.mtx[ESCH_MTX_A] = right.i;
    world.orient.mtx[ESCH_MTX_B] = right.j;
    world.orient.mtx[ESCH_MTX_C] = right.k;

    world.orient.mtx[ESCH_MTX_D] = v.i;
    world.orient.mtx[ESCH_MTX_E] = v.j;
    world.orient.mtx[ESCH_MTX_F] = v.k;

    //ÄÄÄ Inverse Transform
    if (update & ESCH_UPD_INVERSE)
        world.compute_inverse();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - set_direction                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschMetabox::set_direction(float ii, float ij, float ik, dword update)
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

//ÄÄÄ Create right vector 
    right = top CROSS world.dir;

//ÄÄÄ Fill in matrix for ortho rotation

    //ÄÄÄ Transform
    world.orient.mtx[ESCH_MTX_A] = right.i;
    world.orient.mtx[ESCH_MTX_B] = right.j;
    world.orient.mtx[ESCH_MTX_C] = right.k;

    world.orient.mtx[ESCH_MTX_G] = world.dir.i;
    world.orient.mtx[ESCH_MTX_H] = world.dir.j;
    world.orient.mtx[ESCH_MTX_I] = world.dir.k;

    //ÄÄÄ Inverse Transform
    if (update & ESCH_UPD_INVERSE)
        world.compute_inverse();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - set_color                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - set_texture                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - create_cube                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschMetabox::create_cube(float size)
{
    flags |= ESCH_MBOX_TOP   
             | ESCH_MBOX_BOTTOM
             | ESCH_MBOX_FRONT 
             | ESCH_MBOX_BACK  
             | ESCH_MBOX_LEFT  
             | ESCH_MBOX_RIGHT;

    float s = size / 2;

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

//°±² End of module - esmetabx.cpp ²±°

