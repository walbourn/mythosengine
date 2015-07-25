//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
//                              All Rights Reserved.
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
// Created by Chuck Walbourn
//
// xfbitmap.cpp
//
// Contains the code for the XFBitmap container class
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "xfile.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFBitmap - Constructor                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
XFBitmap::XFBitmap() :
    flags(0),
    pal(0),
    data(0),
    palhandle(0),
    handle(0)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFBitmap - Destructor                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
XFBitmap::~XFBitmap()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFBitmap - release                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void XFBitmap::release()
{
    if (palhandle)
    {
        ivory_hfree(&palhandle);
        pal=0;
    }
    if (handle)
    {
        ivory_hfree(&handle);
        data=0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFBitmap - lock                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFBitmap::lock()
{
    xf_error_codes err = XF_ERR_NONE;

    if (!pal && palhandle)
    {
        pal = (dword*)ivory_hlock(palhandle);

        if (!pal)
            err=XF_ERR_LOCKFAILED;
    }
    if (!data && handle)
    {
        data = (byte*)ivory_hlock(handle);

        if (!data)
            err=XF_ERR_LOCKFAILED;
    }

    return err;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFBitmap - unlock                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void XFBitmap::unlock()
{
    if (pal && palhandle)
    {
        ivory_hunlock(palhandle);
        pal=0;
    }
    if (data && handle)
    {
        ivory_hunlock(handle);
        data=0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFBitmap - create                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFBitmap::create(ushort w, ushort h, byte _bpp, int clear)
{
    release();

//ÄÄÄ Verify input
    if (!w || !h)
        return XF_ERR_NOTSUPPORTED;

    switch (_bpp)
    {
        case XFBM_BPP_MONO:
        case XFBM_BPP_8BIT:
        case XFBM_BPP_15BIT:
        case XFBM_BPP_24BIT:
        case XFBM_BPP_32BIT:
            break;
        default:
            return XF_ERR_NOTSUPPORTED;
    }

    width=w;
    height=h;
    bpp=_bpp;

//ÄÄÄ Create palette if needed
    pal=0;
    if (_bpp == XFBM_BPP_8BIT)
    {
        palhandle = ivory_halloc(sizeof(dword)*256);
        if (!palhandle)
            return XF_ERR_NOMEMORY;

        pal = (dword*)ivory_hlock(palhandle);
        if (!pal)
            return XF_ERR_LOCKFAILED;

        if (clear)
            memset(pal,0,sizeof(dword)*256);
    }

//ÄÄÄ Allocate bitmap and possibly clear it
    ulong size = (_bpp == XFBM_BPP_MONO)
                 ? (((w + 7) >> 3) * h)
                 : (w * h * _bpp);

    handle = ivory_halloc(size);
    if (!handle)
    {
        release();
        return XF_ERR_NOMEMORY;
    }

    data = (byte*)ivory_hlock(handle);
    if (!data)
    {
        release();
        return XF_ERR_LOCKFAILED;
    }

    if (clear)
        memset(data,0,size);

    return XF_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFBitmap - generate_mono                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
byte *XFBitmap::generate_mono(dword bgcolor)
{
//ÄÄÄ Verify input
    if (bpp != XFBM_BPP_8BIT || !width || !height)
        return 0;

//ÄÄÄ Allocate result space
    byte *nptr = new byte [((width+7) >> 3) * height];
    if (!nptr)
        return 0;

//ÄÄÄ Lock bitmap
    int locked=0;
    if (data)
    {
        locked=1;
    }
    else if (lock())
    {
        delete nptr;
        return 0;
    }

    if (!data)
    {
        delete nptr;
        return 0;
    }

//ÄÄÄ Convert to mono map
    ulong lwidth = width & ~0x7;
    ulong rwidth = width & 0x7;
    
    byte *dptr=nptr, *sptr=data;
    for (ulong j = 0; j < height; j++)
    {
        if (width >= 8)
        {
            for (ulong i = 0; i < lwidth; i+=8)
            {
                byte t = 0;
                for (ulong k = 0; k < 8; k++)
                {
                    if (*(sptr++) != (byte)bgcolor)
                    {
                        t |= (0x80 >> k);
                    }
                }
                *(dptr++) = t;
            }
        }
        if (rwidth)
        {
            byte t = 0;
            for (ulong k = 0; k < rwidth; k++)
            {
                if (*(sptr++) != (byte)bgcolor)
                    t |= (0x80 >> k);
            }
            *(dptr++) = t;
        }
    }

//ÄÄÄ Unlock and return
    if (!locked)
        unlock();

    return nptr;
}

//°±² End of module - xfbitmap.cpp ²±°
