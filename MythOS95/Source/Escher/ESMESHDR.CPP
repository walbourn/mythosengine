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
// esmeshdr.cpp
//
//      Contains the code for the EschMeshDraw object.  This object is
//      associated with an EschMesh object in order to define a drawable
//      instance of the mesh data--this reduces the data requirements for
//      having multiple copies of the same mesh displayed simultaneously.
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
EschMeshDraw::EschMeshDraw(EschMesh *mdata) : EschGeometry()
{
    mesh=0;
    tmax=0;
    txt=0;
    if (mdata)
        attach(mdata);
}

EschMeshDraw::EschMeshDraw(const char *fname, const char *oname,
                           VngoPal *pal, EschMesh *msh, char *pn)
             : EschGeometry()
{
    mesh=0;
    tmax=0;
    txt=0;
    load(fname,oname,pal,msh,pn);
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
// EschMeshDraw - draw                                                      ³
//                                                                          ³
// Draws the mesh object from the associated mesh's data using local        ³
// object storage.                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschMeshDraw::draw(void)
{
    ulong           i;
    int             output_face=0;
    int             doclip;
    dword           cflags;
    dword           level;
    dword           *vflags;
    dword           *fflags;
    VngoPoint       *vpt;
    EschFace        *face;
    EschVertex      *vn;
    EschCamera      *cam;
    EschLight       *lights;
    VngoRect        damage_rect;
    EschPoint       p;
    EschPoint       eyep(0,0,0);
    EschFrameRef    frame;

    assertMyth("EschMeshDraw::draw needs an attached mesh",
               mesh && mesh->ref_count);

//ÄÄÄ Clear arena
    ivory_arena_clear(EschSysInstance->wspace);


//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschMeshDraw::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschMeshDraw::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    cflags = cam->flags;

    assertMyth("EschMeshDraw::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    int mp = cam->vport->vbuff.pal->shd_pal->mid_point;

//ÄÄÄ Clear the objects damage rectangle
    damage_rect.x = cam->vport->vbuff.width;
    damage_rect.y = cam->vport->vbuff.height;
    damage_rect.dx = 0;
    damage_rect.dy = 0;

//ÄÄÄ Perform object radial extents check
    if (!(flags & ESCH_MSHD_NOEXTENTSCHK))
    {

        // Transform center into view
        exts.center.transform(&world,&p);
        p.transform(&cam->eye.iorient);
        
        // Scale radius
        Flx16 r = flx_16mul16( exts.radius, 
                  flx_16mul16( world.scalef, 
                               cam->radius_factor ) );
        r = flx_16mul16(r,Flx16(1.05));
        assertMyth("EschMeshDraw::draw radius scale resulted in negative radius",
                   r.flx >= 0);
        
        // Setup for compare
        Flx16 yon = cam->yon;
        Flx16 hither = cam->hither;
        
        // Check for fully invisible against hither/yon
        if ( ((p.z.flx + r.flx) < hither.flx)
             || ((p.z.flx - r.flx) > yon.flx) )
        {
            EschGeometry::draw();
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
                EschGeometry::draw();
                return;
            }
            
            // See if fully visible or needs clipping
            doclip = ( ((p.z.flx - r.flx) > hither.flx)
                        && ((p.z.flx + r.flx) < yon.flx)
                        && ((p.x.flx - r.flx) > -tx.flx)
                        && ((p.x.flx + r.flx) < tx.flx)
                        && ((p.y.flx - r.flx) > -ty.flx)
                        && ((p.y.flx + r.flx) < ty.flx) ) ? 0 : 1;

        }
        else doclip = 1;
    }
    else doclip = 1;
        
//ÄÄÄ Push drawing context
    EschContext ec(EschCurrent);
    ec.verts = (EschVertex*)ivory_hlock(mesh->v);
    assertMyth("EschMeshDraw:draw lock on verticies failed",
               ec.verts);
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * mesh->nverts);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[mesh->nverts];
    ec.faces = (EschFace*)ivory_hlock(mesh->f);
    assertMyth("EschMeshDraw:draw lock on faces failed",
               ec.faces);
    ec.fflags = fflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * mesh->nfaces);
    ec.txts = txt;
    ec.push();

//ÄÄÄ Workspace for shadeing values, if not shading in modelspace.
    if (!(cflags & ESCH_CAM_MODELSPACE)
        && (cflags & ESCH_CAM_SHADE_SMOOTH))
    {
        vn = (EschVertex*) new (EschSysInstance->wspace) EschVertex[mesh->nverts];
    }

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

//ÄÄÄ Main face loop
    for(i=0, face=ec.faces; i < mesh->nfaces; i++, face++)
    {

        //ÄÄÄ Figure out shade level (take minimum of shade levels for camera/face)
        level = cflags & face->flags;

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

        //ÄÄÄ Transform face's verts
        if (!(vflags[face->a] & ESCH_VVERT_TRANSFORMED))
        {
            ec.verts[face->a].transform(&frame,(EschPoint*)&vpt[face->a]);
            vflags[face->a] |= ESCH_VVERT_TRANSFORMED;

            // Transform vertex to world, if needed, for shading
            if (!(cflags & ESCH_CAM_MODELSPACE)
                && (level & ESCH_CAM_SHADE_SMOOTH))
            {
                ec.verts[face->a].transform(&world,&vn[face->a]);
                ec.verts[face->a].normal.transform(&world,&vn[face->a].normal);
                if (world.scalef.flx != (1<<16))
                    vn[face->a].normal.normalize();
            }
        }

        if (!(vflags[face->b] & ESCH_VVERT_TRANSFORMED))
        {
            ec.verts[face->b].transform(&frame,(EschPoint*)&vpt[face->b]);
            vflags[face->b] |= ESCH_VVERT_TRANSFORMED;

            // Transform vertex to world, if needed, for shading
            if (!(cflags & ESCH_CAM_MODELSPACE)
                && (level & ESCH_CAM_SHADE_SMOOTH))
            {
                ec.verts[face->b].transform(&world,&vn[face->b]);
                ec.verts[face->b].normal.transform(&world,&vn[face->b].normal);
                if (world.scalef.flx != (1<<16))
                    vn[face->b].normal.normalize();
            }
        }

        if (!(vflags[face->c] & ESCH_VVERT_TRANSFORMED))
        {
            vflags[face->c] |= ESCH_VVERT_TRANSFORMED;
            ec.verts[face->c].transform(&frame,(EschPoint*)&vpt[face->c]);

            // Transform vertex to world, if needed, for shading
            if (!(cflags & ESCH_CAM_MODELSPACE)
                && (level & ESCH_CAM_SHADE_SMOOTH))
            {
                ec.verts[face->c].transform(&world,&vn[face->c]);
                ec.verts[face->c].normal.transform(&world,&vn[face->c].normal);
                if (world.scalef.flx != (1<<16))
                    vn[face->c].normal.normalize();
            }
        }



        //ÄÄÄ Compute shading and clip/draw
        if (lights)
        {

            if (cflags & ESCH_CAM_MODELSPACE)
            {
                if (level & ESCH_CAM_SHADE_SPECULAR)
                {

                    if (!(vflags[face->a] & ESCH_VVERT_LIT))
                    {
                        vpt[face->a].shade=0;
                        lights->hishine(&ec.verts[face->a],&vpt[face->a]);
                        vflags[face->a] |= ESCH_VVERT_LIT;
                    }
                    if (!(vflags[face->b] & ESCH_VVERT_LIT))
                    {
                        vpt[face->b].shade=0;
                        lights->hishine(&ec.verts[face->b],&vpt[face->b]);
                        vflags[face->b] |= ESCH_VVERT_LIT;
                    }
                    if (!(vflags[face->c] & ESCH_VVERT_LIT))
                    {
                        vpt[face->c].shade=0;
                        lights->hishine(&ec.verts[face->c],&vpt[face->c]);
                        vflags[face->c] |= ESCH_VVERT_LIT;
                    }
    
                    vpt[face->a].clr=face->color;
                    esch_clipdraw_face(i,doclip,&damage_rect);
                    output_face++;
                    continue;
                }
                else if (level & ESCH_CAM_SHADE_SMOOTH)
                {
    
                    if (!(vflags[face->a] & ESCH_VVERT_LIT))
                    {
                        vpt[face->a].shade=0;
                        lights->shine(&ec.verts[face->a],&vpt[face->a]);
                        vflags[face->a] |= ESCH_VVERT_LIT;
                    }
                    if (!(vflags[face->b] & ESCH_VVERT_LIT))
                    {
                        vpt[face->b].shade=0;
                        lights->shine(&ec.verts[face->b],&vpt[face->b]);
                        vflags[face->b] |= ESCH_VVERT_LIT;
                    }
                    if (!(vflags[face->c] & ESCH_VVERT_LIT))
                    {
                        vpt[face->c].shade=0;
                        lights->shine(&ec.verts[face->c],&vpt[face->c]);
                        vflags[face->c] |= ESCH_VVERT_LIT;
                    }

                    vpt[face->a].clr=face->color;
                    esch_clipdraw_face(i,doclip,&damage_rect);
                    continue;
                }
                else if (level & ESCH_CAM_SHADE_FLAT)
                {
                    EschVertex fnormal(ec.verts[face->a].x,
                                       ec.verts[face->a].y,
                                       ec.verts[face->a].z,
                                       &face->normal);
                    vpt[face->a].clr=face->color;
                    vpt[face->a].shade=0;
                    lights->shine(&fnormal,&vpt[face->a]);

                    esch_clipdraw_face(i,doclip,&damage_rect);
                    continue;
                }
            }
            else
            {
                if (level & ESCH_CAM_SHADE_SPECULAR)
                {

                    if (!(vflags[face->a] & ESCH_VVERT_LIT))
                    {
                        vpt[face->a].shade=0;
                        lights->hishine(&vn[face->a],&vpt[face->a]);
                        vflags[face->a] |= ESCH_VVERT_LIT;
                    }
                    if (!(vflags[face->b] & ESCH_VVERT_LIT))
                    {
                        vpt[face->b].shade=0;
                        lights->hishine(&vn[face->b],&vpt[face->b]);
                        vflags[face->b] |= ESCH_VVERT_LIT;
                    }
                    if (!(vflags[face->c] & ESCH_VVERT_LIT))
                    {
                        vpt[face->c].shade=0;
                        lights->hishine(&vn[face->c],&vpt[face->c]);
                        vflags[face->c] |= ESCH_VVERT_LIT;
                    }
    
                    vpt[face->a].clr=face->color;
                    esch_clipdraw_face(i,doclip,&damage_rect);
                    continue;
                }
                if (level & ESCH_CAM_SHADE_SMOOTH)
                {
                    if (!(vflags[face->a] & ESCH_VVERT_LIT))
                    {
                        vpt[face->a].shade=0;
                        lights->shine(&vn[face->a],&vpt[face->a]);
                        vflags[face->a] |= ESCH_VVERT_LIT;
                    }
                    if (!(vflags[face->b] & ESCH_VVERT_LIT))
                    {
                        vpt[face->b].shade=0;
                        lights->shine(&vn[face->b],&vpt[face->b]);
                        vflags[face->b] |= ESCH_VVERT_LIT;
                    }
                    if (!(vflags[face->c] & ESCH_VVERT_LIT))
                    {
                        vpt[face->c].shade=0;
                        lights->shine(&vn[face->c],&vpt[face->c]);
                        vflags[face->c] |= ESCH_VVERT_LIT;
                    }
    
                    vpt[face->a].clr=face->color;
                    esch_clipdraw_face(i,doclip,&damage_rect);
                    continue;
                }
                else if (level & ESCH_CAM_SHADE_FLAT)
                {
                    EschVertex  fnormal;

                    ec.verts[face->a].transform(&world,&fnormal);
                    face->normal.transform(&world,&fnormal.normal);
                    vpt[face->a].clr=face->color;
                    vpt[face->a].shade=0;
                    lights->shine(&fnormal,&vpt[face->a]);

                    esch_clipdraw_face(i,doclip,&damage_rect);
                    continue;
                }
            }
        }

        vpt[face->a].clr=face->color;
        vpt[face->a].shade=mp;
        esch_clipdraw_face(i,doclip,&damage_rect);
    }

//ÄÄÄ Ensure damage rect is on a word boundary for both origin and width

    if (damage_rect.dx > 0 && damage_rect.dy > 0)
    {
        // Coming in here .dx & .dy are the right edges, not the actual
        // deltas, we must now derive the delta information.
        damage_rect.dx = damage_rect.dx - damage_rect.x;
        damage_rect.dy = damage_rect.dy - damage_rect.y;
        if (damage_rect.x & 0x1)
        {
           // if it is not on an even boundary, put it there.
           damage_rect.x = damage_rect.x - 1;
           // you now need to adjust the width to compensate for it.
           damage_rect.dx++;
        }
        // There is no need to align the Y parameters.
        if (damage_rect.dx & 1)
        {
           if ((damage_rect.dx + damage_rect.x) < (cam->vport->vbuff.width -1 ))
           {
               damage_rect.dx++;
           }
        }
        if ((damage_rect.dx + damage_rect.x + 2) < (cam->vport->vbuff.width -1))
        {
            damage_rect.dx += 2;
        }
        if ((damage_rect.dy + damage_rect.y + 1) < (cam->vport->vbuff.height -1))
        {
            damage_rect.dy++;
        }
        cam->vport->add_hot_rect(new VngoRectList(damage_rect));
    }

//ÄÄÄ Pop drawing context
    ec.pop();
    ivory_hunlock(mesh->v);
    ivory_hunlock(mesh->f);

    EschGeometry::draw();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - attach                                                    ³
//                                                                          ³
// Attaches an EschMesh object.                                             ³
//                                                                          ³
// Returns 0 on success, non-zero otherwise.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes  EschMeshDraw::attach(EschMesh *mdata)
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
    exts = mesh->exts;

    tmax = mesh->tmax;
    txt = mesh->txt;

    flags &= ~ESCH_MSHD_OWNSTEXTURE;

    //ÄÄ Update diags
    EschSysInstance->diag_ifaces += mesh->nfaces;
    EschSysInstance->diag_iverts += mesh->nverts;

    //ÄÄ Update wspace_mbytes diags
    needed = (sizeof(VngoPoint)+sizeof(dword)+sizeof(EschVertex))*mesh->nverts
             + (sizeof(dword))*mesh->nfaces;

    assertMyth("EschMeshDraw::attach needs more workspace than is available",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

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
    EschSysInstance->diag_ifaces -= mesh->nfaces;
    EschSysInstance->diag_iverts -= mesh->nverts;

    //ÄÄ Decrement reference count
    mesh->ref_count--;

    //ÄÄ Free any data, if owned.
    if (flags & ESCH_DRW_OWNSDATA)
    {
        delete mesh;
        flags &= ~ESCH_DRW_OWNSDATA;
    }
    mesh=0;

    if (flags & ESCH_MSHD_OWNSTEXTURE)
    {
        delete txt;
        flags &= ~ESCH_MSHD_OWNSTEXTURE;
    }
    tmax=0;
    txt=0;
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
                                    VngoPal *pal, EschMesh *msh, char *pn)
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
        msh = new EschMesh();
        if (!msh)
            return ESCH_ERR_NOMEMORY;
        flags |= ESCH_DRW_OWNSDATA;
    }

//ÄÄ Load
    if ((err=msh->load(fname,oname,pal,&local.orient,pn))!=0)
    {
        if (flags & ESCH_DRW_OWNSDATA)
            delete msh;
        return err;
    }

    attach(msh);

//ÄÄ Update drawble information
    local.dir.i = local.orient.mtx[ESCH_MTX_G];
    local.dir.j = local.orient.mtx[ESCH_MTX_H];
    local.dir.k = local.orient.mtx[ESCH_MTX_I];

    local.compute_inverse();

    compute_world();
    return ESCH_ERR_NONE;
}

esch_error_codes EschMeshDraw::load(XFParseIFF *iff, const char *oname,
                                    VngoPal *pal, EschMesh *msh, char *pn)

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
        msh = new EschMesh();
        if (!msh)
            return ESCH_ERR_NOMEMORY;
        flags |= ESCH_DRW_OWNSDATA;
    }

//ÄÄ Load
    if ((err=msh->load(iff,oname,pal,&local.orient,pn))!=0)
    {
        delete mesh;
        return err;
    }

    attach(msh);

//ÄÄ Update drawble information
    local.dir.i = local.orient.mtx[ESCH_MTX_G];
    local.dir.j = local.orient.mtx[ESCH_MTX_H];
    local.dir.k = local.orient.mtx[ESCH_MTX_I];

    local.compute_inverse();

    compute_world();
    return ESCH_ERR_NONE;
}

//°±² End of module - esmeshdr.cpp ²±°

