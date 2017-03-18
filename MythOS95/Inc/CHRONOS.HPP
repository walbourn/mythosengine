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
//                    Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Dan Higdon
//
// Chronos
//
//      Chronos is the system timer interface.  Through Chronos, the user
//  can register functions to be invoked at a particular interval.  The
//  system programmable timer can also be controlled through this interface.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __CHRONOS_HPP
#define __CHRONOS_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <portable.h>
#include <time.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Typedefs
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

typedef void (*ChronosCallback) (void *);

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

// Initialization
void    chronos_init ();
void    chronos_term ();

// Program the timer resolution
int     chronos_interval_hz (dword tick_millihz);
int     chronos_interval    (word tick_multiplier);

// Callback management interfaces
void    chronos_add_callback (ChronosCallback, dword ticks, void *parm);
void    chronos_clear_callbacks ();

// Time management interfaces
clock_t chronos_time_now ();
double  chronos_time_now_precise ();

// Support
extern "C" double chronos_rdtsc();
extern double __chronos_scale;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  A C++ interface to Chronos, including proper initialization.
//  Note that this is completely compatible with the procedural interface.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class ChronosSystem
{
public:
    ChronosSystem ()    { }
    ~ChronosSystem ()   { }

// Initialization (separate from construction)
    void init ()        { chronos_init(); }
    void term ()        { chronos_term(); }

// Timer programming
    int interval_hz (dword tick_millihz)    { return chronos_interval_hz (tick_millihz); }

    int interval (word tick_interval)       { return chronos_interval (tick_interval); }

// Callback management interfaces
    void add_callback (ChronosCallback c, dword t, void *p) { chronos_add_callback (c, t, p); }

    void clear_callbacks () { chronos_clear_callbacks (); }

// Time management interfaces
    clock_t time_now () const           { return chronos_time_now (); }
    double  time_now_precise () const   { return chronos_time_now_precise (); }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// A timer class, used as a stopwatch.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#if 0
class AtomicChronometer
{
    double  elapsed_time;
    double  start_time;

public:
    AtomicChronometer (){ clear (); }

    void   clear ()     { elapsed_time = 0.0;
                          start_time = chronos_rdtsc(); }

    double start ()     { return (start_time = chronos_rdtsc ()); }
    double stop ()      { return (elapsed_time += chronos_rdtsc() - start_time); }

    double check () const { return (chronos_rdtsc() - start_time) * __chronos_scale; }
    double check_elapsed () const { return elapsed_time * __chronos_scale; }
};
#else
class AtomicChronometer
{
    double  elapsed_time;
    double  start_time;

public:
    AtomicChronometer ()  { clear (); }

    void   clear ()     { elapsed_time = 0.0;
                          start_time = chronos_time_now_precise (); }

    double start ()     { return (start_time = chronos_time_now_precise ()); }
    double stop ()      { return (elapsed_time += chronos_time_now_precise() - start_time); }

    double check () const { return chronos_time_now_precise() - start_time; }
    double check_elapsed () const { return elapsed_time; }
};
#endif


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// A less precise timer class, used as a stopwatch.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class Chronometer
{
    clock_t start_time;

public:
    Chronometer ()      { clear (); }

    void    clear ()    { start_time = chronos_time_now (); }
    clock_t check () const;
};


// The check routine, inlined.
inline clock_t Chronometer::check () const
{
    clock_t stop_time (chronos_time_now ());

    // Handle wrap around
    if (stop_time < start_time)
        return clock_t (-1) - (start_time - stop_time);
    else
        return stop_time - start_time;
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - chronos.hpp ²±°

