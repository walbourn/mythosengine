#様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
#                              ** Tester **
#
# Created by Dan Higdon and Chuck Walbourn
#
# makefile
#
#様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#
#                               Variables
#
#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

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

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# File specific variables                                                  �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

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

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# First target                                                             �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

all: setstden $(EXE).exe

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# Standard make include                                                    �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

!include $(MYTH95ROOT)\inc\make.inc

#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#
#                                 Rules
#
#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#--- .c, .cpp, .asm setup in standard include ---

#臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
#
#                              Dependencies
#
#臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# Executable                                                               �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

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


#葦� End of makefile 憶�

