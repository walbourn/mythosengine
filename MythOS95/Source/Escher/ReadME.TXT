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
 Updated: November 12, 1997

 Changes for this release --------------------------------------------------

    o Element Sort

        - Fixed sorting bug which caused invalid max's to be choosen for
          sorting of polygons.

    o Partitioning

        - Fixed problem with the grid partitioning pick() when a max
          distance was not specified.
        - Implemented grid partitioning traverse().
        - Added draw_grid() to grid partitioning for debugging.
        - Implemented quadtree partitioning EschQuadTreePartition class
          and octtree partitioning EschOctTreePartition class.

    o Drawable

        - Added partn_data pointer for use by EschPartition classes.
        - Added ESCH_DRW_SKIPTRAVERSE bit for use by partitioning
          traverse() members.

    o Terrain

        - Special exagerate value added to compute_shades for controlling
          the effect of the normal on the terrain shading for more dramatic
          lighting effects.

    o Motion

        - Continued development and refinement for the keyframer
          classes.

    o Misc

        - Added more constructors for EschSphereExtents and EschBoxExtents.
        - Changed DOT and CROSS operations to use inline math ops instead
          of calling esch_dot and esch_cross functions.
        - Added inline transform() usage with some minor changes to the
          terrain to work around a compiler bug.
        - Flat can now be combined with Specular for specularly highlighted
          facet shading.
        - Some optimizations to various draw functions.


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
        - An orthogonal camera implementation might be useful in some
          situations -- would require changes to most of the drawables
          to support this as well as to the element clipping code.

    o Math

        - Cubic spline interpolation.

    o Drawables

        - Cubic spline drawable.
        - Tesselated object drawables.
        - EschPlaneDraw for infinite planes.
        - EschSprite may still have some rotation problems.
        - EschStarfield could use a load function.  Would be great
          if it could handle starchart input for realistic placement
          of the stars.

    o Lights

        - Regionalized lighting mechanism would be useful.
        - Shadow support using projected shadows.

    o Tools

        - Exporter plug-in for 3D Studio MAX and EschBuildCamera
          and EschBuildLight classes for use by this new tool.

    o Textures

        - EschFireTexture may need some cleanup and updated docs.

*** END OF FILE ***
