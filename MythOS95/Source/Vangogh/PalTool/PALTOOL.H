// PalTool.h : main header file for the PALTOOL application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPalToolApp:
// See PalTool.cpp for the implementation of this class
//

class CPalToolApp : public CWinApp
{
public:
	CPalToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPalToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPalToolApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


class CXFile: public XFileDOS
{

public:
		CXFile (CFile *cf)
		{
			fHandle = (void *)cf->m_hFile;
			sFlags = XF_OPEN_READ | XF_OPEN_WRITE | XF_STATUS_OPEN;
		}

		~CXFile ()
		{
			fHandle = INVALID_HANDLE_VALUE;
		}


		// DON'T CALL THESE!  They are here to prevent the unwary caller from
		// hosing the file handes (owned by MFC, in this case).
    	xf_error_codes close ()
		{
			return XF_ERR_NONE;
		}

		xf_error_codes open (const char *fname, int mode)
		{
			return XF_ERR_NONE;
		}
};


/////////////////////////////////////////////////////////////////////////////
