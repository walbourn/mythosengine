    
                  oooooooooo.                                 
                  `888'   `Y8b                                
                   888     888  .ooooo.    oooooooo  .ooooo.  
                   888oooo888' d88' `88b  d'""7d8P  d88' `88b 
                   888    `88b 888   888    .d8P'   888   888 
                   888    .88P 888   888  .d8P'  .P 888   888 
                  o888bood8P'  `Y8bod8P' d8888888P  `Y8bod8P' 
                             _                       
                            /_\     |    _  _ | _ ._ 
                           /   \  \_||_|(_|(_||(/_|  
                                         _| _|       
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

  Notes by: Dan Higdon
  Updated: June 20, 1996

  Changes for this release --------------------------------------------------

	o The BozoTask::init member now returns an error code in the form
	  of a bozo_task pointer.  A null result means that the task
	  failed to initialize.

    o Added bz_term and bz_return to the BozoTask to correct a rather
	  subtle bug.

  Pending changes ------------------------------------------------------------

    o Possibly the exception handling issue will be investigated and,
      if necessary, corrected.

*** END OF FILE ***
