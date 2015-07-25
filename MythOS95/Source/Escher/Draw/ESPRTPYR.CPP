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
// esprtpyr.cpp
//
// Contains the code for the EschParticlePyramid class which is a 
// colored polygonal pyramid in 3-space with various control attributes.
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
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschParticlePyramid - Constructor                                        ³
//                                                                          ³
// Initializes the particle.                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschParticlePyramid::EschParticlePyramid(Flx16 s, Flx16 ix, Flx16 iy, Flx16 iz,
                           dword c, ulong l) :
    EschParticle(ix,iy,iz,c,l),
    size(s),
    rotate_i(0),
    rotate_j(0),
    rotate_k(0)
{
    dtyp = ESCH_DRWT_PRTPYRAMID;
    check_workspace();
}

EschParticlePyramid::EschParticlePyramid(Flx16 s, Flx16 ix, Flx16 iy, Flx16 iz,
                           Flx16 ii, Flx16 ij, Flx16 ik,
                           dword c, ulong l) :
    EschParticle(ix,iy,iz,ii,ij,ik,c,l),
    size(s),
    rotate_i(0),
    rotate_j(0),
    rotate_k(0)
{
    dtyp = ESCH_DRWT_PRTPYRAMID;
    check_workspace();
}

EschParticlePyramid::EschParticlePyramid(Flx16 s, const EschPoint *p,
                           const EschVector *v,
                           dword c, ulong l) :
    EschParticle(p,v,c,l),
    size(s),
    rotate_i(0),
    rotate_j(0),
    rotate_k(0)
{
    dtyp = ESCH_DRWT_PRTPYRAMID;
    check_workspace();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                          °°° Protected °°°                               ³
// EschParticlePyramid - check_workspace                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschParticlePyramid::check_workspace()
{
    assertMyth("EschPariticlePyramid needs Escher initialized",EschSysInstance != 0);

    //ÄÄ Update wspace_mbytes diags
    dword needed = (sizeof(VngoPoint)+sizeof(dword)+(2*sizeof(EschVertex))
                    +sizeof(EschFace))
                   *4;

    assertMyth("EschParticlePryamid needs more workspace than is available",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschParticlePyramid - draw                                               ³
//                                                                          ³
// Draws the given particle using the current drawing context at the        ³
// current position.                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschParticlePyramid::draw()
{
    int             i;
    dword           ctrlfl;
    dword           *vflags;
    VngoPoint       *vpt;
    EschFace        *face;
    EschVertex      *vn;
    EschCamera      *cam;
    EschLight       *lights;
    EschPoint       p;
    EschPoint       eyep(0,0,0);
    EschFrameRef    frame(0);

    assertMyth("EschParticlePyramid::draw needs valid size", size > 0);

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschParticlePyramid::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschParticlePyramid::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Perform radial extents check
    // Transform center into view
    p.x = 0;  p.y = 0;  p.z = 0;
    p.transform(&world);
    p.transform(&cam->eye.iorient);
    
    // Scale radius
    Flx16 r = flx_16mul16( size, 
              flx_16mul16( world.scalef, 
                           cam->radius_factor ) );
    r = flx_16mul16(r,Flx16(1.05));

    assertMyth("EschParticlePyramid::draw radius scale resulted in negative radius",
               r.flx >= 0);
    
    // Setup for compare
    Flx16 yon = cam->yon;
    Flx16 hither = cam->hither;
    
    // Check for fully invisible against hither/yon
    if ( ((p.z.flx + r.flx) < hither.flx)
         || ((p.z.flx - r.flx) > yon.flx) )
    {
        // Since the extents are inclusive of children, don't
        // need to do anything for children meshes.
        return;
    }
    
    // If center is positive, then we can check against other planes
    // and for fully visible (will need changing later for more general
    // case)
    if (p.z > 0)
    {
        Flx16 tx = flx_16mul16(p.z , cam->xsize);
        Flx16 ty = flx_16mul16(p.z , cam->ysize);
        
        // Check for fully invisible against left/right/top/bottom
        if ( ((p.x.flx + r.flx) < -tx.flx)
             || ((p.x.flx - r.flx) > tx.flx)
             || ((p.y.flx + r.flx) < -ty.flx)
             || ((p.y.flx - r.flx) > ty.flx) )
        {
            return;
        }
        
        // See if fully visible or needs clipping
        ctrlfl = ( ((p.z.flx - r.flx) > hither.flx)
                    && ((p.z.flx + r.flx) < yon.flx)
                    && ((p.x.flx - r.flx) > -tx.flx)
                    && ((p.x.flx + r.flx) < tx.flx)
                    && ((p.y.flx - r.flx) > -ty.flx)
                    && ((p.y.flx + r.flx) < ty.flx) ) ? 0 : ESCH_CDF_CLIP;

    }
    else ctrlfl = ESCH_CDF_CLIP;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup
    dword cflags = cam->flags;
    dword level = cflags & limits;

    assertMyth("EschParticlePyramid::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    int mp = cam->vport->vbuff.pal->shd_pal->mid_point;

    //ÄÄÄ Clear arena
    ivory_arena_clear(EschSysInstance->wspace);
    
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = new (EschSysInstance->wspace) EschVertex[4];
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 4);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[4];
    ec.faces = new (EschSysInstance->wspace) EschFace[4];
    ec.fflags = 0;
    ec.txts = 0;
    ec.push();

    //ÄÄÄ Workspace for shadeing values, if not shading in modelspace.
    if (!(cflags & ESCH_CAM_MODELSPACE)
        && (cflags & (ESCH_CAM_SHADE_SMOOTH|ESCH_CAM_SHADE_SPECULAR)))
    {
        vn = (EschVertex*) new (EschSysInstance->wspace) EschVertex[4];
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Misc Setup
    //ÄÄÄ Create local->world->eye transform
    world.orient.concat(&cam->eye.iorient,&frame.orient);
    cam->eye.orient.concat(&world.iorient,&frame.iorient);

    //ÄÄÄ Get camera into object coords if needed for backculling.
    if (cflags & ESCH_CAM_BACKCULL)
    {
        eyep.transform(&frame.iorient);
    }

    //ÄÄÄ Setup lights, if any
    lights = EschCurrent->lights;
    if (lights)
    {
        lights->setup(&world);
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup Pyramid

//ÄÄÄ Create 4 verticies
//
// (X/Y plane)
//
//      0
//      |
//      |
//      +--*--2
//      | [3]
//      |
//      1
//

    Flx16 size_half = Flx16(size.flx >> 1,0);

    ec.verts[0].x = -size_half;
    ec.verts[0].y = size_half;
    ec.verts[0].z = -size_half;
    ec.verts[0].normal.i = Flx16(0.440094);
    ec.verts[0].normal.j = Flx16(-0.838745);
    ec.verts[0].normal.k = Flx16(0.321503);

    ec.verts[1].x = -size_half;
    ec.verts[1].y = -size_half;
    ec.verts[1].z = -size_half;
    ec.verts[1].normal.i = Flx16(0.440094);
    ec.verts[1].normal.j = Flx16(0.838745);
    ec.verts[1].normal.k = Flx16(0.321503);

    ec.verts[2].x = size_half;
    ec.verts[2].y = 0;
    ec.verts[2].z = -size_half;
    ec.verts[2].normal.i = Flx16(-0.840271);
    ec.verts[2].normal.j = Flx16(0);
    ec.verts[2].normal.k = Flx16(0.542511);

    ec.verts[3].x = 0;
    ec.verts[3].y = 0;
    ec.verts[3].z = size_half;
    ec.verts[3].normal.i = Flx16(0.024384);
    ec.verts[3].normal.j = Flx16(0);
    ec.verts[3].normal.k = Flx16(-0.999710);

//ÄÄÄ Create 4 faces
    dword fflags = (limits & (ESCH_FACE_WIRE
                              | ESCH_FACE_SOLID
                              | ESCH_FACE_FLAT
                              | ESCH_FACE_SMOOTH
                              | ESCH_FACE_SPECULAR
                              | ESCH_FACE_ONESIDED))
                   | ESCH_FACE_ABLINE
                   | ESCH_FACE_BCLINE
                   | ESCH_FACE_CALINE;

    ec.faces[0].color = color;
    ec.faces[0].flags = fflags;
    ec.faces[0].a = 0;
    ec.faces[0].b = 1;
    ec.faces[0].c = 2;
    ec.faces[0].normal.i = Flx16(0);
    ec.faces[0].normal.j = Flx16(0);
    ec.faces[0].normal.k = Flx16(1);

    ec.faces[1].color = color;
    ec.faces[1].flags = fflags;
    ec.faces[1].a = 3;
    ec.faces[1].b = 0;
    ec.faces[1].c = 2;
    ec.faces[1].normal.i = Flx16(-0.436432);
    ec.faces[1].normal.j = Flx16(-0.872864);
    ec.faces[1].normal.k = Flx16(-0.218216);

    ec.faces[2].color = color;
    ec.faces[2].flags = fflags;
    ec.faces[2].a = 3;
    ec.faces[2].b = 2;
    ec.faces[2].c = 1;
    ec.faces[2].normal.i = Flx16(-0.436432);
    ec.faces[2].normal.j = Flx16(0.872864);
    ec.faces[2].normal.k = Flx16(-0.218216);

    ec.faces[3].color = color;
    ec.faces[3].flags = fflags;
    ec.faces[3].a = 3;
    ec.faces[3].b = 1;
    ec.faces[3].c = 0;
    ec.faces[3].normal.i = Flx16(0.894424);
    ec.faces[3].normal.j = Flx16(0);
    ec.faces[3].normal.k = Flx16(-0.447205);

//ÄÄÄ Transform and light (if possible) the verticies
    for(i=0; i < 4; i++)
    {
        vflags[i] = ESCH_VVERT_TRANSFORMED;
        ec.verts[i].transform(&frame,(EschPoint*)&vpt[i]);
        vpt[i].clr=color;
        vpt[i].shade=mp;
        
        // Transform vertex to world, if needed, for shading
        if (!(cflags & ESCH_CAM_MODELSPACE)
            && (level & ESCH_CAM_SHADE_SMOOTH))
        {
            ec.verts[i].transform(&world,&vn[i]);
            ec.verts[i].normal.transform(&world,&vn[i].normal);
            if (world.scalef.flx != (1<<16))
                vn[i].normal.normalize();
        }

        if (lights)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Smooth/Specular shading
            if (level & (ESCH_CAM_SHADE_SPECULAR|ESCH_CAM_SHADE_SMOOTH))
            {
                if (!(vflags[i] & ESCH_VVERT_LIT))
                {
                    vpt[i].shade=0;

                    if (level & ESCH_CAM_SHADE_SPECULAR)
                    {
                        lights->hishine((cflags & ESCH_CAM_MODELSPACE) ?
                                        &ec.verts[i]
                                        : &vn[i],&vpt[i]);
                    }
                    else
                    {
                        lights->shine((cflags & ESCH_CAM_MODELSPACE) ?
                                      &ec.verts[i]
                                      : &vn[i],&vpt[i]);
                    }
                    vflags[i] |= ESCH_VVERT_LIT;
                }
            }
            else if (!(level & ESCH_CAM_SHADE_FLAT))
                vflags[i] |= ESCH_VVERT_LIT;
        }
    }
    
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw Face Loop
    for(i=0, face=ec.faces; i < 4; i++, face++)
    {
        //ÄÄÄ Perform backface culling, if allowed, in object space.
        if (level & ESCH_CAM_BACKCULL)
        {
            EschVector fview;
            fview.i.flx = ec.verts[face->a].x.flx - eyep.x.flx;
            fview.j.flx = ec.verts[face->a].y.flx - eyep.y.flx;
            fview.k.flx = ec.verts[face->a].z.flx - eyep.z.flx;

            if ((fview DOT face->normal).flx > 0)
                continue;
        }

        //ÄÄÄ Compute shading (only if we couldn't above)
        if (lights)
        {
            if (level & ESCH_CAM_SHADE_FLAT)
            {
                EschVertex  fnormal;

                if (cflags & ESCH_CAM_MODELSPACE)
                {
                    fnormal.x = ec.verts[face->a].x;
                    fnormal.y = ec.verts[face->a].y;
                    fnormal.z = ec.verts[face->a].z;
                    fnormal.normal.i = face->normal.i;
                    fnormal.normal.j = face->normal.j;
                    fnormal.normal.k = face->normal.k;
                }
                else
                {
                    ec.verts[face->a].transform(&world,&fnormal);
                    face->normal.transform(&world,&fnormal.normal);
                }

                vpt[face->a].shade=0;
                lights->shine(&fnormal,&vpt[face->a]);
            }
        }

        //ÄÄÄ Call clip draw
        esch_clipdraw_face(i,ctrlfl);
    }

//ÄÄÄ Pop drawing context
    ec.pop();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschParticlePyramid - animate                                            ³
//                                                                          ³
// Performs any operations needed to move the particle to the next frame,   ³
// including life tests for death of the particle.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschParticlePyramid::animate()
{
    EschParticle::animate();

    if (interval == 0)
        return;

    if (rotate_i != 0)
        world.pitch(rotate_i * interval,0);

    if (rotate_j != 0)
        world.yaw(rotate_j * interval,0);

    if (rotate_k != 0)
        world.roll(rotate_k * interval,0);

    world.set_position(pos.x, pos.y, pos.z);
}

//°±² End of module - espartik.cpp ²±°

