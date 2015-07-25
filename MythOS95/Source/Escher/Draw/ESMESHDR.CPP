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
// esmeshdr.cpp
//
// Contains the code for the EschMeshDraw class.  This class is
// associated with an EschMesh object in order to define a drawable
// instance of the mesh data--this reduces the data requirements for
// having multiple copies of the same mesh displayed simultaneously.
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

extern char EschNoName[];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - Constructor                                               ³
//                                                                          ³
// Initializes the class instance.                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschMeshDraw::EschMeshDraw(EschMesh *mdata) :
    EschGeometry(),
    mesh(0),
    tmax(0),
    txt(0)
{
    dtyp = ESCH_DRWT_MESH;

    if (mdata)
        attach(mdata);
}

EschMeshDraw::EschMeshDraw(const char *fname, const char *oname,
                           VngoPal *pal, EschMesh *msh, char *pn,
                           dword ctrlfl) :
    EschGeometry(),
    mesh(0),
    tmax(0),
    txt(0)
{
    dtyp = ESCH_DRWT_MESH;

    load(fname,oname,pal,msh,pn,ctrlfl);
}

EschMeshDraw::EschMeshDraw(const EschMeshDraw &mshd) :
    EschGeometry(mshd),
    mesh (mshd.mesh),
    tmax (mshd.tmax),
    txt (mshd.txt)
{
    flags &= ~(ESCH_DRW_OWNSDATA
               | ESCH_MSHD_OWNSTEXTURE
               | ESCH_MSHD_OWNSNOSTCTXT
               | ESCH_MSHD_OWNSNOMFTXT
               | ESCH_MSHD_OWNSNOPRCTXT);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - Destructor                                                ³
//                                                                          ³
// Detaches the object.                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschMeshDraw:: ~EschMeshDraw()
{
    detach();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - operator =                                                ³
//                                                                          ³
// Copies the data from another mesh draw.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
const EschMeshDraw &EschMeshDraw::operator = (const EschMeshDraw &mshd)
{
    if (this != &mshd)
    {
        detach();

        EschGeometry::operator = (mshd);

        flags &= ~(ESCH_DRW_OWNSDATA
                   | ESCH_MSHD_OWNSTEXTURE
                   | ESCH_MSHD_OWNSNOSTCTXT
                   | ESCH_MSHD_OWNSNOMFTXT
                   | ESCH_MSHD_OWNSNOPRCTXT);

        attach(mshd.mesh);

        tmax = mshd.tmax;
        txt = mshd.txt;
    }
    return *this;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - draw                                                      ³
//                                                                          ³
// Draws the mesh object from the associated mesh's data using local        ³
// object storage.                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschMeshDraw::draw()
{
    ulong           i;
    dword           ctrlfl;
    dword           level;
    dword           facefl;
    dword           cflags;
    int             mp;
    EschFace        *face;
    EschVertex      *vn;
    EschCamera      *cam;
    EschLight       *lights;
    EschPoint       p;
    EschPoint       eyep(0,0,0);
    EschVector      fview;
    EschVertex      fnormal;
    long            base_shade;
    long            shadea;
    long            shadeb;
    long            shadec;
    EschFrameRef    frame(0);

    assertMyth("EschMeshDraw::draw needs an attached mesh",
               mesh && mesh->ref_count);

    //ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschMeshDraw::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschMeshDraw::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Perform object radial extents check
    if (!(flags & ESCH_MSHD_NOEXTENTSCHK))
    {
        // Transform center into view
        exts.center.transform(&world,&p);
        p.transform(&cam->eye.iorient);

        // Scale radius
        float r = exts.radius * world.scalef * cam->radius_factor * 1.05f;

        assertMyth("EschMeshDraw::draw radius scale resulted in negative radius",
                   r >= 0);

        // Setup for compare
        float yon = cam->yon;
        float hither = cam->hither;

        // Check for fully invisible against hither/yon
        if ( ((p.z + r) < hither)
             || ((p.z - r) > yon) )
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
            float tx = p.z * cam->xsize;
            float ty = p.z * cam->ysize;

            // Check for fully invisible against left/right/top/bottom
            if ( ((p.x + r) < -tx)
                 || ((p.x - r) > tx)
                 || ((p.y + r) < -ty)
                 || ((p.y - r) > ty) )
            {
                // Since the extents are inclusive of children, don't
                // need to do anything for children meshes.
                return;
            }

            // See if fully visible or needs clipping
            ctrlfl = ( ((p.z - r) > hither)
                        && ((p.z + r) < yon)
                        && ((p.x - r) > -tx)
                        && ((p.x + r) < tx)
                        && ((p.y - r) > -ty)
                        && ((p.y + r) < ty) ) ? 0 : ESCH_CDF_CLIP;

        }
        else ctrlfl = ESCH_CDF_CLIP;
    }
    else ctrlfl = ESCH_CDF_CLIP;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup
    cflags = cam->flags;

    assertMyth("EschMeshDraw::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    mp = cam->vport->vbuff.pal->shd_pal->mid_point;

    //ÄÄÄ Clear arena
    assertMyth("EschMeshDraw needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    //ÄÄÄ Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;

    //ÄÄÄ Allocate workspace
    ec.verts = (EschVertex*)ivory_hlock(mesh->v);
    assertMyth("EschMeshDraw::draw lock on verticies failed",
               ec.verts != 0);

    ec.faces = (EschFace*)ivory_hlock(mesh->f);
    assertMyth("EschMeshDraw::draw lock on faces failed",
               ec.faces != 0);

    ec.vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,
                                           sizeof(dword) * mesh->nverts);
    assertMyth("EschMeshDraw::draw failed to allocate needed workspace",
               ec.vflags != 0);

    ec.vpoints = (VngoPoint*)ivory_arena_alloc(EschSysInstance->wspace,
                                           sizeof(VngoPoint) * mesh->nverts);
    assertMyth("EschMeshDraw::draw failed to allocate needed workspace",
               ec.vpoints != 0);

    ec.fflags = 0;
    ec.txts = txt;
    ec.push();

    //ÄÄÄ If not doing modelspace lighting, may need vertex workspace
    if (!(cflags & ESCH_CAM_MODELSPACE)
        && (cflags & limits & ESCH_CAM_SHADE_SMOOTH))
    {
        vn = (EschVertex*)ivory_arena_alloc(EschSysInstance->wspace,
                                          sizeof(EschVertex) * mesh->nverts);
        assertMyth("EschMeshDraw::draw failed to allocate needed workspace",
                   vn != 0);
    }
    else
    {
        vn = 0;
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Main Face Loop
    for(i=0, face=ec.faces; i < mesh->nfaces; i++, face++)
    {
        facefl = face->flags;

        //ÄÄÄ Figure out shade level (take minimum of shade levels for
        //ÄÄÄ camera, drawable shade limits, and face)
        level = cflags & facefl & limits;

        //ÄÄÄÄÄÄÄÄÄÄÄÄ Perform backface culling, if allowed, in object space.
        if (level & ESCH_CAM_BACKCULL)
        {
            fview.i = ec.verts[face->a].x - eyep.x;
            fview.j = ec.verts[face->a].y - eyep.y;
            fview.k = ec.verts[face->a].z - eyep.z;

            if ((fview DOT face->normal) > 0)
                continue;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Transform face's verts
        //ÄÄÄ Vertex A
        if (!(ec.vflags[face->a] & ESCH_VVERT_TRANSFORMED))
        {
            ec.vflags[face->a] |= ESCH_VVERT_TRANSFORMED;

            ec.verts[face->a].transform(&frame,
                                        (EschPoint*)(&ec.vpoints[face->a]));

            if (vn && (level & ESCH_CAM_SHADE_SMOOTH))
            {
                ec.verts[face->a].transform(&world,&vn[face->a]);
                ec.verts[face->a].normal.transform(&world,
                                                   &vn[face->a].normal);
                if (world.scalef != 1.0)
                    vn[face->a].normal.normalize();
            }
        }

        //ÄÄÄ Vertex B
        if (!(ec.vflags[face->b] & ESCH_VVERT_TRANSFORMED))
        {
            ec.vflags[face->b] |= ESCH_VVERT_TRANSFORMED;

            ec.verts[face->b].transform(&frame,
                                        (EschPoint*)(&ec.vpoints[face->b]));

            if (vn && (level & ESCH_CAM_SHADE_SMOOTH))
            {
                ec.verts[face->b].transform(&world,&vn[face->b]);
                ec.verts[face->b].normal.transform(&world,
                                                   &vn[face->b].normal);
                if (world.scalef != 1.0)
                    vn[face->b].normal.normalize();
            }
        }

        //ÄÄÄ Vertex C
        if (!(ec.vflags[face->c] & ESCH_VVERT_TRANSFORMED))
        {
            ec.vflags[face->c] |= ESCH_VVERT_TRANSFORMED;

            ec.verts[face->c].transform(&frame,
                                        (EschPoint*)(&ec.vpoints[face->c]));

            if (vn && (level & ESCH_CAM_SHADE_SMOOTH))
            {
                ec.verts[face->c].transform(&world,&vn[face->c]);
                ec.verts[face->c].normal.transform(&world,
                                                   &vn[face->c].normal);
                if (world.scalef != 1.0)
                    vn[face->c].normal.normalize();
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Compute shading

        //ÄÄÄ Sets color (assumes draw face copies into face->b and face->c)
        ec.vpoints[face->a].clr=face->color;

        //ÄÄÄ Sets shade value
        if (lights)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Smooth shading
            if (level & ESCH_CAM_SHADE_SMOOTH)
            {
                int revnormal = !(facefl & ESCH_FACE_ONESIDED);

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ World Shading
                if (vn)
                {
                    //ÄÄÄ Vertex A
                    if (!(ec.vflags[face->a] & ESCH_VVERT_LIT))
                    {
                        ec.vflags[face->a] |= ESCH_VVERT_LIT;

                        ec.vpoints[face->a].shade=0;

                        if (level & ESCH_CAM_SHADE_SPECULAR)
                        {
                            lights->hishine(&vn[face->a],
                                            &ec.vpoints[face->a],
                                            revnormal);
                        }
                        else
                        {
                            lights->shine(&vn[face->a],
                                          &ec.vpoints[face->a],
                                          revnormal);
                        }
                    }

                    //ÄÄÄ Vertex B
                    if (!(ec.vflags[face->b] & ESCH_VVERT_LIT))
                    {
                        ec.vflags[face->b] |= ESCH_VVERT_LIT;

                        ec.vpoints[face->b].shade=0;

                        if (level & ESCH_CAM_SHADE_SPECULAR)
                        {
                            lights->hishine(&vn[face->b],
                                            &ec.vpoints[face->b],
                                            revnormal);
                        }
                        else
                        {
                            lights->shine(&vn[face->b],
                                          &ec.vpoints[face->b],
                                          revnormal);
                        }
                    }

                    //ÄÄÄ Vertex C
                    if (!(ec.vflags[face->c] & ESCH_VVERT_LIT))
                    {
                        ec.vflags[face->c] |= ESCH_VVERT_LIT;

                        ec.vpoints[face->c].shade=0;

                        if (level & ESCH_CAM_SHADE_SPECULAR)
                        {
                            lights->hishine(&vn[face->c],
                                            &ec.vpoints[face->c],
                                            revnormal);
                        }
                        else
                        {
                            lights->shine(&vn[face->c],
                                          &ec.vpoints[face->c],
                                          !(facefl & ESCH_FACE_ONESIDED));
                        }
                    }
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Modelspace Shading
                else
                {
                    //ÄÄÄ Vertex A
                    if (!(ec.vflags[face->a] & ESCH_VVERT_LIT))
                    {
                        ec.vflags[face->a] |= ESCH_VVERT_LIT;

                        ec.vpoints[face->a].shade=0;

                        if (level & ESCH_CAM_SHADE_SPECULAR)
                        {
                            lights->hishine(&ec.verts[face->a],
                                            &ec.vpoints[face->a],
                                            revnormal);
                        }
                        else
                        {
                            lights->shine(&ec.verts[face->a],
                                          &ec.vpoints[face->a],
                                          revnormal);
                        }
                    }

                    //ÄÄÄ Vertex B
                    if (!(ec.vflags[face->b] & ESCH_VVERT_LIT))
                    {
                        ec.vflags[face->b] |= ESCH_VVERT_LIT;

                        ec.vpoints[face->b].shade=0;

                        if (level & ESCH_CAM_SHADE_SPECULAR)
                        {
                            lights->hishine(&ec.verts[face->b],
                                            &ec.vpoints[face->b],
                                            revnormal);
                        }
                        else
                        {
                            lights->shine(&ec.verts[face->b],
                                          &ec.vpoints[face->b],
                                          revnormal);
                        }
                    }

                    //ÄÄÄ Vertex C
                    if (!(ec.vflags[face->c] & ESCH_VVERT_LIT))
                    {
                        ec.vflags[face->c] |= ESCH_VVERT_LIT;

                        ec.vpoints[face->c].shade=0;

                        if (level & ESCH_CAM_SHADE_SPECULAR)
                        {
                            lights->hishine(&ec.verts[face->c],
                                            &ec.vpoints[face->c],
                                            revnormal);
                        }
                        else
                        {
                            lights->shine(&ec.verts[face->c],
                                          &ec.vpoints[face->c],
                                          revnormal);
                        }
                    }
                }
            }
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Flat shading
            else if (level & ESCH_CAM_SHADE_FLAT)
            {
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

                ec.vpoints[face->a].shade=0;

                if (level & ESCH_CAM_SHADE_SPECULAR)
                {
                    lights->hishine(&fnormal,
                                    &ec.vpoints[face->a],
                                    !(facefl & ESCH_FACE_ONESIDED));
                }
                else
                {
                    lights->shine(&fnormal,
                                  &ec.vpoints[face->a],
                                  !(facefl & ESCH_FACE_ONESIDED));
                }
            }
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ No shading
            else
            {
                ec.vpoints[face->a].shade=mp;
            }
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ No lights, so no shading
        else
        {
            ec.vpoints[face->a].shade=mp;
            ec.vpoints[face->b].shade=mp;
            ec.vpoints[face->c].shade=mp;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Call clip draw
        if (!face->self_illum)
        {
            esch_clipdraw_face(i,ctrlfl);
        }
        else
        {
            base_shade = (mp*long(face->self_illum)) / 255;

            shadea = ec.vpoints[face->a].shade;
            if (shadea < base_shade)
                ec.vpoints[face->a].shade = base_shade;

            shadeb = ec.vpoints[face->b].shade;
            if (shadeb < base_shade)
                ec.vpoints[face->b].shade = base_shade;

            shadec = ec.vpoints[face->c].shade;
            if (shadec < base_shade)
                ec.vpoints[face->c].shade = base_shade;

            esch_clipdraw_face(i,ctrlfl);

            ec.vpoints[face->a].shade = shadea;
            ec.vpoints[face->b].shade = shadeb;
            ec.vpoints[face->c].shade = shadec;
        }
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Cleanup
    ec.pop();
    ivory_hunlock(mesh->v);
    ivory_hunlock(mesh->f);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Call onto base
    EschGeometry::draw();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - ray                                                       ³
//                                                                          ³
// Performs a ray intersection test with the object (or its extents),       ³
// returning the distance along the ray for the intersection.               ³
// It returns a zero if it missed the object, a positive distance along the ³
// ray if it hit, or -1 if the intersection is not supported.               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
float EschMeshDraw::ray(const EschPoint *pt, const EschVector *v, int coarse) const
{
    float   dist;

    assertMyth("EschMeshDraw::ray needs an attached mesh",
               mesh && mesh->ref_count);

    assertMyth("EschMeshDraw::ray assumes original extents in 'sphere'",
               sphere != 0 && sphere->radius >= 0);

//ÄÄÄ Transform ray into local coordinates
    EschPoint   point;
    pt->transform(&world.iorient,&point);

    EschVector  ray;
    v->transform(&world.iorient,&ray);
    ray.normalize();

//ÄÄÄ Perform coarse check, returning if coarse fails to detect a hit
//ÄÄÄ (Ray/Sphere intersection)
    dist=sphere->ray(&point,&ray);

    if (dist <= 0)
        return 0;

    //ÄÄÄ If doing coarse only, return result now
    if (coarse)
        return ((world.scalef == 1.0) ? dist : (dist * world.scalef));

//ÄÄÄ Perform fine check (Ray/Box intersection)
    dist=mesh->box.ray(&point,&ray);

    if (dist <= 0)
        return 0;

    return ((world.scalef == 1) ? dist : (dist * world.scalef));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - hit                                                       ³
//                                                                          ³
// Performs a sphere intersection test with the object (or its extents),    ³
// returning 1 if it hit, 0 if it missed, -1 if not supported.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschMeshDraw::hit(const EschPoint *pt, const float r, int coarse) const
{
    assertMyth("EschMeshDraw::hit needs point and radius",
               pt != 0 && r >= 0);

    assertMyth("EschMeshDraw::hit needs an attached mesh",
               mesh && mesh->ref_count);

    assertMyth("EschMeshDraw::hit assumes original extents in 'sphere'",
               sphere != 0 && sphere->radius >= 0);

    EschPoint   center;
    pt->transform(&world.iorient,&center);

    float radius = (world.scalef == 1.0)
                   ? r : (r / world.scalef);

    // Box hit is actually cheaper than sphere/sphere test and more
    // accurate when the target sphere is in world coords.
    return mesh->box.hit(&center,radius);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - animate                                                   ³
//                                                                          ³
// This call is used to inform the drawable to animate itself for the next  ³
// frame.  This is called directly by the application when needed.          ³
// The base behavior for a mesh draw is to call animate for each texture    ³
// in the texture list.                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschMeshDraw::animate()
{
    if (!txt)
        return;

    for(ulong i=0; i < tmax; i++)
    {
        EschTexture *t = txt[i];
        if (!(t->flags & ESCH_TXT_SKIPANIMATE))
            t->animate();
    }

    EschGeometry::animate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - attach                                                    ³
//                                                                          ³
// Attaches an EschMesh object.                                             ³
//                                                                          ³
// Returns 0 on success, non-zero otherwise.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschMeshDraw::attach(EschMesh *mdata, dword update)
{
    ulong   needed;

    if (!mdata)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄ Detach frame mesh, if any
    if (mesh)
    {
        detach();
    }

//ÄÄ Attach new mesh
    mesh = mdata;
    mdata->ref_count++;

    assertMyth("EschMeshDraw::attach mesh reference must have non-zero nverts/nfaces",
               mesh->nverts && mesh->nfaces);

    //ÄÄ Get initial information from mesh data.
    name = mesh->name;
    sphere = &mesh->sphere;

    tmax = mesh->tmax;
    txt = mesh->txt;

    flags &= ~(ESCH_MSHD_OWNSTEXTURE
               | ESCH_MSHD_OWNSNOSTCTXT
               | ESCH_MSHD_OWNSNOMFTXT
               | ESCH_MSHD_OWNSNOPRCTXT);

    //ÄÄ Update diags
    assertMyth("EschMeshDraw needs Escher initialized",EschSysInstance != 0);
    EschSysInstance->diag_ifaces += mesh->nfaces;
    EschSysInstance->diag_iverts += mesh->nverts;

    //ÄÄ Update wspace_mbytes diags
    needed = (sizeof(VngoPoint)+sizeof(dword)+sizeof(EschVertex))*mesh->nverts;

    assertMyth("EschMeshDraw::attach needs more workspace than is available",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

//ÄÄ Our extents probably changed, so rebuild if requested
    if (update & ESCH_UPD_EXTENTS)
    {
        compute_extents();
    }

//ÄÄ Return success
    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - detach                                                    ³
//                                                                          ³
// Detaches an EschMesh object.                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschMeshDraw::detach()
{
    if (!mesh)
        return;

    name=EschNoName;

//ÄÄ Detach reference.

    assertMyth("EschMeshDraw::detach, mesh already has a zero reference count",
               mesh->ref_count);

    //ÄÄ Update diags
    assertMyth("EschMeshDraw needs Escher initialized",EschSysInstance != 0);
    EschSysInstance->diag_ifaces -= mesh->nfaces;
    EschSysInstance->diag_iverts -= mesh->nverts;

    //ÄÄ Decrement reference count
    mesh->ref_count--;

    //ÄÄ Free any data, if owned.
    if (flags & ESCH_DRW_OWNSDATA)
    {
        delete mesh;
    }
    mesh=0;

    if (flags & ESCH_MSHD_OWNSTEXTURE)
    {
        for(ulong i=0; i < tmax; i++)
        {
            if (txt[i])
            {
                switch (txt[i]->get_type() & ESCH_TXTT_BASEMASK)
                {
                    case ESCH_TXTT_STATIC:
                        if (!(flags & ESCH_MSHD_OWNSNOSTCTXT))
                            delete txt[i];
                        break;
                    case ESCH_TXTT_MFRAME:
                        if (!(flags & ESCH_MSHD_OWNSNOMFTXT))
                            delete txt[i];
                        break;
                    case ESCH_TXTT_PRC:
                        if (!(flags & ESCH_MSHD_OWNSNOPRCTXT))
                            delete txt[i];
                        break;
                    default:
                        delete txt[i];
                        break;
                }
            }
        }
        delete [] txt;
    }
    tmax=0;
    txt=0;

    flags &= ~(ESCH_DRW_OWNSDATA
               | ESCH_MSHD_OWNSTEXTURE
               | ESCH_MSHD_OWNSNOSTCTXT
               | ESCH_MSHD_OWNSNOMFTXT
               | ESCH_MSHD_OWNSNOPRCTXT);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                              °°° private °°°                             ³
// EschMeshDraw - clone_helper                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschMeshDraw *EschMeshDraw::clone_helper(EschMeshDraw *_parent,
                                         const EschMeshDraw *_refmsh,
                                         int dupmf)
{
    EschMeshDraw *head=0;

    while(_refmsh != 0)
    {
        //ÄÄÄ Create copy of current reference mesh draw instance
        EschMeshDraw *mptr = new EschMeshDraw(*_refmsh);

        // Need to attach, but must prevent invalid 'detach()' from copy...
        mptr->mesh = 0;
        if (mptr->attach(_refmsh->mesh))
        {
            delete mptr;
            goto error_exit;
        }

        //ÄÄÄ See if there are any mframe instances of textures to dup
        if (dupmf && mptr->txt)
        {
            for(ulong i=0; i < mptr->tmax; i++)
            {
                if (mptr->txt[i]
                    && ((mptr->txt[i]->get_type()
                        & ESCH_TXTT_BASEMASK) == ESCH_TXTT_MFRAME))
                    break;
            }

            //ÄÄÄ Must create our own instances of mframe textures
            if (i < mptr->tmax)
            {
                mptr->txt = new EschTexture*[mptr->tmax];
                if (!mptr->txt)
                {
                    delete mptr;
                    goto error_exit;
                }
                memset(mptr->txt,0,sizeof(EschTexture*)*mptr->tmax);

                mptr->set_flags(mptr->flags | ESCH_MSHD_OWNSTEXTURE
                                            | ESCH_MSHD_OWNSNOSTCTXT
                                            | ESCH_MSHD_OWNSNOPRCTXT);

                for(i=0; i < mptr->tmax; i++)
                {
                    EschTexture *txt = mptr->mesh->txt[i];

                    if (txt
                        && ((txt->get_type()
                            & ESCH_TXTT_BASEMASK) == ESCH_TXTT_MFRAME))
                    {
                        EschTexture *t;
                        if (txt->flags & ESCH_TXT_SHARED)
                        {
                            t=EschTexture::cache_new(txt->name);
                            assert(t != 0);
                        }
                        else
                        {
                            t=new EschMultiFrameTexture(
                                             *((EschMultiFrameTexture*)txt));
                        }

                        if (!t)
                        {
                            delete mptr;
                            goto error_exit;
                        }

                        mptr->txt[i] = t;
                    }
                    else
                    {
                        mptr->txt[i] = txt;
                    }
                }
            }
        }

        //ÄÄÄ Recurse for children
        if (_refmsh->child())
        {
            if (!clone_helper(mptr,(const EschMeshDraw*)_refmsh->child(),dupmf))
            {
                delete mptr;
                goto error_exit;
            }
        }

        mptr->compute_world();

        if (_parent)
        {
            mptr->adopt(_parent);
            if (!head)
                head = mptr;

            _refmsh = (const EschMeshDraw*)_refmsh->next();
        }
        else
        {
            // If we are the root, don't copy our siblings into the
            // new clone, only ourselves and our children!
            return mptr;
        }
    }

    return head;

error_exit :;
    while(head != 0)
    {
        EschMeshDraw *tmp = head;
        head = (EschMeshDraw*)head->next();
        tmp->remove(1);
        delete tmp;
    }

    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - load                                                      ³
//                                                                          ³
// Loads a mesh, creating the Mesh object if not provided, attaches it,     ³
// and sets orientation information from the mesh record, if any.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschMeshDraw::load(const char *fname, const char *oname,
                                    VngoPal *pal, EschMesh *msh, char *pn,
                                    dword ctrlfl)
{
   esch_error_codes err;

//ÄÄ Detach frame mesh, if any
    if (mesh)
    {
        detach();
    }

//ÄÄ Create mesh, if needed
    if (!msh)
    {
        msh = new EschMesh;
        if (!msh)
            return ESCH_ERR_NOMEMORY;
        flags |= ESCH_DRW_OWNSDATA;
    }

    local.orient.reset();

//ÄÄ Load
    if ((err=msh->load(fname,oname,pal,&local.orient,pn,ctrlfl)) != 0)
        return err;

//ÄÄ Attach
    if ((err=attach(msh)) != 0)
        return err;

//ÄÄ Update drawble information
    local.dir.i = local.orient.mtx[ESCH_MTX_G];
    local.dir.j = local.orient.mtx[ESCH_MTX_H];
    local.dir.k = local.orient.mtx[ESCH_MTX_I];

    local.compute_inverse();

    compute_world();
    return ESCH_ERR_NONE;
}

esch_error_codes EschMeshDraw::load(XFParseIFF *iff, const char *oname,
                                    VngoPal *pal, EschMesh *msh, char *pn,
                                    dword ctrlfl)

{
   esch_error_codes err;

//ÄÄ Detach frame mesh, if any
    if (mesh)
    {
        detach();
    }

//ÄÄ Create mesh, if needed
    if (!msh)
    {
        msh = new EschMesh;
        if (!msh)
            return ESCH_ERR_NOMEMORY;
        flags |= ESCH_DRW_OWNSDATA;
    }

    local.orient.reset();

//ÄÄ Load
    if ((err=msh->load(iff,oname,pal,&local.orient,pn,ctrlfl))!=0)
        return err;

//ÄÄ Attach
    if ((err=attach(msh)) != 0)
        return err;

//ÄÄ Update drawble information
    local.dir.i = local.orient.mtx[ESCH_MTX_G];
    local.dir.j = local.orient.mtx[ESCH_MTX_H];
    local.dir.k = local.orient.mtx[ESCH_MTX_I];

    local.compute_inverse();

    compute_world();
    return ESCH_ERR_NONE;
}

//°±² End of module - esmeshdr.cpp ²±°

