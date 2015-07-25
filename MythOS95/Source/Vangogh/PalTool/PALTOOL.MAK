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
!MESSAGE NMAKE /f "PalTool.mak" CFG="Win32 Debug"
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

ALL : $(OUTDIR)/PalTool.exe $(OUTDIR)/PalTool.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"PalTool.pch"\
 /Yu"stdafx.h" /Fo$(INTDIR)/ /Fd$(OUTDIR)/"PalTool.pdb" /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"PalTool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"PalTool.bsc" 
BSC32_SBRS= \
	$(INTDIR)/stdafx.sbr \
	$(INTDIR)/PalTool.sbr \
	$(INTDIR)/mainfrm.sbr \
	$(INTDIR)/paltodoc.sbr \
	$(INTDIR)/PalTovw.sbr \
	$(INTDIR)/bezier.sbr \
	$(INTDIR)/dialog.sbr

$(OUTDIR)/PalTool.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 winmm.lib /NOLOGO /VERSION:4,0 /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# SUBTRACT LINK32 /PDB:none
LINK32_FLAGS=winmm.lib /NOLOGO /VERSION:4,0 /SUBSYSTEM:windows /INCREMENTAL:yes\
 /PDB:$(OUTDIR)/"PalTool.pdb" /DEBUG /MACHINE:I386 /OUT:$(OUTDIR)/"PalTool.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/stdafx.obj \
	$(INTDIR)/PalTool.obj \
	$(INTDIR)/mainfrm.obj \
	$(INTDIR)/paltodoc.obj \
	$(INTDIR)/PalTovw.obj \
	$(INTDIR)/PalTool.res \
	$(INTDIR)/bezier.obj \
	$(INTDIR)/dialog.obj \
	\Charybds\MythOS95\lib\IvoryMFC.lib \
	\Charybds\MythOS95\lib\VanGogh.lib \
	\Charybds\MythOS95\lib\gutenbrg.lib \
	\Charybds\MythOS95\lib\mythos.lib \
	\Charybds\MythOS95\lib\escher.lib \
	\Charybds\MythOS95\lib\felix.lib \
	\Charybds\MythOS95\lib\xfile.lib \
	\Charybds\MythOS95\lib\chronos.lib \
	\Charybds\MythOS95\lib\bozo.lib

$(OUTDIR)/PalTool.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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

ALL : $(OUTDIR)/PalTool.exe $(OUTDIR)/PalTool.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"PalTool.pch"\
 /Yu"stdafx.h" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"PalTool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"PalTool.bsc" 
BSC32_SBRS= \
	$(INTDIR)/stdafx.sbr \
	$(INTDIR)/PalTool.sbr \
	$(INTDIR)/mainfrm.sbr \
	$(INTDIR)/paltodoc.sbr \
	$(INTDIR)/PalTovw.sbr \
	$(INTDIR)/bezier.sbr \
	$(INTDIR)/dialog.sbr

$(OUTDIR)/PalTool.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 winmm.lib /NOLOGO /VERSION:4,0 /SUBSYSTEM:windows /MACHINE:I386
# SUBTRACT LINK32 /PDB:none
LINK32_FLAGS=winmm.lib /NOLOGO /VERSION:4,0 /SUBSYSTEM:windows /INCREMENTAL:no\
 /PDB:$(OUTDIR)/"PalTool.pdb" /MACHINE:I386 /OUT:$(OUTDIR)/"PalTool.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/stdafx.obj \
	$(INTDIR)/PalTool.obj \
	$(INTDIR)/mainfrm.obj \
	$(INTDIR)/paltodoc.obj \
	$(INTDIR)/PalTovw.obj \
	$(INTDIR)/PalTool.res \
	$(INTDIR)/bezier.obj \
	$(INTDIR)/dialog.obj \
	\Charybds\MythOS95\lib\IvoryMFC.lib \
	\Charybds\MythOS95\lib\VanGogh.lib \
	\Charybds\MythOS95\lib\gutenbrg.lib \
	\Charybds\MythOS95\lib\mythos.lib \
	\Charybds\MythOS95\lib\escher.lib \
	\Charybds\MythOS95\lib\felix.lib \
	\Charybds\MythOS95\lib\xfile.lib \
	\Charybds\MythOS95\lib\chronos.lib \
	\Charybds\MythOS95\lib\bozo.lib

$(OUTDIR)/PalTool.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
	\Charybds\MythOS95\inc\MYTHOS.HPP\
	\Charybds\MythOS95\inc\DEBUG.H\
	\Charybds\MythOS95\inc\PORTABLE.H\
	\Charybds\MythOS95\inc\Ivory.hpp\
	\Charybds\MythOS95\inc\CHRONOS.HPP\
	\Charybds\MythOS95\inc\felix.hpp\
	\Charybds\MythOS95\inc\XFILE.HPP\
	\Charybds\MythOS95\inc\BOZO.HPP\
	\Charybds\MythOS95\inc\Max.HPP\
	\Charybds\MythOS95\inc\VANGOGH.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.HPP\
	\Charybds\MythOS95\inc\ESCHER.HPP\
	\Charybds\MythOS95\inc\MYTHOS.H\
	\Charybds\MythOS95\inc\Ivory.h\
	\Charybds\MythOS95\inc\Ivory.ipp\
	\Charybds\MythOS95\inc\felix.ipp\
	\Charybds\MythOS95\inc\XFDEFS.H\
	\Charybds\MythOS95\inc\XFIO.H\
	\Charybds\MythOS95\inc\XFBASE.HPP\
	\Charybds\MythOS95\inc\XFINI.HPP\
	\Charybds\MythOS95\inc\XFBITMAP.HPP\
	\Charybds\MythOS95\inc\XFIFF.HPP\
	\Charybds\MythOS95\inc\BOZO.H\
	\Charybds\MythOS95\inc\BZWRAP.HPP\
	\Charybds\MythOS95\inc\MaxEvt.HPP\
	\Charybds\MythOS95\inc\MaxDevs.HPP\
	\Charybds\MythOS95\inc\MaxESrc.HPP\
	\Charybds\MythOS95\inc\VNGDEFS.H\
	\Charybds\MythOS95\inc\VNGSTRCT.HPP\
	\Charybds\MythOS95\inc\VNGINLIN.IPP\
	\Charybds\MythOS95\inc\VNGVP.HPP\
	\Charybds\MythOS95\inc\VNGVVP8.HPP\
	\Charybds\MythOS95\inc\VNGVPDD8.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.H\
	\Charybds\MythOS95\inc\ESDEFS.H\
	\Charybds\MythOS95\inc\ESMATH.HPP\
	\Charybds\MythOS95\inc\ESCONTXT.HPP\
	\Charybds\MythOS95\inc\ESTXTURE.HPP\
	\Charybds\MythOS95\inc\ESLIGHT.HPP\
	\Charybds\MythOS95\inc\ESCAMERA.HPP\
	\Charybds\MythOS95\inc\ESSYSTEM.HPP\
	\Charybds\MythOS95\inc\ESDRAW.HPP\
	\Charybds\MythOS95\inc\ESPARTIK.HPP\
	\Charybds\MythOS95\inc\ESGEOM.HPP\
	\Charybds\MythOS95\inc\ESTERRAN.HPP\
	\Charybds\MythOS95\inc\ESSCENE.HPP\
	\Charybds\MythOS95\inc\IVMem.h\
	\Charybds\MythOS95\inc\BZSEMAP.H\
	\Charybds\MythOS95\inc\VNGPAL.HPP\
	\Charybds\MythOS95\inc\VNGBD.HPP\
	\Charybds\MythOS95\inc\BZQUEUE.H\
	\Charybds\MythOS95\inc\VNGCOLOR.HPP\
	\Charybds\MythOS95\inc\BZTASK.H\
	\Charybds\MythOS95\inc\BZARTN.H

!IF  "$(CFG)" == "Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

$(INTDIR)/stdafx.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"PalTool.pch"\
 /Yc"stdafx.h" /Fo$(INTDIR)/ /Fd$(OUTDIR)/"PalTool.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

$(INTDIR)/stdafx.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"PalTool.pch"\
 /Yc"stdafx.h" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PalTool.cpp
DEP_PALTO=\
	.\stdafx.h\
	.\PalTool.h\
	.\mainfrm.h\
	.\PalTodoc.h\
	.\PalTovw.h\
	\Charybds\MythOS95\inc\MYTHOS.HPP\
	\Charybds\MythOS95\inc\DEBUG.H\
	\Charybds\MythOS95\inc\PORTABLE.H\
	\Charybds\MythOS95\inc\Ivory.hpp\
	\Charybds\MythOS95\inc\CHRONOS.HPP\
	\Charybds\MythOS95\inc\felix.hpp\
	\Charybds\MythOS95\inc\XFILE.HPP\
	\Charybds\MythOS95\inc\BOZO.HPP\
	\Charybds\MythOS95\inc\Max.HPP\
	\Charybds\MythOS95\inc\VANGOGH.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.HPP\
	\Charybds\MythOS95\inc\ESCHER.HPP\
	\Charybds\MythOS95\inc\MYTHOS.H\
	\Charybds\MythOS95\inc\Ivory.h\
	\Charybds\MythOS95\inc\Ivory.ipp\
	\Charybds\MythOS95\inc\felix.ipp\
	\Charybds\MythOS95\inc\XFDEFS.H\
	\Charybds\MythOS95\inc\XFIO.H\
	\Charybds\MythOS95\inc\XFBASE.HPP\
	\Charybds\MythOS95\inc\XFINI.HPP\
	\Charybds\MythOS95\inc\XFBITMAP.HPP\
	\Charybds\MythOS95\inc\XFIFF.HPP\
	\Charybds\MythOS95\inc\BOZO.H\
	\Charybds\MythOS95\inc\BZWRAP.HPP\
	\Charybds\MythOS95\inc\MaxEvt.HPP\
	\Charybds\MythOS95\inc\MaxDevs.HPP\
	\Charybds\MythOS95\inc\MaxESrc.HPP\
	\Charybds\MythOS95\inc\VNGDEFS.H\
	\Charybds\MythOS95\inc\VNGSTRCT.HPP\
	\Charybds\MythOS95\inc\VNGINLIN.IPP\
	\Charybds\MythOS95\inc\VNGVP.HPP\
	\Charybds\MythOS95\inc\VNGVVP8.HPP\
	\Charybds\MythOS95\inc\VNGVPDD8.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.H\
	\Charybds\MythOS95\inc\ESDEFS.H\
	\Charybds\MythOS95\inc\ESMATH.HPP\
	\Charybds\MythOS95\inc\ESCONTXT.HPP\
	\Charybds\MythOS95\inc\ESTXTURE.HPP\
	\Charybds\MythOS95\inc\ESLIGHT.HPP\
	\Charybds\MythOS95\inc\ESCAMERA.HPP\
	\Charybds\MythOS95\inc\ESSYSTEM.HPP\
	\Charybds\MythOS95\inc\ESDRAW.HPP\
	\Charybds\MythOS95\inc\ESPARTIK.HPP\
	\Charybds\MythOS95\inc\ESGEOM.HPP\
	\Charybds\MythOS95\inc\ESTERRAN.HPP\
	\Charybds\MythOS95\inc\ESSCENE.HPP\
	\Charybds\MythOS95\inc\IVMem.h\
	\Charybds\MythOS95\inc\BZSEMAP.H\
	\Charybds\MythOS95\inc\VNGPAL.HPP\
	\Charybds\MythOS95\inc\VNGBD.HPP\
	\Charybds\MythOS95\inc\BZQUEUE.H\
	\Charybds\MythOS95\inc\VNGCOLOR.HPP\
	\Charybds\MythOS95\inc\BZTASK.H\
	\Charybds\MythOS95\inc\BZARTN.H

$(INTDIR)/PalTool.obj :  $(SOURCE)  $(DEP_PALTO) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\mainfrm.cpp
DEP_MAINF=\
	.\stdafx.h\
	.\PalTool.h\
	.\mainfrm.h\
	\Charybds\MythOS95\inc\MYTHOS.HPP\
	\Charybds\MythOS95\inc\DEBUG.H\
	\Charybds\MythOS95\inc\PORTABLE.H\
	\Charybds\MythOS95\inc\Ivory.hpp\
	\Charybds\MythOS95\inc\CHRONOS.HPP\
	\Charybds\MythOS95\inc\felix.hpp\
	\Charybds\MythOS95\inc\XFILE.HPP\
	\Charybds\MythOS95\inc\BOZO.HPP\
	\Charybds\MythOS95\inc\Max.HPP\
	\Charybds\MythOS95\inc\VANGOGH.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.HPP\
	\Charybds\MythOS95\inc\ESCHER.HPP\
	\Charybds\MythOS95\inc\MYTHOS.H\
	\Charybds\MythOS95\inc\Ivory.h\
	\Charybds\MythOS95\inc\Ivory.ipp\
	\Charybds\MythOS95\inc\felix.ipp\
	\Charybds\MythOS95\inc\XFDEFS.H\
	\Charybds\MythOS95\inc\XFIO.H\
	\Charybds\MythOS95\inc\XFBASE.HPP\
	\Charybds\MythOS95\inc\XFINI.HPP\
	\Charybds\MythOS95\inc\XFBITMAP.HPP\
	\Charybds\MythOS95\inc\XFIFF.HPP\
	\Charybds\MythOS95\inc\BOZO.H\
	\Charybds\MythOS95\inc\BZWRAP.HPP\
	\Charybds\MythOS95\inc\MaxEvt.HPP\
	\Charybds\MythOS95\inc\MaxDevs.HPP\
	\Charybds\MythOS95\inc\MaxESrc.HPP\
	\Charybds\MythOS95\inc\VNGDEFS.H\
	\Charybds\MythOS95\inc\VNGSTRCT.HPP\
	\Charybds\MythOS95\inc\VNGINLIN.IPP\
	\Charybds\MythOS95\inc\VNGVP.HPP\
	\Charybds\MythOS95\inc\VNGVVP8.HPP\
	\Charybds\MythOS95\inc\VNGVPDD8.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.H\
	\Charybds\MythOS95\inc\ESDEFS.H\
	\Charybds\MythOS95\inc\ESMATH.HPP\
	\Charybds\MythOS95\inc\ESCONTXT.HPP\
	\Charybds\MythOS95\inc\ESTXTURE.HPP\
	\Charybds\MythOS95\inc\ESLIGHT.HPP\
	\Charybds\MythOS95\inc\ESCAMERA.HPP\
	\Charybds\MythOS95\inc\ESSYSTEM.HPP\
	\Charybds\MythOS95\inc\ESDRAW.HPP\
	\Charybds\MythOS95\inc\ESPARTIK.HPP\
	\Charybds\MythOS95\inc\ESGEOM.HPP\
	\Charybds\MythOS95\inc\ESTERRAN.HPP\
	\Charybds\MythOS95\inc\ESSCENE.HPP\
	\Charybds\MythOS95\inc\IVMem.h\
	\Charybds\MythOS95\inc\BZSEMAP.H\
	\Charybds\MythOS95\inc\VNGPAL.HPP\
	\Charybds\MythOS95\inc\VNGBD.HPP\
	\Charybds\MythOS95\inc\BZQUEUE.H\
	\Charybds\MythOS95\inc\VNGCOLOR.HPP\
	\Charybds\MythOS95\inc\BZTASK.H\
	\Charybds\MythOS95\inc\BZARTN.H

$(INTDIR)/mainfrm.obj :  $(SOURCE)  $(DEP_MAINF) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\paltodoc.cpp
DEP_PALTOD=\
	.\stdafx.h\
	.\PalTool.h\
	.\dialog.h\
	.\PalTodoc.h\
	\Charybds\MythOS95\inc\MYTHOS.HPP\
	\Charybds\MythOS95\inc\DEBUG.H\
	\Charybds\MythOS95\inc\PORTABLE.H\
	\Charybds\MythOS95\inc\Ivory.hpp\
	\Charybds\MythOS95\inc\CHRONOS.HPP\
	\Charybds\MythOS95\inc\felix.hpp\
	\Charybds\MythOS95\inc\XFILE.HPP\
	\Charybds\MythOS95\inc\BOZO.HPP\
	\Charybds\MythOS95\inc\Max.HPP\
	\Charybds\MythOS95\inc\VANGOGH.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.HPP\
	\Charybds\MythOS95\inc\ESCHER.HPP\
	\Charybds\MythOS95\inc\MYTHOS.H\
	\Charybds\MythOS95\inc\Ivory.h\
	\Charybds\MythOS95\inc\Ivory.ipp\
	\Charybds\MythOS95\inc\felix.ipp\
	\Charybds\MythOS95\inc\XFDEFS.H\
	\Charybds\MythOS95\inc\XFIO.H\
	\Charybds\MythOS95\inc\XFBASE.HPP\
	\Charybds\MythOS95\inc\XFINI.HPP\
	\Charybds\MythOS95\inc\XFBITMAP.HPP\
	\Charybds\MythOS95\inc\XFIFF.HPP\
	\Charybds\MythOS95\inc\BOZO.H\
	\Charybds\MythOS95\inc\BZWRAP.HPP\
	\Charybds\MythOS95\inc\MaxEvt.HPP\
	\Charybds\MythOS95\inc\MaxDevs.HPP\
	\Charybds\MythOS95\inc\MaxESrc.HPP\
	\Charybds\MythOS95\inc\VNGDEFS.H\
	\Charybds\MythOS95\inc\VNGSTRCT.HPP\
	\Charybds\MythOS95\inc\VNGINLIN.IPP\
	\Charybds\MythOS95\inc\VNGVP.HPP\
	\Charybds\MythOS95\inc\VNGVVP8.HPP\
	\Charybds\MythOS95\inc\VNGVPDD8.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.H\
	\Charybds\MythOS95\inc\ESDEFS.H\
	\Charybds\MythOS95\inc\ESMATH.HPP\
	\Charybds\MythOS95\inc\ESCONTXT.HPP\
	\Charybds\MythOS95\inc\ESTXTURE.HPP\
	\Charybds\MythOS95\inc\ESLIGHT.HPP\
	\Charybds\MythOS95\inc\ESCAMERA.HPP\
	\Charybds\MythOS95\inc\ESSYSTEM.HPP\
	\Charybds\MythOS95\inc\ESDRAW.HPP\
	\Charybds\MythOS95\inc\ESPARTIK.HPP\
	\Charybds\MythOS95\inc\ESGEOM.HPP\
	\Charybds\MythOS95\inc\ESTERRAN.HPP\
	\Charybds\MythOS95\inc\ESSCENE.HPP\
	\Charybds\MythOS95\inc\IVMem.h\
	\Charybds\MythOS95\inc\BZSEMAP.H\
	\Charybds\MythOS95\inc\VNGPAL.HPP\
	\Charybds\MythOS95\inc\VNGBD.HPP\
	\Charybds\MythOS95\inc\BZQUEUE.H\
	\Charybds\MythOS95\inc\VNGCOLOR.HPP\
	\Charybds\MythOS95\inc\BZTASK.H\
	\Charybds\MythOS95\inc\BZARTN.H

$(INTDIR)/paltodoc.obj :  $(SOURCE)  $(DEP_PALTOD) $(INTDIR)\
 $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PalTovw.cpp
DEP_PALTOV=\
	.\stdafx.h\
	.\PalTool.h\
	.\PalTodoc.h\
	.\PalTovw.h\
	.\bezier.h\
	\Charybds\MythOS95\inc\MYTHOS.HPP\
	\Charybds\MythOS95\inc\DEBUG.H\
	\Charybds\MythOS95\inc\PORTABLE.H\
	\Charybds\MythOS95\inc\Ivory.hpp\
	\Charybds\MythOS95\inc\CHRONOS.HPP\
	\Charybds\MythOS95\inc\felix.hpp\
	\Charybds\MythOS95\inc\XFILE.HPP\
	\Charybds\MythOS95\inc\BOZO.HPP\
	\Charybds\MythOS95\inc\Max.HPP\
	\Charybds\MythOS95\inc\VANGOGH.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.HPP\
	\Charybds\MythOS95\inc\ESCHER.HPP\
	\Charybds\MythOS95\inc\MYTHOS.H\
	\Charybds\MythOS95\inc\Ivory.h\
	\Charybds\MythOS95\inc\Ivory.ipp\
	\Charybds\MythOS95\inc\felix.ipp\
	\Charybds\MythOS95\inc\XFDEFS.H\
	\Charybds\MythOS95\inc\XFIO.H\
	\Charybds\MythOS95\inc\XFBASE.HPP\
	\Charybds\MythOS95\inc\XFINI.HPP\
	\Charybds\MythOS95\inc\XFBITMAP.HPP\
	\Charybds\MythOS95\inc\XFIFF.HPP\
	\Charybds\MythOS95\inc\BOZO.H\
	\Charybds\MythOS95\inc\BZWRAP.HPP\
	\Charybds\MythOS95\inc\MaxEvt.HPP\
	\Charybds\MythOS95\inc\MaxDevs.HPP\
	\Charybds\MythOS95\inc\MaxESrc.HPP\
	\Charybds\MythOS95\inc\VNGDEFS.H\
	\Charybds\MythOS95\inc\VNGSTRCT.HPP\
	\Charybds\MythOS95\inc\VNGINLIN.IPP\
	\Charybds\MythOS95\inc\VNGVP.HPP\
	\Charybds\MythOS95\inc\VNGVVP8.HPP\
	\Charybds\MythOS95\inc\VNGVPDD8.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.H\
	\Charybds\MythOS95\inc\ESDEFS.H\
	\Charybds\MythOS95\inc\ESMATH.HPP\
	\Charybds\MythOS95\inc\ESCONTXT.HPP\
	\Charybds\MythOS95\inc\ESTXTURE.HPP\
	\Charybds\MythOS95\inc\ESLIGHT.HPP\
	\Charybds\MythOS95\inc\ESCAMERA.HPP\
	\Charybds\MythOS95\inc\ESSYSTEM.HPP\
	\Charybds\MythOS95\inc\ESDRAW.HPP\
	\Charybds\MythOS95\inc\ESPARTIK.HPP\
	\Charybds\MythOS95\inc\ESGEOM.HPP\
	\Charybds\MythOS95\inc\ESTERRAN.HPP\
	\Charybds\MythOS95\inc\ESSCENE.HPP\
	\Charybds\MythOS95\inc\IVMem.h\
	\Charybds\MythOS95\inc\BZSEMAP.H\
	\Charybds\MythOS95\inc\VNGPAL.HPP\
	\Charybds\MythOS95\inc\VNGBD.HPP\
	\Charybds\MythOS95\inc\BZQUEUE.H\
	\Charybds\MythOS95\inc\VNGCOLOR.HPP\
	\Charybds\MythOS95\inc\BZTASK.H\
	\Charybds\MythOS95\inc\BZARTN.H

$(INTDIR)/PalTovw.obj :  $(SOURCE)  $(DEP_PALTOV) $(INTDIR)\
 $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PalTool.rc
DEP_PALTOO=\
	.\res\PalTool.ico\
	.\res\PalTodoc.ico\
	.\res\toolbar.bmp\
	.\res\PalTool.rc2

$(INTDIR)/PalTool.res :  $(SOURCE)  $(DEP_PALTOO) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\readme.txt
# End Source File
################################################################################
# Begin Source File

SOURCE=.\bezier.cpp
DEP_BEZIE=\
	.\stdafx.h\
	.\bezier.h\
	\Charybds\MythOS95\inc\MYTHOS.HPP\
	\Charybds\MythOS95\inc\DEBUG.H\
	\Charybds\MythOS95\inc\PORTABLE.H\
	\Charybds\MythOS95\inc\Ivory.hpp\
	\Charybds\MythOS95\inc\CHRONOS.HPP\
	\Charybds\MythOS95\inc\felix.hpp\
	\Charybds\MythOS95\inc\XFILE.HPP\
	\Charybds\MythOS95\inc\BOZO.HPP\
	\Charybds\MythOS95\inc\Max.HPP\
	\Charybds\MythOS95\inc\VANGOGH.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.HPP\
	\Charybds\MythOS95\inc\ESCHER.HPP\
	\Charybds\MythOS95\inc\MYTHOS.H\
	\Charybds\MythOS95\inc\Ivory.h\
	\Charybds\MythOS95\inc\Ivory.ipp\
	\Charybds\MythOS95\inc\felix.ipp\
	\Charybds\MythOS95\inc\XFDEFS.H\
	\Charybds\MythOS95\inc\XFIO.H\
	\Charybds\MythOS95\inc\XFBASE.HPP\
	\Charybds\MythOS95\inc\XFINI.HPP\
	\Charybds\MythOS95\inc\XFBITMAP.HPP\
	\Charybds\MythOS95\inc\XFIFF.HPP\
	\Charybds\MythOS95\inc\BOZO.H\
	\Charybds\MythOS95\inc\BZWRAP.HPP\
	\Charybds\MythOS95\inc\MaxEvt.HPP\
	\Charybds\MythOS95\inc\MaxDevs.HPP\
	\Charybds\MythOS95\inc\MaxESrc.HPP\
	\Charybds\MythOS95\inc\VNGDEFS.H\
	\Charybds\MythOS95\inc\VNGSTRCT.HPP\
	\Charybds\MythOS95\inc\VNGINLIN.IPP\
	\Charybds\MythOS95\inc\VNGVP.HPP\
	\Charybds\MythOS95\inc\VNGVVP8.HPP\
	\Charybds\MythOS95\inc\VNGVPDD8.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.H\
	\Charybds\MythOS95\inc\ESDEFS.H\
	\Charybds\MythOS95\inc\ESMATH.HPP\
	\Charybds\MythOS95\inc\ESCONTXT.HPP\
	\Charybds\MythOS95\inc\ESTXTURE.HPP\
	\Charybds\MythOS95\inc\ESLIGHT.HPP\
	\Charybds\MythOS95\inc\ESCAMERA.HPP\
	\Charybds\MythOS95\inc\ESSYSTEM.HPP\
	\Charybds\MythOS95\inc\ESDRAW.HPP\
	\Charybds\MythOS95\inc\ESPARTIK.HPP\
	\Charybds\MythOS95\inc\ESGEOM.HPP\
	\Charybds\MythOS95\inc\ESTERRAN.HPP\
	\Charybds\MythOS95\inc\ESSCENE.HPP\
	\Charybds\MythOS95\inc\IVMem.h\
	\Charybds\MythOS95\inc\BZSEMAP.H\
	\Charybds\MythOS95\inc\VNGPAL.HPP\
	\Charybds\MythOS95\inc\VNGBD.HPP\
	\Charybds\MythOS95\inc\BZQUEUE.H\
	\Charybds\MythOS95\inc\VNGCOLOR.HPP\
	\Charybds\MythOS95\inc\BZTASK.H\
	\Charybds\MythOS95\inc\BZARTN.H

$(INTDIR)/bezier.obj :  $(SOURCE)  $(DEP_BEZIE) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\dialog.cpp
DEP_DIALO=\
	.\stdafx.h\
	.\PalTool.h\
	.\dialog.h\
	\Charybds\MythOS95\inc\MYTHOS.HPP\
	\Charybds\MythOS95\inc\DEBUG.H\
	\Charybds\MythOS95\inc\PORTABLE.H\
	\Charybds\MythOS95\inc\Ivory.hpp\
	\Charybds\MythOS95\inc\CHRONOS.HPP\
	\Charybds\MythOS95\inc\felix.hpp\
	\Charybds\MythOS95\inc\XFILE.HPP\
	\Charybds\MythOS95\inc\BOZO.HPP\
	\Charybds\MythOS95\inc\Max.HPP\
	\Charybds\MythOS95\inc\VANGOGH.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.HPP\
	\Charybds\MythOS95\inc\ESCHER.HPP\
	\Charybds\MythOS95\inc\MYTHOS.H\
	\Charybds\MythOS95\inc\Ivory.h\
	\Charybds\MythOS95\inc\Ivory.ipp\
	\Charybds\MythOS95\inc\felix.ipp\
	\Charybds\MythOS95\inc\XFDEFS.H\
	\Charybds\MythOS95\inc\XFIO.H\
	\Charybds\MythOS95\inc\XFBASE.HPP\
	\Charybds\MythOS95\inc\XFINI.HPP\
	\Charybds\MythOS95\inc\XFBITMAP.HPP\
	\Charybds\MythOS95\inc\XFIFF.HPP\
	\Charybds\MythOS95\inc\BOZO.H\
	\Charybds\MythOS95\inc\BZWRAP.HPP\
	\Charybds\MythOS95\inc\MaxEvt.HPP\
	\Charybds\MythOS95\inc\MaxDevs.HPP\
	\Charybds\MythOS95\inc\MaxESrc.HPP\
	\Charybds\MythOS95\inc\VNGDEFS.H\
	\Charybds\MythOS95\inc\VNGSTRCT.HPP\
	\Charybds\MythOS95\inc\VNGINLIN.IPP\
	\Charybds\MythOS95\inc\VNGVP.HPP\
	\Charybds\MythOS95\inc\VNGVVP8.HPP\
	\Charybds\MythOS95\inc\VNGVPDD8.HPP\
	\Charybds\MythOS95\inc\GUTENBRG.H\
	\Charybds\MythOS95\inc\ESDEFS.H\
	\Charybds\MythOS95\inc\ESMATH.HPP\
	\Charybds\MythOS95\inc\ESCONTXT.HPP\
	\Charybds\MythOS95\inc\ESTXTURE.HPP\
	\Charybds\MythOS95\inc\ESLIGHT.HPP\
	\Charybds\MythOS95\inc\ESCAMERA.HPP\
	\Charybds\MythOS95\inc\ESSYSTEM.HPP\
	\Charybds\MythOS95\inc\ESDRAW.HPP\
	\Charybds\MythOS95\inc\ESPARTIK.HPP\
	\Charybds\MythOS95\inc\ESGEOM.HPP\
	\Charybds\MythOS95\inc\ESTERRAN.HPP\
	\Charybds\MythOS95\inc\ESSCENE.HPP\
	\Charybds\MythOS95\inc\IVMem.h\
	\Charybds\MythOS95\inc\BZSEMAP.H\
	\Charybds\MythOS95\inc\VNGPAL.HPP\
	\Charybds\MythOS95\inc\VNGBD.HPP\
	\Charybds\MythOS95\inc\BZQUEUE.H\
	\Charybds\MythOS95\inc\VNGCOLOR.HPP\
	\Charybds\MythOS95\inc\BZTASK.H\
	\Charybds\MythOS95\inc\BZARTN.H

$(INTDIR)/dialog.obj :  $(SOURCE)  $(DEP_DIALO) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=\Charybds\MythOS95\lib\IvoryMFC.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\Charybds\MythOS95\lib\VanGogh.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\Charybds\MythOS95\lib\gutenbrg.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\Charybds\MythOS95\lib\mythos.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\Charybds\MythOS95\lib\escher.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\Charybds\MythOS95\lib\felix.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\Charybds\MythOS95\lib\xfile.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\Charybds\MythOS95\lib\chronos.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\Charybds\MythOS95\lib\bozo.lib
# End Source File
# End Group
# End Project
################################################################################
