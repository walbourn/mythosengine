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
// esextsph.cpp
//
// EschSphereExtents is the container type for spherical extents.
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
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSphereExtents - draw                                                 ³
//                                                                          ³
// Draws the spherical extents of the object.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschSphereExtents::draw(const EschFrameRef *fr, dword clr) const
{
    long                x, y, rd;
    float               r;
    float               hither, yon;
    EschCamera          *cam;
    EschPoint           p;
    EschFrameRef        frame(0);

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschSphereExtents::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschSphereExtents::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//ÄÄÄ Create local->world->eye transform (ignore inverse)
    if (fr)
        fr->orient.concat(&cam->eye.iorient,&frame.orient);
    else
        frame.orient = cam->eye.iorient;

//ÄÄÄ Setup for compare
    yon = cam->yon;
    hither = cam->hither;
    
//ÄÄÄ Transform center into view
    center.transform(&frame,&p);

//ÄÄÄ Scale radius
    r = radius * fr->scalef * cam->radius_factor;

    assertMyth("EschSphereExtents::draw scaled to a negative radius",
               r >= 0);

//ÄÄÄ Check for fully invisible against hither/yon
    if ( (p.z < hither)
         || (p.z > yon)
         || ((p.z + r) < hither)
         || ((p.z - r) > yon) )
        return;

//ÄÄÄ Draw radial extent
    
    if (cam->flags & ESCH_CAM_ORTHO)
    {
        x = long(p.x * cam->xscalar)
            + (cam->vport->vbuff.width>>1);
        y = (cam->vport->vbuff.height>>1)
            - long(p.y * cam->yscalar);
        rd = long((p.x + r) * cam->xscalar)
             + (cam->vport->vbuff.width>>1) - x;
    }
    else
    {
        x = long((p.x * cam->xscalar) / p.z)
            + (cam->vport->vbuff.width>>1);
        y = (cam->vport->vbuff.height>>1)
            - long((p.y * cam->yscalar) / p.z);
        rd = long(((p.x + r) * cam->xscalar) / p.z)
             + (cam->vport->vbuff.width>>1) - x;
    }

    vngo_clip_circle(cam->vport,x,y,rd,clr);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSphereExtents - hit                                                  ³
//                                                                          ³
// Performs an intersection test input in the same coordinate system of the ³
// extents.                                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschSphereExtents::hit(const EschPoint *pt) const
{
    assertMyth("EschSphereExtents::hit needs point",
               pt != 0);

    EschVector  p(pt->x - center.x,
                  pt->y - center.y,
                  pt->z - center.z);

//ÄÄÄ Check for trivial reject
    float r = radius;
    float nr = - r;

    if (p.i > r
        || p.i < nr
        || p.k > r
        || p.k < nr
        || p.j > r
        || p.j < nr)
        return 0;

//ÄÄÄ Check with true magnitude
    return  (((p.magnitude()) < r) ? 1 : 0);
}

int EschSphereExtents::hit(const EschPoint *pt, const float r) const
{
    assertMyth("EschSphereExtents::hit needs point and radius",
               pt != 0 && r >= 0);

    EschVector  p(pt->x - center.x,
                  pt->y - center.y,
                  pt->z - center.z);

//ÄÄÄ Check for trivial reject
    float rs = radius + r;
    float nrs = - rs;

    if (p.i > rs
        || p.i < nrs
        || p.k > rs
        || p.k < nrs
        || p.j > rs
        || p.j < nrs)
        return 0;

//ÄÄÄ Check with true magnitude
    return  (( (p.magnitude()) < rs )
             ? 1 : 0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSphereExtents - ray                                                  ³
//                                                                          ³
// Computes the ray/sphere intersection of the ray starting at point and    ³
// moving along the unit vector ray with the sphere defined by the center   ³
// and the radius.                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
float EschSphereExtents::ray(const EschPoint *pt, const EschVector *v) const
{
    EschVector tvect(center.x - pt->x,
                     center.y - pt->y,
                     center.z - pt->z);

    // tvect DOT v
    float dot = tvect.i*v->i
                + tvect.j*v->j
                + tvect.k*v->k;

    // (radius^2) - (tvect DOT tvect) + (dot * dot)
    float disc = (radius*radius) - (tvect.i*tvect.i
                                    + tvect.j*tvect.j
                                    + tvect.k*tvect.k) + (dot*dot);

    if (disc < 0)
        return 0;

    disc = esch_sqrt(disc);

    float t2 = dot+disc;
    if (t2 <= 0)
        return 0;

    float t1 = dot-disc;
    if (t1 <= 0)
        return t2;

    return t1;
}

//°±² End of module - esextsph.cpp ²±°

