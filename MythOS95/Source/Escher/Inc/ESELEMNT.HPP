//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Tim Little & Chuck Walbourn
//
// eselemnt.hpp
//
// Contains the primtive output routines and support classes for both
// sorted and Z-buffer based drawing.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESELEMNT_HPP
#define __ESELEMNT_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <vangogh.hpp>

#include "esdefs.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

extern ulong EschElementSize;
class EschTexture;
class EschPoint;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschElement - Base class for sort elements.                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschElement
{
protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected draw function for tree recursion                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructor                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschElement(word _typ) :
        typ(_typ),
        left(0),
        right(0)
    {}
    ~EschElement() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual void insert();
    virtual void draw()=0;
    virtual void prepare_test(EschPoint *pt) const =0;
    virtual BOOL perform_test(const EschPoint *pt) const =0 ;

    static void flush();
    static void flush_truesort();
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPixelElement - Pixel element.                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLineElement - Line element.                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyElement - Polygon element.                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

        //陳� Set extents
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyAElement - Polygon with alpha element.                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

        //陳� Set extents
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyTxtElement - Textured polygon element.                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

        //陳� Set extents
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyTxtAElement - Textured polygon with alpha element.               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

        //陳� Set extents
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


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Prototypes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

extern "C" void esch_clipdraw_point(dword ctrlfl=ESCH_CDF_CLIP);
extern "C" void esch_clipdraw_line(VngoPointF *vpt2, dword ctrlfl=ESCH_CDF_CLIP);
extern "C" void esch_clipdraw_face(ulong ind, dword ctrlfl=ESCH_CDF_CLIP);

class EschCamera;
class EschPlane;

// Internal clip functions

#if 1
extern "C" int esch_clip_to_frustrum (ulong *count, VngoPointF3 *pts, VngoPointF3 *outpts,
                                      EschCamera *cam, dword level);
extern "C" int esch_clip_to_plane(int *count, VngoPointF3 *in, VngoPointF3 *out,
                                  EschPlane *plane, dword level);
#else
extern "C" int esch_clip_to_frustrum (ulong *count, VngoPoint *pts,
                                      VngoPoint *outpts,
                                      EschCamera *cam, dword level);
extern "C" int esch_clip_to_plane(int *count, VngoPoint *in, VngoPoint *out,
                                  EschPlane *plane, dword level);
#endif

// Internal rotate check functions
int esch_rotate_check(ulong count,VngoPoint2 *pts);
int esch_rotate_check(ulong count,VngoPoint *pts,EschCamera *cam=0);

int esch_rotate_check(ulong count, VngoPointF3 *pts);
int esch_rotate_check(ulong count, VngoPointF3 *pts, EschCamera *cam=0);

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - eselemnt.hpp 憶�

