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
//ùùùùùùùùùùùCopyrightù(c)ù1994-1997ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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
// esextbox.cpp
//
// EschBoxExtents is the container type for bounding box extents.
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
// EschBoxExtents - draw                                                    ³
//                                                                          ³
// Draws the box extents of the object.                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschBoxExtents::draw(const EschFrameRef *fr, dword clr) const
{
    EschCamera          *cam;
    VngoVport           *vp;
    EschPoint           p;
    EschFrameRef        frame(0);
    VngoPoint           vpt[8];

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschBoxExtents::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschBoxExtents::draw needs a viewport in current context's camera",
               cam->vport != NULL);
    vp=cam->vport;

//ÄÄÄ Create local->world->eye transform (ignore inverse)
    if (fr)
        fr->orient.concat(&cam->eye.iorient,&frame.orient);
    else
        frame.orient = cam->eye.iorient;

//ÄÄÄ Setup for compare
    float yon = cam->yon;
    float hither = cam->hither;

//ÄÄÄ Box
    int mp = vp->vbuff.pal->shd_pal->mid_point;

//ÄÄÄ For each of the eight points of the extents
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

        // If we cross near or far plane, abort draw of extents
        if (p.z < hither || p.z > yon)
            return;

        vpt[i].x = long((p.x * cam->xscalar) / p.z)
                   + (cam->vport->vbuff.width >> 1);
        vpt[i].y = (cam->vport->vbuff.height >> 1)
                   - long((p.y * cam->yscalar) / p.z);
        vpt[i].z = 0;
        vpt[i].clr = clr;
        vpt[i].shade = mp;
    }

//ÄÄÄ Draw box
    vp->clip_line(&vpt[0],&vpt[1]);
    vp->clip_line(&vpt[1],&vpt[5]);
    vp->clip_line(&vpt[5],&vpt[4]);
    vp->clip_line(&vpt[4],&vpt[0]);
    vp->clip_line(&vpt[2],&vpt[3]);
    vp->clip_line(&vpt[3],&vpt[7]);
    vp->clip_line(&vpt[7],&vpt[6]);
    vp->clip_line(&vpt[6],&vpt[2]);
    vp->clip_line(&vpt[0],&vpt[2]);
    vp->clip_line(&vpt[1],&vpt[3]);
    vp->clip_line(&vpt[5],&vpt[7]);
    vp->clip_line(&vpt[4],&vpt[6]);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBoxExtents - hit                                                     ³
//                                                                          ³
// Performs an intersection test with input in the same coordinate system of³
// the extents.                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschBoxExtents::hit(const EschPoint *pt) const
{
    assertMyth("EschBoxExtents::hit needs point",
               pt != 0);

    return ( (pt->x < mins[0])
              || (pt->x > maxs[0])
              || (pt->z < mins[2])
              || (pt->z > maxs[2])
              || (pt->y < mins[1])
              || (pt->y > maxs[1]) ) ? 0 : 1;
}

int EschBoxExtents::hit(const EschPoint *pt, const float r) const
{
    assertMyth("EschBoxExtents::hit needs point and radius",
               pt != 0 && r >= 0);

    return ( (mins[0] > (pt->x + r))
              || (maxs[0] < (pt->x - r))
              || (mins[2] > (pt->z + r)) 
              || (maxs[2] < (pt->z - r))
              || (mins[1] > (pt->y + r)) 
              || (maxs[1] < (pt->y - r)) ) ? 0 : 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBoxExtents - ray                                                     ³
//                                                                          ³
// Performs a box/ray intersection test with input in the same coordinate   ³
// system of the extents.                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
float EschBoxExtents::ray(const EschPoint *pt, const EschVector *v) const
{
    assertMyth("EschBoxExtents::ray needs point and vector",
               pt != 0 && v != 0);

    int     i;
    int     inside = 1;
    enum
    {
        RIGHT=0,
        LEFT=1,
        MIDDLE=2
    }       quad[3];
    float   candidate[3];
    float   origin[3] = { pt->x, pt->y, pt->z };
    float   dir[3] = { v->i, v->j, v->k };

//ÄÄÄ Find canidate planes
    for(i=0; i < 3 ; i++)
    {
        if (origin[i] < mins[i])
        {
            quad[i] = LEFT;
            if (dir[i] <= 0)
                return 0;

            candidate[i] = mins[i];
            inside = 0;
        }
        else if (origin[i] > maxs[i])
        {
            if (dir[i] >= 0)
                return 0;
            quad[i] = RIGHT;
            candidate[i] = maxs[i];
            inside = 0;
        }
        else
        {
            quad[i] = MIDDLE;
        }
    }

//ÄÄÄ Handle ray origin inside box
    if (inside)
    {
        // Compute distance from ray origin to center of box as distance
        EschVector p(pt->x - mins[0] - ((maxs[0] - mins[0]) / 2.0f),
                     pt->y - mins[1] - ((maxs[1] - mins[1]) / 2.0f),
                     pt->z - mins[2] - ((maxs[2] - mins[2]) / 2.0f));

        return p.magnitude();
    }

//ÄÄÄ Calc T distances to candidate planes and find max
    float dist = -1;

    int whichplane = 0;
    for(i=0; i < 3; i++)
    {
        if (quad[i] != MIDDLE && dir[i] != 0)
        {
            float m = (candidate[i] - origin[i]) / dir[i];

            if (dist < m)
            {
                whichplane = i;
                dist = m;
            }
        }
    }

    if (dist < 0)
        return 0;

    float   coord[3];

    for (i=0; i < 3; i++)
    {
        if (whichplane != i)
        {
            coord[i] = origin[i] + dist * dir[i];
            if ((coord[i] < mins[i])
                || (coord[i] > maxs[i]))
            {
                return 0;
            }
            else
            {
                coord[i] = candidate[i];
            }
        }
    }
    return dist;
}

//°±² End of module - esextbox.cpp ²±°

