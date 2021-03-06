//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//        旭旭旭旭旭旭旭旭旭旭旭
//         旭                旭
//          旭              旭
//           旭        敖陳陳  �   � 敖陳� 敖陳� �   � 敖陳�  敖陳�
//            旭       �  旭   �   � �   � �   � �   � �   �  �
//             旭臼 � 桶碓�    �   � �   � �   � �\  � �   �  �
//              旭� 憶嘘旭     団陳� 団陳� �   � �\\ � �   �  青陳�
//               旭臼� 外      �   � �\    �   � � \\� �   �      �
//               旭    外      �   � � \   �   � �  \� �   �      �
//              旭 � � 青陳陳  �   � �  \  青陳� �   � 青陳�  青陳�
//             旭   � �  旭
//            旭 碓碓旭�  旭
//           旭 臼旭憶碓葦旭�            Timer Library
//          旭臼渦渦臆臼憶憶旭
//         旭臆臆臆臆臆臆臆臆旭
//        旭旭旭旭旭旭旭旭旭旭旭
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
// Created by Dan Higdon
//
// Chronos
//
//      Chronos is the system timer interface.  Through Chronos, the user
//  can register functions to be invoked at a particular interval.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <assert.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>

#include "chronos.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

struct iChronosUserProc
{
    UINT            hTimer;
    ChronosCallback fn;
    void            *parm;
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

// Imported from the Mythos class system
extern "C" int mythos_atexit (register void (*__func) (void));
extern "C" void mythos_atexit_remove (register void (*__func) (void));

extern "C" double chronos_rdtsc();

// A cleanup function
static void ichronos_cleanup ();

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

const int MAX_CALLBACKS = 32;

static volatile ulong   system_freq;
static volatile int     instance = 0;
static iChronosUserProc timer_handles[MAX_CALLBACKS];
static bool             __chronos_use_pentium = false;
double                  __chronos_scale;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// A simple utility to convert between "timer multipliers" and milliseconds
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
inline ulong mult2ms (ulong multiplier)
{
    assert (multiplier > 0);

    return 549 / (multiplier * 10);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ichronos_timer_proc
//
//  This routine will call our timer proc.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void CALLBACK ichronos_timer_proc (UINT idTimer, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
    iChronosUserProc *pcup = (iChronosUserProc *)dwUser;

    assert (idTimer == pcup->hTimer);

    pcup->fn (pcup->parm);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// chronos_init
//
// Initialize Chronos
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void chronos_init ()
{
    if (instance == 0)
    {
        system_freq = 0;
        chronos_interval (0);
        memset (timer_handles, 0, sizeof (timer_handles));
        mythos_atexit (ichronos_cleanup);

        // See if we can use the Pentium timer register
        SYSTEM_INFO  ProfilerSysinfo;

        GetSystemInfo (&ProfilerSysinfo);
        __chronos_use_pentium = false;

        if (ProfilerSysinfo.dwProcessorType == PROCESSOR_INTEL_PENTIUM)
        {
            int     c0,cf;  // clocks.
            double  t0,tf;  // ticks.

            int x = 1;

            c0 = clock();
            t0 = chronos_rdtsc();

            for (int i=0;i < 20000000; i++)
                x = (i & x) ? 0 : 1;

            tf = chronos_rdtsc();
            cf = clock();

            double rate = (tf-t0)/((cf-c0)*(1000000.0 / double(CLOCKS_PER_SEC)));
            __chronos_scale = 1.0 / (rate * 1000.0);

            __chronos_use_pentium = true;
        }
    }

    instance++;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// chronos_term
//
// Terminate Chronos
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void chronos_term ()
{
    mythos_atexit_remove (ichronos_cleanup);

    if (instance > 0)
    {
        if (--instance == 0)
        {
            ichronos_cleanup();
        }
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ichronos_cleanup
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
static void ichronos_cleanup ()
{
    chronos_clear_callbacks ();

    if (system_freq != 0)
    {
        timeEndPeriod (system_freq);
    }

    system_freq = 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// chronos_interval_mhz
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int chronos_interval_mhz (dword mlhz)
{
    assert (mlhz <= dword (1193181000));

    // calculate the new system frequency
    return chronos_interval (word ((mlhz / 18207) >> 1));
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// chronos_interval
//
//  Program the timer to the given number of multiples of its base
//  frequency (18.207 hz), based on 0  (0 == 18hz, 1 = 36hz, etc)
//  Return whether or not you succeeded
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int chronos_interval (word multiplier)
{
    // Close out any existing periods
    if (system_freq != 0)
        timeEndPeriod (system_freq);

    // calculate the new system frequency
    system_freq = mult2ms (multiplier + 1);

    // Inform the hardware
    if (timeBeginPeriod (system_freq) == TIMERR_NOERROR)
        return 1;

    system_freq = 0;
    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// chronos_add_callback
//
// Add the function/parameter to the callback list for execution every
// 'freq' timer ticks.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void chronos_add_callback (ChronosCallback func, dword freq, void *parm)
{
    assert (func != 0);
    assert (freq > 0);

    for (int i = 0; i < MAX_CALLBACKS; i++)
    {

        if (timer_handles[i].hTimer == 0)
        {
            timer_handles[i].fn     = func;
            timer_handles[i].parm   = parm;
            timer_handles[i].hTimer = timeSetEvent (freq * system_freq,
                                                    system_freq,
                                                    ichronos_timer_proc,
                                                    (DWORD)&timer_handles[i],
                                                    TIME_PERIODIC);
            return;
        }
    }

    // Error condition if we get here
    assert (!"Unable to add the callback!");
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// chronos_clear_callbacks
//
// Clear all callback functions.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void chronos_clear_callbacks ()
{
    for (int i = 0; i < MAX_CALLBACKS; i++)
    {
        if (timer_handles[i].hTimer)
        {
            timeKillEvent (timer_handles[i].hTimer);
            timer_handles[i].hTimer = 0;
        }
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// chronos_time_now_precise
//
// Return the current time in processor clock fractions
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
double chronos_time_now_precise ()
{
    if (__chronos_use_pentium)
        return chronos_rdtsc() * __chronos_scale;
    else
        return double (timeGetTime());
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// chronos_time_now
//
// Return the current time in milliseconds.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
clock_t chronos_time_now ()
{
    if (__chronos_use_pentium)
        return clock_t (chronos_rdtsc() * __chronos_scale);
    else
        return timeGetTime();
}

//葦� End of module - chronos.cpp 憶�
