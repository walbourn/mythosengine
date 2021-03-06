                    ooo        ooooo
                    `88.       .888'
                     888b     d'888   .oooo.   oooo    ooo
                     8 Y88. .P  888  `P  )88b   `88b..8P'
                     8  `888'   888   .oP"888     Y888'
                     8    Y     888  d8(  888   .o8"'88b
                    o8o        o888o `Y888""8o o88'   888o

                            Across the event horizon...

                       Microsoft Windows 95/98/NT Version

    Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn

 ---------------------------------------------------------------------------

  THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
  OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
  PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
  LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
  OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

                         http://www.mythos-engine.org/

 ---------------------------------------------------------------------------

                              _Library Status_

  Notes by: Dan Higdon
  Updated: February 28, 1998

  Changes for this release --------------------------------------------------

    o Added a new MaxMouse::set_extents (x,y) which allows you to clip the
      mouse position to a specific area of the screen.  Usually, the extents
      are set to GetSystemMetrics (SM_CXEXTENT) and SM_CYEXTENT, but with some
      DirectDraw applications, Windows can get confused about which device has
      the mouse.


  Pending changes -----------------------------------------------------------

    o Needs focusing mechanism and a method for appending/overloading
      event sources.


  Conversion from previous Max ----------------------------------------------

    The major changes in MaxDevices will cause all existing code to break.
    However, the conversion process is relatively simple.  There are three
    major areas of conflict:

    Creation:  You can no longer create a MaxDevices object.  Keep your
               MaxDevices pointer, but where you create the object,
               insert some code such as:

               if (use_directinput)
                   Devs = new MaxDevicesDirectX (hWndClient);
               else
                   Devs = new MaxDevicesWin32 (hWndClient);

               Notice that you must pass an HWND in to create the objects
               now.  You should pass your application's primary window in here.

    Usage:     The members of MaxDevices theMouse, theJoystick, and theKeyboard
               are now pointers.  When those devices are not enabled, the
               pointers are NULL.  That means you can no longer assume those
               devices exist.  (Actually, with the exception of theJoystick,
               they will always exist.)

               The upshot of this is that checking for the presence of any
               device must be performed using one of the following members:
               is_mouse_enabled(), is_joystick_enabled(),is_keyboard_enabled().

               Additionally any place you use one of the devices directly,
               you must take into account that they are now pointers.
               The most common problem here is when creating a MaxKbBuffer.
               Previous code used something like MaxKbBuffer (&Devs->theKeyboard).
               this should now read MaxKbBuffer (Devs->theKeyboard).

    New Requirements:
               When your application gets focus, you should call
               MaxDevices::init(), and when it looses focus you should call
               MaxDevices::uninit().  This is required for correct DirectInput
               behavior.  Note that you do not have to init/uninit the devices
               under normal conditions; this is handled by creation and
               destruction.  (The old version required you to call
               Devs->theKeyboard.init().  That is obsolete.)

               Also, add DXGUID.LIB and DINPUT.LIB to your makefiles.


    For uniformity's sake, you should continue to call theKeyboard's wm_keydown()
    and wm_keyup() members in your window procedure, even though it is only
    actually required for the MaxDevicesWin32 object.  It is still critical
    to call the MaxDevices::wm_clear() and MaxDevices::update() members as
    before.

    In summary:
        o Create the correct device.

        o Replace all device activity tests with a
          MaxDevices::is_*_enabled() calls,

        o Rewrite usages of the[Mouse|Keyboard|Joystick] to take into account
          their change to pointers.

        o Continue calling the MaxKeyboard::wm_* members and
          use MaxDevices::wm_clear() and MaxDevices::update() as before.

        o Add MaxDevices::init() calls to your WM_SETFOCUS handler, and
          MaxDevices::uninit() calls to your WM_KILLFOCUS handler.
          Remove Devs->theKeyboard.init() call in WM_SETFOCUS - these calls
          supercede it.

        o Add DXGUID.LIB and DINPUT.LIB to your makefiles.

*** END OF FILE ***
