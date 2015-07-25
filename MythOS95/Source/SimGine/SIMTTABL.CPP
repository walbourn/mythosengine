//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                              S I M   G I N E
//
//             __               ___   ______,-------
//           __==__,------------/|\--|      | .-.-.|    ___________
//         (|     |--------------|---|------| '-`-`|  _/___________\_
//         (|_____|      _       _   |   _  | 6000 | |               |
//          |__\\_|`-._/___\___/___\_|_/___\|      | |               |
//         __/ |===|--|_____|_|_____|_|___  |\_____|=|_______________|
//      |=|[_]==[_]    \ _ /   \ _ /   \ _ /          [_]   [_]   [_]
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                     A Simluator Framework for MythOS(tm)
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1997-1998 by Charybdis Enterprises, Inc.
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
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// simttabl.cpp
//
//  An event scheduler.  The time table calls back functions at a given
//  time.  This differs from a timer callback in that the time table only
//  guarantees that a function will be evaluated AFTER a specified time,
//  and then only if the time table is stepped.  Therefore, the time table
//  is suitable for scheduling occurences within a simulation.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "simgine.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimTimeTable - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
SimTimeTable::SimTimeTable (int size) :
    head (0),
    tail (0),
    free_list (0),
    arena (0),
    arena_size (0)
{
    assert (size > 0);

    size_alloc (size);
    assert (arena != 0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimTimeTable - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
SimTimeTable::~SimTimeTable()
{
    cleanup();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimTimeTable - size_alloc
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimTimeTable::size_alloc (int _size)
{
    assert (_size > 0);

    if (arena_size < _size)
    {
        if (arena == 0)
        {
            arena = (event *)ivory_alloc (sizeof (event) * _size);
            if (arena != 0)
            {
                //ÄÄÄ Remember the head pointer
                free_list = arena;

                //ÄÄÄ Thread the free list
                event *pevt = arena;
                for (int i = 0; i < _size-1; i++)
                {
                    pevt->next = pevt+1;
                    pevt++;
                }
                pevt->next = 0;

                //ÄÄÄ Remember the new arena size
                arena_size = _size;
            }
        }

        else
        {
            //ÄÄÄ We must resize an existing allocation
            //ÄÄÄ This is tantamount to copying all data over, repatching
            //ÄÄÄ all of the pointers!
            event *new_arena = (event *)ivory_alloc (sizeof (event) * _size);
            if (new_arena != 0)
            {
                //ÄÄÄ Copy the existing entries over and re-link them
                event *arenaptr = new_arena;
                int    arenacnt = 1;    // So the last while loop works out

                //ÄÄÄ First, copy the "good" elements, packing them in the front
                event *aptr = head;
                if (aptr != 0)
                {
                    // This is a little convoluted to maximize execution speed
                    for (;;)
                    {
                        assert (arenacnt <= arena_size);

                        *arenaptr = *aptr;

                        arenacnt++;
                        event **const nptr = &arenaptr->next;
                        arenaptr++;

                        aptr = aptr->next;
                        if (aptr)
                            *nptr = arenaptr;
                        else
                        {
                            *nptr = 0;
                            break;
                        }
                    }
                }

                //ÄÄÄ We are at the divide, mark this as the freelist point
                free_list = arenaptr;

                //ÄÄÄ Now, create a freelist in the rest of the block
                while (arenacnt < _size)
                {
                    arenaptr->next = arenaptr+1;
                    arenaptr++;
                    arenacnt++;
                }

                //ÄÄÄ Cap the end of the freelist
                arenaptr->next = 0;

                //ÄÄÄ Claim the new arena space
                arena = new_arena;
                arena_size = _size;
            }
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimTimeTable - cleanup
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimTimeTable::cleanup ()
{
    if (arena)
        ivory_free ((void **)&arena);
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimTimeTable - add_event
//
//  This routine has been special cased for efficiency.  The last case is
//  actually sufficient, but some special situations that are easy to detect
//  allow us to take some shortcuts.  In particular, the tail append will
//  probably be a BIG time-saver in common usage.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimTimeTable::add_event (clock_t t, callback_t f, void *p)
{
    assert ((head == 0 && tail == 0)
            || (head != 0 && tail != 0));

    //ÄÄÄ Make sure there's room in the free_list
    if (!free_list)
        size_alloc (arena_size * 2);

    //ÄÄÄ Allocate a new event
    event *new_evt = free_list;
    free_list = free_list->next;
    new_evt->event::event (t, f, p);

    //ÄÄÄ Decide where to put the new event (special cased for efficiency)
    if (head == 0)
    {
        //ÄÄÄ This is the first and only node
        head = tail = new_evt;
    }

    else if (tail->time <= t)
    {
        //ÄÄÄ Link the new node in at the end of the list
        tail->next = new_evt;
        tail = new_evt;
    }

    else if (tail == head)
    {
        //ÄÄÄ Link the new node in at the beginning of the single-item list
        new_evt->next = head;
        head = new_evt;
    }

    else
    {
        //ÄÄÄ Link the new node in at the appropriate location
        event *curr_evt = head;
        event *prev_evt = 0;

        //ÄÄÄ Linear search is slow, but hopefully the common cases will have been caught above
        while (curr_evt != 0 && curr_evt->time <= t)
        {
            prev_evt = curr_evt;
            curr_evt = curr_evt->next;
        }

        new_evt->next = curr_evt;

        if (!prev_evt)
            head = new_evt;     // new event inserted at top
        else
        {
            prev_evt->next = new_evt;

            if (curr_evt == 0)
                tail = new_evt;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimTimeTable - add_event_rel
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimTimeTable::add_event_rel (clock_t t, callback_t f, void *p)
{
    add_event (chronos_time_now() + t, f, p);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimTimeTable - rem_event
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimTimeTable::rem_event (callback_t f, void *p, bool all)
{
    assert ((head == 0 && tail == 0)
            || (head != 0 && tail != 0));

    // Optimization of the "don't care" case
    if (f == 0 && p == 0)
    {
        while (head != 0)
        {
            // Unlink the first element
            event *old_evt = head;
            head = head->next;

            // Return it to the free list
            old_evt->next = free_list;
            free_list = old_evt;

            if (!all)
                break;
        }

        if (head == 0 || head->next == 0)
            tail = head;
    }
    else
    {
        event *curr_evt = head;
        event *prev_evt = 0;

        while (curr_evt != 0)
        {
            if ((f == 0 || curr_evt->fp == f)
                && (p == 0 || curr_evt->prm == p))
            {
                // This one needs deleting
                if (!prev_evt)
                    head = curr_evt->next;
                else
                    prev_evt->next = curr_evt->next;

                event *old_evt = curr_evt;
                curr_evt = curr_evt->next;

                // Return it to the free list
                old_evt->next = free_list;
                free_list = old_evt;

                // Keep tail pointer correct (works for empty list too)
                if (curr_evt == 0)
                    tail = prev_evt;
            }

            if (!all)
                break;

            prev_evt = curr_evt;
            curr_evt = curr_evt->next;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimTimeTable - step
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimTimeTable::step (clock_t time)
{
    assert ((head == 0 && tail == 0)
            || (head != 0 && tail != 0));

    while (head != 0 && head->time <= time)
    {
        head->fp (head->prm);

        // Return this link to the freelist
        event *old_evt = head;
        head = head->next;

        old_evt->next = free_list;
        free_list = old_evt;
    }

    if (head == 0)
        tail = 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimTimeTable - step
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimTimeTable::step()
{
    step (chronos_time_now());
}


//°±² End of module - ttable.cpp ²±°
