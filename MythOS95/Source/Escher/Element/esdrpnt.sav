//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùù°°°°°°°°°°ù°°°°°°°°ùùù°°°°°°°°ùù°°°ùùùù°°°ù°°°°°°°°°°ù°°°°°°°°°ùù
//ùùùùùùùùù°±°ùùùùùùù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùùùùùù°±°ùùùù°±°ùù
//ùùùùùùùù±°±ùùùùùùù±°±ùùùùùùùù±°±ùùùùùùùù±°±ùùùù±°±ù±°±ùùùùùùùù±°±ùùùù±°±ùùù
//ùùùùùùù±²±±°±±²ùù±²±±°±±²±±ù±²±ùùùùùùùù±²±±°±±²±±ù±²±±°±±²ùùù±²±±°±±²°ùùùùù
//ùùùùùù±²±ùùùùùùùùùùùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ùùùùù
//ùùùùù²±²ùùùùùùù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùùùùùù²±²ùùùù²±²ùùùùùù
//ùùùù²²²²²²²²²²ù²²²²²²²²ùùù²²²²²²²²ùù²²²ùùùù²²²ù²²²²²²²²²²ù²²²ùùùù²²²ùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùù Microsoft Windows 95/NT Version ùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùCopyrightù(c)ù1994-1998ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little & Chuck Walbourn
//
// esdrpnt.cpp
//
// Contains the C++ implementation of the clip/draw function for points.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define ES_SNAP_VERTS

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern VngoPointF EschTempVPointF;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_clipdraw_point                                                      ³
//                                                                          ³
// Draws a point using the current object information in the context and the³
// global EschTempVPointF                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_clipdraw_point(dword ctrlfl)
{
    long        width, height;
    float       zx, zy;
    EschCamera  *cam;
    dword       cflags;

//ÄÄÄ Setup local pointer to current camera
    assertMyth("esch_clipdraw_point needs camera in current context",
               EschCurrent != 0 && EschCurrent->camera != 0);

    cam = EschCurrent->camera;

    cflags = cam->flags;

//ÄÄÄ Perform Clip
    if (ctrlfl & ESCH_CDF_CLIP)
    {
        //ÄÄÄ Near/far clipping
        if (EschTempVPointF.z > cam->yon
            || EschTempVPointF.z < cam->hither)
            return;

        //ÄÄÄ Left/right/top/bottom plane clipping
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

//ÄÄÄ Project pixel
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

//ÄÄÄ Mark as visible
    assertMyth("esch_clipdraw_point needs valid draw data in context",
               EschCurrent != 0 && EschCurrent->current != 0);
    EschDrawable *current=EschCurrent->current;
    current->flags |= ESCH_DRW_VISIBLE;

//ÄÄÄ Draw pixel
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

//°±² End of module - esdrpnt.cpp ²±°

