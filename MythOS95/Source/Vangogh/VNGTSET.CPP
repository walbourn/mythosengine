//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
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
// Created by Tim Little
//
// vngtset.cpp
//
//     The setup code used for all of the triangles.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#include <assert.h>

#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define INLINE_ASSEMBLY     1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�


//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

#if 0
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  This section of code contains all of the code that is used for all      �
//  triangle types.                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  triangle_setup(VngoPoint *pts,VngoTriangle *tri);                       �
//      Fills in the VngoTriangle structure with the information from the   �
//      VngoPoints that make up the triangle.  It does not compute any of   �
//      the step rates for the triangle, but it does delineate the rotation �
//      as well as which vertices are used for the long and short sides of  �
//      the triangle.                                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

void triangle_setup(VngoPoint2 *pts,VngoTriangle *tri)
{
// Look for the flat top/bottom cases.

    if (pts[0].y == pts[2].y)
    {
        if (pts[0].y > pts[1].y)
        {
            // it is a flat bottom.

            tri->long_top = &pts[1];
            tri->short_top = &pts[1];

            if (pts[0].x < pts[2].x)
            {
                tri->long_bottom = &pts[0];
                tri->short_bottom = &pts[2];
            }
            else
            {
                tri->long_bottom = &pts[2];
                tri->short_bottom = &pts[0];
            }
        }
        else
        {
            // it is a flat top.

            tri->long_bottom = &pts[1];
            tri->short_bottom = &pts[1];

            if (pts[0].x < pts[2].x)
            {
                tri->long_top = &pts[0];
                tri->short_top = &pts[2];
            }
            else
            {
                tri->long_top = &pts[2];
                tri->short_top = &pts[0];
            }
        }
    }
    else if (pts[0].y == pts[1].y)
    {
        if (pts[0].y > pts[2].y)
        {
            // it is a flat bottom.

            tri->long_top = &pts[2];
            tri->short_top = &pts[2];
            if (pts[0].x < pts[1].x)
            {
                tri->long_bottom = &pts[0];
                tri->short_bottom = &pts[1];
            }
            else
            {
                tri->long_bottom = &pts[1];
                tri->short_bottom = &pts[0];
            }
        }
        else
        {
            // it is a flat top.

            tri->long_bottom = &pts[2];
            tri->short_bottom = &pts[2];
            if (pts[0].x < pts[1].x)
            {
                tri->long_top = &pts[0];
                tri->short_top = &pts[1];
            }
            else
            {
                tri->long_top = &pts[1];
                tri->short_top = &pts[0];
            }
        }

    }
    else if (pts[1].y == pts[2].y)
    {
        if (pts[1].y > pts[0].y)
        {
            // it is a flat bottom.

            tri->long_top = &pts[0];
            tri->short_top = &pts[0];
            if (pts[1].x < pts[2].x)
            {
                tri->long_bottom = &pts[1];
                tri->short_bottom = &pts[2];
            }
            else
            {
                tri->long_bottom = &pts[2];
                tri->short_bottom = &pts[1];
            }
        }
        else
        {
            // it is a flat bottom.

            tri->long_bottom = &pts[0];
            tri->short_bottom = &pts[0];
            if (pts[1].x < pts[2].x)
            {
                tri->long_top = &pts[1];
                tri->short_top = &pts[2];
            }
            else
            {
                tri->long_top = &pts[2];
                tri->short_top = &pts[1];
            }
        }
    }
// Ok it is not a flat top or bottom so do case analysis.
    else if (pts[0].y > pts[1].y)
    {
        if (pts[0].y > pts[2].y)
        {
            tri->long_bottom = &pts[0];
            if (pts[1].y > pts[2].y)
            {
                tri->long_top = &pts[2];
                tri->short_top = &pts[2];
                tri->short_bottom = &pts[1];
            }
            else
            {
                tri->long_top = &pts[1];
                tri->short_top = &pts[1];
                tri->short_bottom = &pts[2];
            }
        }
        else
        {
            tri->long_bottom = &pts[2];
            tri->short_bottom = &pts[0];
            tri->long_top = &pts[1];
            tri->short_top = &pts[1];
        }
    }
    else if (pts[1].y > pts[2].y)
    {
        tri->long_bottom = &pts[1];
        if (pts[0].y > pts[2].y)
        {
            tri->short_top = &pts[2];
            tri->long_top = &pts[2];
            tri->short_bottom = &pts[0];
        }
        else
        {
            tri->short_top = &pts[0];
            tri->long_top = &pts[0];
            tri->short_bottom = &pts[2];
        }
    }
    else
    {
        tri->long_bottom = &pts[2];
        tri->long_top = &pts[0];
        tri->short_top = &pts[0];
        tri->short_bottom = &pts[1];
    }
}
#endif


void calc_order(int &high_pt, int &mid_pt, int &low_pt, VngoPoint2 *pts)
{
    high_pt = 0;
    mid_pt = 1;
    low_pt = 2;

// Start by ordering the points.
    if (pts[0].y < pts[1].y)
    {
        if (pts[2].y < pts[0].y)
        {
            high_pt = 2;
            low_pt = 1;
            mid_pt = 0;
            return;
        }
        else
        {
            if (pts[1].y > pts[2].y)
            {
                low_pt = 1;
                mid_pt = 2;
            }
            return;
        }
    }
    else if (pts[1].y < pts[2].y)
    {
        high_pt = 1;
        if(pts[0].y < pts[2].y)
        {
            low_pt = 2;
            mid_pt = 0;
            return;
        }
        else
        {
            low_pt = 0;
            mid_pt = 2;
            return;
        }
    }
    else
    {
        high_pt = 2;
        low_pt = 0;
        mid_pt = 1;
        return;
    }
}


void calc_order(int &high_pt, int &mid_pt, int &low_pt, VngoPoint *pts)
{
    high_pt = 0;
    mid_pt = 1;
    low_pt = 2;

// Start by ordering the points.
    if (pts[0].y < pts[1].y)
    {
        if (pts[2].y < pts[0].y)
        {
            high_pt = 2;
            low_pt = 1;
            mid_pt = 0;
            return;
        }
        else
        {
            if (pts[1].y > pts[2].y)
            {
                low_pt = 1;
                mid_pt = 2;
            }
            return;
        }
    }
    else if (pts[1].y < pts[2].y)
    {
        high_pt = 1;
        if(pts[0].y < pts[2].y)
        {
            low_pt = 2;
            mid_pt = 0;
            return;
        }
        else
        {
            low_pt = 0;
            mid_pt = 2;
            return;
        }
    }
    else
    {
        high_pt = 2;
        low_pt = 0;
        mid_pt = 1;
        return;
    }
}


//葦� End of module - vngtset.cpp 憶�

