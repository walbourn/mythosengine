            __ ,                                                      
             ,-| ~           ,               ,,                      
            ('||/__,        ||               ||                  _   
           (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\ 
           (( |||==| || ||  ||   || \\ || || || || || \\  ||   || || 
            ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || || 
             -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-| 
                                                                /  \ 
                                                               '----`
                      Text Output and Font Management System
 
                           Microsoft Windows '95 Version

             Copyright (c) 1995, 1996 by Charybdis Enterprises, Inc.
                            All Rights Reserved.

 ----------------------------------------------------------------------------
 
            *** Charybdis Enterprises, Inc. Company Confidential ***
 
   This file and all associated files are the company proprietary property
         of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
 
  CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
  TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
  IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
  AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
  INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
 
 ----------------------------------------------------------------------------

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: July 15, 1996

 Changes for this release ---------------------------------------------------

    o Cleaned up the "const-ness" of a number of parameters, etc.

    o Added out_wrap to allow wrapping a string to a given rectangle
      (default is the current viewport rectangle);

    o Minor change for new Van Gogh release

    o Changed gberg_select_font/strings to keep old data active if new name
      is not installed.

    o Added gberg_remove_font/strings() calls.

    o GFONT converter now supports creating a font from bitmap and several
      fonts are included.



  Proposed changes ----------------------------------------------------------

    o Faster string 'search' for loadstring by having compiler build a
      binary search tree and having loadstring use it.

    o Four color font support (3x6 font needs this to be readable).

*** END OF FILE ***




















