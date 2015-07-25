# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Debug" && "$(CFG)" != "Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "eshtedit.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
MTL=MkTypLib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : $(OUTDIR)/eshtedit.exe $(OUTDIR)/eshtedit.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"eshtedit.pch"\
 /Yu"stdafx.h" /Fo$(INTDIR)/ /Fd$(OUTDIR)/"eshtedit.pdb" /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"eshtedit.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"eshtedit.bsc" 
BSC32_SBRS= \
	$(INTDIR)/stdafx.sbr \
	$(INTDIR)/eshtedit.sbr \
	$(INTDIR)/eshtmfrm.sbr \
	$(INTDIR)/eshtdoc.sbr \
	$(INTDIR)/eshtview.sbr \
	$(INTDIR)/eshtdlg.sbr

$(OUTDIR)/eshtedit.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib ..\..\lib\vangogh.lib /NOLOGO /VERSION:4 /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# SUBTRACT LINK32 /PDB:none
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /NOLOGO /VERSION:4 /SUBSYSTEM:windows /INCREMENTAL:yes\
 /PDB:$(OUTDIR)/"eshtedit.pdb" /DEBUG /MACHINE:I386\
 /OUT:$(OUTDIR)/"eshtedit.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/stdafx.obj \
	$(INTDIR)/eshtedit.obj \
	$(INTDIR)/eshtmfrm.obj \
	$(INTDIR)/eshtdoc.obj \
	$(INTDIR)/eshtview.obj \
	$(INTDIR)/eshtedit.res \
	$(INTDIR)/eshtdlg.obj

$(OUTDIR)/eshtedit.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : $(OUTDIR)/eshtedit.exe $(OUTDIR)/eshtedit.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"eshtedit.pch"\
 /Yu"stdafx.h" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"eshtedit.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"eshtedit.bsc" 
BSC32_SBRS= \
	$(INTDIR)/stdafx.sbr \
	$(INTDIR)/eshtedit.sbr \
	$(INTDIR)/eshtmfrm.sbr \
	$(INTDIR)/eshtdoc.sbr \
	$(INTDIR)/eshtview.sbr \
	$(INTDIR)/eshtdlg.sbr

$(OUTDIR)/eshtedit.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib ..\..\lib\vangogh.lib /NOLOGO /VERSION:4 /SUBSYSTEM:windows /MACHINE:I386
# SUBTRACT LINK32 /PDB:none
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /NOLOGO /VERSION:4 /SUBSYSTEM:windows /INCREMENTAL:no\
 /PDB:$(OUTDIR)/"eshtedit.pdb" /MACHINE:I386 /OUT:$(OUTDIR)/"eshtedit.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/stdafx.obj \
	$(INTDIR)/eshtedit.obj \
	$(INTDIR)/eshtmfrm.obj \
	$(INTDIR)/eshtdoc.obj \
	$(INTDIR)/eshtview.obj \
	$(INTDIR)/eshtedit.res \
	$(INTDIR)/eshtdlg.obj

$(OUTDIR)/eshtedit.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

MTL_PROJ=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Group "Source Files"

################################################################################
# Begin Source File

SOURCE=.\stdafx.cpp
DEP_STDAF=\
	.\stdafx.h\
	\CHARYBDS\MythOS95\Inc\MYTHOS.HPP\
	\CHARYBDS\MythOS95\Inc\DEBUG.H\
	..\..\Inc\PORTABLE.H\
	\CHARYBDS\MythOS95\Inc\Ivory.hpp\
	\CHARYBDS\MythOS95\Inc\CHRONOS.HPP\
	\CHARYBDS\MythOS95\Inc\FELIX.HPP\
	\CHARYBDS\MythOS95\Inc\XFILE.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.HPP\
	\CHARYBDS\MythOS95\Inc\Max.HPP\
	\CHARYBDS\MythOS95\Inc\VANGOGH.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.HPP\
	\CHARYBDS\MythOS95\Inc\ESCHER.HPP\
	\CHARYBDS\MythOS95\Inc\MYTHOS.H\
	\CHARYBDS\MythOS95\Inc\Ivory.h\
	\CHARYBDS\MythOS95\Inc\Ivory.ipp\
	\CHARYBDS\MythOS95\Inc\FELIX.IPP\
	\CHARYBDS\MythOS95\Inc\XFDEFS.H\
	\CHARYBDS\MythOS95\Inc\XFIO.H\
	\CHARYBDS\MythOS95\Inc\XFBASE.HPP\
	\CHARYBDS\MythOS95\Inc\XFINI.HPP\
	\CHARYBDS\MythOS95\Inc\XFBITMAP.HPP\
	\CHARYBDS\MythOS95\Inc\XFIFF.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.H\
	\CHARYBDS\MythOS95\Inc\BZWRAP.HPP\
	\CHARYBDS\MythOS95\Inc\MaxEvt.HPP\
	\CHARYBDS\MythOS95\Inc\MaxDevs.HPP\
	\CHARYBDS\MythOS95\Inc\MaxESrc.HPP\
	\CHARYBDS\MythOS95\Inc\VNGDEFS.H\
	\CHARYBDS\MythOS95\Inc\VNGSTRCT.HPP\
	\CHARYBDS\MythOS95\Inc\VNGINLIN.IPP\
	\CHARYBDS\MythOS95\Inc\VNGVP.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVVP8.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVPDD8.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.H\
	\CHARYBDS\MythOS95\Inc\ESDEFS.H\
	\CHARYBDS\MythOS95\Inc\ESMATH.HPP\
	\CHARYBDS\MythOS95\Inc\ESCONTXT.HPP\
	\CHARYBDS\MythOS95\Inc\ESTXTURE.HPP\
	\CHARYBDS\MythOS95\Inc\ESLIGHT.HPP\
	\CHARYBDS\MythOS95\Inc\ESCAMERA.HPP\
	\CHARYBDS\MythOS95\Inc\ESSYSTEM.HPP\
	\CHARYBDS\MythOS95\Inc\ESDRAW.HPP\
	\CHARYBDS\MythOS95\Inc\ESPARTIK.HPP\
	\CHARYBDS\MythOS95\Inc\ESGEOM.HPP\
	\CHARYBDS\MythOS95\Inc\ESTERRAN.HPP\
	\CHARYBDS\MythOS95\Inc\ESSCENE.HPP\
	\CHARYBDS\MythOS95\Inc\IVMem.h\
	\CHARYBDS\MythOS95\Inc\BZSEMAP.H\
	\CHARYBDS\MythOS95\Inc\VNGPAL.HPP\
	\CHARYBDS\MythOS95\Inc\VNGBD.HPP\
	\CHARYBDS\MythOS95\Inc\BZQUEUE.H\
	\CHARYBDS\MythOS95\Inc\VNGCOLOR.HPP\
	\CHARYBDS\MythOS95\Inc\BZTASK.H\
	\CHARYBDS\MythOS95\Inc\BZARTN.H

!IF  "$(CFG)" == "Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

$(INTDIR)/stdafx.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"eshtedit.pch"\
 /Yc"stdafx.h" /Fo$(INTDIR)/ /Fd$(OUTDIR)/"eshtedit.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

$(INTDIR)/stdafx.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"eshtedit.pch"\
 /Yc"stdafx.h" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtedit.cpp
DEP_ESHTE=\
	.\stdafx.h\
	.\eshtedit.h\
	.\eshtmfrm.h\
	.\eshtdoc.h\
	.\eshtview.h\
	\CHARYBDS\MythOS95\Inc\MYTHOS.HPP\
	\CHARYBDS\MythOS95\Inc\DEBUG.H\
	..\..\Inc\PORTABLE.H\
	\CHARYBDS\MythOS95\Inc\Ivory.hpp\
	\CHARYBDS\MythOS95\Inc\CHRONOS.HPP\
	\CHARYBDS\MythOS95\Inc\FELIX.HPP\
	\CHARYBDS\MythOS95\Inc\XFILE.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.HPP\
	\CHARYBDS\MythOS95\Inc\Max.HPP\
	\CHARYBDS\MythOS95\Inc\VANGOGH.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.HPP\
	\CHARYBDS\MythOS95\Inc\ESCHER.HPP\
	\CHARYBDS\MythOS95\Inc\MYTHOS.H\
	\CHARYBDS\MythOS95\Inc\Ivory.h\
	\CHARYBDS\MythOS95\Inc\Ivory.ipp\
	\CHARYBDS\MythOS95\Inc\FELIX.IPP\
	\CHARYBDS\MythOS95\Inc\XFDEFS.H\
	\CHARYBDS\MythOS95\Inc\XFIO.H\
	\CHARYBDS\MythOS95\Inc\XFBASE.HPP\
	\CHARYBDS\MythOS95\Inc\XFINI.HPP\
	\CHARYBDS\MythOS95\Inc\XFBITMAP.HPP\
	\CHARYBDS\MythOS95\Inc\XFIFF.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.H\
	\CHARYBDS\MythOS95\Inc\BZWRAP.HPP\
	\CHARYBDS\MythOS95\Inc\MaxEvt.HPP\
	\CHARYBDS\MythOS95\Inc\MaxDevs.HPP\
	\CHARYBDS\MythOS95\Inc\MaxESrc.HPP\
	\CHARYBDS\MythOS95\Inc\VNGDEFS.H\
	\CHARYBDS\MythOS95\Inc\VNGSTRCT.HPP\
	\CHARYBDS\MythOS95\Inc\VNGINLIN.IPP\
	\CHARYBDS\MythOS95\Inc\VNGVP.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVVP8.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVPDD8.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.H\
	\CHARYBDS\MythOS95\Inc\ESDEFS.H\
	\CHARYBDS\MythOS95\Inc\ESMATH.HPP\
	\CHARYBDS\MythOS95\Inc\ESCONTXT.HPP\
	\CHARYBDS\MythOS95\Inc\ESTXTURE.HPP\
	\CHARYBDS\MythOS95\Inc\ESLIGHT.HPP\
	\CHARYBDS\MythOS95\Inc\ESCAMERA.HPP\
	\CHARYBDS\MythOS95\Inc\ESSYSTEM.HPP\
	\CHARYBDS\MythOS95\Inc\ESDRAW.HPP\
	\CHARYBDS\MythOS95\Inc\ESPARTIK.HPP\
	\CHARYBDS\MythOS95\Inc\ESGEOM.HPP\
	\CHARYBDS\MythOS95\Inc\ESTERRAN.HPP\
	\CHARYBDS\MythOS95\Inc\ESSCENE.HPP\
	\CHARYBDS\MythOS95\Inc\IVMem.h\
	\CHARYBDS\MythOS95\Inc\BZSEMAP.H\
	\CHARYBDS\MythOS95\Inc\VNGPAL.HPP\
	\CHARYBDS\MythOS95\Inc\VNGBD.HPP\
	\CHARYBDS\MythOS95\Inc\BZQUEUE.H\
	\CHARYBDS\MythOS95\Inc\VNGCOLOR.HPP\
	\CHARYBDS\MythOS95\Inc\BZTASK.H\
	\CHARYBDS\MythOS95\Inc\BZARTN.H

$(INTDIR)/eshtedit.obj :  $(SOURCE)  $(DEP_ESHTE) $(INTDIR)\
 $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtmfrm.cpp
DEP_ESHTM=\
	.\stdafx.h\
	.\eshtedit.h\
	.\eshtmfrm.h\
	.\eshtdoc.h\
	.\eshtview.h\
	.\eshtdlg.h\
	\CHARYBDS\MythOS95\Inc\MYTHOS.HPP\
	\CHARYBDS\MythOS95\Inc\DEBUG.H\
	..\..\Inc\PORTABLE.H\
	\CHARYBDS\MythOS95\Inc\Ivory.hpp\
	\CHARYBDS\MythOS95\Inc\CHRONOS.HPP\
	\CHARYBDS\MythOS95\Inc\FELIX.HPP\
	\CHARYBDS\MythOS95\Inc\XFILE.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.HPP\
	\CHARYBDS\MythOS95\Inc\Max.HPP\
	\CHARYBDS\MythOS95\Inc\VANGOGH.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.HPP\
	\CHARYBDS\MythOS95\Inc\ESCHER.HPP\
	\CHARYBDS\MythOS95\Inc\MYTHOS.H\
	\CHARYBDS\MythOS95\Inc\Ivory.h\
	\CHARYBDS\MythOS95\Inc\Ivory.ipp\
	\CHARYBDS\MythOS95\Inc\FELIX.IPP\
	\CHARYBDS\MythOS95\Inc\XFDEFS.H\
	\CHARYBDS\MythOS95\Inc\XFIO.H\
	\CHARYBDS\MythOS95\Inc\XFBASE.HPP\
	\CHARYBDS\MythOS95\Inc\XFINI.HPP\
	\CHARYBDS\MythOS95\Inc\XFBITMAP.HPP\
	\CHARYBDS\MythOS95\Inc\XFIFF.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.H\
	\CHARYBDS\MythOS95\Inc\BZWRAP.HPP\
	\CHARYBDS\MythOS95\Inc\MaxEvt.HPP\
	\CHARYBDS\MythOS95\Inc\MaxDevs.HPP\
	\CHARYBDS\MythOS95\Inc\MaxESrc.HPP\
	\CHARYBDS\MythOS95\Inc\VNGDEFS.H\
	\CHARYBDS\MythOS95\Inc\VNGSTRCT.HPP\
	\CHARYBDS\MythOS95\Inc\VNGINLIN.IPP\
	\CHARYBDS\MythOS95\Inc\VNGVP.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVVP8.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVPDD8.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.H\
	\CHARYBDS\MythOS95\Inc\ESDEFS.H\
	\CHARYBDS\MythOS95\Inc\ESMATH.HPP\
	\CHARYBDS\MythOS95\Inc\ESCONTXT.HPP\
	\CHARYBDS\MythOS95\Inc\ESTXTURE.HPP\
	\CHARYBDS\MythOS95\Inc\ESLIGHT.HPP\
	\CHARYBDS\MythOS95\Inc\ESCAMERA.HPP\
	\CHARYBDS\MythOS95\Inc\ESSYSTEM.HPP\
	\CHARYBDS\MythOS95\Inc\ESDRAW.HPP\
	\CHARYBDS\MythOS95\Inc\ESPARTIK.HPP\
	\CHARYBDS\MythOS95\Inc\ESGEOM.HPP\
	\CHARYBDS\MythOS95\Inc\ESTERRAN.HPP\
	\CHARYBDS\MythOS95\Inc\ESSCENE.HPP\
	\CHARYBDS\MythOS95\Inc\IVMem.h\
	\CHARYBDS\MythOS95\Inc\BZSEMAP.H\
	\CHARYBDS\MythOS95\Inc\VNGPAL.HPP\
	\CHARYBDS\MythOS95\Inc\VNGBD.HPP\
	\CHARYBDS\MythOS95\Inc\BZQUEUE.H\
	\CHARYBDS\MythOS95\Inc\VNGCOLOR.HPP\
	\CHARYBDS\MythOS95\Inc\BZTASK.H\
	\CHARYBDS\MythOS95\Inc\BZARTN.H

$(INTDIR)/eshtmfrm.obj :  $(SOURCE)  $(DEP_ESHTM) $(INTDIR)\
 $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtdoc.cpp
DEP_ESHTD=\
	.\stdafx.h\
	.\eshtedit.h\
	.\eshtdoc.h\
	.\eshtview.h\
	.\eshtdlg.h\
	\CHARYBDS\MythOS95\Inc\ESFILE.HPP\
	.\dem.h\
	\CHARYBDS\MythOS95\Inc\MYTHOS.HPP\
	..\..\Inc\PORTABLE.H\
	\CHARYBDS\MythOS95\Inc\FELIX.HPP\
	\CHARYBDS\MythOS95\Inc\ESDEFS.H\
	\CHARYBDS\MythOS95\Inc\DEBUG.H\
	\CHARYBDS\MythOS95\Inc\Ivory.hpp\
	\CHARYBDS\MythOS95\Inc\CHRONOS.HPP\
	\CHARYBDS\MythOS95\Inc\XFILE.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.HPP\
	\CHARYBDS\MythOS95\Inc\Max.HPP\
	\CHARYBDS\MythOS95\Inc\VANGOGH.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.HPP\
	\CHARYBDS\MythOS95\Inc\ESCHER.HPP\
	\CHARYBDS\MythOS95\Inc\MYTHOS.H\
	\CHARYBDS\MythOS95\Inc\FELIX.IPP\
	\CHARYBDS\MythOS95\Inc\Ivory.h\
	\CHARYBDS\MythOS95\Inc\Ivory.ipp\
	\CHARYBDS\MythOS95\Inc\XFDEFS.H\
	\CHARYBDS\MythOS95\Inc\XFIO.H\
	\CHARYBDS\MythOS95\Inc\XFBASE.HPP\
	\CHARYBDS\MythOS95\Inc\XFINI.HPP\
	\CHARYBDS\MythOS95\Inc\XFBITMAP.HPP\
	\CHARYBDS\MythOS95\Inc\XFIFF.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.H\
	\CHARYBDS\MythOS95\Inc\BZWRAP.HPP\
	\CHARYBDS\MythOS95\Inc\MaxEvt.HPP\
	\CHARYBDS\MythOS95\Inc\MaxDevs.HPP\
	\CHARYBDS\MythOS95\Inc\MaxESrc.HPP\
	\CHARYBDS\MythOS95\Inc\VNGDEFS.H\
	\CHARYBDS\MythOS95\Inc\VNGSTRCT.HPP\
	\CHARYBDS\MythOS95\Inc\VNGINLIN.IPP\
	\CHARYBDS\MythOS95\Inc\VNGVP.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVVP8.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVPDD8.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.H\
	\CHARYBDS\MythOS95\Inc\ESMATH.HPP\
	\CHARYBDS\MythOS95\Inc\ESCONTXT.HPP\
	\CHARYBDS\MythOS95\Inc\ESTXTURE.HPP\
	\CHARYBDS\MythOS95\Inc\ESLIGHT.HPP\
	\CHARYBDS\MythOS95\Inc\ESCAMERA.HPP\
	\CHARYBDS\MythOS95\Inc\ESSYSTEM.HPP\
	\CHARYBDS\MythOS95\Inc\ESDRAW.HPP\
	\CHARYBDS\MythOS95\Inc\ESPARTIK.HPP\
	\CHARYBDS\MythOS95\Inc\ESGEOM.HPP\
	\CHARYBDS\MythOS95\Inc\ESTERRAN.HPP\
	\CHARYBDS\MythOS95\Inc\ESSCENE.HPP\
	\CHARYBDS\MythOS95\Inc\IVMem.h\
	\CHARYBDS\MythOS95\Inc\BZSEMAP.H\
	\CHARYBDS\MythOS95\Inc\VNGPAL.HPP\
	\CHARYBDS\MythOS95\Inc\VNGBD.HPP\
	\CHARYBDS\MythOS95\Inc\BZQUEUE.H\
	\CHARYBDS\MythOS95\Inc\VNGCOLOR.HPP\
	\CHARYBDS\MythOS95\Inc\BZTASK.H\
	\CHARYBDS\MythOS95\Inc\BZARTN.H

$(INTDIR)/eshtdoc.obj :  $(SOURCE)  $(DEP_ESHTD) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtview.cpp
DEP_ESHTV=\
	.\stdafx.h\
	.\eshtedit.h\
	.\eshtdoc.h\
	.\eshtview.h\
	.\eshtmfrm.h\
	.\eshtdlg.h\
	\CHARYBDS\MythOS95\Inc\MYTHOS.HPP\
	\CHARYBDS\MythOS95\Inc\DEBUG.H\
	..\..\Inc\PORTABLE.H\
	\CHARYBDS\MythOS95\Inc\Ivory.hpp\
	\CHARYBDS\MythOS95\Inc\CHRONOS.HPP\
	\CHARYBDS\MythOS95\Inc\FELIX.HPP\
	\CHARYBDS\MythOS95\Inc\XFILE.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.HPP\
	\CHARYBDS\MythOS95\Inc\Max.HPP\
	\CHARYBDS\MythOS95\Inc\VANGOGH.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.HPP\
	\CHARYBDS\MythOS95\Inc\ESCHER.HPP\
	\CHARYBDS\MythOS95\Inc\MYTHOS.H\
	\CHARYBDS\MythOS95\Inc\Ivory.h\
	\CHARYBDS\MythOS95\Inc\Ivory.ipp\
	\CHARYBDS\MythOS95\Inc\FELIX.IPP\
	\CHARYBDS\MythOS95\Inc\XFDEFS.H\
	\CHARYBDS\MythOS95\Inc\XFIO.H\
	\CHARYBDS\MythOS95\Inc\XFBASE.HPP\
	\CHARYBDS\MythOS95\Inc\XFINI.HPP\
	\CHARYBDS\MythOS95\Inc\XFBITMAP.HPP\
	\CHARYBDS\MythOS95\Inc\XFIFF.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.H\
	\CHARYBDS\MythOS95\Inc\BZWRAP.HPP\
	\CHARYBDS\MythOS95\Inc\MaxEvt.HPP\
	\CHARYBDS\MythOS95\Inc\MaxDevs.HPP\
	\CHARYBDS\MythOS95\Inc\MaxESrc.HPP\
	\CHARYBDS\MythOS95\Inc\VNGDEFS.H\
	\CHARYBDS\MythOS95\Inc\VNGSTRCT.HPP\
	\CHARYBDS\MythOS95\Inc\VNGINLIN.IPP\
	\CHARYBDS\MythOS95\Inc\VNGVP.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVVP8.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVPDD8.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.H\
	\CHARYBDS\MythOS95\Inc\ESDEFS.H\
	\CHARYBDS\MythOS95\Inc\ESMATH.HPP\
	\CHARYBDS\MythOS95\Inc\ESCONTXT.HPP\
	\CHARYBDS\MythOS95\Inc\ESTXTURE.HPP\
	\CHARYBDS\MythOS95\Inc\ESLIGHT.HPP\
	\CHARYBDS\MythOS95\Inc\ESCAMERA.HPP\
	\CHARYBDS\MythOS95\Inc\ESSYSTEM.HPP\
	\CHARYBDS\MythOS95\Inc\ESDRAW.HPP\
	\CHARYBDS\MythOS95\Inc\ESPARTIK.HPP\
	\CHARYBDS\MythOS95\Inc\ESGEOM.HPP\
	\CHARYBDS\MythOS95\Inc\ESTERRAN.HPP\
	\CHARYBDS\MythOS95\Inc\ESSCENE.HPP\
	\CHARYBDS\MythOS95\Inc\IVMem.h\
	\CHARYBDS\MythOS95\Inc\BZSEMAP.H\
	\CHARYBDS\MythOS95\Inc\VNGPAL.HPP\
	\CHARYBDS\MythOS95\Inc\VNGBD.HPP\
	\CHARYBDS\MythOS95\Inc\BZQUEUE.H\
	\CHARYBDS\MythOS95\Inc\VNGCOLOR.HPP\
	\CHARYBDS\MythOS95\Inc\BZTASK.H\
	\CHARYBDS\MythOS95\Inc\BZARTN.H

$(INTDIR)/eshtview.obj :  $(SOURCE)  $(DEP_ESHTV) $(INTDIR)\
 $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtedit.rc
DEP_ESHTED=\
	.\res\eshtedit.ico\
	.\res\toolbar.bmp\
	.\res\eshtedit.rc2

$(INTDIR)/eshtedit.res :  $(SOURCE)  $(DEP_ESHTED) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\readme.txt
# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtdlg.cpp
DEP_ESHTDL=\
	.\stdafx.h\
	.\eshtedit.h\
	.\eshtdlg.h\
	.\eshtdoc.h\
	\CHARYBDS\MythOS95\Inc\MYTHOS.HPP\
	\CHARYBDS\MythOS95\Inc\DEBUG.H\
	..\..\Inc\PORTABLE.H\
	\CHARYBDS\MythOS95\Inc\Ivory.hpp\
	\CHARYBDS\MythOS95\Inc\CHRONOS.HPP\
	\CHARYBDS\MythOS95\Inc\FELIX.HPP\
	\CHARYBDS\MythOS95\Inc\XFILE.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.HPP\
	\CHARYBDS\MythOS95\Inc\Max.HPP\
	\CHARYBDS\MythOS95\Inc\VANGOGH.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.HPP\
	\CHARYBDS\MythOS95\Inc\ESCHER.HPP\
	\CHARYBDS\MythOS95\Inc\MYTHOS.H\
	\CHARYBDS\MythOS95\Inc\Ivory.h\
	\CHARYBDS\MythOS95\Inc\Ivory.ipp\
	\CHARYBDS\MythOS95\Inc\FELIX.IPP\
	\CHARYBDS\MythOS95\Inc\XFDEFS.H\
	\CHARYBDS\MythOS95\Inc\XFIO.H\
	\CHARYBDS\MythOS95\Inc\XFBASE.HPP\
	\CHARYBDS\MythOS95\Inc\XFINI.HPP\
	\CHARYBDS\MythOS95\Inc\XFBITMAP.HPP\
	\CHARYBDS\MythOS95\Inc\XFIFF.HPP\
	\CHARYBDS\MythOS95\Inc\BOZO.H\
	\CHARYBDS\MythOS95\Inc\BZWRAP.HPP\
	\CHARYBDS\MythOS95\Inc\MaxEvt.HPP\
	\CHARYBDS\MythOS95\Inc\MaxDevs.HPP\
	\CHARYBDS\MythOS95\Inc\MaxESrc.HPP\
	\CHARYBDS\MythOS95\Inc\VNGDEFS.H\
	\CHARYBDS\MythOS95\Inc\VNGSTRCT.HPP\
	\CHARYBDS\MythOS95\Inc\VNGINLIN.IPP\
	\CHARYBDS\MythOS95\Inc\VNGVP.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVVP8.HPP\
	\CHARYBDS\MythOS95\Inc\VNGVPDD8.HPP\
	\CHARYBDS\MythOS95\Inc\GUTENBRG.H\
	\CHARYBDS\MythOS95\Inc\ESDEFS.H\
	\CHARYBDS\MythOS95\Inc\ESMATH.HPP\
	\CHARYBDS\MythOS95\Inc\ESCONTXT.HPP\
	\CHARYBDS\MythOS95\Inc\ESTXTURE.HPP\
	\CHARYBDS\MythOS95\Inc\ESLIGHT.HPP\
	\CHARYBDS\MythOS95\Inc\ESCAMERA.HPP\
	\CHARYBDS\MythOS95\Inc\ESSYSTEM.HPP\
	\CHARYBDS\MythOS95\Inc\ESDRAW.HPP\
	\CHARYBDS\MythOS95\Inc\ESPARTIK.HPP\
	\CHARYBDS\MythOS95\Inc\ESGEOM.HPP\
	\CHARYBDS\MythOS95\Inc\ESTERRAN.HPP\
	\CHARYBDS\MythOS95\Inc\ESSCENE.HPP\
	\CHARYBDS\MythOS95\Inc\IVMem.h\
	\CHARYBDS\MythOS95\Inc\BZSEMAP.H\
	\CHARYBDS\MythOS95\Inc\VNGPAL.HPP\
	\CHARYBDS\MythOS95\Inc\VNGBD.HPP\
	\CHARYBDS\MythOS95\Inc\BZQUEUE.H\
	\CHARYBDS\MythOS95\Inc\VNGCOLOR.HPP\
	\CHARYBDS\MythOS95\Inc\BZTASK.H\
	\CHARYBDS\MythOS95\Inc\BZARTN.H

$(INTDIR)/eshtdlg.obj :  $(SOURCE)  $(DEP_ESHTDL) $(INTDIR)\
 $(INTDIR)/stdafx.obj

# End Source File
# End Group
# End Project
################################################################################
