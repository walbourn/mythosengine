
           ////////// ////////   ////////  ///    /// ////////// ////////.
          ///       ///    /// ///    /// ///    /// ///        ///    ///
         ///       ///        ///        ///    /// ///        ///    ///
        ////////  ////////// ///        ////////// ////////   /////////
       ///              /// ///        ///    /// ///        ///   .///
      ///       ///    /// ///    /// ///    /// ///        ///    ///
     ////////// ////////   ////////  ///.   ///.////////// ///    ///.

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
 PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIM ANY
 LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
 OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

                        http://www.mythos-engine.org/

 ---------------------------------------------------------------------------

  This library is a component of the MythOS(tm) entertainment and multi-
  media development library.

  MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                               *** Escher Tool ***

 Notes by: Chuck Walbourn

 Last Updated: October 21, 1998

 Escher Tool - MFC Application

 Changes for this release --------------------------------------------------

 Version 2.06

    o Added 15-bit texture file format suppport.

    o Added preserving load/save code for texture data to ensure that
      15-, 24-, and 32-bit texture data can be saved in a Truecolor
      format without being recolored to the palette.



 Pending changes -----------------------------------------------------------

    o Auto-detect of 15- vs 8-bit mode.

    o Support for full-screen mode with 3D hardware

    o The Camera, Light, and Meshes properties dialogs should enforce
      unique names for the items.

    o Handling of multiple FORMs/Scenes within an IFF file for Open/Save.



 Proposed changes ----------------------------------------------------------

    o Rename in tree view.

    o Allow import of cameras, lights, and meshes.

    o Drag in tree view to rearrange hiearchy.

    o Scripts for automatic movement of items within viewer (using application
      bits).

    o Clipboard Cut/Copy/Paste for cameras, lights, and meshes.



 Known problems ------------------------------------------------------------

    o The palette must be selected before any mesh objects are loaded or
      created to ensure proper coloring.

    o Although the Exporter outputs RGB values for the face colors of meshes, 
      the exporter sets them to the lookup value for the palette.  Therefore,
      after editing the file with Escher tool, the RGB information will be
      altered to the closest color in the palette used within the Tool, NOT
      the original RGB value from the export.

    o The output of the texture data is controlled by settings within the
      File menu and is NOT based on the input format.  The data can
      be output as 8-bit or Truecolor (15-, 24-, or 32-bit format)
      and either compressed or uncompressed.

    o The items in the Light's Properties 'Extra' page do not disabled
      themselves when editing light objects that don't support them.  They
      are currently just ignored for those object.

 Future notes ---------------------------------------------------------------

 This library and all associated tools will be retired in a future release
 of MythOS and replaced with an entirely new 3D pipeline.


 *** END OF FILE ***
