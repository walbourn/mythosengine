
           ////////// ////////   ////////  ///    /// ////////// ////////.
          ///       ///    /// ///    /// ///    /// ///        ///    ///
         ///       ///        ///        ///    /// ///        ///    ///
        ////////  ////////// ///        ////////// ////////   /////////
       ///              /// ///        ///    /// ///        ///   .///
      ///       ///    /// ///    /// ///    /// ///        ///    ///
     ////////// ////////   ////////  ///.   ///.////////// ///    ///.

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

                               *** Escher Tool ***

 Notes by: Chuck Walbourn

 Last Updated: January 2, 1998

 Escher Tool - MFC Application

 Changes for this release --------------------------------------------------

 Version 2.04

    o Added Orthogonal camera support.



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
      be output as 8-bit or Truecolor and either compressed or uncompressed.
      The Truecolor output uses the closest RGB values within the palette
      even if the original file was stored as Truecolor.  Also, alpha
      values will be set to 0 or 255 for transparent Truecolor output.

    o The items in the Light's Properties 'Extra' page do not disabled
      themselves when editing light objects that don't support them.  They
      are currently just ignored for those object.

 *** END OF FILE ***
