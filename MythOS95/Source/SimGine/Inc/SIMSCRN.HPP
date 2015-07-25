//���������������������������������������������������������������������������
//
//                              S I M   G I N E
//
//             __               ___   ______,-------
//           __==__,------------/|\--|      | .-.-.|    ___________
//         (|     |--------------|---|------| '-`-`|  _/___________\_
//         (|_____|      _       _   |   _  | 6000 | |               |
//          |__\\_|`-._/___\___/___\_|_/___\|      | |               |
//         __/ |===|--|_____|_|_____|_|___  |\_____|=|_______________|
//      |=|[_]==[_]    \ _ /   \ _ /   \ _ /          [_]   [_]   [_]
//���������������������������������������������������������������������������
//
//                     A Simluator Framework for MythOS(tm)
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1997-1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//���������������������������������������������������������������������������
//
// simscrn.hpp
//
// SimScreen - basic video interface class
//
// SimScreenDD - DirectDraw-based video class
//
// SimScreenDIB - GDI DIB-based video class
//
// SimScreenD3D - Microsoft Direct3D video class

// SimScreenCL3D - Cirrus Clear3D video class
//
//���������������������������������������������������������������������������

#ifndef __SIMSCRN_HPP
#define __SIMSCRN_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimScreen - basic screen management class
//
// This class handles the video device, palettes, and cursors needed
// by the application.
//���������������������������������������������������������������������������
class SimScreen
{
public:
    //���������������������������������������������������������������������Ŀ
    // Equates                                                              �
    //�����������������������������������������������������������������������
    enum
    {
        FULLSCREEN          = 0x1,
        TRUEFLIP            = 0x2,
    };

    enum error_codes
    {
        ERROR_NONE          = 0,
        ERROR_NOMEMORY      = 1,
        ERROR_INVALIDPARMS  = 2,
        ERROR_SCNRMNGRINIT  = 3,
        ERROR_PALINIT       = 4,
        ERROR_MODEFAIL      = 5,
        ERROR_MODENOTSUPP   = 6,
        ERROR_VPORTINIT     = 7,
    };

    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    ushort              width;
    ushort              height;
    ushort              bit_depth;
    ushort              na;

    float               brightness;

    VngoVport           *gvport;
    VngoPal             *pal;
    VngoScreenManager   *vgs;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimScreen();
    virtual ~SimScreen();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual error_codes init (ushort w, ushort h,
                              ushort bd = 16, dword flags=FULLSCREEN);
    virtual void release();
    virtual VngoVport *create_subviewport(VngoRect &screen_rect, dword flags) = 0;
    virtual long lock ();
    virtual int  unlock ();

    void clear ();
    void reinit () { if (vgs) vgs->reinit(brightness); }
    void flip () { if (vgs) vgs->flip(); }

    BOOL load_palette (const char *fname, const char *name, BOOL freeold=TRUE);
    BOOL set_palette (VngoPal *p, BOOL clr=TRUE);

    void set_brightness(float b);
    float get_brightness() const { return brightness; }

    void invalidate (const VngoRect &rct)
    {
        if (vgs)
            vgs->invalidate(rct);
    }
    void invalidate ()
    {
        VngoRect rct;
        rct.x=rct.y=0;
        rct.dx=width;
        rct.dy=height;
        if (vgs)
            vgs->invalidate(rct);
    }

    BOOL capture();

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
    dword find(VngoColor24bit clr)
    {
        assertMyth("SimScreen::find_color needs palette", pal != 0);

        return pal->get_index(clr);
    }

    dword find(dword clr)
    {
        assertMyth("SimScreen::find_color needs palette", pal != 0);

        return pal->get_index(VngoColor24bit(clr));
    }
};


//���������������������������������������������������������������������������
// SimScreenDD - DirectDraw implementation of screen class
//���������������������������������������������������������������������������
class SimScreenDD : public SimScreen
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimScreenDD();
    virtual ~SimScreenDD();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual error_codes init (ushort w, ushort h, 
                              ushort bd = 16, dword flags=FULLSCREEN);
    virtual VngoVport *create_subviewport(VngoRect &srect, dword flags);
    virtual long lock ();
    virtual int  unlock ();
};


//���������������������������������������������������������������������������
// SimScreenDIB - GDI implementation of screen class
//���������������������������������������������������������������������������
class SimScreenDIB : public SimScreen
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimScreenDIB();
    virtual ~SimScreenDIB();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual error_codes init (ushort w, ushort h,
                              ushort bd = 16, dword flags=FULLSCREEN);
    virtual VngoVport *create_subviewport(VngoRect &srect, dword flags);
};


//���������������������������������������������������������������������������
// SimScreenD3D - Microsoft Direct3D implementation of screen class
//���������������������������������������������������������������������������
class SimScreenD3D : public SimScreen
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimScreenD3D();
    virtual ~SimScreenD3D();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual error_codes init (ushort w, ushort h, 
                              ushort bd = 16, dword flags=FULLSCREEN);
    virtual VngoVport *create_subviewport(VngoRect &srect, dword flags);
    virtual long lock ();
    virtual int  unlock ();
};


//���������������������������������������������������������������������������
// SimScreenCL3D - Cirrus Clear3D implementation of screen class
//���������������������������������������������������������������������������
#ifdef  _OEMS
#ifdef  _CLEAR_3D
class SimScreenCL3D : public SimScreen
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimScreenCL3D();
    virtual ~SimScreenCL3D();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual error_codes init (ushort w, ushort h, 
                              ushort bd = 16, dword flags=FULLSCREEN);
    virtual VngoVport *create_subviewport(VngoRect &srect, dword flags);
};
#endif // _CLEAR_3D
#endif // _OEMS

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern SimScreen        *Screen;            // Screen control instance

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - simscrn.hpp ���
