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
// vngpal.hpp
//
// This file has all of the various palette definitions.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGPAL_HPP
#define __VNGPAL_HPP  1

#define FLX_ONLY   1       // force the use of Felix for the HLS calcs.

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"
#include "felix.hpp"
#include "vngcolor.hpp"
#include "xfile.hpp"
#include <ddraw.h>

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif


void gamma_correct_RGB(VngoColor24bit *p, int count=1);

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Hardware palette class
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoHwPal
{
public:
    VngoColor24bit  p[VNGO_PAL_SIZE];

    int init(VngoColor24bit pal[],int count);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Shade palette classes
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Palette classes
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoPal
{
public:
    VngoShadePal        *shd_pal;
    VngoHwPal           hw_pal;
    VngoClrConvert      convert;
    dword               flags;
    dword               type;
    char                name[16];
    IDirectDrawPalette  *ddpal;


    VngoPal(): shd_pal(0) {ddpal=NULL; }
    virtual ~VngoPal();

    void create_ddpal(LPDIRECTDRAW _dd, IDirectDrawPalette **_ddpal);

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

    VngoPal8();
    virtual ~VngoPal8();
    virtual void release();

// Inline functions.

    dword get_index(VngoColorHLS c) { return (convert.get_index(c));}
    dword get_index(VngoColor24bit c) { return (convert.get_index(c));}
    int set_hwpal(VngoColor24bit pal[],int count) { return (hw_pal.init(pal,count));};
    VngoColor24bit get_RGB(int indx)
    {
        VngoColor24bit tclr;
        if (indx & VNGO_COLOR_15BIT)
        {
            tclr.r = byte((indx & 0x7c00) >> 7);
            tclr.g = byte((indx & 0x3e0) >> 2);
            tclr.b = byte((indx & 0x1f) << 3);
        }
        else if (indx & VNGO_COLOR_16BIT)
        {
            tclr.r = byte((indx & 0xf800) >> 8);
            tclr.g = byte((indx & 0x7e0) >> 3);
            tclr.b = byte((indx & 0x1f) << 3);
        }
        else if (indx & VNGO_COLOR_24BIT)
        {
            tclr.r = byte((indx & 0xff0000) >> 16);
            tclr.g = byte((indx & 0xff00) >> 8);
            tclr.b = byte(indx & 0xff);
        }
        else
        {
            tclr = hw_pal.p[indx];
        }
        return (tclr);
    }

// Initialization of the palette.
    int init(dword flags,VngoHwPal *hw=NULL,VngoShadePal8 *sh=NULL);
    int init(dword flags,const char *palfile);
    int init(dword flags,XFParseIFF *palfile);
};

class VngoPal15 : public VngoPal
{
public:

    VngoPal15();
    virtual ~VngoPal15();
    virtual void release();

// Inline functions.

    dword get_index(VngoColorHLS c) { return (convert.get_index(c));}
    dword get_index(VngoColor24bit c) { return (convert.get_index(c));}
    int set_hwpal(VngoColor24bit pal[],int count) { return (hw_pal.init(pal,count));};
    VngoColor24bit get_RGB(int indx)
    {
        VngoColor24bit tclr;
        if (indx & VNGO_COLOR_15BIT)
        {
            tclr.r = byte((indx & 0x7c00) >> 7);
            tclr.g = byte((indx & 0x3e0) >> 2);
            tclr.b = byte((indx & 0x1f) << 3);
        }
        else if (indx & VNGO_COLOR_16BIT)
        {
            tclr.r = byte((indx & 0xf800) >> 8);
            tclr.g = byte((indx & 0x7e0) >> 3);
            tclr.b = byte((indx & 0x1f) << 3);
        }
        else if (indx & VNGO_COLOR_24BIT)
        {
            tclr.r = byte((indx & 0xff0000) >> 16);
            tclr.g = byte((indx & 0xff00) >> 8);
            tclr.b = byte(indx & 0xff);
        }
        else
        {
            tclr = hw_pal.p[indx];
        }
        return (tclr);
    }

// Initialization of the palette.
    int init(dword flags,VngoHwPal *hw=NULL,VngoShadePal16 *sh=NULL);
    int init(dword flags,const char *palfile);
    int init(dword flags,XFParseIFF *palfile);
};

class VngoPal16 : public VngoPal
{
public:

    VngoPal16();
    virtual ~VngoPal16();
    virtual void release();

// Inline functions.

    dword get_index(VngoColorHLS c) { return (convert.get_index(c));}
    dword get_index(VngoColor24bit c) { return (convert.get_index(c));}
    int set_hwpal(VngoColor24bit pal[],int count) { return (hw_pal.init(pal,count));};
    VngoColor24bit get_RGB(int indx)
    {
        VngoColor24bit tclr;
        if (indx & VNGO_COLOR_15BIT)
        {
            tclr.r = byte((indx & 0x7c00) >> 7);
            tclr.g = byte((indx & 0x3e0) >> 2);
            tclr.b = byte((indx & 0x1f) << 3);
        }
        else if (indx & VNGO_COLOR_16BIT)
        {
            tclr.r = byte((indx & 0xf800) >> 8);
            tclr.g = byte((indx & 0x7e0) >> 3);
            tclr.b = byte((indx & 0x1f) << 3);
        }
        else if (indx & VNGO_COLOR_24BIT)
        {
            tclr.r = byte((indx & 0xff0000) >> 16);
            tclr.g = byte((indx & 0xff00) >> 8);
            tclr.b = byte(indx & 0xff);
        }
        else
        {
            tclr = hw_pal.p[indx];
        }
        return (tclr);
    }

// Initialization of the palette.
    int init(dword flags,VngoHwPal *hw=NULL,VngoShadePal16 *sh=NULL);
    int init(dword flags,const char *palfile);
    int init(dword flags,XFParseIFF *palfile);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Palette I/O classes
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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

class VngoPalIFF15 : public VngoPalIFF
{
public:
    VngoPalIFF15();
    VngoPalIFF15(VngoPal *p);
    virtual int save(const char *filename);
    virtual int save(XFParseIFF *iffp);
    virtual int load(const char *filename);
    virtual int load(XFParseIFF *iffp);
};

class VngoPalIFF16 : public VngoPalIFF
{
public:
    VngoPalIFF16();
    VngoPalIFF16(VngoPal *p);
    virtual int save(const char *filename);
    virtual int save(XFParseIFF *iffp);
    virtual int load(const char *filename);
    virtual int load(XFParseIFF *iffp);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif         // __VNGPAL_HPP

//°±² End of header - vngpal.hpp ²±°
