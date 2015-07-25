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
// simproc.cpp
//
// This module contains the window procedure for the client window.
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SimWndProc
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LRESULT CALLBACK SimWndProc (HWND hWnd,
                             UINT message, WPARAM wParam, LPARAM lParam)
{
    static BOOL fScreenSaverActive;

    switch (message)
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Mouse Events
        case WM_SETCURSOR:
            return 0;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Keyboard Events
        case WM_SYSKEYDOWN:
            if (Devs && Devs->theKeyboard)
                Devs->theKeyboard->wm_keydown (wParam);

            return DefWindowProc (hWnd, message, wParam, lParam);

        case WM_KEYDOWN:
            if (Devs && Devs->theKeyboard)
                Devs->theKeyboard->wm_keydown (wParam);

            return 0;

        case WM_SYSKEYUP:
            if (Devs && Devs->theKeyboard)
                Devs->theKeyboard->wm_keyup (wParam);

            return DefWindowProc (hWnd, message, wParam, lParam);

        case WM_KEYUP:
            if (Devs && Devs->theKeyboard)
                Devs->theKeyboard->wm_keyup (wParam);

            return 0;

        case WM_SETFOCUS:
            if (Devs)
                Devs->init();
            return 0;

        case WM_KILLFOCUS:
            if (Devs)
                Devs->uninit();
            return 0;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Application Events
        case WM_CREATE:
            fScreenSaverActive = FALSE;
            SystemParametersInfo (SPI_GETSCREENSAVEACTIVE, 0,&fScreenSaverActive, 0);

            // Now, turn off the screen saver (but not permanently)
            SystemParametersInfo (SPI_SETSCREENSAVEACTIVE, FALSE, NULL, 0);
            return 0;

        case WM_ACTIVATEAPP:
            if (wParam)
            {
                SystemParametersInfo (SPI_SETSCREENSAVEACTIVE, FALSE, NULL, 0);
                if (Screen)
                {
                    Screen->reinit();
                }
            }
            else
            {
                SystemParametersInfo (SPI_SETSCREENSAVEACTIVE, fScreenSaverActive, NULL, 0);
            }
            return 0;

        case WM_CLOSE:
            if (SimApp)
                DestroyWindow(SimApp->hWndClient);
            return 0;

        case WM_DESTROY:
            PostQuitMessage (0);
            SystemParametersInfo (SPI_SETSCREENSAVEACTIVE, fScreenSaverActive, NULL, 0);
            return 0;

        default:
            return DefWindowProc (hWnd, message, wParam, lParam);
    }
}

//°±² End of module - simproc.cpp ²±°

