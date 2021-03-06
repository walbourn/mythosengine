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
#様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#
#                               Variables
#
#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# Watcom C++ v 10.0                                                        �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

!message 敖陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
!message �                  Makefile - Charybdis Enterprises, Inc.              �
!message 青陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰

!if "$(DEBUG)" == "ASSERT"
!message 旭旭旭旭旭旭旭旭旭旭旭葦� Asserts only version 憶旭旭旭旭旭旭旭旭旭旭旭�
!else if "$(DEBUG)" != "NO"
!message 旭旭旭旭旭旭旭旭旭旭旭旭渦 Debugging version 憶旭旭旭旭旭旭旭旭旭旭旭旭�
!endif

!if "$(CALLCONV)" == "REGISTER"
!message 旭旭旭旭旭旭旭旭旭葦� Register Calling Convention 憶旭旭旭旭旭旭旭旭旭旭
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

#臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
#
#                              Dependancies
#
#臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# Environment variables                                                    �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

setstden :
        @set INCLUDE=$(INCLUDE)$(INCPATH)

#葦� End of make.inc 憶�

