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
// Created by Chuck Walbourn
//
// esterran.hpp
//
// The EschTerrain class is a height-field polygonal terrain system which
// uses a 2D array of 8-bit height values to create a realistic "outdoor"
// terrain.  The terrain may have textures and be drawn with multiple
// levels of detail.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

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

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschTerrain - Height-field terrain drawable object.                      ³
//                                                                          ³
// Terrain is assumed to start at the origin and extends out along the XZ   ³
// plane, with heights in positive Y.                                       ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
class EschTerrain : public EschDrawable {
protected:

    int compute_area(Flx16 lox, Flx16 loz, Flx16 hix, Flx16 hiz,
                     int *sw, int *ew, int *sd, int *ed, int bits);

    int compute_shift_value(ulong x, ulong *shift);

    void compute_texture_uv(Flx16 &u_left, Flx16 &u_right,
                            Flx16 &v_top, Flx16 &v_bottom,
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

    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Protected data members                                               ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
    char            iname[ESCH_MAX_NAME];

public:
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Public data members                                                  ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
    ushort          width;                  // Width of height field
    ushort          depth;                  // Depth of height field
    ulong           surfratio;              // Surface ratio (height : surface)
    ulong           surfshift;              // Shift value for surf ratio
    Flx16           scale;                  // World space per unit in width/depth
    ulong           scaleshift;             // Shift value for scale
    Flx16           lodmedium;              // Eye distance for medium LOD
    Flx16           lodlow;                 // Eye distance for low LOD
    EschPoint       origin;                 // Origin of height field
    byte            *hfield;                // 2D array of heights
    Flx16           *htable;                // Array of world height values
    esch_surf_type  *surfinfo;              // 2D array of surface information
    IvoryHandle     hsurfnorml;             // 2D array of surface normals
    ulong           tmax;                   // Number of textures
    byte            *txtcolor;              // Array of colors to use for texture entries
    EschTexture     **txt;                  // Array of textures

    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Constructor/Destructors                                              ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
    EschTerrain(const char *fname=0, const char *tname=0);

    virtual ~EschTerrain();

    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Operations                                                           ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
    virtual void draw();
    virtual void animate();

    virtual void compute_shades(EschCamera *cam, EschLight *lgts);

    virtual void release();

    virtual Flx16 get_height(Flx16 x, Flx16 z) const;
    Flx16 get_height(const EschPoint *pt) const { return get_height(pt->x, pt->z);}

    virtual int check_LOS(EschPoint *pt1, EschPoint *pt2, int precision=-1) const;

    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Utility functions.                                                   ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
    void set_origin(const EschPoint *pt)
    {
        origin = *pt;
    }
    void set_origin(const Flx16 ix, const Flx16 iy, const Flx16 iz)
    {
        origin.x = ix;
        origin.y = iy;
        origin.z = iz;
    }

    void set_scale(const Flx16 i);

    void set_lod(const Flx16 lodm, const Flx16 lodl)
    {
        lodmedium = (lodm <= 0) ? 0 : lodm;
        lodlow = (lodl < lodmedium) ? lodmedium : lodl;
        flags |= ESCH_TRN_LOD;
    }

    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // I/O routines                                                         ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
    virtual esch_error_codes load(const char *fname, const char *tname=0, ushort *hclr=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *tname=0, ushort *hclr=0);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esterran.hpp ²±°

