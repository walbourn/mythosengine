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
//                        Microsoft Windows 95/NT Version
//
//            Copyright (c) 1995-1998 by Charybdis Enterprises, Inc.
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
// gbrgtxt.c
//
// Contains the basic text management routines.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <debug.h>

#include <assert.h>
#include <string.h>

#include <gutenbrg.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern GBergTextInfo *igberg_empty_strings();

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern GBergIData   *GBergInstance;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// gberg_select_strings                                                     ³
//                                                                          ³
// Makes the given text active.                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
gberg_error_codes gberg_select_strings(const char *txtname)
{
    ulong               i;
    GBergTextInfo       *txt, *ntxt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!txtname)
        return GBERG_ERR_TEXTNOTINSTALLED;

    txt=GBergInstance->text_active;
    if (txt)
    {
//ÄÄ Check to see if already active
        if (*txtname == *txt->name)
        {
            if (!strcmp(txtname,txt->name))
                return GBERG_ERR_NONE;
        }
    }

//ÄÄ Search for given text name
    for(i=0, ntxt=&GBergInstance->text[0]; i < GBergInstance->text_hi; i++, ntxt++)
    {
        if (*txtname == *ntxt->name)
		{
            if (!strcmp(txtname,ntxt->name))
                break;
        }
    }

    if (i >= GBergInstance->text_hi)
    {
        return GBERG_ERR_TEXTNOTINSTALLED;
    }

    GBergInstance->text_active=ntxt;
    
    return GBERG_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// gberg_loadstring                                                         ³
//                                                                          ³
// Locks the active resource and returns the requested string               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
gberg_error_codes gberg_loadstring(ulong num, char *buff, ulong len)
{
    ulong               i;
    byte                *ptr;
    gberg_error_codes   err=GBERG_ERR_NONE;
    GBergTextInfo       *txt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    txt=GBergInstance->text_active;
    assertMyth("gberg_loadstring assumes there is an active text block",
               txt);

//ÄÄ Lock
    ptr=ivory_hlock(txt->data);
    if (!ptr)
    {
        return GBERG_ERR_LOCKFAILED;
    }

//ÄÄ Find string
    err = GBERG_ERR_STRINGNOTFOUND;
    for (i = txt->number_of_strings; i > 0; i--)
    {
        if ( *((ulong *)ptr) == num )
        {
            if (!len)
                strcpy(buff,ptr+4);
            else
                strncpy(buff,ptr+4,len);
			err = GBERG_ERR_NONE;
            break;
        }
        else
        {
            ptr += 4+strlen(ptr+4)+1;   // Can't have embedded NULs, so this
                                        // is valid.  Compiler checks for
                                        // this.
        }
    }

//ÄÄ Unlock & exit
    ivory_hunlock(txt->data);
    return err;
}

//°±² End of module - gbrgstr.c ²±°
