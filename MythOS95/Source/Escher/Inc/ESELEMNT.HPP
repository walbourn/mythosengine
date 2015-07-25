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
//שששששששששששCopyrightש(c)ש1994-1997שbyשCharybdisשEnterprises,שInc.שששששששששש
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
// Created by Tim Little & Chuck Walbourn
//
// eselemnt.hpp
//
// Contains the primtive output routines and support classes for both
// sorted and Z-buffer based drawing.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

#ifndef __ESELEMNT_HPP
#define __ESELEMNT_HPP    1

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

#include <vangogh.hpp>

#include "esdefs.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern ulong EschElementSize;
class EschTexture;
class EschPoint;

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschElement - Base class for sort elements.                              ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
class EschElement
{
protected:
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Protected draw function for tree recursion                           ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
    static void draw_tree(EschElement *elm);
    static EschElement *link_tree(EschElement *elm);

public:
    float       maxz;                   // Maximum Z
    float       minz;                   // Minimum Z
    float       maxx;                   // Maximum X
    float       minx;                   // Minimum X
    float       maxy;                   // Maximum Y
    float       miny;                   // Minimum Y
    word        typ;                    // Element type
    ushort      count;                  // Element specific count
    EschElement *left;                  // Left binary tree pointer
    EschElement *right;                 // Right binary tree pointer

    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Constructor/Destructor                                               ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
    EschElement(word _typ) :
        typ(_typ),
        left(0),
        right(0)
    {}
    ~EschElement() {}

    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
    // Operations                                                           ³
    //ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
    virtual void insert();
    virtual void draw()=0;
    virtual void prepare_test(EschPoint *pt) const =0;
    virtual BOOL perform_test(const EschPoint *pt) const =0 ;

    static void flush();
    static void flush_truesort();
};


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschPixelElement - Pixel element.                                        ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
class EschPixelElement : public EschElement
{
public:
    VngoPointF  pnt;

    EschPixelElement(VngoPointF *pt) :
        EschElement(ESCH_ELMNT_PIXEL),
        pnt(*pt)
    {
        maxz = minz = pt->z;
        maxx = minx = pt->x;
        maxy = miny = pt->y;
        EschElementSize += sizeof(*this);
    }

    virtual void draw();
    virtual void prepare_test(EschPoint *pt) const;
    virtual BOOL perform_test(const EschPoint *pt) const;
};


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschLineElement - Line element.                                          ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
class EschLineElement : public EschElement
{
public:
    VngoPointF  pnt1;
    VngoPointF  pnt2;

    EschLineElement(VngoPointF *pt1, VngoPointF *pt2) :
        EschElement(ESCH_ELMNT_LINE),
        pnt1(*pt1),
        pnt2(*pt2)
    {
        if (pt1->z < pt2->z) { minz = pt1->z;  maxz = pt2->z; }
        else { minz = pt2->z;  maxz = pt1->z; }

        if (pt1->x < pt2->x) { minx = pt1->x;  maxx = pt2->x; }
        else { minx = pt2->x;  maxx = pt1->x; }

        if (pt1->y < pt2->y) { miny = pt1->y;  maxy = pt2->y; }
        else { miny = pt2->y;  maxy = pt1->y; }
        
        EschElementSize += sizeof(*this);
    }

    virtual void draw();
    virtual void prepare_test(EschPoint *pt) const;
    virtual BOOL perform_test(const EschPoint *pt) const;
};


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschPolyElement - Polygon element.                                       ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
class EschPolyElement : public EschElement
{
public:
    VngoPointF  vpoly[1];               // Place holder for data

    EschPolyElement(long _count, VngoPointF *_vpoly,
                    word _typ=ESCH_ELMNT_POLY) :
        EschElement(_typ)
    {
        assertMyth("EschPolyElement must have valid typ",
                   (_typ == ESCH_ELMNT_POLY)
                   || (_typ == ESCH_ELMNT_GPOLY)
                   || (_typ == ESCH_ELMNT_GPOLY_PERSP));

        assertMyth("EschPolyElement needs valid input",
                   _count >= 3 && _vpoly != 0);

        count = (ushort)_count;
        memcpy(vpoly, _vpoly, _count * sizeof(VngoPointF));
        EschElementSize += sizeof(*this) + ((_count-1) * sizeof(VngoPointF));

        //ִִִ Set extents
        maxz = minz = _vpoly[0].z;
        maxx = minx = _vpoly[0].x;
        maxy = miny = _vpoly[0].y;
        for(_count--; _count >= 1; _count--)
        {
            if (_vpoly[_count].z > maxz)  maxz = _vpoly[_count].z;
            if (_vpoly[_count].z < minz)  minz = _vpoly[_count].z;
            if (_vpoly[_count].x > maxx)  maxx = _vpoly[_count].x;
            if (_vpoly[_count].x < minx)  minx = _vpoly[_count].x;
            if (_vpoly[_count].y > maxy)  maxy = _vpoly[_count].y;
            if (_vpoly[_count].y < miny)  miny = _vpoly[_count].y;
        }
    }

    virtual void draw();
    virtual void prepare_test(EschPoint *pt) const;
    virtual BOOL perform_test(const EschPoint *pt) const;
};


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschPolyAElement - Polygon with alpha element.                           ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
class EschPolyAElement : public EschElement
{
public:
    long        alpha;
    VngoPointF  vpoly[1];               // Place holder for data

    EschPolyAElement(long _count, VngoPointF *_vpoly, long _alpha,
                     word _typ=ESCH_ELMNT_POLY_A) :
        EschElement(_typ),
        alpha(_alpha)
    {
        assertMyth("EschPolyAElement must have valid typ",
                   (_typ == ESCH_ELMNT_POLY_A)
                   || (_typ == ESCH_ELMNT_GPOLY_A)
                   || (_typ == ESCH_ELMNT_GPOLY_PERSP_A));

        assertMyth("EschPolyAElement needs valid input",
                   _count >= 3 && _vpoly != 0);

        count = (ushort)_count;
        memcpy(vpoly, _vpoly, _count * sizeof(VngoPointF));
        EschElementSize += sizeof(*this) + ((_count-1) * sizeof(VngoPointF));

        //ִִִ Set extents
        maxz = minz = _vpoly[0].z;
        maxx = minx = _vpoly[0].x;
        maxy = miny = _vpoly[0].y;
        for(_count--; _count >= 1; _count--)
        {
            if (_vpoly[_count].z > maxz)  maxz = _vpoly[_count].z;
            if (_vpoly[_count].z < minz)  minz = _vpoly[_count].z;
            if (_vpoly[_count].x > maxx)  maxx = _vpoly[_count].x;
            if (_vpoly[_count].x < minx)  minx = _vpoly[_count].x;
            if (_vpoly[_count].y > maxy)  maxy = _vpoly[_count].y;
            if (_vpoly[_count].y < miny)  miny = _vpoly[_count].y;
        }
    }

    virtual void draw();
    virtual void prepare_test(EschPoint *pt) const;
    virtual BOOL perform_test(const EschPoint *pt) const;
};


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschPolyTxtElement - Textured polygon element.                           ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
class EschPolyTxtElement : public EschElement
{
public:
    EschTexture *txt;
    VngoPointF  vpoly[1];               // Place holder for data

    EschPolyTxtElement(long _count, VngoPointF *_vpoly, EschTexture *_txt,
                       word _typ=ESCH_ELMNT_TXTPOLY) :
        EschElement(_typ),
        txt(_txt)
    {
        assertMyth("EschPolyTxtElement must have valid typ",
                   (_typ == ESCH_ELMNT_TXTPOLY)
                   || (_typ == ESCH_ELMNT_TXTPOLY_PERSP)
                   || (_typ == ESCH_ELMNT_GTXTPOLY)
                   || (_typ == ESCH_ELMNT_GTXTPOLY_PERSP));

        assertMyth("EschPolyTxtElement needs valid input",
                   _count >= 3 && _vpoly != 0);

        count = (ushort)_count;
        memcpy(vpoly, _vpoly, _count * sizeof(VngoPointF));
        EschElementSize += sizeof(*this) + ((_count-1) * sizeof(VngoPointF));

        //ִִִ Set extents
        maxz = minz = _vpoly[0].z;
        maxx = minx = _vpoly[0].x;
        maxy = miny = _vpoly[0].y;
        for(_count--; _count >= 1; _count--)
        {
            if (_vpoly[_count].z > maxz)  maxz = _vpoly[_count].z;
            if (_vpoly[_count].z < minz)  minz = _vpoly[_count].z;
            if (_vpoly[_count].x > maxx)  maxx = _vpoly[_count].x;
            if (_vpoly[_count].x < minx)  minx = _vpoly[_count].x;
            if (_vpoly[_count].y > maxy)  maxy = _vpoly[_count].y;
            if (_vpoly[_count].y < miny)  miny = _vpoly[_count].y;
        }
    }

    virtual void draw();
    virtual void prepare_test(EschPoint *pt) const;
    virtual BOOL perform_test(const EschPoint *pt) const;
};


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschPolyTxtAElement - Textured polygon with alpha element.               ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
class EschPolyTxtAElement : public EschElement
{
public:
    EschTexture *txt;
    long        alpha;
    VngoPointF  vpoly[1];               // Place holder for data

    EschPolyTxtAElement(long _count, VngoPointF *_vpoly,
                        EschTexture *_txt, long _alpha,
                        word _typ=ESCH_ELMNT_TXTPOLY_A) :
        EschElement(_typ),
        txt(_txt),
        alpha(_alpha)
    {
        assertMyth("EschPolyTxtAElement must have valid typ",
                   (_typ == ESCH_ELMNT_TXTPOLY_A)
                   || (_typ == ESCH_ELMNT_TXTPOLY_PERSP_A)
                   || (_typ == ESCH_ELMNT_GTXTPOLY_A)
                   || (_typ == ESCH_ELMNT_GTXTPOLY_PERSP_A));

        assertMyth("EschPolyTxtAElement needs valid input",
                   _count >= 3 && _vpoly != 0);

        count = (ushort)_count;
        memcpy(vpoly, _vpoly, _count * sizeof(VngoPointF));
        EschElementSize += sizeof(*this) + ((_count-1) * sizeof(VngoPointF));

        //ִִִ Set extents
        maxz = minz = _vpoly[0].z;
        maxx = minx = _vpoly[0].x;
        maxy = miny = _vpoly[0].y;
        for(_count--; _count >= 1; _count--)
        {
            if (_vpoly[_count].z > maxz)  maxz = _vpoly[_count].z;
            if (_vpoly[_count].z < minz)  minz = _vpoly[_count].z;
            if (_vpoly[_count].x > maxx)  maxx = _vpoly[_count].x;
            if (_vpoly[_count].x < minx)  minx = _vpoly[_count].x;
            if (_vpoly[_count].y > maxy)  maxy = _vpoly[_count].y;
            if (_vpoly[_count].y < miny)  miny = _vpoly[_count].y;
        }
    }

    virtual void draw();
    virtual void prepare_test(EschPoint *pt) const;
    virtual BOOL perform_test(const EschPoint *pt) const;
};


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" void esch_clipdraw_point(dword ctrlfl=ESCH_CDF_CLIP);
extern "C" void esch_clipdraw_line(VngoPointF *vpt2, dword ctrlfl=ESCH_CDF_CLIP);
extern "C" void esch_clipdraw_face(ulong ind, dword ctrlfl=ESCH_CDF_CLIP);

// Internal clip functions
extern "C" void esch_clip_poly(VngoVbuffer *vport,VngoPoint *points, ulong *n_vertices);
extern "C" void esch_zclip_poly(float hither, float yon,VngoPoint *points, ulong *n_vertices);
extern "C" void esch_clip_x_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern "C" void esch_clip_y_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern "C" void esch_clip_z_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);

class EschCamera;

// Internal rotate check functions
int esch_rotate_check(ulong count,VngoPoint2 *pts);
int esch_rotate_check(ulong count,VngoPoint *pts,EschCamera *cam=0);

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - eselemnt.hpp ²±°

