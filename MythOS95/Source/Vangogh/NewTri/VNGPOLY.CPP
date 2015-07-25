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
// Created by Tim Little
//
// vngpoly.cpp
//
//     The core poly code.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"
#include <math.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

ulong VngoTriCount = 0;
static depth;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" lineproc hline[];

//#define SCREEN_TOLERANCE2   256.f
#define WRATIO_TOLERANCE    1.025f
#define MAX_RECURSION_DEPTH 20

// PrfStopWatch        edge_timer;
// PrfStopWatch        hline_timer;

inline long flt2flx(float val)
{
#if 1
    return long(val * 65536.f);
#else
    long ret_val;
    _asm {
        mov ebx,val
        mov ecx,150
        mov edx,ebx
        mov eax,ebx
        and eax,0x7fffff
        shr ebx,23
        or  eax,0x800000
        and ebx,0xff
        add ebx,16
        sub ecx,ebx
        test ecx,0x80000000
        jns t1
        neg ecx
        shl eax,cl
        jmp done
t1:
        shr eax,cl
done:
        test edx,0x80000000
        jns done2
        neg eax
done2:
        mov ret_val,eax
    }
    return ret_val;
#endif
}


inline dword fltnorm(float val)
{
#if 1
    return dword(val * float(0x7fffffff));
#else
    long ret_val;
    _asm {
        mov ebx,val
        mov ecx,150
        mov edx,ebx
        mov eax,ebx
        and eax,0x7fffff
        shr ebx,23
        or  eax,0x800000
        and ebx,0xff
        add ebx,31
        sub ecx,ebx
        test ecx,0x80000000
        jns t1
        neg ecx
        shl eax,cl
        jmp done
t1:
        shr eax,cl
done:
        test edx,0x80000000
        jns done2
        neg eax
done2:
        mov ret_val,eax
    }
    return ret_val;
#endif
}



inline void find_mid_pt(VngoPointF *p1,VngoPointF *p2,VngoPointF *out)
{
    out->x = (p1->x + p2->x) * 0.5f;
    out->y = (p1->y + p2->y) * 0.5f;
    out->z = (p1->z + p2->z) * 0.5f;
    out->w = (p1->w + p2->w) * 0.5f;
    out->shade = (p1->shade + p2->shade) * 0.5f;
    out->u = (p1->u + p2->u) * 0.5f;
    out->v = (p1->v + p2->v) * 0.5f;
    out->clr = p1->clr;

    return;
}

#define _FABS(x) ((x) < 0.f) ? -(x): (x)
#define _F16CEIL(x) (((x) + 0xfffc) & 0xffff0000)

extern "C" void vngo_build_edgezgt (VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2,int is_right);
extern "C" void vngo_build_edgegt (VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2,int is_right);

extern "C" void vngo_triangle_persp (VngoVport *vp,dword flags,
                          VngoPointF *p0,
                          VngoPointF *p1,
                          VngoPointF *p2,
                          VngoMemTexture3D *tex,
                          long alpha);

extern "C" void vngo_triangle (VngoVport *vp,dword flags,
                               VngoPointF *p0,
                               VngoPointF *p1,
                               VngoPointF *p2,
                               VngoMemTexture3D *tex,
                               long alpha);

extern "C" void vngo_poly(VngoVport *vp,int count, dword flags,
                          VngoPointF *pts, VngoTexture *tex, long alpha)
{
    VngoTexture3D   *tptr=0;
    if (tex)
    {
        tptr = tex->vtex3d;

        while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
        {
            tptr = tptr->next;
        }
        if (tptr == NULL)
        {
            if (tex->pal_ptr == NULL)
                tex->pal_ptr = vp->vbuff.pal;

            tptr = new VngoMemTexture3D(tex,tex->pal_ptr);
            if (tptr->get_err_status() != VNGO_NO_ERROR)
            {
                delete tptr;
                return;
            }
        }
    }

    VngoPal *tpal = vp->vbuff.pal;

    if (tex)
        vp->vbuff.pal = tex->pal_ptr;

    VngoPointF tpts[3];

    depth = 0;
    if ((flags & VNGO_TRITYPE_PERSPECTIVE) && (flags & VNGO_TRITYPE_TEXTURED))
    {
        tpts[0].x     = pts[0].x;
        tpts[0].y     = pts[0].y;
        tpts[0].w     = pts[0].w;
        tpts[0].z     = pts[0].z;
        tpts[0].shade = pts[0].shade;

        tpts[0].u     = pts[0].u * pts[0].w;
        tpts[0].v     = pts[0].v * pts[0].w;
    }
    else
    {
        tpts[0] = pts[0];
    }
    for (int i=1;i < count-1;i++)
    {
        if ((flags & VNGO_TRITYPE_PERSPECTIVE) && (flags & VNGO_TRITYPE_TEXTURED))
        {

            tpts[1].x     = pts[i].x;
            tpts[1].y     = pts[i].y;
            tpts[1].w     = pts[i].w;
            tpts[1].z     = pts[i].z;
            tpts[1].shade = pts[i].shade;

            tpts[1].u     = pts[i].u * pts[i].w;
            tpts[1].v     = pts[i].v * pts[i].w;

            tpts[2].x     = pts[i+1].x;
            tpts[2].y     = pts[i+1].y;
            tpts[2].w     = pts[i+1].w;
            tpts[2].z     = pts[i+1].z;
            tpts[2].shade = pts[i+1].shade;

            tpts[2].u     = pts[i+1].u * pts[i+1].w;
            tpts[2].v     = pts[i+1].v * pts[i+1].w;

            vngo_triangle_persp(vp,flags,&tpts[0],&tpts[1],&tpts[2],(VngoMemTexture3D *)tptr,alpha);
        }
        else
        {
            tpts[1] = pts[i];
            tpts[2] = pts[i+1];

            vngo_triangle(vp,flags,&tpts[0],&tpts[1],&tpts[2],(VngoMemTexture3D *)tptr,alpha);
        }
    }

    vp->vbuff.pal = tpal;
    return;

}

extern "C" void vngo_triangle_persp(VngoVport *vp,dword flags,
                                    VngoPointF *p0,
                                    VngoPointF *p1,
                                    VngoPointF *p2,
                                    VngoMemTexture3D *tex,
                                    long alpha)
{

    float t[6];
    float w[3];

    depth++;
    t[0] = _FABS(p0->x - p1->x);
    t[1] = _FABS(p0->y - p1->y);
    t[2] = _FABS(p1->x - p2->x);
    t[3] = _FABS(p1->y - p2->y);
    t[4] = _FABS(p2->x - p0->x);
    t[5] = _FABS(p2->y - p0->y);

    if (p0->w > p1->w)
        w[0] = p0->w / p1->w;
    else
        w[0] = p1->w / p0->w;
    if (p1->w > p2->w)
        w[1] = p1->w / p2->w;
    else
        w[1] = p2->w / p1->w;
    if (p2->w > p0->w)
        w[2] = p2->w / p0->w;
    else
        w[2] = p0->w / p2->w;

    float tv=0;
    int ti=0;
    for (int i=0;i<6;i++)
    {
        if (t[i] > tv
            && ((w[i>>1] > WRATIO_TOLERANCE)
                || (t[i] > vp->persp_pixcount2)))
        {
            tv = t[i];
            ti=i;
        }
    }

    VngoPointF  tpt;
    if (tv > vp->persp_pixcount && (depth < MAX_RECURSION_DEPTH))
    {
        if (ti == 0 || ti == 1)
        {
            find_mid_pt(p0,p1,&tpt);
            vngo_triangle_persp(vp,flags,p0,&tpt,p2,tex,alpha);
            vngo_triangle_persp(vp,flags,&tpt,p1,p2,tex,alpha);
        }
        else if (ti==2 || ti==3)
        {
            find_mid_pt(p1,p2,&tpt);
            vngo_triangle_persp(vp,flags,p0,p1,&tpt,tex,alpha);
            vngo_triangle_persp(vp,flags,p0,&tpt,p2,tex,alpha);
        }
        else
        {
            find_mid_pt(p2,p0,&tpt);
            vngo_triangle_persp(vp,flags,p0,p1,&tpt,tex,alpha);
            vngo_triangle_persp(vp,flags,&tpt,p1,p2,tex,alpha);
        }
    }
    else
    {
        VngoPointF *tpa[3];

        tpa[0] = p0;
        tpa[1] = p1;
        tpa[2] = p2;

        VngoPointF  pa[3];

        for (int pcnt=0;pcnt < 3;pcnt++)
        {
            float tiw   = 1.f / tpa[pcnt]->w;

            pa[pcnt].x      = tpa[pcnt]->x;
            pa[pcnt].y      = tpa[pcnt]->y;
            pa[pcnt].z      = tpa[pcnt]->z;
            pa[pcnt].shade  = tpa[pcnt]->shade;
            pa[pcnt].clr    = tpa[pcnt]->clr;

            pa[pcnt].u      = (tpa[pcnt]->u * tiw);
            pa[pcnt].v      = (tpa[pcnt]->v * tiw);
        }

        vngo_triangle(vp,flags,&pa[0],&pa[1],&pa[2],tex,alpha);
    }
    depth--;
}

extern "C" void vngo_triangle (VngoVport *vp,dword flags,
                               VngoPointF *p0,
                               VngoPointF *p1,
                               VngoPointF *p2,
                               VngoMemTexture3D *tex,
                               long alpha)
{
    int top = 0,mid = 1,bottom = 2;
    int rotation=0;                        // Zero for clockwise,
    int long_isright = 1;
    VngoTriCount++;

    float dot = (((p0->x - p1->x) * (p2->y - p1->y))
        - ((p0->y - p1->y) * (p2->x - p1->x)));

    if (dot <= 0.f)
        rotation = 1;


    Flx16 flxdot (flt2flx(dot),0);

    if (p0->y < p1->y)
    {
        if (p2->y < p0->y)
        {
            top = 2;
            bottom = 1;
            mid = 0;
        }
        else
        {
            if (p1->y > p2->y)
            {
                bottom = 1;
                mid = 2;
                long_isright = 0;
            }
        }
    }
    else if (p1->y < p2->y)
    {
        top = 1;
        if(p0->y < p2->y)
        {
            bottom = 2;
            mid = 0;
            long_isright = 0;
        }
        else
        {
            bottom = 0;
            mid = 2;
        }
    }
    else
    {
        top = 2;
        bottom = 0;
        mid = 1;
        long_isright = 0;
    }

    if (rotation)
        long_isright ^= 1;


    VngoPoint2 *edge1 = vp->vbuff.edge1;
    VngoPoint2 *edge2 = vp->vbuff.edge2;

    VngoPoint2 pa[3];

    pa[0].x     = flt2flx(p0->x);
    pa[0].y     = flt2flx(p0->y);
    pa[0].z     = fltnorm(p0->z);
    pa[0].clr   = p0->clr;
    pa[0].shade = flt2flx(p0->shade);
    if (flags & VNGO_TRITYPE_TEXTURED)
    {
        pa[0].u     = flt2flx(p0->u) << tex->widthshift;
        pa[0].v     = flt2flx(p0->v) << tex->heightshift;
    }

    pa[1].x     = flt2flx(p1->x);
    pa[1].y     = flt2flx(p1->y);
    pa[1].z     = fltnorm(p1->z);
    pa[1].clr   = p1->clr;
    pa[1].shade = flt2flx(p1->shade);
    if (flags & VNGO_TRITYPE_TEXTURED)
    {
        pa[1].u     = flt2flx(p1->u) << tex->widthshift;
        pa[1].v     = flt2flx(p1->v) << tex->heightshift;
    }

    pa[2].x     = flt2flx(p2->x);
    pa[2].y     = flt2flx(p2->y);
    pa[2].z     = fltnorm(p2->z);
    pa[2].clr   = p2->clr;
    pa[2].shade = flt2flx(p2->shade);
    if (flags & VNGO_TRITYPE_TEXTURED)
    {
        pa[2].u     = flt2flx(p2->u) << tex->widthshift;
        pa[2].v     = flt2flx(p2->v) << tex->heightshift;
    }


    long    dyl,dys1,dys2;

    dyl = (_F16CEIL(pa[bottom].y) - _F16CEIL(pa[top].y)) >> 16;
    dys1 = (_F16CEIL(pa[mid].y) - _F16CEIL(pa[top].y)) >> 16;
    dys2 = (_F16CEIL(pa[bottom].y) - _F16CEIL(pa[mid].y)) >> 16;

    assert (!((dyl < 0) || (dys1 < 0) || (dys2 < 0)));

    int mid_y = dyl - dys2;

    if (dys1 == 0)
        mid_y = 0;
    else if (dys2 == 0)
        mid_y = dyl-1;

    if (mid_y < 0)
        mid_y = 0;

    VngoTriangle    tri;
    tri.start_y = (_F16CEIL(pa[top].y) >> 16);
    tri.color = pa[top].clr;
    tri.sptr = (word*)(dword(vp->vbuff.scrn_ptr) + vp->vbuff.ytable[tri.start_y]);
    tri.vbuff = &vp->vbuff;
    if (flags & VNGO_TRITYPE_ZBUFFER)
        tri.zptr  = (word*)(long(vp->vbuff.zbuff_ptr) + vp->vbuff.ztable[tri.start_y]);

    tri.pitch = vp->vbuff.pitch;
    tri.zpitch = vp->vbuff.zpitch;
    tri.alpha = alpha;
    tri.height = (_F16CEIL(pa[bottom].y) >> 16) - 1 - tri.start_y;
    tri.tex = tex;


    if (long_isright)
    {

        if (flags & VNGO_TRITYPE_ZBUFFER)
        {
            vngo_build_edgezgt(edge2,&pa[top],&pa[bottom],1);
            vngo_build_edgezgt(edge1,&pa[top],&pa[mid],0);
            vngo_build_edgezgt(&edge1[mid_y],&pa[mid],&pa[bottom],0);
        }
        else
        {
            vngo_build_edgegt(edge2,&pa[top],&pa[bottom],1);
            vngo_build_edgegt(edge1,&pa[top],&pa[mid],0);
            vngo_build_edgegt(&edge1[mid_y],&pa[mid],&pa[bottom],0);
        }
    }
    else
    {
        if (flags & VNGO_TRITYPE_ZBUFFER)
        {
            vngo_build_edgezgt(edge1,&pa[top],&pa[bottom],0);
            vngo_build_edgezgt(edge2,&pa[top],&pa[mid],1);
            vngo_build_edgezgt(&edge2[mid_y],&pa[mid],&pa[bottom],1);
        }
        else
        {
            vngo_build_edgegt(edge1,&pa[top],&pa[bottom],0);
            vngo_build_edgegt(edge2,&pa[top],&pa[mid],1);
            vngo_build_edgegt(&edge2[mid_y],&pa[mid],&pa[bottom],1);
        }
    }

    if (mid_y < 0)
        mid_y = 0;

    long mid_dx = edge2[mid_y].x - edge1[mid_y].x;

    tri.sstep_dx1 = 0;
    tri.zstep_dx1 = 0;
    tri.ustep_dx1 = 0;
    tri.vstep_dx1 = 0;

    if (mid_dx > 0)
    {
        tri.sstep_dx1 = (long(edge2[mid_y].shade) - long(edge1[mid_y].shade)) / mid_dx;
        if (flags & VNGO_TRITYPE_ZBUFFER)
            tri.zstep_dx1 = ((long(edge2[mid_y].z) - long(edge1[mid_y].z)) / mid_dx);
        if (flags & VNGO_TRITYPE_TEXTURED)
        {
            tri.ustep_dx1 = ((long(edge2[mid_y].u) - long(edge1[mid_y].u)) / mid_dx) << tri.tex->u_upshift;
            tri.vstep_dx1 = ((long(edge2[mid_y].v) - long(edge1[mid_y].v)) / mid_dx) << tri.tex->v_upshift;
        }
    }

    tri.left_edge = edge1;
    tri.right_edge = edge2;


    dword hlindex = flags & VNGO_TRITYPE_INDEX;
    if (flags & VNGO_TRITYPE_TEXTURED)
        hlindex |= (dword(tex->tdimension) <<  6);

    lineproc myhline = hline[hlindex];

    if (myhline)
        myhline(&tri);

    if (flags & VNGO_TRITYPE_OUTLINE)
    {
        VngoColor24bit red(255,0,0);

        VngoPointF  lp0 = *p0;
        VngoPointF  lp1 = *p1;
        VngoPointF  lp2 = *p2;
        vp->clip_line(&lp0,&lp1,&red);
        vp->clip_line(&lp1,&lp2,&red);
        vp->clip_line(&lp2,&lp0,&red);
    }
}



//°±² End of module - vngpoly.cpp ²±°

