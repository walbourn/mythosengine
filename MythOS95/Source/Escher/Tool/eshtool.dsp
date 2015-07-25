# Microsoft Developer Studio Project File - Name="eshtool" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=eshtool - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "eshtool.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "eshtool.mak" CFG="eshtool - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "eshtool - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "eshtool - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "eshtool - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\WinDebug"
# PROP BASE Intermediate_Dir ".\WinDebug"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\WinDebug"
# PROP Intermediate_Dir ".\WinDebug"
# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\inc" /I "..\..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD MTL /mktyplib203
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib mythos.lib ivorymfc.lib bozo.lib xfile.lib chronos.lib escher.lib gutenbrg.lib felix.lib vangogh.lib /nologo /version:4 /subsystem:windows /debug /machine:I386 /nodefaultlib:"LIBC" /nodefaultlib:"LIBCMT" /libpath:"..\..\lib" /libpath:"..\..\..\lib"
# SUBTRACT LINK32 /verbose /pdb:none /map /nodefaultlib

!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\WinRel"
# PROP BASE Intermediate_Dir ".\WinRel"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\WinRel"
# PROP Intermediate_Dir ".\WinRel"
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\inc" /I "..\..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD MTL /mktyplib203
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib mythos.lib ivorymfc.lib bozo.lib xfile.lib chronos.lib escher.lib gutenbrg.lib felix.lib vangogh.lib /nologo /version:4 /subsystem:windows /machine:I386 /nodefaultlib:"LIBC" /nodefaultlib:"LIBCMT" /libpath:"..\..\lib" /libpath:"..\..\..\lib"
# SUBTRACT LINK32 /verbose /pdb:none /map /nodefaultlib

!ENDIF 

# Begin Target

# Name "eshtool - Win32 Debug"
# Name "eshtool - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\eshtdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtdoc.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtmfrm.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtool.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtool.rc
# End Source File
# Begin Source File

SOURCE=.\eshttree.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtview.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtvp.cpp
# End Source File
# Begin Source File

SOURCE=.\readme.txt
# End Source File
# Begin Source File

SOURCE=.\stdafx.cpp
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\eshtdlg.h
# End Source File
# Begin Source File

SOURCE=.\eshtdoc.h
# End Source File
# Begin Source File

SOURCE=.\eshtmfrm.h
# End Source File
# Begin Source File

SOURCE=.\eshtool.h
# End Source File
# Begin Source File

SOURCE=.\eshttree.h
# End Source File
# Begin Source File

SOURCE=.\eshtview.h
# End Source File
# Begin Source File

SOURCE=.\eshtvp.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\about.bmp
# End Source File
# Begin Source File

SOURCE=.\res\camera.ico
# End Source File
# Begin Source File

SOURCE=.\res\cameras.ico
# End Source File
# Begin Source File

SOURCE=.\res\eshdoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\eshtool.ico
# End Source File
# Begin Source File

SOURCE=.\res\eshtool.rc2
# End Source File
# Begin Source File

SOURCE=.\res\light.ico
# End Source File
# Begin Source File

SOURCE=.\res\light_s.ico
# End Source File
# Begin Source File

SOURCE=.\res\logo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mesh.ico
# End Source File
# Begin Source File

SOURCE=.\res\mesh_s.ico
# End Source File
# Begin Source File

SOURCE=.\res\scene.ico
# End Source File
# Begin Source File

SOURCE=.\res\scene_s.ico
# End Source File
# Begin Source File

SOURCE=.\res\toolbar.bmp
# End Source File
# End Group
# End Target
# End Project
