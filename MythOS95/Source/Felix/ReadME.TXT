  
  
              _,'|             _.-''``-...___..--';)
             /_ \'.      __..-' ,      ,--...--'''
            <\    .`--'''       `     /'     
             `-';'               ;   ; ;  Felix the Fixed-point Library
       __...--''     ___...--_..'  .;.'
      (,__....----'''       (,..--''
  
                       Microsoft Windows '95 Version
     
             Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
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
  Updated:   Oct 24, 1995

  Changes for this release --------------------------------------------------

    o Release Version 1.0



  Proposed changes ----------------------------------------------------------

    o Implement :-

        acos()
        asin()        
        tan()         
        atan()
        atan2()
        exp()
        pow()
        log10()
        log()

    o 2.30 and 24.8 formats.



  Problems ------------------------------------------------------------------

    o Microsoft Visual C++ v2.0 generates extra overhead on inline functions
      for Flx16 if a copy constructor is defined.  This is resolved by
      removing the copy constructor.

*** END OF FILE ***
