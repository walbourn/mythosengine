//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм
//
//                           Turner - Networking
//
//            Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
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
    is_opened (FALSE),
    hMessageEvent (NULL),
    pIDP (0)
{
    // Fill in the common fields of the session descriptor.
    memset (&session, 0, sizeof (session));
    session.dwSize      = sizeof (session);
    session.dwFlags     = DPSESSION_KEEPALIVE;
    session.guidInstance    = GUID_NULL;
    session.guidApplication = _guid;
    session.dwMaxPlayers= _players;
    session.lpszSessionNameA = szSessionName;
    strcpy (szSessionName, _name);
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
    close ();
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - packet_ready
//  returns whether or not a packet is available for the current player.
//  It is more efficient to check with this method than to call Recieve
//  and check for an error condition.
//
//  This method will always return FALSE if a message event was not
//  created during game create/connect.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL TurnerNetwork::packet_ready ()
{
    return hMessageEvent == NULL
           || WaitForSingleObject (&hMessageEvent, 0) != WAIT_TIMEOUT;
}



//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - select_provider
//  Create a DirectPlay interface to the specified DP provider.
//  (Usually this value will be selected by the UI)
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::select_provider (LPGUID provider_guid)
{
    IDirectPlay *pIDP1;
    int res;
    if ((res = DirectPlayCreate (provider_guid, &pIDP1, NULL)) == DP_OK)
    {
        pIDP1->QueryInterface (IID_IDirectPlay2A, (LPVOID *)&pIDP);
        pIDP1->Release();
    }

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - create_game
//  Create a new game of the type specified during construction.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::create_game (BOOL bCreateEvent)
{
    if (pIDP == 0)
        return DPERR_UNAVAILABLE;

    HRESULT res = pIDP->Open (&session,DPOPEN_CREATE);
    Sleep(100);

    is_opened = (res == DP_OK);

#if 0
    // Allow for an event to signal packet arrival (more efficient, but possibly undesirable)
    if (bCreateEvent)
    {
        hMessageEvent = CreateEvent (NULL, FALSE, FALSE, NULL);
        if (hMessageEvent == NULL)
            return -1;
    }
#endif

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - create_player
//  Creates a new player ID, given short and long names.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
DPID TurnerNetwork::create_player (const char *short_name, const char *long_name)
{
    if (pIDP == 0)
        return 0;

    DPID id = 0;

    DPNAME dp_name;
    dp_name.dwSize = sizeof (dp_name);
    dp_name.dwFlags  = 0;
    dp_name.lpszShortNameA = (char *)short_name;
    dp_name.lpszLongNameA  = (char *)long_name;

    pIDP->CreatePlayer (&id, &dp_name, hMessageEvent, 0, 0, 0);
    Sleep(500);

    return id;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - destroy_player
//  Creates a new player ID, given short and long names.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::destroy_player (DPID id)
{
    if (pIDP != 0)
        pIDP->DestroyPlayer (id);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - create_group
//  Creates a new group ID, given short and long names.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
DPID TurnerNetwork::create_group (const char *short_name, const char *long_name)
{
    if (pIDP == 0)
        return 0;

    DPID id = 0;

    DPNAME dp_name;
    dp_name.dwSize = sizeof (dp_name);
    dp_name.dwFlags  = 0;
    dp_name.lpszShortNameA = (char *)short_name;
    dp_name.lpszLongNameA  = (char *)long_name;
    pIDP->CreateGroup (&id, &dp_name, 0, 0, 0);

    return id;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - destroy_group
//  Creates a new group ID, given short and long names.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::destroy_group (DPID id)
{
    if (pIDP != 0)
        pIDP->DestroyGroup (id);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - static _player_callback
//  This is the enumeration function for TurnerNetwork::connect_game
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK _player_callback (DPID id, DWORD dwType, LPCDPNAME lpcName, DWORD flags, LPVOID context)
{
    // Add the player to the internal list of players
    TurnerNetwork  *net = (TurnerNetwork *)context;

    if (dwType == DPPLAYERTYPE_GROUP)
        net->sys_newgroup (id, lpcName->lpszShortNameA, lpcName->lpszLongNameA);
    else
        net->sys_newplayer (id, lpcName->lpszShortNameA, lpcName->lpszLongNameA);

    return TRUE;
}

#if 0
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - static _group_callback
//  This is the enumeration function for TurnerNetwork::connect_game
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK _group_callback (DPID id, char *short_name, char *long_name, DWORD flags, LPVOID context)
{
    // Add the player to the internal list of players
    TurnerNetwork  *net = (TurnerNetwork *)context;

    net->sys_newgroup (id, short_name, long_name);

    return TRUE;
}
#endif


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - connect_game
//  Open a connection to the specified session of the
//  game specified during construction.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::connect_game (GUID guidSession, BOOL bCreateEvent)
{
    if (pIDP == 0)
        return DPERR_UNAVAILABLE;

    // Fill in the rest of the session flags
    session.guidInstance = guidSession;
    HRESULT res = pIDP->Open (&session, DPOPEN_JOIN);
    Sleep(100);

    is_opened = (res == DP_OK);

    // Allow for an event to signal packet arrival (more efficient, but possibly undesirable)
#if 0
    if (bCreateEvent)
    {
        hMessageEvent = CreateEvent (NULL, FALSE, FALSE, NULL);
        if (hMessageEvent == NULL)
            return -1;
    }
#endif

    // Populate our existing group and player tables
    if (res == DP_OK)
    {
        pIDP->EnumGroups  (&guidSession, _player_callback, this, DPENUMPLAYERS_REMOTE);
        pIDP->EnumPlayers (&guidSession, _player_callback, this, DPENUMPLAYERS_REMOTE);
    }

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - join_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::join_group  (DPID group, DPID player)
{
    if (pIDP == 0)
        return DPERR_UNAVAILABLE;

    return pIDP->AddPlayerToGroup (group, player);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - leave_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::leave_group (DPID group, DPID player)
{
    if (pIDP == 0)
        return DPERR_UNAVAILABLE;

    return pIDP->DeletePlayerFromGroup (group, player);
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

    if (hMessageEvent)
    {
        CloseHandle (hMessageEvent);
        hMessageEvent = NULL;
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - receive
//  get and process the next packet in the queue.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::receive (void *ptr, size_t sz)
{
    if (pIDP == 0)
        return DPERR_UNAVAILABLE;

    DPID    from;
    DPID    to;
    HRESULT res;

    // If there is an event handle, use it instead of relying on Receive()
    // (This is supposedly more efficient)
    Sleep(0);
    if (!packet_ready ())
        return DPERR_NOMESSAGES;

    res = pIDP->Receive (&from, &to,
                         DPRECEIVE_ALL,
                         ptr, (LPDWORD)&sz);

    switch (res)
    {
    case DPERR_NOMESSAGES:
        // This is just fine, but unlikely if you have a message event defined
        break;

    case DP_OK:
        // Yaaay!  We got a message
        if (from == 0)
            handle_sysmsg ((DPMSG_GENERIC *)ptr, sz);
        else
            handle_msg (from, to, ptr, sz);
        break;
    }

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - send
//  Send a packet to the specified player (from a specified player)
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::send (DPID player, DPID dest, void *ptr, size_t sz)
{
    if (pIDP == 0)
        return DPERR_UNAVAILABLE;

    int res = pIDP->Send (player, dest, 0, ptr, sz);
    Sleep(0);

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - broadcast
//  Broadcast a packet to all players from a specified player.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::broadcast (DPID player, void *ptr, size_t sz)
{
    if (pIDP == 0)
        return DPERR_UNAVAILABLE;

    int res = pIDP->Send (player, 0, 0, ptr, sz);
    Sleep(0);

    return res;
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
    case DPSYS_CREATEPLAYERORGROUP:
        {
            DPMSG_CREATEPLAYERORGROUP *msg = (DPMSG_CREATEPLAYERORGROUP *)pmsg;

            if (msg->dwPlayerType == DPPLAYERTYPE_PLAYER)
                return sys_newplayer (msg->dpId, msg->dpnName.lpszShortNameA,
												 msg->dpnName.lpszLongNameA);
            else
                return sys_newgroup  (msg->dpId, msg->dpnName.lpszShortNameA,
												 msg->dpnName.lpszLongNameA);
        }
        break;

    case DPSYS_DELETEPLAYERFROMGRP:
        {
            DPMSG_ADDPLAYERTOGROUP *msg = (DPMSG_ADDPLAYERTOGROUP *)pmsg;

            return sys_remove_player_from_group (msg->dpIdGroup, msg->dpIdGroup);
        }

    case DPSYS_ADDPLAYERTOGROUP:
        {
            DPMSG_ADDPLAYERTOGROUP *msg = (DPMSG_ADDPLAYERTOGROUP *)pmsg;

            return sys_add_player_to_group (msg->dpIdGroup, msg->dpIdGroup);
        }
        break;

    case DPSYS_DESTROYPLAYERORGROUP:
        {
            DPMSG_DESTROYPLAYERORGROUP *msg = (DPMSG_DESTROYPLAYERORGROUP *)pmsg;

            if (msg->dwPlayerType == DPPLAYERTYPE_PLAYER)
	            return sys_delplayer (msg->dpId);
			else
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

//╟╠╡ End of module - turner.cpp ╡╠╟

