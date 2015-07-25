  
  
              _,'|             _.-''``-...___..--';)
             /_ \'.      __..-' ,      ,--...--'''
            <\    .`--'''       `     /'     
             `-';'               ;   ; ;  Felix the Fixed-point Library
       __...--''     ___...--_..'  .;.'
      (,__....----'''       (,..--''
  
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

  Notes by:  Tim Little
  Updated:   June 24, 1996

  Changes for this release --------------------------------------------------

    o Changed the precision of the trig functions to .0625 degrees accuracy.

    o Added the atan() functions.

  Proposed changes ----------------------------------------------------------

    o Implement :-

        atan2()
        exp()
        pow()
        log10()
        log()

    o 2.30, 24.8, 20.12, 12.20 formats.

    o Support for floating point table-based trig functions


  Problems ------------------------------------------------------------------

    o Microsoft Visual C++ generates extra overhead on inline functions
      for Flx16 if a copy constructor is defined.  This is resolved by
      removing the copy constructor.

*** END OF FILE ***
