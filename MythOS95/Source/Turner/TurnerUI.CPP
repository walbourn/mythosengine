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
// Turner Network Interface - UI module
//
// turnerui.cpp
//
//  This module provides a dialog user interface to initialize
//  a turner session.
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

TurnerNetworkUI *TurnerNetworkUI::g_this = 0;

//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Code
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - Constructor
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerNetworkUI::TurnerNetworkUI (HWND _hWnd,
                                  TurnerClassic *_net,
                                  int _max_sessions,
                                  dword _timeout):
    hWnd (_hWnd),
    net (_net),
    max_sessions (_max_sessions),
    current_session (0),
    timeout (_timeout),
    sessions (0)
{
    // There can only be one of these created at a a time
    assert (!g_this);

    g_this = this;

    if (max_sessions > 0)
        sessions = new GUID[max_sessions];
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - Destructor
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
TurnerNetworkUI::~TurnerNetworkUI ()
{
    g_this = 0;
    if (sessions)
    {
        delete [] sessions;
        sessions = 0;
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - connect
//
//  Connect to a user-selected game.  Note that this member does not
//  create a player, which must be done by the calling application.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL TurnerNetworkUI::connect ()
{
    // Be sure we aren't already initialized.
    if (net->pIDP != NULL)
        return FALSE;

    if (!get_provider ())
        return FALSE;

    // Select whether to connect to a game or create a new one
    switch (create_or_join ())
    {
    case 1:             // Create
        {
            int res = net->create_game();
            return (res == DP_OK) ? TRUE : FALSE;
        }

    case 2:             // Connect
        return select_session ();

    default:
        return FALSE;
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - get_provider
//
//  Prompt the user for a connection provider, and initialize the
//  network object to use the one selected by the user.
//  Returns:    TRUE if a service selected
//              FALSE if no service selected
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetworkUI::get_provider ()
{
    return DialogBoxParam (NULL,
                           (LPCTSTR)IDD_MAXNETWORK_CHOOSEPROVIDER,
                           hWnd,
                           (DLGPROC)dlg_chooseprovider,
                           (LPARAM)this);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - enum_serviceprovider
//
//  Used by DlgProcChooseProvider
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK TurnerNetworkUI::enum_serviceprovider (LPGUID lpGuid,
                                                     LPSTR  lpDesc,
                                                     DWORD  dwMajorVersion,
                                                     DWORD  dwMinorVersion,
                                                     LPVOID lpv)
{
    HWND hWnd = (HWND)lpv;

    LONG iIndex = SendMessage (hWnd, LB_ADDSTRING, 0, (LPARAM) lpDesc);
    if (iIndex != LB_ERR)
        SendMessage (hWnd, LB_SETITEMDATA, iIndex, (LPARAM) lpGuid);

    SetFocus (hWnd);
    SendMessage (hWnd, LB_SETCURSEL, 0, 0);
    return TRUE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - dlg_chooseprovider
//
//  The dialog proc for get_provider
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK TurnerNetworkUI::dlg_chooseprovider (HWND hDlg,
                                                   UINT msg,
                                                   WPARAM wParam,
                                                   LPARAM lParam)
{
    LONG                    iIndex;
    static  HWND            hWndCtl;
    static  TurnerClassic   *net;

    switch (msg)
    {
        case WM_INITDIALOG:
            net = ((TurnerNetworkUI*)lParam)->net;
            hWndCtl = GetDlgItem (hDlg, IDC_MAXNETWORK_LIST1);

            if (net == 0 || hWndCtl == 0)
            {
                EndDialog (hDlg, TRUE);
                return TRUE;
            }

            DirectPlayEnumerate (enum_serviceprovider, (LPVOID) hWndCtl);
            SetFocus (hWndCtl);
            iIndex=0;
            SendMessage (hWndCtl, LB_SETCURSEL, 0, 0);
            return FALSE;

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                    iIndex = SendMessage (hWndCtl, LB_GETCURSEL, 0, 0);
                    if (iIndex != LB_ERR)
                    {
                        LPGUID lpGuid = (LPGUID) SendMessage (hWndCtl, LB_GETITEMDATA, iIndex, 0);
                        if (lpGuid)
                        {
                            net->select_provider (lpGuid);
                            EndDialog (hDlg, TRUE);
                        }
                        else
                            EndDialog (hDlg, FALSE);

                        return TRUE;
                    }
                    break;

                case IDCANCEL:
                    EndDialog (hDlg, FALSE);
                    return TRUE;

                case IDC_MAXNETWORK_LIST1:
                    switch (HIWORD (wParam))
                    {
                        case LBN_DBLCLK:
                            iIndex = SendMessage ((HWND) lParam, LB_GETCURSEL, 0, 0);
                            if (iIndex != LB_ERR)
                            {
                                LPGUID lpGuid = (LPGUID) SendMessage (hWndCtl, LB_GETITEMDATA, iIndex, 0);
                                if (lpGuid)
                                {
                                    net->select_provider (lpGuid);
                                    EndDialog (hDlg, TRUE);
                                }
                                else
                                    EndDialog (hDlg, FALSE);
                            }
                            break;
                    }
                    break;
            }
            break;
    }
    return FALSE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - create_or_join
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetworkUI::create_or_join ()
{
    return DialogBoxParam (NULL,
                           (LPCTSTR) IDD_MAXNETWORK_Q_CREATE,
                           hWnd,
                           (DLGPROC) dlg_qcreate,
                           (LPARAM)this);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - dlg_qcreate
//
//  Dialog proc used by create_or_join
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK TurnerNetworkUI::dlg_qcreate (HWND hDlg,
                                            UINT msg,
                                            WPARAM wParam,
                                            LPARAM lParam)
{
    switch (msg)
    {
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDC_MAXNETWORK_CREATE:
                    EndDialog(hDlg, 1);
                    return TRUE;

                case IDC_MAXNETWORK_CONNECT:
                    EndDialog(hDlg, 2);
                    return TRUE;

                case IDCANCEL:
                    EndDialog(hDlg, -1);
                    return TRUE;
            }
            break;
    }
    return FALSE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - select_session
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
int TurnerNetworkUI::select_session ()
{
    assertMyth ("TurnerNetworkUI::select_session must be called after a service provider is chosen",
                net->pIDP != 0);

    return DialogBoxParam (NULL,
                           (LPCTSTR) IDD_MAXNETWORK_SELSESSION,
                           hWnd,
                           (DLGPROC) dlg_selectsession,
                           (LPARAM)this);
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - dlg_selectsession
//
//  Dialog proc used by select_session
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK TurnerNetworkUI::dlg_selectsession (HWND hDlg,
                                                  UINT msg,
                                                  WPARAM wParam,
                                                  LPARAM lParam)
{
    LONG                    iIndex;
    DPSESSIONDESC2          dpDesc;

    static  HWND            hWndCtl = 0;
    static  TurnerClassic   *net = 0;

    switch (msg)
    {
        case WM_INITDIALOG:
            net = ((TurnerNetworkUI*)lParam)->net;
            hWndCtl = GetDlgItem (hDlg, IDC_MAXNETWORK_LIST1);

            if (net == NULL || hWndCtl == NULL)
            {
                EndDialog (hDlg, FALSE);
                return TRUE;
            }

            memset (&dpDesc, 0, sizeof (dpDesc));
            dpDesc.dwSize = sizeof (dpDesc);
            dpDesc.guidInstance = net->session.guidInstance;

            net->pIDP->EnumSessions (&dpDesc,
                                     ((TurnerNetworkUI*)lParam)->timeout,
                                     enum_sessions,
                                     (LPVOID)hWndCtl, (DWORD)NULL);

            SetFocus (hWndCtl);
            return FALSE;

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:

                    iIndex  = SendMessage (hWndCtl, LB_GETCURSEL, 0, 0);
                    if (iIndex == LB_ERR)
                    {
                        net->close ();
                        EndDialog (hDlg, FALSE);
                        return TRUE;
                    }
                    else
                    {
                        DWORD session = SendMessage (hWndCtl, LB_GETITEMDATA, iIndex, 0);
                        if (session == LB_ERR)
                        {
                            net->close ();
                            EndDialog (hDlg, FALSE);
                            return TRUE;
                        }

                        HRESULT hr = net->connect_game (g_this->sessions[session]);
                        if (hr != DP_OK)
                        {
                            net->close ();
                            EndDialog (hDlg, FALSE);
                            return TRUE;
                        }
                    }

                    EndDialog (hDlg, TRUE);
                    return TRUE;

                case IDCANCEL:
                    net->close ();
                    EndDialog (hDlg, FALSE);
                    return TRUE;

                case IDC_MAXNETWORK_LIST1:
                    switch (HIWORD (wParam))
                    {
                        case LBN_DBLCLK:
                            iIndex = SendMessage (hWndCtl, LB_GETCURSEL, 0, 0);
                            if (iIndex != LB_ERR)
                            {
                                DWORD session = SendMessage (hWndCtl, LB_GETITEMDATA, iIndex, 0);
                                if (session == LB_ERR)
                                {
                                    net->close ();
                                    EndDialog (hDlg, FALSE);
                                    return TRUE;
                                }

                                HRESULT hr = net->connect_game (g_this->sessions[session]);
                                if (hr != DP_OK)
                                {
                                    net->close ();
                                    EndDialog (hDlg, FALSE);
                                    return TRUE;
                                }

                                // Successfully connected to a gaming session.
                                EndDialog (hDlg, TRUE);
                                return TRUE;
                            }
                            break;
                    }
                    break;
            }
            break;
    }

    return FALSE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TurnerNetworkUI - enum_sessions
//
//  session enumeration proc used by DlgProcSelSession
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BOOL CALLBACK TurnerNetworkUI::enum_sessions(LPCDPSESSIONDESC2 lpDPGameDesc,
                                             LPDWORD lpdwTimeOut,
                                             DWORD dwFlags,
                                             LPVOID lpContext)
{
    HWND hWndCtl = (HWND)lpContext;

    if (dwFlags & DPESC_TIMEDOUT)
        return FALSE;       // don't try again

    int session_index = g_this->current_session++;
    if (session_index < g_this->max_sessions)
    {
        g_this->sessions[session_index] = lpDPGameDesc->guidInstance;

        LONG iIndex = SendMessage (hWndCtl, LB_ADDSTRING, 0, (LPARAM) lpDPGameDesc->lpszSessionNameA);
        if (iIndex != LB_ERR)
            SendMessage (hWndCtl, LB_SETITEMDATA, iIndex, (LPARAM) session_index);

        SetFocus (g_this->hWnd);
        SendMessage (hWndCtl, LB_SETCURSEL, 0, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//╟╠╡ End of module - turnerui.cpp ╡╠╟
