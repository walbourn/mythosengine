#ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
#                               Jb
#                               $$$c
#             $$$$$$$$$$$$$$$$$$$$$$b       d$$$$$$$$$$$$$$$$$$$$$P
#            .$$$$$$$$$$$$$$$$$$$$$$$$.     $$$$$$$$$$$$$$$$$$$$$$
#            ^""""""$$$$$P""""3$$$$$$$$c   d$$$$$""""$$$$$$"""""""
#                  4$$$$$"    $$$$$$$$$$b  $$$$$F   .$$$$$F
#                  $$$$$P    4$$$$$$$$$$$$$$$$$$    d$$$$$
#                 4$$$$$"    $$$$$$$$$$$$$$$$$$P    $$$$$F
#                 $$$$$$    4$$$$$""$$$$$$$$$$$    d$$$$$
#                4$$$$$"    $$$$$$  ^$$$$$$$$$P    $$$$$F
#                $$$$$$    4$$$$$%    *$$$$$$$"   J$$$$$
#               4$$$$$%    $$$$$$      ^$$$$$P    $$$$$F
#               """"""     """"""        *$$$"    """"""
#                                         "$$
#                                          ^%
#
#                         Turner - Networking Library
#
#                    Microsoft Windows 95/98/NT Version
#
#  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
#                              ** Tester **
#
# Created by Dan Higdon and Chuck Walbourn
#
# makefile
#
#ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#
#                               Variables
#
#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

!if "$(DEBUG)" == ""
DEBUG = NO
!endif

!if "$(THREAD)" == ""
THREAD=YES
!endif

!if "$(MYTH95ROOT)" == ""
MYTH95ROOT = \MythOS95
!endif

INCPATH = ;..\..\inc;$(MYTH95ROOT)\inc;

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# File specific variables                                                  ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

EXE = test

OBJS = \
turntest.obj\
resource.res

LIBS=\
ivorymfc.lib\
turner.lib\
dplay.lib\
dplayx.lib\
dxguid.lib\
user32.lib\
ole32.lib\
gdi32.lib\
version.lib\
advapi32.lib\
winmm.lib

LIBPATH = $(MYTH95ROOT)\lib;

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# First target                                                             ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

all: setstden $(EXE).exe

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# Standard make include                                                    ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

!include $(MYTH95ROOT)\inc\make.inc

#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#
#                                 Rules
#
#°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#--- .c, .cpp, .asm setup in standard include ---

#±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
#
#                              Dependencies
#
#±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# Executable                                                               ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

$(EXE).exe:   $(OBJS)
   $(LINK) $(LINKOPTS) /OUT:$*.exe /subsystem:windows,4 @<<
   $(OBJS) $(LIBS)
<<

clean:
   del *.obj
   del *.res
   del *.err
   del *.lst
   del *.ilk
   del *.pdb
   del *.vcp


#°±² End of makefile ²±°

