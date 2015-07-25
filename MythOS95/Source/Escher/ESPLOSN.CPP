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
//שששששששששששCopyrightש(c)ש1994-1996שbyשCharybdisשEnterprises,שInc.שששששששששש
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
// esplosn.cpp
//
// Contains the code for the EschPlosion class.
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

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschPlosion - Constructor                                                ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
EschPlosion::EschPlosion(Flx16 w, Flx16 h, EschFireTexture *f) :
    EschDrawable(ESCH_DRWT_EXPLOSION),
    fire(f),
    width(w),
    height(h),
    fv(1),
    step(0)
{
    check_workspace();
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
//                          °°° Protected °°°                               ³
// EschPlosion - check_workspace                                            ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void EschPlosion::check_workspace()
{
    assertMyth("EschPlosion needs Escher initialized",EschSysInstance != 0);

    //ִִ Update wspace_mbytes diags
    dword needed = (sizeof(VngoPoint)+sizeof(dword)+(2*sizeof(EschVertex)))*8
                   + sizeof(EschFace)*4;

    assertMyth("EschPlosion needs more workspace than is available",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschPlosion - draw                                                       ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void EschPlosion::draw()
{
    int             i;
    dword           cflags;
    dword           level;
    dword           *vflags;
    VngoPoint       *vpt;
    EschCamera      *cam;
    EschPoint       p;
    EschFrameRef    frame(0);

    assertMyth("EschPlosion::draw needs valid width, height, and fire texture",
               width > 0 && height > 0 && fire != 0);

//ִִִ Clear arena
    ivory_arena_clear(EschSysInstance->wspace);
    
//ִִִ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschPlosion::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschPlosion::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    cflags = cam->flags;
    level = cflags & limits;

    assertMyth("EschPlosion::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    int mp = cam->vport->vbuff.pal->shd_pal->mid_point;

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = new (EschSysInstance->wspace) EschVertex[8];
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 8);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[8];
    ec.faces = new (EschSysInstance->wspace) EschFace[4];
    ec.fflags = 0;
    ec.txts = (EschTexture**) &fire;
    ec.push();

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ Misc Setup
    //ִִִ Create local->world->eye transform
    world.orient.concat(&cam->eye.iorient,&frame.orient);
    cam->eye.orient.concat(&world.iorient,&frame.iorient);

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ Setup Trapezoid
//ִִִ Create 8 verticies
//
// (X/Y plane)                (Y/X plane)
//
// 3-------------------2      7-------------------6
//  \                /         \                /
//   \              /           \              /
//   0\____________/1           4\____________/5
//
//

    Flx16 width_half = Flx16(width.flx >> 1,0);
    Flx16 width_quarter = Flx16(width.flx >> 2,0);

    ec.verts[0].x = -width_quarter;
    ec.verts[0].y = 0;
    ec.verts[0].z = 0;

    ec.verts[1].x = width_quarter;
    ec.verts[1].y = 0;
    ec.verts[1].z = 0;

    ec.verts[2].x = width_half;
    ec.verts[2].y = height;
    ec.verts[2].z = 0;

    ec.verts[3].x = -width_half;
    ec.verts[3].y = height;
    ec.verts[3].z = 0;

    ec.verts[4].x = 0;
    ec.verts[4].y = 0;
    ec.verts[4].z = -width_quarter;

    ec.verts[5].x = 0;
    ec.verts[5].y = 0;
    ec.verts[5].z = width_quarter;

    ec.verts[6].x = 0;
    ec.verts[6].y = height; 
    ec.verts[6].z = width_half;

    ec.verts[7].x = 0;
    ec.verts[7].y = height; 
    ec.verts[7].z = -width_half;

//ִִִ Create 4 faces
    dword fflags = (limits & (ESCH_FACE_WIRE
                              | ESCH_FACE_SOLID
                              | ESCH_FACE_TEXTURED))
                   | ESCH_FACE_ABLINE
                   | ESCH_FACE_BCLINE
                   | ESCH_FACE_CALINE;

    ec.faces[0].flags = fflags;
    ec.faces[0].a     = 0;
    ec.faces[0].u[0]  = Flx16(0.01);
    ec.faces[0].v[0]  = fv;
    ec.faces[0].b     = 1;
    ec.faces[0].u[1]  = 1;
    ec.faces[0].v[1]  = fv;
    ec.faces[0].c     = 2;
    ec.faces[0].u[2]  = 1;
    ec.faces[0].v[2]  = Flx16(0.01);
    ec.faces[0].txt   = 1;

    ec.faces[1].flags = fflags;
    ec.faces[1].a     = 0;
    ec.faces[1].u[0]  = Flx16(0.01);
    ec.faces[1].v[0]  = fv;
    ec.faces[1].b     = 2;
    ec.faces[1].u[1]  = 1; 
    ec.faces[1].v[1]  = Flx16(0.01);
    ec.faces[1].c     = 3;
    ec.faces[1].u[2]  = Flx16(0.01);
    ec.faces[1].v[2]  = Flx16(0.01);
    ec.faces[1].txt   = 1;

    ec.faces[2].flags = fflags;
    ec.faces[2].a     = 4;
    ec.faces[2].u[0]  = Flx16(0.01);
    ec.faces[2].v[0]  = fv;
    ec.faces[2].b     = 5;
    ec.faces[2].u[1]  = 1;
    ec.faces[2].v[1]  = fv;
    ec.faces[2].c     = 6;
    ec.faces[2].u[2]  = 1;
    ec.faces[2].v[2]  = Flx16(0.01);
    ec.faces[2].txt   = 1;

    ec.faces[3].flags = fflags;
    ec.faces[3].a     = 4;
    ec.faces[3].u[0]  = Flx16(0.01);
    ec.faces[3].v[0]  = fv;
    ec.faces[3].b     = 6;
    ec.faces[3].u[1]  = 1;
    ec.faces[3].v[1]  = Flx16(0.01);
    ec.faces[3].c     = 7;
    ec.faces[3].u[2]  = Flx16(0.01);
    ec.faces[3].v[2]  = Flx16(0.01);
    ec.faces[3].txt   = 1;

//ִִִ Transform and light (if possible) the verticies
    for(i=0; i < 8; i++)
    {
        vflags[i] = ESCH_VVERT_TRANSFORMED;
        ec.verts[i].transform(&frame,(EschPoint*)&vpt[i]);
        vpt[i].shade=mp;
    }
    
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ Draw Faces
    esch_clipdraw_face(0,ESCH_CDF_CLIP | ESCH_CDF_MUSTTXT);
    esch_clipdraw_face(1,ESCH_CDF_CLIP | ESCH_CDF_MUSTTXT);
    esch_clipdraw_face(2,ESCH_CDF_CLIP | ESCH_CDF_MUSTTXT);
    esch_clipdraw_face(3,ESCH_CDF_CLIP | ESCH_CDF_MUSTTXT);

//ִִִ Pop drawing context
    ec.pop();
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschPlosion - animate                                                    ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void EschPlosion::animate()
{
    if (fire && ~(fire->flags & ESCH_TXT_SKIPANIMATE))
        fire->animate();

    if (fv > Flx16(0.2))
        fv -= step;
}

//°±² End of module - esplosn.cpp ²±°

