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
//������������������� Microsoft Windows 95/NT Version �����������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1998�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
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
// Created by Paul Masters & Chuck Walbourn
//
// esprtlin.cpp
//
// Contains the code for the EschParticleLine class which is a colored line
// in 3-space with various control attributes.
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
//                                 Data
//
//���������������������������������������������������������������������������

extern VngoPointF EschTempVPointF;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleLine - Constructor                                           �
//                                                                          �
// Initializes the particle.                                                �
//���������������������������������������������������������������������������
EschParticleLine::EschParticleLine(float ix, float iy, float iz,
                                   dword c, float l) :
    EschParticle(ix,iy,iz,c,l),
    pos2(ix,iy,iz)
{
    dtyp = ESCH_DRWT_PRTLINE;
}

EschParticleLine::EschParticleLine(float ix, float iy, float iz,
                                   float ii, float ij, float ik,
                                   dword c, float l) :
    EschParticle(ix,iy,iz,ii,ij,ik,c,l),
    pos2(ix,iy,iz)
{
    dtyp = ESCH_DRWT_PRTLINE;
}

EschParticleLine::EschParticleLine(const EschPoint *p,
                                   const EschVector *v,
                                   dword c, float l) :
    EschParticle(p,v,c,l),
    pos2(p->x,p->y,p->z)
{
    dtyp = ESCH_DRWT_PRTLINE;
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleLine - draw                                                  �
//                                                                          �
// Draws the given particle using the current drawing context at the        �
// current position.                                                        �
//���������������������������������������������������������������������������
void EschParticleLine::draw()
{
    EschCamera          *cam;

//��� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschParticle::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschParticle::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//��� Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.push();

//��� Transform into copy of point
    pos.transform(&cam->eye.iorient,(EschPoint*)&EschTempVPointF);
    EschTempVPointF.clr = color;
    EschTempVPointF.shade = float(cam->vport->vbuff.pal->shd_pal->mid_point);
    
    VngoPointF pts;
    pos2.transform(&cam->eye.iorient,(EschPoint*)&pts);
    pts.clr = color;
    pts.shade = float(cam->vport->vbuff.pal->shd_pal->mid_point);

//��� Light (normal shade value)
    assertMyth("EschPointDraw::draw needs palette in viewport",
               cam->vport->vbuff.pal != 0);

//��� Draw
    flags &= ~(ESCH_DRW_VISIBLE);
    esch_clipdraw_line(&pts,ESCH_CDF_CLIP);

//��� Cleanup
    ec.pop();
    if (pflags == ESCH_PRTK_NOTVISIBLE
        && flags & ESCH_DRW_VISIBLE)
    {
        pflags = ESCH_PRTK_VISIBLE;
    }
    else if (pflags == ESCH_PRTK_VISIBLE
             && !(flags & ESCH_DRW_VISIBLE))
    {
        // time to kill myself...
        life = 0;
        flags |= ESCH_DRW_SKIP;
    }
}


//�������������������������������������������������������������������������Ŀ
// EschParticleLine - animate                                               �
//                                                                          �
// Performs any operations needed to move the particle to the next frame,   �
// including life tests for death of the particle.                          �
//���������������������������������������������������������������������������
void EschParticleLine::animate()
{
//�� Perform life test, if not unlimited
    if (life > 0)
    {
        if (flags & ESCH_PRT_TIMEBASED)
            life -= interval;
        else
            life -= 1.0f;

        if (life <= 0)
            flags |= ESCH_DRW_SKIP;
    }

//�� Compute next position (if we have a valid time interval)
    if (interval == 0)
        return;

//�� Calculate the new velocity (based on acceleration)
    velocity.i += acceleration.i * interval;
    velocity.j += acceleration.j * interval;
    velocity.k += acceleration.k * interval;

//�� Calculate the new position (based on velocity)
    pos2 = pos;
    pos.x += velocity.i * interval;
    pos.y += velocity.j * interval;
    pos.z += velocity.k * interval;
}

//��� End of module - esprtlin.cpp ���
