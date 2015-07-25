# Microsoft Developer Studio Project File - Name="eshtedit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=eshtedit - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "eshtedit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "eshtedit.mak" CFG="eshtedit - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "eshtedit - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "eshtedit - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\WinDebug"
# PROP BASE Intermediate_Dir ".\WinDebug"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\WinDebug"
# PROP Intermediate_Dir ".\WinDebug"
# PROP Ignore_Export_Lib 0
# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /Gm /GX /ZI /Od /I "..\..\inc" /I "..\..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr /Yu"stdafx.h" /FD /c
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
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\WinRel"
# PROP BASE Intermediate_Dir ".\WinRel"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\WinRel"
# PROP Intermediate_Dir ".\WinRel"
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /GX /O2 /I "..\..\inc" /I "..\..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
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
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "eshtedit - Win32 Debug"
# Name "eshtedit - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\eshtdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtdlgt.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtdlgx.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtdoc.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtdoci.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtedit.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtedit.rc
# End Source File
# Begin Source File

SOURCE=.\Eshtgrid.cpp
# End Source File
# Begin Source File

SOURCE=.\Eshtlist.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtmfrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Eshtrend.cpp
# End Source File
# Begin Source File

SOURCE=.\Eshtusgs.cpp
# End Source File
# Begin Source File

SOURCE=.\eshtview.cpp
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

SOURCE=.\Dem.h
# End Source File
# Begin Source File

SOURCE=.\eshtdlg.h
# End Source File
# Begin Source File

SOURCE=.\eshtdlgt.h
# End Source File
# Begin Source File

SOURCE=.\eshtdlgx.h
# End Source File
# Begin Source File

SOURCE=.\Eshtdoc.h
# End Source File
# Begin Source File

SOURCE=.\Eshtedit.h
# End Source File
# Begin Source File

SOURCE=.\Eshtgrid.h
# End Source File
# Begin Source File

SOURCE=.\Eshtlist.h
# End Source File
# Begin Source File

SOURCE=.\Eshtmfrm.h
# End Source File
# Begin Source File

SOURCE=.\Eshtrend.h
# End Source File
# Begin Source File

SOURCE=.\eshtusgs.h
# End Source File
# Begin Source File

SOURCE=.\Eshtview.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\eshtdoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\eshtedit.ico
# End Source File
# Begin Source File

SOURCE=.\res\eshtedit.rc2
# End Source File
# Begin Source File

SOURCE=.\res\toolbar.bmp
# End Source File
# End Group
# End Target
# End Project
