  
                                                             %__________%
                                                            %/ . .  .   \%
             Van Gogh 2D-Display Library                     |  . .  o. | 
                                                             |. _  .   .|
   Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.    | / \   .  | 
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
  Updated:   August 26, 1996

  This library is not yet complete.  It is functional using the DIB engine 
  present in Win95, but does not yet utilize any of the 3D-DDI features
  of Win95.

  
  Changes for this release --------------------------------------------------
    o All the service routines that subdivide the polygons now also
      take fractional S not just (u,v).	

    o Direct Draw is now functioning properly.

    o All new directory structure.

    o Fixes a z-buffer bug in the linear flat shadded texture mapper.

    
  Pending changes -----------------------------------------------------------
  
    o Add support for 15,16,24 bit per pixel display usage.

    o Many new features for PalTool.


*** END OF FILE ***

