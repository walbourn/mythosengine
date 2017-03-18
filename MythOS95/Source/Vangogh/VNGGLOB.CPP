//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little
//
// vngglob.cpp
//
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
#include "thlspec.h"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

class VngoSystem    *VgSystem;

long DitherMatrix[4][4] =
{
    -7 << 15,  1 << 15,  -5 << 15, 3 << 15,
   5 << 15,  -3 << 15, 7 << 15,  -1 << 15,
    -4 << 15, 4 << 15,  -6 << 15,  2 << 15,
   8 << 15,  0 << 15, 6 << 15,  -2 << 15
};

long RedDitherMatrix[4][4] =
{
    0 << 16,  8 << 16,  2 << 16, 10 << 16,
   12 << 16,  4 << 16, 14 << 16,  6 << 16,
    3 << 16, 11 << 16,  1 << 16,  9 << 16,
   15 << 16,  7 << 16, 13 << 16,  5 << 16
};
long GreenDitherMatrix[4][4] =
{
   10 << 16,  6 << 16,  9 << 16,  5 << 16,
    2 << 16, 14 << 16,  1 << 16, 13 << 16,
    8 << 16,  4 << 16, 11 << 16,  7 << 16,
    0 << 16, 12 << 16,  3 << 16, 15 << 16
};
long BlueDitherMatrix[4][4] =
{
    5 << 16, 13 << 16,  7 << 16, 15 << 16,
    9 << 16,  1 << 16, 11 << 16,  3 << 16,
    6 << 16,  6 << 16, 14 << 16, 12 << 16,
   10 << 16,  2 << 16,  8 << 16,  0 << 16
};

long AlphaMatrix[4][4] =
{
    0 << 4,  8 << 4,  2 << 4, 10 << 4,
   12 << 4,  4 << 4, 14 << 4,  6 << 4,
    3 << 4, 11 << 4,  1 << 4,  9 << 4,
   15 << 4,  7 << 4, 13 << 4,  5 << 4
};

extern "C" void vngo_lghlines16_filtered(VngoTriangle *tri);
extern "C" void vngo_lghlines16(VngoTriangle *tri);
extern "C" void vngo_lzghlines16_filtered(VngoTriangle *tri);
extern "C" void vngo_lzghlines16(VngoTriangle *tri);
extern "C" void vngo_lhlines16_filtered(VngoTriangle *tri);
extern "C" void vngo_lhlines16(VngoTriangle *tri);
extern "C" void vngo_lzhlines16_filtered(VngoTriangle *tri);
extern "C" void vngo_lzhlines16(VngoTriangle *tri);



extern "C" void vngo_alghlines16_filtered(VngoTriangle *tri);
extern "C" void vngo_alghlines16(VngoTriangle *tri);
extern "C" void vngo_alzghlines16_filtered(VngoTriangle *tri);
extern "C" void vngo_alzghlines16(VngoTriangle *tri);
extern "C" void vngo_alhlines16_filtered(VngoTriangle *tri);
extern "C" void vngo_alhlines16(VngoTriangle *tri);
extern "C" void vngo_alzhlines16_filtered(VngoTriangle *tri);
extern "C" void vngo_alzhlines16(VngoTriangle *tri);

extern "C" void vngo_ghlines16(VngoTriangle *tri);
extern "C" void vngo_zghlines16(VngoTriangle *tri);
extern "C" void vngo_hlines16(VngoTriangle *tri);
extern "C" void vngo_zhlines16(VngoTriangle *tri);

extern "C" void vngo_taghlines16(VngoTriangle *tri);
extern "C" void vngo_tazghlines16(VngoTriangle *tri);
extern "C" void vngo_tahlines16(VngoTriangle *tri);
extern "C" void vngo_tazhlines16(VngoTriangle *tri);


extern "C"
{
    lineproc hline[1600] =
    {
//      TEX16x16
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_hlines16,
                        // ZBuffered
                        vngo_zhlines16,
                    // Gouraud
                        vngo_ghlines16,
                        // ZBuffered
                        vngo_zghlines16,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_hlines16,
                        // ZBuffered
                        vngo_zhlines16,
                    // Gouraud
                        vngo_ghlines16,
                        // ZBuffered
                        vngo_zghlines16,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16,
                        // ZBuffered
                        vngo_lzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16,
                        // ZBuffered
                        vngo_lzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_filtered,
                        // ZBuffered
                        vngo_lzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_filtered,
                        // ZBuffered
                        vngo_lzghlines16_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_tahlines16,
                        // ZBuffered
                        vngo_tazhlines16,
                    // Gouraud
                        vngo_taghlines16,
                        // ZBuffered
                        vngo_tazghlines16,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_tahlines16,
                        // ZBuffered
                        vngo_tazhlines16,
                    // Gouraud
                        vngo_taghlines16,
                        // ZBuffered
                        vngo_tazghlines16,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX16x32
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16,
                        // ZBuffered
                        vngo_lzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16,
                        // ZBuffered
                        vngo_lzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_filtered,
                        // ZBuffered
                        vngo_lzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_filtered,
                        // ZBuffered
                        vngo_lzghlines16_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX16x64
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16,
                        // ZBuffered
                        vngo_lzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16,
                        // ZBuffered
                        vngo_lzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_filtered,
                        // ZBuffered
                        vngo_lzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_filtered,
                        // ZBuffered
                        vngo_lzghlines16_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX16x128
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16,
                        // ZBuffered
                        vngo_lzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16,
                        // ZBuffered
                        vngo_lzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_filtered,
                        // ZBuffered
                        vngo_lzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_filtered,
                        // ZBuffered
                        vngo_lzghlines16_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX16x256
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16,
                        // ZBuffered
                        vngo_lzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16,
                        // ZBuffered
                        vngo_lzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_filtered,
                        // ZBuffered
                        vngo_lzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_filtered,
                        // ZBuffered
                        vngo_lzghlines16_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX32x16
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16,
                        // ZBuffered
                        vngo_lzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16,
                        // ZBuffered
                        vngo_lzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_filtered,
                        // ZBuffered
                        vngo_lzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_filtered,
                        // ZBuffered
                        vngo_lzghlines16_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX32x32
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_32x32,
                        // ZBuffered
                        vngo_lzhlines16_32x32,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_32x32,
                        // ZBuffered
                        vngo_lzghlines16_32x32,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_32x32_filtered,
                        // ZBuffered
                        vngo_lzhlines16_32x32_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_32x32_filtered,
                        // ZBuffered
                        vngo_lzghlines16_32x32_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX32x64
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_32x64,
                        // ZBuffered
                        vngo_lzhlines16_32x64,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_32x64,
                        // ZBuffered
                        vngo_lzghlines16_32x64,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_32x64_filtered,
                        // ZBuffered
                        vngo_lzhlines16_32x64_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_32x64_filtered,
                        // ZBuffered
                        vngo_lzghlines16_32x64_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX32x128
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_32x128,
                        // ZBuffered
                        vngo_lzhlines16_32x128,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_32x128,
                        // ZBuffered
                        vngo_lzghlines16_32x128,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_32x128_filtered,
                        // ZBuffered
                        vngo_lzhlines16_32x128_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_32x128_filtered,
                        // ZBuffered
                        vngo_lzghlines16_32x128_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX32x256
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_32x256,
                        // ZBuffered
                        vngo_lzhlines16_32x256,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_32x256,
                        // ZBuffered
                        vngo_lzghlines16_32x256,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_32x256_filtered,
                        // ZBuffered
                        vngo_lzhlines16_32x256_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_32x256_filtered,
                        // ZBuffered
                        vngo_lzghlines16_32x256_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
            // Textured
                // Non-Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
                // Filtered
                    // Flat
                        0, // Non-ZBuffered
                        0, // ZBuffered
                    // Gouraud
                        0, // Non-ZBuffered
                        0, // ZBuffered
//      TEX64x16
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16,
                        // ZBuffered
                        vngo_lzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16,
                        // ZBuffered
                        vngo_lzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_filtered,
                        // ZBuffered
                        vngo_lzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_filtered,
                        // ZBuffered
                        vngo_lzghlines16_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX64x32
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_64x32,
                        // ZBuffered
                        vngo_lzhlines16_64x32,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_64x32,
                        // ZBuffered
                        vngo_lzghlines16_64x32,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_64x32_filtered,
                        // ZBuffered
                        vngo_lzhlines16_64x32_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_64x32_filtered,
                        // ZBuffered
                        vngo_lzghlines16_64x32_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX64x64
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_64x64,
                        // ZBuffered
                        vngo_lzhlines16_64x64,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_64x64,
                        // ZBuffered
                        vngo_lzghlines16_64x64,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_64x64_filtered,
                        // ZBuffered
                        vngo_lzhlines16_64x64_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_64x64_filtered,
                        // ZBuffered
                        vngo_lzghlines16_64x64_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX64x128
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_64x128,
                        // ZBuffered
                        vngo_lzhlines16_64x128,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_64x128,
                        // ZBuffered
                        vngo_lzghlines16_64x128,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_64x128_filtered,
                        // ZBuffered
                        vngo_lzhlines16_64x128_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_64x128_filtered,
                        // ZBuffered
                        vngo_lzghlines16_64x128_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX64x256
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_64x256,
                        // ZBuffered
                        vngo_lzhlines16_64x256,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_64x256,
                        // ZBuffered
                        vngo_lzghlines16_64x256,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_64x256_filtered,
                        // ZBuffered
                        vngo_lzhlines16_64x256_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_64x256_filtered,
                        // ZBuffered
                        vngo_lzghlines16_64x256_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX128x16
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16,
                        // ZBuffered
                        vngo_lzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16,
                        // ZBuffered
                        vngo_lzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_filtered,
                        // ZBuffered
                        vngo_lzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_filtered,
                        // ZBuffered
                        vngo_lzghlines16_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX128x32
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_128x32,
                        // ZBuffered
                        vngo_lzhlines16_128x32,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_128x32,
                        // ZBuffered
                        vngo_lzghlines16_128x32,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_128x32_filtered,
                        // ZBuffered
                        vngo_lzhlines16_128x32_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_128x32_filtered,
                        // ZBuffered
                        vngo_lzghlines16_128x32_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX128x64
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_128x64,
                        // ZBuffered
                        vngo_lzhlines16_128x64,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_128x64,
                        // ZBuffered
                        vngo_lzghlines16_128x64,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_128x64_filtered,
                        // ZBuffered
                        vngo_lzhlines16_128x64_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_128x64_filtered,
                        // ZBuffered
                        vngo_lzghlines16_128x64_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX128x128
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_128x128,
                        // ZBuffered
                        vngo_lzhlines16_128x128,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_128x128,
                        // ZBuffered
                        vngo_lzghlines16_128x128,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_128x128_filtered,
                        // ZBuffered
                        vngo_lzhlines16_128x128_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_128x128_filtered,
                        // ZBuffered
                        vngo_lzghlines16_128x128_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX128x256
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_128x256,
                        // ZBuffered
                        vngo_lzhlines16_128x256,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_128x256,
                        // ZBuffered
                        vngo_lzghlines16_128x256,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_128x256_filtered,
                        // ZBuffered
                        vngo_lzhlines16_128x256_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_128x256_filtered,
                        // ZBuffered
                        vngo_lzghlines16_128x256_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX256x16
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16,
                        // ZBuffered
                        vngo_lzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16,
                        // ZBuffered
                        vngo_lzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_filtered,
                        // ZBuffered
                        vngo_lzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_filtered,
                        // ZBuffered
                        vngo_lzghlines16_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX256x32
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_256x32,
                        // ZBuffered
                        vngo_lzhlines16_256x32,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_256x32,
                        // ZBuffered
                        vngo_lzghlines16_256x32,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_256x32_filtered,
                        // ZBuffered
                        vngo_lzhlines16_256x32_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_256x32_filtered,
                        // ZBuffered
                        vngo_lzghlines16_256x32_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX256x64
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_256x64,
                        // ZBuffered
                        vngo_lzhlines16_256x64,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_256x64,
                        // ZBuffered
                        vngo_lzghlines16_256x64,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_256x64_filtered,
                        // ZBuffered
                        vngo_lzhlines16_256x64_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_256x64_filtered,
                        // ZBuffered
                        vngo_lzghlines16_256x64_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX256x128
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_256x128,
                        // ZBuffered
                        vngo_lzhlines16_256x128,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_256x128,
                        // ZBuffered
                        vngo_lzghlines16_256x128,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_256x128_filtered,
                        // ZBuffered
                        vngo_lzhlines16_256x128_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_256x128_filtered,
                        // ZBuffered
                        vngo_lzghlines16_256x128_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
//      TEX256x256
    // 16bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                    // Flat
                        // Non-ZBuffered
                        vngo_lhlines16_256x256,
                        // ZBuffered
                        vngo_lzhlines16_256x256,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_256x256,
                        // ZBuffered
                        vngo_lzghlines16_256x256,
                // Filtered
                        // Non-ZBuffered
                        vngo_lhlines16_256x256_filtered,
                        // ZBuffered
                        vngo_lzhlines16_256x256_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_lghlines16_256x256_filtered,
                        // ZBuffered
                        vngo_lzghlines16_256x256_filtered,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        vngo_alhlines16,
                        // ZBuffered
                        vngo_alzhlines16,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16,
                        // ZBuffered
                        vngo_alzghlines16,
                // Filtered
                        // Non-ZBuffered
                        vngo_alhlines16_filtered,
                        // ZBuffered
                        vngo_alzhlines16_filtered,
                    // Gouraud
                        // Non-ZBuffered
                        vngo_alghlines16_filtered,
                        // ZBuffered
                        vngo_alzghlines16_filtered,
    // 8bpp
        // Non-Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
        //Alpha
            // Non-Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
            // Textured
                // Non-Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                // Filtered
                    // Flat
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
                    // Gouraud
                        // Non-ZBuffered
                        0,
                        // ZBuffered
                        0,
    };
};


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


//°±² End of module - vngglob.cpp ²±°




