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
// Created by Tim Little
//
// esternex.cpp
//
// The EschTerrain class is a height-field polygonal terrain system which
// uses a 2D array of 8-bit height values to create a realistic "outdoor"
// terrain.  The terrain may have textures and be drawn with multiple
// levels of detail.  This derived version is optimized for use when you
// will always be close to the ground.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"
#include "esfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

// #define TERRAIN_DEBUG_AID
// #define TERRAIN_NO_FRUSTRUM_WALK
//#define TERRAIN_NO_PATCHUP

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
// EschTerrainEx - constructor                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschTerrainEx::EschTerrainEx(const char *fname, const char *tname, VngoPal *pal) :
    EschTerrain(fname,tname,pal),
    dlevels(0),
    left_edge(0),
    right_edge(0),
    edge_count(0),
    start_dlevel(0),
    num_dlevels(0),
    max_texture_lod(0),
    max_perspective_lod(0),
    max_smooth_lod(0)
{
}

EschTerrainEx::EschTerrainEx(const EschTerrainEx &_t)
{
    left_edge            = _t.left_edge;
    right_edge           = _t.right_edge;
    edge_count           = _t.edge_count;
    darea                = _t.darea;
    ccol                 = _t.ccol;   // colomn coord in array.
    crow                 = _t.crow;   // row coord in array.
    max_texture_lod      = _t.max_texture_lod;
    max_perspective_lod  = _t.max_perspective_lod;
    max_smooth_lod       = _t.max_smooth_lod;
    num_dlevels          = _t.num_dlevels;
    start_dlevel         = _t.start_dlevel;
    dlevels              = _t.dlevels;
    view_dir             = _t.view_dir;

    cam                  = _t.cam;
    cflags               = _t.cflags;
    pos                  = _t.pos;
    po                   = _t.po;

    wvec                 = _t.wvec;
    dvec                 = _t.dvec;
    hvec                 = _t.hvec;

    //more from EschTerrainEx object, these come from EschTerrain
    width                = _t.width;                  // Width of height field
    depth                = _t.depth;                  // Depth of height field
    surfratio            = _t.surfratio;              // Surface ratio (height : surface)
    surfshift            = _t.surfshift;              // Shift value for surf ratio
    scale                = _t.scale;                  // World space per unit in width/depth
    scaleshift           = _t.scaleshift;             // Shift value for scale
    lodmedium            = _t.lodmedium;              // Eye distance for medium LOD
    lodlow               = _t.lodlow;                 // Eye distance for low LOD
    origin               = _t.origin;                 // Origin of height field
    hfield               = _t.hfield;                 // 2D array of heights
    htable               = _t.htable;                 // Array of world height values
    surfinfo             = _t.surfinfo;               // 2D array of surface information
    hsurfnorml           = _t.hsurfnorml;             // 2D array of surface normals
    tmax                 = _t.tmax;                   // Number of textures
    txtcolor             = _t.txtcolor;               // Array of colors to use for texture entries
    txt                  = _t.txt;                    // Array of textures
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - destructor                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschTerrainEx::~EschTerrainEx()
{
    release();
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - release                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::release()
{
    if (dlevels)
    {
        delete [] dlevels;
        dlevels = NULL;
    }
    if (left_edge)
    {
        delete [] left_edge;
        left_edge = NULL;
    }
    if (right_edge)
    {
        delete [] right_edge;
        right_edge = NULL;
    }

    EschTerrain::release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - draw                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::draw()
{
    assertMyth("EschLowTerrain::draw needs height-field information",
               hfield);

    assertMyth("EschLowTerrain::draw needs surface information",
               surfinfo);

    if (!hfield || !surfinfo)
        return;

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschLowTerrain::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschLowTerrain::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    cflags = cam->flags;

//ÄÄÄ Calculate the affected polygon/rectangle.
    esch_find_draw_volume();

//ÄÄÄ Compute orientation factors for terrain grid.  These are used
//ÄÄÄ during the transform of the height field into the camera's view.
    assertMyth("EschTerrain::draw needs positive scale factors",
               scale > 0);

    wvec.i = scale;
    wvec.j = 0;
    wvec.k = 0;
    wvec.transform(&cam->eye.iorient);

    dvec.i = 0;
    dvec.j = 0;
    dvec.k = scale;
    dvec.transform(&cam->eye.iorient);

    hvec.i = 0;
    hvec.j = 1;
    hvec.k = 0;
    hvec.transform(&cam->eye.iorient);

    // Compute position of grid origin
    origin.transform(&cam->eye.iorient,&po);


    dword       tflags = ESCH_TERNEX_SMOOTH_ALL | ESCH_TERNEX_CLIP
                        | ESCH_TERNEX_ALIGN | ESCH_TERNEX_TEXTURE
                        | ESCH_TERNEX_PERSPECTIVE | ESCH_TERNEX_SMOOTH;



    if (flags & ESCH_TRN_LOD)
    {
        VngoRect    clip[ESCH_MAX_LOD+1];
        VngoRect    *iclip = NULL;
        VngoRect    *oclip = NULL;
        int         i;
        int         lod[ESCH_MAX_LOD];

        for (i=0;i < num_dlevels-1;i++)
        {
            lod[i] = (int)dlevels[i] >> scaleshift;
            clip[i].x = ccol - lod[i];
            clip[i].y = crow - lod[i];
            clip[i].dx = lod[i] << 1;
            clip[i].dy = lod[i] << 1;
            clip[i].clip_to(darea);
        }
        clip[num_dlevels - 1] = darea;

        iclip = &clip[0];

        for (i = start_dlevel; i < num_dlevels; i++)
        {
            if (i > max_texture_lod) // || ((ulong)i >= surfshift))
            {
                tflags &= ~ESCH_TERNEX_TEXTURE;
            }
            if (i > max_perspective_lod)
            {
                tflags &= ~ESCH_TERNEX_PERSPECTIVE;
            }
            if (i > max_smooth_lod)
            {
                tflags &= ~ESCH_TERNEX_SMOOTH;
            }

            *iclip = draw_terrain_rect(iclip, oclip, i, tflags);

            oclip = iclip;
            iclip = &clip[i+1];
        }
    }
    else
    {
        if (start_dlevel > max_texture_lod) // || ((ulong)i >= surfshift))
        {
            tflags &= ~ESCH_TERNEX_TEXTURE;
        }
        if (start_dlevel > max_perspective_lod)
        {
            tflags &= ~ESCH_TERNEX_PERSPECTIVE;
        }
        if (start_dlevel > max_smooth_lod)
        {
            tflags &= ~ESCH_TERNEX_SMOOTH;
        }

        tflags &=~ESCH_TERNEX_SMOOTH_ALL;
        draw_terrain_rect (&darea, NULL, start_dlevel,tflags);
    }

    cam = NULL;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - setup_edge_limits                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::setup_edge_limits(VngoPoint *pts)
{
    if (edge_count != depth || !left_edge || !right_edge)
    {
        if (left_edge)
        {
            delete [] left_edge;
        }
        left_edge = new long [depth];
        if (right_edge)
        {
            delete [] right_edge;
        }
        right_edge = new long [depth];
        edge_count = depth;
    }
    for (int i=0;i < depth;i++)
    {
        left_edge[i] = width;
        right_edge[i] = 0;
    }

    add_edge_to_limits(&pts[0],&pts[1]);
    add_edge_to_limits(&pts[0],&pts[2]);
    add_edge_to_limits(&pts[0],&pts[3]);
    add_edge_to_limits(&pts[0],&pts[4]);

    add_edge_to_limits(&pts[1],&pts[2]);
    add_edge_to_limits(&pts[2],&pts[3]);
    add_edge_to_limits(&pts[3],&pts[4]);
    add_edge_to_limits(&pts[4],&pts[1]);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - add_edge_to_limits                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::add_edge_to_limits(VngoPoint *p1, VngoPoint *p2)
{

    long    startx,startz,endx,endz;

    if (p1->y > p2->y)
    {
        startz = p2->y;
        startx = p2->x << 16;
        endz = p1->y;
        endx = p1->x << 16;
    }
    else
    {
        startz = p1->y;
        startx = p1->x << 16;
        endz = p2->y;
        endx = p2->x << 16;
    }
    long    dz = endz - startz;
    long    dx = endx - startx;
    long    adx;
    long    is_xmajor = 0;

    if (dx < 0)
        adx = -dx;
    else
        adx = dx;

    if (adx > dz)
        is_xmajor=1;

    long    xstep;
    if (dz)
        xstep = dx / dz;
    else
        xstep = 0;

    startz--;
    startx -= xstep;
    endz++;

    while (startz <= endz && startz < depth)
    {
        if (startz >= 0)
        {
            int tx = startx >> 16;

            if (is_xmajor)
            {
                if (left_edge[startz] > tx)
                    left_edge[startz] = tx;
                if (right_edge[startz] < tx)
                    right_edge[startz] = tx;

                long tsz = startz - 1;
                if(tsz >= 0)
                {
                    if (left_edge[tsz] > tx)
                        left_edge[tsz] = tx;
                    if (right_edge[tsz] < tx)
                        right_edge[tsz] = tx;
                }
                tsz = startz + 1;
                if (tsz < depth)
                {
                    if (left_edge[tsz] > tx)
                        left_edge[tsz] = tx;
                    if (right_edge[tsz] < tx)
                        right_edge[tsz] = tx;
                }
            }
            else
            {
                if (left_edge[startz] > tx - 1)
                {
                    if (tx > 0)
                        left_edge[startz] = tx - 1;
                    else
                        left_edge[startz] = 0;
                }
                if (right_edge[startz] < tx + 1)
                {
                    if (tx+1 < width)
                        right_edge[startz] = tx + 1;
                    else
                        right_edge[startz] = width - 1;
                }
            }
        }
        startz++;
        startx += xstep;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - draw_terrain_rect                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoRect EschTerrainEx::draw_terrain_rect(VngoRect *iclip, VngoRect *oclip,
                                       int dlevel, dword flags)
{
    VngoRect work_rect = *iclip;


    if ((work_rect.x > (darea.x + darea.dx)) ||
        ((work_rect.x + work_rect.dx) < darea.x) ||
        (work_rect.y > (darea.y + darea.dy)) ||
        ((work_rect.y + work_rect.dy) < darea.y))
        return (work_rect);

#if 0
    if(work_rect.x < darea.x)
    {
        int t = darea.x - work_rect.x;
        work_rect.x = darea.x;
        work_rect.dx -= t;
    }
    if ((work_rect.x + work_rect.dx) > (darea.x + darea.dx))
    {
        work_rect.dx = (darea.x + darea.dx) - work_rect.x;
    }

    if(work_rect.y < darea.y)
    {
        int t = darea.y - work_rect.y;
        work_rect.y = darea.y;
        work_rect.dy -= t;
    }
    if ((work_rect.y + work_rect.dy) > (darea.y + darea.dy))
    {
        work_rect.dy = (darea.y + darea.dy) - work_rect.y;
    }
#endif
    if (flags & ESCH_TERNEX_ALIGN)
    {
        // Put the rect on the correct boundaries.
        int tmask = ((1 << (dlevel+2)) - 1);
        int t = work_rect.x - (work_rect.x & ~(tmask));
        work_rect.x = work_rect.x - t;
        work_rect.dx += t;
        work_rect.dx += tmask;
        work_rect.dx &= ~tmask;

        t = work_rect.y - (work_rect.y & ~(tmask));
        work_rect.y = work_rect.y - t;
        work_rect.dy += t;
        work_rect.dy += tmask;
        work_rect.dy &= ~tmask;
    }

    if (flags & ESCH_TERNEX_CLIP)
    {
        // Make sure work_rect fits on the terrain!
        if (work_rect.x < 0)
        {
            work_rect.dx += work_rect.x;
            work_rect.x = 0;
        }
        if (work_rect.y < 0)
        {
            work_rect.dy += work_rect.y;
            work_rect.y = 0;
        }
        if (work_rect.x + work_rect.dx > width)
        {
            work_rect.dx = width - work_rect.x;
        }
        if (work_rect.y + work_rect.dy > depth)
        {
            work_rect.dy = depth - work_rect.y;
        }
    }

    if (work_rect.dy <= 0 || work_rect.dx <= 0)
        return (work_rect);     // No terrain to draw in this rect.

    if (oclip == NULL)
    {
        draw_terrain_rect (&work_rect,dlevel,flags);
    }
    else
    {
        // get the smoothing flags for this pass.
        VngoRect    trect;

        if (work_rect.x < oclip->x)
        {
            dword   wflags = flags;
            // we need to draw the left rect.
            trect.x  = work_rect.x;
            trect.y  = work_rect.y;
            if (work_rect.x + work_rect.dx < oclip->x)
            {
                trect.dx = work_rect.dx;
            }
            else
            {
                trect.dx = oclip->x - work_rect.x;
                wflags &= ~ESCH_TERNEX_SMOOTH_RIGHT;
            }

            trect.dy = work_rect.dy;

            draw_terrain_rect(&trect,dlevel,wflags);
        }
        if (work_rect.x + work_rect.dx > oclip->x + oclip->dx)
        {
            dword   wflags = flags;
            // we need to draw the right rect.
            if (work_rect.x < oclip->x + oclip->dx)
            {
                trect.x = oclip->x + oclip->dx;
                wflags &= ~ESCH_TERNEX_SMOOTH_LEFT;
            }
            else
            {
                trect.x = work_rect.x;
            }
            trect.y  = work_rect.y;
            trect.dx = work_rect.x + work_rect.dx - trect.x;
            trect.dy = work_rect.dy;

            draw_terrain_rect(&trect,dlevel,wflags);
        }
        if (work_rect.y < oclip->y)
        {
            dword   wflags = flags;
            // we need to draw the top rect.
            if (work_rect.x < oclip->x)
            {
                trect.x  = oclip->x;
                wflags &= ~ESCH_TERNEX_SMOOTH_LEFT;
            }
            else
            {
                trect.x = work_rect.x;
            }

            trect.y  = work_rect.y;

            if (work_rect.x + work_rect.dx < oclip->x + oclip->dx)
            {
                trect.dx = work_rect.x + work_rect.dx - oclip->x;
            }
            else
            {
                trect.dx = oclip->x + oclip->dx - trect.x;
                wflags &= ~ESCH_TERNEX_SMOOTH_RIGHT;
            }

            if (work_rect.y + work_rect.dy < oclip->y)
            {
                trect.dy = work_rect.dy;
            }
            else
            {
                trect.dy = oclip->y - trect.y;
                wflags &= ~ESCH_TERNEX_SMOOTH_BOTTOM;
            }

            draw_terrain_rect(&trect,dlevel,wflags);
        }
        if (work_rect.y + work_rect.dy > oclip->y + oclip->dy)
        {
            dword   wflags = flags;
            // we need to draw the bottom rect.
            if (work_rect.x < oclip->x)
            {
                trect.x  = oclip->x;
                wflags &= ~ESCH_TERNEX_SMOOTH_LEFT;
            }
            else
            {
                trect.x = work_rect.x;
            }

            if (work_rect.y < oclip->y + oclip->dy)
            {
                trect.y = oclip->y + oclip->dy;
                wflags &= ~ESCH_TERNEX_SMOOTH_TOP;
            }
            else
            {
                trect.y = work_rect.y;
            }

            if (work_rect.x + work_rect.dx < oclip->x + oclip->dx)
            {
                trect.dx = work_rect.x + work_rect.dx - trect.x;
            }
            else
            {
                trect.dx = oclip->x + oclip->dx - trect.x;
                wflags &= ~ESCH_TERNEX_SMOOTH_RIGHT;
            }
            trect.dy = work_rect.y + work_rect.dy - trect.y;

            draw_terrain_rect(&trect,dlevel,wflags);
        }
    }
    return (work_rect);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - display_pixel_row                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::display_pixel_row(VngoPoint *vpt,int count)
{
    for (int k=0;k < count;k++)
    {
        VngoPoint *vpnt = &vpt[k];
        const EschPoint *pnt = (const EschPoint*)vpnt;

        if ( (pnt->z <= cam->yon)
             && (pnt->z >= cam->hither) )
        {
            float zx = pnt->z * cam->xsize;
            float zy = pnt->z * cam->ysize;

            if ((pnt->x >= -zx)
                && (pnt->x <= zx)
                && (pnt->y >= -zy)
                && (pnt->y <= zy))
            {
                vpnt->x = long((pnt->x * cam->xscalar) / pnt->z)
                          + (cam->vport->vbuff.width>>1);

                vpnt->y = (cam->vport->vbuff.height>>1)
                          - long((pnt->y * cam->yscalar) / pnt->z);

                vpnt->z = ulong(pnt->z * cam->z_factor * float(0xffffffff));

                //ÄÄÄ Draw pdxel
                cam->vport->pixel(vpnt);
            }
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - draw_terrain_rect                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::draw_terrain_rect (VngoRect *rect, int dlevel,dword lflags)
{
    ulong                   needed;
    int                     texture_shift;
    int                     texture_shift2;
    int                     leftx,curx,curz;
    int                     step,cstep;
    VngoPoint               *vpt;
    EschVector              _wvec;
    EschVector              _dvec;

    dword                   *vflags;
    dword                   fflags1 = ESCH_FACE_ALLOWPERSP
                                    | ESCH_FACE_TEXTURED
                                    | ESCH_FACE_SPECULAR
                                    | ESCH_FACE_SMOOTH
                                    | ESCH_FACE_FLAT
                                    | ESCH_FACE_SOLID
                                    | ESCH_FACE_WIRE
                                    | ESCH_FACE_ABLINE
                                    | ESCH_FACE_BCLINE
                                    | ESCH_FACE_CALINE;

    dword                   fflags2 = ESCH_FACE_ALLOWPERSP
                                    | ESCH_FACE_TEXTURED
                                    | ESCH_FACE_SPECULAR
                                    | ESCH_FACE_SMOOTH
                                    | ESCH_FACE_FLAT
                                    | ESCH_FACE_SOLID
                                    | ESCH_FACE_WIRE
                                    | ESCH_FACE_ABLINE
                                    | ESCH_FACE_BCLINE
                                    | ESCH_FACE_CALINE;

    dword                   fflags3 = ESCH_FACE_SMOOTH
                                    | ESCH_FACE_FLAT
                                    | ESCH_FACE_SOLID
                                    | ESCH_FACE_WIRE
                                    | ESCH_FACE_ABLINE
                                    | ESCH_FACE_BCLINE
                                    | ESCH_FACE_CALINE;


    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    static EschFace         face[3];

    if (dlevel > int(surfshift))
        texture_shift = dlevel - surfshift;
    else
        texture_shift = 0;

    if ((dlevel+1) > int(surfshift))
        texture_shift2 = dlevel - surfshift + 1;
    else
        texture_shift2 = 0;


    if ((rect->x > (darea.x + darea.dx)) ||
        ((rect->x + rect->dx) < darea.x) ||
        (rect->y > (darea.y + darea.dy)) ||
        ((rect->y + rect->dy) < darea.y))
        return;

    if (rect->x + rect->dx >= width)
    {
        rect->dx = width - 1 - rect->x;
    }
    if (rect->y + rect->dy >= depth)
    {
        rect->dy = depth - 1- rect->y;
    }

#if 0
    if(work_rect.x < darea.x)
    {
        int t = darea.x - work_rect.x;
        work_rect.x = darea.x
        work_rect.dx -= t;
    }
    if ((work_rect.x + work_rect.dx) > (darea.x + darea.dx))
    {
        work_rect.dx = (darea.x + darea.dx) - work_rect.x;
    }

    if(work_rect.y < darea.y)
    {
        int t = darea.y - work_rect.y;
        work_rect.y = darea.y
        work_rect.dy -= t;
    }
    if ((work_rect.y + work_rect.dy) > (darea.y + darea.dy))
    {
        work_rect.dy = (darea.y + darea.dy) - work_rect.y;
    }
#endif

    if (!(lflags & ESCH_TERNEX_TEXTURE))
    {
        fflags1 &=~ESCH_FACE_TEXTURED;
        fflags2 &=~ESCH_FACE_TEXTURED;
    }
    else if (!(lflags & ESCH_TERNEX_PERSPECTIVE))
    {
        fflags1 &=~ESCH_FACE_ALLOWPERSP;
        fflags2 &=~ESCH_FACE_ALLOWPERSP;
    }
    if (!(lflags & ESCH_TERNEX_SMOOTH))
    {
        fflags1 &=~ESCH_FACE_SMOOTH;
        fflags2 &=~ESCH_FACE_SMOOTH;
    }
    if (!(lflags & ESCH_FACE_SPECULAR))
    {
        fflags1 &=~ESCH_FACE_SPECULAR;
        fflags2 &=~ESCH_FACE_SPECULAR;
    }



    leftx = rect->x;
    curz = rect->y;
    curx = leftx;
    cstep = 2 << dlevel;
    step = 1 << dlevel;

    assertMyth("EschLowTerrain::draw_terrain_rect needs an in-clip region",
                rect != NULL);
    assertMyth("EschLowTerrain::draw_terrain_rect needs camera.",
                cam != NULL);

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    int dx = (rect->dx >> dlevel) + 1;

    // Initialize all of the faces.
    int     rowa = 0;
    int     rowb = dx;
    int     rowc = dx + dx;

    // Setup the stepping vectors for the correct detail level.

    float dterm = float(1 << dlevel);

    _wvec.i = wvec.i * dterm;
    _wvec.j = wvec.j * dterm;
    _wvec.k = wvec.k * dterm;

    _dvec.i = dvec.i * dterm;
    _dvec.j = dvec.j * dterm;
    _dvec.k = dvec.k * dterm;

    // Update workspace metrics; no other place is reasonable to do this

    needed = (((sizeof(dword)+sizeof(VngoPoint)) * dx) * 3);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

//ÄÄÄ Push drawing context

    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * (dx * 3));
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[dx * 3];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();


    int endy = rect->dy >> dlevel;
    int endx = rect->dx >> dlevel;
    int tstep = (1 << dlevel);
    int i,j;

    VngoPoint   work_points[3];
    EschPoint   *rpt = (EschPoint*) (&work_points[2]);
    EschPoint   *cpt = (EschPoint*) (&work_points[0]);
    EschPoint   *cpt2 = (EschPoint*) (&work_points[1]);
    EschPoint   pd,pw;

    cpt->x = origin.x + float(rect->x << scaleshift);
    cpt->y = origin.y;
    cpt->z = origin.z + float(rect->y << scaleshift);

    ::esch_transform(cpt,&cam->eye.iorient,cpt);

    rpt->x = cpt->x;
    rpt->y = cpt->y;
    rpt->z = cpt->z;

    VngoPoint   *vA = &vpt[rowa];
    VngoPoint   *vB = &vpt[rowb];
    VngoPoint   *vC = &vpt[rowc];

    long            t = (width * rect->y) + rect->x;
    byte            *ptr = hfield + t;
    byte            *rptr = ptr;
    long            st = ((width >> surfshift) * (rect->y >> surfshift)) + (rect->x >> surfshift);
    esch_surf_type  *sptr = surfinfo + st;
    esch_surf_type  *rsptr = sptr;
    long            pstep = 1 << dlevel;


    VngoPoint       tpt;
    VngoColor24bit  clr(0,255,255);
    if (dlevel == 1)
    {
        clr.r = 0;
        clr.g = 255;
        clr.b = 0;
    }
    else if (dlevel == 2)
    {
        clr.r = 0;
        clr.g = 0;
        clr.b = 255;
    }
    else if (dlevel == 3)
    {
        clr.r = 255;
        clr.g = 255;
        clr.b = 255;
    }
    else if (dlevel == 4)
    {
        clr.r = 255;
        clr.g = 255;
        clr.b = 0;
    }

    for (i=0; i <= endx; i++)
    {   // Setup the first line A
        float h = htable[*ptr];
        ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
        ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
        ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

        if (sptr->flags & ESCH_SURF_CINDISTXT)
        {
            vA->clr = txtcolor[sptr->cind-1];
        }
        else
        {
            vA->clr = sptr->cind;
        }

        vA->shade = sptr->shd;
        cpt->x = cpt->x + _wvec.i;
        cpt->y = cpt->y + _wvec.j;
        cpt->z = cpt->z + _wvec.k;
        vA++;
        ptr +=pstep;
        sptr += pstep >> surfshift;
    }
    rpt->x = rpt->x + _dvec.i;
    rpt->y = rpt->y + _dvec.j;
    rpt->z = rpt->z + _dvec.k;

    sptr = rsptr;

    vA = &vpt[rowa];

    if (lflags & ESCH_TERNEX_SMOOTH_TOP)
    {

        for (i=0;i < endx-1;i+=2)
        {
            ((EschPoint*)&vA[i+1])->x = (((const EschPoint*)(&vA[i]))->x
                              + ((const EschPoint*)(&vA[i+2]))->x) / 2.0f;
            ((EschPoint*)&vA[i+1])->y = (((const EschPoint*)(&vA[i]))->y
                              + ((const EschPoint*)(&vA[i+2]))->y) / 2.0f;
            ((EschPoint*)&vA[i+1])->z = (((const EschPoint*)(&vA[i]))->z
                              + ((const EschPoint*)(&vA[i+2]))->z) / 2.0f;
            vA[i+1].shade = (vA[i].shade + vA[i+2].shade) >> 1;
#ifndef TERRAIN_NO_PATCHUP
#ifdef TERRAIN_DEBUG_AID
            if (!(flags & ESCH_TRN_DOTS))
#endif
            {
                float u_left,u_right,v_top,v_bottom;
                dword tlflags = sptr->flags;
                face[2].flags = fflags1;
                face[2].txt = sptr->cind;
                face[2].a = i;
                face[2].b = i+1;
                face[2].c = i+2;
                if (((tlflags & ESCH_SURF_CINDISTXT) &&
                   (!texture_shift2 || (!(tlflags & ESCH_SURF_NOTILE)))))
                {
                    compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                       tlflags,rect->x + (i << dlevel),
                                       rect->y,texture_shift2);

                    face[2].txt = sptr->cind;

                    face[2].u[0] = u_left;
                    face[2].u[1] = (u_left+u_right) / 2.0f;
                    face[2].u[2] = u_right;
                    face[2].v[0] = 0;
                    face[2].v[1] = 0;
                    face[2].v[2] = 0;
                }
                else
                {
                    face[2].flags &= ~ESCH_FACE_TEXTURED;
                }
                esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                sptr += pstep >> surfshift;
            }
#endif
        }

    }

    rptr += (width << dlevel);
    rsptr += (width << dlevel) >> surfshift;
    ptr = rptr;
    sptr = rsptr;

    for (i=1; i <= endy;)
    {
        cpt->x = rpt->x;
        cpt->y = rpt->y;
        cpt->z = rpt->z;
        cpt2->x = rpt->x + _dvec.i;
        cpt2->y = rpt->y + _dvec.j;
        cpt2->z = rpt->z + _dvec.k;

        for (j=0; j <= endx; j++)
        {   // Process lines ABC.
            float h = htable[*ptr];
            ((EschPoint*)vB)->x = cpt->x + (h * hvec.i);
            ((EschPoint*)vB)->y = cpt->y + (h * hvec.j);
            ((EschPoint*)vB)->z = cpt->z + (h * hvec.k);

            if (sptr->flags & ESCH_SURF_CINDISTXT)
            {
                vB->clr = txtcolor[sptr->cind-1];
            }
            else
            {
                vB->clr = sptr->cind;
            }

            vB->shade = sptr->shd;

            cpt->x = cpt->x + _wvec.i;
            cpt->y = cpt->y + _wvec.j;
            cpt->z = cpt->z + _wvec.k;
            vB++;

            if (i + 1 <= endy)
            {
                h = htable[ptr[width << dlevel]];
                ((EschPoint*)vC)->x = cpt2->x + (h * hvec.i);
                ((EschPoint*)vC)->y = cpt2->y + (h * hvec.j);
                ((EschPoint*)vC)->z = cpt2->z + (h * hvec.k);

                if (sptr->flags & ESCH_SURF_CINDISTXT)
                {
                    vC->clr = txtcolor[sptr[width << (dlevel - surfshift)].cind-1];
                }
                else
                {
                    vC->clr = sptr[width << (dlevel - surfshift)].cind;
                }
                vC->shade = sptr[width << (dlevel - surfshift)].shd;

                cpt2->x = cpt2->x + _wvec.i;
                cpt2->y = cpt2->y + _wvec.j;
                cpt2->z = cpt2->z + _wvec.k;
                vC++;
            }
            ptr+=pstep;
            sptr += pstep >> surfshift;
        }
        vA = &vpt[rowa];
        vB = &vpt[rowb];
        vC = &vpt[rowc];

        if (i+1 <= endy)
        {
            if (lflags & ESCH_TERNEX_SMOOTH_LEFT)
            {
                esch_surf_type      *tlsptr;
                tlsptr = rsptr - ((width << dlevel) >> surfshift);
                ((EschPoint*)vB)->x = (((EschPoint*)vA)->x
                                       + ((EschPoint*)vC)->x) / 2.0f;
                ((EschPoint*)vB)->y = (((EschPoint*)vA)->y
                                       + ((EschPoint*)vC)->y) / 2.0f;
                ((EschPoint*)vB)->z = (((EschPoint*)vA)->z
                                       + ((EschPoint*)vC)->z) / 2.0f;
                vB->shade = (vA->shade + vC->shade) >> 1;
#ifndef TERRAIN_NO_PATCHUP
#ifdef TERRAIN_DEBUG_AID
                if (!(flags & ESCH_TRN_DOTS))
#endif
                {
                    float u_left,u_right,v_top,v_bottom;
                    dword tlflags = tlsptr->flags;
                    face[2].flags = fflags1;
                    face[2].a = rowa;
                    face[2].b = rowb;
                    face[2].c = rowc;

                    if (((tlflags & ESCH_SURF_CINDISTXT) &&
                        (!texture_shift2 || (!(tlflags & ESCH_SURF_NOTILE)))))
                    {
                        compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                            tlflags,rect->x + (i << dlevel),
                                            rect->y,texture_shift2);

                        face[2].txt = tlsptr->cind;

                        face[2].u[0] = 0;
                        face[2].u[1] = 0;
                        face[2].u[2] = 0;
                        face[2].v[0] = v_top;
                        face[2].v[1] = (v_top + v_bottom) / 2.0f;
                        face[2].v[2] = v_bottom;
                    }
                    else
                    {
                        face[2].flags &= ~ESCH_FACE_TEXTURED;
                    }

                    esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                }
#endif
            }
            if (lflags & ESCH_TERNEX_SMOOTH_RIGHT)
            {
                esch_surf_type      *tlsptr;
                tlsptr = rsptr - ((width << dlevel) >> surfshift) + (rect->dx >> surfshift);

                ((EschPoint*)(&vB[endx]))->x = (((EschPoint*)(&vA[endx]))->x
                                        + ((EschPoint*)(&vC[endx]))->x) / 2.0f;
                ((EschPoint*)(&vB[endx]))->y = (((EschPoint*)(&vA[endx]))->y
                                        + ((EschPoint*)(&vC[endx]))->y) / 2.0f ;
                ((EschPoint*)(&vB[endx]))->z = (((EschPoint*)(&vA[endx]))->z
                                        + ((EschPoint*)(&vC[endx]))->z) / 2.0f ;
                vB[endx].shade = (vA[endx].shade + vC[endx].shade) >> 1;
#ifndef TERRAIN_NO_PATCHUP
#ifdef TERRAIN_DEBUG_AID
                if (!(flags & ESCH_TRN_DOTS))
#endif
                {
                    float u_left,u_right,v_top,v_bottom;
                    dword tlflags = tlsptr->flags;
                    face[2].flags = fflags1;
                    face[2].a = rowa + dx - 1;
                    face[2].b = rowb + dx - 1;
                    face[2].c = rowc + dx - 1;

                    if (((tlflags & ESCH_SURF_CINDISTXT) &&
                       (!texture_shift2 || (!(tlflags & ESCH_SURF_NOTILE)))))
                    {
                        compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                           tlflags,rect->x + (i << dlevel),
                                           rect->y,texture_shift2);

                        face[2].txt = tlsptr->cind;

                        face[2].u[0] = 0;
                        face[2].u[1] = 0;
                        face[2].u[2] = 0;
                        face[2].v[0] = v_top;
                        face[2].v[1] = (v_top + v_bottom) / 2.0f;
                        face[2].v[2] = v_bottom;
                    }
                    else
                    {
                        face[2].flags &= ~ESCH_FACE_TEXTURED;
                    }


                    esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                }
#endif
            }
        }

        if ((i+1 == endy) && (lflags & ESCH_TERNEX_SMOOTH_BOTTOM))
        {
            esch_surf_type      *tlsptr;
            tlsptr = rsptr + ((width << dlevel) >> surfshift);
            for (int k=0;k < endx-1;k+=2)
            {
                ((EschPoint*)(&vC[k+1]))->x = (((const EschPoint*)(&vC[k]))->x
                                            + ((const EschPoint*)(&vC[k+2]))->x) / 2.0f;
                ((EschPoint*)(&vC[k+1]))->y = (((const EschPoint*)(&vC[k]))->y
                                            + ((const EschPoint*)(&vC[k+2]))->y) / 2.0f;
                ((EschPoint*)(&vC[k+1]))->z = (((const EschPoint*)(&vC[k]))->z
                                            + ((const EschPoint*)(&vC[k+2]))->z) / 2.0f;
                vC[k+1].shade = (vC[k].shade + vC[k+2].shade) >> 1;
#ifndef TERRAIN_NO_PATCHUP
#ifdef TERRAIN_DEBUG_AID
                if (!(flags & ESCH_TRN_DOTS))
#endif
                {
                    float u_left,u_right,v_top,v_bottom;
                    dword tlflags = tlsptr->flags;
                    face[2].flags = fflags1;
                    face[2].txt = tlsptr->cind;
                    face[2].a = rowc + k;
                    face[2].b = rowc + k + 1;
                    face[2].c = rowc + k + 2;

                    if (((tlflags & ESCH_SURF_CINDISTXT) &&
                       (!texture_shift2 || (!(tlflags & ESCH_SURF_NOTILE)))))
                    {
                        compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                           tlflags,rect->x + (i << dlevel),
                                           rect->y,texture_shift2);

                        face[2].txt = tlsptr->cind;

                        face[2].u[0] = u_left;
                        face[2].u[1] = (u_left+u_right) / 2.0f;
                        face[2].u[2] = u_right;
                        face[2].v[0] = 0;
                        face[2].v[1] = 0;
                        face[2].v[2] = 0;
                    }
                    else
                    {
                        face[2].flags &= ~ESCH_FACE_TEXTURED;
                    }

                    esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                }
#endif
                tlsptr += pstep >> surfshift;
            }
        }
        else if (i == endy && (lflags & ESCH_TERNEX_SMOOTH_BOTTOM))
        {
            esch_surf_type      *tlsptr;
            tlsptr = rsptr;
            for (int k=0;k < endx-1;k+=2)
            {
                ((EschPoint*)(&vB[k+1]))->x = (((const EschPoint*)(&vB[k]))->x
                                    + ((const EschPoint*)(&vB[k+2]))->x) / 2.0f;
                ((EschPoint*)(&vB[k+1]))->y = (((const EschPoint*)(&vB[k]))->y
                                    + ((const EschPoint*)(&vB[k+2]))->y) / 2.0f;
                ((EschPoint*)(&vB[k+1]))->z = (((const EschPoint*)(&vB[k]))->z
                                    + ((const EschPoint*)(&vB[k+2]))->z) / 2.0f;
                vB[k+1].shade = (vB[k].shade + vB[k+2].shade) >> 1;
#ifndef TERRAIN_NO_PATCHUP
#ifdef TERRAIN_DEBUG_AID
                if (!(flags & ESCH_TRN_DOTS))
#endif
                {
                    float u_left,u_right,v_top,v_bottom;
                    dword tlflags = tlsptr->flags;
                    face[2].flags = fflags1;
                    face[2].txt = tlsptr->cind;
                    face[2].a = rowb + k;
                    face[2].b = rowb + k + 1;
                    face[2].c = rowb + k + 2;
                    if (((tlflags & ESCH_SURF_CINDISTXT) &&
                       (!texture_shift2 || (!(tlflags & ESCH_SURF_NOTILE)))))
                    {
                        compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                           tlflags,rect->x + (i << dlevel),
                                           rect->y,texture_shift2);

                        face[2].txt = tlsptr->cind;

                        face[2].u[0] = u_left;
                        face[2].u[1] = (u_left+u_right) / 2.0f;
                        face[2].u[2] = u_right;
                        face[2].v[0] = 0;
                        face[2].v[1] = 0;
                        face[2].v[2] = 0;
                    }
                    else
                    {
                        face[2].flags &= ~ESCH_FACE_TEXTURED;
                    }
                    esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                }
#endif
                tlsptr += pstep >> surfshift;
            }
        }


        //
        // Now spew out the faces....tl
        //
#ifdef TERRAIN_DEBUG_AID
        if (flags & ESCH_TRN_DOTS)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Dots
            //ÄÄÄ Clip against view volume
            // Near/far clip plane
            display_pixel_row(vA,endx);
            display_pixel_row(vB,endx);
            if (i+1 <= endy)
                display_pixel_row(vC,endx);
        }
        else
#endif
        {
            float u_left,u_right,v_top,v_bottom;
            esch_surf_type      *lsptr;
            lsptr = &rsptr[-((width >> surfshift) << dlevel)];
            dword tlflags;
            curx = leftx;

            for (int k=0; k < endx;k++)
            {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                if ((curx >= (left_edge[curz] - cstep)
                    || curx >= (left_edge[curz+step] - cstep))
                    && (curx <= (right_edge[curz] + cstep)
                    || curx <= (right_edge[curz+step] + cstep)))
#endif
                {
                    tlflags = lsptr->flags;
                    if (!(tlflags & ESCH_SURF_HIDDEN))
                    {
                        // draw the tri strip formed by rows a & b;
                        face[0].flags = fflags1;
                        face[1].flags = fflags2;

                        face[0].a = k;
                        face[0].b = k + rowb;
                        face[0].c = k + rowb + 1;

                        face[1].a = k;
                        face[1].b = k + rowb + 1;
                        face[1].c = k + 1;

                        if ((tlflags & ESCH_SURF_CINDISTXT) &&
                            (!texture_shift || !(tlflags & ESCH_SURF_NOTILE)))
                        {
                            face[0].txt = lsptr->cind;
                            face[1].txt = face[0].txt;

                            if (face[0].flags & ESCH_FACE_TEXTURED)
                            {
                                compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                                    tlflags,rect->x + (k << dlevel),
                                                    rect->y + (i << dlevel),
                                                    texture_shift);
                            }
                            else
                            {
                                u_left=u_right=v_bottom=v_top=0;
                            }
                            face[0].u[0] = u_left;
                            face[0].v[0] = v_bottom;
                            face[0].u[1] = u_left;
                            face[0].v[1] = v_top;
                            face[0].u[2] = u_right;
                            face[0].v[2] = v_top;

    //                        face[1].flags = face[0].flags;
                            face[1].u[0] = u_left;
                            face[1].v[0] = v_bottom;
                            face[1].u[1] = u_right;
                            face[1].v[1] = v_top;
                            face[1].u[2] = u_right;
                            face[1].v[2] = v_bottom;
                        }
                        else
                        {
                            face[0].flags &= ~ESCH_FACE_TEXTURED;
                            face[1].flags &= ~ESCH_FACE_TEXTURED;
                        }
                        esch_clipdraw_face(0,ctrlfl);
                        esch_clipdraw_face(1,ctrlfl);
                    }
                    else
                    {
                        int debug_trap = TRUE;
                    }
#ifdef TERRAIN_DEBUG_AID
                    if (flags & ESCH_TRN_DEBUG)
                    {
                        tpt.x = curx;
                        tpt.y = curz;
                        tpt.z = 0x10000;
                        cam->vport->clip_pixel(&tpt,&clr);
                    }
#endif
                }
                if( i+1 <= endy)
                {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                    if ((curx >= (left_edge[curz+step] - cstep)
                        || curx >= (left_edge[curz+step+step] - cstep))
                        && (curx <= (right_edge[curz+step] + cstep)
                        || curx <= (right_edge[curz+step+step] + cstep)))
#endif
                    {
                        int t = (width >> surfshift) << dlevel;
                        tlflags = lsptr[t].flags;
                        if (!(tlflags & ESCH_SURF_HIDDEN))
                        {

                            // draw the tri strip formed by rows b & c;
                            face[0].flags = fflags1;
                            face[0].a = k + rowb;
                            face[0].b = k + rowc;
                            face[0].c = k + rowc + 1;

                            face[1].flags = fflags2;
                            face[1].a = k + rowb;
                            face[1].b = k + rowc + 1;
                            face[1].c = k + rowb + 1;


                            if ((tlflags & ESCH_SURF_CINDISTXT) &&
                                (!texture_shift || !(tlflags & ESCH_SURF_NOTILE)))
                            {
                                face[0].txt = lsptr[t].cind;
                                face[1].txt = face[0].txt;

                                if (face[0].flags & ESCH_FACE_TEXTURED)
                                {
                                    compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                                        tlflags,rect->x  + (k << dlevel),
                                                        rect->y + ((i+1) << dlevel),
                                                        texture_shift);
                                }
                                else
                                {
                                    u_left=u_right=v_top=v_bottom=0;
                                }

                                face[0].u[0] = u_left;
                                face[0].v[0] = v_bottom;
                                face[0].u[1] = u_left;
                                face[0].v[1] = v_top;
                                face[0].u[2] = u_right;
                                face[0].v[2] = v_top;

    //                            face[1].flags = face[0].flags;
                                face[1].u[0] = u_left;
                                face[1].v[0] = v_bottom;
                                face[1].u[1] = u_right;
                                face[1].v[1] = v_top;
                                face[1].u[2] = u_right;
                                face[1].v[2] = v_bottom;
                            }
                            else
                            {
                                face[0].flags &= ~ESCH_FACE_TEXTURED;
                                face[1].flags &= ~ESCH_FACE_TEXTURED;
                            }
                            esch_clipdraw_face(0,ctrlfl);
                            esch_clipdraw_face(1,ctrlfl);
                        }
                        else
                        {
                            int debug_trap = TRUE;
                        }
#ifdef TERRAIN_DEBUG_AID
                        if (flags & ESCH_TRN_DEBUG)
                        {
                            tpt.x = curx;
                            tpt.y = curz + step;
                            tpt.z = 0x10000;
                            cam->vport->clip_pixel(&tpt,&clr);
                        }
#endif
                    }
                }
                curx += step;
                lsptr += pstep >> surfshift;
            }
            curz += step << 1;
            for (int l = 0;l <= endx;l++)
            {
                vflags[l] = vflags[l+rowb] = 0;
            }
        }


        //
        // Update all of the stuff to do the next two rows of points.
        //
        i += 2;

        rptr = rptr + (width << (dlevel + 1));
        ptr = rptr;

        rsptr = rsptr + ((width << (dlevel + 1)) >> surfshift);
        sptr = rsptr;

        rpt->x = rpt->x + _dvec.i + _dvec.i;
        rpt->y = rpt->y + _dvec.j + _dvec.j;
        rpt->z = rpt->z + _dvec.k + _dvec.k;
        cpt->x = rpt->x;
        cpt->y = rpt->y;
        cpt->z = rpt->z;
        cpt2->x = rpt->x + _dvec.i;
        cpt2->y = rpt->y + _dvec.j;
        cpt2->z = rpt->z + _dvec.k;

        if (i  <= endy)
        {
            for (j=0; j <= endx; j++)
            {   // Process lines CBA.
                float h = htable[*ptr];
                ((EschPoint*)vB)->x = cpt->x + (h * hvec.i);
                ((EschPoint*)vB)->y = cpt->y + (h * hvec.j);
                ((EschPoint*)vB)->z = cpt->z + (h * hvec.k);

                if (sptr->flags & ESCH_SURF_CINDISTXT)
                {
                    vB->clr = txtcolor[sptr->cind-1];
                }
                else
                {
                    vB->clr = sptr->cind;
                }
                vB->shade = sptr->shd;
                cpt->x = cpt->x + _wvec.i;
                cpt->y = cpt->y + _wvec.j;
                cpt->z = cpt->z + _wvec.k;
                vB++;
                if (i+1 <= endy)
                {
                    h = htable[ptr[width << dlevel]];
                    ((EschPoint*)vA)->x = cpt2->x + (h * hvec.i);
                    ((EschPoint*)vA)->y = cpt2->y + (h * hvec.j);
                    ((EschPoint*)vA)->z = cpt2->z + (h * hvec.k);

                    if (sptr->flags & ESCH_SURF_CINDISTXT)
                    {
                        vA->clr = txtcolor[sptr[width << (dlevel - surfshift)].cind-1];
                    }
                    else
                    {
                        vA->clr = sptr[width << (dlevel - surfshift)].cind;
                    }

                    vA->shade = sptr[width << (dlevel - surfshift)].shd;
                    cpt2->x = cpt2->x + _wvec.i;
                    cpt2->y = cpt2->y + _wvec.j;
                    cpt2->z = cpt2->z + _wvec.k;
                    vA++;
                }
                ptr += pstep;
                sptr += pstep >> surfshift;

            }
            vA = &vpt[rowa];
            vB = &vpt[rowb];
            vC = &vpt[rowc];

            if (i+1 <= endy)
            {
                if (lflags & ESCH_TERNEX_SMOOTH_LEFT)
                {
                    esch_surf_type      *tlsptr;
                    tlsptr = rsptr - ((width << dlevel) >> surfshift);
                    ((EschPoint*)vB)->x = (((EschPoint*)vA)->x
                                           + ((EschPoint*)vC)->x) / 2.0f;
                    ((EschPoint*)vB)->y = (((EschPoint*)vA)->y
                                           + ((EschPoint*)vC)->y) / 2.0f;
                    ((EschPoint*)vB)->z = (((EschPoint*)vA)->z
                                           + ((EschPoint*)vC)->z) / 2.0f;
                    vB->shade = (vA->shade + vC->shade) >> 1;
#ifndef TERRAIN_NO_PATCHUP
#ifdef TERRAIN_DEBUG_AID
                    if (!(flags & ESCH_TRN_DOTS))
#endif
                    {
                        float u_left,u_right,v_top,v_bottom;
                        dword tlflags = tlsptr->flags;
                        face[2].flags = fflags1;
                        face[2].a = rowa;
                        face[2].b = rowb;
                        face[2].c = rowc;

                        if (((tlflags & ESCH_SURF_CINDISTXT) &&
                           (!texture_shift2 || (!(tlflags & ESCH_SURF_NOTILE)))))
                        {
                            compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                               tlflags,rect->x + (i << dlevel),
                                               rect->y,texture_shift2);

                            face[2].txt = tlsptr->cind;

                            face[2].u[0] = 0;
                            face[2].u[1] = 0;
                            face[2].u[2] = 0;
                            face[2].v[0] = v_top;
                            face[2].v[1] = (v_top + v_bottom) / 2.0f;
                            face[2].v[2] = v_bottom;
                        }
                        else
                        {
                            face[2].flags &= ~ESCH_FACE_TEXTURED;
                        }

                        esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                    }
#endif
                }
                if (lflags & ESCH_TERNEX_SMOOTH_RIGHT)
                {
                    esch_surf_type      *tlsptr;
                    tlsptr = rsptr - ((width << dlevel) >> surfshift) + (rect->dx >> surfshift);
                    ((EschPoint*)(&vB[endx]))->x = (((const EschPoint*)(&vA[endx]))->x
                                    + ((const EschPoint*)(&vC[endx]))->x) / 2.0f;
                    ((EschPoint*)(&vB[endx]))->y = (((const EschPoint*)(&vA[endx]))->y
                                    + ((const EschPoint*)(&vC[endx]))->y) / 2.0f;
                    ((EschPoint*)(&vB[endx]))->z = (((const EschPoint*)(&vA[endx]))->z
                                    + ((const EschPoint*)(&vC[endx]))->z) / 2.0f;
                    vB[endx].shade = (vA[endx].shade + vC[endx].shade) >> 1;
#ifndef TERRAIN_NO_PATCHUP
#ifdef TERRAIN_DEBUG_AID
                    if (!(flags & ESCH_TRN_DOTS))
#endif
                    {
                        float u_left,u_right,v_top,v_bottom;
                        dword tlflags = tlsptr->flags;
                        face[2].flags = fflags1;
                        face[2].a = rowa + dx - 1;
                        face[2].b = rowb + dx - 1;
                        face[2].c = rowc + dx - 1;

                        if (((tlflags & ESCH_SURF_CINDISTXT) &&
                           (!texture_shift2 || (!(tlflags & ESCH_SURF_NOTILE)))))
                        {
                            compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                               tlflags,rect->x + (i << dlevel),
                                               rect->y,texture_shift2);

                            face[2].txt = tlsptr->cind;

                            face[2].u[0] = 0;
                            face[2].u[1] = 0;
                            face[2].u[2] = 0;
                            face[2].v[0] = v_top;
                            face[2].v[1] = (v_top + v_bottom) / 2.0f;
                            face[2].v[2] = v_bottom;
                        }
                        else
                        {
                            face[2].flags &= ~ESCH_FACE_TEXTURED;
                        }

                        esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                    }
#endif
                }
            }

            if (((i+1) == endy) && (lflags & ESCH_TERNEX_SMOOTH_BOTTOM))
            {
                esch_surf_type      *tlsptr;
                tlsptr = rsptr + ((width << dlevel) >> surfshift);
                for (int k=0;k < endx-1;k+=2)
                {
                    ((EschPoint*)(&vA[k+1]))->x = (((const EschPoint*)(&vA[k]))->x
                                    + ((const EschPoint*)(&vA[k+2]))->x) / 2.0f;
                    ((EschPoint*)(&vA[k+1]))->y = (((const EschPoint*)(&vA[k]))->y
                                    + ((const EschPoint*)(&vA[k+2]))->y) / 2.0f;
                    ((EschPoint*)(&vA[k+1]))->z = (((const EschPoint*)(&vA[k]))->z
                                    + ((const EschPoint*)(&vA[k+2]))->z) / 2.0f;
                    vA[k+1].shade = (vA[k].shade + vA[k+2].shade) >> 1;
#ifndef TERRAIN_NO_PATCHUP
#ifdef TERRAIN_DEBUG_AID
                    if (!(flags & ESCH_TRN_DOTS))
#endif
                    {
                        float u_left,u_right,v_top,v_bottom;
                        dword tlflags = tlsptr->flags;
                        face[2].flags = fflags1;
                        face[2].txt = tlsptr->cind;
                        face[2].a = rowa + k;
                        face[2].b = rowa + k + 1;
                        face[2].c = rowa + k + 2;

                        if (((tlflags & ESCH_SURF_CINDISTXT) &&
                           (!texture_shift2 || (!(tlflags & ESCH_SURF_NOTILE)))))
                        {
                            compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                               tlflags,rect->x + (i << dlevel),
                                               rect->y,texture_shift2);

                            face[2].txt = tlsptr->cind;

                            face[2].u[0] = u_left;
                            face[2].u[1] = (u_left+u_right) / 2.0f;
                            face[2].u[2] = u_right;
                            face[2].v[0] = 0;
                            face[2].v[1] = 0;
                            face[2].v[2] = 0;
                        }
                        else
                        {
                            face[2].flags &= ~ESCH_FACE_TEXTURED;
                        }

                        esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                    }
#endif
                    tlsptr += pstep >> surfshift;
                }
            }
            else if (i == endy && (lflags & ESCH_TERNEX_SMOOTH_BOTTOM))
            {
                esch_surf_type      *tlsptr;
                tlsptr = rsptr;
                for (int k=0;k < endx-1;k+=2)
                {
                    ((EschPoint*)(&vB[k+1]))->x = (((const EschPoint*)(&vB[k]))->x
                                    + ((const EschPoint*)(&vB[k+2]))->x) / 2.0f;
                    ((EschPoint*)(&vB[k+1]))->y = (((const EschPoint*)(&vB[k]))->y
                                    + ((const EschPoint*)(&vB[k+2]))->y) / 2.0f;
                    ((EschPoint*)(&vB[k+1]))->z = (((const EschPoint*)(&vB[k]))->z
                                    + ((const EschPoint*)(&vB[k+2]))->z) / 2.0f;
                    vB[k+1].shade = (vB[k].shade + vB[k+2].shade) >> 1;

#ifndef TERRAIN_NO_PATCHUP
#ifdef TERRAIN_DEBUG_AID
                    if (!(flags & ESCH_TRN_DOTS))
#endif
                    {
                        float u_left,u_right,v_top,v_bottom;
                        dword tlflags = tlsptr->flags;
                        face[2].flags = fflags1;
                        face[2].txt = tlsptr->cind;
                        face[2].a = rowb + k;
                        face[2].b = rowb + k + 1;
                        face[2].c = rowb + k + 2;

                        if (((tlflags & ESCH_SURF_CINDISTXT) &&
                           (!texture_shift2 || (!(tlflags & ESCH_SURF_NOTILE)))))
                        {
                            compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                               tlflags,rect->x + (i << dlevel),
                                               rect->y,texture_shift2);

                            face[2].txt = tlsptr->cind;

                            face[2].u[0] = u_left;
                            face[2].u[1] = (u_left+u_right) / 2.0f;
                            face[2].u[2] = u_right;
                            face[2].v[0] = 0;
                            face[2].v[1] = 0;
                            face[2].v[2] = 0;
                        }
                        else
                        {
                            face[2].flags &= ~ESCH_FACE_TEXTURED;
                        }

                        esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                    }
#endif
                    tlsptr += pstep >> surfshift;
                }
            }
        }
#ifdef TERRAIN_DEBUG_AID
        if (flags & ESCH_TRN_DOTS)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Dots
            //ÄÄÄ Clip against view volume
            // Near/far clip plane
            if (i <= endy)
                display_pixel_row(vB,endx);
        }
        else
#endif
        {
            float u_left,u_right,v_top,v_bottom;
            esch_surf_type      *lsptr;
            lsptr = &rsptr[-((width >> surfshift) << dlevel)];
            dword tlflags;


            curx = leftx;
            for (int k=0; k < endx;k++)
            {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                if ((curx >= (left_edge[curz] - cstep)
                    || curx >= (left_edge[curz+step] - cstep))
                    && (curx <= (right_edge[curz] + cstep)
                    || curx <= (right_edge[curz+step] + cstep)))
#endif
                {
                    if (i <= endy)
                    {
                        tlflags = lsptr->flags;

                        if (!(tlflags & ESCH_SURF_HIDDEN))
                        {

                            // draw the tri strip formed by rows c & b;
                            face[0].flags = fflags1;
                            face[1].flags = fflags2;

                            face[0].a = k + rowc;
                            face[0].b = k + rowb;
                            face[0].c = k + rowb + 1;

                            face[1].a = k + rowc;
                            face[1].b = k + rowb + 1;
                            face[1].c = k + rowc + 1;

                            if ((tlflags & ESCH_SURF_CINDISTXT) &&
                                (!texture_shift || !(tlflags & ESCH_SURF_NOTILE)))
                            {
                                face[0].txt = lsptr->cind;
                                face[1].txt = face[0].txt;

                                if (face[0].flags & ESCH_FACE_TEXTURED)
                                {
                                    compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                                        tlflags,rect->x  + (k << dlevel),
                                                        rect->y + (i << dlevel),
                                                        texture_shift);
                                }
                                else
                                {
                                    u_left=u_right=v_top=v_bottom=0;
                                }

                                face[0].u[0] = u_left;
                                face[0].v[0] = v_bottom;
                                face[0].u[1] = u_left;
                                face[0].v[1] = v_top;
                                face[0].u[2] = u_right;
                                face[0].v[2] = v_top;

    //                            face[1].flags = face[0].flags;
                                face[1].u[0] = u_left;
                                face[1].v[0] = v_bottom;
                                face[1].u[1] = u_right;
                                face[1].v[1] = v_top;
                                face[1].u[2] = u_right;
                                face[1].v[2] = v_bottom;
                            }
                            else
                            {
                                face[0].flags &= ~ESCH_FACE_TEXTURED;
                                face[1].flags &= ~ESCH_FACE_TEXTURED;
                            }
                            esch_clipdraw_face(0,ctrlfl);
                            esch_clipdraw_face(1,ctrlfl);
                        }
                        else
                        {
                            int debug_trap = TRUE;
                        }
#ifdef TERRAIN_DEBUG_AID
                        if (flags & ESCH_TRN_DEBUG)
                        {
                            tpt.x = curx;
                            tpt.y = curz;
                            tpt.z = 0x10000;

                            cam->vport->clip_pixel(&tpt,&clr);
                        }
#endif
                    }
                }
                if( i+1 <= endy)
                {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                    if ((curx >= (left_edge[curz+step] - cstep)
                        || curx >= (left_edge[curz+step+step] - cstep))
                        && (curx <= (right_edge[curz+step] + cstep)
                        || curx <= (right_edge[curz+step+step] + cstep)))
#endif
                    {
                        int t = (width >> surfshift) << dlevel;
                        tlflags = lsptr[t].flags;

                        if (!(tlflags & ESCH_SURF_HIDDEN))
                        {

                            // draw the tri strip formed by rows b & a;
                            face[0].flags = fflags1;
                            face[1].flags = fflags2;

                            face[0].a = k + rowb;
                            face[0].b = k + rowa;
                            face[0].c = k + rowa + 1;

                            face[1].a = k + rowb;
                            face[1].b = k + rowa + 1;
                            face[1].c = k + rowb + 1;

                            if ((tlflags & ESCH_SURF_CINDISTXT) &&
                                (!texture_shift || !(tlflags & ESCH_SURF_NOTILE)))
                            {
                                face[0].txt = lsptr[t].cind;
                                face[1].txt = face[0].txt;

                                if (face[0].flags & ESCH_FACE_TEXTURED)
                                {
                                    compute_texture_uv(u_left,u_right,v_top,v_bottom,
                                                        tlflags,rect->x + (k << dlevel),
                                                        rect->y + ((i+1) << dlevel),
                                                        texture_shift);
                                }
                                else
                                {
                                    u_left=u_right=v_top=v_bottom=0;
                                }

                                face[0].u[0] = u_left;
                                face[0].v[0] = v_bottom;
                                face[0].u[1] = u_left;
                                face[0].v[1] = v_top;
                                face[0].u[2] = u_right;
                                face[0].v[2] = v_top;

    //                            face[1].flags = face[0].flags;
                                face[1].u[0] = u_left;
                                face[1].v[0] = v_bottom;
                                face[1].u[1] = u_right;
                                face[1].v[1] = v_top;
                                face[1].u[2] = u_right;
                                face[1].v[2] = v_bottom;
                            }
                            else
                            {
                                face[0].flags &= ~ESCH_FACE_TEXTURED;
                                face[1].flags &= ~ESCH_FACE_TEXTURED;
                            }

                            esch_clipdraw_face(0,ctrlfl);
                            esch_clipdraw_face(1,ctrlfl);
                        }
                        else
                        {
                            int debug_trap = TRUE;
                        }

#ifdef TERRAIN_DEBUG_AID
                        if (flags & ESCH_TRN_DEBUG)
                        {
                            tpt.x = curx;
                            tpt.y = curz + step;
                            tpt.z = 0x10000;
                            cam->vport->clip_pixel(&tpt,&clr);
                        }
#endif
                    }
                }
                curx += step;
                lsptr += pstep >> surfshift;
            }
            curz += step << 1;
            for (int l = 0;l <= endx;l++)
            {
                vflags[rowc+l] = vflags[l+rowb] = 0;
            }
        }

        rptr += (width << (dlevel + 1));
        ptr = rptr;

        rsptr = rsptr + ((width << (dlevel + 1)) >> surfshift);
        sptr = rsptr;

        rpt->x = rpt->x + _dvec.i + _dvec.i;
        rpt->y = rpt->y + _dvec.j + _dvec.j;
        rpt->z = rpt->z + _dvec.k + _dvec.k;
        i += 2;

    }
#ifdef TERRAIN_DEBUG_AID
    if(flags & ESCH_TRN_DEBUG)
    {

        VngoColor24bit color(255,0,0);
        // go ahead and draw the rect.
        if (dlevel == 1)
        {
            color.r = 0;
            color.g = 255;
            color.b = 0;
        }
        else if (dlevel == 2)
        {
            color.r = 0;
            color.g = 0;
            color.b = 255;
        }
        else if (dlevel == 3)
        {
            color.r = 255;
            color.g = 255;
            color.b = 255;
        }
        else if (dlevel == 4)
        {
            color.r = 255;
            color.g = 255;
            color.b = 0;
        }

        VngoPoint   pts[4];
        pts[0].x = rect->x;
        pts[1].x = rect->x + rect->dx;
        pts[2].x = rect->x + rect->dx;
        pts[3].x = rect->x;

        pts[0].y = rect->y;
        pts[1].y = rect->y;
        pts[2].y = rect->y + rect->dy;
        pts[3].y = rect->y + rect->dy;

        pts[0].z = 0x10000 + (dlevel << 16);
        pts[1].z = 0x10000 + (dlevel << 16);
        pts[2].z = 0x10000 + (dlevel << 16);
        pts[3].z = 0x10000 + (dlevel << 16);

        cam->vport->clip_line(&pts[0],&pts[1],&color);
        cam->vport->clip_line(&pts[1],&pts[2],&color);
        cam->vport->clip_line(&pts[2],&pts[3],&color);
        cam->vport->clip_line(&pts[3],&pts[0],&color);
    }
#endif

//ÄÄÄ Pop drawing context
    ec.pop();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - esch_find_draw_volume                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::esch_find_draw_volume()
{
    EschCamera             *cam;
    VngoPoint              pt1,pt2;

    cam=EschCurrent->camera;

    //
    // Get and draw the camera position in blue.
    //
    EschPoint   pos;
    cam->get_position(&pos);

    //
    // Get and draw the viewing frustrum.
    //
    VngoPoint   vpt[6];

    float modifier = float(1<< (scaleshift + 2)); // this help enlarge area slightly.
    EschVector  cvect= -cam->eye.dir;
    cvect *=modifier;


    vpt[0].x = (long(pos.x + cvect.i) >> scaleshift) + (width>>1);
    vpt[0].y = (long(pos.z + cvect.k) >> scaleshift) + (width>>1);

    // Calc the 4 corners.
    float tz = cam->yon + modifier;
    float tx = tz * cam->xsize;
    float ty = tz * cam->ysize;

    EschPoint   tpt;

    tpt.x = tx;
    tpt.y = ty;
    tpt.z = tz;

    ::esch_transform(&tpt,&cam->eye.orient,&tpt);

    vpt[1].x = (long(tpt.x) >> scaleshift) + (width>>1);
    vpt[1].y = (long(tpt.z) >> scaleshift) + (width>>1);

    tpt.x = -tx;
    tpt.y = ty;
    tpt.z = tz;

    ::esch_transform(&tpt,&cam->eye.orient,&tpt);

    vpt[2].x = (long(tpt.x) >> scaleshift) + (width>>1);
    vpt[2].y = (long(tpt.z) >> scaleshift) + (width>>1);

    tpt.x = -tx;
    tpt.y = -ty;
    tpt.z = tz;

    ::esch_transform(&tpt,&cam->eye.orient,&tpt);

    vpt[3].x = (long(tpt.x) >> scaleshift) + (width>>1);
    vpt[3].y = (long(tpt.z) >> scaleshift) + (width>>1);

    tpt.x = tx;
    tpt.y = -ty;
    tpt.z = tz;

    ::esch_transform(&tpt,&cam->eye.orient,&tpt);

    vpt[4].x = (long(tpt.x) >> scaleshift) + (width>>1);
    vpt[4].y = (long(tpt.z) >> scaleshift) + (width>>1);

    VngoPoint bound[4];

    bound[0] = vpt[0];
    bound[1] = vpt[0];
    bound[2] = vpt[0];
    bound[3] = vpt[0];

    for (int j = 1; j < 5; j++)
    {
        // find top-left.
        if (vpt[j].x < bound[0].x)
            bound[0].x = vpt[j].x;
        if (vpt[j].y < bound[0].y)
            bound[0].y = vpt[j].y;

        // find top-right
        if (vpt[j].x > bound[1].x)
            bound[1].x = vpt[j].x;
        if (vpt[j].y < bound[1].y)
            bound[1].y = vpt[j].y;

        // find bottom-right
        if (vpt[j].x > bound[2].x)
            bound[2].x = vpt[j].x;
        if (vpt[j].y > bound[2].y)
            bound[2].y = vpt[j].y;

        // find bottom-left
        if (vpt[j].x < bound[3].x)
            bound[3].x = vpt[j].x;
        if (vpt[j].y > bound[3].y)
            bound[3].y = vpt[j].y;
    }

    // Calc the bounding rect for the drawing area.
    // and get the position of the camera.
    ccol = vpt[0].x;
    crow = vpt[0].y;

    darea.x = bound[0].x - 1;
    darea.y = bound[0].y - 1;
    darea.dx = bound[2].x - darea.x + 2;
    darea.dy = bound[2].y - darea.y + 2;

    int t;
    if (darea.x < 0)
    {
        t = darea.x;
        darea.x = 0;
        darea.dx += t;
    }
    if (darea.x + darea.dx >= width)
        darea.dx = width - darea.x - 1;
    if (darea.y < 0)
    {
        t = darea.y;
        darea.y = 0;
        darea.dy += t;
    }
    if (darea.y + darea.dy >= depth)
        darea.dy = depth - darea.y - 1;

#ifndef TERRAIN_NO_FRUSTRUM_WALK
    setup_edge_limits(vpt);
#endif

#ifdef TERRAIN_DEBUG_AID
    VngoColor24bit color(0,0,0);
    int c = cam->vport->vbuff.pal->get_index(color);

    if (flags & ESCH_TRN_DEBUG)
    {
        cam->vport->clip_frect(&darea,c);

        color.r = 255;
        color.g = 255;
        vpt[0].z = 0x10000;
        vpt[1].z = 0x10000;
        vpt[2].z = 0x10000;
        vpt[3].z = 0x10000;
        vpt[4].z = 0x10000;
        cam->vport->clip_line(&vpt[0],&vpt[1],&color);
        cam->vport->clip_line(&vpt[0],&vpt[2],&color);
        cam->vport->clip_line(&vpt[0],&vpt[3],&color);
        cam->vport->clip_line(&vpt[0],&vpt[4],&color);

        cam->vport->clip_line(&vpt[1],&vpt[2],&color);
        cam->vport->clip_line(&vpt[2],&vpt[3],&color);
        cam->vport->clip_line(&vpt[3],&vpt[4],&color);
        cam->vport->clip_line(&vpt[4],&vpt[1],&color);

        color.r = 0;
        color.g = 255;
        color.b = 255;
        VngoPoint   pts[5];

        pts[0].x = darea.x;
        pts[0].y = darea.y;
        pts[0].z = 0x10000;
        pts[1].x = darea.x + darea.dx;
        pts[1].y = darea.y;
        pts[1].z = 0x10000;
        pts[2].x = pts[1].x;
        pts[2].y = darea.y + darea.dy;
        pts[2].z = 0x10000;
        pts[3].x = darea.x;
        pts[3].y = pts[2].y;
        pts[3].z = 0x10000;

        color.r = 255;
        color.g = 0;
        color.b = 255;

        cam->vport->clip_line(&pts[0],&pts[1],&color);
        cam->vport->clip_line(&pts[1],&pts[2],&color);
        cam->vport->clip_line(&pts[2],&pts[3],&color);
        cam->vport->clip_line(&pts[3],&pts[0],&color);
    }
#endif
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - get_height                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
float EschTerrainEx::get_height(float x, float z) const
{
    float   x0,y0,z0,a1,a2,b1,b2,c1,c2,t1,t2,y;

    float _x = x - origin.x;
    float _z = z - origin.z;

    assertMyth("EschTerrain::get_height needs height-field information",
               hfield && htable);

    assertMyth("EschTerrain:get_height needs positive scales",
               scale > 0);

    int     lx = (int)_x >> scaleshift;
    int     lz = (int)_z >> scaleshift;

    float   wx = float(lx << scaleshift);
    float   wz = float(lz << scaleshift);

    x = _x - wx;
    z = _z - wz;

//ÄÄÄÄ Check that point is on map
    if ((lx < 0)
        || (lz < 0)
        || (lx >= width)
        || (lz >= depth))
        return 0;

    byte *ptr = &hfield[( lz * width ) + lx];

//ÄÄÄÄ Compute parameters t1 and t2, and assign b1/b2

    c2 = scale;
    if (x < z)
    {
        x0 = 0;
        y0 = htable[*ptr];
        z0 = 0;
        a1 = 0;

        b1 = htable[*(ptr+width)] - y0;
        b2 = htable[*(ptr+width+1)] - y0;

        c1 = scale;
        a2 = scale;

        t2 = (x0 - x) / -a2;
        t1 = (z0 + (c2 * t2) - z) / -c1;
    }
    else
    {
        x0 = 0;
        y0 = htable[*ptr];
        z0 = 0;
        a1 = scale;
        a2 = scale;

        b1 = htable[*(ptr+width+1)] - y0;
        b2 = htable[*(ptr+1)] - y0;

        c1 = scale;
        c2 = 0;

        t1 = (z0 -z) / -c1;
        t2 = (x0 + (a1 * t1) - x) / -a2;
    }
//ÄÄÄÄ Compute y
    y = y0 + (b1 * t1) + (b2 * t2);
    return (y + origin.y);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - set_lod                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::set_lod (int count, ...)
{
    assert (count <= 8);
    if (dlevels)
    {
        delete [] dlevels;
    }
    dlevels = new float [count];
    if (!dlevels)
    {
        num_dlevels=0;
        return;
    }
    else
    {
        num_dlevels = count;
        flags |= ESCH_TRN_LOD;
    }

    va_list ap;
    va_start (ap, count);
    for (int i=0; i < count - 1; i++)
    {
        dlevels[i] = (float) va_arg(ap, double);
    }
    va_end(ap);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - set_start_lod                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::set_start_lod(int lod)
{
    start_dlevel = lod;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - set_texture_load                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::set_texture_lod(int lod)
{
    if (lod > num_dlevels)
        max_texture_lod = num_dlevels;
    else
        max_texture_lod = lod;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - set_perspective_lod                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::set_perspective_lod(int lod)
{
    if (lod > num_dlevels)
        max_perspective_lod = num_dlevels;
    else
        max_perspective_lod = lod;

    if (max_perspective_lod > max_texture_lod)
        max_perspective_lod = max_texture_lod;

}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - set_smooth_lod                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::set_smooth_lod(int lod)
{
    if (lod > num_dlevels)
        max_smooth_lod = num_dlevels;
    else
        max_smooth_lod = lod;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - hide_rect                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::hide_rect(VngoRect &hrect)
{
    esch_surf_type *sptr = surfinfo;

    // The first thing we need to do is make sure the rect is aligned properly.
    VngoRect trect = hrect;
    if (surfshift)  // There is no need to do anything if there is no surfaceshift.
    {
        int left = trect.x;
        int right = trect.x + trect.dx;
        int top = trect.y;
        int bottom = trect.dy + trect.y;

        dword mask = (1 << surfshift) - 1;
        left += mask;
        left &= ~mask;
        right &= ~mask;
        top += mask;
        top &= ~mask;
        bottom &= ~mask;
        trect.x = left;
        trect.y = top;
        trect.dx = right - left;
        trect.dy = bottom - top;
    }

    int step = 1 << surfshift;
    int wstep = width >> surfshift;
    sptr += (trect.y * wstep);
    sptr += (trect.x >> surfshift);
    for (int y=0;y < trect.dy;y+=step)
    {
        for (int x=0;x < trect.dx;x+=step)
        {
            sptr[x].flags |= ESCH_SURF_HIDDEN;
        }
        sptr += wstep;
    }
}

//°±² End of module - esternex.cpp ²±°

