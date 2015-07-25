  
                                                             %__________%
                                                            %/ . .  .   \%
             Van Gogh 2D-Display Library                     |  . .  o. | 
                                                             |. _  .   .|
   Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    | / \   .  | 
                All rights reserved.                         |_|_|_._._.|
                                                             |.-.-.-.-..|
                                                            %\__________/%
                                                             %          %
  
  ----------------------------------------------------------------------------
  
             *** Charybdis Enterprises, Inc. Company Confidential ***
  
    THIS FILE AND ALL ASSOCIATED FILES ARE THE COMPANY PROPRIETARY PROPERTY
          OF CHARYBDIS ENTERPRISES, INC.  UNAUTHORIZED USE PROHIBITED.
  
   CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
   TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
   IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
   AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
   INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
  
  ----------------------------------------------------------------------------

                            _Library Status_

  Notes by:  Tim Little
  Updated:   July 31, 1997

  Changes for this release --------------------------------------------------

    o This release is reworked in many ways from previous releases with
      a general cleanup and removal of obsolete functions.

    o 3D hardware implementations of Direct3D and Cirrus Clear3D are
      mostly complete except for on-board texture caching management--for
      now when the board's texture memory is full, all additional
      textured polygons are ignored.  Additional work needs to be done to
      check for caps bits, etc.

    o Added new viewport flag VNGO_TRUE_ALPHA which activates software-based
      alpha blending.

    o DirectDraw support has been completed.

    o Added screen manager classes to simplify setup and management of
      devices and the associated viewports.

    o Fixed a z-buffer bug in the linear flat shadded texture mapper.

    o Added new vngo_stretch_blt functions.

    o New sub-pixel accurate polygon scan-converters.

    o Documentation has been completed for all classes except 3D
      hardware classes which are still under development.

    o Van Gogh tester has been included in this release.

    
  Pending changes -----------------------------------------------------------

    o Completion of texture management for Direct3D and Cirrus Clear3D.

    o The screen manager check_mode() functions need to be implemented.

    o Implementation of 3D/fx Glide and Matrox Simple Interface 3D
      viewports/screen managers.

    o Possibly add 24-bit/32-bit display support.

    o More features for PalTool.

*** END OF FILE ***

