//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
// _________________________________________________________________________
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// |       1       2       3       4       5       6       7       8       9
// |                                                                       |
// |              E U L E R:   Math and Computation Library                |
// |_______________________________________________________________________|
//
//                      Microsoft Windows 95/NT Version
//
//               Copyright (c) 1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
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
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PbROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Matthew Lamari
//
// elrquat.hpp
//
// Contains the class definitions for the vector data types:
//
//  ElrVector2D is a 2-dimensional vector
//
//  ElrVector2DW is a 2-dimensional vector with a homogeneous w value
//
//  ElrVector3D is a 3-dimensional vector
//
//  ElrVector3DW is a 3-dimensional vector with a homogeneous w value
//
//  ElrVector is a generic n-length vector
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ELRQUAT_HPP
#define __ELRQUAT_HPP   1

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

#include "elrmath.hpp"
#include "elrpoint.hpp"
#include "elrbasis.hpp"
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°




class ElrQuaternion
{
public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Public data members
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    float   s;
    float   i;
    float   j;
    float   k;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Contructors/Destructors
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    ElrQuaternion() {}
    ElrQuaternion(const ElrVector3D &v, float degrees)
    {
        s = elr_cos(degrees / 2);
        ElrVector3D vp = v;
        vp.normalize();
        float sn = elr_sin(degrees / 2);
        i = vp.i * sn;
        j = vp.j * sn;
        k = vp.k * sn;
    }

    ElrQuaternion(float _s, float _i, float _j, float _k) :
        s(_s), i(_i), j(_j), k(_k) {}

    ~ElrQuaternion() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Arithmetic operations
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

    //ÄÄÄ Addition/Subtraction
    ElrQuaternion operator + (const ElrQuaternion &b) const
    {
        return ElrQuaternion(s + b.s, i + b.i, j + b.j, k + b.k);
    }
    ElrQuaternion operator += (const ElrQuaternion &b)
    {
        s = s + b.s;
        i = i + b.i;
        j = j + b.j;
        k = k + b.k;
        return (*this);
    }

    ElrQuaternion operator - (const ElrQuaternion &b) const
    {
        return ElrQuaternion(s - b.s, i - b.i, j - b.j, k - b.k);
    }
    ElrQuaternion operator -= (const ElrQuaternion &b)
    {
        s = s - b.s;
        i = i - b.i;
        j = j - b.j;
        k = k - b.k;
        return (*this);
    }

    //ÄÄÄ Negation
    ElrQuaternion operator - () const
    {
        return ElrQuaternion(-s,-i,-j,-k);
    }

    //ÄÄÄ Addition/Subtraction with a scalar.
    ElrQuaternion operator + (const float scalar) const
    {
        return ElrQuaternion(s + scalar, i + scalar, j + scalar, k + scalar);
    }
    ElrQuaternion operator += (const float scalar)
    {
        s = s + scalar;
        i = i + scalar;
        j = j + scalar;
        k = k + scalar;
        return (*this);
    }

    ElrQuaternion operator - (const float scalar) const
    {
        return ElrQuaternion(s - scalar, i - scalar, j - scalar, k - scalar);
    }
    ElrQuaternion operator -= (const float scalar)
    {
        s = s - scalar;
        i = i - scalar;
        j = j - scalar;
        k = k - scalar;
        return (*this);
    }

    //ÄÄÄ Multiplication/Division by a scalar.
    ElrQuaternion operator * (const float scalar) const
    {
        return ElrQuaternion(s * scalar, i * scalar, j * scalar, k * scalar);
    }


    ElrQuaternion operator *= (const float scalar)
    {
        s = s * scalar;
        i = i * scalar;
        j = j * scalar;
        k = k * scalar;
        return (*this);
    }

    ElrQuaternion operator * (const ElrQuaternion & q)
    {
        ElrQuaternion r;

        r.s = s * q.s - ( *((ElrVector3D *) & i) DOT *((ElrVector3D *) &(q.i)) );
        ElrVector3D v = ElrVector3D( (j*q.k) - (k*q.j), (k*q.i) - (i*q.k), (i*q.j) - (j*q.i) )
            + ElrVector3D(s * q.i, s * q.j, s * q.k) + ElrVector3D(q.s * i, q.s * j, q.s * k);
        r.i = v.i;
        r.j = v.j;
        r.k = v.k;

        return r;
    }

    ElrQuaternion operator *= (const ElrQuaternion & q)
    {
        *this = *this * q;
        return *this;
    }



    ElrQuaternion operator / (const float scalar) const
    {
        assertMyth("ElrVector3D::operator / needs valid scalar",
                   scalar != 0);

        return ElrQuaternion(s / scalar, i / scalar, j / scalar, k / scalar);
    }

    ElrQuaternion operator /= (const float scalar)
    {
        assertMyth("ElrVector3D::operator /= needs valid scalar",
                   scalar != 0);

        s = s / scalar;
        i = i / scalar;
        j = j / scalar;
        k = k / scalar;
        return (*this);
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Operations
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    float operator DOT (const ElrQuaternion &v) const
    {
        return ((s * v.s) + (i*v.i) + (j*v.j) + (k*v.k));
    }

    float magnitude() const { return elr_sqrt((s * s) + (i*i) + (j*j) + (k*k)); }



    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Transformation operations
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

    //ÄÄÄ Scale vector
    void scale(float scale)
    {
        s = s * scale;
        i = i * scale;
        j = j * scale;
        k = k * scale;
    }
    void scale(float scale, ElrQuaternion &result) const
    {
        result.s = s * scale;
        result.i = i * scale;
        result.j = j * scale;
        result.k = k * scale;
    }

    //ÄÄÄ Rotate
    void rotatex(const float degrees)
    {
        // i' = i
        // j' = j * c + k * s
        // k' = k * c - j * s

        float sn = elr_sin(degrees);
        float cn = elr_cos(degrees);

        float nj = j*cn + k*sn;
        float nk = k*cn - j*sn;

        j = nj;
        k = nk;
    }
    void rotatex(const float degrees, ElrQuaternion &result) const
    {
        // i' = i
        // j' = j * c + k * s
        // k' = k * c - j * s

        float sn = elr_sin(degrees);
        float cn = elr_cos(degrees);

        result.i = i;
        result.j = j*cn + k*sn;
        result.k = k*cn - j*sn;
    }

    void rotatey(const float degrees)
    {
        // i' = i * c - k * s
        // j' = j
        // k' = i * s + k * c

        float sn = elr_sin(degrees);
        float cn = elr_cos(degrees);

        float ni = i*cn - k*sn;
        float nk = i*sn + k*cn;

        i = ni;
        k = nk;
    }
    void rotatey(const float degrees, ElrVector3D &result) const
    {
        // i' = i * c - k * s
        // j' = j
        // k' = i * s + k * c

        float sn = elr_sin(degrees);
        float cn = elr_cos(degrees);

        result.i = i*cn - k*sn;
        result.j = j;
        result.k = i*sn + k*cn;
    }

    void rotatez(const float degrees)
    {
        // i' = i * c + j * s
        // j' = j * c - i * s
        // k' = k

        float sn = elr_sin(degrees);
        float cn = elr_cos(degrees);

        float ni = i*cn + j*sn;
        float nj = j*cn - i*sn;

        i = ni;
        j = nj;
    }
    void rotatez(const float degrees, ElrVector3D &result) const
    {
        // i' = i * c + j * s
        // j' = j * c - i * s
        // k' = k

        float sn = elr_sin(degrees);
        float cn = elr_cos(degrees);

        result.i = i*cn + j*sn;
        result.j = j*cn - i*sn;
        result.k = k;
    }

    void apply(ElrMatrix3D * m) const
    {
    	float xs,ys,zs,wx,wy,wz,xx,xy,xz,yy,yz,zz;

	    xs = i * 2.0f;
	    ys = j * 2.0f;
	    zs = k * 2.0f;
	    wx = s * xs;
	    wy = s * ys;
	    wz = s * zs;
	    xx = i * xs;
	    xy = i * ys;
	    xz = i * zs;
	    yy = j * ys;
	    yz = j * zs;
	    zz = k * zs;
	    m->mtx[0] = ((1.0f) - (yy + zz));
	    m->mtx[1] = (xy + wz);
	    m->mtx[2] = (xz - wy);
	    m->mtx[4] = float(xy - wz);
	    m->mtx[5] = float(float(1.0) - (xx + zz));
	    m->mtx[6] = float(yz + wx);
	    m->mtx[8] = float(xz + wy);
	    m->mtx[9] = float(yz - wx);
	    m->mtx[10] = float(float(1.0) - (xx + yy));
    }

};


inline ElrQuaternion slerp(const ElrQuaternion & a, const ElrQuaternion b, float t)
{
    float angle = elr_acos(a DOT b);

    float sn = elr_sin(angle);

    if (sn == 0)
    {   // they're the same, or at same rel. to start.
        return a;
    }
    
    ElrQuaternion r;
    float oos = 1.0f / sn;

    float sa = elr_sin(angle * (1-t));
    float sb = elr_sin(angle * t);

    r.s = (a.s * sa + b.s * sb) * oos;
    r.i = (a.i * sa + b.i * sb) * oos;
    r.j = (a.j * sa + b.j * sb) * oos;
    r.k = (a.k * sa + b.k * sb) * oos;


    return r;
}






#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - elrquat.hpp ²±°
