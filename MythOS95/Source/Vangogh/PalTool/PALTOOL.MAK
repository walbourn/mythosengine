# Microsoft Developer Studio Generated NMAKE File, Based on Paltool.dsp
!IF "$(CFG)" == ""
CFG=Paltool - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Paltool - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Paltool - Win32 Debug" && "$(CFG)" !=\
 "Paltool - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
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

!IF  "$(CFG)" == "Paltool - Win32 Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\.\WinDebug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Paltool.exe"

!ELSE 

ALL : "$(OUTDIR)\Paltool.exe"

!ENDIF 

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
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Paltool.exe"
	-@erase "$(OUTDIR)\Paltool.ilk"
	-@erase "$(OUTDIR)\Paltool.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Paltool.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/mktyplib203 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\paltool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Paltool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\Paltool.pdb" /debug /machine:I386 /nodefaultlib:"libc"\
 /out:"$(OUTDIR)\Paltool.exe" /VERSION:4,0 
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

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\.\WinRel
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Paltool.exe"

!ELSE 

ALL : "$(OUTDIR)\Paltool.exe"

!ENDIF 

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
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Paltool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Paltool.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/mktyplib203 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\paltool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Paltool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\Paltool.pdb" /machine:I386 /nodefaultlib:"libc"\
 /out:"$(OUTDIR)\Paltool.exe" /VERSION:4,0 
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


!IF "$(CFG)" == "Paltool - Win32 Debug" || "$(CFG)" ==\
 "Paltool - Win32 Release"
SOURCE=.\bezier.cpp
DEP_CPP_BEZIE=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\bzartn.h"\
	"..\..\inc\bzqueue.h"\
	"..\..\inc\bzsemap.h"\
	"..\..\inc\bztask.h"\
	"..\..\inc\bzwrap.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\debug.h"\
	"..\..\inc\esbasic.hpp"\
	"..\..\inc\esbuild.hpp"\
	"..\..\inc\escamera.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\escontxt.hpp"\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esdraw.hpp"\
	"..\..\inc\esexts.hpp"\
	"..\..\inc\esgeom.hpp"\
	"..\..\inc\eskeyfrm.hpp"\
	"..\..\inc\eslight.hpp"\
	"..\..\inc\eslimb.hpp"\
	"..\..\inc\esmath.hpp"\
	"..\..\inc\esmisc.hpp"\
	"..\..\inc\espartik.hpp"\
	"..\..\inc\espartn.hpp"\
	"..\..\inc\esscene.hpp"\
	"..\..\inc\essystem.hpp"\
	"..\..\inc\esterran.hpp"\
	"..\..\inc\estrtop.hpp"\
	"..\..\inc\estxture.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.h"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivmem.h"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\ivory.ipp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxdevs.hpp"\
	"..\..\inc\maxesrc.hpp"\
	"..\..\inc\maxevt.hpp"\
	"..\..\inc\maxjoy.hpp"\
	"..\..\inc\maxkb.hpp"\
	"..\..\inc\maxmouse.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.h"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vgvpdb16.hpp"\
	"..\..\inc\vgvpdd16.hpp"\
	"..\..\inc\vngcolor.hpp"\
	"..\..\inc\vngd3d.hpp"\
	"..\..\inc\vngdefs.h"\
	"..\..\inc\vngoems.hpp"\
	"..\..\inc\vngpal.hpp"\
	"..\..\inc\vngscrn.hpp"\
	"..\..\inc\vngstrct.hpp"\
	"..\..\inc\vngtxtr.hpp"\
	"..\..\inc\vngvp.hpp"\
	"..\..\inc\vngvpdb8.hpp"\
	"..\..\inc\vngvpdd8.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\vngvvp8.hpp"\
	"..\..\inc\xfbase.hpp"\
	"..\..\inc\xfbitmap.hpp"\
	"..\..\inc\xfdefs.h"\
	"..\..\inc\xfiff.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfini.hpp"\
	"..\..\inc\xfio.h"\
	".\bezier.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	

"$(INTDIR)\bezier.obj" : $(SOURCE) $(DEP_CPP_BEZIE) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


SOURCE=.\dialog.cpp
DEP_CPP_DIALO=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\bzartn.h"\
	"..\..\inc\bzqueue.h"\
	"..\..\inc\bzsemap.h"\
	"..\..\inc\bztask.h"\
	"..\..\inc\bzwrap.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\debug.h"\
	"..\..\inc\esbasic.hpp"\
	"..\..\inc\esbuild.hpp"\
	"..\..\inc\escamera.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\escontxt.hpp"\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esdraw.hpp"\
	"..\..\inc\esexts.hpp"\
	"..\..\inc\esgeom.hpp"\
	"..\..\inc\eskeyfrm.hpp"\
	"..\..\inc\eslight.hpp"\
	"..\..\inc\eslimb.hpp"\
	"..\..\inc\esmath.hpp"\
	"..\..\inc\esmisc.hpp"\
	"..\..\inc\espartik.hpp"\
	"..\..\inc\espartn.hpp"\
	"..\..\inc\esscene.hpp"\
	"..\..\inc\essystem.hpp"\
	"..\..\inc\esterran.hpp"\
	"..\..\inc\estrtop.hpp"\
	"..\..\inc\estxture.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.h"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivmem.h"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\ivory.ipp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxdevs.hpp"\
	"..\..\inc\maxesrc.hpp"\
	"..\..\inc\maxevt.hpp"\
	"..\..\inc\maxjoy.hpp"\
	"..\..\inc\maxkb.hpp"\
	"..\..\inc\maxmouse.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.h"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vgvpdb16.hpp"\
	"..\..\inc\vgvpdd16.hpp"\
	"..\..\inc\vngcolor.hpp"\
	"..\..\inc\vngd3d.hpp"\
	"..\..\inc\vngdefs.h"\
	"..\..\inc\vngoems.hpp"\
	"..\..\inc\vngpal.hpp"\
	"..\..\inc\vngscrn.hpp"\
	"..\..\inc\vngstrct.hpp"\
	"..\..\inc\vngtxtr.hpp"\
	"..\..\inc\vngvp.hpp"\
	"..\..\inc\vngvpdb8.hpp"\
	"..\..\inc\vngvpdd8.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\vngvvp8.hpp"\
	"..\..\inc\xfbase.hpp"\
	"..\..\inc\xfbitmap.hpp"\
	"..\..\inc\xfdefs.h"\
	"..\..\inc\xfiff.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfini.hpp"\
	"..\..\inc\xfio.h"\
	".\dialog.h"\
	".\paltool.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	

"$(INTDIR)\dialog.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


SOURCE=.\mainfrm.cpp
DEP_CPP_MAINF=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\bzartn.h"\
	"..\..\inc\bzqueue.h"\
	"..\..\inc\bzsemap.h"\
	"..\..\inc\bztask.h"\
	"..\..\inc\bzwrap.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\debug.h"\
	"..\..\inc\esbasic.hpp"\
	"..\..\inc\esbuild.hpp"\
	"..\..\inc\escamera.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\escontxt.hpp"\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esdraw.hpp"\
	"..\..\inc\esexts.hpp"\
	"..\..\inc\esgeom.hpp"\
	"..\..\inc\eskeyfrm.hpp"\
	"..\..\inc\eslight.hpp"\
	"..\..\inc\eslimb.hpp"\
	"..\..\inc\esmath.hpp"\
	"..\..\inc\esmisc.hpp"\
	"..\..\inc\espartik.hpp"\
	"..\..\inc\espartn.hpp"\
	"..\..\inc\esscene.hpp"\
	"..\..\inc\essystem.hpp"\
	"..\..\inc\esterran.hpp"\
	"..\..\inc\estrtop.hpp"\
	"..\..\inc\estxture.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.h"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivmem.h"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\ivory.ipp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxdevs.hpp"\
	"..\..\inc\maxesrc.hpp"\
	"..\..\inc\maxevt.hpp"\
	"..\..\inc\maxjoy.hpp"\
	"..\..\inc\maxkb.hpp"\
	"..\..\inc\maxmouse.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.h"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vgvpdb16.hpp"\
	"..\..\inc\vgvpdd16.hpp"\
	"..\..\inc\vngcolor.hpp"\
	"..\..\inc\vngd3d.hpp"\
	"..\..\inc\vngdefs.h"\
	"..\..\inc\vngoems.hpp"\
	"..\..\inc\vngpal.hpp"\
	"..\..\inc\vngscrn.hpp"\
	"..\..\inc\vngstrct.hpp"\
	"..\..\inc\vngtxtr.hpp"\
	"..\..\inc\vngvp.hpp"\
	"..\..\inc\vngvpdb8.hpp"\
	"..\..\inc\vngvpdd8.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\vngvvp8.hpp"\
	"..\..\inc\xfbase.hpp"\
	"..\..\inc\xfbitmap.hpp"\
	"..\..\inc\xfdefs.h"\
	"..\..\inc\xfiff.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfini.hpp"\
	"..\..\inc\xfio.h"\
	".\mainfrm.h"\
	".\paltool.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


SOURCE=.\paltodoc.cpp
DEP_CPP_PALTO=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\bzartn.h"\
	"..\..\inc\bzqueue.h"\
	"..\..\inc\bzsemap.h"\
	"..\..\inc\bztask.h"\
	"..\..\inc\bzwrap.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\debug.h"\
	"..\..\inc\esbasic.hpp"\
	"..\..\inc\esbuild.hpp"\
	"..\..\inc\escamera.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\escontxt.hpp"\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esdraw.hpp"\
	"..\..\inc\esexts.hpp"\
	"..\..\inc\esgeom.hpp"\
	"..\..\inc\eskeyfrm.hpp"\
	"..\..\inc\eslight.hpp"\
	"..\..\inc\eslimb.hpp"\
	"..\..\inc\esmath.hpp"\
	"..\..\inc\esmisc.hpp"\
	"..\..\inc\espartik.hpp"\
	"..\..\inc\espartn.hpp"\
	"..\..\inc\esscene.hpp"\
	"..\..\inc\essystem.hpp"\
	"..\..\inc\esterran.hpp"\
	"..\..\inc\estrtop.hpp"\
	"..\..\inc\estxture.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.h"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivmem.h"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\ivory.ipp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxdevs.hpp"\
	"..\..\inc\maxesrc.hpp"\
	"..\..\inc\maxevt.hpp"\
	"..\..\inc\maxjoy.hpp"\
	"..\..\inc\maxkb.hpp"\
	"..\..\inc\maxmouse.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.h"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vgvpdb16.hpp"\
	"..\..\inc\vgvpdd16.hpp"\
	"..\..\inc\vngcolor.hpp"\
	"..\..\inc\vngd3d.hpp"\
	"..\..\inc\vngdefs.h"\
	"..\..\inc\vngoems.hpp"\
	"..\..\inc\vngpal.hpp"\
	"..\..\inc\vngscrn.hpp"\
	"..\..\inc\vngstrct.hpp"\
	"..\..\inc\vngtxtr.hpp"\
	"..\..\inc\vngvp.hpp"\
	"..\..\inc\vngvpdb8.hpp"\
	"..\..\inc\vngvpdd8.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\vngvvp8.hpp"\
	"..\..\inc\xfbase.hpp"\
	"..\..\inc\xfbitmap.hpp"\
	"..\..\inc\xfdefs.h"\
	"..\..\inc\xfiff.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfini.hpp"\
	"..\..\inc\xfio.h"\
	".\dialog.h"\
	".\Paltodoc.h"\
	".\paltool.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	

"$(INTDIR)\paltodoc.obj" : $(SOURCE) $(DEP_CPP_PALTO) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


SOURCE=.\paltool.cpp
DEP_CPP_PALTOO=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\bzartn.h"\
	"..\..\inc\bzqueue.h"\
	"..\..\inc\bzsemap.h"\
	"..\..\inc\bztask.h"\
	"..\..\inc\bzwrap.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\debug.h"\
	"..\..\inc\esbasic.hpp"\
	"..\..\inc\esbuild.hpp"\
	"..\..\inc\escamera.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\escontxt.hpp"\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esdraw.hpp"\
	"..\..\inc\esexts.hpp"\
	"..\..\inc\esgeom.hpp"\
	"..\..\inc\eskeyfrm.hpp"\
	"..\..\inc\eslight.hpp"\
	"..\..\inc\eslimb.hpp"\
	"..\..\inc\esmath.hpp"\
	"..\..\inc\esmisc.hpp"\
	"..\..\inc\espartik.hpp"\
	"..\..\inc\espartn.hpp"\
	"..\..\inc\esscene.hpp"\
	"..\..\inc\essystem.hpp"\
	"..\..\inc\esterran.hpp"\
	"..\..\inc\estrtop.hpp"\
	"..\..\inc\estxture.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.h"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivmem.h"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\ivory.ipp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxdevs.hpp"\
	"..\..\inc\maxesrc.hpp"\
	"..\..\inc\maxevt.hpp"\
	"..\..\inc\maxjoy.hpp"\
	"..\..\inc\maxkb.hpp"\
	"..\..\inc\maxmouse.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.h"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vgvpdb16.hpp"\
	"..\..\inc\vgvpdd16.hpp"\
	"..\..\inc\vngcolor.hpp"\
	"..\..\inc\vngd3d.hpp"\
	"..\..\inc\vngdefs.h"\
	"..\..\inc\vngoems.hpp"\
	"..\..\inc\vngpal.hpp"\
	"..\..\inc\vngscrn.hpp"\
	"..\..\inc\vngstrct.hpp"\
	"..\..\inc\vngtxtr.hpp"\
	"..\..\inc\vngvp.hpp"\
	"..\..\inc\vngvpdb8.hpp"\
	"..\..\inc\vngvpdd8.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\vngvvp8.hpp"\
	"..\..\inc\xfbase.hpp"\
	"..\..\inc\xfbitmap.hpp"\
	"..\..\inc\xfdefs.h"\
	"..\..\inc\xfiff.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfini.hpp"\
	"..\..\inc\xfio.h"\
	".\mainfrm.h"\
	".\Paltodoc.h"\
	".\paltool.h"\
	".\paltovw.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	

"$(INTDIR)\paltool.obj" : $(SOURCE) $(DEP_CPP_PALTOO) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


SOURCE=.\paltool.rc
DEP_RSC_PALTOOL=\
	".\Res\about.bmp"\
	".\Res\logo.bmp"\
	".\res\PalTodoc.ico"\
	".\res\PalTool.ico"\
	".\res\PalTool.rc2"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\paltool.res" : $(SOURCE) $(DEP_RSC_PALTOOL) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\paltovw.cpp
DEP_CPP_PALTOV=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\bzartn.h"\
	"..\..\inc\bzqueue.h"\
	"..\..\inc\bzsemap.h"\
	"..\..\inc\bztask.h"\
	"..\..\inc\bzwrap.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\debug.h"\
	"..\..\inc\esbasic.hpp"\
	"..\..\inc\esbuild.hpp"\
	"..\..\inc\escamera.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\escontxt.hpp"\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esdraw.hpp"\
	"..\..\inc\esexts.hpp"\
	"..\..\inc\esgeom.hpp"\
	"..\..\inc\eskeyfrm.hpp"\
	"..\..\inc\eslight.hpp"\
	"..\..\inc\eslimb.hpp"\
	"..\..\inc\esmath.hpp"\
	"..\..\inc\esmisc.hpp"\
	"..\..\inc\espartik.hpp"\
	"..\..\inc\espartn.hpp"\
	"..\..\inc\esscene.hpp"\
	"..\..\inc\essystem.hpp"\
	"..\..\inc\esterran.hpp"\
	"..\..\inc\estrtop.hpp"\
	"..\..\inc\estxture.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.h"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivmem.h"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\ivory.ipp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxdevs.hpp"\
	"..\..\inc\maxesrc.hpp"\
	"..\..\inc\maxevt.hpp"\
	"..\..\inc\maxjoy.hpp"\
	"..\..\inc\maxkb.hpp"\
	"..\..\inc\maxmouse.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.h"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vgvpdb16.hpp"\
	"..\..\inc\vgvpdd16.hpp"\
	"..\..\inc\vngcolor.hpp"\
	"..\..\inc\vngd3d.hpp"\
	"..\..\inc\vngdefs.h"\
	"..\..\inc\vngoems.hpp"\
	"..\..\inc\vngpal.hpp"\
	"..\..\inc\vngscrn.hpp"\
	"..\..\inc\vngstrct.hpp"\
	"..\..\inc\vngtxtr.hpp"\
	"..\..\inc\vngvp.hpp"\
	"..\..\inc\vngvpdb8.hpp"\
	"..\..\inc\vngvpdd8.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\vngvvp8.hpp"\
	"..\..\inc\xfbase.hpp"\
	"..\..\inc\xfbitmap.hpp"\
	"..\..\inc\xfdefs.h"\
	"..\..\inc\xfiff.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfini.hpp"\
	"..\..\inc\xfio.h"\
	".\bezier.h"\
	".\dialog.h"\
	".\Paltodoc.h"\
	".\paltool.h"\
	".\paltovw.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	

"$(INTDIR)\paltovw.obj" : $(SOURCE) $(DEP_CPP_PALTOV) "$(INTDIR)"\
 "$(INTDIR)\Paltool.pch"


SOURCE=.\stdafx.cpp
DEP_CPP_STDAF=\
	"..\..\inc\bozo.h"\
	"..\..\inc\bozo.hpp"\
	"..\..\inc\bzartn.h"\
	"..\..\inc\bzqueue.h"\
	"..\..\inc\bzsemap.h"\
	"..\..\inc\bztask.h"\
	"..\..\inc\bzwrap.hpp"\
	"..\..\inc\chronos.hpp"\
	"..\..\inc\debug.h"\
	"..\..\inc\esbasic.hpp"\
	"..\..\inc\esbuild.hpp"\
	"..\..\inc\escamera.hpp"\
	"..\..\inc\escher.hpp"\
	"..\..\inc\escontxt.hpp"\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esdraw.hpp"\
	"..\..\inc\esexts.hpp"\
	"..\..\inc\esgeom.hpp"\
	"..\..\inc\eskeyfrm.hpp"\
	"..\..\inc\eslight.hpp"\
	"..\..\inc\eslimb.hpp"\
	"..\..\inc\esmath.hpp"\
	"..\..\inc\esmisc.hpp"\
	"..\..\inc\espartik.hpp"\
	"..\..\inc\espartn.hpp"\
	"..\..\inc\esscene.hpp"\
	"..\..\inc\essystem.hpp"\
	"..\..\inc\esterran.hpp"\
	"..\..\inc\estrtop.hpp"\
	"..\..\inc\estxture.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\felix.ipp"\
	"..\..\inc\gutenbrg.h"\
	"..\..\inc\gutenbrg.hpp"\
	"..\..\inc\ivmem.h"\
	"..\..\inc\ivory.h"\
	"..\..\inc\ivory.hpp"\
	"..\..\inc\ivory.ipp"\
	"..\..\inc\max.hpp"\
	"..\..\inc\maxdevs.hpp"\
	"..\..\inc\maxesrc.hpp"\
	"..\..\inc\maxevt.hpp"\
	"..\..\inc\maxjoy.hpp"\
	"..\..\inc\maxkb.hpp"\
	"..\..\inc\maxmouse.hpp"\
	"..\..\inc\maxvmap.hpp"\
	"..\..\inc\mythos.h"\
	"..\..\inc\mythos.hpp"\
	"..\..\inc\portable.h"\
	"..\..\inc\vangogh.hpp"\
	"..\..\inc\vgvpdb16.hpp"\
	"..\..\inc\vgvpdd16.hpp"\
	"..\..\inc\vngcolor.hpp"\
	"..\..\inc\vngd3d.hpp"\
	"..\..\inc\vngdefs.h"\
	"..\..\inc\vngoems.hpp"\
	"..\..\inc\vngpal.hpp"\
	"..\..\inc\vngscrn.hpp"\
	"..\..\inc\vngstrct.hpp"\
	"..\..\inc\vngtxtr.hpp"\
	"..\..\inc\vngvp.hpp"\
	"..\..\inc\vngvpdb8.hpp"\
	"..\..\inc\vngvpdd8.hpp"\
	"..\..\inc\vngvvp16.hpp"\
	"..\..\inc\vngvvp8.hpp"\
	"..\..\inc\xfbase.hpp"\
	"..\..\inc\xfbitmap.hpp"\
	"..\..\inc\xfdefs.h"\
	"..\..\inc\xfiff.hpp"\
	"..\..\inc\xfile.hpp"\
	"..\..\inc\xfini.hpp"\
	"..\..\inc\xfio.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	

!IF  "$(CFG)" == "Paltool - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Paltool.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\Paltool.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Paltool - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Paltool.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\Paltool.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

