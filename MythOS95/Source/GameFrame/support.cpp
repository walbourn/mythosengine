//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                        _/_/_/           _/_/_/_/
//                      _/                _/
//                     _/  _/_/          _/_/_/
//                    _/    _/  A M E   _/      R A M  E
//                     _/_/_/          _/
//
// A Framework for Microsoft Windows '95 Entertainment Software Using MythOS
//
//           Copyright (c) 1995, 1996 by Charybdis Enterprises, Inc.
//                           All Rights Reserved
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
// support.cpp
//
// This module contains some basic support code for the screen management,
// Windows initialization, and the charybdis assert call function.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <global.hpp>
#include <resource.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

LRESULT CALLBACK ClientWndProc (HWND, UINT, WPARAM, LPARAM);
void fatal_error(ulong id, char *file, int line);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Game State Members °°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GameState::GameState ()
{
    // Nothing to construct here
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GameState::~GameState ()
{
    // Nothing to destroy here
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - activate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::activate ()
{
    // NOP in the base class
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - deactivate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::deactivate ()
{
    // NOP in the base class
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - pump_windows
//
// Runs one cycle of the windows message pump.
// Returns a false if the Quit Message has been returned, true otherwise.
//
// Note: Since this only removes a single message from the queue, messages
//       can build up and cause overflow if pump_windows() isn't called
//       fast enough for the input.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL GameState::pump_windows ()
{
    MSG msg;

    Devs->wm_clear();
    while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
    {
    	if (GetMessage (&msg, 0, 0, 0) == 0)
            return FALSE;

        TranslateMessage (&msg);
        DispatchMessage (&msg);
    }
    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - display
//
// Copies data from the backbuffer to the window.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::display ()
{
    assertMyth ("GameState: display needs valid Screen instance", Screen != 0);

    Screen->flip();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - panic
//
// Fatal error during game, must clean up as much as possible and get out,
// after displaying cause of error.  Derived classes can override panic and
// call base version after performing clean up.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::panic (ulong id, const char *str)
{
    char    buff[1024];

    if (Screen)
    {
        Screen->unlock();
        Screen->cursor_set(GFScreen::CURS_STD);
    }

    LoadString(hInst, id, buff, sizeof(buff) - 128);

    //ÄÄÄ Add any additional comments.
    if (str)
    {
        strcat(buff,"\n\n");
        strcat(buff,str);
    }

    MessageBox (hWndClient,
                buff,
                szAppName, MB_OK | MB_ICONEXCLAMATION);
    DestroyWindow(hWndClient);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°° Windows Initialization Functions °°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// InitApplication
//
// Initializes the application and creates the 'Screen' window.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL InitApplication (HINSTANCE hInstance, int nCmdShow, int w, int h)
{
    char    szTitle[MAX_PATH];

    // Win32 will always set hPrevInstance to NULL, so lets check
    // things a little closer. This is because we only want a single
    // version of this app to run at a time
    HWND hwnd = FindWindow (szAppName, NULL);
    if (hwnd != 0)
    {
        // We found another version of ourself. Lets defer to it:
        if (IsIconic (hwnd))
            ShowWindow (hwnd, SW_RESTORE);
        SetForegroundWindow (hwnd);

        char    buff[1024];

        LoadString(hInstance, 
                   IDS_ERR_MULTINSTANCE,
                   buff,
                   sizeof(buff));

        MessageBox (NULL,
                    buff,
                    szAppName,
                    MB_OK | MB_ICONEXCLAMATION);

        return FALSE;
    }

    // Make sure our Common Controls are available
    // InitCommonControls();

    // Register the client window's class
    WNDCLASSEX  wc;

    // Fill in window class structure with parameters that describe
    // the main window.
    wc.cbSize        = sizeof (WNDCLASSEX);
    wc.style         = CS_OWNDC;
    wc.lpfnWndProc   = (WNDPROC)ClientWndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon (hInstance, szAppName);
    wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject (BLACK_BRUSH);
    wc.lpszClassName = szAppName;
    wc.lpszMenuName  = 0;

    // This will load the small icon image from the icon resource
    wc.hIconSm = LoadImage (hInstance,
                            szAppName,
                            IMAGE_ICON,
                            GetSystemMetrics(SM_CXSMICON), 
                            GetSystemMetrics(SM_CYSMICON), 
                            LR_DEFAULTCOLOR);              

    if (!RegisterClassEx (&wc))
        return FALSE;

    // Save the instance handle in static variable, which will be used in
    // many subsequence calls from this application to Windows.
    hInst = hInstance;

    LoadString (hInstance, IDS_TITLE, szTitle, sizeof (szTitle));
    hWndClient = CreateWindowEx (0, // WS_EX_TOPMOST,
                                szAppName, szTitle,
                                WS_VISIBLE | WS_POPUP,
                                0, 0, w, h,
                                NULL, NULL, hInstance, NULL);

    if (hWndClient == 0)
        return FALSE;

    ShowWindow (hWndClient, nCmdShow);
    UpdateWindow (hWndClient);
    SetFocus (hWndClient);

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ClientWndProc
//
//  This is the Main Application Window's procedure.
//  Mostly, this just allows a black rectangle to overlay GDI.
//  In a game, very little else happens here, but some inter-app interaction
//  must be processed here; most importantly activation and termination.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LRESULT CALLBACK ClientWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Mouse Events
        case WM_SETCURSOR:
            // Don't let windows reassert its mouse cursor!
            return 0;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Keyboard Events
        case WM_SYSKEYDOWN:
            if (Devs)
                Devs->theKeyboard.wm_keydown (wParam);
            return DefWindowProc (hWnd, message, wParam, lParam);

        case WM_KEYDOWN:
            if (Devs)
                Devs->theKeyboard.wm_keydown (wParam);
            return 0;

        case WM_SYSKEYUP:
        case WM_KEYUP:
            if (Devs)
                Devs->theKeyboard.wm_keyup (wParam);
            return 0;

        case WM_SETFOCUS:
        case WM_KILLFOCUS:
            if (Devs)
                Devs->theKeyboard.init();
            return 0;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Application Events
        case WM_CREATE:
            return 0;

        case WM_ACTIVATEAPP:
            if (wParam)
            {
                if (Screen)
                {
                    Screen->reinit();
                    Screen->invalidate();
                }
            }
            return 0;

        case WM_CLOSE:
            if (MessageBox(hWndClient,
                        "Are you sure you wish to exit this application?",
                        szAppName, MB_YESNO | MB_ICONQUESTION) == IDYES)
                DestroyWindow(hWndClient);
            return 0;

        case WM_DESTROY:
            // Get the heck outta here.
            PostQuitMessage (0);
            return 0;

        default:    // Pass other commands through
            return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// fatal_error
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void fatal_error(ulong id, char *file, int line)
{
    char buff[1024];

    int bytes = LoadString (hInst, id, buff, sizeof (buff) - 128);

    wsprintf (buff + bytes, "\n\n%s (%d)", file, line);

    MessageBox (hWndClient,
                buff,
                szAppName, MB_OK | MB_ICONEXCLAMATION);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° MythOS Assert Display °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// _charybdis_assert
// 
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void _charybdis_assert (char *msg, char *exp, char *f, unsigned ln)
{
    int     i, l=0;
    char    title[32];
    char    buff[988];

    if (Screen)
        l = Screen->unlock();

    wsprintf (buff,"Assertion Failed\t\t\t\t\t\n"
                   "Expr:\t%s\n"
                   "File:\t%s\t\tLine %d",exp,f,ln);
    if (msg)
    {
        strcat (buff, "\nComment:\n");
        strcat (buff, msg);
    }
    strcat (buff,"\n\n\tOK to continue, Cancel to exit");

    strcpy (title, szAppName);
    strcat (title, " Debug Message");

    i = MessageBox (IsWindow (hWndClient) ? hWndClient : NULL,
                    buff,
                    title,
                    MB_OKCANCEL | MB_DEFBUTTON2 | MB_APPLMODAL | MB_ICONSTOP);

    if (i == IDCANCEL)
        ExitProcess (1);
    else if (l)
        Screen->lock();
}

//°±² eof - support.cpp ²±°
