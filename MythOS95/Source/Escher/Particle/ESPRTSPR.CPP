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
// esprtspr.cpp
//
// Contains the code for the EschParticleSprite class which is a
// particle that uses an EschSprite as the drawable.
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
// EschParticleSprite - Constructor                                         �
//                                                                          �
// Initializes the particle.                                                �
//���������������������������������������������������������������������������
EschParticleSprite::EschParticleSprite(EschSprite *s, float l) :
    EschParticle(),
    sprite(s),
    rot_rate(0),
    scale_rate(0)
{
    dtyp = ESCH_DRWT_PRTSPRITE;

    assertMyth("EschParticleSprite needs a valid sprite pointer",
               s != 0);

    set_position(&s->pos);
    alpha = float(s->get_alpha());
    life = l;
    alpha_rate = (l > 0) ? (alpha / l) : 0;
    velocity.i = 0;  velocity.j = 0;  velocity.k = 0;
    acceleration.i = 0;  acceleration.j = 0;  acceleration.k = 0;
}

EschParticleSprite::EschParticleSprite(EschSprite *s,
                                       float ii, float ij, float ik,
                                       float l) :
    EschParticle(),
    sprite(s),
    rot_rate(0),
    scale_rate(0)
{
    dtyp = ESCH_DRWT_PRTSPRITE;

    assertMyth("EschParticleSprite needs a valid sprite pointer",
               s != 0);
    set_position(&s->pos);

    alpha = float(s->get_alpha());
    life = l;
    alpha_rate = (l > 0) ? (alpha / l) : 0;
    velocity.i = ii;  velocity.j = ij;  velocity.k = ik;
    acceleration.i = 0;  acceleration.j = 0;  acceleration.k = 0;
}

EschParticleSprite::EschParticleSprite(EschSprite *s,
                                       const EschVector *v,
                                       float l) :
    EschParticle(),
    sprite(s),
    rot_rate(0),
    scale_rate(0)
{
    dtyp = ESCH_DRWT_PRTSPRITE;

    assertMyth("EschParticleSprite needs a valid sprite pointer",
               s != 0);
    set_position(&s->pos);
    alpha = float(s->get_alpha());
    life = l;
    alpha_rate = (l > 0) ? (alpha / l) : 0;
    velocity = *v;
    acceleration.i = 0;  acceleration.j = 0;  acceleration.k = 0;
}


//�������������������������������������������������������������������������Ŀ
// EschParticleSprite - Destructor                                          �
//���������������������������������������������������������������������������
EschParticleSprite::~EschParticleSprite()
{
    release();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleSprite - operator =                                          �
//                                                                          �
// Copies the data from another particle sprite                             �
//���������������������������������������������������������������������������
const EschParticleSprite &EschParticleSprite::operator =
                                              (const EschParticleSprite &that)
{
    if (this != &that)
    {
        release();

        EschParticle::operator = (that);

        sprite = that.sprite;
        alpha = that.alpha;
        alpha_rate = that.alpha_rate;
        rot_rate = that.rot_rate;
        scale_rate = that.scale_rate;
    }
    return *this;
}


//�������������������������������������������������������������������������Ŀ
// EschParticleSprite - draw                                                �
//                                                                          �
// Draws the given particle using the current drawing context at the        �
// current position.                                                        �
//���������������������������������������������������������������������������
void EschParticleSprite::draw()
{
    if (sprite)
        sprite->draw();
}


//�������������������������������������������������������������������������Ŀ
// EschParticleSprite - animate                                             �
//                                                                          �
// Performs any operations needed to move the particle to the next frame,   �
// including life tests for death of the particle.                          �
//���������������������������������������������������������������������������
void EschParticleSprite::animate()
{
    EschParticle::animate();

    if (!sprite)
        return;

    if (interval != 0)
    {
        if (limits & ESCH_FACE_ALPHA)
        {
            if (flags & ESCH_PRT_TIMEBASED)
                alpha -= alpha_rate * interval;
            else
                alpha -= alpha_rate;

            if (alpha < 0)
                alpha = 0;
            sprite->set_alpha((long)alpha);
        }

        if (rot_rate != 0)
        {
            float rotation = sprite->rotation;
            rotation += (interval * rot_rate);
            sprite->set_rotation (rotation);
        }

        if (scale_rate != 0)
        {
            float scale = sprite->scale;
            scale += (interval * scale_rate);
            if (scale < 0.0f)
                scale = 0.0f;
            sprite->set_scale(scale);
        }

        sprite->set_position(pos.x, pos.y, pos.z);
    }

    if (!(sprite->flags & ESCH_DRW_SKIPANIMATE))
        sprite->animate();
}


//�������������������������������������������������������������������������Ŀ
// EschParticleSprite - release                                             �
//���������������������������������������������������������������������������
void EschParticleSprite::release()
{
    if (sprite)
    {
        delete sprite;
        sprite=0;
    }
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleSprite - set_position                                        �
//���������������������������������������������������������������������������
void EschParticleSprite::set_position(float ix, float iy, float iz)
{
    pos.x = ix;
    pos.y = iy;
    pos.z = iz;

    if (sprite)
        sprite->set_position(ix, iy, iz);
}

//��� End of module - esprtspr.cpp ���
