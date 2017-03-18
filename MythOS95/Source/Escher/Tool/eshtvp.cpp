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
// eshtvp.cpp
//
// Escher Tool viewport class, which is a child of the view class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "eshtool.h"
#include "eshtvp.h"
#include "eshtdoc.h"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

extern ulong BitDepth;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolVPort                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

BEGIN_MESSAGE_MAP(ToolVPort, CWnd)
        //{{AFX_MSG_MAP(ToolVPort)
        ON_WM_SIZE()
        ON_WM_PAINT()
        ON_WM_RBUTTONDOWN()
        ON_WM_HSCROLL()
        ON_WM_VSCROLL()
        ON_WM_LBUTTONDOWN()
        ON_WM_MOUSEMOVE()
        ON_WM_LBUTTONUP()
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Constructor/Destructor °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolVPort - Constructor                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ToolVPort::ToolVPort()
{
    vptype = VPORT_NONE;
    bmi = 0;
    gmap = 0;
    gvp = 0;
    cam = 0;

    mode = RNDCTRL_NONE;
    modeTarget = NULL;
    capture = 0;

    cflags = ESCH_CAM_MODELSPACE
             | ESCH_CAM_TEXTURED
             | ESCH_CAM_PERSPECTIVE
             | ESCH_CAM_ALPHA
             | ESCH_CAM_BACKCULL
             | ESCH_CAM_SHADE_WIRE
             | ESCH_CAM_SHADE_SOLID
             | ESCH_CAM_SHADE_FLAT
             | ESCH_CAM_SHADE_SMOOTH
             | ESCH_CAM_SHADE_SPECULAR;

    extra_flags = 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ViewerVPort - Destructor                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ToolVPort::~ToolVPort()
{
    release_vport();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Diagnostics °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Operations °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                            ²²² Protected ²²²                             ³
// ToolVPort - setup_vport                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::setup_vport(int width, int height)
{
    release_vport();

    if (!width || !height)
        return;

    ASSERT(!(width & 0x3));

    ulong ihsize = sizeof(BITMAPINFOHEADER);
    if (BitDepth == 8)
        ihsize += 256*sizeof(WORD);

    bmi = (LPBITMAPINFO) ivory_alloc (ihsize);
    ASSERT(bmi);

    memset(bmi, 0, sizeof(*bmi));
    bmi->bmiHeader.biSize         = sizeof (BITMAPINFOHEADER);
    bmi->bmiHeader.biWidth        = width;
    bmi->bmiHeader.biHeight       = -height;
    bmi->bmiHeader.biPlanes       = 1;
    bmi->bmiHeader.biCompression  = BI_RGB;
    bmi->bmiHeader.biClrUsed      = 0;
    bmi->bmiHeader.biClrImportant = 0;

    ToolDoc *pDoc = (ToolDoc*) ((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    ASSERT(pDoc->palette != 0);

    switch (BitDepth)
    {
        case 15:
            {
                ASSERT(pDoc->palette && (pDoc->palette->flags & VNGO_15BIT));

                bmi->bmiHeader.biBitCount     = 16;

                gmap = new BYTE [(((width*2)+3) & ~0x3)*height];
            }
            break;
        default:
            ASSERT(pDoc->palette && (pDoc->palette->flags & VNGO_8BIT));

            bmi->bmiHeader.biBitCount     = 8;

            for(int i=0; i < 256; i++)
            {
                ((WORD *)bmi->bmiColors)[i] = (WORD)i;
            }

            gmap = new BYTE [width * height];
            break;
    }

    ASSERT(gmap);

    switch (BitDepth)
    {
        case 15:
            gvp = new VngoVportDB16(width,height,gmap,NULL, pDoc->palette,
                                    VNGO_ZBUFFER_DEV);
            break;
        default:
            gvp = new VngoVportDB8(width,height,gmap,NULL, pDoc->palette,
                                   VNGO_ZBUFFER_DEV);
            break;
    }
    ASSERT(gvp);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                            ²²² Protected ²²²                             ³
// ToolVPort - release_vport                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::release_vport()
{
    if (bmi)
    {
        ivory_free((void**)&bmi);
    }

    if (gmap)
    {
        delete [] gmap;
        gmap = 0;
    }

    if (gvp)
    {
        delete gvp;
        gvp = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolVPort - SetCamera                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::SetCamera(EschCameraEx *c)
{
    cam=c;

    vptype=VPORT_CAMERA;

    if (!cam)
        return;

    cam->attach(gvp);
    cam->set_flags(cflags);

    if (cflags & ESCH_CAM_SORT)
        gvp->zbuffer_off();
    else
        gvp->zbuffer_on();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolVPort - extents_render                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::extents_render(EschMeshDraw *ptr)
{
    for(; ptr != NULL; ptr = (EschMeshDraw*)ptr->next())
    {
        if (!(ptr->flags & ESCH_DRW_SKIP))
        {
            dword color = cam->bcolor ^ 255;

            if (extra_flags & BOX_EXTS)
            {
                ptr->mesh->box.draw(&ptr->world,color);
            }
            if (extra_flags & SPHERE_EXTS)
            {
                ptr->draw_extents(color);
            }

            if (ptr->child())
                extents_render((EschMeshDraw*)ptr->child());
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolVPort - Render                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::Render(void)
{
    ToolDoc *pDoc = (ToolDoc*) ((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    if (!cam)
    {
        ASSERT(pDoc->palette != 0);
        if (gvp)
            gvp->reset(pDoc->palette->get_index((VngoColor24bit)0));
        return;
    }

    EschContext ec(EschCurrent);
    ec.camera = cam;
    ec.lights = pDoc->lights;
    ec.eschs = pDoc->meshes;
    ec.push();

    cam->render();

    if (extra_flags & (SPHERE_EXTS | BOX_EXTS))
    {
        extents_render(pDoc->meshes);
    }

    ec.pop();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolVPort - SetMode                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::SetMode(rnd_ctrl_mode_type m, void *t)
{
    switch (m)
    {
        case RNDCTRL_ROTATEIJ:
            if (!t)
                return;
            modeTarget = t;
        case RNDCTRL_ROTATEXY:
            SetScrollRange(SB_VERT,-180,180,FALSE);         // Rotate Y
            SetScrollPos(SB_VERT,0);
            SetScrollRange(SB_HORZ,-180,180,FALSE);         // Rotate X
            SetScrollPos(SB_HORZ,0);
            break;
        case RNDCTRL_MOVEIJ:
            if (!t)
                return;
            modeTarget = t;
        case RNDCTRL_MOVEXY:
            SetScrollRange(SB_VERT,-32768,+32768,FALSE);    // Move Y
            SetScrollPos(SB_VERT,0);
            SetScrollRange(SB_HORZ,-32768,+32768,FALSE);    // Move X
            SetScrollPos(SB_HORZ,0);
            break;
        case RNDCTRL_ROTMOVEK:
            if (!t)
                return;
            modeTarget = t;
        case RNDCTRL_ROTMOVEZ:
            SetScrollRange(SB_VERT,-32768,+32768,FALSE);    // Move Z
            SetScrollPos(SB_VERT,0);
            SetScrollRange(SB_HORZ,-180,180,FALSE);         // Rotate Z
            SetScrollPos(SB_HORZ,0);
            break;
        case RNDCTRL_LIGHTXY:
            if (!t)
                return;
            modeTarget = t;
            if ( ((EschLight*)t)->get_type() == ESCH_LGTT_VECTOR )
            {
                SetScrollRange(SB_VERT,-180,180,FALSE);     // Rotate Y
                SetScrollPos(SB_VERT,0);
                SetScrollRange(SB_HORZ,-180,180,FALSE);     // Rotate X
                SetScrollPos(SB_HORZ,0);
            }
            else if ( ((EschLight*)t)->get_type() == ESCH_LGTT_FPOINT
                      || ((EschLight*)t)->get_type() == ESCH_LGTT_FATTEN
                      || ((EschLight*)t)->get_type() == ESCH_LGTT_FSPOT
                      || ((EschLight*)t)->get_type() == ESCH_LGTT_POINT
                      || ((EschLight*)t)->get_type() == ESCH_LGTT_ATTEN
                      || ((EschLight*)t)->get_type() == ESCH_LGTT_SPOT )
            {
                SetScrollRange(SB_VERT,-32768,+32768,FALSE);// Move Y
                SetScrollPos(SB_VERT,0);
                SetScrollRange(SB_HORZ,-32768,+32768,FALSE);// Move X
                SetScrollPos(SB_HORZ,0);
            }
            else
            {
                return;
            }
            break;
        case RNDCTRL_LIGHTBRIGHT:
            if (!t)
                return;
            modeTarget = t;
                                                            // Adjust light brightness
            SetScrollRange(SB_VERT,0,255,FALSE);
            SetScrollPos(SB_VERT,((EschLight*)t)->get_intensity());
            SetScrollRange(SB_HORZ,0,255,FALSE);
            SetScrollPos(SB_HORZ,((EschLight*)t)->get_intensity());
            break;
        default:
            EnableScrollBarCtrl(SB_VERT,FALSE);
            EnableScrollBarCtrl(SB_HORZ,FALSE);
            break;
    }

    mode = m;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Message Handlers °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ViewerVPort - OnPaint                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::OnPaint()
{
        CPaintDC dc(this);

    CRect   rect;
    GetClientRect(&rect);

    ToolDoc *pDoc = (ToolDoc*) ((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    if (BitDepth == 8)
    {
        SelectPalette(dc.m_hDC,pDoc->hpal,0);
        dc.RealizePalette ();
    }

    int t=SetDIBitsToDevice(dc.m_hDC, 0, 0, rect.right, rect.bottom,
                      0, 0, 0, rect.bottom,
                      gmap, bmi, (BitDepth == 8) ? DIB_PAL_COLORS : DIB_RGB_COLORS);

    if (!t)
    {
        MessageBox("SetDIBits returned error", MB_OK);
        ExitProcess(1);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ViewerVPort - OnSize                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::OnSize(UINT nType, int cx, int cy)
{
    cx &= ~0x3;

    setup_vport(cx, cy);

    if (cam)
        cam->attach(gvp);
    Render();

        CWnd::OnSize(nType, cx, cy);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolVPort - OnHScroll                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    int             t, pos, render=0;
    float           f;
    static int      lastpos=0;
    EschLight       *lgt;
    EschMeshDraw    *msh;

    ToolDoc* pDoc = (ToolDoc*)((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    pos = (int)nPos;

    switch (mode)
    {
        case RNDCTRL_ROTATEXY:                  // Rotate X
            if (!cam)
                break;
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    cam->yaw(-1.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    cam->yaw(-11.25f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    cam->yaw(1.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    cam->yaw(11.25f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    cam->yaw(float(pos - lastpos));
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_MOVEXY:                    // Move X
            if (!cam)
                break;
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    cam->move(-1.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    cam->move(-10.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    cam->move(1.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    cam->move(10.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (float)(pos-lastpos) / 10.0f;
                    cam->move(f,0.0f,0.0f);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_ROTMOVEZ:                  // Rotate Z
            if (!cam)
                break;
            switch (nSBCode)
            {
                case SB_LINERIGHT:
                    cam->roll(-1.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    cam->roll(-11.25f);
                    render=1;
                    break;
                case SB_LINELEFT:
                    cam->roll(1.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    cam->roll(11.25f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    cam->roll(float(lastpos - pos));
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_ROTATEIJ:                  // Rotate I
            if (!modeTarget)
                break;
            msh = (EschMeshDraw*)modeTarget;
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    msh->yaw(-1.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    msh->yaw(-11.25f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    msh->yaw(1.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    msh->yaw(11.25f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    msh->yaw(float(pos - lastpos));
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_MOVEIJ:                    // Move I
            if (!modeTarget)
                break;
            msh = (EschMeshDraw*)modeTarget;
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    msh->move(-1.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    msh->move(-10.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    msh->move(1.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    msh->move(10.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (float)(pos-lastpos) / 10.0f;
                    msh->move(f,0.0f,0.0f);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_ROTMOVEK:                  // Rotate K
            if (!modeTarget)
                break;
            msh = (EschMeshDraw*)modeTarget;
            switch (nSBCode)
            {
                case SB_LINERIGHT:
                    msh->roll(-1.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    msh->roll(-11.25f);
                    render=1;
                    break;
                case SB_LINELEFT:
                    msh->roll(1.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    msh->roll(11.25f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    msh->roll(float(lastpos - pos));
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_LIGHTXY:                   // Rotate X/Move X
            if (!modeTarget)
                break;
            lgt = (EschLight*)modeTarget;
            ASSERT(lgt->get_type() != ESCH_LGTT_AMBIENT);
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatex(-1);
                    else if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                        ((EschPointLight*)lgt)->translate(-1.0f,0.0f,0.0f);
                    else if (lgt->get_type() == ESCH_LGTT_FPOINT
                            || lgt->get_type() == ESCH_LGTT_FATTEN
                            || lgt->get_type() == ESCH_LGTT_FSPOT)
                        ((EschFastPointLight*)lgt)->translate(-1.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatex(-11.25f);
                    else if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                        ((EschPointLight*)lgt)->translate(-10.0f,0.0f,0.0f);
                    else if (lgt->get_type() == ESCH_LGTT_FPOINT
                             || lgt->get_type() == ESCH_LGTT_FATTEN
                             || lgt->get_type() == ESCH_LGTT_FSPOT)
                        ((EschFastPointLight*)lgt)->translate(-10.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatex(1.0f);
                    else if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                        ((EschPointLight*)lgt)->translate(1.0f,0.0f,0.0f);
                    else if (lgt->get_type() == ESCH_LGTT_FPOINT
                             || lgt->get_type() == ESCH_LGTT_FATTEN
                             || lgt->get_type() == ESCH_LGTT_FSPOT)
                        ((EschFastPointLight*)lgt)->translate(1.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatex(11.25f);
                    else if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                        ((EschPointLight*)lgt)->translate(10.0f,0.0f,0.0f);
                    else if (lgt->get_type() == ESCH_LGTT_FPOINT
                             || lgt->get_type() == ESCH_LGTT_FATTEN
                             || lgt->get_type() == ESCH_LGTT_FSPOT)
                        ((EschFastPointLight*)lgt)->translate(10.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatex(float(pos - lastpos));
                    else
                    {
                        f = (float)(pos-lastpos) / 10.0f;

                        if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                            ((EschPointLight*)lgt)->translate(f,0.0f,0.0f);
                        else if (lgt->get_type() == ESCH_LGTT_FPOINT
                             || lgt->get_type() == ESCH_LGTT_FATTEN
                             || lgt->get_type() == ESCH_LGTT_FSPOT)
                            ((EschFastPointLight*)lgt)->translate(f,0.0f,0.0f);
                    }
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_LIGHTBRIGHT:               // Intensity
            if (!modeTarget)
                break;
            lgt = (EschLight*)modeTarget;
            t=lgt->get_intensity();
            switch (nSBCode)
            {
                case SB_LINERIGHT:
                    if (t < 255)
                    {
                        t++;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_PAGERIGHT:
                    if (t < 255)
                    {
                        t += 16;
                        if (t > 255)
                            t = 255;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_LINELEFT:
                    if (t > 0)
                    {
                        t--;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_PAGELEFT:
                    if (t > 0)
                    {
                        t -= 16;
                        if (t < 0)
                            t = 0;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_THUMBTRACK:
                    t = pos;
                    SetScrollPos(SB_HORZ,t);
                    SetScrollPos(SB_VERT,t);
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            if (render)
                lgt->set_intensity(t);
            break;
    }

        CWnd::OnHScroll(nSBCode, nPos, pScrollBar);

    if (render)
    {
        Render();
        RedrawWindow();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolVPort - OnVScroll                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    int             t, pos, render=0;
    float           f;
    static int      lastpos=0;
    EschLight       *lgt;
    EschMeshDraw    *msh;

    ToolDoc* pDoc = (ToolDoc*)((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    pos = (int)nPos;

    switch (mode)
    {
        case RNDCTRL_ROTATEXY:                  // Rotate Y
            if (!cam)
                break;
            switch (nSBCode)
            {
                case SB_LINEUP:
                    cam->pitch(-1.0f);
                    render=1;
                    break;
                case SB_PAGEUP:
                    cam->pitch(-11.25f);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    cam->pitch(1.0f);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    cam->pitch(11.25f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    cam->pitch(float(pos - lastpos));
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_MOVEXY:                    // Move Y
            if (!cam)
                break;
            switch (nSBCode)
            {
                case SB_LINEUP:
                    cam->move(0.0f,1.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGEUP:
                    cam->move(0.0f,10.0f,0.0f);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    cam->move(0.0f,-1.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    cam->move(0.0f,-10.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (float)(lastpos-pos) / 10.0f;
                    cam->move(0.0f,f,0.0f);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_ROTMOVEZ:                  // Move Z
            if (!cam)
                break;
            switch (nSBCode)
            {
                case SB_LINEUP:
                    cam->move(0.0f,0.0f,1.0f);
                    render=1;
                    break;
                case SB_PAGEUP:
                    cam->move(0.0f,0.0f,10.0f);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    cam->move(0.0f,0.0f,-1.0f);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    cam->move(0.0f,0.0f,-10.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (float)(lastpos-pos) / 10.0f;
                    cam->move(0.0f,0.0f,f);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_ROTATEIJ:                  // Rotate J
            if (!modeTarget)
                break;
            msh = (EschMeshDraw*)modeTarget;
            switch (nSBCode)
            {
                case SB_LINEUP:
                    msh->pitch(-1.0f);
                    render=1;
                    break;
                case SB_PAGEUP:
                    msh->pitch(-11.25f);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    msh->pitch(1.0f);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    msh->pitch(11.25f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    msh->pitch(float(pos - lastpos));
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_MOVEIJ:                    // Move J
            if (!modeTarget)
                break;
            msh = (EschMeshDraw*)modeTarget;
            switch (nSBCode)
            {
                case SB_LINEUP:
                    msh->move(0.0f,1.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGEUP:
                    msh->move(0.0f,10.0f,0.0f);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    msh->move(0.0f,-1.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    msh->move(0.0f,-10.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (float)(lastpos-pos) / 10.0f;
                    msh->move(0.0f,f,0.0f);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_ROTMOVEK:                  // Move K
            if (!modeTarget)
                break;
            msh = (EschMeshDraw*)modeTarget;
            switch (nSBCode)
            {
                case SB_LINEUP:
                    msh->move(0.0f,0.0f,1.0f);
                    render=1;
                    break;
                case SB_PAGEUP:
                    msh->move(0.0f,0.0f,10.0f);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    msh->move(0.0f,0.0f,-1.0f);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    msh->move(0.0f,0.0f,-10.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (float)(lastpos-pos) / 10.0f;
                    msh->move(0.0f,0.0f,f);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_LIGHTXY:                   // Rotate Y/Move Y
            if (!modeTarget)
                break;
            lgt = (EschLight*)modeTarget;
            ASSERT(lgt->get_type() != ESCH_LGTT_AMBIENT);
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatey(-1.0f);
                    else if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                        ((EschPointLight*)lgt)->translate(0.0f,-1.0f,0.0f);
                    else if (lgt->get_type() == ESCH_LGTT_FPOINT
                             || lgt->get_type() == ESCH_LGTT_FATTEN
                             || lgt->get_type() == ESCH_LGTT_FSPOT)
                        ((EschFastPointLight*)lgt)->translate(0.0f,-1.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatey(-11.25f);
                    else if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                        ((EschPointLight*)lgt)->translate(0.0f,-10.0f,0.0f);
                    else if (lgt->get_type() == ESCH_LGTT_FPOINT
                             || lgt->get_type() == ESCH_LGTT_FATTEN
                             || lgt->get_type() == ESCH_LGTT_FSPOT)
                        ((EschFastPointLight*)lgt)->translate(0.0f,-10.0f,0.0f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatey(1.0f);
                    else if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                        ((EschPointLight*)lgt)->translate(0.0f,1.0f,0.0f);
                    else if (lgt->get_type() == ESCH_LGTT_FPOINT
                             || lgt->get_type() == ESCH_LGTT_FATTEN
                             || lgt->get_type() == ESCH_LGTT_FSPOT)
                        ((EschFastPointLight*)lgt)->translate(0.0f,1.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatey(11.25f);
                    else if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                        ((EschPointLight*)lgt)->translate(0.0f,10.0f,0.0f);
                    else if (lgt->get_type() == ESCH_LGTT_FPOINT
                             || lgt->get_type() == ESCH_LGTT_FATTEN
                             || lgt->get_type() == ESCH_LGTT_FSPOT)
                        ((EschFastPointLight*)lgt)->translate(0.0f,10.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    if (lgt->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)lgt)->rotatey(float(pos - lastpos));
                    else
                    {
                        f = (float)(pos-lastpos) / 10.0f;

                        if (lgt->get_type() == ESCH_LGTT_POINT
                             || lgt->get_type() == ESCH_LGTT_ATTEN
                             || lgt->get_type() == ESCH_LGTT_SPOT)
                            ((EschPointLight*)lgt)->translate(0.0f,f,0.0f);
                        else if (lgt->get_type() == ESCH_LGTT_FPOINT
                             || lgt->get_type() == ESCH_LGTT_FATTEN
                             || lgt->get_type() == ESCH_LGTT_FSPOT)
                            ((EschFastPointLight*)lgt)->translate(0.0f,f,0.0f);
                    }
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_LIGHTBRIGHT:               // Intensity
            if (!modeTarget)
                break;
            lgt = (EschLight*)modeTarget;
            t=lgt->get_intensity();
            switch (nSBCode)
            {
                case SB_LINERIGHT:
                    if (t < 255)
                    {
                        t++;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_PAGERIGHT:
                    if (t < 255)
                    {
                        t += 16;
                        if (t > 255)
                            t = 255;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_LINELEFT:
                    if (t > 0)
                    {
                        t--;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_PAGELEFT:
                    if (t > 0)
                    {
                        t -= 16;
                        if (t < 0)
                            t = 0;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_THUMBTRACK:
                    t = pos;
                    SetScrollPos(SB_HORZ,t);
                    SetScrollPos(SB_VERT,t);
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            if (render)
                lgt->set_intensity(t);
            break;
    }

        CWnd::OnVScroll(nSBCode, nPos, pScrollBar);

    if (render)
    {
        Render();
        RedrawWindow();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ViewerVPort - OnLButtonDown                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::OnLButtonDown(UINT nFlags, CPoint point)
{
    if (!capture)
    {
        capture=1;
        SetCapture();
        lastx = point.x;
        lasty = point.y;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ViewerVPort - OnLButtonUp                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::OnLButtonUp(UINT nFlags, CPoint point)
{
    if (capture)
    {
        capture=0;
        ReleaseCapture();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ViewerVPort - OnMouseMove                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::OnMouseMove(UINT nFlags, CPoint point)
{
    if (!capture)
        return;

    int dx = point.x - lastx;
    int dy = point.y - lasty;

    if (!dx && !dy)
        return;

    ToolDoc* pDoc = (ToolDoc*)((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    int             t, render=0;
    EschLight       *lgt;
    EschMeshDraw    *msh;

    switch (mode)
    {
        case RNDCTRL_ROTATEXY:                  // Rotate X/Y
            if (!cam)
                break;
            cam->yaw((float)-dx);
            cam->pitch((float)-dy);
            render=1;
            break;
        case RNDCTRL_MOVEXY:                    // Move X/Y
            if (!cam)
                break;
            cam->move((float)-dx, (float)dy, 0.0f);
            render=1;
            break;
        case RNDCTRL_ROTMOVEZ:                  // Rotate Z/Move Z
            if (!cam)
                break;
            if (nFlags & MK_SHIFT)
                cam->roll((float)-dx);
            else
                cam->move(0.0f, 0.0f, (float)dy);
            render=1;
            break;
        case RNDCTRL_ROTATEIJ:                  // Rotate I/J
            if (!modeTarget)
                break;
            msh = (EschMeshDraw*)modeTarget;
            msh->yaw((float)-dx);
            msh->pitch((float)-dy);
            render=1;
            break;
        case RNDCTRL_MOVEIJ:                    // Move I/J
            if (!modeTarget)
                break;
            msh = (EschMeshDraw*)modeTarget;
            {
                EschVector v((float)dx, (float)-dy, 0.0f);
                v.transform(&cam->eye.orient);
                msh->translate (&v);
            }
            render=1;
            break;
        case RNDCTRL_ROTMOVEK:                  // Rotate K/MoveK
            if (!modeTarget)
                break;
            msh = (EschMeshDraw*)modeTarget;
            if (nFlags & MK_SHIFT)
                msh->roll((float)-dx);
            else
            {
                EschVector v(0.0f, 0.0f, (float)-dy);
                v.transform(&cam->eye.orient);
                msh->translate (&v);
            }
            render=1;
            break;
        case RNDCTRL_LIGHTXY:                   // Rotate/Move
            if (!modeTarget)
                break;
            lgt = (EschLight*)modeTarget;
            ASSERT(lgt->get_type() != ESCH_LGTT_AMBIENT);
            if (lgt->get_type() == ESCH_LGTT_VECTOR)
            {
                ((EschVectorLight*)lgt)->rotatex((float)dx);
                ((EschVectorLight*)lgt)->rotatey((float)dy);
            }
            else if (nFlags & MK_SHIFT)
            {
                if (lgt->get_type() == ESCH_LGTT_POINT
                    || lgt->get_type() == ESCH_LGTT_ATTEN
                    || lgt->get_type() == ESCH_LGTT_SPOT)
                    ((EschPointLight*)lgt)->translate(0.0f, 0.0f, (float)dy);
                else if (lgt->get_type() == ESCH_LGTT_FPOINT
                         || lgt->get_type() == ESCH_LGTT_FATTEN
                         || lgt->get_type() == ESCH_LGTT_FSPOT)
                    ((EschFastPointLight*)lgt)->translate(0.0f, 0.0f, (float)dy);
            }
            else
            {
                if (lgt->get_type() == ESCH_LGTT_POINT
                    || lgt->get_type() == ESCH_LGTT_ATTEN
                    || lgt->get_type() == ESCH_LGTT_SPOT)
                    ((EschPointLight*)lgt)->translate((float)dx, (float)-dy, 0.0f);
                else if (lgt->get_type() == ESCH_LGTT_FPOINT
                         || lgt->get_type() == ESCH_LGTT_FATTEN
                         || lgt->get_type() == ESCH_LGTT_FSPOT)
                    ((EschFastPointLight*)lgt)->translate((float)dx, (float)-dy, 0.0f);
            }
            render=1;
            break;
        case RNDCTRL_LIGHTBRIGHT:               // Intensity
            if (!modeTarget)
                break;
            lgt = (EschLight*)modeTarget;
            t=lgt->get_intensity();
            t += dx;
            if (t < 0)
                t = 0;
            if (t > 255)
                t = 255;
            lgt->set_intensity(t);
            SetScrollPos(SB_VERT,t);
            SetScrollPos(SB_HORZ,t);
            render=1;
            break;
    }

    lastx = point.x;
    lasty = point.y;

    if (render)
    {
        Render();
        RedrawWindow();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ViewerVPort - OnRButtonDown                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolVPort::OnRButtonDown(UINT nFlags, CPoint point)
{
    if (capture)
    {
        return;
    }

//ÄÄÄ Create menu(s)

    CRect   rct;
    GetWindowRect (&rct);

    point.x += rct.left;
    point.y += rct.top;

//ÄÄÄ Create menu(s)

    //ÄÄÄ Render Submenu
    CMenu   modeMenu;
    modeMenu.CreatePopupMenu();

    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_WIREFRAME, "Wireframe");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_SOLID, "Solid");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_FLAT, "Flat");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_SMOOTH, "Smooth");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_SPECULAR, "Specular");
    modeMenu.AppendMenu(MF_SEPARATOR);
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_ALL_LINES, "Show All Lines");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_MSPACE, "Model Space");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_BACKFACE, "Backface");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_TEXTURES, "Textures");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_PERSPECTIVE, "Perspective");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_ALPHA, "Alpha");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_SORT, "Sort");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_ORTHO, "Orthogonal");

    //ÄÄÄ Show Submenu
    CMenu   showMenu;
    showMenu.CreatePopupMenu();

    showMenu.AppendMenu(MF_STRING, ID_VIEW_SHOW_SPHEXTS, "Spherical Extents");
    showMenu.AppendMenu(MF_STRING, ID_VIEW_SHOW_BOXEXTS, "Box Extents");

    //ÄÄÄ AutoRotate Submenu
    CMenu   autoMenu;
    autoMenu.CreatePopupMenu();
    autoMenu.AppendMenu(MF_STRING, ID_VIEW_AUTOOFF, "Off");
    autoMenu.AppendMenu(MF_SEPARATOR);
    autoMenu.AppendMenu(MF_STRING, ID_VIEW_AUTOROTX, "Rotate X");
    autoMenu.AppendMenu(MF_STRING, ID_VIEW_AUTOROTY, "Rotate Y");
    autoMenu.AppendMenu(MF_STRING, ID_VIEW_AUTOROTZ, "Rotate Z");
    autoMenu.AppendMenu(MF_SEPARATOR);
    autoMenu.AppendMenu(MF_STRING, ID_VIEW_AUTOFAST, "Fast");
    autoMenu.AppendMenu(MF_STRING, ID_VIEW_AUTOSLOW, "Slow");

    //ÄÄÄ Menu
    CMenu   rMenu;
    rMenu.CreatePopupMenu();
    rMenu.AppendMenu(MF_STRING, ID_VIEW_REFRESH, "Refresh");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING | MF_POPUP, (unsigned int) modeMenu.m_hMenu, "Render");
    rMenu.AppendMenu(MF_STRING | MF_POPUP, (unsigned int) showMenu.m_hMenu, "Show");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_VIEW_ROTXY, "Rotate X/Y");
    rMenu.AppendMenu(MF_STRING, ID_VIEW_MOVEXY, "Move X/Y");
    rMenu.AppendMenu(MF_STRING, ID_VIEW_ROTMOVEZ, "Rotate/Move Z");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_MESH_ROTIJ, "Rotate I/J");
    rMenu.AppendMenu(MF_STRING, ID_MESH_MOVEIJ, "Move I/J");
    rMenu.AppendMenu(MF_STRING, ID_MESH_ROTMOVEK, "Rotate/Move K");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_LGT_ADJUSTXY, "Adjust X/Y");
    rMenu.AppendMenu(MF_STRING, ID_LGT_ABRIGHT, "Adjust Intensity");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING | MF_POPUP, (unsigned int) autoMenu.m_hMenu, "Auto-Rotate");


//ÄÄÄ Display and perform action
    ASSERT(AfxGetMainWnd());
    rMenu.TrackPopupMenu( TPM_RIGHTBUTTON | TPM_LEFTALIGN,
                          point.x, point.y,
                          AfxGetMainWnd());
    rMenu.DestroyMenu();
    autoMenu.DestroyMenu();
    showMenu.DestroyMenu();
    modeMenu.DestroyMenu();
}

//°±² eof - eshtvp.cpp ²±°
