#ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
#
#                              Makefile Include
#
#             Copyright (c) 1994,1995 by Charybdis Enterprises, Inc.
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
#      This standard make include file is setup for compling with Watcom
#      version 10.0 and MASM 6.11.
#
#      It assumes that INCPATH is setup to be a PATH-style variable of
#      include paths, DEBUG is set to NO, ASSERT, or YES for debug
#      compilation, and CALLCONV is set to REGISTER if register calling
#      convention should be used instead of STACK.
#
#      Also, the first target should be defined BEFORE this include.
#
#      The dependancy 'setstden' sets up the PATH and INCLUDE environment
#      variables to include path to include the additional directories
#      in INCPATH, which is used by MASM and Watcom.
#
#ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#
#                               Variables
#                                
#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# Watcom C++ v 10.0                                                        ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

!message ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
!message ³                  Makefile - Charybdis Enterprises, Inc.              ³
!message ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

!if "$(DEBUG)" == "ASSERT"
!message °°°°°°°°°°°°°°°°°°°°°°°±² Asserts only version ²±°°°°°°°°°°°°°°°°°°°°°°°
!else if "$(DEBUG)" != "NO"
!message °°°°°°°°°°°°°°°°°°°°°°°°±² Debugging version ²±°°°°°°°°°°°°°°°°°°°°°°°°°
!endif

!if "$(CALLCONV)" == "REGISTER"
!message °°°°°°°°°°°°°°°°°°°±² Register Calling Convention ²±°°°°°°°°°°°°°°°°°°°°
!endif

WTCDIR = $(WATCOM)
INCLUDE = $(WATCOM)\h

!if "$(LIBPATH)" == ""
LIBPATH = ;
!endif

ASM = ml
!if "$(DEBUG)" == "NO"
ASMOPTS = /nologo /c /DNDEBUG /Zp1
!else if "$(DEBUG)" == "ASSERT"
ASMOPTS = /nologo /c /Zp1
!else
#ASMOPTS = /nologo /c /DDEBUG /Zi /Zp1
ASMOPTS = /nologo /c /DDEBUG /Zp1 /Fl
!endif

CPP = wpp386
CC = wcc386

!if "$(CALLCONV)" == "REGISTER"
CCOPTIONS = -5r
!else
CCOPTIONS = -5s
!endif

!if "$(DEBUG)" == "NO"
CCOPTIONS = $(CCOPTIONS) -ze -zp1 -zq -w3 -oatx -DNDEBUG  
!else if "$(DEBUG)" == "ASSERT"
CCOPTIONS = $(CCOPTIONS) -ze -zp1 -zq -w3 -oatx
!else
#CCOPTIONS = $(CCOPTIONS) -ze -zp1 -zq -wx -hc -d2 -oatx -DDEBUG 
CCOPTIONS = $(CCOPTIONS) -ze -zp1 -zq -wx -d2 -oatx -DDEBUG 
!endif

LB = wlib
LBOPTS = -q -b -c

LINK = wlink
!if ("$(DEBUG)" == "NO") || ("$(DEBUG)" == "ASSERT")
LINKOPTS = op q libp $(LIBPATH) 
!else
LINKOPTS = op q d all libp $(LIBPATH) 
!endif      

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

#±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
#
#                              Dependancies
#
#±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# Environment variables                                                    ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

setstden :
	@set INCLUDE=$(INCLUDE)$(INCPATH)

#°±² End of make.inc ²±°

