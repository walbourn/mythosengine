//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
//                     A Simluator Framework for MythOS(tm)
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1997-1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//���������������������������������������������������������������������������
//
// simunit.cpp
//
// This module contains the base unit representation class for the simulator.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "simgine.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimUnit - Constructor
//���������������������������������������������������������������������������
SimUnit::SimUnit(SimulatorState *_parent) :
    SimBase(_parent)
{
    for(int i=0; i < SIM_MAX_EQUIP; i++)
        equip[i] = 0;
}


//���������������������������������������������������������������������������
// SimUnit - Destructor
//���������������������������������������������������������������������������
SimUnit::~SimUnit()
{
    release();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimUnit - release
//���������������������������������������������������������������������������
void SimUnit::release()
{
    for(int i=0; i < SIM_MAX_EQUIP; i++)
    {
        if (!equip[i])
            continue;

        equip[i]->release();
        delete equip[i];
        equip[i]=0;
    }
}


//���������������������������������������������������������������������������
// SimUnit - step
//���������������������������������������������������������������������������
void SimUnit::step(float interval)
{
    for(int i=0; i < SIM_MAX_EQUIP; i++)
    {
        if (equip[i])
            equip[i]->step(interval);
    }
}


//���������������������������������������������������������������������������
// SimUnit - insert
//���������������������������������������������������������������������������
BOOL SimUnit::insert(ushort t)
{
    assertMyth("SimUnit::insert needs parent",
               parent != 0 && parent->teams[t].units != 0);

    if (index != ushort(-1))
        remove();

    team = t;

//��� Find empty slot
    SimulatorState::sim_team_t *st = &parent->teams[t];

    for (int i=0; i < st->unit_max; i++)
    {
        if (!st->units[i])
            break;
    }
    //��� Expand array
    if (i >= st->unit_max)
    {
        ushort nsize = st->unit_max + SIM_INIT_OBJECTS;

        SimUnit **tmp = new SimUnit *[nsize];
        if (!tmp)
            return FALSE;

        memset(tmp, 0, sizeof(SimUnit*) * nsize);

        memcpy(tmp, st->units, sizeof(SimUnit*) * st->unit_max);

        delete [] st->units;

        st->units = tmp;
        st->unit_max = nsize;
    }

//��� Insert into slot
    st->units[i] = this;
    index = i;

    if (i >= st->unit_hi)
        st->unit_hi = i + 1;

    return TRUE;
}


//���������������������������������������������������������������������������
// SimUnit - remove
//���������������������������������������������������������������������������
void SimUnit::remove()
{
    if (index == ushort(-1))
        return;

    if (!parent || !parent->teams[team].units)
        return;

    SimulatorState::sim_team_t *st = &parent->teams[team];

    if (index < st->unit_max)
        st->units[index] = 0;

    index = ushort(-1);
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//��� End of module - simunit.cpp ���
