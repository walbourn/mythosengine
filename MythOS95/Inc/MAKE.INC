#様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
#
#                              Makefile Include
#
#                      Microsoft Windows 95/98/NT Version
#
#   Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
#
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#
# THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
# OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
# PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
# LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
# OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
#
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#
#                        http://www.mythos-engine.org/
#
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#
# make.inc
#
# This standard make include file is setup for compling with
# Microsoft Visual C/C++ v6.x and MASM 6.14.
#
# It assumes that INCPATH is setup to be a PATH-style variable of include
# paths, DEBUG is set to NO, ASSERT, or YES for debug compilation, and
# THREAD is set to NO, YES, or DLL for run-time library use.
#
# If LINKMAP is set to YES, then a linker map is generated
#
# Also, the first target should be defined BEFORE this include.
#
# The dependency 'setstden' sets the INCLUDE and LIB environment variables.
# To add more paths for the INCLUDE or LIB, set INCPATH and LIBPATH before
# this file.
#
#様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#
#                               Variables
#
#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

!message 敖陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
!message �                    M Y T H O S   9 5    -   make.inc                 �
!message 青陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰

!if "$(DEBUG)" == "ASSERT"
!message 旭旭旭旭旭旭旭旭旭旭旭葦� Asserts only version 憶旭旭旭旭旭旭旭旭旭旭旭�
!else if "$(DEBUG)" != "NO"
!message 旭旭旭旭旭旭旭旭旭旭旭旭渦 Debugging version 憶旭旭旭旭旭旭旭旭旭旭旭旭�
!else
!message 旭旭旭旭旭旭旭旭旭旭旭旭葦� Release version 憶旭旭旭旭旭旭旭旭旭旭旭旭旭
!endif

!if "$(THREAD)" == "DLL"
!message 旭旭旭旭旭旭旭旭旭葦� Multi-Threaded DLL version 憶旭旭旭旭旭旭旭旭旭旭�
!else if "$(THREAD)" != "YES"
!message 旭旭旭旭旭旭旭旭旭旭渦 Non Multi-Threaded version 憶旭旭旭旭旭旭旭旭旭旭
!else
!message 旭旭旭旭旭旭旭旭旭旭旭渦 Multi-Threaded version 憶旭旭旭旭旭旭旭旭旭旭旭
!endif

#陳� Microsoft Visual C/C++ v6.x
!if "$(INCLUDE)" == ""
!if "$(MSVC)" == ""
!error make.inc requires that the variable MSVC be set
!endif
INCLUDE = $(MSVC)\include;$(MSVC)\mfc\include
!endif

!if "$(LIB)" == ""
!if "$(MSVC)" == ""
!error make.inc requires that the variable MSVC be set
!endif
LIBVARS = $(MSVC)\lib;$(MSVC)\mfc\lib
!endif

#陳� Assembly
ASM = ml
!if "$(DEBUG)" == "NO"
ASMOPTS = /nologo /c /DNDEBUG /Zp1 /coff
!else if "$(DEBUG)" == "ASSERT"
ASMOPTS = /nologo /c /Zp1 /coff
!else
ASMOPTS = /nologo /c /DDEBUG /Zi /Zp1 /Fl /coff
!endif

#陳� C/C++
CPP = cl
CC = cl

!if "$(THREAD)" == "DLL"
CCRTOPT = /MD
!else if "$(THREAD)" != "YES"
CCRTOPT = /ML
!else
CCRTOPT = /MT
!endif

!if "$(DEBUG)" == "NO"
CCOPTIONS = /c -Zp1 $(CCRTOPT) /nologo -W3 /wd4530 /Ox -DNDEBUG /DWIN32 /D_WINDOWS /D_CRT_SECURE_NO_WARNINGS
!else if "$(DEBUG)" == "ASSERT"
CCOPTIONS = /c -Zp1 $(CCRTOPT) /nologo -W3 /wd4530 /Ox /DWIN32 /D_WINDOWS /D_CRT_SECURE_NO_WARNINGS
!else
CCOPTIONS = /c -Zp1 $(CCRTOPT)d /nologo -W3 /wd4530 /Zi /Od -DDEBUG /DWIN32 /D_WINDOWS /D_CRT_SECURE_NO_WARNINGS
!endif

#陳� Librarian
LB = lib
LBOPTS = /nologo

#陳� Link
LINK = link
!if ("$(DEBUG)" == "NO") || ("$(DEBUG)" == "ASSERT")
LINKOPTS = /nologo
!else
LINKOPTS = /DEBUG /nologo
!endif

!if "$(LINKMAP)" == "YES"
LINKOPTS = /MAP $(LINKOPTS)
!endif

#陳� Resource
RC = rc
RCOPTS = /R

#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#
#                                 Rules
#
#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

# define how we compile a .ASM file
{..\}.asm{}.obj:
   $(ASM) $(ASMOPTS) $<

# define how we compile a .C file
{..\}.c{}.obj:
        $(CC) $(CCOPTIONS) $<

# define how we compile a .CPP file
{..\}.cpp{}.obj:
        $(CPP) $(CCOPTIONS) $<

# define how we compile a .RC file
{..\}.rc{}.res:
   $(RC) $(RCOPTS) /fo $*.res $<

#臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
#
#                              Dependancies
#
#臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# Environment variables                                                    �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

setstden :
        @set INCLUDE=;$(INCPATH);$(INCLUDE)
        @set LIB=$(LIB);$(LIBVARS);$(LIBPATH)

#葦� End of make.inc 憶�

