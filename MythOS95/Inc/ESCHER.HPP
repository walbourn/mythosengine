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
// Created by Tim Little & Chuck Walbourn
//
// escher.hpp
//
// Escher's C++ include header for the Escher library.  This includes all
// classes defined in the Escher library and associated functions and
// types, as well as some standard headers needed by the Escher library.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESCHER_HPP
#define __ESCHER_HPP    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳 Standard includes
#include <assert.h>
#include <string.h>
#include <math.h>

#include <portable.h>

//陳 Supporting library includes
#include <ivory.hpp>
#include <felix.hpp>
#include <vangogh.hpp>

//陳 Escher headers
#include "esdefs.h"

#include "eselemnt.hpp"

#include "esmath.hpp"                   // EschPoint, EschVector, EschVertex,
                                        // EschMatrix, EschFrameRef

#include "escontxt.hpp"                 // EschContext
#include "estxture.hpp"                 // EschTexture and derived classes
#include "eslight.hpp"                  // EschLight and derived classes
#include "escamera.hpp"                 // EschCamera and derived classes

#include "essystem.hpp"                 // EschSystem

#include "esdraw.hpp"                   // EschDrawable
#include "esbasic.hpp"                  // EschPointDraw
#include "espartik.hpp"                 // EschParticle and associated classes
#include "esgeom.hpp"                   // EschGeometry and associated classes

#include "eslimb.hpp"                   // EschLimbSegment & associated classes
#include "eskeyfrm.hpp"                 // EschKeyframer and associated classes

#include "esterran.hpp"                 // EschTerrain and derived classes

#include "espartn.hpp"                  // EschParition and associated classes

#include "esscene.hpp"                  // EschScene

#include "esbuild.hpp"                  // EschBuild classes

#include "esmisc.hpp"                   // Misc. Escher classes.

#endif

//葦� End of header - escher.hpp 憶�

