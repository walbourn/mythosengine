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
// Created by Chuck Walbourn
//
// esopartn.cpp
//
// Contains the code for the EschOctTreePartition class which implements
// a 3D octtree partitioning scheme with adaptive subdivision of space.
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
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - Constructor                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschOctTreePartition::EschOctTreePartition() :
    EschPartition(),
    root(0),
    global(0),
    maxdepth(0),
    maxcount(1)
{
    dtyp=ESCH_DRWT_PRTN_OCT;
}

EschOctTreePartition::EschOctTreePartition(const EschPoint *o,
                                           float w, float h, float d) :
    EschPartition(),
    root(0),
    global(0),
    maxdepth(0),
    maxcount(1)
{
    dtyp=ESCH_DRWT_PRTN_OCT;

    esch_error_codes err = init(o,w,h,d);
    assertMyth("EschOctTreePartition failed init", err == ESCH_ERR_NONE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - Destructor                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschOctTreePartition::~EschOctTreePartition()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - find                                              ³
//                                                                          ³
// Performs a search for a drawable with a given name.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschDrawable *EschOctTreePartition::find(const char *dname) const
{
    if (!strncmp(dname,name,ESCH_MAX_NAME))
        return (EschDrawable*)this;

//ÄÄÄ Check octtree
    if (root)
    {
        EschDrawable *drw = walk_find(root,dname);
        if (drw)
            return drw;
    }

//ÄÄÄ Check global list
    for(EschPartitionList *ptr=global; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::find found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        assertMyth("EschOctTreePartition::find found entry without item",
                    ptr->item != 0);

        EschDrawable *drw = ptr->item->find(dname);
        if (drw)
            return drw;
    }

    if (!inext)
        return 0;

    return inext->find(dname);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine
EschDrawable *EschOctTreePartition::walk_find(EschOctTreeNode *node,
                                              const char *dname) const
{
    if (!node)
        return 0;

//ÄÄÄ Check draw list
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_find found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        assertMyth("EschOctTreePartition::walk_find found entry without item",
                   ptr->item != 0);

        EschDrawable *drw = ptr->item->find(dname);
        if (drw)
            return drw;
    }

//ÄÄÄ Check child octants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_find found corrupt links",
                       node != node->parent && node != node->q[i]);

            EschDrawable *drw=walk_find(node->q[i], dname);
            if (drw)
                return drw;
        }
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - draw                                              ³
//                                                                          ³
// Performs a draw for drawables within the partitioning.                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschOctTreePartition::draw()
{
//ÄÄÄ Draw octtree
    if (root)
    {
        if (flags & ESCH_PARTN_OFF)
        {
            walk_draw_dumb(root);
        }
        else
        {
            EschPoint   pos;
            float       tx, ty;
            EschCamera  *cam;
            dword       cflags;

            //ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
            assertMyth("EschOctTreePartition::draw needs camera in current context",
                       EschCurrent != NULL && EschCurrent->camera != NULL);

            cam=EschCurrent->camera;

            cflags = cam->flags;

            assertMyth("EschOctTreePartition::draw needs a viewport in current context's camera",
                       cam->vport != NULL);

            //ÄÄÄ Transform view volume into world coords and form min/maxs

            //ÄÄÄ Camera Position
            cam->get_position(&pos);

            EschBoxExtents exts(&pos,&pos);

            //ÄÄÄ Far points
            if (cam->flags & ESCH_CAM_ORTHO)
            {
                tx = cam->xsize;
                ty = cam->ysize;
            }
            else
            {
                tx = cam->yon * cam->xsize;
                ty = cam->yon * cam->ysize;
            }

            // -tx, ty
            pos.x = -tx;
            pos.y = ty;
            pos.z = cam->yon;
            pos.transform(&cam->eye.orient);
            if (exts.mins[0] > pos.x)  exts.mins[0] = pos.x;
            if (exts.mins[1] > pos.y)  exts.mins[1] = pos.y;
            if (exts.mins[2] > pos.z)  exts.mins[2] = pos.z;
            if (exts.maxs[0] < pos.x)  exts.maxs[0] = pos.x;
            if (exts.maxs[1] < pos.y)  exts.maxs[1] = pos.y;
            if (exts.maxs[2] < pos.z)  exts.maxs[2] = pos.z;

            // tx, ty
            pos.x = tx;
            pos.y = ty;
            pos.z = cam->yon;
            pos.transform(&cam->eye.orient);
            if (exts.mins[0] > pos.x)  exts.mins[0] = pos.x;
            if (exts.mins[1] > pos.y)  exts.mins[1] = pos.y;
            if (exts.mins[2] > pos.z)  exts.mins[2] = pos.z;
            if (exts.maxs[0] < pos.x)  exts.maxs[0] = pos.x;
            if (exts.maxs[1] < pos.y)  exts.maxs[1] = pos.y;
            if (exts.maxs[2] < pos.z)  exts.maxs[2] = pos.z;

            // -tx, -ty
            pos.x = -tx;
            pos.y = -ty;
            pos.z = cam->yon;
            pos.transform(&cam->eye.orient);
            if (exts.mins[0] > pos.x)  exts.mins[0] = pos.x;
            if (exts.mins[1] > pos.y)  exts.mins[1] = pos.y;
            if (exts.mins[2] > pos.z)  exts.mins[2] = pos.z;
            if (exts.maxs[0] < pos.x)  exts.maxs[0] = pos.x;
            if (exts.maxs[1] < pos.y)  exts.maxs[1] = pos.y;
            if (exts.maxs[2] < pos.z)  exts.maxs[2] = pos.z;

            // tx, -ty
            pos.x = tx;
            pos.y = -ty;
            pos.z = cam->yon;
            pos.transform(&cam->eye.orient);
            if (exts.mins[0] > pos.x)  exts.mins[0] = pos.x;
            if (exts.mins[1] > pos.y)  exts.mins[1] = pos.y;
            if (exts.mins[2] > pos.z)  exts.mins[2] = pos.z;
            if (exts.maxs[0] < pos.x)  exts.maxs[0] = pos.x;
            if (exts.maxs[1] < pos.y)  exts.maxs[1] = pos.y;
            if (exts.maxs[2] < pos.z)  exts.maxs[2] = pos.z;

            // exts is now bounding area

            walk_draw(root,&exts);
        }
    }

//ÄÄÄ Draw global list
    for(EschPartitionList *ptr=global; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::draw found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::draw found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIP))
            item->draw();
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine for dumb walk
void EschOctTreePartition::walk_draw_dumb(EschOctTreeNode *node)
{
    if (!node)
        return;

//ÄÄÄ Draw list
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_draw_dumb found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::walk_draw_dumb found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIP))
            item->draw();
    }

//ÄÄÄ Draw child octants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_draw_dumb found corrupt links",
                        node != node->parent && node != node->q[i]);

            walk_draw_dumb(node->q[i]);
        }
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine for smart walk
void EschOctTreePartition::walk_draw(EschOctTreeNode *node,
                                     EschBoxExtents *exts)
{
    if (!node)
        return;

//ÄÄÄ See if bound-volume intersects node region (we should be able to use
//ÄÄÄ actual frustrum instead of bounding volume to check for visible regions)
    if (node->x1 > exts->maxs[0]
        || node->y1 > exts->maxs[1]
        || node->z1 > exts->maxs[2]
        || node->x2 < exts->mins[0]
        || node->y2 < exts->mins[1]
        || node->z2 < exts->mins[2])
        return;

//ÄÄÄ Draw list
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_draw found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::walk_draw found entry without item",
                   item != 0);

        if (!(item->flags & ESCH_DRW_SKIP))
            item->draw();
    }

//ÄÄÄ Draw child octants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_draw found corrupt links",
                       node != node->parent && node != node->q[i]);

            walk_draw(node->q[i],exts);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - pick                                              ³
//                                                                          ³
// Performs a pick for drawables in the partitioning.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschOctTreePartition::pick(EschPicking *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ We want to intercept test self case only...
    if (data->flags & ESCH_PICK_TESTSELF)
    {
        //ÄÄÄ Check octtree
        if (root)
        {
            if (flags & ESCH_PARTN_OFF)
            {
                esch_error_codes err = walk_pick_dumb(root,data);
                if (err)
                    return err;
            }
            else
            {
                esch_error_codes err = walk_pick(root,data);
                if (err)
                    return err;
            }
        }

        //ÄÄÄ Check global list
        for(EschPartitionList *ptr=global; ptr != 0; ptr = ptr->next)
        {
            assertMyth("EschOctTreePartition::pick found corrupt links",
                       ptr != ptr->next && ptr != ptr->prev);

            EschDrawable *item = ptr->item;

            assertMyth("EschOctTreePartition::pick found entry without item",
                        item != 0);

            if (!(item->flags & ESCH_DRW_SKIPTEST))
            {
                esch_error_codes err = item->pick(data);
                if (err)
                    return err;
            }
        }

        return ESCH_ERR_NONE;
    }

//ÄÄÄ Otherwise use base implementation
    return EschDrawable::pick(data);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine for dumb walk
esch_error_codes EschOctTreePartition::walk_pick_dumb(EschOctTreeNode *node,
                                                      EschPicking *data) const
{
    if (!node)
        return ESCH_ERR_NONE;

//ÄÄÄ Check drawlist
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_pick_dumb found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::walk_pick_dumb found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIPTEST))
        {
            esch_error_codes err = item->pick(data);
            if (err)
                return err;
        }
    }

//ÄÄÄ Check child octants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_pick_dumb found corrupt links",
                       node != node->parent && node != node->q[i]);

            esch_error_codes err = walk_pick_dumb(node->q[i],data);
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine for smart walk
esch_error_codes EschOctTreePartition::walk_pick(EschOctTreeNode *node,
                                                 EschPicking *data) const
{
    if (!node)
        return ESCH_ERR_NONE;

//ÄÄÄ See if node hit by ray
    int     inside = 1;
    enum
    {
        RIGHT=0,
        LEFT=1,
        MIDDLE=2
    }       quad[3];
    float   candidate[3];
    float   mins[3] = { node->x1, node->y1, node->z1 };
    float   maxs[3] = { node->x2, node->y2, node->z2 };
    float   origin[3] = { data->start.x, data->start.y, data->start.z };
    float   dir[3] = { data->direction.i, data->direction.j, data->direction.k };

    //ÄÄÄ Find candidate planes
    for(int i=0; i < 3; i++)
    {
        if (origin[i] < mins[i])
        {
            quad[i] = LEFT;
            if (dir[i] <= 0)
                return ESCH_ERR_NONE;

            candidate[i] = mins[i];
            inside = 0;
        }
        else if (origin[i] > maxs[i])
        {
            quad[i] = RIGHT;
            if (dir[i] >= 0)
                return ESCH_ERR_NONE;

            candidate[i] = maxs[i];
            inside = 0;
        }
        else
        {
            quad[i] = MIDDLE;
        }
    }

    //ÄÄÄ If we are inside, we definetely need to check node
    if (!inside)
    {
        //ÄÄÄ Calc T distances to candidate planes and find max
        float dist = -1;

        int whichplane = 0;
        for(int i=0; i < 3; i++)
        {
            if (quad[i] != MIDDLE && dir[i] != 0)
            {
                float m = (candidate[i] - origin[i]) / dir[i];

                if (dist < m)
                {
                    whichplane = i;
                    dist = m;
                }
            }
        }

        if (dist < 0)
            return ESCH_ERR_NONE;

        float coord[3];
        for (int i=0; i < 3; i++)
        {
            if (whichplane != i)
            {
                coord[i] = origin[i] + dist * dir[i];
                if ((coord[i] < mins[i]) || (coord[i] > maxs[i]))
                {
                    return ESCH_ERR_NONE;
                }
                else
                {
                    coord[i] = candidate[i];
                }
            }
        }

        if (data->flags & ESCH_PICK_MAXDIST
            && dist > data->maxdist)
            return ESCH_ERR_NONE;
    }

//ÄÄÄ Check drawlist
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_pick found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::walk_pick found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIPTEST))
        {
            esch_error_codes err = item->pick(data);
            if (err)
                return err;
        }
    }

//ÄÄÄ Check child octants (we should be able to use results from ray/box
//ÄÄÄ test above to throw out impossible child octants...)
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_pick found corrupt links",
                       node != node->parent && node != node->q[i]);

            esch_error_codes err = walk_pick(node->q[i],data);
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - collide                                           ³
//                                                                          ³
// Performs a collision for drawables in the partitioning.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschOctTreePartition::collide(EschCollision *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ We want to intercept test self case only...
    if (data->flags & ESCH_CLSN_TESTSELF)
    {
        //ÄÄÄ Check octtree
        if (root)
        {
            if (flags & ESCH_PARTN_OFF)
            {
                esch_error_codes err = walk_collide_dumb(root,data);
                if (err)
                    return err;
            }
            else
            {
                esch_error_codes err = walk_collide(root,data);
                if (err)
                    return err;
            }
        }

        //ÄÄÄ Check global list
        for(EschPartitionList *ptr=global; ptr != 0; ptr = ptr->next)
        {
            assertMyth("EschOctTreePartition::collide found corrupt links",
                       ptr != ptr->next && ptr != ptr->prev);

            EschDrawable *item = ptr->item;

            assertMyth("EschOctTreePartition::collide found entry without item",
                        item != 0);

            if (item != data->orig
                && !(item->flags & ESCH_DRW_SKIPTEST))
            {
                esch_error_codes err = item->collide(data);
                if (err)
                    return err;
            }
        }

        return ESCH_ERR_NONE;
    }

//ÄÄÄ Otherwise use base implementation
    return EschDrawable::collide(data);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine for dumb walk
esch_error_codes EschOctTreePartition::walk_collide_dumb(EschOctTreeNode *node,
                                                         EschCollision *data) const
{
    if (!node)
        return ESCH_ERR_NONE;

//ÄÄÄ Check drawlist
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_collide_dumb found corrupt links",
                    ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::walk_collide_dumb found entry without item",
                    item != 0);

        if (item != data->orig
            && !(item->flags & ESCH_DRW_SKIPTEST))
        {
            esch_error_codes err = item->collide(data);
            if (err)
                return err;
        }
    }

//ÄÄÄ Check child octants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_collide_dumb found corrupt links",
                       node != node->parent && node != node->q[i]);

            esch_error_codes err = walk_collide_dumb(node->q[i],data);
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine for smart walk
esch_error_codes EschOctTreePartition::walk_collide(EschOctTreeNode *node,
                                                    EschCollision *data) const
{
    if (!node)
        return ESCH_ERR_NONE;

//ÄÄÄ See if node intersects collision sphere
    float radius = data->sphere.radius;

    if ((data->sphere.center.x + radius) < node->x1
        || (data->sphere.center.y + radius) < node->y1
        || (data->sphere.center.z + radius) < node->z1
        || (data->sphere.center.x - radius) > node->x2
        || (data->sphere.center.y - radius) > node->y2
        || (data->sphere.center.z - radius) > node->z2)
        return ESCH_ERR_NONE;

//ÄÄÄ Check drawlist
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_collide found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::walk_collide found entry without item",
                    item != 0);

        if (item != data->orig
            && !(item->flags & ESCH_DRW_SKIPTEST))
        {
            esch_error_codes err = item->collide(data);
            if (err)
                return err;
        }
    }

//ÄÄÄ Check child octants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_collide found corrupt links",
                       node != node->parent && node != node->q[i]);

            esch_error_codes err = walk_collide(node->q[i],data);
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - animate                                           ³
//                                                                          ³
// Calls animate for each drawable in the partitioning (subject to          ³
// the SKIPANIMATE bit).                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschOctTreePartition::animate()
{
//ÄÄÄ Animate octtree
    if (root)
        walk_animate(root);

//ÄÄÄ Animate global list
    for(EschPartitionList *ptr=global; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::animate found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::animate found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIPANIMATE))
            item->animate();
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine
void EschOctTreePartition::walk_animate(EschOctTreeNode *node)
{
    if (!node)
        return;

//ÄÄÄ Animate drawlist
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_animate found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::walk_animate found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIPANIMATE))
            item->animate();
    }

//ÄÄÄ Check child octrants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_animate found corrupt links",
                       node != node->parent && node != node->q[i]);

            walk_animate(node->q[i]);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - release                                           ³
//                                                                          ³
// Releases all drawables owned by the partition and clears the partition   ³
// lists.                                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschOctTreePartition::release()
{
    if (flags & ESCH_DRW_OWNSDATA)
    {
        //ÄÄÄ Release octtree
        if (root)
            walk_release(root);

        //ÄÄÄ Release global list (and draws if we own them)
        for(EschPartitionList *ptr=global; ptr != 0;)
        {
            assertMyth("EschOctTreePartition::release found corrupt links",
                       ptr != ptr->next && ptr != ptr->prev);

            EschPartitionList *t = ptr;
            ptr = ptr->next;

            if (t->item)
            {
                t->item->set_partn_data(0);
                if (flags & ESCH_PARTN_OWNSDRAWS)
                    delete t->item;
            }

            delete t;
        }
    }

    root=0;
    global=0;
    flags &= ~(ESCH_DRW_OWNSDATA|ESCH_PARTN_OWNSDRAWS);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine
void EschOctTreePartition::walk_release(EschOctTreeNode *node)
{
    if (!node)
        return;

//ÄÄÄ Release draws list (and draws if we own them)
    for(EschPartitionList *ptr=node->draws; ptr != 0;)
    {
        assertMyth("EschOctTreePartition::walk_release found corrupt links",
                    ptr != ptr->next && ptr != ptr->prev);

        EschPartitionList *t = ptr;
        ptr = ptr->next;

        if (t->item)
        {
            t->item->set_partn_data(0);
            if (flags & ESCH_PARTN_OWNSDRAWS)
                delete t->item;
        }

        delete t;
    }

//ÄÄÄ Release child octants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_release found corrupt links",
                       node != node->parent && node != node->q[i]);

            walk_release(node->q[i]);
        }
    }

//ÄÄÄ Delete self
    delete node;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - insert                                            ³
//                                                                          ³
// Inserts a drawable into the partitioning.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschOctTreePartition::insert(EschDrawable *drw)
{
    if (!drw || !root)
        return ESCH_ERR_INVALIDPARMS;

    if (drw->partn_data)
        return ESCH_ERR_REFERENCED;

//ÄÄÄ Get world sphere of drawable
    EschSphereExtents sphere;
    if (drw->get_extents(&sphere) == -1)
        return ESCH_ERR_NOTSUPPORTED;

//ÄÄÄ If sphere partially or fully outside of root octtree node,
//ÄÄÄ insert into globals
    if ((sphere.center.x - sphere.radius) < root->x1
        || (sphere.center.y - sphere.radius) < root->y1
        || (sphere.center.z - sphere.radius) < root->z1
        || (sphere.center.x + sphere.radius) > root->x2
        || (sphere.center.y + sphere.radius) > root->y2
        || (sphere.center.z + sphere.radius) > root->z2)
    {
        //ÄÄÄ Insert into global list
        EschPartitionList *ptr = new EschPartitionList(drw);
        if (!ptr)
            return ESCH_ERR_NOMEMORY;

        if (global)
        {
            ptr->next = global;
            global->prev = ptr;
        }

        global = ptr;

        drw->set_partn_data(0);

        return ESCH_ERR_NONE;
    }

//ÄÄÄ Insert into octtree
    return walk_insert(root,drw,sphere);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine
esch_error_codes EschOctTreePartition::walk_insert(EschOctTreeNode *node,
                                                   EschDrawable *drw,
                                                   EschSphereExtents &sphere,
                                                   ushort depth)
{
    if (!node)
        return ESCH_ERR_NOTSUPPORTED;

//ÄÄÄ If we can add depth to the tree...
    if (!maxdepth
        || (depth < maxdepth))
    {
        float xm = node->x1 + ((node->x2 - node->x1) / 2);
        float ym = node->y1 + ((node->y2 - node->y1) / 2);
        float zm = node->z1 + ((node->z2 - node->z1) / 2);

        float xmin = sphere.center.x - sphere.radius;
        float ymin = sphere.center.y - sphere.radius;
        float zmin = sphere.center.z - sphere.radius;
        float xmax = sphere.center.x + sphere.radius;
        float ymax = sphere.center.y + sphere.radius;
        float zmax = sphere.center.z + sphere.radius;

        int newoct = 0;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ See if new item will fit into octant
        //ÄÄÄ Check octant 0: (x1,y1,z1) - (xm,ym,zm)
        if (xmin > node->x1
            && ymin > node->y1
            && zmin > node->z1
            && xmax < xm
            && ymax < ym
            && zmax < zm)
        {
            if (node->q[0])
            {
                //ÄÄÄ Already have node, so insert it there...
                return walk_insert(node->q[0],drw,sphere,depth+1);
            }
            else if ((node->count >= maxcount)
                     || node->q[1]
                     || node->q[2]
                     || node->q[3]
                     || node->q[4]
                     || node->q[5]
                     || node->q[6]
                     || node->q[7])
                newoct = 1;
        }
        //ÄÄÄ Check octant 1: (xm,y1,z1) - (x2,ym,zm)
        else if (xmin > xm
                 && ymin > node->y1
                 && zmin > node->z1
                 && xmax < node->x2
                 && ymax < ym
                 && zmax < zm)
        {
            if (node->q[1])
            {
                //ÄÄÄ Already have node, so insert it there...
                return walk_insert(node->q[1],drw,sphere,depth+1);
            }
            else if ((node->count >= maxcount)
                     || node->q[0]
                     || node->q[2]
                     || node->q[3]
                     || node->q[4]
                     || node->q[5]
                     || node->q[6]
                     || node->q[7])
                newoct = 2;
        }
        //ÄÄÄ Check octant 2: (xm,y1,zm) - (x2,ym,z2)
        else if (xmin > xm
                 && ymin > node->y1
                 && zmin > zm
                 && xmax < node->x2
                 && ymax < ym
                 && zmax < node->z2)
        {
            if (node->q[2])
            {
                //ÄÄÄ Already have node, so insert it there...
                return walk_insert(node->q[2],drw,sphere,depth+1);
            }
            else if ((node->count >= maxcount)
                     || node->q[0]
                     || node->q[1]
                     || node->q[3]
                     || node->q[4]
                     || node->q[5]
                     || node->q[6]
                     || node->q[7])
                newoct = 3;
        }
        //ÄÄÄ Check octant 3: (x1,y1,zm) - (xm,ym,z2)
        else if (xmin > node->x1
                 && ymin > node->y1
                 && zmin > zm
                 && xmax < xm
                 && ymax < ym
                 && zmax < node->z2)
        {
            if (node->q[3])
            {
                //ÄÄÄ Already have node, so insert it there...
                return walk_insert(node->q[3],drw,sphere,depth+1);
            }
            else if ((node->count >= maxcount)
                     || node->q[0]
                     || node->q[1]
                     || node->q[2]
                     || node->q[4]
                     || node->q[5]
                     || node->q[6]
                     || node->q[7])
                newoct = 4;
        }
        //ÄÄÄ Check octant 4: (x1,ym,z1) - (xm,y2,zm)
        else if (xmin > node->x1
                 && ymin > ym
                 && zmin > node->z1
                 && xmax < xm
                 && ymax < node->y2
                 && zmax < zm)
        {
            if (node->q[4])
            {
                //ÄÄÄ Already have node, so insert it there...
                return walk_insert(node->q[4],drw,sphere,depth+1);
            }
            else if ((node->count >= maxcount)
                     || node->q[0]
                     || node->q[1]
                     || node->q[2]
                     || node->q[3]
                     || node->q[5]
                     || node->q[6]
                     || node->q[7])
                newoct = 5;
        }
        //ÄÄÄ Check octant 5: (xm,ym,z1) - (x2,y2,zm)
        else if (xmin > xm
                 && ymin > ym
                 && zmin > node->z1
                 && xmax < node->x2
                 && ymax < node->y2
                 && zmax < zm)
        {
            if (node->q[5])
            {
                //ÄÄÄ Already have node, so insert it there...
                return walk_insert(node->q[5],drw,sphere,depth+1);
            }
            else if ((node->count >= maxcount)
                     || node->q[0]
                     || node->q[1]
                     || node->q[2]
                     || node->q[3]
                     || node->q[4]
                     || node->q[6]
                     || node->q[7])
                newoct = 6;
        }
        //ÄÄÄ Check octant 6: (xm,ym,zm) - (x2,y2,z2)
        else if (xmin > xm
                 && ymin > ym
                 && zmin > zm
                 && xmax < node->x2
                 && ymax < node->y2
                 && zmax < node->z2)
        {
            if (node->q[6])
            {
                //ÄÄÄ Already have node, so insert it there...
                return walk_insert(node->q[6],drw,sphere,depth+1);
            }
            else if ((node->count >= maxcount)
                     || node->q[0]
                     || node->q[1]
                     || node->q[2]
                     || node->q[3]
                     || node->q[4]
                     || node->q[5]
                     || node->q[7])
                newoct = 7;
        }
        //ÄÄÄ Check octant 7: (x1,ym,zm) - (xm,y2,z2)
        else if (xmin > node->x1
                 && ymin > ym
                 && zmin > zm
                 && xmax < xm
                 && ymax < node->y2
                 && zmax < node->z2)
        {
            if (node->q[7])
            {
                //ÄÄÄ Already have node, so insert it there...
                return walk_insert(node->q[7],drw,sphere,depth+1);
            }
            else if ((node->count >= maxcount)
                     || node->q[0]
                     || node->q[1]
                     || node->q[2]
                     || node->q[3]
                     || node->q[4]
                     || node->q[5]
                     || node->q[6])
                newoct = 8;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Add new level of children nodes
        if (newoct)
        {
            //ÄÄÄ Move any items in current node that fit entirely within
            //ÄÄÄ a octant, adding any needed child nodes
            for(EschPartitionList *ptr = node->draws; ptr != 0;)
            {
                assertMyth("EschOctTreePartition::insert found corrupt links",
                           ptr != ptr->next && ptr != ptr->prev);

                assertMyth("EschOctTreePartition::insert found entry without item",
                            ptr->item != 0);

                EschSphereExtents sphere2;
                if (ptr->item->get_extents(&sphere2) == -1)
                {
                    ptr = ptr->next;
                    continue;
                }

                float xmin2 = sphere2.center.x - sphere2.radius;
                float ymin2 = sphere2.center.y - sphere2.radius;
                float zmin2 = sphere2.center.z - sphere2.radius;
                float xmax2 = sphere2.center.x + sphere2.radius;
                float ymax2 = sphere2.center.y + sphere2.radius;
                float zmax2 = sphere2.center.z + sphere2.radius;

                int newoct2 = 0;

                //ÄÄÄ Check octant 0: (x1,y1,z1) - (xm,ym,zm)
                if (xmin2 > node->x1
                    && ymin2 > node->y1
                    && zmin2 > node->z1
                    && xmax2 < xm
                    && ymax2 < ym
                    && zmax2 < zm)
                {
                    if (!node->q[0])
                    {
                        node->q[0] = new EschOctTreeNode(node->x1,node->y1,node->z1,
                                                         xm,ym,zm,
                                                         node,depth+1);
                        if (!node->q[0])
                            return ESCH_ERR_NOMEMORY;
                    }

                    newoct2 = 1;
                }
                //ÄÄÄ Check octant 1: (xm,y1,z1) - (x2,ym,zm)
                else if (xmin2 > xm
                         && ymin2 > node->y1
                         && zmin2 > node->z1
                         && xmax2 < node->x2
                         && ymax2 < ym
                         && zmax2 < zm)
                {
                    if (!node->q[1])
                    {
                        node->q[1] = new EschOctTreeNode(xm,node->y1,node->z1,
                                                         node->x2,ym,zm,
                                                         node,depth+1);
                        if (!node->q[1])
                            return ESCH_ERR_NOMEMORY;
                    }

                    newoct2 = 2;
                }
                //ÄÄÄ Check octant 2: (xm,y1,zm) - (x2,ym,z2)
                else if (xmin2 > xm
                         && ymin2 > node->y1
                         && zmin2 > zm
                         && xmax2 < node->x2
                         && ymax2 < ym
                         && zmax2 < node->z2)
                {
                    if (!node->q[2])
                    {
                        node->q[2] = new EschOctTreeNode(xm,node->y1,zm,
                                                         node->x2,ym,node->z2,
                                                         node,depth+1);
                        if (!node->q[2])
                            return ESCH_ERR_NOMEMORY;
                    }

                    newoct2 = 3;
                }
                //ÄÄÄ Check octant 3: (x1,y1,zm) - (xm,ym,z2)
                else if (xmin2 > node->x1
                         && ymin2 > node->y1
                         && zmin2 > zm
                         && xmax2 < xm
                         && ymax2 < ym
                         && zmax2 < node->z2)
                {
                    if (!node->q[3])
                    {
                        node->q[3] = new EschOctTreeNode(node->x1,node->y1,zm,
                                                         xm,ym,node->z2,
                                                         node,depth+1);
                        if (!node->q[3])
                            return ESCH_ERR_NOMEMORY;
                    }

                    newoct2 = 4;
                }
                //ÄÄÄ Check octant 4: (x1,ym,z1) - (xm,y2,zm)
                else if (xmin2 > node->x1
                         && ymin2 > ym
                         && zmin2 > node->z1
                         && xmax2 < xm
                         && ymax2 < node->y2
                         && zmax2 < zm)
                {
                    if (!node->q[4])
                    {
                        node->q[4] = new EschOctTreeNode(node->x1,ym,node->z1,
                                                         xm,node->y2,zm,
                                                         node,depth+1);
                        if (!node->q[4])
                            return ESCH_ERR_NOMEMORY;
                    }

                    newoct2 = 5;
                }
                //ÄÄÄ Check octant 5: (xm,ym,z1) - (x2,y2,zm)
                else if (xmin2 > xm
                         && ymin2 > ym
                         && zmin2 > node->z1
                         && xmax2 < node->x2
                         && ymax2 < node->y2
                         && zmax2 < zm)
                {
                    if (!node->q[5])
                    {
                        node->q[5] = new EschOctTreeNode(xm,ym,node->z1,
                                                         node->x2,node->y2,zm,
                                                         node,depth+1);
                        if (!node->q[5])
                            return ESCH_ERR_NOMEMORY;
                    }

                    newoct2 = 6;
                }
                //ÄÄÄ Check octant 6: (xm,ym,zm) - (x2,y2,z2)
                else if (xmin2 > xm
                         && ymin2 > ym
                         && zmin2 > zm
                         && xmax2 < node->x2
                         && ymax2 < node->y1
                         && zmax2 < node->z2)
                {
                    if (!node->q[6])
                    {
                        node->q[6] = new EschOctTreeNode(xm,ym,zm,
                                                         node->x2,node->y2,node->z2,
                                                         node,depth+1);
                        if (!node->q[6])
                            return ESCH_ERR_NOMEMORY;
                    }

                    newoct2 = 7;
                }
                //ÄÄÄ Check octant 7: (x1,ym,zm) - (xm,y2,z2)
                else if (xmin2 > node->x1
                         && ymin2 > ym
                         && zmin2 > zm
                         && xmax2 < xm
                         && ymax2 < node->y2
                         && zmax2 < node->z2)
                {
                    if (!node->q[7])
                    {
                        node->q[7] = new EschOctTreeNode(node->x1,ym,zm,
                                                         xm,node->y2,node->z2,
                                                         node,depth+1);
                        if (!node->q[7])
                            return ESCH_ERR_NOMEMORY;
                    }

                    newoct2 = 8;
                }

                //ÄÄÄ If it fits into an octant, move it
                if (newoct2)
                {
                    EschPartitionList *tptr = ptr;
                    ptr = ptr->next;

                    //ÄÄÄ Remove from our draws list...
                    if (tptr->next)
                        tptr->next->prev = tptr->prev;

                    if (tptr->prev)
                        tptr->prev->next = tptr->next;
                    else
                        node->draws = tptr->next;

                    node->count--;

                    //ÄÄÄ Insert into new octant
                    assertMyth("EschOctTreeNode::insert found entry without item",
                               tptr->item != 0);
                    EschDrawable *drw2 = tptr->item;
                    delete tptr;

                    drw2->set_partn_data(0);

                    assert(newoct2 >= 1 && newoct2 <= 8);
                    esch_error_codes err = walk_insert(node->q[newoct2-1],drw2,
                                                       sphere2,depth+1);
                    if (err)
                    {
                        if (flags & ESCH_PARTN_OWNSDRAWS)
                            delete drw2;
                        return err;
                    }
                }
                else
                {
                    ptr = ptr->next;
                }
            }

            //ÄÄÄ Add new item, adding any needed child node
            assert(newoct >= 1 && newoct <= 8);
            switch (newoct)
            {
                case 1:
                    if (!node->q[0])
                    {
                        node->q[0] = new EschOctTreeNode(node->x1,node->y1,node->z1,
                                                         xm,ym,zm,
                                                         node,depth+1);
                        if (!node->q[0])
                            return ESCH_ERR_NOMEMORY;
                    }
                    return walk_insert(node->q[0],drw,sphere,depth+1);
                case 2:
                    if (!node->q[1])
                    {
                        node->q[1] = new EschOctTreeNode(xm,node->y1,node->z1,
                                                         node->x2,ym,zm,
                                                         node,depth+1);
                        if (!node->q[1])
                            return ESCH_ERR_NOMEMORY;
                    }
                    return walk_insert(node->q[1],drw,sphere,depth+1);
                case 3:
                    if (!node->q[2])
                    {
                        node->q[2] = new EschOctTreeNode(xm,node->y1,zm,
                                                          node->x2,ym,node->z2,
                                                          node,depth+1);
                        if (!node->q[2])
                            return ESCH_ERR_NOMEMORY;
                    }
                    return walk_insert(node->q[2],drw,sphere,depth+1);
                case 4:
                    if (!node->q[3])
                    {
                        node->q[3] = new EschOctTreeNode(node->x1,node->y1,zm,
                                                          xm,ym,node->z2,
                                                          node,depth+1);
                        if (!node->q[3])
                            return ESCH_ERR_NOMEMORY;
                    }
                    return walk_insert(node->q[3],drw,sphere,depth+1);
                case 5:
                    if (!node->q[4])
                    {
                        node->q[4] = new EschOctTreeNode(node->x1,ym,node->z1,
                                                         xm,node->y2,zm,
                                                         node,depth+1);
                        if (!node->q[4])
                            return ESCH_ERR_NOMEMORY;
                    }
                    return walk_insert(node->q[4],drw,sphere,depth+1);
                case 6:
                    if (!node->q[5])
                    {
                        node->q[5] = new EschOctTreeNode(xm,ym,node->z1,
                                                         node->x2,node->y2,zm,
                                                         node,depth+1);
                        if (!node->q[5])
                            return ESCH_ERR_NOMEMORY;
                    }
                    return walk_insert(node->q[5],drw,sphere,depth+1);
                case 7:
                    if (!node->q[6])
                    {
                        node->q[6] = new EschOctTreeNode(xm,ym,zm,
                                                         node->x2,node->y2,node->z2,
                                                         node,depth+1);
                        if (!node->q[6])
                            return ESCH_ERR_NOMEMORY;
                    }
                    return walk_insert(node->q[6],drw,sphere,depth+1);
                case 8:
                    if (!node->q[7])
                    {
                        node->q[7] = new EschOctTreeNode(node->x1,ym,zm,
                                                         xm,node->y2,node->z2,
                                                         node,depth+1);
                        if (!node->q[7])
                            return ESCH_ERR_NOMEMORY;
                    }
                    return walk_insert(node->q[7],drw,sphere,depth+1);
            }
        }
    }

//ÄÄÄ Otherwise insert at this node...
    EschPartitionList *ptr = new EschPartitionList(drw);
    if (!ptr)
        return ESCH_ERR_NOMEMORY;

    if (node->draws)
    {
        ptr->next = node->draws;
        node->draws->prev = ptr;
    }

    node->draws = ptr;
    node->count++;

    drw->set_partn_data(node);

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - remove                                            ³
//                                                                          ³
// Removes a given drawable from the partitioning                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschOctTreePartition::remove(EschDrawable *drw)
{
    if (!drw)
        return;

    int found = 0;

    if (drw->partn_data)
    {
        //ÄÄÄ Find node we are located in
        EschOctTreeNode *node = (EschOctTreeNode*)drw->partn_data;

        //ÄÄÄ Remove ourselves from the list
        for(EschPartitionList *ptr = node->draws; ptr != 0; ptr = ptr->next)
        {
            assertMyth("EschOctTreePartition::remove found corrupt links",
                       ptr != ptr->next && ptr != ptr->prev);

            if (ptr->item == drw)
            {
                if (ptr->next)
                    ptr->next->prev = ptr->prev;

                if (ptr->prev)
                    ptr->prev->next = ptr->next;
                else
                    node->draws = ptr->next;

                delete ptr;

                node->count--;

                walk_remove(node);

                drw->set_partn_data(0);

                found=1;
                break;
            }
        }
    }
    else
    {
        //ÄÄÄ Remove ourselves from global list if we are in it
        for(EschPartitionList *ptr = global; ptr != 0; ptr = ptr->next)
        {
            assertMyth("EschOctTreePartition::remove found corrupt links",
                       ptr != ptr->next && ptr != ptr->prev);

            if (ptr->item == drw)
            {
                if (ptr->next)
                    ptr->next->prev = ptr->prev;

                if (ptr->prev)
                    ptr->prev->next = ptr->next;
                else
                    global = ptr->next;

                delete ptr;

                found=1;
                break;
            }
        }
    }

    if (found && (flags & ESCH_PARTN_OWNSDRAWS))
        delete drw;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine
void EschOctTreePartition::walk_remove(EschOctTreeNode *node)
{
    if (!node)
        return;

//ÄÄÄ Cleanup children first
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_remove found corrupt links",
                       node != node->parent && node != node->q[i]);

            walk_remove(node->q[i]);
        }
    }

//ÄÄÄ If we have children, see if they should be folded up into us
//ÄÄÄ (children must have no children and total should be less than
//ÄÄÄ max count)
    if (node->q[0]
        || node->q[1]
        || node->q[2]
        || node->q[3]
        || node->q[4]
        || node->q[5]
        || node->q[6]
        || node->q[7])
    {
        ushort tcount = node->count;

        for(int i=0; i < 8; i++)
        {
            if (tcount > maxcount)
                break;

            if (node->q[i])
            {
                if (!node->q[i]->q[0]
                    && !node->q[i]->q[1]
                    && !node->q[i]->q[2]
                    && !node->q[i]->q[3]
                    && !node->q[i]->q[4]
                    && !node->q[i]->q[5]
                    && !node->q[i]->q[6]
                    && !node->q[i]->q[7])
                {
                    tcount += node->q[i]->count;
                }
                else
                {
                    // Abort folding optimization
                    tcount = maxcount+1;
                }
            }
        }

        //ÄÄÄ Perform folding optimization
        assert(tcount > 0);
        if (tcount <= maxcount)
        {
            for(int i=0; i < 8; i++)
            {
                if (node->q[i])
                {
                    for(EschPartitionList *ptr = node->q[i]->draws; ptr != 0;)
                    {
                        assertMyth("EschOctTreePartition::walk_remove found corrupt links",
                                   ptr != ptr->next && ptr != ptr->prev);

                        //ÄÄÄ Remove from child list
                        EschPartitionList *tptr = ptr;
                        ptr = ptr->next;

                        tptr->next = tptr->prev = 0;

                        //ÄÄÄ Insert into node's list
                        if (node->draws)
                        {
                            tptr->next = node->draws;
                            node->draws->prev = tptr;
                        }

                        node->draws = tptr;
                        node->count++;

                        assertMyth("EschOctTreePartition::walk_insert found entry without item",
                                   tptr->item != 0);

                        tptr->item->set_partn_data(node);
                    }

                    delete node->q[i];
                    node->q[i] = 0;
                }
            }
        }
    }

//ÄÄÄ If we are empty, remove ourselves if we are not the root
    else if (!node->count && node->parent)
    {
        assertMyth("EschOctTreePartition::walk_remove found non-empty draw list with count 0",
                   node->draws == 0);

        for(int i=0; i < 8; i++)
        {
            assertMyth("EschOctTreePartition::walk_remove found corrupt links",
                       node != node->parent && node != node->q[i]);

            if (node->parent->q[i] == node)
                node->parent->q[i] = 0;
        }

        delete node;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - traverse                                          ³
//                                                                          ³
// Performs a controlled walk of the drawables within the partitioning,     ³
// calling a supplied function for each item.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschOctTreePartition::traverse(EschTraverse *data) const
{
    if (!data || !data->func)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ Traverse octtree
    if (root)
    {
        if (flags & ESCH_PARTN_OFF)
        {
            esch_error_codes err = walk_traverse_dumb(root,data);
            if (err)
                return err;
        }
        else if (data->flags & ESCH_TRAV_DIRECTION)
        {
            esch_error_codes err = walk_traverse_dir(root,data);
            if (err)
                return err;
        }
        else
        {
            esch_error_codes err = walk_traverse_area(root,data);
            if (err)
                return err;
        }
    }

//ÄÄÄ Traverse global list
    for(EschPartitionList *ptr=global; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::traverse found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschOctTreePartition::traverse found entry without item",
                   item != 0);

        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
        {
            if (data->func(data->data,item))
                return ESCH_ERR_STOPPED;
        }
    }

    return ESCH_ERR_NONE;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine for dumb walk
esch_error_codes EschOctTreePartition::walk_traverse_dumb(EschOctTreeNode *node,
                                                          EschTraverse *data) const
{
    if (!node)
        return ESCH_ERR_NONE;

//ÄÄÄ Traverse drawlist
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_traverse_dumb found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschGridPartition::walk_traverse_dumb found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
        {
            if (data->func(data->data,item))
                return ESCH_ERR_STOPPED;
        }
    }

//ÄÄÄ Traverse child octants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_traverse_dumb found corrupt links",
                       node != node->parent && node != node->q[i]);

            esch_error_codes err = walk_traverse_dumb(node->q[i],data);
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine for smart direction walk
esch_error_codes EschOctTreePartition::walk_traverse_dir(EschOctTreeNode *node,
                                                         EschTraverse *data) const
{
    if (!node)
        return ESCH_ERR_NONE;

//ÄÄÄ See if node hit by ray
    int     inside = 1;
    enum
    {
        RIGHT=0,
        LEFT=1,
        MIDDLE=2
    }       quad[3];
    float   candidate[3];
    float   mins[3] = { node->x1, node->y1, node->z1 };
    float   maxs[3] = { node->x2, node->y2, node->z2 };
    float   origin[3] = { data->pos.x, data->pos.y, data->pos.z };
    float   dir[3] = { data->dir.i, data->dir.j, data->dir.k };

    //ÄÄÄ Find candidate planes
    for(int i=0; i < 3; i++)
    {
        if (origin[i] < mins[i])
        {
            quad[i] = LEFT;
            if (dir[i] <= 0)
                return ESCH_ERR_NONE;

            candidate[i] = mins[i];
            inside = 0;
        }
        else if (origin[i] > maxs[i])
        {
            quad[i] = RIGHT;
            if (dir[i] >= 0)
                return ESCH_ERR_NONE;

            candidate[i] = maxs[i];
            inside = 0;
        }
        else
        {
            quad[i] = MIDDLE;
        }
    }

    //ÄÄÄ If we are inside, we definetely need to check node
    if (!inside)
    {
        //ÄÄÄ Calc T distances to candidate planes and find max
        float dist = -1;

        int whichplane = 0;
        for(int i=0; i < 3; i++)
        {
            if (quad[i] != MIDDLE && dir[i] != 0)
            {
                float m = (candidate[i] - origin[i]) / dir[i];

                if (dist < m)
                {
                    whichplane = i;
                    dist = m;
                }
            }
        }

        if (dist < 0)
            return ESCH_ERR_NONE;

        float coord[3];
        for (int i=0; i < 3; i++)
        {
            if (whichplane != i)
            {
                coord[i] = origin[i] + dist * dir[i];
                if ((coord[i] < mins[i]) || (coord[i] > maxs[i]))
                {
                    return ESCH_ERR_NONE;
                }
                else
                {
                    coord[i] = candidate[i];
                }
            }
        }

        if (data->flags & ESCH_TRAV_DIST
            && dist > data->dist)
            return ESCH_ERR_NONE;
    }

//ÄÄÄ Traverse drawlist
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_traverse_dir found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschGridPartition::walk_traverse_dir found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
        {
            if (data->func(data->data,item))
                return ESCH_ERR_STOPPED;
        }
    }

//ÄÄÄ Traverse child octants (we should be able to use results from ray/box
//ÄÄÄ test above to throw out impossible child octants...
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_traverse_dir found corrupt links",
                       node != node->parent && node != node->q[i]);

            esch_error_codes err = walk_traverse_dir(node->q[i],data);
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine for smart area walk
esch_error_codes EschOctTreePartition::walk_traverse_area(EschOctTreeNode *node,
                                                          EschTraverse *data) const
{
    if (!node)
        return ESCH_ERR_NONE;

//ÄÄÄ See if node too far from start point
    if (data->flags & ESCH_TRAV_DIST)
    {
        if ((data->pos.x + data->dist) < node->x1
            || (data->pos.y + data->dist) < node->y1
            || (data->pos.z + data->dist) < node->z1
            || (data->pos.x - data->dist) > node->x2
            || (data->pos.y - data->dist) > node->y2
            || (data->pos.z - data->dist) > node->z2)
            return ESCH_ERR_NONE;
    }

//ÄÄÄ Traverse drawlist
    for(EschPartitionList *ptr=node->draws; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::walk_traverse_area found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        EschDrawable *item = ptr->item;

        assertMyth("EschGridPartition::walk_traverse_area found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
        {
            if (data->func(data->data,item))
                return ESCH_ERR_STOPPED;
        }
    }

//ÄÄÄ Traverse child octants
    for(int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_traverse_area found corrupt links",
                       node != node->parent && node != node->q[i]);

            esch_error_codes err = walk_traverse_area(node->q[i],data);
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - update                                            ³
//                                                                          ³
// Performs an update of the position of a drawable within the partitioning ³
// or all drawables if drw is 0.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschOctTreePartition::update(EschDrawable *drw)
{
    if (!root)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Update a single drawable
    if (drw)
    {
        if (drw->flags & ESCH_DRW_PARTNSTATIC)
            return ESCH_ERR_NONE;

        //ÄÄÄ Get world sphere of drawable
        EschSphereExtents sphere;
        if (drw->get_extents(&sphere) == -1)
            return ESCH_ERR_NOTSUPPORTED;

        float xmin = sphere.center.x - sphere.radius;
        float ymin = sphere.center.y - sphere.radius;
        float zmin = sphere.center.z - sphere.radius;
        float xmax = sphere.center.x + sphere.radius;
        float ymax = sphere.center.y + sphere.radius;
        float zmax = sphere.center.z + sphere.radius;

        if (drw->partn_data)
        {
            //ÄÄÄ We were in the octtree, so see if we've moved out of our
            //ÄÄÄ node and if so, where do we fit up the tree...

            EschOctTreeNode *onode = (EschOctTreeNode*)drw->partn_data;

            for(EschOctTreeNode *node = onode; node != 0; node = node->parent)
            {
                assertMyth("EschOctTreePartition::update found corrupt links",
                           node != node->parent);

                if (xmin > node->x1
                    && ymin > node->y1
                    && zmin > node->z1
                    && xmax < node->x2
                    && ymax < node->y2
                    && zmax < node->z2)
                {
                    if (node == onode)
                    {
                        //ÄÄÄ We still fit in our original node

                        //ÄÄÄ See if we can force it down a level
                        if (node->q[0]
                            || node->q[1]
                            || node->q[2]
                            || node->q[3]
                            || node->q[4]
                            || node->q[5]
                            || node->q[6]
                            || node->q[7]
                            || ((node->count > maxcount)
                                && (!maxdepth
                                    || (node->depth < maxdepth))))
                        {
                            float xm = node->x1 + ((node->x2 - node->x1) / 2);
                            float ym = node->y1 + ((node->y2 - node->y1) / 2);
                            float zm = node->z1 + ((node->z2 - node->z1) / 2);

                            int newoct = 0;

                            //ÄÄÄ Check octant 0: (x1,y1,z1) - (xm,ym,zm)
                            if (xmin > node->x1
                                && ymin > node->y1
                                && zmin > node->z1
                                && xmax < xm
                                && ymax < ym
                                && zmax < zm)
                            {
                                newoct = 1;
                            }
                            //ÄÄÄ Check octant 1: (xm,y1,z1) - (x2,ym,zm)
                            else if (xmin > xm
                                    && ymin > node->y1
                                    && zmin > node->z1
                                    && xmax < node->x2
                                    && ymax < ym
                                    && zmax < zm)
                            {
                                newoct = 2;
                            }
                            //ÄÄÄ Check octant 2: (xm,y1,zm) - (x2,ym,z2)
                            else if (xmin > xm
                                     && ymin > node->y1
                                     && zmin > zm
                                     && xmax < node->x2
                                     && ymax < ym
                                     && zmax < node->z2)
                            {
                                newoct = 3;
                            }
                            //ÄÄÄ Check octant 3: (x1,y1,zm) - (xm,ym,z2)
                            else if (xmin > node->x1
                                     && ymin > node->y1
                                     && zmin > zm
                                     && xmax < xm
                                     && ymax < ym
                                     && zmax < node->z2)
                            {
                                newoct = 4;
                            }
                            //ÄÄÄ Check octant 4: (x1,ym,z1) - (xm,y2,zm)
                            else if (xmin > node->x1
                                     && ymin > ym
                                     && zmin > node->z1
                                     && xmax < xm
                                     && ymax < node->y2
                                     && zmax < zm)
                            {
                                newoct = 5;
                            }
                            //ÄÄÄ Check octant 5: (xm,ym,z1) - (x2,y2,zm)
                            else if (xmin > xm
                                    && ymin > ym
                                    && zmin > node->z1
                                    && xmax < node->x2
                                    && ymax < node->y2
                                    && zmax < zm)
                            {
                                newoct = 6;
                            }
                            //ÄÄÄ Check octant 6: (xm,ym,zm) - (x2,y2,z2)
                            else if (xmin > xm
                                     && ymin > ym
                                     && zmin > zm
                                     && xmax < node->x2
                                     && ymax < node->y2
                                     && zmax < node->z2)
                            {
                                newoct = 7;
                            }
                            //ÄÄÄ Check octant 7: (x1,ym,zm) - (xm,y2,z2)
                            else if (xmin > node->x1
                                     && ymin > ym
                                     && zmin > zm
                                     && xmax < xm
                                     && ymax < node->y2
                                     && zmax < node->z2)
                            {
                                newoct = 8;
                            }

                            if (newoct)
                            {
                                //ÄÄÄ Remove from old node
                                EschPartitionList *ptr = NULL;
                                for(ptr = onode->draws;
                                    ptr != 0;
                                    ptr = ptr->next)
                                {
                                    assertMyth("EschOctTreePartition::update found corrupt links",
                                               ptr != ptr->next && ptr != ptr->prev);

                                    if (ptr->item == drw)
                                    {
                                        if (ptr->next)
                                            ptr->next->prev = ptr->prev;

                                        if (ptr->prev)
                                            ptr->prev->next = ptr->next;
                                        else
                                            onode->draws = ptr->next;

                                        onode->count--;

                                        walk_remove(onode);

                                        break;
                                    }
                                }

                                if (!ptr)
                                    return ESCH_ERR_NOTFOUND;

                                delete ptr;

                                drw->set_partn_data(0);

                                //ÄÄÄ Insert at new location
                                return walk_insert(node,drw,sphere,node->depth);
                            }
                        }

#ifdef DEBUG
                        //ÄÄÄ Verify drawable in list
                        for(EschPartitionList *ptr = onode->draws;
                            ptr != 0;
                            ptr = ptr->next)
                        {
                            assertMyth("EschOctTreePartition::update found corrupt links",
                                        ptr != ptr->next && ptr != ptr->prev);

                            if (ptr->item == drw)
                                break;
                        }

                        if (!ptr)
                            return ESCH_ERR_NOTFOUND;
#endif

                        //ÄÄÄ Don't need to move
                        return ESCH_ERR_NONE;
                    }
                    else
                    {
                        //ÄÄÄ Move to new node in octtree

                        //ÄÄÄ Remove from old node
                        EschPartitionList *ptr = NULL;
                        for(ptr = onode->draws;
                            ptr != 0;
                            ptr = ptr->next)
                        {
                            assertMyth("EschOctTreePartition::update found corrupt links",
                                        ptr != ptr->next && ptr != ptr->prev);

                            if (ptr->item == drw)
                            {
                                if (ptr->next)
                                    ptr->next->prev = ptr->prev;

                                if (ptr->prev)
                                    ptr->prev->next = ptr->next;
                                else
                                    onode->draws = ptr->next;

                                onode->count--;

                                walk_remove(onode);

                                break;
                            }
                        }

                        if (!ptr)
                            return ESCH_ERR_NOTFOUND;

                        delete ptr;

                        drw->set_partn_data(0);

                        //ÄÄÄ Insert at new location
                        return walk_insert(node,drw,sphere,node->depth);
                    }
                }
            }

            //ÄÄÄ We must not have fit into quad-tree so we are now global

            //ÄÄÄ Remove from old location in node
            EschPartitionList *ptr=NULL;
            for(ptr = onode->draws;
                ptr != 0;
                ptr = ptr->next)
            {
                assertMyth("EschOctTreePartition::update found corrupt links",
                            ptr != ptr->next && ptr != ptr->prev);

                if (ptr->item == drw)
                {
                    if (ptr->next)
                        ptr->next->prev = ptr->prev;

                    if (ptr->prev)
                        ptr->prev->next = ptr->next;
                    else
                        onode->draws = ptr->next;

                    ptr->next = ptr->prev = 0;

                    onode->count--;

                    walk_remove(onode);

                    break;
                }
            }

            if (!ptr)
                return ESCH_ERR_NOTFOUND;

            drw->set_partn_data(0);

            //ÄÄÄ Insert into globals
            if (global)
            {
                ptr->next = global;
                global->prev = ptr;
            }

            global = ptr;

            drw->set_partn_data(0);

            return ESCH_ERR_NONE;
        }
        else if (xmin > root->x1
                 && ymin > root->y1
                 && zmin > root->z1
                 && xmax < root->x2
                 && ymax < root->y2
                 && zmax < root->z2)
        {
            //ÄÄÄ We were in the globals list, so if we fit into the
            //ÄÄÄ quad-tree now, move from the globals to the tree

            //ÄÄÄ Remove ourselves from global list if we are in it
            for(EschPartitionList *ptr = global; ptr != 0; ptr = ptr->next)
            {
                assertMyth("EschOctTreePartition::update found corrupt links",
                            ptr != ptr->next && ptr != ptr->prev);

                if (ptr->item == drw)
                {
                    if (ptr->next)
                        ptr->next->prev = ptr->prev;

                    if (ptr->prev)
                        ptr->prev->next = ptr->next;
                    else
                        global = ptr->next;

                    delete ptr;

                    //ÄÄÄ Insert outselves into octtree
                    return walk_insert(root,drw,sphere);
                }
            }

            return ESCH_ERR_NOTFOUND;
        }
        else
        {
            // Otherwise we are in globals and should stay there...

#ifdef DEBUG
            //ÄÄÄ Verify drawable in list
            for(EschPartitionList *ptr = global; ptr != 0; ptr = ptr->next)
            {
                assertMyth("EschOctTreePartition::update found corrupt links",
                            ptr != ptr->next && ptr != ptr->prev);

                if (ptr->item == drw)
                    break;
            }

            if (!ptr)
                return ESCH_ERR_NOTFOUND;
#endif

            return ESCH_ERR_NONE;
        }
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Update all drawables that aren't static
    else
    {
        if (root)
        {
            esch_error_codes err = walk_update(root);
            if (err)
                return err;
        }

        for(EschPartitionList *ptr = global; ptr != 0;)
        {
            assertMyth("EschOctTreePartition::update found corrupt links",
                        ptr != ptr->next && ptr != ptr->prev);

            EschPartitionList *tptr = ptr;
            ptr = ptr->next;

            EschDrawable *item = tptr->item;

            assertMyth("EschOctTreePartition::update found entry without item",
                       item != 0);

            if (item && !(item->flags & ESCH_DRW_PARTNSTATIC))
            {
                esch_error_codes err = update(item);
                    return err;
            }
        }

        return ESCH_ERR_NONE;
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine
esch_error_codes EschOctTreePartition::walk_update(EschOctTreeNode *node)
{
    if (!node)
        return ESCH_ERR_NONE;

//ÄÄÄ Update drawlist
    for(EschPartitionList *ptr=node->draws; ptr != 0;)
    {
        assertMyth("EschOctTreePartition::walk_update found corrupt links",
                    ptr != ptr->next && ptr != ptr->prev);

        EschPartitionList *tptr = ptr;
        ptr = ptr->next;

        EschDrawable *item = tptr->item;

        assertMyth("EschGridPartition::walk_update found entry without item",
                    item != 0);

        if (item && !(item->flags & ESCH_DRW_PARTNSTATIC))
        {
            esch_error_codes err = update(item);
            if (err)
                return err;
        }
    }

//ÄÄÄ Update child octants
    for (int i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_update found corrupt links",
                       node != node->parent && node != node->q[i]);

            esch_error_codes err = walk_update(node->q[i]);
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - init                                              ³
//                                                                          ³
// Initializes the partitioning.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschOctTreePartition::init(const EschPoint *o,
                                            float w, float h, float d)
{
    release();

//ÄÄÄ Verify inputs
    if (!o || w <= 0 || h < 0 || d < 0)
        return ESCH_ERR_INVALIDPARMS;

    if (d == 0)
        d = w;

    if (h == 0)
        h = w;

//ÄÄÄ Create root node
    root = new EschOctTreeNode(o->x, o->y, o->z,
                               o->x + w, o->y + h, o->z + d);
    if (!root)
        return ESCH_ERR_NOMEMORY;

    flags |= ESCH_DRW_OWNSDATA;

    return ESCH_ERR_NONE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - draw_octtree                                      ³
//                                                                          ³
// Draws the outline of the quad-tree itself.  Needs the current context to ³
// be valid.                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschOctTreePartition::draw_octtree(dword clr) const
{
    if (root)
    {
        //ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
        assertMyth("EschOctTreePartition::draw_octtree needs camera in current context",
                EschCurrent != NULL && EschCurrent->camera != NULL);

        EschCamera *cam=EschCurrent->camera;

        assertMyth("EschOctTreePartition::draw_octtree needs a viewport in current context's camera",
                cam->vport != NULL);

        walk_drawocttree(root,cam,clr);
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine
void EschOctTreePartition::walk_drawocttree(EschOctTreeNode *node,
                                            EschCamera *cam,
                                            dword clr) const
{
    int         i;
    int         mp;
    float       hither, yon;
    VngoVport   *vp;
    EschPoint   p;
    VngoPoint   vpt[8];

    if (!node)
        return;

    vp=cam->vport;

//ÄÄÄ Setup for compare
    yon = cam->yon;
    hither = cam->hither;

    mp = vp->vbuff.pal->shd_pal->mid_point;

//ÄÄÄ Draw self
    //ÄÄÄ For each of the eight points of the cell
    for(i=0; i < 8; i++)
    {
        switch (i)
        {
            case 0:
                p.x = node->x1;
                p.y = node->y1;
                p.z = node->z1;
                break;
            case 1:
                p.x = node->x2;
                p.y = node->y1;
                p.z = node->z1;
                break;
            case 2:
                p.x = node->x1;
                p.y = node->y2;
                p.z = node->z1;
                break;
            case 3:
                p.x = node->x2;
                p.y = node->y2;
                p.z = node->z1;
                break;
            case 4:
                p.x = node->x1;
                p.y = node->y1;
                p.z = node->z2;
                break;
            case 5:
                p.x = node->x2;
                p.y = node->y1;
                p.z = node->z2;
                break;
            case 6:
                p.x = node->x1;
                p.y = node->y2;
                p.z = node->z2;
                break;
            default: /* 7 */
                p.x = node->x2;
                p.y = node->y2;
                p.z = node->z2;
                break;
        }
        p.transform(&cam->eye.iorient);

        // If we cross near or far plane, abort draw of extents
        if (p.z < hither || p.z > yon)
            break;

        if (cam->flags & ESCH_CAM_ORTHO)
        {
            vpt[i].x = long(p.x * cam->xscalar)
                       + (cam->vport->vbuff.width >> 1);
            vpt[i].y = (cam->vport->vbuff.height >> 1)
                       - long(p.y * cam->yscalar);
        }
        else
        {
            vpt[i].x = long((p.x * cam->xscalar) / p.z)
                       + (cam->vport->vbuff.width >> 1);
            vpt[i].y = (cam->vport->vbuff.height >> 1)
                       - long((p.y * cam->yscalar) / p.z);
        }
        vpt[i].z = dword(p.z * cam->z_factor * float(0xffffffff));
        vpt[i].clr = clr;
        vpt[i].shade = mp;
    }

    //ÄÄÄ Draw cell
    if (i >= 8)
    {
        vp->clip_line(&vpt[0],&vpt[1]);
        vp->clip_line(&vpt[1],&vpt[5]);
        vp->clip_line(&vpt[5],&vpt[4]);
        vp->clip_line(&vpt[4],&vpt[0]);
        vp->clip_line(&vpt[2],&vpt[3]);
        vp->clip_line(&vpt[3],&vpt[7]);
        vp->clip_line(&vpt[7],&vpt[6]);
        vp->clip_line(&vpt[6],&vpt[2]);
        vp->clip_line(&vpt[0],&vpt[2]);
        vp->clip_line(&vpt[1],&vpt[3]);
        vp->clip_line(&vpt[5],&vpt[7]);
        vp->clip_line(&vpt[4],&vpt[6]);
    }

//ÄÄÄ Draw child octants
    for(i=0; i < 8; i++)
    {
        if (node->q[i])
        {
            assertMyth("EschOctTreePartition::walk_drawquadtree found corrupt links",
                       node != node->parent && node != node->q[i]);

            walk_drawocttree(node->q[i],cam,clr);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschOctTreePartition - compute_stats                                     ³
//                                                                          ³
// Compute statistics about the octtree.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschOctTreePartition::compute_stats(EschOctTreeStats *stats) const
{
    if (!stats)
        return;

    memset(stats,0,sizeof(EschOctTreeStats));

//ÄÄÄ Compute tree stats
    if (root)
        walk_stats(root,stats);

//ÄÄÄ Compute global stats
    for(EschPartitionList *ptr = global; ptr != 0; ptr = ptr->next)
    {
        assertMyth("EschOctTreePartition::compute_stats found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        stats->items++;
        stats->items_global++;
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Helper recursive routine
void EschOctTreePartition::walk_stats(EschOctTreeNode *node,
                                      EschOctTreeStats *stats) const
{
    if (!node)
        return;

//ÄÄÄ Verify node count
    ushort tcount=0;
    for(EschPartitionList *ptr = node->draws; ptr != 0; ptr = ptr->next, tcount++)
    {
        assertMyth("EschOctTreePartition::walk_stats found corrupt links",
                   ptr != ptr->next && ptr != ptr->prev);

        assertMyth("EschOctTreePartition::walk_stats found incorrect count",
                   tcount <= node->count);
    }

    assertMyth("EschOctTreePartition::walk_stats found incorrect count",
               tcount == node->count);

//ÄÄÄ Compute node stats
    if (node->depth > stats->hidepth)
        stats->hidepth = node->depth;

    if (tcount > stats->hicount)
        stats->hicount = tcount;

    stats->nodes++;
    stats->items += tcount;

    if (!node->q[0]
        && !node->q[1]
        && !node->q[2]
        && !node->q[3]
        && !node->q[4]
        && !node->q[5]
        && !node->q[6]
        && !node->q[7])
    {
        //ÄÄÄ No child nodes, so we are a leaf
        stats->leaves++;
    }
    else
    {
        //ÄÄÄ We have children, so we are an internal node
        stats->items_nonleaf += tcount;

        for(int i=0; i < 8; i++)
        {
            if (node->q[i])
            {
                assertMyth("EschOctTreePartition::walk_stats found corrupt links",
                           node != node->parent && node != node->q[i]);

                walk_stats(node->q[i],stats);
            }
        }
    }
}

//°±² End of module - esopartn.cpp ²±°

