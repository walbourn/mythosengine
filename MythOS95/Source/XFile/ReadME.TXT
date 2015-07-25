                             
            ^           **   **   **** ***** *    ****     ^      Take me to
           (_)            * *     *      *   *    *       (_)    / your
      ^                    *      **     *   *    **            ^  leader...
     (_)       ^          * *     *      *   *    *            (_)
              (_)       **   **   *    ***** **** ****

                          Microsoft Windows '95 Version
 
             Copyright (c) 1994,1995 by Charybdis Enterprises, Inc.
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
 Updated: November 5, 1995

 Changes for this release --------------------------------------------------

    o Release Version 1.0

    o XFParseIFF now supports variations of the EA IFF format, including
      Microsoft RIFF and MIDI SMF files.  IFFC and IFFDIR have command-line
      options to utilize these options.

      
      
 Pending changes -----------------------------------------------------------

   o XFileX file-system-in-a-file class plus associated compactor and
     directory tools

   o XFParse classes will need changes to take advantage of XFileX classes,
     but they will only require that all code be recompiled.



 Proposed changes ----------------------------------------------------------

    ° NOTE:  Due to the Unisys patent, XFileGIF will not be implemented. °

   o XFileCD direct CD control and input class, as well as local disk
     caching

   o XFParseText class for generic parsing of ASCII files--lexical
     scanner

   o XFile compression support

   o XFParse bitmap writer objects to output compressed images

*** END OF FILE ***
