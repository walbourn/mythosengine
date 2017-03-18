//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм
//                               Jb
//                               $$$c
//             $$$$$$$$$$$$$$$$$$$$$$b       d$$$$$$$$$$$$$$$$$$$$$P
//            .$$$$$$$$$$$$$$$$$$$$$$$$.     $$$$$$$$$$$$$$$$$$$$$$
//            ^""""""$$$$$P""""3$$$$$$$$c   d$$$$$""""$$$$$$"""""""
//                  4$$$$$"    $$$$$$$$$$b  $$$$$F   .$$$$$F
//                  $$$$$P    4$$$$$$$$$$$$$$$$$$    d$$$$$
//                 4$$$$$"    $$$$$$$$$$$$$$$$$$P    $$$$$F
//                 $$$$$$    4$$$$$""$$$$$$$$$$$    d$$$$$
//                4$$$$$"    $$$$$$  ^$$$$$$$$$P    $$$$$F
//                $$$$$$    4$$$$$%    *$$$$$$$"   J$$$$$
//               4$$$$$%    $$$$$$      ^$$$$$P    $$$$$F
//               """"""     """"""        *$$$"    """"""
//                                         "$$
//                                          ^%
//
//                         Turner - Networking Library
//
//                    Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
//                        http://www.mythos-engine.org/
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// Created by Dan Higdon and Chuck Walbourn
//
// Turner Network Interface
//
// turnex.cpp
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

//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Code
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  Constructors/Destructors  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - Constructor
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerNetwork::TurnerNetwork (GUID _guid, const char *_name,
                              int _players, DWORD sflags) :
    TurnerClassic(_guid,_name,_players,sflags)
{
}

TurnerNetwork::TurnerNetwork (GUID _guid, const char *_name,
                              int _players, const char *_passwd, DWORD sflags) :
    TurnerClassic(_guid,_name,_players,_passwd,sflags)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - Destructor
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerNetwork::~TurnerNetwork()
{
    close ();
}



//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  Operations  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// static _player_callback
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
static BOOL CALLBACK _player_callback (DPID id,
                                       DWORD dwType,
                                       LPCDPNAME lpcName,
                                       DWORD flags,LPVOID context)
{
    TurnerNetwork  *net = (TurnerNetwork *)context;

    switch (dwType)
    {
        case DPPLAYERTYPE_GROUP:
            net->sys_newgroup (id,
                               lpcName->lpszShortNameA, lpcName->lpszLongNameA,
                               0, 0, 0, flags);
        case DPPLAYERTYPE_PLAYER:
            net->sys_newplayer (id,
                                lpcName->lpszShortNameA, lpcName->lpszLongNameA,
                                0, 0, 0, flags);
    }

    return TRUE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - connect_game
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::connect_game (GUID guidSession)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    session.guidInstance = guidSession;
    int res = pIDP->Open (&session, DPOPEN_JOIN);
    Sleep(100);

    flags &= ~(TURNER_FLAGS_OPEN | TURNER_FLAGS_HOST);

    if (res == DP_OK)
    {
        flags |= TURNER_FLAGS_OPEN;
        pIDP->EnumGroups  (&guidSession, _player_callback, this,
                           DPENUMPLAYERS_REMOTE);
        pIDP->EnumPlayers (&guidSession, _player_callback, this,
                           DPENUMPLAYERS_REMOTE);
        return DP_OK;
    }

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - create_group
//
// Creates a new group ID, given short and long names.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
DPID TurnerNetwork::create_group (const char *short_name,
                                  const char *long_name,
                                  LPVOID data, DWORD size,
                                  DWORD _flags)
{
    if (!pIDP)
        return 0;

    DPID id = 0;

    DPNAME dp_name;
    dp_name.dwSize = sizeof (dp_name);
    dp_name.dwFlags  = 0;
    dp_name.lpszShortNameA = (char *)short_name;
    dp_name.lpszLongNameA  = (char *)long_name;

    pIDP->CreateGroup (&id, &dp_name, data, size, _flags);
    Sleep(500);

    return id;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - destroy_group
//
// Destroys a group by ID
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::destroy_group (DPID group)
{
    if (pIDP)
        pIDP->DestroyGroup (group);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - set_group_name
//
// Sets a given group's name
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::set_group_name(DPID group,
                                  const char *short_name, const char *long_name,
                                  DWORD _flags)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    DPNAME dp_name;
    dp_name.dwSize = sizeof (dp_name);
    dp_name.dwFlags  = 0;
    dp_name.lpszShortNameA = (char *)short_name;
    dp_name.lpszLongNameA  = (char *)long_name;

    return pIDP->SetGroupName(group, &dp_name, _flags);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - set_group_data
//
// Sets a given group's data
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::set_group_data(DPID group, LPVOID data,
                                  DWORD size, DWORD _flags)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    return pIDP->SetGroupData(group, data, size, _flags);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - set_group_owner
//
// Sets a given group's owner
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::set_group_owner(DPID group, DPID owner)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    return pIDP->SetGroupOwner(group, owner);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - join_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::join_group  (DPID group, DPID player)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!player)
        player = playerid;

    return pIDP->AddPlayerToGroup (group, player);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - leave_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::leave_group (DPID group, DPID player)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!player)
        player = playerid;

    return pIDP->DeletePlayerFromGroup (group, player);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - add_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::add_group (DPID pgroup, DPID group)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    return pIDP->AddGroupToGroup (pgroup, group);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - remove_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::remove_group (DPID pgroup, DPID group)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    return pIDP->DeleteGroupFromGroup (pgroup, group);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - send_ex
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::send_ex (DPID from, DPID to, LPVOID data, DWORD size,
                            DWORD priority, DWORD timeout,
                            LPVOID context, LPDWORD msgid)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!from)
        from = playerid;

    int res = pIDP->SendEx (from, to, sendfl, data, size,
                            priority, timeout, context, msgid);
    Sleep(0);

    return res;
}

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - send_guaranteed_ex
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::send_guaranteed_ex (DPID from, DPID to,
                                       LPVOID data, DWORD size,
                                       DWORD priority, DWORD timeout,
                                       LPVOID context, LPDWORD msgid)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!from)
        from = playerid;

    int res = pIDP->SendEx (from, to, sendfl | DPSEND_GUARANTEED, data, size,
                            priority, timeout, context, msgid);
    Sleep(0);

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - broadcast_ex
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::broadcast_ex (DPID from, LPVOID data, DWORD size,
                                 DWORD priority, DWORD timeout,
                                 LPVOID context, LPDWORD msgid)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!from)
        from = playerid;

    int res = pIDP->SendEx (from, DPID_ALLPLAYERS, sendfl, data, size,
                            priority, timeout, context, msgid);
    Sleep(0);

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - broadcast_guaranteed_ex
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetwork::broadcast_guaranteed_ex (DPID from, LPVOID data, DWORD size,
                                            DWORD priority, DWORD timeout,
                                            LPVOID context, LPDWORD msgid)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!from)
        from = playerid;

    int res = pIDP->SendEx (from, DPID_ALLPLAYERS, sendfl | DPSEND_GUARANTEED,
                            data, size, priority, timeout, context, msgid);
    Sleep(0);

    return res;
}



//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  System Message Process Routines  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - handle_sysmsg
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::handle_sysmsg (DPID to, DPMSG_GENERIC *pmsg, DWORD size)
{
    assertMyth("TurnerNetwork::handle_sysmsg needs valid input", pmsg != 0);

    switch (pmsg->dwType)
    {
        case DPSYS_CREATEPLAYERORGROUP:
            {
                DPMSG_CREATEPLAYERORGROUP *msg = (DPMSG_CREATEPLAYERORGROUP *)pmsg;
                switch (msg->dwPlayerType)
                {
                    case DPPLAYERTYPE_PLAYER:
                        sys_newplayer (msg->dpId,
                                       msg->dpnName.lpszShortNameA,
                                       msg->dpnName.lpszLongNameA,
                                       msg->lpData, msg->dwDataSize,
                                       msg->dpIdParent, msg->dwFlags);
                        break;
                    case DPPLAYERTYPE_GROUP:
                        sys_newgroup  (msg->dpId,
                                       msg->dpnName.lpszShortNameA,
                                       msg->dpnName.lpszLongNameA,
                                       msg->lpData, msg->dwDataSize,
                                       msg->dpIdParent, msg->dwFlags);
                        break;
                }
            }
            break;

        case DPSYS_DESTROYPLAYERORGROUP:
            {
                DPMSG_DESTROYPLAYERORGROUP *msg = (DPMSG_DESTROYPLAYERORGROUP *)pmsg;
                switch (msg->dwPlayerType)
                {
                    case DPPLAYERTYPE_PLAYER:
                        sys_delplayer (msg->dpId,msg->dwFlags);
                        break;
                    case DPPLAYERTYPE_GROUP:
                        sys_delgroup (msg->dpId,msg->dwFlags);
                        break;
                }
            }
            break;

        case DPSYS_SETPLAYERORGROUPNAME:
            {
                DPMSG_SETPLAYERORGROUPNAME *msg = (DPMSG_SETPLAYERORGROUPNAME *)pmsg;
                switch (msg->dwPlayerType)
                {
                    case DPPLAYERTYPE_PLAYER:
                        sys_set_player_name(msg->dpId,
                                            msg->dpnName.lpszShortNameA,
                                            msg->dpnName.lpszLongNameA);
                        break;
                    case DPPLAYERTYPE_GROUP:
                        sys_set_group_name(msg->dpId,
                                           msg->dpnName.lpszShortNameA,
                                           msg->dpnName.lpszLongNameA);
                        break;
                }
            }
            break;

        case DPSYS_SETPLAYERORGROUPDATA:
            {
                DPMSG_SETPLAYERORGROUPDATA *msg = (DPMSG_SETPLAYERORGROUPDATA *)pmsg;
                switch (msg->dwPlayerType)
                {
                    case DPPLAYERTYPE_PLAYER:
                        sys_set_player_data(msg->dpId,
                                            msg->lpData, msg->dwDataSize);
                        break;
                    case DPPLAYERTYPE_GROUP:
                        sys_set_group_data(msg->dpId,
                                           msg->lpData, msg->dwDataSize);
                        break;
                }
            }
            break;

        case DPSYS_SETGROUPOWNER:
            {
                DPMSG_SETGROUPOWNER *msg = (DPMSG_SETGROUPOWNER*)pmsg;
                sys_set_group_owner(msg->idGroup, msg->idNewOwner,
                                    msg->idOldOwner);
            }
            break;

        case DPSYS_ADDPLAYERTOGROUP:
            {
                DPMSG_ADDPLAYERTOGROUP *msg = (DPMSG_ADDPLAYERTOGROUP *)pmsg;
                sys_add_player_to_group (msg->dpIdGroup, msg->dpIdPlayer);
            }
            break;

        case DPSYS_DELETEPLAYERFROMGRP:
            {
                DPMSG_ADDPLAYERTOGROUP *msg = (DPMSG_ADDPLAYERTOGROUP *)pmsg;
                sys_remove_player_from_group (msg->dpIdGroup,
                                              msg->dpIdPlayer);
            }
            break;

        case DPSYS_ADDGROUPTOGROUP:
            {
                DPMSG_ADDGROUPTOGROUP *msg = (DPMSG_ADDGROUPTOGROUP *)pmsg;
                sys_add_group_to_group (msg->dpIdParentGroup,
                                        msg->dpIdGroup);
            }
            break;

        case DPSYS_DELETEGROUPFROMGROUP:
            {
                DPMSG_ADDGROUPTOGROUP *msg = (DPMSG_ADDGROUPTOGROUP *)pmsg;
                sys_remove_group_from_group (msg->dpIdParentGroup,
                                             msg->dpIdGroup);
            }
            break;

        case DPSYS_SENDCOMPLETE:
            {
                DPMSG_SENDCOMPLETE *msg = (DPMSG_SENDCOMPLETE*)pmsg;
                sys_send_complete(msg->idFrom, msg->idTo,
                                  msg->lpvContext, msg->dwMsgID,
                                  msg->dwSendTime);
            }
            break;

        default:
            TurnerClassic::handle_sysmsg(to,pmsg,size);
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_newgroup
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_newgroup (DPID group,
                                  LPCSTR short_name, LPCSTR long_name,
                                  LPVOID data, DWORD size, DPID pgroup,
                                 DWORD _flags)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_delgroup
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_delgroup (DPID group, DWORD _flags)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_set_group_name
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_set_group_name (DPID group, LPCSTR short_name, LPCSTR long_name)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_set_group_data
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_set_group_data(DPID group, LPVOID data, DWORD size)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_set_group_owner
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_set_group_owner(DPID group, DPID newowner, DPID oldowner)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_add_player_to_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_add_player_to_group (DPID group, DPID player)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_remove_player_from_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_remove_player_from_group (DPID group, DPID player)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_add_group_to_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_add_group_to_group (DPID parent, DPID group)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_remove_group_from_group
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_remove_group_from_group (DPID parent, DPID group)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetwork - sys_send_complete
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerNetwork::sys_send_complete (DPID from, DPID to,
                                       LPVOID context, DWORD msgid,
                                       DWORD sendtime)
{
}



//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  Utility Routines  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//╟╠╡ End of module - turnex.cpp ╡╠╟
