//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
//                              All Rights Reserved.
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
// xuiffdir.cpp
//
// This is a utility module for the XFile library for printing out
// a directory of the contents of an .IFF file.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "xfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define FLAGS_PAUSE         0x1
#define FLAGS_RIFF          0x2
#define FLAGS_NOPAD         0x4

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

STATIC void print_help(int full);
STATIC void print_error(XFParseIFF &xp, char *s=0);

STATIC void directory(XFParseIFF &iff);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

STATIC dword   Flags=0;

STATIC ulong   Line=0;
STATIC ulong   Maxline=24;

STATIC char Util_name[]
       = "°± IFF Directory - (C) 1994-1998 Charybdis Enterprises, Inc. ±°\n"
         "                   All Rights Reserved.  " __DATE__ "\n";

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// main                                                                     ³
//                                                                          ³
// Entry point for the IFFDIR utility.                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void main(int argc, char *argv[])
{
    int         i;
    char        *fn;

//ÄÄÄ Handle no filename for directory...
    if (argc < 2)
    {
        print_help(0);
        return;
    }

//ÄÄÄ Process arguments
    for(i=1, fn=0; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {
                case 'p':
                case 'P':
                    Flags |= FLAGS_PAUSE;
                    break;
                case 'r':
                case 'R':
                    Flags |= FLAGS_RIFF;
                    break;
                case 'z':
                case 'Z':
                    Flags |= FLAGS_NOPAD;
                    break;
                case '?':
                    print_help(1);
                    return;
                default:
                    cout << "Unknown option " << argv[i] << " ignored\n";
                    break;
            }
        }
        else if (!fn)
        {
            fn=argv[i];
        }
    }

    if (!fn)
    {
        print_help(0);
        return;
    }

//ÄÄÄ Check to see if supplied iff file exists
    if (!xf_exist(fn))
    {
        cout << "±±± " << fn << " does not exist\n";
        return;
    }

//ÄÄÄ Construct IFF reader
    XFParseIFF  iff( ((Flags & FLAGS_RIFF) ? XF_IFF_RIFF : 0)
                     | ((Flags & FLAGS_NOPAD) ? XF_IFF_NOPAD : 0) );

//ÄÄÄ Open supplied iff file
    if (iff.open(fn,XF_OPEN_READ | XF_OPEN_DENYWRITE))
    {
        print_error(iff,"Failed to open file");
        return;
    }
   
//ÄÄÄ Print outline of file contents
    cout << Util_name;
    cout << "   File: " << fn << "\t"
         << ((Flags & FLAGS_RIFF) ? "Microsoft RIFF Format" : "EA IFF Format")
         << ((Flags & FLAGS_NOPAD) ? ", no padding" : "") << endl;
    Line=2;
    directory(iff);

//ÄÄÄ Close file
    iff.close();
}   


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// print_help                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void print_help(int full)
{
    cout << Util_name;
    cout << "   Usage: iffdir [-p] [-r] [-z] <filename.iff/.xxx>\n";
    if (full)
    {
        cout << "          -p = Pause between screens.\n";
        cout << "          -r = Use Microsoft RIFF instead of EA IFF\n";
        cout << "          -z = Don't assume even byte padding (MID files)\n";
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// print_error                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void print_error(XFParseIFF &xp, char *s)
{
    cout << "±±± ";
   
    if (s)
    {
        cout << s << ", ";
    }
   
    switch (xp.error())
    {
        case XF_ERR_NOTIFF:
            cout << "not an IFF/RIFF file error";
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
            cout << "invalid operation for FORM/RIFF error";
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// directory                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define COLUMN 45
#define MAXCOLUMN  75

STATIC void directory(XFParseIFF &iff)
{
    ulong   i;
    ulong   size;
    char    buff[5] = { 0, 0, 0, 0, 0 };

//ÄÄ Loop through current level
    while (iff.next() == XF_ERR_NONE)
    {
        if (iff.chunkid == ((Flags & FLAGS_RIFF)
                            ? iff.makeid('R','I','F','F')
                            : iff.makeid('F','O','R','M')))
        {

            //ÄÄ FORM/RIFF
            for (i=0; i < iff.depth; i++)
                cout << "³";

            cout << ((Flags & FLAGS_RIFF) ? "RIFF" : "FORM");

            cout << " '" << iff.strid(iff.formid,buff) << "'";

            for(i=iff.depth + sizeof("XXXX ''")+4; i < MAXCOLUMN; i++)
                cout << "Ä";

            cout << "\n";
            if ((Flags & FLAGS_PAUSE) && (++Line >= Maxline))
            {
                cout << "°° More °°\r";
                getch();
                Line=1;
            }

            size = iff.chunkSize + 8;

            if (iff.enterform() != XF_ERR_NONE)
            {
                print_error(iff,"Problem entering FORM/RIFF");
            }
            else
            {
                directory(iff);

                for(i=0; i < iff.depth-1; i++)
                    cout << "³";

                cout << "À";

                for(; i < COLUMN - sizeof("Total "); i++)
                    cout << "Ä";

                cout << "Total " << size << " bytes\n";
                if ((Flags & FLAGS_PAUSE) && (++Line >= Maxline))
                {
                    cout << "°° More °°\r";
                    cout.flush();
                    getch();
                    Line=1;
                }

                iff.leaveform();
            }
        }
        else
        {

            //ÄÄ Chunk
            for(i=0; i < iff.depth; i++)
                cout << "³";

            cout << "'" << iff.strid(iff.chunkid,buff) << "' ";
            for(i=iff.depth + sizeof("'' ")+4; i < COLUMN; i++)
                cout << " ";

            cout << iff.chunkSize << " bytes\n";
            if ((Flags & FLAGS_PAUSE) && (++Line >= Maxline))
            {
                cout << "°° More °°\r";
                cout.flush();
                getch();
                Line=1;
            }

        }
    }

    if (iff.error() != XF_ERR_EOF)
    {
        print_error(iff,"Problem processing file");
    }
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

//°±² End of module - xuiffdir.cpp ²±°

