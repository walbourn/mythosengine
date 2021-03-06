//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//                    Microsoft Windows 95/98/NT Version
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
//                          *** Tester Application ***
//
// Created by Chuck Walbourn
//
// xtini.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdio.h>
#include <iostream>

#include "xfile.hpp"

using namespace std; 

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

void print_error(char *s);
void print_error(class XFile *xf, char *s);
void print_error(class XFParseINI *xp, char *s);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

STATIC void ini_read(XFParseINI *ini, char *s)
{
   char        buff[128];
   char        value[XF_MAX_INIVALUE];

   if (ini->read(s,value)) {
       sprintf(buff,"Reading '%s'",s);
       print_error(ini,buff);
   }
   else
       cout << s << "�" << value << "\n";
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ini                                                                      �
//                                                                          �
//     Entry point for the XFParseINI tests.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void ini()
{
//陳陳 Perform .INI tests 陳陳
   cout << "\n\n\n旭旭旭臼臼臼臆臆臆 XFParseINI object tests 臆臆臆臼臼臼旭旭旭\n";

   cout <<"\n葦� Testing .INI read operations 憶�\n";

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

   cout <<"\n葦� Testing .INI write operations 憶�\n";

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

//葦� End of module - xtini.cpp 憶�

