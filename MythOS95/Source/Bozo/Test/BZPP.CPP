//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                oooooooooo.                                 
//                `888'   `Y8b                                
//                 888     888  .ooooo.    oooooooo  .ooooo.  
//                 888oooo888' d88' `88b  d'""7d8P  d88' `88b 
//                 888    `88b 888   888    .d8P'   888   888 
//                 888    .88P 888   888  .d8P'  .P 888   888 
//                o888bood8P'  `Y8bod8P' d8888888P  `Y8bod8P' 
//                           _                       
//                          /_\     |    _  _ | _ ._ 
//                         /   \  \_||_|(_|(_||(/_|  
//                                       _| _|       
//                       Microsoft Windows '95 Version
//
//            Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
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
// Test application, C++
//
//  This application is very similar to the C version, but uses the C++
// convention stuff
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

#include "ivory.hpp"
#include "bozo.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

BozoSemaphore screen;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class MySemTask: public BozoTask
{
    int instance;

public:
    MySemTask (int _instance): instance (_instance) 
    {
        cout << "Creating " << instance << endl;
    }

    ~MySemTask ()  
    { 
        cout << "Destroying" << instance << endl; 
    }

    void run ()
    {
        MessageBox (NULL, "Hello there!", "Test", MB_OK);

        cout << "Enter " << instance << endl;
        for (int i = 0; i < 5; i++)
        {
            screen.wait();
            cout << "Task " << instance << " number " << i << endl;
            screen.signal();
        }
    }
};

class MySimpleTask: public BozoTask
{
    int instance;

public:
    MySimpleTask (int _instance): instance (_instance) 
    {
        cout << "Creating " << instance << endl;
    }

    ~MySimpleTask ()  
    { 
        cout << "Destroying" << instance << endl; 
    }

    void run ()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Task " << instance << " number " << i << endl;
            yield();
        }
    }
};

class MyTask: public BozoTask
{
public:
    MyTask ()   { }
    ~MyTask ()  { }
    void Run ()
    {
        for (;;)
        {
            cout << "Idle" << endl;
            yield();
        }
    }
};


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Test out the tasking functions with a simple task-switcher.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int main()
{
    char buf[1024 * 64];
    ivory_sub_initialize ((IvorySubAlloc *)buf, sizeof (buf));

//ÄÄÄÄ Print welcome banner ÄÄÄÄ
    cout << "Bozo Tester - (C) 1994, 1995 by Charybdis Enterprises, Inc.\n\n";

    IvorySystem ivory;
    BozoSystem  bozo ((IvorySubAlloc *)buf);

    BozoGate    gate;

    MyTask *idle = new MyTask;
    idle->init (&gate);

    // Now, create some tasks in a scope, so we can test destruction.
    {
        screen.wait();

        MySemTask a (1), c (3);
        MySimpleTask b (2);

        // Initialize them
        a.init (&gate);
        b.init (&gate);
        c.init (&gate);

        // Let the run and give them a chance to breathe
        gate.open();
        bz_suspend();

        // Now, release the semaphore.
        cout << "Release semaphore!\n";
        screen.signal();

        // Run the pump for a while
        bz_suspend();
        bz_suspend();
        bz_suspend();
        bz_suspend();
    }

    cout << "Before the last suspend\n";
    bz_suspend();
    bz_suspend();
    delete idle;
    bz_suspend();
    bz_suspend();
    cout << "After the last suspend\n";

    cout << "Complete\n";
    return 0;
}

// A support function (usually provided by MythosSystem)
extern "C" int mythos_atexit( register void ( *__func )( void ) )
{
    return atexit (__func);
}

// Make sure it uses the correct calling convention!
#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) mythos_atexit;
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

//°±² End of module - bzpp.cpp ²±°

