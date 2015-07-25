//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
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
// Created by Dan Higdon & Chuck Walbourn
//
// paltodoc.h
//
// PalTool document class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class CPalToolDoc : public CDocument
{
protected: // create from serialization only
        CPalToolDoc();
        DECLARE_DYNCREATE(CPalToolDoc)

// Attributes
public:
    char        name[16];
        VngoPal         *base_pal;

    char        desc[256];
    char        auth[256];
    char        copy[256];

        enum
    {
        LINEAR,
        BEZIER,
        QUADRATIC
    } curve_mode;

        long &shade_env_break() const { return base_pal->shd_pal->mid_point; }

// Operations
public:
    enum genpal_type
    {
        PAL_ORIGGEN =0,
        PAL_GEN     =1,
        PAL_GREY    =2,
        PAL_332     =3,
        PAL_RGBG    =4,
        PAL_SPC1    =100,
        PAL_EMPTY,
    };

    void Generate (genpal_type typ);
    void CalcConvert ();
        void CalcShades ();

        int  ImportWindowsPalette (LPCSTR);
        int  ImportVGPalette (LPCSTR);

    void UIPalette(CWnd *parent, UINT ind=0);
    void UIProperties(CWnd *parent, UINT ipage=0);

// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CPalToolDoc)
        public:
        virtual BOOL OnNewDocument();
        virtual void DeleteContents();
        //}}AFX_VIRTUAL

// Implementation
public:
        virtual ~CPalToolDoc();
        virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    void gen_rampHLS(VngoColor24bit base, VngoColor24bit *colors, int steps);
    void gen_rampRGB(VngoColor24bit base, VngoColor24bit *colors, int steps);

        void use_colors8  (VngoColor24bit *colors, int steps, int color_index);
        void use_colors15 (VngoColor24bit *colors, int steps, int color_index);
        void use_colors16 (VngoColor24bit *colors, int steps, int color_index);
        void use_colors24 (VngoColor24bit *colors, int steps, int color_index);

        void calc_linear_colors (VngoColor24bit *colors, int steps,
                                                         VngoColor24bit color, int break_point);
        void calc_bez_colors (VngoColor24bit *colors, int steps,
                                                 VngoColor24bit color, int break_point);
        void calc_quad_colors (VngoColor24bit *colors, int steps,
                                                 VngoColor24bit color, int break_point);

// Generated message map functions
protected:
        //{{AFX_MSG(CPalToolDoc)
        afx_msg void OnFileImport();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

//°±² eof - paltodoc.h ²±°
