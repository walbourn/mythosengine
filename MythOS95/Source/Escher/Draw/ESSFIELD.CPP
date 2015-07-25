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
// essfield.cpp
//
// Contains the code for the EschStarfield class which implements
// a space 'starfield' drawable.
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

extern EschPoint EschTempPoint;
extern VngoPoint EschTempVPoint;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschStarfield - Destructor                                               �
//���������������������������������������������������������������������������
EschStarfield::~EschStarfield()
{
    release();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschStarfield - operator =                                               �
//                                                                          �
// Copies the data from another starfield.                                  �
//���������������������������������������������������������������������������
const EschStarfield &EschStarfield::operator = (const EschStarfield &sf)
{
    if (this != &sf)
    {
        release();

        EschDrawable::operator = (sf);

        count = sf.count;
        stars = sf.stars;
        brightness = sf.brightness;
        color = sf.color;
    }
    return *this;
}


//�������������������������������������������������������������������������Ŀ
// EschStarfield - draw                                                     �
//                                                                          �
// Draws the starfield using the current drawing context.                   �
//���������������������������������������������������������������������������
void EschStarfield::draw()
{
    EschCamera          *cam;

    if (!stars || !count)
        return;

//��� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschStarfield::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschStarfield::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    VngoVport *vport = cam->vport;

    assertMyth("EschStarfield::draw needs palette in viewport",
               vport->vbuff.pal != 0);

    EschTempVPoint.clr = color;
    EschTempVPoint.shade = vport->vbuff.pal->shd_pal->mid_point;

//���������������������������������������������������������������� Draw stars
    for(ulong i=0; i < count; i++)
    {
        //��� Transform into copy of point
        if (flags & ESCH_SFLD_FTL)
        {
            stars[i].transform(&cam->eye.iorient,&EschTempPoint);
        }
        else
        {
            ((EschVector*)&stars[i])->transform(&cam->eye.iorient,
                                                (EschVector*)&EschTempPoint);
        }

        //��� Clip against view volume

        // Near clipping (stars should ignore far plane)
        if (EschTempPoint.z.flx < cam->hither.flx)
            continue;

        // Left/right/top/bottom plane clipping
        Flx16 zx = flx_16mul16(EschTempPoint.z,cam->xsize);
        Flx16 zy = flx_16mul16(EschTempPoint.z,cam->ysize);

        if (EschTempPoint.x.flx < -zx.flx 
            || EschTempPoint.x.flx > zx.flx
            || EschTempPoint.y.flx < -zy.flx
            || EschTempPoint.y.flx > zy.flx)
            continue;

        flags |= ESCH_DRW_VISIBLE;

        //��� Project pixel
        EschTempVPoint.x = (flx_muldiv(EschTempPoint.x,
                                    cam->xscalar,
                                    EschTempPoint.z).flx
                            + (cam->vport->vbuff.width<<15)) >> 16;
        EschTempVPoint.y = ((cam->vport->vbuff.height<<15)
                            - flx_muldiv(EschTempPoint.y,
                                        cam->yscalar,
                                        EschTempPoint.z).flx) >> 16;
        EschTempVPoint.z = 0xfffeffff;

        if (brightness)
            EschTempVPoint.shade = brightness[i];

        //��� Draw pixel
        vport->pixel(&EschTempVPoint);
    }
}


//�������������������������������������������������������������������������Ŀ
// EschStarfield - release                                                  �
//                                                                          �
// Releases the star database.                                              �
//���������������������������������������������������������������������������
void EschStarfield::release()
{
    if (flags & ESCH_DRW_OWNSDATA)
    {
        if (stars)  
        {
            delete [] stars;
        }
        if (brightness)
        {
            delete [] brightness;
        }
    }
    flags &= ~ESCH_DRW_OWNSDATA;
    stars=0;
    brightness=0;
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschStarfield - create_stars                                             �
//                                                                          �
// Creates a random starfield.                                              �
//���������������������������������������������������������������������������
esch_error_codes EschStarfield::create_stars(ulong c, int dobrights)
{
    release();

//��� Allocate memory
    stars = new EschPoint[c];
    if (!stars)
        return ESCH_ERR_NOMEMORY;

    if (dobrights)
    {
        brightness = new dword[c];
        if (!brightness)
        {
            delete [] stars;
            stars=0;
            return ESCH_ERR_NOMEMORY;
        }
    }

    flags |= ESCH_DRW_OWNSDATA;

//��� Create random stars
    count=c;

    for(ulong i=0; i < c; i++)
    {
        stars[i].x = flx_rand() * Flx16(0.7);
        stars[i].y = flx_rand() * Flx16(0.7);
        stars[i].z = flx_rand() * Flx16(0.7);

        if (brightness)
        {
            brightness[i] = ((flx_rand().flx & 0xf) << 4) | 0x1f;
        }
    }

    return ESCH_ERR_NONE;
}

//��� End of module - essfield.cpp ���
