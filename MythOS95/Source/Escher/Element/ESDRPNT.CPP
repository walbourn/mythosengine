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
// esdrpnt.cpp
//
// Contains the C++ implementation of the clip/draw function for points.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define ES_SNAP_VERTS

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern VngoPointF EschTempVPointF;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_clipdraw_point                                                      �
//                                                                          �
// Draws a point using the current object information in the context and the�
// global EschTempVPointF                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void esch_clipdraw_point(dword ctrlfl)
{
    long        width, height;
    float       zx, zy;
    EschCamera  *cam;
    dword       cflags;

//陳� Setup local pointer to current camera
    assertMyth("esch_clipdraw_point needs camera in current context",
               EschCurrent != 0 && EschCurrent->camera != 0);

    cam = EschCurrent->camera;

    cflags = cam->flags;

//陳� Perform Clip
    if (ctrlfl & ESCH_CDF_CLIP)
    {
        //陳� Near/far clipping
        if (EschTempVPointF.z > cam->yon
            || EschTempVPointF.z < cam->hither)
            return;

        //陳� Left/right/top/bottom plane clipping
        if (cflags & ESCH_CAM_ORTHO)
        {
            zx = cam->xsize - 1;
            zy = cam->ysize - 1;
        }
        else
        {
            zx = (EschTempVPointF.z * cam->xsize) - 1;
            zy = (EschTempVPointF.z * cam->ysize) - 1;
        }

        if (EschTempVPointF.x < -zx
            || EschTempVPointF.x > zx
            || EschTempVPointF.y < -zy
            || EschTempVPointF.y > zy)
            return;
    }

    width = cam->vport->vbuff.width;
    height = cam->vport->vbuff.height;

//陳� Project pixel
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

//陳� Mark as visible
    assertMyth("esch_clipdraw_point needs valid draw data in context",
               EschCurrent != 0 && EschCurrent->current != 0);
    EschDrawable *current=EschCurrent->current;
    current->flags |= ESCH_DRW_VISIBLE;

//陳� Draw pixel
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

//葦� End of module - esdrpnt.cpp 憶�

