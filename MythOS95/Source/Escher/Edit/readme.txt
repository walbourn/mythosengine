 ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
 שששששששששש//////////ש////////ששש////////שש///שששש///ש//////////ש////////.שש
 ששששששששש///ששששששש///שששש///ש///שששש///ש///שששש///ש///שששששששש///שששש///שש
 שששששששש///ששששששש///שששששששש///שששששששש///שששש///ש///שששששששש///שששש///ששש
 ששששששש////////שש//////////ש///שששששששש//////////ש////////ששש/////////ששששש
 שששששש///שששששששששששששש///ש///שששששששש///שששש///ש///שששששששש///ששש.///ששששש
 ששששש///ששששששש///שששש///ש///שששש///ש///שששש///ש///שששששששש///שששש///שששששש
 שששש//////////ש////////ששש////////שש///.ששש///.//////////ש///שששש///.שששששש
 ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
 שששששששששששCopyrightש(c)ש1994-1996שbyשCharybdisשEnterprises,שInc.שששששששששש
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

 Last Updated: August 16, 1996

 Escher Terrain Editor - MFC Application

 Changes for this release --------------------------------------------------

 Version 1.31

 o The shift left-click shortcut for assigning textures now supports a
   rectangle area set.  Colors may be set by selecting a color in the
   Color Definitions listbox instead of a texture.

 o Added new bits for applications and for new terrain system--dropping
   water/fire/smoke bits from terrain data--to surface, texture, and color
   flags property sheets.  A new view mode displays the application bits
   on shaded terrain.

 o Added Load and Save Textures commands to read and write the texture
   definitions to an ASCII file and two similar commands for color
   definitions.

 o The texture definition dialog now includes a View button to view the
   currently selected bitmap file as it would appear in the current palette.
   Also includes a 'Create New Texture' button for generating a new texture
   from a 'transparent' master texture or from base colors or another
   bitmap.

 o Added one-level undo for the surface information grid (surface colors,
   attributes, and texture assignments).

 o Terrain level-of-detail controls have been added to the View Properties
   dialog.

 o Added 'hover' mode which causes the camera to maintain a fixed height
   above the terran and can be moved in X and Z.  The hover height can be
   set in the view properites dialog.

 o Added light properties dialog and support for Point, Attenuated, and Spot
   lights to the render view (Ambient and fast lights are not allowed since
   do not work well with terrain drawables).

 o Added option to display surface information as basic colors, shaded
   colors, textures only, height-based colors, or based on application bits.

 o Surface information display has been 'flipped' to allow easier setup
   of texture bitmaps.

 o Added terrain properties page for assignment of heights to color bands. 
   Data is included in the terrain export.

 o CST file now includes camera and lights data, height-color bands
   information, and other misc. settings.

 o Custom color dialog picker is now in use.

 o Cleaned up dialogs.

 o Added compressed normals output for export.

 o Automatic use of the VR Labs DECOMP utility when importing a compressed
   VistaPro DEM file.

 o Added new methods for converting VistaPro DEMs to Escher terrain using
   a height table instead of a direct scale value.  Fixed problem with
   inversing of DEM data on import.

 o Added USGS DEM terrain import for height data.

 o Added Edit/Flip Horizontal, Edit/Flip Vertical, and Edit Rotate 90
   commands.

 o Added Edit/Assign by commands for assiging textures/colors based
   on elevations, random roll, and surface angle.

 o Added Terrain/Set base elevation option to control height-table values.

 o Added support for extended camera features including bitmap backgrounds
   and hazing.



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
