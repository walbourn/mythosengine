//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùù°°°°°°°°°°ù°°°°°°°°ùùù°°°°°°°°ùù°°°ùùùù°°°ù°°°°°°°°°°ù°°°°°°°°°ùù
//ùùùùùùùùù°±°ùùùùùùù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùùùùùù°±°ùùùù°±°ùù
//ùùùùùùùù±°±ùùùùùùù±°±ùùùùùùùù±°±ùùùùùùùù±°±ùùùù±°±ù±°±ùùùùùùùù±°±ùùùù±°±ùùù
//ùùùùùùù±²±±°±±²ùù±²±±°±±²±±ù±²±ùùùùùùùù±²±±°±±²±±ù±²±±°±±²ùùù±²±±°±±²°ùùùùù
//ùùùùùù±²±ùùùùùùùùùùùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ùùùùù
//ùùùùù²±²ùùùùùùù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùùùùùù²±²ùùùù²±²ùùùùùù
//ùùùù²²²²²²²²²²ù²²²²²²²²ùùù²²²²²²²²ùù²²²ùùùù²²²ù²²²²²²²²²²ù²²²ùùùù²²²ùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùù Microsoft Windows 95/NT Version ùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùCopyrightù(c)ù1994-1998ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
// Created by Tim Little & Chuck Walbourn
//
// eshlw.cpp
//
// Escher LightWave object converter.
//
// *** This is only a basic converter for geometry and doesn't include ***
// *** support for texture information.  Full support for Lightwave    ***
// *** is not likely to be implemented since the texturing model is    ***
// *** distincly different than Escher's model.                        ***
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

#include "debug.h"
#include "xfile.hpp"
#include "escher.hpp"
#include "esfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define FLAGS_QUIET         0x1
#define FLAGS_INFO          0x2
#define FLAGS_OUTPUT        0x4
#define FLAGS_DETAILPOLYS   0x8
#define FLAGS_SCENE         0x10
#define FLAGS_FORCE_1SIDED  0x20
#define FLAGS_FORCE_2SIDED  0x40
#define FLAGS_QUICK_EXTS    0x80
#define FLAGS_FIXED         0x100

#define LW_SURF_FLAG_LUMINOUS           0x1
#define LW_SURF_FLAG_OUTLINE            0x2
#define LW_SURF_FLAG_SMOOTHING          0x4
#define LW_SURF_FLAG_COLOR_HIGHLIGHT    0x8
#define LW_SURF_FLAG_COLOR_FILTER       0x10
#define LW_SURF_FLAG_OPAQUE_EDGE        0x20
#define LW_SURF_FLAG_TRANSP_EDGE        0x40
#define LW_SURF_FLAG_SHARP_TERM         0x80
#define LW_SURF_FLAG_DOUBLE_SIDED       0x100
#define LW_SURF_FLAG_ADDITIVE           0x200

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct Point
{
    float   x;
    float   y;
    float   z;
};

struct Surface
{
    char    *name;
    dword   flags;
    dword   color;
    byte    alpha;
    byte    selfi;
    word    na;
};

struct Poly    
{
    short   num;
    short   surf;
    short   *verts;
};

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

STATIC void cleanup(void);
STATIC void print_help(int full);
STATIC void print_error(XFParseIFF &xp, char *s=0);
STATIC void print_info(Point *points, ulong maxpoints,
                       Poly *polys, ulong maxpolys,
                       Surface *surfs, ulong maxsurfs);

STATIC void process(XFParseIFF &iff, const char *name);
STATIC Point *process_points(XFParseIFF &iff, ulong &max);
STATIC Surface *process_surface_list(XFParseIFF &iff, ulong &max);
STATIC Poly *process_polygons(XFParseIFF &iff, ulong &max);
STATIC BOOL process_surfaces(XFParseIFF &iff, Surface *surfs, ulong max);

STATIC void generate(const char *name,
                     Point *points, ulong maxpoints,
                     Poly *polys, ulong maxpolys,
                     Surface *surfs, ulong maxsurfs);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

STATIC dword   Flags=0;

STATIC char Util_name[]
        = "°± Escher Lightwave Converter - (C) 1997-1998 Charybdis Enterprises, Inc. ±°\n"
          "                                All Rights Reserved.  " __DATE__ "\n";

XFParseIFF     IFF;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Entry Point °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// main                                                                     ³
//                                                                          ³
// Entry point for the ESHLW utility.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void main(int argc, char *argv[])
{
    int         i;
    char        *fn;
    char        *outfn;
    XFParseIFF  iff;
    char        name[ESCH_MAX_NAME];
    char        path[128];

    *name=0;

//ÄÄÄ Handle no filename for directory...
    if (argc < 2)
    {
        print_help(0);
        return;
    }

//ÄÄÄ Process arguments
    for(i=1, fn=0, outfn=0; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Quiet mode
                case 'q':
                case 'Q':
                    Flags |= FLAGS_QUIET;
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Info mode
                case 'i':
                case 'I':
                    Flags |= FLAGS_INFO;
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Detail polygons
                case 'd':
                case 'D':
                    Flags |= FLAGS_DETAILPOLYS;
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Wrap in scene
                case 's':
                case 'S':
                    Flags |= FLAGS_SCENE;
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Force one-sided
                case '1':
                    Flags |= FLAGS_FORCE_1SIDED;
                    break;
                    
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Force two-sided
                case '2':
                    Flags |= FLAGS_FORCE_2SIDED;
                    break;
                    
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Quick extents
                case 'k':
                case 'K':
                    Flags |= FLAGS_QUICK_EXTS;
                    break;
                    
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point
                case 'f':
                case 'F':
                    Flags |= FLAGS_FIXED;
                    break;
                    
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Output file

                case 'O':
                case 'o':
                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/')
                    {
                        cout << "°° Expected an image file name\n";
                        return;
                    }
                    Flags |= FLAGS_OUTPUT;
                    outfn=argv[i];
                    strlwr(outfn);
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Name
                case 'N':
                case 'n':
                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/')
                    {
                        cout << "°° Expected a name\n";
                        return;
                    }
                    strncpy(name,argv[i],sizeof(name));
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Help
                case '?':
                    print_help(1);
                    return;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Unknown option
                default:
                    cout << "Unknown option " << argv[i] << " ignored\n";
                    break;
            }
        }
        else if (!fn)
        {
            fn=strlwr(argv[i]);
        }
    }

    if (!fn)
    {
        print_help(0);
        return;
    }

//ÄÄÄ Check to see if supplied lw file exists
    if (!xf_exist(fn))
    {
        cout << "±±± " << fn << " does not exist" << endl;
        return;
    }

//ÄÄÄ Check for valid options
    if ((Flags & FLAGS_FORCE_1SIDED)
        && (Flags & FLAGS_FORCE_2SIDED))
    {
        cout << "±±± -1 and -2 options cannot both be specified" << endl;
        return;
    }

    if (Flags & FLAGS_OUTPUT)
    {
        if (!strcmp(fn,outfn))
        {
            cout << "±±± Output filename must be different than input" << endl;
            return;
        }

        char        drive[XF_MAX_DRIVE];
        char        dir[XF_MAX_DIR];
        char        fname[XF_MAX_FNAME];
        char        ext[XF_MAX_EXT];

        // Forces .IFF extention onto whatever output file is being used
        xf_splitpath(outfn,drive,dir,fname,ext);
        strcpy(ext,".iff");
        xf_makepath(path,drive,dir,fname,ext);

        outfn=path;
    }

//ÄÄÄ Open supplied lw file
    if (iff.open(fn,XF_OPEN_READ))
    {
        print_error(iff,"Failed to open file");
        return;
    }
   
//ÄÄÄ Find
    if (iff.seekform(iff.makeid('L','W','O','B')))
    {
        cout << "±±± " << fn << " does not contain lightwave data" << endl;
        return;
    }

    iff.enterform();

//ÄÄÄ Output title and source/output file stats.
    if (!(Flags & FLAGS_QUIET))
    {
        cout << Util_name;

        if (Flags & FLAGS_OUTPUT)
        {
            cout << "   Source: " << fn << "    Output: " << outfn << endl;
        }
        else
        {
            cout << "   Source: " << fn << endl;
        }
    }

    if (Flags & FLAGS_OUTPUT)
    {
        //ÄÄÄ Kill target file...
        xf_remove(outfn);

        //ÄÄÄ Open output file
        if (IFF.create(outfn,0))
        {
            print_error(IFF,"Failed to open output file");
            return;
        }

         atexit(cleanup);
    }

    if (!*name)
    {
        char        drive[XF_MAX_DRIVE];
        char        dir[XF_MAX_DIR];
        char        fname[XF_MAX_FNAME];
        char        ext[XF_MAX_EXT];

        xf_splitpath(fn,drive,dir,fname,ext);

        strncpy(name,fname,ESCH_MAX_NAME);
    }

    process(iff,name);

//ÄÄÄ Close file
    iff.close();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° Support Routines °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Cleanup function.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void cleanup(void)
{
    IFF.close();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// print_help                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void print_help(int full)
{
    cout << Util_name;
    cout << "   Usage: eshlw [-q] [-i] [-d] <filename.lw>" << endl;
    cout << "                [-s] [-1 | -2] [-k] [-f] [-n \"name\"]" << endl;
    cout << "                [-o <filename.iff>]" << endl;
    if (full)
    {
        cout << endl;
        cout << "          -q = Operate quietly." << endl;
        cout << "          -i = Display detailed info" << endl;
        cout << "          -d = Include detail polygons (normally skipped)." << endl;
        cout << endl;
        cout << "                  (only used when generating output)" << endl;
        cout << "          -s = Wrap exported object in a scene" << endl;
        cout << "          -1 = Force polygons to be one-sided" << endl;
        cout << "          -2 = Force polygons to be two-sided" << endl;
        cout << "          -k = Use quick extents computation (default is optimal)" << endl;
        cout << "          -f = Used fixed-point data format (default is floating-point)" << endl;
        cout << "          -n = Specifies output object name" << endl;
        cout << "          -o = Output to Escher IFF file" << endl;
    }
    cout << endl;
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
   
    cout << endl;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// print_info                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void print_info(Point *points, ulong maxpoints,
                       Poly *polys, ulong maxpolys,
                       Surface *surfs, ulong maxsurfs)
{
    //ÄÄÄ Points
    if (Flags & FLAGS_INFO)
    {
        printf("   Points:\n");

        Point *ptr = points;
        for(ulong i=0; i < maxpoints; i++, ptr++)
        {
            cout.flush();
            printf("[%i]     X: %6.2f   Y: %6.2f   Z: %6.2f\n",
                   i+1,
                   ptr->x,
                   ptr->y,
                   ptr->z);
        }
    }

    if (!(Flags & FLAGS_QUIET) 
        || Flags & FLAGS_INFO)
    {
        printf("           %i points\n",maxpoints);
    }

    //ÄÄÄ Polygons
    if (Flags & FLAGS_INFO)
    {
        printf("\n   Polygons:\n");

        Poly *ptr = polys;
        for(ulong i=0; i < maxpolys; i++, ptr++)
        {
            cout.flush();
            const char *nptr = ((ulong)ptr->surf-1 >= maxsurfs)
                               ? "Error!"
                               : surfs[ptr->surf-1].name;

            printf("[%i]     '%s'   #%d\n",
                   i+1, nptr, ptr->num);

            printf("          ");
            short *vert = ptr->verts;
            for(short n=0; n < ptr->num; n++)
            {
                if (n)
                    printf(", ");
                printf("%i",*(vert++));
            }
            printf("\n");
        }
    }

    if (!(Flags & FLAGS_QUIET) 
        || Flags & FLAGS_INFO)
    {
        printf("           %i polygons\n",maxpolys);
    }

    //ÄÄÄ Surfaces
    if (Flags & FLAGS_INFO)
    {
        printf("\n   Surfaces:\n");

        for(ulong i=0; i < maxsurfs; i++)
        {
            cout.flush();
            printf("[%i]     '%s'\n",
                   i+1,
                   surfs[i].name);
            printf("        colr=%06x  %s %s %s\n",
                   surfs[i].color,
                   (surfs[i].flags & ESCH_FACE_ONESIDED) ? "" : "TWOSIDED",
                   (surfs[i].flags & ESCH_FACE_SPECULAR) ? "SPECULAR" : "",
                   (surfs[i].selfi) ? "LUMINOUS" : "");
        }
    }

    if (!(Flags & FLAGS_QUIET) 
        || Flags & FLAGS_INFO)
    {
        printf("           %i surfaces\n",maxsurfs);
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



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° Process Routines °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// process                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void process(XFParseIFF &iff, const char *name)
{
//ÄÄÄ Points
    ulong maxpoints;
    Point *points = process_points(iff,maxpoints);
    if (!points)
        return;

//ÄÄÄ Surface List
    ulong maxsurfs;
    Surface *surfs = process_surface_list(iff,maxsurfs);
    if (!surfs)
        return;

//ÄÄÄ Polygons
    ulong maxpolys;
    Poly *polys = process_polygons(iff,maxpolys);
    if (!polys)
        return;

//ÄÄÄ Surface
    if (!process_surfaces(iff,surfs,maxsurfs))
        return;

//ÄÄÄ Print info
    print_info(points,maxpoints,
               polys,maxpolys,
               surfs,maxsurfs);

    if (!(Flags & FLAGS_OUTPUT))
        return;

//ÄÄÄ If we need to build mesh, do so
    generate(name,
             points,maxpoints,
             polys,maxpolys,
             surfs,maxsurfs);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// process_points                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC Point *process_points(XFParseIFF &iff, ulong &max)
{
//ÄÄÄ Find and read points data
    if (iff.seekchunk(iff.makeid('P','N','T','S'))
        || !iff.chunkSize)
    {
        cout << "±±± Missing points" << endl;
        return NULL;
    }

    float *data = new float[iff.chunkSize / sizeof(float)];
    if (!data)
    {
        cout << "±±± Out of memory!" << endl;
        return NULL;
    }
    
    if (iff.read(data))
    {
        cout << "±±± Failed to read points" << endl;
        return NULL;
    }

//ÄÄÄ Convert to Intel format
    {
        dword *ptr=(dword*)data;
        for(ulong i=0; i < iff.chunkSize / 4; i++)
        {
            *ptr = iff.swapendian(*(ptr));
            ptr++;
        }
    }

    max = iff.chunkSize / 12;

//ÄÄÄ Convert to internal format
    assert(max > 0);

    Point *points = new Point[max];
    if (!points)
    {
        cout << "±±± Out of memory!" << endl;
        return NULL;
    }
    else
    {
        float *ptr=data;
        for(ulong i=0; i < max; i++)
        {
            points[i].x = *(ptr++);
            points[i].y = *(ptr++);
            points[i].z = *(ptr++);
        }
    }

    delete [] data;

    return points;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// process_surface_list                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC Surface *process_surface_list(XFParseIFF &iff, ulong &max)
{
//ÄÄÄ Find and read surface data
    if (iff.seekchunk(iff.makeid('S','R','F','S'))
        || !iff.chunkSize)
    {
        cout << "±±± Missing surface list" << endl;
        return NULL;
    }

    char *data = new char[iff.chunkSize];
    if (!data)
    {
        cout << "±±± Out of memory!" << endl;
        return NULL;
    }
    
    if (iff.read(data))
    {
        cout << "±±± Failed to read surface list" << endl;
        return NULL;
    }

//ÄÄÄ Count the number of names
    max=0;
    {
        char *ptr = data;
        for(ulong s=0; s < iff.chunkSize; s++, ptr++)
        {
            if (!*ptr)
            {
                if (s & 0x1)
                {
                    s++;
                    ptr++;
                }
                else
                {
                    s+=2;
                    ptr+=2;
                }
                max++;
            }
        }
    }

    if (!max)
    {
        cout << "±±± Failed to find data in surface list" << endl;
        return NULL;
    }

//ÄÄÄ Convert to internal format
    Surface *surfs = new Surface[max];
    if (!surfs)
    {
        cout << "±±± Out of memory!" << endl;
        return NULL;
    }

    {
        char *ptr = data;
        char *prev = data;
        for(ulong s=0, i=0; s < iff.chunkSize; s++, ptr++)
        {
            if (!*ptr)
            {
                if (s & 0x1)
                {
                    s++;
                    ptr++;
                }
                else
                {
                    s+=2;
                    ptr+=2;
                }

                surfs[i].name = new char[strlen(prev)+1];
                if (!surfs[i].name)
                {
                    cout << "±±± Out of memory!" << endl;
                    return NULL;
                }
                strcpy(surfs[i].name,prev);

                surfs[i].flags = ESCH_FACE_ABLINE
                                 | ESCH_FACE_BCLINE
                                 | ESCH_FACE_CALINE
                                 | ESCH_FACE_WIRE
                                 | ESCH_FACE_SOLID
                                 | ESCH_FACE_ALLOWPERSP
                                 | ESCH_FACE_SMOOTH
                                 | ESCH_FACE_FLAT
                                 | ((Flags & FLAGS_FORCE_2SIDED)
                                    ? 0 : ESCH_FACE_ONESIDED);

                ((VngoColor24bit*)&surfs[i].color)->r = 128;
                ((VngoColor24bit*)&surfs[i].color)->g = 128;
                ((VngoColor24bit*)&surfs[i].color)->b = 128;

                surfs[i].selfi = 0;
                surfs[i].alpha = 255;
                i++;
                prev = ptr;
            }
        }
    }

    delete [] data;

    return surfs;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// process_polygons                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC Poly *process_polygons(XFParseIFF &iff, ulong &max)
{
//ÄÄÄ Find and read surface data
    if (iff.seekchunk(iff.makeid('P','O','L','S'))
        || !iff.chunkSize)
    {
        cout << "±±± Missing polygons" << endl;
        return NULL;
    }

    short *data = new short[iff.chunkSize / 2];
    if (!data)
    {
        cout << "±±± Out of memory!" << endl;
        return NULL;
    }
    
    if (iff.read(data))
    {
        cout << "±±± Failed to read polygons" << endl;
        return NULL;
    }

//ÄÄÄ Convert to Intel format
    {
        short *ptr=data;
        for(ulong i=0; i < iff.chunkSize / 2; i++)
        {
            *ptr = ((*ptr & 0xff00) >> 8)
                   | ((*ptr & 0x00ff) << 8);
            ptr++;
        }
    }

//ÄÄÄ Count the number of polygons
    max = 0;
    {
        for(short *ptr=data; ptr < data+(iff.chunkSize / 2);)
        {
            short numverts = *(ptr++);
            while(numverts--)
                ptr++;

            short surf = *(ptr++);

            max++;
            if (surf < 0)
            {
                // Detail polygons
                short numdetails = *(ptr++);
                while (numdetails--)
                {
                    short numverts = *(ptr++);
                    while (numverts-- > 0)
                        ptr++;
                    ptr++;

                    if (Flags & FLAGS_DETAILPOLYS)
                        max++;
                }
            }
        }
    }

//ÄÄÄ Convert to internal format
    Poly *polys = new Poly[max];
    if (!polys)
    {
        cout << "±±± Out of memory!" << endl;
        return NULL;
    }
    else {
        ulong i=0;
        for(short *ptr=data; ptr < data+(iff.chunkSize / 2);)
        {
            short numverts = *(ptr++);

            polys[i].num = numverts;

            short *pptr = new short[numverts];
            if (!pptr)
            {
                cout << "±±± Out of memory!" << endl;
                return NULL;
            }
            polys[i].verts = pptr;

            while(numverts--)
            {
                *(pptr++) = *(ptr++);
            }

            short surf = *(ptr++);
            polys[i].surf = abs(surf);

            i++;
            if (surf < 0)
            {
                // Detail polygons
                short numdetails = *(ptr++);
                while (numdetails--)
                {
                    short numverts = *(ptr++);

                    if (Flags & FLAGS_DETAILPOLYS)
                    {
                        polys[i].num = numverts;
    
                        short *pptr = new short[numverts];
                        if (!pptr)
                        {
                            cout << "±±± Out of memory!" << endl;
                            return NULL;
                        }
                        polys[i].verts = pptr;

                        while (numverts-- > 0)
                        {
                            *(pptr++) = *(ptr++);
                        }
                        polys[i].surf = *(ptr++);
                        i++;
                    }
                    else
                    {
                        while (numverts-- > 0)
                            ptr++;
                        ptr++;
                    }
                }
            }
        }
    }

    delete [] data;

    return polys;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// process_surfaces                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC BOOL process_surfaces(XFParseIFF &iff, Surface *surfs, ulong max)
{
    while (iff.next() == XF_ERR_NONE)
    {
        if (iff.chunkid != iff.makeid('S','U','R','F'))
            continue;

        //ÄÄÄ Read surface data
        if (!iff.chunkSize)
        {
            cout << "±±± Missing surface data" << endl;
            return FALSE;
        }

        char *data = new char[iff.chunkSize];

        if (iff.read(data))
        {
            cout << "±±± Failed to read surface data" << endl;
            return FALSE;
        }

        //ÄÄÄ Find corresponding structure in surface list
        for(ulong index=0; index < max; index++)
        {
            if (!strcmp(surfs[index].name,data))
                break;
        }

        if (index >= max)
            continue;

        Surface *surf = &surfs[index];

        //ÄÄÄ Find start of data
        ulong s = 0;
        for(byte *ptr=(byte*)data; *ptr; ptr++, s++);

        if (s & 0x1)
        {
            ptr++;
        }
        else
        {
            ptr += 2;
        }

        //ÄÄÄ Process sub-chunks
        while (ptr < ((byte*)data+iff.chunkSize))
        {
            dword id = *((dword*)ptr);  ptr += 4;

            ushort size = (*ptr << 8) | *(ptr+1);
            ptr += 2;

            if (id == iff.makeid('C','O','L','R')
                && size == 4)
            {
                ((VngoColor24bit*)&surf->color)->r = *ptr;
                ((VngoColor24bit*)&surf->color)->g = *(ptr+1);
                ((VngoColor24bit*)&surf->color)->b = *(ptr+2);
            }
            else if (id == iff.makeid('F','L','A','G')
                     && size == 2)
            {
                ushort flags = (*ptr << 8) | *(ptr+1); 

                if (flags & LW_SURF_FLAG_DOUBLE_SIDED
                    && !(Flags & FLAGS_FORCE_1SIDED))
                {
                    surf->flags &= ~ESCH_FACE_ONESIDED;
                }

                if (flags & LW_SURF_FLAG_LUMINOUS)
                {
                    surf->selfi = 128;
                }
            }
            else if (id == iff.makeid('L','U','M','I')
                     && size == 2)
            {
                short value = (*ptr << 8) | *(ptr+1); 

                if (value > 0)
                    surf->selfi = byte((value-1) & 0xff);
            }
            else if (id == iff.makeid('S','P','E','C')
                     && size == 2)
            {
                short value = (*ptr << 8) | *(ptr+1); 

                if (value >= 128)
                    surf->flags |= ESCH_FACE_SPECULAR;
            }

            ptr += size;
        }

        delete [] data;
    }

//ÄÄÄ Check for unexpected error
    if (iff.error() != XF_ERR_EOF)
    {
        print_error(iff,"Unexpected error processing surfaces");
        return FALSE;
    }

    return TRUE;
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° Generate Routine °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// generate                                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void generate(const char *name,
                     Point *points, ulong maxpoints,
                     Poly *polys, ulong maxpolys,
                     Surface *surfs, ulong maxsurfs)
{
//ÄÄÄ Determine number of triangle faces we are going to generate
    ulong mfaces=0;
    {
        Poly *ptr = polys;
        for(ulong i=0; i < maxpolys; i++, ptr++)
        {
            if ((ulong)ptr->surf-1 >= maxsurfs)
            {
                cout << "±±± Face " << i+1 << " has an invalid surface reference " << endl;
                return;
            }

            if (ptr->num >= 3)
                mfaces += (ptr->num-2);
        }
    }

    if (!(Flags & FLAGS_QUIET) 
        || Flags & FLAGS_INFO)
    {
        printf("           %i faces generated\n", mfaces);
    }

    esch_error_codes    err;

//ÄÄÄ Initialize mesh builder
    EschBuildMesh mbld;
    if ((err=mbld.init(maxpoints,mfaces,0))!=0)
    {
        cout << "±±± Failed to create mesh builder, error #" << (int)err
             << endl;
        return;
    }

    strncpy(mbld.name,name,ESCH_MAX_NAME);

//ÄÄÄ Add verticies
    if (!(Flags & FLAGS_QUIET))
    {
        printf("Generating verticies...\n");
        fflush(stdout);
    }

    {
        Point *ptr = points;
        for(ulong i=0; i < maxpoints; i++, ptr++)
        {
            EschPoint pnt(float(ptr->x),
                          float(ptr->y),
                          float(ptr->z));
            if ((err=mbld.add_vertex(&pnt))!=0)
            {
                cout << "±±± Failed to add vertex " << i+1 << " to mesh, error #"
                     << (int)err << endl;
                return;
            }
        }
    }
    
//ÄÄÄ Add faces
    if (!(Flags & FLAGS_QUIET))
    {
        printf("Generating faces...\n");
        fflush(stdout);
    }

    {
        Poly *ptr = polys;
        for(ulong i=0; i < maxpolys; i++, ptr++)
        {
            if (ptr->num < 3)
                continue;

            mbld.set_face_flags(surfs[ptr->surf-1].flags);
            mbld.set_self_illum(surfs[ptr->surf-1].selfi);
            mbld.set_alpha(surfs[ptr->surf-1].alpha);

            dword color = surfs[ptr->surf-1].color;

            for(short j=1; j < (ptr->num-1); j++)
            {
                word base = (word)*ptr->verts;

                word *vert = (word*)ptr->verts + j;

                if ((err=mbld.add_face(base, *vert, *(vert+1), color)) != 0)
                {
                    cout << "±±± Failed to add face from polygon #" << i+1
                         << " to mesh, error #" << (int)err << endl;
                    return;
                }
            }
        }
    }

//ÄÄÄ Compute normals
    if (!(Flags & FLAGS_QUIET))
    {
        printf("Computing normals...\n");
        fflush(stdout);
    }

    if ((err=mbld.compute_normals())!=0)
    {
        cout << "±±± Failed to compute normals, error #" << (int)err
             << endl;
        return;
    }

//ÄÄÄ Compute normals
    if (!(Flags & FLAGS_QUIET))
    {
        printf("Computing extents...\n");
        fflush(stdout);
    }

    if ((err=mbld.compute_extents((Flags & FLAGS_QUICK_EXTS) ? 0 : 1))!=0)
    {
        cout << "±±± Failed to compute extents, error #" << (int)err
             << endl;
        return;
    }

//ÄÄÄ Save to data file
    if (!(Flags & FLAGS_QUIET))
    {
        printf("Saving object '%s'...\n",name);
        fflush(stdout);
    }

    if ((err=mbld.save(&IFF, ESCH_MBLD_EXTENTS
                             | ((Flags & FLAGS_SCENE) ? ESCH_MBLD_INSCENE : 0)
                             | ((Flags & FLAGS_FIXED) ? ESCH_MBLD_FIXED : 0)))!=0)
    {
        cout << "±±± Failed write of mesh, error #" << (int)err << endl;
        return;
    }

    if (!(Flags & FLAGS_QUIET))
    {
        printf("Done\n\n");
    }
}

//°±² End of module - eshlw.cpp ²±°

