//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994,1995 by Charybdis Enterprises, Inc.
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
// xtiff.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <stdio.h>
#include <iostream.h>

#include "xfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

void print_error(XFParseIFF *xf, char *s);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// iff                                                                      ³
//                                                                          ³
//     Entry point for the XFileIFF tests.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void iff()
{
//ÄÄÄÄ Perform .IFF tests ÄÄÄÄ
   cout << "\n\n\n°°°°°°±±±±±±²²²²²² XFileIFF object tests ²²²²²²±±±±±±°°°°°°\n";

   cout <<"\n°±² Testing .IFF read operations ²±°\n";

   XFParseIFF  iff;

   cout << "\n°°° Simple one-level object °°°\n";

   if (iff.open("TEST.IFF",XF_OPEN_READ))
       print_error(&iff,"Cannot open TEST.IFF");
   else {
       char buff[5] = { 0, 0, 0, 0, 0 };

       while (iff.next() == XF_ERR_NONE) {
           cout << "Chunk " << iff.strid(iff.chunkid,buff) << "  size=" << iff.chunkSize << "\n";
       }
       print_error(&iff,"Done with next loop");

       if (iff.close())
           print_error(&iff,"Cannot close TEST.IFF");
   }

   cout << "\n°°° Two-level object °°°\n";

   if (iff.open("TEST.LBM",XF_OPEN_READ))
       print_error(&iff,"Cannot open TEST.LBM");
   else {
       char buff[5] = { 0, 0, 0, 0, 0 };

       while (iff.next() == XF_ERR_NONE) {

           if (iff.makeid('F','O','R','M') == iff.chunkid) {
                cout << "Form " << iff.strid(iff.formid,buff);
                if (iff.enterform() != XF_ERR_NONE)
                   print_error(&iff,"Problem entering FORM");
           }
           else {
                cout << "Chunk " << iff.strid(iff.chunkid,buff);
           }
           cout << "  size=" << iff.chunkSize << "\n";
       }
       print_error(&iff,"Done with next loop");

       if (iff.close())
           print_error(&iff,"Cannot close TEST.LBM");
   }

   cout <<"\n°±² Testing .IFF write operations ²±°\n";

   ulong       size;
   XFParseIFF  iff2;

   cout << "\n°°° Simple one-level object °°°\n";

   remove("TEST2.IFF");

   if (iff.open("TEST.IFF",XF_OPEN_READ))
       print_error(&iff,"Cannot open TEST.IFF");
   else if (iff2.create("TEST2.IFF",0))
       print_error(&iff,"Cannot create TEST2.IFF");
   else {
       char buff[5] = { 0, 0, 0, 0, 0 };
       char *work;

       work = new char[65536];

       while (iff.next() == XF_ERR_NONE) {
           cout << "Chunk " << iff.strid(iff.chunkid,buff) << "  size=" << iff.chunkSize << "\n";
           size=iff.chunkSize;
           iff.read(work);
           iff2.write(iff.chunkid,work,size);
       }

       delete [] work;

       if (iff.close())
           print_error(&iff,"Cannot close TEST.IFF");
       if (iff2.close())
           print_error(&iff2,"Cannot close TEST2.IFF");
   }

   cout << "\n°°° Two-level object °°°\n";

   remove("TEST2.LBM");

   if (iff.open("TEST.LBM",XF_OPEN_READ))
       print_error(&iff,"Cannot open TEST.LBM");
   else if (iff2.create("TEST2.LBM",0))
       print_error(&iff,"Cannot create TEST2.LBM");
   else {
       char buff[5] = { 0, 0, 0, 0, 0 };
       char *work;

       work = new char[65536];

       while (iff.next() == XF_ERR_NONE) {

           if (iff.makeid('F','O','R','M') == iff.chunkid) {
                cout << "Form " << iff.strid(iff.formid,buff);
                if (iff.enterform() != XF_ERR_NONE)
                   print_error(&iff,"Problem entering FORM");
                if (iff2.newform(iff.formid))
                   print_error(&iff,"Cannot create FORM");
           }
           else {
                cout << "Chunk " << iff.strid(iff.chunkid,buff);
                size=iff.chunkSize;
                iff.read(work);
                iff2.write(iff.chunkid,work,size);
           }
           cout << "  size=" << iff.chunkSize << "\n";
       }

       delete [] work;

       if (iff.close())
           print_error(&iff,"Cannot close TEST.LBM");
       if (iff2.close())
           print_error(&iff2,"Cannot close TEST2.LBM");
   }

}

//°±² End of module - xtiff.cpp ²±°

