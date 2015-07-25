//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששש°°°°°°°°°°ש°°°°°°°°ששש°°°°°°°°שש°°°שששש°°°ש°°°°°°°°°°ש°°°°°°°°°שש
//ששששששששש°±°ששששששש°±°שששש°±°ש°±°שששש°±°ש°±°שששש°±°ש°±°שששששששש°±°שששש°±°שש
//שששששששש±°±ששששששש±°±שששששששש±°±שששששששש±°±שששש±°±ש±°±שששששששש±°±שששש±°±ששש
//ששששששש±²±±°±±²שש±²±±°±±²±±ש±²±שששששששש±²±±°±±²±±ש±²±±°±±²ששש±²±±°±±²°ששששש
//שששששש±²±שששששששששששששש±²±ש±²±שששששששש±²±שששש±²±ש±²±שששששששש±²±שששש±²±ששששש
//ששששש²±²ששששששש²±²שששש²±²ש²±²שששש²±²ש²±²שששש²±²ש²±²שששששששש²±²שששש²±²שששששש
//שששש²²²²²²²²²²ש²²²²²²²²ששש²²²²²²²²שש²²²שששש²²²ש²²²²²²²²²²ש²²²שששש²²²ששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששששCopyrightש(c)ש1994-1996שbyשCharybdisשEnterprises,שInc.שששששששששש
//ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ששששששששששששששששששששש Microsoft Windows '95 Version ששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
// Created by Tim Little
//
// esternex.hpp
//
// The EschTerrain class is a height-field polygonal terrain system which
// uses a 2D array of 8-bit height values to create a realistic "outdoor"
// terrain.  The terrain may have textures and be drawn with multiple
// levels of detail.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

#ifndef __ESTERNTREE_HPP
#define __ESTERNTREE_HPP    1

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

#include <stdarg.h>

#include <portable.h>
#include "esmath.hpp"
#include "esdraw.hpp"
#include "esterran.hpp"

#define TESTING_TERRAIN
#define ESCH_LOW_TERRAIN_X_PRIMARY  0x1
#define ESCH_LOW_TERRAIN_Z_PRIMARY  0x2
#define ESCH_MAX_LOD                8

#define ESCH_TREETEX_TREETOPS       1
#define ESCH_TREETEX_TREETRANS      2
#define ESCH_TREETEX_TREESOLID      3
#define ESCH_TREETEX_UNDERGROWTH    4

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschTerrainTreeTop - Height-field terrain drawable object.               ³
//                                                                          ³
// Terrain is assumed to start at the origin and extends out along the XZ   ³
// plane, with heights in positive Y.                                       ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
class EschTerrainTreeTop : public EschTerrainEx {
protected:

    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Protected data members                                               ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

    VngoRect treerect;

    long    left;
    long    right;
    long    top;
    long    bottom;
    float   hgt;

    EschTerrainEx *terr;

    int esch_find_draw_volume(EschVector *pts=0);
    VngoRect draw_tree_rect(VngoRect *iclip, VngoRect *oclip,int dlevel,dword flags);
    void draw_tree_rect(VngoRect *iclip, int dlevel, dword flags);
    int setup_edge_limits(VngoPoint *edge);

    VngoRect draw_tree_skirt(VngoRect *iclip, VngoRect *oclip,int dlevel,dword flags);
    void draw_tree_skirt(VngoRect *iclip, int dlevel, dword flags);

    void draw_slip_endcap (VngoRect *rect, dword type, int dlevel, dword lflags);
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


    BOOL    TOP_FACING;
    BOOL    LEFT_FACING;
    BOOL    RIGHT_FACING;
    BOOL    BOTTOM_FACING;

    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Operations                                                           ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

    // maybe a constructor.
    EschTerrainTreeTop(EschTerrainEx* terr, int _left, int _right,
                                           int _top, int _bottom, float _hgt);
    // and a destructor
    virtual ~EschTerrainTreeTop()
    {
        release();

        // Zero out "borrowed" pointers from EschTerrainEx
        dlevels = 0;
        cam = 0;

        // Zero out "borrowed" pointers from EschTerrain
        hfield = 0;
        surfinfo = 0;
        txtcolor = 0;
        txt = 0;
    }

    // Draw is the only thing to overload.
    virtual void draw();

    // Well...  Almost...
    virtual void release();

    void update_lods();
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esternex.hpp ²±°

