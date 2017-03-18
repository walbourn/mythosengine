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
// script.cpp
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
#include "screvt.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern BOOL Pump();

//ÄÄ External from scanner.
extern "C" int yylex();
extern "C" int yy_pushfile(const char *fname);

//ÄÄ External
extern void create_camera();
extern void modify_camera();

extern void create_light();
extern void modify_light();

extern void create_drawable();
extern void modify_drawable();
extern void animate_drawable();

//ÄÄ Local
STATIC BOOL csf();
STATIC void create();
STATIC void modify();
STATIC void animate();
STATIC void include();

long integer(void);
long expr(void);
STATIC long term(void);
STATIC long factor(void);

double real(void);
double rexpr(void);
STATIC double rterm(void);
STATIC double rfactor(void);

void match(int tok);
extern "C" void error(const char *str);
extern "C" void warning(const char *str);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄ Global Windows data
extern HINSTANCE       hInst;
extern HWND            hWndClient;
extern char            szAppName[];

//ÄÄÄ Global data
extern MythosSystem         *MythOS;
extern MaxDevices           *Devs;
extern VngoScreenManager    *Screen;
extern VngoVport            *Vport;
extern VngoPal              *Palette;

//ÄÄ External from scanner.
extern "C" long             YY_integer;
extern "C" double           YY_real;
extern "C" int              YY_lineno;
extern "C" int              YY_esc_allowed;
extern "C" char             *yytext;
extern "C" int              yyleng;

//ÄÄ Additional global data
EschCamera                  *CurCamera=0;

EschCameraEx                *Cameras=0;
EschDrawable                *Drawlist=0;
EschLight                   *Lights=0;

Chronometer                 Clock;

int                         CurrentToken;

//ÄÄ Local
STATIC MaxEventSource       *Evt=0;
STATIC MaxEventListOneshot  OneShot;
STATIC BOOL                 KeyHit=FALSE;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ProcessScript
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void ProcessScript()
{
//ÄÄÄ Get and start event system
    Evt = new MaxEventUser (*Devs);
    if (!Evt
        || ((MaxEventUser*)Evt)->load("SCREVT.IFF"))
        return;

    Evt->install();

    Clock.clear();

//ÄÄÄ Process script
    CurrentToken = yylex();
    while (CurrentToken)
    {
        if (!csf())
            break;
    }

//ÄÄÄ Cleanup
    if (Evt)
    {
        Evt->uninstall();
        delete Evt;
        Evt=0;
    }

    if (Drawlist)
    {
        for(EschDrawable *drw=Drawlist; drw != 0;)
        {
            EschDrawable *tmp = drw;

            switch (tmp->get_type())
            {
                case ESCH_DRWT_PGENERATOR:
                    if (tmp->name)
                    {
                        delete [] tmp->name;
                        tmp->name = 0;
                    }
                    break;
            }

            if (tmp->app_data)
            {
                delete ((DrawableAnimate*)tmp->app_data);
                tmp->set_app_data(0);
            }

            drw = drw->next();
            delete tmp;
        }
        Drawlist=0;
    }
    if (Lights)
    {
        for(EschLight *lgt=Lights; lgt != 0;)
        {
            EschLight *tmp = lgt;
            lgt = lgt->next();
            delete tmp;
        }
        Lights=0;
    }
    if (Cameras)
    {
        for(EschCamera *cam=Cameras; cam != 0;)
        {
            EschCamera *tmp = cam;
            cam = cam->next();
            delete tmp;
        }
        Cameras=0;
    }
    CurCamera=0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ProcessEvents
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void ProcessEvents()
{
//ÄÄÄ Determine events
    assertMyth("ProcessEvents() needs event source", Evt != 0);
    MaxEventList events = Evt->process ();
    MaxEventList single_events = OneShot.process (events);

    if (events.check(DONE))
    {
        PostQuitMessage(0);
        return;
    }

    if (single_events.check(NEXT))
        KeyHit=TRUE;

//ÄÄÄ Do per-frame updates
    float interval = float(Clock.check()) / 1000.0f;
    Clock.clear();

    for(EschDrawable *drw=Drawlist; drw != 0; drw = drw->next())
    {
        DrawableAnimate *anim=(DrawableAnimate *)drw->app_data;

        switch (drw->get_type())
        {
            case ESCH_DRWT_MESH:
                if (anim)
                {
                    EschMeshDraw *msh = (EschMeshDraw*)drw;

                    if (anim->usenewton)
                    {
                        anim->nobj.step(interval);

                        NewtVector v;
                        anim->nobj.get_position(&v);
                        msh->set_position((const EschPoint*)&v);

                        if (anim->lockdir)
                        {
                            anim->nobj.get_velocity(&v);

                            float mag = v.magnitude();
                            if (mag > 0)
                            {
                                v /= mag;
                                msh->set_direction((const EschVector*)&v);
                            }
                        }
                    }

                    if (!anim->usenewton || !anim->lockdir)
                    {
                        if (anim->rotatex)
                            msh->rotatex(anim->rotatex * interval);
                        if (anim->rotatey)
                            msh->rotatey(anim->rotatey * interval);
                        if (anim->rotatez)
                            msh->rotatez(anim->rotatez * interval);
                        if (anim->yaw)
                            msh->yaw(anim->yaw * interval);
                        if (anim->pitch)
                            msh->pitch(anim->pitch * interval);
                        if (anim->roll)
                            msh->roll(anim->roll * interval);
                    }
                }
                break;

            case ESCH_DRWT_PGENERATOR:
                {
                    EschParticleGenerator *pgen = (EschParticleGenerator*)drw;
                    pgen->set_interval(interval);

                    if (anim)
                    {
                        if (anim->usenewton)
                        {
                            anim->nobj.step(interval);

                            NewtVector v;
                            anim->nobj.get_position(&v);
                            pgen->set_position((const EschPoint*)&v);

                            if (anim->lockdir)
                            {
                                anim->nobj.get_velocity(&v);

                                float mag = v.magnitude();
                                if (mag > 0)
                                {
                                    v /= mag;
                                    pgen->set_direction((const EschVector*)&v);
                                }
                            }
                        }

                        if (!anim->usenewton || !anim->lockdir)
                        {
                            if (anim->rotatex)
                                pgen->rotatex(anim->rotatex * interval);
                            if (anim->rotatey)
                                pgen->rotatey(anim->rotatey * interval);
                            if (anim->rotatez)
                                pgen->rotatez(anim->rotatez * interval);
                            if (anim->yaw)
                                pgen->yaw(anim->yaw * interval);
                            if (anim->pitch)
                                pgen->pitch(anim->pitch * interval);
                            if (anim->roll)
                                pgen->roll(anim->roll * interval);
                        }
                    }
                }
                break;
        }

        if (anim)
        {

            if (anim->usenewton)
                anim->nobj.step(interval);
        }

        drw->animate();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Render
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Render()
{
    if (!CurCamera || !Drawlist)
    {
        Vport->reset();
        return;
    }

    CurCamera->render(Drawlist,Lights);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Recursive Decent Parser °°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// csf                                                                      ³
//                                                                          ³
//         csf :-  create                                                   ³
//                 modify                                                   ³
//                 animate                                                  ³
//                 viewpoint                                                ³
//                 activate                                                 ³
//                 deactivate                                               ³
//                 show                                                     ³
//                 hide                                                     ³
//                 halt                                                     ³
//                 render                                                   ³
//                 wait                                                     ³
//                 waitkey                                                  ³
//                 save                                                     ³
//                 include                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC BOOL csf(void)
{
    switch (CurrentToken)
    {
        case YY_SEMICOLON:
            match(YY_SEMICOLON);
            break;
        case YY_CREATE:
            create();
            break;
        case YY_MODIFY:
            modify();
            break;
        case YY_ANIMATE:
            animate();
            break;
        case YY_VIEWPOINT:
            {
                match(YY_VIEWPOINT);

                if (CurrentToken != YY_STRING)
                    error("viewpoint statement must be followed by a camera name.");

                if (!Cameras)
                {
                    warning("No cameras defined for viewpoint command");
                }
                else
                {
                    EschCamera *cam=Cameras->find(yytext);
                    if (!cam)
                        warning("Cannot find camera to make viewpoint");
                    else
                        CurCamera=cam;
                }

                match(YY_STRING);
                match(YY_SEMICOLON);
            }
            break;
        case YY_ACTIVATE:
            {
                match(YY_ACTIVATE);

                if (CurrentToken != YY_STRING)
                    error("activate statement must be followed by a light name.");

                if (!Lights)
                {
                    warning("No lights defined for activate command");
                }
                else
                {
                    EschLight *lgt = Lights->find(yytext);
                    if (!lgt)
                        warning("Cannot find light to activate.");
                    else
                        lgt->set_flags(lgt->flags & ~ESCH_LGT_OFF);
                }

                match(YY_STRING);
                match(YY_SEMICOLON);
            }
            break;
        case YY_DEACTIVATE:
            {
                match(YY_DEACTIVATE);

                if (CurrentToken != YY_STRING)
                    error("deactivate statement must be followed by a light name.");

                if (!Lights)
                {
                    warning("No lights defined for deactivate command");
                }
                else
                {
                    EschLight *lgt = Lights->find(yytext);
                    if (!lgt)
                        warning("Cannot find light to deactivate.");
                    else
                        lgt->set_flags(lgt->flags | ESCH_LGT_OFF);
                }

                match(YY_STRING);
                match(YY_SEMICOLON);
            }
            break;
        case YY_SHOW:
            {
                match(YY_SHOW);

                if (CurrentToken != YY_STRING)
                    error("show statement must be followed by a drawable name.");

                if (!Drawlist)
                {
                    warning("No drawables defined for show command");
                }
                else
                {
                    EschDrawable *drw = Drawlist->find(yytext);
                    if (!drw)
                        warning("Cannot find drawable to show.");
                    else
                        drw->set_flags(drw->flags & ~ESCH_DRW_SKIP);
                }

                match(YY_STRING);
                match(YY_SEMICOLON);
            }
            break;
        case YY_HIDE:
            {
                match(YY_HIDE);

                if (CurrentToken != YY_STRING)
                    error("hide statement must be followed by a drawable name.");

                if (!Drawlist)
                {
                    warning("No drawables defined for hide command");
                }
                else
                {
                    EschDrawable *drw = Drawlist->find(yytext);
                    if (!drw)
                        warning("Cannot find drawable to hide.");
                    else
                        drw->set_flags(drw->flags | ESCH_DRW_SKIP);
                }

                match(YY_STRING);
                match(YY_SEMICOLON);
            }
            break;
        case YY_HALT:
            {
                match(YY_HALT);

                switch (CurrentToken)
                {
                    case YY_DRAWABLE:
                        match(YY_DRAWABLE);
                        match(YY_EQUAL);

                        if (CurrentToken != YY_STRING)
                            error("halt statement needs drawable name.");

                        if (!Drawlist)
                        {
                            warning("No drawables defined for halt command");
                        }
                        else
                        {
                            EschDrawable *drw = Drawlist->find(yytext);
                            if (!drw)
                                warning("Cannot find drawable to halt.");
                            else if (drw->app_data)
                            {
                                delete ((DrawableAnimate*)drw->app_data);
                                drw->set_app_data(0);
                            }
                        }
                        match(YY_STRING);
                        match(YY_SEMICOLON);
                        break;

                    default:
                        error("animate must be followed by drawable");
                        break;
                }
            }
            break;
        case YY_RENDER:
            {
                match(YY_RENDER);
                long frames=expr();
                match(YY_SEMICOLON);

                for(long i=0; i < frames; i++)
                {
                    if (!Pump())
                        return FALSE;
                }
            }
            break;
        case YY_WAIT:
            {
                match(YY_WAIT);
                match(YY_EQUAL);
                long ms=expr();
                match(YY_SEMICOLON);

                if (ms < 0)
                    ms = 0;

                Chronometer clock;
                clock.clear();
                do
                {
                    if (!Pump())
                        return FALSE;
                }
                while (clock.check() <= ms);
            }
            break;
        case YY_WAITKEY:
            {
                KeyHit=FALSE;

                match(YY_WAITKEY);

                if (CurrentToken == YY_EQUAL)
                {
                    match(YY_EQUAL);
                    long ms=expr();
                    match(YY_SEMICOLON);

                    if (ms < 0)
                        ms = 0;

                    Chronometer clock;
                    clock.clear();
                    do
                    {
                        if (KeyHit)
                            break;

                        if (!Pump())
                            return FALSE;
                    }
                    while (clock.check() <= ms);
                }
                else
                {
                    match(YY_SEMICOLON);

                    while (!KeyHit)
                    {
                        if (!Pump())
                            return FALSE;
                    }
                }
            }
            break;
        case YY_SAVE:
            {
                match(YY_SAVE);

                if (CurrentToken == YY_STRING)
                {
                    match(YY_STRING);
                }
                else
                {
                }

                error("not yet implemented");

                match(YY_SEMICOLON);
            }
            break;
        case YY_INCLUDE:
            include();
            break;
        default:
            {
                char buff[128];
                sprintf(buff,"Invalid operation: expected a statement\n"
                             "(encountered token #%d out of context)",
                             CurrentToken);
                error(buff);
            }
            return FALSE;
    }

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// create                                                                   ³
//                                                                          ³
//         create :- create { camera | light | drawable } <create-?>        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void create()
{
    match(YY_CREATE);

    switch (CurrentToken)
    {
        case YY_CAMERA:
            create_camera();
            break;

        case YY_LIGHT:
            create_light();
            break;

        case YY_DRAWABLE:
            create_drawable();
            break;

        default:
            error("create must be followed by camera, light, or drawable");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// modify                                                                   ³
//                                                                          ³
//         modify :- modify { camera | light | drawable } <modify-?>        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void modify()
{
    match(YY_MODIFY);

    switch (CurrentToken)
    {
        case YY_CAMERA:
            modify_camera();
            break;

        case YY_LIGHT:
            modify_light();
            break;

        case YY_DRAWABLE:
            modify_drawable();
            break;

        default:
            error("modify must be followed by camera, light, or drawable");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// animate                                                                  ³
//                                                                          ³
//         animate :- animate drawable <animate-?>                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void animate()
{
    match(YY_ANIMATE);

    switch (CurrentToken)
    {
        case YY_DRAWABLE:
            animate_drawable();
            break;

        default:
            error("animate must be followed by drawable");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// include                                                                  ³
//                                                                          ³
//     include :- 'include' <string>                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void include(void)
{
    int err;

    YY_esc_allowed=0;
    match(YY_INCLUDE);
    YY_esc_allowed=1;

    switch(CurrentToken)
    {
        case YY_STRING:
            {
                char fname[256];
                strncpy(fname,yytext,sizeof(fname));
                match(YY_STRING);

                err=yy_pushfile(fname);
                switch (err)
                {
                    case 0:
                        /* OK */
                        break;
                    case 1:
                        error("Too many nested includes");
                        break;
                    case 2:
                        error("could not open include file");
                        break;
                    case 3:
                        error("Not enough memory to include file");
                    default:
                        error("Include failed");
                        break;
                }

                // Read first token from new file and continue processing
                // yywrap will undo include later

                CurrentToken = yylex();
            }
            break;
        default:
            error("Invalid include command, expecting filename of CSF file to include");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// integer/expr                                                             ³
//                                                                          ³
// Signed integer expression parsers.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
long integer(void)
{
    long    t=0;

    if (CurrentToken == YY_INTEGER)
    {
        t=YY_integer;
        match(YY_INTEGER);
    }
    else
        error("Integer expected");

    return(t);
}

long expr(void)
{
    long    t1, t2;

    t1 = term();
    switch(CurrentToken)
    {
        case YY_PLUS:
            match(YY_PLUS);
            t2 = term();
            return (t1 + t2);
        case YY_MINUS:
            match(YY_MINUS);
            t2 = term();
            return (t1 - t2);
        default:
            return t1;
    }
}

STATIC long term(void)
{
    long    t1, t2;

    t1 = factor();
    switch (CurrentToken)
    {
        case YY_MULTIPLY:
            match(YY_MULTIPLY);
            t2 = term();
            return (t1 * t2);
        case YY_DIVIDE:
            match(YY_DIVIDE);
            t2 = term();
            if (!t2)
                error("Divide by zero in expression");
            return (t1 / t2);
        default:
            return t1;
    }
}

STATIC long factor(void)
{
    long    t;

    switch(CurrentToken)
    {
        case YY_LPAREN:
            match(YY_LPAREN);
            t = expr();
            match(YY_RPAREN);
            return (t);
        case YY_INTEGER:
            return (integer());
        case YY_REAL:
            error("Floating-point value is invalid in integer expression");
            break;
        case YY_PLUS:
            match(YY_PLUS);
            return expr();
        case YY_MINUS:
            match(YY_MINUS);
            return -expr();
        default:
            error("Invalid integer expression");
            break;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// real/rexpr                                                               ³
//                                                                          ³
// Signed floating-point expression parsers.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
double real(void)
{
    double  t=0;

    if (CurrentToken == YY_REAL)
    {
        t=YY_real;
        match(YY_REAL);
    }
    else if (CurrentToken == YY_INTEGER)
    {
        t=(double)YY_integer;
        match(YY_INTEGER);
    }
    else
        error("Real or integer expected");

    return(t);
}

double rexpr(void)
{
    double  t1, t2;

    t1 = rterm();
    switch(CurrentToken)
    {
        case YY_PLUS:
            match(YY_PLUS);
            t2 = rterm();
            return (t1 + t2);
        case YY_MINUS:
            match(YY_MINUS);
            t2 = rterm();
            return (t1 - t2);
        default:
            return t1;
    }
}

STATIC double rterm(void)
{
   double  t1, t2;

   t1 = rfactor();
   switch (CurrentToken)
   {
       case YY_MULTIPLY:
           match(YY_MULTIPLY);
           t2 = rterm();
           return (t1 * t2);
       case YY_DIVIDE:
           match(YY_DIVIDE);
           t2 = rterm();
           if (!t2)
               error("Divide by zero in expression");
           return (t1 / t2);
       default:
           return t1;
    }
}

STATIC double rfactor(void)
{
    double  t;

    switch(CurrentToken)
    {
        case YY_LPAREN:
            match(YY_LPAREN);
            t = rexpr();
            match(YY_RPAREN);
            return (t);
        case YY_INTEGER:
        case YY_REAL:
            return (real());
        case YY_PLUS:
            match(YY_PLUS);
            return rexpr();
        case YY_MINUS:
            match(YY_MINUS);
            return -rexpr();
        default:
            error("Invalid real expression");
            break;
    }

    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Helper Routines °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// match                                                                    ³
//                                                                          ³
// Matches input token again target; if it failes, then it prints an error. ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void match(int tok)
{
    if (tok != CurrentToken)
    {
        switch (tok)
        {
            case YY_LBRACE:
                error("Expected a '{'");
                break;
            case YY_RBRACE:
                error("Expected a '}'");
                break;
            case YY_LPAREN:
                error("Expected a '('");
                break;
            case YY_RPAREN:
                error("Expected a ')'");
                break;
            case YY_COMMA:
                error("Expected a ','");
                break;
            case YY_EQUAL:
                error("Expected a '='");
                break;
            case YY_SEMICOLON:
                error("Expected a ';'");
                break;
            default:
                error("Unexpected token in source file");
                break;
        }
    }

    CurrentToken = yylex();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// error                                                                    ³
//                                                                          ³
// Emits an error and aborts processing.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void error(const char *str)
{
    char buff[2048];

    sprintf(buff,"ERROR IN SCRIPT\nLine: %d\n\nText:\n%s", YY_lineno, str);
    MessageBox(hWndClient,buff,szAppName, MB_ICONEXCLAMATION | MB_OK);
    ExitProcess(1);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// warning                                                                  ³
//                                                                          ³
// Emits a warning.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void warning(const char *str)
{
    char buff[2048];

    sprintf(buff,"SCRIPT WARNING\nLine: %d\n\nText:\n%s", YY_lineno, str);
    if (MessageBox(hWndClient,buff,szAppName,
                   MB_ICONSTOP | MB_OKCANCEL) == IDCANCEL)
        ExitProcess(1);
}

//°±² eof - script.cpp ²±°
