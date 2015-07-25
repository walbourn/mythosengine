 
                                 /\    /\
                                /  \  /  \
                               /    \/    \
                              /  /\    /\  \
                             /  /  \  /  Y T H O S
                            /  /    \/    \  \
                           /  /            \  \
                          /__/              \__\
 
                       Microsoft Windows '95 Version

             Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
                            All Rights Reserved.

 ---------------------------------------------------------------------------
 
            *** Charybdis Enterprises, Inc. Company Confidential ***
 
   This file and all associated files are the company proprietary property
         of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
 
  CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
  TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
  IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
  AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
  INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

  This example application is a component of the MythOS(tm) entertainment
  and multi-media development library.

  MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                              LUNAR LANDER EXAMPLE

 Notes by: Chuck Walbourn
 Updated: October 31, 1997


 ---------------------------------------------------------------------------
 DESCRIPTION

 This example demonstrates a simple 2D game implementation using the
 SimGine Framework.  This was formely the GameFrame example in older
 releases of MythOS.


 ---------------------------------------------------------------------------
 PARAMETERS

 The parameters are taken from the LLANDER.INI file.  The [Screen] section
 specifies information about the Van Gogh viewport, screen device, and
 palette to use.  The [Startup] section controls some SimGine startup
 parameters and the [Lander] section controls Multiplayer mode.


 ---------------------------------------------------------------------------
 CONTROLS

 The controls can be changed by editing the LLEVT.CEL file.  They
 are currently setup as follows:

 Esc                Quits
 Space              Next screen

 Left Arrow         Thrust from right
 Right Arrow        Thrust from left
 Up Arrow           Small up thrust
 Down Arrow         Large up thrust

 H                  Turns off gravity
 Shift+H            Turns on gravity


 ---------------------------------------------------------------------------
 LIBRARIES

 This makes use of the MythOS SimGine framework which initializes the
 libraries.  Van Gogh and Escher are used to create the views, Max
 is used for input processing, Chronos for time tracking, and Turner
 is used for network communcation.

*** END OF FILE ***
