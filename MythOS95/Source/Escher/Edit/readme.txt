 ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
 שששששששששש//////////ש////////ששש////////שש///שששש///ש//////////ש////////.שש
 ששששששששש///ששששששש///שששש///ש///שששש///ש///שששש///ש///שששששששש///שששש///שש
 שששששששש///ששששששש///שששששששש///שששששששש///שששש///ש///שששששששש///שששש///ששש
 ששששששש////////שש//////////ש///שששששששש//////////ש////////ששש/////////ששששש
 שששששש///שששששששששששששש///ש///שששששששש///שששש///ש///שששששששש///ששש.///ששששש
 ששששש///ששששששש///שששש///ש///שששש///ש///שששש///ש///שששששששש///שששש///שששששש
 שששש//////////ש////////ששש////////שש///.ששש///.//////////ש///שששש///.שששששש
 ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
 שששששששששששCopyrightש(c)ש1994-1997שbyשCharybdisשEnterprises,שInc.שששששששששש
 ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
 ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
 ששששששששששששששששששששש Microsoft Windows '95 Version ששששששששששששששששששששששש
 ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
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

                         *** Escher Terrain Editor ***

 Notes by: Chuck Walbourn

 Last Updated: September 16, 1996

 Escher Terrain Editor - MFC Application

 Changes for this release --------------------------------------------------

 Version 1.41

 o Added support for compressed texture export.



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

 *** END OF FILE ***
