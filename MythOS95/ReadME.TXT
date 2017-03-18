
                                 /\    /\
                                /  \  /  \
                               /    \/    \
                              /  /\    /\  \
                             /  /  \  /  Y T H O S
                            /  /    \/    \  \
                           /  /            \  \
                          /__/              \__\
 
    Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn

                           Windows 95/98/NT Version

 ---------------------------------------------------------------------------

  THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
  OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
  PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
  LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
  OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

                         http://www.mythos-engine.org/

 ---------------------------------------------------------------------------

                         *** Version 1.8 Release ***

			       July 8, 1999

 All documentation for MythOS is provided in Windows Help files.  If you 
 have need of hardcopy documentation, you can use the print option in the 
 Windows help viewer.  An HTML version of the help file should be available
 from the MythOS Home Page (http://www.mythos-engine.org/).

 
 
 ---------------------------------------------------------------------------
 INSTALLATION

 Select Start/Run... and select 'setup.exe'.  Follow the instructions
 given in the setup program.

 To build the code, you will need some supporting Microsoft SDKs in
 addition to the Visual C++ v6 compiler and MASM 6.14 (a patch from
 MASM 6.11 is provided in ML614.EXE from Microsoft's FTP site
 ftp://ftp.microsoft.com/Softlib/MSLFILES/ML614.EXE):

    DirectX V6.1 SDK

    DirectX Media V6 SDK

    Microsoft September 1998 Platform SDK

 -or-

    Microsoft June 1999 Platform SDK (includes DX V6.1, DXM V6)

 Be sure that your INCLUDE and LIB environment variables put the DX and DXM
 SDK first (if present), the Platform SDK next, and the Visual C++
 directories last.  If you are using the libraries from within the MSDEV
 environment, you will need to edit the variables under the Tools/Options...
 menu.

 Note: The Platform SDK can be downloaded from Microsoft's site at
       http://msdn.microsoft.com/



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
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Obj
    |   
    +--Bozo                         Bozo (Task switcher)
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Obj
    |   
    +--Chronos                      Chronos (Timer services)
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Obj
    |
    +--Escher                       Escher (3D Graphics System)
    |  +--Inc
    |  |
    |  +--Build
    |  |
    |  +--Draw
    |  |
    |  +--Element
    |  |
    |  +--Light
    |  |
    |  +--Math
    |  |
    |  +--Motion
    |  |
    |  +--Particle
    |  |
    |  +--Partn
    |  |
    |  +--Terrain
    |  |
    |  +--Texture
    |  |
    |  +--Obj
    |  |
    |  +--Edit                             Terrain Editor
    |  |
    |  +--Tool                             Object Viewer Tool
    |  |
    |  +--Test
    |  |  +--Data
    |  |  |
    |  |  +--Obj
    |  | 
    |  +--Util                             Directory, Converters, and Texture Librarian
    |  |  +--Obj
    |  | 
    |  +--Export                           3D Studio for DOS R4 Exporter
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
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Obj
    |
    +--Gutenbrg                     Gutenberg (Font and string support)
    |  +--Inc 
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |  |  +--Obj
    |  | 
    |  +--Util
    |     +--Obj
    |
    +--Help                         Help Master and Project Files
    |
    |
    +--Ivory                        Ivory (Memory-manager)
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Obj
    |
    +--Max                          Max (Event-system)
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |  |  +--Obj
    |  | 
    |  +--Util
    |     +--Obj
    |
    +--Newton                       Newton (Physics system)
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Obj
    |
    +--Pane                         Pane (GUI Helper Library)
    |  +--Inc
    |  |
    |  +--Obj
    |
    +--SimGine                      SimGine Framework
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Res
    |     |
    |     +--Obj
    |
    +--Spielberg                    Spielberg (Animation/movie player)
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Obj
    |
    +--System                       MythOS System
    |  +--Inc
    |  |
    |  +--Obj
    |  |
    |  +--Test
    |     +--Obj
    |
    +--Turner                       Turner (Network system)
    |  +--Inc
    |  |
    |  +--Obj
    |
    +--Util                         MythOS General Utilities
    |  +--Obj
    |
    +--VanGogh                      Van Gogh (2D Graphics System)
    |  +--Inc
    |  |
    |  +--8BPP 
    |  |
    |  +--16BPP
    |  |
    |  +--Boards
    |  |
    |  +--Screen
    |  |
    |  +--Obj
    |  |
    |  +--PalTool
    |  |
    |  +--Test
    |     +--Obj
    |
    +--XFile                        XFile (File system)
       +--Inc
       |
       +--IFF
       |
       +--INI 
       |
       +--IO
       |
       +--Bitmap
       |
       +--Obj
       |
       +--Test
       |  +--Obj
       | 
       +--Util
          +--Obj

    A master build.bat is included build all libraries and release them
    to the Lib and Inc directories.

    If you select a destination other than \MythOS95, you will need to
    set the environment variable MYTH95ROOT equal to the path of the
    target tree.  This variable is used by the makefiles.
    

 
 ---------------------------------------------------------------------------
 RELEASE NOTES

    See the WHATSNEW.TXT for a list of major changes since the last
    release.

    README.TXT's are in each of the library component directories with
    current status and work notes.

    This version of MythOS was built with Microsoft Visual C++ v6.0.

    The .libs have been built with the three run-time library choices for
    Visual C++.  The multi-threaded libraries were built with /MT, the
    single-threaded libraries with /ML, and the multi-threaded DLL
    libraries with /MD.  The ASSERT.NMT and NMT directories from the
    last release were renamed to ASSERT.ML and ML to match the compiler
    switch.

    Note: The Escher Exporter must be built using Watcom v10 and the 
          Autodesk IPAS4 Toolkit, since it is a 3D Studio Plug-In module.
          It also uses the Autodesk Animation Support Libraries R2.0.

    MFC Version 6.x support DLLs are installed as part of the MythOS
    installation procedure since they are required by the MFC-based tools.

    Several of the utilities require a PD utility, Flex, which must be 
    located in C:\FLEX in order to build the executable.  Unzip the FLEX.ZIP
    contained in the root directory of the installed tree structure into
    C:\FLEX (must be this directory!) and put C:\FLEX in your path.

    A 3D Studio MAX exporter was planned, but has not been completed.
    If time permits, Chuck will try to complete at least a basic
    exporter for 3DS MAX.

      
    
 ---------------------------------------------------------------------------
 EXAMPLES

    This release includes some example code to get you started.  The
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
 VIEWING CODE

    The commenting style uses extended IBM characters.  To properly view
    them, set your editor to use the 'Terminal' font--most editors default
    to Courier.



 ---------------------------------------------------------------------------
 BUILDING CODE

    The majority of the code has been setup to build and run from the
    command line using Microsoft's NMAKE utility.  There are 'mk.bat'
    batch files in each directory that build the local files.  The
    examples and testers include run batches which keep the current
    directory with the supporting data files.

    The build environment makes use of a number of environment variables:
    
       DEBUG        YES for debug version, NO or not set for release version,
                    or ASSERT for asserts only build.

       THREAD       YES for multi-threaded run-time, DLL for multi-threaded DLL,
                    or anything else for non multi-threaded run-time.

       MSVC         If INCLUDE or LIB is not set, this is used to set the default
                    directories where MSVC points to the Visual C library
                    (set MSVC=D:\msdev\vc98 for example).

       LINKMAP      If set to YES, then a link map file is generated.

       MYTH95ROOT   Set to the root of the MythOS95 directory.

    The build environment assumes that the PATH has already been updated for the
    compiler tools.  The VCVARS32.BAT should work for this, although you might want
    more direct control by writing your own batch or editing your AUTOEXEC.BAT.

    The MFC-based tools are setup to build release versions with the
    'mk.bat' but full control files have been included for use with
    Microsoft's Developer Studio.

    To perform a build in all directories, change to the Source directory
    and run the 'build' batch after setting the preferred environment
    variables:

    	'build release' will build and release all the libraries to the
	Inc and Lib directories.

	'build clean' will erase all library temporary files for a rebuild.

	'build tools' will build and release all the utilities to the
	Bin directory.  Libraries must exist before building tools.

              Note: If you don't have the tools for building the
	            Escher exporter, edit the Escher's mk.bat tools
		    section.

	'build tests' will build the testers.  Libraries and tools must
	exist.

	'build examples' will build the examples.  Libraries and tools
	must exist.



 ---------------------------------------------------------------------------
 BUILDING HELP

    The HLP file is constructed from RTF files in the Source\Help directory
    along with RTF files in each libraries' source directory.  To rebuild
    the help, run the 'make.bat' batch in the Source\Help directory after
    editing it to point to the Help Compiler on your system.



 ---------------------------------------------------------------------------
 PROBLEMS/BUGS

    This library is provided on an "as-is" basis and no supported is
    provided.  Any future releases or bug-fixes will be posted to the
    MythOS Home Page (http://www.mythos-engine.org/).

    Send comments and suggestions to mythos@mythos-engine.org.  Bug
    reports should be sent to mythos_bugs@mythos-engine.org.



 ---------------------------------------------------------------------------
 FUTURE RELEASES

    The MythOS 95 library set represents a technology base started in 1994
    for use in Charybdis' first title.  We had plans for the development
    of a new 2.0 version of the library to provide a major rewrite of the
    graphics libraries (Van Gogh and Escher) to update for the shift
    to 3D graphics consumer hardware from software-based rendering
    on 486 class computers.  This version was to be called "MythOS 98".

    We are not making any commitments for a future version, but there are
    a number of plans which may or may not materialize.  Any such work
    will take place on a part-time basis and would hopefully be released
    using the same Open Source license.  The new version would be a major
    rewrite and would not be compatable with MythOS 95.

END OF DOCUMENT
