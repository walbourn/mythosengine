//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                /\    /\
//                               /  \  /  \
//                              /    \/    \
//                             /  /\    /\  \
//                            /  /  \  /  Y T H O S
//                           /  /    \/    \  \
//                          /  /            \  \
//                         /__/              \__\
//
//                  Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
//                        http://www.mythos-engine.org/
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
//                               3D SCRIPT EXAMPLE
//
// Created by Chuck Walbourn
//
// scrtok.h
//
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                Equates
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

#define YY_LPAREN               1
#define YY_RPAREN               2
#define YY_LBRACE               3
#define YY_RBRACE               4
#define YY_PLUS                 5
#define YY_MINUS                6
#define YY_MULTIPLY             7
#define YY_DIVIDE               8
#define YY_COMMA                9
#define YY_EQUAL                10
#define YY_SEMICOLON            11

#define YY_ACCELERATION         100
#define YY_ACTIVATE             101
#define YY_ACTIVE               102
#define YY_ALPHA                103
#define YY_AMBIENT              104
#define YY_ANIMATE              105
#define YY_ASPECT_RATIO         106
#define YY_ATTEN                107
#define YY_ATTENUATED           108
#define YY_BCOLOR               109
#define YY_BFCULLING            110
#define YY_BITMAP               111
#define YY_CAMERA               112
#define YY_CIRCLE               113
#define YY_COLOR                114
#define YY_CREATE               115
#define YY_DARKLIGHT            116
#define YY_DEACTIVATE           117
#define YY_DIRECTION            118
#define YY_DOTS                 119
#define YY_DRAWABLE             120
#define YY_FACTOR               121
#define YY_FALLOFF              122
#define YY_FASTATTEN            123
#define YY_FASTPOINT            124
#define YY_FASTSPOT             125
#define YY_FILE                 126
#define YY_FLAT                 127
#define YY_FOV                  128
#define YY_HALT                 129
#define YY_HAZE                 130
#define YY_HIDE                 131
#define YY_HITHER               132
#define YY_HOTSPOT              133
#define YY_INCLUDE              134
#define YY_INNER                135
#define YY_INTENSITY            136
#define YY_LIFE                 137
#define YY_LIGHT                138
#define YY_LOOKAT               139
#define YY_MAXCOUNT             140
#define YY_MESH                 141
#define YY_MODIFY               142
#define YY_MOVE                 143
#define YY_NO                   144
#define YY_OFF                  145
#define YY_ON                   146
#define YY_OUTER                147
#define YY_PARTICLE             148
#define YY_PARTS                149
#define YY_PERSPECTIVE          150
#define YY_PITCH                151
#define YY_POINT                152
#define YY_POSITION             153
#define YY_PYRAMIDS             154
#define YY_RECTANGLE            155
#define YY_RENDER               156
#define YY_ROLL                 157
#define YY_ROTATEX              158
#define YY_ROTATEY              159
#define YY_ROTATEZ              160
#define YY_SAVE                 161
#define YY_SHADE                162
#define YY_SHAPE                163
#define YY_SHOW                 164
#define YY_SHOW_ALL_LINES       165
#define YY_SIZE                 166
#define YY_SMOOTH               167
#define YY_SOLID                168
#define YY_SPECULAR             169
#define YY_SPEED                170
#define YY_SPHERE               171
#define YY_SPOT                 172
#define YY_SPRITE               173
#define YY_TEXTURED             174
#define YY_TOP                  175
#define YY_TRANSLATE            176
#define YY_TYPE                 177
#define YY_VECTOR               178
#define YY_VELOCITY             179
#define YY_VIEWPOINT            180
#define YY_VISIBLE              181
#define YY_WAIT                 182
#define YY_WAITKEY              183
#define YY_WIRE                 184
#define YY_YAW                  185
#define YY_YES                  186
#define YY_YON                  187

#define YY_INTEGER              200
#define YY_REAL                 201
#define YY_STRING               202

//ฐฑฒ End of header - scrtok.h ฒฑฐ

