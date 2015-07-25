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
//ùùùùùùùùùùCopyrightù(c)ù1994,ù1995ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùù Microsoft Windows '95 Version ùùùùùùùùùùùùùùùùùùùùùùù
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
// Created by Tim Little & Chuck Walbourn
//
// esdrface.cpp
//
//      Contains the C++ implementation of the clip/draw function for
//      faces.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define ES_MAX_VERTS 9

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_clipdraw_face                                                       ³
//                                                                          ³
// Draws a face using the current object information in the context.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_clipdraw_face(ulong ind, int doclip, VngoRect *damage_rect,int dobfcul)
{
    ulong               i;
    ulong               edge_count;
    long                x, y;
    Flx16               tx, ty;
    dword               cflags;
    dword               zflags=0;
    dword               r;
    dword               lclip_flags=0;
    dword               level;
    EschFace            *face;
    EschCamera          *cam;
    EschTexture         *texture;
    VngoVport           *vp;
    static VngoPoint    *vpt[ES_MAX_VERTS];
    static dword        *vflags[ES_MAX_VERTS];
    static dword        flags[ES_MAX_VERTS];
    static VngoPoint    vpoly[ES_MAX_VERTS];
    static VngoPoint    tvpoly[ES_MAX_VERTS];

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("esch_clipdraw_face needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

//ÄÄÄ Setup values/quick references
    face=&EschCurrent->faces[ind];

    cflags = cam->flags;

    vpt[0] = &EschCurrent->vpoints[face->a];
    vpt[1] = &EschCurrent->vpoints[face->b];
    vpt[2] = &EschCurrent->vpoints[face->c];

    vpt[0]->u = face->u[0].flx;
    vpt[0]->v = face->v[0].flx;
                      
    vpt[1]->u = face->u[1].flx;
    vpt[1]->v = face->v[1].flx;
                      
    vpt[2]->u = face->u[2].flx;
    vpt[2]->v = face->v[2].flx;

    vflags[0]=&EschCurrent->vflags[face->a];
    vflags[1]=&EschCurrent->vflags[face->b];
    vflags[2]=&EschCurrent->vflags[face->c];

    edge_count = 3;

    //ÄÄÄ Figure out shade level (take minimum of shade levels for camera/face)

    level = cflags & face->flags;

//ÄÄÄ Clip if needed

    if (doclip)
    {
//ÄÄÄ Clip against view volume
        Flx16 yon = cam->yon;
        Flx16 hither = cam->hither;

        // Near/far clipping
        long    z;
        dword   tzflags=0;
        for (i=0;i < edge_count; i++)
        {
            assertMyth("esch_clipdraw_face expects all shades in 0-255 range",
                       vpt[i]->shade <= 255);

            z = vpt[i]->wz;
            if (z < hither.flx)
                zflags++;

            if (z > yon.flx)
                tzflags++;
        }

        if ((zflags >= edge_count) || (tzflags >= edge_count))
        {
            return;
        }
        zflags += tzflags;
        if (zflags)
        {   
            for (ulong qc=0;qc < edge_count;qc++)
            {
                // get all of the vertex information into work space.
                tvpoly[qc] = *vpt[qc];
            }
            // This will be a call to Z clip the polygon.
            esch_zclip_poly(hither,yon,tvpoly,&edge_count);
            for (qc=0; qc < edge_count; qc++)
            {
                // Now use the work vertices for the rest of this polygon.
                vpt[qc] = &tvpoly[qc];

                // point to empty flags since we are clipping in Z.
                vflags[qc] = &flags[qc];
                flags[qc]=0;
            }
        }

#ifdef DEBUG
        for (i=0; i < edge_count; i++)
        {
            assertMyth("esch_clipdraw_face Z-clip failed",
                       vpt[i]->wz >= hither.flx);
            assertMyth("esch_clipdraw_face Z-clip failed",
                       vpt[i]->wz <= yon.flx);
        }
#endif

        // Left/right/top/bottom plane clipping

        for(i=0; i < edge_count; i++)
        {
        
            if (*vflags[i] & ESCH_VVERT_PROJECTED)
            {
                lclip_flags |= ((*vflags[i] & 0xf0) >> 4) << (4*i);
            }
            else
            {
                tx.flx = flx_16mul16( Flx16(vpt[i]->wz,1) , cam->xsize ).flx;
                ty.flx = flx_16mul16( Flx16(vpt[i]->wz,1) , cam->ysize ).flx;

                x = vpt[i]->wx;

                if (x < -tx.flx)
                {
                    lclip_flags |= 0x1 << (4*i);
                    *vflags[i] |= ESCH_VVERT_CLIPLEFT;
                }
                else if (x > tx.flx)
                {
                    lclip_flags |= 0x2 << (4*i);
                    *vflags[i] |= ESCH_VVERT_CLIPRIGHT;
                }

                y = vpt[i]->wy;

                if (y < -ty.flx)
                {
                    lclip_flags |= 0x4 << (4*i);
                    *vflags[i] |= ESCH_VVERT_CLIPTOP;
                }
                else if (y > ty.flx)
                {
                    lclip_flags |= 0x8 << (4*i);
                    *vflags[i] |= ESCH_VVERT_CLIPBOTTOM;
                }
            }
        }

    }
    
    // if any of the bits are set, then it is off the screen.
    i=0;
    r=0xffffffff;
    for(dword t=lclip_flags; i < edge_count; i++)
    {
        r &= (t & 0xf);
        t >>= 4;
    }
    if (r)
        return;

//ÄÄÄ Setup local copies of frequently used data
    assertMyth("esch_clipdraw_face expects current context's camera to have a viewport",
               cam->vport != NULL);
    vp=cam->vport;

    Flx16 height = (vp->get_vbuff()->height >> 1);
    Flx16 width = (vp->get_vbuff()->width >> 1);

    tx = cam->xscalar;
    ty = cam->yscalar;

//ÄÄÄ Project vertecies
    for(i=0; i < edge_count; i++)
    {
        if (!(*vflags[i] & ESCH_VVERT_PROJECTED))
        {
        
            Flx16 z= Flx16(vpt[i]->wz,1);
        
            vpt[i]->x = (flx_muldiv(Flx16(vpt[i]->wx,1),tx,z).flx + width.flx)>>16;
        
            vpt[i]->y = (height.flx - flx_muldiv(Flx16(vpt[i]->wy,1),ty,z).flx)>>16;
        
            if (cflags & ESCH_CAM_PERSPECTIVE)
            {
                vpt[i]->w = flx_recip230(z);
            }
        
            *vflags[i] |= ESCH_VVERT_PROJECTED;
        }
    }

    for(i=0; i < edge_count; i++)
    {
        vpoly[i]=*vpt[i];

        vpoly[i].clr = EschCurrent->vpoints[face->a].clr;
        if (!(level & ESCH_CAM_SHADE_SMOOTH))
            vpoly[i].shade = EschCurrent->vpoints[face->a].shade;
    }

//ÄÄÄ Back Face Cull  if needed.
    if (dobfcul)
    {
        if (!esch_rotate_check(edge_count,vpoly))
            return;
    }
                  
//ÄÄÄ Draw triangle
    assertMyth ("esch_clipdraw_face has invalid polygon before clipping",
                (edge_count > 2) && (edge_count < ES_MAX_VERTS));

    // If any local clip flags exist, then we need to clip the polygon
    // and move its points into the array to be sent to the scan converter.
    if (lclip_flags)   
    {                  
       esch_clip_poly(vp->get_vbuff(),vpoly,&edge_count);
    }
    if ((edge_count < 3) || (edge_count > ES_MAX_VERTS))
    {
        return;
    }
    assertMyth ("esch_clipdraw_face has invalid polygon post clipping",
                (edge_count > 2) && (edge_count < ES_MAX_VERTS));

    //ÄÄÄ Scale Z between hither & yon and calc damage_rect.
    for (i=0;i < edge_count;i++)
    {
       // scale Z.
       vpoly[i].z = flx_16mul16(Flx16(vpoly[i].wz,1),cam->z_factor).flx << 1;

       if (damage_rect != NULL)
       {
           // Find the growing bounding box of this mesh.
           if (damage_rect->x > vpoly[i].x)
               damage_rect->x = vpoly[i].x;
           if (damage_rect->y > vpoly[i].y)
               damage_rect->y = vpoly[i].y;

           if (damage_rect->dx < vpoly[i].x)
               damage_rect->dx = vpoly[i].x;
           if (damage_rect->dy < vpoly[i].y)
               damage_rect->dy = vpoly[i].y;
       }
       if (vpoly[i].x < 0)
       {
           assertMyth("esch_clipdraw_face found out-of-range point",
                      vpoly[i].x >= 0);
           vpoly[i].x = 0;
       }
       if (vpoly[i].y < 0)
       {
           assertMyth("esch_clipdraw_face found out-of-range point",
                      vpoly[i].y >= 0);
           vpoly[i].y = 0;
       }
       if (vpoly[i].x >= cam->vport->vbuff.width)
       {
           assertMyth("esch_clipdraw_face found out-of-range point",
                      vpoly[i].x < cam->vport->vbuff.width);
           vpoly[i].x = cam->vport->vbuff.width;
       }
       if (vpoly[i].y >= cam->vport->vbuff.height)
       {
           assertMyth("esch_clipdraw_face found out-of-range point",
                      vpoly[i].y < cam->vport->vbuff.height);
           vpoly[i].x = cam->vport->vbuff.height;
       }
    }

    //ÄÄÄ Need to draw with Gouraud-shading
    if (level & ESCH_CAM_SHADE_SMOOTH)
    {
        if (level & ESCH_CAM_TEXTURED)
        {
            assertMyth("esch_clipdraw_face needs textures in current context",
                       EschCurrent->txts);

            texture=&EschCurrent->txts[face->txt-1];

            texture->lock();

            if (level & ESCH_CAM_PERSPECTIVE)
            {
                vp->gtpoly_persp(edge_count,vpoly,texture->ptr);
            }
            else
            {
                vp->gtpoly(edge_count,vpoly,texture->ptr);
            }
            texture->unlock();
        }
        else
        {
            if (level & ESCH_CAM_PERSPECTIVE)
            {
                vp->gpoly_persp(edge_count,vpoly);
            }
            else
            {
                vp->gpoly(edge_count,vpoly);
            }
        }

        return;
    }

    //ÄÄÄ Draw with single-color polygon
    else if (level & (ESCH_CAM_SHADE_FLAT | ESCH_CAM_SHADE_SOLID))
    {
        if (level & ESCH_CAM_TEXTURED)
        {
            assertMyth("esch_clipdraw_face needs textures in current context",
                       EschCurrent->txts);

            texture=&EschCurrent->txts[face->txt-1];

            texture->lock();

            if (level & ESCH_CAM_PERSPECTIVE)
            {
                vp->tpoly_persp(edge_count,vpoly,texture->ptr);
            }
            else
            {
                vp->tpoly(edge_count,vpoly,texture->ptr);
            }
            texture->unlock();
        }
        else
        {
            vp->poly(edge_count,vpoly);
        }

        return;
    }

    //ÄÄÄ Draw wireframe
    if (!lclip_flags & !zflags)
    {
        if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_ABLINE))
            vp->line(&vpoly[0],&vpoly[1]);

        if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_BCLINE))
            vp->line(&vpoly[1],&vpoly[2]);

        if ((cflags & ESCH_CAM_SHOW_ALL_LINES) || (face->flags & ESCH_FACE_CALINE))
            vp->line(&vpoly[2],&vpoly[0]);
    }
    else
    {
        for (i=0;i < edge_count-1;i++)
        {
            vp->line(&vpoly[i],&vpoly[i+1]);
        }
        vp->line(&vpoly[i],&vpoly[0]);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_zclip_poly                                                          ³
//                                                                          ³
// Performs the polygon clipping to the near and far planes.                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_zclip_poly(Flx16 hither,
                                Flx16 yon,
                                VngoPoint *points, 
                                ulong *n_vertices)
{
   static VngoPoint  work_pts[ES_MAX_VERTS];
   VngoPoint         *work, *first, *second;
   int               vcount;
   ulong             npoints,s,out;

   vcount = *n_vertices;
   npoints = vcount;

   //
   // Clip hither
   //

   second = points;
   first  = &points[npoints-1];

   work = work_pts;
   out  = 0;

   for (s=0; s < npoints; s++, second++)
   {

      if (first->wz >= hither.flx)
      {
         *work = *first;
         work++;
         out++;
      }

      if ((first->wz > hither.flx && second->wz < hither.flx) ||
          (first->wz < hither.flx && second->wz > hither.flx))
      {
         esch_clip_z_line(hither.flx, second, first, work);
         work++;
         out++;
      }

      first = second;
   }

   //
   // Clip yon
   //

   second = work_pts;
   first  = work-1;

   work     = points;
   npoints = out;
   out      = 0;

   for (s=0; s < npoints; s++, second++)
   {

      if (first->wz <= yon.flx)
      {
         *work = *first;
         work++;
         out++;
      }

      if ((first->wz < yon.flx && second->wz > yon.flx) ||
          (first->wz > yon.flx && second->wz < yon.flx))
      {
         esch_clip_z_line(yon.flx, second, first, work);
         work++;
		 out++;
      }

      first = second;
   }
   *n_vertices = out;
    
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_clip_poly                                                           ³
//                                                                          ³
// Performs the polygon clipping.                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_clip_poly(VngoVbuffer     *vport,
                               VngoPoint      *points, 
                               ulong      *n_vertices)
{
   static VngoPoint  work_pts[8];
   VngoPoint         *work, *first, *second;
   int               vcount;
   ulong             npoints,s,out;
   long              top, bottom, left, right;

   vcount = *n_vertices;
   npoints = vcount;

   top    = vport->top;
   bottom = vport->height-1;
   left   = vport->left;
   right  = vport->width-1;


   //
   // Clip right
   //

   second = points;
   first  = &points[npoints-1];

   work = work_pts;
   out  = 0;

   for (s=0; s < npoints; s++, second++)
   {
      if (first->x <= right)
      {
         *work = *first;
         work++;
         out++;
      }

      if ((first->x < right && second->x > right) ||
          (first->x > right && second->x < right))
      {
         esch_clip_x_line(right, second, first, work);
         work++;
         out++;
      }

      first = second;
   }

   //
   // Clip top
   //

   second = work_pts;
   first  = work-1;

   work     = points;
   npoints = out;
   out      = 0;

   for (s=0; s < npoints; s++, second++)
   {
      if (first->y >= top)
      {
         *work = *first;
         work++;
         out++;
      }

      if ((first->y < top && second->y > top) ||
          (first->y > top && second->y < top))
      {
         esch_clip_y_line(top, second, first, work);
         work++;
		 out++;
      }

      first = second;
   }

   //
   // Clip left
   //

   second = points;
   first  = work-1;

   work     = work_pts;
   npoints = out;
   out      = 0;

   for (s=0; s < npoints; s++, second++)
   {
      if (first->x >= left)
      {
         *work = *first;
         work++;
         out++;
      }

      if ((first->x < left && second->x > left) ||
          (first->x > left && second->x < left))
      {
         esch_clip_x_line(left, second, first, work);
         work++;
         out++;
      }

      first = second;
   }

   //
   // Clip bottom
   //

   second = work_pts;
   first  = work-1;

   work     = points;
   npoints = out;
   out      = 0;

   for (s=0; s < npoints; s++, second++)
   {
      if (first->y <= bottom)
      {
         *work = *first;
         work++;
         out++;
      }

      if ((first->y < bottom && second->y > bottom) ||
          (first->y > bottom && second->y < bottom))
      {
         esch_clip_y_line(bottom, second, first, work);
         work++;
         out++;
      }

      first = second;
   }

   *n_vertices = out;
}


//°±² End of module - esdrface.cpp ²±°

