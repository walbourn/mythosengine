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
 Updated: March 4, 1997

 Changes for this release --------------------------------------------------

    o Directory
        - Updated for new data files.

    o Edit
        - See Edit/ReadME.TXT

    o Export
        - See Export/ReadME.TXT

    o Tool
        - See Tool/ReadME.TXT

    o Utility
        - Added Escher Lightwave converter as an example of using the
          new mesh builder class.

    o Build
        - Added a new BuildMesh class to create new objects directly
          under program control and save the data into IFF files for
          later use.
        - Added a supporting BuildTexture class for creating
          texture data files.

    o Camera
        - Changed hazing interface to take a cut-off Z value
          for performance.
        - Added a gradient-background mechanism which is sensitive
          to camera view-angle for use as a gradient-sky effect
          with the terrain system.
        - Added view frustrum information for use by 3D clipping code.

    o Drawable
        - Added data pointer to for use by the application.
        - Added ESCH_DRW_VISIBLE bit which is set when a drawable
          has determined that it is not being rejected due to clipping.
          The application must clear this bit for any drawable it
          needs to track this information for.

    o Geometry
        - Was not passing animate calls down to children drawables.
        - Some performance fixes for ray/hit.

    o Meshes
        - Fixed minor bug which prevented early trivial rejection of
          child objects based on the extents check.
        - Fixed minor bug with loading object data file without
          an orientation matrix.
        - Added control flags and parameters for texture changes.
        - Added special owns bits to control deletion of meshdraw owned
          texture instances.
        - Some performance fixes for ray/hit.

    o Extents
        - Some performance fixes for hit/ray tests.

    o Partition
        - Defined basic partitioning interface and implemented most
          of Grid paritioning (no traverse function yet).

    o Scenes
        - Added control flags for texture changes.

    o Sprites
        - Added some early rejection and fully visible tests for sprites.
        - Added Alpha Blending support.

    o Explosions
        - Added a 'circular' mode to the EschPlosion class.
        - Was missing set_top/set_direction function bodies.

    o Textures
        - Added create member and time-based animation logic to
          multi-frame texture.
        - Fixed problem with multi-frame texture lock.
        - Added extra parameters to load needed for texture changes.
        - Added multi-frame texture load.
        - Added support for compressed data and 24/32-bit dynamically
          recolored formats.
        - Added run-time type.
        - Added texture cache for sharing texture data between
          instances.

    o Terrain
        - Added optional parameter for check_LOS to return approx
          distance of hit from first point.
        - Added get_surface_flags() function.

    o Tester
        - Cleaned up tester and added support for new features.

    o Restructured source directories to split some source files into
      sub-directories
     
        Build\      - Builder classes
        Draw\       - Drawables and support
        Light\      - Lights
        Math\       - Math support
        Texture\    - Textures

    o Some minor cleanup: Added a few missing copy constructors/operator =
      overloads and fixed up some 'const' issues.

    o Changed find() implementation for Camera, Light, and Drawable to
      use 'find' function to call down the chain.  This makes the find()
      functions easier to overload.

    o Added Alpha-blending support.  This is controlled on a face-by-face
      basis.

    o Fixed a memory problem with the Fire Texture.

    o Added EschProposedTris and EschDrawnTris variables to
      esch_clipdraw_face for benchmarking.

    o Some extensions to EschPlosion.

    o Fixed problem with orthogonalize in some circumstances.

    o Added EschParticleSprite, EschMetabox, and EschLineDraw drawables.

    o Added EschPlane math support class.

    o Updated for new Van Gogh release with change to Texture::create
      for controlling transparent vs. non-transparent textures.

    o EschLevelOfDetail drawable has been implemented.

    o Updated documentation.



 Pending changes -----------------------------------------------------------

    o Textures

        - Export/load as 24-bit with alpha channel and map down to
          palette.
        - Use XFEB for texture data.
        - Multi-frame/animated textures loading
        - Van Gogh will need 'handle-based' texture control with
          all management in Escher.
        - Need to have shared library of bitmaps.

    o Drawable/Partitioning

        - Add Partitioning interface.
        - Implement QuadTree partitioning scheme.

    o Meshes

        - Add multiple levels of detail.

    o Terrain

        - Reimplementation for faster performance.

    o Camera

        - Once hardware support for hazing/fogging is added to 
          Van Gogh, the EschCameraEx will need to check for this
          and disable post-process filtering.

    o Other
       
        - Other object format converters.
        - EschFireTexture may need some cleanup and updated docs.
        - EschPlosion may be rewritten or expanded.
        - EschStarfield could use a load function.
        - EschSprite may still have some rotation problems.

*** END OF FILE ***
