//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//                     Microsoft Windows 95/98/NT Version
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
// Created by Dan Higdon
//
// Test application, C++
//
//  This application is very similar to the C version, but uses the C++
// convention stuff
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "ivory.hpp"
#include "bozo.hpp"

using namespace std;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

BozoSemaphore screen;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

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


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Test out the tasking functions with a simple task-switcher.             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int main()
{
    char buf[1024 * 64];
    ivory_sub_initialize ((IvorySubAlloc *)buf, sizeof (buf));

//陳陳 Print welcome banner 陳陳
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

//葦� End of module - bzpp.cpp 憶�

