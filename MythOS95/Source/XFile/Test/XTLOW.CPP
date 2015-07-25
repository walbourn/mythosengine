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
// xtlow.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <iostream.h>

#include <io.h>
#include <fcntl.h>

#include "xfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

void print_error(char *s);
void print_error(class XFile *xf, char *s);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// low_level                                                                ³
//                                                                          ³
//     Entry point for the low-level file tests for XFile.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void low_level()
{
   HANDLE   fhandle;

//ÄÄÄÄ Perform file tests ÄÄÄÄ
   cout << "\n\n\n°°°°°°±±±±±±²²²²²² Low-level/Base object tests ²²²²²²±±±±±±°°°°°°\n";

   cout << "°°° Using low-level functions °°°\n";
   fhandle=xf_open("TESTFILE.DAT",XF_OPEN_CREATE|XF_OPEN_WRITE);

   if (fhandle == INVALID_HANDLE_VALUE)
   {
       print_error("Failed to open file");
   }
   else
   {
       ulong   result;
       char    data[128];

       cout << "File created.\n";

       result = xf_write(fhandle,"Test String\n",sizeof("Test String\n") );

       if (result != sizeof("Test String\n")) 
           print_error("Failed to write string");
       else
           cout << "Written.\n";

       cout << "Current file position: " << xf_seek (fhandle,1,0) << "\n";

       xf_flush (fhandle);
       xf_close (fhandle);

       fhandle = xf_open("TESTFILE.DAT",XF_OPEN_READ);
       if (fhandle == INVALID_HANDLE_VALUE)
       {
           print_error("Failed to open file");
       }
       else
       {
           ulong    i;

           cout << "File size " << xf_getsize(fhandle) << "\n";

           result = xf_read (fhandle, data, 128);

           if (!result)
               print_error ("Error reading");
           else
           {
               for (i = 0; i < result; i++)
                   cout << data[i];
           }

           xf_close(fhandle);
       }
   }

   cout << "°°° Temporary file" << endl;

   char fname[16] = "xxx";

   fhandle=xf_opentmp(fname,XF_OPEN_CREATE|XF_OPEN_WRITE);

   if (fhandle == INVALID_HANDLE_VALUE)
   {
       print_error("Failed to open temporary file");
   }
   else
   {
       ulong   result;
       char    data[128];

       cout << "File created as " << fname << ".\n";

       result=xf_write(fhandle,"Test String\n",sizeof("Test String\n") );

       if (result != sizeof("Test String\n")) 
           print_error("Failed to write string");
       else
           cout << "Written.\n";

       cout << "Current file position: " << xf_seek(fhandle,1,0) << "\n";

       xf_flush(fhandle);
       xf_close(fhandle);

       fhandle=xf_open(fname,XF_OPEN_READ);
       if (fhandle == INVALID_HANDLE_VALUE)
       {
           print_error("Failed to open file");
       }
       else
       {
           ulong    i;

           cout << "File size " << xf_getsize(fhandle) << "\n";

           result=xf_read(fhandle,data,128);

           if (!result)
               print_error("Error reading");
           else
           {
               for (i = 0; i < result; i++)
                   cout << data[i];
           }

           xf_close(fhandle);
       }

       xf_remove(fname);
   }

   cout << "\n°°° Using XFileDOS object °°°\n";
   XFileDOS   xf;

   if (xf.create("TESTFIL2.DAT",0))
   {
       print_error(&xf,"Failed to create file");
   }
   else
   {
       ulong   result;
       char    data[128];

       cout << "File created.\n";

       result=xf.write("Test string\n",sizeof("Test string\n"));

       if (result != sizeof("Test string\n"))
           print_error(&xf,"Failed to write string");
       else
           cout << "Written.\n";

       cout << "Current file position: " << xf.tell() << "\n";

       xf.flush();
       xf.close();

       if (xf.open("TESTFIL2.DAT",XF_OPEN_READ))
       {
           print_error(&xf,"Failed to open file");
       }
       else
       {
           ulong    i;

           result=xf.read(data,128);

           if (!result)
               print_error(&xf,"Failed to read");
           else
           {
               for (i = 0; i < result; i++)
                   cout << data[i];
           }

           xf.close();
       }
   }

   cout << "\n°°° Testing miscellanous low-level routines °°°\n";

   if (xf_exist("TESTFILE.DAT"))
   {
       int attrs;

       cout << "Testfile.dat exists, this is correct.  Attributes =";
       
       attrs=xf_getattr("TESTFILE.DAT");

       if (attrs & XF_ATTRIB_READONLY)
           cout << " Ronly";
       if (attrs & XF_ATTRIB_HIDDEN)
           cout << " Hidden";
       if (attrs & XF_ATTRIB_SYSTEM)
           cout << " System";
       if (attrs & XF_ATTRIB_LABEL)
           cout << " Label";
       if (attrs & XF_ATTRIB_DIRECTORY)
           cout << " Directory";
       if (attrs & XF_ATTRIB_ARCHIVE)
           cout << " Archive";
       if (attrs & XF_ATTRIB_SHAREABLE)
           cout << " Shareable";

       cout << "\n";
   }
   else
       print_error("Testfile.dat should exist at this point");

   if (xf_remove("TESTFILE.DAT"))
       print_error("Error removing file");
   else
       cout << "File removed\n";

   if (!xf_exist("TESTFILE.DAT"))
       cout << "Testfile.dat doesnt exist, this is correct\n";
   else
       print_error("Testfile.dat should NOT exist at this point");

   if (xf_rename("TESTFIL2.DAT","TESTFILE.DAT"))
   {
       print_error("Renaming didn't work");
       xf_remove("TESTFIL2.DAT");
   }
   else
   {
       cout << "Renamed file work...\n";

       xf_remove("TESTFILE.DAT");
   }

   char *c;
   cout << "\nDumping PATH\n";

   c=xf_getenv("PATH");
   if (!c)
       cout << "Path not set\n";
   else
       cout << "Path = " << c;
   cout << "\n";

   cout << "\nTest searching\n";
   char buff[128];
   if (*xf_searchenv("WPP386.EXE","PATH",buff))
   {
       cout << "Filename: " << buff << "\n";
   }

   cout << "Test path ops\n";
   cout << xf_makepath(buff,"C:","TEMP","RESULT","DAT") << "\n";

   cout << "Test find file\n";
   struct xf_find_type find;

   if (!xf_findfirst ("*.bat",0,&find))
   {
       cout << find.xf_name << "  " << find.xf_size << " bytes\n";

       while (xf_findnext (&find) == 0)
       {
            cout << find.xf_name << "  " << find.xf_size << " bytes\n";
       }

       xf_findclose(&find);
   }
   else
       cout << "No Files Found\n";
}

//°±² End of module - xtlow.cpp ²±°

