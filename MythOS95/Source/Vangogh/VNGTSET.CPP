//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
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
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// vngtset.cpp
//
//     The setup code used for all of the triangles.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#include <assert.h>

#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define INLINE_ASSEMBLY     1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#if 0
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  This section of code contains all of the code that is used for all      ³
//  triangle types.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  triangle_setup(VngoPoint *pts,VngoTriangle *tri);                       ³
//      Fills in the VngoTriangle structure with the information from the   ³
//      VngoPoints that make up the triangle.  It does not compute any of   ³
//      the step rates for the triangle, but it does delineate the rotation ³
//      as well as which vertices are used for the long and short sides of  ³
//      the triangle.                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

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


//°±² End of module - vngtset.cpp ²±°

