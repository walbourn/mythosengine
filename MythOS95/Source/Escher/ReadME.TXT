 ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
 שששששששששש//////////ש////////ששש////////שש///שששש///ש//////////ש////////.שש
 ששששששששש///ששששששש///שששש///ש///שששש///ש///שששש///ש///שששששששש///שששש///שש
 שששששששש///ששששששש///שששששששש///שששששששש///שששש///ש///שששששששש///שששש///ששש
 ששששששש////////שש//////////ש///שששששששש//////////ש////////ששש/////////ששששש
 שששששש///שששששששששששששש///ש///שששששששש///שששש///ש///שששששששש///ששש.///ששששש
 ששששש///ששששששש///שששש///ש///שששש///ש///שששש///ש///שששששששש///שששש///שששששש
 שששש//////////ש////////ששש////////שש///.ששש///.//////////ש///שששש///.שששששש
 ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
 שששששששששששCopyrightש(c)ש1994,ש1995שbyשCharybdisשEnterprises,שInc.ששששששששש
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

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: Nov 7, 1995

 Changes for this release --------------------------------------------------

    o Release Version 1.0

    Removed copy constructors to avoid problem with MS VC v2.x.

    o Camera

        - Removed hazing for now, until Van Gogh palette changes are
          complete.

    o Exporter

        - Moved DOS Exporter over to Windows 95 tree using a mix of 
          new and old headers (must link with old XFile and has local 
          copy of Van Gogh palette code).

    o Extents

        - Simplified test API.

    o Lights

        - Minor change to lights to use new Van Gogh palettes.

    o Meshes

        - Fixed problem with color assignment for some objects in smooth/
          specular modes.

    o Terrain

        - Terrain Editor implemented.
        - Textures implemented.
        - compute_shades() now needs a full Camera pointer instead of just
          the camera flags.

    o Texture

        - Added release() and load() members.

    Virtualized a number of members in some classes for future extention.



 Pending changes -----------------------------------------------------------

    o Camera

        - Need to change to use Van Gogh offset image transfer so that
          bitmap offsets/size is used.

    o Exporter
 
        - May need changes for multiple instances of identical mesh.
        - Changes for exporting multi-frame/animated textures.

    o Extents

        - Need to do picking.
        - Need to collision detection.

    o Lights

        - Implement 'fast' multiple-light approximation (reduces all
          lights to a single vector and ambient term).

    o Scenes

        - Handle multiple instances of identical meshes.

    o Meshes

        - Transform performance.
        - Level-of-detail control.

    o Particles

        - Needs damage rectangle handling.
        - Needs depthque (cue?) tested.
        - Load from external file.

    o Terrain

        - Level-of-detail control.
        - API calls for querying the height-field database.
        - Hit detection with height-field.
        - Textures

    o Textures

        - Van Gogh will need 'handle-based' texture control with
          all management in Escher.
        - Need to have shared library of materials.
        - Multi-frame/animated textures

    o Other
       
        - Other object format converters.
        - Post-filtering.



 Known problems ------------------------------------------------------------

    o Inverse, may need to be changed to use 64-bit internal math.
      Will need to use 64-bit for determinant as well.

    o Dot product, in some cases, is returning a value greater than 1
      given two normalized vectors...  Possibly only a little greater than
      1--this is probably in Felix.

    o "More-accurate" Felix sqrt will cause orthonormalize to fail, why?

    o Need to look at center of object in 3D Studio to ensure we are
      able to position the objects correctly about their center.

*** END OF FILE ***
