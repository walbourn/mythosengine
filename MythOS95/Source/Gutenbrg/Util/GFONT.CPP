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
// gfont.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <windows.h>

#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "xfile.hpp"

#include "gfont.h"

#include "gbrgfile.hpp"

using namespace std;


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

STATIC void print_help(int full);

void print_error(XFParseIFF &xp, char *s=0);

extern void compile(char *name);
extern void bitmap(char *name, XFBitmap *bm,
                   ushort width, ushort height,
                   ushort startx, ushort starty,
                   ushort spacer,
                   byte startc, ushort numc, byte cpr);
extern void enumerate_tt();
extern void capture_tt(char *name, char *ttname,
                       ushort width, ushort height,
                       byte startc, ushort numc);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern "C" FILE *yyin;

STATIC char Util_name[]
       = "°± Gutenberg Font Utility - (C) 1995-9 by D. Higdon, T. Little, C. Walbourn ±°\n"
         "                            Subject to the terms of the MIT License " __DATE__ "\n";

XFParseIFF     IFF;

dword   Flags=0;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// main                                                                     ³
//                                                                          ³
// Entry point for the GFONT utility.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void main(int argc, char *argv[])
{
    int         i;
    char        *ifn, *ofn;

    ushort      width=0, height=0;
    ushort      startx=0, starty=0;
    ushort      spacer=0;
    byte        startc=0, cpr=0;
    ushort      numc=0;

    char        fontname[16];
    char        ttname[32];

    char        path[XF_MAX_PATH];

    char        drive[XF_MAX_DRIVE];
    char        dir[XF_MAX_DIR];
    char        fname[XF_MAX_FNAME];
    char        ext[XF_MAX_EXT];

//ÄÄÄ Handle no filename for directory...
    if (argc < 2)
    {
        print_help(0);
        return;
    }

    *fontname=0;
    *ttname=0;

//ÄÄÄ Process arguments
    for(i=1, ifn=0, ofn=0; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {
                case 'Q':
                case 'q':
                    Flags |= FLAGS_QUIET;
                    break;
                case 'N':
                case 'n':
                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/')
                    {
                        cout << "°° Expected a font name\n";
                        return;
                    }
                    strncpy(fontname,argv[i],sizeof(fontname));
                    break;
                case 'W':
                case 'w':
                    width = (ushort) atoi(&argv[i][2]);
                    break;
                case 'H':
                case 'h':
                    height = (ushort) atoi(&argv[i][2]);
                    break;
                case 'X':
                case 'x':
                    startx = (ushort) atoi(&argv[i][2]);
                    break;
                case 'Y':
                case 'y':
                    starty = (ushort) atoi(&argv[i][2]);
                    break;
                case 'P':
                case 'p':
                    spacer = (ushort) atoi(&argv[i][2]);
                    break;
                case 'S':
                case 's':
                    startc = (byte) atoi(&argv[i][2]);
                    break;
                case 'C':
                case 'c':
                    numc = (ushort) atoi(&argv[i][2]);
                    break;
                case 'R':
                case 'r':
                    cpr = (byte) atoi(&argv[i][2]);
                    break;
                case 'I':
                case 'i':
                    Flags |= FLAGS_INVERSE;
                    break;
                case 'E':
                case 'e':
                    enumerate_tt();
                    break;
                case 'B':
                case 'b':
                    Flags |= FLAGS_TT_BOLD;
                    break;
                case 'T':
                case 't':
                    Flags |= FLAGS_TT_ITALIC;
                    break;
                case 'U':
                case 'u':
                    Flags |= FLAGS_TT_UNDERLINE;
                    break;
                case 'K':
                case 'k':
                    Flags |= FLAGS_TT_STRIKEOUT;
                    break;
                case 'O':
                case 'o':
                    Flags |= FLAGS_TT_OEMCHARSET;
                    break;
                case '8':
                    Flags |= FLAGS_TT_CP850;
                    break;
                case '?':
                    print_help(1);
                    return;
                default:
                    cout << "Unknown option " << argv[i] << " ignored\n";
                    break;
            }
        }
        else if (!ifn)
        {
            ifn=argv[i];
            strlwr(ifn);
        }
        else if (!ofn)
        {
            ofn=argv[i];
            strlwr(ofn);
        }
    }

    if (!ifn)
    {
        print_help(0);
        return;
    }

//ÄÄÄ Check for valid input file extension
    if (strstr(ifn,".bdf"))
    {
        //ÄÄÄ Check to see if supplied file exists
        if (!xf_exist(ifn))
        {
            cout << "±±± " << ifn << " does not exist\n";
            return;
        }

        //ÄÄÄ Open source file
        if ((yyin=fopen(ifn,"r"))==NULL)
        {
            cout << Util_name;
            cout << "±±± Could not open " << ifn << "\n";
            return;
        }
    }
    else if (strstr(ifn,".pcx")
             || strstr(ifn,".lbm")
             || strstr(ifn,".cel")
             || strstr(ifn,".bmp")
             || strstr(ifn,".xeb"))
    {
        //ÄÄÄ Check to see if supplied file exists
        if (!xf_exist(ifn))
        {
            cout << "±±± " << ifn << " does not exist\n";
            return;
        }

        if (!width || !height || !startc || !numc)
        {
            cout << Util_name;
            cout << "±±±  Must use -w, -h, -s, -c with bitmaps\n";
            return;
        }
    }
    else
    {
        // Assume it is a TrueType font name...
        strncpy(ttname,ifn,sizeof(ttname));
    }


//ÄÄÄ Setup output filename (uses input name if none given)
    if (ofn)
    {
        strcpy(path,ofn);
    }
    else
    {
        strcpy(path,ifn);
    }
    ofn=path;

    // Forces .IFF extention onto whatever output file is being used
    xf_splitpath(path,drive,dir,fname,ext);
    strcpy(ext,".iff");
    xf_makepath(path,drive,dir,fname,ext);

    if (!*fontname)
        strncpy(fontname,fname,sizeof(fontname));

//ÄÄÄ Output title and source/output file stats.
    if (!(Flags & FLAGS_QUIET))
    {
        cout << Util_name;

        if (ifn)
        {
            cout << "   Source: " << ifn;
        }
        if (ofn)
        {
            cout << "   Output: " << ofn << "\n";
        }
    }

//ÄÄÄ Kill target file...
    xf_remove(ofn);

//ÄÄÄ Open output file
    if (IFF.create(ofn,0)
        || IFF.newform(IFF.makeid('G','F','N','T')))
    {
        print_error(IFF,"Failed to open output file");
        return;
    }

    if (*ttname)
    {
        capture_tt(fontname, ttname,
                   width,height,
                   startc, (numc) ? numc : 256);
    }
    else if (strstr(ifn,".bdf"))
    {
        compile(fontname);
    }
    else
    {
        int         err=0;
        XFBitmap    bm;
        if (strstr(ifn,".pcx"))
        {
            XFParsePCX  pcx;
            err=pcx.nameread(ifn,&bm);
        }
        else if (strstr(ifn,".lbm"))
        {
            XFParseLBM  lbm;
            err=lbm.nameread(ifn,&bm);
        }
        else if (strstr(ifn,".cel"))
        {
            XFParseCEL  cel;
            err=cel.nameread(ifn,&bm);
        }
        else if (strstr(ifn,".bmp"))
        {
            XFParseBMP  bmp;
            err=bmp.nameread(ifn,&bm);
        }
        else if (strstr(ifn,".xeb"))
        {
            XFParseXEB  xeb;
            err=xeb.nameread(ifn,&bm);
        }
        else
        {
            cout << "±±± Unknown input image extender\n";
            return;
        }

        if (err)
        {
            cout << "±±± Error " << err << " loading image " << ifn << "\n";
            return;
        }

        if (bm.bpp == 1)
        {
            bitmap(fontname,&bm,
                   width,height,
                   startx,starty,
                   spacer,
                   startc, numc, cpr);
        }
        else
        {
            cout << "±±± Input image must be 8-bit\n";
            return;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// print_help                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void print_help(int full)
{
    cout << Util_name;
    cout << "   Usage: gfont [-q] [-i] [-n fontname]\n";
    cout << "\n";
    cout << "                <filename.bdf> [<filename.iff>]\n";
    cout << "     -or-\n";
    cout << "                -w<number> -h<number>\n";
    cout << "                [-x<number>] [-y<number>] [-p<number>]\n";
    cout << "                -s<number> -c<number> [-r<number>]\n";
    cout << "                <filename.xxx> [<filename.iff>]\n";
    cout << "     -or-\n";
    cout << "                [-e]\n";
    cout << "                [-h<number>] [-w<number>]\n";
    cout << "                [-s<number>] [-c<number>]\n";
    cout << "                [-b] [-t] [-u] [-k] [-o] [-8]\n";
    cout << "                <TrueType fontname> [<filename.iff>]\n";
    if (full)
    {
        cout << "          -q = Quiet mode.\n";
        cout << "          -i = Inverse font images.\n";
        cout << "          -n = Font identifer name (defaults to output file name base).\n";
        cout << "\n";
        cout << "          These only apply to converting from a bitmap file\n";
        cout << "          (.xxx can be BMP, CEL, LBM, PCX, or XEB)\n\n";
        cout << "          -w = Width of font cells (required)\n";
        cout << "          -h = Height of font cells (required)\n";
        cout << "          -x = Starting offset in X of font cells\n";
        cout << "          -y = Starting offset in Y of font cells\n";
        cout << "          -p = Space between cells (in pixels, defaults to 0)\n";
        cout << "          -s = Starting character number (required)\n";
        cout << "          -c = Number of characters defined (required)\n";
        cout << "          -r = Characters per row\n";
        cout << "\n";
        cout << "          These only apply to capturing a TrueType font\n";
        cout << "          -e = Enumerate installed TrueType fonts\n";
        cout << "          -h = Height of font to capture\n";
        cout << "          -w = Maximum width (defaults to 0 for no maximum)\n";
        cout << "          -s = Starting character number (defaults to 0)\n";
        cout << "          -c = Number of characters to capture (defaults to 256)\n";
        cout << "          -b = Bold\n";
        cout << "          -t = Italic\n";
        cout << "          -u = Underline\n";
        cout << "          -k = StrikeOut\n";
        cout << "          -o = OEM Character Set\n";
        cout << "          -8 = Capture German characters as Codepage 850 instead of 1232\n";
    }
    cout << "\n";
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// print_error                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void print_error(XFParseIFF &xp, char *s)
{
    cout << "±±± ";

    if (s)
    {
        cout << s << ", ";
    }

    switch (xp.error())
    {
        case XF_ERR_NOTIFF:
            cout << "not an IFF file error";
            break;
        case XF_ERR_CHUCKNOTFOUND:
            cout << "chunk not found error";
            break;
        case XF_ERR_FORMNOTFOUND:
            cout << "form not found error";
            break;
        case XF_ERR_UNEXPECTEDEOF:
            cout << "unexpected end-of-file error";
            break;
        case XF_ERR_INVALIDFORFORM:
            cout << "invalid operation for FORM error";
            break;
        case XF_ERR_INVALIDFORCHUNK:
            cout << "invalid operation for chunk error";
            break;
        case XF_ERR_INVALIDID:
            cout << "invalid identifier error";
            break;
        case XF_ERR_TRUNCATEDCHUNK:
            cout << "truncated chunk error";
            break;
        case XF_ERR_WRITENOTALLOWED:
            cout << "write not allowed error";
            break;
        case XF_ERR_MAXDEPTHREACHED:
            cout << "maximum supported depth reached error";
            break;
        default:
            cout << "error " << (int)xp.error();
            break;
    }

    cout << "\n";
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// _charybdis_assert
//
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void _charybdis_assert(char *msg, char *exp, char *f, unsigned ln)
{
    cout.flush();
    printf("\n\n±±± Assertion Failed ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n"
           "Expr:\t%s\n"
           "File:\t%s\t\tLine %d\n",exp,f,ln);
    if (msg)
    {
        printf("Comment:\n%s\n",msg);
    }

    exit(1);
}

//°±² End of module - gfont.cpp ²±°

