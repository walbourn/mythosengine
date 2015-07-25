#ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
#
#                              Makefile Include
#
#                         Microsoft Windows '95 Version
#
#            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
#                            All Rights Reserved.
#
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#
#           *** Charybdis Enterprises, Inc. Company Confidential ***
#
#  This file and all associated files are the company proprietary property
#        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
#
# CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
# TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
# IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
# AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
# INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
#
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#
# make.inc
#
#
#      This standard make include file is setup for compling with 
#      Microsoft Visual C/C++ v5.x and MASM 6.11.
#
#      It assumes that INCPATH is setup to be a PATH-style variable of
#      include paths, DEBUG is set to NO, ASSERT, or YES for debug
#      compilation, and THREAD is set to NO or YES for multi-threaded
#      vs. non multi-threaded run-time library use.
#
#      Also, the first target should be defined BEFORE this include.
#
#      The dependency 'setstden' sets the INCLUDE and LIB environment
#      variables.  To add more paths for the INCLUDE or LIB, set
#      INCPATH and LIBPATH before this file.
#
#ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#
#                               Variables
#                                
#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# Microsoft Visual C/C++ v5.x                                              ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

!message ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
!message ³         Windows '95 Makefile - Charybdis Enterprises, Inc.           ³
!message ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

!if "$(DEBUG)" == "ASSERT"
!message °°°°°°°°°°°°°°°°°°°°°°°±² Asserts only version ²±°°°°°°°°°°°°°°°°°°°°°°°
!else if "$(DEBUG)" != "NO"
!message °°°°°°°°°°°°°°°°°°°°°°°°±² Debugging version ²±°°°°°°°°°°°°°°°°°°°°°°°°°
!endif

!if "$(THREAD)" != "YES"
!message °°°°°°°°°°°°°°°°°°°°±² Non Multi-Threaded version ²±°°°°°°°°°°°°°°°°°°°°
!else
!message °°°°°°°°°°°°°°°°°°°°°°±² Multi-Threaded version ²±°°°°°°°°°°°°°°°°°°°°°°
!endif

MSVCDIR = $(MSVC)
!if "$(INCLUDE)" == ""
INCLUDE = $(MSVC)\include;$(MSVC)\mfc\include
!endif

!if "$(LIB)" == ""
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

!if ("$(DEBUG)" == "NO") && ("$(THREAD)" == "YES")
CCOPTIONS = /c /G5 -Ze -Zp1 /MT /nologo -W3 /Ox -DNDEBUG /DWIN32 /D_WINDOWS
!else if "$(DEBUG)" == "NO"
CCOPTIONS = /c /G5 -Ze -Zp1 /nologo -W3 /Ox -DNDEBUG /DWIN32 /D_WINDOWS
!else if ("$(DEBUG)" == "ASSERT") && ("$(THREAD)" == "YES")
CCOPTIONS = /c /G5 -Ze -Zp1 /MT /nologo -W3 /Ox /DWIN32 /D_WINDOWS
!else if "$(DEBUG)" == "ASSERT"
CCOPTIONS = /c /G5 -Ze -Zp1 /nologo -W3 /Ox /DWIN32 /D_WINDOWS
!else if "$(THREAD)" == "YES"
CCOPTIONS = /c /G5 -Ze -Zp1 /MTd /nologo -W3 /Zi /Od -DDEBUG /DWIN32 /D_WINDOWS
!else
CCOPTIONS = /c /G5 -Ze -Zp1 /nologo -W3 /Zi /Od -DDEBUG /DWIN32 /D_WINDOWS
!endif

#ÄÄÄ Librarian
LB = lib
LBOPTS = /nologo

#ÄÄÄ Link
LINK = link
!if ("$(DEBUG)" == "NO") || ("$(DEBUG)" == "ASSERT")
LINKOPTS = /NOLOGO
!else
LINKOPTS = /DEBUG /NOLOGO
!endif

#ÄÄÄ Resource
RC = rc
RCOPTS = /r

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

