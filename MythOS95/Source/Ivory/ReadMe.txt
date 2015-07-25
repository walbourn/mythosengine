 ============================================================================
  
                       Ivory -- A Memory Management Library
                          Microsoft Windows '95 Version
 
             Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
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
 
 ============================================================================

                             _Library Status_

 Notes by:  Dan Higdon
 Updated:  November 6, 1995

  Changes for this release --------------------------------------------------

    o Release 1.0

    o A special version of Ivory (IvoryMFC) is built for use with
      MFC.  This version basically stubs the standard allocation routines
      to avoid conflict with MFC.  This version can also be substituted
      for standard Ivory if Ivory seems to be having stability problems.

  Pending changes -----------------------------------------------------------

    o Debug version with sentinal checking, memory-leak checking, etc.

    o Verify commit/decommit code for optimal use.  Should "free"
      blocks be decommitted before they can be returned to wildspace?
      Probably not, but this should be discussed.

*** END OF FILE ***
