# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=eshtool - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to eshtool - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "eshtool - Win32 Debug" && "$(CFG)" !=\
 "eshtool - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "eshtool.mak" CFG="eshtool - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "eshtool - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "eshtool - Win32 Release" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "eshtool - Win32 Release"
MTL=mktyplib.exe
RSC=rc.exe
CPP=cl.exe

!IF  "$(CFG)" == "eshtool - Win32 Debug"

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

ALL : "$(OUTDIR)\eshtool.exe"

CLEAN : 
	-@erase "$(INTDIR)\eshtdlg.obj"
	-@erase "$(INTDIR)\eshtdoc.obj"
	-@erase "$(INTDIR)\eshtmfrm.obj"
	-@erase "$(INTDIR)\eshtool.obj"
	-@erase "$(INTDIR)\eshtool.pch"
	-@erase "$(INTDIR)\eshtool.res"
	-@erase "$(INTDIR)\eshttree.obj"
	-@erase "$(INTDIR)\eshtview.obj"
	-@erase "$(INTDIR)\eshtvp.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\eshtool.exe"
	-@erase "$(OUTDIR)\eshtool.ilk"
	-@erase "$(OUTDIR)\eshtool.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/eshtool.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/eshtool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/eshtool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /debug /machine:I386 /nodefaultlib:"LIBC"
# SUBTRACT LINK32 /verbose /pdb:none /map /nodefaultlib
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/eshtool.pdb" /debug /machine:I386 /nodefaultlib:"LIBC"\
 /out:"$(OUTDIR)/eshtool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\eshtdlg.obj" \
	"$(INTDIR)\eshtdoc.obj" \
	"$(INTDIR)\eshtmfrm.obj" \
	"$(INTDIR)\eshtool.obj" \
	"$(INTDIR)\eshtool.res" \
	"$(INTDIR)\eshttree.obj" \
	"$(INTDIR)\eshtview.obj" \
	"$(INTDIR)\eshtvp.obj" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\eshtool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

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

ALL : "$(OUTDIR)\eshtool.exe"

CLEAN : 
	-@erase "$(INTDIR)\eshtdlg.obj"
	-@erase "$(INTDIR)\eshtdoc.obj"
	-@erase "$(INTDIR)\eshtmfrm.obj"
	-@erase "$(INTDIR)\eshtool.obj"
	-@erase "$(INTDIR)\eshtool.pch"
	-@erase "$(INTDIR)\eshtool.res"
	-@erase "$(INTDIR)\eshttree.obj"
	-@erase "$(INTDIR)\eshtview.obj"
	-@erase "$(INTDIR)\eshtvp.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(OUTDIR)\eshtool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/eshtool.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/eshtool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/eshtool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /machine:I386 /nodefaultlib:"LIBC"
# SUBTRACT LINK32 /verbose /pdb:none /map /nodefaultlib
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/eshtool.pdb" /machine:I386 /nodefaultlib:"LIBC"\
 /out:"$(OUTDIR)/eshtool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\eshtdlg.obj" \
	"$(INTDIR)\eshtdoc.obj" \
	"$(INTDIR)\eshtmfrm.obj" \
	"$(INTDIR)\eshtool.obj" \
	"$(INTDIR)\eshtool.res" \
	"$(INTDIR)\eshttree.obj" \
	"$(INTDIR)\eshtview.obj" \
	"$(INTDIR)\eshtvp.obj" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\eshtool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "eshtool - Win32 Debug"
# Name "eshtool - Win32 Release"

!IF  "$(CFG)" == "eshtool - Win32 Debug"

!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

!ENDIF 

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
	"..\..\Inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\Inc\BZARTN.H"\
	".\..\..\Inc\BZQUEUE.H"\
	".\..\..\Inc\BZSEMAP.H"\
	".\..\..\Inc\BZTASK.H"\
	".\..\..\Inc\BZWRAP.HPP"\
	".\..\..\Inc\DEBUG.H"\
	".\..\..\Inc\esbasic.hpp"\
	".\..\..\Inc\ESCAMERA.HPP"\
	".\..\..\Inc\ESCONTXT.HPP"\
	".\..\..\Inc\ESDEFS.H"\
	".\..\..\Inc\ESDRAW.HPP"\
	".\..\..\Inc\esexts.hpp"\
	".\..\..\Inc\ESGEOM.HPP"\
	".\..\..\Inc\ESLIGHT.HPP"\
	".\..\..\Inc\ESMATH.HPP"\
	".\..\..\Inc\esmisc.hpp"\
	".\..\..\Inc\ESPARTIK.HPP"\
	".\..\..\Inc\ESSCENE.HPP"\
	".\..\..\Inc\ESSYSTEM.HPP"\
	".\..\..\Inc\ESTERRAN.HPP"\
	".\..\..\Inc\ESTXTURE.HPP"\
	".\..\..\Inc\GUTENBRG.H"\
	".\..\..\Inc\IVMem.h"\
	".\..\..\Inc\Ivory.ipp"\
	".\..\..\Inc\MaxDevs.HPP"\
	".\..\..\Inc\MaxESrc.HPP"\
	".\..\..\Inc\MaxEvt.HPP"\
	".\..\..\Inc\MYTHOS.H"\
	".\..\..\Inc\VNGBD.HPP"\
	".\..\..\Inc\VNGCOLOR.HPP"\
	".\..\..\Inc\VNGDEFS.H"\
	".\..\..\Inc\VNGPAL.HPP"\
	".\..\..\Inc\VNGSTRCT.HPP"\
	".\..\..\Inc\VNGVP.HPP"\
	".\..\..\Inc\vngvpdb8.hpp"\
	".\..\..\Inc\VNGVPDD8.HPP"\
	".\..\..\Inc\vngvvp16.hpp"\
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtool - Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/eshtool.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\eshtool.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/eshtool.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\eshtool.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtool.cpp
DEP_CPP_ESHTO=\
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
	"..\..\Inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\Inc\BZARTN.H"\
	".\..\..\Inc\BZQUEUE.H"\
	".\..\..\Inc\BZSEMAP.H"\
	".\..\..\Inc\BZTASK.H"\
	".\..\..\Inc\BZWRAP.HPP"\
	".\..\..\Inc\DEBUG.H"\
	".\..\..\Inc\esbasic.hpp"\
	".\..\..\Inc\ESCAMERA.HPP"\
	".\..\..\Inc\ESCONTXT.HPP"\
	".\..\..\Inc\ESDEFS.H"\
	".\..\..\Inc\ESDRAW.HPP"\
	".\..\..\Inc\esexts.hpp"\
	".\..\..\Inc\ESGEOM.HPP"\
	".\..\..\Inc\ESLIGHT.HPP"\
	".\..\..\Inc\ESMATH.HPP"\
	".\..\..\Inc\esmisc.hpp"\
	".\..\..\Inc\ESPARTIK.HPP"\
	".\..\..\Inc\ESSCENE.HPP"\
	".\..\..\Inc\ESSYSTEM.HPP"\
	".\..\..\Inc\ESTERRAN.HPP"\
	".\..\..\Inc\ESTXTURE.HPP"\
	".\..\..\Inc\GUTENBRG.H"\
	".\..\..\Inc\IVMem.h"\
	".\..\..\Inc\Ivory.ipp"\
	".\..\..\Inc\MaxDevs.HPP"\
	".\..\..\Inc\MaxESrc.HPP"\
	".\..\..\Inc\MaxEvt.HPP"\
	".\..\..\Inc\MYTHOS.H"\
	".\..\..\Inc\VNGBD.HPP"\
	".\..\..\Inc\VNGCOLOR.HPP"\
	".\..\..\Inc\VNGDEFS.H"\
	".\..\..\Inc\VNGPAL.HPP"\
	".\..\..\Inc\VNGSTRCT.HPP"\
	".\..\..\Inc\VNGVP.HPP"\
	".\..\..\Inc\vngvpdb8.hpp"\
	".\..\..\Inc\VNGVPDD8.HPP"\
	".\..\..\Inc\vngvvp16.hpp"\
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdoc.h"\
	".\eshtmfrm.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtool.obj" : $(SOURCE) $(DEP_CPP_ESHTO) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtmfrm.cpp
DEP_CPP_ESHTM=\
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
	"..\..\Inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\Inc\BZARTN.H"\
	".\..\..\Inc\BZQUEUE.H"\
	".\..\..\Inc\BZSEMAP.H"\
	".\..\..\Inc\BZTASK.H"\
	".\..\..\Inc\BZWRAP.HPP"\
	".\..\..\Inc\DEBUG.H"\
	".\..\..\Inc\esbasic.hpp"\
	".\..\..\Inc\ESCAMERA.HPP"\
	".\..\..\Inc\ESCONTXT.HPP"\
	".\..\..\Inc\ESDEFS.H"\
	".\..\..\Inc\ESDRAW.HPP"\
	".\..\..\Inc\esexts.hpp"\
	".\..\..\Inc\ESGEOM.HPP"\
	".\..\..\Inc\ESLIGHT.HPP"\
	".\..\..\Inc\ESMATH.HPP"\
	".\..\..\Inc\esmisc.hpp"\
	".\..\..\Inc\ESPARTIK.HPP"\
	".\..\..\Inc\ESSCENE.HPP"\
	".\..\..\Inc\ESSYSTEM.HPP"\
	".\..\..\Inc\ESTERRAN.HPP"\
	".\..\..\Inc\ESTXTURE.HPP"\
	".\..\..\Inc\GUTENBRG.H"\
	".\..\..\Inc\IVMem.h"\
	".\..\..\Inc\Ivory.ipp"\
	".\..\..\Inc\MaxDevs.HPP"\
	".\..\..\Inc\MaxESrc.HPP"\
	".\..\..\Inc\MaxEvt.HPP"\
	".\..\..\Inc\MYTHOS.H"\
	".\..\..\Inc\VNGBD.HPP"\
	".\..\..\Inc\VNGCOLOR.HPP"\
	".\..\..\Inc\VNGDEFS.H"\
	".\..\..\Inc\VNGPAL.HPP"\
	".\..\..\Inc\VNGSTRCT.HPP"\
	".\..\..\Inc\VNGVP.HPP"\
	".\..\..\Inc\vngvpdb8.hpp"\
	".\..\..\Inc\VNGVPDD8.HPP"\
	".\..\..\Inc\vngvvp16.hpp"\
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdoc.h"\
	".\eshtmfrm.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtmfrm.obj" : $(SOURCE) $(DEP_CPP_ESHTM) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtdoc.cpp
DEP_CPP_ESHTD=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\esfile.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\max.hpp"\
	"..\..\Inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\Inc\BZARTN.H"\
	".\..\..\Inc\BZQUEUE.H"\
	".\..\..\Inc\BZSEMAP.H"\
	".\..\..\Inc\BZTASK.H"\
	".\..\..\Inc\BZWRAP.HPP"\
	".\..\..\Inc\DEBUG.H"\
	".\..\..\Inc\esbasic.hpp"\
	".\..\..\Inc\ESCAMERA.HPP"\
	".\..\..\Inc\ESCONTXT.HPP"\
	".\..\..\Inc\ESDEFS.H"\
	".\..\..\Inc\ESDRAW.HPP"\
	".\..\..\Inc\esexts.hpp"\
	".\..\..\Inc\ESGEOM.HPP"\
	".\..\..\Inc\ESLIGHT.HPP"\
	".\..\..\Inc\ESMATH.HPP"\
	".\..\..\Inc\esmisc.hpp"\
	".\..\..\Inc\ESPARTIK.HPP"\
	".\..\..\Inc\ESSCENE.HPP"\
	".\..\..\Inc\ESSYSTEM.HPP"\
	".\..\..\Inc\ESTERRAN.HPP"\
	".\..\..\Inc\ESTXTURE.HPP"\
	".\..\..\Inc\GUTENBRG.H"\
	".\..\..\Inc\IVMem.h"\
	".\..\..\Inc\Ivory.ipp"\
	".\..\..\Inc\MaxDevs.HPP"\
	".\..\..\Inc\MaxESrc.HPP"\
	".\..\..\Inc\MaxEvt.HPP"\
	".\..\..\Inc\MYTHOS.H"\
	".\..\..\Inc\VNGBD.HPP"\
	".\..\..\Inc\VNGCOLOR.HPP"\
	".\..\..\Inc\VNGDEFS.H"\
	".\..\..\Inc\VNGPAL.HPP"\
	".\..\..\Inc\VNGSTRCT.HPP"\
	".\..\..\Inc\VNGVP.HPP"\
	".\..\..\Inc\vngvpdb8.hpp"\
	".\..\..\Inc\VNGVPDD8.HPP"\
	".\..\..\Inc\vngvvp16.hpp"\
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtdoc.obj" : $(SOURCE) $(DEP_CPP_ESHTD) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtview.cpp
DEP_CPP_ESHTV=\
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
	"..\..\Inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\Inc\BZARTN.H"\
	".\..\..\Inc\BZQUEUE.H"\
	".\..\..\Inc\BZSEMAP.H"\
	".\..\..\Inc\BZTASK.H"\
	".\..\..\Inc\BZWRAP.HPP"\
	".\..\..\Inc\DEBUG.H"\
	".\..\..\Inc\esbasic.hpp"\
	".\..\..\Inc\ESCAMERA.HPP"\
	".\..\..\Inc\ESCONTXT.HPP"\
	".\..\..\Inc\ESDEFS.H"\
	".\..\..\Inc\ESDRAW.HPP"\
	".\..\..\Inc\esexts.hpp"\
	".\..\..\Inc\ESGEOM.HPP"\
	".\..\..\Inc\ESLIGHT.HPP"\
	".\..\..\Inc\ESMATH.HPP"\
	".\..\..\Inc\esmisc.hpp"\
	".\..\..\Inc\ESPARTIK.HPP"\
	".\..\..\Inc\ESSCENE.HPP"\
	".\..\..\Inc\ESSYSTEM.HPP"\
	".\..\..\Inc\ESTERRAN.HPP"\
	".\..\..\Inc\ESTXTURE.HPP"\
	".\..\..\Inc\GUTENBRG.H"\
	".\..\..\Inc\IVMem.h"\
	".\..\..\Inc\Ivory.ipp"\
	".\..\..\Inc\MaxDevs.HPP"\
	".\..\..\Inc\MaxESrc.HPP"\
	".\..\..\Inc\MaxEvt.HPP"\
	".\..\..\Inc\MYTHOS.H"\
	".\..\..\Inc\VNGBD.HPP"\
	".\..\..\Inc\VNGCOLOR.HPP"\
	".\..\..\Inc\VNGDEFS.H"\
	".\..\..\Inc\VNGPAL.HPP"\
	".\..\..\Inc\VNGSTRCT.HPP"\
	".\..\..\Inc\VNGVP.HPP"\
	".\..\..\Inc\vngvpdb8.hpp"\
	".\..\..\Inc\VNGVPDD8.HPP"\
	".\..\..\Inc\vngvvp16.hpp"\
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlg.h"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtview.obj" : $(SOURCE) $(DEP_CPP_ESHTV) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtool.rc
DEP_RSC_ESHTOO=\
	".\res\camera.ico"\
	".\res\cameras.ico"\
	".\res\eshdoc.ico"\
	".\res\eshtool.ico"\
	".\res\eshtool.rc2"\
	".\res\light.ico"\
	".\res\light_s.ico"\
	".\res\mesh.ico"\
	".\res\mesh_s.ico"\
	".\res\scene.ico"\
	".\res\scene_s.ico"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\eshtool.res" : $(SOURCE) $(DEP_RSC_ESHTOO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\readme.txt

!IF  "$(CFG)" == "eshtool - Win32 Debug"

!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtvp.cpp
DEP_CPP_ESHTVP=\
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
	"..\..\Inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\Inc\BZARTN.H"\
	".\..\..\Inc\BZQUEUE.H"\
	".\..\..\Inc\BZSEMAP.H"\
	".\..\..\Inc\BZTASK.H"\
	".\..\..\Inc\BZWRAP.HPP"\
	".\..\..\Inc\DEBUG.H"\
	".\..\..\Inc\esbasic.hpp"\
	".\..\..\Inc\ESCAMERA.HPP"\
	".\..\..\Inc\ESCONTXT.HPP"\
	".\..\..\Inc\ESDEFS.H"\
	".\..\..\Inc\ESDRAW.HPP"\
	".\..\..\Inc\esexts.hpp"\
	".\..\..\Inc\ESGEOM.HPP"\
	".\..\..\Inc\ESLIGHT.HPP"\
	".\..\..\Inc\ESMATH.HPP"\
	".\..\..\Inc\esmisc.hpp"\
	".\..\..\Inc\ESPARTIK.HPP"\
	".\..\..\Inc\ESSCENE.HPP"\
	".\..\..\Inc\ESSYSTEM.HPP"\
	".\..\..\Inc\ESTERRAN.HPP"\
	".\..\..\Inc\ESTXTURE.HPP"\
	".\..\..\Inc\GUTENBRG.H"\
	".\..\..\Inc\IVMem.h"\
	".\..\..\Inc\Ivory.ipp"\
	".\..\..\Inc\MaxDevs.HPP"\
	".\..\..\Inc\MaxESrc.HPP"\
	".\..\..\Inc\MaxEvt.HPP"\
	".\..\..\Inc\MYTHOS.H"\
	".\..\..\Inc\VNGBD.HPP"\
	".\..\..\Inc\VNGCOLOR.HPP"\
	".\..\..\Inc\VNGDEFS.H"\
	".\..\..\Inc\VNGPAL.HPP"\
	".\..\..\Inc\VNGSTRCT.HPP"\
	".\..\..\Inc\VNGVP.HPP"\
	".\..\..\Inc\vngvpdb8.hpp"\
	".\..\..\Inc\VNGVPDD8.HPP"\
	".\..\..\Inc\vngvvp16.hpp"\
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtvp.obj" : $(SOURCE) $(DEP_CPP_ESHTVP) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshttree.cpp
DEP_CPP_ESHTT=\
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
	"..\..\Inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\Inc\BZARTN.H"\
	".\..\..\Inc\BZQUEUE.H"\
	".\..\..\Inc\BZSEMAP.H"\
	".\..\..\Inc\BZTASK.H"\
	".\..\..\Inc\BZWRAP.HPP"\
	".\..\..\Inc\DEBUG.H"\
	".\..\..\Inc\esbasic.hpp"\
	".\..\..\Inc\ESCAMERA.HPP"\
	".\..\..\Inc\ESCONTXT.HPP"\
	".\..\..\Inc\ESDEFS.H"\
	".\..\..\Inc\ESDRAW.HPP"\
	".\..\..\Inc\esexts.hpp"\
	".\..\..\Inc\ESGEOM.HPP"\
	".\..\..\Inc\ESLIGHT.HPP"\
	".\..\..\Inc\ESMATH.HPP"\
	".\..\..\Inc\esmisc.hpp"\
	".\..\..\Inc\ESPARTIK.HPP"\
	".\..\..\Inc\ESSCENE.HPP"\
	".\..\..\Inc\ESSYSTEM.HPP"\
	".\..\..\Inc\ESTERRAN.HPP"\
	".\..\..\Inc\ESTXTURE.HPP"\
	".\..\..\Inc\GUTENBRG.H"\
	".\..\..\Inc\IVMem.h"\
	".\..\..\Inc\Ivory.ipp"\
	".\..\..\Inc\MaxDevs.HPP"\
	".\..\..\Inc\MaxESrc.HPP"\
	".\..\..\Inc\MaxEvt.HPP"\
	".\..\..\Inc\MYTHOS.H"\
	".\..\..\Inc\VNGBD.HPP"\
	".\..\..\Inc\VNGCOLOR.HPP"\
	".\..\..\Inc\VNGDEFS.H"\
	".\..\..\Inc\VNGPAL.HPP"\
	".\..\..\Inc\VNGSTRCT.HPP"\
	".\..\..\Inc\VNGVP.HPP"\
	".\..\..\Inc\vngvpdb8.hpp"\
	".\..\..\Inc\VNGVPDD8.HPP"\
	".\..\..\Inc\vngvvp16.hpp"\
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshttree.obj" : $(SOURCE) $(DEP_CPP_ESHTT) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtdlg.cpp
DEP_CPP_ESHTDL=\
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
	"..\..\Inc\maxvmap.hpp"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfio.h"\
	".\..\..\Inc\BZARTN.H"\
	".\..\..\Inc\BZQUEUE.H"\
	".\..\..\Inc\BZSEMAP.H"\
	".\..\..\Inc\BZTASK.H"\
	".\..\..\Inc\BZWRAP.HPP"\
	".\..\..\Inc\DEBUG.H"\
	".\..\..\Inc\esbasic.hpp"\
	".\..\..\Inc\ESCAMERA.HPP"\
	".\..\..\Inc\ESCONTXT.HPP"\
	".\..\..\Inc\ESDEFS.H"\
	".\..\..\Inc\ESDRAW.HPP"\
	".\..\..\Inc\esexts.hpp"\
	".\..\..\Inc\ESGEOM.HPP"\
	".\..\..\Inc\ESLIGHT.HPP"\
	".\..\..\Inc\ESMATH.HPP"\
	".\..\..\Inc\esmisc.hpp"\
	".\..\..\Inc\ESPARTIK.HPP"\
	".\..\..\Inc\ESSCENE.HPP"\
	".\..\..\Inc\ESSYSTEM.HPP"\
	".\..\..\Inc\ESTERRAN.HPP"\
	".\..\..\Inc\ESTXTURE.HPP"\
	".\..\..\Inc\GUTENBRG.H"\
	".\..\..\Inc\IVMem.h"\
	".\..\..\Inc\Ivory.ipp"\
	".\..\..\Inc\MaxDevs.HPP"\
	".\..\..\Inc\MaxESrc.HPP"\
	".\..\..\Inc\MaxEvt.HPP"\
	".\..\..\Inc\MYTHOS.H"\
	".\..\..\Inc\VNGBD.HPP"\
	".\..\..\Inc\VNGCOLOR.HPP"\
	".\..\..\Inc\VNGDEFS.H"\
	".\..\..\Inc\VNGPAL.HPP"\
	".\..\..\Inc\VNGSTRCT.HPP"\
	".\..\..\Inc\VNGVP.HPP"\
	".\..\..\Inc\vngvpdb8.hpp"\
	".\..\..\Inc\VNGVPDD8.HPP"\
	".\..\..\Inc\vngvvp16.hpp"\
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlg.h"\
	".\eshtool.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtdlg.obj" : $(SOURCE) $(DEP_CPP_ESHTDL) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


# End Source File
# End Target
# End Project
################################################################################
