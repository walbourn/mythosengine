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
// eslimb.hpp
//
// Contains the EschLimb, derived, and support classes for drawing 3D
// articulated, constrained objects (limbs).
//
// EschLimb is the base class for a constrained yaw/pitch/roll based object.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESLIMB_HPP
#define __ESLIMB_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "esgeom.hpp"
#include "eskeyfrm.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class TwoLeggedMech;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegment - Abstract base class for 3D articulated limbs.          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschLimbSegment : public EschKeyframeDraw
{
    friend TwoLeggedMech; // debugging use

protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected data members                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    esch_limb_type  l_type;
    dword           state;
    float           max_pitch;
    float           max_roll;
    float           max_yaw;
    float           min_pitch;
    float           min_roll;
    float           min_yaw;
    float           secondary_pitch;
    float           secondary_roll;
    float           secondary_yaw;
    EschKeyframe    interim[ESCH_MAX_SIMULTANEOUS];
    EschKeyframe    pre_interim[ESCH_MAX_SIMULTANEOUS];

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected functions                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void build_interim(int num);

    void calc_step(int num);
    void init_tween(int num);

    float calc_stride(char *mt, dword *count);
    int calc_foot(ulong kt, char *mt,
                  EschVector *ret, EschFrameRef *stride_mtx, int frame_num);

    int get_next_key(int num, float side_vel);

    void set_rot_limits();

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    float       fore_pitch;
    float       side_pitch;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschLimbSegment();
    virtual ~EschLimbSegment();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual int step(float scalar, float side_vel);

//    virtual int set_key(EschKeyframe *key, float scalar);

//    virtual void do_keyframe(EschKeyframe *frame);
    virtual void do_rotations(EschVector *rot);

    virtual int swap_motion (char *str1, char *str2);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Accessor functions                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    int get_key_chain_count() const { return (key_chain_count); }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    float pitch_c(const float degrees, dword update=ESCH_UPD_ALL);
    float roll_c(const float degrees, dword update=ESCH_UPD_ALL);
    float yaw_c(const float degrees, dword update=ESCH_UPD_ALL);

    float change_second_pitch (float degrees);
    float change_second_roll (float degrees);
    float change_second_yaw (float degrees);
    void set_second_pitch (float degrees);
    void set_second_roll (float degrees);
    void set_second_yaw (float degrees);

    void fore_pitch_change (float pit, int swap);
    void side_pitch_change (float pit, int swap);

    void set_pitch_max (const float degrees) { max_pitch = degrees; }
    void set_pitch_max (const dword degrees) { max_pitch = float((long)degrees); }

    void set_roll_max (const float degrees) { max_roll = degrees; }
    void set_roll_max (const dword degrees) { max_roll = float((long)degrees); }

    void set_yaw_max (const float degrees) { max_yaw = degrees; }
    void set_yaw_max (const dword degrees) { max_yaw = float((long)degrees); }

    void set_pitch_min (const float degrees) { min_pitch = degrees; }
    void set_pitch_min (const dword degrees) { min_pitch = float((long)degrees); }

    void set_roll_min (const float degrees) { min_roll = degrees; }
    void set_roll_min (const dword degrees) { min_roll = float((long)degrees); }

    void set_yaw_min (const float degrees) { min_yaw = degrees; }
    void set_yaw_min (const dword degrees) { min_yaw = float((long)degrees); }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // I/O Routines.                                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual esch_error_codes load(const char *fname, const char *oname,
                                  VngoPal *pal, EschMesh *msh, char *pn,
                                  dword ctrlfl);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname,
                                  VngoPal *pal, EschMesh *msh, char *pn,
                                  dword ctrlfl);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EcshLimbPair                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschLimbPair
{
    EschLimbSegment *hip;
    EschLimbSegment *leading_leaf;
    EschLimbSegment *trailing_leaf;

    void swap_leading_trailing();
    void get_trailing_offset(EschVector *output);
    void adjust_hip_to_trailing();
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimb - Collector class for LimbSegments.  Allows multiple            �
//            EschLimbSegments to work in a hierarchy.                      �
//            This is an abstract class.  Actual limb activity depends on   �
//            the inherited classes.                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschLimb : public EschDrawable {

protected:
    dword           segment_count;
    EschLimbSegment *segments;          // points at the ultimate parent of the limb

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschLimb();
    virtual ~EschLimb();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual void adjust_gait();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // I/O Routines.                                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - eslimb.hpp 憶�


