                             
            ^           **   **   **** ***** *    ****     ^      Take me to
           (_)            * *     *      *   *    *       (_)    / your
      ^                    *      **     *   *    **            ^  leader...
     (_)       ^          * *     *      *   *    *            (_)
              (_)       **   **   *    ***** **** ****

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

  This library is a component of the MythOS(tm) entertainment and multi-
  media development library.

  MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: August 24, 1998

 Changes for this release --------------------------------------------------

   o Added 15-bit support to the BMP reader/writer.


 Proposed changes ----------------------------------------------------------

   ° NOTE:  Due to the Unisys patent, XFileGIF will not be implemented. °

   o XFCompress class that acts as an interface to ZLIB.  Possibly a
     XFParseZIP class.

   o XFParsePNG, XFParseJPEG making use of freeware libraries.

   o XFileMemMapped to take advantage of the Win32 memory-mapped system
     for reading files.

   o XFileRAM needs a method for attaching/loading a binary resource entry.

*** END OF FILE ***
