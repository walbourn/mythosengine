
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
  Updated:   November 12, 1997

  Changes for this release --------------------------------------------------

    o Minor fix to palette loading code for 16-bit

    o Changed pixel for D3D to always use line() since some boards do not
      support a pixel operation and detecting this case is not obvious.

    o Continued development of Direct3D.



  Pending changes -----------------------------------------------------------

    o Update documentation for internals of the 3D management.

    o The screen manager check_mode() functions need to be implemented.

    o Implementation of 3D/fx Glide and Matrox Simple Interface 3D
      viewports/screen managers.

    o Possibly add 24-bit/32-bit display support.

    o More features for PalTool.

*** END OF FILE ***

