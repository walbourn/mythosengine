# Microsoft Developer Studio Generated NMAKE File, Based on eshtool.dsp
!IF "$(CFG)" == ""
CFG=eshtool - Win32 Debug
!MESSAGE No configuration specified. Defaulting to eshtool - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "eshtool - Win32 Debug" && "$(CFG)" !=\
 "eshtool - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "eshtool - Win32 Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\.\WinDebug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\eshtool.exe"

!ELSE 

ALL : "$(OUTDIR)\eshtool.exe"

!ENDIF 

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
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\eshtool.exe"
	-@erase "$(OUTDIR)\eshtool.ilk"
	-@erase "$(OUTDIR)\eshtool.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtool.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\eshtool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\eshtool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\eshtool.pdb" /debug /machine:I386 /nodefaultlib:"LIBC"\
 /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\eshtool.exe" 
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

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\.\WinRel
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\eshtool.exe"

!ELSE 

ALL : "$(OUTDIR)\eshtool.exe"

!ENDIF 

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
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\eshtool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtool.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\eshtool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\eshtool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\eshtool.pdb" /machine:I386 /nodefaultlib:"LIBC"\
 /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\eshtool.exe" 
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


!IF "$(CFG)" == "eshtool - Win32 Debug" || "$(CFG)" ==\
 "eshtool - Win32 Release"
SOURCE=.\eshtdlg.cpp

!IF  "$(CFG)" == "eshtool - Win32 Debug"

DEP_CPP_ESHTD=\
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
	"..\..\inc\eselemnt.hpp"\
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
	".\eshtdlg.h"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	{$(INCLUDE)}"gl\gl.h"\
	

"$(INTDIR)\eshtdlg.obj" : $(SOURCE) $(DEP_CPP_ESHTD) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

DEP_CPP_ESHTD=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlg.h"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	

"$(INTDIR)\eshtdlg.obj" : $(SOURCE) $(DEP_CPP_ESHTD) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ENDIF 

SOURCE=.\eshtdoc.cpp

!IF  "$(CFG)" == "eshtool - Win32 Debug"

DEP_CPP_ESHTDO=\
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
	"..\..\inc\eselemnt.hpp"\
	"..\..\inc\esexts.hpp"\
	"..\..\inc\esfile.hpp"\
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
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	{$(INCLUDE)}"gl\gl.h"\
	

"$(INTDIR)\eshtdoc.obj" : $(SOURCE) $(DEP_CPP_ESHTDO) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

DEP_CPP_ESHTDO=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esfile.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	

"$(INTDIR)\eshtdoc.obj" : $(SOURCE) $(DEP_CPP_ESHTDO) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ENDIF 

SOURCE=.\eshtmfrm.cpp

!IF  "$(CFG)" == "eshtool - Win32 Debug"

DEP_CPP_ESHTM=\
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
	"..\..\inc\eselemnt.hpp"\
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
	".\eshtdoc.h"\
	".\eshtmfrm.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	{$(INCLUDE)}"gl\gl.h"\
	

"$(INTDIR)\eshtmfrm.obj" : $(SOURCE) $(DEP_CPP_ESHTM) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

DEP_CPP_ESHTM=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdoc.h"\
	".\eshtmfrm.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	

"$(INTDIR)\eshtmfrm.obj" : $(SOURCE) $(DEP_CPP_ESHTM) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ENDIF 

SOURCE=.\eshtool.cpp

!IF  "$(CFG)" == "eshtool - Win32 Debug"

DEP_CPP_ESHTO=\
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
	"..\..\inc\eselemnt.hpp"\
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
	".\eshtdoc.h"\
	".\eshtmfrm.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	{$(INCLUDE)}"gl\gl.h"\
	

"$(INTDIR)\eshtool.obj" : $(SOURCE) $(DEP_CPP_ESHTO) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

DEP_CPP_ESHTO=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdoc.h"\
	".\eshtmfrm.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	

"$(INTDIR)\eshtool.obj" : $(SOURCE) $(DEP_CPP_ESHTO) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ENDIF 

SOURCE=.\eshtool.rc
DEP_RSC_ESHTOO=\
	".\res\about.bmp"\
	".\res\camera.ico"\
	".\res\cameras.ico"\
	".\res\eshdoc.ico"\
	".\res\eshtool.ico"\
	".\res\eshtool.rc2"\
	".\res\light.ico"\
	".\res\light_s.ico"\
	".\res\logo.bmp"\
	".\res\mesh.ico"\
	".\res\mesh_s.ico"\
	".\res\scene.ico"\
	".\res\scene_s.ico"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\eshtool.res" : $(SOURCE) $(DEP_RSC_ESHTOO) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\eshttree.cpp

!IF  "$(CFG)" == "eshtool - Win32 Debug"

DEP_CPP_ESHTT=\
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
	"..\..\inc\eselemnt.hpp"\
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
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	{$(INCLUDE)}"gl\gl.h"\
	

"$(INTDIR)\eshttree.obj" : $(SOURCE) $(DEP_CPP_ESHTT) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

DEP_CPP_ESHTT=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	

"$(INTDIR)\eshttree.obj" : $(SOURCE) $(DEP_CPP_ESHTT) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ENDIF 

SOURCE=.\eshtview.cpp

!IF  "$(CFG)" == "eshtool - Win32 Debug"

DEP_CPP_ESHTV=\
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
	"..\..\inc\eselemnt.hpp"\
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
	".\eshtdlg.h"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	{$(INCLUDE)}"gl\gl.h"\
	

"$(INTDIR)\eshtview.obj" : $(SOURCE) $(DEP_CPP_ESHTV) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

DEP_CPP_ESHTV=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlg.h"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\eshttree.h"\
	".\eshtview.h"\
	".\eshtvp.h"\
	

"$(INTDIR)\eshtview.obj" : $(SOURCE) $(DEP_CPP_ESHTV) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ENDIF 

SOURCE=.\eshtvp.cpp

!IF  "$(CFG)" == "eshtool - Win32 Debug"

DEP_CPP_ESHTVP=\
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
	"..\..\inc\eselemnt.hpp"\
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
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\eshtvp.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"dinput.h"\
	{$(INCLUDE)}"gl\gl.h"\
	

"$(INTDIR)\eshtvp.obj" : $(SOURCE) $(DEP_CPP_ESHTVP) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

DEP_CPP_ESHTVP=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdoc.h"\
	".\eshtool.h"\
	".\eshtvp.h"\
	

"$(INTDIR)\eshtvp.obj" : $(SOURCE) $(DEP_CPP_ESHTVP) "$(INTDIR)"\
 "$(INTDIR)\eshtool.pch"


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "eshtool - Win32 Debug"

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
	"..\..\inc\eselemnt.hpp"\
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
	{$(INCLUDE)}"gl\gl.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtool.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\eshtool.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

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
	"..\..\inc\eselemnt.hpp"\
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
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtool.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\eshtool.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

