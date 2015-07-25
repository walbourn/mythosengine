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
// vngpal.cpp
//
//     The C++ palette classes for the VanGogh Draw library.
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
#include "ivory.h"
#include "vangogh.hpp"
#include "xfile.hpp"
#include <ddraw.h>

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
extern VngoSystem *VgSystem;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoHwPal °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoHwPal::init(VngoColor24bit pal[],int count);                         ³
//     This function sets the first count number of palette entries to the  ³
//     the values stored in the pal array that is passed in.  It does not   ³
//     modeify the current state of the hardware, it simply modifies the    ³
//     table entries.  If you pass in the flag VNGO_PAL_HWINIT, it will     ³
//     update the hardware as well.                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoHwPal::init(VngoColor24bit pal[],int count)
{
    for (int i=0;i < count;i++)
    {
        p[i] = pal[i];
    }
    return (0);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoPal °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::release                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void VngoPal::release()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
}


void VngoPal::create_ddpal(LPDIRECTDRAW _dd,IDirectDrawPalette **_ddpal)
{
    if (ddpal != NULL)
    {
        *_ddpal = ddpal;
    }
    else if (_dd != NULL)
    {
        PALETTEENTRY        ape[256];
        for (int i=0;i < 255;i++)
        {
            ape[i].peRed = hw_pal.p[i].r;
            ape[i].peGreen = hw_pal.p[i].g;
            ape[i].peBlue = hw_pal.p[i].b & 0xfe;
        }
        ape[256].peRed = 48;
        ape[256].peRed = 48;
        ape[256].peRed = 48;

//        ape[256].peRed = hw_pal.p[256].r;
//        ape[256].peRed = hw_pal.p[256].g;
//        ape[256].peRed = hw_pal.p[256].b;

        _dd->CreatePalette(DDPCAPS_8BIT,ape,&ddpal,NULL);
        *_ddpal = ddpal;
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::~VngoPal();                                                     ³
//     This is the destructor for the VngoPal.  It will delete any memory   ³
//     that was allocated during the construction of this class.            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPal::~VngoPal()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
    if (ddpal != NULL)
    {
        ddpal->Release();
        ddpal=NULL;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal8::VngoPal8();                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPal8::VngoPal8()
{
    flags = VNGO_8BIT;
    shd_pal = NULL;
    ddpal = NULL;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal8::~VngoPal8();                                                   ³
//     This is the destructor for the VngoPal.  It will delete any memory   ³
//     that was allocated during the construction of this class.            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPal8::~VngoPal8()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete (VngoShadePal8 *)shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal8::release                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void VngoPal8::release()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete (VngoShadePal8 *)shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword _flags,VngoHwPal *hw,VngoShadePal *hz);              ³
//     This function will allocate memory for any of the structures that    ³
//     you do not pass a buffer in for.                                     ³
//     If you pass in the VNGO_PAL_HWINIT flag, it will write the passed in ³
//     hardware palette, if you didn't pass in a VngoHwPal then this flag is³
//     ignored.                                                             ³
//     If you pass in the VNGO_PAL_CALC flag, it will initialize the all    ³
//     three of the calculated tables in this order:                        ³
//         1)  Color conversion table.                                      ³
//         2)  Shade Palette table.                                         ³
//         3)  Haze Palette table.                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal8::init(dword _flags,VngoHwPal *hw,VngoShadePal8 *sh)
{
    if (hw)
    {
        for (int i=0;i < 256;i++)
        {
            hw_pal.p[i] = hw->p[i];
        }
    }
    if (!sh)
    {
        if (!shd_pal)
        {
            shd_pal = (VngoShadePal *)new VngoShadePal8 (32);
            flags |= VNGO_MYMEM_SHADE;
        }
        // Once there is a mechanism to initialize the palette with a specified
        // number of shade levels rather than the hard coded 32, then more
        // checking will need to be done here.
    }
    else
    {
        shd_pal = (VngoShadePal *)sh;
    }


    if (_flags & VNGO_PAL_CALC)
    {
        convert.init(this,1);
    }
    else
    {
        convert.init(this);
    }

    return (0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword _flags,const char *palfile);                         ³
//     This function will load a palette from a file whos name is passed in.³
//     It will fist initialize a palette to get all of the required memory  ³
//     allocated, and will not do any of the calculations.  It will then    ³
//     read the palette from the specified file, and write it to the        ³
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal8::init(dword _flags,const char *palfile)
{
    int         err;
    VngoPalIFF8 loadpal(this);

    init(0);
    err=loadpal.load(palfile);
    return (err);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword _flags,char *palfile);                               ³
//     This function will load a palette from a file whos name is passed in.³
//     It will fist initialize a palette to get all of the required memory  ³
//     allocated, and will not do any of the calculations.  It will then    ³
//     read the palette from the specified file, and write it to the        ³
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal8::init(dword _flags,XFParseIFF *palfile)
{
    int         err;
    VngoPalIFF8 loadpal(this);

    init(0);
    err=loadpal.load(palfile);

    return (err);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoPalIFF8 °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF8::VngoPalIFF8();                                              ³
//     This  constructor will set the palettes name to 'Default' and set the³
//     palette pointer to NULL.  No reading or writing will take place.     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPalIFF8::VngoPalIFF8()
{
    name[0]='D';
    name[1]='e';
    name[2]='f';
    name[3]='a';
    name[4]='u';
    name[5]='l';
    name[6]='t';
    name[7]=0;

    pal = NULL;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF8::VngoPalIFF8(VngoPal *p);                                    ³
//     This  constructor will set the palettes name to 'Default' and set the³
//     palette pointer to the passed in palette. No file IO will take place.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPalIFF8::VngoPalIFF8(VngoPal *p)
{
    name[0]='D';
    name[1]='e';
    name[2]='f';
    name[3]='a';
    name[4]='u';
    name[5]='l';
    name[6]='t';
    name[7]=0;

    pal = (VngoPal8 *)p;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF8::save(const char *filename);                                 ³
//     This  will save the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be stored to the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF8::save(const char *filename)
{
    XFParseIFF  iffp;
    int         err=0;

    // Assert that there is memory allocated for all fields.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);

    err=iffp.create(filename,0);
    if (err)
        return(err);

    err = save(&iffp);
    if (err)
        return (err);

    return ( iffp.close() );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF8::save(XFParseIFF *iffp);                                     ³
//     This  will save the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be stored to the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF8::save(XFParseIFF *iffp)
{
    int             err=0;
    VngoShadePal8   *tpal = (VngoShadePal8 *)pal->shd_pal;

    // Assert that there is memory allocated for all fields.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);

    err = iffp->newform(iffp->makeid('V','P','A','L'));
    if (err)
        return(err);

    // ---- Write the name of the palette.
    err = iffp->write(iffp->makeid('n','a','m','e'),name,16);
    if (err)
        return(err);

    // ---- Save the shade palette.

    err = iffp->newform (iffp->makeid('s','h','d','P'));
    if (err)
        return(err);

    VngoShadePal::HDR hdr;
    hdr.type = VNGO_8BIT;
    hdr.num_levels = tpal->num_shd_lvl;
    hdr.level_bits = tpal->num_shd_lvl_bits;
    hdr.mid_point  = tpal->mid_point;

    // output the number of shade levels in the shade palette.
    err = iffp->write(iffp->makeid ('H','D','R',' '), &hdr, sizeof(hdr));
    if (err)
        return(err);

    dword id = iffp->makeid('s','h','d','L');
    for (int i=0; i < VNGO_PAL_SIZE;i++)
    {
        err = iffp->write (id, &(*tpal)[i], tpal->num_shd_lvl * sizeof (byte));
        if (err)
            return(err);
    }

    iffp->leaveform();


    // ---- Save the hardware palette.
    err = iffp->write(iffp->makeid('h','w','d','P'), &((VngoPal8 *)pal)->hw_pal,sizeof(VngoHwPal));
    if (err)
        return(err);

    // ---- Save the color conversion table.
    err = iffp->write(iffp->makeid('c','n','v','t'),&((VngoPal8 *)pal)->convert,sizeof(VngoClrConvert));
    if (err)
        return(err);

    err = iffp->leaveform();

    return(err);

}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF8::load(const char *filename);                                 ³
//     This  will load the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be read from the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF8::load(const char *filename)
{
    XFParseIFF      iffp;
    int             err=0;

    // Assert that there is memory allocated to load into.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);

    err=iffp.open(filename,XF_OPEN_READ);
    if (err)
        return (err);

    err = load(&iffp);
    if (err)
        return (err);

    return (iffp.close() );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF8::load(XFParseIFF *iffp);                                     ³
//     This  will load the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be read from the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF8::load(XFParseIFF *iffp)
{
    int             err=0;
    VngoShadePal8   *tpal = (VngoShadePal8 *)pal->shd_pal;

    // Assert that there is memory allocated to load into.
    assert(tpal != NULL);
    assert(pal->shd_pal != NULL);
    //assert(pal->hz_pal != NULL);

find_pal:

    err = iffp->seekform(iffp->makeid('V','P','A','L'));
    if (err)
        return (err);

    err = iffp->enterform();
    if (err)
        return (err);

    char nbuff[16];
    err = iffp->seekchunk (iffp->makeid('n','a','m','e'));
    if (err)
        return err;

    if (sizeof(nbuff) < iffp->chunkSize)
        return XF_ERR_CHUNKNOTFOUND;

    err = iffp->read(nbuff);
    if (err)
        return err;

    if (strcmp(name,"Default"))
    {
        if (strcmp(name,nbuff))
        {
            iffp->leaveform();
            goto find_pal;
        }
    }

    strncpy(name,nbuff,16);

    // ---- Find and read the shade palette.

    err = iffp->seekform (iffp->makeid('s','h','d','P'));
    if (err)
        return(err);

    err = iffp->enterform();
    if (err)
        return (err);

    VngoShadePal::HDR hdr;
    err = iffp->seekchunk (iffp->makeid ('H','D','R',' '));
    if (err)
        return (err);

    if (sizeof (hdr) != iffp->chunkSize)
        return XF_ERR_CHUNKNOTFOUND;

    err = iffp->read (&hdr);
    if (err)
        return (err);

    if (hdr.type != VNGO_8BIT)
        return XF_ERR_CHUNKNOTFOUND;

    // Get the new information
    tpal->num_shd_lvl = hdr.num_levels;
    tpal->num_shd_lvl_bits = hdr.level_bits;
    int tbits = 8 - hdr.level_bits;
    tpal->mid_point = ((hdr.mid_point >> tbits) - 1) << tbits;

    dword id = iffp->makeid('s','h','d','L');
    for (int i=0; i < VNGO_PAL_SIZE; i++)
    {
        err = iffp->seekchunk (id);
        if (err)
            return (err);

        if (tpal->num_shd_lvl * sizeof (byte) != iffp->chunkSize)
            return XF_ERR_CHUNKNOTFOUND;

        err = iffp->read (&(*tpal)[i]);
        if (err)
            return (err);
    }
    iffp->leaveform();


    // ---- Find and read the hardware palette.
    err = iffp->seekchunk(iffp->makeid('h','w','d','P'));
    if (err)
        return (err);

    err = iffp->read(&((VngoPal8 *)pal)->hw_pal);
    if (err)
        return (err);

    // ---- Find and read the color conversion table.
    err = iffp->seekchunk(iffp->makeid('c','n','v','t'));
    if (err)
        return (err);

    err = iffp->read(&((VngoPal8 *)pal)->convert);
    if (err)
        return (err);

    // ---- Clean up and close down.
    err = iffp->leaveform();

    gamma_correct_RGB(pal->hw_pal.p,256);
    return (err);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal15::VngoPal15();                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPal15::VngoPal15()
{
    flags = VNGO_15BIT;
    shd_pal=NULL;
    ddpal = NULL;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal15::~VngoPal15();                                                 ³
//     This is the destructor for the VngoPal.  It will delete any memory   ³
//     that was allocated during the construction of this class.            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPal15::~VngoPal15()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete (VngoShadePal15 *)shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal15::release                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void VngoPal15::release()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete (VngoShadePal15 *)shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword _flags,VngoHwPal *hw,VngoShadePal *hz);              ³
//     This function will allocate memory for any of the structures that    ³
//     you do not pass a buffer in for.                                     ³
//     If you pass in the VNGO_PAL_HWINIT flag, it will write the passed in ³
//     hardware palette, if you didn't pass in a VngoHwPal then this flag is³
//     ignored.                                                             ³
//     If you pass in the VNGO_PAL_CALC flag, it will initialize the all    ³
//     three of the calculated tables in this order:                        ³
//         1)  Color conversion table.                                      ³
//         2)  Shade Palette table.                                         ³
//         3)  Haze Palette table.                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal15::init(dword _flags,VngoHwPal *hw,VngoShadePal16 *sh)
{
    ddpal=NULL;
    if (hw)
    {
        for (int i=0;i < 256;i++)
        {
            hw_pal.p[i] = hw->p[i];
        }
    }
    if (!sh)
    {
        if (!shd_pal)
        {
            shd_pal = (VngoShadePal *)new VngoShadePal16 (32);
            flags |= VNGO_MYMEM_SHADE;
        }
        // Once there is a mechanism to initialize the palette with a specified
        // number of shade levels rather than the hard coded 32, then more
        // checking will need to be done here.
    }
    else
    {
        shd_pal = (VngoShadePal *)sh;
    }


    if (_flags & VNGO_PAL_CALC)
    {
        convert.init(this,1);
    }
    else
    {
        convert.init(this);
    }

    return (0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword _flags,const char *palfile);                         ³
//     This function will load a palette from a file whos name is passed in.³
//     It will fist initialize a palette to get all of the required memory  ³
//     allocated, and will not do any of the calculations.  It will then    ³
//     read the palette from the specified file, and write it to the        ³
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal15::init(dword _flags,const char *palfile)
{
    int             err = 0;
    VngoPalIFF15    loadpal(this);

    ddpal=NULL;
    init(0);
    err=loadpal.load(palfile);

    return (err);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword _flags,char *palfile);                               ³
//     This function will load a palette from a file whos name is passed in.³
//     It will fist initialize a palette to get all of the required memory  ³
//     allocated, and will not do any of the calculations.  It will then    ³
//     read the palette from the specified file, and write it to the        ³
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal15::init(dword _flags,XFParseIFF *palfile)
{
    int             err = 0;
    VngoPalIFF15    loadpal(this);

    ddpal=NULL;
    init(0);
    err=loadpal.load(palfile);

    return (err);
}


STATIC void calc_linear_colors15 (word *colors, int steps,
                                  VngoColor24bit color, int break_point)
{
    float           tr,tg,tb;
    VngoColor24bit  tclr;

    tr = float(color.r);
    tg = float(color.g);
    tb = float(color.b);


    float   rstep = tr / float(break_point);
    float   gstep = tg / float(break_point);
    float   bstep = tb / float(break_point);

    for (int i = break_point; i >= 0; i--)
    {
        tclr.r = int(tr + 0.5f);
        tclr.g = int(tg + 0.5f);
        tclr.b = int(tb + 0.5f);
        tr -= rstep;
        tg -= gstep;
        tb -= bstep;
        colors[i] = tclr.compress();
    }


    tr = float(color.r);
    tg = float(color.g);
    tb = float(color.b);

    rstep = (255.f - tr) / float(steps - break_point);
    gstep = (255.f - tg) / float(steps - break_point);
    bstep = (255.f - tb) / float(steps - break_point);

    for (i = break_point+1; i < steps; i++)
    {
        tr += rstep;
        tg += gstep;
        tb += bstep;
        tclr.r = int(tr + 0.5f);
        tclr.g = int(tg + 0.5f);
        tclr.b = int(tb + 0.5f);
        colors[i] = tclr.compress();
    }
}


void MakePal15fromPal8(VngoPal15 *p15, VngoPal8 *p8)
{
    // This will mock up a Pal16 using the Pal8s shade info.
    byte *data8 = (byte *)(p8->shd_pal->ptr);
    word *data15 = (word *)(p15->shd_pal->ptr);

// This will go through and make a 16bit shade_pal.  Not that the
// memory has to be allocated before you get to this routine.
    for (int i=0;i < 256;i++)
    {
        calc_linear_colors15(&data15[i <<5],32,p8->get_RGB(i),
                             p8->shd_pal->mid_point >> (8 - p8->shd_pal->num_shd_lvl_bits));
    }
    for (i=0;i < 256;i++)
    {
        p15->hw_pal.p[i] = p8->hw_pal.p[i];
    }
    for (i=0;i < 32768; i++)
    {
        p15->convert.cvt2_8.colorconvert[i] = p8->convert.cvt2_8.colorconvert[i];
    }
    p15->shd_pal->mid_point = p8->shd_pal->mid_point;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoPalIFF15 °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF15::VngoPalIFF15();                                            ³
//     This  constructor will set the palettes name to 'Default' and set the³
//     palette pointer to NULL.  No reading or writing will take place.     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPalIFF15::VngoPalIFF15()
{
    name[0]='D';
    name[1]='e';
    name[2]='f';
    name[3]='a';
    name[4]='u';
    name[5]='l';
    name[6]='t';
    name[7]=0;

    pal = NULL;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF15::VngoPalIFF15(VngoPal *p);                                  ³
//     This  constructor will set the palettes name to 'Default' and set the³
//     palette pointer to the passed in palette. No file IO will take place.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VngoPalIFF15::VngoPalIFF15(VngoPal *p)
{
    name[0]='D';
    name[1]='e';
    name[2]='f';
    name[3]='a';
    name[4]='u';
    name[5]='l';
    name[6]='t';
    name[7]=0;

    pal = (VngoPal15 *)p;
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF15::save(const char *filename);                                ³
//     This  will save the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be stored to the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF15::save(const char *filename)
{
    XFParseIFF  iffp;
    int         err=0;
    return(err);

    // Assert that there is memory allocated for all fields.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);

    err=iffp.create(filename,0);
    if (err)
        return(err);

    err = save(&iffp);
    if (err)
        return (err);

    return ( iffp.close() );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF15::save(XFParseIFF *iffp);                                    ³
//     This  will save the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be stored to the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF15::save(XFParseIFF *iffp)
{
    int             err=0;
    return(err);

    VngoShadePal8   *tpal = (VngoShadePal8 *)pal->shd_pal;

    // Assert that there is memory allocated for all fields.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);

    err = iffp->newform(iffp->makeid('V','P','A','L'));
    if (err)
        return(err);

    // ---- Write the name of the palette.
    err = iffp->write(iffp->makeid('n','a','m','e'),name,16);
    if (err)
        return(err);

    // ---- Save the shade palette.

    err = iffp->newform (iffp->makeid('s','h','d','P'));
    if (err)
        return(err);

    VngoShadePal::HDR hdr;
    hdr.type = VNGO_8BIT;
    hdr.num_levels = tpal->num_shd_lvl;
    hdr.level_bits = tpal->num_shd_lvl_bits;
    hdr.mid_point  = tpal->mid_point;

    // output the number of shade levels in the shade palette.
    err = iffp->write(iffp->makeid ('H','D','R',' '), &hdr, sizeof(hdr));
    if (err)
        return(err);

    dword id = iffp->makeid('s','h','d','L');
    for (int i=0; i < VNGO_PAL_SIZE;i++)
    {
        err = iffp->write (id, &(*tpal)[i], tpal->num_shd_lvl * sizeof (byte));
        if (err)
            return(err);
    }

    iffp->leaveform();


    // ---- Save the hardware palette.
    err = iffp->write(iffp->makeid('h','w','d','P'), &((VngoPal8 *)pal)->hw_pal,sizeof(VngoHwPal));
    if (err)
        return(err);

    // ---- Save the color conversion table.
    err = iffp->write(iffp->makeid('c','n','v','t'),&((VngoPal8 *)pal)->convert,sizeof(VngoClrConvert));
    if (err)
        return(err);

    err = iffp->leaveform();

    return(err);

}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF15::load(const char *filename);                                ³
//     This  will load the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be read from the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF15::load(const char *filename)
{
    XFParseIFF      iffp;
    int             err=0;

    // Assert that there is memory allocated to load into.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);
    //assert(pal->hz_pal != NULL);

    err=iffp.open(filename,XF_OPEN_READ);
    if (err)
        return (err);

    err = load(&iffp);
    if (err)
        return (err);

    return (iffp.close() );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF15::load(XFParseIFF *iffp);                                    ³
//     This  will load the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be read from the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF15::load(XFParseIFF *iffp)
{
    int             err=0;
    VngoShadePal15  *tpal = (VngoShadePal15 *)pal->shd_pal;

    // Assert that there is memory allocated to load into.
    assert(tpal != NULL);
    assert(pal->shd_pal != NULL);
    //assert(pal->hz_pal != NULL);

find_pal:

    err = iffp->seekform(iffp->makeid('V','P','A','L'));
    if (err)
        return (err);

    err = iffp->enterform();
    if (err)
        return (err);

    char nbuff[16];
    err = iffp->seekchunk (iffp->makeid('n','a','m','e'));
    if (err)
        return err;

    if (sizeof(nbuff) < iffp->chunkSize)
        return XF_ERR_CHUNKNOTFOUND;

    err = iffp->read(nbuff);
    if (err)
        return err;

    if (strcmp(name,"Default"))
    {
        if (strcmp(name,nbuff))
        {
            iffp->leaveform();
            goto find_pal;
        }
    }

    strncpy(name,nbuff,16);

    // ---- Find and read the shade palette.

    err = iffp->seekform (iffp->makeid('s','h','d','P'));
    if (err)
        return(err);

    err = iffp->enterform();
    if (err)
        return (err);

    VngoShadePal::HDR hdr;
    err = iffp->seekchunk (iffp->makeid ('H','D','R',' '));
    if (err)
        return (err);

    if (sizeof (hdr) != iffp->chunkSize)
        return XF_ERR_CHUNKNOTFOUND;

    err = iffp->read (&hdr);
    if (err)
        return (err);

    if (hdr.type != VNGO_8BIT)
        return XF_ERR_CHUNKNOTFOUND;

    // Get the new information
    tpal->num_shd_lvl = hdr.num_levels;
    tpal->num_shd_lvl_bits = hdr.level_bits;
    int tbits = 8 - hdr.level_bits;
    tpal->mid_point = ((hdr.mid_point >> tbits) - 1) << tbits;

    iffp->leaveform();

    // ---- Find and read the hardware palette.
    err = iffp->seekchunk(iffp->makeid('h','w','d','P'));
    if (err)
        return (err);

    err = iffp->read(&((VngoPal *)pal)->hw_pal);
    if (err)
        return (err);

    // ---- Find and read the color conversion table.
    err = iffp->seekchunk(iffp->makeid('c','n','v','t'));
    if (err)
        return (err);

    err = iffp->read(&((VngoPal *)pal)->convert);
    if (err)
        return (err);

    // This will mock up a Pal15 using the Pal8s shade info.
    word *data15 = (word *)(pal->shd_pal->ptr);

// This will go through and make a 16bit shade_pal.  Not that the
// memory has to be allocated before you get to this routine.
    gamma_correct_RGB(pal->hw_pal.p,256);

    for (int i=0;i < 256;i++)
    {
        calc_linear_colors15(&data15[i <<5],32,pal->get_RGB(i),
                             pal->shd_pal->mid_point >> (8 - pal->shd_pal->num_shd_lvl_bits));
    }

    // ---- Clean up and close down.
    err = iffp->leaveform();

    return (err);
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal16::VngoPal16();                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPal16::VngoPal16()
{
    flags = VNGO_16BIT;
    shd_pal=NULL;
    ddpal = NULL;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal16::~VngoPal16();                                                   ³
//     This is the destructor for the VngoPal.  It will delete any memory   ³
//     that was allocated during the construction of this class.            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPal16::~VngoPal16()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete (VngoShadePal16 *)shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal16::release                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void VngoPal16::release()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete (VngoShadePal16 *)shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword _flags,VngoHwPal *hw,VngoShadePal *hz);              ³
//     This function will allocate memory for any of the structures that    ³
//     you do not pass a buffer in for.                                     ³
//     If you pass in the VNGO_PAL_HWINIT flag, it will write the passed in ³
//     hardware palette, if you didn't pass in a VngoHwPal then this flag is³
//     ignored.                                                             ³
//     If you pass in the VNGO_PAL_CALC flag, it will initialize the all    ³
//     three of the calculated tables in this order:                        ³
//         1)  Color conversion table.                                      ³
//         2)  Shade Palette table.                                         ³
//         3)  Haze Palette table.                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal16::init(dword _flags,VngoHwPal *hw,VngoShadePal16 *sh)
{
    ddpal=NULL;

    if (hw)
    {
        for (int i=0;i < 256;i++)
        {
            hw_pal.p[i] = hw->p[i];
        }
    }
    if (!sh)
    {
        if (!shd_pal)
        {
            shd_pal = (VngoShadePal *)new VngoShadePal16 (32);
            flags |= VNGO_MYMEM_SHADE;
        }
        // Once there is a mechanism to initialize the palette with a specified
        // number of shade levels rather than the hard coded 32, then more
        // checking will need to be done here.
    }
    else
    {
        shd_pal = (VngoShadePal *)sh;
    }


    if (_flags & VNGO_PAL_CALC)
    {
        convert.init(this,1);
    }
    else
    {
        convert.init(this);
    }

    return (0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword _flags,const char *palfile);                         ³
//     This function will load a palette from a file whos name is passed in.³
//     It will fist initialize a palette to get all of the required memory  ³
//     allocated, and will not do any of the calculations.  It will then    ³
//     read the palette from the specified file, and write it to the        ³
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal16::init(dword _flags,const char *palfile)
{
    int         err = 0;
    VngoPalIFF16 loadpal(this);

    ddpal=NULL;

    init(0);
    err=loadpal.load(palfile);

    return (err);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword _flags,char *palfile);                               ³
//     This function will load a palette from a file whos name is passed in.³
//     It will fist initialize a palette to get all of the required memory  ³
//     allocated, and will not do any of the calculations.  It will then    ³
//     read the palette from the specified file, and write it to the        ³
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal16::init(dword _flags,XFParseIFF *palfile)
{
    int             err = 0;
    VngoPalIFF16    loadpal(this);

    ddpal=NULL;

    init(0);
    err=loadpal.load(palfile);

    return (err);
}


STATIC void calc_linear_colors16 (word *colors, int steps,
                                  VngoColor24bit color, int break_point)
{
#if 1
    float           tr,tg,tb;
    VngoColor24bit  tclr;

    tr = float(color.r);
    tg = float(color.g);
    tb = float(color.b);


    float   rstep = tr / float(break_point);
    float   gstep = tg / float(break_point);
    float   bstep = tb / float(break_point);

    for (int i = break_point; i >= 0; i--)
    {
        tclr.r = int(tr + 0.5f);
        tclr.g = int(tg + 0.5f);
        tclr.b = int(tb + 0.5f);
        tr -= rstep;
        tg -= gstep;
        tb -= bstep;
        colors[i] = tclr.compress16();
    }


    tr = float(color.r);
    tg = float(color.g);
    tb = float(color.b);

    rstep = (255.f - tr) / float(steps - break_point);
    gstep = (255.f - tg) / float(steps - break_point);
    bstep = (255.f - tb) / float(steps - break_point);

    for (i = break_point+1; i < steps; i++)
    {
        tr += rstep;
        tg += gstep;
        tb += bstep;
        tclr.r = int(tr + 0.5f);
        tclr.g = int(tg + 0.5f);
        tclr.b = int(tb + 0.5f);
        colors[i] = tclr.compress16();
    }
#else

    VngoColorHLS    hlst;
    VngoColor24bit  tclr;
    float           t1;
    float           base,mean,step,step2,max,tl;


    hlst = color;
    tl = float(hlst.l);
    mean = tl;
    base = tl * 0.2f;

    t1 = mean - base;
    step = t1 / float(break_point);

    break_point--;  // Convert to 0 based value

    for (int i = break_point-1; i >= 0; i--)
    {
        tl -= step;
        hlst.l = Flx16(tl);
        tclr = hlst;
        colors[i] = tclr.compress16();
    }

    colors[break_point] = color.compress16();

    tl = mean;

    t1 = 1.f - tl;
    max = t1 * float(0.85);
    step = max / float(steps - break_point);

    for (i = break_point + 1; i < steps; i++)
    {
        tl += step;
        hlst.l = Flx16(tl);
        tclr = hlst;
        colors[i] = tclr.compress16();
    }
#endif
}


void MakePal16fromPal8(VngoPal16 *p16, VngoPal8 *p8)
{
    // This will mock up a Pal16 using the Pal8s shade info.
    byte *data8 = (byte *)(p8->shd_pal->ptr);
    word *data16 = (word *)(p16->shd_pal->ptr);


// This will go through and make a 16bit shade_pal.  Not that the
// memory has to be allocated before you get to this routine.
    for (int i=0;i < 256;i++)
    {
        calc_linear_colors16(&data16[i <<5],32,p8->get_RGB(i),
                             p8->shd_pal->mid_point >> (8 - p8->shd_pal->num_shd_lvl_bits));
    }
    for (i=0;i < 256;i++)
    {
        p16->hw_pal.p[i] = p8->hw_pal.p[i];
    }
    for (i=0;i < 32768; i++)
    {
        p16->convert.cvt2_8.colorconvert[i] = p8->convert.cvt2_8.colorconvert[i];
    }
    p16->shd_pal->mid_point = p8->shd_pal->mid_point;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoPalIFF16 °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF16::VngoPalIFF16();                                            ³
//     This  constructor will set the palettes name to 'Default' and set the³
//     palette pointer to NULL.  No reading or writing will take place.     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPalIFF16::VngoPalIFF16()
{
    name[0]='D';
    name[1]='e';
    name[2]='f';
    name[3]='a';
    name[4]='u';
    name[5]='l';
    name[6]='t';
    name[7]=0;

    pal = NULL;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF16::VngoPalIFF16(VngoPal *p);                                  ³
//     This  constructor will set the palettes name to 'Default' and set the³
//     palette pointer to the passed in palette. No file IO will take place.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPalIFF16::VngoPalIFF16(VngoPal *p)
{
    name[0]='D';
    name[1]='e';
    name[2]='f';
    name[3]='a';
    name[4]='u';
    name[5]='l';
    name[6]='t';
    name[7]=0;

    pal = (VngoPal16 *)p;
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF16::save(const char *filename);                                ³
//     This  will save the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be stored to the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF16::save(const char *filename)
{
    XFParseIFF  iffp;
    int         err=0;
    return(err);

    // Assert that there is memory allocated for all fields.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);

    err=iffp.create(filename,0);
    if (err)
        return(err);

    err = save(&iffp);
    if (err)
        return (err);

    return ( iffp.close() );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF16::save(XFParseIFF *iffp);                                    ³
//     This  will save the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be stored to the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF16::save(XFParseIFF *iffp)
{
    int             err=0;
    return(err);

    VngoShadePal8   *tpal = (VngoShadePal8 *)pal->shd_pal;

    // Assert that there is memory allocated for all fields.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);

    err = iffp->newform(iffp->makeid('V','P','A','L'));
    if (err)
        return(err);

    // ---- Write the name of the palette.
    err = iffp->write(iffp->makeid('n','a','m','e'),name,16);
    if (err)
        return(err);

    // ---- Save the shade palette.

    err = iffp->newform (iffp->makeid('s','h','d','P'));
    if (err)
        return(err);

    VngoShadePal::HDR hdr;
    hdr.type = VNGO_8BIT;
    hdr.num_levels = tpal->num_shd_lvl;
    hdr.level_bits = tpal->num_shd_lvl_bits;
    hdr.mid_point  = tpal->mid_point;

    // output the number of shade levels in the shade palette.
    err = iffp->write(iffp->makeid ('H','D','R',' '), &hdr, sizeof(hdr));
    if (err)
        return(err);

    dword id = iffp->makeid('s','h','d','L');
    for (int i=0; i < VNGO_PAL_SIZE;i++)
    {
        err = iffp->write (id, &(*tpal)[i], tpal->num_shd_lvl * sizeof (byte));
        if (err)
            return(err);
    }

    iffp->leaveform();


    // ---- Save the hardware palette.
    err = iffp->write(iffp->makeid('h','w','d','P'), &((VngoPal8 *)pal)->hw_pal,sizeof(VngoHwPal));
    if (err)
        return(err);

    // ---- Save the color conversion table.
    err = iffp->write(iffp->makeid('c','n','v','t'),&((VngoPal8 *)pal)->convert,sizeof(VngoClrConvert));
    if (err)
        return(err);

    err = iffp->leaveform();

    return(err);

}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF16::load(const char *filename);                                ³
//     This  will load the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be read from the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF16::load(const char *filename)
{
    XFParseIFF      iffp;
    int             err=0;

    // Assert that there is memory allocated to load into.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);
    //assert(pal->hz_pal != NULL);

    err=iffp.open(filename,XF_OPEN_READ);
    if (err)
        return (err);

    err = load(&iffp);
    if (err)
        return (err);

    return (iffp.close() );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF16::load(XFParseIFF *iffp);                                    ³
//     This  will load the palette that is associated with the object to the³
//     file specified in the parameters.  All fields will be read from the  ³
//     file, including the name.                                            ³
//     It returns any errors that may occur during the file IO.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPalIFF16::load(XFParseIFF *iffp)
{
    int             err=0;
    VngoShadePal16  *tpal = (VngoShadePal16 *)pal->shd_pal;

    // Assert that there is memory allocated to load into.
    assert(tpal != NULL);
    assert(pal->shd_pal != NULL);
    //assert(pal->hz_pal != NULL);

find_pal:

    err = iffp->seekform(iffp->makeid('V','P','A','L'));
    if (err)
        return (err);

    err = iffp->enterform();
    if (err)
        return (err);

    char nbuff[16];
    err = iffp->seekchunk (iffp->makeid('n','a','m','e'));
    if (err)
        return err;

    if (sizeof(nbuff) < iffp->chunkSize)
        return XF_ERR_CHUNKNOTFOUND;

    err = iffp->read(nbuff);
    if (err)
        return err;

    if (strcmp(name,"Default"))
    {
        if (strcmp(name,nbuff))
        {
            iffp->leaveform();
            goto find_pal;
        }
    }

    strncpy(name,nbuff,16);

    // ---- Find and read the shade palette.

    err = iffp->seekform (iffp->makeid('s','h','d','P'));
    if (err)
        return(err);

    err = iffp->enterform();
    if (err)
        return (err);

    VngoShadePal::HDR hdr;
    err = iffp->seekchunk (iffp->makeid ('H','D','R',' '));
    if (err)
        return (err);

    if (sizeof (hdr) != iffp->chunkSize)
        return XF_ERR_CHUNKNOTFOUND;

    err = iffp->read (&hdr);
    if (err)
        return (err);

    if (hdr.type != VNGO_8BIT)
        return XF_ERR_CHUNKNOTFOUND;

    // Get the new information
    tpal->num_shd_lvl = hdr.num_levels;
    tpal->num_shd_lvl_bits = hdr.level_bits;
    int tbits = 8 - hdr.level_bits;
    tpal->mid_point = ((hdr.mid_point >> tbits) - 1) << tbits;

    iffp->leaveform();

    // ---- Find and read the hardware palette.
    err = iffp->seekchunk(iffp->makeid('h','w','d','P'));
    if (err)
        return (err);

    err = iffp->read(&((VngoPal *)pal)->hw_pal);
    if (err)
        return (err);

    // ---- Find and read the color conversion table.
    err = iffp->seekchunk(iffp->makeid('c','n','v','t'));
    if (err)
        return (err);

    err = iffp->read(&((VngoPal *)pal)->convert);
    if (err)
        return (err);

    // This will mock up a Pal16 using the Pal8s shade info.
    word *data16 = (word *)(pal->shd_pal->ptr);

    gamma_correct_RGB(pal->hw_pal.p,256);

// This will go through and make a 16bit shade_pal.  Not that the
// memory has to be allocated before you get to this routine.
    for (int i=0;i < 256;i++)
    {
        calc_linear_colors16(&data16[i <<5],32,pal->get_RGB(i),
                             pal->shd_pal->mid_point >> (8 - pal->shd_pal->num_shd_lvl_bits));
    }

    // ---- Clean up and close down.
    err = iffp->leaveform();

    return (err);
}

void gamma_correct_RGB(VngoColor24bit *p,int count)
{
    if (VgSystem && VgSystem->gamma_correct != 1.0f)
    {
        for (int i=0;i < count; i++)
        {
            p[i].r = VgSystem->gtable[p[i].r];
            p[i].g = VgSystem->gtable[p[i].g];
            p[i].b = VgSystem->gtable[p[i].b];
        }
    }
}

//°±² End of module - vngpal.cpp ²±°
