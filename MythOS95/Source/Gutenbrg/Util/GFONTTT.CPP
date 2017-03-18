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
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                              *** Utilities ***
//
// Created by Chuck Walbourn
//
// gfonttt.cpp
//
//     This is the capture module for TrueType fonts.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <windows.h>

#include <assert.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "debug.h"
#include "xfile.hpp"

#include "gfont.h"

#include "gutenbrg.hpp"
#include "gbrgfile.hpp"

using namespace std;


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
// enumerate_tt                                                             ³
//                                                                          ³
// Enumerates available TrueType fonts.                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
static int CALLBACK enum_proc(ENUMLOGFONT FAR *lpelf,
                              NEWTEXTMETRIC FAR *lpntm,
                              int FontType,
                              LPARAM lParam)
{
    if (!(FontType & TRUETYPE_FONTTYPE))
        return 1;

    char pitch[14];
    *pitch = 0;

    if (lpelf->elfLogFont.lfPitchAndFamily & FIXED_PITCH)
        strcpy(pitch,"Fixed-pitch");
    else if (lpelf->elfLogFont.lfPitchAndFamily & VARIABLE_PITCH)
        strcpy(pitch,"Varible-pitch");

    printf("%-30s (%-10s) %2dx%2d %-14s\n",
           (char*)lpelf->elfFullName,
           (char*)lpelf->elfStyle,
           lpelf->elfLogFont.lfHeight,
           lpelf->elfLogFont.lfWidth,
           pitch);

    return 1;
}

void enumerate_tt()
{
    HWND hWnd = GetDesktopWindow();
    assert(hWnd != 0);

    HDC hDC = GetDC(hWnd);
    assert(hDC != 0);

    cout.flush();
    printf("%-30s (%-10s) %-5s %-14s\n",
           "Name",
           "Style",
           "Size",
           "Pitch");
    printf("------------------------------ ------------ ----- --------------\n");

    EnumFontFamilies(hDC, NULL, (FONTENUMPROC) enum_proc, 0);

    ReleaseDC(hWnd,hDC);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_tt                                                               ³
//                                                                          ³
// Captures a TrueType font into the output IFF (already open by main)      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void capture_tt(char *name, char *ttname,
                ushort width, ushort height,
                byte startc, ushort numc)
{
    int                 j;
    byte                *font, *fptr;
    ulong               fontSize;
    GBergFileFontHDR    header;
    byte                work[4096];

    assert(name != 0 && ttname != 0 && height > 0);

    memset(&header,0,sizeof(header));
    strncpy(header.name,name,sizeof(header.name));

    if (((int)startc+(int)numc-1) > 256)
    {
        cout << "±±± Error: number of characters in set must fit in 128 or 256 chars";
        exit(1);
    }

    int numchars = (((int)startc+(int)numc-1) > 128) ? 256 : 128;

//ÄÄÄ Find and select font that meets input criteria
    HWND hWnd = GetDesktopWindow();
    assert(hWnd != 0);

    HDC hDC = GetDC(hWnd);
    assert(hDC != 0);

    HFONT               hFont, hOldFont;
    OUTLINETEXTMETRIC   tm;
    for(;;)
    {
        LOGFONT fontinfo;
        memset(&fontinfo,0,sizeof(fontinfo));
        fontinfo.lfHeight = height;
        if (Flags & FLAGS_TT_BOLD)
            fontinfo.lfWeight = FW_BOLD;
        if (Flags & FLAGS_TT_ITALIC)
            fontinfo.lfItalic = TRUE;
        if (Flags & FLAGS_TT_UNDERLINE)
            fontinfo.lfUnderline = TRUE;
        if (Flags & FLAGS_TT_STRIKEOUT)
            fontinfo.lfStrikeOut = TRUE;
        if (Flags & FLAGS_TT_OEMCHARSET)
            fontinfo.lfCharSet = OEM_CHARSET;
        fontinfo.lfOutPrecision = OUT_TT_ONLY_PRECIS;
        strncpy(fontinfo.lfFaceName,ttname,sizeof(fontinfo.lfFaceName));

        hFont = CreateFontIndirect(&fontinfo);
        if (!hFont)
        {
            cout << "±±± Error: failed to get TrueType font with specified characteristics";
            ReleaseDC(hWnd,hDC);
            exit(1);
        }

        hOldFont = (HFONT__*)SelectObject(hDC,hFont);

        memset(&tm,0,sizeof(tm));
        GetOutlineTextMetrics(hDC,sizeof(tm),&tm);

        if (!width || tm.otmTextMetrics.tmMaxCharWidth <= width)
        {
            break;
        }
        else if (height <= 1)
        {
            cout << "±±± Error: failed to get TrueType font with specified characteristics\n";
            SelectObject(hDC,hOldFont);
            DeleteObject(hFont);
            ReleaseDC(hWnd,hDC);
            exit(1);
        }
        else
        {
            height--;
            SelectObject(hDC,hOldFont);
        }
    }

//ÄÄÄ See if we can download bitmap for font...
    {
        GLYPHMETRICS glyph;
        MAT2 matrix;
        memset(&matrix,0,sizeof(matrix));
        matrix.eM11.value = 1;
        matrix.eM22.value = 1;

        if (GetGlyphOutline(hDC,0,GGO_BITMAP,&glyph,0,0,&matrix) == GDI_ERROR)
        {
            cout << "±±± Error: Can't capture data for specified font characteristics\n";
            SelectObject(hDC,hOldFont);
            DeleteObject(hFont);
            ReleaseDC(hWnd,hDC);
            exit(1);
        }
    }

//ÄÄÄ Output information about selected font
    if (!(Flags & FLAGS_QUIET))
    {
        cout << "Capturing TrueType font '" << ttname << "'...\n";
        cout << "   Size: " << tm.otmTextMetrics.tmMaxCharWidth
             << " by " << tm.otmTextMetrics.tmHeight << endl;
        cout << "   Character #" << (int)startc << " to #" << ((int)startc+(int)numc-1) << endl;
        if (tm.otmfsType & 0x1)
            cout << "   *Licensed font*";
        cout << "   Attributes: ";

        switch (tm.otmTextMetrics.tmWeight)
        {
            case FW_THIN:
                cout << "Thin ";
                break;
            case FW_EXTRALIGHT:
                cout << "ExtraLight ";
                break;
            case FW_LIGHT:
                cout << "Light ";
                break;
            case FW_NORMAL:
                cout << "Normal ";
                break;
            case FW_MEDIUM:
                cout << "Medium ";
                break;
            case FW_SEMIBOLD:
                cout << "SemiBold ";
                break;
            case FW_BOLD:
                cout << "Bold ";
                break;
            case FW_EXTRABOLD:
                cout << "ExtraBold ";
                break;
            case FW_HEAVY:
                cout << "Heavy ";
                break;
            default:
                cout << "Wght(" << tm.otmTextMetrics.tmWeight << ") ";
                break;
        }
        if (tm.otmTextMetrics.tmItalic)
            cout << "Italic ";
        if (tm.otmTextMetrics.tmUnderlined)
            cout << "Underlined ";
        if (tm.otmTextMetrics.tmStruckOut)
            cout << "StruckOut ";
        if (tm.otmTextMetrics.tmPitchAndFamily & TMPF_FIXED_PITCH)
            cout << "Variable-pitch ";
        else
            cout << "Fixed-pitch ";
        cout << endl;

        cout << "   Family: ";
        if (tm.otmTextMetrics.tmPitchAndFamily & FF_MODERN)
            cout << "Modern ";
        if (tm.otmTextMetrics.tmPitchAndFamily & FF_ROMAN)
            cout << "Roman ";
        if (tm.otmTextMetrics.tmPitchAndFamily & FF_SCRIPT)
            cout << "Script ";
        if (tm.otmTextMetrics.tmPitchAndFamily & FF_SWISS)
            cout << "Swiss ";
        if (tm.otmTextMetrics.tmPitchAndFamily & FF_DECORATIVE)
            cout << "Decorative ";
        cout << endl;

        cout << "   CharSet: ";
        switch (tm.otmTextMetrics.tmCharSet)
        {
            case ANSI_CHARSET:
                cout << "ANSI ";
                break;
            case SYMBOL_CHARSET:
                cout << "Symbol ";
                break;
            case OEM_CHARSET:
                cout << "OEM ";
                break;
            default:
                cout << "#" << tm.otmTextMetrics.tmCharSet;
                break;
        }
        cout << endl;

        if ((numchars > 128) && (Flags & FLAGS_TT_CP850))
        {
            cout << "   Map special characters to Codepage 850\n";
        }
    }

    if (tm.otmTextMetrics.tmMaxCharWidth > 32)
    {
        cout << "±±± Error: Maximum width must be less than or equal to 32";
        SelectObject(hDC,hOldFont);
        DeleteObject(hFont);
        ReleaseDC(hWnd,hDC);
        exit(1);
    }

//ÄÄ Font Header
    header.width = (ushort)tm.otmTextMetrics.tmMaxCharWidth;
    header.height = (ushort)tm.otmTextMetrics.tmHeight;

    // Only supports MONO non-COMPRESSED fonts
    header.compression = 0;
    if (tm.otmTextMetrics.tmPitchAndFamily & TMPF_FIXED_PITCH)
    {
        // Variable
        header.type = (numchars > 128) ? GBERG_FNT_MONOVARIABLEEX
                                       : GBERG_FNT_MONOVARIABLE;
        header.bpc = (ushort)((((header.width + 7) >> 3) * header.height) + 1);
    }
    else
    {
        // Fixed
        header.type = (numchars > 128) ? GBERG_FNT_MONOFIXEDEX
                                       : GBERG_FNT_MONOFIXED;
        header.bpc = (ushort)(((header.width + 7) >> 3) * header.height);
    }

    // Write header
    if (IFF.write(IFF.makeid('H','D','R',' '),&header,sizeof(header)))
    {
        print_error(IFF,"Failed to write header chunk");
        SelectObject(hDC,hOldFont);
        DeleteObject(hFont);
        ReleaseDC(hWnd,hDC);
        exit(1);
    }

//ÄÄ Character encode
    fontSize = numchars*header.bpc;
    font = new byte[fontSize];
    if (!font)
    {
        cout << "±±± Error: Failed to allocate memory for font\n";
        SelectObject(hDC,hOldFont);
        DeleteObject(hFont);
        ReleaseDC(hWnd,hDC);
        exit(1);
    }
    memset(font,0,fontSize);

    // Identity rotation matrix...
    MAT2 matrix;
    memset(&matrix,0,sizeof(matrix));
    matrix.eM11.value = 1;
    matrix.eM22.value = 1;

    int adjy = tm.otmrcFontBox.bottom
               + ((tm.otmrcFontBox.top < 0) ? tm.otmrcFontBox.top : 0);
    if (adjy > header.height)
        adjy = header.height;

    // Capture each character
    for(int chloop=startc; chloop < numchars; chloop++)
    {
        if (!(Flags & FLAGS_QUIET))
        {
            cout << ".";
            cout.flush();
        }

        int ch = chloop;
        if ((numchars > 128) && (Flags & FLAGS_TT_CP850))
        {
            // Since Windows fonts are in CodePage 1232, we
            // want to move special characters to their
            // correct positions for Codepage 850.

            switch (ch)
            {
                case 131:  ch = 159;  break;
                case 161:  ch = 173;  break;
                case 162:  ch = 189;  break;
                case 163:  ch = 156;  break;
                case 164:  ch = 207;  break;
                case 165:  ch = 190;  break;
                case 167:  ch = 245;  break;
                case 168:  ch = 249;  break;
                case 169:  ch = 184;  break;
                case 170:  ch = 166;  break;
                case 171:  ch = 174;  break;
                case 172:  ch = 170;  break;
                case 174:  ch = 169;  break;
                case 176:  ch = 248;  break;
                case 177:  ch = 241;  break;
                case 178:  ch = 253;  break;
                case 179:  ch = 252;  break;
                case 180:  ch = 239;  break;
                case 181:  ch = 230;  break;
                case 182:  ch = 244;  break;
                case 183:  ch = 240;  break;
                case 186:  ch = 167;  break;
                case 187:  ch = 175;  break;
                case 188:  ch = 172;  break;
                case 189:  ch = 171;  break;
                case 190:  ch = 243;  break;
                case 191:  ch = 168;  break;
                case 192:  ch = 183;  break;
                case 193:  ch = 181;  break;
                case 194:  ch = 182;  break;
                case 195:  ch = 199;  break;
                case 196:  ch = 142;  break;
                case 197:  ch = 143;  break;
                case 198:  ch = 146;  break;
                case 199:  ch = 128;  break;
                case 200:  ch = 212;  break;
                case 201:  ch = 144;  break;
                case 202:  ch = 210;  break;
                case 203:  ch = 211;  break;
                case 204:  ch = 222;  break;
                case 205:  ch = 214;  break;
                case 206:  ch = 215;  break;
                case 207:  ch = 216;  break;
                case 208:  ch = 209;  break;
                case 209:  ch = 165;  break;
                case 210:  ch = 227;  break;
                case 211:  ch = 224;  break;
                case 212:  ch = 226;  break;
                case 213:  ch = 229;  break;
                case 214:  ch = 153;  break;
                case 215:  ch = 158;  break;
                case 216:  ch = 157;  break;
                case 217:  ch = 235;  break;
                case 218:  ch = 233;  break;
                case 219:  ch = 234;  break;
                case 220:  ch = 154;  break;
                case 221:  ch = 237;  break;
                case 222:  ch = 231;  break;
                case 223:  ch = 225;  break;
                case 224:  ch = 133;  break;
                case 225:  ch = 160;  break;
                case 226:  ch = 131;  break;
                case 227:  ch = 198;  break;
                case 228:  ch = 132;  break;
                case 229:  ch = 134;  break;
                case 230:  ch = 145;  break;
                case 231:  ch = 135;  break;
                case 232:  ch = 138;  break;
                case 233:  ch = 130;  break;
                case 234:  ch = 136;  break;
                case 235:  ch = 137;  break;
                case 236:  ch = 141;  break;
                case 237:  ch = 161;  break;
                case 238:  ch = 140;  break;
                case 239:  ch = 139;  break;
                case 240:  ch = 208;  break;
                case 241:  ch = 164;  break;
                case 242:  ch = 149;  break;
                case 243:  ch = 162;  break;
                case 244:  ch = 147;  break;
                case 245:  ch = 228;  break;
                case 246:  ch = 148;  break;
                case 247:  ch = 246;  break;
                case 248:  ch = 155;  break;
                case 249:  ch = 151;  break;
                case 250:  ch = 163;  break;
                case 251:  ch = 150;  break;
                case 252:  ch = 129;  break;
                case 253:  ch = 236;  break;
                case 254:  ch = 232;  break;
                case 255:  ch = 252;  break;
                default:
                    if (ch > 128)
                        continue;
                    break;
            }
        }

        GLYPHMETRICS glyph;

        dword gsize = GetGlyphOutline(hDC,chloop,
                                      GGO_BITMAP,
                                      &glyph,sizeof(work),work,&matrix);

        if (gsize == GDI_ERROR)
        {
            cout << "±±± Error: failed to get glyph #" << chloop << "\n";
            SelectObject(hDC,hOldFont);
            DeleteObject(hFont);
            ReleaseDC(hWnd,hDC);
            exit(1);
        }

        if (tm.otmTextMetrics.tmPitchAndFamily & TMPF_FIXED_PITCH)
        {
            // Variable
            fptr = &font[ch * header.bpc];
            *(fptr++) = (ushort)glyph.gmCellIncX+1;

            int dbpl = (glyph.gmCellIncX + 1 + 7) >> 3;
            memset(fptr,
                   (Flags & FLAGS_INVERSE) ? 0xff : 0,
                   dbpl*header.height);

            if (gsize)
            {
                int sbpl = ((glyph.gmBlackBoxX + 31) >> 5) * 4;

                fptr += ((adjy - glyph.gmptGlyphOrigin.y)*dbpl);

                byte *ptr = work;
                for(j=0; j < (int)glyph.gmBlackBoxY; j++)
                {
                    assert(header.width <= 32);

                    dword dw = (*ptr << 24);
                    if (sbpl > 1)
                        dw |= *(ptr+1) << 16;
                    if (sbpl > 2)
                        dw |= *(ptr+2) << 8;
                    if (sbpl > 3)
                        dw |= *(ptr+3);

                    if (glyph.gmptGlyphOrigin.x < 0)
                        dw <<= -glyph.gmptGlyphOrigin.x;
                    else
                        dw >>= glyph.gmptGlyphOrigin.x;
                    if (Flags & FLAGS_INVERSE)
                        dw ^= 0xffffffff;

                    *fptr = byte((dw >> 24) & 0xff);
                    if (dbpl > 1)
                        *(fptr+1) = byte((dw >> 16) & 0xff);
                    if (dbpl > 2)
                        *(fptr+2) = byte((dw >> 8) & 0xff);
                    if (dbpl > 3)
                        *(fptr+3) = byte(dw & 0xff);

                    ptr += sbpl;
                    fptr += dbpl;
                }
            }
        }
        else
        {
            // Fixed
            fptr = &font[ch * header.bpc];

            int dbpl = (header.width + 7) >> 3;

            if (Flags & FLAGS_INVERSE)
                memset(fptr,0xff,dbpl*header.height);

            if (gsize)
            {
                int sbpl = ((glyph.gmBlackBoxX + 31) >> 5) * 4;

                byte *ptr = work;
                fptr += ((adjy - glyph.gmptGlyphOrigin.y)*dbpl);
                for(j=0; j < (int)glyph.gmBlackBoxY; j++)
                {
                    assert(header.width <= 32);

                    dword dw = (*ptr << 24);
                    if (sbpl > 1)
                        dw |= *(ptr+1) << 16;
                    if (sbpl > 2)
                        dw |= *(ptr+2) << 8;
                    if (sbpl > 3)
                        dw |= *(ptr+3);

                    if (glyph.gmptGlyphOrigin.x < 0)
                        dw <<= -glyph.gmptGlyphOrigin.x;
                    else
                        dw >>= glyph.gmptGlyphOrigin.x;
                    if (Flags & FLAGS_INVERSE)
                        dw ^= 0xffffffff;

                    *fptr = byte((dw >> 24) & 0xff);
                    if (dbpl > 1)
                        *(fptr+1) = byte((dw >> 16) & 0xff);
                    if (dbpl > 2)
                        *(fptr+2) = byte((dw >> 8) & 0xff);
                    if (dbpl > 3)
                        *(fptr+3) = byte(dw & 0xff);

                    ptr += sbpl;
                    fptr += dbpl;
                }
            }
        }

        if (ch >= startc+numc-1)
            break;
    }

    // Output font
    if (IFF.write(IFF.makeid('B','O','D','Y'),font,fontSize))
    {
        print_error(IFF,"Failed to write font data chunk");
        SelectObject(hDC,hOldFont);
        DeleteObject(hFont);
        ReleaseDC(hWnd,hDC);
        exit(1);
    }

//ÄÄÄ Cleanup and return
    if (!(Flags & FLAGS_QUIET))
    {
        cout << "\nDone\n";
    }

    delete [] font;

    SelectObject(hDC,hOldFont);
    DeleteObject(hFont);
    ReleaseDC(hWnd,hDC);
}

//°±² End of module - gfonttt.cpp ²±°

