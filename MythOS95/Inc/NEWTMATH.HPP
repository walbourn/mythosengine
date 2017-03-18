//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм
//                                   ____
//                                  / __ \
//                                 ( (__) )
//                                 _\____/___
//                                /  |  |   /\
//                               /_________/  \_
//                              /          \    \
//                             /            \    \_
//                            /              \     \
//                           /                \     \_
//                          /                  \      \
//                         /                    \      \_
//                        /                      \       \
//                       /                        \       \_
//                      /                          \        \
//                     /                            \        \_
//                    /                              \         \
//                   / N  N EEE W   W TTTTT  OO  N  N \        /
//                  /  NN N E_  W   W   T   O  O NN N  \      /
//                 /   N NN E   W W W   T   O  O N NN   \    /
//                /    N  N EEE  W W    T    OO  N  N    \  /
//               /________________________________________\/
//
//                     Newtonian Physics Simulation Library
//
//                      Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
//                        http://www.mythos-engine.org/
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// Created by Dan Higdon
//
// newtmath.hpp
//
// Newton math support header.  This contains the NewtVector class which
// is used for positions, forces, velocities, acclerations, etc.
//
// If conversion to and from EschVectors is desired, this header should
// be included AFTER Escher's esmath.hpp header.
//
//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм

#ifndef __NEWTMATH_HPP
#define __NEWTMATH_HPP   1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Includes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

#include <portable.h>
#include <assert.h>

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Equates
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

// If these are already defined, they are assumed to be set correctly (usually
// by the Escher header)

#ifndef DOT
#define DOT    |
#endif

#ifndef CROSS
#define CROSS  &
#endif

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                               Prototypes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

class NewtVector;

extern "C" NewtVector *newt_cross(const NewtVector *v1,const NewtVector *v2,NewtVector *dest);
extern "C" float newt_dot(const NewtVector *v1,const NewtVector *v2);
extern "C" float newt_magnitude(const NewtVector *vect);

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Classes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// Newton Vector type (used for force and position)
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
class NewtVector
{
public:
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Public data members                                                  Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    float   i;
    float   j;
    float   k;
    dword   flags;

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructors                                              Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    NewtVector () : i (0), j (0), k (0), flags (0) {};
    NewtVector (float _ii, float _ij, float _ik) :
                i (_ii), j (_ij), k (_ik), flags (0) {};

#ifdef __ESMATH_HPP
    NewtVector (EschVector &v) : i (v.i), j (v.j), k (v.k), flags (0) {};

    inline operator EschVector() const
    {
        return EschVector(i,j,k);
    }
#endif

    ~NewtVector() {};

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    float magnitude(void) const { return (newt_magnitude(this));}
    void normalize(void)
    {
        float mag=magnitude();

#ifdef assertMyth
        assertMyth("NewtVector::normalize found magnitude of zero",
                   mag > 0.0f);
#endif

        if (mag > 0.0f) // can't normalize a vector of magnitude 0.
        {
            i = i / mag;
            j = j / mag;
            k = k / mag;
        }
    }
};

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                              Inline Functions
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator +
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector operator + (const NewtVector &a, const NewtVector &b)
{
    return NewtVector (a.i + b.i,
                       a.j + b.j,
                       a.k + b.k);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator +=
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector &operator += (NewtVector &a, const NewtVector &b)
{
    a.i += b.i;
    a.j += b.j;
    a.k += b.k;

    return a;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator -
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector operator - (const NewtVector &a, const NewtVector &b)
{
    return NewtVector (a.i - b.i,
                       a.j - b.j,
                       a.k - b.k);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator -=
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector &operator -= (NewtVector &a, const NewtVector &b)
{
    a.i -= b.i;
    a.j -= b.j;
    a.k -= b.k;

    return a;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator - (negation)
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector operator - (const NewtVector &a)
{
    return NewtVector (-a.i,
                       -a.j,
                       -a.k);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator + scalar
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector operator + (const NewtVector &a, const float b)
{
    return NewtVector (a.i + b,
                       a.j + b,
                       a.k + b);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator += scalar
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector &operator += (NewtVector &a, const float b)
{
    a.i += b;
    a.j += b;
    a.k += b;

    return a;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator - scalar
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector operator - (const NewtVector &a, const float b)
{
    return NewtVector (a.i - b,
                       a.j - b,
                       a.k - b);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator -= scalar
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector &operator -= (NewtVector &a, const float b)
{
    a.i -= b;
    a.j -= b;
    a.k -= b;

    return a;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator * scalar
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector operator * (const NewtVector &a, const float b)
{
    return NewtVector (a.i * b,
                       a.j * b,
                       a.k * b);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator *= scalar
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector &operator *= (NewtVector &a, const float b)
{
    a.i = a.i * b;
    a.j = a.j * b;
    a.k = a.k * b;

    return a;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator / scalar
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector operator / (const NewtVector &a, const float b)
{
    return NewtVector (a.i / b,
                       a.j / b,
                       a.k / b);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator /= scalar
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector &operator /= (NewtVector &a, const float b)
{
    a.i = a.i / b;
    a.j = a.j / b;
    a.k = a.k / b;

    return a;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator CROSS
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline NewtVector operator CROSS (const NewtVector &a, const NewtVector &b)
{
    NewtVector  result;
    return (*::newt_cross(&a,&b,&result));
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//  operator DOT
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
inline float operator DOT (const NewtVector &a, const NewtVector &b)
{
    return (::newt_dot(&a,&b));
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//╟╠╡ End of header - newtmath.hpp ╡╠╟

