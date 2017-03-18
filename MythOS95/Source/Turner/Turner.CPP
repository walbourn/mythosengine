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
// Turner Classic interface
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

//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Data
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠

int TurnerCOMInit;

//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Code
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  Constructors/Destructors  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - Constructor
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerClassic::TurnerClassic (GUID _guid, const char *_name,
                              int _players, DWORD sflags) :
    rbuffer(0),
    flags(0),
    sendfl(0),
    pIDP (0),
    playerid (0)
{
    memset (&session, 0, sizeof (session));
    session.dwSize              = sizeof (session);
    session.dwFlags             = sflags;
    session.guidInstance        = GUID_NULL;
    session.guidApplication     = _guid;
    session.dwMaxPlayers        = _players;
    session.lpszSessionNameA    = sessionName;

    *sessionName = 0;
    *password = 0;
    if (_name)
        strncpy (sessionName, _name, sizeof(sessionName));
}

TurnerClassic::TurnerClassic (GUID _guid, const char *_name,
                              int _players, const char *_passwd,
                              DWORD sflags) :
    rbuffer(0),
    flags(0),
    sendfl(0),
    pIDP (0),
    playerid (0)
{
    memset (&session, 0, sizeof (session));
    session.dwSize              = sizeof (session);
    session.dwFlags             = sflags;
    session.guidInstance        = GUID_NULL;
    session.guidApplication     = _guid;
    session.dwMaxPlayers        = _players;
    session.lpszSessionNameA    = sessionName;
    session.lpszPasswordA       = password;

    *sessionName = 0;
    *password = 0;
    if (_name)
        strncpy (sessionName, _name, sizeof(sessionName));
    if (_passwd)
        strncpy (password, _passwd, sizeof(password));
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - Destructor
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerClassic::~TurnerClassic()
{
    close ();
}



//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  Operations  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - select_provider
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::select_provider (LPGUID guid)
{
    close();

//ддд Initialize COM
    if (!TurnerCOMInit)
    {
        CoInitialize(NULL);
        TurnerCOMInit=1;
    }

//ддд Create an address from the guid
    IDirectPlayLobbyA   *lobby;
    char                address[128];
    DWORD               adsize = sizeof(address);

    int res = DirectPlayLobbyCreate( NULL, &lobby, NULL, NULL, 0 );
    if (FAILED(res))
        return res;

    res = lobby->CreateAddress( *guid, DPAID_ServiceProvider,
                                NULL, 0, address, &adsize );

    lobby->Release();

    if (FAILED(res))
        return res;

//ддд Connect to DirectPlay
    res = CoCreateInstance(CLSID_DirectPlay,
                           NULL,
                           CLSCTX_INPROC_SERVER,
                           IID_IDirectPlay4A,
                           (void **) &pIDP);

    if (FAILED(res))
    {
        pIDP=0;
        return res;
    }


    res = pIDP->InitializeConnection(address, 0);
    if (FAILED(res))
    {
        pIDP->Release();
        pIDP = 0;
    }

    return res;
}

int TurnerClassic::select_provider (LPVOID address)
{
    close();

//ддд Initialize COM
    if (!TurnerCOMInit)
    {
        CoInitialize(NULL);
        TurnerCOMInit=1;
    }

//ддд Connect to DirectPlay
    int res = CoCreateInstance(CLSID_DirectPlay,
                               NULL,
                               CLSCTX_INPROC_SERVER,
                               IID_IDirectPlay4A,
                               (void **) &pIDP);

    if (FAILED(res))
    {
        pIDP=0;
        return res;
    }

    res = pIDP->InitializeConnection(address, 0);
    if (FAILED(res))
    {
        pIDP->Release();
        pIDP = 0;
    }

    return res;
}

int TurnerClassic::select_provider (turner_provider provider, LPVOID data)
{
    close();

    IDirectPlayLobbyA   *lobby;
    DWORD               size;
    char                address[128];
    DWORD               adsize = sizeof(address);

    int res = DirectPlayLobbyCreate( NULL, &lobby, NULL, NULL, 0 );
    if (FAILED(res))
        return res;

    switch (provider)
    {
        case TURNER_PROVIDER_IPX:
            res = lobby->CreateAddress( DPSPGUID_IPX, DPAID_INet,
                                        NULL, 0, address, &adsize );
            break;
        case TURNER_PROVIDER_TCPIP:
            size = (data) ? strlen((char*)data)+1 : 0;
            res = lobby->CreateAddress( DPSPGUID_TCPIP, DPAID_INet,
                                        data, size, address, &adsize );
            break;
        case TURNER_PROVIDER_MODEM:
            size = (data) ? strlen((char*)data)+1 : 0;
            res = lobby->CreateAddress( DPSPGUID_MODEM, DPAID_Phone,
                                        data, size, address, &adsize );
            break;
        case TURNER_PROVIDER_SERIAL:
            size = (data) ? sizeof(DPCOMPORTADDRESS) : 0;
            res = lobby->CreateAddress( DPSPGUID_SERIAL, DPAID_ComPort,
                                        data, size, address, &adsize );
            break;
        default:
            lobby->Release();
            return DPERR_UNSUPPORTED;
    }

    lobby->Release();

    if (FAILED(res))
        return res;

//ддд Initialize COM
    if (!TurnerCOMInit)
    {
        CoInitialize(NULL);
        TurnerCOMInit=1;
    }

//ддд Connect to DirectPlay
    res = CoCreateInstance(CLSID_DirectPlay,
                           NULL,
                           CLSCTX_INPROC_SERVER,
                           IID_IDirectPlay4A,
                           (void **) &pIDP);

    if (FAILED(res))
    {
        pIDP=0;
        return res;
    }

    res = pIDP->InitializeConnection(address, 0);
    if (FAILED(res))
    {
        pIDP->Release();
        pIDP = 0;
    }

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - close
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::close ()
{
    if (pIDP)
    {
        if (flags & TURNER_FLAGS_OPEN)
        {
            pIDP->Close ();
        }

        pIDP->Release ();
        pIDP = 0;
    }

    if (rbuffer)
    {
        delete [] rbuffer;
        rbuffer=0;
    }

    playerid = 0;

    flags &= ~(TURNER_FLAGS_OPEN | TURNER_FLAGS_HOST);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - create_game
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::create_game ()
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (flags & TURNER_FLAGS_OPEN)
        return DPERR_ALREADYINITIALIZED;

    int res = pIDP->Open (&session,DPOPEN_CREATE);
    Sleep(100);

    flags &= ~(TURNER_FLAGS_OPEN | TURNER_FLAGS_HOST);

    if (res == DP_OK)
    {
        flags |= TURNER_FLAGS_OPEN | TURNER_FLAGS_HOST;
        return DP_OK;
    }

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// static _player_callback
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
static BOOL CALLBACK _player_callback (DPID id,
                                       DWORD dwType,
                                       LPCDPNAME lpcName,
                                       DWORD flags,
                                       LPVOID context)
{
    TurnerClassic  *net = (TurnerClassic *)context;

    if (dwType == DPPLAYERTYPE_PLAYER)
    {
        net->sys_newplayer (id, lpcName->lpszShortNameA, lpcName->lpszLongNameA,
                            0, 0, 0, 0);
    }

    return TRUE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - connect_game
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::connect_game (GUID guidSession)
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
        pIDP->EnumPlayers (&guidSession, _player_callback, this,
                           DPENUMPLAYERS_REMOTE);
        return DP_OK;
    }

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - set_session_desc
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::set_session_desc(DPSESSIONDESC2 &desc)
{
    if (flags & TURNER_FLAGS_OPEN)
    {
        if (!(flags & TURNER_FLAGS_HOST))
            return DPERR_ACCESSDENIED;

        session.dwFlags &= ~(DPSESSION_JOINDISABLED
                             | DPSESSION_NEWPLAYERSDISABLED
                             | DPSESSION_NODATAMESSAGES
                             | DPSESSION_NOPRESERVEORDER
                             | DPSESSION_PRIVATE);
        session.dwFlags |= (desc.dwFlags & (DPSESSION_JOINDISABLED
                                            | DPSESSION_NEWPLAYERSDISABLED
                                            | DPSESSION_NODATAMESSAGES
                                            | DPSESSION_NOPRESERVEORDER
                                            | DPSESSION_PRIVATE));
    }
    else
    {
        session.dwFlags = desc.dwFlags;
        session.guidInstance = desc.guidInstance;
        session.guidApplication = desc.guidApplication;
    }

    session.dwMaxPlayers    = desc.dwMaxPlayers;
    session.dwUser1         = desc.dwUser1;
    session.dwUser2         = desc.dwUser2;
    session.dwUser3         = desc.dwUser3;
    session.dwUser4         = desc.dwUser4;

    if (desc.lpszSessionNameA && desc.lpszSessionNameA != sessionName)
    {
        strncpy(sessionName,desc.lpszSessionNameA,sizeof(sessionName));
    }

    if (desc.lpszPasswordA && desc.lpszPasswordA != password)
    {
        session.lpszPasswordA = password;
        strncpy(password,desc.lpszPasswordA,sizeof(password));
    }

    if (flags & TURNER_FLAGS_OPEN)
    {
        assert(pIDP != 0);
        return pIDP->SetSessionDesc(&session, 0);
    }

    return 0;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - create_player
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
DPID TurnerClassic::create_player (const char *short_name,
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

    pIDP->CreatePlayer (&id, &dp_name, NULL, data, size, _flags);
    Sleep(500);

    playerid = id;

    return id;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - destroy_player
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::destroy_player (DPID player)
{
    if (pIDP)
        pIDP->DestroyPlayer (player);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - set_player_name
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::set_player_name(DPID player,
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

    return pIDP->SetPlayerName(player, &dp_name, _flags);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - set_player_data
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::set_player_data(DPID player, LPVOID data,
                                   DWORD size, DWORD _flags)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    return pIDP->SetPlayerData(player, data, size, _flags);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - receive
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::receive ()
{
    DPID    from, to;
    HRESULT res;
    DWORD   size;

    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!rbuffer)
    {
        rbuffer = new char[TURNER_INIT_BUFFER];
        if (!rbuffer)
            return DPERR_OUTOFMEMORY;

        rbsize = TURNER_INIT_BUFFER;
    }

    for(;;)
    {
        Sleep(0);
        res = pIDP->Receive (&from, &to,
                             DPRECEIVE_ALL,
                             rbuffer, (LPDWORD)&size);

        switch (res)
        {
            case DPERR_BUFFERTOOSMALL:
                if (size > TURNER_MAX_BUFFER)
                    return DPERR_SENDTOOBIG;

                delete [] rbuffer;

                while (rbsize < size)
                    rbsize *= 2;

                rbuffer = new char[rbsize];
                if (!rbuffer)
                    return DPERR_OUTOFMEMORY;
                break;

            case DP_OK:
                if (!from)
                    handle_sysmsg (to, (DPMSG_GENERIC *)rbuffer, size);
                else
                    handle_msg (from, to, rbuffer, size);
                return DP_OK;

            default:
                return res;
        }
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - receive_all
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::receive_all (DWORD timeout)
{
    if (!timeout)
    {
        for(;;)
        {
            int res = receive();
            if (res != DP_OK)
                return res;
        }
    }
    else
    {
        DWORD time = GetTickCount() + timeout;
        for(;;)
        {
            int res = receive();
            if (res != DP_OK)
                return res;

            if (time <= GetTickCount())
                return DPERR_TIMEOUT;
        }
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - send
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::send (DPID from, DPID to, LPVOID data, DWORD size)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!from)
        from = playerid;

    int res = pIDP->SendEx (from, to, sendfl, data, size,
                            0, 0, NULL, NULL);
    Sleep(0);

    return res;
}

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - send_guaranteed
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::send_guaranteed (DPID from, DPID to, LPVOID data, DWORD size)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!from)
        from = playerid;

    int res = pIDP->SendEx (from, to, sendfl | DPSEND_GUARANTEED, data, size,
                            0, 0, NULL, NULL);
    Sleep(0);

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - broadcast
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::broadcast (DPID from, LPVOID data, DWORD size)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!from)
        from = playerid;

    int res = pIDP->SendEx (from, DPID_ALLPLAYERS, sendfl,
                            data, size, 0, 0, NULL, NULL);
    Sleep(0);

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - broadcast_guaranteed
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::broadcast_guaranteed (DPID from, LPVOID data, DWORD size)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    if (!from)
        from = playerid;

    int res = pIDP->SendEx (from, DPID_ALLPLAYERS, sendfl | DPSEND_GUARANTEED,
                            data, size, 0, 0, NULL, NULL);
    Sleep(0);

    return res;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - send_chat
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::send_chat (DPID from, DPID to, char *msg, DWORD _flags)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    DPCHAT dp_chat;
    dp_chat.dwSize = sizeof(DPCHAT);
    dp_chat.dwFlags = 0;
    dp_chat.lpszMessageA = msg;

    if (!from)
        from = playerid;

    return pIDP->SendChatMessage(from, to, _flags, &dp_chat);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - broadcast_chat
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::broadcast_chat (DPID from, char *msg, DWORD _flags)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    DPCHAT dp_chat;
    dp_chat.dwSize = sizeof(DPCHAT);
    dp_chat.dwFlags = 0;
    dp_chat.lpszMessageA = msg;

    if (!from)
        from = playerid;

    return pIDP->SendChatMessage(from, DPID_ALLPLAYERS, _flags, &dp_chat);
}



//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  System Message Process Routines  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - handle_sysmsg
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::handle_sysmsg (DPID to, DPMSG_GENERIC *pmsg, DWORD size)
{
    assertMyth("TurnerClassic::handle_sysmsg needs valid input", pmsg != 0);

    switch (pmsg->dwType)
    {
        case DPSYS_SETSESSIONDESC:
            {
                DPMSG_SETSESSIONDESC *msg = (DPMSG_SETSESSIONDESC*)pmsg;

                if (!(flags & TURNER_FLAGS_HOST))
                {
                    session.dwFlags = msg->dpDesc.dwFlags;
                    session.guidInstance = msg->dpDesc.guidInstance;
                    session.guidApplication = msg->dpDesc.guidApplication;
                    session.dwMaxPlayers = msg->dpDesc.dwMaxPlayers;
                    session.dwCurrentPlayers = msg->dpDesc.dwCurrentPlayers;
                    if (msg->dpDesc.lpszSessionNameA)
                    {
                        session.lpszSessionNameA = sessionName;
                        strncpy(sessionName,msg->dpDesc.lpszSessionNameA,
                                sizeof(sessionName));
                    }
                    if (msg->dpDesc.lpszPasswordA)
                    {
                        session.lpszPasswordA = password;
                        strncpy(password,msg->dpDesc.lpszPasswordA,
                                sizeof(password));
                    }
                    session.dwUser1 = msg->dpDesc.dwUser1;
                    session.dwUser2 = msg->dpDesc.dwUser2;
                    session.dwUser3 = msg->dpDesc.dwUser3;
                    session.dwUser4 = msg->dpDesc.dwUser4;
                }

                sys_set_session_desc(msg->dpDesc);
            }
            break;

        case DPSYS_HOST:
            flags |= TURNER_FLAGS_HOST;
            sys_host ();
            break;

        case DPSYS_SESSIONLOST:
            sys_no_session ();
            break;

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
                }
            }
            break;

        case DPSYS_CHAT:
            {
                DPMSG_CHAT *msg = (DPMSG_CHAT*)pmsg;
                handle_chat(msg->idFromPlayer, msg->idToPlayer,
                            msg->idToGroup, msg->lpChat->lpszMessageA);
                break;
            }
            break;
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - sys_set_session_desc
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::sys_set_session_desc(DPSESSIONDESC2 &desc)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - sys_host
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::sys_host ()
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - sys_no_session
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::sys_no_session ()
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - sys_newplayer
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::sys_newplayer (DPID player,
                                  LPCSTR short_name, LPCSTR long_name,
                                  LPVOID data, DWORD size, DPID pgroup,
                                  DWORD _flags)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - sys_delplayer
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::sys_delplayer (DPID player, DWORD _flags)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - sys_set_player_name
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::sys_set_player_name (DPID player,
                                         LPCSTR short_name, LPCSTR long_name)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - sys_set_player_data
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::sys_set_player_data(DPID player, LPVOID data, DWORD size)
{
}



//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  Enumeration Routines  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - enum_providers
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::enum_providers()
{
    DirectPlayEnumerate (enum_serviceprovider, (LPVOID)this);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - enum_sessions
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void TurnerClassic::enum_sessions(DWORD timeout)
{
    if (!pIDP)
        return;

    DPSESSIONDESC2 desc;
    memset (&desc, 0, sizeof (desc));
    desc.dwSize = sizeof (desc);
    desc.guidInstance = session.guidInstance;

    pIDP->EnumSessions (&desc, timeout,
                        enum_sessions, (LPVOID)this, (DWORD)NULL);

}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - handle_enum_provider
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::handle_enum_provider(LPGUID _guid, LPSTR _desc,
                                        DWORD _majver, DWORD _minver)
{
    return 0;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - handle_enum_session
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::handle_enum_session(LPCDPSESSIONDESC2 _session,
                                       LPDWORD _timeout,
                                       DWORD _flags)
{
    return 0;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - enum_serviceprovider
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK TurnerClassic::enum_serviceprovider (LPGUID _guid,
                                                   LPSTR _desc,
                                                   DWORD _majver,
                                                   DWORD _minver,
                                                   LPVOID _this)
{
    return ((TurnerClassic*)_this)->handle_enum_provider(_guid,_desc,_majver,_minver);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - enum_sessions
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK TurnerClassic::enum_sessions (LPCDPSESSIONDESC2 _session,
                                            LPDWORD _timeout,
                                            DWORD _flags,
                                            LPVOID _this)
{
    return ((TurnerClassic*)_this)->handle_enum_session(_session,_timeout,_flags);
}



//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  Utility Routines  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - get_caps
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::get_caps(LPDPCAPS caps, DWORD _flags)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    memset(caps,0,sizeof(caps));
    caps->dwSize = sizeof(DPCAPS);

    return pIDP->GetCaps(caps, _flags);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - get_player_caps
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::get_player_caps(DPID player, LPDPCAPS caps, DWORD _flags)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    memset(caps,0,sizeof(caps));
    caps->dwSize = sizeof(DPCAPS);

    return pIDP->GetPlayerCaps(player, caps, _flags);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - get_send_message_queue
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::get_send_message_queue(DPID from, DPID to,
                                          LPDWORD nmsgs, LPDWORD nbytes)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    return pIDP->GetMessageQueue(from,to,DPMESSAGEQUEUE_SEND,nmsgs,nbytes);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerClassic - get_receive_message_queue
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerClassic::get_receive_message_queue(DPID from, DPID to,
                                             LPDWORD nmsgs, LPDWORD nbytes)
{
    if (!pIDP)
        return DPERR_UNAVAILABLE;

    return pIDP->GetMessageQueue(from,to,DPMESSAGEQUEUE_RECEIVE,nmsgs,nbytes);
}

//╟╠╡ End of module - turner.cpp ╡╠╟
