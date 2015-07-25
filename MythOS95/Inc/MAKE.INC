#ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
#
#                              Makefile Include
#
#                      Microsoft Windows 95/98/NT Version
#
#   Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
#
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#
# This file and all associated files are subject to the terms of the
# GNU Lesser General Public License version 2 as published by the
# Free Software Foundation (http://www.gnu.org).   They remain the
# property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
# See LICENSE.TXT in the distribution for a copy of this license.
#
# THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
# OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
# PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
# LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
# OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
#
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#
#                        http://www.mythos-engine.org/
#
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
#ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#
#                               Variables
#
#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

!message ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
!message ³                    M Y T H O S   9 5    -   make.inc                 ³
!message ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

!if "$(DEBUG)" == "ASSERT"
!message °°°°°°°°°°°°°°°°°°°°°°°±² Asserts only version ²±°°°°°°°°°°°°°°°°°°°°°°°
!else if "$(DEBUG)" != "NO"
!message °°°°°°°°°°°°°°°°°°°°°°°°±² Debugging version ²±°°°°°°°°°°°°°°°°°°°°°°°°°
!else
!message °°°°°°°°°°°°°°°°°°°°°°°°°±² Release version ²±°°°°°°°°°°°°°°°°°°°°°°°°°°
!endif

!if "$(THREAD)" == "DLL"
!message °°°°°°°°°°°°°°°°°°°±² Multi-Threaded DLL version ²±°°°°°°°°°°°°°°°°°°°°°
!else if "$(THREAD)" != "YES"
!message °°°°°°°°°°°°°°°°°°°°±² Non Multi-Threaded version ²±°°°°°°°°°°°°°°°°°°°°
!else
!message °°°°°°°°°°°°°°°°°°°°°°±² Multi-Threaded version ²±°°°°°°°°°°°°°°°°°°°°°°
!endif

#ÄÄÄ Microsoft Visual C/C++ v6.x
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

#ÄÄÄ Assembly
ASM = ml
!if "$(DEBUG)" == "NO"
ASMOPTS = /nologo /c /DNDEBUG /Zp1 /coff
!else if "$(DEBUG)" == "ASSERT"
ASMOPTS = /nologo /c /Zp1 /coff
!else
ASMOPTS = /nologo /c /DDEBUG /Zi /Zp1 /Fl /coff
!endif

#ÄÄÄ C/C++
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
CCOPTIONS = /c /G5 -Ze -Zp1 $(CCRTOPT) /nologo -W3 /Ox -DNDEBUG /DWIN32 /D_WINDOWS
!else if "$(DEBUG)" == "ASSERT"
CCOPTIONS = /c /G5 -Ze -Zp1 $(CCRTOPT) /nologo -W3 /Ox /DWIN32 /D_WINDOWS
!else
CCOPTIONS = /c /G5 -Ze -Zp1 $(CCRTOPT)d /nologo -W3 /Zi /Od -DDEBUG /DWIN32 /D_WINDOWS
!endif

#ÄÄÄ Librarian
LB = lib
LBOPTS = /nologo

#ÄÄÄ Link
LINK = link
!if ("$(DEBUG)" == "NO") || ("$(DEBUG)" == "ASSERT")
LINKOPTS = /nologo
!else
LINKOPTS = /DEBUG /nologo
!endif

!if "$(LINKMAP)" == "YES"
LINKOPTS = /MAP $(LINKOPTS)
!endif

#ÄÄÄ Resource
RC = rc
RCOPTS = /R

#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#
#                                 Rules
#
#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

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

#±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
#
#                              Dependancies
#
#±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# Environment variables                                                    ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

setstden :
        @set INCLUDE=;$(INCPATH);$(INCLUDE)
        @set LIB=$(LIB);$(LIBVARS);$(LIBPATH)

#°±² End of make.inc ²±°

