 ---------------------------------------------------------------------------

                              S I M   G I N E

             __               ___   ______,-------
           __==__,------------/|\--|      | .-.-.|    ___________
         (|     |--------------|---|------| '-`-`|  _/___________\_
         (|_____|      _       _   |   _  | 6000 | |               |
          |__\\_|`-._/___\___/___\_|_/___\|      | |               |
         __/ |===|--|_____|_|_____|_|___  |\_____|=|_______________|
      |=|[_]==[_]    \ _ /   \ _ /   \ _ /          [_]   [_]   [_]
 ---------------------------------------------------------------------------

                     A Simluator Framework for MythOS(tm)

                        Microsoft Windows '95 Version

               Copyright (c) 1997 by Charybdis Enterprises, Inc.
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

  This library is a component of the MythOS(tm) entertainment and multi-
  media development library.

 MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: October 8, 1997

 Changes for this release --------------------------------------------------

 o Updated SimScreen classes to clean up interface and to update for new
   15/16-bit bit-depth error handling in Van Gogh for automatic determination
   of 15 vs. 16-bit devices.  Also updated for new Van Gogh capture() routine.

 o Updated Max device initialization to check for failed DirectInput
   initialization and fallback onto Win32 if it does.

 o Logic fix for SimScreen load_palette() routine to fix potential invalid
   memory access bug.

*** END OF FILE ***

