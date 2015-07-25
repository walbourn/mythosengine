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

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: August 26, 1996

 Changes for this release --------------------------------------------------

    o Documentation updated.
        - Release 1.1 didn't have complete documentation for
          EschParticleSystem or EschParticleGeometry.
        - Reorganized a few of the classes in the contents for easier
          reference.
        - Updated docs for changes.

    o Directory
        - Updated for new lights and terrain changes.

    o Exporter
        - See Exporter\ReadME.TXT

    o Editor
        - See Edit\ReadME.TXT

    o Tool
        - See Tool\ReadME.TXT

    o Lights
        - Added EschFastPointLight for point source approximation with
          the same lighting cost as vector lights.
        - Added EschFastAttenLight and EschAttenLight for attenuated
          point sources.
        - Added EschFastSpotLight and EschSpotLight for directional
          point sources with attenuation.
        - Added copy constructor and operator =.

    o Sprite
        - A new sprite drawable was added for objects drawn as a 
          scaled 2D bitmap, including a mode for extremely distant
          objects.

    o Drawable
        - Fixed problem with picking returning incorrect drawables
          due to errors in result sorting.
        - Added copy constructor and operator =.

    o MeshDraw
        - Added use of ESCH_FACE_SELFILUM levels.
        - Added copy constructor and operator =.

    o Scene
        - Updated for new lights.
        - Added ESCH_SCENELD_CAMSEX to create extended camera instances.

    o Terrain
        - Changed height-field to use lookup-table instead of direct
          linear scale value.
        - Load has optional parameter to get at 'height-color' assignments
          used in the terrain editor.
        - Fixed 'black' triangles along one edge of the High/Medium
          detail boundary.
        - Added routine to check for a clear 'line-of-sight' relative
          to the terrain.
        - Added support for loading compressed normals.
        - Redefined some surface bits and added 4 application bits.
        - Added low level of detail usage.

    o Geometry
        - 'find' didn't always work correctly.  This has been corrected.
          This caused problems when loading some models with hierarchial
          links.
        - Added copy constructor and operator =.

    o Clip
        - Fixed clipping problems for U, V, Z, and shading caused by
          perspective on long polygons.
        - Fixed minor edge condition for clip.
        - Performance enhancement to the backface culling within the
          clip routine.

    o Camera
        - Changed internal interface for render() to use
          pre_rend(), rend(), and post_rend() internal protected members.
        - Added render control bits for new render().
        - Added support for scrolling bitmap backgrounds with offsets.
        - Added hazing using post-processing software-only solution.
        - Added usage of update flags for scalar values.
        - Added copy constructor and operator =.

    o Textures
        - Added copy constructor and operator =.

    o Misc.
        - Starfield completed and documented.
        - Matrix and FrameRef's now have contructors that do not
          initialize any data members.  These can be used when the
          instance is a target of a concat operation, but not a source.
        - Added 'create' member to EschStaticTexture for creating textures
          directly from XFile bitmaps.
        - Minor change to texture code for new Van Gogh.
        - Fixed minor problem with clearing of EschFireTexture.

         
          
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
