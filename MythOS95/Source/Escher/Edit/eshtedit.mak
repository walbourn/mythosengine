# Microsoft Developer Studio Generated NMAKE File, Based on eshtedit.dsp
!IF "$(CFG)" == ""
CFG=eshtedit - Win32 Debug
!MESSAGE No configuration specified. Defaulting to eshtedit - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "eshtedit - Win32 Debug" && "$(CFG)" !=\
 "eshtedit - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\.\WinDebug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\eshtedit.exe" "$(OUTDIR)\eshtedit.bsc"

!ELSE 

ALL : "$(OUTDIR)\eshtedit.exe" "$(OUTDIR)\eshtedit.bsc"

!ENDIF 

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
	-@erase "$(INTDIR)\eshtedit.pch"
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
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\eshtedit.bsc"
	-@erase "$(OUTDIR)\eshtedit.exe"
	-@erase "$(OUTDIR)\eshtedit.ilk"
	-@erase "$(OUTDIR)\eshtedit.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G5 /MD /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr"$(INTDIR)\\"\
 /Fp"$(INTDIR)\eshtedit.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=.\WinDebug/
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\eshtedit.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\eshtedit.bsc" 
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

"$(OUTDIR)\eshtedit.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\eshtedit.pdb" /debug /machine:I386 /nodefaultlib:"LIBC"\
 /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\eshtedit.exe" 
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

"$(OUTDIR)\eshtedit.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\.\WinRel
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\eshtedit.exe"

!ELSE 

ALL : "$(OUTDIR)\eshtedit.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\eshtdlg.obj"
	-@erase "$(INTDIR)\eshtdlgt.obj"
	-@erase "$(INTDIR)\eshtdlgx.obj"
	-@erase "$(INTDIR)\eshtdoc.obj"
	-@erase "$(INTDIR)\eshtdoci.obj"
	-@erase "$(INTDIR)\eshtedit.obj"
	-@erase "$(INTDIR)\eshtedit.pch"
	-@erase "$(INTDIR)\eshtedit.res"
	-@erase "$(INTDIR)\Eshtgrid.obj"
	-@erase "$(INTDIR)\Eshtlist.obj"
	-@erase "$(INTDIR)\eshtmfrm.obj"
	-@erase "$(INTDIR)\Eshtrend.obj"
	-@erase "$(INTDIR)\Eshtusgs.obj"
	-@erase "$(INTDIR)\eshtview.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\eshtedit.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G5 /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtedit.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\eshtedit.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\eshtedit.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib ..\..\lib\mythos.lib ..\..\lib\ivorymfc.lib\
 ..\..\lib\bozo.lib ..\..\lib\xfile.lib ..\..\lib\chronos.lib\
 ..\..\lib\escher.lib ..\..\lib\gutenbrg.lib ..\..\lib\felix.lib\
 ..\..\lib\vangogh.lib /nologo /version:4 /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\eshtedit.pdb" /machine:I386 /nodefaultlib:"LIBC"\
 /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\eshtedit.exe" 
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

"$(OUTDIR)\eshtedit.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

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

MTL_PROJ=/mktyplib203 

!IF "$(CFG)" == "eshtedit - Win32 Debug" || "$(CFG)" ==\
 "eshtedit - Win32 Release"
SOURCE=.\eshtdlg.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

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
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\eshtusgs.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtdlg.obj"	"$(INTDIR)\eshtdlg.sbr" : $(SOURCE) $(DEP_CPP_ESHTD)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTD=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlg.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\eshtusgs.h"\
	

"$(INTDIR)\eshtdlg.obj" : $(SOURCE) $(DEP_CPP_ESHTD) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtdlgt.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

DEP_CPP_ESHTDL=\
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
	".\eshtdlgt.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtdlgt.obj"	"$(INTDIR)\eshtdlgt.sbr" : $(SOURCE) $(DEP_CPP_ESHTDL)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTDL=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlg.h"\
	".\eshtdlgt.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	

"$(INTDIR)\eshtdlgt.obj" : $(SOURCE) $(DEP_CPP_ESHTDL) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtdlgx.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

DEP_CPP_ESHTDLG=\
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
	".\eshtdlgx.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtdlgx.obj"	"$(INTDIR)\eshtdlgx.sbr" : $(SOURCE)\
 $(DEP_CPP_ESHTDLG) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTDLG=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlgx.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	

"$(INTDIR)\eshtdlgx.obj" : $(SOURCE) $(DEP_CPP_ESHTDLG) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtdoc.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

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
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtdoc.obj"	"$(INTDIR)\eshtdoc.sbr" : $(SOURCE) $(DEP_CPP_ESHTDO)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTDO=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esfile.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlg.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	

"$(INTDIR)\eshtdoc.obj" : $(SOURCE) $(DEP_CPP_ESHTDO) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtdoci.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

DEP_CPP_ESHTDOC=\
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
	

"$(INTDIR)\eshtdoci.obj"	"$(INTDIR)\eshtdoci.sbr" : $(SOURCE)\
 $(DEP_CPP_ESHTDOC) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTDOC=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\esfile.hpp"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\Dem.h"\
	".\eshtdlg.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtrend.h"\
	".\eshtusgs.h"\
	".\Eshtview.h"\
	

"$(INTDIR)\eshtdoci.obj" : $(SOURCE) $(DEP_CPP_ESHTDOC) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtedit.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

DEP_CPP_ESHTE=\
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
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtedit.obj"	"$(INTDIR)\eshtedit.sbr" : $(SOURCE) $(DEP_CPP_ESHTE)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTE=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	

"$(INTDIR)\eshtedit.obj" : $(SOURCE) $(DEP_CPP_ESHTE) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtedit.rc
DEP_RSC_ESHTED=\
	".\RES\about.bmp"\
	".\res\eshtdoc.ico"\
	".\res\eshtedit.ico"\
	".\res\eshtedit.rc2"\
	".\RES\logo.bmp"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\eshtedit.res" : $(SOURCE) $(DEP_RSC_ESHTED) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Eshtgrid.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

DEP_CPP_ESHTG=\
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
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

"$(INTDIR)\Eshtgrid.obj"	"$(INTDIR)\Eshtgrid.sbr" : $(SOURCE) $(DEP_CPP_ESHTG)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTG=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	

"$(INTDIR)\Eshtgrid.obj" : $(SOURCE) $(DEP_CPP_ESHTG) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\Eshtlist.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

DEP_CPP_ESHTL=\
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
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

"$(INTDIR)\Eshtlist.obj"	"$(INTDIR)\Eshtlist.sbr" : $(SOURCE) $(DEP_CPP_ESHTL)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTL=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	

"$(INTDIR)\Eshtlist.obj" : $(SOURCE) $(DEP_CPP_ESHTL) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtmfrm.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

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
	".\eshtdlgt.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtmfrm.obj"	"$(INTDIR)\eshtmfrm.sbr" : $(SOURCE) $(DEP_CPP_ESHTM)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTM=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlg.h"\
	".\eshtdlgt.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	

"$(INTDIR)\eshtmfrm.obj" : $(SOURCE) $(DEP_CPP_ESHTM) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\Eshtrend.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

DEP_CPP_ESHTR=\
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
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

"$(INTDIR)\Eshtrend.obj"	"$(INTDIR)\Eshtrend.sbr" : $(SOURCE) $(DEP_CPP_ESHTR)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTR=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlg.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	

"$(INTDIR)\Eshtrend.obj" : $(SOURCE) $(DEP_CPP_ESHTR) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\Eshtusgs.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

DEP_CPP_ESHTU=\
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
	".\Eshtedit.h"\
	".\eshtusgs.h"\
	".\stdafx.h"\
	

"$(INTDIR)\Eshtusgs.obj"	"$(INTDIR)\Eshtusgs.sbr" : $(SOURCE) $(DEP_CPP_ESHTU)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTU=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlg.h"\
	".\Eshtedit.h"\
	".\eshtusgs.h"\
	

"$(INTDIR)\Eshtusgs.obj" : $(SOURCE) $(DEP_CPP_ESHTU) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtview.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

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
	".\eshtdlgx.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	".\stdafx.h"\
	

"$(INTDIR)\eshtview.obj"	"$(INTDIR)\eshtview.sbr" : $(SOURCE) $(DEP_CPP_ESHTV)\
 "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

DEP_CPP_ESHTV=\
	"..\..\inc\esdefs.h"\
	"..\..\inc\felix.hpp"\
	"..\..\inc\portable.h"\
	".\eshtdlgx.h"\
	".\Eshtdoc.h"\
	".\Eshtedit.h"\
	".\Eshtgrid.h"\
	".\Eshtlist.h"\
	".\Eshtmfrm.h"\
	".\Eshtrend.h"\
	".\Eshtview.h"\
	

"$(INTDIR)\eshtview.obj" : $(SOURCE) $(DEP_CPP_ESHTV) "$(INTDIR)"\
 "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

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
	
CPP_SWITCHES=/nologo /G5 /MD /W3 /Gm /GX /Zi /Od /I "..\..\inc" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr"$(INTDIR)\\"\
 /Fp"$(INTDIR)\eshtedit.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\eshtedit.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

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
	
CPP_SWITCHES=/nologo /G5 /MD /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtedit.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\eshtedit.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

