# Microsoft Developer Studio Generated NMAKE File, Based on eshtool.dsp
!IF "$(CFG)" == ""
CFG=eshtool - Win32 Debug
!MESSAGE No configuration specified. Defaulting to eshtool - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "eshtool - Win32 Debug" && "$(CFG)" != "eshtool - Win32 Release"
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

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "eshtool - Win32 Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\WinDebug
# End Custom Macros

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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\eshtool.exe"
	-@erase "$(OUTDIR)\eshtool.ilk"
	-@erase "$(OUTDIR)\eshtool.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\inc" /I "..\..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\eshtool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\eshtool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib mythos.lib ivorymfc.lib bozo.lib xfile.lib chronos.lib escher.lib gutenbrg.lib felix.lib vangogh.lib /nologo /version:4 /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\eshtool.pdb" /debug /machine:I386 /nodefaultlib:"LIBC" /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\eshtool.exe" /libpath:"..\..\lib" /libpath:"..\..\..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\eshtdlg.obj" \
	"$(INTDIR)\eshtdoc.obj" \
	"$(INTDIR)\eshtmfrm.obj" \
	"$(INTDIR)\eshtool.obj" \
	"$(INTDIR)\eshttree.obj" \
	"$(INTDIR)\eshtview.obj" \
	"$(INTDIR)\eshtvp.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\eshtool.res"

"$(OUTDIR)\eshtool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\WinRel
# End Custom Macros

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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\eshtool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /I "..\..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\eshtool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\eshtool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib mythos.lib ivorymfc.lib bozo.lib xfile.lib chronos.lib escher.lib gutenbrg.lib felix.lib vangogh.lib /nologo /version:4 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\eshtool.pdb" /machine:I386 /nodefaultlib:"LIBC" /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\eshtool.exe" /libpath:"..\..\lib" /libpath:"..\..\..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\eshtdlg.obj" \
	"$(INTDIR)\eshtdoc.obj" \
	"$(INTDIR)\eshtmfrm.obj" \
	"$(INTDIR)\eshtool.obj" \
	"$(INTDIR)\eshttree.obj" \
	"$(INTDIR)\eshtview.obj" \
	"$(INTDIR)\eshtvp.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\eshtool.res"

"$(OUTDIR)\eshtool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL_PROJ=/mktyplib203 

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("eshtool.dep")
!INCLUDE "eshtool.dep"
!ELSE 
!MESSAGE Warning: cannot find "eshtool.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "eshtool - Win32 Debug" || "$(CFG)" == "eshtool - Win32 Release"
SOURCE=.\eshtdlg.cpp

"$(INTDIR)\eshtdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtool.pch"


SOURCE=.\eshtdoc.cpp

"$(INTDIR)\eshtdoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtool.pch"


SOURCE=.\eshtmfrm.cpp

"$(INTDIR)\eshtmfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtool.pch"


SOURCE=.\eshtool.cpp

"$(INTDIR)\eshtool.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtool.pch"


SOURCE=.\eshtool.rc

"$(INTDIR)\eshtool.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\eshttree.cpp

"$(INTDIR)\eshttree.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtool.pch"


SOURCE=.\eshtview.cpp

"$(INTDIR)\eshtview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtool.pch"


SOURCE=.\eshtvp.cpp

"$(INTDIR)\eshtvp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtool.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "eshtool - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\inc" /I "..\..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\eshtool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "eshtool - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /I "..\..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\eshtool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

