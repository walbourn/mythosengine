//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//������������������� Microsoft Windows 95/NT Version �����������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1998�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
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
// Created by Paul Masters
//
// eskeyfrm.hpp
//
// Contains the EschKeyframer class used in keyframing articualted motions.
//
//���������������������������������������������������������������������������

#ifndef __ESKEYFRM_HPP
#define __ESKEYFRM_HPP  1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#include "esdefs.h"
#include "estoken.hpp"

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

struct EschKeyframeHeader;

//�������������������������������������������������������������������������Ŀ
// EschKeyframe                                                             �
//���������������������������������������������������������������������������
struct EschKeyframe
{
    EschVector          rotations;
    ulong               k_type;
    EschKeyframe        *next;
    EschKeyframe        *child;
    EschKeyframe        *parent;
    EschKeyframeHeader  *root;
    int                 frame_num;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschKeyframe() :
        k_type (ESCH_KEYFRAME_NONE)
    {
        next = 0;
        child = 0;
        parent = 0;
        root = 0;
    };

    EschKeyframe (EschVector *rot, esch_limb_type ktype) :
        rotations(*rot),
        k_type(ktype)
    {
        next = 0;
        child = 0;
        parent = 0;
        root = 0;
    };
};


//�������������������������������������������������������������������������Ŀ
// EschKeyframeHeader                                                       �
//���������������������������������������������������������������������������
struct EschKeyframeHeader
{
    char                m_type[M_TYPE_LEN];
    ulong               flags;
    ulong               key_depth;
    EschKeyframe        *child;
    EschKeyframeHeader  *next;
    EschKeyframeHeader  *chain_next;
    EschKeyframeHeader  *chain_prev;
    EschKeyframeHeader()
    {
        child = 0;
        next = 0;
        chain_next = 0;
        chain_prev = 0;
    };
};



//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschKeyframer                                                            �
//���������������������������������������������������������������������������
class EschKeyframer
{
    dword               count;
    EschKeyframeHeader  *list;

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschKeyframer();
    virtual ~EschKeyframer();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void release();

    virtual EschKeyframe *get(esch_limb_type ktype, char *mtype,
                              int frame_num, EschKeyframeHeader *head=0);

    //���������������������������������������������������������������������Ŀ
    // I/O Routines.                                                        �
    //�����������������������������������������������������������������������
    virtual esch_error_codes load (const char *filename);
    virtual esch_error_codes load (XFParseIFF *iff);

    virtual esch_error_codes update_chaining();

    int get_chain_count();

    void get_next_chain_type (char *find, char *set);
};


//�������������������������������������������������������������������������Ŀ
// EschKeyframeDraw - Keyframed mesh drawable                               �
//���������������������������������������������������������������������������
class EschKeyframeDraw : public EschMeshDraw
{
protected:
    //���������������������������������������������������������������������Ŀ
    // Protected data members                                               �
    //�����������������������������������������������������������������������
    ulong           k_type;                     // keyframe type
    ulong           k_type_store;               // backup k_type info
    float           rest_pitch;
    float           rest_roll;
    float           rest_yaw;

    int             key_chain_count;
    float           tween_step[ESCH_MAX_SIMULTANEOUS];
    int             leads_with_left;            // bool for swapping

    // Array of  time to completion  values - time between each keyframe
    float           step_times[ESCH_MAX_SIMULTANEOUS];
    float           total_times[ESCH_MAX_SIMULTANEOUS];

    // array for active/inactive keychain flagging
    ulong           activity[ESCH_MAX_SIMULTANEOUS];

    // pointers into Keyframe Manager data for keychain head
    EschKeyframe    *keyheads[ESCH_MAX_SIMULTANEOUS];
    // pointers into Keyframe Manager data for current keyframes
    EschKeyframe    *keyframes[ESCH_MAX_SIMULTANEOUS];
    // pointers into Keyframe Manager data for next keyframes
    EschKeyframe    *next_keyframes[ESCH_MAX_SIMULTANEOUS];
    // array of data work vectors for building tweens
    EschVector      tweens[ESCH_MAX_SIMULTANEOUS];
    // array of incremental step data for tweening
    EschVector      steps[ESCH_MAX_SIMULTANEOUS];
    // array of bools for reverse during ping pong animation
    BOOL            ping_pong[ESCH_MAX_SIMULTANEOUS];

    // timing array.  floating precision needed for determining interval step to next frame
    float           fnext_frames[ESCH_MAX_SIMULTANEOUS];
    float           current_next[ESCH_MAX_SIMULTANEOUS];

    // time stamps for tweening
    float           prev_stamp[ESCH_MAX_SIMULTANEOUS];
    float           current_stamp[ESCH_MAX_SIMULTANEOUS];

    // time compression shift change data
    float           prev_shift[ESCH_MAX_SIMULTANEOUS];
    float           prev_shift_storage[ESCH_MAX_SIMULTANEOUS];

    // object tokens for object/keyframe pairing
    static EschTokenManager *TokenMan;
    static long             tok_users;

    //���������������������������������������������������������������������Ŀ
    // Protected functions                                                  �
    //�����������������������������������������������������������������������
    void calc_step(int num, float time = 0, float shift = 1.0f);
    void init_tween(int num);

    void build_keyframe(float scalar, float interval);

    int get_keyframe_spot(EschKeyframe *key);

    void remove_key_chains(char *mt);
    void remove_key (int num);

    void scale_step (int num, float scalar);

    int get_next_key(int num, float interval, float time = 0, float shift = 0);

    void load_tokens(XFParseIFF *iff);
    void tokenize_name();

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    EschFrameRef    home;
    float           current_pitch;
    float           current_roll;
    float           current_yaw;
    float           step_pitch;
    float           step_roll;
    float           step_yaw;
    EschVector      work;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschKeyframeDraw();
    virtual ~EschKeyframeDraw();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    void init_rotations(float time=0);
    void init_keys(float time=0);

    virtual int step(float interval, float scalar, float time=0, float shift=0);

    virtual int set_key(EschKeyframe *key, float scalar, float chain_time = 1.0f);

    void reset_key (int num);
    void reset_keys ();

    virtual void do_keyframe(EschKeyframe *frame);
    virtual void do_rotations(EschVector *rot);

    int swap_motion(char *str1, char *str2);

    void reset_keyframes(int num, float time, float interval=0.0f, float shift=1.0f);
    void reset_ktypes();

    float calc_stride (int chain_num);
    int calc_foot (ulong kt, char *mt, EschVector *ret, EschFrameRef *stride_mtx, int frame_num);


    // search through all objects in hierarchy and hide/unhide
    void hide_by_ktype (ulong kt);
    void hide_by_absolute_ktype (ulong kt);
    void unhide_by_ktype (ulong kt);
    void unhide_by_absolute_ktype (ulong kt);

    //���������������������������������������������������������������������Ŀ
    // Accessor functions                                                   �
    //�����������������������������������������������������������������������
    ulong get_ktype() const { return k_type; }
    void set_type (ulong type) { k_type = type; }

    int get_key_chain_count() const { return key_chain_count; }

    void set_activity(int num);
    void set_inactivity(int num);

    int get_key_depth(int num)
    {
        if ((num < ESCH_MAX_SIMULTANEOUS)
            && keyheads
            && keyheads[num]
            && keyheads[num]->root)
        {
            return (keyheads[num]->root->key_depth);
        }
        else
        {
            return 0;
        }
    }

    int get_current_key (int num)
    {
        if (keyframes && keyframes[num])
        {
            return (keyframes[num]->frame_num);
        }
        return (0);
    }

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������

    // Constrained pitch/roll/yaw
    float pitch_c(const float degrees, dword update=ESCH_UPD_ALL);
    float roll_c(const float degrees, dword update=ESCH_UPD_ALL);
    float yaw_c(const float degrees, dword update=ESCH_UPD_ALL);

    void pitch(const float degrees, dword update=ESCH_UPD_ALL);
    void roll(const float degrees, dword update=ESCH_UPD_ALL);
    void yaw(const float degrees, dword update=ESCH_UPD_ALL);

    void translate(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        home.translate(idx,idy,idz,update);
        local.translate(idx,idy,idz,update);
        if (update & ESCH_UPD_WORLD)
            compute_world(update);
    }
    void translate (EschVector *v, dword update=ESCH_UPD_ALL)
    {
        home.translate (v,update);
        local.translate (v,update);
        if (update & ESCH_UPD_WORLD)
            compute_world(update);
    }

    int is_last_key();
    int is_last_key(int num);

    EschKeyframeDraw *get_child_by_ktype (ulong kt);
    void get_child_by_kt (ulong kt, EschKeyframeDraw **temp);
    void get_pos_by_frame (long chain_num, long frame_num, EschPoint *pos);
    void calc_frame (long chain_num, long frame_num);

    void set_pitch_rest (const float degrees) { rest_pitch = degrees; };
    void set_pitch_rest (const dword degrees) { rest_pitch = float((long)degrees); };

    void set_roll_rest (const float degrees) { rest_roll = degrees; };
    void set_roll_rest (const dword degrees) { rest_roll = float((long)degrees); };

    void set_yaw_rest (const float degrees) { rest_yaw = degrees; };
    void set_yaw_rest (const dword degrees) { rest_yaw = float((long)degrees); };

    void align_swapping_keys();
    void align_child(int num, EschKeyframeDraw *root);
    void tokenize_names();
    esch_error_codes initialize_tokens(char *filename=0);


    //���������������������������������������������������������������������Ŀ
    // I/O Routines.                                                        �
    //�����������������������������������������������������������������������
    esch_error_codes load_keys(XFParseIFF *iff);

    virtual esch_error_codes load(const char *fname, const char *oname,
                                  VngoPal *pal, EschMesh *msh, char *pn,
                                  dword ctrlfl);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname,
                                  VngoPal *pal, EschMesh *msh, char *pn,
                                  dword ctrlfl);
};

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern EschKeyframer *EschKeyframeMan;

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - eskeyfrm.hpp ���

