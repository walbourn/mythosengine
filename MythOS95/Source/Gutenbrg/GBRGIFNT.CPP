//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//           __ ,                                                      
//            ,-| ~           ,               ,,                      
//           ('||/__,        ||               ||                  _   
//          (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\ 
//          (( |||==| || ||  ||   || \\ || || || || || \\  ||   || || 
//           ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || || 
//            -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-| 
//                                                               /  \ 
//                                                              '----`
//                     Text Output and Font Management System
//                          Microsoft Windows '95 Version
//
//            Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// gbrgifnt.cpp
//
// Contains the advanced font management routines.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include <string.h>

#include <ivory.hpp>
#include <xfile.hpp>

#include <gutenbrg.hpp>
#include <gbrgfile.hpp>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" GBergFontInfo *igberg_empty_font();

STATIC gberg_error_codes igberg_install_font(XFParseIFF *iff, const char *fntname);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern "C" GBergIData   *GBergInstance;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// gberg_install_font                                                       ³
//                                                                          ³
// This installs a new font, loading the data into the handle area and      ³
// setting up for a later select.                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" gberg_error_codes gberg_install_font (const char *fname, const char *fntname)
{
    gberg_error_codes   err;
    GBergFontInfo       *fnt;
    XFParseIFF          iff;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!fname)
        return GBERG_ERR_FILEERROR;

//ÄÄ Make current font inactive
    fnt=GBergInstance->font_active;
    if (fnt)
    {

        //ÄÄ Check to see if already active
        if (fntname && *fntname == *fnt->name)
        {
            if (!strcmp(fntname,fnt->name))
                return GBERG_ERR_NONE;
        }

        //ÄÄ Unlock active
        assertMyth("gberg_install_font found that active font has no data",
                   fnt->data);

        ivory_hunlock(fnt->data);
        fnt->ptr=0;

        GBergInstance->font_active=0;
    }

//ÄÄ Open file
    if (iff.open(fname,XF_OPEN_READ))
        return GBERG_ERR_FILEERROR;

//ÄÄ Loop until a header with the correct name is found
    err=GBERG_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            return GBERG_ERR_FONTNOTFOUND;
        }

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('G','F','N','T'))
            {
                err=igberg_install_font(&iff,fntname);
                if (!err
                    || err != GBERG_ERR_FONTNOTFOUND)
                    break;
            }
        }
    }

//ÄÄ Return ok
    iff.close();
    return err;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                            °°° Private °°°                               ³
// igberg_install_font                                                      ³
//                                                                          ³
// This installs the new font, assuming that the IFF is pointing to the     ³
// correct form.                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC gberg_error_codes igberg_install_font(XFParseIFF *iff, const char *fntname)
{
    gberg_error_codes   err;
    GBergFontInfo       *fnt;
    GBergFileFontHDR    header;

    assertMyth("igberg_install_font needs iff pointer",
               iff);

//ÄÄ Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('G','F','N','T'))
        return GBERG_ERR_FONTNOTFOUND;

//ÄÄ Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(GBergFileFontHDR))
    {
        iff->leaveform();
        return GBERG_ERR_INVALIDDATA;
    }

    if (iff->read(&header))
    {
        iff->leaveform();
        return GBERG_ERR_FILEERROR;
    }

    if (fntname && strncmp(fntname,header.name,GBERG_MAX_NAME))
    {
        iff->leaveform();
        return GBERG_ERR_FONTNOTFOUND;
    }

//ÄÄ Found, so setup 
    //ÄÄ Get empty slot for font
    fnt=igberg_empty_font();
    if (!fnt)
        return GBERG_ERR_NOMEMORY;

//ÄÄ Verify header
    switch (header.type)
    {
        case GBERG_FNT_MONOFIXED:
        case GBERG_FNT_MONOFIXEDEX:
        case GBERG_FNT_MONOVARIABLE:
        case GBERG_FNT_MONOVARIABLEEX:
            break;
        default:
            iff->leaveform();
            return GBERG_ERR_NOTSUPPORTED;
    }

    if (header.compression)
    {
        iff->leaveform();
        return GBERG_ERR_NOTSUPPORTED;
    }

//ÄÄ Fill out data
    strncpy(fnt->name,header.name,GBERG_MAX_NAME);
    fnt->width = header.width;
    fnt->height = header.height;
    fnt->bpc = header.bpc;
    fnt->type = header.type;

    if (!fnt->bpc || !fnt->width || !fnt->height)
    {
        iff->leaveform();
        return GBERG_ERR_INVALIDDATA;
    }

    int numchars = 128;
    switch (header.type)
    {
        case GBERG_FNT_MONOFIXEDEX:
        case GBERG_FNT_MONOVARIABLEEX:
            numchars = 256;
            break;
    }

    if ((fnt->data=ivory_halloc(numchars*fnt->bpc))==0)
    {
        iff->leaveform();
        return GBERG_ERR_NOMEMORY;
    }

    fnt->ptr=(byte*)ivory_hlock(fnt->data);
    if (!fnt->ptr)
    {
        iff->leaveform();
        ivory_hfree(&fnt->data);
        return GBERG_ERR_LOCKFAILED;
    }

    while (!iff->next())
    {

        if (iff->chunkid == iff->makeid('B','O','D','Y'))
        {
            if (iff->chunkSize != (ulong)(numchars * fnt->bpc))
            {
                err=GBERG_ERR_INVALIDDATA;
                goto error_exit;
            }

            if (iff->read(fnt->ptr))
            {
                err=GBERG_ERR_FILEERROR;
                goto error_exit;
            }
        }
    }

//ÄÄ Make font active
    assertMyth("igberg_install_font no assumes there is no active font",
               !GBergInstance->font_active);
    GBergInstance->font_active=fnt;

    iff->leaveform();
    return GBERG_ERR_NONE;

error_exit:;
    if (fnt->data)
    {
        if (fnt->ptr)
        {
            ivory_hunlock(fnt->data);
            fnt->ptr=0;
        }
        ivory_hfree(&fnt->data);
    }
    memset(fnt,0,sizeof(GBergFontInfo));

    iff->leaveform();
    return err;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// gberg_info_font                                                          ³
//                                                                          ³
// Returns information about the given font.  If fntname is empty, it will  ³
// return information for any current font.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" gberg_error_codes gberg_info_font(const char *fntname, GBergFontInfo *info)
{
    ulong           i;
    GBergFontInfo   *fnt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!fntname || !*fntname)
    {
    //ÄÄ No name means use the active font
        if ((fnt = GBergInstance->font_active) != 0)
        {
            *info = *fnt;
            return GBERG_ERR_NONE;
        }
    }
    else
    {
    //ÄÄ Search for given font name
        for (i = 0, fnt = &GBergInstance->fonts[0]; i < GBergInstance->fonts_hi; i++, fnt++)
        {
            if (*fntname == *fnt->name)
            {
                if (!strcmp (fntname, fnt->name))
                {
                    *info = *fnt;
                    return GBERG_ERR_NONE;
                }
            }
        }
    }

    return GBERG_ERR_FONTNOTINSTALLED;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// gberg_widthc                                                             ³
//                                                                          ³
// Returns the width of the given character in the current font, or 0 if    ³
// no font is selected.                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
long gberg_widthc(char c)
{
    assertMyth("Gutenberg must be initialized",GBergInstance);

    GBergFontInfo   *fnt=GBergInstance->font_active;

    if (!fnt)
        return 0;

    switch (fnt->type)
    {
        case GBERG_FNT_MONOFIXED:
        case GBERG_FNT_MONOFIXEDEX:
            return GBergInstance->font_active->width;

        case GBERG_FNT_MONOVARIABLE:
            {
                byte *ptr = (byte *)((byte *)fnt->ptr + (c*fnt->bpc));
                return *ptr;
            }

        case GBERG_FNT_MONOVARIABLEEX:
            {
                byte *ptr = (byte *)((byte *)fnt->ptr + ((byte)c*fnt->bpc));
                return *ptr;
            }

        default:
            return 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// gberg_heightc                                                            ³
//                                                                          ³
// Returns the height of the current font, or 0 if no font is selected.     ³                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
long gberg_heightc()
{
    assertMyth("Gutenberg must be initialized",GBergInstance);

    return (GBergInstance->font_active) ?
                            GBergInstance->font_active->height
                            : 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// gberg_width                                                              ³
//                                                                          ³
// Returns the width of the given string in the current font, or 0 if       ³
// no font is selected.                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
long gberg_width(const char *str)
{
    assertMyth("Gutenberg must be initialized",GBergInstance);

    GBergFontInfo   *fnt=GBergInstance->font_active;

    if (!fnt)
        return 0;

    switch (fnt->type)
    {
        case GBERG_FNT_MONOFIXED:
        case GBERG_FNT_MONOFIXEDEX:
            return (GBergInstance->font_active->width * strlen(str));

        case GBERG_FNT_MONOVARIABLE:
            {
                long len=0;
                for(const char *ch = str; *ch != 0; ch++)
                {
                    byte *ptr = (byte *)((byte *)fnt->ptr + ((*ch)*fnt->bpc));
                    len += *ptr;
                }
                return len;
            }

        case GBERG_FNT_MONOVARIABLEEX:
            {
                long len=0;
                for(const byte *ch = (const byte *)str; *ch != 0; ch++)
                {
                    byte *ptr = (byte *)((byte *)fnt->ptr + ((*ch)*fnt->bpc));
                    len += *ptr;
                }
                return len;
            }

        default:
            return 0;
    }
}

//°±² End of module - gbrgifnt.cpp ²±°


