//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                                /\    /\
//                               /  \  /  \
//                              /    \/    \
//                             /  /\    /\  \
//                            /  /  \  /  Y T H O S
//                           /  /    \/    \  \
//                          /  /            \  \
//                         /__/              \__\
//
//                  Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Chuck Walbourn
//
// pic.cpp
//
//     Picture/bitmap recolor utility.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include <ivory.hpp>
#include <xfile.hpp>
#include <vangogh.hpp>

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define FLAGS_QUIET     0x1     // Keep silent
#define FLAGS_PALETTED  0x4     // Make file paletted
#define FLAGS_INFO      0x8     // Display image information
#define FLAGS_OUTPUT    0x10    // Output image after any ops
#define FLAGS_PALPRINT  0x20    // Display image palette
#define FLAGS_TRANSP    0x40    // Transparent (don't lookup color 255).
#define FLAGS_COMPRESS  0x80    // Compress transparent images to monochrome.
#define FLAGS_2BPP      0x100   // Convert to 2 bytes/pixel
#define FLAGS_3BPP      0x200   // Convert to 3 bytes/pixel

using namespace std;

//--- Error values ---
typedef enum _pic_err_codes {
    PIC_ERR_NONE                       =0,

    PIC_ERR_NOTSUPPORTED               =1,
    PIC_ERR_NOMEMORY                   =2,
    PIC_ERR_LOCKFAILED                 =3,
} pic_err_codes;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class PicCanvas : public XFBitmap
{

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    PicCanvas() {}
    ~PicCanvas() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations on Canvas objects.                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    pic_err_codes convert_to_paletted(VngoPal8 *pal);
    pic_err_codes convert_to_2bpp();
    pic_err_codes convert_to_3bpp();
    byte *compress_transparent();
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

STATIC void print_help(int full);
STATIC int load_pal(VngoPal *pal,char *infile);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

char Util_name[] = "葦 MythOS Pic Image Utility - (C) 1994-1999 by D. Higdon, T. Little, and C. Walbourn 碓\n"
                   "                              Subject to terms of MIT License " __DATE__ "\n";



IvorySystem     Ivory;

dword           Flags=0;

char            Pal_name[128];
VngoPal         *Palette=0;
PicCanvas       *Canvas=0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// main                                                                     �
//                                                                          �
// Entry point for the Pic utility.                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void main(int argc, char *argv[])
{
    int         err;
    int         i;
    char        *fn;
    char        *outfn;

    VngoZMap   zmp;
    byte *tptr=0;

//陳� Setup default palette file
    strcpy(Pal_name,argv[0]);
    strlwr(Pal_name);
    for(i=strlen(Pal_name); i >= 0; i--)
    {
        if (Pal_name[i]=='\\')
        {
            strcpy(&Pal_name[i+1],"default.pal");
            break;
        }
    }

//陳� Handle no filename...
    if (argc < 2)
    {
        print_help(0);
        return;
    }

//陳� Process arguments
    for(i=1, fn=0, outfn=0; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Quiet mode

                case 'Q':
                case 'q':
                    Flags |= FLAGS_QUIET;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Display image information

                case 'I':
                case 'i':
                    Flags |= FLAGS_INFO;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Display image palette

                case 'S':
                case 's':
                    Flags |= FLAGS_PALPRINT;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Paletted file

                case 'P':
                case 'p':
                    Flags |= FLAGS_PALETTED;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Palette file

                case 'T':
                case 't':
                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/' ||
                        (!strstr(strlwr(argv[i]),".pal")
                         && !strstr(strlwr(argv[i]),".vgp")))
                    {
                        cout << "旭 Expected a palette file name\n";
                        return;
                    }
                    strcpy(Pal_name,argv[i]);
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� 2bpp

                case '2':
                    Flags |= FLAGS_2BPP;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� 3bpp

                case '3':
                    Flags |= FLAGS_3BPP;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Output file

                case 'O':
                case 'o':
                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/')
                    {
                        cout << "旭 Expected an image file name\n";
                        return;
                    }
                    Flags |= FLAGS_OUTPUT;
                    outfn=argv[i];
                    strlwr(outfn);
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Transparent

                case 'X':
                case 'x':
                    Flags |= FLAGS_TRANSP;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Compress to Mono

                case 'M':
                case 'm':
                    Flags |= FLAGS_COMPRESS;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Help

                case '?':
                    print_help(1);
                    return;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Unknown option

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
        cout << "旭 Expected an input image file name\n";
        return;
    }

//陳� Banner
    if (!(Flags & FLAGS_QUIET))
    {
        cout << Util_name;
    }

//陳� Check to see if supplied files exist
    if (!xf_exist(fn))
    {
        cout << "臼� Input file " << fn << " not found\n";
        return;
    }

    if (!xf_exist(Pal_name))
    {
        cout << "臼� Palette file " << Pal_name << " not found\n";
    }

//陳� Check for valid options
    if (Flags & FLAGS_OUTPUT)
    {
        if (!outfn || (!strstr(outfn,".tga")
                       && !strstr(outfn,".pcx")
                       && !strstr(outfn,".lbm")
                       && !strstr(outfn,".cel")
                       && !strstr(outfn,".bmp")
                       && !strstr(outfn,".xeb")
                       && !strstr(outfn,".zmp")))
        {
            cout << "臼� Unrecognized output image type...\n";
            return;
        }

        if (!strcmp(fn,outfn))
        {
            cout << "臼� Will overwrite original, ok? (Y/n)";
            cout.flush();
            for(;;)
            {
                i=getch();
                cout << (char)i << "\n";

                if (i == 'Y' || i == 'y' || i == 13)
                    break;
                else if (i=='n' || i == 'N')
                    goto error_exit;

                break;
            }
        }
    }

    switch (Flags & (FLAGS_2BPP|FLAGS_3BPP|FLAGS_PALETTED))
    {
        case 0:
        case FLAGS_2BPP:
        case FLAGS_3BPP:
        case FLAGS_PALETTED:
            break;
        default:
            cout << "臼� -p, -2, and -3 are mutually exclusive options";
            return;
    }

//陳� Load palette
    Palette = new VngoPal8;
    if (!(Flags & FLAGS_QUIET))
    {
        cout << "Using palette " << Pal_name << "...\n";
    }
    err=load_pal(Palette,Pal_name);
    if (err)
    {
        cout << "臼� Error " << err << " loading palette " << Pal_name << "\n";
        goto error_exit;
    }

//陳� Load image
    Canvas = new PicCanvas;
    if (!(Flags & FLAGS_QUIET))
    {
        cout << "Loading image " << fn << "...\n";
    }
    if (strstr(fn,".tga"))
    {
        XFParseTGA  tga;

        err=tga.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "臼� Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".pcx"))
    {
        XFParsePCX  pcx;

        err=pcx.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "臼� Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".lbm"))
    {
        XFParseLBM  lbm;

        err=lbm.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "臼� Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".cel"))
    {
        XFParseCEL  cel;

        err=cel.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "臼� Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".bmp"))
    {
        XFParseBMP  bmp;

        err=bmp.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "臼� Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".xeb"))
    {
        XFParseXEB  xeb;

        err=xeb.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "臼� Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else
    {
        cout << "臼� Unknown input image extender\n";
        goto error_exit;
    }

//陳� Perform needed action
    if (Flags & FLAGS_INFO)
    {
        cout << "   Width: " << Canvas->width <<
                "\tHeight: " << Canvas->height <<
                "\tColor-depth: ";

        switch (Canvas->bpp)
        {
            case XFBM_BPP_MONO:
                cout << "Monochrome\n";
                break;
            case XFBM_BPP_8BIT:
                cout << "8-bit\n";
                break;
            case XFBM_BPP_15BIT:
                cout << "15-bit\n";
                break;
            case XFBM_BPP_24BIT:
                cout << "24-bit\n";
                break;
            case XFBM_BPP_32BIT:
                cout << "32-bit\n";
                break;
            default:
                cout << "Unknown\n";
                break;
        }
    }

    if (Flags & FLAGS_PALPRINT)
    {
        if (Canvas->bpp == XFBM_BPP_8BIT && Canvas->pal)
        {
            VngoColor24bit  clr;

            cout << "Original image palette:\n";
            for(i=0; i < 256; i++)
            {
                clr=(VngoColor24bit)Canvas->pal[i];
                cout.flush();
                printf("\t%3d    Red %3d  Green %3d  Blue %3d\n",
                       i,
                       clr.r,
                       clr.g,
                       clr.b);
                if ((i % 24)==23)
                {
                    cout << "<more>\r";
                    cout.flush();
                    getch();
                }
            }
        }
        else
        {
            cout << "臼� Image has no palette\n";
        }
    }

    if (Flags & FLAGS_PALETTED)
    {
        if (!(Flags & FLAGS_QUIET))
        {
            if ((Flags & FLAGS_TRANSP) && Canvas->bpp == XFBM_BPP_8BIT)
            {
                cout << "Converting image to use palette (preserving index 255)\n";
            }
            else
            {
                cout << "Converting image to use palette\n";
            }
        }

        if (Canvas->convert_to_paletted((VngoPal8*)Palette))
        {
            cout << "臼� Error occurred during convert to palette\n";
            return;
        }
    }
    else if (Flags & FLAGS_2BPP)
    {
        if (!(Flags & FLAGS_QUIET))
        {
            cout << "Converting image to 2 bytes/pixel\n";
        }

        if (Canvas->convert_to_2bpp())
        {
            cout << "臼� Error occurred during convert to 2bpp\n";
            return;
        }
    }
    else if (Flags & FLAGS_3BPP)
    {
        if (!(Flags & FLAGS_QUIET))
        {
            cout << "Converting image to 3 bytes/pixel\n";
        }

        if (Canvas->convert_to_3bpp())
        {
            cout << "臼� Error occurred during convert to 3bpp\n";
            return;
        }
    }

//陳� Compress to .zmp format.
    if (Flags & FLAGS_COMPRESS)
    {
        if (!(Flags & FLAGS_QUIET))
        {
            cout << "Converting transparent image to Zmap\n";
        }

        tptr = Canvas->compress_transparent();
        zmp.zmap.tex = tptr;
        if (tptr)
        {
            // Save the file here and then release memory.
            zmp.zmap.tex = tptr;
            zmp.zmap.width = Canvas->width;
            zmp.zmap.height = Canvas->height;
            zmp.color = 255;
            zmp.depth = 0;
            int    size;
            size = ((zmp.zmap.width + 7) >> 3) * zmp.zmap.height;
            if (!(Flags & FLAGS_QUIET))
            {
                cout << "\tSize of Zmap is " << size << " bytes.\n";
            }
        }
        else
        {
            cout << "臼� Error occured compressing image.\n";
            return;
        }
        if (!(Flags & FLAGS_OUTPUT))
        {
            char        path[XF_MAX_PATH];
            char        drive[XF_MAX_DRIVE];
            char        dir[XF_MAX_DIR];
            char        fname[XF_MAX_FNAME];
            char        ext[XF_MAX_EXT];

            strcpy (path,fn);

            xf_splitpath(path,drive,dir,fname,ext);
            strcpy(ext,".zmp");
            xf_makepath(path,drive,dir,fname,ext);
            if (!(Flags & FLAGS_QUIET))
            {
                cout << "Saving zmap as " << path << ".\n";
            }
            strncpy(zmp.name,fname,16);
            zmp.save(path);
        }
    }

//陳� Save result, if required
    if (Flags & FLAGS_OUTPUT)
    {
        if (!(Flags & FLAGS_QUIET))
        {
            cout << "Saving image " << outfn << "...\n";
        }
        if (strstr(outfn,".tga"))
        {
            XFParseTGA  tga;

            err=tga.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "臼� Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".pcx"))
        {
            XFParsePCX  pcx;

            err=pcx.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "臼� Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".lbm"))
        {
            XFParseLBM  lbm;

            err=lbm.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "臼� Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".cel"))
        {
            XFParseCEL  cel;

            err=cel.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "臼� Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".bmp"))
        {
            XFParseBMP  bmp;

            err=bmp.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "臼� Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".xeb"))
        {
            XFParseXEB  xeb;

            err=xeb.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "臼� Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".zmp") && (Flags & FLAGS_COMPRESS))
        {
            char        drive[XF_MAX_DRIVE];
            char        dir[XF_MAX_DIR];
            char        fname[XF_MAX_FNAME];
            char        ext[XF_MAX_EXT];

            xf_splitpath(outfn,drive,dir,fname,ext);
            strncpy(zmp.name,fname,16);

            zmp.save(outfn);
            if (tptr)
                delete [] tptr;
        }
        else
        {
            cout << "臼� Unknown image extender\n";
            goto error_exit;
        }
    }

//陳� Cleanup
error_exit: ;
    delete Canvas;
    delete Palette;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// print_help                                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void print_help(int full)
{
    cout << Util_name;
    cout << "   Usage: pic [-q | -i | -s | -x | -m | -t <fname.pal>]\n";
    cout << "              [-p | -2 | -3] <fname.xxx>\n";
    cout << "              [-o <fname.xxx>]\n";
    if (full)
    {
        cout << "\n          xxx can be BMP, CEL, LBM, PCX, TGA, or XEB\n\n";
        cout << "          -q = Quiet mode.\n";
        cout << "          -i = Show image information\n";
        cout << "          -s = Show image palette\n";
        cout << "          -x = Keep transparent (index 255) in 8-bit images\n";
        cout << "          -x = Convert color (255,0,255) to transparent\n";
        cout << "               (index 255) for 24-bit images\n";
        cout << "          -m = Convert transparent images to a monochrome Zmap\n";
        cout << "          -t <filename.pal/.vgp> = Palette file to use (default is DEFAULT.PAL)\n";
        cout << "          -p = Convert to use loaded palette\n";
        cout << "          -2 = Convert to 2 bytes/pixel\n";
        cout << "          -3 = Convert to 3 bytes/pixel\n";
        cout << "          -o = Output resulting image\n";
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// load_pal                                                                 �
//                                                                          �
//     Palette loader...                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC int load_pal(VngoPal *pal,char *infile)
{
    int err;

    err = pal->init(0,infile);

    return(err);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PicCanvas - convert_to_paletted                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
pic_err_codes PicCanvas::convert_to_paletted(VngoPal8 *p)
{
    int             i;
    byte            *sptr, *dptr, *nptr;
    IvoryHandle     nhandle;
    VngoColor24bit  clr;
    int             had_transparency=0;
    int             mypal[256];

    if (!palhandle)
    {
        palhandle = ivory_halloc(256 * sizeof(dword));
        if (!palhandle)
            return PIC_ERR_NOMEMORY;

        pal = (dword*) ivory_hlock(palhandle);
        if (!pal)
            return PIC_ERR_LOCKFAILED;
    }

    switch (bpp)
    {
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 8-bits per pixel
        case XFBM_BPP_8BIT:
            for(i=0; i < 256; i++)
            {
                clr=(VngoColor24bit)pal[i];
                mypal[i] = (byte)p->get_index(clr);

                clr = p->hw_pal.p[i];
                pal[i] = (clr.r | (clr.g << 8) | (clr.b << 16));
            }
            if (Flags & FLAGS_TRANSP)
            {
                for(i=0; i < width*height; i++)
                {
                    if (data[i] != 255)
                        data[i] = (byte)mypal[data[i]];
                }
            }
            else
            {
                for(i=0; i < width*height; i++)
                    data[i] = (byte)mypal[data[i]];
            }
            return PIC_ERR_NONE;

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� 15-bits per pixel
        case XFBM_BPP_15BIT:
            nhandle = ivory_halloc(width * height);
            if (!nhandle)
                return PIC_ERR_NOMEMORY;

            nptr = (byte*) ivory_hlock(nhandle);
            if (!nptr)
                return PIC_ERR_LOCKFAILED;

            for(i=0; i < 256; i++)
            {
                clr = p->hw_pal.p[i];
                pal[i] = (clr.r | (clr.g << 8) | (clr.b << 16));
            }

            for(i=0, sptr=data, dptr=nptr; i < width*height; i++)
            {
                word pcolor = *sptr | (*(sptr+1) << 8);

                sptr += 2;

                clr.r = (pcolor >> 7) & 0xf8;
                clr.g = (pcolor >> 2) & 0xf8;
                clr.b = (pcolor << 3) & 0xf8;

                if ((Flags & FLAGS_TRANSP) &&
                    (clr.r == 248) &&
                    (clr.b == 248) &&
                    (clr.g == 0))
                {
                    *(dptr++) = (byte)255;
                    had_transparency = 1;
                }
                else
                {
                    *(dptr++) = (byte)p->get_index(clr);
                }
            }

            if (had_transparency)
            {
                VngoColor24bit tclr(255,0,255);
                pal[255] = (tclr.r | (tclr.g << 8) | (tclr.b << 16));
            }

            ivory_hfree(&handle);

            handle = nhandle;
            data = nptr;
            bpp = 1;

            return PIC_ERR_NONE;

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� 24-bits per pixel
        case XFBM_BPP_24BIT:
            nhandle = ivory_halloc(width * height);
            if (!nhandle)
                return PIC_ERR_NOMEMORY;

            nptr = (byte*) ivory_hlock(nhandle);
            if (!nptr)
                return PIC_ERR_LOCKFAILED;

            for(i=0; i < 256; i++)
            {
                clr = p->hw_pal.p[i];
                pal[i] = (clr.r | (clr.g << 8) | (clr.b << 16));
            }

            for(i=0, sptr=data, dptr=nptr; i < width*height; i++)
            {
                clr.r = *(sptr++);
                clr.g = *(sptr++);
                clr.b = *(sptr++);

                if ((Flags & FLAGS_TRANSP) &&
                    (clr.r == 255) &&
                    (clr.b == 255) &&
                    (clr.g == 0))
                {
                    *(dptr++) = (byte)255;
                    had_transparency = 1;
                }
                else
                {
                    *(dptr++) = (byte)p->get_index(clr);
                }
            }

            if (had_transparency)
            {
                VngoColor24bit tclr(255,0,255);
                pal[255] = (tclr.r | (tclr.g << 8) | (tclr.b << 16));
            }

            ivory_hfree(&handle);

            handle = nhandle;
            data = nptr;
            bpp = 1;

            return PIC_ERR_NONE;


        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� 32-bits per pixel
        case XFBM_BPP_32BIT:
            nhandle = ivory_halloc(width * height);
            if (!nhandle)
                return PIC_ERR_NOMEMORY;

            nptr = (byte*) ivory_hlock(nhandle);
            if (!nptr)
                return PIC_ERR_LOCKFAILED;

            for(i=0; i < 256; i++)
            {
                clr = p->hw_pal.p[i];
                pal[i] = (clr.r | (clr.g << 8) | (clr.b << 16));
            }

            for(i=0, sptr=data, dptr=nptr; i < width*height; i++)
            {
                clr.r = *(sptr++);
                clr.g = *(sptr++);
                clr.b = *(sptr++);

                if (*(sptr++) < 255)
                {
                    *(dptr++) = (byte)255;
                    had_transparency = 1;
                }
                else
                {
                    *(dptr++) = (byte)p->get_index(clr);
                }
            }

            if (had_transparency)
            {
                VngoColor24bit tclr(255,0,255);
                pal[255] = (tclr.r | (tclr.g << 8) | (tclr.b << 16));
            }

            ivory_hfree(&handle);

            handle = nhandle;
            data = nptr;
            bpp = 1;

            return PIC_ERR_NONE;
    }

    return PIC_ERR_NOTSUPPORTED;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PicCanvas - convert_to_2bpp                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
pic_err_codes PicCanvas::convert_to_2bpp()
{
    int             i;
    byte            *sptr, *dptr, *nptr;
    IvoryHandle     nhandle;

    switch (bpp)
    {
        case XFBM_BPP_15BIT:
            return PIC_ERR_NONE;

        case XFBM_BPP_24BIT:
            nhandle = ivory_halloc(width * height * 2);
            if (!nhandle)
                return PIC_ERR_NOMEMORY;

            nptr = (byte*) ivory_hlock(nhandle);
            if (!nptr)
                return PIC_ERR_LOCKFAILED;

            for(i=0, sptr=data, dptr=nptr; i < width*height; i++)
            {
                word pcolor = (((*sptr) >> 3) << 10)
                                + (((*(sptr+1)) >> 3) << 5)
                                + ((*(sptr+2)) >> 3);

                *(dptr++) = byte(pcolor & 0xff);
                *(dptr++) = byte((pcolor & 0xff00) >> 8);

                sptr += 3;
            }

            ivory_hfree(&handle);

            handle = nhandle;
            data = nptr;
            bpp = XFBM_BPP_15BIT;
            return PIC_ERR_NONE;

        case XFBM_BPP_32BIT:
            nhandle = ivory_halloc(width * height * 2);
            if (!nhandle)
                return PIC_ERR_NOMEMORY;

            nptr = (byte*) ivory_hlock(nhandle);
            if (!nptr)
                return PIC_ERR_LOCKFAILED;

            for(i=0, sptr=data, dptr=nptr; i < width*height; i++)
            {
                word pcolor = (((*sptr) >> 3) << 10)
                                + (((*(sptr+1)) >> 3) << 5)
                                + ((*(sptr+2)) >> 3);

                *(dptr++) = byte(pcolor & 0xff);
                *(dptr++) = byte((pcolor & 0xff00) >> 8);

                sptr += 4;
            }

            ivory_hfree(&handle);

            handle = nhandle;
            data = nptr;
            bpp = XFBM_BPP_15BIT;
            return PIC_ERR_NONE;
    }

    return PIC_ERR_NOTSUPPORTED;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PicCanvas - convert_to_3bpp                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
pic_err_codes PicCanvas::convert_to_3bpp()
{
    int             i;
    byte            *sptr, *dptr, *nptr;
    IvoryHandle     nhandle;

    switch (bpp)
    {
        case XFBM_BPP_24BIT:
            return PIC_ERR_NONE;

        case XFBM_BPP_15BIT:
            nhandle = ivory_halloc(width * height * 3);
            if (!nhandle)
                return PIC_ERR_NOMEMORY;

            nptr = (byte*) ivory_hlock(nhandle);
            if (!nptr)
                return PIC_ERR_LOCKFAILED;

            for(i=0, sptr=data, dptr=nptr; i < width*height; i++)
            {
                word pcolor = *sptr | (*(sptr+1) << 8);

                sptr += 2;

                *(dptr++) = (pcolor >> 7) & 0xf8;
                *(dptr++) = (pcolor >> 2) & 0xf8;
                *(dptr++) = (pcolor << 3) & 0xf8;
            }

            ivory_hfree(&handle);

            handle = nhandle;
            data = nptr;
            bpp = XFBM_BPP_24BIT;
            return PIC_ERR_NONE;

        case XFBM_BPP_32BIT:
            nhandle = ivory_halloc(width * height * 3);
            if (!nhandle)
                return PIC_ERR_NOMEMORY;

            nptr = (byte*) ivory_hlock(nhandle);
            if (!nptr)
                return PIC_ERR_LOCKFAILED;

            for(i=0, sptr=data, dptr=nptr; i < width*height; i++)
            {
                *(dptr++) = *(sptr++);
                *(dptr++) = *(sptr++);
                *(dptr++) = *(sptr++);
                sptr++;
            }

            ivory_hfree(&handle);

            handle = nhandle;
            data = nptr;
            bpp = XFBM_BPP_24BIT;
            return PIC_ERR_NONE;
    }

    return PIC_ERR_NOTSUPPORTED;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PicCanvas - compress_transparent                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
byte *PicCanvas::compress_transparent()
{
    int             i,j,k,t;
    int             lwidth,rwidth;
    byte            *nptr;
    byte            *rptr=0;
    int             dbcount=0;
    int             offset = 0;

    if (bpp == XFBM_BPP_8BIT)
    {
        rptr = new byte [((width+7) >> 3) * height];
        nptr = rptr;

        lwidth = width & ~0x7;
        rwidth = width & 0x7;

        for (j = 0; j < height; j++)
        {
            if (width >= 8)
            {
                for (i = 0;i < lwidth; i+=8)
                {
                    t = 0;
                    for (k = 0;k < 8;k++)
                    {
                        if (data[ offset++ ] == 255)
                        {
                            t |= (0x80 >> k);
                        }
                    }
                    *nptr = (byte)t;
                    nptr++;
                }
            }
            if (rwidth)
            {
                t = 0;
                for (k = 0;k < rwidth; k++)
                {
                    if (data[ offset++ ] == 255)
                        t |= (0x80 >> k);
                }
                *nptr = (byte) t;
                nptr++;
            }
        }
    }
    return rptr;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// _charybdis_assert
//
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void _charybdis_assert(char *msg, char *exp, char *f, unsigned ln)
{
    cout.flush();
    printf("\n\n臼� Assertion Failed 臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼\n"
           "Expr:\t%s\n"
           "File:\t%s\t\tLine %d\n",exp,f,ln);
    if (msg)
    {
        printf("Comment:\n%s\n",msg);
    }

    exit(1);
}

//葦� End of module - pic.cpp 憶�
