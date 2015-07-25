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
// esterran.cpp
//
// Height-field polygonal terrain drawable.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <xfile.hpp>

#include "escher.hpp"
#include "esfile.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - constructor                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschTerrain::EschTerrain(const char *fname, const char *tname)
{
//ÄÄ Set initial values
    width=depth=0;

    hfield=0;
    surfinfo=0;
    hsurfnorml=0;

    tmax=0;
    txtcolor=0;
    txt=0;

    surfratio=1;                        // 1:1 Height:Surface data ratio
    origin.x=origin.y=origin.z=0;
                                        // Assumes world unit is a meter
                                        // and DEM standard is being used
                                        // for data (30 meter per grid, with
                                        // each 8-bit value representing
                                        // 16 meters
    hscale=16;
    wscale=dscale=30;
    lodmedium=lodlow=0;

//ÄÄ Load data set, if requested
    if (fname)
        load(fname,tname);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - destructor                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschTerrain::~EschTerrain()
{
    release();
};


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                          °°° Protected °°°                               ³
// compute_area                                                             ³
//                                                                          ³
// Computes starting and ending width and depth array indicies for projected³
// area.  Returns 0 if degenerate case (end and start are equal or end is   ³
// greater than start.                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschTerrain::compute_area(Flx16 lox, Flx16 loz, Flx16 hix, Flx16 hiz,
                              int *sw, int *ew, int *sd, int *ed, int bits)
{
    assertMyth("EschTerrain:compute_area needs positive w/dscale",
               wscale.flx > 0 && dscale.flx > 0);

    //ÄÄÄÄ Adjust to origin
    lox.flx = lox.flx - origin.x.flx;
    loz.flx = loz.flx - origin.z.flx;
    hix.flx = hix.flx - origin.x.flx;
    hiz.flx = hiz.flx - origin.z.flx;
    
    //ÄÄÄÄ Convert to index

    // Width start
    if (lox.flx <= 0)  *sw = 0;
    else
    {
        *sw = (int)flx_16div16(lox,wscale);
        if (*sw >= width)
            *sw = width;
    }

    // Depth start
    if (loz.flx <= 0)  *sd = 0;
    else
    {
        *sd = (int)flx_16div16(loz,dscale);
        if (*sd >= depth)
            *sd = depth;
    }

    // Width end
    if (hix.flx <= 0)  *ew = 0;
    else
    {
        *ew = (int)(flx_16div16(hix,wscale) + Flx16(1));
        if (*ew > width)
            *ew = width;
        assert(*ew >= 0);
    }

    // Depth end
    if (hiz.flx <= 0)  *ed = 0;
    else
    {
        *ed = (int)(flx_16div16(hiz,dscale) + Flx16(1));
        if (*ed > depth)
            *ed = depth;
        assert(*ed >= 0);
    }

    //ÄÄÄÄ Check for degenerate condition
    if ((*ed <= *sd) || (*ew <= *sw))
        return 0;

    //ÄÄÄÄ Align to even values
    ulong mask = (ulong)-1 << bits;

    (*sw) &= mask;
    (*sd) &= mask;

    (*ew) = ((*ew) + (1 << bits)) & mask;
    (*ed) = ((*ed) + (1 << bits)) & mask;

    if ((*ew) > width)
        (*ew) = width & mask;

    if ((*ed) > depth)
        (*ed) = depth & mask;

    //ÄÄÄÄ Check for degenerate condition
    if ((*ed <= *sd) || (*ew <= *sw))
        return 0;

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - draw                                                       ³
//                                                                          ³
// Displays the terrain.                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::draw(void)
{
    int                     i, j, k, w, d;          // Loop variables
    byte                    *ptr;                   // Fast-access pointers
    struct esch_surf_type   *sptr;
    dword                   *vflags;
    VngoPoint               *vpt, *v;
    EschCamera              *cam;
    int                     sw, ew, sd, ed, rowsz;  // Bound area indecies and values
    int                     swm, ewm, sdm, edm;     // Medium detail indecies
//  int                     swl, ewl, sdl, edl;     // Low detail indecies
    dword                   cflags;
    ulong                   needed;
    Flx16                   tx, ty;                 // Temp values
    Flx16                   minx, minz, maxx, maxz; // Bounding area (far/yon)
    Flx16                   mlox, mloz, mhix, mhiz; // Medium detail area
    Flx16                   llox, lloz, lhix, lhiz; // Low detail area
    VngoRect                damage_rect;
    static EschPoint        po, pd, pw;             // Workspace
    static EschFace         face(ESCH_FACE_ALLOWPERSP
                                 | ESCH_FACE_SPECULAR
                                 | ESCH_FACE_SMOOTH
                                 | ESCH_FACE_FLAT  
                                 | ESCH_FACE_SOLID
                                 | ESCH_FACE_WIRE
                                 | ESCH_FACE_ABLINE
                                 | ESCH_FACE_BCLINE
                                 | ESCH_FACE_CALINE,
                                 0,0,0, /* A, B, C */
                                 0, /* Txt */
                                 0,0,0,0,0,0, /* U, V */
                                 0, /* color */
                                 0,1,0 /* normal */);

    assertMyth("EschTerrain::draw needs height-field information",
               hfield);

    assertMyth("EschTerrain::draw needs surface information",
               surfinfo);

    if (!hfield || !surfinfo)
        return;

//ÄÄÄ Clear arena
    ivory_arena_clear(EschSysInstance->wspace);

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschTerrain::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschTerrain::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    cflags = cam->flags;

//ÄÄÄ Clear the objects damage rectangle
    damage_rect.x = cam->vport->vbuff.width;
    damage_rect.y = cam->vport->vbuff.height;
    damage_rect.dx = 0;
    damage_rect.dy = 0;

//ÄÄÄ Transform view volume into world coords and project onto XZ plane,
//ÄÄÄ forming min/max bound.  Also, figure medium and low detail areas, if
//ÄÄÄ needed.

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Camera Position
    EschPoint   pos;

    cam->get_position(&pos);

    mlox.flx = llox.flx = minx.flx = pos.x.flx;
    mloz.flx = lloz.flx = minz.flx = pos.z.flx;
    mhix.flx = lhix.flx = maxx.flx = pos.x.flx;
    mhiz.flx = lhiz.flx = maxz.flx = pos.z.flx;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Level of Detail
    if (flags & ESCH_TRN_LOD)
    {
        if (lodmedium.flx > cam->hither.flx)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Medium
            tx.flx = flx_16mul16(lodmedium, cam->xsize).flx;
            ty.flx = flx_16mul16(lodmedium, cam->ysize).flx;

            // -tx, ty
            po.x.flx = -tx.flx;
            po.y.flx = ty.flx;
            po.z.flx = lodmedium.flx;
            po.transform(&cam->eye.orient);
            if (mlox.flx > po.x.flx)  mlox.flx = po.x.flx;
            if (mloz.flx > po.z.flx)  mloz.flx = po.z.flx;
            if (mhix.flx < po.x.flx)  mhix.flx = po.x.flx;
            if (mhiz.flx < po.z.flx)  mhiz.flx = po.z.flx;

            // tx, ty
            po.x.flx = tx.flx;
            po.y.flx = ty.flx;
            po.z.flx = lodmedium.flx;
            po.transform(&cam->eye.orient);
            if (mlox.flx > po.x.flx)  mlox.flx = po.x.flx;
            if (mloz.flx > po.z.flx)  mloz.flx = po.z.flx;
            if (mhix.flx < po.x.flx)  mhix.flx = po.x.flx;
            if (mhiz.flx < po.z.flx)  mhiz.flx = po.z.flx;

            // -tx, -ty
            po.x.flx = -tx.flx;
            po.y.flx = -ty.flx;
            po.z.flx = lodmedium.flx;
            po.transform(&cam->eye.orient);
            if (mlox.flx > po.x.flx)  mlox.flx = po.x.flx;
            if (mloz.flx > po.z.flx)  mloz.flx = po.z.flx;
            if (mhix.flx < po.x.flx)  mhix.flx = po.x.flx;
            if (mhiz.flx < po.z.flx)  mhiz.flx = po.z.flx;

            // tx, -ty
            po.x.flx = tx.flx;
            po.y.flx = -ty.flx;
            po.z.flx = lodmedium.flx;
            po.transform(&cam->eye.orient);
            if (mlox.flx > po.x.flx)  mlox.flx = po.x.flx;
            if (mloz.flx > po.z.flx)  mloz.flx = po.z.flx;
            if (mhix.flx < po.x.flx)  mhix.flx = po.x.flx;
            if (mhiz.flx < po.z.flx)  mhiz.flx = po.z.flx;
        }

        if (lodlow.flx > cam->hither.flx)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Low
            tx.flx = flx_16mul16(lodlow, cam->xsize).flx;
            ty.flx = flx_16mul16(lodlow, cam->ysize).flx;

            // -tx, ty
            po.x.flx = -tx.flx;
            po.y.flx = ty.flx;
            po.z.flx = lodlow.flx;
            po.transform(&cam->eye.orient);
            if (llox.flx > po.x.flx)  llox.flx = po.x.flx;
            if (lloz.flx > po.z.flx)  lloz.flx = po.z.flx;
            if (lhix.flx < po.x.flx)  lhix.flx = po.x.flx;
            if (lhiz.flx < po.z.flx)  lhiz.flx = po.z.flx;

            // tx, ty
            po.x.flx = tx.flx;
            po.y.flx = ty.flx;
            po.z.flx = lodlow.flx;
            po.transform(&cam->eye.orient);
            if (llox.flx > po.x.flx)  llox.flx = po.x.flx;
            if (lloz.flx > po.z.flx)  lloz.flx = po.z.flx;
            if (lhix.flx < po.x.flx)  lhix.flx = po.x.flx;
            if (lhiz.flx < po.z.flx)  lhiz.flx = po.z.flx;

            // -tx, -ty
            po.x.flx = -tx.flx;
            po.y.flx = -ty.flx;
            po.z.flx = lodlow.flx;
            po.transform(&cam->eye.orient);
            if (llox.flx > po.x.flx)  llox.flx = po.x.flx;
            if (lloz.flx > po.z.flx)  lloz.flx = po.z.flx;
            if (lhix.flx < po.x.flx)  lhix.flx = po.x.flx;
            if (lhiz.flx < po.z.flx)  lhiz.flx = po.z.flx;

            // tx, -ty
            po.x.flx = tx.flx;
            po.y.flx = -ty.flx;
            po.z.flx = lodlow.flx;
            po.transform(&cam->eye.orient);
            if (llox.flx > po.x.flx)  llox.flx = po.x.flx;
            if (lloz.flx > po.z.flx)  lloz.flx = po.z.flx;
            if (lhix.flx < po.x.flx)  lhix.flx = po.x.flx;
            if (lhiz.flx < po.z.flx)  lhiz.flx = po.z.flx;
        }
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Far points 
    tx.flx = flx_16mul16(cam->yon, cam->xsize).flx;
    ty.flx = flx_16mul16(cam->yon, cam->ysize).flx;

    // -tx, ty
    po.x.flx = -tx.flx;
    po.y.flx = ty.flx;
    po.z.flx = cam->yon.flx;
    po.transform(&cam->eye.orient);
    if (minx.flx > po.x.flx)  minx.flx = po.x.flx;
    if (minz.flx > po.z.flx)  minz.flx = po.z.flx;
    if (maxx.flx < po.x.flx)  maxx.flx = po.x.flx;
    if (maxz.flx < po.z.flx)  maxz.flx = po.z.flx;

    // tx, ty
    po.x.flx = tx.flx;
    po.y.flx = ty.flx;
    po.z.flx = cam->yon.flx;
    po.transform(&cam->eye.orient);
    if (minx.flx > po.x.flx)  minx.flx = po.x.flx;
    if (minz.flx > po.z.flx)  minz.flx = po.z.flx;
    if (maxx.flx < po.x.flx)  maxx.flx = po.x.flx;
    if (maxz.flx < po.z.flx)  maxz.flx = po.z.flx;

    // -tx, -ty
    po.x.flx = -tx.flx;
    po.y.flx = -ty.flx;
    po.z.flx = cam->yon.flx;
    po.transform(&cam->eye.orient);
    if (minx.flx > po.x.flx)  minx.flx = po.x.flx;
    if (minz.flx > po.z.flx)  minz.flx = po.z.flx;
    if (maxx.flx < po.x.flx)  maxx.flx = po.x.flx;
    if (maxz.flx < po.z.flx)  maxz.flx = po.z.flx;

    // tx, -ty
    po.x.flx = tx.flx;
    po.y.flx = -ty.flx;
    po.z.flx = cam->yon.flx;
    po.transform(&cam->eye.orient);
    if (minx.flx > po.x.flx)  minx.flx = po.x.flx;
    if (minz.flx > po.z.flx)  minz.flx = po.z.flx;
    if (maxx.flx < po.x.flx)  maxx.flx = po.x.flx;
    if (maxz.flx < po.z.flx)  maxz.flx = po.z.flx;

    // minx,minz to maxx, maxz is now the bounding area on the XZ plane

//ÄÄÄ Determine start and ending grid locations

    //ÄÄÄ Bounding area
    if (!compute_area(minx, minz, maxx, maxz,
                      &sw, &ew, &sd, &ed, 2))
        return;

    rowsz = ew - sw;
    assert(rowsz > 0);

    //ÄÄÄ Level Of Detail areas
    if (flags & ESCH_TRN_LOD)
    {
        //ÄÄÄ Medium LOD
        if (!compute_area(mlox, mloz, mhix, mhiz,
                          &swm, &ewm, &sdm, &edm, 1))
        {
            swm=sw-2;   sdm=sd-2;
            ewm=width & 0xfffffffe;
            edm=depth & 0xfffffffe;
        }

        //ÄÄÄ Low LOD
    }

//ÄÄÄ Compute orientation factors for terrain grid.  These are used
//ÄÄÄ during the transform of the height field into the camera's view.
    assertMyth("EschTerrain::draw needs positive scale factors",
               wscale.flx >= 0 && dscale.flx >= 0 && hscale.flx >= 0);

    EschVector wvec(wscale,0,0);
    wvec.transform(&cam->eye.iorient);

    EschVector dvec(0,0,dscale);
    dvec.transform(&cam->eye.iorient);

    EschVector hvec(0,hscale,0);
    hvec.transform(&cam->eye.iorient);

    // Compute position of grid origin
    origin.transform(&cam->eye.iorient,&po);

//ÄÄÄ Push drawing context

    // Update workspace metrics; no other place is reasonable to do this
    needed = ((sizeof(dword)+sizeof(VngoPoint))*rowsz) << 1;
    assertMyth("EschTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

    EschContext ec(EschCurrent);
    ec.verts = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword)*rowsz*2);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[rowsz*2];
    ec.faces = &face;
    ec.fflags = 0;
    ec.txts = txt;
    ec.push();

//ÄÄÄ Draw grid sw->ew by sd->ed
    pd.x.flx = po.x.flx + (dvec.i.flx*sd);
    pd.y.flx = po.y.flx + (dvec.j.flx*sd);
    pd.z.flx = po.z.flx + (dvec.k.flx*sd);

    // Depth loop
    for(d=sd, k=0; d < ed; k = !k)
    {
        ptr = hfield + (d*width) + sw;
        pw.x.flx = pd.x.flx + (wvec.i.flx*sw);
        pw.y.flx = pd.y.flx + (wvec.j.flx*sw);
        pw.z.flx = pd.z.flx + (wvec.k.flx*sw);

        // Determine this row (i) vs. last row (j) counters
        if (k)
        {
            i=rowsz; 
            j=0;
        }
        else
        {
            i=0;
            j=rowsz;
        }

        // Width loop
        for(w=sw; w < ew; i++, j++)
        {
            v=&vpt[i];

            // Test for Medium LOD row skip
            if (flags & ESCH_TRN_LOD
                && (d < sdm || d >= edm-1 || w < swm || w >= ewm-1))
            {
                if (d & 0x1)
                { 
                    // Handle missing triangle for 
                    if (!(flags & ESCH_TRN_DOTS)
                        && (w == ewm))
                    {
                        face.a = (word)j;
                        face.b = (word)(j-1);
                        face.c = (word)(i-1);

                        sptr = surfinfo;
                        sptr += ((d >> surfshift) * (width >> surfshift)) + (w >> surfshift);
                        vpt[face.a].clr = sptr->cind;
                        esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);
                    }

                    *v = vpt[j];
                    vflags[i] = vflags[j];

                    w += 2;
                    ptr += 2;
                    pw.x.flx += wvec.i.flx << 1;
                    pw.y.flx += wvec.j.flx << 1;
                    pw.z.flx += wvec.k.flx << 1;
                    continue;
                }
            }

            // Compute height-field point for current width and depth
            ((EschPoint*)v)->x.flx = pw.x.flx + ((Flx16)(*ptr) * hvec.i).flx;
            ((EschPoint*)v)->y.flx = pw.y.flx + ((Flx16)(*ptr) * hvec.j).flx;
            ((EschPoint*)v)->z.flx = pw.z.flx + ((Flx16)(*ptr) * hvec.k).flx;

            // Setup surface colors and lighting
            sptr = surfinfo;
            sptr += ((d >> surfshift) * (width >> surfshift)) + (w >> surfshift);

            if (sptr->flags & ESCH_SURF_CINDISTXT)
            {
                assertMyth("EschTerrain::draw needs texture array",
                           txtcolor);

                assertMyth("EschTerrain::draw found out of range texture index",
                           sptr->cind && sptr->cind <= tmax);

                v->clr = txtcolor[sptr->cind-1];
            }
            else
            {
                v->clr = sptr->cind;
            }

            v->shade = sptr->shd;

            vflags[i] = ESCH_VVERT_TRANSFORMED;

            // Draw
            if (flags & ESCH_TRN_DOTS)
            {
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Dots
                //ÄÄÄ Clip against view volume
                // Near/far clip plane
                if (((EschPoint*)v)->z.flx <= cam->yon.flx
                    && ((EschPoint*)v)->z.flx >= cam->hither.flx)
                {
                    // Left/right/top/bottom plane clippdng
                    Flx16 zx = flx_16mul16(((EschPoint*)v)->z,cam->xsize);
                    Flx16 zy = flx_16mul16(((EschPoint*)v)->z,cam->ysize);

                    if (((EschPoint*)v)->x.flx >= -zx.flx
                        && ((EschPoint*)v)->x.flx <= zx.flx
                        && ((EschPoint*)v)->y.flx >= -zy.flx
                        && ((EschPoint*)v)->y.flx <= zy.flx)
                    {
                        //ÄÄÄ Project pdxel
                        v->x = (flx_muldiv(((EschPoint*)v)->x,
                                        cam->xscalar,
                                        ((EschPoint*)v)->z).flx
                            + (cam->vport->vbuff.width<<15)) >> 16;
                        v->y = ((cam->vport->vbuff.height<<15)
                            - flx_muldiv(((EschPoint*)v)->y,
                                            cam->yscalar,
                                            ((EschPoint*)v)->z).flx) >> 16;
                        v->z = flx_16mul16(((EschPoint*)v)->z,
                                        cam->z_factor).flx << 1;
                        vflags[i] |= ESCH_VVERT_PROJECTED;

                        //ÄÄÄ Draw pdxel
                        cam->vport->pixel(v);
                    }
                }
            }
            else
            {
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Triangles
                if (d > sd)
                {
                    if (w > sw)
                    {
                        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Medium LOD
                        if (flags & ESCH_TRN_LOD
                            && (d < sdm || d > edm || w < swm || w > ewm))
                        {

                            // (d is never odd since top case catches that)
                            assert ((d & 0x1) == 0);

                            if (w & 0x3)
                            {
                                face.a = (word)((d & 0x3) ? i:j);
                                face.b = (word)(j-1);
                                face.c = (word)(i-1);
                            }
                            else
                            {
                                if (d & 0x3)
                                {
                                    face.a = (word)(i-1);
                                    face.b = (word)j;
                                    face.c = (word)(j-1);
                                }
                                else
                                {
                                    face.a = (word)(j-1);
                                    face.b = (word)(i-1);
                                    face.c = (word)i;
                                }
                            }
                            vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                              ? txtcolor[sptr->cind-1] : sptr->cind;
                            esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                            if (w & 0x3)
                            {
                                if (d & 0x3)
                                {
                                    face.a = (word)i;
                                    face.b = (word)j;
                                    face.c = (word)(j-1);
                                }
                                else
                                {
                                    face.a = (word)j;
                                    face.b = (word)(i-1);
                                    face.c = (word)i;
                                }
                            }
                            else
                            {
                                face.a = (word)((d & 0x3) ? (i-1):(j-1));
                                face.b = (word)i;
                                face.c = (word)j;
                            }
                            vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                              ? txtcolor[sptr->cind-1] : sptr->cind;
                            esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);
                        }
                        else if (flags & ESCH_TRN_LOD && (d == sdm))
                        {
                            if (w == swm || w == ewm)
                            {
                                face.a = (word)(j-1);
                                face.b = (word)(i-1);
                                face.c = (word)i;
                                vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                   ? txtcolor[sptr->cind-1] : sptr->cind;
                                esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                                face.a = (word)(j-1);
                                face.b = (word)i;   
                                face.c = (word)j;
                                vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                   ? txtcolor[sptr->cind-1] : sptr->cind;
                                esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);
                            }
                            else if ((w & 0x1) == 0)
                            {
                                face.a = (word)(j-2);
                                face.b = (word)(i-2);
                                face.c = (word)(i-1);
                                vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                   ? txtcolor[sptr->cind-1] : sptr->cind;
                                esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                                face.b = (word)(i-1);
                                face.c = (word)(j-1);
                                vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                   ? txtcolor[sptr->cind-1] : sptr->cind;
                                esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                                face.a = (word)i;
                                face.b = (word)(j-1);
                                face.c = (word)(i-1);
                                vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                   ? txtcolor[sptr->cind-1] : sptr->cind;
                                esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);
                                j--;
                            }

                            // Don't draw in odd case
                        }
                        else if (flags & ESCH_TRN_LOD && (d >= edm-1))
                        {
                            if (d == edm)
                            {
                                if (w == swm || w == ewm)
                                {
                                    face.a = (word)(j-1);
                                    face.b = (word)(i-1);
                                    face.c = (word)j;
                                    vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                      ? txtcolor[sptr->cind-1] : sptr->cind;
                                    esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                                    face.a = (word)i;   
                                    face.b = (word)j;
                                    face.c = (word)(i-1);
                                    vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                      ? txtcolor[sptr->cind-1] : sptr->cind;
                                    esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);
                                }
                                else
                                {
                                    face.a = (word)(j-1);
                                    face.b = (word)(i-1);
                                    face.c = (word)j;
                                    vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                      ? txtcolor[sptr->cind-1] : sptr->cind;
                                    esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                                    face.a = (word)i;
                                    face.b = (word)j;
                                    face.c = (word)(i-1);
                                    vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                      ? txtcolor[sptr->cind-1] : sptr->cind;
                                    esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                                    face.a = (word)i;
                                    face.b = (word)(j+1);
                                    face.c = (word)j;
                                    vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                      ? txtcolor[sptr->cind-1] : sptr->cind;
                                    esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);
                                    j++;
                                }
                            }

                            // Don't draw in edm-1 case
                        }
                        else if (flags & ESCH_TRN_LOD && (w == swm))
                        {
                            if (d & 0x1)
                            {
                                face.a = (word)(j-1);
                                face.b = (word)i;
                                face.c = (word)j;
                                vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                  ? txtcolor[sptr->cind-1] : sptr->cind;
                                esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);
                            }
                            else
                            {
                                face.a = (word)(j-1);
                                face.b = (word)(i-1);
                                face.c = (word)(j);
                                vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                  ? txtcolor[sptr->cind-1] : sptr->cind;
                                esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                                face.a = (word)i;
                                face.b = (word)j;
                                face.c = (word)(i-1);
                                vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                  ? txtcolor[sptr->cind-1] : sptr->cind;
                                esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);
                            }
                        }
                        else if (flags & ESCH_TRN_LOD && (w >= ewm-1))
                        {

                            // One of the 3 faces points are missing by
                            // this point... must do this above when we
                            // skip the row.

                            if (w == ewm)
                            {
                                if ((d & 0x1) == 0)
                                {
                                    face.a = (word)i;
                                    face.b = (word)j;
                                    face.c = (word)(j-1);
                                    vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                      ? txtcolor[sptr->cind-1] : sptr->cind;
                                    esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                                    face.a = (word)(i-1);
                                    face.b = (word)i;
                                    face.c = (word)(j-1);
                                    vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                                      ? txtcolor[sptr->cind-1] : sptr->cind;
                                    esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);
                                }

                                // Don't draw in odd case
                            }

                            // Don't draw in ewm-1 case
                        }
                        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ High LOD
                        else
                        {
                            if (sptr->flags & ESCH_SURF_CINDISTXT)
                            {
                                face.txt = sptr->cind;
                                face.flags |= ESCH_FACE_TEXTURED;
                            }

                            if (w & 0x1)
                            {
                                if (d & 0x1)
                                {
                                    face.a = (word)(j-1);
                                    face.b = (word)(i-1);
                                    face.c = (word)i;

                                    face.u[0] = 0;  face.v[0] = 1;
                                    face.u[1] = 0;  face.v[1] = 0;
                                    face.u[2] = 1;  face.v[2] = 0;
                                }
                                else
                                {
                                    face.a = (word)(i-1);
                                    face.b = (word)j;
                                    face.c = (word)(j-1);

                                    face.u[0] = 0;  face.v[0] = 0;
                                    face.u[1] = 1;  face.v[1] = 1;
                                    face.u[2] = 0;  face.v[2] = 1;
                                }
                            }
                            else
                            {
                                face.a = (word)((d & 0x1) ? j:i);
                                face.b = (word)(j-1);
                                face.c = (word)(i-1);

                                face.u[0] = 1;  face.v[0] = (d & 0x1) ? 1 : 0;
                                face.u[1] = 0;  face.v[1] = 1;
                                face.u[2] = 0;  face.v[2] = 0;
                            }
                            vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                              ? txtcolor[sptr->cind-1] : sptr->cind;
                            esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                            if (w & 0x1)
                            {
                                face.a = (word)((d & 0x1) ? (j-1):(i-1));
                                face.b = (word)i;
                                face.c = (word)j;

                                face.u[0] = 0;  face.v[0] = (d & 0x1) ? 1 : 0;
                                face.u[1] = 1;  face.v[1] = 0;
                                face.u[2] = 1;  face.v[2] = 1;
                            }
                            else
                            {
                                if (d & 0x1)
                                {
                                    face.a = (word)j;
                                    face.b = (word)(i-1);
                                    face.c = (word)i;

                                    face.u[0] = 1;  face.v[0] = 1;
                                    face.u[1] = 0;  face.v[1] = 0;
                                    face.u[2] = 1;  face.v[2] = 0;
                                }
                                else
                                {
                                    face.a = (word)i;
                                    face.b = (word)j;
                                    face.c = (word)(j-1);

                                    face.u[0] = 1;  face.v[0] = 0;
                                    face.u[1] = 1;  face.v[1] = 1;
                                    face.u[2] = 0;  face.v[2] = 1;
                                }
                            }
                            vpt[face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                                              ? txtcolor[sptr->cind-1] : sptr->cind;
                            esch_clipdraw_face(0,1,&damage_rect, cflags & ESCH_CAM_BACKCULL);

                            face.flags &= ~ESCH_FACE_TEXTURED;
                        }
                    }
                }
            }

            // Advance walk in width
            if (flags & ESCH_TRN_LOD 
                && (d < sdm || d >= edm-1 || w < swm || w >= ewm-2))
            {
                w += 2;
                ptr += 2;
                pw.x.flx += wvec.i.flx << 1;
                pw.y.flx += wvec.j.flx << 1;
                pw.z.flx += wvec.k.flx << 1;
            }
            else
            {
                w++;
                ptr++;
                pw.x.flx += wvec.i.flx;
                pw.y.flx += wvec.j.flx;
                pw.z.flx += wvec.k.flx;
            }
        }

        // Advance walk in depth
        d++;
        pd.x.flx += dvec.i.flx;
        pd.y.flx += dvec.j.flx;
        pd.z.flx += dvec.k.flx;
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
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - compute_shades                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::compute_shades(EschCamera *cam, EschLight *lgts)
{
    byte            *ptr;
    int             w,d;
    esch_surf_type  *sptr;
    EschVector      *nptr=0;
    EschPoint       pd, pw;
    VngoPoint       v;
    EschVertex      vert;

    assertMyth("EschTerrain::compute_shades needs surfinfo",
               surfinfo);

//ÄÄÄ Handle case of 'trivial' shade computation
    if (!lgts
       || !(cam->flags & (ESCH_CAM_SHADE_FLAT
                      | ESCH_CAM_SHADE_SMOOTH)))
    {
        assertMyth("EschTerrain::compute_shades needs palette in camera's viewport",
                    cam && cam->vport && cam->vport->vbuff.pal);

        byte mp = (byte) cam->vport->vbuff.pal->shd_pal->mid_point;

        for(d=0, sptr=surfinfo; d < (depth >> surfshift); d++)
        {
            for(w=0; w < (width >> surfshift); w++)
            {
                (sptr++)->shd = mp;
            }
        }

        return;
    }

//ÄÄÄ Otherwise, must have normals

    assertMyth("EschTerrain::compute_shades needs hsurfnorml",
               hsurfnorml);

    nptr=(EschVector*)ivory_hlock(hsurfnorml);

    assertMyth("EschTerrain::compute_shades can't lock surface normals",
               nptr != NULL);

    if (!nptr)
        return;

    EschContext ec;

    ec.lights = lgts;
    ec.camera = cam;
    ec.push();

    lgts->setup(0);

//ÄÄÄ Main transform and shade loops
    assertMyth("EschTerrain::compute_shades needs positive scale factors",
               wscale.flx >= 0 && dscale.flx >= 0 && hscale.flx >= 0);

    pd.x.flx = origin.x.flx;
    pd.y.flx = origin.y.flx;
    pd.z.flx = origin.z.flx;
    for(d=0, sptr=surfinfo;
        d < (depth >> surfshift);
        d++, pd.z.flx += (dscale * (Flx16)(surfratio)).flx)
    {
        ptr = hfield + ((d << surfshift)*width);

        pw.x.flx = pd.x.flx;
        pw.y.flx = pd.y.flx;
        pw.z.flx = pd.z.flx;

        for(w=0; w < (width >> surfshift);
            w++, pw.x.flx += (wscale * (Flx16)(surfratio)).flx,
            ptr += surfratio)
        {
            vert.x.flx = pw.x.flx;
            vert.y.flx = pw.y.flx + ((Flx16)(*ptr) * hscale).flx;
            vert.z.flx = pw.z.flx;

            vert.normal.i = nptr->i;
            vert.normal.j = nptr->j;
            vert.normal.k = nptr->k;
            nptr++;

            v.shade = 0;

            if (cam->flags & ESCH_CAM_SHADE_SPECULAR)
            {
                lgts->hishine(&vert,&v);
            }
            else
            {
                lgts->shine(&vert,&v);
            }

            sptr->shd = (byte)v.shade;
            sptr++;
        }
    }

    ec.pop();

//ÄÄÄ Unlock normals
    ivory_hunlock(hsurfnorml);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - release                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::release(void)
{
    if (flags & ESCH_DRW_OWNSDATA)
    {
//ÄÄ Free associated data, if any
        if (hfield)
        {
            delete [] hfield;
            hfield=0;
        }
        if (surfinfo)
        {
            delete [] surfinfo;
            surfinfo=0;
        }
        if (hsurfnorml)
        {
            ivory_hfree(&hsurfnorml);
            hsurfnorml=0;
        }
        if (txtcolor)
        {
            delete [] txtcolor;
            txtcolor=0;
        }
        if (txt)
        {
            delete [] txt;
            txt=0;
            tmax=0;
        }

        flags &= ~ESCH_DRW_OWNSDATA;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°




//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - load                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschTerrain::load(const char *fname, const char *tname)
{
    esch_error_codes    err;
    XFParseIFF          iff;

    release();

//ÄÄ Open file
    if (iff.open(fname,XF_OPEN_READ))
        return ESCH_ERR_FILEERROR;

//ÄÄ Loop until a header with the correct name is found
    err=ESCH_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
        }

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('E','T','E','R'))
            {
                err=load(&iff,tname);
                if (!err
                    || err != ESCH_ERR_NOTFOUND)
                    break;
            }

            // Must scan inside any ESEN Scene forms.
            else if (iff.formid == iff.makeid('E','S','E','N'))
            {
                iff.enterform();
            }
        }
    }

//ÄÄ Return ok
    iff.close();
    return err;
}

esch_error_codes EschTerrain::load(XFParseIFF *iff, const char *tname)
{
    ulong               nt=0;
    esch_error_codes    err;
    EschFileTerrHDR     header;

    assertMyth("EschTerrain::load requires an iff pointer",
               iff);

    release();

//ÄÄ Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('E','T','E','R'))
        return ESCH_ERR_NOTFOUND;

//ÄÄ Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(EschFileTerrHDR))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

    if (tname && strncmp(tname,header.name,ESCH_MAX_NAME))
    {
        iff->leaveform();
        return ESCH_ERR_NOTFOUND;
    }

    if (!header.width || !header.depth || !header.surfratio)
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

//ÄÄ Found, so setup terrain

    // Check for valid header options
    if (header.compression)
    {
        iff->leaveform();
        return ESCH_ERR_NOTSUPPORTED;
    }

    // Copy header initial data
    strncpy(name,header.name,ESCH_MAX_NAME);
    flags = header.flags | ESCH_DRW_OWNSDATA;
    width = header.width;
    depth = header.depth;
    surfratio = header.surfratio;
    switch (surfratio)
    {
        case 1:
            surfshift = 0;
            break;
        case 2:
            surfshift = 1;
            break;
        case 4:
            surfshift = 2;
            break;
        case 8:
            surfshift = 3;
            break;
        case 16:
            surfshift = 4;
            break;
        default:
            iff->leaveform();
            return ESCH_ERR_NOTSUPPORTED;
    }
    wscale = header.wscale;
    dscale = header.dscale;
    hscale = header.hscale;

    //ÄÄ Scan and load chunks in form
    while (!iff->next())
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Height Field
        if (iff->chunkid == iff->makeid('H','G','T','S'))
        {
            if (iff->chunkSize != (ulong)(width * depth))
            {
                err=ESCH_ERR_INVALIDHGTDATA;
                goto error_exit;
            }

            hfield = new byte[width*depth];
            if (!hfield)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            if (iff->read(hfield))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Surface Info
        else if (iff->chunkid == iff->makeid('S','U','R','F'))
        {
            if (iff->chunkSize !=
                (ulong)(((width*depth) >> (surfshift*2)) * sizeof(esch_surf_type)))
            {
                err=ESCH_ERR_INVALIDSRFDATA;
                goto error_exit;
            }

            surfinfo = new esch_surf_type[(width*depth) >> (surfshift*2)];
            if (!surfinfo)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            if (iff->read(surfinfo))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Surface Normals
        else if (iff->chunkid == iff->makeid('N','R','M','L'))
        {
            if (iff->chunkSize != 
                (ulong)(((width*depth) >> (surfshift*2)) * sizeof(EschVector)))
            {
                err=ESCH_ERR_INVALIDSRFDATA;
                goto error_exit;
            }

            hsurfnorml = ivory_halloc((ulong)
                   (((width*depth) >> (surfshift*2)) * sizeof(EschVector)));
            if (!hsurfnorml)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            EschVector *ptr = (EschVector*)ivory_hlock(hsurfnorml);
            if (!ptr)
            {
                err=ESCH_ERR_LOCKFAILED;
                goto error_exit;
            }
            if (iff->read(ptr))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
            ivory_hunlock(hsurfnorml);
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Texture Colors
        else if (header.ntxts
                 && (iff->chunkid == iff->makeid('C','O','L','R')))
        {
            if (iff->chunkSize != header.ntxts)
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }

            txtcolor = new byte[header.ntxts];
            if (!txtcolor)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            if (iff->read(txtcolor))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Material Form
        else if (header.ntxts
                 && (iff->chunkid == iff->makeid('F','O','R','M'))
                 && (iff->formid == iff->makeid('E','M','T','L')))
        {
            // Allocate texture memory, if not already allocated.
            if (!txt)
            {
                txt = new EschTexture[header.ntxts];
                if (!txt)
                {
                    err=ESCH_ERR_NOMEMORY;
                    goto error_exit;
                }
                tmax = header.ntxts;
            }

            if (nt < tmax)
            {
                if (err=txt[nt++].load(iff))
                    goto error_exit;
            }
        }
    }

    if (!hfield)
    {
        err=ESCH_ERR_MISSINGDATA;
        goto error_exit;
    }


//ÄÄ Return ok
    iff->leaveform();

    return ESCH_ERR_NONE;

//ÄÄ Return error
error_exit : ;
    flags &= ~ESCH_DRW_OWNSDATA;
    if (hfield)
    {
        delete [] hfield;
        hfield=0;
    }
    if (surfinfo)
    {
        delete [] surfinfo;
        surfinfo=0;
    }
    if (txt)
    {
        delete [] txt;
        txt=0;
        tmax=0;
    }
    if (txtcolor)
    {
        delete [] txtcolor;
        txtcolor=0;
    }
    if (hsurfnorml)
    {
        ivory_hfree(&hsurfnorml);
        hsurfnorml=0;
    }

    iff->leaveform();
    return err;
}

//°±² End of module - esterran.cpp ²±°

