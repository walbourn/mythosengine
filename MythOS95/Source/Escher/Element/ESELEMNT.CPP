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
// Created by Tim Little & Chuck Walbourn
//
// eselemnt.cpp
//
// Contains the implementation of the element sort area routines.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

ulong EschElementDepth=0;               // Depth of current element tree
ulong EschElementSize=0;                // Size of current element tree

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° EschElement °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschElement - insert                                                     ³
//                                                                          ³
// Inserts the element into the binary tree.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschElement::insert()
{
    assertMyth("EschElement::insert() needs sort area",
               EschSysInstance != 0 && EschSysInstance->sspace != 0);

    EschElement *elm = EschSysInstance->sroot;

//ÄÄÄ Check for empty tree
    if (!elm)
    {
        EschSysInstance->sroot = this;
        return;
    }

//ÄÄÄ Walk down until we can insert as left or right leaf
    ulong depth=1;
    for(depth=1;; depth++)
    {
        //ÄÄÄ Insert by maximum z
        if (maxz <= elm->maxz)
        {
            if (!elm->left)                     //ÄÄÄ Closer
            {
                elm->left = this;
                break;
            }
            elm = elm->left;
        }
        else
        {
            if (!elm->right)                    //ÄÄÄ Further
            {
                elm->right = this;
                break;
            }
            elm = elm->right;
        }
    }

//ÄÄÄ Update stats
    if (depth > EschElementDepth)
        EschElementDepth = depth;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                            °°° Protected °°°                             ³
// EschElement - draw_tree                                                  ³
//                                                                          ³
// Draws recursively using Painter's algorithm (furtherest to closest)      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschElement::draw_tree(EschElement *elm)
{
    assertMyth("EschElement::draw_tree() needs valid input", elm != 0);

    if (elm->right)
        draw_tree(elm->right);

    elm->draw();

    if (elm->left)
        draw_tree(elm->left);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschElement - flush                                                      ³
//                                                                          ³
// Draws any pending element entries and clears the arena.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschElement::flush()
{
    assertMyth("EschElement::flush() needs sort area",
               EschSysInstance != 0 && EschSysInstance->sspace != 0);

//ÄÄÄ Perform draw of any pending elements
    if (EschSysInstance->sroot)
        draw_tree(EschSysInstance->sroot);

//ÄÄÄ Clear sort area
    ivory_arena_clear(EschSysInstance->sspace);
    EschSysInstance->sroot=0;

//ÄÄÄ Update stats
    if (EschElementDepth > EschSysInstance->sspace_mdepth)
        EschSysInstance->sspace_mdepth = EschElementDepth;

    if (EschElementSize > EschSysInstance->sspace_mbytes)
        EschSysInstance->sspace_mbytes = EschElementSize;

    EschElementDepth=0;
    EschElementSize=0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                            °°° Protected °°°                             ³
// EschElement - link_tree                                                  ³
//                                                                          ³
// Creates a linked-list from the tree (destroying the tree).               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschElement *EschElement::link_tree(EschElement *elm)
{
    assertMyth("EschElement::draw_tree() needs valid input", elm != 0);

    EschElement *right = (elm->right) ? link_tree(elm->right) : 0;
    EschElement *left = (elm->left) ? link_tree(elm->left) : 0;

    if (right)
    {
        EschElement *e=NULL;
        for(e = right; e->right != 0; e = e->right);

        e->right = elm;
        elm->left = e;

        elm->right = left;
        if (left)
            left->left = elm;

        return right;
    }
    else if (left)
    {
        elm->left = 0;
        elm->right = left;
        if (left)
            left->left = elm;

        return elm;
    }
    else
    {
        elm->left = elm->right = 0;
        return elm;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschElement - flush_truesort                                             ³
//                                                                          ³
// Draws any pending element entries using a more complex sort and clears   ³
// the arena.                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschElement::flush_truesort()
{
    assertMyth("EschElement::flush_truesort() needs sort area",
               EschSysInstance != 0 && EschSysInstance->sspace != 0);

//ÄÄÄ Perform draw of any pending elements
    if (EschSysInstance->sroot)
    {
        //ÄÄÄ Create linked-list of elements sorted by Z-max
        //ÄÄÄ with right as next, left as prev.
        EschElement *head = link_tree(EschSysInstance->sroot);
        assert(head != 0);

        //ÄÄÄ Start from end of list
        EschElement *elm=NULL;
        for(elm=head; elm->right != 0; elm = elm->right);

        //ÄÄÄ Process each polygon from back to front
        while(elm != 0)
        {
            // for now just draw...
            elm->draw();
        }
    }

//ÄÄÄ Clear sort area
    ivory_arena_clear(EschSysInstance->sspace);
    EschSysInstance->sroot=0;

//ÄÄÄ Update stats
    if (EschElementDepth > EschSysInstance->sspace_mdepth)
        EschSysInstance->sspace_mdepth = EschElementDepth;

    if (EschElementSize > EschSysInstance->sspace_mbytes)
        EschSysInstance->sspace_mbytes = EschElementSize;

    EschElementDepth=0;
    EschElementSize=0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° EschPixelElement °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPixelElement - draw                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPixelElement::draw()
{
    assertMyth("EschPixelElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPixelElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    EschCurrent->camera->vport->pixel(&pnt);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPixelElement - prepare_test                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPixelElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPixelElement::prepare_test() needs point", pt != 0);

    // Test point is point itself
    pt->x = pnt.x;
    pt->y = pnt.y;
    pt->z = pnt.z;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPixelElement - perform_test                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL EschPixelElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPixelElement::perform_test() needs point", pt != 0);

    // Test point is point itself
    return ((pnt.z < pt->z) ? TRUE : FALSE);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° EschLineElement °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschLineElement - draw                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschLineElement::draw()
{
    assertMyth("EschLineElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschLineElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

//!!! Need to change clipdraw_line to actually clip! so we can use line

    EschCurrent->camera->vport->clip_line(&pnt1, &pnt2);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschLineElement - prepare_test                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschLineElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschLineElement::prepare_test() needs point", pt != 0);

    // Test point is midpoint
    pt->x = pnt1.x + (pnt2.x - pnt1.x) / 2;
    pt->y = pnt1.y + (pnt2.y - pnt1.y) / 2;
    pt->z = pnt1.z + (pnt2.z - pnt1.z) / 2;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschLineElement - perform_test                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL EschLineElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschLineElement::perform_test() needs point", pt != 0);

    // Test point is midpoint
    float z = pnt1.z + ((pnt2.z - pnt1.z) / 2);

    return ((z < pt->z) ? TRUE : FALSE);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° EschPolyElement °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyElement - draw                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPolyElement::draw()
{
    assertMyth("EschPolyElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPolyElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    switch (typ)
    {
        case ESCH_ELMNT_POLY:
            EschCurrent->camera->vport->poly(count,vpoly);
            return;

        case ESCH_ELMNT_GPOLY:
            EschCurrent->camera->vport->gpoly(count,vpoly);
            return;

        case ESCH_ELMNT_GPOLY_PERSP:
            EschCurrent->camera->vport->gpoly_persp(count,vpoly);
            return;

        default:
            assertMyth("EschPolyElement::draw() found unknown typ",
                       0);
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyElement - prepare_test                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPolyElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyElement - perform_test                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL EschPolyElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPolyElement::perform_test() needs point and valid count",
               pt != 0 && (count >= 3));

    // Make a vector from first vertex to test point
    EschVector v1(pt->x - vpoly[0].x,
                  pt->y - vpoly[0].y,
                  pt->z - vpoly[0].z);

    // Create plane normal by crossing two endpoints
    EschVector v2 = EschVector(vpoly[1].x - vpoly[0].x,
                               vpoly[1].y - vpoly[0].y,
                               vpoly[1].z - vpoly[0].z)
                    CROSS EschVector(vpoly[2].x - vpoly[0].x,
                                     vpoly[2].y - vpoly[0].y,
                                     vpoly[2].z - vpoly[0].z);

    // Determine closeness by sign of dot product
    return (((v1 DOT v2) < 0) ? TRUE : FALSE);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° EschPolyAElement °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyAElement - draw                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPolyAElement::draw()
{
    assertMyth("EschPolyAElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPolyAElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    switch (typ)
    {
        case ESCH_ELMNT_POLY_A:
            EschCurrent->camera->vport->poly_a(count,vpoly,alpha);
            return;

        case ESCH_ELMNT_GPOLY_A:
            EschCurrent->camera->vport->gpoly_a(count,vpoly,alpha);
            return;

        case ESCH_ELMNT_GPOLY_PERSP_A:
            EschCurrent->camera->vport->gpoly_persp_a(count,vpoly,alpha);
            return;

        default:
            assertMyth("EschPolyAElement::draw() found unknown typ",
                       0);
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyAElement - prepare_test                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPolyAElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyAElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyAElement - perform_test                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL EschPolyAElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPolyAElement::perform_test() needs point and valid count",
               pt != 0 && (count >= 3));

    // Make a vector from first vertex to test point
    EschVector v1(pt->x - vpoly[0].x,
                  pt->y - vpoly[0].y,
                  pt->z - vpoly[0].z);

    // Create plane normal by crossing two endpoints
    EschVector v2 = EschVector(vpoly[1].x - vpoly[0].x,
                               vpoly[1].y - vpoly[0].y,
                               vpoly[1].z - vpoly[0].z)
                    CROSS EschVector(vpoly[2].x - vpoly[0].x,
                                     vpoly[2].y - vpoly[0].y,
                                     vpoly[2].z - vpoly[0].z);

    // Determine closeness by sign of dot product
    return (((v1 DOT v2) < 0) ? TRUE : FALSE);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° EschPolyTxtElement °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyTxtElement - draw                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPolyTxtElement::draw()
{
    assertMyth("EschPolyTxtElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPolyTxtElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    assertMyth("EschPolyTxtElement::draw() needs texture", txt != 0);

    txt->lock();

    switch (typ)
    {
        case ESCH_ELMNT_TXTPOLY:
            EschCurrent->camera->vport->tpoly(count,vpoly,txt->ptr);
            break;

        case ESCH_ELMNT_TXTPOLY_PERSP:
            EschCurrent->camera->vport->tpoly_persp(count,vpoly,txt->ptr);
            break;

        case ESCH_ELMNT_GTXTPOLY:
            EschCurrent->camera->vport->gtpoly(count,vpoly,txt->ptr);
            break;

        case ESCH_ELMNT_GTXTPOLY_PERSP:
            EschCurrent->camera->vport->gtpoly_persp(count,vpoly,txt->ptr);
            break;

        default:
            assertMyth("EschPolyTxtElement::draw() found unknown typ",
                       0);
            break;
    }

    txt->unlock();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyTxtElement - prepare_test                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPolyTxtElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyTxtElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyTxtElement - perform_test                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL EschPolyTxtElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPolyTxtElement::perform_test() needs point and valid count",
               pt != 0 && (count >= 3));

    // Make a vector from first vertex to test point
    EschVector v1(pt->x - vpoly[0].x,
                  pt->y - vpoly[0].y,
                  pt->z - vpoly[0].z);

    // Create plane normal by crossing two endpoints
    EschVector v2 = EschVector(vpoly[1].x - vpoly[0].x,
                               vpoly[1].y - vpoly[0].y,
                               vpoly[1].z - vpoly[0].z)
                    CROSS EschVector(vpoly[2].x - vpoly[0].x,
                                     vpoly[2].y - vpoly[0].y,
                                     vpoly[2].z - vpoly[0].z);

    // Determine closeness by sign of dot product
    return (((v1 DOT v2) < 0) ? TRUE : FALSE);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° EschPolyTxtAElement °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyTxtAElement - draw                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPolyTxtAElement::draw()
{
    assertMyth("EschPolyTxtAElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPolyTxtAElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    assertMyth("EschPolyTxtAElement::draw() needs texture", txt != 0);

    txt->lock();

    switch (typ)
    {
        case ESCH_ELMNT_TXTPOLY_A:
            EschCurrent->camera->vport->tpoly_a(count,vpoly,
                                                txt->ptr,alpha);
            break;

        case ESCH_ELMNT_TXTPOLY_PERSP_A:
            EschCurrent->camera->vport->tpoly_persp_a(count,vpoly,
                                                      txt->ptr,alpha);
            break;

        case ESCH_ELMNT_GTXTPOLY_A:
            EschCurrent->camera->vport->gtpoly_a(count,vpoly,
                                                 txt->ptr,alpha);
            break;

        case ESCH_ELMNT_GTXTPOLY_PERSP_A:
            EschCurrent->camera->vport->gtpoly_persp_a(count,vpoly,
                                                       txt->ptr,alpha);
            break;

        default:
            assertMyth("EschPolyTxtAElement::draw() found unknown typ",
                       0);
            break;
    }

    txt->unlock();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyTxtAElement - prepare_test                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschPolyTxtAElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyTxtAElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPolyTxtAElement - perform_test                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL EschPolyTxtAElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPolyTxtAElement::perform_test() needs point and valid count",
               pt != 0 && (count >= 3));

    // Make a vector from first vertex to test point
    EschVector v1(pt->x - vpoly[0].x,
                  pt->y - vpoly[0].y,
                  pt->z - vpoly[0].z);

    // Create plane normal by crossing two endpoints
    EschVector v2 = EschVector(vpoly[1].x - vpoly[0].x,
                               vpoly[1].y - vpoly[0].y,
                               vpoly[1].z - vpoly[0].z)
                    CROSS EschVector(vpoly[2].x - vpoly[0].x,
                                     vpoly[2].y - vpoly[0].y,
                                     vpoly[2].z - vpoly[0].z);

    // Determine closeness by sign of dot product
    return (((v1 DOT v2) < 0) ? TRUE : FALSE);
}

//°±² End of module - eselemnt.cpp ²±°
