//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.
//                             All Rights Reserved.
//                        Microsoft Windows '95 Version
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
// xfbitmap.hpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __XFBITMAP_HPP
#define __XFBITMAP_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//             
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <ivory.hpp>

#include "xfbase.hpp"
#include "xfiff.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

const ulong    XF_MAX_WIDTH    =65535;
const ulong    XF_MAX_HEIGHT   =65535;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct XFXEBHeader
{
    ushort  version;
    ushort  width;
    ushort  height;
    byte    bpp;
    char    na[9];
};

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Bitmap Object read/written by XFileBitmap.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class XFBitmap {
public:         
    word        flags;          // Flags for bitmap.
    ushort      width;          // X-size of bitmap
    ushort      height;         // Y-size of bitmap
    byte        bpp;            // Bytes per pixel for bitmap (1 or 3)
    byte        clrinuse;       // Highest pal index in use
    dword       *pal;           // Pointer to locked palette data, if any.
    byte        *data;          // Pointer to locked bitmap data.
    IvoryHandle palhandle;      // Palette data handle (256 dword table) 
    IvoryHandle handle;         // Bitmap handle

    XFBitmap();
    ~XFBitmap();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations on bitmap objects.                                        ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void release();

    xf_error_codes lock();
    void unlock();

    xf_error_codes create(ushort w, ushort h, byte _bpp=1, int clear=1);

    byte *generate_mono(dword bgcolor);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Abstract base object for reading/writing bitmap files.                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class XFParseBitmap {
    XFileDiskBuf    xfile;
    XFBitmap        bitmap;

protected:
    XFile           *xf;
    xf_error_codes  errorn;

public:
    XFBitmap        *bm;

    XFParseBitmap();
    XFParseBitmap(XFile *f);
    XFParseBitmap(XFBitmap *b);
    XFParseBitmap(XFile *f, XFBitmap *b);
    virtual ~XFParseBitmap();
   
    void attach(XFile *f) { if (!f) {xf=&xfile;} else {xf=f;} };

    xf_error_codes error(void) { return errorn; };

           //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
           // Reads the given data into the object, freeing up any          ³
           // previously loaded bitmap in the object's memory.              ³
           //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    xf_error_codes nameread(const char *name, XFBitmap *bm=0);
    virtual xf_error_codes read(XFBitmap *bm=0)=0;


           //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
           // Writes the bitmap in the object's memory to the given file.   ³
           //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    xf_error_codes namewrite(const char *name, XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0)=0;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Bitmap reading/writing objects for various formats.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄ Windows BMP
class XFParseBMP : public XFParseBitmap {
public:
    XFParseBMP() {};
    XFParseBMP(XFile *f) : XFParseBitmap(f) {};
    XFParseBMP(XFBitmap *b) : XFParseBitmap(b) {};
    XFParseBMP(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {};

    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};

//ÄÄ Autodesk's CEL
class XFParseCEL : public XFParseBitmap {
public:
    XFParseCEL() {};
    XFParseCEL(XFile *f) : XFParseBitmap(f) {};
    XFParseCEL(XFBitmap *b) : XFParseBitmap(b) {};
    XFParseCEL(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {};

    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};

//ÄÄ IFF Standard ILBM
class XFParseLBM : public XFParseBitmap {
public:
    XFParseLBM() {};
    XFParseLBM(XFile *f) : XFParseBitmap(f) {};
    XFParseLBM(XFBitmap *b) : XFParseBitmap(b) {};
    XFParseLBM(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {};

    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);

    xf_error_codes read(XFParseIFF *iff, XFBitmap *b=0);
    xf_error_codes write(XFParseIFF *iff, XFBitmap *b=0);
};

//ÄÄ Zsoft's PCX
class XFParsePCX : public XFParseBitmap {
public:
    XFParsePCX() {};
    XFParsePCX(XFile *f) : XFParseBitmap(f) {};
    XFParsePCX(XFBitmap *b) : XFParseBitmap(b) {};
    XFParsePCX(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {};

    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};

//ÄÄ Targa TrueVision TGA
class XFParseTGA : public XFParseBitmap {
public:
    XFParseTGA() {};
    XFParseTGA(XFile *f) : XFParseBitmap(f) {};
    XFParseTGA(XFBitmap *b) : XFParseBitmap(b) {};
    XFParseTGA(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {};

    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};

//ÄÄ Charybdis' XEB format
class XFParseXEB : public XFParseBitmap {
public:
    XFParseXEB() {};
    XFParseXEB(XFile *f) : XFParseBitmap(f) {};
    XFParseXEB(XFBitmap *b) : XFParseBitmap(b) {};
    XFParseXEB(XFile *f, XFBitmap *b) : XFParseBitmap(f,b) {};

    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);

    xf_error_codes read(XFParseIFF *iff, XFBitmap *b=0);
    xf_error_codes write(XFParseIFF *iff, XFBitmap *b=0);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - xfbitmap.hpp ²±°

