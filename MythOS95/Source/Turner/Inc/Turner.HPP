//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
// Created by Dan Higdon and Chuck Walbourn
//
// Turner Network Communications
//
// turner.hpp
//
//  This module implements an abstraction for DirectPlay's networking
//  interface (currently DirectX Version 6's DirectPlay4).  DirectPlay
//  allows transport-independant network communications for Win95 apps.
//  This abstraction layer will permit the application to connect any
//  number of players together and exchange messages between them.
//
//  TurnerClassic - Base network functionality for sending/receiving messages
//                  and handling creating/joining sessions.
//
//  TurnerNetwork - Extends TurnerClassic to include the group functionality
//                  and the advanced send options.
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
#include <dplobby.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄ State flags for Turner Network
#define TURNER_FLAGS_OPEN               0x1
#define TURNER_FLAGS_HOST               0x2

#define TURNER_FLAGS_APP0               0x1000000
#define TURNER_FLAGS_APP1               0x2000000
#define TURNER_FLAGS_APP2               0x4000000
#define TURNER_FLAGS_APP3               0x8000000
#define TURNER_FLAGS_APP4               0x10000000
#define TURNER_FLAGS_APP5               0x20000000
#define TURNER_FLAGS_APP6               0x40000000
#define TURNER_FLAGS_APP7               0x80000000

//ÄÄÄ Turner provider defines
typedef enum _turner_provider
{
    TURNER_PROVIDER_IPX                 =0,
    TURNER_PROVIDER_TCPIP               =1,
    TURNER_PROVIDER_MODEM               =2,
    TURNER_PROVIDER_SERIAL              =3
} turner_provider;

//ÄÄÄ Misc defines
#define TURNER_DPSESSION_FLAGS          (DPSESSION_KEEPALIVE | DPSESSION_DIRECTPLAYPROTOCOL | DPSESSION_OPTIMIZELATENCY)
#define TURNER_MAX_NAME                 64
#define TURNER_MAX_PASSWD               64
#define TURNER_INIT_BUFFER              1024
#define TURNER_MAX_BUFFER               65535

//ÄÄÄ Resources for UI class
#define IDC_MAXNETWORK_LIST1            100
#define IDC_MAXNETWORK_CREATE           100
#define IDC_MAXNETWORK_CONNECT          101

#define IDD_MAXNETWORK_REMCONNABORTDLG  1
#define IDD_MAXNETWORK_CHOOSEPROVIDER   2
#define IDD_MAXNETWORK_SELSESSION       3
#define IDD_MAXNETWORK_Q_CREATE         4

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TurnerClassic
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class TurnerClassic
{
protected:
    void            *rbuffer;
    dword           rbsize;

    static BOOL CALLBACK enum_serviceprovider (LPGUID, LPSTR, DWORD, DWORD, LPVOID);
    static BOOL CALLBACK enum_sessions (LPCDPSESSIONDESC2, LPDWORD, DWORD, LPVOID);

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    dword           flags;                          // State flags
    DWORD           sendfl;                         // Send flags
    IDirectPlay4A   *pIDP;                          // DirectPlay interface
    DPID            playerid;                       // Local player ID
    DPSESSIONDESC2  session;                        // Session description
    char            sessionName[TURNER_MAX_NAME];   // Session name
    char            password[TURNER_MAX_PASSWD];    // Password

private:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    TurnerClassic (const TurnerClassic &m);
    TurnerClassic &operator = (const TurnerClassic &m);

public:
    TurnerClassic (GUID _guid, const char *_name, int _players,
                   DWORD sflags=TURNER_DPSESSION_FLAGS);
    TurnerClassic (GUID _guid, const char *_name, int _players,
                   const char *_passwd, DWORD sflags=TURNER_DPSESSION_FLAGS);
    virtual ~TurnerClassic();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual int select_provider (LPGUID guid);
    virtual int select_provider (LPVOID address);
    virtual int select_provider (turner_provider provider, LPVOID data=0);

    virtual void close ();

    virtual int create_game ();
    virtual int connect_game (GUID guid);

    virtual int set_session_desc(DPSESSIONDESC2 &desc);

    virtual DPID create_player (const char *short_name, const char *long_name,
                                LPVOID data=0, DWORD size=0, DWORD _flags=0);
    virtual void destroy_player (DPID player);
    virtual int set_player_name(DPID player,
                                const char *short_name, const char *long_name,
                                DWORD _flags=0);
    virtual int set_player_data(DPID player, LPVOID data,
                                DWORD size, DWORD _flags=0);

    virtual int receive ();
    virtual int receive_all (DWORD timeout=0);

    virtual int send (DPID from, DPID to, LPVOID data, DWORD size);
    virtual int send_guaranteed (DPID from, DPID to, LPVOID data, DWORD size);

    virtual int broadcast (DPID from, LPVOID data, DWORD size);
    virtual int broadcast_guaranteed (DPID from, LPVOID data, DWORD size);

    virtual int send_chat (DPID from, DPID to, char *msg, DWORD _flags=0);
    virtual int broadcast_chat (DPID from, char *msg, DWORD _flags=0);

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Application message process function                                 ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void handle_msg (DPID from, DPID to, LPVOID ptr, DWORD size)=0;
    virtual void handle_chat (DPID fromplayer, DPID toplayer, DPID togroup, LPSTR msg)=0;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // System message process function(s)                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void handle_sysmsg (DPID to, DPMSG_GENERIC *msg, DWORD size);

    virtual void sys_set_session_desc(DPSESSIONDESC2 &desc);
    virtual void sys_host ();
    virtual void sys_no_session ();

    virtual void sys_newplayer (DPID player, LPCSTR short_name, LPCSTR long_name,
                               LPVOID data, DWORD size, DPID pgroup, DWORD _flags);
    virtual void sys_delplayer (DPID player, DWORD _flags);
    virtual void sys_set_player_name (DPID player, LPCSTR short_name, LPCSTR long_name);
    virtual void sys_set_player_data (DPID player, LPVOID data, DWORD size);

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Enumeration functions                                                ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void enum_providers();
    virtual void enum_sessions(DWORD timeout=5000);

    virtual int handle_enum_provider(LPGUID _guid, LPSTR _desc,
                                     DWORD _majver, DWORD _minver);
    virtual int handle_enum_session(LPCDPSESSIONDESC2 _session,
                                    LPDWORD _timeout,
                                    DWORD _flags);

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    int is_host() const  { return (flags & TURNER_FLAGS_HOST); }
    int is_active () const { return pIDP != 0 && (flags & TURNER_FLAGS_OPEN); }
    int is_valid ()  const { return pIDP != 0; }

    void set_flags(dword f) { flags=f; }

    void set_async(BOOL on)
    {
        if (on)
            sendfl |= DPSEND_ASYNC;
        else
            sendfl &= ~DPSEND_ASYNC;
    }
    void set_sendcomplete(BOOL on)
    {
        if (on)
            sendfl &= ~DPSEND_NOSENDCOMPLETEMSG;
        else
            sendfl |= DPSEND_NOSENDCOMPLETEMSG;
    }

    void set_player_id(DPID id) { playerid = id; }

    int set_max_players(int _players)
    {
        DPSESSIONDESC2 desc = session;

        desc.dwMaxPlayers = _players;

        return set_session_desc(desc);
    }
    int set_user(DWORD user1, DWORD user2, DWORD user3, DWORD user4)
    {
        DPSESSIONDESC2 desc = session;

        desc.dwUser1 = user1;
        desc.dwUser2 = user2;
        desc.dwUser3 = user3;
        desc.dwUser4 = user4;

        return set_session_desc(desc);
    }
    int set_session_name(char *_name)
    {
        DPSESSIONDESC2 desc = session;

        desc.lpszSessionNameA = _name;

        return set_session_desc(desc);
    }
    int set_password(char *_passwd)
    {
        DPSESSIONDESC2 desc = session;

        desc.lpszPasswordA = _passwd;

        return set_session_desc(desc);
    }

    int get_caps(LPDPCAPS caps, DWORD _flags=0);
    int get_player_caps(DPID player, LPDPCAPS caps, DWORD _flags=0);

    int get_send_message_queue(DPID from, DPID to, LPDWORD nmsgs, LPDWORD nbytes);
    int get_receive_message_queue(DPID from, DPID to, LPDWORD nmsgs, LPDWORD nbytes);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TurnerNetwork
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class TurnerNetwork : public TurnerClassic
{
private:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    TurnerNetwork (const TurnerNetwork &m);
    TurnerNetwork &operator = (const TurnerNetwork &m);

public:
    TurnerNetwork (GUID _guid, const char *_name, int _players,
                   DWORD sflags=TURNER_DPSESSION_FLAGS);
    TurnerNetwork (GUID _guid, const char *_name, int _players,
                   const char *_passwd, DWORD sflags=TURNER_DPSESSION_FLAGS);
    virtual ~TurnerNetwork();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual int connect_game (GUID guid);

    virtual DPID create_group (const char *short_name, const char *long_name,
                               LPVOID data=0, DWORD size=0, DWORD _flags=0);
    virtual void destroy_group (DPID group);
    virtual int set_group_name(DPID group,
                               const char *short_name, const char *long_name,
                               DWORD _flags=0);
    virtual int set_group_data(DPID group, LPVOID data,
                               DWORD size, DWORD _flags=0);
    virtual int set_group_owner(DPID group, DPID owner);

    virtual int join_group  (DPID group, DPID player);
    virtual int leave_group (DPID group, DPID player);

    virtual int add_group (DPID pgroup, DPID group);
    virtual int remove_group (DPID pgroup, DPID group);

    virtual int send_ex (DPID from, DPID to, LPVOID data, DWORD size,
                         DWORD priority, DWORD timeout,
                         LPVOID context=0, LPDWORD msgid=0);
    virtual int send_guaranteed_ex (DPID from, DPID to, LPVOID data, DWORD size,
                                    DWORD priority, DWORD timeout,
                                    LPVOID context=0, LPDWORD msgid=0);

    virtual int broadcast_ex (DPID from, LPVOID data, DWORD size,
                              DWORD priority, DWORD timeout, LPVOID context=0,
                              LPDWORD msgid=0);
    virtual int broadcast_guaranteed_ex (DPID from, LPVOID data, DWORD size,
                                         DWORD priority, DWORD timeout,
                                         LPVOID context=0, LPDWORD msgid=0);

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // System message process function(s)                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void handle_sysmsg (DPID to, DPMSG_GENERIC *msg, DWORD size);

    virtual void sys_newgroup  (DPID group, LPCSTR short_name, LPCSTR long_name,
                               LPVOID data, DWORD size,  DPID pgroup, DWORD _flags);
    virtual void sys_delgroup  (DPID group, DWORD _flags);
    virtual void sys_set_group_name (DPID group, LPCSTR short_name, LPCSTR long_name);
    virtual void sys_set_group_data (DPID group, LPVOID data, DWORD size);
    virtual void sys_set_group_owner (DPID group, DPID newowner, DPID oldowner);

    virtual void sys_add_player_to_group (DPID group, DPID player);
    virtual void sys_remove_player_from_group (DPID group, DPID player);
    virtual void sys_add_group_to_group (DPID parent, DPID group);
    virtual void sys_remove_group_from_group (DPID parent, DPID group);

    virtual void sys_send_complete (DPID from, DPID to,
                                   LPVOID context, DWORD msgid, DWORD sendtime);
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
protected:
    static  TurnerNetworkUI *g_this;

    TurnerClassic   *net;
    HWND            hWnd;
    HWND            hDlg;

    int             max_sessions;
    int             current_session;
    GUID            *sessions;
    dword           timeout;

    static BOOL CALLBACK dlg_chooseprovider (HWND, UINT, WPARAM, LPARAM);
    static BOOL CALLBACK enum_serviceprovider (LPGUID, LPSTR, DWORD, DWORD, LPVOID);

    static BOOL CALLBACK dlg_qcreate (HWND, UINT, WPARAM, LPARAM);

    static BOOL CALLBACK dlg_selectsession (HWND, UINT, WPARAM, LPARAM);
    static BOOL CALLBACK enum_sessions (LPCDPSESSIONDESC2, LPDWORD, DWORD, LPVOID);

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    TurnerNetworkUI  (HWND hwnd, TurnerClassic *net, int _max_sessions = 32,
                      dword _timeout = 5000);
    ~TurnerNetworkUI ();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual int connect ();

    virtual int get_provider ();
    virtual int create_or_join ();
    virtual int select_session ();
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - turner.hpp ²±°
