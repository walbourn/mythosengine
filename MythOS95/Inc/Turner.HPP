//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                           Turner - Networking
//
//            Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
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
// Turner Network Communications
//
// turner.hpp
//
//  This module implements an abstraction for DirectPlay's networking
//  interface.  DirectPlay allows transport-independant network communications
//  for Win95 apps.  This abstraction layer will permit the application
//  to connect any number of players together and exchange messages
//  between them.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __TURNER_HPP
#define __TURNER_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <portable.h>
#include <dplay.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Pragmas
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

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
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TurnerNetwork
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ


#define IDC_MAXNETWORK_LIST1           100
#define IDC_MAXNETWORK_CREATE          100
#define IDC_MAXNETWORK_CONNECT         101

#define IDD_MAXNETWORK_REMCONNABORTDLG 1
#define IDD_MAXNETWORK_CHOOSEPROVIDER  2
#define IDD_MAXNETWORK_SELSESSION      3
#define IDD_MAXNETWORK_Q_CREATE        4


class TurnerNetwork
{
protected:
        BOOL    is_opened;
        HANDLE  hMessageEvent;

        char    szSessionName[64];

public:
        // DirectPlay objects
        IDirectPlay2A   *pIDP;
        DPSESSIONDESC2  session;

        BOOL            is_creator()    { return session.dwFlags == DPOPEN_CREATESESSION; }

private:
        // Hide this constructor so that others cannot copy this
        TurnerNetwork (const TurnerNetwork &m);

        // Copying, hidden for the same reason as the constructor
        TurnerNetwork &operator = (const TurnerNetwork &m);

public:
        // Constructor
        TurnerNetwork (GUID _guid, const char *_name, int _players);

        // Destructor
virtual ~TurnerNetwork();

        // Information
        BOOL    is_active () const { return pIDP != 0 && is_opened; }
        BOOL    is_valid ()  const { return pIDP != 0; }
        BOOL    packet_ready ();    // not const because of DP restriction.

        // Initialize and connect to the game
virtual int     select_provider (LPGUID);
virtual int     create_game (BOOL bCreateEvent = TRUE);
virtual int     connect_game (GUID, BOOL bCreateEvent = TRUE);

virtual DPID    create_player (const char *, const char *);
virtual void    destroy_player (DPID);
virtual DPID    create_group (const char *, const char *);
virtual void    destroy_group (DPID);
virtual int     join_group  (DPID group, DPID player);
virtual int     leave_group (DPID group, DPID player);


        // Handle communication tasks.
virtual void    close   ();
virtual int     receive (void *, size_t);
virtual int     send    (DPID, DPID, void *, size_t);
virtual int     broadcast (DPID, void *, size_t);

virtual int     handle_msg (DPID, DPID, void *, size_t);
virtual int     handle_sysmsg (DPMSG_GENERIC *, size_t);

virtual int     sys_newplayer (DPID, LPCSTR, LPCSTR);
virtual int     sys_newgroup  (DPID, LPCSTR, LPCSTR);
virtual int     sys_delplayer (DPID);
virtual int     sys_delgroup  (DPID);
virtual int     sys_add_player_to_group (DPID, DPID);
virtual int     sys_remove_player_from_group (DPID, DPID);
virtual int     sys_no_session  ();
};



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  TurnerNetworkUI
//
//  This class provides a user interface to initialize and manage
//  a TurnerNetwork object
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class TurnerNetworkUI
{
private:
static  TurnerNetworkUI *g_this;

        TurnerNetwork   *net;
        HWND            hWnd;
        HWND            hDlg;

        int             max_sessions;
        int             current_session;
        GUID            *sessions;

public:
        TurnerNetworkUI  (HWND, TurnerNetwork *, int _max_sessions = 32);
        ~TurnerNetworkUI ();

        // Perform the complete connection/initialization of the net object.
        int  connect ();

        // Select a provider
        int  get_provider ();
static  BOOL CALLBACK DlgProcChooseProvider (HWND, UINT, WPARAM, LPARAM);
static  BOOL CALLBACK EnumSP (LPGUID, LPSTR, DWORD, DWORD, LPVOID);

        // Query, create or join?
        int  create_or_join ();
static  BOOL CALLBACK DlgProcQCreate (HWND, UINT, WPARAM, LPARAM);

        // Select a session
        int  select_session ();
static  BOOL CALLBACK EnumSession (LPCDPSESSIONDESC2, LPDWORD, DWORD, LPVOID);
static  BOOL CALLBACK DlgProcSelSession (HWND, UINT, WPARAM, LPARAM);


};


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - turner.hpp ²±°

