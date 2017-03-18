
           ////////// ////////   ////////  ///    /// ////////// ////////.
          ///       ///    /// ///    /// ///    /// ///        ///    ///
         ///       ///        ///        ///    /// ///        ///    ///
        ////////  ////////// ///        ////////// ////////   /////////
       ///              /// ///        ///    /// ///        ///   .///
      ///       ///    /// ///    /// ///    /// ///        ///    ///
     ////////// ////////   ////////  ///.   ///.////////// ///    ///.

                    Microsoft Windows 95/98/NT Version

    Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn

 ---------------------------------------------------------------------------

 THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
 OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
 PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
 LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
 OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

                        http://www.mythos-engine.org/

 ---------------------------------------------------------------------------

  This library is a component of the MythOS(tm) entertainment and multi-
  media development library.

  MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: October 23, 1998

 Changes for this release --------------------------------------------------

    o Fixed EschMetaBox class to work correctly with perspective correction and
      to pay attention to the limits flags for texturing.

    o Added EschPlaneDraw class for drawing infinite planes with lighting and texturing.

    o Fixed hither/yon clipping bug.

    o EschParticleGenerator now uses VNGO_COLOR_24BIT format for 15- and 16-
      bit devices when given RGB color ranges.

    o Added base version of 'sibling' back into EschGeometry.

    o EschCameraEx gradient background redone.

    o Added set_flags(mask, on) which takes the or'd set of flags and sets or
      clears them from the flags variable based on the value of 'on'.

    o Fixed problem with time-based particle generation (it was clearing
      the accumulator on every call to set_parts()).

    o Changed particles to have a new ESCH_PRT_CULLIFNOTVISIBLE flag instead
      of just assumming this is a valid assumption.

    o Added new ESCH_MTL_TYPE_15BIT and ESCH_MTL_TYPE_15BIT_TRANSP formats
      and updated the texture classes, builder classes, Texture Librarian,
      Escher Tool, and Escher Directory.   Also added color conversions to
      EschBuildTexture class.  Added ESCH_TXTLD_TCBITMAP/ESCH_MSHLD_TXTTCBM
      functionality for use by Escher Tool to retain original data format on
      texture load.

    o Moved partitioning drawables into PARTN directory from DRAW; moved
      terrain drawables into TERRAIN directory from DRAW.

    o Changes for Escher Exporter, Escher Tool, and Terrain Editor.
      See Export\ReadME.TXT, Tool\ReadME.TXT, and Edit\ReadME.TXT


 Proposed Changes -----------------------------------------------------------

    o Needs a 3D Studio MAX Plugin for exporting data directly from MAX.


 Future notes ---------------------------------------------------------------

 This library and all associated tools will be retired in a future release
 of MythOS and replaced with an entirely new 3D pipeline.

*** END OF FILE ***
