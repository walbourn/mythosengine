//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                  ooo        ooooo
//                  `88.       .888'
//                   888b     d'888   .oooo.   oooo    ooo
//                   8 Y88. .P  888  `P  )88b   `88b..8P'
//                   8  `888'   888   .oP"888     Y888'
//                   8    Y     888  d8(  888   .o8"'88b
//                  o8o        o888o `Y888""8o o88'   888o
//
//                          Across the event horizon...
//
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// Created by Dan Higdon
//
// evtc.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <debug.h>
#include <xfile.hpp>
#include <max.hpp>
#include "evttok.h"

using namespace std; 

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define INIT_WORK_SIZE     32768

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" int mythos_atexit( register void ( *__func )( void ) );

#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) mythos_atexit;
#endif

STATIC void cleanup (void);
STATIC void print_help(int full);

void print_error (XFParseIFF &xp, char *s=0);
void print_error (XFile &xp, char *s=0);

extern void compile (const char *evt_name);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern "C" FILE *yyin;

STATIC char Util_name[]
       = "°± Max CEL Compiler - (C) 1994-1999 by D. Higdon, T. Little, and C. Walbourn ±°\n"
         "                      Subject to terms of the MIT Licesnse " __DATE__ "\n";

XFParseIFF  IFF;
XFileDOS    header;
byte        *Work=0;
ulong       Work_size=0;
dword       Flags=0;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// main                                                                     ³
//                                                                          ³
// Entry point for the IFFC utility.                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void main (int argc, char *argv[])
{
    char        *ifn = 0, *ofn = 0, *hfn = 0;

    char        path[XF_MAX_PATH];
    char        hpath[XF_MAX_PATH];

    char        drive[XF_MAX_DRIVE];
    char        dir[XF_MAX_DIR];
    char        fname[XF_MAX_FNAME];
    char        ext[XF_MAX_EXT];

//ÄÄÄ Handle no filename for source file...
    if (argc < 2)
    {
        print_help (0);
        return;
    }

//ÄÄÄ Process arguments
    for (int i = 1; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {
            case '?':
            case 'h':
                print_help(1);
                return;

            case 'q':
                break;

            case 'o':
                switch (argv[i][2])
                {
                case 'i':   // IFF file name
                    if (++i > argc)
                    {
                        print_help (0);
                        return;
                    }
                    ofn = argv[i];
                    strlwr (ofn);
                    break;

                case 'h':   // HPP file name
                    if (++i > argc)
                    {
                        print_help (0);
                        return;
                    }
                    hfn = argv[i];
                    strlwr (hfn);
                    break;
                }
                break;

            default:
                cout << "Unknown option " << argv[i] << " ignored\n";
                break;
            }
        }
        else if (!ifn)
        {
            ifn = argv[i];
            strlwr (ifn);
        }
    }

//ÄÄÄ Make sure that a parameter name was specified
    if (!ifn)
    {
        print_help(0);
        return;
    }


//ÄÄÄ Get default file names, if none were specified
    if (!hfn)
        hfn = ifn;

    if (!ofn)
        ofn = ifn;

//ÄÄÄ Check to see if source .cel file exists
    if (!xf_exist (ifn))
    {
        cout << Util_name;
        cout << "±±± " << ifn << " does not exist\n";
        return;
    }

//ÄÄÄ Open source file
    if ((yyin = fopen (ifn,"r"))==NULL)
    {
        cout << Util_name;
        cout << "±±± Could not open " << ifn << "\n";
        return;
    }

//ÄÄÄ Setup output filename
    strcpy (path, ofn);
    ofn = path;
    strcpy (hpath, hfn);
    hfn = hpath;

    // Forces .IFF extention onto whatever output file is being used
    xf_splitpath (path, drive, dir, fname, ext);
    xf_makepath  (path, drive, dir, fname, ".iff");

    // Do the same for the header file
    xf_splitpath (hpath, drive, dir, fname, ext);
    xf_makepath  (hpath, drive, dir, fname, ".hpp");

//ÄÄÄ Output title and source/output file stats.
    //if (!(Flags & FLAGS_QUIET))
    {
        cout << Util_name;
        cout << "Source: "   << ifn;
        cout << "  Output: " << ofn;
        cout << "  Header: " << hfn << endl;
    }

//ÄÄÄ Kill target file...
    xf_remove (ofn);

//ÄÄÄ Open output file
    if (IFF.create (ofn, 0))
        print_error (IFF, "Failed to open output file");

//ÄÄÄ Open output header file
    if (header.create (hfn, 0))
        print_error (header, "Failed to open output file");

//ÄÄÄ Parse input
    mythos_atexit (cleanup);
    compile (fname);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Cleanup function.                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void cleanup(void)
{
    delete [] Work;
    Work = 0;
    IFF.close ();
    header.close ();
    fclose (yyin);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Just a simple function to shut up the linker!                            ³
// This will not be needed in the full Mythos library.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" int mythos_atexit( register void ( *__func )( void ) )
{
    return atexit (__func);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// print_help                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void print_help (int full)
{
    cout << Util_name;
    cout << "   Usage: maxc <filename.cel> [-oi <filename.iff>] [-oh <filename.hpp>]\n";
    if (full)
    {
        cout << "          -h  = Display this message.\n";
        cout << "          -oi = Specifies alternate .IFF file name.\n";
        cout << "          -oh = Specifies alternate .HPP file name.\n";
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// print_error                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void print_error (XFParseIFF &xp, char *s)
{
    cout << "±±± ";

    if (s)
        cout << s << ", ";

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
        cout << "error " << int (xp.error());
        break;
   }

   cout << "\n";
}

void print_error (XFile &xp, char *s)
{
    cout << "±±± ";

    if (s)
        cout << s << ", ";

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
        cout << "error " << int (xp.error());
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

//°±² End of module - evtc.cpp ²±°

