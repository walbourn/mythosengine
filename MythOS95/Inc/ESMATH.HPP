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
// esmath.hpp
//
//      EschPoint is a 3D point with an optional color, which can be operated
//      on in various ways including addition, transformation, and
//      rotation.
//
//      EschVector is a 3D vector which can be operated in various ways,
//      including addition, transformation, rotation, and forming dot/cross
//      products.
//
//      EschPlane is a 3D plane.
//
//      EschVertex is a 3D point with a normal.
//
//      EschMatrix is a special case 4x4 matrix where the last column is
//      always 0 0 0 1, resulting a 3x4 representation.
//
//      EschFrameRef is a 3x4 transform matrix with a direction vector, and
//      associated inverse transform matrix.  Includes utility routines
//      to perform various affine transformations.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ESMATH_HPP
#define __ESMATH_HPP    1

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

#include <math.h>

#include <portable.h>
#include <felix.hpp>

#include "esdefs.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define DOT    |
#define CROSS  &

//ÄÄ EschMatrix layout
//
// [A B C 0]
// [D E F 0]
// [G H I 0]
// [J K L 1]

#define ESCH_MTX_A      0
#define ESCH_MTX_B      1
#define ESCH_MTX_C      2
#define ESCH_MTX_D      3
#define ESCH_MTX_E      4
#define ESCH_MTX_F      5
#define ESCH_MTX_G      6
#define ESCH_MTX_H      7
#define ESCH_MTX_I      8
#define ESCH_MTX_J      9
#define ESCH_MTX_K      10
#define ESCH_MTX_L      11

#define ESCH_MTX_NUM    12

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class EschVector;
class EschMatrix;
class EschFrameRef;

//ÄÄ Point and vector operations
extern "C" void esch_rotatex(const void *s,const float deg, void *d);
extern "C" void esch_rotatey(const void *s,const float deg, void *d);
extern "C" void esch_rotatez(const void *s,const float deg, void *d);
extern "C" void esch_transform(const void *s,const EschMatrix *m, void *d);
extern "C" void esch_transform_notran(const void *s,const EschMatrix *m,
                                      void *d);

//ÄÄ Vector functions
extern "C" EschVector *esch_cross(const EschVector *v1,const EschVector *v2,
                                  EschVector *dest);
extern "C" float esch_dot(const EschVector *v1,const EschVector *v2);
extern "C" float esch_magnitude(const EschVector *vect);

//ÄÄ Matrix functions
extern "C" void esch_concatmatrix(const EschMatrix *s, const EschMatrix *m,
                                  EschMatrix *d);
extern "C" int esch_inversematrix(const EschMatrix *m, EschMatrix *d);
extern "C" float esch_detmatrix(const EschMatrix *m);

//ÄÄ Trig functions
inline float esch_sin(float degrees) { return float(sin(degrees * 0.017453292f)); }
inline float esch_cos(float degrees) { return float(cos(degrees * 0.017453292f)); }
inline float esch_tan(float degrees) { return float(tan(degrees * 0.017453292f)); }
inline float esch_asin(float n) { return (float(asin(n)) * 57.29577951f); }
inline float esch_acos(float n) { return (float(acos(n)) * 57.29577951f); }
inline float esch_atan(float n) { return (float(atan(n)) * 57.29577951f); }

//ÄÄ Misc functions
inline float esch_sqrt(float n) { return float(sqrt(n)); }

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPoint - 3D point (needs to match first three members of VngoPoint)   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschPoint {

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    float   x;                          // Must match VngoPoint.wx
    float   y;                          // Must match VngoPoint.wy
    float   z;                          // Must match VngoPoint.wz
    dword   na;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschPoint() {}
    EschPoint(float ix, float iy, float iz) : x(ix), y(iy), z(iz) {}

    ~EschPoint() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Arthimetic operators on points.                                      ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

    //ÄÄÄ Addition/Subtraction of points.
    EschPoint operator + (const EschPoint &b) const
    {
        return EschPoint(x + b.x,
                         y + b.y,
                         z + b.z);
    }

    EschPoint operator += (const EschPoint &b)
    {   
        x = x + b.x;
        y = y + b.y;
        z = z + b.z;
        return (*this);
    }

    EschPoint operator - (const EschPoint &b) const
    {
        return EschPoint(x - b.x,
                         y - b.y,
                         z - b.z);
    }

    EschPoint operator -= (const EschPoint &b)
    {
        x = x - b.x;
        y = y - b.y;
        z = z - b.z;
        return (*this);
    }

    //ÄÄÄ Negation
    EschPoint operator - () const
    {
        return EschPoint(-x,-y,-z);
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Transformation operations.                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void transform(const EschMatrix *m) 
    {
        ::esch_transform(this,m,this);
    }
    void transform(const EschFrameRef *m)
    {
        ::esch_transform(this,(EschMatrix *)m,this);
    }

    void transform(const EschMatrix *m, EschPoint *result) const
    {
        ::esch_transform(this,m,result);
    }
    void transform(const EschFrameRef *m, EschPoint *result) const
    {
        ::esch_transform(this,(EschMatrix *)m,result);
    }

    void rotatex(const float degrees)
    {
        ::esch_rotatex(this,degrees,this);
    }
    void rotatex(const float degrees, EschPoint *result) const
    {
        ::esch_rotatex(this,degrees,result);
    }

    void rotatey(const float degrees)
    {
        ::esch_rotatey(this,degrees,this);
    }
    void rotatey(const float degrees, EschPoint *result) const
    {
        ::esch_rotatey(this,degrees,result);
    }

    void rotatez(const float degrees)
    {
        ::esch_rotatez(this,degrees,this);
    }
    void rotatez(const float degrees, EschPoint *result) const
    {
        ::esch_rotatez(this,degrees,result);
    }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschVector - 3D i,j,k vector.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschVector {

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    float   i;
    float   j;
    float   k;
    dword   na;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschVector() {}
    EschVector(float ii, float ij, float ik) : i(ii), j(ij), k(ik) {}

    ~EschVector() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Arthimetic operations on vectors                                     ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

    //ÄÄÄ Addition/Subtraction of vectors.
    EschVector operator + (const EschVector &b) const
    {
        return EschVector(i + b.i,
                          j + b.j,
                          k + b.k);
    }
    EschVector operator += (const EschVector &b)
    {   
        i = i + b.i;
        j = j + b.j;
        k = k + b.k;
        return (*this);
    }

    EschVector operator - (const EschVector &b) const
    {
        return EschVector(i - b.i,
                          j - b.j,
                          k - b.k);
    }
    EschVector operator -= (const EschVector &b)
    {   
        i = i - b.i;
        j = j - b.j;
        k = k - b.k;
        return (*this);
    }

    //ÄÄÄ Negation
    EschVector operator - () const
    {
        return EschVector(-i,-j,-k);
    }

    //ÄÄÄ Addition/Subtraction with a scalar.
    EschVector operator + (const float scalar) const
    {
        return EschVector(i + scalar,
                          j + scalar,
                          k + scalar);
    }
    EschVector operator += (const float scalar)
    {   
        i = i + scalar;
        j = j + scalar;
        k = k + scalar;
        return (*this);
    }

    EschVector operator - (const float scalar) const
    {
        return EschVector(i - scalar,
                          j - scalar,
                          k - scalar);
    }
    EschVector operator -= (const float scalar)
    {   
        i = i - scalar;
        j = j - scalar;
        k = k - scalar;
        return (*this);
    }

    //ÄÄÄ Multiplication/Division by a scalar.
    EschVector operator * (const float scalar) const
    {
        return EschVector(i * scalar,
                          j * scalar,
                          k * scalar);
    }

    EschVector operator *= (const float scalar)
    {
        i = i * scalar;
        j = j * scalar;
        k = k * scalar;
        return (*this);
    }

    EschVector operator / (const float scalar) const
    {
        return EschVector(i / scalar,
                          j / scalar,
                          k / scalar);
    }

    EschVector operator /= (const float scalar)
    {
        i = i / scalar;
        j = j / scalar;
        k = k / scalar;
        return (*this);
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Vector operations                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

    EschVector operator CROSS (const EschVector &v) const
    {
        EschVector result;
        return (*::esch_cross(this,&v,&result));
    }

    float operator DOT (const EschVector &v) const
    {
        return (::esch_dot(this,&v));
    }

    float magnitude() const { return (esch_magnitude(this));}

    void normalize() 
    {
        float   mag;
        mag = magnitude();

#ifdef assertMyth
        assertMyth("EschVector::normalize found magnitude of zero",
                   mag > 0);
#endif

        if (mag)    // can't normalize a vector of magnitude 0.
        {
            i = i / mag;
            j = j / mag;
            k = k / mag;
        }
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Transformation operations                                            ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

    //ÄÄÄ Scale vector
    void scale(float scale)
    {
        i = i * scale;
        j = j * scale;
        k = k * scale;
    }        

    //ÄÄÄ Translate vector
    void translate(float ix, float iy, float iz)
    {
        i = i + ix;
        j = j + iy;
        k = k + iz; 
    }
    void translate(const EschVector *v)
    {
        i = i + v->i;
        j = j + v->j;
        k = k + v->k; 
    }

    //ÄÄÄ Transform by a matrix
    void transform(const EschMatrix *m)
    {
        ::esch_transform_notran(this,m,this);
    }
    void transform(const EschFrameRef *m)
    {
        ::esch_transform_notran(this,(EschMatrix *)m,this);
    }

    void transform(const EschMatrix *m, EschVector *result) const
    {
        ::esch_transform_notran(this,m,result);
    }
    void transform(const EschFrameRef *m, EschVector *result) const
    {
        ::esch_transform_notran(this,(EschMatrix *)m,result);
    }

    //ÄÄÄ Rotate vector
    void rotatex(const float degrees)
    {
        ::esch_rotatex(this,degrees,this);
    }
    void rotatex(const float degrees, EschVector *result) const
    {
        ::esch_rotatex(this,degrees,result);
    }

    void rotatey(const float degrees)
    {
        ::esch_rotatey(this,degrees,this);
    }
    void rotatey(const float degrees, EschVector *result) const
    {
        ::esch_rotatey(this,degrees,result);
    }

    void rotatez(const float degrees)
    {
        ::esch_rotatez(this,degrees,this);
    }
    void rotatez(const float degrees, EschVector *result) const
    {
        ::esch_rotatez(this,degrees,result);
    }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlane - 3D plane.                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschPlane {

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschVector  normal;
    float       dist;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschPlane() {}
    EschPlane(float ia, float ib, float ic, float id) :
        normal(ia,ib,ic), dist(id) {}

    ~EschPlane() {}
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschVertex - A 3D point and a normal at the point.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschVertex : public EschPoint {

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data member                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschVector  normal;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschVertex() {}
    EschVertex(float ix, float iy, float iz,
               float ii, float ij, float ik)
               : EschPoint(ix,iy,iz), normal(ii,ij,ik) {}
    EschVertex(float ix, float iy, float iz, const EschVector *n)
               : EschPoint(ix,iy,iz) { normal=*n; }
    EschVertex(const EschPoint *p, const EschVector *n)
               : EschPoint(*p) { normal=*n; }
    EschVertex(const EschPoint *p, float ii, float ij, float ik)
               : EschPoint(*p), normal(ii,ij,ik) {}

    ~EschVertex() {}
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMatrix - A matrix is a 4x3 homogenous matrix.                        ³
//                                                                          ³
// [A B C 0]                                                                ³
// [D E F 0]                                                                ³
// [G H I 0]                                                                ³
// [J K L 1]                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschMatrix {

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data member                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    float   mtx[3*4];

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschMatrix() { reset(); }
    EschMatrix(int dummy) {}
    EschMatrix(float a, float b, float c, float d, float e, float f,
               float g, float h, float i, float j, float k, float l)
               { mtx[ESCH_MTX_A]=a; mtx[ESCH_MTX_B]=b; mtx[ESCH_MTX_C]=c;
                 mtx[ESCH_MTX_D]=d; mtx[ESCH_MTX_E]=e; mtx[ESCH_MTX_F]=f;
                 mtx[ESCH_MTX_G]=g; mtx[ESCH_MTX_H]=h; mtx[ESCH_MTX_I]=i;
                 mtx[ESCH_MTX_J]=j; mtx[ESCH_MTX_K]=k; mtx[ESCH_MTX_L]=l; }

    ~EschMatrix() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Arthimetic operations on matricies                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

    //ÄÄÄ Multiplication by a matrix.
    EschMatrix operator * (const EschMatrix &b) const
    {
        EschMatrix m;
        ::esch_concatmatrix(this,&b,&m);
        return m;
    }
    EschMatrix operator *= (const EschMatrix &b)
    {
        ::esch_concatmatrix(this,&b,this);
        return (*this);
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations on matrix objects.                                        ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

    //ÄÄÄ Matrix math operations
    void concat(const EschMatrix *m)
    {
        ::esch_concatmatrix(this,m,this);
    }
    void concat(const EschMatrix *m, EschMatrix *result) const
    {
        ::esch_concatmatrix(this,m,result);
    }

    float det() { return (esch_detmatrix(this)); }

    int inverse() { return ::esch_inversematrix(this,this); }
    int inverse(EschMatrix *result) const
    {
        return ::esch_inversematrix(this,result);
    }

    //ÄÄÄ Reset to identity.
    void reset()
    {
        for(int i=0; i < ESCH_MTX_NUM; i++)
            mtx[i]=0;
        mtx[ESCH_MTX_A]=mtx[ESCH_MTX_E]=mtx[ESCH_MTX_I]=1;
    }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - Frame of reference                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschFrameRef {

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschMatrix      orient;                 // Transform matrix
    EschVector      dir;
    EschMatrix      iorient;                // Inverse matrix
    float           scalef;                 // Scale factor (saved for
                                            // orthogonalization)
    dword           ortho_count;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschFrameRef() : orient(), iorient(), dir(0,0,1),
                     scalef(1), ortho_count(0) {}
    EschFrameRef(int dummy) : orient(0), iorient(0) {};
    EschFrameRef(float a, float b, float c, float d, float e, float f,
                 float g, float h, float i, float j, float k, float l,
                 float s=1) :
                dir(g,h,i), scalef(s), ortho_count(0)
    {
        orient.mtx[ESCH_MTX_A]=a; orient.mtx[ESCH_MTX_D]=d;
        orient.mtx[ESCH_MTX_B]=b; orient.mtx[ESCH_MTX_E]=e;
        orient.mtx[ESCH_MTX_C]=c; orient.mtx[ESCH_MTX_F]=f;
        orient.mtx[ESCH_MTX_G]=g; orient.mtx[ESCH_MTX_J]=j; 
        orient.mtx[ESCH_MTX_H]=h; orient.mtx[ESCH_MTX_K]=k; 
        orient.mtx[ESCH_MTX_I]=i; orient.mtx[ESCH_MTX_L]=l; 
        compute_inverse();
    }
    EschFrameRef(EschMatrix *m, float s=1) :
                scalef(s), ortho_count(0)
    {
        orient=*m;
        dir.i=m->mtx[ESCH_MTX_G];
        dir.j=m->mtx[ESCH_MTX_H];
        dir.k=m->mtx[ESCH_MTX_I];
        compute_inverse();
    }

    ~EschFrameRef() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions for working with frames of reference.              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void get_position(EschPoint *pt) const 
    {
        pt->x = orient.mtx[ESCH_MTX_J];
        pt->y = orient.mtx[ESCH_MTX_K];
        pt->z = orient.mtx[ESCH_MTX_L];
    }
    void get_position(float *ix, float *iy, float *iz) const
    {
        *ix = orient.mtx[ESCH_MTX_J];
        *iy = orient.mtx[ESCH_MTX_K];
        *iz = orient.mtx[ESCH_MTX_L];
    }

    void set_position(const EschPoint *pt, dword update=ESCH_UPD_ALL);
    void set_position(const float ix, const float iy, const float iz,
                      dword update=ESCH_UPD_ALL);

    void rotatex(const float degrees, dword update=ESCH_UPD_ALL);
    void rotatey(const float degrees, dword update=ESCH_UPD_ALL);
    void rotatez(const float degrees, dword update=ESCH_UPD_ALL);

    void rotate(const EschVector *v, const float degrees,
                dword update=ESCH_UPD_ALL);

    void pitch(const float degrees, dword update=ESCH_UPD_ALL);
    void roll(const float degrees, dword update=ESCH_UPD_ALL);
    void yaw(const float degrees, dword update=ESCH_UPD_ALL);

    void translate(const EschVector *v, dword update=ESCH_UPD_ALL);
    void translate(const float idx, const float idy, const float idz,
                   dword update=ESCH_UPD_ALL);

    void move(const EschVector *v, dword update=ESCH_UPD_ALL);
    void move(const float idx, const float idy, const float idz,
              dword update=ESCH_UPD_ALL);

    void scale(const float is, dword update=ESCH_UPD_ALL);

    void orthogonalize(dword update=ESCH_UPD_ALL);
    void orthogonalize_top(dword update=ESCH_UPD_ALL);
    void orthogonalize_right(dword update=ESCH_UPD_ALL);

    void concat(const EschFrameRef *m);
    void concat(const EschFrameRef *m, EschFrameRef *result) const;

    void reset();

    void compute_inverse();
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esmath.hpp ²±°

