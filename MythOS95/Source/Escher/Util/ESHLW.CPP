//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

#include "debug.h"
#include "xfile.hpp"
#include "escher.hpp"
#include "esfile.hpp"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define FLAGS_QUIET         0x1
#define FLAGS_INFO          0x2
#define FLAGS_OUTPUT        0x4
#define FLAGS_DETAILPOLYS   0x8
#define FLAGS_SCENE         0x10
#define FLAGS_FORCE_1SIDED  0x20
#define FLAGS_FORCE_2SIDED  0x40
#define FLAGS_QUICK_EXTS    0x80

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

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

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
};

struct Poly    
{
    short   num;
    short   surf;
    short   *verts;
};

//���������������������������������������������������������������������������
//
//                               Routines
//
//���������������������������������������������������������������������������

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

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

STATIC dword   Flags=0;

STATIC char Util_name[]
        = "�� Escher Lightwave Converter - (C) 1997 Charybdis Enterprises, Inc. ��\n"
          "                                All Rights Reserved.  " __DATE__ "\n";

XFParseIFF     IFF;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//����������������������������� Entry Point ���������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// main                                                                     �
//                                                                          �
// Entry point for the ESHLW utility.                                       �
//���������������������������������������������������������������������������
void main(int argc, char *argv[])
{
    int         i;
    char        *fn;
    char        *outfn;
    XFParseIFF  iff;
    char        name[ESCH_MAX_NAME];
    char        path[128];

    *name=0;

//��� Handle no filename for directory...
    if (argc < 2)
    {
        print_help(0);
        return;
    }

//��� Process arguments
    for(i=1, fn=0, outfn=0; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {
                //������������������������������������� Quiet mode
                case 'q':
                case 'Q':
                    Flags |= FLAGS_QUIET;
                    break;

                //������������������������������������� Info mode
                case 'i':
                case 'I':
                    Flags |= FLAGS_INFO;
                    break;

                //������������������������������������� Detail polygons
                case 'd':
                case 'D':
                    Flags |= FLAGS_DETAILPOLYS;
                    break;

                //������������������������������������� Wrap in scene
                case 's':
                case 'S':
                    Flags |= FLAGS_SCENE;
                    break;

                //������������������������������������� Force one-sided
                case '1':
                    Flags |= FLAGS_FORCE_1SIDED;
                    break;
                    
                //������������������������������������� Force two-sided
                case '2':
                    Flags |= FLAGS_FORCE_2SIDED;
                    break;
                    
                //������������������������������������� Force two-sided
                case 'k':
                case 'K':
                    Flags |= FLAGS_QUICK_EXTS;
                    break;
                    
                //������������������������������������� Output file

                case 'O':
                case 'o':
                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/')
                    {
                        cout << "�� Expected an image file name\n";
                        return;
                    }
                    Flags |= FLAGS_OUTPUT;
                    outfn=argv[i];
                    strlwr(outfn);
                    break;

                //������������������������������������� Name
                case 'N':
                case 'n':
                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/')
                    {
                        cout << "�� Expected a name\n";
                        return;
                    }
                    strncpy(name,argv[i],sizeof(name));
                    break;

                //������������������������������������� Help
                case '?':
                    print_help(1);
                    return;

                //������������������������������������� Unknown option
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

//��� Check to see if supplied lw file exists
    if (!xf_exist(fn))
    {
        cout << "��� " << fn << " does not exist" << endl;
        return;
    }

//��� Check for valid options
    if ((Flags & FLAGS_FORCE_1SIDED)
        && (Flags & FLAGS_FORCE_2SIDED))
    {
        cout << "��� -1 and -2 options cannot both be specified" << endl;
        return;
    }

    if (Flags & FLAGS_OUTPUT)
    {
        if (!strcmp(fn,outfn))
        {
            cout << "��� Output filename must be different than input" << endl;
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

//��� Open supplied lw file
    if (iff.open(fn,XF_OPEN_READ))
    {
        print_error(iff,"Failed to open file");
        return;
    }
   
//��� Find
    if (iff.seekform(iff.makeid('L','W','O','B')))
    {
        cout << "��� " << fn << " does not contain lightwave data" << endl;
        return;
    }

    iff.enterform();

//��� Output title and source/output file stats.
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
        //��� Kill target file...
        xf_remove(outfn);

        //��� Open output file
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

//��� Close file
    iff.close();
}



//���������������������������������������������������������������������������
//�������������������������� Support Routines �������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// Cleanup function.                                                         �
//���������������������������������������������������������������������������
STATIC void cleanup(void)
{
    IFF.close();
}


//�������������������������������������������������������������������������Ŀ
// print_help                                                               �
//���������������������������������������������������������������������������
STATIC void print_help(int full)
{
    cout << Util_name;
    cout << "   Usage: eshlw [-q] [-i] [-d] <filename.lw>" << endl;
    cout << "                [-s] [-1 | -2] [-k] [-n \"name\"]" << endl;
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
        cout << "          -n = Specifies output object name" << endl;
        cout << "          -o = Output to Escher IFF file" << endl;
    }
    cout << endl;
}


//�������������������������������������������������������������������������Ŀ
// print_error                                                              �
//���������������������������������������������������������������������������
STATIC void print_error(XFParseIFF &xp, char *s)
{
    cout << "��� ";
   
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


//�������������������������������������������������������������������������Ŀ
// print_info                                                               �
//���������������������������������������������������������������������������
STATIC void print_info(Point *points, ulong maxpoints,
                       Poly *polys, ulong maxpolys,
                       Surface *surfs, ulong maxsurfs)
{
    //��� Points
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

    //��� Polygons
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

    //��� Surfaces
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
                   (surfs[i].flags & ESCH_FACE_SELFILUM_MASK) ? "LUMINOUS" : "");
        }
    }

    if (!(Flags & FLAGS_QUIET) 
        || Flags & FLAGS_INFO)
    {
        printf("           %i surfaces\n",maxsurfs);
    }
}


//���������������������������������������������������������������������������
// _charybdis_assert
// 
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//���������������������������������������������������������������������������
extern "C" void _charybdis_assert(char *msg, char *exp, char *f, unsigned ln)
{
    cout.flush();
    printf("\n\n��� Assertion Failed ����������������������������������\n"
           "Expr:\t%s\n"
           "File:\t%s\t\tLine %d\n",exp,f,ln);
    if (msg)
    {
        printf("Comment:\n%s\n",msg);
    }

    exit(1);
}



//���������������������������������������������������������������������������
//�������������������������� Process Routines �������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// process                                                                  �
//���������������������������������������������������������������������������
STATIC void process(XFParseIFF &iff, const char *name)
{
//��� Points
    ulong maxpoints;
    Point *points = process_points(iff,maxpoints);
    if (!points)
        return;

//��� Surface List
    ulong maxsurfs;
    Surface *surfs = process_surface_list(iff,maxsurfs);
    if (!surfs)
        return;

//��� Polygons
    ulong maxpolys;
    Poly *polys = process_polygons(iff,maxpolys);
    if (!polys)
        return;

//��� Surface
    if (!process_surfaces(iff,surfs,maxsurfs))
        return;

//��� Print info
    print_info(points,maxpoints,
               polys,maxpolys,
               surfs,maxsurfs);

    if (!(Flags & FLAGS_OUTPUT))
        return;

//��� If we need to build mesh, do so
    generate(name,
             points,maxpoints,
             polys,maxpolys,
             surfs,maxsurfs);
}


//�������������������������������������������������������������������������Ŀ
// process_points                                                           �
//���������������������������������������������������������������������������
STATIC Point *process_points(XFParseIFF &iff, ulong &max)
{
//��� Find and read points data
    if (iff.seekchunk(iff.makeid('P','N','T','S'))
        || !iff.chunkSize)
    {
        cout << "��� Missing points" << endl;
        return NULL;
    }

    float *data = new float[iff.chunkSize / sizeof(float)];
    if (!data)
    {
        cout << "��� Out of memory!" << endl;
        return NULL;
    }
    
    if (iff.read(data))
    {
        cout << "��� Failed to read points" << endl;
        return NULL;
    }

//��� Convert to Intel format
    {
        dword *ptr=(dword*)data;
        for(ulong i=0; i < iff.chunkSize / 4; i++)
        {
            *ptr = iff.swapendian(*(ptr));
            ptr++;
        }
    }

    max = iff.chunkSize / 12;

//��� Convert to internal format
    assert(max > 0);

    Point *points = new Point[max];
    if (!points)
    {
        cout << "��� Out of memory!" << endl;
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


//�������������������������������������������������������������������������Ŀ
// process_surface_list                                                     �
//���������������������������������������������������������������������������
STATIC Surface *process_surface_list(XFParseIFF &iff, ulong &max)
{
//��� Find and read surface data
    if (iff.seekchunk(iff.makeid('S','R','F','S'))
        || !iff.chunkSize)
    {
        cout << "��� Missing surface list" << endl;
        return NULL;
    }

    char *data = new char[iff.chunkSize];
    if (!data)
    {
        cout << "��� Out of memory!" << endl;
        return NULL;
    }
    
    if (iff.read(data))
    {
        cout << "��� Failed to read surface list" << endl;
        return NULL;
    }

//��� Count the number of names
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
        cout << "��� Failed to find data in surface list" << endl;
        return NULL;
    }

//��� Convert to internal format
    Surface *surfs = new Surface[max];
    if (!surfs)
    {
        cout << "��� Out of memory!" << endl;
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
                    cout << "��� Out of memory!" << endl;
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
                i++;
                prev = ptr;
            }
        }
    }

    delete [] data;

    return surfs;
}


//�������������������������������������������������������������������������Ŀ
// process_polygons                                                         �
//���������������������������������������������������������������������������
STATIC Poly *process_polygons(XFParseIFF &iff, ulong &max)
{
//��� Find and read surface data
    if (iff.seekchunk(iff.makeid('P','O','L','S'))
        || !iff.chunkSize)
    {
        cout << "��� Missing polygons" << endl;
        return NULL;
    }

    short *data = new short[iff.chunkSize / 2];
    if (!data)
    {
        cout << "��� Out of memory!" << endl;
        return NULL;
    }
    
    if (iff.read(data))
    {
        cout << "��� Failed to read polygons" << endl;
        return NULL;
    }

//��� Convert to Intel format
    {
        short *ptr=data;
        for(ulong i=0; i < iff.chunkSize / 2; i++)
        {
            *ptr = ((*ptr & 0xff00) >> 8)
                   | ((*ptr & 0x00ff) << 8);
            ptr++;
        }
    }

//��� Count the number of polygons
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

//��� Convert to internal format
    Poly *polys = new Poly[max];
    if (!polys)
    {
        cout << "��� Out of memory!" << endl;
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
                cout << "��� Out of memory!" << endl;
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
                            cout << "��� Out of memory!" << endl;
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


//�������������������������������������������������������������������������Ŀ
// process_surfaces                                                         �
//���������������������������������������������������������������������������
STATIC BOOL process_surfaces(XFParseIFF &iff, Surface *surfs, ulong max)
{
    while (iff.next() == XF_ERR_NONE)
    {
        if (iff.chunkid != iff.makeid('S','U','R','F'))
            continue;

        //��� Read surface data
        if (!iff.chunkSize)
        {
            cout << "��� Missing surface data" << endl;
            return FALSE;
        }

        char *data = new char[iff.chunkSize];

        if (iff.read(data))
        {
            cout << "��� Failed to read surface data" << endl;
            return FALSE;
        }

        //��� Find corresponding structure in surface list
        for(ulong index=0; index < max; index++)
        {
            if (!strcmp(surfs[index].name,data))
                break;
        }

        if (index >= max)
            continue;

        Surface *surf = &surfs[index];

        //��� Find start of data
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

        //��� Process sub-chunks
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
                    surf->flags |= ESCH_FACE_SELFILUM_MASK;
                }
            }
            else if (id == iff.makeid('L','U','M','I')
                     && size == 2)
            {
                short value = (*ptr << 8) | *(ptr+1); 

                assert(ESCH_FACE_SELFILLUM_MASK == 0xf00000);

                surf->flags &= ~ESCH_FACE_SELFILUM_MASK;

                if (value > 0)
                    surf->flags |= ((value-1) & 0xff) << 20;
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

//��� Check for unexpected error
    if (iff.error() != XF_ERR_EOF)
    {
        print_error(iff,"Unexpected error processing surfaces");
        return FALSE;
    }

    return TRUE;
}


//���������������������������������������������������������������������������
//�������������������������� Generate Routine �������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// generate                                                                 �
//���������������������������������������������������������������������������
STATIC void generate(const char *name,
                     Point *points, ulong maxpoints,
                     Poly *polys, ulong maxpolys,
                     Surface *surfs, ulong maxsurfs)
{
//��� Determine number of triangle faces we are going to generate
    ulong mfaces=0;
    {
        Poly *ptr = polys;
        for(ulong i=0; i < maxpolys; i++, ptr++)
        {
            if ((ulong)ptr->surf-1 >= maxsurfs)
            {
                cout << "��� Face " << i+1 << " has an invalid surface reference " << endl;
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

//��� Initialize mesh builder
    EschBuildMesh mbld;
    if ((err=mbld.init(maxpoints,mfaces,0))!=0)
    {
        cout << "��� Failed to create mesh builder, error #" << (int)err
             << endl;
        return;
    }

    strncpy(mbld.name,name,ESCH_MAX_NAME);

//��� Add verticies
    if (!(Flags & FLAGS_QUIET))
    {
        printf("Generating verticies...\n");
        fflush(stdout);
    }

    {
        Point *ptr = points;
        for(ulong i=0; i < maxpoints; i++, ptr++)
        {
            EschPoint pnt(Flx16(ptr->x),
                          Flx16(ptr->y),
                          Flx16(ptr->z));
            if ((err=mbld.add_vertex(&pnt))!=0)
            {
                cout << "��� Failed to add vertex " << i+1 << " to mesh, error #"
                     << (int)err << endl;
                return;
            }
        }
    }
    
//��� Add faces
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

            dword color = surfs[ptr->surf-1].color;

            for(short j=1; j < (ptr->num-1); j++)
            {
                word base = (word)*ptr->verts;

                word *vert = (word*)ptr->verts + j;

                if ((err=mbld.add_face(base, *vert, *(vert+1), color)) != 0)
                {
                    cout << "��� Failed to add face from polygon #" << i+1
                         << " to mesh, error #" << (int)err << endl;
                    return;
                }
            }
        }
    }

//��� Compute normals
    if (!(Flags & FLAGS_QUIET))
    {
        printf("Computing normals...\n");
        fflush(stdout);
    }

    if ((err=mbld.compute_normals())!=0)
    {
        cout << "��� Failed to compute normals, error #" << (int)err
             << endl;
        return;
    }

//��� Compute normals
    if (!(Flags & FLAGS_QUIET))
    {
        printf("Computing extents...\n");
        fflush(stdout);
    }

    if ((err=mbld.compute_extents((Flags & FLAGS_QUICK_EXTS) ? 0 : 1))!=0)
    {
        cout << "��� Failed to compute extents, error #" << (int)err
             << endl;
        return;
    }

//��� Save to data file
    if (!(Flags & FLAGS_QUIET))
    {
        printf("Saving object '%s'...\n",name);
        fflush(stdout);
    }

    if ((err=mbld.save(&IFF, ESCH_MBLD_EXTENTS
                             | ((Flags & FLAGS_SCENE) ? ESCH_MBLD_INSCENE : 0)))!=0)
    {
        cout << "��� Failed write of mesh, error #" << (int)err << endl;
        return;
    }

    if (!(Flags & FLAGS_QUIET))
    {
        printf("Done\n\n");
    }
}

//��� End of module - eshlw.cpp ���
