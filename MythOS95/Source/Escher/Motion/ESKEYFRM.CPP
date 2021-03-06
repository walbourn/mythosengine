//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

#include "esfile.hpp"
#include "estoken.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                Defines
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�


//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

EschKeyframer *EschKeyframeMan = 0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschKeyframer - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschKeyframer::EschKeyframer() :
    count (0),
    list (0)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschKeyframer - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschKeyframer::~EschKeyframer()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschKeyframer - release
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschKeyframer - get
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschKeyframer - load
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschKeyframer::load (const char *filename)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//陳 Open file
    if (iff.open(filename,XF_OPEN_READ | XF_OPEN_DENYWRITE))
        return ESCH_ERR_FILEERROR;

//陳 Loop until data found
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

//陳 Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('K','E','Y','F'))
        return ESCH_ERR_NOTFOUND;

    EschFileKeyframeHeader header;

//陳 Enter FORM, find header
    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(header))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

//陳 Read header
    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

//陳 Process chunks
    // read a chunk
    // search for the type in list
    // if there is not a header of the correct type, add the header
    // once header is determined, place the node in the correct
    //  keyframe position

    while (!iff->next())
    {
        //陳 Read Key Data
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

        //陳 Put into data structure
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

//葦� End of module - eskeyfrm.cpp 憶�
