                             
            ^           **   **   **** ***** *    ****     ^      Take me to
           (_)            * *     *      *   *    *       (_)    / your
      ^                    *      **     *   *    **            ^  leader...
     (_)       ^          * *     *      *   *    *            (_)
              (_)       **   **   *    ***** **** ****

                        Microsoft Windows 95/NT Version
 
             Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
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
 Updated: January 2, 1998

 Changes for this release --------------------------------------------------

   o Minor updates to comments.


 Proposed changes ----------------------------------------------------------

   ° NOTE:  Due to the Unisys patent, XFileGIF will not be implemented. °

   o XFileMemMapped to take advantage of the Win32 memory-mapped system
     for reading files.

   o XFileRAM needs a method for attaching/loading a binary resource entry.

   o XFileX file-system-in-a-file class plus associated compactor and
     directory tools

   o XFParse classes will need changes to take advantage of XFileX classes,
     but they will only require that all code be recompiled.

   o General XFile compression and encryption support (probably as a
     special XFileDiskEx or as a filter XFile which writes to another XFile
     instance).

   o Additional XFParse bitmaps objects for new formats (PNM, IMG, JPG)

*** END OF FILE ***
