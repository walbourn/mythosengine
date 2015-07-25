
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

                         *** Version 1.5 Release ***

                             October 8, 1997

 This is the sixth full release of the MythOS collection.  Usage of this 
 library is subject to your license agreement.  All materials herein 
 should be treated as confidential information.

 All documentation for MythOS is provided in Windows Help files.  If you 
 have need of hardcopy documentation, you can use the print option in the 
 Windows 95 help viewer.

 
 
 ---------------------------------------------------------------------------
 INSTALLATION

 Select Start/Run... and select 'setup.exe'.  Follow the instructions
 given in the setup program.



 ---------------------------------------------------------------------------
 DIRECTORIES

 The following structure will be placed onto the destination drive:

 \MythOS95
 +--Inc                             Includes
 |
 +--Bin                             Utility programs
 |
 +--Lib                             Production Libraries (multi-threaded static)
 |  |
 |  +--Assert                       Assert version of libraries (multi-threaded static)
 |  |
 |  +--ML                           Production Libraries (single-threaded)
 |  |
 |  +--Assert.ML                    Assert version libraries (single-threaded)
 |  |
 |  +--Assert.MD                    Assert version libraries (multi-threaded DLL)
 |  |
 |  +--MD                           Production Libraries (multi-threaded DLL)
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
    |  +--Build (source only)
    |  |
    |  +--Draw (source only)
    |  |
    |  +--Element (source only)
    |  |
    |  +--Light (source only)
    |  |
    |  +--Math (source only)
    |  |
    |  +--Motion (source only)
    |  |
    |  +--Particle (source only)
    |  |
    |  +--Texture (source only)
    |  |
    |  +--Obj (source only)
    |  |
    |  +--Edit
    |  |
    |  +--Tool
    |  |
    |  +--Test
    |  |  +--Data
    |  |  |
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
    +--Examples                     Example Code
    |  |
    |  +--Viewer
    |  |  +--Obj
    |  | 
    |  +--LLander
    |  |  +--Data
    |  |  |
    |  |  +--Obj
    |  | 
    |  +--Script
    |     +--Data
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
    |  |
    |  +--Test
    |     +--Obj
    |
    +--SimGine                      SimGine Framework (Source)
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Res
    |     |
    |     +--Obj
    |
    +--System                       MythOS System (Source)
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
    |  +--Boards (source only)
    |  |
    |  +--Screen (source only)
    |  |
    |  +--Obj (source only)
    |  |
    |  +--PalTool
    |  |
    |  +--Test
    |     +--Obj
    |
    +--XFile                        XFile (File system)
       +--Inc (source only)
       |
       +--IFF (source only)
       |
       +--INI (source only)
       |
       +--IO (source only)
       |
       +--Bitmap (source only)
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
 RELEASE NOTES

    See the WHATSNEW.TXT for a list of major changes since the last
    release.

    README.TXT's are in each of the library component directories with
    current status and work notes.

    A new examples directory was added to the release.  The GameFrame
    was removed.

    This version of MythOS was built with Microsoft Visual C++ v5.0.  The
    MFC-based tools will therefore not compile with v2.x MSVC.

    The .libs have been built with the three run-time library choices for
    Visual C++.  The multi-threaded libraries were built with /MT, the
    single-threaded libraries with /ML, and the multi-threaded DLL
    libraries with /MD.  The ASSERT.NMT and NMT directories from the
    last release were renamed to ASSERT.ML and ML to match the compiler
    switch.

    Note: The Escher Exporter must be built using Watcom v10 and the 
          Autodesk IPAS4 Toolkit, since it is a 3D Studio Plug-In module.
          It also uses the Autodesk Animation Support Libraries R2.0.

    MFC Version 5.x support DLLs are installed as part of the MythOS
    installation procedure since they are required by the MFC-based tools.

    The Bach library has been included with this release, although this
    is still under development.  The documentation is only a basic
    template.
    
    Several of the utilities require a PD utility, Flex, which must be 
    located in C:\FLEX in order to build the executable.  Unzip the FLEX.ZIP
    contained in the root directory of the installed tree structure into
    C:\FLEX (must be this directory!) and put C:\FLEX in your path.

      
    
 ---------------------------------------------------------------------------
 EXAMPLES

    We have started to include some example code with this release.  The
    ReadME files for the examples give details on thier function.

    The Viewer example is a simple object viewer with interactive controls
    simliar to the Microsoft Direct3D Viewer sample.  This is a great
    place to see how to handle all of the initialization issues for MythOS
    and how to respond to various error conditions.

    The second example, Lunar Lander, was previously the GameFrame
    example and has been converted over to use the SimGine framework.  It
    makes use of more of the 2D and support functionality of MythOS.

    Script, our third example, is a simple scripting system for creating,
    modifying, and animating cameras, lights, meshes, and particle
    generators.  This could be extended in many directions, but the system
    does allow you to play with various parameters and try out some simple
    physics stuff with Newton.
    


 ---------------------------------------------------------------------------
 BUILDING CODE

    The majority of the code has been setup to build and run from the
    command line using Microsoft's NMAKE utility.  There are 'mk.bat'
    batch files in each directory that build the local files.  The
    examples and testers include run batches which keep the current
    directory with the supporting data files.

    The MFC-based tools are setup to build release versions with the
    'mk.bat' but full control files have been included for use with
    Microsoft's Developer Studio.



 ---------------------------------------------------------------------------
 PROBLEMS/BUGS

    If you have problems or find bugs working with MythOS, we would 
    like to hear about them.  E-mail or FAX is the preferred method 
    for reporting problems.  We are committed to doing quality work, 
    so please let us know what you find.

    Bug reports should be sent to mythos_bugs@charybdis.com.  General
    comments are welcome at mythos@charybdis.com.  There is a public
    message board on our website which is open for comments and
    discussions with other MythOS developers.  The URL is
    http://www.charybdis.com/wwwboard/wwwboard-mythos.html.

    We will make future releases as the need arises and updates become 
    available.

END OF DOCUMENT

