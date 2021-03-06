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
// esplosn.cpp
//
// Contains the code for the EschPlosion class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPlosion - Constructor                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschPlosion::EschPlosion(float w, float h, EschFireTexture *f) :
    EschDrawable(ESCH_DRWT_EXPLOSION),
    fire(f),
    width(w),
    height(h),
    fv(float(0.90)),
    alpha_level(255),
    step(0)
{
    check_workspace();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                          旭� Protected 旭�                               �
// EschPlosion - check_workspace                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschPlosion::check_workspace()
{
    assertMyth("EschPlosion needs Escher initialized",EschSysInstance != 0);

    //陳 Update wspace_mbytes diags
    dword needed = (sizeof(VngoPoint)+sizeof(dword)+(sizeof(EschVertex)))*8
                   + sizeof(EschFace)*8;

    assertMyth("EschPlosion needs more workspace than is available",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPlosion - draw                                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschPlosion::draw()
{
    ulong           i;
    dword           cflags;
    dword           level;
    dword           *vflags;
    VngoPoint       *vpt;
    EschCamera      *cam;
    EschPoint       p;
    EschFrameRef    frame(0);

    assertMyth("EschPlosion::draw needs valid width, height, and fire texture",
               width > 0 && height > 0 && fire != 0);

//陳� Clear arena
    ivory_arena_clear(EschSysInstance->wspace);

//陳� Setup local pointers to current camera and Van Gogh viewport.
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

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Setup Context

    ulong verts;
    ulong faces;
    if (flags & ESCH_PLSN_CIRCULAR)
    {
        verts = 7;
        faces = 8;
    }
    else if (flags & ESCH_PLSN_TRIANGULAR)
    {
        verts = 5;
        faces = 2;
    }
    else
    {
        verts = 8;
        faces = 4;
    }

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = new (EschSysInstance->wspace) EschVertex[verts];
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * verts);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[verts];
    ec.faces = new (EschSysInstance->wspace) EschFace[faces];
    ec.fflags = 0;
    ec.txts = (EschTexture**) &fire;
    ec.push();

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Misc Setup
    //陳� Create local->world->eye transform
    world.orient.concat(&cam->eye.iorient,&frame.orient);
    cam->eye.orient.concat(&world.iorient,&frame.iorient);

    ec.faces[0].flags = (limits & (ESCH_FACE_WIRE
                                   | ESCH_FACE_SOLID
                                   | ESCH_FACE_TEXTURED))
                        | ESCH_FACE_ABLINE
                        | ESCH_FACE_BCLINE
                        | ESCH_FACE_CALINE;

    if ((limits & ESCH_FACE_ALPHA) && alpha_level < 255)
    {
        ec.faces[0].flags |= ESCH_FACE_ALPHA;
        ec.faces[0].set_alpha(alpha_level);
    }

    for(i=1; i < faces; i++)
        ec.faces[i].flags = ec.faces[0].flags;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Setup Shape
    if (flags & ESCH_PLSN_CIRCULAR)
    {
        assert(verts == 7 && faces == 8);

        //陳� Create 7 verticies
        //
        // (X/Y plane)                (Y/Z plane)
        //
        //          3                          3
        //        /\                         /\
        //       /  \                       /  \
        //      /    \                     /    \
        //     /      \                   /      \
        //    /        \                 /        \
        // 4 /    0     \ 2           6 /          \ 5
        //   \          /               \          /
        //    \        /                 \        /
        //     \      /                   \      /
        //      \    /                     \    /
        //       \  /                       \  /
        //        \/                         \/
        //       1                          1
        //

        float width_half = width / 2;
        float height_half = height / 2;

        ec.verts[0].x = 0;
        ec.verts[0].y = 0;
        ec.verts[0].z = 0;

        ec.verts[1].x = 0;
        ec.verts[1].y = -height_half;
        ec.verts[1].z = 0;

        ec.verts[2].x = width_half;
        ec.verts[2].y = 0;
        ec.verts[2].z = 0;

        ec.verts[3].x = 0;
        ec.verts[3].y = height_half;
        ec.verts[3].z = 0;

        ec.verts[4].x = -width_half;
        ec.verts[4].y = 0;
        ec.verts[4].z = 0;

        ec.verts[5].x = 0;
        ec.verts[5].y = 0;
        ec.verts[5].z = width_half;

        ec.verts[6].x = 0;
        ec.verts[6].y = 0;
        ec.verts[6].z = -width_half;

        //陳� Create 8 faces
        ec.faces[0].a     = 0;
        ec.faces[0].u[0]  = float(0.5);
        ec.faces[0].v[0]  = fv;
        ec.faces[0].b     = 2;
        ec.faces[0].u[1]  = float(0.01);
        ec.faces[0].v[1]  = float(0.01);
        ec.faces[0].c     = 1;
        ec.faces[0].u[2]  = float(0.90);
        ec.faces[0].v[2]  = float(0.01);
        ec.faces[0].txt   = 1;

        ec.faces[1].a     = 0;
        ec.faces[1].u[0]  = float(0.5);
        ec.faces[1].v[0]  = fv;
        ec.faces[1].b     = 3;
        ec.faces[1].u[1]  = float(0.90);
        ec.faces[1].v[1]  = float(0.01);
        ec.faces[1].c     = 2;
        ec.faces[1].u[2]  = float(0.01);
        ec.faces[1].v[2]  = float(0.01);
        ec.faces[1].txt   = 1;

        ec.faces[2].a     = 0;
        ec.faces[2].u[0]  = float(0.5);
        ec.faces[2].v[0]  = fv;
        ec.faces[2].b     = 4;
        ec.faces[2].u[1]  = float(0.01);
        ec.faces[2].v[1]  = float(0.01);
        ec.faces[2].c     = 3;
        ec.faces[2].u[2]  = float(0.90);
        ec.faces[2].v[2]  = float(0.01);
        ec.faces[2].txt   = 1;

        ec.faces[3].a     = 0;
        ec.faces[3].u[0]  = float(0.5);
        ec.faces[3].v[0]  = fv;
        ec.faces[3].b     = 1;
        ec.faces[3].u[1]  = float(0.90);
        ec.faces[3].v[1]  = float(0.01);
        ec.faces[3].c     = 4;
        ec.faces[3].u[2]  = float(0.01);
        ec.faces[3].v[2]  = float(0.01);
        ec.faces[3].txt   = 1;

        ec.faces[4].a     = 0;
        ec.faces[4].u[0]  = float(0.5);
        ec.faces[4].v[0]  = fv;
        ec.faces[4].b     = 5;
        ec.faces[4].u[1]  = float(0.01);
        ec.faces[4].v[1]  = float(0.01);
        ec.faces[4].c     = 1;
        ec.faces[4].u[2]  = float(0.90);
        ec.faces[4].v[2]  = float(0.01);
        ec.faces[4].txt   = 1;

        ec.faces[5].a     = 0;
        ec.faces[5].u[0]  = float(0.5);
        ec.faces[5].v[0]  = fv;
        ec.faces[5].b     = 3;
        ec.faces[5].u[1]  = float(0.90);
        ec.faces[5].v[1]  = float(0.01);
        ec.faces[5].c     = 5;
        ec.faces[5].u[2]  = float(0.01);
        ec.faces[5].v[2]  = float(0.01);
        ec.faces[5].txt   = 1;

        ec.faces[6].a     = 0;
        ec.faces[6].u[0]  = float(0.5);
        ec.faces[6].v[0]  = fv;
        ec.faces[6].b     = 6;
        ec.faces[6].u[1]  = float(0.01);
        ec.faces[6].v[1]  = float(0.01);
        ec.faces[6].c     = 3;
        ec.faces[6].u[2]  = float(0.90);
        ec.faces[6].v[2]  = float(0.01);
        ec.faces[6].txt   = 1;

        ec.faces[7].a     = 0;
        ec.faces[7].u[0]  = float(0.5);
        ec.faces[7].v[0]  = fv;
        ec.faces[7].b     = 1;
        ec.faces[7].u[1]  = float(0.90);
        ec.faces[7].v[1]  = float(0.01);
        ec.faces[7].c     = 6;
        ec.faces[7].u[2]  = float(0.01);
        ec.faces[7].v[2]  = float(0.01);
        ec.faces[7].txt   = 1;
    }
    else if (flags & ESCH_PLSN_TRIANGULAR)
    {
        assert(verts == 5 && faces == 2);
        //陳� Create 5 verticies
        //
        // (X/Y plane)                (Y/Z plane)
        //
        // 3-------------------2      7-------------------6
        //  \                /         \                /
        //   \              /           \              /
        //   0\____________/1           4\____________/5
        //
        //
        // 2 ____________ 1           4 ____________ 3
        //   \          /               \          /
        //    \        /                 \        /
        //     \      /                   \      /
        //      \    /                     \    /
        //       \  /                       \  /
        //        \/                         \/
        //       0                          0
        //

        float width_half = width / 2;

        ec.verts[0].x = 0;
        ec.verts[0].y = 0;
        ec.verts[0].z = 0;

        ec.verts[1].x = width_half;
        ec.verts[1].y = height;
        ec.verts[1].z = 0;

        ec.verts[2].x = -width_half;
        ec.verts[2].y = height;
        ec.verts[2].z = 0;

        ec.verts[3].x = 0;
        ec.verts[3].y = height;
        ec.verts[3].z = width_half;

        ec.verts[4].x = 0;
        ec.verts[4].y = height;
        ec.verts[4].z = -width_half;

        //陳� Create 2 faces
        ec.faces[0].a     = 0;
        ec.faces[0].u[0]  = float(0.5);
        ec.faces[0].v[0]  = fv;
        ec.faces[0].b     = 1;
        ec.faces[0].u[1]  = float(0.90);
        ec.faces[0].v[1]  = float(0.01);
        ec.faces[0].c     = 2;
        ec.faces[0].u[2]  = float(0.01);
        ec.faces[0].v[2]  = float(0.01);
        ec.faces[0].txt   = 1;

        ec.faces[1].a     = 0;
        ec.faces[1].u[0]  = float(0.5);
        ec.faces[1].v[0]  = fv;
        ec.faces[1].b     = 3;
        ec.faces[1].u[1]  = float(0.90);
        ec.faces[1].v[1]  = float(0.01);
        ec.faces[1].c     = 4;
        ec.faces[1].u[2]  = float(0.01);
        ec.faces[1].v[2]  = float(0.01);
        ec.faces[1].txt   = 1;
    }
    else
    {
        assert(verts == 8 && faces == 4);

        //陳� Create 8 verticies
        //
        // (X/Y plane)                (Y/Z plane)
        //
        // 3-------------------2      7-------------------6
        //  \                /         \                /
        //   \              /           \              /
        //   0\____________/1           4\____________/5
        //
        //

        float width_half = width / 2;
        float width_quarter = width / 4;

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

        //陳� Create 4 faces
        ec.faces[0].a     = 0;
        ec.faces[0].u[0]  = float(0.01);
        ec.faces[0].v[0]  = fv;
        ec.faces[0].b     = 1;
        ec.faces[0].u[1]  = float(0.90);
        ec.faces[0].v[1]  = fv;
        ec.faces[0].c     = 2;
        ec.faces[0].u[2]  = float(0.90);
        ec.faces[0].v[2]  = float(0.01);
        ec.faces[0].txt   = 1;

        ec.faces[1].a     = 0;
        ec.faces[1].u[0]  = float(0.01);
        ec.faces[1].v[0]  = fv;
        ec.faces[1].b     = 2;
        ec.faces[1].u[1]  = float(0.90);
        ec.faces[1].v[1]  = float(0.01);
        ec.faces[1].c     = 3;
        ec.faces[1].u[2]  = float(0.01);
        ec.faces[1].v[2]  = float(0.01);
        ec.faces[1].txt   = 1;

        ec.faces[2].a     = 4;
        ec.faces[2].u[0]  = float(0.01);
        ec.faces[2].v[0]  = fv;
        ec.faces[2].b     = 5;
        ec.faces[2].u[1]  = float(0.90);
        ec.faces[2].v[1]  = fv;
        ec.faces[2].c     = 6;
        ec.faces[2].u[2]  = float(0.90);
        ec.faces[2].v[2]  = float(0.01);
        ec.faces[2].txt   = 1;

        ec.faces[3].a     = 4;
        ec.faces[3].u[0]  = float(0.01);
        ec.faces[3].v[0]  = fv;
        ec.faces[3].b     = 6;
        ec.faces[3].u[1]  = float(0.90);
        ec.faces[3].v[1]  = float(0.01);
        ec.faces[3].c     = 7;
        ec.faces[3].u[2]  = float(0.01);
        ec.faces[3].v[2]  = float(0.01);
        ec.faces[3].txt   = 1;
    }

//陳� Transform and light (if possible) the verticies
    for(i=0; i < verts; i++)
    {
        ec.verts[i].transform(&frame,(EschPoint*)(&vpt[i]));
        vpt[i].shade=mp;
    }

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Draw Faces
    for(i=0; i < faces; i++)
    {
        esch_clipdraw_face(i,ESCH_CDF_CLIP | ESCH_CDF_MUSTTXT);
    }

//陳� Pop drawing context
    ec.pop();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPlosion - animate                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschPlosion::animate()
{
    if (fire && !(fire->flags & ESCH_TXT_SKIPANIMATE))
        fire->animate();

    if (fv > float(0.2))
        fv -= step;
}

//葦� End of module - esplosn.cpp 憶�

