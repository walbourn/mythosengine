//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                   Ivory -- A Memory Management Library
//
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
// Ivory Test
//
//      This module provides a (hopefully) rigorous test of the IVORY
//      library.  It stresses all three allocation strategies by
//      allocating random blocks of memory, and freeing these back in
//      a random order.  Then, once it is finished, it verifies that
//      all allocations have been properly cleaned up.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <assert.h>
#include "../inc/ivory.hpp"

using namespace std;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

const int arena_size = 0x10000;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

// For the C++ test.
struct MyClass
{
   char *msg;
   MyClass (char *_msg): msg(_msg) { }
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//      The main routine.  This drives the test.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void main ()
{
    const       swap_space = 1024 * 1024;
    void        *ptrs[100]; // A very handy little local
    int         i;
    IvoryHandle h[100];

//陳陳 Print welcome banner 陳陳
    cerr << "Ivory Tester - (C) 1994-1999 by Charybdis Enterprises, Inc.\n\n";
    cerr << "Initializing the Ivory system....\n";

    IvorySystem ivory;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Global space functions
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    cerr << "Testing global space allocation... ";
    memset (ptrs, 0, sizeof (ptrs));
    time_t start = clock();
    for (i = 0; i < 100000; i++)
    {
        int j = rand() % 10;
        if (ptrs[j])
            ivory_free (&ptrs[j]);
        else
        {
            ptrs[j] = ivory_alloc (0x1000 - 8);

            if (ptrs[j] == NULL)
            {
                cerr << "Out of standard memory" << endl;
                return;
            }

            memset (ptrs[j], 0xff, 0x1000 - 8);

            // Ensure paragraph alignment
//            assert (((ulong)ptrs[j] & 0x0f) == 0);
        }
    }

    // Now, clean up any stragglers.
    for (i = 0; i < 10; i++)
        if (ptrs[i])
            ivory_free (&ptrs[i]);

    cerr << "Time = " << (clock() - start);
    cerr << "Passed" << endl;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Handle space speed test
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    cerr << "Testing handle space speed... ";
    memset (ptrs, 0, sizeof (ptrs));
    start = clock();
    for (i = 0; i < 100; i++)
        h[i] = ivory_halloc (0x1000 - 8);

    // Test 100000 iterations
    for (i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            void *lock = ivory_hlock (h[j]);
            ivory_hunlock (h[j]);
        }
    }

    // Now, clean up any stragglers.
    for (i = 0; i < 100; i++)
        if (h[i])
            ivory_hfree (&h[i]);

    cerr << "Time = " << (clock() - start);
    cerr << "Passed" << endl;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Handle space functions
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    cerr << "Testing handle space allocation... ";

    // Totally butt-simple test for now; I'll do better later
    for (i = 0; i < 10; i++)
    {
        h[i] = ivory_halloc (swap_space/5);
        if (h[i] == NULL)
        {
            cerr << "Unable to allocate handle #" << i << endl;
            return;
        }
    }

    // Set up the memory
    for (i = 0; i < 10; i++)
    {
        char *ptr = (char *)ivory_hlock (h[i]);
        if (ptr == NULL)
        {
            cerr << "Unable to lock handle #" << i << endl;
            return;
        }
        memset (ptr, i+'0', swap_space/5);
        ivory_hunlock (h[i]);
    }

    // Test the memory
    for (i = 0; i < 10; i++)
    {
        // Check the memory (notice I swapped the byte to seek)
        char *ptr = (char *)ivory_hlock (h[i]);
        if (ptr == NULL)
        {
            cerr << "Unable to lock handle #" << i << endl;
            return;
        }
        ptr = (char *)memchr (ptr, i+'0', swap_space/5);
        if (!ptr)
            cerr << "Incorrect data in handle #" << i << endl;
        ivory_hunlock (h[i]);
    }

    // Free the handles
    for (i = 0; i < 10; i++)
        ivory_hfree (&h[i]);

    cerr << "Passed" << endl;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Arena space functions
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    cerr << "Testing arena space allocation... ";

    // Here, we just create an arena, and allocate enough bytes to
    // cause it to create two additional "arena chains".

    // Create a local scope
    {
        IvoryArena *arena = (IvoryArena *)ivory_alloc (arena_size);
        ivory_arena_initialize (arena, arena_size);
        assert (ivory_arena_chainlength (arena) == 0);

        for (i = 0; i < 0x28; i++)
        {
            ptrs[i] = ivory_arena_alloc (arena, arena_size / 0x10);
            memset (ptrs[i], 0xff, arena_size / 0x10);
            assert (ptrs[i] != 0);
        }

        assert (ivory_arena_chainlength (arena) == 2);
        ivory_arena_clear (arena);
        for (i = 0; i < 0x28; i++)
            ptrs[i] = 0;
        assert (ivory_arena_chainlength (arena) == 0);
        ivory_free ((void **)&arena);
    }

    cerr << "Passed" << endl;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Now, do it all again, but this time, in C++!
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // C++ Global space functions
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    cerr << "Testing C++ global space allocation... ";
    for (i = 0; i < 100; i++)
    {
        int j = rand() % 10;
        if (ptrs[j])
        {
            delete ptrs[j];
            ptrs[j] = 0;
        }
        else
        {
            ptrs[j] = new char[0x1000-8];
            assert (ptrs[j]);
        }
    }

    // Now, clean up any stragglers.
    for (i = 0; i < 10; i++)
        if (ptrs[i])
            delete ptrs[i];

    cerr << "Passed" << endl;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // C++ Handle space functions
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    cerr << "Testing C++ handle space allocation... ";

    h[0] = ivory_hdup (MyClass ("(Duplicating...) "), 1);
    if (h[0])
    {
        IvoryLock<MyClass> p (h[0]);
        cerr << p->msg;
    }
    ivory.hfree (&h[0]);

    cerr << "Passed" << endl;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // C++ Arena space functions
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    cerr << "Testing C++ arena space allocation... ";

    // Create a local scope
    {
        IvoryNewArena<arena_size> *arena = new IvoryNewArena<arena_size>;

        // Here, we just create an arena, and allocate enough bytes to
        // cause it to create two additional "arena chains".
        for (i = 0; i < 0x28; i++)
        {
            ptrs[i] = new (arena) char [arena_size / 0x10];
            assert (ptrs[i]);
        }
        assert (arena->chainlength() == 2);
        arena->clear();
        assert (arena->chainlength() == 0);

        delete arena;
    }

    cerr << "Passed" << endl;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    //  If we get here, we probably work correctly!
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    cerr << "Complete!" << endl;
    ivory_terminate ();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// _charybdis_assert
//
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void _charybdis_assert(char *msg, char *exp, char *f, unsigned ln)
{
    static loop_check = 0;

    if (!loop_check)
    {
        loop_check++;
        cout.flush();
        printf("\n\n臼� Assertion Failed 臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼\n"
               "Expr:\t%s\n"
               "File:\t%s\t\tLine %d\n",exp,f,ln);
        if (msg)
        {
            printf("Comment:\n%s\n",msg);
        }
    }

    exit(1);
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


//葦� End of module - ivtest.cpp 憶�
