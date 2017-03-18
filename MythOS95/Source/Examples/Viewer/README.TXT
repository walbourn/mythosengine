 
                                 /\    /\
                                /  \  /  \
                               /    \/    \
                              /  /\    /\  \
                             /  /  \  /  Y T H O S
                            /  /    \/    \  \
                           /  /            \  \
                          /__/              \__\
 
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

                               3D VIEWER EXAMPLE

 Notes by: Chuck Walbourn
 Updated: January 2, 1998


 ---------------------------------------------------------------------------
 DESCRIPTION

 This example loads one or more 3D meshes and lights and displays them inside
 a 3D viewport.  The items can be interactively positioned, rotated, and
 otherwise manipulated.


 ---------------------------------------------------------------------------
 PARAMETERS

 The parameters are taken from the VIEWER.INI file.  The [Screen] section
 specifies information about the Van Gogh viewport, screen device, and
 palette to use.  The [Camera] sections sets various camera parameters and
 [View] specifies one or more exported scene files to load.


 ---------------------------------------------------------------------------
 CONTROLS

 The controls can be changed by editing the VIEWEVT.CEL file.  They
 are currently setup as follows:

 Esc or Alt+Q       Quits
    
 F1                 Toggles All Lines mode for Wireframe
 F2                 Toggles Model Space lighting
 F3                 Toggles Backface culling
 F4                 Wireframe
 F5                 Solid
 F6                 Flat shaded
 F7                 Smooth shaded
 F8                 Specular shaded
 F9                 Toggles texture maps
 F10                Toggles perspective correction for texture maps
 F11                Toggles use of alpha
 F12                Toggles sorting mode (turns off z-buffer when sorting)
 Shift+F12          Toggles just the Z-buffer on and off.
 H                  Toggles hazing mode on and off
 `                  Toggles display of statistics

 Clicking and holding mouse button 1 selects an object for rotation.  If
 the mouse is moving when the button is let go, the movement is applied
 automatically every frame.  Clicking and hold mouse button 2 selects an
 object for movement.  The shift key motifies the movement to the third
 axis.


 ---------------------------------------------------------------------------
 LIBRARIES

 This makes use of the MythOS System class to initailize the libraries, but
 most of the calls used are those to setup Van Gogh and the use of Escher's
 basic drawable and camera control routines.  Max is used for the
 event processing.

*** END OF FILE ***
