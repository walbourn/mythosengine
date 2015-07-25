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
// xtini.cpp
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

void print_error(char *s);
void print_error(class XFile *xf, char *s);
void print_error(class XFParseINI *xp, char *s);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

STATIC void ini_read(XFParseINI *ini, char *s)
{
   char        buff[128];
   char        value[XF_MAX_INIVALUE];

   if (ini->read(s,value)) {
       sprintf(buff,"Reading '%s'",s);
       print_error(ini,buff);
   }
   else
       cout << s << "ð" << value << "\n";
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ini                                                                      ³
//                                                                          ³
//     Entry point for the XFParseINI tests.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ini()
{
//ÄÄÄÄ Perform .INI tests ÄÄÄÄ
   cout << "\n\n\n°°°°°°±±±±±±²²²²²² XFParseINI object tests ²²²²²²±±±±±±°°°°°°\n";

   cout <<"\n°±² Testing .INI read operations ²±°\n";

   XFParseINI    ini;
   if (ini.open(".\\TEST.INI",XF_OPEN_READ))
       print_error(&ini,"Cannot open TEST.INI");
   else {
       int i;
       const char *items[] = { "String1", "String2", "String3", 0 };
       char buff1[128];
       char buff2[128];
       char buff3[128];
       char *values[] = {buff1, buff2, buff3};
       
       if (ini.section("Hardware"))
           print_error(&ini,"Setting section [Hardware]");
       else
           cout << "Current section is [Hardware]\n";

       ini_read(&ini,"VideoMode");
       cout << "Half of the video mode number is " << ini.read("VideoMode")/2 << "\n";

       ini_read(&ini,"String1");

       cout << "\n";

       if (ini.section("English"))
           print_error(&ini,"Setting section [English]");
       else
           cout << "Current section is [English]\n";

       if (ini.read(items,values)) {
           print_error(&ini,"Error reading block of strings");
       }
       else {
           for(i=0; i < 3; i++)
               cout << "String" << i+1 << " " << values[i] << "\n";
       }
                                    
       if (ini.section("German"))
           print_error(&ini,"Setting section [German]");
       else
           cout << "Current section is [German]\n";

       if (ini.read(items,values)) {
           print_error(&ini,"Error reading block of strings");
       }
       else {
           for(i=0; i < 3; i++)
               cout << "String" << i+1 << " " << values[i] << "\n";
       }

       if (ini.close())
           print_error(&ini,"Cannot close TEST.INI");
   }

   cout <<"\n°±² Testing .INI write operations ²±°\n";

   xf_remove(".\\TEST2.INI");

   if (ini.create (".\\TEST2.INI",XF_OPEN_WRITE))
       print_error (&ini,"Cannot create TEST2.INI");
   else
   {
        const char *items[] = { "String1", "String2", "String3", 0 };
        const char *values[] = { "Data for 1", "Data for 2", "Data for 3" };

        if (ini.section ("Info"))
            print_error (&ini,"Setting section [Info]");
        else
            cout << "Current section is [Info]\n";

        ini.write ("Widget","ONE");
        ini.write ("Foo","BAR");
        ini.write ("Widget","TWO");

        ini.write (items,values);

        if (ini.section ("Another"))
            print_error (&ini,"Setting section [Another]");
        else
            cout << "Current section is [Another]\n";

        ini.write (items,values);

        if (ini.section("Info"))
            print_error(&ini,"Setting section [Info]");
        else
            cout << "Current section is [Info]\n";

        ini_read (&ini, "Foo");

        if (ini.close())
            print_error (&ini,"Cannot close TEST2.INI");
    }
}

//°±² End of module - xtini.cpp ²±°

