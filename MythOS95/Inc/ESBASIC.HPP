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
// Created by Tim Little & Chuck Walbourn
//
// esbasic.hpp
//
// Contains some basic draw classes.
//
// EschPointDraw is a single unlit colored point in 3-space.
//
// EschLineDraw is a single unlit colored line in 3-space.
//
// EschSprite is a 2D bitmap always facing the viewer.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ESBASIC_HPP
#define __ESBASIC_HPP    1

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

#include "esdraw.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPointDraw -  Single colored point in 3-space.                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschPointDraw : public EschDrawable
{
public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschPoint   pos;                        // Position
    dword       color;                      // Color

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschPointDraw() : EschDrawable(ESCH_DRWT_POINTDRAW) {}

    EschPointDraw(float ix, float iy, float iz, dword c) :
        EschDrawable(ESCH_DRWT_POINTDRAW),
        pos(ix,iy,iz), color(c) {}

    EschPointDraw(const EschPoint *p, dword c, ulong l=0) :
        EschDrawable(ESCH_DRWT_POINTDRAW),
        pos(*p), color(c) {}

    virtual ~EschPointDraw() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void draw();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility routines.                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_position(float ix, float iy, float iz)
    {
        pos.x = ix;  pos.y = iy;  pos.z = iz;
    }
    void set_position(const EschPoint *pnt)
    {
        pos.x = pnt->x;  pos.y = pnt->y;  pos.z = pnt->z;
    }

    void set_color(dword c) { color = c; }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschLineDraw -  Single colored line in 3-space.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschLineDraw : public EschDrawable
{
public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschPoint   pos1;                       // End-positions
    EschPoint   pos2;
    dword       color;                      // Color

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschLineDraw() : EschDrawable(ESCH_DRWT_LINEDRAW) {}

    EschLineDraw(float ix1, float iy1, float iz1,
                 float ix2, float iy2, float iz2,
                 dword c) :
        EschDrawable(ESCH_DRWT_LINEDRAW),
        pos1(ix1,iy1,iz1), pos2(ix2,iy2,iz2), color(c) {}

    EschLineDraw(const EschPoint *p1, const EschPoint *p2, dword c, ulong l=0) :
        EschDrawable(ESCH_DRWT_LINEDRAW),
        pos1(*p1), pos2(*p2), color(c) {}

    virtual ~EschLineDraw() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void draw();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility routines.                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_position(float ix1, float iy1, float iz1,
                      float ix2, float iy2, float iz2)
    {
        pos1.x = ix1;  pos1.y = iy1;  pos1.z = iz1;
        pos2.x = ix2;  pos2.y = iy2;  pos2.z = iz2;
    }
    void set_position(const EschPoint *pnt1, const EschPoint *pnt2)
    {
        pos1.x = pnt1->x;  pos1.y = pnt1->y;  pos1.z = pnt1->z;
        pos2.x = pnt2->x;  pos2.y = pnt2->y;  pos2.z = pnt2->z;
    }

    void set_color(dword c) { color = c; }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSprite - 2D bitmap always drawn facing the viewer.                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschSprite : public EschDrawable
{
protected:
    EschTexture     *txt;
    long            alpha_level;

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschPoint       pos;
    float           width;
    float           height;
    float           rotation;
    float           scale;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschSprite() :
        EschDrawable(ESCH_DRWT_SPRITE),
        txt(0),
        alpha_level(255),
        rotation(0),
        scale(1) {};
    EschSprite(float ix, float iy, float iz, float w, float h,
               float r=0, float s=1) :
        EschDrawable(ESCH_DRWT_SPRITE),
        txt(0),
        alpha_level(255),
        pos(ix,iy,iz),
        width(w), height(h),
        rotation(r),
        scale(s) {};
    EschSprite(const EschPoint *p, float w, float h,
               float r=0, float s=1) :
        EschDrawable(ESCH_DRWT_SPRITE),
        txt(0),
        alpha_level(255),
        pos(*p),
        width(w), height(h),
        rotation(r),
        scale(s) {};

    virtual ~EschSprite();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschSprite &operator = (const EschSprite &s);

    virtual void draw();
    virtual int get_extents(EschSphereExtents *sp) const;
    virtual void animate();

    virtual void release();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_position(float ix, float iy, float iz)
    {
        pos.x = ix;
        pos.y = iy;
        pos.z = iz;
    }
    void set_position(const EschPoint *pnt)
    {
        pos.x = pnt->x;
        pos.y = pnt->y;
        pos.z = pnt->z;
    }

    void set_size(float w, float h)
    {
        width=w;
        height=h;
    }

    void set_rotation (float r) { rotation = r; }
    void set_scale (float s) { scale = s; }

    void set_alpha(long alpha) { alpha_level = alpha; }
    long get_alpha() const { return alpha_level; }

    void attach(EschTexture *t);

    esch_error_codes create(XFBitmap *bm, float w, float h,
                            int trans=1, VngoPal *pal=0);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esbasic.hpp ²±°

