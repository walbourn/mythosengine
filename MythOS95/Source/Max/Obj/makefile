#ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
#                  ooo        ooooo                       
#                  `88.       .888'                       
#                   888b     d'888   .oooo.   oooo    ooo 
#                   8 Y88. .P  888  `P  )88b   `88b..8P'  
#                   8  `888'   888   .oP"888     Y888'    
#                   8    Y     888  d8(  888   .o8"'88b   
#                  o8o        o888o `Y888""8o o88'   888o 
#
#                          Across the event horizon...
#
#               Copyright (c) 1994 by Charybdis Enterprises, Inc.
#                            All Rights Reserved.
#
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#
#           *** Charybdis Enterprises, Inc. Company Confidential ***
#
#  This file and all associated files are the company proprietary property
#        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
#
# Charybdis Enterprises, Inc. makes no warranties, express or implied, as
# to the correctness of this code or any derivative works which incorporate
# it.  Charybdis Enterprises, Inc. provides the code on an "as-is" basis
# and explicitly disclaims any liability, including consequential and
# incidental damages for errors, omissions, and other problems in the code.
#
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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

!if "$(MYTH95ROOT)" == ""
MYTH95ROOT = \MythOS95
!endif

INCPATH = ;..\inc;$(MYTH95ROOT)\inc;

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# File specific variables                                                  ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

LIB = max
OBJS=\
maxevt.obj\
maxesrc.obj\
maxdevs.obj\
maxetsk.obj\
maxvmap.obj

LIBPATH = $(MYTH95ROOT)\lib;

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# First target                                                             ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

all: setstden $(LIB).lib

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
#                              Dependancies
#
#±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

maxevt.obj:  ..\maxevt.cpp  ..\inc\maxevt.hpp  ..\inc\maxdevs.hpp
maxesrc.obj: ..\maxesrc.cpp ..\inc\maxesrc.hpp ..\inc\maxevt.hpp ..\inc\maxdevs.hpp
maxdevs.obj: ..\maxdevs.cpp ..\inc\maxdevs.hpp
maxetsk.obj: ..\maxetsk.cpp ..\inc\maxesrc.hpp ..\inc\maxevt.hpp
maxvmap.obj: ..\maxvmap.cpp ..\inc\maxvmap.hpp

#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
# Library                                                                  ³
#ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

$(LIB).lib:   $(OBJS)
    -del $(LIB).lib
    $(LB) $(LBOPTS) /out:$(LIB).lib @<<
    $(OBJS: =
)
<<

release: all
    copy ..\inc\*.* $(MYTH95ROOT)\inc
    copy $(LIB).lib $(MYTH95ROOT)\lib

clean:
    del *.obj
    del *.res
    del *.err
    del *.lst
    del *.ilk
    del *.pdb

#°±² End of makefile ²±°
