 ============================================================================

                       Ivory -- A Memory Management Library
                          Microsoft Windows '95 Version

             Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
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
 Updated:  February 22, 1998

  Changes for this release --------------------------------------------------

    o Boy do I feel sheepish.  The AllocationHeader prepended to every
      data block was only 8 bytes long.  So, while the block itself was
      paragraph aligned, the pointer returned to the user wasn't.
      This has been corrected.

  Pending changes -----------------------------------------------------------

    o None

*** END OF FILE ***
