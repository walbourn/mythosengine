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
// esdrpnt.cpp
//
// Contains the C++ implementation of the clip/draw function for points.
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
//                                Equates
//
//���������������������������������������������������������������������������

#define ES_SNAP_VERTS

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

//�������������������������������������������������������������������������Ŀ
// esch_clipdraw_point                                                      �
//                                                                          �
// Draws a point using the current object information in the context and the�
// global EschTempVPointF                                                   �
//���������������������������������������������������������������������������
extern "C" void esch_clipdraw_point(dword ctrlfl)
{
    long        width, height;
    float       zx, zy;
    EschCamera  *cam;
    dword       cflags;

//��� Setup local pointer to current camera
    assertMyth("esch_clipdraw_point needs camera in current context",
               EschCurrent != 0 && EschCurrent->camera != 0);
    
    cam = EschCurrent->camera;

    cflags = cam->flags;

//��� Perform Clip
    if (ctrlfl & ESCH_CDF_CLIP)
    {
        //��� Near/far clipping
        if (EschTempVPointF.z > cam->yon
            || EschTempVPointF.z < cam->hither)
            return;

        //��� Left/right/top/bottom plane clipping
        if (cflags & ESCH_CAM_ORTHO)
        {
            zx = cam->xsize;
            zy = cam->ysize;
        }
        else
        {
            zx = EschTempVPointF.z * cam->xsize;
            zy = EschTempVPointF.z * cam->ysize;
        }

        if (EschTempVPointF.x < -zx 
            || EschTempVPointF.x > zx
            || EschTempVPointF.y < -zy
            || EschTempVPointF.y > zy)
            return;
    }

    width = cam->vport->vbuff.width;
    height = cam->vport->vbuff.height;

//��� Project pixel
    if (cflags & ESCH_CAM_ORTHO)
    {
#ifdef ES_SNAP_VERTS
        EschTempVPointF.x = float(long(EschTempVPointF.x * cam->xscalar)
                                  + (width >> 1));
        EschTempVPointF.y = float((height >> 1)
                                  - long(EschTempVPointF.y * cam->yscalar));
#else
        EschTempVPointF.x = (EschTempVPointF.x * cam->xscalar)
                            + float(width >> 1);
        EschTempVPointF.y = float(height >> 1)
                            - (EschTempVPointF.y * cam->yscalar);
#endif
    }
    else
    {
#ifdef ES_SNAP_VERTS
        EschTempVPointF.x = float(long((EschTempVPointF.x * cam->xscalar)
                                                      / EschTempVPointF.z)
                                  + (width >> 1));
        EschTempVPointF.y = float((height >> 1)
                                  - long((EschTempVPointF.y * cam->yscalar)
                                                        / EschTempVPointF.z));
#else
        EschTempVPointF.x = ((EschTempVPointF.x * cam->xscalar)
                                            / EschTempVPointF.z)
                            + float(width >> 1);
        EschTempVPointF.y = float(height >> 1)
                            - ((EschTempVPointF.y * cam->yscalar)
                                              / EschTempVPointF.z);
#endif
    }

    EschTempVPointF.z = (ctrlfl & ESCH_CDF_INFINITEZ)
                        ? 0.99998f : (EschTempVPointF.z * cam->z_factor);

#if 0
    if (EschTempVPointF.x < 0.0f)
        EschTempVPointF.x = 0.0f;
    if (EschTempVPointF.x > float(width-1))
        EschTempVPointF.x = float(width-1);
    if (EschTempVPointF.y < 0.0f)
        EschTempVPointF.y = 0.0f;
    if (EschTempVPointF.y > float(height-1))
        EschTempVPointF.y = float(height-1);
#endif
    
//��� Mark as visible
    assertMyth("esch_clipdraw_point needs valid draw data in context",
               EschCurrent != 0 && EschCurrent->current != 0);
    EschDrawable *current=EschCurrent->current;
    current->flags |= ESCH_DRW_VISIBLE;

//��� Draw pixel
    if ((ctrlfl & ESCH_CDF_DONTSORT) || !(cam->flags & ESCH_CAM_SORT))
    {
        cam->vport->pixel(&EschTempVPointF);
    }
    else
    {
        assertMyth("esch_clipdraw_point() needs EschSysInstance and sort area",
                   EschSysInstance && EschSysInstance->sspace);

        EschElement *elm = new (EschSysInstance->sspace)
                           EschPixelElement(&EschTempVPointF);

        assertMyth("esch_clipdraw_point() can't allocate sort area memory",
                   elm != 0);
        if (elm)
            elm->insert();
    }
}

//��� End of module - esdrpnt.cpp ���
