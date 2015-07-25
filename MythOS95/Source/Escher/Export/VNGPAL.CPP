//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
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
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// vngpal.cpp
//
//     The C++ palette classes for the VanGogh Draw library.
//
//ммммммммммммммммммммммммммммм Revision History мммммммммммммммммммммммммммм
//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Includes
//                                
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
#include <assert.h>

#include "debug.h"
#include "portable.h"
#include "ivory.h"
#include "felix.hpp"
#include "xfile.hpp"
#include "vangogh.hpp"
#include "xfile.hpp"

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Equates
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                               Structures
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                               Routines
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Data
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠


//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Code
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoHwPal Class meber functions.                                         Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoHwPal::init(VngoColor24bit pal[],int count,dword flags);             Ё
//     This function sets the first count number of palette entries to the  Ё
//     the values stored in the pal array that is passed in.  It does not   Ё
//     modeify the current state of the hardware, it simply modifies the    Ё
//     table entries.  If you pass in the flag VNGO_PAL_HWINIT, it will     Ё
//     update the hardware as well.                                         Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды

int VngoHwPal::init(VngoColor24bit pal[],int count,dword flags)
{
    for (int i=0;i < count;i++)
    {
        p[i] = pal[i];
    }
    if (flags & VNGO_PAL_HWINIT)
    {
        write();
    }
    return (0);
}

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoHwPal::write();                                                      Ё
//     This function writes the current hard ware palette structure to the  Ё
//     physical device.                                                     Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void VngoHwPal::write()
{
    for (int i=0;i < 256;i++)
    {
//        vngo_set_pal(i,p[i]);
    }
}

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoHwPal::read();                                                       Ё
//     This function reads into the current hardware palette structure the  Ё
//     data that is active on the physical device.                          Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void VngoHwPal::read()
{
    for (int i=0;i < 256;i++)
    {
//        p[i]=vngo_get_pal(i);
    }
}

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoShadePal Class meber functions.                                      Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
#if 0
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoShadePal::init(VngoPal *pal);                                        Ё
//     This function calculates the shade values for all 256 of the palette Ё
//     entries in the palette that is passed into the call.                 Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void VngoShadePal8::init(VngoPal *pal)
{
    for (int i=0;i < 256; i++)
    {
        p[i].init(pal,i);
    }
}
#endif

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoHazePal Class meber functions.                                       Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoHazePal::init(VngoPal *pal);                                         Ё
//     This function calculates the haze values for all 256 of the palette  Ё
//     entries in the palette that is passed into the call.                 Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void VngoHazePal8::init(VngoPal *pal)
{
#if 0
    for (int i=0;i < 256; i++)
    {
        p[i].init(pal,i);
    }
#endif
}

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPal Class meber functions.                                           Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPal::~VngoPal();                                                     Ё
//     This is the destructor for the VngoPal.  It will delete any memory   Ё
//     that was allocated during the construction of this class.            Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
VngoPal::~VngoPal()
{
    if (flags & VNGO_MYMEM_SHADE)
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




//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPal::init(dword flags,VngoHwPal *hw,VngoShadePal *hz);               Ё
//     This function will allocate memory for any of the structures that    Ё
//     you do not pass a buffer in for.                                     Ё
//     If you pass in the VNGO_PAL_HWINIT flag, it will write the passed in Ё
//     hardware palette, if you didn't pass in a VngoHwPal then this flag isЁ
//     ignored.                                                             Ё
//     If you pass in the VNGO_PAL_CALC flag, it will initialize the all    Ё
//     three of the calculated tables in this order:                        Ё
//         1)  Color conversion table.                                      Ё
//         2)  Shade Palette table.                                         Ё
//         3)  Haze Palette table.                                          Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
int VngoPal8::init(dword flags,VngoHwPal *hw,VngoShadePal8 *sh,VngoHazePal8 *hz)
{
    if (hw)
    {
        for (int i=0;i < 256;i++)
        {
            hw_pal.p[i] = hw->p[i];
        }
        if (flags & VNGO_PAL_HWINIT)
        {
            hw_pal.write();
        }
    }
    if (!sh)
    {
        shd_pal = (VngoShadePal *)new VngoShadePal8 (32);
        flags |= VNGO_MYMEM_SHADE;
    }
    else
    {
        shd_pal = (VngoShadePal *)sh;
    }
#if 0
    if (!hz)
    {
        hz_pal = new VngoHazePal8;
        flags |= VNGO_MYMEM_HAZE;
    }
    else
    {
        hz_pal = (VngoHazePal *)hz;
    }
#endif


    if (flags & VNGO_PAL_CALC)
    {
        convert.init(this,1);
//        ((VngoShadePal8 *)shd_pal)->init(this);
//        ((VngoHazePal8 *)hz_pal)->init(this);
    }
    else
        convert.init(this);

    return (0);
}

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPal::init(dword flags,const char *palfile);                          Ё
//     This function will load a palette from a file whos name is passed in.Ё
//     It will fist initialize a palette to get all of the required memory  Ё
//     allocated, and will not do any of the calculations.  It will then    Ё
//     read the palette from the specified file, and write it to the        Ё
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
int VngoPal8::init(dword flags,const char *palfile)
{
    int         err;
    VngoPalIFF8 loadpal(this);

    init(0);
    err=loadpal.load(palfile);

    if (flags & VNGO_PAL_HWINIT)
    {
        hw_pal.write();
    }
    return (err);
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPal::init(dword flags,char *palfile);                                Ё
//     This function will load a palette from a file whos name is passed in.Ё
//     It will fist initialize a palette to get all of the required memory  Ё
//     allocated, and will not do any of the calculations.  It will then    Ё
//     read the palette from the specified file, and write it to the        Ё
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
int VngoPal8::init(dword flags,XFParseIFF *palfile)
{
    int         err;
    VngoPalIFF8 loadpal(this);

    init(0);
    err=loadpal.load(palfile);

    if (flags & VNGO_PAL_HWINIT)
    {
        hw_pal.write();
    }
    return (err);
}



//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPalIFF Class meber functions.                                        Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPalIFF::VngoPalIFF();                                                Ё
//     This  constructor will set the palettes name to 'Default' and set theЁ
//     palette pointer to NULL.  No reading or writing will take place.     Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPalIFF::VngoPalIFF(VngoPal *p);                                      Ё
//     This  constructor will set the palettes name to 'Default' and set theЁ
//     palette pointer to the passed in palette. No file IO will take place.Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPalIFF::save(const char *filename);                                  Ё
//     This  will save the palette that is associated with the object to theЁ
//     file specified in the parameters.  All fields will be stored to the  Ё
//     file, including the name.                                            Ё
//     It returns any errors that may occur during the file IO.             Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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

    return (save(&iffp));
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPalIFF::save(XFParseIFF *iffp);                                      Ё
//     This  will save the palette that is associated with the object to theЁ
//     file specified in the parameters.  All fields will be stored to the  Ё
//     file, including the name.                                            Ё
//     It returns any errors that may occur during the file IO.             Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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
#if 0
    err = iffp->write(iffp->makeid('s','h','d','P'),tpal,sizeof(VngoShadePal8));
    if (err)
        return(err);
#else
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

#endif

#if 0
    // ---- Save the haze palette.
    err = iffp->write(iffp->makeid('h','a','z','P'),pal->hz_pal,sizeof(VngoHazePal8));
    if (err)
        return(err);
#endif

    // ---- Save the hardware palette.
    err = iffp->write(iffp->makeid('h','w','d','P'), &((VngoPal8 *)pal)->hw_pal,sizeof(VngoHwPal));
    if (err)
        return(err);

    // ---- Save the color conversion table.
    err = iffp->write(iffp->makeid('c','n','v','t'),&((VngoPal8 *)pal)->convert,sizeof(VngoClrConvert));
    if (err)
        return(err);

    err = iffp->leaveform();
    if (err)
        return(err);

    err = iffp->close();
    if (err)
        return(err);

    // ---- no errors occured so return zero.
    return (0);
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPalIFF::load(const char *filename);                                  Ё
//     This  will load the palette that is associated with the object to theЁ
//     file specified in the parameters.  All fields will be read from the  Ё
//     file, including the name.                                            Ё
//     It returns any errors that may occur during the file IO.             Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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

    return (load(&iffp));
}

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPalIFF::load(XFParseIFF *iffp);                                      Ё
//     This  will load the palette that is associated with the object to theЁ
//     file specified in the parameters.  All fields will be read from the  Ё
//     file, including the name.                                            Ё
//     It returns any errors that may occur during the file IO.             Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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
#if 0
    err = iffp->seekchunk(iffp->makeid('s','h','d','P'));
    if (err)
        return (err);

    err = iffp->read(tpal);
    if (err)
        return (err);
#else
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
#endif

#if 0
    // ---- Find and read the haze palette.
    err = iffp->seekchunk(iffp->makeid('h','a','z','P'));
    if (err)
        return (err);

    err = iffp->read(pal->hz_pal);
    if (err)
        return (err);
#endif

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
    if (err)
        return (err);

    err = iffp->close();
    if (err)
        return (err);

    // ---- Since no error occured return zero.
    return (0);
}

//╟╠╡ End of module - vngcolor.cpp ╡╠╟
