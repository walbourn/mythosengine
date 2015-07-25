//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
//                            All Rights Reserved.
//                        Microsoft Windows '95 Version
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
//                          *** Tester Application ***
//
// Created by Chuck Walbourn
//
// xtbitmap.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <iostream.h>
#include <conio.h>

#include "xfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

void print_error(class XFParseBitmap *bp, char *s);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// bitmap                                                                   ³
//                                                                          ³
//     Entry point for the XFParseBitmap tests.                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void bitmap()
{
    XFParseBMP     bmp;
    XFParseCEL     cel;
    XFParseLBM     lbm;
    XFParsePCX     pcx;
    XFParseTGA     tga;
    XFParseXEB     xeb;

    cout << "\n\n\n°°°°°°±±±±±±²²²²²² XFParseBitmap object tests ²²²²²²±±±±±±°°°°°°\n";

//ÄÄÄÄ BMP

    //ÄÄÄÄ 2-color read
    cout << "Testing 2-color BMP reader...\n";
    if (bmp.nameread("TEST2.BMP"))
    {
        print_error(&bmp,"Error name-reading TEST2.BMP");
    }

    //ÄÄÄÄ 2-color write
    cout << "Testing 2-color BMP writer...\n";
    if (bmp.namewrite("OUT2.BMP"))
    {
        print_error(&bmp,"Error writing OUT2.BMP");
    }
    else
    {
        cout << "OUT2.BMP written...\n";
        if (bmp.nameread("OUT2.BMP"))
        {
            print_error(&bmp,"Error name-reading OUT2.BMP");
        }
    }

    //ÄÄÄÄ 16-color read
    cout << "Testing 16-color BMP reader...\n";
    if (bmp.nameread("TEST16.BMP"))
    {
        print_error(&bmp,"Error name-reading TEST16.BMP");
    }

    //ÄÄÄÄ 256-color read
    cout << "Testing 256-color BMP reader...\n";
    if (bmp.nameread("TEST256.BMP"))
    {
        print_error(&bmp,"Error name-reading TEST256.BMP");
    }

    //ÄÄÄÄ 256-color write
    cout << "Testing 256-color BMP writer...\n";
    if (bmp.namewrite("OUT256.BMP"))
    {
        print_error(&bmp,"Error writing OUT256.BMP");
    }
    else
    {
        cout << "OUT256.BMP written...\n";

        if (bmp.nameread("OUT256.BMP"))
        {
            print_error(&bmp,"Error name-reading OUT256.BMP");
        }
    }

    //ÄÄÄÄ Padded file
    cout << "Testing padded BMP reader/writer...\n";
    if (bmp.nameread("TEST.BMP"))
    {
        print_error(&bmp,"Error name-reading TEST.BMP");
    }

    //ÄÄÄÄ Compressed file
    cout << "Testing compressed BMP reader/writer...\n";
    if (bmp.nameread("BOUNCE.BMP"))
    {
        print_error(&bmp,"Error name-reading BOUNCE.BMP");
    }

    //ÄÄÄÄ 256-color write
    if (bmp.namewrite("OUT.BMP"))
    {
        print_error(&bmp,"Error writing OUT.BMP");
    }
    else
    {
        cout << "OUT.BMP written...\n";

        if (bmp.nameread("OUT.BMP"))
        {
            print_error(&bmp,"Error name-reading OUT.BMP");
        }
    }

//ÄÄÄÄ CEL

    //ÄÄÄÄ Read
    cout << "Testing CEL reader...\n";

    if (cel.nameread("APE.CEL"))
    {
        print_error(&cel,"Error name-reading APE.CEL");
    }

    //ÄÄÄÄ Write
    cout << "Testing CEL writer...\n";
    if (cel.namewrite("OUT.CEL"))
    {
        print_error(&cel,"Error writing OUT.CEL");
    }
    else
    {
        cout << "OUT.CEL written...\n";

        if (cel.nameread("OUT.CEL"))
        {
            print_error(&cel,"Error name-reading OUT.CEL");
        }
    }

    //ÄÄÄÄConvert
    cout << "Converting APE.CEL to APE.BMP...\n";
    if (cel.nameread("APE.CEL"))
    {
        print_error(&cel,"Error name-reading APE.CEL");
    }

    if (bmp.namewrite("APE.BMP",cel.bm))
    {
        print_error(&bmp,"Error writing APE.BMP");
    }
    else
    {
        cout << "APE.BMP written...\n";

        if (bmp.nameread("APE.BMP"))
        {
            print_error(&bmp,"Error name-reading APE.BMP");
        }
    }

//ÄÄÄÄ LBM

    //ÄÄÄÄ 2-color read
    cout << "Testing LBM 2-color reader...\n";
    if (lbm.nameread("BORDERS1.LBM"))
    {
        print_error(&lbm,"Error name-reading BORDERS1.LBM");
    }
    else
    {
        cout << "Converting BORDERS1.LBM to BORDERS1.BMP...\n";

        if (bmp.namewrite("BORDERS1.BMP",lbm.bm))
        {
            print_error(&bmp,"Error name-writing BORDERS1.BMP");
        }
        else
        {
            cout << "BORDERS1.BMP written...\n";
        }
    }

    //ÄÄÄÄ 2-color write
    cout << "Testing 2-color LBM writer...\n";
    if (lbm.namewrite("OUT2.LBM"))
    {
        print_error(&lbm,"Error writing OUT2.LBM");
    }
    else
    {
        cout << "OUT2.LBM written...\n";
    
        if (lbm.nameread("OUT2.LBM"))
        {
            print_error(&lbm,"Error name-reading OUT2.LBM");
        }
    }

    //ÄÄÄÄ 256-color read
    cout << "Testing LBM 256-color reader...\n";

    if (lbm.nameread("TEST.LBM"))
    {
        print_error(&lbm,"Error name-reading TEST.LBM");
    }

    //ÄÄÄÄ 256-color write
    cout << "Testing 256-color LBM writer...\n";
    if (lbm.namewrite("OUT256.LBM"))
    {
        print_error(&lbm,"Error writing OUT256.LBM");
    }
    else
    {
        cout << "OUT256.LBM written...\n";

        if (lbm.nameread("OUT256.LBM"))
        {
            print_error(&lbm,"Error name-reading OUT256.LBM");
        }
    }

    //ÄÄÄÄ Convert 2-color
    cout << "Converting TEST2.BMP to TEST2.LBM...\n";
    if (bmp.nameread("TEST2.BMP"))
    {
        print_error(&bmp,"Error name-reading TEST2.BMP");
    }

    if (lbm.namewrite("TEST2.LBM",bmp.bm))
    {
        print_error(&lbm,"Error writing TEST2.LBM");
    }
    else
    {
        cout << "TEST2.LBM written...\n";
 
        if (lbm.nameread("TEST2.LBM"))
        {
            print_error(&lbm,"Error name-reading TEST2.LBM");
        }
    }

    //ÄÄÄÄ Convert 256-color
    cout << "Converting APE.CEL to APE.LBM...\n";
    if (cel.nameread("APE.CEL"))
    {
        print_error(&cel,"Error name-reading APE.CEL");
    }
    else
    {
        if (lbm.namewrite("APE.LBM",cel.bm))
        {
            print_error(&lbm,"Error writing APE.LBM");
        }
        else
        {
            cout << "APE.LBM written...\n";

            if (lbm.nameread("APE.LBM"))
            {
                print_error(&lbm,"Error name-reading APE.LBM");
            }
        }
    }

//ÄÄÄÄ PCX

    //ÄÄÄÄ Read
    cout << "Testing PCX reader...\n";

    if (pcx.nameread("TEST.PCX"))
    {
        print_error(&pcx,"Error name-reading TEST.PCX");
    }

    //ÄÄÄÄ Convert
    cout << "Converting APE.CEL to APE.PCX...\n";
    if (cel.nameread("APE.CEL"))
    {
        print_error(&cel,"Error name-reading APE.CEL");
    }
    else
    {
        if (pcx.namewrite("APE.PCX",cel.bm))
        {
            print_error(&pcx,"Error writing APE.PCX");
        }
        else
        {
            cout << "APE.PCX written...\n";

            if (pcx.nameread("APE.PCX"))
            {
                print_error(&pcx,"Error name-reading APE.PCX");
            }
        }
    }

//ÄÄÄÄ TGA

    //ÄÄÄÄ Read 24-bit
    cout << "Testing 24-bit TGA reader...\n";

    if (tga.nameread("EARTH.TGA"))
    {
        print_error(&tga,"Error name-reading EARTH.TGA");
    }
    else
    {
        //ÄÄÄÄ Write
        cout << "Testing 24-bit TGA writer...\n";
        if (tga.namewrite("OUT.TGA"))
        {
            print_error(&tga,"Error writing OUT.TGA");
        }
        else
        {
            cout << "OUT.TGA written...\n";

            if (tga.nameread("OUT.TGA"))
            {
                print_error(&tga,"Error name-reading OUT.TGA");
            }
        }
    }

    //ÄÄÄÄ Read
    cout << "Testing 32-bit TGA reader...\n";

    if (tga.nameread("BOUNCE.TGA"))
    {
        print_error(&tga,"Error name-reading BOUNCE.TGA");
    }
    else
    {
        //ÄÄÄÄ Write
        cout << "Testing 32-bit TGA writer...\n";
        if (tga.namewrite("OUTBOUN.TGA"))
        {
            print_error(&tga,"Error writing OUTBOUN.TGA");
        }
        else
        {
            cout << "OUTBOUN.TGA written...\n";

            if (tga.nameread("OUTBOUN.TGA"))
            {
                print_error(&tga,"Error name-reading OUTBOUN.TGA");
            }
        }
    }

//ÄÄÄÄ XEB

    //ÄÄÄÄ Convert 2-bit
    cout << "Converting BORDERS1.LBM to BORDERS1.XEB...\n";
    if (lbm.nameread("BORDERS1.LBM"))
    {
        print_error(&lbm,"Error name-reading BORDERS1.LBM");
    }
    else
    {
        if (xeb.namewrite("BORDERS1.XEB",lbm.bm))
        {
            print_error(&xeb,"Error writing BORDERS1.XEB");
        }
        else
        {
            cout << "BORDERS1.XEB written...\n";
        }
    }

    cout << "Converting BORDERS1.XEB to BORD1XEB.BMP...\n";
    if (xeb.nameread("BORDERS1.XEB"))
    {
        print_error(&xeb,"Error name-reading BORDERS1.XEB");
    }
    else
    {
        if (bmp.namewrite("BORD1XEB.BMP",xeb.bm))
        {
            print_error(&bmp,"Error writing BORD1XEB.BMP");
        }
        else
        {
            cout << "BORD1XEB.BMP written...\n";
        }
    }

    //ÄÄÄÄ Convert 8-bit
    cout << "Converting APE.CEL to APE.XEB...\n";
    if (cel.nameread("APE.CEL"))
    {
        print_error(&cel,"Error name-reading APE.CEL");
    }
    else
    {
        if (xeb.namewrite("APE.XEB",cel.bm))
        {
            print_error(&xeb,"Error writing APE.XEB");
        }
        else
        {
            cout << "APE.XEB written...\n";
        }
    }

    cout << "Converting APE.XEB to APEXEB.PCX...\n";
    if (xeb.nameread("APE.XEB"))
    {
        print_error(&xeb,"Error name-reading APE.XEB");
    }
    else
    {
        if (pcx.namewrite("APEXEB.PCX",xeb.bm))
        {
            print_error(&pcx,"Error writing APEXEB.PCX");
        }
        else
        {
            cout << "APEXEB.PCX written...\n";
        }
    }

    //ÄÄÄÄ Convert 8-bit
    cout << "Converting BOUNCE.BMP to APE.XEB...\n";
    if (bmp.nameread("BOUNCE.BMP"))
    {
        print_error(&bmp,"Error name-reading BOUNCE.BMP");
    }
    else
    {
        if (xeb.namewrite("BOUNCE.XEB",bmp.bm))
        {
            print_error(&xeb,"Error writing BOUNCE.XEB");
        }
        else
        {
            cout << "BOUNCE.XEB written...\n";
        }
    }

    cout << "Converting BOUNCE.XEB to BOUNXEB.BMP...\n";
    if (xeb.nameread("BOUNCE.XEB"))
    {
        print_error(&xeb,"Error name-reading BOUNCE.XEB");
    }
    else
    {
        if (bmp.namewrite("BOUNXEB.BMP",xeb.bm))
        {
            print_error(&bmp,"Error writing BOUNXEB.BMP");
        }
        else
        {
            cout << "BOUNXEB.BMP written...\n";
        }
    }

    //ÄÄÄÄ Convert 24-bit
    cout << "Converting EARTH.TGA to EARTH.XEB...\n";
    if (tga.nameread("EARTH.TGA"))
    {
        print_error(&tga,"Error name-reading EARTH.TGA");
    }
    else
    {
        if (xeb.namewrite("EARTH.XEB",tga.bm))
        {
            print_error(&xeb,"Error writing EARTH.XEB");
        }
        else
        {
            cout << "EARTH.XEB written...\n";
        }
    }

    cout << "Converting EARTH.XEB to EARTXEB.TGA...\n";
    if (xeb.nameread("EARTH.XEB"))
    {
        print_error(&xeb,"Error name-reading EARTH.XEB");
    }
    else
    {
        if (tga.namewrite("EARTXEB.TGA",xeb.bm))
        {
            print_error(&tga,"Error writing EARTXEB.TGA");
        }
        else
        {
            cout << "EARTXEB.TGA written...\n";
        }
    }
}

//°±² End of module - xtbitmap.cpp ²±°

