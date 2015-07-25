                             
            ^           **   **   **** ***** *    ****     ^      Take me to
           (_)            * *     *      *   *    *       (_)    / your
      ^                    *      **     *   *    **            ^  leader...
     (_)       ^          * *     *      *   *    *            (_)
              (_)       **   **   *    ***** **** ****

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

  This library is a component of the MythOS(tm) entertainment and multi-
  media development library.

  MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: Febuary 2, 1997

 Changes for this release --------------------------------------------------

   o General cleanup and rearrangement of source tree.

   o Changed XFParseXEB to expose the supporting compression routines
     for use by other classes and added support for 16-bit, 24-bit,
     and 32-bit compressed images and uncompressed usage if compressed
     information larger than original.

   o XFParseIFF::topofcontext now accepts a donext flag to control the
     call of next() after resetting the top of context.

   o Added XFParseCEL::read/write routines to access the x- and y-coordinate
     information in the CEL header.

   o Changed IFFC so that merge/binary chunks open the file with read share
     priviledges.



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

   o XFParse bitmap writer objects to output compressed images and support
     for 2bpp and 4bpp.

   o Additional XFParse bitmaps objects for new formats.

*** END OF FILE ***
