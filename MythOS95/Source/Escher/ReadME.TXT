
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

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: March 20, 1998

 Changes for this release --------------------------------------------------

    o Element

        - Internal changes and optimizations for the clipping routines.
        - Lines now properly clip in 3D.

    o Particles

        - Added EschParticleLine class.
        - Various changes and opimizations.  These have not been fully
          developed or documented at this time.

    o Terrain

        - Optimizations and bug fixes for the terrain and tree tops.

    o Math

        - Added first cut of AMD-3D Technology enhancements: esch_transform,
          esch_transform_notran, esch_cross, esch_normalize, and
          esch_concatmatrix are now function pointers set by the
          enable_amd3d() member of EschSystem to AMD-3D only versions.


 Pending changes -----------------------------------------------------------

    o Element Sort

        - Implement more sophisticated scheme to resolve some common
          missorting cases with Zmax-only approach that is currently
          in use (TRUESORT).

    o Partitioning

        - Quad/Octtree optimizations for draw(), pick(), and direction
          traverse() walks.
        - BSP-based partitioning methods -- this requires a method for
          creating the partitioning off-line since the BSP-build process
          cannot be done effectively in real-time.

    o Camera

        - Gradient background needs completion/debugging.

    o Math

        - Cubic spline interpolation.
        - 4X4 matrix implementations
        - esch_detmatrix() and esch_inversematrix() could have AMD-3D
          versions.

    o Drawables

        - Cubic spline drawable.
        - Tesselated object drawables.
        - EschPlaneDraw for finite and infinite planes.
        - EschSprite may still have some rotation problems.
        - EschStarfield could use a load function.  Would be great
          if it could handle starchart input for realistic placement
          of the stars.
        - The terrain drawables don't seem to work correctly in ORTHO mode.

    o Lights

        - Regionalized lighting mechanism would be useful.
        - Shadow support using projected 'fake' ground-plane shadows.
        - Colored lights (will require changes to Van Gogh).

    o Tools

        - Exporter plug-in for 3D Studio MAX and EschBuildCamera
          and EschBuildLight classes for use by this new tool.

    o Textures

        - EschFireTexture may need some cleanup and updated docs.
        - Rework to use a more generic "materials" interface.

    o Total rewrite planned for MythOS 98

*** END OF FILE ***
