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
//                              *** Utilities ***
//
// Created by Chuck Walbourn
//
// gfontbm.cpp
//
//     This is the converter module for bitmap files
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "debug.h"
#include "xfile.hpp"

#include "gfont.h"

#include "gutenbrg.hpp"
#include "gbrgfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄ External from main module.
void print_error(XFParseIFF &xp, char *s=0);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄ External from main module.
extern XFParseIFF  IFF;
extern dword       Flags;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// bitmap                                                                   ³
//                                                                          ³
// Converts a bitmap file into the output IFF (both already open by main)   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void bitmap(char *name, XFBitmap *bm,
            ushort width, ushort height,
            ushort startx, ushort starty,
            ushort spacer,
            byte startc, byte numc, byte cpr)
{
    int                 i, j, k, t;
    byte                *font, *fptr;
    ulong               fontSize;
    GBergFileFontHDR    header;

    assert(name != 0 && bm != 0);

    memset(&header,0,sizeof(GBergFileFontHDR));
    strcpy(header.name,name);

    if (((int)startc+(int)numc-1) > 256)
    {
        cout << "±±± Error: number of characters in set must fit in 128 or 256 chars";
        exit(1);
    }

    int numchars = (((int)startc+(int)numc-1) > 128) ? 256 : 128;

    if (!(Flags & FLAGS_QUIET))
    {
        cout << "Converting font " << name << "...\n";
        cout << "   Size: " << width << " by " << height << endl;
        cout << "   Starting at (" << startx << ',' << starty << ')';
        cout << "   Character #" << (int)startc << " to #" << ((int)startc+(int)numc-1) << endl;
        if (spacer)
        {
            cout << "   Spacer: " << spacer << " pixels between each cell in X and Y" << endl;
        }
        if (cpr)
        {
            cout << "   Characters per row: " << (int)cpr << endl;
        }
    }

//ÄÄ Font Header
    // For now, only supports MONOFIXED non-COMPRESSED fonts.
    header.compression = 0;
    header.type = (numchars > 128) ? GBERG_FNT_MONOFIXEDEX : GBERG_FNT_MONOFIXED;

    header.width = width;
    header.height = height;

    if (width > 32)
    {
        cout << "±±± Error: width must be less than or equal to 32";
        exit(1);
    }

    assert(header.type == GBERG_FNT_MONOFIXED);
    header.bpc = (ushort)(((header.width + 7) >> 3) * header.height);

    // Write header
    if (IFF.write(IFF.makeid('H','D','R',' '),&header,sizeof(GBergFileFontHDR)))
    {
        print_error(IFF,"Failed to write header chunk");
        exit(1);
    }

//ÄÄ Character encode
    fontSize = numchars*header.bpc;
    font = new byte[fontSize];
    if (!font)
    {
        cout << "Failed to allocate memory for font\n";
        exit(1);
    }
    memset(font,0,fontSize);

    ulong x = startx;
    ulong y = starty;
    int crow=0;
    
    for(int ch=startc; ch < numchars; ch++)
    {
        if (!(Flags & FLAGS_QUIET))
            cout << ".";

        int lwidth = width & ~0x7;
        int rwidth = width & 0x7;

        for(j=0, fptr = &font[ch * header.bpc];
            j < header.height; j++)
        {
            assert(bm->bpp == 1 && x < bm->width && y < bm->height);
            byte *ptr = bm->data+(((y+j)*bm->width)+x);

            if (width >= 8)
            {
                for (i = 0; i < lwidth; i+=8)
                {
                    t = 0;
                    for (k = 0; k < 8; k++)
                    {
                        if (*(ptr++))
                        {
                            t |= (0x80 >> k);
                        }
                    }
                    if (Flags & FLAGS_INVERSE)
                        t ^= 0xff;
                    *(fptr++) = (byte)t;
                }
            }
            if (rwidth)
            {
                t = 0;
                for (k = 0;k < rwidth; k++)
                {
                    if (*(ptr++))
                        t |= (0x80 >> k);
                }
                if (Flags & FLAGS_INVERSE)
                    t ^= 0xff;
                *(fptr++) = (byte) t;
            }
        }

        if (ch >= startc+numc-1)
            break;

        x += width + spacer;
        crow++;

        if (cpr)
        {
            if (crow >= cpr)
            {
                x = startx;
                y += height + spacer;
                crow=0;
            }
        }
        else
        {
            if (x + width > bm->width)
            {
                x = startx;
                y += height + spacer;
                crow=0;
            }
        }

        if ((x + width) >= bm->width
            || (y + height) >= bm->height)
        {
            cout << "Stopping at character #" << ch << " since cell exceeds bitmap size" << endl;
            break;
        }
    }

    // Output font
    if (IFF.write(IFF.makeid('B','O','D','Y'),font,fontSize))
    {
        print_error(IFF,"Failed to write font data chunk");
        exit(1);
    }

    if (!(Flags & FLAGS_QUIET))
    {
        cout << "\nDone\n";
    }
}

//°±² End of module - gfontbm.cpp ²±°

