
                         _/_/_/          _/_/_/_/
                       _/                _/
                      _/  _/_/          _/_/_/
                     _/    _/  A M E   _/      R A M  E
                      _/_/_/          _/

  A Framework for Microsoft Windows '95 Entertainment Software Using MythOS

           Copyright (c) 1995 - 1997 by Charybdis Enterprises, Inc.
                            All Rights Reserved

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

  This framework is part of the MythOS(tm) entertainment and multi-
  media development library distribution.

  MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                                   _Status_

 Notes by: Chuck Walbourn
 Updated: May 22, 1997

 Release Notes --------------------------------------------------------------

 This version of the Game Frame has been updated with a number of
 improvements for the basic classes.  The GFScreen class has been
 expanded into two subclasses.  GFScreenDD is for DirectDraw usage
 and GFScreenDIB will use GDI's DIB functions, but will use DirectDraw's
 functions to switch resolutions, if desired.

 As the MythOS libraries are developed, any application-side initialization
 will be added to the GameFrame.

 This version of GameFrame contains a simple game, called
 LLander.  LLander is a take-off on the old standby, lunar lander.
 It's extremely simple minded, but it does illustrate the techniques
 needed to write a Win95 game, including network play.  Efforts have
 been made to ensure that LLander works correctly, but there will
 doubtlessly be minor bugs, as LLander is more of a test application
 and example than a "real" game.

 LLander is implemented in the files LLander.CPP and LLander.HPP.
 Main.CPP contains some LLander-specific code as well, but may be used
 as an "outline" for initializing other games.  All other data files
 are LLander-specific as well.

 This portion of MythOS is likely to be supplanted by SimGine.

*** END OF FILE ***
