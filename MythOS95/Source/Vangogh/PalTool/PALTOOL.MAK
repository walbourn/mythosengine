# Microsoft Developer Studio Generated NMAKE File, Based on Paltool.dsp
!IF "$(CFG)" == ""
CFG=Paltool - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Paltool - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Paltool - Win32 Debug" && "$(CFG)" != "Paltool - Win32 Release"
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

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Paltool - Win32 Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\WinDebug
# End Custom Macros

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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Paltool.exe"
	-@erase "$(OUTDIR)\Paltool.ilk"
	-@erase "$(OUTDIR)\Paltool.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\inc" /I "..\..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Paltool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\paltool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Paltool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib mythos.lib ivorymfc.lib bozo.lib xfile.lib chronos.lib escher.lib gutenbrg.lib felix.lib vangogh.lib /nologo /version:4 /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Paltool.pdb" /debug /machine:I386 /nodefaultlib:"libc" /out:"$(OUTDIR)\Paltool.exe" /libpath:"..\..\lib" /libpath:"..\..\..\lib" /VERSION:4,0 
LINK32_OBJS= \
	"$(INTDIR)\bezier.obj" \
	"$(INTDIR)\dialog.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\paltodoc.obj" \
	"$(INTDIR)\paltool.obj" \
	"$(INTDIR)\paltovw.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\paltool.res"

"$(OUTDIR)\Paltool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Paltool - Win32 Release"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\WinRel
# End Custom Macros

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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Paltool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /I "..\..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Paltool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\paltool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Paltool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib mythos.lib ivorymfc.lib bozo.lib xfile.lib chronos.lib escher.lib gutenbrg.lib felix.lib vangogh.lib /nologo /version:4 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Paltool.pdb" /machine:I386 /nodefaultlib:"libc" /out:"$(OUTDIR)\Paltool.exe" /libpath:"..\..\lib" /libpath:"..\..\..\lib" /VERSION:4,0 
LINK32_OBJS= \
	"$(INTDIR)\bezier.obj" \
	"$(INTDIR)\dialog.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\paltodoc.obj" \
	"$(INTDIR)\paltool.obj" \
	"$(INTDIR)\paltovw.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\paltool.res"

"$(OUTDIR)\Paltool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Paltool.dep")
!INCLUDE "Paltool.dep"
!ELSE 
!MESSAGE Warning: cannot find "Paltool.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Paltool - Win32 Debug" || "$(CFG)" == "Paltool - Win32 Release"
SOURCE=.\bezier.cpp

"$(INTDIR)\bezier.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Paltool.pch"


SOURCE=.\dialog.cpp

"$(INTDIR)\dialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Paltool.pch"


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Paltool.pch"


SOURCE=.\paltodoc.cpp

"$(INTDIR)\paltodoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Paltool.pch"


SOURCE=.\paltool.cpp

"$(INTDIR)\paltool.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Paltool.pch"


SOURCE=.\paltool.rc

"$(INTDIR)\paltool.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\paltovw.cpp

"$(INTDIR)\paltovw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Paltool.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Paltool - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\inc" /I "..\..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Paltool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\Paltool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Paltool - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /I "..\..\inc" /I "..\..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Paltool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\Paltool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

