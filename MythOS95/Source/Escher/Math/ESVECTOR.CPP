//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//������������������� Microsoft Windows 95/NT Version �����������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1998�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// Created by Tim Little & Chuck Walbourn
//
// esvector.cpp
//
// Contains the various arithmetic operations for the EschVector class
// in the 'math' header.
//
//        esch_cross
//        esch_dot
//        esch_magnitude
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// esch_cross                                                               �
//                                                                          �
// Computes the cross-product of the two vectors.                           �
//���������������������������������������������������������������������������
extern "C" EschVector *esch_cross(const EschVector *v1, const EschVector *v2,
                                  EschVector *dest)
{
//
// (i', j', k') = v1 CROSS v2
//
//       i' = (v1.j * v2.k) - (v1.k * v2.j)
//       j' = (v1.k * v2.i) - (v1.i * v2.k)
//       k' = (v1.i * v2.j) - (v1.j * v2.i)
//

    float newi = (v1->j*v2->k) - (v1->k*v2->j);
    float newj = (v1->k*v2->i) - (v1->i*v2->k);
    float newk = (v1->i*v2->j) - (v1->j*v2->i);

    dest->i = newi;
    dest->j = newj;
    dest->k = newk;

    return dest;
}


//�������������������������������������������������������������������������Ŀ
// esch_dot                                                                 �
//                                                                          �
// Returns the dot product of two vectors.                                  �
//���������������������������������������������������������������������������
extern "C" float esch_dot(const EschVector *v1, const EschVector *v2)
{
//
// x = v1 DOT v2 =  (v1.i*v2.i) + (v1.j*v2.j) + (v1.k*v2.k)
//

    return ((v1->i*v2->i)
            + (v1->j*v2->j)
            + (v1->k*v2->k));
}


//�������������������������������������������������������������������������Ŀ
// esch_magnitude                                                           �
//                                                                          �
// Returns the magnitude of the vector.                                     �
//���������������������������������������������������������������������������
extern "C" float esch_magnitude(const EschVector *vect)
{
// magnitude = sqrt(i^2 + j^2 + k^3)

    return esch_sqrt(vect->i*vect->i
                     + vect->j*vect->j
                     + vect->k*vect->k);
}

//��� End of module - esvector.cpp ���
