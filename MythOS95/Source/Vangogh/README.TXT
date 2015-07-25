
                                                             %__________%
                                                            %/ . .  .   \%
             Van Gogh 2D-Display Library                     |  . .  o. |
                                                             |. _  .   .|
           Microsoft Windows 95/NT Version                   | / \   .  |
                                                             |_|_|_._._.|
   Copyright (C) 1994-1998 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
                  All rights reserved.                      %\__________/%
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
  Updated:   March 16, 1998

  Changes for this release --------------------------------------------------

    o Rewrote 16bpp rasterization routines for faster performance and easier
      maintenance.

    o Added gamma correction to texture conversion and palette management.

    o Added cursor drawing for Direct3D devices.

    o Added new vngo_circle/vngo_clip_circle version which takes a 24-bit
      color.

    o Dropped incomplete 3Dfx, MSI, and Clear3D implementations.

    o Fixed texture caching and hazing problems with D3D.  Cleaned up
      init/term of D3D device to ensure good behavior.

    o Removed unused variables in Direct3D, DIB, and DirectDraw viewports.


  Pending changes -----------------------------------------------------------

    o The screen manager check_mode() functions need to be implemented.

    o Total rewrite planned for MythOS 98

*** END OF FILE ***

