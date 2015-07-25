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

                               *** Escher Tool ***

 Notes by: Chuck Walbourn

 Last Updated: August 6, 1996

 Escher Tool - MFC Application

 Changes for this release --------------------------------------------------

 Version 1.02

    o Updated for new light types: EschFastPointLight, EschFastAttenLight,
      EschFastSpotLight, EschAttenLight, EschSpotLight.

    o Added support for extended camera features including bitmap backgrounds
      and hazing.

    o Double-clicking in the tree view brings up the properties sheet.

    o Added Render menu control for model space lighting bit.

    o Fixed bug caused when changing render bits without any defined
      camera.

    o Fixed crash when trying to DEFAULT.PAL on startup if the file
      is missing.



 Pending changes -----------------------------------------------------------

    o The Camera, Light, and Meshes properties dialogs should enforce
      unique names for the items.

    o Handling of multiple FORMs/Scenes within an IFF file for Open/Save.



 Proposed changes ----------------------------------------------------------

    o Editing of faces, verticies, and textures for meshes.

    o Rename in tree view.

    o Allow import of cameras, lights, and meshes.

    o Drag in tree view to rearrange hiearchy.

    o Scripts for automatic movement of items within viewer (using application
      bits).

    o Clipboard Cut/Copy/Paste for cameras, lights, and meshes.



 Known problems ------------------------------------------------------------

    o The palette must be selected before any mesh objects are loaded or
      created.

    o Although the Exporter outputs RGB values for the face colors of meshes, 
      the exporter sets them to the lookup value for the palette.  Therefore,
      after editing the file with Escher tool, the RGB information will be
      altered to the closest color in the palette used within the Tool, NOT
      the original RGB value from the export.

    o The items in the Light's Properties 'Extra' page do not disabled
      themselves when editing light objects that don't support them.  They
      are currently just ignored for those object.

 *** END OF FILE ***
