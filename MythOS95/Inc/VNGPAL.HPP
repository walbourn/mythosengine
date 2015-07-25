//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
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
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// Vngpal.hpp  
//
//     This file has all of the various palette definitions.    
//
//อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#ifndef __VNGPAL_HPP
#define __VNGPAL_HPP  1

#define FLX_ONLY   1       // force the use of Felix for the HLS calcs.

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//             
//                                Includes
//                                
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

#include "portable.h"
#include "felix.hpp"
#include "vngcolor.hpp"
#include "xfile.hpp"


//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                Equates
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ


//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                               Prototypes
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

class VngoHwPal
{
public:
    VngoColor24bit  p[VNGO_PAL_SIZE];

    int init(VngoColor24bit pal[],int count);
};


class VngoShadePal
{
public:
    void    *ptr;
    long    num_shd_lvl_bits;
    long    num_shd_lvl;
    long    mid_point;

    // This is the "persistant" format header.
    struct HDR
    {
        long    type;
        long    num_levels;
        long    level_bits;
        long    mid_point;
    };
};

class VngoShadePal8 : public VngoShadePal
{
    byte *p;

    //VngoColorShade8 p[VNGO_PAL_SIZE];
public:

    int get_shaded_index(int color, int shade)
    {
        return (p[(color << num_shd_lvl_bits) + (shade >> (8 - num_shd_lvl_bits))]);
    }
    VngoColorShade8 &operator[] (int i)
    {
        return *(VngoColorShade8 *)(p + (i << num_shd_lvl_bits));
    }

    VngoShadePal8 (int shade_levels)
    {
        num_shd_lvl = shade_levels;
        num_shd_lvl_bits = 0;
        while (shade_levels > 1)
        {
            num_shd_lvl_bits++;
            shade_levels >>= 1;
        }

        p = new byte[VNGO_PAL_SIZE << num_shd_lvl_bits];
        ptr = p;
    }

    ~VngoShadePal8 ()
    {
        if (p != 0)
        {
            delete [] p;
            p = 0;
        }
    }
};



class VngoShadePal15 : public VngoShadePal
{
    word    *p;

    //VngoColorShade15 p[VNGO_PAL_SIZE];
public:

    int get_shaded_index(int color, int shade)
    {
        return (p[(color << num_shd_lvl_bits) + (shade >> (8 - num_shd_lvl_bits))]);
    }
    VngoColorShade15 &operator[] (int i)
    {
        return *(VngoColorShade15 *)(p + (i << num_shd_lvl_bits));
    }

    VngoShadePal15 (int shade_levels)
    {
        num_shd_lvl = shade_levels;
        num_shd_lvl_bits = 0;
        while (shade_levels > 1)
        {
            num_shd_lvl_bits++;
            shade_levels >>= 1;
        }

        p = new word[VNGO_PAL_SIZE << num_shd_lvl_bits];
        ptr = p;
    }

    ~VngoShadePal15 ()
    {
        if (p != 0)
        {
            delete [] p;
            p = 0;
        }
    }
};


class VngoShadePal16 : public VngoShadePal
{
    word    *p;

    //VngoColorShade16 p[VNGO_PAL_SIZE];
public:

    int get_shaded_index(int color, int shade)
    {
        return (p[(color << num_shd_lvl_bits) + (shade >> (8 - num_shd_lvl_bits))]);
    }
    VngoColorShade16 &operator[] (int i)
    {
        return *(VngoColorShade16 *)(p + (i << num_shd_lvl_bits));
    }

    VngoShadePal16 (int shade_levels)
    {
        num_shd_lvl = shade_levels;
        num_shd_lvl_bits = 0;
        while (shade_levels > 1)
        {
            num_shd_lvl_bits++;
            shade_levels >>= 1;
        }

        p = new word[VNGO_PAL_SIZE << num_shd_lvl_bits];
        ptr = p;
    }

    ~VngoShadePal16 ()
    {
        if (p != 0)
        {
            delete [] p;
            p = 0;
        }
    }
};


class VngoPal
{
public:
    VngoShadePal    *shd_pal;

    dword           flags;
    dword           type;
    char            name[16];


    VngoPal() {shd_pal=NULL; }
    virtual ~VngoPal();

// Virtual Utility functions.
    virtual void release();

// Virtual Color based functions.
    virtual dword get_index(VngoColorHLS c) = 0;
    virtual dword get_index(VngoColor24bit c) = 0;
    virtual int set_hwpal(VngoColor24bit pal[],int count) = 0;
    virtual VngoColor24bit get_RGB(int indx) = 0;

// Initialization of the palette.
    virtual int init(dword flags,const char *palfile) = 0;
    virtual int init(dword flags,XFParseIFF *palfile) = 0;

};

class VngoPal8 : public VngoPal
{
public:
    VngoHwPal       hw_pal;
    VngoClrConvert  convert;

//    VngoPal8() {shd_pal=NULL;}
//   ~VngoPal8();


// Inline functions.

    dword get_index(VngoColorHLS c) { return (convert.get_index(c));}
    dword get_index(VngoColor24bit c) { return (convert.get_index(c));}
    int set_hwpal(VngoColor24bit pal[],int count) { return (hw_pal.init(pal,count));};
    VngoColor24bit get_RGB(int indx) { return (hw_pal.p[indx]);}

// Initialization of the palette.
    int init(dword flags,VngoHwPal *hw=NULL,VngoShadePal8 *sh=NULL);
    int init(dword flags,const char *palfile);
    int init(dword flags,XFParseIFF *palfile);
};


class VngoPalIFF 
{
public:
    VngoPal         *pal;
    char            name[16];

public:
    VngoPalIFF() {};
    VngoPalIFF(VngoPal *p) {pal = p;};

    virtual int save(const char *filename) = 0;
    virtual int save(XFParseIFF *iffp) = 0;
    virtual int load(const char *filename) = 0;
    virtual int load(XFParseIFF *iffp) = 0;
};

class VngoPalIFF8 : public VngoPalIFF
{
public:
    VngoPalIFF8();
    VngoPalIFF8(VngoPal *p);
    virtual int save(const char *filename);
    virtual int save(XFParseIFF *iffp);
    virtual int load(const char *filename);
    virtual int load(XFParseIFF *iffp);
};


#endif         // __VNGPAL_HPP
//ฐฑฒ End of header - VNGPAL.hpp ฒฑฐ
