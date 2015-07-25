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
// Created by Paul Masters
//
// eskeyfrm.cpp
//
// Contains the code for the EschKeyframer class.  This class is
// the base class for a EschLimbSegment based keyframe motion.  The
// keyframer maintains a list of keyframes for retrieval by any animating
// EschLimbSegment constrained object.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <stdio.h>

#include "escher.hpp"

#include "esfile.hpp"
#include "estoken.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                Defines
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

EschKeyframer *EschKeyframeMan = 0;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframer - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EschKeyframer::EschKeyframer() :
    count (0),
    list (0)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframer - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EschKeyframer::~EschKeyframer()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframer - release
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframer::release()
{
    EschKeyframeHeader *head_killer = list;
    while (head_killer)
    {
        EschKeyframe *frame_head = head_killer->child;
        while (frame_head)
        {
            EschKeyframe *frame_killer = frame_head->child;
            while (frame_killer)
            {
                EschKeyframe *prev_frame = frame_killer;
                frame_killer = frame_killer->child;
                delete prev_frame;
            }
            EschKeyframe *prev_frame_head = frame_head;
            frame_head = frame_head->next;
            delete prev_frame_head;
        }
        EschKeyframeHeader *prev = head_killer;
        head_killer = head_killer->next;
        delete prev;
    }
    list = 0;
    count = 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframer - get
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EschKeyframe *EschKeyframer::get (esch_limb_type ltype, char *mtype,
                                  int frame_num, EschKeyframeHeader *head)
{
    EschKeyframeHeader  *motion;
    EschKeyframe        *framenum=0;
    EschKeyframe        *frame=0;

    // Search through the headers for mtype
    if (!head)
    {
        motion = list;
        while (motion && (strcmp(motion->m_type, mtype)))
        {
            motion = motion->next;
        }
    }
    else
    {
        motion = head;
        while (motion && strcmp(motion->m_type, mtype))
        {
            motion = motion->next;
        }
    }

    // Search through
    if (motion)
    {
        frame = motion->child;
        if (frame)
        {
            while (frame && ((frame->k_type&ltype) != frame->k_type))
            {
                frame = frame->next;
            }
        }
        if (frame)
        {
            framenum = frame;
            while (framenum && (framenum->frame_num != frame_num))
            {
                framenum = framenum->child;
            }
        }
    }
    if (framenum)
    {
        if (framenum->frame_num == frame_num)
        {
            return (framenum);
        }
    }
    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframer - load
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
esch_error_codes EschKeyframer::load (const char *filename)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//ÄÄ Open file
    if (iff.open(filename,XF_OPEN_READ | XF_OPEN_DENYWRITE))
        return ESCH_ERR_FILEERROR;

//ÄÄ Loop until data found
    err=ESCH_ERR_NONE;

    for (;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
            continue;
        }

        if (iff.chunkid == iff.makeid('F','O','R','M')
            && iff.formid == iff.makeid ('K','E','Y','F'))
        {
            err=load(&iff);
            if (!err
                || err != ESCH_ERR_NOTFOUND)
                break;
        }

        // Must scan inside any ESEN/EMSH forms.
        else if (iff.chunkid == iff.makeid('F','O','R','M')
                 && (iff.formid == iff.makeid('E','S','E','N')
                     || iff.formid == iff.makeid('E','M','S','H')))
        {
            iff.enterform();
        }

    }
    iff.close();
    return err;
}

esch_error_codes EschKeyframer::load (XFParseIFF *iff)
{
    // The data is placed into sub-trees off of a linked list of EschKeyframeHeaders
    // The sub-trees are linked lists based on LimbSegment type
    // The basic structure "looks" like the following:
    //  /----\          /----\
    //  |walk|--------->|jump|
    //  \----/          \----/
    //    \/              \/
    //  /----\  /----\  /----\  /----\  /----\  /----\
    //  | 0  |->| 0  |  | 0  |->| 0  |->| 0  |->| 0  |
    //  |hand|  |foot|  |foot|  |hand|  |head|  |shin|
    //  \----/  \----/  \----/  \----/  \----/  \----/
    //    \/      \/      \/      \/      \/      \/
    //  /----\  /----\  /----\  /----\  /----\  /----\
    //  | 1  |  | 1  |  | 1  |  | 1  |  | 1  |  | 1  |
    //  |hand|  |foot|  |foot|  |hand|  |head|  |shin|
    //  \----/  \----/  \----/  \----/  \----/  \----/
    //    \/      \/      \/      \/      \/      \/
    //  /----\  /----\  /----\  /----\  /----\  /----\
    //  | 2  |  | 2  |  | 2  |  | 2  |  | 2  |  | 2  |
    //  |hand|  |foot|  |foot|  |hand|  |head|  |shin|
    //  \----/  \----/  \----/  \----/  \----/  \----/

    assertMyth("EschKeyframer::load needs a valid iff pointer",
               iff);

//ÄÄ Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('K','E','Y','F'))
        return ESCH_ERR_NOTFOUND;

    EschFileKeyframeHeader header;

//ÄÄ Enter FORM, find header
    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(header))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

//ÄÄ Read header
    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

//ÄÄ Process chunks
    // read a chunk
    // search for the type in list
    // if there is not a header of the correct type, add the header
    // once header is determined, place the node in the correct
    //  keyframe position

    while (!iff->next())
    {
        //ÄÄ Read Key Data
        EschFileKeyframe key;

        if (iff->chunkid == iff->makeid('K','E','Y','1'))
        {
            if (iff->chunkSize != sizeof(key))
            {
                iff->leaveform();
                return ESCH_ERR_INVALIDDATA;
            }

            if (iff->read(&key))
            {
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }
#if 0
            if (key.k_type & ESCH_KEYFRAME_ROOT)
//                && key.frame_num == 0)
            {
                key.rotation[0] = 0;
                key.rotation[1] = 0;
                key.rotation[2] = 0;
            }
#endif
        }
        else if (iff->chunkid == iff->makeid('K','E','Y',' '))
        {
            EschFileKeyframeV1 v1key;

            if (iff->chunkSize != sizeof(v1key))
            {
                iff->leaveform();
                return ESCH_ERR_INVALIDDATA;
            }

            if (iff->read(&v1key))
            {
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }

            key.k_type = v1key.k_type;
            key.frame_num = v1key.frame_num;
            key.rotation[0] = v1key.rotation[0] / 65536.0f;
            key.rotation[1] = v1key.rotation[1] / 65536.0f;
            key.rotation[2] = v1key.rotation[2] / 65536.0f;
#if 0
            if (key.k_type & ESCH_KEYFRAME_ROOT
                && key.frame_num == 0)
            {
                key.rotation[0] = 0;
                key.rotation[1] = 0;
                key.rotation[2] = 0;
            }
#endif
        }
        else
        {
            continue;
        }

        //ÄÄ Put into data structure
        // search for m_type in list
        if (!list)
        {
            // list is empty
            // header_step is automatically the first list entry
            list = new EschKeyframeHeader;
            if (!list)
            {
                iff->leaveform();
                return ESCH_ERR_NOMEMORY;
            }
            list->next = 0;

            strncpy (list->m_type, header.m_type, M_TYPE_LEN);
            list->flags = header.flags;
            list->key_depth = header.key_depth;

            list->chain_prev = NULL;
            list->chain_next = NULL;

            list->child = 0;
        }

        EschKeyframeHeader *header_step = list;

        while (header_step)
        {
            if (!strncmp (header_step->m_type,header.m_type, M_TYPE_LEN))
            {
                break;
            }
            header_step = header_step->next;
        }

        if (!header_step)
        {
            // header_step->m_type not found in list
            header_step = list;
            while (header_step->next)
            {
                header_step = header_step->next;
            }
            header_step->next = new EschKeyframeHeader;
            header_step = header_step->next;

            strncpy (header_step->m_type, header.m_type, M_TYPE_LEN);
            header_step->flags = header.flags;
            header_step->key_depth = header.key_depth;

            list->chain_next = NULL;
            list->chain_prev = NULL;

            header_step->child = 0;
        }

        if (header_step)
        {
            EschKeyframe *frame_step = header_step->child;
            if (frame_step)
            {
                while (frame_step->next
                       && (frame_step->k_type != key.k_type))
                {
                    frame_step = frame_step->next;
                }

                if (frame_step->k_type == key.k_type)
                {
                    // insertion sort into linked list
                    EschKeyframe *frame_num_step = frame_step;
                    if (frame_num_step->frame_num < key.frame_num)
                    {
                        EschKeyframe *frame_temp;

                        while (frame_num_step->child
                               && (frame_num_step->child->frame_num < key.frame_num))
                        {
                            frame_num_step = frame_num_step->child;
                        }

                        if (!frame_num_step->child)
                        {
                            if (frame_num_step->frame_num != key.frame_num)
                            {
                                frame_num_step->child = new EschKeyframe;
                                if (!frame_num_step->child)
                                {
                                    iff->leaveform();
                                    return ESCH_ERR_NOMEMORY;
                                }
                                frame_temp = frame_num_step->child;
                                frame_temp->next = 0;
                                frame_temp->child = 0;
                            }
                        }
                        else if (frame_num_step->child->frame_num > key.frame_num)
                        {
                            // insert keyframe between frame_num_step and frame_num_step->child;
                            frame_temp = new EschKeyframe;
                            if (!frame_temp)
                            {
                                iff->leaveform();
                                return ESCH_ERR_NOMEMORY;
                            }
                            frame_temp->child = frame_num_step->child->child;
                            frame_temp->next = 0;
                            frame_num_step->child = frame_temp;
                        }
                        else if (frame_num_step->child->frame_num == key.frame_num)
                        {
                            // do nothing.  It's already loaded
                        }
                        frame_temp->k_type = key.k_type;
                        frame_temp->rotations.i = key.rotation[0];
                        frame_temp->rotations.j = key.rotation[1];
                        frame_temp->rotations.k = key.rotation[2];
                        frame_temp->frame_num = key.frame_num;
                        frame_temp->root = header_step;
                        frame_temp->parent = frame_num_step;
                    }
                    else
                    {
                        EschKeyframe *frame_temp;

                        // new keyframe needs to be head of sublist
                        // go back and find the previous
                        if (header_step->child == frame_step)
                        {
                            frame_temp = new EschKeyframe;
                            if (!frame_temp)
                            {
                                iff->leaveform();
                                return ESCH_ERR_NOMEMORY;
                            }
                            frame_temp->next = frame_step->next;
                            frame_temp->child = frame_step;
                            header_step->child = frame_temp;
                            frame_step->next = 0;
                        }
                        else
                        {
                            EschKeyframe *prev_step = header_step->child;
                            while (prev_step->next != frame_step)
                            {
                                prev_step = prev_step->next;
                            }
                            frame_temp = new EschKeyframe;
                            if (!frame_temp)
                            {
                                iff->leaveform();
                                return ESCH_ERR_NOMEMORY;
                            }
                            frame_temp->next = frame_step->next;
                            frame_temp->child = frame_step;
                            prev_step->next = frame_temp;
                            frame_step->next = 0;
                        }
                        frame_temp->rotations.i = key.rotation[0];
                        frame_temp->rotations.j = key.rotation[1];
                        frame_temp->rotations.k = key.rotation[2];
                        frame_temp->k_type = key.k_type;
                        frame_temp->frame_num = key.frame_num;
                        frame_temp->root = header_step;
                        frame_temp->parent = NULL;
                    }
                }
                else if (!frame_step->next)
                {
                    frame_step->next = new EschKeyframe;
                    if (!frame_step->next)
                    {
                        iff->leaveform();
                        return ESCH_ERR_NOMEMORY;
                    }
                    EschKeyframe *frame_temp = frame_step->next;
                    frame_temp->child = 0;
                    frame_temp->next = 0;
                    frame_temp->rotations.i = key.rotation[0];
                    frame_temp->rotations.j = key.rotation[1];
                    frame_temp->rotations.k = key.rotation[2];
                    frame_temp->k_type = key.k_type;
                    frame_temp->frame_num = key.frame_num;
                    frame_temp->root = header_step;
                    frame_temp->parent = NULL;
                }
            }
            else
            {
                header_step->child = new EschKeyframe;
                if (!header_step->child)
                {
                    iff->leaveform();
                    return ESCH_ERR_NOMEMORY;
                }
                frame_step = header_step->child;
                frame_step->k_type = key.k_type;
                frame_step->rotations.i = key.rotation[0];
                frame_step->rotations.j = key.rotation[1];
                frame_step->rotations.k = key.rotation[2];
                frame_step->child = 0;
                frame_step->next = 0;
                frame_step->frame_num = key.frame_num;
                frame_step->root = header_step;
                frame_step->parent = NULL;
            }
        }
        count++;
    }

    iff->leaveform();

    return update_chaining();
}

esch_error_codes EschKeyframer::update_chaining()
{
    return ESCH_ERR_NONE;
}

int EschKeyframer::get_chain_count()
{
    int chain_count = 0;
    EschKeyframeHeader *step = list;

    while (step)
    {
        step = step->next;
        chain_count ++;
    }

    return chain_count;
}

void EschKeyframer::get_next_chain_type(char *find, char *set)
{
    if (!set || !list)
        return;

    if (!find)
    {
        strcpy (set, list->m_type);
        return;
    }

    EschKeyframeHeader *step = list;

    while (step && strcmp (step->m_type, find))
    {
        step = step->next;
    }
    if (step)
    {
        step = step->next;
    }
    if (step)
    {
        strcpy (set, step->m_type);
    }
    else
    {
        set[0] = 0;
    }
}

//°±² End of module - eskeyfrm.cpp ²±°
