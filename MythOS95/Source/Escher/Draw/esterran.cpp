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
// esterran.cpp
//
// The EschTerrain class is a height-field polygonal terrain system which
// uses a 2D array of 8-bit height values to create a realistic "outdoor"
// terrain.  The terrain may have textures and be drawn with multiple
// levels of detail.
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

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define USE_LOW_LOD 0

#define FACE_FLAGS  ESCH_FACE_SPECULAR \
                    | ESCH_FACE_SMOOTH \
                    | ESCH_FACE_FLAT   \
                    | ESCH_FACE_SOLID  \
                    | ESCH_FACE_WIRE   \
                    | ESCH_FACE_ABLINE \
                    | ESCH_FACE_BCLINE \
                    | ESCH_FACE_CALINE

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern char EschNoName[];

static EschFace Face(FACE_FLAGS,
                     0,0,0, /* A, B, C */
                     0, /* Txt */
                     0,0,0,0,0,0, /* U, V */
                     0, /* color */
                     0,1,0 /* normal */);

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
EschTerrain::EschTerrain(const char *fname, const char *tname) :
    EschDrawable(ESCH_DRWT_TERRAIN),
    width(0),
    depth(0),
    surfratio(1),                       // 1:1 Height:Surface data ratio
    surfshift(0),
                                        // Assumes world unit is a meter
                                        // and DEM standard is being used
                                        // for data (30 meter per grid, with
                                        // each 8-bit value representing
                                        // 16 meters
    scale(32),
    scaleshift(5),
    lodmedium(0),
    lodlow(0),
    origin(0,0,0),
    hfield(0),
    htable(0),
    surfinfo(0),
    hsurfnorml(0),
    tmax(0),
    txtcolor(0),
    txt(0)
{
    dtyp = ESCH_DRWT_TERRAIN;

//ÄÄ Set initial values
    name=iname;
    strcpy(name,EschNoName);

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
// EschTerrain - operator =                                                 ³
//                                                                          ³
// Copies the data from another terrain.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
const EschTerrain &EschTerrain::operator = (const EschTerrain &t)
{
    if (this != &t)
    {
        release();

        EschDrawable::operator = (t);

        width = t.width;
        depth = t.depth;
        surfratio = t.surfratio;
        surfshift = t.surfshift;
        scale = t.scale;
        scaleshift = t.scaleshift;
        lodmedium = t.lodmedium;
        lodlow = t.lodlow;
        origin = t.origin;
        hfield = t.hfield;
        htable = t.htable;
        surfinfo = t.surfinfo;
        hsurfnorml = t.hsurfnorml;
        tmax = t.tmax;
        txtcolor = t.txtcolor;
        txt = t.txt;

        strncpy(iname,t.iname,ESCH_MAX_NAME);
    }
    return *this;
}


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
    assertMyth("EschTerrain:compute_area needs positive scale",
               scale.flx > 0);

    //ÄÄÄÄ Adjust to origin
    lox.flx = lox.flx - origin.x.flx;
    loz.flx = loz.flx - origin.z.flx;
    hix.flx = hix.flx - origin.x.flx;
    hiz.flx = hiz.flx - origin.z.flx;

    //ÄÄÄÄ Convert to index
    lox -= scale;
    loz -= scale;
    hix += scale;
    hiz += scale;

    // Width start
    if (lox.flx <= 0)  *sw = 0;
    else
    {
        *sw = (int)lox >> scaleshift;
        if (*sw >= width)
            *sw = width;
    }

    // Depth start
    if (loz.flx <= 0)  *sd = 0;
    else
    {
        *sd = (int)loz >> scaleshift;
        if (*sd >= depth)
            *sd = depth;
    }

    // Width end
    if (hix.flx <= 0)  *ew = 0;
    else
    {
        *ew = ((int)hix >> scaleshift) + 1;
        if (*ew > width)
            *ew = width;
        assert(*ew >= 0);
    }

    // Depth end
    if (hiz.flx <= 0)  *ed = 0;
    else
    {
        *ed = ((int)hiz >> scaleshift) + 1;
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
//                          °°° Protected °°°                               ³
// compute_shift_value                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschTerrain::compute_shift_value(ulong x, ulong *shift)
{
    ulong msk = 0x1;

    for(int i=0; i < 16; i++, msk <<= 1)
    {
        if (msk == x)
        {
            *shift = i;
            return 1;
        }
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                          °°° Protected °°°                               ³
// EschTerrain - compute_texture_uv                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::compute_texture_uv(Flx16 &u_left, Flx16 &u_right,
                                     Flx16 &v_top, Flx16 &v_bottom,
                                     dword flags,
                                     int w, int d,
                                     ulong shift)
{
    static Flx16 tile_lookup[8] = { 1,
                                    2,
                                    4,
                                    8,
                                    12,
                                    16,
                                    32,
                                    64
                                  };

    dword mask = (1 << surfshift) - 1;
    int doff = d & mask;
    int woff = w & mask;

    assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);
    Flx16 tile_factor = tile_lookup[(flags & (ESCH_SURF_TILE1 
                                              | ESCH_SURF_TILE2 
                                              | ESCH_SURF_TILE3)) >> 4];
    Flx16 rate(tile_factor.flx >> surfshift,1);
    Flx16 t((int)mask);

    if (flags & ESCH_SURF_FLIPU)
    {
        u_left = tile_factor - (Flx16(woff) * rate);
        u_right = (t - Flx16(woff)) * rate;
    }
    else
    {
        u_left = Flx16(woff) * rate;
        u_right = tile_factor - ((t - Flx16(woff)) * rate);
    }

    if (flags & ESCH_SURF_FLIPV)
    {
        v_top = tile_factor - ((t - Flx16(doff)) * rate);
        v_bottom = Flx16(doff) * rate;
    }
    else
    {             
        v_top = tile_factor - (Flx16(doff+1) * rate);
        v_bottom = tile_factor - (Flx16(doff) * rate);
    }
    if (shift)
    {
        u_left.flx <<= shift;
        u_right.flx <<= shift;
        v_top.flx <<= shift;
        v_bottom.flx <<= shift;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                          °°° Protected °°°                               ³
// EschTerrain - draw_block                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::draw_block(int w, int d, int i, int j,
                             esch_surf_type *sptr, dword ctrlfl,
                             ulong shift)
{
    dword test = (1 << (shift+1)) - 1;

//ÄÄÄ Get texturing parameters
    Flx16 u_left(0);
    Flx16 u_right(1);
    Flx16 v_top(0);
    Flx16 v_bottom(1);
    if (sptr->flags & ESCH_SURF_CINDISTXT
        && (!shift
            || !(sptr->flags & ESCH_SURF_NOTILE)))
    {
        compute_texture_uv(u_left, u_right,
                        v_top, v_bottom,
                        sptr->flags,
                        w, d, shift);
        Face.txt = sptr->cind;
        Face.flags = FACE_FLAGS
                    | ESCH_FACE_TEXTURED
                    | ((shift) ? 0 : ESCH_FACE_ALLOWPERSP);
    }

    assert(EschCurrent != 0);
    VngoPoint *vpt = EschCurrent->vpoints;

//ÄÄÄ Draw face 1
    if (w & test)
    {
        if (d & test)
        {
            Face.a = (word)(j-1);
            Face.b = (word)(i-1);
            Face.c = (word)i;

            Face.u[0] = u_left;
            Face.u[1] = u_left;  
            Face.u[2] = u_right;  

            Face.v[0] = v_bottom;
            Face.v[1] = v_top;
            Face.v[2] = v_top;
        }
        else
        {
            Face.a = (word)(i-1);
            Face.b = (word)j;
            Face.c = (word)(j-1);

            Face.u[0] = u_left;
            Face.u[1] = u_right;
            Face.u[2] = u_left;

            Face.v[0] = v_top;
            Face.v[1] = v_bottom;
            Face.v[2] = v_bottom;
        }
    }
    else
    {
        Face.a = (word)((d & test) ? j:i);
        Face.b = (word)(j-1);
        Face.c = (word)(i-1);

        Face.u[0] = u_right;  
        Face.u[1] = u_left;  
        Face.u[2] = u_left;  

        Face.v[0] = (d & test) ? v_bottom : v_top;
        Face.v[1] = v_bottom;
        Face.v[2] = v_top;
    }
    vpt[Face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                        ? txtcolor[sptr->cind-1] : sptr->cind;
    esch_clipdraw_face(0,ctrlfl);

//ÄÄÄ Draw face 2
    if (w & test)
    {
        Face.a = (word)((d & test) ? (j-1):(i-1));
        Face.b = (word)i;
        Face.c = (word)j;

        Face.u[0] = u_left;  
        Face.u[1] = u_right;  
        Face.u[2] = u_right;  

        Face.v[0] = (d & test) ? v_bottom : v_top;
        Face.v[1] = v_top;
        Face.v[2] = v_bottom;
    }
    else
    {
        if (d & test)
        {
            Face.a = (word)j;
            Face.b = (word)(i-1);
            Face.c = (word)i;

            Face.u[0] = u_right;  
            Face.u[1] = u_left;  
            Face.u[2] = u_right;  

            Face.v[0] = v_bottom;
            Face.v[1] = v_top;
            Face.v[2] = v_top;
        }
        else
        {
            Face.a = (word)i;
            Face.b = (word)j;
            Face.c = (word)(j-1);

            Face.u[0] = u_right;  
            Face.u[1] = u_right;  
            Face.u[2] = u_left;  

            Face.v[0] = v_top;
            Face.v[1] = v_bottom;
            Face.v[2] = v_bottom;
        }
    }
    vpt[Face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                        ? txtcolor[sptr->cind-1] : sptr->cind;
    esch_clipdraw_face(0,ctrlfl);

    Face.flags = FACE_FLAGS;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                          °°° Protected °°°                               ³
// EschTerrain - draw_transitions                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::draw_transitions(int w, int d, int i, int j,
                                   esch_surf_type *sptr, dword ctrlfl,
                                   int id,
                                   ulong shift)
{
    dword test = (1 << (shift+1)) - 1;

//ÄÄÄ Get texturing parameters
    Flx16 u_left(0);
    Flx16 u_half(0.5);
    Flx16 u_right(1);
    Flx16 v_top(0);
    Flx16 v_half(0.5);
    Flx16 v_bottom(1);

    if (sptr->flags & ESCH_SURF_CINDISTXT
        && (!shift
            || !(sptr->flags & ESCH_SURF_NOTILE)))
    {
        compute_texture_uv(u_left, u_right,
                           v_top, v_bottom,
                           sptr->flags,
                           w, d, shift);
        u_half.flx = (u_left.flx + u_right.flx) >> 1;
        v_half.flx = (v_top.flx + v_bottom.flx) >> 1;

        Face.txt = sptr->cind;
        Face.flags = FACE_FLAGS
                     | ESCH_FACE_TEXTURED
                     | ((shift) ? 0 : ESCH_FACE_ALLOWPERSP);
    }

    assert(EschCurrent != 0);
    VngoPoint *vpt = EschCurrent->vpoints;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw face 1
    switch (id)
    {
        case BOTTOM:
            Face.a = (word)(j-2);
            Face.b = (word)(i-2);
            Face.c = (word)(i-1);

            Face.u[0] = u_left;
            Face.u[1] = u_left;
            Face.u[2] = u_half;

            Face.v[0] = v_bottom;
            Face.v[1] = v_top;
            Face.v[2] = v_top;
            break;
        case TOP:
            Face.a = (word)(j-1);
            Face.b = (word)(i-1);
            Face.c = (word)j;

            Face.u[0] = u_left;
            Face.u[1] = u_left;
            Face.u[2] = u_half;

            Face.v[0] = v_bottom;
            Face.v[1] = v_top;
            Face.v[2] = v_bottom;
            break;
        case LEFTA:
            Face.a = (word)(j-1);
            Face.b = (word)i;
            Face.c = (word)j;

            Face.u[0] = u_left;
            Face.u[1] = u_right;
            Face.u[2] = u_right;

            Face.v[0] = v_bottom;
            Face.v[1] = v_half;
            Face.v[2] = v_bottom;
            break;
        case LEFTB:
            Face.a = (word)(j-1);
            Face.b = (word)(i-1);
            Face.c = (word)(j);

            Face.u[0] = u_left;
            Face.u[1] = u_left;
            Face.u[2] = u_right;

            Face.v[0] = v_bottom;
            Face.v[1] = v_top;
            Face.v[2] = v_half;
            break;
        case RIGHTA:
            Face.a = (word)j;
            Face.b = (word)(j-1);
            Face.c = (word)(i-1);

            Face.u[0] = u_right;
            Face.u[1] = u_left;
            Face.u[2] = u_left;

            Face.v[0] = v_bottom;
            Face.v[1] = v_bottom;
            Face.v[2] = v_half;
            break;
        case RIGHTB:
            Face.a = (word)i;
            Face.b = (word)j;
            Face.c = (word)(j-1);

            Face.u[0] = u_right;
            Face.u[1] = u_right;
            Face.u[2] = u_left;

            Face.v[0] = v_top;
            Face.v[1] = v_bottom;
            Face.v[2] = v_half;
            break;
        case BOTTOM_CORNERS:
            Face.a = (word)(j-1);
            Face.b = (word)(i-1);
            Face.c = (word)i;

            Face.u[0] = u_left;
            Face.u[1] = u_left;
            Face.u[2] = u_right;

            Face.v[0] = v_bottom;
            Face.v[1] = v_top;
            Face.v[2] = v_top;
            break;
        case TOP_CORNERS:
            Face.a = (word)(j-1);
            Face.b = (word)(i-1);
            Face.c = (word)j;

            Face.u[0] = u_left;
            Face.u[1] = u_left;
            Face.u[2] = u_right;

            Face.v[0] = v_bottom;
            Face.v[1] = v_top;
            Face.v[2] = v_bottom;
            break;
        default:
            assert(FALSE);
            Face.flags = FACE_FLAGS;
            return;
    }
    if (id != BOTTOM)
    {
        vpt[Face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                            ? txtcolor[sptr->cind-1] : sptr->cind;
    }
    else
    {
        vpt[Face.a].clr = 255;
        vpt[Face.a].shade = 173;
    }
    esch_clipdraw_face(0,ctrlfl);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw face 2
    switch (id)
    {
        case BOTTOM:
            Face.a = (word)(j-2);
            Face.b = (word)(i-1);
            Face.c = (word)(j-1);

            Face.u[0] = u_left;
            Face.u[1] = u_half;
            Face.u[2] = u_right;

            Face.v[0] = v_bottom;
            Face.v[1] = v_top;
            Face.v[2] = v_bottom;
            break;
        case TOP:
            Face.a = (word)i;
            Face.b = (word)j;
            Face.c = (word)(i-1);

            Face.u[0] = u_right;
            Face.u[1] = u_half;
            Face.u[2] = u_left;

            Face.v[0] = v_top;
            Face.v[1] = v_bottom;
            Face.v[2] = v_top;
            break;
        case LEFTB:
            Face.a = (word)i;
            Face.b = (word)j;
            Face.c = (word)(i-1);

            Face.u[0] = u_right;
            Face.u[1] = u_right;
            Face.u[2] = u_left;

            Face.v[0] = v_top;
            Face.v[1] = v_half;
            Face.v[2] = v_top;
            break;
        case RIGHTB:
            Face.a = (word)(i-1);
            Face.b = (word)i;
            Face.c = (word)(j-1);

            Face.u[0] = u_left;
            Face.u[1] = u_right;
            Face.u[2] = u_left;

            Face.v[0] = v_top;
            Face.v[1] = v_top;
            Face.v[2] = v_half;
            break;
        case BOTTOM_CORNERS:
            Face.a = (word)(j-1);
            Face.b = (word)i;   
            Face.c = (word)j;

            Face.u[0] = u_left;
            Face.u[1] = u_right;
            Face.u[2] = u_right;

            Face.v[0] = v_bottom;
            Face.v[1] = v_top;
            Face.v[2] = v_bottom;
            break;
        case TOP_CORNERS:
            Face.a = (word)i;   
            Face.b = (word)j;
            Face.c = (word)(i-1);

            Face.u[0] = u_right;
            Face.u[1] = u_right;
            Face.u[2] = u_left;

            Face.v[0] = v_top;
            Face.v[1] = v_bottom;
            Face.v[2] = v_top;
            break;
        default:
            Face.flags = FACE_FLAGS;
            return;
    }
    if (id != BOTTOM)
    {
        vpt[Face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                            ? txtcolor[sptr->cind-1] : sptr->cind;
    }
    else
    {
        vpt[Face.a].clr = 255;
        vpt[Face.a].shade = 173;
    }

    esch_clipdraw_face(0,ctrlfl);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Draw face 3
    switch (id)
    {
        case BOTTOM:
            Face.a = (word)i;
            Face.b = (word)(j-1);
            Face.c = (word)(i-1);

            Face.u[0] = u_right;
            Face.u[1] = u_right;
            Face.u[2] = u_half;

            Face.v[0] = v_top;
            Face.v[1] = v_bottom;
            Face.v[2] = v_top;
            break;
        case TOP:
            Face.a = (word)i;
            Face.b = (word)(j+1);
            Face.c = (word)j;

            Face.u[0] = u_right;
            Face.u[1] = u_right;
            Face.u[2] = u_half;

            Face.v[0] = v_top;
            Face.v[1] = v_bottom;
            Face.v[2] = v_bottom;
            break;
        default:
            Face.flags = FACE_FLAGS;
            return;
    }
    if (id != BOTTOM)
    {
        vpt[Face.a].clr = (sptr->flags & ESCH_SURF_CINDISTXT)
                            ? txtcolor[sptr->cind-1] : sptr->cind;
    }
    else
    {
        vpt[Face.a].clr = 255;
        vpt[Face.a].shade = 173;
    }
    esch_clipdraw_face(0,ctrlfl);

    Face.flags = FACE_FLAGS;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - draw                                                       ³
//                                                                          ³
// Displays the terrain.                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::draw()
{
    int                     i, j, k, w, d;          // Loop variables
    byte                    *ptr;                   // Fast-access pointers
    struct esch_surf_type   *sptr;
    dword                   *vflags;
    VngoPoint               *vpt, *v;
    int                     sw, ew, sd, ed, rowsz;  // Bound area indecies and values
    int                     swm, ewm, sdm, edm;     // Medium detail indecies
    int                     swl, ewl, sdl, edl;     // Low detail indecies
    ulong                   needed;
    Flx16                   tx, ty;                 // Temp values
    Flx16                   minx, minz, maxx, maxz; // Bounding area (far/yon)
    Flx16                   mlox, mloz, mhix, mhiz; // Medium detail area
    Flx16                   llox, lloz, lhix, lhiz; // Low detail area
    static EschPoint        po, pd, pw;             // Workspace

    assertMyth("EschTerrain::draw needs height-field information",
               hfield && htable);

    assertMyth("EschTerrain::draw needs surface information",
               surfinfo);

    if (!hfield || !htable || !surfinfo)
        return;

//ÄÄÄ Clear arena
    assertMyth("EschTerrain needs Escher initialized",EschSysInstance != 0);
    ivory_arena_clear(EschSysInstance->wspace);

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschTerrain::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    EschCamera *cam=EschCurrent->camera;

    assertMyth("EschTerrain::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    dword ctrlfl = ESCH_CDF_CLIP
                   | ((cam->flags & ESCH_CAM_BACKCULL) ? ESCH_CDF_BFCULL : 0);

//ÄÄÄ Transform view volume into world coords and project onto XZ plane,
//ÄÄÄ forming min/max bound.  Also, figure medium and low detail areas, if
//ÄÄÄ needed.

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Camera Position
    EschPoint   pos;

    cam->get_position(&pos);

    {
        EschVector  tvect;
        tvect = cam->eye.dir;
        tvect = tvect * scale * Flx16(2);

        pos.x = (pos.x - tvect.i);
        pos.y = (pos.y - tvect.j);
        pos.z = (pos.z - tvect.k);
    }

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
                      &sw, &ew, &sd, &ed, 3))
        return;

    rowsz = ew - sw;
    assert(rowsz > 0);

    //ÄÄÄ Level Of Detail areas
    if (flags & ESCH_TRN_LOD)
    {
        //ÄÄÄ Medium LOD
        if (!compute_area(mlox, mloz, mhix, mhiz,
                          &swm, &ewm, &sdm, &edm, 2))
        {
            swm=sw-2;   
            if (sw < 0)
                sw = 0;
            sdm=sd-2;
            if (sd < 0)
                sd = 0;
            ewm=(width + 2) & ~0x1;
            if (ewm > width)
                ewm = width;
            edm=(depth + 2) & ~0x1;
            if (edm > depth)
                edm = depth;
        }

        if (swm <= sw)
            swm = sw-2;
        if (ewm >= ew)
            ewm = ew+2;

        if (sdm <= sd)
            sdm = sd-2;
        if (edm >= ed)
            edm = ed+2;

        //ÄÄÄ Low LOD
        if (!compute_area(llox, lloz, lhix, lhiz,
                          &swl, &ewl, &sdl, &edl, 3))
        {
            swl=sw-4;
            if (sw < 0)
                sw = 0;
            sdl=sd-4;
            if (sd < 0)
                sd = 0;
            ewl=(width + 4) & ~0x3;
            if (ewl > width)
                ewl = width;
            edl=(depth + 4) & ~0x3;
            if (edl > depth)
                edl = depth;
        }

        if (swl <= sw)
            swl = sw-4;
        if (ewl >= ew)
            ewl = ew+4;

        if (sdl <= sd)
            sdl = sd-4;
        if (edl >= ed)
            edl = ed+4;
    }


//ÄÄÄ Compute orientation factors for terrain grid.  These are used
//ÄÄÄ during the transform of the height field into the camera's view.
    assertMyth("EschTerrain::draw needs positive scale factors",
               scale.flx > 0 && htable != 0);

    EschVector wvec(scale,0,0);
    wvec.transform(&cam->eye.iorient);

    EschVector dvec(0,0,scale);
    dvec.transform(&cam->eye.iorient);

    EschVector hvec(0,1,0);
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
    ec.current = this;
    ec.verts = 0;
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword)*rowsz*2);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[rowsz*2];
    ec.faces = &Face;
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

            // Test for Medium/Low LOD row skip
            if (flags & ESCH_TRN_LOD)
            {
#if USE_LOW_LOD
                if ((d < sdl || d >= edl-3 || w < swl || w >= ewl-3)
                    && (d & 0x3))
                { 
                    // Handle missing triangle for 
                    if (!(flags & ESCH_TRN_DOTS)
                        && (w == ewl))
                    {
                        sptr = surfinfo;
                        sptr += ((d >> surfshift) * (width >> surfshift)) + (w >> surfshift);

                        draw_transitions(w, d, i, j, sptr, ctrlfl, RIGHTA, 2);
                    }

                    *v = vpt[j];
                    vflags[i] = vflags[j];

                    w += 4;
                    ptr += 4;
                    pw.x.flx += wvec.i.flx << 2;
                    pw.y.flx += wvec.j.flx << 2;
                    pw.z.flx += wvec.k.flx << 2;
                    continue;
                }
                else
#endif
                if ((d < sdm || d >= edm-1 || w < swm || w >= ewm-1)
                    && (d & 0x1))
                { 
                    // Handle missing triangle for 
                    if (!(flags & ESCH_TRN_DOTS)
                        && (w == ewm))
                    {
                        sptr = surfinfo;
                        sptr += ((d >> surfshift) * (width >> surfshift)) + (w >> surfshift);

                        draw_transitions(w, d, i, j, sptr, ctrlfl, RIGHTA, 1);
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
            Flx16 h = htable[*ptr];
            ((EschPoint*)v)->x.flx = pw.x.flx + (h * hvec.i).flx;
            ((EschPoint*)v)->y.flx = pw.y.flx + (h * hvec.j).flx;
            ((EschPoint*)v)->z.flx = pw.z.flx + (h * hvec.k).flx;

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
                        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Use level-of-detail
                        if (flags & ESCH_TRN_LOD)
                        {
#if USE_LOW_LOD
                            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Low LOD
                            if (d < sdl || d > edl || w < swl || w > ewl)
                            {
                                // (d is never odd since top case catches that)
                                assert ((d & 0x3) == 0);

                                draw_block(w, d, i, j, sptr, ctrlfl, 2);
                            }
                            else if (d == sdl)
                            {
                                if (w == swl || w == ewl)
                                {
                                    draw_transitions(w, d, i, j, sptr, ctrlfl, BOTTOM_CORNERS, 2);
                                }
                                else if ((w & 0x3) == 0)
                                {
                                    draw_transitions(w, d, i, j, sptr, ctrlfl, BOTTOM, 2);
                                    j--;
                                }

                                // Don't draw in odd case
                            }
                            else if (d >= edl-3)
                            {
                                if (d == edl)
                                {
                                    if (w == swl || w == ewl)
                                    {
                                        draw_transitions(w, d, i, j, sptr, ctrlfl, TOP_CORNERS, 2);
                                    }
                                    else
                                    {
                                        draw_transitions(w, d, i, j, sptr, ctrlfl, TOP, 2);
                                        j++;
                                    }
                                }

                                // Don't draw in edl-3 case
                            }
                            else if (w == swl)
                            {
                                if (d & 0x3)
                                {
                                    draw_transitions(w, d, i, j, sptr, ctrlfl, LEFTA, 2);
                                }
                                else
                                {
                                    draw_transitions(w, d, i, j, sptr, ctrlfl, LEFTB, 2);
                                }
                            }
                            else if (w >= ewl-3)
                            {

                                // One of the 3 faces points are missing by
                                // this point... must do this above when we
                                // skip the row.

                                if (w == ewl)
                                {
                                    if ((d & 0x3) == 0)
                                    {
                                        draw_transitions(w, d, i, j, sptr, ctrlfl, RIGHTB, 2);
                                    }

                                    // Don't draw in odd case
                                }

                                // Don't draw in ewl-3 case
                            }

                            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Medium LOD
                            else
#endif
                            if (d < sdm || d > edm || w < swm || w > ewm)
                            {
                                // (d is never odd since top case catches that)
                                assert ((d & 0x1) == 0);

                                draw_block(w, d, i, j, sptr, ctrlfl, 1);
                            }
                            else if (d == sdm)
                            {
                                if (w == swm || w == ewm)
                                {
                                    draw_transitions(w, d, i, j, sptr, ctrlfl, BOTTOM_CORNERS, 1);
                                }
                                else if ((w & 0x1) == 0)
                                {
                                    draw_transitions(w, d, i, j, sptr, ctrlfl, BOTTOM, 1);
                                    j--;
                                }

                                // Don't draw in odd case
                            }
                            else if (d >= edm-1)
                            {
                                if (d == edm)
                                {
                                    if (w == swm || w == ewm)
                                    {
                                        draw_transitions(w, d, i, j, sptr, ctrlfl, TOP_CORNERS, 1);
                                    }
                                    else if ((w & 0x1) == 0)
                                    {
                                        draw_transitions(w, d, i, j, sptr, ctrlfl, TOP, 1);
                                        j++;
                                    }
                                }

                                // Don't draw in edm-1 case
                            }
                            else if (w == swm)
                            {
                                if (d & 0x1)
                                {
                                    draw_transitions(w, d, i, j, sptr, ctrlfl, LEFTA, 1);
                                }
                                else
                                {
                                    draw_transitions(w, d, i, j, sptr, ctrlfl, LEFTB, 1);
                                }
                            }
                            else if (w >= ewm-1)
                            {

                                // One of the 3 faces points are missing by
                                // this point... must do this above when we
                                // skip the row.

                                if (w == ewm)
                                {
                                    if ((d & 0x1) == 0)
                                    {
                                        draw_transitions(w, d, i, j, sptr, ctrlfl, RIGHTB, 1);
                                    }

                                    // Don't draw in odd case
                                }

                                // Don't draw in ewm-1 case
                            }
                            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ High LOD
                            else
                            {
                                draw_block(w, d, i, j, sptr, ctrlfl, 0);
                            }
                        }
                        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Always draw as full detail
                        else
                        {
                            draw_block(w, d, i, j, sptr, ctrlfl, 0);
                        }
                    }
                }
            }

            // Advance walk in width
#if USE_LOW_LOD
            if (flags & ESCH_TRN_LOD
                && (d < sdl || d >= edl-3 || w < swl || w >= ewl-5))
            {
                w += 4;
                ptr += 4;
                pw.x.flx += wvec.i.flx << 2;
                pw.y.flx += wvec.j.flx << 2;
                pw.z.flx += wvec.k.flx << 2;
            }
            else
#endif
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

#if USE_LOW_LOD
        if (flags & ESCH_TRN_LOD
            && (d < sdl-3 || d > edl+3))
        { 
            d += 4;
            pd.x.flx += dvec.i.flx << 2;
            pd.y.flx += dvec.j.flx << 2;
            pd.z.flx += dvec.k.flx << 2;
        }
        else
#endif
        if (flags & ESCH_TRN_LOD
            && (d < sdm-1 || d > edm+1))
        { 
            d += 2;
            pd.x.flx += dvec.i.flx << 1;
            pd.y.flx += dvec.j.flx << 1;
            pd.z.flx += dvec.k.flx << 1;
        }
        else
        {
            d++;
            pd.x.flx += dvec.i.flx;
            pd.y.flx += dvec.j.flx;
            pd.z.flx += dvec.k.flx;
        }
    }
//
//ÄÄÄ Pop drawing context
    ec.pop();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - animate                                                    ³
//                                                                          ³
// This call is used to inform the drawable to animate itself for the next  ³
// frame.  This is called directly by the application when needed.          ³
// The base behavior for the terrain is to call animate for each texture    ³
// in the texture list.                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::animate()
{
    if (!txt)
        return;

    for(ulong i=0; i < tmax; i++)
    {
        EschTexture *t = txt[i];
        if (!(t->flags & ESCH_TXT_SKIPANIMATE))
            t->animate();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - compute_shades                                             ³
//                                                                          ³
// Computes the lighting values for the terrain.  Computing the lighting    ³
// values every frame is extremely expensive, so this routine must be       ³
// called explicitly to set the terrain shading values.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::compute_shades(EschCamera *cam, EschLight *lgts)
{
    byte            *ptr;
    int             w,d;
    esch_surf_type  *sptr;
    dword           level;
    EschVector      *nptr=0;
    EschPoint       pd, pw;
    VngoPoint       v;
    EschVertex      vert;

    assertMyth("EschTerrain::compute_shades needs surfinfo",
               surfinfo);

    //ÄÄÄ Figure out shade level (take minimum of shade levels for
    //ÄÄÄ camera and drawable limits)

    level = cam->flags & limits;

//ÄÄÄ Handle case of 'trivial' shade computation
    if (!lgts
       || !(level & (ESCH_CAM_SHADE_FLAT
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
               scale.flx > 0 && htable != 0);

    pd.x.flx = origin.x.flx;
    pd.y.flx = origin.y.flx;
    pd.z.flx = origin.z.flx;
    for(d=0, sptr=surfinfo;
        d < (depth >> surfshift);
        d++, pd.z.flx += Flx16((long)surfratio << scaleshift).flx)
    {
        ptr = hfield + ((d << surfshift)*width);

        pw.x.flx = pd.x.flx;
        pw.y.flx = pd.y.flx;
        pw.z.flx = pd.z.flx;

        for(w=0; w < (width >> surfshift);
            w++, pw.x.flx += Flx16((long)surfratio << scaleshift).flx,
            ptr += surfratio)
        {
            vert.x.flx = pw.x.flx;
            vert.y.flx = pw.y.flx + htable[*ptr].flx;
            vert.z.flx = pw.z.flx;

            vert.normal.i = nptr->i;
            vert.normal.j = nptr->j;
            vert.normal.k = nptr->k;
            nptr++;

            v.shade = 0;

            if (level & ESCH_CAM_SHADE_SPECULAR)
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
//                                                                          ³
// Releases all data associated with the EschTerrain instance.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::release()
{
    if (flags & ESCH_DRW_OWNSDATA)
    {
//ÄÄ Free associated data, if any
        if (hfield)
        {
            delete [] hfield;
            hfield=0;
        }
        if (htable)
        {
            delete [] htable;
            htable=0;
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
            for(ulong i=0; i < tmax; i++)
            {
                if (txt[i])
                    delete txt[i];
            }
            delete [] txt;
            txt=0;
            tmax=0;
        }

        flags &= ~ESCH_DRW_OWNSDATA;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - get_height                                                 ³
//                                                                          ³
// Return the world y value on the terrain surface at the givne x,z world   ³
// location.                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
Flx16 EschTerrain::get_height(Flx16 x, Flx16 z) const
{
    Flx16   x0,y0,z0,a1,a2,b1,b2,c1,c2,t1,t2,y;

    Flx16 _x = x - origin.x;
    Flx16 _z = z - origin.z;

    assertMyth("EschTerrain::get_height needs height-field information",
               hfield && htable);

    assertMyth("EschTerrain:get_height needs positive scales",
               scale.flx > 0);

    int     lx = (int)_x >> scaleshift;
    int     lz = (int)_z >> scaleshift;

    Flx16   wx = Flx16(lx << scaleshift);
    Flx16   wz = Flx16(lz << scaleshift);

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

    return (y + origin.y);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - get_surface_flags                                          ³
//                                                                          ³
// Return the surface flags associated with the given x,z world location.   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ushort EschTerrain::get_surface_flags(Flx16 x, Flx16 z) const
{
    Flx16 _x = x - origin.x;
    Flx16 _z = z - origin.z;
          
    assertMyth("EschTerrain::get_surface_flags needs surface information",
               surfinfo);

    int     lx = (int)_x >> (scaleshift+surfshift);
    int     lz = (int)_z >> (scaleshift+surfshift);

    int swidth = width >> surfshift;

//ÄÄÄÄ Check that point is on map
    if ((lx < 0)
        || (lz < 0)
        || (lx >= swidth)
        || (lz >= (depth >> surfshift)))
        return 0;

//ÄÄÄÄ Return surface information
    esch_surf_type *sptr = surfinfo + (lz*swidth) + lx;
    return sptr->flags;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - check_LOS                                                  ³
//                                                                          ³
// Check to see if the terrain obstructs the line of sight between two      ³
// points.                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschTerrain::check_LOS (EschPoint *pt1, EschPoint *pt2, 
                           int precision,Flx16 *ndist) const
{
//ÄÄÄ Form vector
    EschVector  temp (pt1->x - pt2->x, pt1->y - pt2->y, pt1->z - pt2->z);
    Flx16       dist = temp.magnitude();

//ÄÄÄ Determine step count and size
    long count;
    if (precision > 0)
    {
        count = (long)(dist / Flx16(precision)) + 1;
    }
    else
    {
        count = (long)(dist / scale) + 1;
    }

    Flx16 xstep = (pt2->x - pt1->x) / Flx16(count);
    Flx16 ystep = (pt2->y - pt1->y) / Flx16(count);
    Flx16 zstep = (pt2->z - pt1->z) / Flx16(count);

//ÄÄÄ Perform checks
    Flx16 curx = pt1->x;
    Flx16 cury = pt1->y;
    Flx16 curz = pt1->z;

    for (long i=0; i < count; i++)
    {
        Flx16 nheight = get_height(curx,curz);
        if (nheight.flx > cury.flx)
        {
            if (ndist != NULL)
            {
                EschVector tvect(curx-pt1->x,nheight-pt1->y,curz-pt1->z);
                *ndist = tvect.magnitude();
            }
            return 0;
        }
        curx += xstep;
        cury += ystep;
        curz += zstep;
    }
    return 1;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - set_scale                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTerrain::set_scale(const Flx16 i)
{
    assertMyth("EschTerrain:set_scale requires positive scale value",
               i.flx > 0);

    if (!compute_shift_value((ulong)(long)i,&scaleshift))
        return;

    scale = i;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain - load                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschTerrain::load(const char *fname, const char *tname, ushort *hclr)
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
                err=load(&iff,tname,hclr);
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

esch_error_codes EschTerrain::load(XFParseIFF *iff, const char *tname, ushort *hclr)
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
    origin.x = header.origin_x;
    origin.y = header.origin_y;
    origin.z = header.origin_z;

    if (!compute_shift_value(surfratio,(&surfshift)))
    {
        iff->leaveform();
        return ESCH_ERR_NOTSUPPORTED;
    }
    if (header.wscale.flx > 0 || header.dscale.flx > 0)
    {
        scale = 32;
        scaleshift = 5;
    }
    else
    {
        scale = header.scale;
        if (!compute_shift_value((ulong)(long)scale,&scaleshift))
        {
            iff->leaveform();
            return ESCH_ERR_NOTSUPPORTED;
        }
    }

    ulong surfsize = (width*depth) >> (surfshift*2);

    //ÄÄ If height scale is given, must create height table
    if (header.hscale.flx)
    {
        htable = new Flx16[256];
        if (!htable)
        {
            err=ESCH_ERR_NOMEMORY;
            goto error_exit;
        }

        Flx16 hs=0;
        for(ulong i=0; i < 256; i++)
        {
            htable[i] = hs;
            hs += header.hscale;
        }
    }

    //ÄÄ Scan and load chunks in form
    while (!iff->next())
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Height Field
        if (iff->chunkid == iff->makeid('H','G','T','S'))
        {
            if (hfield
                || iff->chunkSize != (ulong)(width * depth))
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
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Height Table
        else if (iff->chunkid == iff->makeid('H','T','B','L'))
        {
            if (htable
                || iff->chunkSize != sizeof(Flx16)*256)
            {
                err=ESCH_ERR_INVALIDHGTDATA;
                goto error_exit;
            }

            htable = new Flx16[256];
            if (!htable)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            if (iff->read(htable))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Surface Info
        else if (iff->chunkid == iff->makeid('S','U','R','F'))
        {
            if (surfinfo
                || iff->chunkSize != (ulong)(surfsize
                                             * sizeof(esch_surf_type)))
            {
                err=ESCH_ERR_INVALIDSRFDATA;
                goto error_exit;
            }

            surfinfo = new esch_surf_type[surfsize];
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
        else if ((iff->chunkid == iff->makeid('N','R','M','1')
                 || iff->chunkid == iff->makeid('N','R','M','L')))
        {   
            if (hsurfnorml)
            {
                err=ESCH_ERR_INVALIDSRFDATA;
                goto error_exit;
            }

            hsurfnorml = ivory_halloc((ulong)(surfsize * sizeof(EschVector)));
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

            if (iff->chunkid == iff->makeid('N','R','M','1'))
            {
                //ÄÄÄ Compressed normals
                if (iff->chunkSize != (ulong)(surfsize * 4 * sizeof(ushort)))
                {
                    err=ESCH_ERR_INVALIDSRFDATA;
                    goto error_exit;
                }

                ushort *cnrmls = new ushort[surfsize * 4];
                if (!cnrmls)
                {
                    err=ESCH_ERR_NOMEMORY;
                    goto error_exit;
                }
                if (iff->read(cnrmls))
                {
                    delete cnrmls;
                    err=ESCH_ERR_FILEERROR;
                    goto error_exit;
                }

                ushort *sptr = cnrmls;
                for(ulong i=0; i < surfsize; i++, ptr++)
                {
                    ptr->i.flx = (ulong)*(sptr++);
                    ptr->j.flx = (ulong)*(sptr++);
                    ptr->k.flx = (ulong)*(sptr++);

                    if (*sptr & 0x1)
                        ptr->i.flx |= 0x00010000;
                    if (*sptr & 0x2)
                        ptr->j.flx |= 0x00010000;
                    if (*sptr & 0x4)
                        ptr->k.flx |= 0x00010000;

                    if (*sptr & 0x8)
                        ptr->i.flx = -ptr->i.flx;
                    if (*sptr & 0x10)
                        ptr->j.flx = -ptr->j.flx;
                    if (*sptr & 0x20)
                        ptr->k.flx = -ptr->k.flx;
                    sptr++;
                }

                delete cnrmls;
            }
            else
            {
                //ÄÄÄ Uncompressed normals
                if (iff->chunkSize != (ulong)(surfsize * sizeof(EschVector)))
                {
                    err=ESCH_ERR_INVALIDSRFDATA;
                    goto error_exit;
                }
                if (iff->read(ptr))
                {
                    err=ESCH_ERR_FILEERROR;
                    goto error_exit;
                }
            }

            ivory_hunlock(hsurfnorml);
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Height colors
        else if (hclr
                 && iff->chunkid == iff->makeid('H','C','L','R'))
        {
            EschFileTerrHCLR hcolor;

            if (iff->chunkSize != sizeof(EschFileTerrHCLR))
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }

            if (iff->read(&hcolor))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }

            hclr[0] = hcolor.blue;
            hclr[1] = hcolor.lblue;
            hclr[2] = hcolor.white;
            hclr[3] = hcolor.green;
            hclr[4] = hcolor.lgreen;
            hclr[5] = hcolor.yellow;
            hclr[6] = hcolor.lorange;
            hclr[7] = hcolor.orange;
            hclr[8] = hcolor.lbrown;
            hclr[9] = hcolor.brown;
            hclr[10] = hcolor.red;
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Texture Colors
        else if (header.ntxts
                 && (iff->chunkid == iff->makeid('C','O','L','R')))
        {
            if (txtcolor
                || iff->chunkSize != header.ntxts)
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
                txt = new EschTexture*[header.ntxts];
                if (!txt)
                {
                    err=ESCH_ERR_NOMEMORY;
                    goto error_exit;
                }
                tmax = header.ntxts;
            }

            if (nt < tmax)
            {
                EschTexture *t = new EschStaticTexture;
                if (!t)
                {
                    err=ESCH_ERR_NOMEMORY;
                    goto error_exit;
                }
                if (err=t->load(iff))
                {
                    delete t;
                    goto error_exit;
                }

                txt[nt++] = t;
            }
        }
    }

    if (!hfield || !htable || !surfinfo)
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
    if (htable)
    {
        delete [] htable;
        htable=0;
    }
    if (surfinfo)
    {
        delete [] surfinfo;
        surfinfo=0;
    }
    if (txt)
    {
        for(ulong i=0; i < tmax; i++)
        {
            if (txt[i])
                delete txt[i];
        }
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

