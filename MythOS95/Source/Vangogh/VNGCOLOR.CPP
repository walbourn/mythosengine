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
// vngcolor.cpp
//
//     The C++ color classes for the VanGogh Draw library.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "debug.h"
#include "portable.h"
#include "ivory.h"
#include "vangogh.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

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

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoClrConvert class.                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void VngoClrConvert::init(VngoPal *my_pal,int flags)
{
    mypal = &((VngoPal8 *)my_pal)->hw_pal;
    if (flags & VNGO_PAL_CALC)
        cvt2_8.init(my_pal);
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Vngo24to8bit color conversion class.                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
VngoColorIndex Vngo24to8bit::get_index(VngoColor24bit clr)
{
    return ((VngoColorIndex)colorconvert[clr.compress()]);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// init()  This function takes a 256 color palette and generates a          �
// look up table that give the index of the 8bit mapped palette color that  �
// is the closest to the 15bit rgb.  It is slow and should only be called   �
// when initializing the system or when the 8bpp palette is changed.        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

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



//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoColor24Bit  Class member functions.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoColor24bit::VngoColor24bit(VngoColorHLS c);                          �
//     This constructor allows a VngoColorHLS to be automaticaly converted  �
//     to a VngoColor24bit, this is handy for doing conversion by           �
//     assignmment.                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
VngoColor24bit::VngoColor24bit(VngoColorHLS c)
{
    VngoColor24bit rgbc;
    rgbc = c.to_RGB();
    r = rgbc.r;
    g = rgbc.g;
    b = rgbc.b;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoColor24Bit::to_HLS();                                                �
//     This function converts an RGB to HLS.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoColorHLS    Class member functions.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoColorHLS::VngoColorHLS(VngoColor24bit c);                            �
//     This constructor allows a VngoColor24bit to be automaticaly converted�
//     to a VngoColorHLS, this is handy for doing conversion by assignmment.�
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
VngoColorHLS::VngoColorHLS(VngoColor24bit c)
{
    VngoColorHLS    rgbc;
    rgbc = c.to_HLS();
    h = rgbc.h;
    l = rgbc.l;
    s = rgbc.s;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoColorHLS::to_RGB();                                                  �
//     This does the explicit conversion of HLS to RGB.                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoColorHLS::value(Flx16 a,Flx16 b,Flx16 c);                            �
//     This is an internal function used by the convertion function to help �
//     convert a VngoColorHLS to a VngoColor24bit.                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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



//葦� End of module - vngcolor.cpp 憶�
