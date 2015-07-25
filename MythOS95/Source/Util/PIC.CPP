//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
//                      Microsoft Windows '95 Version
//
//            Copyright (c) 1994,1995 by Charybdis Enterprises, Inc.
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
// pic.cpp
//
//     Picture/bitmap recolor utility.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string.h>

#include <ivory.hpp>
#include <xfile.hpp>
#include <vangogh.hpp>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define FLAGS_QUIET     0x1     // Keep silent
#define FLAGS_PALETTED  0x4     // Make file paletted
#define FLAGS_INFO      0x8     // Display image information
#define FLAGS_OUTPUT    0x10    // Output image after any ops
#define FLAGS_PALPRINT  0x20    // Display image palette
#define FLAGS_TRANSP    0x40    // Transparent (don't lookup color 255).
#define FLAGS_COMPRESS  0x80    // Compress transparent images to monochrome.

//--- Error values ---
typedef enum _pic_err_codes {
    PIC_ERR_NONE                       =0,

    PIC_ERR_NOTSUPPORTED               =1,
    PIC_ERR_NOMEMORY                   =2,
    PIC_ERR_LOCKFAILED                 =3,
} pic_err_codes;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class PicCanvas : public XFBitmap
{

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    PicCanvas() {}
    ~PicCanvas() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations on Canvas objects.                                        ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    pic_err_codes convert_to_paletted(VngoPal8 *pal);
    byte *compress_transparent();
};

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

STATIC void print_help(int full);
STATIC int load_pal(VngoPal *pal,char *infile);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

IvorySystem     Ivory;

dword           Flags=0;

char            Pal_name[128];
VngoPal         *Palette=0;
PicCanvas       *Canvas=0;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// main                                                                     ³
//                                                                          ³
// Entry point for the Pic utility.                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void main(int argc, char *argv[])
{
    int         err;
    int         i;
    char        *fn;
    char        *outfn;

    VngoZMap   zmp;
    byte *tptr=0;

//ÄÄÄ Setup default palette file
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

//ÄÄÄ Handle no filename...
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

                case 'Q':
                case 'q':
                    Flags |= FLAGS_QUIET;
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Display image information

                case 'I':
                case 'i':
                    Flags |= FLAGS_INFO;
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Display image palette

                case 'S':
                case 's':
                    Flags |= FLAGS_PALPRINT;
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Paletted file

                case 'P':
                case 'p':
                    Flags |= FLAGS_PALETTED;
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Palette file

                case 'T':
                case 't':
                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/' ||
                        (!strstr(strlwr(argv[i]),".pal")
                         && !strstr(strlwr(argv[i]),".vgp")))
                    {
                        cout << "°° Expected a palette file name\n";
                        return;
                    }
                    strcpy(Pal_name,argv[i]);
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

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Transparent

                case 'X':
                case 'x':
                    Flags |= FLAGS_TRANSP;
                    break;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Compress to Mono

                case 'M':
                case 'm':
                    Flags |= FLAGS_COMPRESS;
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
        cout << "°° Expected an input image file name\n";
        return;
    }

//ÄÄÄ Banner
    if (!(Flags & FLAGS_QUIET))
    {
        cout << "°± MythOS Pic Image Utility - (C) 1994, 1995 Charybdis Enterprises, Inc. ±°\n";
    }

//ÄÄÄ Check to see if supplied files exist
    if (!xf_exist(fn))
    {
        cout << "±±± Input file " << fn << " not found\n";
        return;
    }

    if (!xf_exist(Pal_name))
    {
        cout << "±±± Palette file " << Pal_name << " not found\n";
    }

//ÄÄÄ Check for valid options
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
            cout << "±±± Unrecognized output image type...\n";
            return;
        }

        if (!strcmp(fn,outfn))
        {
            cout << "±±± Will overwrite original, ok? (Y/n)";
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

//ÄÄÄ Load palette
    Palette = new VngoPal8;
    if (!(Flags & FLAGS_QUIET))
    {
        cout << "Using palette " << Pal_name << "...\n";
    }
    err=load_pal(Palette,Pal_name);
    if (err)
    {
        cout << "±±± Error " << err << " loading palette " << Pal_name << "\n";
        goto error_exit;
    }

//ÄÄÄ Load image
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
            cout << "±±± Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".pcx"))
    {
        XFParsePCX  pcx;

        err=pcx.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "±±± Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".lbm"))
    {
        XFParseLBM  lbm;

        err=lbm.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "±±± Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".cel"))
    {
        XFParseCEL  cel;

        err=cel.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "±±± Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".bmp"))
    {
        XFParseBMP  bmp;

        err=bmp.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "±±± Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else if (strstr(fn,".xeb"))
    {
        XFParseXEB  xeb;

        err=xeb.nameread(fn,(XFBitmap*)Canvas);
        if (err)
        {
            cout << "±±± Error " << err << " loading image " << fn << "\n";
            goto error_exit;
        }
    }
    else
    {
        cout << "±±± Unknown input image extender\n";
        goto error_exit;
    }

//ÄÄÄ Perform needed action
    if (Flags & FLAGS_INFO)
    {
        cout << "   Width: " << Canvas->width <<
                "\tHeight: " << Canvas->height <<
                "\tColor-depth: ";

        if (Canvas->bpp == 1)
            cout << "8-bit\n";
        else
            cout << "24-bit\n";
    }

    if (Flags & FLAGS_PALPRINT)
    {
        if (Canvas->bpp == 1 && Canvas->pal)
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
                    getch();
                }
            }
        }
        else
        {
            cout << "±±± Image has no palette\n";
        }
    }

    if (Flags & FLAGS_PALETTED)
    {
        if (!(Flags & FLAGS_QUIET))
        {
            if ((Flags & FLAGS_TRANSP) && Canvas->bpp == 1)
            {
                cout << "Converting image to use palette (preserving index 255)\n";
            }
            else
            {
                cout << "Converting image to use palette\n";
            }
        }

        Canvas->convert_to_paletted((VngoPal8*)Palette);
    }

//ÄÄÄ Compress to .zmp format.
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
            cout << "Error occured compressing image.\n";
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

//ÄÄÄ Save result, if required
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
                cout << "±±± Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".pcx"))
        {
            XFParsePCX  pcx;

            err=pcx.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "±±± Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".lbm"))
        {
            XFParseLBM  lbm;

            err=lbm.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "±±± Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".cel"))
        {
            XFParseCEL  cel;

            err=cel.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "±±± Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".bmp"))
        {
            XFParseBMP  bmp;

            err=bmp.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "±±± Error " << err << " writing image " << outfn << "\n";
                goto error_exit;
            }
        }
        else if (strstr(outfn,".xeb"))
        {
            XFParseXEB  xeb;

            err=xeb.namewrite(outfn,(XFBitmap*)Canvas);
            if (err)
            {
                cout << "±±± Error " << err << " writing image " << outfn << "\n";
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
            cout << "±±± Unknown image extender\n";
            goto error_exit;
        }
    }

//ÄÄÄ Cleanup
error_exit: ;
    delete Canvas;
    delete Palette;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// print_help                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void print_help(int full)
{
   cout << "°± MythOS Pic Image Utility - (C) 1994, 1995 Charybdis Enterprises, Inc. ±°\n";
   cout << "                              " __DATE__ "   All Rights Reserved.\n";
   cout << "   Usage: pic [-q |  -i  | -s | -p | -x | -m | -t <fname.pal>] <fname.xxx>\n";
   cout << "              [-o <fname.xxx>]\n";
   if (full)
   {
       cout << "\n          xxx can be BMP, CEL, LBM, PCX, TGA, or XEB\n\n";
       cout << "          -q = Quiet mode.\n";
       cout << "          -i = Show image information\n";
       cout << "          -s = Show image palette\n";
       cout << "          -p = Convert to use loaded palette\n";
       cout << "          -x = Keep transparent (index 255) in 8-bit images\n";
       cout << "          -x = Convert color (255,0,255) to transparent (index 255) for 24-bit images\n";
       cout << "          -m = Convert transparent images to a monochrome Zmap\n";
       cout << "          -t <filename.pal/.vgp> = Palette file to use (default is DEFAULT.PAL)\n";
       cout << "          -o = Output resulting image\n";
   }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// load_pal                                                                 ³
//                                                                          ³
//     Palette loader...                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int load_pal(VngoPal *pal,char *infile)
{
    int err;

    err = pal->init(0,infile);

    return(err);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// PicCanvas - convert_to_paletted                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
pic_err_codes PicCanvas::convert_to_paletted(VngoPal8 *p)
{
    int             i;
    byte            *sptr, *dptr, *nptr;
    IvoryHandle     nhandle;
    VngoColor24bit  clr;
    int             mypal[256];

    if (bpp == 1)
    {
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
    }
    else if (bpp == 3)
    {
        if (!palhandle)
        {
            palhandle = ivory_halloc(256 * sizeof(dword));
            if (!palhandle)
                return PIC_ERR_NOMEMORY;

            pal = (dword*) ivory_hlock(palhandle);
            if (!pal)
                return PIC_ERR_LOCKFAILED;
        }

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

        int had_transparency=0;
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
    }

    return PIC_ERR_NOTSUPPORTED;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// PicCanvas - compress_transparent;                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
byte *PicCanvas::compress_transparent()
{
    int             i,j,k,t;
    int             lwidth,rwidth;
    byte            *nptr;
    byte            *rptr=0;
    int             dbcount=0;
    int             offset = 0;

    if (bpp == 1)
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

//°±² End of module - pic.cpp ²±°
