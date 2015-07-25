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
// esprtsys.cpp
//
// Contains the code for the EschParticleSystem class which is a 
// particle container class for maintaining a large number of EschParticle
// instances.
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
// EschParticleSystem - Destructor                                          �
//���������������������������������������������������������������������������
EschParticleSystem::~EschParticleSystem()
{
    release();
};



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleSystem - operator =                                          �
//                                                                          �
// Copies the data from another particle system.                            �
//���������������������������������������������������������������������������
const EschParticleSystem &EschParticleSystem::operator =
                                              (const EschParticleSystem &ps)
{
    if (this != &ps)
    {
        release();

        EschDrawable::operator = (ps);

        interval = ps.interval;
        maxcount = ps.maxcount;
        particles = ps.particles;
        acceleration = ps.acceleration;
    }
    return *this;
}


//�������������������������������������������������������������������������Ŀ
// EschParticleSystem - draw                                                �
//                                                                          �
// This calls draw() for each defined particle in the class.                �
//���������������������������������������������������������������������������
void EschParticleSystem::draw()
{
    if (!maxcount || !particles)
        return;

    for(ulong i=0; i < maxcount; i++)
    {
        EschParticle *ptr = particles[i];
        if (ptr && !(ptr->flags & ESCH_DRW_SKIP))
            ptr->draw();
    }
}


//�������������������������������������������������������������������������Ŀ
// EschParticleSystem - animate                                             �
//                                                                          �
// This calls animate() for each defined particle in the class.             �
//���������������������������������������������������������������������������
void EschParticleSystem::animate()
{
    if (!maxcount || !particles)
        return;

    for(ulong i=0; i < maxcount; i++)
    {
        EschParticle *ptr = particles[i];
        if (ptr && !(ptr->flags & ESCH_DRW_SKIP))
            ptr->animate();
    }
}


//�������������������������������������������������������������������������Ŀ
// EschParticleSystem - init                                                �
//                                                                          �
// Initializes the particle system by creating the array of pointers.       �
//���������������������������������������������������������������������������
esch_error_codes EschParticleSystem::init(ulong mc)
{
//��� Release any previous particle set
    release();

//��� Setup count
    maxcount=mc;

    if (!mc)
        return ESCH_ERR_INVALIDPARMS;

//��� Create array of pointers and clear it
    particles = new EschParticle*[mc];
    if (!particles)
        return ESCH_ERR_NOMEMORY;

    for(ulong i=0; i < mc; i++)
        particles[i] = 0;

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschParticleSystem - release                                             �
//                                                                          �
// Releases all particles given to the particle system and the array of     �
// pointers.                                                                �
//���������������������������������������������������������������������������
void EschParticleSystem::release()
{
    if (!particles)
        return;

    for(ulong i=0; i < maxcount; i++)
    {
        if (particles[i])
            delete particles[i];
    }
    delete [] particles;
    particles=0;
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleSystem - add                                                 �
//                                                                          �
// This adds a particle to the particle system.  It will assume ownership   �
// of the particle class passed in and assumes it has been 'newd'.          �
//���������������������������������������������������������������������������
void EschParticleSystem::add(EschParticle *p)
{
    assertMyth("EschParticleSystem::add expects valid particle",
               p != 0);

    if (maxcount && particles)
    {
        for(ulong i=0; i < maxcount; i++)
        {
            if (particles[i])
            {
                //��� We can overwrite SKIPs since they have run out of life
                if ( !(particles[i]->flags & ESCH_DRW_SKIP) )
                    continue;

                delete particles[i];
            }

            //��� Add our global acceleration vector
            p->set_acceleration( p->acceleration.i + acceleration.i,
                                 p->acceleration.j + acceleration.j,
                                 p->acceleration.k + acceleration.k );

            p->set_flags(p->flags &= ~ESCH_DRW_SKIP);

            p->set_interval(interval);

            p->set_limits(limits);

            //��� Assign particle to slot and return
            particles[i] = p;
            return;
        }
    }

//��� No space, so must free before leaving
    delete p;
}


//�������������������������������������������������������������������������Ŀ
// EschParticleSystem - set_interval                                        �
//                                                                          �
// This calls set_interval() for each defined particle in the class.        �
//���������������������������������������������������������������������������
void EschParticleSystem::set_interval(float i)
{
    if (!maxcount || !particles)
        return;

    interval = i;

    for(ulong c=0; c < maxcount; c++)
    {
        if (particles[c])
            particles[c]->set_interval(i);
    }
}

//��� End of module - esprtsys.cpp ���
