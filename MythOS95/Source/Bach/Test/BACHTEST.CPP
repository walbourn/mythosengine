//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                        ÜÜÜÜÜÜÜÜÜÜ                       ÜÜÜÜ
//     ÚÄÄ¿                ÛÛÛ     ÛÛÜ                     ŞÛÛÛ
//     ³  ³       ÚÄÄ¿     ÛÛÛ     ÛÛÛ   ÜÜÜÜ      ÜÜÜÜÜ    ÛÛÛ ÜÜÜ
//     ³  ³ ÚÄÄ¿  ³  ³     ÛÛÛÜÜÜÜÛÛÛß  ß  ŞÛİ    ÛÛß   ßÛ  ÛÛÛÛÛßÛÛ
//     ³  ³ ³  ³  ³  ³     ÛÛÛ     ÛÛÜ  ÜÛÛÛÛÛİ  ÛÛÛ        ÛÛÛ   ÛÛÛ
//    OÙ OÙ ³  ³  ³  ³     ÛÛÛ     ÛÛÛ ŞÛİ  ÛÛÛ  ÛÛÛ    ÜÛ  ÛÛÛ   ÛÛÛ
//          ³  ³ OÙ OÙ    ÜÛÛÛÜÜÜÛÛÛß   ÛÛÛÛİßÛÜ  ßÛÛÜÜÛÛ  ÜÛÛÛÜ ÜÛÛÛÜ
//         OÙ OÙ
//                            C++ Music, Sound, and Effects Library
//                               Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
//                          *** Tester Application ***
//
// Created by Dan Higdon & Chuck Walbourn
//
// bachtest.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#include "bach.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

BOOL PumpWindows();
STATIC BOOL InitBachCD();
STATIC BOOL InitApplication (HINSTANCE, int, int, int);
LRESULT CALLBACK ClientWndProc (HWND, UINT, WPARAM, LPARAM);

char *str_error(char *str, bach_err_codes err);
char *str_format(char *str, bach_digi_fmt f);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄ Global Windows data
HINSTANCE       hInst;
HWND            hWndClient;
const char      szAppName[]     = "Bach Tester";

//ÄÄÄ Tester data
BachDigital3D       *BachDigi=0;
BachCD              *BachCd=0;

BachStaticSample    *Chimes=0;
BachStaticSample    *Tada=0;
BachStaticSample    *Test=0;

BachFileSample      *File=0;

BachSample3D        *Niceshot3D=0;

BachSampleSequencer *Sequencer=0;

BachMusic           *BachMus=0;

BachSequence        *Bigcity=0;
BachSequence        *Galactic=0;
BachSequence        *Sherwood=0;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// WinMain
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int APIENTRY WinMain (HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR     lpCmdLine,
                      int       nCmdShow)
{
//ÄÄÄ Initialize Windows

    //ÄÄÄ If we are already running, this routine will reactivate the older
    //ÄÄÄ application and return failure.
    if (!InitApplication (hInstance, nCmdShow, 320, 240))
        return 1;

    IvorySystem ivory;

//ÄÄÄÄ Initialize Bach ÄÄÄÄ
    BachDigi = new BachDigital3D(22500,BACH_DIGI_STEREO_16);
    if (!BachDigi)
    {
        MessageBox(hWndClient,"Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

    bach_err_codes err = BachDigi->init(hWndClient,DSSCL_PRIORITY);
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - Bach Digital Init");
        MessageBox(hWndClient,buff,
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

    BachMus = new BachMusic();
    if (!BachMus)
    {
        MessageBox(hWndClient,"Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

    err = BachMus->init(BachDigi,hWndClient,DMUS_EFFECT_REVERB);
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - Bach Music Init");
        MessageBox(hWndClient,buff,
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

//ÄÄÄÄ Load Samples ÄÄÄÄ
    Niceshot3D = new BachSample3D(BachDigi);
    if (!Niceshot3D)
    {
        MessageBox(hWndClient,"Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }
    err=Niceshot3D->load_wav("NICESHOT.WAV");
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - loading niceshot.wav");
        MessageBox(hWndClient,buff,
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

    Chimes = new BachStaticSample(BachDigi);
    if (!Chimes)
    {
        MessageBox(hWndClient,"Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }
    err=Chimes->load_wav("CHIMES.WAV");
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - loading chimes.wav");
        MessageBox(hWndClient,buff,
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

    Tada = new BachStaticSample(BachDigi);
    if (!Tada)
    {
        MessageBox(hWndClient,"Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }
    err=Tada->load_wav("TADA.WAV");
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - loading tada.wav");
        MessageBox(hWndClient,buff,
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

    Test = new BachStaticSample(BachDigi);
    if (!Test)
    {
        MessageBox(hWndClient,"Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }
    err=Test->load_raw("TEST.RAW",BACH_DIGI_MONO_8,11025);
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - loading test.raw");
        MessageBox(hWndClient,buff,
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

//ÄÄÄÄ Load Sequences ÄÄÄÄ
    Bigcity = new BachSequence(BachMus);
    if (!Bigcity)
    {
        MessageBox(hWndClient,"Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }
    err=Bigcity->load_mid("BIGCITY.MID");
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - loading bigcity.mid");
        MessageBox(hWndClient,buff,
                    szAppName,MB_OK | MB_ICONEXCLAMATION);
    }

    Galactic = new BachSequence(BachMus);
    if (!Galactic)
    {
        MessageBox(hWndClient,"Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }
    err=Galactic->load_mid("GALACTIC.MID");
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - loading galactic.mid");
        MessageBox(hWndClient,buff,
                    szAppName,MB_OK | MB_ICONEXCLAMATION);
    }

    Sherwood = new BachSequence(BachMus);
    if (!Sherwood)
    {
        MessageBox(hWndClient,"Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }
    err=Sherwood->load_mid("SHERWOOD.MID");
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - loading sherwood.mid");
        MessageBox(hWndClient,buff,
                    szAppName,MB_OK | MB_ICONEXCLAMATION);
    }

//ÄÄÄ Main Loop
    while (PumpWindows());

//ÄÄÄ Cleanup
    if (Sequencer)
    {
        delete Sequencer;
        Sequencer = 0;
    }
    if (Bigcity)
    {
        delete Bigcity;
        Bigcity = 0;
    }
    if (Galactic)
    {
        delete Galactic;
        Galactic = 0;
    }
    if (Sherwood)
    {
        delete Sherwood;
        Sherwood = 0;
    }
    if (Chimes)
    {
        delete Chimes;
        Chimes = 0;
    }
    if (Tada)
    {
        delete Tada;
        Tada = 0;
    }
    if (Test)
    {
        delete Test;
        Test = 0;
    }
    if (Niceshot3D)
    {
        delete Niceshot3D;
        Niceshot3D = 0;
    }
    if (BachCd)
    {
        delete BachCd;
        BachCd = 0;
    }
    if (BachDigi)
    {
        delete BachDigi;
        BachDigi = 0;
    }
    if (BachMus)
    {
        delete BachMus;
        BachMus = 0;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// InitBachCd
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL InitBachCd()
{
    if (BachCd)
        return TRUE;

    BachCd = new BachCD;
    if (!BachCd)
    {
        MessageBox(hWndClient,"Bach Cd - Out of memory",
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    bach_err_codes err = BachCd->init();
    if (err)
    {
        char buff[128];
        strcat(str_error(buff,err)," - Bach Cd Init");
        MessageBox(hWndClient,buff,
                   szAppName,MB_OK | MB_ICONEXCLAMATION);
        delete BachCd;
        BachCd =0;
        return FALSE;
    }

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PumpWindows
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL PumpWindows()
{
    MSG msg;
    while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
    {
        if (GetMessage (&msg, 0, 0, 0) == 0)
            return FALSE;

        TranslateMessage (&msg);
        DispatchMessage (&msg);
    }

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ClientWndProc
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LRESULT CALLBACK ClientWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static shift = 0;
    static ctrl = 0;

    switch (message)
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Keyboard Events
        case WM_KEYDOWN:
            switch (wParam)
            {
                case VK_ESCAPE:
                    DestroyWindow(hWndClient);
                    break;
                case '1':
                    if (Chimes)
                    {
                        if (ctrl)
                            Chimes->play(1);
                        else if (shift)
                            Chimes->stop();
                        else
                            Chimes->play();
                    }
                    break;
                case '2':
                    if (Tada)
                    {
                        if (ctrl)
                            Tada->play(1);
                        else if (shift)
                            Tada->stop();
                        else
                            Tada->play();
                    }
                    break;
                case '3':
                    if (Test)
                    {
                        if (ctrl)
                            Test->play(1);
                        else if (shift)
                            Test->stop();
                        else
                            Test->play();
                    }
                    break;
                case '5':
                    if (Bigcity)
                    {
                        if (ctrl)
                            Bigcity->queue();
                        else if (shift)
                            Bigcity->stop();
                        else
                            Bigcity->play();
                    }
                    break;
                case '6':
                    if (Galactic)
                    {
                        if (ctrl)
                            Galactic->queue();
                        else if (shift)
                            Galactic->stop();
                        else
                            Galactic->play();
                    }
                    break;
                case '7':
                    if (Sherwood)
                    {
                        if (ctrl)
                            Sherwood->queue();
                        else if (shift)
                            Sherwood->stop();
                        else
                            Sherwood->play();
                    }
                    break;
                case '9':
                    if (Niceshot3D)
                    {
                        if (ctrl)
                            Niceshot3D->play(1);
                        else if (shift)
                            Niceshot3D->stop();
                        else
                            Niceshot3D->play();
                    }
                    break;
                case VK_LEFT:
                    if (Niceshot3D)
                    {
                        float x, y, z;

                        Niceshot3D->get_position(x,y,z);

                        x -= (shift) ? 0.1f : 0.5f;

                        Niceshot3D->set_position(x,y,z);
                    }
                    break;
                case VK_RIGHT:
                    if (Niceshot3D)
                    {
                        float x, y, z;

                        Niceshot3D->get_position(x,y,z);

                        x += (shift) ? 0.1f : 0.5f;

                        Niceshot3D->set_position(x,y,z);
                    }
                    break;
                case VK_UP:
                    if (Niceshot3D)
                    {
                        float x, y, z;

                        Niceshot3D->get_position(x,y,z);

                        y += (shift) ? 0.1f : 0.5f;

                        Niceshot3D->set_position(x,y,z);
                    }
                    break;
                case VK_DOWN:
                    if (Niceshot3D)
                    {
                        float x, y, z;

                        Niceshot3D->get_position(x,y,z);

                        y -= (shift) ? 0.1f : 0.5f;

                        Niceshot3D->set_position(x,y,z);
                    }
                    break;
                case VK_HOME:
                    if (Niceshot3D)
                    {
                        Niceshot3D->set_position(0,0,0);
                    }
                    break;
                case 'F':
                    if (ctrl)
                    {
                        if (File)
                            File->next();
                    }
                    else if (shift)
                    {
                        if (File)
                            File->stop();
                    }
                    else
                    {
                        if (!File)
                        {
                            File = new BachFileSample(BachDigi,32768);
                            if (!File)
                            {
                                MessageBox(hWndClient,"Out of memory!",
                                           szAppName,MB_OK | MB_ICONEXCLAMATION);
                                ExitProcess(1);
                            }

                            bach_err_codes err = File->init();
                            if (err)
                            {
                                char buff[128];
                                strcat(str_error(buff,err)," - File init");
                                MessageBox(hWndClient,buff,
                                        szAppName,MB_OK | MB_ICONEXCLAMATION);
                                ExitProcess(1);
                            }
                        }
                        File->ready_wav("niceshot.wav");
                        File->play();
                    }
                    break;
                case 'S':
                    if (ctrl)
                    {
                        if (Sequencer)
                            Sequencer->next();
                    }
                    else if (shift)
                    {
                        if (Sequencer)
                            Sequencer->stop();
                    }
                    else
                    {
                        if (!Sequencer)
                        {
                            Sequencer = new BachSampleSequencer;
                            if (!Sequencer)
                            {
                                MessageBox(hWndClient,"Out of memory!",
                                        szAppName,MB_OK | MB_ICONEXCLAMATION);
                                ExitProcess(1);
                            }

                            bach_err_codes err = Sequencer->init();
                            if (err)
                            {
                                char buff[128];
                                strcat(str_error(buff,err)," - Sequencer init");
                                MessageBox(hWndClient,buff,
                                        szAppName,MB_OK | MB_ICONEXCLAMATION);
                                ExitProcess(1);
                            }
                        }
                        Sequencer->add(Chimes);
                        Sequencer->add(Test);
                        Sequencer->add(Tada);
                    }
                    break;
                case 'C':
                    if (InitBachCd())
                    {
                        if (ctrl)
                        {
                            char buff[4096];
                            ulong ntrack = BachCd->get_num_tracks();
                            wsprintf(buff, "CD Audio\nnumber of tracks = %d\n\n",
                                     ntrack);

                            for(ulong i=1; i <= ntrack; i++)
                            {
                                ulong sms, ems;
                                char tbuff[128];

                                bach_err_codes err=BachCd->get_track_info(i,sms,ems);
                                if (err)
                                {
                                    strcat(str_error(tbuff,err)," - CD Audio get track info");
                                    MessageBox(hWndClient,tbuff,
                                               szAppName,MB_OK | MB_ICONEXCLAMATION);
                                }
                                else
                                {
                                    wsprintf(tbuff,"#%d = %d to %d\n",i,sms,ems);
                                    strcat(buff,tbuff);
                                }
                            }
                            MessageBox(hWndClient,buff,szAppName,MB_OK);
                        }
                        else if (shift)
                        {
                            bach_err_codes err = BachCd->stop();
                            if (err)
                            {
                                char buff[128];
                                strcat(str_error(buff,err)," - CD Audio stop");
                                MessageBox(hWndClient,buff,
                                        szAppName,MB_OK | MB_ICONEXCLAMATION);
                            }
                        }
                        else
                        {
                            bach_err_codes err = BachCd->play();
                            if (err)
                            {
                                char buff[128];
                                strcat(str_error(buff,err)," - CD Audio stop");
                                MessageBox(hWndClient,buff,
                                        szAppName,MB_OK | MB_ICONEXCLAMATION);
                            }
                        }
                    }
                    break;
                case 'E':
                    if (InitBachCd())
                    {
                        if (shift)
                            BachCd->retract();
                        else
                            BachCd->eject();
                    }
                    break;
                case VK_SHIFT:
                    shift=1;
                    break;
                case VK_CONTROL:
                    ctrl=1;
                    break;
            }
            return 0;

        case WM_KEYUP:
            switch (wParam)
            {
                case VK_SHIFT:
                    shift=0;
                    break;
                case VK_CONTROL:
                    ctrl=0;
                    break;
            }
            return 0;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Application Events
        case WM_CREATE:
            return 0;

        case WM_ACTIVATEAPP:
            if (wParam)
            {
                if (BachMus)
                    BachMus->activate();
            }
            else
            {
                if (BachMus)
                    BachMus->deactivate();
            }
            return 0;

        case WM_CLOSE:
            DestroyWindow(hWndClient);
            return 0;

        case WM_DESTROY:
            PostQuitMessage (0);
            return 0;

        default:
            return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// str_error
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
char *str_error(char *str, bach_err_codes err)
{
    switch (err)
    {
        case BACH_ERR_INVALIDPARAMS:
            strcpy(str,"invalid parameters");
            break;
        case BACH_ERR_NOTSUPPORTED:
            strcpy(str,"not supported");
            break;
        case BACH_ERR_OUTOFMEMORY:
            strcpy(str,"out of memory");
            break;
        case BACH_ERR_LOCKFAILED:
            strcpy(str,"lock failed");
            break;
        case BACH_ERR_UNINITIALIZED:
            strcpy(str,"uninitialized");
            break;
        case BACH_ERR_BUSY:
            strcpy(str,"busy");
            break;
        case BACH_ERR_ALREADYOPEN:
            strcpy(str,"already open");
            break;

        case BACH_ERR_FILENOTFOUND:
            strcpy(str,"file not found");
            break;
        case BACH_ERR_FILEERROR:
            strcpy(str,"file error");
            break;
        case BACH_ERR_NOTFOUND:
            strcpy(str,"not found");
            break;

        case BACH_ERR_THREADFAILED:
            strcpy(str,"thread create failed");
            break;
        case BACH_ERR_EVENTFAILED:
            strcpy(str,"event create failed");
            break;

        case BACH_ERR_DSCONNECTFAIL:
            strcpy(str,"DirectSound connect failed");
            break;
        case BACH_ERR_DSPRICREATFAIL:
            strcpy(str,"DirectSound primary strer created failed");
            break;
        case BACH_ERR_DSSECCREATFAIL:
            strcpy(str,"DirectSound secondary strer created failed");
            break;
        case BACH_ERR_DSSETCOOPFAIL:
            strcpy(str,"DirectSound set coop mode failed");
            break;
        case BACH_ERR_DSFORMATFAILED:
            strcpy(str,"DirectSound set format failed");
            break;
        case BACH_ERR_DSLOCKFAILED:
            strcpy(str,"DirectSound lock failed");
            break;
        case BACH_ERR_DSBUFFERLOST:
            strcpy(str,"DirectSound strer lost");
            break;
        case BACH_ERR_DSFAILED:
            strcpy(str,"DirectSound failed");
            break;

        case BACH_ERR_DMCONNECTFAIL:
            strcpy(str,"DirectMusic connect failed");
            break;
        case BACH_ERR_DMFAILED:
            strcpy(str,"DirectMusic failed");
            break;

        case BACH_ERR_MCIFAILED:
            strcpy(str,"MCI failed");
            break;
        case BACH_ERR_MCIDEVOPEN:
            strcpy(str,"MCI device open");
            break;
        case BACH_ERR_MCIOUTOFRANGE:
            strcpy(str,"MCI out of range");
            break;

        default:
            strcpy(str,"*unknown error*");
            break;
    }

    return str;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// str_format
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
char *str_format(char *str, bach_digi_fmt f)
{
    switch (f)
    {
        case BACH_DIGI_MONO_8:
            strcpy(str,"mono 8-bit");
            break;
        case BACH_DIGI_MONO_16:
            strcpy(str,"mono 16-bit");
            break;
        case BACH_DIGI_STEREO_8:
            strcpy(str,"stereo 8-bit");
            break;
        case BACH_DIGI_STEREO_16:
            strcpy(str,"stereo 16-bit");
            break;
        default:
            strcpy(str,"*unknown format*");
            break;
    }

    return str;
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°° Windows Initialization Functions °°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// InitApplication
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL InitApplication (HINSTANCE hInstance, int nCmdShow, int w, int h)
{
//ÄÄÄ Win32 will always set hPrevInstance to NULL, so lets check
//ÄÄÄ things a little closer. This is because we only want a single
//ÄÄÄ version of this app to run at a time
    HWND hwnd = FindWindow (szAppName, NULL);
    if (hwnd != 0)
    {
        // We found another version of ourself. Lets defer to it:
        if (IsIconic (hwnd))
            ShowWindow (hwnd, SW_RESTORE);
        SetForegroundWindow (hwnd);
        return FALSE;
    }

//ÄÄÄ Register the client window's class
    WNDCLASSEX  wc;

    // Fill in window class structure with parameters that describe
    // the main window.
    wc.cbSize        = sizeof (WNDCLASSEX);
    wc.style         = CS_OWNDC;
    wc.lpfnWndProc   = (WNDPROC)ClientWndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon (hInstance, szAppName);
    wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject (BLACK_BRUSH);
    wc.lpszClassName = szAppName;
    wc.lpszMenuName  = 0;

    // This will load the small icon image from the icon resource
    wc.hIconSm = (HICON__*)LoadImage (hInstance,
                                      szAppName,
                                      IMAGE_ICON,
                                      GetSystemMetrics(SM_CXSMICON),
                                      GetSystemMetrics(SM_CYSMICON),
                                      LR_DEFAULTCOLOR);

    if (!RegisterClassEx (&wc))
        return FALSE;

    // Save the instance handle in static variable, which will be used in
    // many subsequence calls from this application to Windows.
    hInst = hInstance;

    hWndClient = CreateWindowEx (0,
                                 szAppName, szAppName,
                                 WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                 0, 0, w, h,
                                 NULL, NULL, hInstance, NULL);

    if (hWndClient == 0)
        return FALSE;

    ShowWindow (hWndClient, nCmdShow);
    UpdateWindow (hWndClient);
    SetFocus (hWndClient);

    return TRUE;
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° MythOS Assert Display °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// _charybdis_assert
//
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void _charybdis_assert (char *msg, char *exp, char *f, unsigned ln)
{
    int     i;
    char    title[32];
    char    buff[988];

    wsprintf (buff,"Assertion Failed\t\t\t\t\t\n"
                   "Expr:\t%s\n"
                   "File:\t%s\t\tLine %d",exp,f,ln);
    if (msg)
    {
        strcat (buff, "\nComment:\n");
        strcat (buff, msg);
    }
    strcat (buff,"\n\n\tOK to continue, Cancel to exit");

    strcpy (title, szAppName);
    strcat (title, " Debug Message");

    i = MessageBox (IsWindow (hWndClient) ? hWndClient : NULL,
                    buff,
                    title,
                    MB_OKCANCEL | MB_DEFBUTTON2 | MB_APPLMODAL | MB_ICONSTOP);

    if (i == IDCANCEL)
        ExitProcess (1);
}

//°±² End of module - bmain.cpp ²±°

