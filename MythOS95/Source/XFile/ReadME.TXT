                             
            ^           **   **   **** ***** *    ****     ^      Take me to
           (_)            * *     *      *   *    *       (_)    / your
      ^                    *      **     *   *    **            ^  leader...
     (_)       ^          * *     *      *   *    *            (_)
              (_)       **   **   *    ***** **** ****

                          Microsoft Windows '95 Version
 
             Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.
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
 Updated: July 1, 1996

 Changes for this release --------------------------------------------------

   o XFBitmap now has a 'create' helper routine to properly allocate and
     lock data space.

     Added 'generate_mono' helper routine to create a Van Gogh compatable
     monochrome bitmap from an 8-bit image.

   o XFParseLBM can now be used with XFParseIFF instances configured for
     Microsoft's RIFF format.

   o XFParseXEB implemented and documented.
   
   o IFFC updated to support XEB format and added -e option to prevent
     'Empty Chunk' warnings.

     Added new keywords 'maxsize' and 'ntext'.
     
     Added alias names for common data types: 'char', 'short', and 'ushort'



 Proposed changes ----------------------------------------------------------

    ° NOTE:  Due to the Unisys patent, XFileGIF will not be implemented. °

   o XFileX file-system-in-a-file class plus associated compactor and
     directory tools

   o XFParse classes will need changes to take advantage of XFileX classes,
     but they will only require that all code be recompiled.

   o XFileCD direct CD control and input class, as well as local disk
     caching

   o XFParseText class for generic parsing of ASCII files--lexical
     scanner

   o XFile compression support

   o XFParse bitmap writer objects to output compressed images

*** END OF FILE ***
