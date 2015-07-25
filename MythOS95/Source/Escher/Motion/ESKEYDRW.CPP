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
//ùùùùùùùùùùùCopyrightù(c)ù1994-1997ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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
// Created by Paul Masters
//
// eskeydrw.cpp
//
// Contains the code for the EschKeyframeDraw class.  This class is
// the base class for a constrained pitch, yaw, roll object.  The LimbSegment
// is assumed to be a part of an EschLimb object which is a collector class.
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
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EschKeyframeDraw::EschKeyframeDraw() :
    EschMeshDraw(),
    step_pitch (0),
    step_roll (0),
    step_yaw (0),
    current_pitch (0),
    current_roll (0),
    current_yaw (0),
    first_step (1)
{
    init_keys();
    dtyp = ESCH_DRWT_SKELETON;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EschKeyframeDraw::~EschKeyframeDraw()
{
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - init_rotations
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::init_rotations(float time)
{
    current_pitch=0;
    current_roll=0;
    current_yaw=0;
    step_pitch=0;
    step_roll=0;
    step_yaw=0;
    rest_pitch = 0;
    rest_roll = 0;
    rest_yaw = 0;
    for (int i=0; i<ESCH_MAX_SIMULTANEOUS; i++)
    {
        keyheads[i] = 0;
        keyframes[i] = 0;
        next_keyframes[i] = 0;
        steps[i].i = 0.0f;
        steps[i].j = 0.0f;
        steps[i].k = 0.0f;
        tweens[i].i = 0.0f;
        tweens[i].j = 0.0f;
        tweens[i].k = 0.0f;
        tween_step[i] = 0.0f;
        prev_stamp[i] = time;
        current_stamp[i] = time;
        activity[i] = FALSE;
        prev_shift[i] = 0.0f;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - init_keys
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::init_keys(float time)
{
    for (int i=0; i<ESCH_MAX_SIMULTANEOUS; i++)
    {
        keyheads[i] = 0;
        keyframes[i] = 0;
        next_keyframes[i] = 0;
        steps[i].i = 0.0f;
        steps[i].j = 0.0f;
        steps[i].k = 0.0f;
        tweens[i].i = 0.0f;
        tweens[i].j = 0.0f;
        tweens[i].k = 0.0f;
        tween_step[i] = 0.0f;
        ping_pong[i] = 0;
        total_times[i] = 0.0f;
        step_times[i] = 0.0f;
        activity[i] = FALSE;
        prev_stamp[i] = time;
        current_stamp[i] = time;
        prev_shift[i] = 0.0f;
    }
    key_chain_count = 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - step
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EschKeyframeDraw::step(float interval, float scalar, float time, float shift)
{
    int retval=0;
    int retval2=0;

    // interval is the amount of time that has passed since the previous frame

    for (int i=0; i<key_chain_count; i++)
    {
//        if (tween_step[i] >= total_times[i])
        if (activity[i])
        {
            // calculate this key step

            // calc step from current key to next key
            calc_step(i,interval,shift);

            //
            init_tween(i);
            if (scalar != 0.0f)
            {
                scale_step(i, scalar);
            }

            // step pointers for the next key
            retval = get_next_key(i,interval,time,shift);
            if (retval > 0)
            {
                if (keyheads[i]->root->flags & ESCH_KEYFRAME_SWAPPING_1
                    || keyheads[i]->root->flags & ESCH_KEYFRAME_SWAPPING_2)
                {
                    tween_step[i] = 2 * step_times[i];
                }
                else
                {
                    tween_step[i] = step_times[i];
                }
            }
        }
    }
    if ((key_chain_count) && (retval>=0))
    {
        build_keyframe(scalar, interval);
        do_rotations(&work);
    }

    if ((!(k_type & ESCH_KEYFRAME_ROOT)) && next() &&
        (next()->get_type()==ESCH_DRWT_SKELETON))
    {
        retval2 = ((EschKeyframeDraw *)next())->step(interval, scalar,time,shift);
    }
    if (child() &&
        (child()->get_type()==ESCH_DRWT_SKELETON))
    {
        retval2 = ((EschKeyframeDraw *)child())->step(interval, scalar,time,shift);
    }
    return (retval|retval2);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - set_key
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EschKeyframeDraw::set_key(EschKeyframe *key, float scalar, float chain_time)
{
    // find an empty spot
    // if none found, cancel one of the ones that is going
    int keynum;
    if (get_type()==ESCH_DRWT_SKELETON)
    {
        keynum = get_keyframe_spot(key);

        keyheads[keynum] = key;
        keyframes[keynum] = key;

        // count the number of keyframes
        EschKeyframe *ptr = keyheads[keynum];
        float cnt = 0;
        if (ptr)
        {
            while (ptr->child)
            {
                ptr = ptr->child;
            }
            cnt = float(ptr->frame_num);
        }
        if (cnt > 0.0f)
        {
            step_times[keynum] = chain_time / cnt;
        }
        else
        {
            step_times[keynum] = 1.0f;
        }

        total_times[keynum] = chain_time;

        if (keyframes[keynum]->child)
        {
            next_keyframes[keynum] = keyframes[keynum]->child;
        }
        else
        {
            next_keyframes[keynum] = keyframes[keynum];
        }
        calc_step(keynum);
        init_tween(keynum);
        if (scalar != 0.0f)
        {
            scale_step(keynum, scalar);
        }
        if ((!(k_type&ESCH_KEYFRAME_ROOT)) &&
            (next() && (next()->get_type()==ESCH_DRWT_SKELETON)))
        {
            EschKeyframe *temp;
            temp = EschKeyframeMan->get (((EschLimbSegment *)next())->get_ktype(), key->root->m_type, 0);
            ((EschKeyframeDraw *)next())->set_key (temp, scalar, chain_time);
        }

        if (child() && (child()->get_type()==ESCH_DRWT_SKELETON))
        {
            EschKeyframe *temp;
            temp = EschKeyframeMan->get (((EschLimbSegment *)child())->get_ktype(), key->root->m_type, 0);
            ((EschKeyframeDraw *)child())->set_key(temp, scalar, chain_time);
        }

        activity[keynum] = TRUE;
        return(keynum);
    }
    return (-1);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - reset_keys
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::reset_keys()
{
    for (int i=0; i<key_chain_count; i++)
    {
        reset_key(i);
        calc_step(i);
        init_tween(i);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - reset_key
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::reset_key (int num)
{
    keyframes[num] = keyheads[num];
    if (keyframes[num]->child)
    {
        next_keyframes[num] = keyframes[num]->child;
    }
    else
    {
        next_keyframes[num] = keyframes[num];
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - do_keyframe
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::do_keyframe(EschKeyframe *frame)
{
    memcpy (&local, &home, sizeof(local));

    step_pitch = frame->rotations.i;
    current_pitch = step_pitch;

    step_roll = frame->rotations.j;
    current_roll = step_roll;

    step_yaw = frame->rotations.k;
    current_yaw = step_yaw;

    local.yaw (current_yaw, 0);
    local.pitch (current_pitch, 0);
    local.roll (current_roll);
    local.orthogonalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - do_rotations
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::do_rotations(EschVector *rot)
{
    memcpy (&local, &home, sizeof(local));

    step_pitch = rot->i;
    current_pitch = step_pitch;

    step_roll = rot->j;
    current_roll = step_roll;

    step_yaw = rot->k;
    current_yaw = step_yaw;

    local.yaw (current_yaw);
    local.pitch (current_pitch);
    local.roll (current_roll);
    local.orthogonalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - swap_motion
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EschKeyframeDraw::swap_motion (char *str1, char *str2)
{
    if (!str1 || !str2)
    {
        return 0;
    }
    if (!strcmp (str1,str2))
    {
        return 0;
    }
    for (int i=0; i<key_chain_count; i++)
    {
        if (!strcmp (str1, keyheads[i]->root->m_type))
        {
            // found a match
            EschKeyframe *temp = EschKeyframeMan->get (k_type, str2, 0);
            if (temp)
            {
                keyheads[i] = temp;
            }
            keyframes[i] = temp;
            next_keyframes[i] = keyframes[i]->child;
            calc_step (i);
            init_tween (i);

            steps[i] *= 0;

            if (!(k_type&ESCH_KEYFRAME_ROOT))
            {
                if (next())
                {
                    ((EschKeyframeDraw *)next())->swap_motion(str1,str2);
                }
            }
            if (child())
            {
                ((EschKeyframeDraw *)child())->swap_motion(str1,str2);
            }
            return 1;
        }
    }
    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - reset_keyframes
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::reset_keyframes(int num, float time, float interval)
{
    if (!(k_type & ESCH_KEYFRAME_ROOT))
    {
        return;
    }

    keyframes[num] = keyheads[num];
    if (keyframes[num]->child)
    {
        next_keyframes[num] = keyframes[num]->child;
    }
    else
    {
        next_keyframes[num] = keyframes[num];
    }
    prev_stamp[num] = current_stamp[num];
    current_stamp[num] = time;
    tween_step[num] = 0;
    calc_step (num);
    init_tween (num);
    build_keyframe(1.0f,interval);
    do_rotations(&work);
    if (child())
    {
        ((EschKeyframeDraw *)child())->reset_children(num, time, interval);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - reset_children
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::reset_children(int num, float time, float interval)
{
    prev_stamp[num] = current_stamp[num];
    current_stamp[num] = time;
    keyframes[num] = keyheads[num];
    if ((keyframes[num]->root->flags & ESCH_KEYFRAME_LOOPING)
        && (keyframes[num]->child))
    {
        next_keyframes[num] = keyframes[num]->child;
    }
    else
    {
        next_keyframes[num] = keyframes[num];
    }
    tween_step[num] = 0;
    calc_step (num);
    init_tween (num);
    build_keyframe(1.0f,interval);
    do_rotations(&work);

    if (next())
    {
        ((EschKeyframeDraw *)next())->reset_children(num, time, interval);
    }
    if (child())
    {
        ((EschKeyframeDraw *)child())->reset_children(num, time, interval);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
// EschKeyframeDraw - calc_step
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::calc_step(int num, float interval, float shift)
{
    steps[num] = next_keyframes[num]->rotations - keyframes[num]->rotations;

    // we want the percentage of one keyframe that occurs in our interval?
    // we want the amount of interval that steps into our current key...
    // we want to build a step based off of that amount / step_times[num]

    // interval is the time from the last tween frame
    // we need expected times for our actual keys
    // tween time is the sliver of time that extends over our key time

    float extend_time;

    extend_time = (prev_stamp[num] + (interval * shift)) - current_stamp[num];
    float sliver;

    if (prev_shift[num] != shift
        || shift > 4.0f)
    {
        sliver = 1.0f;
        prev_shift[num] = shift;
    }
    else
    {
        sliver = extend_time / step_times[num];
    }

    steps[num] *= sliver;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
// EschKeyframeDraw - init_tween
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::init_tween(int num)
{
    if (keyframes[num])
    {
        tweens[num] = keyframes[num]->rotations;
//        tween_step[num] = 0.0f;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
// EschKeyframeDraw - build_keyframe
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::build_keyframe(float scalar, float interval)
{
    // take primary_keyframe and secondary_keyframe
    // build tweens for them with next_primary and next_secondary

    for (int i=0; i<key_chain_count; i++)
    {
        if (activity[i])
        {
            tweens[i].i += steps[i].i;
            tweens[i].j += steps[i].j;
            tweens[i].k += steps[i].k;
            if (scalar != 0.0f)
            {
                tween_step[i] += interval;
            }
        }
    }

    if (activity[0])
    {
        work.i = (tweens[0].i * scalar);
        work.j = (tweens[0].j * scalar);
        work.k = (tweens[0].k * scalar);
    }
    else
    {
        work.i = 0;
        work.j = 0;
        work.k = 0;
    }

    for (i=1; i<key_chain_count; i++)
    {
        if (activity[i])
        {
            work.i += (tweens[i].i * scalar);
            work.j += (tweens[i].j * scalar);
            work.k += (tweens[i].k * scalar);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
// EschKeyframeDraw - get_keyframe_spot
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EschKeyframeDraw::get_keyframe_spot(EschKeyframe *key)
{
    // first, see if the keyframe is already in the list
    for (int i=0; i<key_chain_count; i++)
    {
        // find its position and return
        if (keyheads[i] == key)
        {
            // its already here
            return (i);
        }
    }

    if (key_chain_count == ESCH_MAX_SIMULTANEOUS)
    {
        // list is full
        // find and remove any keyframe chains (m_types) that can be removed
        remove_key_chains(key->root->m_type);
    }
    // now set the data
    keyheads[key_chain_count] = key;
    keyframes[key_chain_count] = key;
    if (key->child)
    {
        next_keyframes[key_chain_count] = key->child;
    }
    else
    {
        next_keyframes[key_chain_count] = key;
    }

    key_chain_count ++;
    return (key_chain_count-1);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
// EschKeyframeDraw - remove_key_chains
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::remove_key_chains(char *mt)
{
    for (int i=0; i<key_chain_count; i++)
    {
        remove_key(i);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
// EschKeyframeDraw - remove_key
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::remove_key (int num)
{
    for (int i=num; i<key_chain_count; i++)
    {
        keyheads[i] = keyheads[i+1];
        keyframes[i] = keyframes[i+1];
        next_keyframes[i] = next_keyframes[i+1];
    }
    key_chain_count--;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
// EschKeyframeDraw - swap_lead_trail
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::swap_lead_trail (int num, float side_vel)
{
    // needs to test for negative terrain pitch
    // a negative terrain pitch implies that the swapping should not occur until
    //  the leading foot is firmly planted on the ground.
    // the leading foot needs to be tested for grounded-ness because the rear
    //  shin rotation cannot be specifically derived from terrain elevation
    //  changes

    // keyheads[num] needs to move
    // next_keyframes[num] needs to change to new keyheads[num]
    // keyframes[num] needs to stay where it is

    if (keyheads[num]->root->flags & (ESCH_KEYFRAME_LOOPING |
                                      ESCH_KEYFRAME_SWAPPING_1 |
                                      ESCH_KEYFRAME_SWAPPING_2 ))
    {
        if (!(keyheads[num]->root->flags & ESCH_KEYFRAME_CHAINING))
        {
            if (keyheads[num]->root->flags & ESCH_KEYFRAME_SWAPPING_1)
            {
                if (keyheads[num]->root->flags & ESCH_KEYFRAME_PING_PONG)
                {
                    ping_pong[num] = !ping_pong[num];
                }
                else
                {
                    ulong type = keyheads[num]->k_type;
                    if (type & ESCH_KEYFRAME_LEADING)
                    {
                        type &= ~ESCH_KEYFRAME_LEADING;
                        type |= ESCH_KEYFRAME_TRAILING;
                    }
                    else if (type & ESCH_KEYFRAME_TRAILING)
                    {
                        type &= ~ESCH_KEYFRAME_TRAILING;
                        type |= ESCH_KEYFRAME_LEADING;
                    }

                    if (k_type & ESCH_KEYFRAME_LEADING)
                    {
                        k_type &= ~ESCH_KEYFRAME_LEADING;
                        k_type |= ESCH_KEYFRAME_TRAILING;
                    }
                    else if (k_type & ESCH_KEYFRAME_TRAILING)
                    {
                        k_type &= ~ESCH_KEYFRAME_TRAILING;
                        k_type |= ESCH_KEYFRAME_LEADING;
                    }
                    EschKeyframe *temp = EschKeyframeMan->get(type, keyheads[num]->root->m_type, 0, keyheads[num]->root);
                    if (temp)
                    {
                        keyheads[num] = temp;
                    }
                }
            }
            else if (keyheads[num]->root->flags & ESCH_KEYFRAME_SWAPPING_2)
            {
                if (keyheads[num]->root->flags & ESCH_KEYFRAME_PING_PONG)
                {
                    ping_pong[num] = !ping_pong[num];
                }
                else
                {
                    ulong type = keyheads[num]->k_type;
                    if (type & ESCH_KEYFRAME_LEADING_2)
                    {
                        type &= ~ESCH_KEYFRAME_LEADING_2;
                        type |= ESCH_KEYFRAME_TRAILING_2;
                    }
                    else if (type & ESCH_KEYFRAME_TRAILING_2)
                    {
                        type &= ~ESCH_KEYFRAME_TRAILING_2;
                        type |= ESCH_KEYFRAME_LEADING_2;
                    }

                    if (k_type & ESCH_KEYFRAME_LEADING_2)
                    {
                        k_type &= ~ESCH_KEYFRAME_LEADING_2;
                        k_type |= ESCH_KEYFRAME_TRAILING_2;
                    }
                    else if (k_type & ESCH_KEYFRAME_TRAILING_2)
                    {
                        k_type &= ~ESCH_KEYFRAME_TRAILING_2;
                        k_type |= ESCH_KEYFRAME_LEADING_2;
                    }
                    EschKeyframe *temp = EschKeyframeMan->get(type, keyheads[num]->root->m_type, 0, keyheads[num]->root);
                    if (temp)
                    {
                        keyheads[num] = temp;
                    }
                }
            }
        }
        else
        {
            ulong type = keyheads[num]->k_type;
            if (k_type & ESCH_KEYFRAME_LEADING)
            {
                k_type &= ~ESCH_KEYFRAME_LEADING;
                k_type |= ESCH_KEYFRAME_TRAILING;
            }
            else if (k_type & ESCH_KEYFRAME_TRAILING)
            {
                k_type &= ~ESCH_KEYFRAME_TRAILING;
                k_type |= ESCH_KEYFRAME_LEADING;
            }


            if (side_vel > 0) // stepping right
            {
                if (strstr(keyheads[num]->root->m_type, "WALKING_SIDE_IN"))
                {
                    if (k_type & ESCH_KEYFRAME_LEFT)
                    {
                        type &= ~ESCH_KEYFRAME_TRAILING;
                        type |= ESCH_KEYFRAME_LEADING;
                    }
                    else if (k_type & ESCH_KEYFRAME_RIGHT)
                    {
                        type &= ~ESCH_KEYFRAME_LEADING;
                        type |= ESCH_KEYFRAME_TRAILING;
                    }
                    EschKeyframe *temp = EschKeyframeMan->get(type, "WALKING_SIDE_OUT_R", 0, 0);
                    if (temp)
                    {
                        keyheads[num] = temp;
                    }
                }
                else
                {
                    if (k_type & ESCH_KEYFRAME_LEFT)
                    {
                        type &= ~ESCH_KEYFRAME_TRAILING;
                        type |= ESCH_KEYFRAME_LEADING;
                    }
                    else if (k_type & ESCH_KEYFRAME_RIGHT)
                    {
                        type &= ~ESCH_KEYFRAME_LEADING;
                        type |= ESCH_KEYFRAME_TRAILING;
                    }
                    EschKeyframe *temp = EschKeyframeMan->get(type, "WALKING_SIDE_IN_R", 0, 0);
                    if (temp)
                    {
                        keyheads[num] = temp;
                    }
                }
            }
            else
            {
                if (strstr(keyheads[num]->root->m_type, "WALKING_SIDE_OUT"))
                {
                    if (k_type & ESCH_KEYFRAME_LEFT)
                    {
                        type &= ~ESCH_KEYFRAME_TRAILING;
                        type |= ESCH_KEYFRAME_LEADING;
                    }
                    else if (k_type & ESCH_KEYFRAME_RIGHT)
                    {
                        type &= ~ESCH_KEYFRAME_LEADING;
                        type |= ESCH_KEYFRAME_TRAILING;
                    }
                    EschKeyframe *temp = EschKeyframeMan->get(type, "WALKING_SIDE_IN_L", 0, 0);
                    if (temp)
                    {
                        keyheads[num] = temp;
                    }
                }
                else
                {
                    if (k_type & ESCH_KEYFRAME_LEFT)
                    {
                        type &= ~ESCH_KEYFRAME_TRAILING;
                        type |= ESCH_KEYFRAME_LEADING;
                    }
                    else if (k_type & ESCH_KEYFRAME_RIGHT)
                    {
                        type &= ~ESCH_KEYFRAME_LEADING;
                        type |= ESCH_KEYFRAME_TRAILING;
                    }
                    EschKeyframe *temp = EschKeyframeMan->get(type, "WALKING_SIDE_OUT_L", 0, 0);
                    if (temp)
                    {
                        keyheads[num] = temp;
                    }
                }
            }
            ping_pong[num] = 0;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
// EschKeyframeDraw - scale_step
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::scale_step (int num, float scalar)
{
    // scale steps[num] by *scalar
    // velocity scalar
    steps[num].i *= scalar;
    steps[num].j *= scalar;
    steps[num].k *= scalar;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
//
// EschKeyframeDraw - get_next_key
// This is a big, ugly function.
// It has casing for multiple types of keyframe flags
// The casing is heavily dependant on other cases
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EschKeyframeDraw::get_next_key(int num, float interval, float time, float shift)
{
    // figure out which keyframe we want next
    int next_framenum;
    int current_framenum = keyframes[num]->frame_num;
    int first_framenum;
    int last_framenum;

    prev_stamp[num] = current_stamp[num];
    current_stamp[num] = time;

    EschKeyframeHeader  *head = keyheads[num]->root;
    EschKeyframe        *keyhead = keyheads[num];
    EschKeyframe        *key = keyframes[num];
    EschKeyframe        *next = next_keyframes[num];
    ulong               temp_ktype;
    int                 swap_count = 0;
    int                 frame_count;

    head = keyheads[num]->root;
    frame_count = head->key_depth;
    dword _flags = head->flags;
    last_framenum = head->key_depth - 1;


    // calculate the first frame
    if ((_flags & ESCH_KEYFRAME_SWAPPING_1)
        || (_flags & ESCH_KEYFRAME_SWAPPING_2))
    {
        first_framenum = 2;
    }
    else
    {
        first_framenum = 1;
    }

    if (first_framenum > last_framenum)
    {
        // bad data error
        return ESCH_KEYFRAME_FRAMENUMSYNCERR;
    }

    // we know what our time step is
    // let's see if it creates underflow or overflow
    if ((_flags & ESCH_KEYFRAME_PING_PONG)
        && ping_pong[num])
    {
        next_framenum = current_framenum - int((interval / step_times[num]) * shift);
    }
    else
    {
        next_framenum = current_framenum + int((interval / step_times[num]) * shift);
    }

    // now let's set current and next
    if ((next_framenum > last_framenum
            || next_framenum < first_framenum))
    {
        // determine how far past the ends we have gone
        swap_count = next_framenum / frame_count;

        if (_flags & ESCH_KEYFRAME_CHAINING)
        {
            // determine which EschKeyframeHeader to look at
            if (_flags & ESCH_KEYFRAME_PING_PONG
                && ping_pong[num])
            {
                head = keyheads[num]->root->chain_prev;
                if (!head && _flags & ESCH_KEYFRAME_LOOPING)
                {
                    head = keyheads[num]->root;
                }
            }
            else
            {
                head = keyheads[num]->root->chain_next;
                if (!head && _flags & ESCH_KEYFRAME_LOOPING)
                {
                    EschKeyframeHeader *stepper = keyheads[num]->root;
                    if (stepper)
                    {
                        while (stepper->chain_prev)
                        {
                            stepper = stepper->chain_prev;
                        }
                    }
                    if (stepper)
                    {
                        head = stepper;
                    }
                    else
                    {
                        head = keyheads[num]->root;
                    }
                }
            }
        }

        // determine which keyhead to look at
        temp_ktype = keyheads[num]->k_type;
        if (_flags & ESCH_KEYFRAME_SWAPPING_1)
        {
            if (temp_ktype & ESCH_KEYFRAME_LEADING)
            {
                temp_ktype &= ~ESCH_KEYFRAME_LEADING;
                temp_ktype |= ESCH_KEYFRAME_TRAILING;
                k_type &= ~ESCH_KEYFRAME_LEADING;
                k_type |= ESCH_KEYFRAME_TRAILING;
            }
            else if (temp_ktype & ESCH_KEYFRAME_TRAILING)
            {
                temp_ktype &= ~ESCH_KEYFRAME_TRAILING;
                temp_ktype |= ESCH_KEYFRAME_LEADING;
                k_type &= ~ESCH_KEYFRAME_TRAILING;
                k_type |= ESCH_KEYFRAME_LEADING;
            }
        }
        else if (_flags & ESCH_KEYFRAME_SWAPPING_2)
        {
            if (temp_ktype & ESCH_KEYFRAME_LEADING_2)
            {
                temp_ktype &= ~ESCH_KEYFRAME_LEADING_2;
                temp_ktype |= ESCH_KEYFRAME_TRAILING_2;
                k_type &= ~ESCH_KEYFRAME_LEADING_2;
                k_type |= ESCH_KEYFRAME_TRAILING_2;
            }
            else if (temp_ktype & ESCH_KEYFRAME_TRAILING_2)
            {
                temp_ktype &= ~ESCH_KEYFRAME_TRAILING_2;
                temp_ktype |= ESCH_KEYFRAME_LEADING_2;
                k_type &= ~ESCH_KEYFRAME_TRAILING_2;
                k_type |= ESCH_KEYFRAME_LEADING_2;
            }
        }

        keyhead = EschKeyframeMan->get(temp_ktype, head->m_type, 0, head);

        // determine which keyframe to look at
        EschKeyframe *stepper = keyhead;

        // move next_framenum until it is in proper range
        if (_flags & ESCH_KEYFRAME_LOOPING)
        {
            while (next_framenum > last_framenum)
            {
                next_framenum -= (head->key_depth-first_framenum);
                if (next_framenum < first_framenum)
                {
                    next_framenum = first_framenum;
                }
            }
            while (next_framenum < first_framenum)
            {
                next_framenum += (head->key_depth-first_framenum);
                if (next_framenum > last_framenum)
                {
                    next_framenum = last_framenum;
                }
            }
        }
        else
        {
            if (_flags & ESCH_KEYFRAME_PING_PONG
                && ping_pong[num])
            {
                if (_flags & ESCH_KEYFRAME_CHAINING)
                {
                    if (head == keyheads[num]->root)
                    {
                        // reached the end of the chain
                        next_framenum = last_framenum;
                        EschKeyframe *stepper = keyhead;
                        if (stepper)
                        {
                            while (stepper->frame_num != next_framenum)
                            {
                                stepper = stepper->child;
                            }
                        }
                        if (stepper)
                        {
                            key = stepper;
                        }
                        else
                        {
                            // error because the data is bad
                            return ESCH_KEYFRAME_DATAERROR;
                        }
                        next = key;

                        keyheads[num] = keyhead;
                        keyframes[num] = key;
                        next_keyframes[num] = next;

                        return (ESCH_KEYFRAME_LOOPEND);
                    }
                    else
                    {
                        while (next_framenum > last_framenum)
                        {
                            next_framenum -= (head->key_depth-first_framenum);
                            if (next_framenum < first_framenum)
                            {
                                next_framenum = first_framenum;
                            }
                        }
                        while (next_framenum < first_framenum)
                        {
                            next_framenum += (head->key_depth-first_framenum);
                            if (next_framenum > last_framenum)
                            {
                                next_framenum = last_framenum;
                            }
                        }
                    }
                }
                else
                {
                    next_framenum = first_framenum;
                    EschKeyframe *stepper = keyhead;
                    if (stepper)
                    {
                        while (stepper->frame_num != next_framenum)
                        {
                            stepper = stepper->child;
                        }
                    }
                    if (stepper)
                    {
                        key = stepper;
                    }
                    else
                    {
                        // error because the data is bad
                        return ESCH_KEYFRAME_DATAERROR;
                    }
                    next = key;

                    keyheads[num] = keyhead;
                    keyframes[num] = key;
                    next_keyframes[num] = next;

                    return (ESCH_KEYFRAME_LOOPEND);
                }
            }
            else
            {
                if (_flags & ESCH_KEYFRAME_CHAINING)
                {
                    if (head == keyheads[num]->root)
                    {
                        // reached the end of the chain
                        next_framenum = last_framenum;
                        EschKeyframe *stepper = keyhead;
                        if (stepper)
                        {
                            while (stepper->frame_num != next_framenum)
                            {
                                stepper = stepper->child;
                            }
                        }
                        if (stepper)
                        {
                            key = stepper;
                        }
                        else
                        {
                            // error because the data is bad
                            return ESCH_KEYFRAME_DATAERROR;
                        }
                        next = key;

                        keyheads[num] = keyhead;
                        keyframes[num] = key;
                        next_keyframes[num] = next;

                        return (ESCH_KEYFRAME_LOOPEND);
                    }
                    else
                    {
                        while (next_framenum > last_framenum)
                        {
                            next_framenum -= (head->key_depth-first_framenum);
                            if (next_framenum < first_framenum)
                            {
                                next_framenum = first_framenum;
                            }
                        }
                        while (next_framenum < first_framenum)
                        {
                            next_framenum += (head->key_depth-first_framenum);
                            if (next_framenum > last_framenum)
                            {
                                next_framenum = last_framenum;
                            }
                        }
                    }
                }
                else
                {
                    next_framenum = last_framenum;
                    EschKeyframe *stepper = keyhead;
                    if (stepper)
                    {
                        while (stepper && stepper->frame_num != next_framenum)
                        {
                            stepper = stepper->child;
                        }
                    }
                    if (stepper)
                    {
                        key = stepper;
                    }
                    else
                    {
                        // error because the data is bad
                        return ESCH_KEYFRAME_DATAERROR;
                    }
                    next = key;

                    keyheads[num] = keyhead;
                    keyframes[num] = key;
                    next_keyframes[num] = next;

                    return (ESCH_KEYFRAME_LOOPEND);
                }
            }
        }

        while (stepper && stepper->frame_num != next_framenum)
        {
            stepper = stepper->child;
        }
        if (stepper)
        {
            key = stepper;
        }
        else
        {
            // data error
            return ESCH_KEYFRAME_DATAERROR;
        }
        if (_flags & ESCH_KEYFRAME_PING_PONG
            && ping_pong[num])
        {
            // next is going to be changing direction
            EschKeyframe *stepper = keyhead;
            if (stepper)
            {
                while (stepper && stepper->child != key)
                {
                    stepper = stepper->child;
                }
            }
            if (stepper)
            {
                next = stepper;
            }
            else
            {
                // we can assume that we've reached the beginning of the list
                // so ping_pong is going to reverse
                next = key->child;
            }
            if (!next)
            {
                // error because the data is bad
                return ESCH_KEYFRAME_DATAERROR;
            }
        }
        else
        {
            next = key->child;
            if (!next)
            {
                if (_flags & ESCH_KEYFRAME_PING_PONG)
                {
                    // go to key->prev for next
                    EschKeyframe *stepper = keyhead;
                    if (stepper)
                    {
                        while (stepper->next != key)
                        {
                            stepper = stepper->next;
                        }
                    }
                    if (stepper)
                    {
                        next = stepper;
                    }
                    else
                    {
                        // error because the data is bad
                        return ESCH_KEYFRAME_DATAERROR;
                    }
                }
                else
                {
                    // go to the first_framenum for next
                    EschKeyframe *stepper = keyhead;
                    if (stepper)
                    {
                        while (stepper && stepper->frame_num != first_framenum)
                        {
                            stepper = stepper->child;
                        }
                    }
                    if (stepper)
                    {
                        next = stepper;
                    }
                    else
                    {
                        // error because the data is bad
                        return ESCH_KEYFRAME_DATAERROR;
                    }
                }
            }
        }
    }
    else
    {
        EschKeyframe *stepper = keyhead;
        while (stepper && stepper->frame_num != next_framenum)
        {
            stepper = stepper->child;
        }
        if (stepper)
        {
            key = stepper;
        }
        else
        {
            // data error
            return ESCH_KEYFRAME_DATAERROR;
        }
        stepper = keyhead;
        if (_flags & ESCH_KEYFRAME_PING_PONG
            && ping_pong[num])
        {
            while (stepper && stepper->child != key)
            {
                stepper = stepper->child;
            }
            if (stepper)
            {
                next = stepper;
            }
            else
            {
                // no previous was found
                // ping_pong[num] about to reverse
                next = key->child;
            }
            if (!next)
            {
                // keyframe data error
                return ESCH_KEYFRAME_DATAERROR;
            }
        }
        else
        {
            next = key->child;
            if (!next)
            {
                if (_flags & ESCH_KEYFRAME_PING_PONG)
                {
                    // find key->prev
                    stepper = keyhead;
                    while (stepper && stepper->child != key)
                    {
                        stepper = stepper->child;
                    }
                    if (stepper)
                    {
                        next = stepper;
                    }
                    else
                    {
                        // bad keyframe data error
                        return ESCH_KEYFRAME_DATAERROR;
                    }
                }
                else
                {
                    stepper = keyhead;
                    while (stepper && stepper->frame_num != first_framenum)
                    {
                        stepper = stepper->child;
                    }
                    if (stepper)
                    {
                        next = stepper;
                    }
                    else
                    {
                        // keyframe data error
                        return ESCH_KEYFRAME_DATAERROR;
                    }
                }
            }
        }
    }

    if ((_flags & ESCH_KEYFRAME_PING_PONG))
    {
        ping_pong[num] = !ping_pong[num];
    }

    // now let's set current and next
    keyheads[num] = keyhead;
    keyframes[num] = key;
    next_keyframes[num] = next;

    // return the number of swaps that are performed
    //  (i.e. - the time jump can be larger than the time to complete the chain
    return (swap_count);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Functions  ±°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - pitch
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::pitch (const float degrees, dword update)
{
    home.pitch (degrees, update);
    local.pitch (degrees, update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - roll
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::roll (const float degrees, dword update)
{
    home.roll (degrees, update);
    local.roll (degrees, update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - yaw
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::yaw (const float degrees, dword update)
{
    local.yaw (degrees, update);
    home.yaw (degrees, update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - pitch_c
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
float EschKeyframeDraw::pitch_c (const float degrees, dword update)
{
    memcpy (&local,&home,sizeof(local));

    float temp_pitch = current_pitch;

    step_pitch += degrees;
    current_pitch = step_pitch;
    temp_pitch = current_pitch - temp_pitch;

    local.yaw (current_yaw,update);
    local.pitch (current_pitch,update);
    local.roll (current_roll,update);
    if (update & ESCH_UPD_WORLD)
    {
        compute_world(update);
    }

    return temp_pitch;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - roll_c
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
float EschKeyframeDraw::roll_c(const float degrees, dword update)
{
    memcpy (&local,&home,sizeof(local));

    float temp_roll = current_roll;

    step_roll += degrees;
    current_roll = step_roll;
    temp_roll = current_roll - temp_roll;

    local.yaw (current_yaw,update);
    local.pitch (current_pitch,update);
    local.roll (current_roll,update);
    if (update & ESCH_UPD_WORLD)
    {
        compute_world(update);
    }

    return temp_roll;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - yaw_c
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
float EschKeyframeDraw::yaw_c(const float degrees, dword update)
{
    memcpy (&local,&home,sizeof(local));

    float temp_yaw = current_yaw;

    step_yaw += degrees;
    current_yaw = step_yaw;
    temp_yaw = current_yaw - temp_yaw;

    local.yaw (current_yaw,update);
    local.pitch (current_pitch,update);
    local.roll (current_roll,update);
    if (update & ESCH_UPD_WORLD)
    {
        compute_world(update);
    }

    return temp_yaw;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - is_last_key
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EschKeyframeDraw::is_last_key()
{
    int retval = 0;
    for (int i=0; i<key_chain_count; i++)
    {
        retval = is_last_key(i);
    }
    return retval;
}

int EschKeyframeDraw::is_last_key(int num)
{
    return (!!keyframes[num]->next);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - get_child_by_ktype
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EschKeyframeDraw *EschKeyframeDraw::get_child_by_ktype (ulong kt)
{
    EschKeyframeDraw *temp;
    temp = 0;

    get_child_by_kt (kt, &temp);
    return (temp);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - get_child_by_kt
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::get_child_by_kt (ulong kt, EschKeyframeDraw **temp)
{
    if (k_type == kt)
    {
        *temp = this;
    }
    if (next() && (!(k_type & ESCH_KEYFRAME_ROOT)))
    {
        ((EschKeyframeDraw *)next())->get_child_by_kt (kt, temp);
    }
    if (child() && (!(*temp)))
    {
        ((EschKeyframeDraw *)child())->get_child_by_kt (kt, temp);
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - load_keys
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
esch_error_codes EschKeyframeDraw::load_keys(XFParseIFF *iff)
{
    esch_error_codes err;

    if (EschKeyframeMan)
    {
        err = EschKeyframeMan->load (iff);
    }
    return err;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                           °°° Protected °°°
// EschKeyframeDraw - tokenize_name
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::tokenize_name()
{
    char *step_ptr = &mesh->name[0];

    for (int i=0; i<ESCH_KEYFRAME_TOKEN_COUNT; i++)
    {
        if (strstr(&mesh->name[0], esch_token_list[i].name))
        {
            k_type = esch_token_list[i].type;
            return;
        }
    }
    k_type = ESCH_KEYFRAME_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - load
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
esch_error_codes EschKeyframeDraw::load(const char *fname, const char *oname,
                                        VngoPal *pal, EschMesh *msh, char *pn,
                                        dword ctrlfl)
{
   esch_error_codes err;

//ÄÄ Detach frame mesh, if any
    if (mesh)
    {
        detach();
    }

//ÄÄ Create mesh, if needed
    if (!msh)
    {
        msh = new EschMesh;
        if (!msh)
            return ESCH_ERR_NOMEMORY;
        flags |= ESCH_DRW_OWNSDATA;
    }

    local.orient.reset();

//ÄÄ Load
    if ((err=msh->load(fname,oname,pal,&local.orient,pn,ctrlfl)) != 0)
        return err;

//ÄÄ Attach
    if ((err=attach(msh)) != 0)
        return err;

//ÄÄ Update drawble information
    local.dir.i = local.orient.mtx[ESCH_MTX_G];
    local.dir.j = local.orient.mtx[ESCH_MTX_H];
    local.dir.k = local.orient.mtx[ESCH_MTX_I];

    local.compute_inverse();
    float dummy,y;
    local.get_position(&dummy, &y, &dummy);
    length =  y - msh->box.mins[1];

    memcpy (&home,&local,sizeof(local));

    compute_world();

    return ESCH_ERR_NONE;
}

esch_error_codes EschKeyframeDraw::load(XFParseIFF *iff, const char *oname,
                                           VngoPal *pal, EschMesh *msh, char *pn,
                                           dword ctrlfl)
{
   esch_error_codes err;

//ÄÄ Detach frame mesh, if any
    if (mesh)
    {
        detach();
    }

//ÄÄ Create mesh, if needed
    if (!msh)
    {
        msh = new EschMesh;
        if (!msh)
            return ESCH_ERR_NOMEMORY;
        flags |= ESCH_DRW_OWNSDATA;
    }

    local.orient.reset();

//ÄÄ Load
    if ((err=msh->load(iff,oname,pal,&local.orient,pn,ctrlfl))!=0)
        return err;

//ÄÄ Attach
    if ((err=attach(msh)) != 0)
        return err;

//ÄÄ tokenize name into an esch_limb_type
    tokenize_name ();

//ÄÄ Update drawble information
    local.dir.i = local.orient.mtx[ESCH_MTX_G];
    local.dir.j = local.orient.mtx[ESCH_MTX_H];
    local.dir.k = local.orient.mtx[ESCH_MTX_I];

    current_pitch = 0;
    current_roll = 0;
    current_yaw = 0;

    local.compute_inverse();

    memcpy (&home,&local,sizeof(local));

    compute_world();

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - set_activity
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::set_activity(int num)
{
    activity[num] = TRUE;

    if ((!(k_type&ESCH_KEYFRAME_ROOT)) &&
        (next() && (next()->get_type()==ESCH_DRWT_SKELETON)))
    {
        ((EschKeyframeDraw *)next())->set_activity (num);
    }

    if (child() && (child()->get_type()==ESCH_DRWT_SKELETON))
    {
        ((EschKeyframeDraw *)child())->set_activity (num);
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EschKeyframeDraw - set_inactivity
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EschKeyframeDraw::set_inactivity(int num)
{
    activity[num] = FALSE;

    if ((!(k_type&ESCH_KEYFRAME_ROOT)) &&
        (next() && (next()->get_type()==ESCH_DRWT_SKELETON)))
    {
        ((EschKeyframeDraw *)next())->set_inactivity (num);
    }

    if (child() && (child()->get_type()==ESCH_DRWT_SKELETON))
    {
        ((EschKeyframeDraw *)child())->set_inactivity (num);
    }
}


//°±² End of module - eskeydrw.cpp ²±°

