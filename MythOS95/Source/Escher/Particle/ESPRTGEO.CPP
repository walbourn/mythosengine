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
// Created by Tim Little & Chuck Walbourn
//
// esprtgeo.cpp
//
// Contains the code for the EschParticleGeometry class which is a 
// particle that uses an EschGeometry as the drawable.
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
// EschParticleGeometry - Constructor                                       �
//                                                                          �
// Initializes the particle.                                                �
//���������������������������������������������������������������������������
EschParticleGeometry::EschParticleGeometry(EschGeometry *g, float l) :
    EschParticle(),
    geom(g),
    rotate_i(0),
    rotate_j(0),
    rotate_k(0)
{
    dtyp = ESCH_DRWT_PRTGEOMETRY;

    assertMyth("EschParticleGeometry needs a valid geometry pointer",
               g != 0);
    g->get_position(&pos);
    life = l;
    velocity.i = 0;  velocity.j = 0;  velocity.k = 0;
    acceleration.i = 0;  acceleration.j = 0;  acceleration.k = 0;
}

EschParticleGeometry::EschParticleGeometry(EschGeometry *g,
                                           float ii, float ij, float ik,
                                           float l) :
    EschParticle(),
    geom(g),
    rotate_i(0),
    rotate_j(0),
    rotate_k(0)
{
    dtyp = ESCH_DRWT_PRTGEOMETRY;

    assertMyth("EschParticleGeometry needs a valid geometry pointer",
               g != 0);
    g->get_position(&pos);
    life = l;
    velocity.i = ii;  velocity.j = ij;  velocity.k = ik;
    acceleration.i = 0;  acceleration.j = 0;  acceleration.k = 0;
}

EschParticleGeometry::EschParticleGeometry(EschGeometry *g,
                                           const EschVector *v,
                                           float l) :
    EschParticle(),
    geom(g),
    rotate_i(0),
    rotate_j(0),
    rotate_k(0)
{
    dtyp = ESCH_DRWT_PRTGEOMETRY;

    assertMyth("EschParticleGeometry needs a valid geometry pointer",
               g != 0);
    g->get_position(&pos);
    life = l;
    velocity = *v;
    acceleration.i = 0;  acceleration.j = 0;  acceleration.k = 0;
}


//�������������������������������������������������������������������������Ŀ
// EschParticleGeometry - Destructor                                        �
//���������������������������������������������������������������������������
EschParticleGeometry::~EschParticleGeometry()
{
    release();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleGeometry - operator =                                        �
//                                                                          �
// Copies the data from another particle geometry                           �
//���������������������������������������������������������������������������
const EschParticleGeometry &EschParticleGeometry::operator =
                                              (const EschParticleGeometry &pg)
{
    if (this != &pg)
    {
        release();

        EschParticle::operator = (pg);

        geom = pg.geom;
        rotate_i = pg.rotate_i;
        rotate_j = pg.rotate_j;
        rotate_k = pg.rotate_k;
    }
    return *this;
}


//�������������������������������������������������������������������������Ŀ
// EschParticleGeometry - draw                                              �
//                                                                          �
// Draws the given particle using the current drawing context at the        �
// current position.                                                        �
//���������������������������������������������������������������������������
void EschParticleGeometry::draw()
{
    if (geom)
        geom->draw();
}


//�������������������������������������������������������������������������Ŀ
// EschParticleGeometry - animate                                           �
//                                                                          �
// Performs any operations needed to move the particle to the next frame,   �
// including life tests for death of the particle.                          �
//���������������������������������������������������������������������������
void EschParticleGeometry::animate()
{
    EschParticle::animate();

    if (!geom)
        return;

    if (interval == 0)
        return;

    if (rotate_i != 0)
        geom->pitch(rotate_i * interval,0);

    if (rotate_j != 0)
        geom->yaw(rotate_j * interval,0);

    if (rotate_k != 0)
        geom->roll(rotate_k * interval,0);

    geom->set_position(pos.x, pos.y, pos.z);

    if (!(geom->flags & ESCH_DRW_SKIPANIMATE))
        geom->animate();
}


//�������������������������������������������������������������������������Ŀ
// EschParticleGeometry - release                                           �
//���������������������������������������������������������������������������
void EschParticleGeometry::release()
{
    if (geom)
    {
        delete geom;
        geom=0;
    }
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleGeometry - set_position                                      �
//���������������������������������������������������������������������������
void EschParticleGeometry::set_position(float ix, float iy, float iz)
{
    pos.x = ix;
    pos.y = iy;
    pos.z = iz;

    if (geom)
        geom->set_position(ix, iy, iz);
}


//�������������������������������������������������������������������������Ŀ
// EschParticleGeometry - reset                                             �
//���������������������������������������������������������������������������
void EschParticleGeometry::reset()
{
    if (!geom)
        return;

    geom->reset();
    geom->set_position(&pos);
}

//��� End of module - esprtgeo.cpp ���
