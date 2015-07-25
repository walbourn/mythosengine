                                   ____
                                  / __ \
                                 ( (__) )
                                 _\____/___
                                /  |  |   /\
                               /_________/  \_
                              /          \    \
                             /            \    \_
                            /              \     \
                           /                \     \_
                          /                  \      \
                         /                    \      \_
                        /                      \       \
                       /                        \       \_
                      /                          \        \
                     /                            \        \_
                    /                              \         \
                   / N  N EEE W   W TTTTT  OO  N  N \        /
                  /  NN N E_  W   W   T   O  O NN N  \      /
                 /   N NN E   W W W   T   O  O N NN   \    /
                /    N  N EEE  W W    T    OO  N  N    \  /
               /________________________________________\/

                     Newtonian Physics Simulation Library

                      Microsoft Windows 95/98/NT Version

    Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn

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

 ---------------------------------------------------------------------------

                             _Library Status_

 Notes by: Dan Higdon
 Updated: February 2, 1998

 Changes for this release --------------------------------------------------

 o Added NewtObject::set_initial_position(), which correctly initializes
   the last_position member variable.

 o Converted to use float instead of Flx16.



 Future notes --------------------------------------------------------------

 o Will need updating for new math library (Euler)

 o Support for 2nd and 4th order integration techniques.

 o More advanced physics models should be added (spring-dampner,
   rigid-body collision computations, etc.).

*** END OF FILE ***
