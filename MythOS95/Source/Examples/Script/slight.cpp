//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
//                    Microsoft Windows 95/NT Version
//
//            Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
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
//                               3D SCRIPT EXAMPLE
//
// Created by Chuck Walbourn
//
// slight.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

#include <mythos.hpp>

#include "scrtok.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern long integer(void);
extern long expr(void);

extern double real(void);
extern double rexpr(void);

extern void match(int tok);
extern "C" void error(const char *str);
extern "C" void warning(const char *str);

//ÄÄ Local
STATIC void light_body(EschLight *lgt);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄ External from scanner.
extern "C" int              YY_esc_allowed;
extern "C" char             *yytext;
extern "C" int              yyleng;

//ÄÄ Global data
extern VngoPal              *Palette;
extern EschLight            *Lights; 

extern int                  CurrentToken;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// create_light
//            
//         create_light :- light '=' <name>
//                         [ type={ambient | vector | point | atten | spot
//                                 | fastpoint | fastatten | fastspot} ]
//                         [ file=<file> ] '{' <body> '}'
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void create_light()
{
    EschLight       *lgt=0;
    dword           typ=ESCH_LGTT_VECTOR;
    char            name[ESCH_MAX_NAME];
    char            fname[256];

    *fname = 0;

    match(YY_LIGHT);
    match(YY_EQUAL);

//ÄÄÄ Get name
    if (CurrentToken != YY_STRING)
        error("create light needs name");

    //ÄÄÄ Check to see if name already defined
    if (Lights)
    {
        lgt = Lights->find(yytext);
        if (lgt)
            warning("Duplicate light name, light already exists");
    }

    strncpy(name,yytext,sizeof(name));
    match(YY_STRING);

//ÄÄÄ Handle attributes
    while (CurrentToken != YY_LBRACE)
    {
        switch (CurrentToken)
        {
            case YY_FILE:
                match(YY_FILE);

                YY_esc_allowed=0;
                match(YY_EQUAL);
                YY_esc_allowed=1;
                
                if (CurrentToken != YY_STRING
                    || !xf_exist(yytext))
                    error("file needs valid filename");
                strncpy(fname,yytext,sizeof(fname));

                match(YY_STRING);
                break;

            case YY_TYPE:
                match(YY_TYPE);
                match(YY_EQUAL);

                switch (CurrentToken)
                {
                    case YY_AMBIENT:
                        match(YY_AMBIENT);
                        typ = ESCH_LGTT_AMBIENT;
                        break;
                    case YY_VECTOR:
                        match(YY_VECTOR);
                        typ = ESCH_LGTT_VECTOR;
                        break;
                    case YY_POINT:
                        match(YY_POINT);
                        typ = ESCH_LGTT_POINT;
                        break;
                    case YY_ATTEN:
                        match(YY_ATTEN);
                        typ = ESCH_LGTT_ATTEN;
                        break;
                    case YY_SPOT:
                        match(YY_SPOT);
                        typ = ESCH_LGTT_SPOT;
                        break;
                    case YY_FASTPOINT:
                        match(YY_FASTPOINT);
                        typ = ESCH_LGTT_FPOINT;
                        break;
                    case YY_FASTATTEN:
                        match(YY_FASTATTEN);
                        typ = ESCH_LGTT_FATTEN;
                        break;
                    case YY_FASTSPOT:
                        match(YY_FASTSPOT);
                        typ = ESCH_LGTT_FSPOT;
                        break;
                    default:
                        error("Expected valid light type:\n"
                              "ambient, vector, point, atten, spot,\n"
                              "fastpoint, fastatten, or fastspot");
                        break;
                }
                break;

            default:
                error("Expected optional file attribute, type attribute, or '{'");
        }
    }

    match(YY_LBRACE);

//ÄÄÄ Handle load or create
    if (!lgt)
    {
        switch (typ)
        {
            case ESCH_LGTT_AMBIENT:
                lgt = new EschLight;
                break;
            case ESCH_LGTT_VECTOR:
                lgt = new EschVectorLight;
                break;
            case ESCH_LGTT_POINT:
                lgt = new EschPointLight;
                break;
            case ESCH_LGTT_ATTEN:
                lgt = new EschAttenLight;
                break;
            case ESCH_LGTT_SPOT:
                lgt = new EschSpotLight;
                break;
            case ESCH_LGTT_FPOINT:
                lgt = new EschFastPointLight;
                break;
            case ESCH_LGTT_FATTEN:
                lgt = new EschFastAttenLight;
                break;
            case ESCH_LGTT_FSPOT:
                lgt = new EschFastSpotLight;
                break;
        }
        if (!lgt)
            error("Out of memory");
        strncpy(lgt->name,name,ESCH_MAX_NAME);

        if (*fname)
        {
            if (lgt->load(fname,name) != ESCH_ERR_NONE)
            {
                char buff[512];
                sprintf(buff,"Failed to load light '%s'\nfrom '%s'",
                             name,fname);
                error(buff);
            }
        }

        if (!Lights)
            Lights = lgt;
        else
            lgt->sibling(Lights);
    }

//ÄÄÄ Process body
    while (CurrentToken != YY_RBRACE)
        light_body(lgt);

    match(YY_RBRACE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// modify_light
//            
//         modify_light :- light '=' <name> '{' <body> '}'
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void modify_light()
{
    match(YY_LIGHT);
    match(YY_EQUAL);

//ÄÄÄ Get name
    if (CurrentToken != YY_STRING)
        error("modify light needs name");

    //ÄÄÄ Check to see if name already defined
    if (!Lights)
        error("No lights defined");

    EschLight *lgt = Lights->find(yytext);
    if (!lgt)
        error("Modify light needs defined light name");

    match(YY_STRING);
    match(YY_LBRACE);

//ÄÄÄ Process body
    while (CurrentToken != YY_RBRACE)
        light_body(lgt);

    match(YY_RBRACE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// light_body
//
//         light_body :- intensity=<integer>;
//                       | active={on | off | yes | no};
//                       | darklight={on | off | yes | no};
//                       
//                       (not valid for vector or ambient)
//                       | position=<float>,<float>,<float>;
//                       | translate=<float>,<float>,<float>;
//                       
//                       (only valid for vector, spot, and fastspot)
//                       | direction=<float>,<float>,<float>;
//                       | rotatex=<float>;
//                       | rotatey=<float>;
//                       | rotatez=<float>;
//                       
//                       (only valid for atten, spot, fastatten, or fastspot)
//                       | attenuated={on | off | yes | no};
//                       | inner=<float>;
//                       | outer=<float>;
//                       
//                       (only valid for spot or fastspot)
//                       | hotspot=<float>;
//                       | falloff=<float>;
//                       
//                       | <empty>
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
STATIC void light_body(EschLight *lgt)
{
    assert(lgt != 0);

    switch (CurrentToken)
    {
        case YY_RBRACE:
            break;

        //ÄÄÄÄÄ intensity=<integer>;
        case YY_INTENSITY:
            {
                match(YY_INTENSITY);
                match(YY_EQUAL);

                int i = expr();
                if (i < 0 || i > 255)
                    error("Intensity must be between 0 and 255");

                match(YY_SEMICOLON);

                lgt->set_intensity((byte)i);
            }
            break;

        //ÄÄÄÄÄ active={on | off | yes | no};
        case YY_ACTIVE:
            {
                match(YY_ACTIVE);
                match(YY_EQUAL);

                dword flags = lgt->flags;

                switch (CurrentToken)
                {
                    case YY_YES:
                    case YY_ON:
                        match(CurrentToken);
                        flags &= ~ESCH_LGT_OFF;
                        break;

                    case YY_NO:
                    case YY_OFF:
                        match(CurrentToken);
                        flags |= ESCH_LGT_OFF;
                        break;

                    default:
                        error("active can be yes/on or no/off");
                        break;
                }

                match(YY_SEMICOLON);

                lgt->set_flags(flags);
            }
            break;

        //ÄÄÄÄÄ darklight={on | off | yes | no};
        case YY_DARKLIGHT:
            {
                match(YY_DARKLIGHT);
                match(YY_EQUAL);

                dword flags = lgt->flags;

                switch (CurrentToken)
                {
                    case YY_YES:
                    case YY_ON:
                        match(CurrentToken);
                        flags |= ESCH_LGT_DARK;
                        break;

                    case YY_NO:
                    case YY_OFF:
                        match(CurrentToken);
                        flags &= ~ESCH_LGT_DARK;
                        break;

                    default:
                        error("darklight can be yes/on or no/off");
                        break;
                }

                match(YY_SEMICOLON);

                lgt->set_flags(flags);
            }
            break;

        //ÄÄÄÄÄ position=<float>,<float>,<float>;
        case YY_POSITION:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_FPOINT:
                case ESCH_LGTT_FATTEN:
                case ESCH_LGTT_FSPOT:
                case ESCH_LGTT_POINT:
                case ESCH_LGTT_ATTEN:
                case ESCH_LGTT_SPOT:
                    {
                        match(YY_POSITION);
                        match(YY_EQUAL);

                        float x = (float)rexpr();
                        match(YY_COMMA);

                        float y = (float)rexpr();
                        match(YY_COMMA);

                        float z = (float)rexpr();
                        match(YY_SEMICOLON);
                
                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_FPOINT:
                            case ESCH_LGTT_FATTEN:
                            case ESCH_LGTT_FSPOT:
                                ((EschFastPointLight*)lgt)->set_position(x, y, z);
                                break;

                            case ESCH_LGTT_POINT:
                            case ESCH_LGTT_ATTEN:
                            case ESCH_LGTT_SPOT:
                                ((EschPointLight*)lgt)->set_position(x, y, z);
                                break;
                        }
                    }
                    break;

                default:
                    error("position not valid for vector or ambient light");
            }
            break;

        //ÄÄÄÄÄ translate=<float>,<float>,<float>;
        case YY_TRANSLATE:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_FPOINT:
                case ESCH_LGTT_FATTEN:
                case ESCH_LGTT_FSPOT:
                case ESCH_LGTT_POINT:
                case ESCH_LGTT_ATTEN:
                case ESCH_LGTT_SPOT:
                    {
                        match(YY_TRANSLATE);
                        match(YY_EQUAL);

                        float x = (float)rexpr();
                        match(YY_COMMA);

                        float y = (float)rexpr();
                        match(YY_COMMA);

                        float z = (float)rexpr();
                        match(YY_SEMICOLON);
            
                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_FPOINT:
                            case ESCH_LGTT_FATTEN:
                            case ESCH_LGTT_FSPOT:
                                ((EschFastPointLight*)lgt)->translate(x, y, z);
                                break;

                            case ESCH_LGTT_POINT:
                            case ESCH_LGTT_ATTEN:
                            case ESCH_LGTT_SPOT:
                                ((EschPointLight*)lgt)->translate(x, y, z);
                                break;
                        }
                    }
                    break;

                default:
                    error("translate not valid for vector or ambient light");
            }
            break;

        //ÄÄÄÄÄ direction=<float>,<float>,<float>;
        case YY_DIRECTION:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_VECTOR:
                case ESCH_LGTT_SPOT:
                case ESCH_LGTT_FSPOT:
                    {
                        match(YY_DIRECTION);
                        match(YY_EQUAL);

                        float i = (float)rexpr();
                        match(YY_COMMA);

                        float j = (float)rexpr();
                        match(YY_COMMA);

                        float k = (float)rexpr();
                        match(YY_SEMICOLON);
                
                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_VECTOR:
                                ((EschVectorLight*)lgt)->set_direction(i,j,k);
                                break;

                            case ESCH_LGTT_FSPOT:
                                ((EschFastSpotLight*)lgt)->set_direction(i,j,k);
                                break;

                            case ESCH_LGTT_SPOT:
                                ((EschSpotLight*)lgt)->set_direction(i,j,k);
                                break;
                        }
                    }
                    break;

                default:
                    error("direction only valid for vector, spot, and fastspot");
                    break;
            }
            break;

        //ÄÄÄÄÄ rotatex=<float>;
        case YY_ROTATEX:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_VECTOR:
                case ESCH_LGTT_SPOT:
                case ESCH_LGTT_FSPOT:
                    {
                        match(YY_ROTATEX);
                        match(YY_EQUAL);

                        float d = (float)rexpr();
                        match(YY_SEMICOLON);
                
                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_VECTOR:
                                ((EschVectorLight*)lgt)->rotatex(d);
                                break;

                            case ESCH_LGTT_FSPOT:
                                ((EschFastSpotLight*)lgt)->rotatex(d);
                                break;

                            case ESCH_LGTT_SPOT:
                                ((EschSpotLight*)lgt)->rotatex(d);
                                break;
                        }
                    }
                    break;

                default:
                    error("rotatex only valid for vector, spot, and fastspot");
                    break;
            }
            break;

        //ÄÄÄÄÄ rotatey=<float>;
        case YY_ROTATEY:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_VECTOR:
                case ESCH_LGTT_SPOT:
                case ESCH_LGTT_FSPOT:
                    {
                        match(YY_ROTATEY);
                        match(YY_EQUAL);

                        float d = (float)rexpr();
                        match(YY_SEMICOLON);
                
                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_VECTOR:
                                ((EschVectorLight*)lgt)->rotatey(d);
                                break;

                            case ESCH_LGTT_FSPOT:
                                ((EschFastSpotLight*)lgt)->rotatey(d);
                                break;

                            case ESCH_LGTT_SPOT:
                                ((EschSpotLight*)lgt)->rotatey(d);
                                break;
                        }
                    }
                    break;

                default:
                    error("rotatey only valid for vector, spot, and fastspot");
                    break;
            }
            break;

        //ÄÄÄÄÄ rotatez=<float>;
        case YY_ROTATEZ:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_VECTOR:
                case ESCH_LGTT_SPOT:
                case ESCH_LGTT_FSPOT:
                    {
                        match(YY_ROTATEZ);
                        match(YY_EQUAL);

                        float d = (float)rexpr();
                        match(YY_SEMICOLON);
                
                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_VECTOR:
                                ((EschVectorLight*)lgt)->rotatez(d);
                                break;

                            case ESCH_LGTT_FSPOT:
                                ((EschFastSpotLight*)lgt)->rotatez(d);
                                break;

                            case ESCH_LGTT_SPOT:
                                ((EschSpotLight*)lgt)->rotatez(d);
                                break;
                        }
                    }
                    break;

                default:
                    error("rotatez only valid for vector, spot, and fastspot");
                    break;
            }
            break;

        //ÄÄÄÄÄ attenuated={on | off | yes | no};
        case YY_ATTENUATED:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_FATTEN:
                case ESCH_LGTT_FSPOT:
                case ESCH_LGTT_ATTEN:
                case ESCH_LGTT_SPOT:
                    {
                        match(YY_ATTENUATED);
                        match(YY_EQUAL);

                        dword flags = lgt->flags;

                        switch (CurrentToken)
                        {
                            case YY_YES:
                            case YY_ON:
                                match(CurrentToken);
                                flags |= ESCH_LGT_ATTEN;
                                break;

                            case YY_NO:
                            case YY_OFF:
                                match(CurrentToken);
                                flags &= ~ESCH_LGT_ATTEN;
                                break;

                            default:
                                error("attenuated can be yes/on or no/off");
                                break;
                        }

                        match(YY_SEMICOLON);

                        lgt->set_flags(flags);
                    }
                    break;

                default:
                    error("attenuated only valid for atten, spot, fastatten, and fastspot");
                    break;
            }
            break;

        //ÄÄÄÄÄ inner=<float>;
        case YY_INNER:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_FATTEN:
                case ESCH_LGTT_FSPOT:
                case ESCH_LGTT_ATTEN:
                case ESCH_LGTT_SPOT:
                    {
                        match(YY_INNER);
                        match(YY_EQUAL);

                        float f = (float)rexpr();

                        if (f < 0)
                            error("inner value out of range");

                        match(YY_SEMICOLON);

                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_FATTEN:
                            case ESCH_LGTT_FSPOT:
                                ((EschFastAttenLight*)lgt)->set_inner(f);
                                break;

                            case ESCH_LGTT_ATTEN:
                            case ESCH_LGTT_SPOT:
                                ((EschAttenLight*)lgt)->set_inner(f);
                                break;
                        }
                    }
                    break;

                default:
                    error("inner only valid for atten, spot, fastatten, and fastspot");
                    break;
            }
            break;

        //ÄÄÄÄÄ outer=<float>;
        case YY_OUTER:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_FATTEN:
                case ESCH_LGTT_FSPOT:
                case ESCH_LGTT_ATTEN:
                case ESCH_LGTT_SPOT:
                    {
                        match(YY_OUTER);
                        match(YY_EQUAL);

                        float f = (float)rexpr();

                        if (f < 0)
                            error("outer value out of range");

                        match(YY_SEMICOLON);

                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_FATTEN:
                            case ESCH_LGTT_FSPOT:
                                ((EschFastAttenLight*)lgt)->set_outer(f);
                                break;

                            case ESCH_LGTT_ATTEN:
                            case ESCH_LGTT_SPOT:
                                ((EschAttenLight*)lgt)->set_outer(f);
                                break;
                        }
                    }
                    break;

                default:
                    error("outer only valid for atten, spot, fastatten, and fastspot");
                    break;
            }
            break;

        //ÄÄÄÄÄ hotspot=<float>;
        case YY_HOTSPOT:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_FSPOT:
                case ESCH_LGTT_SPOT:
                    {
                        match(YY_HOTSPOT);
                        match(YY_EQUAL);

                        float d = (float)rexpr();

                        if (d < 0 || d > 180)
                            error("hotspot value out of range");

                        match(YY_SEMICOLON);

                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_FSPOT:
                                ((EschFastSpotLight*)lgt)->set_hotspot(d);
                                break;

                            case ESCH_LGTT_SPOT:
                                ((EschSpotLight*)lgt)->set_hotspot(d);
                                break;
                        }
                    }
                    break;

                default:
                    error("hotspot only valid for spot and fastspot");
                    break;
            }
            break;

        //ÄÄÄÄÄ falloff=<float>;
        case YY_FALLOFF:
            switch (lgt->get_type())
            {
                case ESCH_LGTT_FSPOT:
                case ESCH_LGTT_SPOT:
                    {
                        match(YY_FALLOFF);
                        match(YY_EQUAL);

                        float d = (float)rexpr();

                        if (d < 0 || d > 180)
                            error("falloff value out of range");

                        match(YY_SEMICOLON);

                        switch (lgt->get_type())
                        {
                            case ESCH_LGTT_FSPOT:
                                ((EschFastSpotLight*)lgt)->set_falloff(d);
                                break;

                            case ESCH_LGTT_SPOT:
                                ((EschSpotLight*)lgt)->set_falloff(d);
                                break;
                        }
                    }
                    break;

                default:
                    error("falloff only valid for spot and fastspot");
                    break;
            }
            break;

        default:
            error("Expected a light attribute");
            break;
    }
}

//°±² eof - slight.cpp ²±°
