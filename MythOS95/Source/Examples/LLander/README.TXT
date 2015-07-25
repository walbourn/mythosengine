 
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

  This file and all associated files are subject to the terms of the
  GNU Lesser General Public License version 2 as published by the
  Free Software Foundation (http://www.gnu.org).   They remain the
  property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
  See LICENSE.TXT in the distribution for a copy of this license.

  THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
  OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
  PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
  LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
  OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

                         http://www.mythos-engine.org/

 ---------------------------------------------------------------------------

                              LUNAR LANDER EXAMPLE

 Notes by: Chuck Walbourn
 Updated: January 2, 1998


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
