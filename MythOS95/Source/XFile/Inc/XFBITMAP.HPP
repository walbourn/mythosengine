//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//                    Microsoft Windows 95/98/NT Version
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
// Created by Chuck Walbourn
//
// xfbitmap.hpp
//
// Contains the classes for working with bitmap files.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __XFBITMAP_HPP
#define __XFBITMAP_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <ivory.hpp>

#include "xfbase.hpp"
#include "xfiff.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define XF_MAX_WIDTH    65535
#define XF_MAX_HEIGHT   65535

#define XF_XEB_COMPRESS_RLE     0
#define XF_XEB_COMPRESS_NONE    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

struct XFXEBHeader
{
    ushort  version;
    ushort  width;
    ushort  height;
    byte    bpp;
    byte    compress;
    char    na[8];
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFBitmap - Bitmap container class.                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFBitmap
{
public:
    word        flags;          // Flags for bitmap.
    ushort      width;          // X-size of bitmap
    ushort      height;         // Y-size of bitmap
    byte        bpp;            // Bytes per pixel for bitmap
    byte        clrinuse;       // Highest pal index in use
    dword       *pal;           // Pointer to locked palette data, if any.
    byte        *data;          // Pointer to locked bitmap data.
    IvoryHandle palhandle;      // Palette data handle (256 dword table)
    IvoryHandle handle;         // Bitmap handle

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    XFBitmap();
    ~XFBitmap();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void release();

    xf_error_codes lock();
    void unlock();

    xf_error_codes create(ushort w, ushort h, byte _bpp=XFBM_BPP_8BIT,
                          int clear=1);

    byte *generate_mono(dword bgcolor);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseBitmap - Abstract base object for reading/writing bitmap files.   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFParseBitmap
{
    XFileDiskBuf    xfile;
    XFBitmap        bitmap;

protected:
    XFile           *xf;
    xf_error_codes  errorn;

public:
    XFBitmap        *bm;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    XFParseBitmap();
    XFParseBitmap(XFile *f);
    XFParseBitmap(XFBitmap *b);
    XFParseBitmap(XFile *f, XFBitmap *b);

    virtual ~XFParseBitmap();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void attach(XFile *f) { if (!f) {xf=&xfile;} else {xf=f;} };

    xf_error_codes error(void) { return errorn; };

    xf_error_codes nameread(const char *name, XFBitmap *bm=0);
    virtual xf_error_codes read(XFBitmap *bm=0)=0;

    xf_error_codes namewrite(const char *name, XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0)=0;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseBMP - Windows BMP format.                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFParseBMP : public XFParseBitmap
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    XFParseBMP() : XFParseBitmap() {}
    XFParseBMP(XFile *f) : XFParseBitmap(f) {}
    XFParseBMP(XFBitmap *b) : XFParseBitmap(b) {}
    XFParseBMP(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseCEL - Autodesk's CEL format.                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFParseCEL : public XFParseBitmap
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    XFParseCEL() : XFParseBitmap()  {}
    XFParseCEL(XFile *f) : XFParseBitmap(f) {}
    XFParseCEL(XFBitmap *b) : XFParseBitmap(b) {}
    XFParseCEL(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);

    xf_error_codes read(ushort &xcoord, ushort &ycoord, XFBitmap *b=0);
    xf_error_codes write(ushort xcoord, ushort ycoord, XFBitmap *b=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseLBM - IFF Standard ILBM format.                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFParseLBM : public XFParseBitmap
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    XFParseLBM() : XFParseBitmap()  {}
    XFParseLBM(XFile *f) : XFParseBitmap(f) {}
    XFParseLBM(XFBitmap *b) : XFParseBitmap(b) {}
    XFParseLBM(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);

    xf_error_codes read(XFParseIFF *iff, XFBitmap *b=0);
    xf_error_codes write(XFParseIFF *iff, XFBitmap *b=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParsePCX - Zsoft's PCX format.                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFParsePCX : public XFParseBitmap
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    XFParsePCX() : XFParseBitmap() {}
    XFParsePCX(XFile *f) : XFParseBitmap(f) {}
    XFParsePCX(XFBitmap *b) : XFParseBitmap(b) {}
    XFParsePCX(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseTGA - TrueVision's Targa Format.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFParseTGA : public XFParseBitmap
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    XFParseTGA() : XFParseBitmap()  {}
    XFParseTGA(XFile *f) : XFParseBitmap(f) {}
    XFParseTGA(XFBitmap *b) : XFParseBitmap(b) {}
    XFParseTGA(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseXEB - Charybdis' XFile Encoded Bitmap format.                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFParseXEB : public XFParseBitmap
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    XFParseXEB() : XFParseBitmap()  {}
    XFParseXEB(XFile *f) : XFParseBitmap(f) {}
    XFParseXEB(XFBitmap *b) : XFParseBitmap(b) {}
    XFParseXEB(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);

    xf_error_codes read(XFParseIFF *iff, XFBitmap *b=0);
    xf_error_codes write(XFParseIFF *iff, XFBitmap *b=0);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility members                                                      �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    static ulong compress_rle_mono(ushort w, ushort h,
                                   byte *data, byte *cdata);
    static int uncompress_rle_mono(ushort w, ushort h, ulong csize,
                                   byte *cdata, byte *data);

    static ulong compress_rle_8bpp(ushort w, ushort h,
                                   byte *data, byte *cdata);
    static int uncompress_rle_8bpp(ushort w, ushort h, ulong csize,
                                   byte *cdata, byte *data);

    static ulong compress_rle_16bpp(ushort w, ushort h,
                                    byte *data, byte *cdata);
    static int uncompress_rle_16bpp(ushort w, ushort h, ulong csize,
                                    byte *cdata, byte *data);

    static ulong compress_rle_24bpp(ushort w, ushort h,
                                    byte *data, byte *cdata);
    static int uncompress_rle_24bpp(ushort w, ushort h, ulong csize,
                                    byte *cdata, byte *data);

    static ulong compress_rle_32bpp(ushort w, ushort h,
                                    byte *data, byte *cdata);
    static int uncompress_rle_32bpp(ushort w, ushort h, ulong csize,
                                    byte *cdata, byte *data);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - xfbitmap.hpp 憶�

