# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=eshtedit - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to eshtedit - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "eshtedit - Win32 Debug" && "$(CFG)" !=\
 "eshtedit - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Eshtedit.mak" CFG="eshtedit - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "eshtedit - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "eshtedit - Win32 Release" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "eshtedit - Win32 Release"
MTL=mktyplib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

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

ALL : "$(OUTDIR)\Eshtedit.exe" "$(OUTDIR)\Eshtedit.bsc"

CLEAN : 
	-@erase "$(INTDIR)\eshtdlg.obj"
	-@erase "$(INTDIR)\eshtdlg.sbr"
	-@erase "$(INTDIR)\eshtdlgt.obj"
	-@erase "$(INTDIR)\eshtdlgt.sbr"
	-@erase "$(INTDIR)\eshtdlgx.obj"
	-@erase "$(INTDIR)\eshtdlgx.sbr"
	-@erase "$(INTDIR)\eshtdoc.obj"
	-@erase "$(INTDIR)\eshtdoc.sbr"
	-@erase "$(INTDIR)\eshtdoci.obj"
	-@erase "$(INTDIR)\eshtdoci.sbr"
	-@erase "$(INTDIR)\eshtedit.obj"
	-@erase "$(INTDIR)\Eshtedit.pch"
	-@erase "$(INTDIR)\eshtedit.res"
	-@erase "$(INTDIR)\eshtedit.sbr"
	-@erase "$(INTDIR)\Eshtgrid.obj"
	-@erase "$(INTDIR)\Eshtgrid.sbr"
	-@erase "$(INTDIR)\Eshtlist.obj"
	-@erase "$(INTDIR)\Eshtlist.sbr"
	-@erase "$(INTDIR)\eshtmfrm.obj"
	-@erase "$(INTDIR)\eshtmfrm.sbr"
	-@erase "$(INTDIR)\Eshtrend.obj"
	-@erase "$(INTDIR)\Eshtrend.sbr"
	-@erase "$(INTDIR)\Eshtusgs.obj"
	-@erase "$(INTDIR)\Eshtusgs.sbr"
	-@erase "$(INTDIR)\eshtview.obj"
	-@erase "$(INTDIR)\eshtview.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Eshtedit.bsc"
	-@erase "$(OUTDIR)\Eshtedit.exe"
	-@erase "$(OUTDIR)\Eshtedit.ilk"
	-@erase "$(OUTDIR)\Eshtedit.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr"$(INTDIR)/"\
 /Fp"$(INTDIR)/Eshtedit.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=.\WinDebug/
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/eshtedit.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Eshtedit.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\eshtdlg.sbr" \
	"$(INTDIR)\eshtdlgt.sbr" \
	"$(INTDIR)\eshtdlgx.sbr" \
	"$(INTDIR)\eshtdoc.sbr" \
	"$(INTDIR)\eshtdoci.sbr" \
	"$(INTDIR)\eshtedit.sbr" \
	"$(INTDIR)\Eshtgrid.sbr" \
	"$(INTDIR)\Eshtlist.sbr" \
	"$(INTDIR)\eshtmfrm.sbr" \
	"$(INTDIR)\Eshtrend.sbr" \
	"$(INTDIR)\Eshtusgs.sbr" \
	"$(INTDIR)\eshtview.sbr" \
	"$(INTDIR)\stdafx.sbr"

"$(OUTDIR)\Eshtedit.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /debug /machine:I386 /nodefaultlib:"LIBC"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Eshtedit.pdb" /debug /machine:I386 /nodefaultlib:"LIBC"\
 /out:"$(OUTDIR)/Eshtedit.exe" 
LINK32_OBJS= \
	"$(INTDIR)\eshtdlg.obj" \
	"$(INTDIR)\eshtdlgt.obj" \
	"$(INTDIR)\eshtdlgx.obj" \
	"$(INTDIR)\eshtdoc.obj" \
	"$(INTDIR)\eshtdoci.obj" \
	"$(INTDIR)\eshtedit.obj" \
	"$(INTDIR)\eshtedit.res" \
	"$(INTDIR)\Eshtgrid.obj" \
	"$(INTDIR)\Eshtlist.obj" \
	"$(INTDIR)\eshtmfrm.obj" \
	"$(INTDIR)\Eshtrend.obj" \
	"$(INTDIR)\Eshtusgs.obj" \
	"$(INTDIR)\eshtview.obj" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\Eshtedit.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

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

ALL : "$(OUTDIR)\Eshtedit.exe"

CLEAN : 
	-@erase "$(INTDIR)\eshtdlg.obj"
	-@erase "$(INTDIR)\eshtdlgt.obj"
	-@erase "$(INTDIR)\eshtdlgx.obj"
	-@erase "$(INTDIR)\eshtdoc.obj"
	-@erase "$(INTDIR)\eshtdoci.obj"
	-@erase "$(INTDIR)\eshtedit.obj"
	-@erase "$(INTDIR)\Eshtedit.pch"
	-@erase "$(INTDIR)\eshtedit.res"
	-@erase "$(INTDIR)\Eshtgrid.obj"
	-@erase "$(INTDIR)\Eshtlist.obj"
	-@erase "$(INTDIR)\eshtmfrm.obj"
	-@erase "$(INTDIR)\Eshtrend.obj"
	-@erase "$(INTDIR)\Eshtusgs.obj"
	-@erase "$(INTDIR)\eshtview.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(OUTDIR)\Eshtedit.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Eshtedit.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/eshtedit.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Eshtedit.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /machine:I386 /nodefaultlib:"LIBC"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Eshtedit.pdb" /machine:I386 /nodefaultlib:"LIBC"\
 /out:"$(OUTDIR)/Eshtedit.exe" 
LINK32_OBJS= \
	"$(INTDIR)\eshtdlg.obj" \
	"$(INTDIR)\eshtdlgt.obj" \
	"$(INTDIR)\eshtdlgx.obj" \
	"$(INTDIR)\eshtdoc.obj" \
	"$(INTDIR)\eshtdoci.obj" \
	"$(INTDIR)\eshtedit.obj" \
	"$(INTDIR)\eshtedit.res" \
	"$(INTDIR)\Eshtgrid.obj" \
	"$(INTDIR)\Eshtlist.obj" \
	"$(INTDIR)\eshtmfrm.obj" \
	"$(INTDIR)\Eshtrend.obj" \
	"$(INTDIR)\Eshtusgs.obj" \
	"$(INTDIR)\eshtview.obj" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\Eshtedit.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "eshtedit - Win32 Debug"
# Name "eshtedit - Win32 Release"

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr"$(INTDIR)/"\
 /Fp"$(INTDIR)/Eshtedit.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c\
 $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\stdafx.sbr" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Eshtedit.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Eshtedit.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Eshtedit.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtedit.cpp
DEP_CPP_ESHTE=\
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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtedit.obj" : $(SOURCE) $(DEP_CPP_ESHTE) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\eshtedit.sbr" : $(SOURCE) $(DEP_CPP_ESHTE) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtedit.obj" : $(SOURCE) $(DEP_CPP_ESHTE) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlg.h"\
	".\eshtdlgt.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtmfrm.obj" : $(SOURCE) $(DEP_CPP_ESHTM) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\eshtmfrm.sbr" : $(SOURCE) $(DEP_CPP_ESHTM) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtmfrm.obj" : $(SOURCE) $(DEP_CPP_ESHTM) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlg.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdoc.obj" : $(SOURCE) $(DEP_CPP_ESHTD) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\eshtdoc.sbr" : $(SOURCE) $(DEP_CPP_ESHTD) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdoc.obj" : $(SOURCE) $(DEP_CPP_ESHTD) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlgx.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtview.obj" : $(SOURCE) $(DEP_CPP_ESHTV) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\eshtview.sbr" : $(SOURCE) $(DEP_CPP_ESHTV) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtview.obj" : $(SOURCE) $(DEP_CPP_ESHTV) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtedit.rc
DEP_RSC_ESHTED=\
	".\res\eshtdoc.ico"\
	".\res\eshtedit.ico"\
	".\res\eshtedit.rc2"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\eshtedit.res" : $(SOURCE) $(DEP_RSC_ESHTED) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\readme.txt

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

!ENDIF 

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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlg.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\eshtusgs.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdlg.obj" : $(SOURCE) $(DEP_CPP_ESHTDL) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\eshtdlg.sbr" : $(SOURCE) $(DEP_CPP_ESHTDL) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdlg.obj" : $(SOURCE) $(DEP_CPP_ESHTDL) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Eshtlist.cpp
DEP_CPP_ESHTL=\
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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\Eshtlist.obj" : $(SOURCE) $(DEP_CPP_ESHTL) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\Eshtlist.sbr" : $(SOURCE) $(DEP_CPP_ESHTL) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\Eshtlist.obj" : $(SOURCE) $(DEP_CPP_ESHTL) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Eshtgrid.cpp
DEP_CPP_ESHTG=\
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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\Eshtgrid.obj" : $(SOURCE) $(DEP_CPP_ESHTG) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\Eshtgrid.sbr" : $(SOURCE) $(DEP_CPP_ESHTG) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\Eshtgrid.obj" : $(SOURCE) $(DEP_CPP_ESHTG) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Eshtrend.cpp
DEP_CPP_ESHTR=\
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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlg.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\Eshtrend.obj" : $(SOURCE) $(DEP_CPP_ESHTR) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\Eshtrend.sbr" : $(SOURCE) $(DEP_CPP_ESHTR) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\Eshtrend.obj" : $(SOURCE) $(DEP_CPP_ESHTR) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Eshtusgs.cpp
DEP_CPP_ESHTU=\
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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlg.h"\
	".\Eshtedit.h"\
	".\eshtusgs.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\Eshtusgs.obj" : $(SOURCE) $(DEP_CPP_ESHTU) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\Eshtusgs.sbr" : $(SOURCE) $(DEP_CPP_ESHTU) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\Eshtusgs.obj" : $(SOURCE) $(DEP_CPP_ESHTU) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtdoci.cpp
DEP_CPP_ESHTDO=\
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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\Dem.h"\
	".\eshtdlg.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtrend.h"\
	".\eshtusgs.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdoci.obj" : $(SOURCE) $(DEP_CPP_ESHTDO) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\eshtdoci.sbr" : $(SOURCE) $(DEP_CPP_ESHTDO) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdoci.obj" : $(SOURCE) $(DEP_CPP_ESHTDO) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtdlgt.cpp
DEP_CPP_ESHTDLG=\
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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlg.h"\
	".\eshtdlgt.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdlgt.obj" : $(SOURCE) $(DEP_CPP_ESHTDLG) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\eshtdlgt.sbr" : $(SOURCE) $(DEP_CPP_ESHTDLG) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdlgt.obj" : $(SOURCE) $(DEP_CPP_ESHTDLG) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eshtdlgx.cpp
DEP_CPP_ESHTDLGX=\
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
	"..\..\Inc\vngvvp16.hpp"\
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
	".\..\..\Inc\VNGVVP8.HPP"\
	".\..\..\Inc\XFBASE.HPP"\
	".\..\..\Inc\XFBITMAP.HPP"\
	".\..\..\Inc\XFDEFS.H"\
	".\..\..\Inc\XFIFF.HPP"\
	".\..\..\Inc\XFINI.HPP"\
	".\eshtdlgx.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdlgx.obj" : $(SOURCE) $(DEP_CPP_ESHTDLGX) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"

"$(INTDIR)\eshtdlgx.sbr" : $(SOURCE) $(DEP_CPP_ESHTDLGX) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdlgx.obj" : $(SOURCE) $(DEP_CPP_ESHTDLGX) "$(INTDIR)"\
 "$(INTDIR)\Eshtedit.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
