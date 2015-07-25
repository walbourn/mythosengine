
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
 Updated: January 2, 1998

 Changes for this release --------------------------------------------------

    o Camera

        - Added support for orthographic projection.
        - Fixed minor problem with assignment of clipping planes in
          perspective mode.

    o Element/Drawables/Extents

        - Updated for orthographic projection mode.
        - EschLineDraw now uses true 3D clipping.
        - Minor optimizations made in the draw routines.

    o Motion

        - Continued development and refinement for the keyframer
          classes.


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
