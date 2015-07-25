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
//ùùùùùùùùùùCopyrightù(c)ù1994,ù1995ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùù Microsoft Windows '95 Version ùùùùùùùùùùùùùùùùùùùùùùù
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
// esexts.cpp
//
//      Contains the code for the EschExtents class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

static VngoPoint    Vpt;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschExtents - draw                                                       ³
//                                                                          ³
// Draws the extent of the object.                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschExtents::draw(const EschFrameRef *fr, dword clr, int box) const
{
    EschCamera          *cam;
    EschPoint           p;
    EschFrameRef        frame;

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschExtents::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschExtents::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//ÄÄÄ Create local->world->eye transform (ignore inverse)
    fr->orient.concat(&cam->eye.iorient,&frame.orient);

//ÄÄÄ Setup for compare
    Flx16 yon = cam->yon;
    Flx16 hither = cam->hither;
    
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Box
    if (box)
    {

        Vpt.z = 0;
        Vpt.clr = clr;

        for(int i=0; i < 8; i++)
        {
            switch (i)
            {
                case 0:
                    p.x = mins[0];
                    p.y = mins[1];
                    p.z = mins[2];
                    break;
                case 1:
                    p.x = maxs[0];
                    p.y = mins[1];
                    p.z = mins[2];
                    break;
                case 2:
                    p.x = mins[0];
                    p.y = maxs[1];
                    p.z = mins[2];
                    break;
                case 3:
                    p.x = maxs[0];
                    p.y = maxs[1];
                    p.z = mins[2];
                    break;
                case 4:
                    p.x = mins[0];
                    p.y = mins[1];
                    p.z = maxs[2];
                    break;
                case 5:
                    p.x = maxs[0];
                    p.y = mins[1];
                    p.z = maxs[2];
                    break;
                case 6:
                    p.x = mins[0];
                    p.y = maxs[1];
                    p.z = maxs[2];
                    break;
                default: /* 7 */
                    p.x = maxs[0];
                    p.y = maxs[1];
                    p.z = maxs[2];
                    break;
            }
            p.transform(&frame);
            if (p.z >= hither && p.z <= yon)
            {
                Vpt.x = (flx_muldiv(p.x, cam->xscalar, p.z).flx
                         + (cam->vport->get_vbuff()->width<<15)) >> 16;
                Vpt.y = ((cam->vport->get_vbuff()->height<<15)
                         - flx_muldiv(p.y, cam->yscalar, p.z).flx) >> 16;
                if (Vpt.x >= 0 && Vpt.x < cam->vport->get_vbuff()->width
                    && Vpt.y >= 0 && Vpt.y < cam->vport->get_vbuff()->height)
                    cam->vport->pixel(&Vpt);
            }
        }
    }
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Radial
    else
    {
        //ÄÄÄ Transform center into view
        center.transform(&frame,&p);

        //ÄÄÄ Scale radius
        Flx16 r = flx_16mul16( radius, 
                  flx_16mul16( fr->scalef, 
                               cam->radius_factor ) );

        assertMyth("EschExtents::draw scaled to a negative radius",
                   r.flx >= 0);

        //ÄÄÄ Check for fully invisible against hither/yon
        if ( ((p.z.flx + r.flx) < hither.flx)
             || ((p.z.flx - r.flx) > yon.flx) )
            return;

        //ÄÄÄ Draw radial extents as 5 points.

        if (p.z <= 0)
            return;
        
        Vpt.z = 0;
        Vpt.clr = clr;
    
        Vpt.x = (flx_muldiv(p.x, cam->xscalar, p.z).flx
                 + (cam->vport->get_vbuff()->width<<15)) >> 16;
        Vpt.y = ((cam->vport->get_vbuff()->height<<15)
                 - flx_muldiv(p.y, cam->yscalar, p.z).flx) >> 16;
        if (Vpt.x >= 0 && Vpt.x < cam->vport->get_vbuff()->width
            && Vpt.y >= 0 && Vpt.y < cam->vport->get_vbuff()->height)
            cam->vport->pixel(&Vpt);
            
        Vpt.x = (flx_muldiv(p.x + r, cam->xscalar, p.z).flx
                 + (cam->vport->get_vbuff()->width<<15)) >> 16;
        Vpt.y = ((cam->vport->get_vbuff()->height<<15)
                 - flx_muldiv(p.y, cam->yscalar, p.z).flx) >> 16;
        if (Vpt.x >= 0 && Vpt.x < cam->vport->get_vbuff()->width
            && Vpt.y >= 0 && Vpt.y < cam->vport->get_vbuff()->height)
            cam->vport->pixel(&Vpt);
            
        Vpt.x = (flx_muldiv(p.x - r, cam->xscalar, p.z).flx
                 + (cam->vport->get_vbuff()->width<<15)) >> 16;
        Vpt.y = ((cam->vport->get_vbuff()->height<<15)
                 - flx_muldiv(p.y, cam->yscalar, p.z).flx) >> 16;
        if (Vpt.x >= 0 && Vpt.x < cam->vport->get_vbuff()->width
            && Vpt.y >= 0 && Vpt.y < cam->vport->get_vbuff()->height)
            cam->vport->pixel(&Vpt);
            
        Vpt.x = (flx_muldiv(p.x, cam->xscalar, p.z).flx
                 + (cam->vport->get_vbuff()->width<<15)) >> 16;
        Vpt.y = ((cam->vport->get_vbuff()->height<<15)
                 - flx_muldiv(p.y + r, cam->yscalar, p.z).flx) >> 16;
        if (Vpt.x >= 0 && Vpt.x < cam->vport->get_vbuff()->width
            && Vpt.y >= 0 && Vpt.y < cam->vport->get_vbuff()->height)
            cam->vport->pixel(&Vpt);
            
        Vpt.x = (flx_muldiv(p.x, cam->xscalar, p.z).flx
                 + (cam->vport->get_vbuff()->width<<15)) >> 16;
        Vpt.y = ((cam->vport->get_vbuff()->height<<15)
                 - flx_muldiv(p.y - r, cam->yscalar, p.z).flx) >> 16;
        if (Vpt.x >= 0 && Vpt.x < cam->vport->get_vbuff()->width
            && Vpt.y >= 0 && Vpt.y < cam->vport->get_vbuff()->height)
            cam->vport->pixel(&Vpt);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschExtents - hit                                                        ³
//                                                                          ³
// Performs an intersection test input in the same coordinate system of the ³
// extents.  This will test against either the radial or box extents of the ³
// object.                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschExtents::hit(const EschPoint *pt, int box) const
{
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Box
    if (box)
    {
        return ( (pt->x < mins[0])
                 || (pt->x > maxs[0])
                 || (pt->y < mins[1])
                 || (pt->y > maxs[1])
                 || (pt->z < mins[2])
                 || (pt->z > maxs[2]) ) ? 0 : 1;
    }
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Radial
    else
    {
        EschPoint   p;

        p = *pt - center;

        return  ( ((EschVector*)&p)->magnitude() <= radius )
                  ? 1 : 0;
    }
}

int EschExtents::hit(const EschPoint *pt, const Flx16 r) const
{
    EschPoint   p;

    p = *pt - center;

    return  ( ((EschVector*)&p)->magnitude().flx <= (radius.flx + r.flx) )
            ? 1 : 0;
}

//°±² End of module - esexts.cpp ²±°

