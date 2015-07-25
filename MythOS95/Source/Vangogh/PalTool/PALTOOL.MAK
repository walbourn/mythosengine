# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Paltool - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Paltool - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Paltool - Win32 Debug" && "$(CFG)" !=\
 "Paltool - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Paltool.mak" CFG="Paltool - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Paltool - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Paltool - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Paltool - Win32 Release"
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "Paltool - Win32 Debug"

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

ALL : "$(OUTDIR)\Paltool.exe"

CLEAN : 
	-@erase "$(INTDIR)\bezier.obj"
	-@erase "$(INTDIR)\dialog.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\paltodoc.obj"
	-@erase "$(INTDIR)\paltool.obj"
	-@erase "$(INTDIR)\Paltool.pch"
	-@erase "$(INTDIR)\paltool.res"
	-@erase "$(INTDIR)\paltovw.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Paltool.exe"
	-@erase "$(OUTDIR)\Paltool.ilk"
	-@erase "$(OUTDIR)\Paltool.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Paltool.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/paltool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Paltool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /debug /machine:I386 /nodefaultlib:"libc" /VERSION:4,0
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Paltool.pdb" /debug /machine:I386 /nodefaultlib:"libc"\
 /out:"$(OUTDIR)/Paltool.exe" /VERSION:4,0 
LINK32_OBJS= \
	"$(INTDIR)\bezier.obj" \
	"$(INTDIR)\dialog.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\paltodoc.obj" \
	"$(INTDIR)\paltool.obj" \
	"$(INTDIR)\paltool.res" \
	"$(INTDIR)\paltovw.obj" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\Paltool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Paltool - Win32 Release"

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

ALL : "$(OUTDIR)\Paltool.exe"

CLEAN : 
	-@erase "$(INTDIR)\bezier.obj"
	-@erase "$(INTDIR)\dialog.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\paltodoc.obj"
	-@erase "$(INTDIR)\paltool.obj"
	-@erase "$(INTDIR)\Paltool.pch"
	-@erase "$(INTDIR)\paltool.res"
	-@erase "$(INTDIR)\paltovw.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(OUTDIR)\Paltool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Paltool.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/paltool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Paltool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /machine:I386 /nodefaultlib:"libc" /VERSION:4,0
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Paltool.pdb" /machine:I386 /nodefaultlib:"libc"\
 /out:"$(OUTDIR)/Paltool.exe" /VERSION:4,0 
LINK32_OBJS= \
	"$(INTDIR)\bezier.obj" \
	"$(INTDIR)\dialog.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\paltodoc.obj" \
	"$(INTDIR)\paltool.obj" \
	"$(INTDIR)\paltool.res" \
	"$(INTDIR)\paltovw.obj" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\Paltool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Paltool - Win32 Debug"
# Name "Paltool - Win32 Release"

!IF  "$(CFG)" == "Paltool - Win32 Debug"

!ELSEIF  "$(CFG)" == "Paltool - Win32 Release"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\bezier.cpp
DEP_CPP_BEZIE=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\inc\BZARTN.H"\
	".\..\..\inc\BZQUEUE.H"\
	".\..\..\inc\BZSEMAP.H"\
	".\..\..\inc\BZTASK.H"\
	".\..\..\inc\BZWRAP.HPP"\
	".\..\..\inc\DEBUG.H"\
	".\..\..\inc\esbasic.hpp"\
	".\..\..\inc\ESCAMERA.HPP"\
	".\..\..\inc\ESCONTXT.HPP"\
	".\..\..\inc\ESDEFS.H"\
	".\..\..\inc\ESDRAW.HPP"\
	".\..\..\inc\esexts.hpp"\
	".\..\..\inc\ESGEOM.HPP"\
	".\..\..\inc\ESLIGHT.HPP"\
	".\..\..\inc\ESMATH.HPP"\
	".\..\..\inc\esmisc.hpp"\
	".\..\..\inc\ESPARTIK.HPP"\
	".\..\..\inc\ESSCENE.HPP"\
	".\..\..\inc\ESSYSTEM.HPP"\
	".\..\..\inc\ESTERRAN.HPP"\
	".\..\..\inc\ESTXTURE.HPP"\
	".\..\..\inc\GUTENBRG.H"\
	".\..\..\inc\IVMem.h"\
	".\..\..\inc\Ivory.ipp"\
	".\..\..\inc\MaxDevs.HPP"\
	".\..\..\inc\MaxESrc.HPP"\
	".\..\..\inc\MaxEvt.HPP"\
	".\..\..\inc\MYTHOS.H"\
	".\..\..\inc\VNGBD.HPP"\
	".\..\..\inc\VNGCOLOR.HPP"\
	".\..\..\inc\VNGDEFS.H"\
	".\..\..\inc\VNGPAL.HPP"\
	".\..\..\inc\VNGSTRCT.HPP"\
	".\..\..\inc\VNGVP.HPP"\
	".\..\..\inc\vngvpdb8.hpp"\
	".\..\..\inc\VNGVPDD8.HPP"\
	".\..\..\inc\VNGVVP8.HPP"\
	".\..\..\inc\XFBASE.HPP"\
	".\..\..\inc\XFBITMAP.HPP"\
	".\..\..\inc\XFDEFS.H"\
	".\..\..\inc\XFIFF.HPP"\
	".\..\..\inc\XFINI.HPP"\
	".\bezier.h"\
	".\stdafx.h"\
	

"$(INTDIR)\bezier.obj" : $(SOURCE) $(DEP_CPP_BEZIE) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\dialog.cpp
DEP_CPP_DIALO=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\inc\BZARTN.H"\
	".\..\..\inc\BZQUEUE.H"\
	".\..\..\inc\BZSEMAP.H"\
	".\..\..\inc\BZTASK.H"\
	".\..\..\inc\BZWRAP.HPP"\
	".\..\..\inc\DEBUG.H"\
	".\..\..\inc\esbasic.hpp"\
	".\..\..\inc\ESCAMERA.HPP"\
	".\..\..\inc\ESCONTXT.HPP"\
	".\..\..\inc\ESDEFS.H"\
	".\..\..\inc\ESDRAW.HPP"\
	".\..\..\inc\esexts.hpp"\
	".\..\..\inc\ESGEOM.HPP"\
	".\..\..\inc\ESLIGHT.HPP"\
	".\..\..\inc\ESMATH.HPP"\
	".\..\..\inc\esmisc.hpp"\
	".\..\..\inc\ESPARTIK.HPP"\
	".\..\..\inc\ESSCENE.HPP"\
	".\..\..\inc\ESSYSTEM.HPP"\
	".\..\..\inc\ESTERRAN.HPP"\
	".\..\..\inc\ESTXTURE.HPP"\
	".\..\..\inc\GUTENBRG.H"\
	".\..\..\inc\IVMem.h"\
	".\..\..\inc\Ivory.ipp"\
	".\..\..\inc\MaxDevs.HPP"\
	".\..\..\inc\MaxESrc.HPP"\
	".\..\..\inc\MaxEvt.HPP"\
	".\..\..\inc\MYTHOS.H"\
	".\..\..\inc\VNGBD.HPP"\
	".\..\..\inc\VNGCOLOR.HPP"\
	".\..\..\inc\VNGDEFS.H"\
	".\..\..\inc\VNGPAL.HPP"\
	".\..\..\inc\VNGSTRCT.HPP"\
	".\..\..\inc\VNGVP.HPP"\
	".\..\..\inc\vngvpdb8.hpp"\
	".\..\..\inc\VNGVPDD8.HPP"\
	".\..\..\inc\VNGVVP8.HPP"\
	".\..\..\inc\XFBASE.HPP"\
	".\..\..\inc\XFBITMAP.HPP"\
	".\..\..\inc\XFDEFS.H"\
	".\..\..\inc\XFIFF.HPP"\
	".\..\..\inc\XFINI.HPP"\
	".\dialog.h"\
	".\paltool.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dialog.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\mainfrm.cpp
DEP_CPP_MAINF=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\inc\BZARTN.H"\
	".\..\..\inc\BZQUEUE.H"\
	".\..\..\inc\BZSEMAP.H"\
	".\..\..\inc\BZTASK.H"\
	".\..\..\inc\BZWRAP.HPP"\
	".\..\..\inc\DEBUG.H"\
	".\..\..\inc\esbasic.hpp"\
	".\..\..\inc\ESCAMERA.HPP"\
	".\..\..\inc\ESCONTXT.HPP"\
	".\..\..\inc\ESDEFS.H"\
	".\..\..\inc\ESDRAW.HPP"\
	".\..\..\inc\esexts.hpp"\
	".\..\..\inc\ESGEOM.HPP"\
	".\..\..\inc\ESLIGHT.HPP"\
	".\..\..\inc\ESMATH.HPP"\
	".\..\..\inc\esmisc.hpp"\
	".\..\..\inc\ESPARTIK.HPP"\
	".\..\..\inc\ESSCENE.HPP"\
	".\..\..\inc\ESSYSTEM.HPP"\
	".\..\..\inc\ESTERRAN.HPP"\
	".\..\..\inc\ESTXTURE.HPP"\
	".\..\..\inc\GUTENBRG.H"\
	".\..\..\inc\IVMem.h"\
	".\..\..\inc\Ivory.ipp"\
	".\..\..\inc\MaxDevs.HPP"\
	".\..\..\inc\MaxESrc.HPP"\
	".\..\..\inc\MaxEvt.HPP"\
	".\..\..\inc\MYTHOS.H"\
	".\..\..\inc\VNGBD.HPP"\
	".\..\..\inc\VNGCOLOR.HPP"\
	".\..\..\inc\VNGDEFS.H"\
	".\..\..\inc\VNGPAL.HPP"\
	".\..\..\inc\VNGSTRCT.HPP"\
	".\..\..\inc\VNGVP.HPP"\
	".\..\..\inc\vngvpdb8.hpp"\
	".\..\..\inc\VNGVPDD8.HPP"\
	".\..\..\inc\VNGVVP8.HPP"\
	".\..\..\inc\XFBASE.HPP"\
	".\..\..\inc\XFBITMAP.HPP"\
	".\..\..\inc\XFDEFS.H"\
	".\..\..\inc\XFIFF.HPP"\
	".\..\..\inc\XFINI.HPP"\
	".\mainfrm.h"\
	".\paltool.h"\
	".\stdafx.h"\
	

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\paltodoc.cpp
DEP_CPP_PALTO=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\inc\BZARTN.H"\
	".\..\..\inc\BZQUEUE.H"\
	".\..\..\inc\BZSEMAP.H"\
	".\..\..\inc\BZTASK.H"\
	".\..\..\inc\BZWRAP.HPP"\
	".\..\..\inc\DEBUG.H"\
	".\..\..\inc\esbasic.hpp"\
	".\..\..\inc\ESCAMERA.HPP"\
	".\..\..\inc\ESCONTXT.HPP"\
	".\..\..\inc\ESDEFS.H"\
	".\..\..\inc\ESDRAW.HPP"\
	".\..\..\inc\esexts.hpp"\
	".\..\..\inc\ESGEOM.HPP"\
	".\..\..\inc\ESLIGHT.HPP"\
	".\..\..\inc\ESMATH.HPP"\
	".\..\..\inc\esmisc.hpp"\
	".\..\..\inc\ESPARTIK.HPP"\
	".\..\..\inc\ESSCENE.HPP"\
	".\..\..\inc\ESSYSTEM.HPP"\
	".\..\..\inc\ESTERRAN.HPP"\
	".\..\..\inc\ESTXTURE.HPP"\
	".\..\..\inc\GUTENBRG.H"\
	".\..\..\inc\IVMem.h"\
	".\..\..\inc\Ivory.ipp"\
	".\..\..\inc\MaxDevs.HPP"\
	".\..\..\inc\MaxESrc.HPP"\
	".\..\..\inc\MaxEvt.HPP"\
	".\..\..\inc\MYTHOS.H"\
	".\..\..\inc\VNGBD.HPP"\
	".\..\..\inc\VNGCOLOR.HPP"\
	".\..\..\inc\VNGDEFS.H"\
	".\..\..\inc\VNGPAL.HPP"\
	".\..\..\inc\VNGSTRCT.HPP"\
	".\..\..\inc\VNGVP.HPP"\
	".\..\..\inc\vngvpdb8.hpp"\
	".\..\..\inc\VNGVPDD8.HPP"\
	".\..\..\inc\VNGVVP8.HPP"\
	".\..\..\inc\XFBASE.HPP"\
	".\..\..\inc\XFBITMAP.HPP"\
	".\..\..\inc\XFDEFS.H"\
	".\..\..\inc\XFIFF.HPP"\
	".\..\..\inc\XFINI.HPP"\
	".\dialog.h"\
	".\Paltodoc.h"\
	".\paltool.h"\
	".\stdafx.h"\
	

"$(INTDIR)\paltodoc.obj" : $(SOURCE) $(DEP_CPP_PALTO) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\paltool.cpp
DEP_CPP_PALTOO=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\inc\BZARTN.H"\
	".\..\..\inc\BZQUEUE.H"\
	".\..\..\inc\BZSEMAP.H"\
	".\..\..\inc\BZTASK.H"\
	".\..\..\inc\BZWRAP.HPP"\
	".\..\..\inc\DEBUG.H"\
	".\..\..\inc\esbasic.hpp"\
	".\..\..\inc\ESCAMERA.HPP"\
	".\..\..\inc\ESCONTXT.HPP"\
	".\..\..\inc\ESDEFS.H"\
	".\..\..\inc\ESDRAW.HPP"\
	".\..\..\inc\esexts.hpp"\
	".\..\..\inc\ESGEOM.HPP"\
	".\..\..\inc\ESLIGHT.HPP"\
	".\..\..\inc\ESMATH.HPP"\
	".\..\..\inc\esmisc.hpp"\
	".\..\..\inc\ESPARTIK.HPP"\
	".\..\..\inc\ESSCENE.HPP"\
	".\..\..\inc\ESSYSTEM.HPP"\
	".\..\..\inc\ESTERRAN.HPP"\
	".\..\..\inc\ESTXTURE.HPP"\
	".\..\..\inc\GUTENBRG.H"\
	".\..\..\inc\IVMem.h"\
	".\..\..\inc\Ivory.ipp"\
	".\..\..\inc\MaxDevs.HPP"\
	".\..\..\inc\MaxESrc.HPP"\
	".\..\..\inc\MaxEvt.HPP"\
	".\..\..\inc\MYTHOS.H"\
	".\..\..\inc\VNGBD.HPP"\
	".\..\..\inc\VNGCOLOR.HPP"\
	".\..\..\inc\VNGDEFS.H"\
	".\..\..\inc\VNGPAL.HPP"\
	".\..\..\inc\VNGSTRCT.HPP"\
	".\..\..\inc\VNGVP.HPP"\
	".\..\..\inc\vngvpdb8.hpp"\
	".\..\..\inc\VNGVPDD8.HPP"\
	".\..\..\inc\VNGVVP8.HPP"\
	".\..\..\inc\XFBASE.HPP"\
	".\..\..\inc\XFBITMAP.HPP"\
	".\..\..\inc\XFDEFS.H"\
	".\..\..\inc\XFIFF.HPP"\
	".\..\..\inc\XFINI.HPP"\
	".\mainfrm.h"\
	".\Paltodoc.h"\
	".\paltool.h"\
	".\paltovw.h"\
	".\stdafx.h"\
	

"$(INTDIR)\paltool.obj" : $(SOURCE) $(DEP_CPP_PALTOO) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\paltovw.cpp
DEP_CPP_PALTOV=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\inc\BZARTN.H"\
	".\..\..\inc\BZQUEUE.H"\
	".\..\..\inc\BZSEMAP.H"\
	".\..\..\inc\BZTASK.H"\
	".\..\..\inc\BZWRAP.HPP"\
	".\..\..\inc\DEBUG.H"\
	".\..\..\inc\esbasic.hpp"\
	".\..\..\inc\ESCAMERA.HPP"\
	".\..\..\inc\ESCONTXT.HPP"\
	".\..\..\inc\ESDEFS.H"\
	".\..\..\inc\ESDRAW.HPP"\
	".\..\..\inc\esexts.hpp"\
	".\..\..\inc\ESGEOM.HPP"\
	".\..\..\inc\ESLIGHT.HPP"\
	".\..\..\inc\ESMATH.HPP"\
	".\..\..\inc\esmisc.hpp"\
	".\..\..\inc\ESPARTIK.HPP"\
	".\..\..\inc\ESSCENE.HPP"\
	".\..\..\inc\ESSYSTEM.HPP"\
	".\..\..\inc\ESTERRAN.HPP"\
	".\..\..\inc\ESTXTURE.HPP"\
	".\..\..\inc\GUTENBRG.H"\
	".\..\..\inc\IVMem.h"\
	".\..\..\inc\Ivory.ipp"\
	".\..\..\inc\MaxDevs.HPP"\
	".\..\..\inc\MaxESrc.HPP"\
	".\..\..\inc\MaxEvt.HPP"\
	".\..\..\inc\MYTHOS.H"\
	".\..\..\inc\VNGBD.HPP"\
	".\..\..\inc\VNGCOLOR.HPP"\
	".\..\..\inc\VNGDEFS.H"\
	".\..\..\inc\VNGPAL.HPP"\
	".\..\..\inc\VNGSTRCT.HPP"\
	".\..\..\inc\VNGVP.HPP"\
	".\..\..\inc\vngvpdb8.hpp"\
	".\..\..\inc\VNGVPDD8.HPP"\
	".\..\..\inc\VNGVVP8.HPP"\
	".\..\..\inc\XFBASE.HPP"\
	".\..\..\inc\XFBITMAP.HPP"\
	".\..\..\inc\XFDEFS.H"\
	".\..\..\inc\XFIFF.HPP"\
	".\..\..\inc\XFINI.HPP"\
	".\bezier.h"\
	".\dialog.h"\
	".\Paltodoc.h"\
	".\paltool.h"\
	".\paltovw.h"\
	".\stdafx.h"\
	

"$(INTDIR)\paltovw.obj" : $(SOURCE) $(DEP_CPP_PALTOV) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\readme.txt

!IF  "$(CFG)" == "Paltool - Win32 Debug"

!ELSEIF  "$(CFG)" == "Paltool - Win32 Release"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\paltool.rc
DEP_RSC_PALTOOL=\
	".\res\PalTodoc.ico"\
	".\res\PalTool.ico"\
	".\res\PalTool.rc2"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\paltool.res" : $(SOURCE) $(DEP_RSC_PALTOOL) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\stdafx.cpp
DEP_CPP_STDAF=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\inc\BZARTN.H"\
	".\..\..\inc\BZQUEUE.H"\
	".\..\..\inc\BZSEMAP.H"\
	".\..\..\inc\BZTASK.H"\
	".\..\..\inc\BZWRAP.HPP"\
	".\..\..\inc\DEBUG.H"\
	".\..\..\inc\esbasic.hpp"\
	".\..\..\inc\ESCAMERA.HPP"\
	".\..\..\inc\ESCONTXT.HPP"\
	".\..\..\inc\ESDEFS.H"\
	".\..\..\inc\ESDRAW.HPP"\
	".\..\..\inc\esexts.hpp"\
	".\..\..\inc\ESGEOM.HPP"\
	".\..\..\inc\ESLIGHT.HPP"\
	".\..\..\inc\ESMATH.HPP"\
	".\..\..\inc\esmisc.hpp"\
	".\..\..\inc\ESPARTIK.HPP"\
	".\..\..\inc\ESSCENE.HPP"\
	".\..\..\inc\ESSYSTEM.HPP"\
	".\..\..\inc\ESTERRAN.HPP"\
	".\..\..\inc\ESTXTURE.HPP"\
	".\..\..\inc\GUTENBRG.H"\
	".\..\..\inc\IVMem.h"\
	".\..\..\inc\Ivory.ipp"\
	".\..\..\inc\MaxDevs.HPP"\
	".\..\..\inc\MaxESrc.HPP"\
	".\..\..\inc\MaxEvt.HPP"\
	".\..\..\inc\MYTHOS.H"\
	".\..\..\inc\VNGBD.HPP"\
	".\..\..\inc\VNGCOLOR.HPP"\
	".\..\..\inc\VNGDEFS.H"\
	".\..\..\inc\VNGPAL.HPP"\
	".\..\..\inc\VNGSTRCT.HPP"\
	".\..\..\inc\VNGVP.HPP"\
	".\..\..\inc\vngvpdb8.hpp"\
	".\..\..\inc\VNGVPDD8.HPP"\
	".\..\..\inc\VNGVVP8.HPP"\
	".\..\..\inc\XFBASE.HPP"\
	".\..\..\inc\XFBITMAP.HPP"\
	".\..\..\inc\XFDEFS.H"\
	".\..\..\inc\XFIFF.HPP"\
	".\..\..\inc\XFINI.HPP"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Paltool - Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Paltool.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Paltool.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Paltool - Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Paltool.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Paltool.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
