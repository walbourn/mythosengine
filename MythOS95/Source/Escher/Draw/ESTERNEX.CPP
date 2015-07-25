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
// #define TERRAIN_NO_PATCHUP

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

        if (dlevel == (num_dlevels-1))
            flags &= ~ESCH_TERNEX_SMOOTH_ALL;

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

    if (dlevel == (num_dlevels-1))
        flags |= ESCH_TERNEX_SMOOTH_ALL;
    return (work_rect);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - display_pixel_row                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::display_pixel_row(VngoPoint *vpt,int count,dword cflags)
{
    int         k;
    VngoPoint   *vpnt;
    float       zx, zy;

    for (k=0;k < count;k++)
    {
        vpnt = &vpt[k];
        const EschPoint *pnt = (const EschPoint*)vpnt;

        if ( (pnt->z <= cam->yon)
             && (pnt->z >= cam->hither) )
        {
            if (cflags & ESCH_CAM_ORTHO)
            {
                zx = cam->xsize;
                zy = cam->ysize;

                if ((pnt->x >= -zx)
                    && (pnt->x <= zx)
                    && (pnt->y >= -zy)
                    && (pnt->y <= zy))
                {
                    vpnt->x = long(pnt->x * cam->xscalar)
                              + (cam->vport->vbuff.width>>1);

                    vpnt->y = (cam->vport->vbuff.height>>1)
                               - long(pnt->y * cam->yscalar);

                    vpnt->z = ulong(pnt->z * cam->z_factor * float(0xffffffff));

                    //ÄÄÄ Draw pdxel
                    cam->vport->pixel(vpnt);
                }
            }
            else
            {
                zx = pnt->z * cam->xsize;
                zy = pnt->z * cam->ysize;

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
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - draw_terrain_rect                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::draw_terrain_rect (VngoRect *rect, int dlevel,dword lflags)
{
    long            st = ((width >> surfshift) * (rect->y >> surfshift)) + (rect->x >> surfshift);
    esch_surf_type  *sptr = surfinfo + st;
    byte            *lhfield = hfield + (width * rect->y) + rect->x;

    VngoRect trect;
    trect.x = rect->x;
    trect.y = rect->y;
    trect.dx = rect->dx;
    trect.dy = rect->dy;
    int mod = 2 << dlevel;
    if (lflags & ESCH_TERNEX_SMOOTH_TOP)
    {
        trect.y += mod;
        trect.dy -= mod;
    }
    if (lflags & ESCH_TERNEX_SMOOTH_BOTTOM)
    {
        trect.dy -= mod;
    }
    if (lflags & ESCH_TERNEX_SMOOTH_LEFT)
    {
        trect.x += mod;
        trect.dx -= mod;
    }
    if (lflags & ESCH_TERNEX_SMOOTH_RIGHT)
    {
        trect.dx -= mod;
    }

    if (trect.dx > 0 && trect.dy > 0)
        draw_terrain_trans_rect(&trect,dlevel,lflags);

    EschPoint root_point;
    root_point.x = origin.x + float(rect->x << scaleshift);
    root_point.y = origin.y;
    root_point.z = origin.z + float(rect->y << scaleshift);

    ::esch_transform(&root_point,&cam->eye.iorient,&root_point);

    if (lflags & ESCH_TERNEX_SMOOTH_TOP)
    {
        VngoRect  wrect = *rect;
        EschPoint troot2 = root_point;
        int hfoff = 0;
        int spoff = 0;
        if (lflags & ESCH_TERNEX_SMOOTH_RIGHT)
        {
            wrect.dx -= mod;

            VngoRect trect = *rect;
            trect.x = trect.x + trect.dx - mod;
            trect.dx = mod;
            trect.dy = mod;

            EschPoint troot = troot2;
            troot.x = troot.x + (wvec.i * float(rect->dx-mod));
            troot.y = troot.y + (wvec.j * float(rect->dx-mod));
            troot.z = troot.z + (wvec.k * float(rect->dx-mod));

            draw_terrain_trans_ur(&trect,&troot,lhfield+(rect->dx-mod),
                                  sptr + ((rect->dx-mod) >> surfshift),
                                  dlevel,lflags);
        }
        if (lflags & ESCH_TERNEX_SMOOTH_LEFT)
        {
            wrect.x += mod;
            wrect.dx -= mod;

            VngoRect trect = *rect;
            trect.dx = mod;
            trect.dy = mod;

            troot2.x = troot2.x + (wvec.i * float(mod));
            troot2.y = troot2.y + (wvec.j * float(mod));
            troot2.z = troot2.z + (wvec.k * float(mod));

            draw_terrain_trans_ul(&trect,&root_point,lhfield,sptr,dlevel,lflags);

            hfoff+=mod;
            spoff+=(mod >> surfshift);
        }
        int count = (wrect.dx >> dlevel);

        draw_terrain_trans_top(&wrect,&troot2,lhfield+hfoff,sptr+spoff,
                               dlevel,count,lflags);
    }
#if 1
    if (lflags & ESCH_TERNEX_SMOOTH_BOTTOM)
    {
        int count_mod = 0;
        VngoRect    wrect = *rect;
        wrect.y += wrect.dy - mod;
        wrect.dy = mod;
        EschPoint troot2 = root_point;
        troot2.x += dvec.i * float(rect->dy - mod);
        troot2.y += dvec.j * float(rect->dy - mod);
        troot2.z += dvec.k * float(rect->dy - mod);
        // check to ensure troot2 within clip rect...  How could it not be in if it is within dy?
        int hfoff = width * (rect->dy - mod);
        int spoff = hfoff >> surfshift;

        if (lflags & ESCH_TERNEX_SMOOTH_RIGHT)
        {
            VngoRect trect = *rect;
            trect.x = trect.x + trect.dx - mod;
            trect.y = trect.y + trect.dy - mod;
            trect.dx = mod;
            trect.dy = mod;

            wrect.dx -=mod;

            EschPoint troot = troot2;
            troot.x += (wvec.i * float(rect->dx-mod));
            troot.y += (wvec.j * float(rect->dx-mod));
            troot.z += (wvec.k * float(rect->dx-mod));

            int thfoff = (rect->dx-mod) + hfoff;
            int tspoff = ((rect->dx-mod) >> surfshift) + spoff;

            draw_terrain_trans_br(&trect,&troot,lhfield+thfoff, sptr+tspoff,
                                  dlevel,lflags);

        }
        if (lflags & ESCH_TERNEX_SMOOTH_LEFT)
        {
            wrect.x += mod;
            wrect.dx -= mod;
            VngoRect trect = *rect;
            trect.y = trect.y + trect.dy - mod;
            trect.dx = mod;
            trect.dy = mod;

            draw_terrain_trans_bl(&trect,&troot2,lhfield+hfoff,sptr+spoff,dlevel,lflags);

            troot2.x = troot2.x + (wvec.i * float(mod));
            troot2.y = troot2.y + (wvec.j * float(mod));
            troot2.z = troot2.z + (wvec.k * float(mod));

            hfoff+=mod;
            spoff+=(mod >> surfshift);
        }
        int count = wrect.dx >> dlevel;

        draw_terrain_trans_bottom(&wrect,&troot2,lhfield+hfoff,sptr+spoff,
                                  dlevel,count,lflags);
    }
    if (lflags & ESCH_TERNEX_SMOOTH_LEFT)
    {
        VngoRect    wrect = *rect;
        EschPoint troot2 = root_point;
        int hfoff = 0;
        int spoff = 0;
        int count_mod=0;

        if (lflags & ESCH_TERNEX_SMOOTH_TOP)
        {
            troot2.x += (dvec.i * float (mod));
            troot2.y += (dvec.j * float (mod));
            troot2.z += (dvec.k * float (mod));
            wrect.y += mod;
            wrect.dy -= mod;
            hfoff += ((width << 1) << dlevel);
            spoff += (((width << 1) << dlevel) >> surfshift);
        }
        if (lflags & ESCH_TERNEX_SMOOTH_BOTTOM)
        {
            wrect.dy -= mod;
        }
        int count = wrect.dy >> dlevel;

        draw_terrain_trans_left(&wrect,&troot2,lhfield+hfoff,
                                sptr+spoff,dlevel,count,lflags);
    }
    if (lflags & ESCH_TERNEX_SMOOTH_RIGHT)
    {
        VngoRect    wrect = *rect;
        wrect.x = wrect.x + wrect.dx - mod;
        wrect.dx = mod;
        EschPoint troot2 = root_point;
        int hfoff = rect->dx - mod;
        int spoff = hfoff >> surfshift;
        troot2.x += wvec.i * float(rect->dx - mod);
        troot2.y += wvec.j * float(rect->dx - mod);
        troot2.z += wvec.k * float(rect->dx - mod);
        int count_mod=0;

        if (lflags & ESCH_TERNEX_SMOOTH_TOP)
        {
            troot2.x += (dvec.i * float (mod));
            troot2.y += (dvec.j * float (mod));
            troot2.z += (dvec.k * float (mod));
            wrect.y += mod;
            wrect.dy -= mod;
            hfoff += ((width << 1) << dlevel);
            spoff += (((width << 1) << dlevel) >> surfshift);
        }
        if (lflags & ESCH_TERNEX_SMOOTH_BOTTOM)
        {
            wrect.dy -= mod;
        }

        int count = wrect.dy >> dlevel;

        draw_terrain_trans_right(&wrect,&troot2,lhfield+hfoff,
                                 sptr+spoff,dlevel,count,lflags);
    }
#endif
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - esch_find_draw_volume                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrainEx::esch_find_draw_volume()
{
    VngoPoint   pt1,pt2;
    EschPoint   pos;
    EschPoint   tpt;
    EschCamera  *cam;
    float       tx, ty, tz;
    VngoPoint   vpt[6];

    cam=EschCurrent->camera;

    //
    // Get and draw the camera position in blue.
    //
    cam->get_position(&pos);

    //
    // Get and draw the viewing frustrum.
    //

    float modifier = float(1<< (scaleshift + 2)); // this help enlarge area slightly.
    EschVector  cvect= -cam->eye.dir;
    cvect *=modifier;


    vpt[0].x = (long(pos.x + cvect.i) >> scaleshift) + (width>>1);
    vpt[0].y = (long(pos.z + cvect.k) >> scaleshift) + (width>>1);

    // Calc the 4 corners.
    tz = cam->yon + modifier;

    if (cam->flags & ESCH_CAM_ORTHO)
    {
        tx = cam->xsize;
        ty = cam->ysize;
    }
    else
    {
        tx = tz * cam->xsize;
        ty = tz * cam->ysize;
    }

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
        || (lx >= width)
        || (lz < 0)
        || (lz >= depth))
        return 0;

    const byte *ptr = &hfield[( lz * width ) + lx];

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
// EschTerrainEx - get_face                                                 ³
//                                                                          ³
// Return the three points of the triangle under the point <x,z>.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bool EschTerrainEx::get_face (float x, float z, EschPoint *p1, EschPoint *p2, EschPoint *p3) const
{
    float _x = x - origin.x;
    float _z = z - origin.z;

    assertMyth("EschTerrainEx::get_face needs height-field information",
               hfield && htable);

    assertMyth("EschTerrainEx::get_face needs positive scales",
               scale > 0);

    int     lx = (int)_x >> scaleshift;
    int     lz = (int)_z >> scaleshift;

    float   wx = float(lx << scaleshift);
    float   wz = float(lz << scaleshift);

    x = _x - wx;
    z = _z - wz;

//ÄÄÄÄ Check that point is on map
    if ((lx < 0)
        || (lx >= width)
        || (lz < 0)
        || (lz >= depth))
        return 0;

    const byte *ptr = &hfield[lz * width + lx];

//ÄÄÄÄ Compute the points

    const float one = float (1 << scaleshift);
    if (x < z)
    {
        p1->x = wx;
        p1->y = htable[*ptr];
        p1->z = wz;

        p2->x = wx;
        p2->y = htable[*(ptr+width)];
        p2->z = wz + one;

        p3->x = wx + one;
        p3->y = htable[*(ptr+width+1)];
        p3->z = wz + one;
    }
    else
    {
        p1->x = wx;
        p1->y = htable[*ptr];
        p1->z = wz;

        p2->x = wx + one;
        p2->y = htable[*(ptr+width+1)];
        p2->z = wz + one;

        p3->x = wx + one;
        p3->y = htable[*(ptr+1)];
        p3->z = wz;
    }
//ÄÄÄÄ Compute y
    return true;
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


void EschTerrainEx::point_average (EschPoint *mid, EschPoint *top, EschPoint *bottom)
{
    mid->x = (mid->x + ((top->x + bottom->x) / 2.0f)) / 2.0f;
    mid->y = (mid->y + ((top->y + bottom->y) / 2.0f)) / 2.0f;
    mid->z = (mid->z + ((top->z + bottom->z) / 2.0f)) / 2.0f;
}

//°±² End of module - esternex.cpp ²±°

