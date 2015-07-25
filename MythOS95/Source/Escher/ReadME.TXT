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

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: October 8, 1997

 Changes for this release --------------------------------------------------

    o Changed EschCameraEx extensively to take advantage of new functionality
      within Van Gogh for both hazing/fogging and 15/16-bit devices.
      Previous use of the bitmap background and hazing interface will fail
      to compile and will need updating for the new interface.

    o Added app_data pointers to EschCamera, EschTexture, EschLight,
      and EschFace to match that found in EschDrawable.

    o Updated EschFace structure to provide space for alpha values and
      some other parameters.  Updated all load code to handle older
      data format and to use new format.

    o Added rotation and scale factors to EschSprite and rate
      support to EschParticleSprite for these values.

    o Terrain

        - Terrain load function now takes a palette pointer for use by
          texture load changes.
        - Minor change to terrain data format to make implementation of
          shared texture-files feasible.
        - Updated load code with control flags for texture handling and
          setup to match logic in EschMesh (MTL chunk triggers use of
          shared cache and registered texture files, load any missing
          textures from local form).
        - Added EschTerrain::get_surface_color() routine.
        - Documented EschTerrainEx and EschTerrainTreeTop classes.
        - Continued development/debugging for EschTerrainTreeTops.

    o Mesh

        - Updated load to match logic in EschTerrain when there is no
          MTL chunk (just load each material in the local form in
          order they are encountered).
        - Added a clone() routine.

    o Math

        - Moved set_top and set_direction routines into EschFrameRef
          since a number of drawables had duplicated code for these.
        - Unified usage of EschFrameRef to include the standard
          transformation routines as helpers for all drawables that
          utilize it.
        - Changed the maximum orthongonalize count to 4096 since floating
          point has far less drift than the fixed-point version.
        - Added some minor routines to EschPoint and a new constructor
          for EschVector.
        - Added math routines for EschPlane.

    o Particles

        - Added EschParticleGenerator class to handle dynamic creation
          issues for particles using spherical, circular, or rectangular
          generation areas and stochasitic parameters.
        - EschParticle lifetime now has time-based lifetime mode and
          lifetime is now in a 'float' rather than a ulong.  This also
          affected the EschParticle-derived classes.
        - Added alpha support to EschParticlePyramid.
        - Moved particle-related drawable classes from DRAW to PARTICLE
          subdirectory.

    o Textures

        - Updated for new Van Gogh changes in VngoTexture.
        - Added registered texture file interface to allow texture data
          in individual data files to be extracted or overridden by
          one or more 'central' shared texture data files.
        - Fixed problem with texture-cache handling of names which had
          resulted in invalid 'name' pointers in shared texture references
          when the texture cache was expanded.

    o Updated all usage of XFile when reading files to deny only write-mode
      sharing, thereby allowing read-mode sharing.

    o Fixed load routines which take a filename to correct bug with
      form scanning.

    o Changes made to Exporter, Tool, and Editor.  See the ReadME.TXT
      files for more details.  Updated Directory utility for latest data
      file changes.

    o Created ESHTLIB utility for creating shared texture files and
      optionally texture stripped remainder files, plus dumping IFF
      texture data to bitmaps.

    o Added load() routines to EschBuildTexture.

    o Minor changes for working with Van Gogh.



 Pending changes -----------------------------------------------------------

    o Element Sort

        - Implement more sophisticated scheme to resolve some common
          missorting cases with Zmax-only approach that is currently
          in use.

    o Partitioning

        - Implement traverse
        - Implement EschQuadTreePartition
        - Extend QuadTree to EschOctTreePartition

    o Camera

        - Gradient background needs completion/debugging.

    o Exporter plug-in for 3D Studio MAX and EschBuildCamera/EschBuildLight
      classes for use by this new tool.

    o Math

        - Cubic Spline Interpolation

    o Drawables

        - Cubic Spline drawable
        - Tesselated object drawables

    o Other
       
        - EschFireTexture may need some cleanup and updated docs.
        - EschStarfield could use a load function.
        - EschSprite may still have some rotation problems.

*** END OF FILE ***
