
                                    Turner

                          Microsoft Windows '95 Version
  
              Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
                             All Rights Reserved.
  
  --------------------------------------------------------------------------
  
             *** Charybdis Enterprises, Inc. Company Confidential ***
  
    This file and all associated files are the company proprietary property
          of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
  
   CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
   TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
   IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
   AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
   INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
  
  --------------------------------------------------------------------------

                              _Library Status_

  Notes by: Dan Higdon
  Updated:  May 12, 1996

  Changes for this release --------------------------------------------------

	- Added CreateEvent() to allow DirectPlay to more efficiently tell
	  us when a new message is ready.  The receive() member uses this
	  event, if present, instead of waiting for DirectPlay's Receive()
	  to timeout.

	- Discovered that DPSEND_GUARANTEE does not currently work.
	  The application will have to implement resending for now.

*** END OF FILE ***
