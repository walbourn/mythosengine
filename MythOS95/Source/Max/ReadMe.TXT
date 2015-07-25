                    ooo        ooooo                       
                    `88.       .888'                       
                     888b     d'888   .oooo.   oooo    ooo 
                     8 Y88. .P  888  `P  )88b   `88b..8P'  
                     8  `888'   888   .oP"888     Y888'    
                     8    Y     888  d8(  888   .o8"'88b   
                    o8o        o888o `Y888""8o o88'   888o 
  
                            Across the event horizon...

                          Microsoft Windows '95 Version
  
          Copyright (c) 1994, 1995, 1996 by Charybdis Enterprises, Inc.
                             All Rights Reserved.
  
  --------------------------------------------------------------------------
  
             *** Charybdis Enterprises, Inc. Company Confidential ***
  
    This file and all associated files are the company proprietary property
          of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
  
   CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
   TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
   IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
   AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
   INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
  
  --------------------------------------------------------------------------

                              _Library Status_

  Notes by: Dan Higdon
  Updated: April 2, 1996

  Changes for this release --------------------------------------------------

    o Release Version 1.1

    Added a new member to MaxEventUser that allows enumeration of
	all defined triggers.

        Added a new member to MaxKbBuffer that converts scan codes
        to ascii, where possible.

	Also, added a guard to MAXC for too many events, and 
	added #shift, #alt, and #ctrl synonyms.

        Added a new utility class MaxValueMap which allows flexible
        interpolation of values across the short integer range.

	Added an automatic polling mode to MaxJoystick which causes
	the joystick to perform its own polling (on a user-specifed
	interval), and report the current stick location plus
	the buttons that have been pressed since the last get_stat().

	Added a capabilites member to MaxJoystick.

  Pending changes -----------------------------------------------------------

    o LED calls don't do anything!

*** END OF FILE ***
