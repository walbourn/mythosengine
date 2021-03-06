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
// esprtspr.cpp
//
// Contains the code for the EschParticleSprite class which is a
// particle that uses an EschSprite as the drawable.
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
// EschParticleSprite - Constructor                                         �
//                                                                          �
// Initializes the particle.                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleSprite - Destructor                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschParticleSprite::~EschParticleSprite()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleSprite - operator =                                          �
//                                                                          �
// Copies the data from another particle sprite                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleSprite - draw                                                �
//                                                                          �
// Draws the given particle using the current drawing context at the        �
// current position.                                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschParticleSprite::draw()
{
    if (sprite)
    {
        sprite->flags &= ~ESCH_DRW_VISIBLE;
        sprite->draw();

        //陳� Do CULL option...
        if (!(sprite->flags & ESCH_DRW_VISIBLE))
        {
            if ((flags & ESCH_PRT_CULLIFOUTOFVIEW)
                && (flags & ESCH_PRT_WASVISIBLE))
            {
                life = 0;
                flags |= ESCH_DRW_SKIP;
            }
        }
        else
            flags |= ESCH_PRT_WASVISIBLE;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleSprite - animate                                             �
//                                                                          �
// Performs any operations needed to move the particle to the next frame,   �
// including life tests for death of the particle.                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleSprite - release                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschParticleSprite::release()
{
    if (sprite)
    {
        delete sprite;
        sprite=0;
    }
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleSprite - set_position                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschParticleSprite::set_position(float ix, float iy, float iz)
{
    pos.x = ix;
    pos.y = iy;
    pos.z = iz;

    if (sprite)
        sprite->set_position(ix, iy, iz);
}

//葦� End of module - esprtspr.cpp 憶�

