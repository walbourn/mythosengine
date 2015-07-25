//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                  ooo        ooooo
//                  `88.       .888'
//                   888b     d'888   .oooo.   oooo    ooo
//                   8 Y88. .P  888  `P  )88b   `88b..8P'
//                   8  `888'   888   .oP"888     Y888'
//                   8    Y     888  d8(  888   .o8"'88b
//                  o8o        o888o `Y888""8o o88'   888o
//
//                          Across the event horizon...
//
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
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
// maxesrc.cpp
//
// Max Event Source
//
//  EventSource --  This class associates Events with EventTriggers,
//                  and contains the physical device objects that can be
//                  shown to EventTriggers.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include <ivory.hpp>
#include <xfile.hpp>
#include <bzwrap.hpp>

#include <stdio.h>

#include "maxesrc.hpp"

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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Create a new event source with no Event/Trigger bindings,               ³
//  and Uninited physical devices.                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MaxEventUser::MaxEventUser (MaxDevices &devs, const char *iff_file, const char *evt_chunk):
    MaxEventSource (),
    bindings    (0),
    TRGS        (0),
    ntriggers   (0),
    theDevices  (devs)
{
    if (iff_file)
    {
        int res = load (iff_file, evt_chunk);
        assert (res == 0);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Destroy the EventSource, freeing any assiociations allocated.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MaxEventUser::~MaxEventUser()
{
    clear();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Load a set of triggers from the specified IFF file.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int MaxEventUser::load (const char *fname, const char *ename)
{
    // Open and parse IFF file.
    XFParseIFF  iff;

    if (iff.open (fname, XF_OPEN_READ) == 0)
    {
        while (iff.seekform (iff.makeid ('M','E','V','T')) == 0)
        {
            if (load (&iff, ename) == 0)
                return 0;
        }
    }

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Load a set of triggers from the specified IFF file.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int MaxEventUser::load (XFParseIFF *iffp, const char *ename)
{
    int         res = 1;
    MaxHeader   hdr;
    dword       *EVTS = 0;

    assert (iffp != 0);

    if (iffp->chunkid == iffp->makeid ('F','O','R','M') &&
        iffp->formid  == iffp->makeid ('M','E','V','T'))
    {
        iffp->enterform();

        // Find the header chunk
        if (iffp->seekchunk (iffp->makeid ('H','D','R',' ')) != 0)
        {
            iffp->leaveform();
            return res;
        }

        // Read the header, and make sure it's the size we're expecting
        if (iffp->chunkSize != sizeof (hdr))
        {
            iffp->leaveform();
            return res;
        }

        iffp->read (&hdr);

        if (ename == 0 || strncmp (ename, hdr.name, sizeof (hdr.name)) == 0)
        {
            // Start with a clean slate.
            clear();

            ntriggers = hdr.num_trigs;

            TRGS = new MaxTrigger[ntriggers];
            EVTS = new dword[ntriggers];

            if (!TRGS || !EVTS)
            {
                if (TRGS)
                    delete [] TRGS;

                if (EVTS)
                    delete [] EVTS;

                TRGS = 0;

                iffp->leaveform();
                return res;
            }

            if (   iffp->seekchunk (iffp->makeid ('E','V','N','T')) == 0
                && iffp->chunkSize == hdr.num_trigs * sizeof (dword)
                && iffp->read (EVTS) == 0)
            {
                if (   iffp->seekchunk (iffp->makeid ('T','R','G','S')) == 0
                    && iffp->chunkSize == hdr.num_trigs * sizeof (MaxTrigger)
                    && iffp->read (TRGS) == 0)
                {
                    // Now, hook them up
                    for (ulong i = 0; i < hdr.num_trigs; i++)
                        connect (TRGS[i], MaxEvent (EVTS[i]));

                    // We did it!
                    res = 0;
                }
            }

            // Lastly, remove the events.  Triggers remain, since
            // they are references and must be maintained.
            if (EVTS)
                delete [] EVTS;
        }
        iffp->leaveform();
    }

    return res;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Initialize the system, including the physical devices.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxEventUser::install ()
{
    int use_mou = 0;
    int use_key = 0;
    int use_joy = 0;

    // Collect the list of required devices
    for (EventBinding *n = bindings; n != 0; n = n->next)
    {
        if (n->trigger.uses_mouse ())
            use_mou = 1;
        if (n->trigger.uses_joystick ())
            use_joy = 1;
        if (n->trigger.uses_keyboard ())
            use_key = 1;
    }

    // Enable the required devices
    theDevices.enable_mouse    (use_mou);
    theDevices.enable_keyboard (use_key);
    theDevices.enable_joystick (use_joy);

    // Get the current set of events.
    theDevices.update();
    process();
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Uninit the system, including the physical devices.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxEventUser::uninstall ()
{
    theDevices.enable_mouse    (0);
    theDevices.enable_keyboard (0);
    theDevices.enable_joystick (0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Add a trigger/event pair to the EventSource.  No check is made for       ³
// uniqueness.                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxEventUser::connect (const MaxTrigger &et, MaxEvent evt)
{
    bindings = new EventBinding (et, evt, bindings);
    assert (bindings);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Remove the trigger/event pair from the EventSource.                      ³
// If the pair is not present, that's ok.                                   ³
// (Removing things from lists is always SO unpleasant....)                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxEventUser::disconnect (const MaxTrigger &et, MaxEvent evt)
{
    if (bindings)
    {
        const EventBinding target (et, evt);
        EventBinding *b = bindings;

        // Is it the head of the list?
        if (*b == target)
        {
            bindings = b->next;
            delete b;
        }
        else
        {
            // Otherwise, scan the list for it.
            for (EventBinding *n = b->next; n != 0; (b = n), (n = b->next))
            {
                if (*n == target)
                {
                    b->next = n->next;
                    delete n;
                    break;      // Only remove the first instance!
                }
            }
        }
    }
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Enumerate all of the triggers.                                          ³
//  The function can modify the triggers if it wants.  The function         ³
//  May return TRUE in order to halt the enumeration.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxEventUser::enumerate_triggers (int (*func) (MaxTrigger *))
{
    for (int i = 0; i < ntriggers; i++)
    {
        if (!func (&TRGS[i]))
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Clear the event/trigger bindings.                                       ³
//  Additionally, remove the TRGS buffer, if one exists.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxEventUser::clear ()
{
    EventBinding *b = bindings;

    while (b)
    {
        EventBinding *n = b->next;
        delete b;
        b = n;
    }

    if (TRGS)
        delete [] TRGS;

    TRGS = 0;
    bindings = 0;
    ntriggers = 0;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Process all event/triggers, and return and EventList of all events       ³
// in the source.  Only check events we might be interested in              ³
// (that is, only check events in the mask).                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MaxEventList MaxEventUser::process (const MaxEventList &mask)
{
    MaxEventList res;

    for (EventBinding *p = bindings; p; p = p->next)
    {
        // If we're interested in this event, check its trigger(s).
        if (mask.check (p->event))
        {
            if (p->trigger.check (theDevices))
                res.add (p->event);
        }
    }

    return res;
}



//°±² End of module - maxesrc.cpp ²±°

