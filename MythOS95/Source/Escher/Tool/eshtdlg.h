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
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                             *** Escher Tool ***
//
// Chuck Walbourn
//
// eshtdlg.h
//
// Escher Tool dialog classes.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Scene Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ScenePropGeneralPage                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class ScenePropGeneralPage : public CPropertyPage
{
        DECLARE_DYNCREATE(ScenePropGeneralPage)

// Construction
public:
        ScenePropGeneralPage();
        ~ScenePropGeneralPage();

// Dialog Data
        //{{AFX_DATA(ScenePropGeneralPage)
        enum { IDD = IDD_SNPROP_GEN };
        CString m_name;
        UINT    m_ncameras;
        UINT    m_nmeshes;
        UINT    m_nplights;
        UINT    m_nvlights;
        UINT    m_nfplights;
        UINT    m_nalights;
        UINT    m_nslights;
        UINT    m_nfalights;
        UINT    m_nfslights;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(ScenePropGeneralPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(ScenePropGeneralPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ScenePropMiscPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class ScenePropMiscPage : public CPropertyPage
{
        DECLARE_DYNCREATE(ScenePropMiscPage)

// Construction
public:
        ScenePropMiscPage();
        ~ScenePropMiscPage();

// Dialog Data
        //{{AFX_DATA(ScenePropMiscPage)
        enum { IDD = IDD_SNPROP_MISC };
        CString m_auth;
        CString m_copy;
        CString m_desc;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(ScenePropMiscPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(ScenePropMiscPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° Camera Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropGeneralPage                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class CameraPropGeneralPage : public CPropertyPage
{
        DECLARE_DYNCREATE(CameraPropGeneralPage)

// Construction
public:
        CameraPropGeneralPage();
        ~CameraPropGeneralPage();

// Dialog Data
        //{{AFX_DATA(CameraPropGeneralPage)
        enum { IDD = IDD_CAMPROP_GEN };
        CString m_name;
        float   m_xpos;
        float   m_ypos;
        float   m_zpos;
        float   m_idir;
        float   m_jdir;
        float   m_kdir;
        float   m_itop;
        float   m_jtop;
        float   m_ktop;
        float   m_fov;
        float   m_height;
        float   m_width;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(CameraPropGeneralPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(CameraPropGeneralPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropAppFlagsPage                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class CameraPropAppFlagsPage : public CPropertyPage
{
        DECLARE_DYNCREATE(CameraPropAppFlagsPage)

// Construction
public:
        CameraPropAppFlagsPage();
        ~CameraPropAppFlagsPage();

// Dialog Data
        //{{AFX_DATA(CameraPropAppFlagsPage)
        enum { IDD = IDD_CAMPROP_APPFLAGS };
        BOOL    m_app1;
        BOOL    m_app2;
        BOOL    m_app3;
        BOOL    m_app4;
        BOOL    m_app5;
        BOOL    m_app6;
        BOOL    m_app7;
        BOOL    m_app0;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(CameraPropAppFlagsPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(CameraPropAppFlagsPage)
                // NOTE: the ClassWizard will add member functions here
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

    dword   m_bcolor;

// Dialog Data
        //{{AFX_DATA(CameraPropMiscPage)
        enum { IDD = IDD_CAMPROP_MISC };
        float   m_hither;
        float   m_yon;
        float   m_scalef;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(CameraPropMiscPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
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
        CButton m_bg_activeCtl;
        CButton m_haze_activeCtl;
        BOOL    m_bg_active;
        BOOL    m_haze_active;
        float   m_startz;
        float   m_midz;
        //}}AFX_DATA

    XFBitmap *bg_bm;
    dword    haze_color;
    BOOL     haze_change;

// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(CameraPropExPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(CameraPropExPage)
        afx_msg void OnSelectBitmap();
        afx_msg void OnHazeColor();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Light Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LightPropGeneralPage                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class LightPropGeneralPage : public CPropertyPage
{
        DECLARE_DYNCREATE(LightPropGeneralPage)

// Construction
public:
        LightPropGeneralPage();
        ~LightPropGeneralPage();

    int     m_edit;
    int     m_type;
    byte    m_intensity;

// Dialog Data
        //{{AFX_DATA(LightPropGeneralPage)
        enum { IDD = IDD_LGTPROP_GEN };
        CSliderCtrl     m_iSlider;
        CEdit   m_zkCtrl;
        CEdit   m_yjCtrl;
        CEdit   m_xiCtrl;
        CComboBox       m_typeList;
        CString m_name;
        BOOL    m_active;
        float   m_xiValue;
        float   m_yjValue;
        float   m_zkValue;
        BOOL    m_atten;
        BOOL    m_dark;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(LightPropGeneralPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(LightPropGeneralPage)
        afx_msg void OnTypeSelectChange();
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
        float   m_inner;
        float   m_outer;
        float   m_falloff;
        float   m_hotspot;
        float   m_diri;
        float   m_dirj;
        float   m_dirk;
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LightPropAppFlagsPage                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class LightPropAppFlagsPage : public CPropertyPage
{
        DECLARE_DYNCREATE(LightPropAppFlagsPage)

// Construction
public:
        LightPropAppFlagsPage();
        ~LightPropAppFlagsPage();

// Dialog Data
        //{{AFX_DATA(LightPropAppFlagsPage)
        enum { IDD = IDD_LGTPROP_APPFLAGS };
        BOOL    m_app1;
        BOOL    m_app2;
        BOOL    m_app3;
        BOOL    m_app4;
        BOOL    m_app5;
        BOOL    m_app6;
        BOOL    m_app7;
        BOOL    m_app0;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(LightPropAppFlagsPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(LightPropAppFlagsPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Face Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FacePropGeneralPage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class FacePropGeneralPage : public CPropertyPage
{
        DECLARE_DYNCREATE(FacePropGeneralPage)

// Construction
public:
        FacePropGeneralPage();
        ~FacePropGeneralPage();

// Dialog Data
        //{{AFX_DATA(FacePropGeneralPage)
        enum { IDD = IDD_FPROP_GEN };
        CEdit   m_v2Ctl;
        CEdit   m_v1Ctl;
        CEdit   m_v0Ctl;
        CEdit   m_u2Ctl;
        CEdit   m_u1Ctl;
        CEdit   m_u0Ctl;
        CComboBox       m_txtList;
        UINT    m_a;
        UINT    m_b;
        UINT    m_c;
        float   m_i;
        float   m_k;
        float   m_j;
        float   m_u0;
        float   m_u1;
        float   m_u2;
        float   m_v0;
        float   m_v1;
        float   m_v2;
        //}}AFX_DATA

    int tind;
    ulong tmax;
    EschTexture **txt;

// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(FacePropGeneralPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(FacePropGeneralPage)
        afx_msg void OnTextureChange();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FacePropFlagsPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class FacePropFlagsPage : public CPropertyPage
{
        DECLARE_DYNCREATE(FacePropFlagsPage)

// Construction
public:
        FacePropFlagsPage();
        ~FacePropFlagsPage();

// Dialog Data
        //{{AFX_DATA(FacePropFlagsPage)
        enum { IDD = IDD_FPROP_FLAGS };
        BOOL    m_1sided;
        BOOL    m_abline;
        BOOL    m_allow_persp;
        BOOL    m_bcline;
        BOOL    m_caline;
        BOOL    m_flat;
        BOOL    m_smooth;
        BOOL    m_solid;
        BOOL    m_specular;
        BOOL    m_wire;
        BOOL    m_alpha;
        UINT    m_alpha_a;
        UINT    m_alpha_b;
        UINT    m_alpha_c;
        UINT    m_selfillum;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(FacePropFlagsPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(FacePropFlagsPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FacePropAppFlagsPage                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class FacePropAppFlagsPage : public CPropertyPage
{
        DECLARE_DYNCREATE(FacePropAppFlagsPage)

// Construction
public:
        FacePropAppFlagsPage();
        ~FacePropAppFlagsPage();

// Dialog Data
        //{{AFX_DATA(FacePropAppFlagsPage)
        enum { IDD = IDD_FPROP_APPFLAGS };
        BOOL    m_app0;
        BOOL    m_app1;
        BOOL    m_app2;
        BOOL    m_app3;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(FacePropAppFlagsPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(FacePropAppFlagsPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Texture Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TexturePropGenPage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class TexturePropGenPage : public CPropertyPage
{
        DECLARE_DYNCREATE(TexturePropGenPage)

// Construction
public:
        TexturePropGenPage();
        ~TexturePropGenPage();

// Dialog Data
        //{{AFX_DATA(TexturePropGenPage)
        enum { IDD = IDD_TXTPROP_GEN };
        BOOL    m_animate;
        UINT    m_height;
        CString m_name;
        UINT    m_nframes;
        int             m_type;
        UINT    m_width;
        //}}AFX_DATA

// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(TexturePropGenPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(TexturePropGenPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TexturePropAppFlagsPage                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class TexturePropAppFlagsPage : public CPropertyPage
{
        DECLARE_DYNCREATE(TexturePropAppFlagsPage)

// Construction
public:
        TexturePropAppFlagsPage();
        ~TexturePropAppFlagsPage();

// Dialog Data
        //{{AFX_DATA(TexturePropAppFlagsPage)
        enum { IDD = IDD_TXTPROP_APPFLAGS };
        BOOL    m_app0;
        BOOL    m_app1;
        BOOL    m_app2;
        BOOL    m_app3;
        BOOL    m_app4;
        BOOL    m_app5;
        BOOL    m_app6;
        BOOL    m_app7;
        //}}AFX_DATA

// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(TexturePropAppFlagsPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(TexturePropAppFlagsPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Mesh Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropGeneralPage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class MeshPropGeneralPage : public CPropertyPage
{
        DECLARE_DYNCREATE(MeshPropGeneralPage)

// Construction
public:
        MeshPropGeneralPage();
        ~MeshPropGeneralPage();

// Dialog Data
        //{{AFX_DATA(MeshPropGeneralPage)
        enum { IDD = IDD_MSHPROP_GEN };
        CString m_name;
        CString m_parent;
        CString m_child;
        float   m_xpos;
        float   m_ypos;
        float   m_zpos;
        BOOL    m_visible;
        BOOL    m_chkext;
        UINT    m_nfaces;
        UINT    m_nverts;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(MeshPropGeneralPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(MeshPropGeneralPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropOrientPage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class MeshPropOrientPage : public CPropertyPage
{
        DECLARE_DYNCREATE(MeshPropOrientPage)

// Construction
public:
        MeshPropOrientPage();
        ~MeshPropOrientPage();

// Dialog Data
        //{{AFX_DATA(MeshPropOrientPage)
        enum { IDD = IDD_MSHPROP_ORIENT };
        float   m_mtxa;
        float   m_mtxb;
        float   m_mtxc;
        float   m_mtxd;
        float   m_mtxe;
        float   m_mtxf;
        float   m_mtxg;
        float   m_mtxh;
        float   m_mtxi;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(MeshPropOrientPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(MeshPropOrientPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropExtPage                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class MeshPropExtPage : public CPropertyPage
{
        DECLARE_DYNCREATE(MeshPropExtPage)

// Construction
public:
        MeshPropExtPage();
        ~MeshPropExtPage();

// Dialog Data
        //{{AFX_DATA(MeshPropExtPage)
        enum { IDD = IDD_MSHPROP_EXT };
        float   m_xcen;
        float   m_ycen;
        float   m_zcen;
        float   m_xmin;
        float   m_ymin;
        float   m_zmin;
        float   m_xmax;
        float   m_ymax;
        float   m_zmax;
        float   m_radius;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(MeshPropExtPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(MeshPropExtPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropVertsPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class MeshPropVertsPage : public CPropertyPage
{
        DECLARE_DYNCREATE(MeshPropVertsPage)

// Construction
public:
        MeshPropVertsPage();
        ~MeshPropVertsPage();

// Dialog Data
        //{{AFX_DATA(MeshPropVertsPage)
        enum { IDD = IDD_MSHPROP_VERTS };
        CListBox        m_vList;
        //}}AFX_DATA

    ulong nverts;
    IvoryHandle v;

// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(MeshPropVertsPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(MeshPropVertsPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropFacePage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class MeshPropFacePage : public CPropertyPage
{
        DECLARE_DYNCREATE(MeshPropFacePage)

// Construction
public:
        MeshPropFacePage();
        ~MeshPropFacePage();

// Dialog Data
        //{{AFX_DATA(MeshPropFacePage)
        enum { IDD = IDD_MSHPROP_FACE };
        CButton m_fProp;
        CListBox        m_fList;
        //}}AFX_DATA

    ulong nfaces;
    IvoryHandle f;

    ulong nverts;
    ulong tmax;
    EschTexture **txt;

    void setup(ToolDoc *p) { pDoc=p; }

// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(MeshPropFacePage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
    void ui_face_properties();

        // Generated message map functions
        //{{AFX_MSG(MeshPropFacePage)
        afx_msg void OnProperties();
        afx_msg void OnDblClick();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

    int cursel;
    ToolDoc *pDoc;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropTexturePage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class ToolDoc;

class MeshPropTexturePage : public CPropertyPage
{
        DECLARE_DYNCREATE(MeshPropTexturePage)

// Construction
public:
        MeshPropTexturePage();
        ~MeshPropTexturePage();

// Dialog Data
        //{{AFX_DATA(MeshPropTexturePage)
        enum { IDD = IDD_MSHPROP_TXTS };
        CButton m_txtProp;
        CListBox        m_txtList;
        //}}AFX_DATA

    ulong       tmax;
    EschTexture **txt;

    void setup(ToolDoc *p) { pDoc=p; }

// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(MeshPropTexturePage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
    void ui_texture_properties();

        // Generated message map functions
        //{{AFX_MSG(MeshPropTexturePage)
        afx_msg void OnProperties();
        afx_msg void OnDblClick();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

    int cursel;
    ToolDoc *pDoc;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropAppFlagsPage                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class MeshPropAppFlagsPage : public CPropertyPage
{
        DECLARE_DYNCREATE(MeshPropAppFlagsPage)

// Construction
public:
        MeshPropAppFlagsPage();
        ~MeshPropAppFlagsPage();

// Dialog Data
        //{{AFX_DATA(MeshPropAppFlagsPage)
        enum { IDD = IDD_MSHPROP_APPFLAGS };
        BOOL    m_app0;
        BOOL    m_app1;
        BOOL    m_app2;
        BOOL    m_app3;
        BOOL    m_app4;
        BOOL    m_app5;
        BOOL    m_app6;
        BOOL    m_app7;
        BOOL    m_app8;
        BOOL    m_app9;
        BOOL    m_appa;
        BOOL    m_appb;
        BOOL    m_appc;
        BOOL    m_appd;
        BOOL    m_appe;
        BOOL    m_appf;
        //}}AFX_DATA


// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(MeshPropAppFlagsPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        // Generated message map functions
        //{{AFX_MSG(MeshPropAppFlagsPage)
                // NOTE: the ClassWizard will add member functions here
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};

//°±² eof - eshtdlg.h ²±°
