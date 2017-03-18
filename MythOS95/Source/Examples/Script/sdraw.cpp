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
//                  Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
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
//                               3D SCRIPT EXAMPLE
//
// Created by Chuck Walbourn
//
// sdraw.cpp
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
#include <newton.hpp>

#include "scrapp.hpp"
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
STATIC void drawable_body(EschDrawable *drw);
STATIC void drawable_anim(EschDrawable *drw);

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
extern EschDrawable         *Drawlist;

extern int                  CurrentToken;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// create_drawable
//
//         create_drawable :- drawable '=' <name>
//                         [ type={mesh | particle} ]
//                         [ maxcount=<integer> ]
//                         [ file=<file> ] '{' <body> '}'
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void create_drawable()
{
    EschDrawable    *drw=0;
    dword           typ=ESCH_DRWT_MESH;
    char            name[ESCH_MAX_NAME];
    char            fname[256];
    ulong           maxcount=128;

    *fname = 0;

    match(YY_DRAWABLE);
    match(YY_EQUAL);

//ÄÄÄ Get name
    if (CurrentToken != YY_STRING)
        error("create drawable needs name");

    //ÄÄÄ Check to see if name already defined
    if (Drawlist)
    {
        drw = Drawlist->find(yytext);
        if (drw)
            warning("Duplicate drawable name, drawable already exists");
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

            case YY_MAXCOUNT:
                match(YY_MAXCOUNT);
                match(YY_EQUAL);

                maxcount = expr();

                if (maxcount <= 0)
                    error("Max count out of range");
                break;

            case YY_TYPE:
                match(YY_TYPE);
                match(YY_EQUAL);

                switch (CurrentToken)
                {
                    case YY_MESH:
                        match(YY_MESH);
                        typ = ESCH_DRWT_MESH;
                        break;
                    case YY_PARTICLE:
                        match(YY_PARTICLE);
                        typ = ESCH_DRWT_PGENERATOR;
                        break;
                    default:
                        error("Expected valid drawable type:\n"
                              "mesh or particle\n");
                        break;
                }
                break;

            default:
                error("Expected optional file attribute, type attribute, or '{'");
        }
    }

    match(YY_LBRACE);

//ÄÄÄ Handle load or create
    if (!drw)
    {
        switch (typ)
        {
            case ESCH_DRWT_MESH:
                if (*fname)
                {
                    EschScene scene;
                    if ((scene.load(fname,0,Palette,
                                    ESCH_SCENELD_MESHES
                                    | ESCH_SCENELD_HIERARCHY) != ESCH_ERR_NONE)
                        || !scene.meshes
                        || !scene.meshes->find(name))
                    {
                        char buff[512];
                        sprintf(buff,"Failed to load mesh '%s'\nfrom '%s'",
                                    name,fname);
                        error(buff);
                    }

                    drw=scene.meshes->find(name);
                    if (scene.meshes == drw)
                        scene.meshes = (EschMeshDraw*)drw->next();
                    drw->remove();
                }
                else
                    error("Mesh type must have file to load from");
                break;

            case ESCH_DRWT_PGENERATOR:
                drw = new EschParticleGenerator;
                if (!drw)
                    error("Out of memory");

                drw->name = new char[ESCH_MAX_NAME];
                if (!drw->name)
                    error("Out of memory");
                strncpy(drw->name,name,ESCH_MAX_NAME);

                if (((EschParticleGenerator*)drw)->init(maxcount) != ESCH_ERR_NONE)
                    error("particle init failed");
                break;
        }

        if (!Drawlist)
            Drawlist = drw;
        else
            drw->sibling(Drawlist);
    }

//ÄÄÄ Process body
    while (CurrentToken != YY_RBRACE)
        drawable_body(drw);

    match(YY_RBRACE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// modify_drawable
//
//         modify_drawable :- drawable '=' <name> '{' <body> '}'
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void modify_drawable()
{
    match(YY_DRAWABLE);
    match(YY_EQUAL);

//ÄÄÄ Get name
    if (CurrentToken != YY_STRING)
        error("modify drawable needs name");

    //ÄÄÄ Check to see if name already defined
    if (!Drawlist)
        error("No drawable defined");

    EschDrawable *drw = Drawlist->find(yytext);
    if (!drw)
        error("Modify drawable needs defined drawable name");

    match(YY_STRING);
    match(YY_LBRACE);

//ÄÄÄ Process body
    while (CurrentToken != YY_RBRACE)
        drawable_body(drw);

    match(YY_RBRACE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// drawable_body
//
//         drawable_body :- position=<float>,<float>,<float>;
//                          | visible={on | off | yes | no};
//                          | translate=<float>,<float>,<float>;
//                          | move=<float>,<float>,<float>;
//                          | direction=<float>,<float>,<float>;
//                          | top=<float>,<float>,<float>;
//                          | rotatex=<float>;
//                          | rotatey=<float>;
//                          | rotatez=<float>;
//                          | yaw=<float>;
//                          | pitch=<float>;
//                          | roll=<float>;
//
//                          (only valid for particles)
//                          | shape={dots | pyramids};
//                          | sphere=<float>;
//                          | circle=<float>,<float>;
//                          | rectangle=<float>,<float>,<float>;
//                          | parts=<float> [,<float>];
//                          | speed=<float> [,<float>];
//                          | size=<float> [,<float>];
//                          | life=<float> [,<float>];
//                          | color=<integer>,<integer>,<integer>
//                                  [,<integer>,<integer>,<integer> ];
//                          | alpha=<integer> [,<integer>];
//                          | acceleration=<float>,<float>,<float>;
//
//                          | <empty>
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
STATIC void drawable_body(EschDrawable *drw)
{
    assert(drw != 0);

    switch (CurrentToken)
    {
        case YY_RBRACE:
            break;

        //ÄÄÄÄÄ position=<float>,<float>,<float>;
        case YY_POSITION:
            {
                match(YY_POSITION);
                match(YY_EQUAL);

                float x = (float)rexpr();
                match(YY_COMMA);

                float y = (float)rexpr();
                match(YY_COMMA);

                float z = (float)rexpr();
                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->set_position(x, y, z);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->set_position(x, y, z);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ visible={on | off | yes | no};
        case YY_VISIBLE:
            {
                match(YY_VISIBLE);
                match(YY_EQUAL);

                dword flags = drw->flags;

                switch (CurrentToken)
                {
                    case YY_YES:
                    case YY_ON:
                        match(CurrentToken);
                        flags &= ~ESCH_DRW_SKIP;
                        break;

                    case YY_NO:
                    case YY_OFF:
                        match(CurrentToken);
                        flags |= ESCH_DRW_SKIP;
                        break;

                    default:
                        error("visible can be yes/on or no/off");
                        break;
                }

                match(YY_SEMICOLON);

                drw->set_flags(flags);
            }
            break;

        //ÄÄÄÄÄ translate=<float>,<float>,<float>;
        case YY_TRANSLATE:
            {
                match(YY_TRANSLATE);
                match(YY_EQUAL);

                float i = (float)rexpr();
                match(YY_COMMA);

                float j = (float)rexpr();
                match(YY_COMMA);

                float k = (float)rexpr();
                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->translate(i, j, k);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->translate(i, j, k);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ move=<float>,<float>,<float>;
        case YY_MOVE:
            {
                match(YY_MOVE);
                match(YY_EQUAL);

                float i = (float)rexpr();
                match(YY_COMMA);

                float j = (float)rexpr();
                match(YY_COMMA);

                float k = (float)rexpr();
                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->move(i, j, k);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->move(i, j, k);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ direction=<float>,<float>,<float>;
        case YY_DIRECTION:
            {
                match(YY_DIRECTION);
                match(YY_EQUAL);

                float i = (float)rexpr();
                match(YY_COMMA);

                float j = (float)rexpr();
                match(YY_COMMA);

                float k = (float)rexpr();
                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->set_direction(i, j, k);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->set_direction(i, j, k);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ top=<float>,<float>,<float>;
        case YY_TOP:
            {
                match(YY_TOP);
                match(YY_EQUAL);

                float i = (float)rexpr();
                match(YY_COMMA);

                float j = (float)rexpr();
                match(YY_COMMA);

                float k = (float)rexpr();
                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->set_top(i, j, k);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->set_top(i, j, k);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ rotatex=<float>;
        case YY_ROTATEX:
            {
                match(YY_ROTATEX);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->rotatex(d);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->rotatex(d);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ rotatey=<float>;
        case YY_ROTATEY:
            {
                match(YY_ROTATEY);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->rotatey(d);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->rotatey(d);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ rotatez=<float>;
        case YY_ROTATEZ:
            {
                match(YY_ROTATEZ);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->rotatez(d);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->rotatez(d);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ yaw=<float>;
        case YY_YAW:
            {
                match(YY_YAW);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->yaw(d);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->yaw(d);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ pitch=<float>;
        case YY_PITCH:
            {
                match(YY_PITCH);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->pitch(d);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->pitch(d);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ roll=<float>;
        case YY_ROLL:
            {
                match(YY_ROLL);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                switch (drw->get_type())
                {
                    case ESCH_DRWT_MESH:
                        ((EschMeshDraw*)drw)->roll(d);
                        break;

                    case ESCH_DRWT_PGENERATOR:
                        ((EschParticleGenerator*)drw)->roll(d);
                        break;
                }
            }
            break;

        //ÄÄÄÄÄ
        //ÄÄÄÄÄ (only valid for particles)
        //ÄÄÄÄÄ shape={dots | pyramids};
        case YY_SHAPE:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_SHAPE);
                match(YY_EQUAL);

                switch (CurrentToken)
                {
                    case YY_DOTS:
                        match(YY_DOTS);
                        ((EschParticleGenerator*)drw)->set_callback(0);
                        break;
                    case YY_PYRAMIDS:
                        match(YY_PYRAMIDS);
                        ((EschParticleGenerator*)drw)->set_callback(
                                                     esch_generate_pyramid);
                        break;
                    default:
                        error("shape can be dots or pyramids");
                }

                match(YY_SEMICOLON);
            }
            else
                error("shape only valid for particle");
            break;

        //ÄÄÄÄÄ sphere=<float>;
        case YY_SPHERE:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_SPHERE);
                match(YY_EQUAL);

                float r = (float)rexpr();
                if (r <= 0)
                    error("Radius out of range");
                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_sphere(r);
            }
            else
                error("sphere only valid for particle");
            break;

        //ÄÄÄÄÄ circle=<float>,<float>;
        case YY_CIRCLE:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_CIRCLE);
                match(YY_EQUAL);

                float r = (float)rexpr();
                if (r <= 0)
                    error("Radius out of range");
                match(YY_COMMA);

                float ma = (float)rexpr();
                if (ma < 0 || ma > 360)
                    error("Maximum angle out of range");
                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_circle(r,ma);
            }
            else
                error("circle only valid for particle");
            break;

        //ÄÄÄÄÄ rectangle=<float>,<float>,<float>;
        case YY_RECTANGLE:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_RECTANGLE);
                match(YY_EQUAL);

                float l = (float)rexpr();
                if (l <= 0)
                    error("Length out of range");
                match(YY_COMMA);

                float w = (float)rexpr();
                if (w <= 0)
                    error("Width out of range");
                match(YY_COMMA);

                float ma = (float)rexpr();
                if (ma < 0 || ma > 360)
                    error("Maximum angle out of range");
                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_rectangle(l,w,ma);
            }
            else
                error("rectangle only valid for particle");
            break;

        //ÄÄÄÄÄ parts=<float> [,<float>];
        case YY_PARTS:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_PARTS);
                match(YY_EQUAL);

                float mean = (float)rexpr();
                if (mean < 0)
                    error("Mean out of range");

                float var=0;
                if (CurrentToken == YY_COMMA)
                {
                    match(YY_COMMA);
                    var = (float)rexpr();
                    if (var < 0)
                        error("Variance out of range");
                }

                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_parts(mean,var);
            }
            else
                error("parts only valid for particle");
            break;

        //ÄÄÄÄÄ speed=<float> [,<float>];
        case YY_SPEED:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_SPEED);
                match(YY_EQUAL);

                float mean = (float)rexpr();
                if (mean <= 0)
                    error("Mean out of range");

                float var=0;
                if (CurrentToken == YY_COMMA)
                {
                    match(YY_COMMA);
                    var = (float)rexpr();
                    if (var < 0)
                        error("Variance out of range");
                }

                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_speed(mean,var);
            }
            else
                error("speed only valid for particle");
            break;

        //ÄÄÄÄÄ size=<float> [,<float>];
        case YY_SIZE:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_SIZE);
                match(YY_EQUAL);

                float mean = (float)rexpr();
                if (mean < 0)
                    error("Mean out of range");

                float var=0;
                if (CurrentToken == YY_COMMA)
                {
                    match(YY_COMMA);
                    var = (float)rexpr();
                    if (var < 0)
                        error("Variance out of range");
                }

                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_size(mean,var);
            }
            else
                error("size only valid for particle");
            break;

        //ÄÄÄÄÄ life=<float> [,<float>];
        case YY_LIFE:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_LIFE);
                match(YY_EQUAL);

                float mean = (float)rexpr();
                if (mean < 0)
                    error("Mean out of range");

                float var=0;
                if (CurrentToken == YY_COMMA)
                {
                    match(YY_COMMA);
                    var = (float)rexpr();
                    if (var < 0)
                        error("Variance out of range");
                }

                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_lifetime(mean,var);
            }
            else
                error("life only valid for particle");
            break;

        //ÄÄÄÄÄ color=<integer>,<integer>,<integer> [,<integer>,<integer>,<integer> ];
        case YY_COLOR:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_COLOR);
                match(YY_EQUAL);

                int mean_r = expr();
                if (mean_r < 0 || mean_r > 255)
                    error("Mean Red Component out of range");
                match(YY_COMMA);

                int mean_g = expr();
                if (mean_g < 0 || mean_g > 255)
                    error("Mean Green Component out of range");
                match(YY_COMMA);

                int mean_b = expr();
                if (mean_b < 0 || mean_b > 255)
                    error("Mean Blue Component out of range");

                int var_r=0, var_g=0, var_b=0;
                if (CurrentToken == YY_COMMA)
                {
                    match(YY_COMMA);

                    var_r = expr();
                    if (var_r < 0 || var_r > 255)
                        error("Variance Red Component out of range");
                    match(YY_COMMA);

                    var_g = expr();
                    if (var_g < 0 || var_g > 255)
                        error("Variance Green Component out of range");
                    match(YY_COMMA);

                    var_b = expr();
                    if (var_b < 0 || var_b > 255)
                        error("Variance Blue Component out of range");
                }

                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_color(Palette,
                      VngoColor24bit((byte)mean_r,(byte)mean_g,(byte)mean_b),
                      VngoColor24bit((byte)var_r,(byte)var_g,(byte)var_b));
            }
            else
                error("color only valid for particle");
            break;


        //ÄÄÄÄÄ alpha=<integer> [,<integer>];
        case YY_ALPHA:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_ALPHA);
                match(YY_EQUAL);

                int mean = expr();
                if (mean < 0 || mean > 255)
                    error("Mean out of range");

                int var=0;
                if (CurrentToken == YY_COMMA)
                {
                    match(YY_COMMA);
                    var = expr();
                    if (var < 0 || var > 255)
                        error("Variance out of range");
                }

                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_alpha((byte)mean,(byte)var);
            }
            else
                error("alpha only valid for particle");
            break;

        //ÄÄÄÄÄ acceleration=<float>,<float>,<float>;
        case YY_ACCELERATION:
            if (drw->get_type() == ESCH_DRWT_PGENERATOR)
            {
                match(YY_ACCELERATION);
                match(YY_EQUAL);

                EschVector v;

                v.i = (float)rexpr();
                match(YY_COMMA);

                v.j = (float)rexpr();
                match(YY_COMMA);

                v.k = (float)rexpr();
                match(YY_SEMICOLON);

                ((EschParticleGenerator*)drw)->set_acceleration(&v);
            }
            else
                error("acceleration only valid for particle");
            break;

        default:
            error("Expected a drawable attribute");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// animate_drawable
//
//        animate_drawable :- drawable '=' <name> '{' <body> '}'
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void animate_drawable()
{
    match(YY_DRAWABLE);
    match(YY_EQUAL);

//ÄÄÄ Get name
    if (CurrentToken != YY_STRING)
        error("animate drawable needs name");

    //ÄÄÄ Check to see if name already defined
    if (!Drawlist)
        error("No drawable defined");

    EschDrawable *drw = Drawlist->find(yytext);
    if (!drw)
        error("Modify drawable needs defined drawable name");

    match(YY_STRING);
    match(YY_LBRACE);

//ÄÄÄ Process body
    while (CurrentToken != YY_RBRACE)
        drawable_anim(drw);

    match(YY_RBRACE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// drawable_anim
//
//        drawable_anim :- speed=<float>;
//                         | velocity=<float>,<float>,<float>;
//                         | acceleration=<float>,<float>,<float>;
//                         | rotatex=<float>;
//                         | rotatey=<float>;
//                         | rotatez=<float>;
//                         | yaw=<float>;
//                         | pitch=<float>;
//                         | roll=<float>;
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
STATIC void drawable_anim(EschDrawable *drw)
{
    assert(drw != 0);

    DrawableAnimate *anim = (DrawableAnimate *)drw->app_data;
    if (!anim)
    {
        anim = new DrawableAnimate;
        if (!anim)
            error("Out of memory");

        drw->set_app_data(anim);
    }

    switch (CurrentToken)
    {
        case YY_RBRACE:
            break;

        //ÄÄÄÄÄ speed=<float>;
        case YY_SPEED:
            {
                match(YY_SPEED);
                match(YY_EQUAL);

                float s = (float)rexpr();

                match(YY_SEMICOLON);

                anim->usenewton = TRUE;
                anim->lockdir = TRUE;

                EschMatrix *mtx;
                if (drw->get_type() == ESCH_DRWT_PGENERATOR)
                    mtx = &((EschParticleGenerator*)drw)->world.orient;
                else
                    mtx = &((EschMeshDraw*)drw)->world.orient;

                NewtVector p(mtx->mtx[ESCH_MTX_J],
                             mtx->mtx[ESCH_MTX_K],
                             mtx->mtx[ESCH_MTX_L]);
                anim->nobj.set_position(p);

                NewtVector v(mtx->mtx[ESCH_MTX_G],
                             mtx->mtx[ESCH_MTX_H],
                             mtx->mtx[ESCH_MTX_I]);
                v.normalize();
                v *= s;
                anim->nobj.set_velocity(v);
            }
            break;

        //ÄÄÄÄÄ velocity=<float>,<float>,<float>;
        case YY_VELOCITY:
            {
                match(YY_VELOCITY);
                match(YY_EQUAL);

                anim->usenewton = TRUE;
                anim->lockdir = FALSE;

                EschMatrix *mtx;
                if (drw->get_type() == ESCH_DRWT_PGENERATOR)
                    mtx = &((EschParticleGenerator*)drw)->world.orient;
                else
                    mtx = &((EschMeshDraw*)drw)->world.orient;

                NewtVector p(mtx->mtx[ESCH_MTX_J],
                             mtx->mtx[ESCH_MTX_K],
                             mtx->mtx[ESCH_MTX_L]);
                anim->nobj.set_position(p);

                NewtVector v;
                v.i = (float)rexpr();
                match(YY_COMMA);

                v.j = (float)rexpr();
                match(YY_COMMA);

                v.k = (float)rexpr();
                match(YY_SEMICOLON);

                anim->nobj.set_velocity(v);
            }
            break;

        //ÄÄÄÄÄ acceleration=<float>,<float>,<float>;
        case YY_ACCELERATION:
            {
                if (!anim->usenewton)
                    warning("acceleration requires the drawable to have a speed or velocity");

                match(YY_ACCELERATION);
                match(YY_EQUAL);

                NewtVector v;

                v.i = (float)rexpr();
                match(YY_COMMA);

                v.j = (float)rexpr();
                match(YY_COMMA);

                v.k = (float)rexpr();
                match(YY_SEMICOLON);

                anim->nobj.set_acceleration(v);
            }
            break;

        //ÄÄÄÄÄ rotatex=<float>;
        case YY_ROTATEX:
            {
                match(YY_ROTATEX);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                anim->lockdir = FALSE;
                anim->rotatex = d;
            }
            break;

        //ÄÄÄÄÄ rotatey=<float>;
        case YY_ROTATEY:
            {
                match(YY_ROTATEY);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                anim->lockdir = FALSE;
                anim->rotatey = d;
            }
            break;

        //ÄÄÄÄÄ rotatez=<float>;
        case YY_ROTATEZ:
            {
                match(YY_ROTATEZ);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                anim->lockdir = FALSE;
                anim->rotatez = d;
            }
            break;

        //ÄÄÄÄÄ yaw=<float>;
        case YY_YAW:
            {
                match(YY_YAW);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                anim->lockdir = FALSE;
                anim->yaw = d;
            }
            break;

        //ÄÄÄÄÄ pitch=<float>;
        case YY_PITCH:
            {
                match(YY_PITCH);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                anim->lockdir = FALSE;
                anim->pitch = d;
            }
            break;

        //ÄÄÄÄÄ roll=<float>;
        case YY_ROLL:
            {
                match(YY_ROLL);
                match(YY_EQUAL);

                float d = (float)rexpr();

                match(YY_SEMICOLON);

                anim->lockdir = FALSE;
                anim->roll = d;
            }
            break;

        default:
            error("Expected a drawable animation attribute");
            break;
    }
}

//°±² eof - sdraw.cpp ²±°
