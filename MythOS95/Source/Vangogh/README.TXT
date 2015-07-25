  
                                                             %__________%
                                                            %/ . .  .   \%
             Van Gogh 2D-Display Library                     |  . .  o. | 
                                                             |. _  .   .|
   Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   | / \   .  | 
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
  Updated:   Nov. 6, 1995

  This library is not yet complete.  It is functional using the DIB engine 
  present in Win95, but does not yet utilize any of the Direct Draw, or 
  3D-DDI features of Win95.

  
  Changes for this release --------------------------------------------------
    
    o All new faster polygon scan converter, including a perspectively 
      correct texture mapper.

    o An all new interactive PalTool which allows the use of bi-linear or
      Bezier curves for the shading dynamics generated.  The base color 
      location is no longer required to be 3/4 of the way through the shade
      range.


  Pending changes -----------------------------------------------------------
  
    o Add some context management so the application is not responsible for
      the setup and operational differnces between the Direct Draw, 3D-DDI,
      and DIB versions of physical output.

    o Add support for 15,16,24 bit per pixel display usage.

    o Many new features for PalTool.


*** END OF FILE ***

