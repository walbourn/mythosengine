//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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
// vngcolor.cpp
//
//     The C++ color classes for the VanGogh Draw library.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "debug.h"
#include "portable.h"
#include "felix.hpp"
#include "xfile.hpp"
#include "ivory.h"

#include "vngdefs.h"
#include "vngcolor.hpp"
#include "vngpal.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoClrConvert class.                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void VngoClrConvert::init(VngoPal *my_pal,int flags)
{
    mypal = &((VngoPal8 *)my_pal)->hw_pal;
    if (flags & VNGO_PAL_CALC)
        cvt2_8.init(my_pal);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Vngo24to8bit color conversion class.                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoColorIndex Vngo24to8bit::get_index(VngoColor24bit clr)
{
    return ((VngoColorIndex)colorconvert[clr.compress()]);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// init()  This function takes a 256 color palette and generates a          ³
// look up table that give the index of the 8bit mapped palette color that  ³
// is the closest to the 15bit rgb.  It is slow and should only be called   ³
// when initializing the system or when the 8bpp palette is changed.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

void Vngo24to8bit::init(VngoPal *mypal)
{
    VngoHwPal   *my_pal8;
    int r,g,b,c;
    int dr,dg,db,tmp,close;
    int close_idx=0;
    int index;

    my_pal8 = &((VngoPal8 *)mypal)->hw_pal;

    for (r=0;r < 32; r++)
    {
        for (g=0;g < 32; g++)
        {
            for (b=0;b < 32; b++)
            {
                close = 0x7ffffff;      // reset close to greater than 256^3
                for (c=0;c < 255;c++)
                {                    
                    dr = (r<<3) - my_pal8->p[c].r;
                    dg = (g<<3) - my_pal8->p[c].g;
                    db = (b<<3) - my_pal8->p[c].b;
#ifdef PURE_COLOR_CONVERT
                    dr *= dr;
                    dg *= dg;
                    db *= db;
#else  // This methos distorts color matching in order of eye sensitivity.
#if 0   // These seemed a little too exagerated so for now we will use 
        // some calmer values.
                    dr *= dr * 30;
                    dg *= dg * 59;
                    db *= db * 11;
#else   // We will see how these work out.
                    dr *= dr * 8;
                    dg *= dg * 15;
                    db *= db * 5;
#endif
#endif
                    tmp = dr+dg+db;
                    if (tmp < close)
                    {
                        close = tmp;
                        close_idx = c;
                    }
                }
                index = (r<<10) + (g<<5) + b;
                colorconvert[index] = (byte)close_idx;
            }
        }
    }
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoColor24Bit  Class member functions.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoColor24bit::VngoColor24bit(VngoColorHLS c);                          ³
//     This constructor allows a VngoColorHLS to be automaticaly converted  ³
//     to a VngoColor24bit, this is handy for doing conversion by           ³
//     assignmment.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoColor24bit::VngoColor24bit(VngoColorHLS c)
{
    VngoColor24bit rgbc;
    rgbc = c.to_RGB();
    r = rgbc.r;
    g = rgbc.g;
    b = rgbc.b;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoColor24Bit::to_HLS();                                                ³
//     This function converts an RGB to HLS.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoColorHLS VngoColor24bit::to_HLS()
{
    VngoColorHLS    c;
    Flx16           dr,dg,db;
    Flx16           max,min,delta;
    dr = r;
    dg = g;
    db = b;
    dr = dr / (Flx16)255;
    dg = dg / (Flx16)255;
    db = db / (Flx16)255;

    c.flags = 0;

    if (dr > dg)
        if (dr > db)
            max = dr;
        else
            max = db;
    else if (dg > db)
        max = dg;
    else   
        max = db;

    if (dr < dg)
        if (dr < db)
            min = dr;
        else
            min = db;
    else if (dg < db)
        min = dg;
    else
        min = db;

    c.l = (max + min) / (Flx16)2;
    if (max == min)
    {
        c.s = 0;
    }
    else
    {
        if (c.l <= (Flx16)0.5)
            c.s = (max-min)/(max+min);
        else
            c.s = (max-min)/(((Flx16)2)-max-min);

        delta = max-min;
        if (dr == max)
            c.h = (dg - db)/delta;
        if (dg == max)
            c.h = (db-dr)/delta + (Flx16)2;
        if (db == max)
            c.h = (dr-dg)/delta + (Flx16)4;

        c.h = c.h * (Flx16)60;
        while (c.h < 0)
            c.h = c.h + (Flx16)360;
    }
    
    return (c);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoColorHLS    Class member functions.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoColorHLS::VngoColorHLS(VngoColor24bit c);                            ³
//     This constructor allows a VngoColor24bit to be automaticaly converted³
//     to a VngoColorHLS, this is handy for doing conversion by assignmment.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoColorHLS::VngoColorHLS(VngoColor24bit c)
{
    VngoColorHLS    rgbc;
    rgbc = c.to_HLS();
    h = rgbc.h;
    l = rgbc.l;
    s = rgbc.s;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoColorHLS::to_RGB();                                                  ³
//     This does the explicit conversion of HLS to RGB.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoColor24bit VngoColorHLS::to_RGB()
{
    VngoColor24bit  c;
    Flx16           m1, m2;

    if (l <= (Flx16)0.5)
    {
        m2 = l * ((Flx16)1 + s);
    }
    else
    {
        m2 = l + s - l * s;
    }
    m1 = (Flx16)2 * l - m2;

    if (s == 0)
    {
        c.r = c.g = c.b = (byte)((int)(l * (Flx16)255));
    }
    else
    {
        c.r = (byte)value(m1,m2,h + (Flx16)120);
        c.g = (byte)value(m1,m2,h );
        c.b = (byte)value(m1,m2,h - (Flx16)120);
    }
    return (c);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoColorHLS::value(Flx16 a,Flx16 b,Flx16 c);                            ³
//     This is an internal function used by the convertion function to help ³
//     convert a VngoColorHLS to a VngoColor24bit.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoColorHLS::value(Flx16 a,Flx16 b,Flx16 c)
{
    Flx16 v;
    while (c > 360)
        c = c - (Flx16)360;
    while (c < 0)
        c = c + (Flx16)360 ;

    if (c < 60)
        v = a + (b - a) * c / (Flx16)60;
    else if (c < 180)
        v = b;
    else if (c < 240)
        v = a + (b-a) * ((Flx16)240-c)/(Flx16)60;
    else
        v = a;
    v = v * (Flx16)255;
    return ((int) v);
}



//°±² End of module - vngcolor.cpp ²±°
