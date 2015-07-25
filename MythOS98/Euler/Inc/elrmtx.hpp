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
// Created by Chuck Walbourn
//
// elrmtx.hpp
//
// Contains the class definitions for the matrix data types:
//
//  ElrMatrix2D is a 3x3 matrix for transforming in 2D homongenous space
//
//  ElrMartix3D is a 4x4 matrix for transforming in 3D homongenous space
//
//  ElrMatrix is a generic m by n matrix
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ELRMTX_HPP
#define __ELRMTX_HPP   1

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
#include "elrvect.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define ELR_MTX2D_A     0
#define ELR_MTX2D_D     1
#define ELR_MTX2D_G     2
#define ELR_MTX2D_B     3
#define ELR_MTX2D_E     4
#define ELR_MTX2D_H     5
#define ELR_MTX2D_C     6
#define ELR_MTX2D_F     7
#define ELR_MTX2D_I     8
#define ELR_MTX2D_MAX   9

#define ELR_MTX3D_A     0
#define ELR_MTX3D_E     1
#define ELR_MTX3D_I     2
#define ELR_MTX3D_M     3
#define ELR_MTX3D_B     4
#define ELR_MTX3D_F     5
#define ELR_MTX3D_J     6
#define ELR_MTX3D_N     7
#define ELR_MTX3D_C     8
#define ELR_MTX3D_G     9
#define ELR_MTX3D_K     10
#define ELR_MTX3D_O     11
#define ELR_MTX3D_D     12
#define ELR_MTX3D_H     13
#define ELR_MTX3D_L     14
#define ELR_MTX3D_P     15
#define ELR_MTX3D_MAX   16

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ElrMatrix2D - 3x3 matrix
//
// [A B C]      stored as [A D G B E H C F I]
// [D E F]
// [G H I]
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class ElrMatrix2D
{
public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Public data members
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    float   mtx[ELR_MTX2D_MAX];

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Contructors/Destructors
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    ElrMatrix2D() {}
    ElrMatrix2D(int c)
    {
        if (c == 1)
            identity();
        else
            zero();
    }
    ElrMatrix2D(float _a, float _b, float _c,
                float _d, float _e, float _f,
                float _g, float _h, float _i)
    {
        mtx[ELR_MTX2D_A] = _a;  mtx[ELR_MTX2D_D] = _d;  mtx[ELR_MTX2D_G] = _g;
        mtx[ELR_MTX2D_B] = _b;  mtx[ELR_MTX2D_E] = _e;  mtx[ELR_MTX2D_H] = _h;
        mtx[ELR_MTX2D_C] = _c;  mtx[ELR_MTX2D_F] = _f;  mtx[ELR_MTX2D_I] = _i;
    }

    ~ElrMatrix2D() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Arithmetic operations
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

    //ÄÄÄ Addition/Subtraction
    ElrMatrix2D operator + (const ElrMatrix2D &b) const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = mtx[i] + b.mtx[i];
        return r;
    }
    ElrMatrix2D operator += (const ElrMatrix2D &b)
    {
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            mtx[i] = mtx[i] + b.mtx[i];
        return (*this);
    }

    ElrMatrix2D operator - (const ElrMatrix2D &b) const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = mtx[i] - b.mtx[i];
        return r;
    }
    ElrMatrix2D operator -= (const ElrMatrix2D &b)
    {
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            mtx[i] = mtx[i] - b.mtx[i];
        return (*this);
    }

    //ÄÄÄ Negation
    ElrMatrix2D operator - () const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = - mtx[i];
        return r;
    }

    //ÄÄÄ Addition/Subtraction with a scalar.
    ElrMatrix2D operator + (const float scalar) const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = mtx[i] + scalar;
        return r;
    }
    ElrMatrix2D operator += (const float scalar)
    {
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            mtx[i] = mtx[i] + scalar;
        return (*this);
    }

    ElrMatrix2D operator - (const float scalar) const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = mtx[i] - scalar;
        return r;
    }
    ElrMatrix2D operator -= (const float scalar)
    {
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            mtx[i] = mtx[i] - scalar;
        return (*this);
    }

    //ÄÄÄ Multiplication/Division by a scalar.
    ElrMatrix2D operator * (const float scalar) const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = mtx[i] * scalar;
        return r;
    }
    ElrMatrix2D operator *= (const float scalar)
    {
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            mtx[i] = mtx[i] * scalar;
        return (*this);
    }

    ElrMatrix2D operator / (const float scalar) const
    {
        assertMyth("ElrMatrix2D::operator / needs valid scalar",
                   scalar != 0);

        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = mtx[i] / scalar;
        return r;
    }
    ElrMatrix2D operator /= (const float scalar)
    {
        assertMyth("ElrMatrix2D::operator /= needs valid scalar",
                   scalar != 0);

        for(int i=0; i < ELR_MTX2D_MAX; i++)
            mtx[i] = mtx[i] / scalar;
        return (*this);
    }

    //ÄÄÄ Logical (binary) matrix operations
    ElrMatrix2D operator & (const ElrMatrix2D &b) const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = (mtx[i] != 0) && (b.mtx[i] != 0);
        return r;
    }
    ElrMatrix2D operator &= (const ElrMatrix2D &b)
    {
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            mtx[i] = (mtx[i] != 0) && (b.mtx[i] != 0);
        return (*this);
    }
    ElrMatrix2D operator | (const ElrMatrix2D &b) const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = (mtx[i] != 0) || (b.mtx[i] != 0);
        return r;
    }
    ElrMatrix2D operator |= (const ElrMatrix2D &b)
    {
        for(int i=0; i < ELR_MTX2D_MAX; i++)
             mtx[i] = (mtx[i] != 0) || (b.mtx[i] != 0);
        return (*this);
    }
    ElrMatrix2D operator ! () const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = !(mtx[i] != 0);
        return r;
    }

    //ÄÄÄ Pointwise multiplication and division by a matrix.
    ElrMatrix2D dot_mul(const ElrMatrix2D &b) const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            r.mtx[i] = mtx[i] * b.mtx[i];
        return r;
    }
    ElrMatrix2D dot_muleq(const ElrMatrix2D &b)
    {
        for(int i=0; i < ELR_MTX2D_MAX; i++)
            mtx[i] = mtx[i] * b.mtx[i];
        return (*this);
    }

    ElrMatrix2D dot_div(const ElrMatrix2D &b) const
    {
        ElrMatrix2D r;
        for(int i=0; i < ELR_MTX2D_MAX; i++)
        {
            assertMyth("ElrMatrix2D::dot_div() needs valid input",
                       b.mtx[i] != 0.0f);

            r.mtx[i] = mtx[i] / b.mtx[i];
        }
        return r;
    }
    ElrMatrix2D dot_diveq(const ElrMatrix2D &b)
    {
        for(int i=0; i < ELR_MTX2D_MAX; i++)
        {
            assertMyth("ElrMatrix2D::dot_diveq() needs valid input",
                       b.mtx[i] != 0.0f);

            mtx[i] = mtx[i] / b.mtx[i];
        }
        return (*this);
    }

    //ÄÄÄ Multiplication by a matrix.
    ElrMatrix2D operator * (const ElrMatrix2D &b) const
    {
        ElrMatrix2D m;
        ::elr_concatmatrix2d(this,&b,&m);
        return m;
    }
    ElrMatrix2D operator *= (const ElrMatrix2D &b)
    {
        ::elr_concatmatrix2d(this,&b,this);
        return (*this);
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Operations
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

    //ÄÄÄ Matrix math operations
    void concat(const ElrMatrix2D &m, int hn=0)
    {
        ::elr_concatmatrix2d(this,&m,this,hn);
    }
    void concat(const ElrMatrix2D &m, ElrMatrix2D &result, int hn=0) const
    {
        ::elr_concatmatrix2d(this,&m,&result,hn);
    }

    float det() const;

    void transpose()
    {
        ElrMatrix2D m = *this;

        mtx[ELR_MTX2D_A] = m.mtx[ELR_MTX2D_A];
        mtx[ELR_MTX2D_D] = m.mtx[ELR_MTX2D_B];
        mtx[ELR_MTX2D_G] = m.mtx[ELR_MTX2D_C];
        mtx[ELR_MTX2D_B] = m.mtx[ELR_MTX2D_D];
        mtx[ELR_MTX2D_E] = m.mtx[ELR_MTX2D_E];
        mtx[ELR_MTX2D_H] = m.mtx[ELR_MTX2D_F];
        mtx[ELR_MTX2D_C] = m.mtx[ELR_MTX2D_G];
        mtx[ELR_MTX2D_F] = m.mtx[ELR_MTX2D_H];
        mtx[ELR_MTX2D_I] = m.mtx[ELR_MTX2D_I];
    }
    void transpose(ElrMatrix2D &result) const
    {
        result.mtx[ELR_MTX2D_A] = mtx[ELR_MTX2D_A];
        result.mtx[ELR_MTX2D_D] = mtx[ELR_MTX2D_B];
        result.mtx[ELR_MTX2D_G] = mtx[ELR_MTX2D_C];
        result.mtx[ELR_MTX2D_B] = mtx[ELR_MTX2D_D];
        result.mtx[ELR_MTX2D_E] = mtx[ELR_MTX2D_E];
        result.mtx[ELR_MTX2D_H] = mtx[ELR_MTX2D_F];
        result.mtx[ELR_MTX2D_C] = mtx[ELR_MTX2D_G];
        result.mtx[ELR_MTX2D_F] = mtx[ELR_MTX2D_H];
        result.mtx[ELR_MTX2D_I] = mtx[ELR_MTX2D_I];
    }

    void adjoint(int hn=0) { ::elr_adjointmatrix2d(this,this,hn); }
    void adjoint(ElrMatrix2D &result, int hn=0) const
    {
        ::elr_adjointmatrix2d(this,&result,hn);
    }

    int inverse(int hn=0) { return ::elr_inversematrix2d(this,this,hn); }
    int inverse(ElrMatrix2D &result, int hn=0) const
    {
        return ::elr_inversematrix2d(this,&result,hn);
    }

    //ÄÄÄ Special matricies
    void identity()
    {
        memset(mtx,0,sizeof(mtx));
        mtx[ELR_MTX2D_A]=mtx[ELR_MTX2D_E]=mtx[ELR_MTX2D_I]=1.0f;
    }

    void zero() { memset(mtx,0,sizeof(mtx)); }

    void one() { for(int i=0; i < ELR_MTX2D_MAX; i++)  mtx[i] = 1.0f; }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ElrMatrix3D - 4x4 matrix
//
// [A B C D]    stored as [A E I M B F J N C G K O D H L P]
// [E F G H]
// [I J K L]
// [M N O P]
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class ElrMatrix3D
{
public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Public data members
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    float   mtx[ELR_MTX3D_MAX];

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Contructors/Destructors
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

    ElrMatrix3D(const class ElrQuaternion &);
    ElrMatrix3D() {}
    ElrMatrix3D(int c)
    {
        if (c == 1)
            identity();
        else
            zero();
    }
    ElrMatrix3D(float _a, float _b, float _c, float _d,
                float _e, float _f, float _g, float _h,
                float _i, float _j, float _k, float _l,
                float _m, float _n, float _o, float _p)
    {
        mtx[ELR_MTX3D_A] = _a;  mtx[ELR_MTX3D_E] = _e;
        mtx[ELR_MTX3D_I] = _i;  mtx[ELR_MTX3D_M] = _m;
        mtx[ELR_MTX3D_B] = _b;  mtx[ELR_MTX3D_F] = _f;
        mtx[ELR_MTX3D_J] = _j;  mtx[ELR_MTX3D_N] = _n;
        mtx[ELR_MTX3D_C] = _c;  mtx[ELR_MTX3D_G] = _g;
        mtx[ELR_MTX3D_K] = _k;  mtx[ELR_MTX3D_O] = _o;
        mtx[ELR_MTX3D_D] = _d;  mtx[ELR_MTX3D_H] = _h;
        mtx[ELR_MTX3D_L] = _l;  mtx[ELR_MTX3D_P] = _p;
    }

    ~ElrMatrix3D() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Arithmetic operations
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

    //ÄÄÄ Addition/Subtraction
    ElrMatrix3D operator + (const ElrMatrix3D &b) const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = mtx[i] + b.mtx[i];
        return r;
    }
    ElrMatrix3D operator += (const ElrMatrix3D &b)
    {
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            mtx[i] = mtx[i] + b.mtx[i];
        return (*this);
    }

    ElrMatrix3D operator - (const ElrMatrix3D &b) const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = mtx[i] - b.mtx[i];
        return r;
    }
    ElrMatrix3D operator -= (const ElrMatrix3D &b)
    {
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            mtx[i] = mtx[i] - b.mtx[i];
        return (*this);
    }

    //ÄÄÄ Negation
    ElrMatrix3D operator - () const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = - mtx[i];
        return r;
    }

    //ÄÄÄ Addition/Subtraction with a scalar.
    ElrMatrix3D operator + (const float scalar) const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = mtx[i] + scalar;
        return r;
    }
    ElrMatrix3D operator += (const float scalar)
    {
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            mtx[i] = mtx[i] + scalar;
        return (*this);
    }

    ElrMatrix3D operator - (const float scalar) const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = mtx[i] - scalar;
        return r;
    }
    ElrMatrix3D operator -= (const float scalar)
    {
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            mtx[i] = mtx[i] - scalar;
        return (*this);
    }

    //ÄÄÄ Multiplication/Division by a scalar.
    ElrMatrix3D operator * (const float scalar) const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = mtx[i] * scalar;
        return r;
    }
    ElrMatrix3D operator *= (const float scalar)
    {
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            mtx[i] = mtx[i] * scalar;
        return (*this);
    }

    ElrMatrix3D operator / (const float scalar) const
    {
        assertMyth("ElrMatrix3D::operator / needs valid scalar",
                   scalar != 0);

        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = mtx[i] / scalar;
        return r;
    }
    ElrMatrix3D operator /= (const float scalar)
    {
        assertMyth("ElrMatrix3D::operator /= needs valid scalar",
                   scalar != 0);

        for(int i=0; i < ELR_MTX3D_MAX; i++)
            mtx[i] = mtx[i] / scalar;
        return (*this);
    }

    //ÄÄÄ Logical (binary) matrix operations
    ElrMatrix3D operator & (const ElrMatrix3D &b) const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = (mtx[i] != 0) && (b.mtx[i] != 0);
        return r;
    }
    ElrMatrix3D operator &= (const ElrMatrix3D &b)
    {
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            mtx[i] = (mtx[i] != 0) && (b.mtx[i] != 0);
        return (*this);
    }
    ElrMatrix3D operator | (const ElrMatrix3D &b) const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = (mtx[i] != 0) || (b.mtx[i] != 0);
        return r;
    }
    ElrMatrix3D operator |= (const ElrMatrix3D &b)
    {
        for(int i=0; i < ELR_MTX3D_MAX; i++)
             mtx[i] = (mtx[i] != 0) || (b.mtx[i] != 0);
        return (*this);
    }
    ElrMatrix3D operator ! () const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = !(mtx[i] != 0);
        return r;
    }

    //ÄÄÄ Pointwise multiplication and division by a matrix.
    ElrMatrix3D dot_mul(const ElrMatrix3D &b) const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            r.mtx[i] = mtx[i] * b.mtx[i];
        return r;
    }
    ElrMatrix3D dot_muleq(const ElrMatrix3D &b)
    {
        for(int i=0; i < ELR_MTX3D_MAX; i++)
            mtx[i] = mtx[i] * b.mtx[i];
        return (*this);
    }

    ElrMatrix3D dot_div(const ElrMatrix3D &b) const
    {
        ElrMatrix3D r;
        for(int i=0; i < ELR_MTX3D_MAX; i++)
        {
            assertMyth("ElrMatrix3D::dot_div() needs valid input",
                       b.mtx[i] != 0.0f);

            r.mtx[i] = mtx[i] / b.mtx[i];
        }
        return r;
    }
    ElrMatrix3D dot_diveq(const ElrMatrix3D &b)
    {
        for(int i=0; i < ELR_MTX3D_MAX; i++)
        {
            assertMyth("ElrMatrix3D::dot_diveq() needs valid input",
                       b.mtx[i] != 0.0f);

            mtx[i] = mtx[i] / b.mtx[i];
        }
        return (*this);
    }

    //ÄÄÄ Multiplication by a matrix.
    ElrMatrix3D operator * (const ElrMatrix3D &b) const
    {
        ElrMatrix3D m;
        ::elr_concatmatrix3d(this,&b,&m);
        return m;
    }
    ElrMatrix3D operator *= (const ElrMatrix3D &b)
    {
        ::elr_concatmatrix3d(this,&b,this);
        return (*this);
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    // Operations
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

    //ÄÄÄ Matrix math operations
    void concat(const ElrMatrix3D &m, int hn=0)
    {
        ::elr_concatmatrix3d(this,&m,this,hn);
    }
    void concat(const ElrMatrix3D &m, ElrMatrix3D &result, int hn=0) const
    {
        ::elr_concatmatrix3d(this,&m,&result,hn);
    }

    float det() const;

    void transpose()
    {
        ElrMatrix3D m = *this;

        mtx[ELR_MTX3D_A] = m.mtx[ELR_MTX3D_A];
        mtx[ELR_MTX3D_E] = m.mtx[ELR_MTX3D_B];
        mtx[ELR_MTX3D_I] = m.mtx[ELR_MTX3D_C];
        mtx[ELR_MTX3D_M] = m.mtx[ELR_MTX3D_D];
        mtx[ELR_MTX3D_B] = m.mtx[ELR_MTX3D_E];
        mtx[ELR_MTX3D_F] = m.mtx[ELR_MTX3D_F];
        mtx[ELR_MTX3D_J] = m.mtx[ELR_MTX3D_G];
        mtx[ELR_MTX3D_N] = m.mtx[ELR_MTX3D_H];
        mtx[ELR_MTX3D_C] = m.mtx[ELR_MTX3D_I];
        mtx[ELR_MTX3D_G] = m.mtx[ELR_MTX3D_J];
        mtx[ELR_MTX3D_K] = m.mtx[ELR_MTX3D_K];
        mtx[ELR_MTX3D_O] = m.mtx[ELR_MTX3D_L];
        mtx[ELR_MTX3D_D] = m.mtx[ELR_MTX3D_M];
        mtx[ELR_MTX3D_H] = m.mtx[ELR_MTX3D_N];
        mtx[ELR_MTX3D_L] = m.mtx[ELR_MTX3D_O];
        mtx[ELR_MTX3D_P] = m.mtx[ELR_MTX3D_P];
    }
    void transpose(ElrMatrix3D &result) const
    {
        result.mtx[ELR_MTX3D_A] = mtx[ELR_MTX3D_A];
        result.mtx[ELR_MTX3D_E] = mtx[ELR_MTX3D_B];
        result.mtx[ELR_MTX3D_I] = mtx[ELR_MTX3D_C];
        result.mtx[ELR_MTX3D_M] = mtx[ELR_MTX3D_D];
        result.mtx[ELR_MTX3D_B] = mtx[ELR_MTX3D_E];
        result.mtx[ELR_MTX3D_F] = mtx[ELR_MTX3D_F];
        result.mtx[ELR_MTX3D_J] = mtx[ELR_MTX3D_G];
        result.mtx[ELR_MTX3D_N] = mtx[ELR_MTX3D_H];
        result.mtx[ELR_MTX3D_C] = mtx[ELR_MTX3D_I];
        result.mtx[ELR_MTX3D_G] = mtx[ELR_MTX3D_J];
        result.mtx[ELR_MTX3D_K] = mtx[ELR_MTX3D_K];
        result.mtx[ELR_MTX3D_O] = mtx[ELR_MTX3D_L];
        result.mtx[ELR_MTX3D_D] = mtx[ELR_MTX3D_M];
        result.mtx[ELR_MTX3D_H] = mtx[ELR_MTX3D_N];
        result.mtx[ELR_MTX3D_L] = mtx[ELR_MTX3D_O];
        result.mtx[ELR_MTX3D_P] = mtx[ELR_MTX3D_P];
    }

    void adjoint(int hn=0) { ::elr_adjointmatrix3d(this,this,hn); }
    void adjoint(ElrMatrix3D &result, int hn=0) const
    {
        ::elr_adjointmatrix3d(this,&result,hn);
    }

    int inverse(int hn=0) { return ::elr_inversematrix3d(this,this,hn); }
    int inverse(ElrMatrix3D &result, int hn=0) const
    {
        return ::elr_inversematrix3d(this,&result,hn);
    }

    //ÄÄÄ Special matricies
    void identity()
    {
        memset(mtx,0,sizeof(mtx));
        mtx[ELR_MTX3D_A]=mtx[ELR_MTX3D_F]=
        mtx[ELR_MTX3D_K]=mtx[ELR_MTX3D_P]=1.0f;
    }

    void zero() { memset(mtx,0,sizeof(mtx)); }

    void one() { for(int i=0; i < ELR_MTX3D_MAX; i++)  mtx[i] = 1.0f; }
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - elrmtx.hpp ²±°
