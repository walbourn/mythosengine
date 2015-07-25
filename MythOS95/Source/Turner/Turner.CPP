//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм
//
//                           Turner - Networking
//
//                Copyright (c) 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
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
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// Turner Network Interface
//
// turner.cpp
//
//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Includes
//                                
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

#include <assert.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Turner.hpp"

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Equates
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                               Structures
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                               Routines
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Data
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠


//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Code
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - Constructor
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerNetwork::TurnerNetwork (GUID _guid, const char *_name, int _players):
    is_opened (FALSE), pIDP (0)
{
    // Fill in the common fields of the session descriptor.
    memset (&session, 0, sizeof (session));
    session.dwSize      = sizeof (session);
    session.dwMaxPlayers= _players;
    session.dwFlags     = DPOPEN_OPENSESSION;
    session.guidSession = _guid;
    strcpy (session.szSessionName, _name);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - Copy Constructor
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerNetwork::TurnerNetwork (const TurnerNetwork &m):
    is_opened (FALSE),
    pIDP (0)
{
    // Hidden, should never be called
    assertMyth ("TurnerNetwork::TurnerNetwork (TurnerNetwork &) cannot be called", 0);
}



//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - active
//  returns whether or not this network connection is active
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL TurnerNetwork::active () const
{
    return pIDP != 0 && is_opened;
}



//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - select_provider
//  Create a DirectPlay interface to the specified DP provider.
//  (Usually this value will be selected by the UI)
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::select_provider (LPGUID provider_guid)
{
    return DirectPlayCreate (provider_guid, &pIDP, NULL);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - create_game
//  Create a new game of the type specified during construction.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::create_game ()
{
    assertMyth ("TurnerNetwork::create_game - A service provider must have been chosen", pIDP);

    // Fill in the rest of the session flags
    session.dwFlags = DPOPEN_CREATESESSION;

    HRESULT res = pIDP->Open (&session);

    is_opened = (res == DP_OK);

    return res;
}



//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - create_player
//  Creates a new player ID, given short and long names.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
DPID TurnerNetwork::create_player (const char *short_name, const char *long_name)
{
    assertMyth ("TurnerNetwork::create_player - A service provider must have been chosen", pIDP);

    DPID id = 0;

    pIDP->CreatePlayer (&id, (char *)short_name, (char *)long_name, NULL);

    return id;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - destroy_player
//  Creates a new player ID, given short and long names.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::destroy_player (DPID id)
{
    assertMyth ("TurnerNetwork::destroy_player - A service provider must have been chosen", pIDP);
    pIDP->DestroyPlayer (id);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - static _player_callback
//  This is the enumeration function for TurnerNetwork::connect_game
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK _player_callback (DPID id, char *short_name, char *long_name, DWORD flags, LPVOID context)
{
    // Add the player to the internal list of players
    TurnerNetwork  *net = (TurnerNetwork *)context;

    net->sys_newplayer (id, short_name, long_name);

    return TRUE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - connect_game
//  Open a connection to the specified session of the 
//  game specified during construction.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::connect_game (DWORD dwSession)
{
    // Fill in the rest of the session flags
    session.dwFlags     = DPOPEN_OPENSESSION;
    session.dwSession   = dwSession;

    HRESULT res = pIDP->Open (&session);

    is_opened = (res == DP_OK);

    // Populate our existing player tables
    if (res == DP_OK)
        pIDP->EnumPlayers (dwSession, _player_callback, this, DPENUMPLAYERS_REMOTE);

    return res;
}



//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - operator =
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerNetwork &TurnerNetwork::operator = (const TurnerNetwork &m)
{
    // Hidden, should never be called
    assertMyth ("TurnerNetwork::operator = cannot be called", 0);

    return *this;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - Destructor
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerNetwork::~TurnerNetwork()
{
    assertMyth ("TurnerNetwork Destructor: Must have DPlay connection", pIDP != 0);

    if (pIDP)
    {
        is_opened = FALSE;
        pIDP->Close();
        pIDP->Release();
        pIDP = 0;
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - close
//  Close the connection to the game.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::close ()
{
    if (pIDP)
    {
        is_opened = FALSE;
        pIDP->Close ();
        pIDP->Release ();
        pIDP = 0;
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - receive
//  get and process the next packet in the queue.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::receive (void *ptr, size_t sz)
{
    assertMyth ("TurnerNetwork receive: Must have DPlay connection", pIDP != 0);

    DPID    from;
    DPID    to;
    HRESULT res;

    res = pIDP->Receive (&from, &to,
                         DPRECEIVE_ALL,
                         ptr, (LPDWORD)&sz);

    switch (res)
    {
    case DPERR_NOMESSAGES:
        // This is just fine
        break;

    case DP_OK:
        // Yaaay!  We got a message
        if (from == 0)
            return handle_sysmsg ((DPMSG_GENERIC *)ptr, sz);
        else
            return handle_msg (from, to, ptr, sz);
    }
    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - send
//  Send a packet to the specified player (from a specified player)
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::send (DPID player, DPID dest, void *ptr, size_t sz)
{
    assertMyth ("TurnerNetwork send: Must have DPlay connection", pIDP != 0);

    return pIDP->Send (player, dest, 0, ptr, sz);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - broadcast
//  Broadcast a packet to all players from a specified player.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::broadcast (DPID player, void *ptr, size_t sz)
{
    assertMyth ("TurnerNetwork broadcast: Must have DPlay connection", pIDP != 0);

    return pIDP->Send (player, 0, 0, ptr, sz);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - handle_msg
//  Handle ordinary messages
//  Overload this member for application message processing
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::handle_msg (DPID from, DPID to, void *pmsg, size_t msg_len)
{
    return DP_OK;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - handle_sysmsg
//  Handles any system messages that are received.
//  Overload this member for custom system message processing
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::handle_sysmsg (DPMSG_GENERIC *pmsg, size_t msg_len)
{
    switch (pmsg->dwType)
    {
    case DPSYS_ADDPLAYER:
        {
            DPMSG_ADDPLAYER *msg = (DPMSG_ADDPLAYER *)pmsg;

            if (msg->dwPlayerType)
                return sys_newplayer (msg->dpId, msg->szShortName, msg->szLongName);
            else
                return sys_newgroup (msg->dpId, msg->szShortName, msg->szLongName);
        }
        break;

    case DPSYS_DELETEPLAYERFROMGRP:
        {
            DPMSG_GROUPDELETE *msg = (DPMSG_GROUPDELETE *)pmsg;

            return sys_remove_player_from_group (msg->dpIdGroup, msg->dpIdGroup);
        }

    case DPSYS_ADDPLAYERTOGROUP:
        {
            DPMSG_GROUPADD *msg = (DPMSG_GROUPADD *)pmsg;

            return sys_add_player_to_group (msg->dpIdGroup, msg->dpIdGroup);
        }
        break;

    case DPSYS_DELETEPLAYER:
        {
            DPMSG_DELETEPLAYER *msg = (DPMSG_DELETEPLAYER *)pmsg;

            return sys_delplayer (msg->dpId);
        }
        break;

    case DPSYS_DELETEGROUP:
        {
            DPMSG_DELETEPLAYER *msg = (DPMSG_DELETEPLAYER *)pmsg;

            return sys_delgroup (msg->dpId);
        }
        break;

    case DPSYS_SESSIONLOST:
        {
            // Requested reply was denied
            return sys_no_session ();
        }
        break;
    }

    return 0;
}



//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_newplayer
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::sys_newplayer (DPID id, LPCSTR short_name, LPCSTR long_name)
{
    return 0;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_newgroup
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::sys_newgroup (DPID id, LPCSTR short_name, LPCSTR long_name)
{
    return 0;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_delplayer
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::sys_delplayer (DPID id)
{
    return 0;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_delgroup
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::sys_delgroup (DPID id)
{
    return 0;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_no_session
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::sys_no_session ()
{
    return 0;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_add_player_to_group
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::sys_add_player_to_group (DPID group, DPID player)
{
    return 0;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_remove_player_from_group
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::sys_remove_player_from_group (DPID group, DPID player)
{
    return 0;
}

z
//╟╠╡ End of module - turner.cpp ╡╠╟

