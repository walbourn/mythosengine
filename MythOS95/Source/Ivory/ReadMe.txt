 ============================================================================

                       Ivory -- A Memory Management Library
                          Microsoft Windows '95 Version

             Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
                            All Rights Reserved.

 ----------------------------------------------------------------------------

            *** Charybdis Enterprises, Inc. Company Confidential ***

   This file and all associated files are the company proprietary property
         of Charybdis Enterprises, Inc.  Unauthorized use prohibited.

  CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
  TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
  IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
  AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
  INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ============================================================================

                             _Library Status_

 Notes by:  Dan Higdon
 Updated:  January 15, 1997

  Changes for this release --------------------------------------------------

    o Added debugging code - now, the debug version of Ivory allocates
      an additional 32 bytes which it uses to catch overwrites and
      multiple frees (on a good day).  It will report the delta in
      allocs and frees, and how many bytes remain unallocated.
      This can't catch cases where the freed block merges with an
      existing freeblock, but it's better than nothing.

  Pending changes -----------------------------------------------------------

    o None

*** END OF FILE ***
