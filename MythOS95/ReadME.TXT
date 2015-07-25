
                                 /\    /\
                                /  \  /  \
                               /    \/    \
                              /  /\    /\  \
                             /  /  \  /  Y T H O S
                            /  /    \/    \  \
                           /  /            \  \
                          /__/              \__\
 
             Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
                            All Rights Reserved.

                            Windows '95 Version

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

                           Charybdis Enterprises, Inc.
                              9430 Research Blvd.
                             Echelon IV, Suite 302
                               Austin, TX  78759
                                (512) 343-7224
                              FAX: (512) 343-6310

                  Direct e-mail inquires to: tim@charybdis.com

                          http://www.charybdis.com/

 ---------------------------------------------------------------------------

                         *** Version 1.3 Release ***

                                March 11, 1997

 This is the fourth full release of the MythOS collection.  Usage of this 
 library is subject to your license agreement.  All materials herein 
 should be treated as confidential information.

 All documentation for MythOS is provided in Windows Help files.  If you 
 have need of hardcopy documentation, you can use the print option in the 
 Windows 95 help viewer.

 
 
 ---------------------------------------------------------------------------
 Installation

 Select Start/Run... and select 'setup.exe'.  Follow the instructions
 given in the setup program.



 ---------------------------------------------------------------------------
 The following structure will be placed onto the destination drive:

 \MythOS95
 +--Inc                             Includes
 |
 +--Bin                             Utility programs
 |
 +--Lib                             Production Libraries
 |  +--Assert                       Assert version of libraries
 |
 +--Source
    +--Bach                         Bach (Sound library)
    |  +--Inc (source only)
    |  |
    |  +--Obj (source only)
    |   
    +--Bozo                         Bozo (Task switcher)
    |  +--Inc (source only)
    |  |
    |  +--Obj (source only)
    |  |
    |  +--Test
    |     +--Obj
    |   
    +--Chronos                      Chronos (Timer services)
    |  +--Inc (source only)
    |  |
    |  +--Obj (source only)
    |  |
    |  +--Test
    |     +--Obj
    |
    +--Escher                       Escher (3D Graphics System)
    |  +--Inc (source only)
    |  |
    |  +--Edit
    |  |
    |  +--Tool
    |  |
    |  +--Obj (source only)
    |  |
    |  +--Test
    |  |  +--Obj
    |  | 
    |  +--Util
    |  |  +--Obj
    |  | 
    |  +--Export
    |     +--Inc
    |     |
    |     +--Lib
    |     |
    |     +--Obj
    |
    +--Felix                        Felix (Fixed-point support)
    |  +--Inc (source only)
    |  |
    |  +--Obj (source only)
    |  |
    |  +--Test
    |     +--Obj
    |
    +--GameFrame                    Application framework and example
    |  +--Inc
    |  |
    |  +--Obj
    |
    +--Gutenbrg                     Gutenberg (Font and string support)
    |  +--Inc (source only)
    |  |
    |  +--Obj (source only)
    |  |
    |  +--Test
    |  |  +--Obj
    |  | 
    |  +--Util
    |     +--Obj
    |
    +--Ivory                        Ivory (Memory-manager)
    |  +--Inc (source only)
    |  |
    |  +--Obj (source only)
    |  |
    |  +--Test
    |     +--Obj
    |
    +--Max                          Max (Event-system)
    |  +--Inc (source only)
    |  |
    |  +--Obj (source only)
    |  |
    |  +--Test
    |  |  +--Obj
    |  | 
    |  +--Util
    |     +--Obj
    |
    +--Newton                       Newton (Physics system)
    |  +--Inc (source only)
    |  |
    |  +--Obj (source only)
    |
    +--System                       MythOS System (Full Source)
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Obj
    |
    +--Turner                       Turner (Network system)
    |  +--Inc (source only)
    |  |
    |  +--Obj (source only)
    |
    +--Util                         MythOS General Utilities (Source)
    |  +--Obj
    |
    +--VanGogh                      Van Gogh (2D Graphics System)
    |  +--Inc (source only)
    |  |
    |  +--8BPP (source only)
    |  |
    |  +--16BPP (source only)
    |  |
    |  +--PalTool
    |  |
    |  +--Obj (source only)
    |
    +--XFile                        XFile (File system)
       +--Inc (source only)
       |
       +--Obj (source only)
       |
       +--Test
       |  +--Obj
       | 
       +--Util
          +--Obj

    If this is a source release, then each of the library subdirectories
    will include the source code, an Inc, and an Obj directory.  A master
    build.bat is also included in Source to build all libraries and release
    them to the Lib and Inc directories.

    If you select a destination other than \MythOS95, you will need to
    set the environment variable MYTH95ROOT equal to the path of the
    target tree.  This variable is used by the makefiles.
    

 
 ---------------------------------------------------------------------------
 Release Notes

    README.TXT's are in each of the library component directories with
    current status and work notes.

    This version of MythOS was built with Microsoft Visual C++ v4.2.  The
    MFC-based tools will therefore not compile with v2.x MSVC.

    Note: The Escher Exporter must be built using Watcom v10 and the 
          Autodesk IPAS4 Toolkit, since it is a 3D Studio Plug-In module.
          It also uses the Autodesk Animation Support Libraries R2.0.

    MFC Version 4.x support DLLs are installed as part of the MythOS
    installation procedure since they are required by the MFC-based tools.

    The Van Gogh library documentation is not complete.  Van Gogh v2 is
    under development and is being documented as part of this effort.

    The Bach library has been included with this release, although this
    is still under development.  The documentation is only a basic
    template.
    
    Several of the utilities require a PD utility, Flex, which must be 
    located in C:\FLEX in order to build the executable.  Unzip the FLEX.ZIP
    contained in the root directory of the installed tree structure into
    C:\FLEX (must be this directory!) and put C:\FLEX in your path.

  
    
 ---------------------------------------------------------------------------
 Problems/Bugs

    If you have problems or find bugs working with MythOS, we would 
    like to hear about them.  E-mail or FAX is the preferred method 
    for reporting problems.  We are committed to doing quality work, 
    so please let us know what you find.

    We will make future releases as the need arises and updates become 
    available.

END OF DOCUMENT

