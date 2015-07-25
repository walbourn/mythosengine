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
// Created by Keith Stauffer & Paul Masters
//
// estrtop.cpp
//
// The EschTerrainTreeTop class is a height-field polygonal terrain system
// which uses a 2D array of 8-bit height values to create a realistic
// "outdoor" tree canopy overtop of a terrain.  The terrain may have
// textures and be drawn with multiple levels of detail.  This class is a
// derivative of the EschTerrainEx class.
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

//#define TERRAIN_DEBUG_AID
// #define TERRAIN_NO_FRUSTRUM_WALK

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern char EschNoName[];

float TreeHgtRandomizationMatrix[4][4] =
{
   0.4f, 0.9f, 1.2f, 1.0f,
   1.0f, 0.5f, 0.9f, 0.6f,
   1.4f, 1.1f, 0.6f, 0.9f,
   1.0f, 0.7f, 1.3f, 0.5f
};

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EschTerrainTreeTop::EschTerrainTreeTop(EschTerrainEx* _terr, int _left, int _right,
                                       int _top, int _bottom, float _hgt) :
    EschTerrainEx(*_terr),
    hgt(_hgt)
{
    // initialize edge data;
    left_edge = 0;
    right_edge = 0;

    terr = _terr;

    // Adjust treetop box for actual terrain center point
    _top -= (int)terr->origin.z;
    _left -= (int)terr->origin.x;
    _right -= (int)terr->origin.x;
    _bottom -= (int)terr->origin.z;

    // Ensure +/- nature of points is correct
    if (_right > _left)
    {
        right = _right;
        left = _left;
    }
    else
    {
        left = _right;
        right = _left;
    }
    if (_top < _bottom)
    {
        top = _top;
        bottom = _bottom;
    }
    else
    {
        top = _bottom;
        bottom = _top;
    }

    // Adjust precision of points based on terrain grid sample rate
    top >>= scaleshift;
    left >>= scaleshift;
    right >>= scaleshift;
    bottom >>= scaleshift;

    // htable is a pointer assigned to terr->htable by the copy constructor
    // this allocates new memory for htable so it doesn't get freed twice
    float *t = new float[256];
    for(int i=0;i<255;i++)
    {
        t[i] = htable[i] + hgt;
    }
    htable = t;

    top = top & ~0xF;
    left = left & ~0xF;
    right = right & ~0xF;
    bottom = bottom & ~0xF;

    if (right == left)
    {
        right += 16;
    }

    if (bottom == top)
    {
        bottom += 16;
    }

    // Assign the rect directly
    treerect.x = left;
    treerect.y = top;
    treerect.dx = right - left;
    treerect.dy = bottom - top;

    // Turn off terrain underneath
    terr->hide_rect (treerect);

    // Arbitrarily set the number of textures...
    // This should be file based...
    tmax=5;

    memcpy (hgt_dither_mat, TreeHgtRandomizationMatrix, sizeof (hgt_dither_mat));
    hgt_dither_scalar = 10.0f;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EschTerrainTreeTop::~EschTerrainTreeTop()
{
    // TreeTops do not own their textures -- they point to them
    txt = 0;

    release();

    // Zero out "borrowed" pointers from EschTerrainEx
    dlevels = 0;
    cam = 0;

    // Zero out "borrowed" pointers from EschTerrain
    hfield = 0;
    surfinfo = 0;
    txtcolor = 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - release
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::release()
{
    if (htable)
    {
        delete [] htable;
        htable = 0;
    }
    if (left_edge)
    {
        delete [] left_edge;
        left_edge = 0;
    }
    if (right_edge)
    {
        delete [] right_edge;
        right_edge = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - draw
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::draw()
{
    assertMyth("EschLowTerrain::draw needs height-field information",
               hfield);

    assertMyth("EschLowTerrain::draw needs surface information",
               surfinfo);

    if (!hfield || !surfinfo)
        return;

    update_lods();

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschLowTerrain::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschLowTerrain::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    cflags = cam->flags;

//ÄÄÄ Calculate the affected polygon/rectangle.
    EschVector pts[6];
    int err = esch_find_draw_volume(&pts[0]);

//ÄÄÄ Compute orientation factors for terrain grid.  These are used
//ÄÄÄ during the transform of the height field into the camera's view.
    assertMyth("EschTerrain::draw needs positive scale factors",
               scale > 0.0f);

    // width, depth, height vectors
    wvec.i = scale;
    wvec.j = 0.0f;
    wvec.k = 0.0f;
    wvec.transform(&cam->eye.iorient);

    dvec.i = 0.0f;
    dvec.j = 0.0f;
    dvec.k = scale;
    dvec.transform(&cam->eye.iorient);

    hvec.i = 0.0f;
    hvec.j = 1.0f;
    hvec.k = 0.0f;
    hvec.transform(&cam->eye.iorient);

    // Compute position of grid origin
    origin.transform(&cam->eye.iorient,&po);

    // member vpt contains 4 points of the view frustrum.
    // building vectors based off of those 4 points and the camera pos
    // testing those 4 vectors against the planes of the tree skirts
    EschVector dummy;
    EschVector frustrum_edges[6];
    cam->eye.get_position(&dummy.i, &dummy.j, &dummy.k);
    LEFT_FACING = RIGHT_FACING = TOP_FACING = BOTTOM_FACING = FALSE;

    for (int i=1; i<5; i++)
    {
        frustrum_edges[i] = dummy - pts[i];
    }
    if (frustrum_edges[1].k < 0
        || frustrum_edges[2].k < 0
        || frustrum_edges[3].k < 0
        || frustrum_edges[4].k < 0)
    {
        TOP_FACING = TRUE;
    }
    if (frustrum_edges[1].k > 0
        || frustrum_edges[2].k > 0
        || frustrum_edges[3].k > 0
        || frustrum_edges[4].k > 0)
    {
        BOTTOM_FACING = TRUE;
    }
    if (frustrum_edges[1].i < 0
        || frustrum_edges[2].i < 0
        || frustrum_edges[3].i < 0
        || frustrum_edges[4].i < 0)
    {
        LEFT_FACING = TRUE;
    }
    if (frustrum_edges[1].i > 0
        || frustrum_edges[2].i > 0
        || frustrum_edges[3].i > 0
        || frustrum_edges[4].i > 0)
    {
        RIGHT_FACING = TRUE;
    }

    dword tflags = ESCH_TERNEX_SMOOTH_ALL | ESCH_TERNEX_CLIP
                   | ESCH_TERNEX_ALIGN | ESCH_TERNEX_TEXTURE
                   | ESCH_TERNEX_PERSPECTIVE | ESCH_TERNEX_SMOOTH;


    if (flags & ESCH_TRN_LOD)
    {
        VngoRect    clip[ESCH_MAX_LOD+1];
        VngoRect    *iclip = NULL;
        VngoRect    *oclip = NULL;
        VngoRect    temprect = treerect;
        int         i;
        int         lod[ESCH_MAX_LOD];

        // Check to see if the treerect is even visible
        if ((temprect.clip_to(darea) == VNGO_FULLY_CLIPPED) ||
            (temprect.x + temprect.dx == darea.x) || (temprect.y + temprect.dy == darea.y))
            return;

        long tstart_dlevel = start_dlevel;
        for (i=0;i < num_dlevels-1;i++)
        {
            lod[i] = (int)dlevels[i] >> scaleshift;
            clip[i].x = ccol - lod[i];
            clip[i].y = crow - lod[i];
            clip[i].dx = lod[i] << 1;
            clip[i].dy = lod[i] << 1;
            if (clip[i].clip_to(temprect)==VNGO_FULLY_CLIPPED)
                if (i+1 > start_dlevel)
                    tstart_dlevel = i+1;
        }
        clip[num_dlevels - 1] = darea;

        // Set iclip to the first detail level rect (should be 0 rect)
        iclip = &clip[tstart_dlevel];


        for (i = tstart_dlevel; i < num_dlevels; i++)
        {
            if (!(iclip->dx <=0 || iclip->dy <=0))
            {
                if (i > max_texture_lod)
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

                draw_tree_rect (iclip, oclip, i, tflags|ESCH_TERNEX_SLIP_ON);
                *iclip = draw_tree_rect(iclip, oclip, i, tflags);

            }
            oclip = iclip;
            iclip = &clip[i+1];

        }

        iclip = &clip[tstart_dlevel];
        oclip = NULL;
        for (i = tstart_dlevel; i < num_dlevels; i++)
        {
            if (!(iclip->dx <=0 || iclip->dy <=0))
            {
                if (i > max_texture_lod)
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
                draw_tree_skirt (iclip, oclip, i, tflags|ESCH_TERNEX_SLIP_ON);
                *iclip = draw_tree_skirt(iclip, oclip, i, tflags);
                if (!iclip)
                {
                    return;
                }
            }
            oclip = iclip;
            iclip = &clip[i+1];
        }
    }
    else
    {
        VngoRect temprect = treerect;

        if (start_dlevel > max_texture_lod)
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

        if ((temprect.clip_to(darea) != VNGO_FULLY_CLIPPED) &&
            (temprect.x + temprect.dx != darea.x) && (temprect.y + temprect.dy != darea.y))
        {
            draw_tree_rect (&darea, NULL, start_dlevel, tflags|ESCH_TERNEX_SLIP_ON);
            draw_tree_rect (&darea, NULL, start_dlevel,tflags);
            draw_tree_skirt (&darea, NULL, start_dlevel,tflags|ESCH_TERNEX_SLIP_ON);
            draw_tree_skirt (&darea, NULL, start_dlevel,tflags);
        }
    }

    cam = NULL;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - setup_edge_limits
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EschTerrainTreeTop::setup_edge_limits(VngoPoint *pts)
{
    if (edge_count != depth || !left_edge || !right_edge)
    {
        if (left_edge)
        {
            delete [] left_edge;
        }
        left_edge = new long [depth];
        if (!left_edge)
        {
            return 1;
        }
        if (right_edge)
        {
            delete [] right_edge;
        }
        right_edge = new long [depth];
        if (!right_edge)
        {
            return 1;
        }
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

#if TERRAIN_DEBUG_AID
    VngoColor24bit color(255,0,255);                //  draw frustrum
    cam->vport->clip_line(&pts[0],&pts[1],&color);
    cam->vport->clip_line(&pts[0],&pts[2],&color);
    cam->vport->clip_line(&pts[0],&pts[3],&color);
    cam->vport->clip_line(&pts[0],&pts[4],&color);

    cam->vport->clip_line(&pts[1],&pts[2],&color);
    cam->vport->clip_line(&pts[2],&pts[3],&color);
    cam->vport->clip_line(&pts[3],&pts[4],&color);
    cam->vport->clip_line(&pts[4],&pts[1],&color);
#endif
    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - draw_tree_rect
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoRect EschTerrainTreeTop::draw_tree_rect(VngoRect *iclip, VngoRect *oclip,
                                       int dlevel, dword flags)
{
    VngoRect work_rect = *iclip;

    // clip work_rect to treerect, giving us only the rectangle we need
    //  for this detail level
    work_rect.clip_to(treerect);

#if TERRAIN_DEBUG_AID
    if (EschTerrainTreeTop::flags & ESCH_TRN_DEBUG)
    {
        VngoPoint pts[4];
        VngoColor24bit color(255,255,255);

        pts[0].x = work_rect.x;
        pts[1].x = work_rect.x + work_rect.dx;
        pts[2].x = work_rect.x + work_rect.dx;
        pts[3].x = work_rect.x;

        pts[0].y = work_rect.y;
        pts[1].y = work_rect.y;
        pts[2].y = work_rect.y + work_rect.dy;
        pts[3].y = work_rect.y + work_rect.dy;

        pts[0].z = 0;
        pts[1].z = 0;
        pts[2].z = 0;
        pts[3].z = 0;

        cam->vport->clip_line(&pts[0],&pts[1],&color);
        cam->vport->clip_line(&pts[1],&pts[2],&color);
        cam->vport->clip_line(&pts[2],&pts[3],&color);
        cam->vport->clip_line(&pts[3],&pts[0],&color);
    }
#endif

    // Check to make sure work_rect is in draw area
    if ((work_rect.x > (darea.x + darea.dx)) ||
        ((work_rect.x + work_rect.dx) < darea.x) ||
        (work_rect.y > (darea.y + darea.dy)) ||
        ((work_rect.y + work_rect.dy) < darea.y))
        return (work_rect);

    // align the rect if necessary
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

    // special case when oclip is clipped to the tree block rectangle and it
    // returns a rectangle with 0 depth
    if ((oclip != NULL) && (oclip->y == treerect.y) && (oclip->dy == 0))
    {
        if (flags & ESCH_TERNEX_ALIGN)
        {
            // Put the rect on the correct boundaries.
            int tmask = ((1 << (dlevel+2)) - 1);
            int t = oclip->x - (oclip->x & ~(tmask));
            oclip->x = oclip->x - t;
            oclip->dx += t;
            oclip->dx += tmask;
            oclip->dx &= ~tmask;

            t = oclip->y - (oclip->y & ~(tmask));
            oclip->y = oclip->y - t;
            oclip->dy += t;
            oclip->dy += tmask;
            oclip->dy &= ~tmask;
        }
    }

    if (work_rect.dy <= 0 || work_rect.dx <= 0)
        return (work_rect);     // No terrain to draw in this rect.

    if (oclip == NULL)
    {
        draw_tree_rect (&work_rect,dlevel,flags);
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

            draw_tree_rect(&trect,dlevel,wflags);
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

            draw_tree_rect(&trect,dlevel,wflags);
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

            draw_tree_rect(&trect,dlevel,wflags);
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

            draw_tree_rect(&trect,dlevel,wflags);
        }
    }
    return (work_rect);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - draw_tree_skirt
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoRect EschTerrainTreeTop::draw_tree_skirt(VngoRect *iclip, VngoRect *oclip,
                                       int dlevel, dword flags)
{
    VngoRect work_rect = *iclip;

#if TERRAIN_DEBUG_AID
    if (EschTerrainTreeTop::flags & ESCH_TRN_DEBUG)
    {
        VngoPoint pts[4];
        VngoColor24bit color(0,0,0);
        if (dlevel == 1)
        {
            color.r = 128;
            color.g = 128;
            color.b = 128;
        }
        if (dlevel == 2)
        {
            color.r = 255;
            color.g = 255;
            color.b = 255;
        }

        pts[0].x = work_rect.x;
        pts[1].x = work_rect.x + work_rect.dx;
        pts[2].x = work_rect.x + work_rect.dx;
        pts[3].x = work_rect.x;

        pts[0].y = work_rect.y;
        pts[1].y = work_rect.y;
        pts[2].y = work_rect.y + work_rect.dy;
        pts[3].y = work_rect.y + work_rect.dy;

        pts[0].z = 0;
        pts[1].z = 0;
        pts[2].z = 0;
        pts[3].z = 0;

        cam->vport->clip_line(&pts[0],&pts[1],&color);
        cam->vport->clip_line(&pts[1],&pts[2],&color);
        cam->vport->clip_line(&pts[2],&pts[3],&color);
        cam->vport->clip_line(&pts[3],&pts[0],&color);

    }
#endif


    //  if the skirt flags are on, then turn them all OFF
    if (flags & ESCH_TERNEX_SLIP_ON)
    {
        flags &= ESCH_TERNEX_SKIRT_NONE;
        flags |= ESCH_TERNEX_SLIP_ON;
    }
    else
    {
        flags &= ESCH_TERNEX_SKIRT_NONE;
    }
    flags |= ESCH_TERNEX_ALIGN;

    if ((work_rect.x > (darea.x + darea.dx)) ||
        ((work_rect.x + work_rect.dx) < darea.x) ||
        (work_rect.y > (darea.y + darea.dy)) ||
        ((work_rect.y + work_rect.dy) < darea.y))
        return (work_rect);

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

    // special case when oclip is clipped to the tree block rectangle and it
    // returns a rectangle with 0 depth
    if ((oclip != NULL) && (oclip->y == treerect.y) && (oclip->dy == 0))
    {
        if (flags & ESCH_TERNEX_ALIGN)
        {
            // Put the rect on the correct boundaries.
            int tmask = ((1 << (dlevel+2)) - 1);
            int t = oclip->x - (oclip->x & ~(tmask));
            oclip->x = oclip->x - t;
            oclip->dx += t;
            oclip->dx += tmask;
            oclip->dx &= ~tmask;

            t = oclip->y - (oclip->y & ~(tmask));
            oclip->y = oclip->y - t;
            oclip->dy += t;
            oclip->dy += tmask;
            oclip->dy &= ~tmask;
        }
    }

    if (work_rect.dy <= 0 || work_rect.dx <= 0)
        return (work_rect);     // No terrain to draw in this rect.

    if (oclip == NULL)
    {

        if (work_rect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
        {
            // set flags for which sides of the rectangle to draw
            if ((work_rect.x == left) && (LEFT_FACING))
                flags |= ESCH_TERNEX_SKIRT_LEFT;
            if (((work_rect.x + work_rect.dx) == right) && (RIGHT_FACING))
                flags |= ESCH_TERNEX_SKIRT_RIGHT;
            if ((work_rect.y == top) && (TOP_FACING))
                flags |= ESCH_TERNEX_SKIRT_TOP;
            if (((work_rect.y + work_rect.dy) == bottom) && (BOTTOM_FACING))
                flags |= ESCH_TERNEX_SKIRT_BOTTOM;

            draw_tree_skirt (&work_rect,dlevel,flags);
            flags &= ESCH_TERNEX_SKIRT_NONE;
        }
    }
    else
    {
        VngoRect    trect;

        // camera is to the upper left of the tree block
        if ((work_rect.x + work_rect.dx > oclip->x + oclip->dx) &&
            (work_rect.y + work_rect.dy > oclip->y + oclip->dy))
        {
            dword   wflags = flags;

            trect.x = oclip->x + oclip->dx;                     // right rectangle
            trect.dx = work_rect.x + work_rect.dx - trect.x;
            trect.y = work_rect.y;
            trect.dy = work_rect.dy;

            if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
            {
                // set flags for which sides of the rectangle to draw
                if ((trect.x == left) && (LEFT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_LEFT;
                if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                if ((trect.y == top) && (TOP_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_TOP;
                if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                draw_tree_skirt (&trect,dlevel,wflags);
                wflags &= ESCH_TERNEX_SKIRT_NONE;                   // clear flags
            }


            trect.x = oclip->x;                                 // bottom rectangle
            trect.dx = oclip->dx;
            trect.y = oclip->y + oclip->dy;
            trect.dy = work_rect.y + work_rect.dy - trect.y;

            if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
            {
                // set flags for which sides of the rectangle to draw
                if ((trect.x == left) && (LEFT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_LEFT;
                if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                if ((trect.y == top) && (TOP_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_TOP;
                if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                draw_tree_skirt (&trect,dlevel,wflags);
                wflags &= ESCH_TERNEX_SKIRT_NONE;                   // clear flags
            }


        }

        // camera is to the upper right of the tree block
        if ((work_rect.x < oclip->x) &&
            (work_rect.y + work_rect.dy > oclip->y + oclip->dy))
        {
            dword wflags = flags;

            trect.x = work_rect.x;                              // left rectangle
            trect.dx = oclip->x - trect.x;
            trect.y = work_rect.y;
            trect.dy = work_rect.dy;

            if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
            {
                // set flags for which sides of the rectangle to draw
                if ((trect.x == left) && (LEFT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_LEFT;
                if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                if ((trect.y == top) && (TOP_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_TOP;
                if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                draw_tree_skirt (&trect,dlevel,wflags);
                wflags &= ESCH_TERNEX_SKIRT_NONE;                   // clear flags
            }


            trect.x = oclip->x;                                 // bottom rectangle
            trect.dx = oclip->dx;
            trect.y = oclip->y + oclip->dy;
            trect.dy = work_rect.y + work_rect.dy - trect.y;

            if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
            {
                // set flags for which sides of the rectangle to draw
                if ((trect.x == left) && (LEFT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_LEFT;
                if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                if ((trect.y == top) && (TOP_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_TOP;
                if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                draw_tree_skirt (&trect,dlevel,wflags);
                wflags &= ESCH_TERNEX_SKIRT_NONE;                   // clear flags
            }


        }

        // camera is to the lower right of the tree block
        if ((work_rect.y < oclip->y) && (work_rect.x < oclip->x))
        {
            dword wflags = flags;

            trect.x = work_rect.x;                              // left rectangle
            trect.dx = oclip->x - trect.x;
            trect.y = work_rect.y;
            trect.dy = work_rect.dy;

            if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
            {
                // set flags for which sides of the rectangle to draw
                if ((trect.x == left) && (LEFT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_LEFT;
                if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                if ((trect.y == top) && (TOP_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_TOP;
                if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                draw_tree_skirt (&trect,dlevel,wflags);
                wflags &= ESCH_TERNEX_SKIRT_NONE;                   // clear flags
            }

            trect.x = oclip->x;                                 // top rectangle
            trect.dx = oclip->dx;
            trect.y = work_rect.y;
            trect.dy = oclip->y - trect.y;

            if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
            {
                // set flags for which sides of the rectangle to draw
                if ((trect.x == left) && (LEFT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_LEFT;
                if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                if ((trect.y == top) && (TOP_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_TOP;
                if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                draw_tree_skirt (&trect,dlevel,wflags);
                wflags = ESCH_TERNEX_SKIRT_NONE;
            }


        }

        // camera is to the lower left of the tree block
        if ((work_rect.y < oclip->y) && (work_rect.x + work_rect.dx > oclip->x + oclip->dx))
        {
            dword   wflags = flags;

            trect.x = oclip->x + oclip->dx;                     // right rectangle
            trect.dx = work_rect.x + work_rect.dx - trect.x;
            trect.y = work_rect.y;
            trect.dy = work_rect.dy;

            if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
            {
                // set flags for which sides of the rectangle to draw
                if ((trect.x == left) && (LEFT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_LEFT;
                if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                if ((trect.y == top) && (TOP_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_TOP;
                if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                draw_tree_skirt (&trect,dlevel,wflags);
                wflags = ESCH_TERNEX_SKIRT_NONE;
            }

            trect.x = oclip->x;                             // top rectangle
            trect.dx = oclip->dx;
            trect.y = work_rect.y;
            trect.dy = oclip->y - trect.y;

            if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
            {
                // set flags for which sides of the rectangle to draw
                if ((trect.x == left) && (LEFT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_LEFT;
                if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                if ((trect.y == top) && (TOP_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_TOP;
                if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                    wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                draw_tree_skirt (&trect,dlevel,wflags);
                wflags = ESCH_TERNEX_SKIRT_NONE;
            }
        }

        // special case when dlevels are equal in depth because of alignment
        if (oclip->dy == work_rect.dy)
        {
            dword wflags = flags;



            if (work_rect.x + work_rect.dx > oclip->x + oclip->dx)
            {

                trect.x = oclip->x + oclip->dx;                     // right rectangle
                trect.dx = work_rect.x + work_rect.dx - trect.x;
                trect.y = work_rect.y;
                trect.dy = work_rect.dy;

                if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
                {
                    // set flags for which sides of the rectangle to draw
                    if ((trect.x == left) && (LEFT_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_LEFT;
                    if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                    if ((trect.y == top) && (TOP_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_TOP;
                    if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                    draw_tree_skirt (&trect,dlevel,wflags);
                    wflags &= ESCH_TERNEX_SKIRT_NONE;                   // clear flags
                }
            }
            if (work_rect.x < oclip->x)
            {
                trect.x = work_rect.x;
                trect.dx = oclip->x - trect.x;
                trect.y = work_rect.y;
                trect.dy = work_rect.dy;

                if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
                {
                    // set flags for which sides of the rectangle to draw
                    if ((trect.x == left) && (LEFT_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_LEFT;
                    if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                    if ((trect.y == top) && (TOP_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_TOP;
                    if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                    draw_tree_skirt (&trect,dlevel,wflags);
                    wflags &= ESCH_TERNEX_SKIRT_NONE;                   // clear flags
                }
            }
        }

        // special case when dlevels are equal in width because of alignment
        if (oclip->dx == work_rect.dx)
        {
            dword wflags = flags;

            if (work_rect.y + work_rect.dy > oclip->y + oclip->dy)
            {
                trect.x = oclip->x;                                 // bottom rectangle
                trect.dx = oclip->dx;
                trect.y = oclip->y + oclip->dy;
                trect.dy = work_rect.y + work_rect.dy - trect.y;

                if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
                {
                    // set flags for which sides of the rectangle to draw
                    if ((trect.x == left) && (LEFT_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_LEFT;
                    if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                    if ((trect.y == top) && (TOP_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_TOP;
                    if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                    draw_tree_skirt (&trect,dlevel,wflags);
                    wflags &= ESCH_TERNEX_SKIRT_NONE;                   // clear flags
                }
            }
            if (work_rect.y < oclip->y)
            {
                trect.x = oclip->x;                             // top rectangle
                trect.dx = oclip->dx;
                trect.y = work_rect.y;
                trect.dy = oclip->y - trect.y;

                if (trect.clip_to(treerect) != VNGO_FULLY_CLIPPED)
                {
                    // set flags for which sides of the rectangle to draw
                    if ((trect.x == left) && (LEFT_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_LEFT;
                    if (((trect.x + trect.dx) == right) && (RIGHT_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_RIGHT;
                    if ((trect.y == top) && (TOP_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_TOP;
                    if (((trect.y + trect.dy) == bottom) && (BOTTOM_FACING))
                        wflags |= ESCH_TERNEX_SKIRT_BOTTOM;

                    draw_tree_skirt (&trect,dlevel,wflags);
                    wflags &= ESCH_TERNEX_SKIRT_NONE;                   // clear flags
                }
            }
        }
    }
    return (work_rect);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - draw_tree_rect
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::draw_tree_rect (VngoRect *rect, int dlevel,dword lflags)
{
    ulong                   needed;
    int                     texture_shift;
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

    // Slip only works on detail level 0
    if (lflags & ESCH_TERNEX_SLIP_ON
        && dlevel)
        return;

    if (rect->x == left)
        lflags &= ~ESCH_TERNEX_SMOOTH_LEFT;

    if (rect->x + rect->dx == right)
        lflags &= ~ESCH_TERNEX_SMOOTH_RIGHT;

    if (rect->y == top)
        lflags &= ~ESCH_TERNEX_SMOOTH_TOP;

    if (rect->y + rect->dy == bottom)
        lflags &= ~ESCH_TERNEX_SMOOTH_BOTTOM;

#if TERRAIN_DEBUG_AID
    if (EschTerrainTreeTop::flags & ESCH_TRN_DEBUG)
    {
        VngoPoint pts[4];
        VngoColor24bit color(0,0,0);
        if (dlevel == 1)
        {
            color.r = 128;
            color.g = 128;
            color.b = 128;
        }
        if (dlevel == 2)
        {
            color.r = 255;
            color.g = 255;
            color.b = 255;
        }

        pts[0].x = rect->x;
        pts[1].x = rect->x + rect->dx;
        pts[2].x = rect->x + rect->dx;
        pts[3].x = rect->x;

        pts[0].y = rect->y;
        pts[1].y = rect->y;
        pts[2].y = rect->y + rect->dy;
        pts[3].y = rect->y + rect->dy;

        pts[0].z = 0;
        pts[1].z = 0;
        pts[2].z = 0;
        pts[3].z = 0;

        cam->vport->clip_line(&pts[0],&pts[1],&color);
        cam->vport->clip_line(&pts[1],&pts[2],&color);
        cam->vport->clip_line(&pts[2],&pts[3],&color);
        cam->vport->clip_line(&pts[3],&pts[0],&color);

    }
#endif

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

    static EschFace         face[4];

    if (dlevel > int(surfshift))
        texture_shift = dlevel - surfshift;
    else
        texture_shift = 0;


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



    leftx = rect->x;
    curz = rect->y;
    curx = leftx;
    cstep = 2 << dlevel;
    step = 1 << dlevel;

    assertMyth("EschLowTerrain::draw_tree_rect needs an in-clip region",
                rect != NULL);
    assertMyth("EschLowTerrain::draw_tree_rect needs camera.",
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

    float temp_mult = float(1 << dlevel);
    _wvec.i = wvec.i * temp_mult;
    _wvec.j = wvec.j * temp_mult;
    _wvec.k = wvec.k * temp_mult;

    _dvec.i = dvec.i * temp_mult;
    _dvec.j = dvec.j * temp_mult;
    _dvec.k = dvec.k * temp_mult;

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

    //assert (rect->dx == (rect->dx & ~((4 << dlevel) - 1)));

    int endy = rect->dy >> dlevel;
    int endx = rect->dx >> dlevel;

    int tstep = (1 << dlevel);
    int i,j;

    VngoPoint   work_points[3];
    EschPoint   *cpt = (EschPoint*) &work_points[0];
    EschPoint   *cpt2 = (EschPoint*) &work_points[1];
    EschPoint   *rpt = (EschPoint*) &work_points[2];
    EschPoint   pd,pw;

    cpt->x = origin.x + (float)(rect->x << scaleshift);
    cpt->y = origin.y;
    cpt->z = origin.z + (float)(rect->y << scaleshift);

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
    VngoColor24bit  clr(0,255,0);
#if TERRAIN_DEBUG_AID
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
#endif

    for (i=0; i <= endx; i++)
    {   // Setup the first line A
        float h = htable[*ptr];
        if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
            h -= hgt;
        else if ((rect->x+(i<<dlevel) > left) && (rect->x+(i<<dlevel) < right) && (rect->y > top))
        {
//            if (!(j & 0x1))
            {
                h += (hgt_dither_mat[(rect->x+(i<<dlevel))&3][(rect->y)&3] * hgt_dither_scalar);
            }
        }
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

    rptr += (width << dlevel);
    rsptr += (width << dlevel) >> surfshift;
    ptr = rptr;
    sptr = rsptr;

    vA = &vpt[rowa];

    if (lflags & ESCH_TERNEX_SMOOTH_TOP)
    {
        esch_surf_type  *lsptr;
        lsptr = &rsptr[-((width >> surfshift) << dlevel)];

        for (i=0;i < endx-1;i+=2)
        {
            ((EschPoint *)&vA[i+1])->x = (((EschPoint *)&vA[i])->x + ((EschPoint *)&vA[i+2])->x)/2.0f;
            ((EschPoint *)&vA[i+1])->y = (((EschPoint *)&vA[i])->y + ((EschPoint *)&vA[i+2])->y)/2.0f;
            ((EschPoint *)&vA[i+1])->z = (((EschPoint *)&vA[i])->z + ((EschPoint *)&vA[i+2])->z)/2.0f;
            vA[i+1].shade = (vA[i].shade + vA[i+2].shade) >> 1;
            face[2].flags = fflags3;
            face[2].a = i;
            face[2].b = i+1;
            face[2].c = i+2;
#ifdef TERRAIN_DEBUG_AID
            if (!(flags & ESCH_TRN_DOTS))
            {
                esch_surf_type        *tlsptr;
                tlsptr = &lsptr[(i << dlevel) >> surfshift];
                dword tlflags = tlsptr->flags;
                esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
            }
#endif
        }
    }

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
            // AB
            float h = htable[*ptr];
            if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
                h -= hgt;
            else if ((rect->x+(j<<dlevel) > left) && (rect->x+(j<<dlevel) < right)
                     && (rect->y+(i<<dlevel) > top) && (rect->y+(i<<dlevel)+(1<<dlevel)-1 < bottom))
            {
                h += (hgt_dither_mat[(rect->x+(j<<dlevel))&3][(rect->y+(i<<dlevel))&3] * hgt_dither_scalar);
            }
            ((EschPoint *)vB)->x = cpt->x + (h * hvec.i);
            ((EschPoint *)vB)->y = cpt->y + (h * hvec.j);
            ((EschPoint *)vB)->z = cpt->z + (h * hvec.k);

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
                // BC
                h = htable[ptr[width << dlevel]];
                if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
                    h -= hgt;
                else if ((rect->x+(j<<dlevel) > left) && (rect->x+(j<<dlevel) < right)
                         && (rect->y+(i<<dlevel)+(1<<dlevel) < bottom))
                {
//                    if (!(j & 0x1))
                    {
                        h += (hgt_dither_mat[(rect->x+(j<<dlevel))&3][(rect->y+((i+1)<<dlevel))&3] * hgt_dither_scalar);
                    }
                }
                ((EschPoint *)vC)->x = cpt2->x + (h * hvec.i);
                ((EschPoint *)vC)->y = cpt2->y + (h * hvec.j);
                ((EschPoint *)vC)->z = cpt2->z + (h * hvec.k);

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
                ((EschPoint *)vB)->x = (((EschPoint *)vA)->x + ((EschPoint *)vC)->x) / 2.0f;
                ((EschPoint *)vB)->y = (((EschPoint *)vA)->y + ((EschPoint *)vC)->y) / 2.0f;
                ((EschPoint *)vB)->z = (((EschPoint *)vA)->z + ((EschPoint *)vC)->z) / 2.0f;
                vB->shade = (vA->shade + vC->shade) >> 1;
#ifdef TERRAIN_DEBUG_AID
                if (!(flags & ESCH_TRN_DOTS))
                {
                    face[2].flags = fflags3;
                    face[2].a = rowa;
                    face[2].b = rowb;
                    face[2].c = rowc;
                    esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                }
#endif
            }
            if (lflags & ESCH_TERNEX_SMOOTH_RIGHT)
            {
                ((EschPoint *)&vB[endx])->x = (((EschPoint *)&vA[endx])->x + ((EschPoint *)&vC[endx])->x) / 2.0f;
                ((EschPoint *)&vB[endx])->y = (((EschPoint *)&vA[endx])->y + ((EschPoint *)&vC[endx])->y) / 2.0f;
                ((EschPoint *)&vB[endx])->z = (((EschPoint *)&vA[endx])->z + ((EschPoint *)&vC[endx])->z) / 2.0f;
                vB[endx].shade = (vA[endx].shade + vC[endx].shade) >> 1;
#ifdef TERRAIN_DEBUG_AID
                if (!(flags & ESCH_TRN_DOTS))
                {
                    face[2].flags = fflags3;
                    face[2].a = rowa + dx - 1;
                    face[2].b = rowb + dx - 1;
                    face[2].c = rowc + dx - 1;
                    esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                }
#endif
            }
        }

        if ((i+1 == endy) && (lflags & ESCH_TERNEX_SMOOTH_BOTTOM))
        {
            for (int k=0;k < endx-1;k+=2)
            {
                ((EschPoint *)&vC[k+1])->x = (((EschPoint *)&vC[k])->x + ((EschPoint *)&vC[k+2])->x) ;
                ((EschPoint *)&vC[k+1])->y = (((EschPoint *)&vC[k])->y + ((EschPoint *)&vC[k+2])->y) ;
                ((EschPoint *)&vC[k+1])->z = (((EschPoint *)&vC[k])->z + ((EschPoint *)&vC[k+2])->z) ;
                vC[k+1].shade = (vC[k].shade + vC[k+2].shade) >> 1;
#ifdef TERRAIN_DEBUG_AID
                if (!(flags & ESCH_TRN_DOTS))
                {
                    face[2].flags = fflags3;
                    face[2].a = rowc + k;
                    face[2].b = rowc + k + 1;
                    face[2].c = rowc + k + 2;
                    esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                }
#endif
            }
        }
        else if (i == endy && (lflags & ESCH_TERNEX_SMOOTH_BOTTOM))
        {
            for (int k=0;k < endx-1;k+=2)
            {
                ((EschPoint *)&vB[k+1])->x = (((EschPoint *)&vB[k])->x + ((EschPoint *)&vB[k+2])->x) / 2.0f;
                ((EschPoint *)&vB[k+1])->y = (((EschPoint *)&vB[k])->y + ((EschPoint *)&vB[k+2])->y) / 2.0f;
                ((EschPoint *)&vB[k+1])->z = (((EschPoint *)&vB[k])->z + ((EschPoint *)&vB[k+2])->z) / 2.0f;
                vB[k+1].shade = (vB[k].shade + vB[k+2].shade) >> 1;
#ifdef TERRAIN_DEBUG_AID
                if (!(flags & ESCH_TRN_DOTS))
                {
                    face[2].flags = fflags3;
                    face[2].a = rowb + k;
                    face[2].b = rowb + k + 1;
                    face[2].c = rowb + k + 2;
                    esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                }
#endif
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
            display_pixel_row(vA,endx, 0);
            display_pixel_row(vB,endx, 0);
            if (i+1 <= endy)
                display_pixel_row(vC,endx, 0);
        }
        else
#endif
        {
            float       u_left,u_right,v_top,v_bottom;
            esch_surf_type      *lsptr;
            lsptr = &rsptr[-((width >> surfshift) << dlevel)];
            dword tlflags;
            curx = leftx;

            for (int k=0; k < endx; k++)
            {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                if ((((curx >= (left_edge[curz] - cstep)
                    || curx >= (left_edge[curz+step] - cstep))
                    && (curx <= (right_edge[curz] + cstep)
                    || curx <= (right_edge[curz+step] + cstep)))))
#endif
                {
                    if (!(lflags & ESCH_TERNEX_SLIP_ON)
                        || ((lflags & ESCH_TERNEX_SLIP_ON)
                            && ((TOP_FACING && i == 1)
                                || (LEFT_FACING && k == 0)
                                || (RIGHT_FACING && k == endx - 1))))
                    {
                        tlflags = lsptr->flags;
                        // draw the tri strip formed by rows a & b;
                        face[0].flags = fflags1;
                        face[1].flags = fflags2;

                        face[0].a = k;
                        face[0].b = k + rowb;
                        face[0].c = k + rowb + 1;

                        face[1].a = k;
                        face[1].b = k + rowb + 1;
                        face[1].c = k + 1;

                        if (lflags & ESCH_TERNEX_SLIP_ON)
                        {
                            face[0].txt = ESCH_TREETEX_UNDERGROWTH;
                            face[1].txt = ESCH_TREETEX_UNDERGROWTH;
                        }
                        else
                        {
                            face[0].txt = 1;
                            face[1].txt = 1;
                        }

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
                        face[1].u[0] = u_left;
                        face[1].v[0] = v_bottom;
                        face[1].u[1] = u_right;
                        face[1].v[1] = v_top;
                        face[1].u[2] = u_right;
                        face[1].v[2] = v_bottom;

                        if (!(lflags & ESCH_TERNEX_SLIP_ON)
                            && !dlevel
                            && ((TOP_FACING && i == 1)
                                || (LEFT_FACING && k == 0)
                                || (RIGHT_FACING && k == endx - 1)))
                        {
                            ctrlfl &= ~ESCH_CDF_BFCULL;
                        }
                        esch_clipdraw_face(0,ctrlfl);
                        esch_clipdraw_face(1,ctrlfl);
                        if (!(lflags & ESCH_TERNEX_SLIP_ON)
                            && !dlevel
                            && ((TOP_FACING && i == 1)
                                || (LEFT_FACING && k == 0)
                                || (RIGHT_FACING && k == endx - 1)))
                        {
                            ctrlfl |= ((cam->flags & ESCH_CAM_BACKCULL)
                                        ? ESCH_CDF_BFCULL
                                        : 0);
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
                    if ((((curx >= (left_edge[curz] - cstep)
                    || curx >= (left_edge[curz+step] - cstep))
                    && (curx <= (right_edge[curz] + cstep)
                    || curx <= (right_edge[curz+step] + cstep)))))
#endif
                    {
                        if (!(lflags & ESCH_TERNEX_SLIP_ON)
                            || ((lflags & ESCH_TERNEX_SLIP_ON)
                                && ((LEFT_FACING && k == 0)
                                    || (RIGHT_FACING && k == endx - 1))))
                        {
                            int t = (width >> surfshift) << dlevel;
                            tlflags = lsptr[t].flags;


                            // draw the tri strip formed by rows b & c;
                            face[0].flags = fflags1;
                            face[0].a = k + rowb;
                            face[0].b = k + rowc;
                            face[0].c = k + rowc + 1;

                            face[1].flags = fflags2;
                            face[1].a = k + rowb;
                            face[1].b = k + rowc + 1;
                            face[1].c = k + rowb + 1;


                            if (lflags & ESCH_TERNEX_SLIP_ON)
                            {
                                face[0].txt = ESCH_TREETEX_UNDERGROWTH;
                                face[1].txt = ESCH_TREETEX_UNDERGROWTH;
                            }
                            else
                            {
                                face[0].txt = 1;
                                face[1].txt = 1;
                            }

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
                            face[1].u[0] = u_left;
                            face[1].v[0] = v_bottom;
                            face[1].u[1] = u_right;
                            face[1].v[1] = v_top;
                            face[1].u[2] = u_right;
                            face[1].v[2] = v_bottom;
                            if (!(lflags & ESCH_TERNEX_SLIP_ON)
                                && !dlevel
                                && ((LEFT_FACING && k == 0)
                                    || (RIGHT_FACING && k == endx - 1)))
                            {
                                ctrlfl &= ~ESCH_CDF_BFCULL;
                            }
                            esch_clipdraw_face(0,ctrlfl);
                            esch_clipdraw_face(1,ctrlfl);
                            if (!(lflags & ESCH_TERNEX_SLIP_ON)
                                && !dlevel
                                && ((LEFT_FACING && k == 0)
                                    || (RIGHT_FACING && k == endx - 1)))
                            {
                                ctrlfl |= ((cam->flags & ESCH_CAM_BACKCULL)
                                            ? ESCH_CDF_BFCULL
                                            : 0);
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
                // CB
                float h = htable[*ptr];
                if (!dlevel &&lflags & ESCH_TERNEX_SLIP_ON)
                    h -= hgt;
                else if ((rect->x+(j<<dlevel) > left) && (rect->x+(j<<dlevel) < right)
                         && (rect->y+(i<<dlevel)+(1<<dlevel)-1 < bottom))
                {
//                    if (!(j & 0x1))
                    {
                        h += (hgt_dither_mat[(rect->x+(j<<dlevel))&3][(rect->y+(i<<dlevel))&3] * hgt_dither_scalar);
                    }
                }
                ((EschPoint *)vB)->x = cpt->x + (h * hvec.i);
                ((EschPoint *)vB)->y = cpt->y + (h * hvec.j);
                ((EschPoint *)vB)->z = cpt->z + (h * hvec.k);

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
                    // BA
                    h = htable[ptr[width << dlevel]];
                    if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
                        h -= hgt;
                    else if ((rect->x+(j<<dlevel) > left) && (rect->x+(j<<dlevel) < right)
                             && (rect->y+(i<<dlevel)+(1<<dlevel) < bottom))
                    {
//                        if (!(j & 0x1))
                        {
                            h += (hgt_dither_mat[(rect->x+(j<<dlevel))&3][(rect->y+((i+1)<<dlevel))&3] * hgt_dither_scalar);
                        }
                    }
                    ((EschPoint *)vA)->x = cpt2->x + (h * hvec.i);
                    ((EschPoint *)vA)->y = cpt2->y + (h * hvec.j);
                    ((EschPoint *)vA)->z = cpt2->z + (h * hvec.k);

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
                    ((EschPoint *)vB)->x = (((EschPoint *)vA)->x + ((EschPoint *)vC)->x) / 2.0f;
                    ((EschPoint *)vB)->y = (((EschPoint *)vA)->y + ((EschPoint *)vC)->y) / 2.0f;
                    ((EschPoint *)vB)->z = (((EschPoint *)vA)->z + ((EschPoint *)vC)->z) / 2.0f;
                    vB->shade = (vA->shade + vC->shade) >> 1;
#ifdef TERRAIN_DEBUG_AID
                    if (!(flags & ESCH_TRN_DOTS))
                    {
                        face[2].flags = fflags3;
                        face[2].a = rowa;
                        face[2].b = rowb;
                        face[2].c = rowc;
                        esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                    }
#endif
                }
                if (lflags & ESCH_TERNEX_SMOOTH_RIGHT)
                {
                    ((EschPoint *)&vB[endx])->x    = (((EschPoint *)&vA[endx])->x + ((EschPoint *)&vC[endx])->x) / 2.0f;
                    ((EschPoint *)&vB[endx])->y    = (((EschPoint *)&vA[endx])->y + ((EschPoint *)&vC[endx])->y) / 2.0f;
                    ((EschPoint *)&vB[endx])->z    = (((EschPoint *)&vA[endx])->z + ((EschPoint *)&vC[endx])->z) / 2.0f;
                    vB[endx].shade = (vA[endx].shade + vC[endx].shade) >> 1;
#ifdef TERRAIN_DEBUG_AID
                    if (!(flags & ESCH_TRN_DOTS))
                    {
                        face[2].flags = fflags3;
                        face[2].a = rowa + dx - 1;
                        face[2].b = rowb + dx - 1;
                        face[2].c = rowc + dx - 1;
                        esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                    }
#endif
                }
            }

            if (((i+1) == endy) && (lflags & ESCH_TERNEX_SMOOTH_BOTTOM))
            {
                for (int k=0;k < endx-1;k+=2)
                {
                    ((EschPoint *)&vA[k+1])->x = (((EschPoint *)&vA[k])->x + ((EschPoint *)&vA[k+2])->x) / 2.0f;
                    ((EschPoint *)&vA[k+1])->y = (((EschPoint *)&vA[k])->y + ((EschPoint *)&vA[k+2])->y) / 2.0f;
                    ((EschPoint *)&vA[k+1])->z = (((EschPoint *)&vA[k])->z + ((EschPoint *)&vA[k+2])->z) / 2.0f;
                    vA[k+1].shade = (vA[k].shade + vA[k+2].shade) >> 1;
#ifdef TERRAIN_DEBUG_AID
                    if (!(flags & ESCH_TRN_DOTS))
                    {
                        face[2].flags = fflags3;
                        face[2].a = rowa + k;
                        face[2].b = rowa + k + 1;
                        face[2].c = rowa + k + 2;
                        esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                    }
#endif
                }
            }
            else if (i == endy && (lflags & ESCH_TERNEX_SMOOTH_BOTTOM))
            {
                for (int k=0;k < endx-1;k+=2)
                {
                    ((EschPoint *)&vB[k+1])->x = (((EschPoint *)&vB[k])->x + ((EschPoint *)&vB[k+2])->x) / 2.0f;
                    ((EschPoint *)&vB[k+1])->y = (((EschPoint *)&vB[k])->y + ((EschPoint *)&vB[k+2])->y) / 2.0f;
                    ((EschPoint *)&vB[k+1])->z = (((EschPoint *)&vB[k])->z + ((EschPoint *)&vB[k+2])->z) / 2.0f;
                    vB[k+1].shade = (vB[k].shade + vB[k+2].shade) >> 1;

#ifdef TERRAIN_DEBUG_AID
                    if (!(flags & ESCH_TRN_DOTS))
                    {
                        face[2].flags = fflags3;
                        face[2].a = rowb + k;
                        face[2].b = rowb + k + 1;
                        face[2].c = rowb + k + 2;
                        esch_clipdraw_face(2,(ctrlfl & ~ESCH_CDF_BFCULL));
                    }
#endif
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
                display_pixel_row(vB,endx, 0);
        }
        else
#endif
        {
            float       u_left,u_right,v_top,v_bottom;
            esch_surf_type      *lsptr;
            lsptr = &rsptr[-((width >> surfshift) << dlevel)];
            dword tlflags;


            curx = leftx;
            for (int k=0; k < endx;k++)
            {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                if ((((curx >= (left_edge[curz] - cstep)
                    || curx >= (left_edge[curz+step] - cstep))
                    && (curx <= (right_edge[curz] + cstep)
                    || curx <= (right_edge[curz+step] + cstep)))))
        //            && ((curx >= left) && ((curx + cstep) <= right)
        //             && (curz >= top) && ((curz + step) <= bottom))))
#endif
                {
                    if (i <= endy)
                    {
                        if (!(lflags & ESCH_TERNEX_SLIP_ON)
                            || ((lflags & ESCH_TERNEX_SLIP_ON)
                                && ((LEFT_FACING && k == 0)
                                    || (RIGHT_FACING && k == endx - 1))))
                        {
                            tlflags = lsptr->flags;

                            // draw the tri strip formed by rows c & b;
                            face[0].flags = fflags1;
                            face[1].flags = fflags2;

                            face[0].a = k + rowc;
                            face[0].b = k + rowb;
                            face[0].c = k + rowb + 1;

                            face[1].a = k + rowc;
                            face[1].b = k + rowb + 1;
                            face[1].c = k + rowc + 1;

                            if (lflags & ESCH_TERNEX_SLIP_ON)
                            {
                                face[0].txt = ESCH_TREETEX_UNDERGROWTH;
                                face[1].txt = ESCH_TREETEX_UNDERGROWTH;
                            }
                            else
                            {
                                face[0].txt = 1;
                                face[1].txt = 1;
                            }

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
                            face[1].u[0] = u_left;
                            face[1].v[0] = v_bottom;
                            face[1].u[1] = u_right;
                            face[1].v[1] = v_top;
                            face[1].u[2] = u_right;
                            face[1].v[2] = v_bottom;

                            if (!(lflags & ESCH_TERNEX_SLIP_ON)
                                && !dlevel
                                && ((LEFT_FACING && k == 0)
                                    || (RIGHT_FACING && k == endx - 1)))
                            {
                                ctrlfl &= ~ESCH_CDF_BFCULL;
                            }
                            esch_clipdraw_face(0,ctrlfl);
                            esch_clipdraw_face(1,ctrlfl);
                            if (!(lflags & ESCH_TERNEX_SLIP_ON)
                                && !dlevel
                                && ((LEFT_FACING && k == 0)
                                    || (RIGHT_FACING && k == endx - 1)))
                            {
                                ctrlfl |= ((cam->flags & ESCH_CAM_BACKCULL)
                                            ? ESCH_CDF_BFCULL
                                            : 0);
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
                }
                if( i+1 <= endy)
                {
#ifndef TERRAIN_NO_FRUSTRUM_WALK
                    if ((((curx >= (left_edge[curz] - cstep)
                    || curx >= (left_edge[curz+step] - cstep))
                    && (curx <= (right_edge[curz] + cstep)
                    || curx <= (right_edge[curz+step] + cstep)))))
          //          && ((curx >= left) && ((curx + cstep) <= right)
          //           && (curz >= top) && ((curz + step) <= bottom))))
#endif
                    {
                        if (!(lflags & ESCH_TERNEX_SLIP_ON)
                            || ((lflags & ESCH_TERNEX_SLIP_ON)
                                && ((LEFT_FACING && k == 0)
                                    || (RIGHT_FACING && k == endx - 1)
                                    || (BOTTOM_FACING && (i+1) == endy))))
                        {
                            int t = (width >> surfshift) << dlevel;
                            tlflags = lsptr[t].flags;

                            // draw the tri strip formed by rows b & a;
                            face[0].flags = fflags1;
                            face[1].flags = fflags2;

                            face[0].a = k + rowb;
                            face[0].b = k + rowa;
                            face[0].c = k + rowa + 1;

                            face[1].a = k + rowb;
                            face[1].b = k + rowa + 1;
                            face[1].c = k + rowb + 1;

                            if (lflags & ESCH_TERNEX_SLIP_ON)
                            {
                                face[0].txt = ESCH_TREETEX_UNDERGROWTH;
                                face[1].txt = ESCH_TREETEX_UNDERGROWTH;
                            }
                            else
                            {
                                face[0].txt = 1;
                                face[1].txt = 1;
                            }

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
                            face[1].u[0] = u_left;
                            face[1].v[0] = v_bottom;
                            face[1].u[1] = u_right;
                            face[1].v[1] = v_top;
                            face[1].u[2] = u_right;
                            face[1].v[2] = v_bottom;

                            if (!(lflags & ESCH_TERNEX_SLIP_ON)
                                && !dlevel
                                && ((LEFT_FACING && k == 0)
                                    || (RIGHT_FACING && k == endx - 1)
                                    || (BOTTOM_FACING && (i+1) == endy)))
                            {
                                ctrlfl &= ~ESCH_CDF_BFCULL;
                            }
                            esch_clipdraw_face(0,ctrlfl);
                            esch_clipdraw_face(1,ctrlfl);
                            if (!(lflags & ESCH_TERNEX_SLIP_ON)
                                && !dlevel
                                && ((LEFT_FACING && k == 0)
                                    || (RIGHT_FACING && k == endx - 1)
                                    || (BOTTOM_FACING && (i+1) == endy)))
                            {
                                ctrlfl |= ((cam->flags & ESCH_CAM_BACKCULL)
                                            ? ESCH_CDF_BFCULL
                                            : 0);
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

        rpt->x += _dvec.i + _dvec.i;
        rpt->y += _dvec.j + _dvec.j;
        rpt->z += _dvec.k + _dvec.k;
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - draw_tree_skirt
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::draw_tree_skirt (VngoRect *rect, int dlevel, dword lflags)
{
    ulong                   needed;
    int                     texture_shift;
    int                     leftx,curx,curz;
    int                     step,cstep;
    VngoPoint               *vpt;
    EschVector              _wvec;
    EschVector              _dvec;
    EschVector              htreevec;

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

    VngoPoint pts[4];               //  sets color and points for displaying
                                    //  edge detection
    VngoColor24bit color(255,255,0);

    // Slip only works on detail level 0
    if (lflags & ESCH_TERNEX_SLIP_ON
        && dlevel)
        return;

    pts[0].x = rect->x;
    pts[1].x = rect->x + rect->dx;
    pts[2].x = rect->x + rect->dx;
    pts[3].x = rect->x;

    pts[0].y = rect->y;
    pts[1].y = rect->y;
    pts[2].y = rect->y + rect->dy;
    pts[3].y = rect->y + rect->dy;

    pts[0].z = 0;
    pts[1].z = 0;
    pts[2].z = 0;
    pts[3].z = 0;

#if TERRAIN_DEBUG_AID
    if (EschTerrainTreeTop::flags & ESCH_TRN_DEBUG)     // draws detail rectangles
    {
        VngoPoint pts[4];
        VngoColor24bit color(0,0,0);
        if (dlevel == 1)
        {
            color.r = 128;
            color.g = 128;
            color.b = 128;
        }
        if (dlevel == 2)
        {
            color.r = 255;
            color.g = 255;
            color.b = 255;
        }

        pts[0].x = rect->x;
        pts[1].x = rect->x + rect->dx;
        pts[2].x = rect->x + rect->dx;
        pts[3].x = rect->x;

        pts[0].y = rect->y;
        pts[1].y = rect->y;
        pts[2].y = rect->y + rect->dy;
        pts[3].y = rect->y + rect->dy;

        pts[0].z = 0;
        pts[1].z = 0;
        pts[2].z = 0;
        pts[3].z = 0;

        cam->vport->clip_line(&pts[0],&pts[1],&color);
        cam->vport->clip_line(&pts[1],&pts[2],&color);
        cam->vport->clip_line(&pts[2],&pts[3],&color);
        cam->vport->clip_line(&pts[3],&pts[0],&color);
    }
#endif

    dword ctrlfl = ESCH_CDF_CLIP;

    static EschFace         face[2];

    if (dlevel > int(surfshift))
        texture_shift = dlevel - surfshift;
    else
        texture_shift = 0;

    // Ensure that we are within draw area
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

    leftx = rect->x;
    curz = rect->y;
    curx = leftx;
    cstep = 2 << dlevel;
    step = 1 << dlevel;

    assertMyth("EschLowTerrain::draw_tree_rect needs an in-clip region",
                rect != NULL);
    assertMyth("EschLowTerrain::draw_tree_rect needs camera.",
                cam != NULL);

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

    int dx, dy;

    dx = (rect->dx >> dlevel) + 1;
    dy = (rect->dy >> dlevel) + 1;

    // Initialize all of the faces.
    int     rowa1 = 0;
    int     rowb1 = dx;
    int     rowa2 = dx+dx;
    int     rowb2 = rowa2+dx;
    int     cola1 = dx + dx + dx + dx;
    int     colb1 = cola1 + dy;
    int     cola2 = colb1 + dy;
    int     colb2 = cola2 + dy;

    // Setup the stepping vectors for the correct detail level.

    float temp_mult = float(1<<dlevel);
    _wvec.i = wvec.i * temp_mult;
    _wvec.j = wvec.j * temp_mult;
    _wvec.k = wvec.k * temp_mult;

    _dvec.i = dvec.i * temp_mult;
    _dvec.j = dvec.j * temp_mult;
    _dvec.k = dvec.k * temp_mult;

    htreevec = hvec * hgt;

    // Update workspace metrics; no other place is reasonable to do this
    needed = ((((sizeof(dword)+sizeof(VngoPoint)) * dx)
             + ((sizeof(dword)+sizeof(VngoPoint)) * dy)) * 2);

    assertMyth("EschLowTerrain::draw needs more workspace",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;

//ÄÄÄ Push drawing context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * ((dy + dx) * 4));
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[(dx + dy) * 4];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();

    int endy = rect->dy >> dlevel;
    int endx = rect->dx >> dlevel;
    int tstep = (1 << dlevel);
    int i,j;

    VngoPoint   work_points[3];
    EschPoint   *cpt = (EschPoint*) &work_points[0];

    long            t = (width * rect->y) + rect->x;
    byte            *ptr = hfield + t;
    byte            *rptr = ptr;
    long            st = ((width >> surfshift) * (rect->y >> surfshift)) + (rect->x >> surfshift);
    esch_surf_type  *sptr = surfinfo + st;
    esch_surf_type  *rsptr = sptr;
    long            pstep = 1 << dlevel;

    // If we are drawing the slip, offset the height and surf ptrs
    if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
    {
        ptr = hfield + (width * (rect->y + 1)) + (rect->x + 1);
        sptr = surfinfo + ((width >> surfshift) * ((rect->y + 1) >> surfshift))
                        + ((rect->x + 1) >> surfshift);
    }

    // The four corners of our rect are special cases for the slips
    if (lflags & ESCH_TERNEX_SLIP_ON)
    {
        // TOP/LEFT corner
        dword temp_type = ESCH_TERNEX_SLIP_TOPLEFT;
        if (lflags & ESCH_TERNEX_SKIRT_TOP)
        {
            temp_type |= ESCH_TERNEX_SLIP_DRAWS_BOTTOM
                         | ESCH_TERNEX_SLIP_DRAWS_LEFT;
            if (rect->x == left)
            {
                temp_type |= ESCH_TERNEX_VERTICAL_TRANS;
            }
            if (lflags & ESCH_TERNEX_SKIRT_LEFT)
            {
                temp_type |= ESCH_TERNEX_ENDCAP_NONE;
            }
        }
        else if (lflags & ESCH_TERNEX_SKIRT_LEFT)
        {
            temp_type |= ESCH_TERNEX_SLIP_DRAWS_RIGHT
                         | ESCH_TERNEX_SLIP_DRAWS_TOP;
            if (rect->y == top)
            {
                temp_type |= ESCH_TERNEX_HORIZONTAL_TRANS;
            }
        }
        draw_slip_endcap (rect, temp_type, dlevel, lflags);

        // TOP_RIGHT corner
        temp_type = ESCH_TERNEX_SLIP_TOPRIGHT;
        if (lflags & ESCH_TERNEX_SKIRT_TOP)
        {
            temp_type |= ESCH_TERNEX_SLIP_DRAWS_BOTTOM
                         | ESCH_TERNEX_SLIP_DRAWS_RIGHT;
            if (rect->x+rect->dx == right)
            {
                temp_type |= ESCH_TERNEX_VERTICAL_TRANS;
            }
            if (lflags & ESCH_TERNEX_SKIRT_RIGHT)
            {
                temp_type |= ESCH_TERNEX_ENDCAP_NONE;
            }
        }
        else if (lflags & ESCH_TERNEX_SKIRT_RIGHT)
        {
            temp_type |= ESCH_TERNEX_SLIP_DRAWS_LEFT
                         | ESCH_TERNEX_SLIP_DRAWS_TOP;
            if (rect->y == top)
            {
                temp_type |= ESCH_TERNEX_HORIZONTAL_TRANS;
            }
        }
        draw_slip_endcap (rect, temp_type, dlevel, lflags);

        // BOTTOM/LEFT corner
        temp_type = ESCH_TERNEX_SLIP_BOTTOMLEFT;
        if (lflags & ESCH_TERNEX_SKIRT_BOTTOM)
        {
            temp_type |= ESCH_TERNEX_SLIP_DRAWS_TOP
                         | ESCH_TERNEX_SLIP_DRAWS_LEFT;
            if (rect->x == left)
            {
                temp_type |= ESCH_TERNEX_VERTICAL_TRANS;
            }
            if (lflags & ESCH_TERNEX_SKIRT_LEFT)
            {
                temp_type |= ESCH_TERNEX_ENDCAP_NONE;
            }
        }
        else if (lflags & ESCH_TERNEX_SKIRT_LEFT)
        {
            temp_type |= ESCH_TERNEX_SLIP_DRAWS_RIGHT
                         | ESCH_TERNEX_SLIP_DRAWS_BOTTOM;
            if (rect->y+rect->dy == bottom)
            {
                temp_type |= ESCH_TERNEX_HORIZONTAL_TRANS;
            }
        }
        draw_slip_endcap (rect, temp_type, dlevel, lflags);

        // BOTTOM/RIGHT corner
        temp_type = ESCH_TERNEX_SLIP_BOTTOMRIGHT;
        if (lflags & ESCH_TERNEX_SKIRT_BOTTOM)
        {
            temp_type |= ESCH_TERNEX_SLIP_DRAWS_TOP
                         | ESCH_TERNEX_SLIP_DRAWS_RIGHT;
            if (rect->x+rect->dx == right)
            {
                temp_type |= ESCH_TERNEX_VERTICAL_TRANS;
            }
            if (lflags & ESCH_TERNEX_SKIRT_RIGHT)
            {
                temp_type |= ESCH_TERNEX_ENDCAP_NONE;
            }
        }
        else if (lflags & ESCH_TERNEX_SKIRT_RIGHT)
        {
            temp_type |= ESCH_TERNEX_SLIP_DRAWS_LEFT
                         | ESCH_TERNEX_SLIP_DRAWS_BOTTOM;
            if (rect->y+rect->dy == bottom)
            {
                temp_type |= ESCH_TERNEX_HORIZONTAL_TRANS;
            }
        }
        draw_slip_endcap (rect, temp_type, dlevel, lflags);
    }

    if (lflags & ESCH_TERNEX_SKIRT_TOP)
    {
#if TERRAIN_DEBUG_AID
        cam->vport->clip_line(&pts[0],&pts[1],&color);
#endif

        // compensate for SLIP
        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            cpt->x = origin.x + float((rect->x+1) << scaleshift);
            cpt->z = origin.z + float((rect->y+1) << scaleshift);
        }
        else
        {
            cpt->x = origin.x + float((rect->x << scaleshift));
            cpt->z = origin.z + float((rect->y << scaleshift));
        }
        cpt->y = origin.y;

        ::esch_transform(cpt,&cam->eye.iorient,cpt);

        VngoPoint   *vA = &vpt[rowa1];
        VngoPoint   *vB = &vpt[rowb1];

        int temp_len;
        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            temp_len = endx - 2;
        }
        else
        {
            temp_len = endx;
        }
        for (i=0; i <= temp_len; i++)
        {   // Setup the first line A
            float h = htable[*ptr];
            ((EschPoint *)vB)->x = cpt->x + ((h-(hgt+0.5f)) * hvec.i);
            ((EschPoint *)vB)->y = cpt->y + ((h-(hgt+0.5f)) * hvec.j);
            ((EschPoint *)vB)->z = cpt->z + ((h-(hgt+0.5f)) * hvec.k);

            if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
            {
                h += (hgt_dither_mat[(rect->x+i+1)&3][1] * hgt_dither_scalar);
            }
            ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
            ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
            ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

            if (sptr->flags & ESCH_SURF_CINDISTXT)
            {
                vA->clr = txtcolor[sptr->cind-1];
                vB->clr = txtcolor[sptr->cind-1];
            }
            else
            {
                vA->clr = sptr->cind;
                vB->clr = sptr->cind;
            }
            vA->shade = sptr->shd;
            vB->shade = sptr->shd;

            cpt->x = cpt->x + _wvec.i;
            cpt->y = cpt->y + _wvec.j;
            cpt->z = cpt->z + _wvec.k;

            vA++;
            vB++;
            ptr +=pstep;
            sptr += pstep >> surfshift;
        }


        face[0].flags = fflags1;
        face[1].flags = fflags1;

        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            temp_len = endx - 2;
        }
        else
        {
            temp_len = endx;
        }
        for (j=0; j < temp_len; j++)
        {

            face[0].a = rowb1 + j;
            face[0].b = rowa1 + j;
            face[0].c = rowa1 + j + 1;

            face[1].a = rowb1 + j;
            face[1].b = rowa1 + j + 1;
            face[1].c = rowb1 + j + 1;

            if (lflags & ESCH_TERNEX_SLIP_ON)
            {
                face[0].txt = ESCH_TREETEX_TREEBACK;
                face[1].txt = ESCH_TREETEX_TREEBACK;
            }
            else
            {
                face[0].txt = ESCH_TREETEX_TREETRANS + (!!dlevel);
                face[1].txt = ESCH_TREETEX_TREETRANS + (!!dlevel);
            }

            face[0].flags |= ESCH_FACE_TEXTURED;
            face[1].flags |= ESCH_FACE_TEXTURED;


            face[0].u[0] = 0.0f;
            face[0].v[0] = 1.0f;
            face[0].u[1] = 0.0f;
            face[0].v[1] = 0.0f;
            face[0].u[2] = float(1 << dlevel);
            face[0].v[2] = 0.0f;

            face[1].u[0] = 0.0f;
            face[1].v[0] = 1.0f;
            face[1].u[1] = float(1 << dlevel);
            face[1].v[1] = 0.0f;
            face[1].u[2] = float(1 << dlevel);
            face[1].v[2] = 1.0f;

            esch_clipdraw_face(0,ctrlfl);
            esch_clipdraw_face(1,ctrlfl);

        }
    }

    // If we are drawing the slip, offset the height ptr
    if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
    {
        ptr = hfield + (width * (rect->y + rect->dy - 1)) + (rect->x + 1);
        sptr = surfinfo + ((width >> surfshift) * ((rect->y + rect->dy - 1)>>surfshift))
                        + (rect->x >> surfshift);
    }
    else
    {
        ptr = hfield + t + (rect->dy * width);
        sptr = surfinfo + st + ((rect->dy * width) >> surfshift);
    }

    if (lflags & ESCH_TERNEX_SKIRT_BOTTOM)
    {
#if TERRAIN_DEBUG_AID
        cam->vport->clip_line(&pts[2],&pts[3],&color);
#endif
        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            cpt->x = origin.x + float((rect->x+1) << scaleshift);
            cpt->z = origin.z + float((rect->y+rect->dy-1) << scaleshift);
        }
        else
        {
            cpt->x = origin.x + float((rect->x << scaleshift));
            cpt->z = origin.z + float(((rect->y+rect->dy) << scaleshift));
        }
        cpt->y = origin.y;

        ::esch_transform(cpt,&cam->eye.iorient,cpt);

        VngoPoint   *vA = &vpt[rowa2];
        VngoPoint   *vB = &vpt[rowb2];

        int temp_len;
        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            temp_len = endx - 2;
        }
        else
        {
            temp_len = endx;
        }
        for (i=0; i <= temp_len; i++)
        {   // Setup the first line A
            float h = htable[*ptr];
            ((EschPoint *)vB)->x = cpt->x + ((h-(hgt+0.5f)) * hvec.i);
            ((EschPoint *)vB)->y = cpt->y + ((h-(hgt+0.5f)) * hvec.j);
            ((EschPoint *)vB)->z = cpt->z + ((h-(hgt+0.5f)) * hvec.k);
            if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
            {
                h += (hgt_dither_mat[(rect->x+i+1)&3][(rect->y+endy-1)&3] * hgt_dither_scalar);
            }
            ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
            ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
            ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

            if (sptr->flags & ESCH_SURF_CINDISTXT)
            {
                vA->clr = txtcolor[sptr->cind-1];
                vB->clr = txtcolor[sptr->cind-1];
            }
            else
            {
                vA->clr = sptr->cind;
                vB->clr = sptr->cind;
            }
            vA->shade = sptr->shd;
            vB->shade = sptr->shd;
            cpt->x += _wvec.i;
            cpt->y += _wvec.j;
            cpt->z += _wvec.k;
            vA++;
            vB++;
            ptr +=pstep;
            sptr += pstep >> surfshift;
        }


        face[0].flags = fflags1;
        face[1].flags = fflags1;

        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            temp_len = endx - 2;
        }
        else
        {
            temp_len = endx;
        }
        for (j=0; j < temp_len; j++)
        {

            face[0].a = rowb2 + j;
            face[0].b = rowa2 + j;
            face[0].c = rowa2 + j + 1;

            face[1].a = rowb2 + j;
            face[1].b = rowa2 + j + 1;
            face[1].c = rowb2 + j + 1;

            if (lflags & ESCH_TERNEX_SLIP_ON)
            {
                face[0].txt = ESCH_TREETEX_TREEBACK;
                face[1].txt = ESCH_TREETEX_TREEBACK;
            }
            else
            {
                face[0].txt = ESCH_TREETEX_TREETRANS + (!!dlevel);
                face[1].txt = ESCH_TREETEX_TREETRANS + (!!dlevel);
            }

            face[0].flags |= ESCH_FACE_TEXTURED;
            face[1].flags |= ESCH_FACE_TEXTURED;


            face[0].u[0] = 0.0f;
            face[0].v[0] = 1.0f;
            face[0].u[1] = 0.0f;
            face[0].v[1] = 0.0f;
            face[0].u[2] = float(1 << dlevel);
            face[0].v[2] = 0.0f;

            face[1].u[0] = 0.0f;
            face[1].v[0] = 1.0f;
            face[1].u[1] = float(1 << dlevel);
            face[1].v[1] = 0.0f;
            face[1].u[2] = float(1 << dlevel);
            face[1].v[2] = 1.0f;

            esch_clipdraw_face(0,ctrlfl);
            esch_clipdraw_face(1,ctrlfl);

        }
    }


    // If we are drawing the slip, offset the height and surf ptrs
    if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
    {
        ptr = hfield + (width * (rect->y + 1)) + (rect->x + 1);
        sptr = surfinfo + ((width >> surfshift) * ((rect->y + 1) >> surfshift))
                        + ((rect->x + 1) >> surfshift);
    }
    else
    {
        ptr = hfield + t;
        sptr = surfinfo + st;
    }

    if (lflags & ESCH_TERNEX_SKIRT_LEFT)
    {
#if TERRAIN_DEBUG_AID
        cam->vport->clip_line(&pts[3],&pts[0],&color);
#endif

        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            cpt->x = origin.x + float((rect->x+1) << scaleshift);
            cpt->z = origin.z + float((rect->y+1) << scaleshift);
        }
        else
        {
            cpt->x = origin.x + float((rect->x << scaleshift));
            cpt->z = origin.z + float((rect->y << scaleshift));
        }
        cpt->y = origin.y;

        ::esch_transform(cpt,&cam->eye.iorient,cpt);

        VngoPoint   *vA = &vpt[cola1];
        VngoPoint   *vB = &vpt[colb1];

        int temp_len;
        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            temp_len = endy - 2;
        }
        else
        {
            temp_len = endy;
        }
        for (i=0; i <= temp_len; i++)
        {   // Setup the first line A
            float h = htable[*ptr];
            ((EschPoint *)vB)->x = cpt->x + ((h-(hgt+0.5f)) * hvec.i);
            ((EschPoint *)vB)->y = cpt->y + ((h-(hgt+0.5f)) * hvec.j);
            ((EschPoint *)vB)->z = cpt->z + ((h-(hgt+0.5f)) * hvec.k);
            if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
            {
                h += (hgt_dither_mat[1][(rect->y+i+1)&3] * hgt_dither_scalar);
            }
            ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
            ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
            ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

            if (sptr->flags & ESCH_SURF_CINDISTXT)
            {
                vA->clr = txtcolor[sptr->cind-1];
                vB->clr = txtcolor[sptr->cind-1];
            }
            else
            {
                vA->clr = sptr->cind;
                vB->clr = sptr->cind;
            }
            vA->shade = sptr->shd;
            vB->shade = sptr->shd;
            cpt->x += _dvec.i;
            cpt->y += _dvec.j;
            cpt->z += _dvec.k;
            vA++;
            vB++;
            ptr += (pstep * width);
            sptr += ((pstep >> surfshift) * width);
        }
        face[0].flags = fflags1;
        face[1].flags = fflags1;

        for (j=0; j < temp_len; j++)
        {
            face[0].a = colb1 + j;
            face[0].b = cola1 + j;
            face[0].c = cola1 + j + 1;

            face[1].a = colb1 + j;
            face[1].b = cola1 + j + 1;
            face[1].c = colb1 + j + 1;

            if (lflags & ESCH_TERNEX_SLIP_ON)
            {
                face[0].txt = ESCH_TREETEX_TREEBACK;
                face[1].txt = ESCH_TREETEX_TREEBACK;
            }
            else
            {
                face[0].txt = ESCH_TREETEX_TREETRANS + (!!dlevel);
                face[1].txt = ESCH_TREETEX_TREETRANS + (!!dlevel);
            }

            face[0].flags |= ESCH_FACE_TEXTURED;
            face[1].flags |= ESCH_FACE_TEXTURED;


            face[0].u[0] = 0.0f;
            face[0].v[0] = 1.0f;
            face[0].u[1] = 0.0f;
            face[0].v[1] = 0.0f;
            face[0].u[2] = float(1 << dlevel);
            face[0].v[2] = 0.0f;

            face[1].u[0] = 0.0f;
            face[1].v[0] = 1.0f;
            face[1].u[1] = float(1 << dlevel);
            face[1].v[1] = 0.0f;
            face[1].u[2] = float(1 << dlevel);
            face[1].v[2] = 1.0f;

            esch_clipdraw_face(0,ctrlfl);
            esch_clipdraw_face(1,ctrlfl);
        }
    }

    // If we are drawing the slip, offset the height and surf ptrs
    if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
    {
        ptr = hfield + (width * (rect->y + 1)) + (rect->x + rect->dx - 1);
        sptr = surfinfo + ((width >> surfshift) * ((rect->y + 1) >> surfshift))
                        + ((rect->x + rect->dx-1) >> surfshift);
    }
    else
    {
        ptr = hfield + t + rect->dx;
        sptr = surfinfo + st + (rect->dx >> surfshift);
    }

    if (lflags & ESCH_TERNEX_SKIRT_RIGHT)
    {
#if TERRAIN_DEBUG_AID
        cam->vport->clip_line(&pts[1],&pts[2],&color);
#endif
        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            cpt->x = origin.x + float((rect->x + rect->dx - 1) << scaleshift);
            cpt->z = origin.z + float((rect->y+1) << scaleshift);
        }
        else
        {
            cpt->x = origin.x + float(((rect->x + rect->dx) << scaleshift));
            cpt->z = origin.z + float((rect->y << scaleshift));
        }
        cpt->y = origin.y;

        ::esch_transform(cpt,&cam->eye.iorient,cpt);

        VngoPoint   *vA = &vpt[cola2];
        VngoPoint   *vB = &vpt[colb2];

        int temp_len;
        if (lflags & ESCH_TERNEX_SLIP_ON)
        {
            temp_len = endy - 2;
        }
        else
        {
            temp_len = endy;
        }
        for (i=0; i <= temp_len; i++)
        {   // Setup the first line A
            float h = htable[*ptr];
            ((EschPoint *)vB)->x = cpt->x + ((h-(hgt+0.5f)) * hvec.i);
            ((EschPoint *)vB)->y = cpt->y + ((h-(hgt+0.5f)) * hvec.j);
            ((EschPoint *)vB)->z = cpt->z + ((h-(hgt+0.5f)) * hvec.k);
            if (!dlevel && lflags & ESCH_TERNEX_SLIP_ON)
            {
                h += (hgt_dither_mat[(rect->x+rect->dx-1)&3][(rect->y+i+1)&3] * hgt_dither_scalar);
            }
            ((EschPoint *)vA)->x = cpt->x + (h * hvec.i);
            ((EschPoint *)vA)->y = cpt->y + (h * hvec.j);
            ((EschPoint *)vA)->z = cpt->z + (h * hvec.k);

            if (sptr->flags & ESCH_SURF_CINDISTXT)
            {
                vA->clr = txtcolor[sptr->cind-1];
                vB->clr = txtcolor[sptr->cind-1];
            }
            else
            {
                vA->clr = sptr->cind;
                vB->clr = sptr->cind;
            }
            vA->shade = sptr->shd;
            vB->shade = sptr->shd;
            cpt->x += _dvec.i;
            cpt->y += _dvec.j;
            cpt->z += _dvec.k;
            vA++;
            vB++;
            ptr += (pstep * width);
            sptr += ((pstep >> surfshift) * width);
        }
        face[0].flags = fflags1;
        face[1].flags = fflags1;

        for (j=0; j < temp_len; j++)
        {
            face[0].a = colb2 + j;
            face[0].b = cola2 + j;
            face[0].c = cola2 + j + 1;

            face[1].a = colb2 + j;
            face[1].b = cola2 + j + 1;
            face[1].c = colb2 + j + 1;

            if (lflags & ESCH_TERNEX_SLIP_ON)
            {
                face[0].txt = ESCH_TREETEX_TREEBACK;
                face[1].txt = ESCH_TREETEX_TREEBACK;
            }
            else
            {
                face[0].txt = ESCH_TREETEX_TREETRANS + (!!dlevel);
                face[1].txt = ESCH_TREETEX_TREETRANS + (!!dlevel);
            }

            face[0].flags |= ESCH_FACE_TEXTURED;
            face[1].flags |= ESCH_FACE_TEXTURED;


            face[0].u[0] = 0.0f;
            face[0].v[0] = 1.0f;
            face[0].u[1] = 0.0f;
            face[0].v[1] = 0.0f;
            face[0].u[2] = float(1 << dlevel);
            face[0].v[2] = 0.0f;

            face[1].u[0] = 0.0f;
            face[1].v[0] = 1.0f;
            face[1].u[1] = float(1 << dlevel);
            face[1].v[1] = 0.0f;
            face[1].u[2] = float(1 << dlevel);
            face[1].v[2] = 1.0f;

            esch_clipdraw_face(0,ctrlfl);
            esch_clipdraw_face(1,ctrlfl);
        }

    }

//ÄÄÄ Pop drawing context
    ec.pop();

    return;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - esch_find_draw_volume
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EschTerrainTreeTop::esch_find_draw_volume(EschVector *pts)
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

    float modifier = (float)(1 << (scaleshift + 2)); // this help enlarge area slightly.
    EschVector  cvect= -cam->eye.dir;
    cvect *=modifier;

    vpt[0].x = (long(pos.x + cvect.i) >> scaleshift) + (width >> 1);
    vpt[0].y = (long(pos.z + cvect.k) >> scaleshift) + (width >> 1);

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
    int err = setup_edge_limits(vpt);
    if (err)
    {
        return err;
    }
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

    if (pts)
    {
        // pts should be pts[6], but we only care about the first 4
        for (int i=0; i<5; i++)
        {
            pts[i].i = origin.x + float(vpt[i].x<<scaleshift);
            pts[i].j = origin.y;
            pts[i].k = origin.z + float(vpt[i].y<<scaleshift);
        }
    }
    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - draw_slip_endcap
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::draw_slip_endcap (VngoRect *rect, dword type, int dlevel, dword lflags)
{
    if (type & ESCH_TERNEX_ENDCAP_NONE)
        return;

    // The detail level needs to be the next detail level out.
    dlevel ++;

    dword   *vflags;
    dword   fflags1 = ESCH_FACE_ALLOWPERSP
                    | ESCH_FACE_TEXTURED
                    | ESCH_FACE_SPECULAR
                    | ESCH_FACE_SMOOTH
                    | ESCH_FACE_FLAT
                    | ESCH_FACE_SOLID
                    | ESCH_FACE_WIRE
                    | ESCH_FACE_ABLINE
                    | ESCH_FACE_BCLINE
                    | ESCH_FACE_CALINE;

    VngoRect corner;
    dword ctrlfl = ESCH_CDF_CLIP;
    static EschFace face[8];
    VngoPoint *points;

    // Build a small rect based on TOPLEFT, TOPRIGHT, BOTTOMLEFT, BOTTOMRIGHT
    // Use the coordinates of that rect as the drawing points
    if (type & ESCH_TERNEX_SLIP_TOPLEFT)
    {
        corner.x = rect->x;
        corner.y = rect->y;
    }
    else if (type & ESCH_TERNEX_SLIP_TOPRIGHT)
    {
        corner.x = rect->x + rect->dx - 1;
        corner.y = rect->y;
    }
    else if (type & ESCH_TERNEX_SLIP_BOTTOMLEFT)
    {
        corner.x = rect->x;
        corner.y = rect->y + rect->dy - 1;
    }
    else if (type & ESCH_TERNEX_SLIP_BOTTOMRIGHT)
    {
        corner.x = rect->x + rect->dx - 1;
        corner.y = rect->y + rect->dy - 1;
    }
    corner.dx = 1;
    corner.dy = 1;

    if ((corner.x > (darea.x + darea.dx)) ||
        ((corner.x + corner.dx) < darea.x) ||
        (corner.y > (darea.y + darea.dy)) ||
        ((corner.y + corner.dy) < darea.y))
    {
        return;
    }

    int             dx, dy;
    long            t = width * corner.y + corner.x;
    byte            *ptr = hfield + t;
    long            st = ((width >> surfshift) * (corner.y >> surfshift)) + (corner.x >> surfshift);
    esch_surf_type  *sptr = surfinfo + st;

    dx = corner.dx + 1;
    dy = corner.dy + 1;


    // push a context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = 0;
    ec.fflags = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword)*((dx+dy)*2));
    ec.vpoints = points = new (EschSysInstance->wspace) VngoPoint[8];
    ec.faces = &face[0];
    ec.txts = txt;
    ec.push();

    // Set up 8 vertices
    // 0-3 are on the terrain
    // 4-7 are in the canopy
    EschPoint cpt;
    float h = htable[*(hfield + (width * corner.y + corner.x))];
    cpt.x = origin.x + float (corner.x << scaleshift);
    cpt.y = origin.y;
    cpt.z = origin.z + float (corner.y << scaleshift);
    ::esch_transform(&cpt,&cam->eye.iorient,&cpt);

    ((EschPoint *)&points[0])->x = cpt.x + ((h-(hgt+0.5f)) * hvec.i);
    ((EschPoint *)&points[0])->y = cpt.y + ((h-(hgt+0.5f)) * hvec.j);
    ((EschPoint *)&points[0])->z = cpt.z + ((h-(hgt+0.5f)) * hvec.k);

    if ((corner.x != left)
        && (corner.y != top))
    {
        if (type & ESCH_TERNEX_SLIP_TOPRIGHT)
        {
            // Smooth the TOP edge of the rect
            float _h;
            int temp_x, temp_y;

            temp_x = rect->x + rect->dx - 2;
            temp_y = rect->y;
            _h = (hgt_dither_mat[(temp_x)&3][(temp_y)&3] * hgt_dither_scalar);

            h += _h / 2.0f;
        }
        else if (type & ESCH_TERNEX_SLIP_BOTTOMLEFT)
        {
            // Smooth the LEFT edge of the rect
            float _h;
            int temp_x, temp_y;

            temp_x = rect->x;
            temp_y = rect->y + rect->dy - 2;
            _h = (hgt_dither_mat[(temp_x)&3][(temp_y)&3] * hgt_dither_scalar);

            h += _h / 2.0f;
        }
        else if (type & ESCH_TERNEX_SLIP_BOTTOMRIGHT)
        {
            h += (hgt_dither_mat[(rect->x+rect->dx-1)&3][(rect->y+rect->dy-1)&3] * hgt_dither_scalar);
        }
    }
    points[0].shade = sptr->shd;
    ((EschPoint *)&points[4])->x = cpt.x + (h * hvec.i);
    ((EschPoint *)&points[4])->y = cpt.y + (h * hvec.j);
    ((EschPoint *)&points[4])->z = cpt.z + (h * hvec.k);


    points[4].shade = sptr->shd;
    sptr ++;
    h = htable[*(hfield + (width * corner.y + (corner.x + 1)))];
    cpt.x = origin.x + float ((corner.x+corner.dx) << scaleshift);
    cpt.y = origin.y;
    cpt.z = origin.z + float (corner.y << scaleshift);
    ::esch_transform(&cpt,&cam->eye.iorient,&cpt);
    ((EschPoint *)&points[1])->x = cpt.x + ((h-(hgt+0.5f)) * hvec.i);
    ((EschPoint *)&points[1])->y = cpt.y + ((h-(hgt+0.5f)) * hvec.j);
    ((EschPoint *)&points[1])->z = cpt.z + ((h-(hgt+0.5f)) * hvec.k);
    points[1].shade = sptr->shd;
    if (((corner.x+1) != right)
        && (corner.y != top))
    {
        if (type & ESCH_TERNEX_SLIP_TOPLEFT)
        {
            float _h;
            int temp_x, temp_y;

            temp_x = rect->x + 2;
            temp_y = rect->y;
            _h = (hgt_dither_mat[(temp_x)&3][(temp_y)&3] * hgt_dither_scalar);

            h += _h / 2.0f;
        }
        else if (type & ESCH_TERNEX_SLIP_BOTTOMLEFT)
        {
            h += (hgt_dither_mat[(rect->x+1)&3][(rect->y+rect->dy-1)&3] * hgt_dither_scalar);
        }
        else if (type & ESCH_TERNEX_SLIP_BOTTOMRIGHT)
        {
            float _h;
            int temp_x, temp_y;

            temp_x = rect->x + rect->dx;
            temp_y = rect->y + rect->dy - 2;
            _h = (hgt_dither_mat[(temp_x)&3][(temp_y)&3] * hgt_dither_scalar);

            h += _h / 2.0f;
        }
    }
    ((EschPoint *)&points[5])->x = cpt.x + (h * hvec.i);
    ((EschPoint *)&points[5])->y = cpt.y + (h * hvec.j);
    ((EschPoint *)&points[5])->z = cpt.z + (h * hvec.k);
    points[5].shade = sptr->shd;

    sptr += ((width + 1) >> surfshift);

    h = htable[*(hfield + (width * (corner.y + 1) + (corner.x + 1)))];
    cpt.x = origin.x + float ((corner.x+corner.dx) << scaleshift);
    cpt.y = origin.y;
    cpt.z = origin.z + float ((corner.y+corner.dy) << scaleshift);
    ::esch_transform(&cpt,&cam->eye.iorient,&cpt);
    ((EschPoint *)&points[2])->x = cpt.x + ((h-(hgt+0.5f)) * hvec.i);
    ((EschPoint *)&points[2])->y = cpt.y + ((h-(hgt+0.5f)) * hvec.j);
    ((EschPoint *)&points[2])->z = cpt.z + ((h-(hgt+0.5f)) * hvec.k);
    points[2].shade = sptr->shd;
    if (((corner.x+1) != right)
        && ((corner.y+1) != bottom))
    {
        if (type & ESCH_TERNEX_SLIP_TOPLEFT)
        {
            h += (hgt_dither_mat[(rect->x+1)&3][(rect->y+1)&3] * hgt_dither_scalar);
        }
        else if (type & ESCH_TERNEX_SLIP_TOPRIGHT)
        {
            float _h;
            int temp_x, temp_y;

            temp_x = rect->x + rect->dx;
            temp_y = rect->y + 2;
            _h = (hgt_dither_mat[(temp_x)&3][(temp_y)&3] * hgt_dither_scalar);

            h += _h / 2.0f;
        }
        else if (type & ESCH_TERNEX_SLIP_BOTTOMLEFT)
        {
            float _h;
            int temp_x, temp_y;

            temp_x = rect->x + 2;
            temp_y = rect->y + rect->dy;
            _h = (hgt_dither_mat[(temp_x)&3][(temp_y)&3] * hgt_dither_scalar);

            h += (_h / 2.0f);
        }
    }
    ((EschPoint *)&points[6])->x = cpt.x + (h * hvec.i);
    ((EschPoint *)&points[6])->y = cpt.y + (h * hvec.j);
    ((EschPoint *)&points[6])->z = cpt.z + (h * hvec.k);
    points[6].shade = sptr->shd;

    sptr --;

    h = htable[*(hfield + (width * (corner.y + 1) + corner.x))];
    cpt.x = origin.x + float (corner.x << scaleshift);
    cpt.y = origin.y;
    cpt.z = origin.z + float ((corner.y+corner.dy) << scaleshift);
    ::esch_transform(&cpt,&cam->eye.iorient,&cpt);
    ((EschPoint *)&points[3])->x = cpt.x + ((h-(hgt+0.5f)) * hvec.i);
    ((EschPoint *)&points[3])->y = cpt.y + ((h-(hgt+0.5f)) * hvec.j);
    ((EschPoint *)&points[3])->z = cpt.z + ((h-(hgt+0.5f)) * hvec.k);
    points[3].shade = sptr->shd;
    if (((corner.x) != left)
        && ((corner.y+1) != bottom))
    {
        if (type & ESCH_TERNEX_SLIP_TOPLEFT)
        {
            float _h;
            int temp_x, temp_y;

            temp_x = rect->x;
            temp_y = rect->y + 2;
            _h = (hgt_dither_mat[(temp_x)&3][(temp_y)&3] * hgt_dither_scalar);

            h += (_h + 2.0f);
        }
        else if (type & ESCH_TERNEX_SLIP_TOPRIGHT)
        {
            h += (hgt_dither_mat[(rect->x+rect->dx-1)&3][(rect->y+1)&3] * hgt_dither_scalar);
        }
        else if (type & ESCH_TERNEX_SLIP_BOTTOMRIGHT)
        {
            float _h;
            int temp_x, temp_y;

            temp_x = rect->x + rect->dx - 2;
            temp_y = rect->y + rect->dy;
            _h = (hgt_dither_mat[(temp_x)&3][(temp_y)&3] * hgt_dither_scalar);

            h += (_h / 2.0f);
        }
    }
    ((EschPoint *)&points[7])->x = cpt.x + (h * hvec.i);
    ((EschPoint *)&points[7])->y = cpt.y + (h * hvec.j);
    ((EschPoint *)&points[7])->z = cpt.z + (h * hvec.k);
    points[7].shade = sptr->shd;

    // Set up 8 faces
    for (int i=0; i<8; i++)
    {
        face[i].flags = fflags1;
    }

    // 0 and 1 are top
    face[0].a = 4;
    face[0].b = 5;
    face[0].c = 0;
    face[1].a = 5;
    face[1].b = 1;
    face[1].c = 0;

    // 2 and 3 are bottom
    face[2].a = 7;
    face[2].b = 6;
    face[2].c = 3;
    face[3].a = 6;
    face[3].b = 2;
    face[3].c = 3;

    // 4 and 5 are left
    face[4].a = 4;
    face[4].b = 7;
    face[4].c = 0;
    face[5].a = 7;
    face[5].b = 3;
    face[5].c = 0;

    // 6 and 7 are right
    face[6].a = 5;
    face[6].b = 6;
    face[6].c = 1;
    face[7].a = 6;
    face[7].b = 2;
    face[7].c = 1;

    if (type & ESCH_TERNEX_HORIZONTAL_TRANS)
    {
        face[0].txt = ESCH_TREETEX_TREETRANS;
        face[1].txt = ESCH_TREETEX_TREETRANS;
        face[2].txt = ESCH_TREETEX_TREETRANS;
        face[3].txt = ESCH_TREETEX_TREETRANS;
    }
    else
    {
        face[0].txt = ESCH_TREETEX_TREEBACK;
        face[1].txt = ESCH_TREETEX_TREEBACK;
        face[2].txt = ESCH_TREETEX_TREEBACK;
        face[3].txt = ESCH_TREETEX_TREEBACK;
    }
    if (type & ESCH_TERNEX_VERTICAL_TRANS)
    {
        face[4].txt = ESCH_TREETEX_TREETRANS;
        face[5].txt = ESCH_TREETEX_TREETRANS;
        face[6].txt = ESCH_TREETEX_TREETRANS;
        face[7].txt = ESCH_TREETEX_TREETRANS;
    }
    else
    {
        face[4].txt = ESCH_TREETEX_TREEBACK;
        face[5].txt = ESCH_TREETEX_TREEBACK;
        face[6].txt = ESCH_TREETEX_TREEBACK;
        face[7].txt = ESCH_TREETEX_TREEBACK;
    }
    for (i=0; i<8; i+=2)
    {
        face[i].u[0] = 0;
        face[i].v[0] = 0;
        face[i].u[1] = 1;
        face[i].v[1] = 0;
        face[i].u[2] = 0;
        face[i].v[2] = 1;
        face[i+1].u[0] = 1;
        face[i+1].v[0] = 0;
        face[i+1].u[1] = 1;
        face[i+1].v[1] = 1;
        face[i+1].u[2] = 0;
        face[i+1].v[2] = 1;
    }

    // draw the faces
    if (type & ESCH_TERNEX_SLIP_DRAWS_TOP)
    {

        esch_clipdraw_face (0, ctrlfl);
        esch_clipdraw_face (1, ctrlfl);
    }
    if (type & ESCH_TERNEX_SLIP_DRAWS_BOTTOM)
    {
        esch_clipdraw_face (2, ctrlfl);
        esch_clipdraw_face (3, ctrlfl);
    }
    if (type & ESCH_TERNEX_SLIP_DRAWS_LEFT)
    {
        esch_clipdraw_face (4, ctrlfl);
        esch_clipdraw_face (5, ctrlfl);
    }
    if (type & ESCH_TERNEX_SLIP_DRAWS_RIGHT)
    {
        esch_clipdraw_face (6, ctrlfl);
        esch_clipdraw_face (7, ctrlfl);
    }

    // pop the context
    ec.pop();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - check_LOS
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EschTerrainTreeTop::check_LOS (EschPoint *pt1, EschPoint *pt2,
                           int precision,float *ndist) const
{
    // build a world rect from left/right, top/bottom
    VngoRect tree_world;
    tree_world.x = (left<<scaleshift) + long(origin.x);
    tree_world.y = (top<<scaleshift) + long(origin.z);
    tree_world.dx = (right<<scaleshift) - (left<<scaleshift);
    tree_world.dy = (bottom<<scaleshift) - (top<<scaleshift);

    VngoPoint tpt1, tpt2;
    tpt1.x = (long)pt1->x;
    tpt1.y = (long)pt1->z;
    tpt1.z = (long)pt1->y;
    tpt2.x = (long)pt2->x;
    tpt2.y = (long)pt2->z;
    tpt2.z = (long)pt2->y;

    VNGError clip_state = tree_world.clip_to (&tpt1, &tpt2, VNGO_CLIP_VERBOSE|VNGO_CLIP_Z);

    long temp_swap;
    temp_swap = tpt1.z;
    tpt1.z = tpt1.y;
    tpt1.y = temp_swap;

    temp_swap = tpt2.z;
    tpt2.z = tpt2.y;
    tpt2.y = temp_swap;

    // clip_to() will swap points to ensure movement from left to right...  need to swap back...
    if (pt1->x > pt2->x)
    {
        VngoPoint temp_pt;
        temp_pt = tpt1;
        tpt1 = tpt2;
        tpt2 = temp_pt;
    }

    if (clip_state == VNGO_FULLY_INSIDE)
    {
        // line is completely inside trees
        if (ndist)
            *ndist = 0;
        return 0;
    }
    else if (clip_state == VNGO_FULLY_CLIPPED)
    {
        // we don't hamper LOS, so return TRUE
        return 1;
    }

    // tpt1 and/or tpt2 is on the edge of the tree blocks
    // pt1 is the starting point
    // pt2 is the ending point
    // if tpt1 has changed, line is pt1 to tpt1
    // else, line is pt1 to tpt2

    float dist;
    long count;
    EschVector temp (float(tpt1.x - tpt2.x), float(tpt1.y-tpt2.y), float(tpt1.z-tpt2.z));
    dist = temp.magnitude();
    if (precision > 0)
    {
        count = (long)(dist / float(precision)) + 1;
    }
    else
    {
        count = (long)(dist / scale) + 1;
    }

    float xstep = (float)(tpt2.x - tpt1.x) / float(count);
    float ystep = (float)(tpt2.y - tpt1.y) / float(count);
    float zstep = (float)(tpt2.z - tpt1.z) / float(count);

    float curx = (float)tpt1.x;
    float cury = (float)tpt1.y;
    float curz = (float)tpt1.z;

    for (long i=0; i<count; i++)
    {
        float test_hgt = get_height(curx,curz);
        if (test_hgt >= cury)
        {
            if (ndist)
            {
                EschVector tvect(curx-pt1->x,test_hgt-pt1->y,curz-pt1->z);
                if (ndist)
                    *ndist = tvect.magnitude();
            }
            return 0;
        }
    }

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - get_height
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
float EschTerrainTreeTop::get_height(float x, float z) const
{
#if 0
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

    if (!((lx ^ lz) & 0x1)) // determine which triangle pattern to follow
    {                       // __
                            // |/  or /|
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
    }
    else
    {                       // |\
                            // ---
        c2 = scale;

        if ((x+z) > scale)
        {
            x0 = scale;
            y0 = htable[*(ptr+width+1)];
            z0 = scale;
            a1 = 0;
            a2 = -scale;
            b1 = htable[*(ptr+1)] - y0;
            b2 = htable[*(ptr+width)] - y0;
            c1 = -scale;
            c2 = 0;

            t1 = (z0 -z) / -c1;

            t2 = (x0 + (a1 * t1) - x) / -a2;
        }
        else
        {
            x0 = 0;
            y0 = htable[*ptr];
            z0 = 0;
            a1 = 0;
            a2 = scale;
            b1 = htable[*(ptr+width)] - y0;
            b2 = htable[*(ptr+1)] - y0;
            c1 = scale;
            c2 = 0;

            t1 = (z0 -z) / -c1;


            t2 = (x0 + (a1 * t1) - x) / -a2;
        }
    }

//ÄÄÄÄ Compute y
    y = y0 + (b1 * t1) + (b2 * t2);

    return (y + origin.y + hgt);

#else
    // Just like TerrainEX, but with dither patterns added in

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

    const byte *ptr = &hfield[lz * width + lx];

//ÄÄÄÄ Compute parameters t1 and t2, and assign b1/b2

    c2 = scale;
    if (x < z)
    {
        x0 = 0;
        y0 = htable[*ptr] + hgt_dither_mat[lx & 3][lz & 3] * hgt_dither_scalar;
        z0 = 0;
        a1 = 0;

        b1 = htable[*(ptr+width)] + hgt_dither_mat[lx & 3][(lz+1) & 3] * hgt_dither_scalar - y0;
        b2 = htable[*(ptr+width+1)] + hgt_dither_mat[(lx+1) & 3][(lz+1) & 3] * hgt_dither_scalar - y0;

        c1 = scale;
        a2 = scale;

        t2 = (x0 - x) / -a2;
        t1 = (z0 + (c2 * t2) - z) / -c1;
    }
    else
    {
        x0 = 0;
        y0 = htable[*ptr] + hgt_dither_mat[lx & 3][lz & 3] * hgt_dither_scalar;
        z0 = 0;
        a1 = scale;
        a2 = scale;

        b1 = htable[*(ptr+width+1)] + hgt_dither_mat[(lx+1) & 3][(lz+1) & 3] * hgt_dither_scalar - y0;
        b2 = htable[*(ptr+1)] + hgt_dither_mat[(lx+1) & 3][lz & 3] * hgt_dither_scalar - y0;

        c1 = scale;
        c2 = 0;

        t1 = (z0 -z) / -c1;
        t2 = (x0 + (a1 * t1) - x) / -a2;
    }

//ÄÄÄÄ Compute y
    y = y0 + (b1 * t1) + (b2 * t2);
    return (y + origin.y + hgt);

#endif
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - update_lods
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::update_lods()
{
    dlevels = terr->get_dlevels();
    num_dlevels = terr->get_num_lod();

    max_texture_lod = terr->get_texture_lod();
    max_perspective_lod = terr->get_perspective_lod();
    max_smooth_lod = terr->get_smooth_lod();
    start_dlevel = terr->get_start_lod();

    if (terr->flags & ESCH_TRN_LOD)
    {
        flags |= ESCH_TRN_LOD;
    }
    else
    {
        flags &= ~ESCH_TRN_LOD;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - get_exterior_rect
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::get_exterior_rect (VngoRect *rect)
{
    rect->x = left;
    rect->y = top;
    rect->dx = right - left;
    rect->dy = bottom - top;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - get_exterior_rect_world
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::get_exterior_rect_world (float *x, float *z, float *dx, float *dz)
{
    *x = float(left << terr->scaleshift);
    *z = float(top << terr->scaleshift);
    *dx = float((right-left) << terr->scaleshift);
    *dz = float((bottom-top) << terr->scaleshift);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - get_interior_rect
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::get_interior_rect (VngoRect *rect)
{
    rect->x = left + 1;
    rect->y = top + 1;
    rect->dx = (right-left) - 2;
    rect->dy = (bottom-top) - 2;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschTerrainTreeTop - get_interior_rect_world
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschTerrainTreeTop::get_interior_rect_world (float *x, float *z, float *dx, float *dz)
{
    *x = float((left + 1) << terr->scaleshift);
    *z = float((top + 1) << terr->scaleshift);
    *dx = float(((right-left) - 2) << terr->scaleshift);
    *dz = float(((bottom-top) - 2) << terr->scaleshift);
}

//°±² End of module - estrtop.cpp ²±°

