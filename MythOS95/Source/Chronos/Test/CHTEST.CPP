//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//        °°°°°°°°°°°°°°°°°°°°°°
//         °°                °°
//          °°              °°
//           °°        ÚÄÄÄÄÄ  ³   ³ ÚÄÄÄ¿ ÚÄÄÄ¿ ³   ³ ÚÄÄÄ¿  ÚÄÄÄ¿
//            °°       ³  °°   ³   ³ ³   ³ ³   ³ ³   ³ ³   ³  ³   
//             °°±± ± ²³±°°    ³   ³ ³   ³ ³   ³ ³\  ³ ³   ³  ³   
//              °°² ²±±³°°     ÃÄÄÄ´ ÃÄÄÄÙ ³   ³ ³\\ ³ ³   ³  ÀÄÄÄ¿
//               °°±±² ³°      ³   ³ ³\    ³   ³ ³ \\³ ³   ³      ³
//               °°    ³°      ³   ³ ³ \   ³   ³ ³  \³ ³   ³      ³
//              °° ° ° ÀÄÄÄÄÄ  ³   ³ ³  \  ÀÄÄÄÙ ³   ³ ÀÄÄÄÙ  ÀÄÄÄÙ
//             °°   ± °  °°
//            °° ±°±°°°±  °°
//           °° ±±°°²±±°°±°°°            Timer Library
//          °°±±±²±²²²±±²±²±°°
//         °°²²²²²²²²²²²²²²²²°°
//        °°°°°°°°°°°°°°°°°°°°°°
//
//          Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
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
// Chronos Test App
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <stdlib.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>

#include <chronos.hpp>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

int counter = 0;

void cproc (void *addr)
{
    counter++;
//    *(word *)addr = (word)(0x0700 | ('0' + (i & 7)));
}

void main (int argc, char **argv)
{
    ChronosSystem Chronos;

    for(int i=0; i < 30; i++)
        cout << "\n";

//ÄÄÄÄ Print welcome banner ÄÄÄÄ
    cout << "Chronos Tester - (C) 1994, 1995 by Charybdis Enterprises, Inc.\n\n";

    Chronos.init();

    Chronometer c;

    // Allow the user to specify a speed multiplier
    if (argc == 2)
    {
        int i = atoi (argv[1]);

        cout << "Interval set to " << i << " * 18.207 secs" << endl;

        Chronos.interval ((ushort)i);
    }
    else
        cout << "Optionally, specify a speed multiplyer (0-65535) on the command line" << endl;

    cout << "Time now = " << c.check() << " ms"  << endl;

    chronos_add_callback (cproc, 1, (void *)0xb8000);
    chronos_add_callback (cproc, 10, (void *)0xb8002);

    cout << "<press any key to stop>" << endl;

    while (!kbhit())
        cout << counter << ' ';

    cout << "Time now = " << c.check() << " ms, (" 
         << counter << ") iterations" << endl;
    getch();
    Chronos.term();
}


extern "C" int mythos_atexit( register void ( *__func )( void ) )
{
    return atexit (__func);
}


extern "C" void mythos_atexit_remove( register void ( *__func )( void ) )
{
    (void)__func;
    // NOP
}

// Make sure it uses the correct calling convention!
#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) mythos_atexit;
#pragma aux (_ASMSTKCALL_) mythos_atexit_remove;
#endif

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

//°±² End of module - chtest.cpp ²±°

