
                                                             %__________%
                                                            %/ . .  .   \%
             Van Gogh 2D-Display Library                     |  . .  o. |
                                                             |. _  .   .|
         Microsoft Windows 95/98/NT Version                  | / \   .  |
                                                             |_|_|_._._.|
                                                             |.-.-.-.-..|
                                                            %\__________/%
                                                             %          %

    Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
  
 ---------------------------------------------------------------------------

  This file and all associated files are subject to the terms of the
  GNU Lesser General Public License version 2 as published by the
  Free Software Foundation (http://www.gnu.org).   They remain the
  property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
  See LICENSE.TXT in the distribution for a copy of this license.

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

  ----------------------------------------------------------------------------

                            _Library Status_

  Notes by:  Tim Little
  Updated:   October 13, 1998

  Changes for this release --------------------------------------------------

    o Added VngoColor24bit::compress24() to convert to internal 24 bit
      color format.

    o Added check for VNGO_COLOR_24BIT flag to frect() and pixel() in
      the 16 bpp and D3D viewports to allow direct use of 24-bit RGB
      values.

    o get_RGB() for the VngoPal structures now check for the VNGO_COLOR_
      bits and perform appropriately.  Mostly changed for safety as we
      add checks for the VNGO_COLOR_ flags to more functions.

    o The screen manager check_mode() functions need to be implemented.


 Future notes ---------------------------------------------------------------

 This library and all associated tools will be retired in a future release
 of MythOS and replaced with an entirely new 2D/3D pipeline.

*** END OF FILE ***

