  
  
              _,'|             _.-''``-...___..--';)
             /_ \'.      __..-' ,      ,--...--'''
            <\    .`--'''       `     /'     
             `-';'               ;   ; ;  Felix the Fixed-point Library
       __...--''     ___...--_..'  .;.'
      (,__....----'''       (,..--''
  
                     Microsoft Windows 95/NT Version
     
          Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
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
  Updated:   March 9, 1998

  Changes for this release --------------------------------------------------

    o Updated copyrights


  Problems ------------------------------------------------------------------

    o Microsoft Visual C++ generates extra overhead on inline functions
      for Flx16 if a copy constructor is defined.  This is resolved by
      removing the copy constructor.

*** END OF FILE ***
