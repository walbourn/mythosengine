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
// simulatr.cpp
//
// This module contains the simulator-specific state management class.
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
// SimulatorState - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
SimulatorState::SimulatorState() :
     ui (0),
     objects (0),
     temps (0),
     timeshift (0)
{
    memset(teams, 0, sizeof(teams));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimulatorState - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
SimulatorState::~SimulatorState()
{
    deactivate();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimulatorState - activate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimulatorState::activate ()
{
//ÄÄÄ Create model storage
    obj_hi = 0;
    obj_max = SIM_INIT_OBJECTS;
    objects = new SimObject *[SIM_INIT_OBJECTS];
    if (!objects)
    {
        panic(IDS_SIM_NOMEMORY,"SimulatorState::activate");
        return;
    }
    memset(objects, 0, sizeof(SimObject*) * SIM_INIT_OBJECTS);

    temp_hi = 0;
    temp_max = SIM_INIT_TEMPS;
    temps = new SimTemp *[SIM_INIT_TEMPS];
    if (!temps)
    {
        panic(IDS_SIM_NOMEMORY,"SimulatorState::activate");
        return;
    }
    memset(temps, 0, sizeof(SimTemp*) * SIM_INIT_TEMPS);

    for (int t=0; t < SIM_MAX_TEAMS; t++)
    {
        sim_team_t *st = &teams[t];

        st->unit_hi = 0;
        st->unit_max = SIM_INIT_UNITS;
        st->units = new SimUnit *[SIM_INIT_UNITS];
        if (!st->units)
        {
            panic(IDS_SIM_NOMEMORY,"SimulatorState::activate");
            return;
        }
        memset(st->units, 0, sizeof(SimUnit*) * SIM_INIT_UNITS);

        st->ofld_hi = 0;
        st->ofld_max = SIM_INIT_OFFIELDS;
        st->offields = new SimOffield *[SIM_INIT_OFFIELDS];
        if (!st->offields)
        {
            panic(IDS_SIM_NOMEMORY,"SimulatorState::activate");
            return;
        }
        memset(st->offields, 0, sizeof(SimOffield*) * SIM_INIT_OFFIELDS);
    }

    timebase=0;
    time_now=0;

//ÄÄÄ Startup UI
    assertMyth("SimulatorState::activate needs valid starting ui", ui != 0);

    ui->activate();

    clock.clear();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimulatorState - deactivate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimulatorState::deactivate ()
{
//ÄÄÄ Terminate UI
    if (ui)
        ui->deactivate();

//ÄÄÄ Destroy model storage
    if (objects)
    {
        for(int i=0; i < obj_hi; i++)
        {
            if (objects[i])
                delete objects[i];
        }

        delete [] objects;
        objects = 0;
    }
    if (temps)
    {
        for(int i=0; i < temp_hi; i++)
        {
            if (temps[i])
                delete temps[i];
        }

        delete [] temps;
        temps = 0;
    }
    for (int t=0; t < SIM_MAX_TEAMS; t++)
    {
        sim_team_t *st = &teams[t];

        if (st->units)
        {
            for(int i=0; i < st->unit_hi; i++)
            {
                if (st->units[i])
                    delete st->units[i];
            }

            delete [] st->units;
            st->units = 0;
        }
        if (st->offields)
        {
            for(int i=0; i < st->ofld_hi; i++)
            {
                if (st->offields[i])
                    delete st->offields[i];
            }

            delete [] st->offields;
            st->offields = 0;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimulatorState - process_events
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimulatorState::process_events ()
{
    if (!(flags & MODEL_FROZEN))
    {
        //ÄÄÄ Determine mission time...

        const float interval (float(clock.check() << timeshift) / 1000.0f);
        timebase += interval;
        clock.clear();

        if (timebase > 0)
        {
            time_now = ulong(timebase * 1000.0f);

            //ÄÄÄ Step model
            for(int i=0; i < obj_hi; i++)
            {
                SimObject *ptr = objects[i];
                if (ptr && !(ptr->base_flags & SimObject::BASE_INACTIVE))
                {
                    ptr->step(interval);
                }
            }

            for(i=0; i < temp_hi; i++)
            {
                SimTemp *ptr = temps[i];
                if (ptr && !(ptr->base_flags & SimObject::BASE_INACTIVE))
                {
                    ptr->step(interval);
                }
            }

            sim_team_t *st = teams;
            for(int t=0; t < SIM_MAX_TEAMS; t++, st++)
            {
                for(i=0; i < st->unit_hi; i++)
                {
                    SimUnit *ptr = st->units[i];
                    if (ptr && !(ptr->base_flags & SimObject::BASE_INACTIVE))
                    {
                        ptr->step(interval);
                    }
                }
                for(i=0; i < st->ofld_hi; i++)
                {
                    SimOffield *ptr = st->offields[i];
                    if (ptr && !(ptr->base_flags & SimObject::BASE_INACTIVE))
                    {
                        ptr->step(interval);
                    }
                }
            }
        }
    }

//ÄÄÄ Process UI
    assertMyth("SimulatorState::process_events needs valid ui", ui != 0);

    ui->process_events();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimulatorState - render
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SimulatorState::render ()
{
    assertMyth("SimulatorState::render needs valid ui", ui != 0);

    ui->render();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°±² End of module - simulatr.cpp ²±°

