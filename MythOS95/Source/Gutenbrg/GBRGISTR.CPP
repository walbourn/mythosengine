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
// gbrgistr.cpp
//
// Contains the advanced string management routines.
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

extern "C" GBergTextInfo *igberg_empty_strings();

STATIC gberg_error_codes igberg_install_strings(XFParseIFF *iff, const char *txtname);

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
// gberg_install_strings                                                    ³
//                                                                          ³
// This installs a new text block, loading the data into the handlea area   ³
// and setting up for a later select.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" gberg_error_codes gberg_install_strings(const char *fname, const char *txtname)
{
    gberg_error_codes   err;
    GBergTextInfo       *txt;
    XFParseIFF          iff;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!fname)
        return GBERG_ERR_FILEERROR;

//ÄÄ Make current text inactive
    txt=GBergInstance->text_active;
    if (txt)
    {

        //ÄÄ Check to see if already active
        if (txtname && *txtname == *txt->name)
        {
            if (!strcmp(txtname,txt->name))
                return GBERG_ERR_NONE;
        }

        GBergInstance->text_active=0;
    }

//ÄÄ Open file
    if (iff.open(fname,XF_OPEN_READ))
        return GBERG_ERR_FILEERROR;

//ÄÄ Loop until a header with the correct name is found
    err=GBERG_ERR_NONE;

    for (;;)
    {
        if (iff.next() != XF_ERR_NONE)
            return GBERG_ERR_TEXTNOTFOUND;

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('G','T','X','T'))
            {
                err = igberg_install_strings(&iff,txtname);
                if (!err || err != GBERG_ERR_TEXTNOTFOUND)
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
// igberg_install_strings                                                   ³
//                                                                          ³
// This installs the new text, assuming that the IFF is pointing to the     ³
// correct form.                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC gberg_error_codes igberg_install_strings(XFParseIFF *iff, const char *txtname)
{
    byte                *ptr=0;
    gberg_error_codes   err;
    GBergTextInfo       *txt;
    GBergFileTextHDR    header;

    assertMyth("igberg_install_strings needs iff pointer",
               iff);

//ÄÄ Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('G','T','X','T'))
        return GBERG_ERR_TEXTNOTFOUND;

//ÄÄ Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(GBergFileTextHDR))
    {
        iff->leaveform();
        return GBERG_ERR_INVALIDDATA;
    }

    if (iff->read(&header))
    {
        iff->leaveform();
        return GBERG_ERR_FILEERROR;
    }

    if (txtname && strncmp(txtname,header.name,GBERG_MAX_NAME))
    {
        iff->leaveform();
        return GBERG_ERR_TEXTNOTFOUND;
    }

//ÄÄ Found, so setup 
    //ÄÄ Get empty slot for text
    txt=igberg_empty_strings();
    if (!txt)
        return GBERG_ERR_NOMEMORY;

//ÄÄ Verify header
    if (header.compression)
    {
        iff->leaveform();
        return GBERG_ERR_NOTSUPPORTED;
    }

//ÄÄ Fill out data
    strncpy(txt->name,header.name,GBERG_MAX_NAME);
    txt->number_of_strings = header.number_of_strings;

    while (!iff->next())
    {

        if (iff->chunkid == iff->makeid('B','O','D','Y'))
        {
            if (!iff->chunkSize)
            {
                err=GBERG_ERR_INVALIDDATA;
                goto error_exit;
            }

            if ((txt->data=ivory_halloc(iff->chunkSize))==0)
            {
                return GBERG_ERR_NOMEMORY;
            }

            ptr=(byte*)ivory_hlock(txt->data);
            if (!ptr)
            {
                ivory_hfree(&txt->data);
                return GBERG_ERR_LOCKFAILED;
            }

            if (iff->read(ptr))
            {
                err=GBERG_ERR_FILEERROR;
                goto error_exit;
            }

            ivory_hunlock(txt->data);
        }
    }

//ÄÄ Make text active
    assertMyth("igberg_install_strings now assumes no active strings",
               !GBergInstance->text_active);
    GBergInstance->text_active=txt;

    iff->leaveform();
    return GBERG_ERR_NONE;

error_exit:;
    if (txt->data)
    {
        if (ptr)
        {
            ivory_hunlock(txt->data);
            ptr=0;
        }
        ivory_hfree(&txt->data);
    }
    memset(txt,0,sizeof(GBergTextInfo));

    iff->leaveform();
    return err;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// gberg_info_strings                                                       ³
//                                                                          ³
// Returns information about the given text.  If txtname is empty, it will  ³
// return information for any current text.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" gberg_error_codes gberg_info_strings(const char *txtname, GBergTextInfo *info)
{
    ulong           i;
    GBergTextInfo   *txt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!txtname || !*txtname)
    {
        txt=GBergInstance->text_active;
        if (!txt)
        {
            return GBERG_ERR_TEXTNOTINSTALLED;
        }

        memcpy(info,txt,sizeof(GBergTextInfo));
        return GBERG_ERR_NONE;
    }

//ÄÄ Search for given text name
    for(i=0, txt=&GBergInstance->text[0]; i < GBergInstance->text_hi; i++, txt++)
    {
        if (*txtname == *txt->name)
        {
            if (!strcmp(txtname,txt->name))
                break;
        }
    }
    return GBERG_ERR_TEXTNOTINSTALLED;
}

//°±² End of module - gbrgitxt.cpp ²±°

