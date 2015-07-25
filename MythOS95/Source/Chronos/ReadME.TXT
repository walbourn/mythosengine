
          ======================
           \\                //
            \\              //
             \\        +-----  |   | +---+ +---+ |   | +---+  +---+
              \\       |  //   |   | |   | |   | |   | |   |  |
               \\.. . *|.//    |   | |   | |   | |\  | |   |  |
                \\* *.X|//     +---+ +---+ |   | |\\ | |   |  +---+
                 |X..* ||      |   | |\    |   | | \\| |   |      |
                 |X    ||      |   | | \   |   | |  \| |   |      |
                // X X +-----  |   | |  \  +---+ |   | +---+  +---+
               //   . X  \\
              // .X.XXX.  \\
             // ..XX*..XX.X\\            Timer Library
            //...*****..*.*.\\
           //****************\\
          ======================

                        Microsoft Windows '95 Version

            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
                             All Rights Reserved.

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

                               _Library Status_

  Notes by: Dan Higdon
  Updated: July 23, 1997

  Changes for this release --------------------------------------------------

    o Release Version 2.0

    o New code from the (now defunct) Profiler library, enabling Chronos
      to report very precise times, up to the processor's clock speed.
      The new members are chronos_time_now_precise(), and the new
      AtomicChronometer class, which can be used for accumulated code
      timing/profiling.  Other members work as in Chronos 1.0

  Pending changes -----------------------------------------------------------

    o Load-balancing of timer-callbacks.

*** END OF FILE ***
