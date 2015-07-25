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
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little, Chuck Walbourn, Keith Stauffer, and Paul Masters
//
// esterran.hpp
//
// The EschTerrain class is a height-field polygonal terrain system which
// uses a 2D array of 8-bit height values to create a realistic "outdoor"
// terrain.  The terrain may have textures and be drawn with multiple
// levels of detail.
//
// EschTerrainEx class extends this with a more complex level-of-detail
// drawing algorithm.
//
// EschTerrainTreeTop creates 'forest blocks' which sit above an instance
// of the EschTerrainEx class to fill large terrain-following drawables.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ESTERRAN_HPP
#define __ESTERRAN_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <portable.h>

#include "esmath.hpp"
#include "esdraw.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define TESTING_TERRAIN
#define ESCH_LOW_TERRAIN_X_PRIMARY  0x1
#define ESCH_LOW_TERRAIN_Z_PRIMARY  0x2
#define ESCH_MAX_LOD                8

#define ESCH_TREETEX_TREETOPS       1
#define ESCH_TREETEX_TREETRANS      2
#define ESCH_TREETEX_TREESOLID      3
#define ESCH_TREETEX_UNDERGROWTH    4
#define ESCH_TREETEX_TREEBACK       5

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct esch_surf_type
{
    ushort  flags;                          // Surface flags
    byte    shd;                            // Shade level
    byte    cind;                           // Color index
};

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - Height-field terrain drawable object.                      ³
//                                                                          ³
// Terrain is assumed to start at the origin and extends out along the XZ   ³
// plane, with heights in positive Y.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschTerrain : public EschDrawable
{
protected:

    int compute_area(float lox, float loz, float hix, float hiz,
                     int *sw, int *ew, int *sd, int *ed, int bits);

    int compute_shift_value(ulong x, ulong *shift);

    void compute_texture_uv(float &u_left, float &u_right,
                            float &v_top, float &v_bottom,
                            dword flags,
                            int w, int d,
                            ulong shift=0);

    void draw_block(int w, int d, int i, int j,
                    esch_surf_type *sptr, dword ctrlfl,
                    ulong shift=0);

    enum
    {
        BOTTOM          =0,
        TOP             =1,
        LEFTA           =2,
        LEFTB           =3,
        RIGHTA          =4,
        RIGHTB          =5,
        BOTTOM_CORNERS  =6,
        TOP_CORNERS     =7,
    };

    void draw_transitions(int w, int d, int i, int j,
                          esch_surf_type *sptr, dword ctrlfl,
                          int id,
                          ulong shift=0);

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Protected data members                                               ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    char            iname[ESCH_MAX_NAME];

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    ushort          width;                  // Width of height field
    ushort          depth;                  // Depth of height field
    ulong           surfratio;              // Surface ratio (height : surface)
    ulong           surfshift;              // Shift value for surf ratio
    float           scale;                  // World space per unit in width/depth
    ulong           scaleshift;             // Shift value for scale
    float           lodmedium;              // Eye distance for medium LOD
    float           lodlow;                 // Eye distance for low LOD
    EschPoint       origin;                 // Origin of height field
    byte            *hfield;                // 2D array of heights
    float           *htable;                // Array of world height values
    esch_surf_type  *surfinfo;              // 2D array of surface information
    IvoryHandle     hsurfnorml;             // 2D array of surface normals
    ulong           tmax;                   // Number of textures
    byte            *txtcolor;              // Array of colors to use for texture entries
    EschTexture     **txt;                  // Array of textures

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschTerrain(const char *fname=0, const char *tname=0, VngoPal *pal=0);

    virtual ~EschTerrain();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschTerrain &operator = (const EschTerrain &t);

    virtual void draw();
    virtual void animate();

    virtual void compute_shades(EschCamera *cam, EschLight *lgts,
                                float exagerate=1.0f);

    virtual void release();

    virtual float get_height(float x, float z) const;
    float get_height(const EschPoint *pt) const
    {
        return get_height(pt->x, pt->z);
    }

    virtual bool get_face (float x, float z, EschPoint *p1, EschPoint *p2, EschPoint *p3) const;
    bool get_face (const EschPoint *pt, EschPoint *p1, EschPoint *p2, EschPoint *p3) const
    {
        return get_face (pt->x, pt->z, p1, p2, p3);
    }

    virtual ushort get_surface_flags(float x, float z) const;
    ushort get_surface_flags(const EschPoint *pt) const
    {
        return get_surface_flags(pt->x, pt->z);
    }

    virtual dword get_surface_color(float x, float z) const;
    dword get_surface_color(const EschPoint *pt) const
    {
        return get_surface_color(pt->x, pt->z);
    }

    virtual int check_LOS(EschPoint *pt1, EschPoint *pt2,
                          int precision=-1,
                          float *dist=0, EschPoint *npos=0) const;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_origin(const EschPoint *pt)
    {
        origin = *pt;
    }
    void set_origin(const float ix, const float iy, const float iz)
    {
        origin.x = ix;
        origin.y = iy;
        origin.z = iz;
    }

    void set_scale(const float i);

    void set_lod(const float lodm, const float lodl)
    {
        lodmedium = (lodm <= 0) ? 0 : lodm;
        lodlow = (lodl < lodmedium) ? lodmedium : lodl;
        flags |= ESCH_TRN_LOD;
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // I/O routines                                                         ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual esch_error_codes load(const char *fname, const char *tname=0,
                                  ushort *hclr=0, VngoPal *pal=0,
                                  dword ctrlfl=ESCH_TRNLD_ALL);
    virtual esch_error_codes load(XFParseIFF *iff, const char *tname=0,
                                  ushort *hclr=0, VngoPal *pal=0,
                                  dword ctrlfl=ESCH_TRNLD_ALL);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainEx - Height-field terrain drawable object.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschTerrainEx : public EschTerrain
{
public:
    enum
    {
        ESCH_TERNEX_SMOOTH_NONE     = 0x0,
        ESCH_TERNEX_SMOOTH_TOP      = 0x1,
        ESCH_TERNEX_SMOOTH_BOTTOM   = 0x2,
        ESCH_TERNEX_SMOOTH_LEFT     = 0x4,
        ESCH_TERNEX_SMOOTH_RIGHT    = 0x8,
        ESCH_TERNEX_SMOOTH_ALL      = ESCH_TERNEX_SMOOTH_TOP
                                    | ESCH_TERNEX_SMOOTH_BOTTOM
                                    | ESCH_TERNEX_SMOOTH_LEFT
                                    | ESCH_TERNEX_SMOOTH_RIGHT,

        ESCH_TERNEX_CLIP            =0x10,
        ESCH_TERNEX_ALIGN           =0x20,
        ESCH_TERNEX_TEXTURE         =0x40,
        ESCH_TERNEX_PERSPECTIVE     =0x80,
        ESCH_TERNEX_SMOOTH          =0x100
    };

protected:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Protected data members                                               ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//    EschPoint   dvolume[10];
    long        *left_edge;
    long        *right_edge;
    long        edge_count;
    VngoRect    darea;
    int         ccol;   // colomn coord in array.
    int         crow;   // row coord in array.
    int         max_texture_lod;
    int         max_perspective_lod;
    int         max_smooth_lod;
    int         num_dlevels;
    int         start_dlevel;
    float       *dlevels;
    dword       view_dir;

    EschCamera  *cam;
    dword       cflags;
    EschPoint   pos;
    EschPoint   po;

    EschVector  wvec;
    EschVector  dvec;
    EschVector  hvec;

    void esch_find_draw_volume();
    VngoRect draw_terrain_rect(VngoRect *iclip, VngoRect *oclip,int dlevel,dword flags);
    void draw_terrain_rect(VngoRect *iclip, int dlevel, dword flags);
    void draw_terrain_trans_rect(VngoRect *iclip, int dlevel, dword flags);
    void draw_terrain_trans_ul (VngoRect *rect,EschPoint *orig, byte *dptr,
                                esch_surf_type *sptr, int dlevel, dword lflags);
    void draw_terrain_trans_ur (VngoRect *rect,EschPoint *orig, byte *dptr,
                                esch_surf_type *sptr, int dlevel, dword lflags);
    void draw_terrain_trans_bl (VngoRect *rect,EschPoint *orig, byte *dptr,
                                esch_surf_type *sptr, int dlevel, dword lflags);
    void draw_terrain_trans_br (VngoRect *rect,EschPoint *orig, byte *dptr,
                                esch_surf_type *sptr, int dlevel, dword lflags);
    void draw_terrain_trans_top (VngoRect *rect,EschPoint *orig, byte *dptr,
                                 esch_surf_type *sptr, int dlevel, ulong count, dword lflags);
    void draw_terrain_trans_bottom (VngoRect *rect,EschPoint *orig, byte *dptr,
                                    esch_surf_type *sptr, int dlevel, ulong count, dword lflags);
    void draw_terrain_trans_left (VngoRect *rect,EschPoint *orig, byte *dptr,
                                  esch_surf_type *sptr, int dlevel, ulong count, dword lflags);
    void draw_terrain_trans_right (VngoRect *rect,EschPoint *orig, byte *dptr,
                                   esch_surf_type *sptr, int dlevel, ulong count, dword lflags);
    void point_average (EschPoint *mid, EschPoint *top, EschPoint *bottom);
    void display_pixel_row(VngoPoint *vpt, int count, dword cflags);
    void setup_edge_limits(VngoPoint *edge);
    void add_edge_to_limits(VngoPoint *p1,VngoPoint *p2);

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschTerrainEx (const char *fname=0, const char *tname=0, VngoPal *pal=0);
    EschTerrainEx (const EschTerrainEx &_t);
    virtual ~EschTerrainEx();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void draw();
    virtual void release();
    virtual float get_height(float x, float z) const;
    virtual bool  get_face (float x, float z, EschPoint *p1, EschPoint *p2, EschPoint *p3) const;

    virtual void set_lod (int count,...);
    virtual void set_texture_lod(int lod);
    virtual void set_perspective_lod(int lod);
    virtual void set_smooth_lod(int lod);
    virtual void set_start_lod(int lod);

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    int get_num_lod() const { return num_dlevels; }
    int get_texture_lod() const { return max_texture_lod; }
    int get_perspective_lod() const { return max_perspective_lod; }
    int get_smooth_lod() const { return max_smooth_lod; }
    int get_start_lod() const { return start_dlevel; }

    float *get_dlevels() const { return dlevels; }

    void hide_rect(VngoRect &hrect);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrainTreeTop - Terrain extension for trees.                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschTerrainTreeTop : public EschTerrainEx
{
public:
    enum
    {
        ESCH_TERNEX_SKIRT_NONE          = 0x0,
        ESCH_TERNEX_SKIRT_TOP           = 0x1,
        ESCH_TERNEX_SKIRT_BOTTOM        = 0x2,
        ESCH_TERNEX_SKIRT_LEFT          = 0x4,
        ESCH_TERNEX_SKIRT_RIGHT         = 0x8,
        ESCH_TERNEX_SKIRT_ALL           = ESCH_TERNEX_SKIRT_TOP
                                         | ESCH_TERNEX_SKIRT_BOTTOM
                                         | ESCH_TERNEX_SKIRT_LEFT
                                         | ESCH_TERNEX_SKIRT_RIGHT,
        ESCH_TERNEX_SLIP_ON             = 0x200,
        ESCH_TERNEX_SLIP_TOPLEFT        = 0x400,
        ESCH_TERNEX_SLIP_TOPRIGHT       = 0x800,
        ESCH_TERNEX_SLIP_BOTTOMLEFT     = 0x1000,
        ESCH_TERNEX_SLIP_BOTTOMRIGHT    = 0x2000,
        ESCH_TERNEX_SLIP_DRAWS_TOP      = 0x4000,
        ESCH_TERNEX_SLIP_DRAWS_BOTTOM   = 0x8000,
        ESCH_TERNEX_SLIP_DRAWS_LEFT     = 0x10000,
        ESCH_TERNEX_SLIP_DRAWS_RIGHT    = 0x20000,
        ESCH_TERNEX_ENDCAP_NONE         = 0x40000,
        ESCH_TERNEX_HORIZONTAL_TRANS    = 0x80000,
        ESCH_TERNEX_VERTICAL_TRANS      = 0x100000
    };

protected:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Protected data members                                               ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    VngoRect treerect;

    long    left;
    long    right;
    long    top;
    long    bottom;
    float   hgt;

    EschTerrainEx *terr;

    float   hgt_dither_mat[4][4];
    float   hgt_dither_scalar;

    int esch_find_draw_volume(EschVector *pts=0);
    VngoRect draw_tree_rect(VngoRect *iclip, VngoRect *oclip,int dlevel,dword flags);
    void draw_tree_rect(VngoRect *iclip, int dlevel, dword flags);
    int setup_edge_limits(VngoPoint *edge);

    VngoRect draw_tree_skirt(VngoRect *iclip, VngoRect *oclip,int dlevel,dword flags);
    void draw_tree_skirt(VngoRect *iclip, int dlevel, dword flags);

    void draw_slip_endcap (VngoRect *rect, dword type, int dlevel, dword lflags);

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    BOOL    TOP_FACING;
    BOOL    LEFT_FACING;
    BOOL    RIGHT_FACING;
    BOOL    BOTTOM_FACING;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschTerrainTreeTop(EschTerrainEx* terr, int _left, int _right,
                       int _top, int _bottom, float _hgt);
    virtual ~EschTerrainTreeTop();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void draw();
    virtual void release();
    virtual int check_LOS(EschPoint *pt1, EschPoint *pt2,
                          int precision=-1,
                          float *dist=0, EschPoint *npos=0) const;
    virtual float get_height(float x, float z) const;

    void update_lods();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    long get_left() const {return left;};
    long get_right() const {return right;};
    long get_top() const {return top;};
    long get_bottom() const {return bottom;};

    void get_exterior_rect (VngoRect *rect);
    void get_exterior_rect_world (float *x, float *z, float *dx, float *dz);
    void get_interior_rect (VngoRect *rect);
    void get_interior_rect_world (float *x, float *z, float *dx, float *dz);

    void set_hgt_dither_mat (float *mat) {if (mat) memcpy (hgt_dither_mat, mat, sizeof (hgt_dither_mat));};
    void set_hgt_dither_scalar (float scale) {hgt_dither_scalar = scale;};
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esterran.hpp ²±°

