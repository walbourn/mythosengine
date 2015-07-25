; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPalToolDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PalTool.h"
LastPage=0

ClassCount=6
Class1=CPalToolApp
Class2=CPalToolDoc
Class3=CPalToolView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDR_PTOOLTYPE
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX
Resource4=IDD_PROGRESS
Class6=CProgressDlg

[CLS:CPalToolApp]
Type=0
HeaderFile=PalTool.h
ImplementationFile=PalTool.cpp
Filter=N

[CLS:CPalToolDoc]
Type=0
HeaderFile=PalTodoc.h
ImplementationFile=PalTodoc.cpp
Filter=N
VirtualFilter=DC
LastObject=IDM_FILE_EXPORT

[CLS:CPalToolView]
Type=0
HeaderFile=PalTovw.h
ImplementationFile=PalTovw.cpp
Filter=C
LastObject=IDM_OPTIONS_QUADRATIC
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp
Filter=T



[CLS:CAboutDlg]
Type=0
HeaderFile=PalTool.cpp
ImplementationFile=PalTool.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_MRU_FILE1
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_APP_ABOUT
CommandCount=7

[MNU:IDR_PTOOLTYPE]
Type=1
Class=CPalToolView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=IDM_FILE_IMPORT
Command4=ID_FILE_CLOSE
Command5=ID_FILE_SAVE
Command6=ID_FILE_SAVE_AS
Command7=ID_FILE_SEND_MAIL
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_WINDOW_NEW
Command17=ID_WINDOW_CASCADE
Command18=ID_WINDOW_TILE_HORZ
Command19=ID_WINDOW_ARRANGE
Command20=IDM_OPTIONS_LINEAR
Command21=IDM_OPTIONS_BEZIER
Command22=IDM_OPTIONS_QUADRATIC
Command23=ID_APP_ABOUT
CommandCount=23

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=IDM_FILE_EXPORT
Command3=IDM_FILE_IMPORT
Command4=ID_FILE_NEW
Command5=ID_FILE_OPEN
Command6=ID_FILE_SAVE
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

[DLG:IDD_PROGRESS]
Type=1
Class=CProgressDlg
ControlCount=1
Control1=IDC_PROGRESSBAR,msctls_progress32,1350565888

[CLS:CProgressDlg]
Type=0
HeaderFile=dialog.h
ImplementationFile=dialog.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_PROGRESSBAR

