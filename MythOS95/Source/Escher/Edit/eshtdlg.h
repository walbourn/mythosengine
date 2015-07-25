//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùù°°°°°°°°°°ù°°°°°°°°ùùù°°°°°°°°ùù°°°ùùùù°°°ù°°°°°°°°°°ù°°°°°°°°°ùù
//ùùùùùùùùù°±°ùùùùùùù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùùùùùù°±°ùùùù°±°ùù
//ùùùùùùùù±°±ùùùùùùù±°±ùùùùùùùù±°±ùùùùùùùù±°±ùùùù±°±ù±°±ùùùùùùùù±°±ùùùù±°±ùùù
//ùùùùùùù±²±±°±±²ùù±²±±°±±²±±ù±²±ùùùùùùùù±²±±°±±²±±ù±²±±°±±²ùùù±²±±°±±²°ùùùùù
//ùùùùùù±²±ùùùùùùùùùùùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ùùùùù
//ùùùùù²±²ùùùùùùù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùùùùùù²±²ùùùù²±²ùùùùùù
//ùùùù²²²²²²²²²²ù²²²²²²²²ùùù²²²²²²²²ùù²²²ùùùù²²²ù²²²²²²²²²²ù²²²ùùùù²²²ùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùù Microsoft Windows 95/NT Version ùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùCopyrightù(c)ù1994-1998ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        *** Escher Terrain Editor ***
//
// Chuck Walbourn
//
// eshtdlg.h
//
// Terrain Editor Dialog Classes
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define EXPSTAT_HDR     0x1
#define EXPSTAT_HGTS    0x2
#define EXPSTAT_NRML    0x4
#define EXPSTAT_SURF    0x8
#define EXPSTAT_TXTS    0x10

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class TerrEditDoc;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°° Terrain Properies Dialog °°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropGenPage                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class TerrPropGenPage : public CPropertyPage
{
	DECLARE_DYNCREATE(TerrPropGenPage)

// Construction
public:
	TerrPropGenPage();   // standard constructor
    ~TerrPropGenPage();   // standard constructor

    int     m_edit;
    UINT    m_surfratio;

// Dialog Data
	//{{AFX_DATA(TerrPropGenPage)
	enum { IDD = IDD_TERRPROP_GEN };
	CButton	m_autoCenterCtl;
	CEdit	m_orgzCtl;
	CEdit	m_orgyCtl;
	CEdit	m_orgxCtl;
	CComboBox	m_surfratioCtl;
	CEdit	m_depthCtl;
	CEdit	m_widthCtl;
	UINT	m_width;
	UINT	m_depth;
	CString	m_name;
	UINT	m_scale;
	float	m_orgx;
	float	m_orgy;
	float	m_orgz;
	BOOL	m_autoCenterOrg;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrPropGenPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TerrPropGenPage)
	afx_msg void OnAutoCenter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropHColrPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class TerrPropHColrPage : public CPropertyPage
{
	DECLARE_DYNCREATE(TerrPropHColrPage)

// Construction
public:
	TerrPropHColrPage();
	~TerrPropHColrPage();

// Dialog Data
	//{{AFX_DATA(TerrPropHColrPage)
	enum { IDD = IDD_TERRPROP_HGTCLR };
	UINT	m_blue;
	UINT	m_brown;
	UINT	m_green;
	UINT	m_lblue;
	UINT	m_lbrown;
	UINT	m_lgreen;
	UINT	m_lorange;
	UINT	m_orange;
	UINT	m_red;
	UINT	m_white;
	UINT	m_yellow;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(TerrPropHColrPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(TerrPropHColrPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropHTablePage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class TerrPropHTablePage : public CPropertyPage
{
	DECLARE_DYNCREATE(TerrPropHTablePage)

// Construction
public:
	TerrPropHTablePage();
	~TerrPropHTablePage();

// Dialog Data
	//{{AFX_DATA(TerrPropHTablePage)
	enum { IDD = IDD_TERRPROP_HTBL };
	CListBox	m_list;
	//}}AFX_DATA

    float htable[256];

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(TerrPropHTablePage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(TerrPropHTablePage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropMiscPage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class TerrPropMiscPage : public CPropertyPage
{
	DECLARE_DYNCREATE(TerrPropMiscPage)

// Construction
public:
	TerrPropMiscPage();
	~TerrPropMiscPage();

// Dialog Data
	//{{AFX_DATA(TerrPropMiscPage)
	enum { IDD = IDD_TERRPROP_MISC };
	CString	m_copy;
	CString	m_auth;
	CString	m_desc;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(TerrPropMiscPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(TerrPropMiscPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Light Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LightPropGenPage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class LightPropGenPage : public CPropertyPage
{
	DECLARE_DYNCREATE(LightPropGenPage)

// Construction
public:
	LightPropGenPage();
	~LightPropGenPage();

    int     m_type;
    byte    m_intensity;

// Dialog Data
	//{{AFX_DATA(LightPropGenPage)
	enum { IDD = IDD_LGTPROP_GEN };
	CComboBox	m_typeList;
	CSliderCtrl	m_iSlider;
	BOOL	m_atten;
	float	m_xiValue;
	float	m_yjValue;
	float	m_zkValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(LightPropGenPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(LightPropGenPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LightPropExtraPage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class LightPropExtraPage : public CPropertyPage
{
	DECLARE_DYNCREATE(LightPropExtraPage)

// Construction
public:
	LightPropExtraPage();
	~LightPropExtraPage();

// Dialog Data
	//{{AFX_DATA(LightPropExtraPage)
	enum { IDD = IDD_LGTPROP_EXTRA };
	float	m_inner;
	float	m_outer;
	float	m_hotspot;
	float	m_diri;
	float	m_dirj;
	float	m_dirk;
	float	m_falloff;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(LightPropExtraPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(LightPropExtraPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Camera Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropGenPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class CameraPropGenPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CameraPropGenPage)

// Construction
public:
	CameraPropGenPage();
	~CameraPropGenPage();

// Dialog Data
	//{{AFX_DATA(CameraPropGenPage)
	enum { IDD = IDD_CAMPROP_GEN };
	float	m_fov;
	float	m_diri;
	float	m_topi;
	float	m_dirj;
	float	m_topj;
	float	m_dirk;
	float	m_topk;
	float	m_xpos;
	float	m_ypos;
	float	m_zpos;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CameraPropGenPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CameraPropGenPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropLODPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class CameraPropLODPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CameraPropLODPage)

// Construction
public:
	CameraPropLODPage();
	~CameraPropLODPage();

// Dialog Data
	//{{AFX_DATA(CameraPropLODPage)
	enum { IDD = IDD_CAMPROP_LOD };
	CEdit	m_medCtl;
	CEdit	m_lowCtl;
	float	m_low;
	float	m_med;
	BOOL	m_lod;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CameraPropLODPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CameraPropLODPage)
	afx_msg void OnLevelOfDetail();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropMiscPage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class CameraPropMiscPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CameraPropMiscPage)

// Construction
public:
	CameraPropMiscPage();
	~CameraPropMiscPage();

// Dialog Data
	//{{AFX_DATA(CameraPropMiscPage)
	enum { IDD = IDD_CAMPROP_MISC };
	float	m_hither;
	float	m_yon;
	float	m_scalef;
	float	m_hover;
	//}}AFX_DATA

    dword m_bcolor;

    void setup(TerrEditDoc *pd) { pDoc=pd; }

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CameraPropMiscPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    TerrEditDoc *pDoc;

	// Generated message map functions
	//{{AFX_MSG(CameraPropMiscPage)
	afx_msg void OnBackgroundColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropExPage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class CameraPropExPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CameraPropExPage)

// Construction
public:
	CameraPropExPage();
	~CameraPropExPage();

// Dialog Data
	//{{AFX_DATA(CameraPropExPage)
	enum { IDD = IDD_CAMPROP_EX };
	CButton	m_bg_activeCtl;
	CButton	m_haze_activeCtl;
	BOOL	m_bg_active;
	BOOL	m_haze_active;
	float	m_startz;
	float	m_midz;
	//}}AFX_DATA

    XFBitmap *bg_bm;
    dword    haze_color;
    BOOL     haze_change;
    void setup(TerrEditDoc *pd);

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CameraPropExPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    TerrEditDoc *pDoc;

	// Generated message map functions
	//{{AFX_MSG(CameraPropExPage)
	afx_msg void OnSelectBitmap();
	afx_msg void OnHazeColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Surface Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// SurfPropGenPage                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class SurfPropGenPage : public CPropertyPage
{
	DECLARE_DYNCREATE(SurfPropGenPage)

// Construction
public:
	SurfPropGenPage();
	~SurfPropGenPage();

// Dialog Data
	//{{AFX_DATA(SurfPropGenPage)
	enum { IDD = IDD_SURFPROP_GEN };
	CButton	m_notileCtl;
	CComboBox	m_tileCtl;
	CComboBox	m_txtList;
	CButton	m_colorbutton;
	CButton	m_flipvCtl;
	CButton	m_flipuCtl;
	BOOL	m_cbit4;
	UINT	m_dloc;
	UINT	m_xloc;
	BOOL	m_flipu;
	BOOL	m_flipv;
	BOOL	m_indistxt;
    int     m_tile;
	BOOL	m_cbit11;
	BOOL	m_cbit12;
	BOOL	m_hidden;
	BOOL	m_highonly;
	BOOL	m_notile;
	BOOL	m_app0;
	BOOL	m_app1;
	BOOL	m_app2;
	BOOL	m_app3;
	//}}AFX_DATA

    int   m_edit;
    dword m_color;
    int   m_txt;

	void setup(TerrEditDoc *pd) { pDoc=pd; }

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SurfPropGenPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    TerrEditDoc *pDoc;

	// Generated message map functions
	//{{AFX_MSG(SurfPropGenPage)
	afx_msg void OnColor();
	afx_msg void OnTextureSelectChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°° Color Properties Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ColorGenPropPage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class ColorGenPropPage : public CPropertyPage
{
	DECLARE_DYNCREATE(ColorGenPropPage)

// Construction
public:
	ColorGenPropPage();
	~ColorGenPropPage();
    void setup(TerrEditDoc *pd) { pDoc = pd;  ASSERT(pDoc); }

    int     colorIndx;

    int     m_isnew;

// Dialog Data
	//{{AFX_DATA(ColorGenPropPage)
	enum { IDD = IDD_CLRPROP_GEN };
	CButton	m_resetCtl;
	CString	m_name;
	BOOL	m_app0;
	BOOL	m_app1;
	BOOL	m_app2;
	BOOL	m_app3;
	BOOL	m_highonly;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(ColorGenPropPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    TerrEditDoc *pDoc;

	// Generated message map functions
	//{{AFX_MSG(ColorGenPropPage)
	afx_msg void OnResetUsage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Color Select Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ColorSelectPropPage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class ColorGenPropPage;
class ShadeReviewPropPage;

class ColorSelectPropPage : public CPropertyPage
{
	DECLARE_DYNCREATE(ColorSelectPropPage)

// Construction
public:
	ColorSelectPropPage();
	~ColorSelectPropPage();

    VngoPal8        *palette;
    dword           color;

    void setup(ColorGenPropPage *pg,
               ShadeReviewPropPage *ps) { pCGPage=pg; pSRPage=ps; }

// Dialog Data
	//{{AFX_DATA(ColorSelectPropPage)
	enum { IDD = IDD_COLORSELECT };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(ColorSelectPropPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    HPALETTE            hpal;
    BITMAPINFO          *bmi;
    BYTE                *gmap;
    VngoVportDB8        *gvport;
    int                 wid, hgt;
    int                 x_spacing;
    int                 y_spacing;
    VngoRect            sel_rect;
    ColorGenPropPage    *pCGPage;
    ShadeReviewPropPage *pSRPage;

    void setup_vport(int width, int height);
    void release_vport();

	// Generated message map functions
	//{{AFX_MSG(ColorSelectPropPage)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ShadeReviewPropPage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class ShadeReviewPropPage : public CPropertyPage
{
	DECLARE_DYNCREATE(ShadeReviewPropPage)

// Construction
public:
	ShadeReviewPropPage();
	~ShadeReviewPropPage();

    VngoPal8        *palette;
    dword           color;

// Dialog Data
	//{{AFX_DATA(ShadeReviewPropPage)
	enum { IDD = IDD_SHADEREVIEW };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(ShadeReviewPropPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    HPALETTE            hpal;
    BITMAPINFO          *bmi;
    BYTE                *gmap;
    VngoVportDB8        *gvport;
    int                 wid, hgt;
    int                 x_spacing;
    int                 y_spacing;

    void setup_vport(int width, int height);
    void release_vport();

	// Generated message map functions
	//{{AFX_MSG(ShadeReviewPropPage)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Progress Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ProgressDlg                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class ProgressDlg : public CDialog
{
// Construction
public:
	ProgressDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ProgressDlg)
	enum { IDD = IDD_PROGRESS };
	CProgressCtrl	m_pbar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ProgressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ProgressDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Status Dialogs °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrExpStatDlg                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class TerrExpStatDlg : public CDialog
{
// Construction
public:
	TerrExpStatDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TerrExpStatDlg)
	enum { IDD = IDD_EXPORTSTAT };
	CStatic	m_txts;
	CStatic	m_surf;
	CStatic	m_nrml;
	CStatic	m_hgts;
	CStatic	m_hdr;
	//}}AFX_DATA

    dword   sflags;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrExpStatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TerrExpStatDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Import Dialogs °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// DEMImportDlg                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class DEMImportDlg : public CDialog
{
// Construction
public:
	DEMImportDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DEMImportDlg)
	enum { IDD = IDD_DEMIMPORT };
	CEdit	m_lng_secondsCtl;
	CEdit	m_lng_minutesCtl;
	CEdit	m_lng_degreesCtl;
	CEdit	m_lat_secondsCtl;
	CEdit	m_lat_minutesCtl;
	CEdit	m_lat_degreesCtl;
    CButton m_stdCtl;
    CButton m_uniformCtl;
    CButton m_avgCtl;
	CEdit	m_avg_maxdCtl;
	float	m_avg_maxd;
	UINT	m_lat_degrees;
	UINT	m_lat_minutes;
	UINT	m_lat_seconds;
	UINT	m_lng_degrees;
	UINT	m_lng_minutes;
	UINT	m_lng_seconds;
    CButton m_lng_east;
    CButton m_lng_west;
    CButton m_lat_north;
    CButton m_lat_south;
	BOOL	m_normalize;
	//}}AFX_DATA

    enum
    {
        STANDARD=0,
        UNIFORM=1,
        AVERAGE=2
    };

    int option;
    BOOL isusgs;
    long longitude;
    long latitude;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DEMImportDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DEMImportDlg)
	afx_msg void OnDemAverage();
	afx_msg void OnDemStd();
	afx_msg void OnDemUniform();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// DEMProgressDlg                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class USGSFileParseDEM;

class DEMProgressDlg : public CDialog
{
// Construction
public:
	DEMProgressDlg(USGSFileParseDEM *d, CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(DEMProgressDlg)
	enum { IDD = IDD_DEMPROGRESS };
	CButton	m_ok;
	CProgressCtrl	m_pbar;
	CString	m_comments;
	CString	m_elv_units;
	CString	m_fname;
	CString	m_grnd_units;
	CString	m_name;
	UINT	m_profile_cols;
	UINT	m_profile_rows;
	UINT	m_quality;
	CString	m_status;
	float	m_axisx;
	float	m_axisy;
	float	m_axisz;
	//}}AFX_DATA

    BOOL    okon;
    long    longitude;
    long    latitude;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DEMProgressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    USGSFileParseDEM *dem;

	// Generated message map functions
	//{{AFX_MSG(DEMProgressDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Misc Dialogs °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LocateDlg                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class LocateDlg : public CDialog
{
// Construction
public:
	LocateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LocateDlg)
	enum { IDD = IDD_LOCATE };
	CString	m_fname;
	//}}AFX_DATA

    CString title;
    CString typestr;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LocateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LocateDlg)
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// SetBaseElvDlg                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class SetBaseElvDlg : public CDialog
{
// Construction
public:
	SetBaseElvDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SetBaseElvDlg)
	enum { IDD = IDD_SETBASEELV };
	float	m_setbase_elv;
	float	m_elvmin;
	float	m_elvmax;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SetBaseElvDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SetBaseElvDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//°±² eof - eshtdlg.h ²±°
