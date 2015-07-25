//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
#include "ivory.h"
#include "felix.hpp"
#include "xfile.hpp"

#define __VNGVPDD8_HPP
#include "vangogh.hpp"
#include "xfile.hpp"

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
// VngoHwPal Class meber functions.                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoHwPal::init(VngoColor24bit pal[],int count,dword flags);             ³
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal Class meber functions.                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

void VngoPal::release()
{
    if (flags & VNGO_MYMEM_SHADE && shd_pal)
    {
        delete shd_pal;
        shd_pal = NULL;
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::~VngoPal();                                                     ³
//     This is the destructor for the VngoPal.  It will delete any memory   ³
//     that was allocated during the construction of this class.            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoPal::~VngoPal()
{
    if (flags & VNGO_MYMEM_SHADE && shd_pal)
    {
        delete shd_pal;
        shd_pal = NULL;
    }
#if 0
    if (flags & VNGO_MYMEM_HAZE)
    {
        delete hz_pal;
        hz_pal = NULL;
    }
#endif
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword flags,VngoHwPal *hw,VngoShadePal *hz);               ³
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
int VngoPal8::init(dword flags,VngoHwPal *hw,VngoShadePal8 *sh)
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


    if (flags & VNGO_PAL_CALC)
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
// VngoPal::init(dword flags,const char *palfile);                          ³
//     This function will load a palette from a file whos name is passed in.³
//     It will fist initialize a palette to get all of the required memory  ³
//     allocated, and will not do any of the calculations.  It will then    ³
//     read the palette from the specified file, and write it to the        ³
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal8::init(dword flags,const char *palfile)
{
    int         err;
    VngoPalIFF8 loadpal(this);

    init(0);
    err=loadpal.load(palfile);

    return (err);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPal::init(dword flags,char *palfile);                                ³
//     This function will load a palette from a file whos name is passed in.³
//     It will fist initialize a palette to get all of the required memory  ³
//     allocated, and will not do any of the calculations.  It will then    ³
//     read the palette from the specified file, and write it to the        ³
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoPal8::init(dword flags,XFParseIFF *palfile)
{
    int         err;
    VngoPalIFF8 loadpal(this);

    init(0);
    err=loadpal.load(palfile);

    return (err);
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF Class meber functions.                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF::VngoPalIFF();                                                ³
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
// VngoPalIFF::VngoPalIFF(VngoPal *p);                                      ³
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
// VngoPalIFF::save(const char *filename);                                  ³
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
//    assert(pal->hz_pal != NULL);

    err=iffp.create(filename,0);
    if (err)
        return(err);

    err = save(&iffp);
    if (err)
        return (err);

    return ( iffp.close() );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPalIFF::save(XFParseIFF *iffp);                                      ³
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
    //assert(tpal->hz_pal != NULL);

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
// VngoPalIFF::load(const char *filename);                                  ³
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
// VngoPalIFF::load(XFParseIFF *iffp);                                      ³
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

    err = iffp->seekform(iffp->makeid('V','P','A','L'));
    if (err)
        return (err);

    err = iffp->enterform();
    if (err)
        return (err);

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
        return XF_ERR_CHUCKNOTFOUND;

    err = iffp->read (&hdr);
    if (err)
        return (err);

    if (hdr.type != VNGO_8BIT)
        return XF_ERR_CHUCKNOTFOUND;

    // Get the new information
    tpal->num_shd_lvl = hdr.num_levels;
    tpal->num_shd_lvl_bits = hdr.level_bits;
    tpal->mid_point = hdr.mid_point;

    dword id = iffp->makeid('s','h','d','L');
    for (int i=0; i < VNGO_PAL_SIZE; i++)
    {
        err = iffp->seekchunk (id);
        if (err)
            return (err);

        if (tpal->num_shd_lvl * sizeof (byte) != iffp->chunkSize)
            return XF_ERR_CHUCKNOTFOUND;

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

    return (err);
}

//°±² End of module - vngcolor.cpp ²±°
