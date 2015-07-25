# Microsoft Developer Studio Generated NMAKE File, Based on eshtedit.dsp
!IF "$(CFG)" == ""
CFG=eshtedit - Win32 Debug
!MESSAGE No configuration specified. Defaulting to eshtedit - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "eshtedit - Win32 Debug" && "$(CFG)" != "eshtedit - Win32 Release"
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
OutDir=.\WinDebug
# End Custom Macros

ALL : "$(OUTDIR)\eshtedit.exe" "$(OUTDIR)\eshtedit.bsc"


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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\eshtedit.bsc"
	-@erase "$(OUTDIR)\eshtedit.exe"
	-@erase "$(OUTDIR)\eshtedit.ilk"
	-@erase "$(OUTDIR)\eshtedit.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G5 /MD /W3 /Gm /GX /ZI /Od /I "..\..\inc" /I "..\..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr"$(INTDIR)\\" /Fp"$(INTDIR)\eshtedit.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
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
LINK32_FLAGS=winmm.lib mythos.lib ivorymfc.lib bozo.lib xfile.lib chronos.lib escher.lib gutenbrg.lib felix.lib vangogh.lib /nologo /version:4 /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\eshtedit.pdb" /debug /machine:I386 /nodefaultlib:"LIBC" /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\eshtedit.exe" /libpath:"..\..\lib" /libpath:"..\..\..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\eshtdlg.obj" \
	"$(INTDIR)\eshtdlgt.obj" \
	"$(INTDIR)\eshtdlgx.obj" \
	"$(INTDIR)\eshtdoc.obj" \
	"$(INTDIR)\eshtdoci.obj" \
	"$(INTDIR)\eshtedit.obj" \
	"$(INTDIR)\Eshtgrid.obj" \
	"$(INTDIR)\Eshtlist.obj" \
	"$(INTDIR)\eshtmfrm.obj" \
	"$(INTDIR)\Eshtrend.obj" \
	"$(INTDIR)\Eshtusgs.obj" \
	"$(INTDIR)\eshtview.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\eshtedit.res"

"$(OUTDIR)\eshtedit.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\WinRel
# End Custom Macros

ALL : "$(OUTDIR)\eshtedit.exe"


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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\eshtedit.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G5 /MD /W3 /GX /O2 /I "..\..\inc" /I "..\..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtedit.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\eshtedit.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\eshtedit.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib mythos.lib ivorymfc.lib bozo.lib xfile.lib chronos.lib escher.lib gutenbrg.lib felix.lib vangogh.lib /nologo /version:4 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\eshtedit.pdb" /machine:I386 /nodefaultlib:"LIBC" /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\eshtedit.exe" /libpath:"..\..\lib" /libpath:"..\..\..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\eshtdlg.obj" \
	"$(INTDIR)\eshtdlgt.obj" \
	"$(INTDIR)\eshtdlgx.obj" \
	"$(INTDIR)\eshtdoc.obj" \
	"$(INTDIR)\eshtdoci.obj" \
	"$(INTDIR)\eshtedit.obj" \
	"$(INTDIR)\Eshtgrid.obj" \
	"$(INTDIR)\Eshtlist.obj" \
	"$(INTDIR)\eshtmfrm.obj" \
	"$(INTDIR)\Eshtrend.obj" \
	"$(INTDIR)\Eshtusgs.obj" \
	"$(INTDIR)\eshtview.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\eshtedit.res"

"$(OUTDIR)\eshtedit.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("eshtedit.dep")
!INCLUDE "eshtedit.dep"
!ELSE 
!MESSAGE Warning: cannot find "eshtedit.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "eshtedit - Win32 Debug" || "$(CFG)" == "eshtedit - Win32 Release"
SOURCE=.\eshtdlg.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdlg.obj"	"$(INTDIR)\eshtdlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtdlgt.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdlgt.obj"	"$(INTDIR)\eshtdlgt.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdlgt.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtdlgx.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdlgx.obj"	"$(INTDIR)\eshtdlgx.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdlgx.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtdoc.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdoc.obj"	"$(INTDIR)\eshtdoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtdoci.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtdoci.obj"	"$(INTDIR)\eshtdoci.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtdoci.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtedit.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtedit.obj"	"$(INTDIR)\eshtedit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtedit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtedit.rc

"$(INTDIR)\eshtedit.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Eshtgrid.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\Eshtgrid.obj"	"$(INTDIR)\Eshtgrid.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\Eshtgrid.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\Eshtlist.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\Eshtlist.obj"	"$(INTDIR)\Eshtlist.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\Eshtlist.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtmfrm.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtmfrm.obj"	"$(INTDIR)\eshtmfrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtmfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\Eshtrend.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\Eshtrend.obj"	"$(INTDIR)\Eshtrend.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\Eshtrend.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\Eshtusgs.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\Eshtusgs.obj"	"$(INTDIR)\Eshtusgs.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\Eshtusgs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\eshtview.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"


"$(INTDIR)\eshtview.obj"	"$(INTDIR)\eshtview.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"


"$(INTDIR)\eshtview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\eshtedit.pch"


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "eshtedit - Win32 Debug"

CPP_SWITCHES=/nologo /G5 /MD /W3 /Gm /GX /ZI /Od /I "..\..\inc" /I "..\..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr"$(INTDIR)\\" /Fp"$(INTDIR)\eshtedit.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\eshtedit.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "eshtedit - Win32 Release"

CPP_SWITCHES=/nologo /G5 /MD /W3 /GX /O2 /I "..\..\inc" /I "..\..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\eshtedit.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\eshtedit.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

