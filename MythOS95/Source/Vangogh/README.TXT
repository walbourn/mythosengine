
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
  Updated:   October 7, 1997

  Changes for this release --------------------------------------------------

    o Updated to support set_haze/haze calls to the VngoVport class to
      support both software post-process and hardware support hazing.

    o Added capture() routine to VngoVport to handle device-dependant
      code for screenshot capture.

    o Added a make_current call to the VngoVport class that sets the cur_vport
      member of the VngoSystem class, and forces the viewports local infomation
      to be updated.  If you ever draw to a VngoVport that is not the current,
      it will make itself the current automatically if it needs to be the current
      in order to function properly.

    o Added new calls to enable true alpha blending and texture filtering when
      they are supported by the view port.  Note that calling either of these
      functions or the zbuffer_on/off functions force a call to the VngoVport's
      make_current function as well.

    o Added line-clipping routines to VngoRect class.
      
    o Continued development of Direct3D.



  Pending changes -----------------------------------------------------------

    o Update documentation for internals of the 3D management.

    o The screen manager check_mode() functions need to be implemented.

    o Implementation of 3D/fx Glide and Matrox Simple Interface 3D
      viewports/screen managers.

    o Possibly add 24-bit/32-bit display support.

    o More features for PalTool.

*** END OF FILE ***

