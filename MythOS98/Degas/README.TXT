                                          . .
                                        , h $ F
                                        ?,$,$,F
                                        `$$$$$P  ,
                                         ?$$$$L,c'
                                          $$$$$"'
                                         c$$P"                              
 ;;,                                  .z$$$F                                
 !'',ccc                            ,c$$$P"                                 
  ,$$$$$".                        zJ$$$$"                        .z..       
 > $".,,c,.                     c$$$$$P'                        ,$$$$$c,.   
  z$$,.,$$$F                   $$$$$$P                          J$$$$PP$$$hc
 z$$$$$$$$$=                  "??$$$"                           <$$$$$ $$P".
 $$$$$$$$$,ccc             zJ$$$$$P'                            `?$$$$c " ??
 $$$$$$$$$$??"         .zJ$$$$$P"                        .,;;;!!; <$$$$.  =$
 `$$$$$$$P"     ,ccd$$$$$$$$$"'                         <!!!!!'!! `"?$$h <c$
  $$$$$$$F  .zc???$??""'..`"         zcccc,,,.,..,..   `!!!!'  ' ;!; "$$.`$$
 J$$$$$$$L $P" ,;;,;;!!!''          <$$$$$$$$$$$$P",;,-``!(.-' .<!!!! `$L  "
 $$$$$$$$$ ? ;!!!!!!'``,;;;;;;,      $$$$$"""???" <!'  ' !' ;!!!!!!!!> $$h. 
 $$$$$$$$'  <!!!'  ,;<!!!!!!!!!!>    ?$$$$$c     `!! ,;;!!;<`<!!!!!'`. $$$$.
 $$$$$$$$ ;!!!!'!!!!!!!!!!!!!!!       $$$$$$c     !! !!!!!' ;'`!'' ,$F."???$
 $$$$$$$' `(!!> !!!!!! ..`!!!' ,$     ?$$$$$$.      ;!!!' ;! ., z$$F zJh=y,?
 $$$$$P  ;!!!!> !!!!' <F" `' ,J$$      $$$$$$h     c, `..<'' `,J$$P  " $r`F`
 $$$P" <; ``!!! !!!' .`?chcc$$$L       `$$$$$$c    $$$c,.,ccc$$$$F cc  ".,c$
 .",;<!!!!>; ;! `' z$$L ",$$$$$$c       $$$$$$$c, J$$$$$$??????" z$$$$ ! ?$$
 !!!!!!!!!!! `' c$$$$$$cd$$$$$$$""      $$$$$$$$h $$$$$$$c,.,,zc$$$$$$.`! $$
 !!!!!!!!!!!!!`<$$$$$$$$$$$$$$??        ?$$$$$$$',$$$$$$$$$$$$$$$$$$$$F !><$
 !!!!!!!!!!!!! J$$$$$$$"$$$$$$F         `??$???',$$$$$$$$$$$$$$$$$$$$$ <!> "
 !!!!!!!!!!!' z$$$$$$$$ """??",$$F ,c$,c c  .- ,$$$$$$$$$$$$$$$$$$$$$" !!>  
 !!!!!!!!!',c$$$$$$$$$",$$$$cd$P  J$$$$$$$c=". $$$$$$$$$$$$$$$$$$$$$" !!!>';
 !!!!!!'`,c$$$$$$$$$$$ $$$$$$$F J $$$$$$$"  "F<$$$$$$$$$$$$$$$$$$$$" <!!! <!
 !!!'.,c$$$$$$$$$$$$$$$$$$$$$P J z$$$$P".z$$cc,,.""?$$$$$$$$$$$$$$P >'!!  ``
 ! ,J$$$$"".,... "$$$$$$$$$$P / z$$$$P c$$$$$$$$$$$c,."???$$$$$$$" <'`!!! !;
 ! ?$$$F ;!!!!!!!  `"??$$$$F `,J$$$$$   `"?$$$$$$$$$$$$hcc ?$$$$" !! `!!! !!
 ! <$$" <!!!!!!'.zc,`'-.,..- z$$$$$$'        ""???$$$$$$$$F`??" ;!!! <!!! !!
 !> $" !!!',,,zc$$$$$cc,_' ,J$$$$$$F        <!>;;;;,  $$$$$  ;!!!!!! !!!';!!
 !! ' !!! J$$$$$$$$$$$$$$$$$$$$$$$".         !!!!!!!!;`$$$$h `!!!!!  <!! <!!
 `' .<!! .""???$$$$$$$$$$$$$$$$$$F !          `!!!!!!!;`$$$$$ <!!!! ;,.,;!!!
 Mx`<!'! !!!;;;,."""?$$$$$$$$$$P";!!           <!!!!!!!; $$$$c`!!! , `````.,
 MMn ',`!!!!!!!!!!!>;,,,."""??" <!!             !!!!!!!!; ?$$$.`!>4MMMMMM MM
 MMMb.`,`!!!!!!!!!!!!!!!!!!! ;!!!!              `!!!!!!!!; ?$$$ ' ,_""4MMMMM
 MMMMMx`,`!!!!!!!!!!!!!!!!!' !!!                 !!!!!!!!!> ?$$F MMMMM,  ..`
 
                                 D E G A S
                        2D/3D Graphics Device Manager

                      Microsoft Windows 95/NT Version

                Copyright (c) 1998 by Charybdis Enterprises, Inc.
                            All Rights Reserved.

 ---------------------------------------------------------------------------
 
            *** Charybdis Enterprises, Inc. Company Confidential ***
 
   This file and all associated files are the company proprietary property
         of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
 
  CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
  TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
  IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
  AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
  INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

  This library is a component of the MythOS(tm) entertainment and multi-
  media development library.

  MythOS is a trademark of Charybdis Enterprises, Inc.

  Created by Chuck Walbourn

  Last Updated: Septebmer 5, 1998

 ---------------------------------------------------------------------------
 DESCRIPTION

 This library provides 2D and 3D graphics pipeline including transformation,
 clipping, rasterization, and device management.  The core implementation
 will cover Software rasterization (memory, DIBs, and DDraw surfaces),
 Direct3D, Glide 3.x, and OpenGL.


 ---------------------------------------------------------------------------
 NOTES

 Started with basic architectural design. For simplicity, this will assume
 that direct import libraries are used for all APIs.  We will either have
 to convert this to use a hand-built jump table or broken up into multiple
 DLLs for use by applications to avoid requiring DLLs for APIs that are not
 used.

 DegasDevice

    This class defines the interface for a 'device' for video output.  This
    includes detection, intialization, and shutdown.  This interface is used
    to create displays and texture managers.  For now, we will assume
    only 15/16-bit displays with an eye towards 24-bit and 32-bit displays
    in the future.

    If we use virtuals for all functions that are not inline, this base
    can handle searching and loading of DLLs which contain the derived
    classes.

    - This includes a static interface for constructing the correct device
      through a common interface with device id and shared setup structure.

    - Possibly a simple method for the complete setup of Display, Texture
      Manager, and the primary Viewport class would make use of the 
      API simplier for basic usage, leaving the details of using each
      level for the advanced user.

    class DegasDevice
    {
        // Instance owns all created instances of displays
        // and texture managers which are freed by calling close or by
        // individually closing the instances.

    public:
        DegasDevice();
        virtual ~DegasDevice();

        virtual dg_error_codes open(DegasDevDesc *,
                                    DegasDisplay **,
                                    DegasTexManager **);
        virtual close();

        virtual dg_error_codes caps(DegasDevCaps *) const;

        void set_app_data(void *);
        void *get_app_data() const;

        static dg_error_codes enumerate(int (*)func(DegasDevDesc *, void*),
                                        void *) const;

        static dg_error_codes open(DegasSetupDesc *,
                                   DegasDevice **, DegasDisplay **,
                                   DegasTexManager **);
    };

    class DegasDevDesc
    {
        // Ids, features, subids, etc. needed to create a display
        // and to communicate back from an enumerate.
    };

    class DegasDevCaps
    {
        // Capabilities of the device
    }

    class DegasSetupDesc
    {
        // Contains all information needed for creation of a device
        // in a given resolution with a given set of features.
        // This used during a static 'open' to completely initalize
        // the device, display, and texture manager based on these
        // settings.

        dg_error_codes read(const char *ini_file);
        dg_error_codes read(XFParseINI *);

        dg_error_codes write(const char *ini_file);
        dg_error_codes write(XFParseINI *);
    };

        DegasMemoryDevice : DegasDevice

            This class handles creation of virtual drawing buffers with
            no physical device.  This uses the same structure for
            consisentcy.  "Off-screen" viewports can be created from
            many devices which provides this capability without requiring
            a new DegasMemoryDevice be opened, but this can be used
            when no other suitable device is open and present.

        DegasDIBDevice : DegasDevice

            This class handles a WinG or DIB-based display.  Performance
            of DIB using 15-bit bit-depths is poor, but this provides
            the easist base-line functionality for debugging of software
            rasterizers which can greatly simplify development of DirectDraw
            software rasterization.

        DegasDDrawDevice : DegasDevice

            This class handles a DirectDraw display without the use of
            Direct3D.  This is the fastest method for displaying the
            results of software rasterization on Windows platform
            machines.

        DegasD3DDevice : DegasDevice

            This class handles a DirectDraw display with the use of Direct3D.
            Although the stability of Direct3D varies greatly, it provides
            the largest base-line of support and covers many low-end
            cards common to the 'mass-market'.

        Degas3DfxDevice : DegasDevice

            This class handles a Glide-based display technology.  This is
            considered to be the current 'end-all beat-all', but it is
            unclear whether it will be dropped in favor of another interface
            or possibly expand its support to other vendors chipsets.

        DegasOGLDevice : DegasDevice

            This class handles an OpenGL-based display technology. While
            OpenGL is very easy to work with and many hardware vendors are
            taking support of its seriously, Microsoft has made it clear
            they don't want OpenGL to survive as is and will work hard to
            only support this for "high-end" software--which apparently
            doesn't include games.

 DegasDisplay

    This class defines the interface for a display instance.  For most
    devices, there is only a single display instance.  The correct
    instance type is returned by the Device.  This class owns the
    frame buffers, depth buffers, and other attributes of the primary
    device.  The 'swap' command, resolution enumeration and setting,
    and creation of viewports is the primary purpose of this interface.
    A method for saving displays to files and/or transfer to/from other
    display types would also be very useful in certain instances.

    class DegasDisplay
    {
        // Instance owns all created viewport instances which are freed
        // by calling close or by individually closing the instances.

        DegasDisplay();

    public:
        virtual ~DegasDisplay();

        virtual dg_error_codes enumerate(int (*)func(DegasDispDesc *, void *),
                                         void *) const;

        virtual dg_error_codes open(DegasDispDesc *,
                                    DegasViewport **);
        virtual dg_error_codes close();

        virtual dg_error_codes create(DegasVPortDesc *,
                                      DegasViewport **);

        virtual dg_error_codes swap();

        virtual dg_error_codes reset();

        virtual dg_error_codes capture(DegasImage *);

        void set_app_data(void *);
        void *get_app_data() const;
    };

    class DegasVPortDesc
    {
        // Resolution and features desired for a sub-viewport...
        // This can be an 'off-screen' viewport which for all software
        // rasterization displays is a 'main memory' viewport.
    };

        DegasMemoryDisplay : DegasDisplay

            Again, most displays can create 'off-screen' viewports
            which are memory viewports in the case of the software
            rasterizers, but this class is required to maintain
            a consistent operation even in the case of entirely
            virtual device and display usage.

        DegasDIBDisplay : DegasMemoryDisplay

            This manages the WinG DIB display.

        DegasDDrawDisplay : DegasDisplay

            This manages a DirectDraw display without Direct3D.

        DegasD3DDisplay : DegasDDrawDisplay

            This manages a DirectDraw display with Direct3D.

        Degas3DfxDisplay : DegasDisplay

            This manages a Glide technology display.

        DegasOGLDisplay : DegasDisplay

            This manages an OpenGL technology display.

 DegasViewport

    This class defines the interface for drawing onto a display.  A viewport
    can point to an entire display area or a subviewport within the the
    display.  This interface includes the methods for setting up clipping
    and transform information as well as direct commands for rasterizing
    to the display.

    class DegasViewport
    {
        DegasViewport();

    public:
        virtual ~DegasViewport();

        virtual dg_error_codes close();
        virtual dg_error_codes reset();

        virtual dg_error_codes sync();
        virtual dg_error_codes begin();
        virtual dg_error_codes end();

        virtual dg_error_codes frect(DegasRect *);
        virtual dg_error_codes point(DegasVertex *pt);
        virtual dg_error_codes line(DegasVertex *pt1, DegasVertex *p2);
        virtual dg_error_codes gline(DegasVertex *pt1, DegasVertex *p2);
        virtual dg_error_codes gline_persp(DegasVertex *pt1, DegasVertex *p2);
        virtual dg_error_codes poly(int count, DegasVertex pts[]);
        virtual dg_error_codes gpoly(int count, DegasVertex pts[]);
        virtual dg_error_codes gpoly_persp(int count, DegasVertex pts[]);
        virtual dg_error_codes tpoly(int count, DegasVertex pts[]);
        virtual dg_error_codes tpoly_persp(int count, DegasVertex pts[]);
        virtual dg_error_codes gtpoly(int count, DegasVertex pts[]);
        virtual dg_error_codes gtpoly_persp(int count, DegasVertex pts[]);

        virtual dg_error_codes transform(ElrMatrix3DW *mtx);
        virtual dg_error_codes view(DegasView *);

        virtual void set_flags(dword flags);
        dword get_flags() const;

        virtual void set_color(DegasRGBColor *);
        void get_color(DegasRGBColor *) const;

        virtual void set_alpha(float f);
        float get_alpha() const;

        virtual void set_material(DegasMaterial *);
        void get_material(DegasMaterial *) const;

        virtual void set_bcolor(DegasRGBColor *);
        void get_bcolor(DegasRGBColor *) const;

        virtual void set_farz(float);
        float get_farz() const;

        virtual void set_fog(DegasFog *);
        void get_fog(DegasFog *) const;

        void set_app_data(void *);
        void *get_app_data() const;
    };

    class DegasMaterial
    {
        // Information about various lighting model colors, 
        // and texture choice.
    }

    class DegasView
    {
        // Viewing paramters for projection and
        // clipping.
    }

        DegasMemoryViewport

            This handles drawing to a memory buffer with software
            rasterization and is therefore used for either Memory or
            DIB displays.

        DegasSurfaceViewport

            This handles drawing onto a DirectDraw surface buffer using
            software rasterization and is used for DDraw without Direct3D.

        DegasD3DViewport : DegasSurfaceViewport

            This handles drawing onto a DirectDraw surface with the use
            of Direct3D for rasterization.

        Degas3DfxViewport

            This handles drawing onto a display using the Glide 3.x API.

        DegasOGLViewport

            This handles drawing onto a display using the OpenGL API.

 DegasTexManager

    This class defines the interface for manging textures on the device.
    This includes registration of textures, priority assignment, caching,
    and loading/saving of textures to/from disk.

        DegasMemoryTextureManager
        DegasSurfaceTextureManager
        DegasD3DTextureManager
        Degas3DfxTextureManager
        DegasOGLTextureManager

 DegasRGBColor

    This is a container class for RGB color values.

 DegasHLSColor

    This is a container class for HLS color values.

 DegasRect

    This is a container class for defining screen rectangles.

 DegasVertex

    This is a container class for defining coordinates.

 DegasMaterial

    This is a container class for defining colors, surface
    characteristics, and texture choice.

 DegasImage

    This is a container class for providing a bitmap for transfer
    directly to a display.  This will include support for native
    format transfers as well as 8-bit, mono, and RLE compressed
    data.

*** END OF FILE ***
