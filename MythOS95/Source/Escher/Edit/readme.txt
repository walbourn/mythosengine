
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

                         *** Escher Terrain Editor ***

 Notes by: Chuck Walbourn

 Last Updated: October 12, 1998

 Escher Terrain Editor - MFC Application

 Changes for this release --------------------------------------------------

 Version 2.12

 o Updated for 15-bpp bitmap formats (TGA, BMP).

 Version 2.11

 o Updated for new EschCameraEx interface for hazing/background bitmaps.

 Version 2.10

 o Added missing 'MTL ' chunk which will be needed for shared texture-file
   loading.

 o Changed to use EschTerrainEx for render view.



 Proposed changes ----------------------------------------------------------

 o Multiple light sources for complex 'pre-lighting' to take advantage
   of the saving of shade values into the export.  Lighting information
   should be exportable to the IFF for loading assoicated lights as Fast
   lights into Escher.

 o The render view camera's location (and lights) should be indicated on the
   surface grid.

 o Perhaps need a 'Reset' button for Camera properties.

 o A zoom to rectangle option would be convient.

 o Texturing tools for assigning textures by elevation, by picking from
   a random roll, and based on slope.

 o Need to add support for compressed data output.



 Known problems ------------------------------------------------------------

 o There are some problems with the render view locking up on occasion when
   using non-DOTS mode.  You are strongly advised to SAVE BEFORE USING THE
   RENDER VIEW.  The problem seems to occur most often when in Hover mode.

 o If the render mode is set to Wire or Solid, then the 'shaded' version of
   the Surface Information Grid will appear the same as the 'colors' version
   since all shades are set to the palette's mid-point.

 o If the same bitmap is used for multiple textures, it will be exported
   and subsequently loaded multiple times.  Any unused bitmaps defined
   during export will also be exported.  The Surface/Remove Unused Definitions
   option may be used to remove these unreferenced textures.

 o If you move a child window accidentially, you can resize the main window
   to restore the original window locations.

 Future notes ---------------------------------------------------------------

 This library and all associated tools will be retired in a future release
 of MythOS and replaced with an entirely new 3D pipeline.

 *** END OF FILE ***
