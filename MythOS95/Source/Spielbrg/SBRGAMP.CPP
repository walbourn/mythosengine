//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//                                                      _o######ooooooo-_
//     Spielberg -- Animation player library          o#####o_o#####~~~~~~
//                                                   ################o__o
//      Microsoft Windows 95/98/NT Version        _o###########~~~~~###~
//                                               o##############
//                                            _o###############~
//                                          _o#########~ooo~##~
//                                     _o############# ##o::___
//                                   _o#################oo:~~~~~
//                                 _o#####################~
//                               _####~_oooooooo:~~######~
//                             _##### o###########_:~##~
//                            o#####_##################
//                           _#######_~#################_
//                           ##########o:~###############o
//                         _##############o~##############_
//                       o#############~~     ~~~~~~~######_
//                   __o##########~::o_             o#######
//              _oo##########~~::o#####            o###########o___
//          o##########~~~~    ~~~##########       ~~~~#############o
//         #####~~~~~~                ~~~
//
//  Copyright (c) 1996-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
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
// sbrgamp.cpp
//
// ActiveMovie(TM) player Spielberg class implementation
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "spielbrg.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define OATRUE      -1
#define OAFALSE     0

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern int SpielbrgCOMInit;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SpielbergAMPlayer::SpielbergAMPlayer(HWND _parent) :
    SpielbergPlayer(),
    parent(_parent),
    am_graph(0),
    am_event(0)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SpielbergAMPlayer::~SpielbergAMPlayer()
{
    close();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - open
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::open(const char *name, dword ctrlfl)
{
    if (!name || !parent)
        return SBERG_ERR_INVALIDPARMS;

    if (!xf_exist(name))
        return SBERG_ERR_FILENOTFOUND;

    if (am_graph)
        return SBERG_ERR_ALREADYOPEN;

//陳� Initialize COM
    if (!SpielbrgCOMInit)
    {
        CoInitialize(NULL);
        SpielbrgCOMInit=1;
    }

//陳� Connect to ActiveMovie
    HRESULT hr = CoCreateInstance(CLSID_FilterGraph,
                                  NULL,
                                  CLSCTX_INPROC_SERVER,
                                  IID_IGraphBuilder,
                                  (void **) &am_graph);

    if (FAILED(hr))
    {
        am_graph=0;
        return SBERG_ERR_AMCONNECTFAILED;
    }

//陳� Get ActiveMovie event handle
    IMediaEvent *am_mediaevt=0;
    hr=am_graph->QueryInterface(IID_IMediaEvent, (void**)&am_mediaevt);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_AMQUERYIFAILED;
    }

    hr = am_mediaevt->GetEventHandle((OAEVENT*) &am_event);
    if (FAILED(hr))
    {
        am_mediaevt->Release();
        close();
        return SBERG_ERR_AMEVENTFAILED;
    }

    am_mediaevt->Release();
    am_mediaevt=0;

//陳� Attach file to graph
    WCHAR   wPath[XF_MAX_PATH];

    MultiByteToWideChar(CP_ACP,0,name, -1, wPath, XF_MAX_PATH);

    hr = am_graph->RenderFile(wPath,NULL);
    if (FAILED(hr))
    {
        switch (hr)
        {
            case VFW_S_AUDIO_NOT_RENDERED:
            case VFW_S_VIDEO_NOT_RENDERED:
            case VFW_S_RPZA:
                close();
                return SBERG_ERR_NOTSUPPORTED;
            case VFW_S_PARTIAL_RENDER:
                break;
            default:
                close();
                return SBERG_ERR_AMFAILED;
        }
    }

//陳� Get basic video interface
    IVideoWindow *am_video=0;
    hr = am_graph->QueryInterface(IID_IVideoWindow, (void**)&am_video);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Setup fullscreen mode for video device
    hr = am_video->put_FullScreenMode((ctrlfl & SBERG_CTRL_FULLSCREEN)
                                      ? OATRUE : OAFALSE);

    am_video->put_Owner((OAHWND)parent);

    long style;
    am_video->get_WindowStyle(&style);
    am_video->put_WindowStyle(style & ~(WS_BORDER
                                        | WS_DLGFRAME
                                        | WS_SYSMENU
                                        | WS_THICKFRAME));

    am_video->put_Left(0);
    am_video->put_Top(0);

    am_video->Release();
    am_video=0;

    if (FAILED(hr))
    {
        if (hr != E_NOTIMPL || (ctrlfl & SBERG_CTRL_FULLSCREEN))
            return SBERG_ERR_AMFSFAILED;
    }

    flags &= ~(SBERG_PLAYER_PLAYING | SBERG_PLAYER_PAUSED);

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - close
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::close()
{
    if (am_graph)
    {
        stop();

        //陳� Ensure window disconnect
        IVideoWindow *am_vwindow=0;
        HRESULT hr = am_graph->QueryInterface(IID_IVideoWindow,
                                              (void**)&am_vwindow);
        if (SUCCEEDED(hr))
        {
            am_vwindow->put_Owner(NULL);
            am_vwindow->put_Visible(OAFALSE); //?ShowWindow?
            am_vwindow->Release();
            am_vwindow=0;
        }

        //陳� Release graph
        am_graph->Release();
        am_graph=0;

        am_event=0;
    }

    flags &= ~(SBERG_PLAYER_PLAYING | SBERG_PLAYER_PAUSED);

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - play
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::play()
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

    if (get_flags() & SBERG_PLAYER_PLAYING)
        return SBERG_ERR_NONE;

//陳� Get media control interface
    IMediaControl *am_mediactrl=0;
    HRESULT hr=am_graph->QueryInterface(IID_IMediaControl,
                                        (void**)&am_mediactrl);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Start playing
    hr=am_mediactrl->Run();

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    OAFilterState state;
    am_mediactrl->GetState(INFINITE, &state);

    am_mediactrl->Release();
    am_mediactrl=0;

    flags |= SBERG_PLAYER_PLAYING;
    flags &= ~SBERG_PLAYER_PAUSED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - stop
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::stop()
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

    if (!(get_flags() & SBERG_PLAYER_PLAYING))
        return SBERG_ERR_NONE;

//陳� Get media control & position interfaces
    IMediaControl *am_mediactrl=0;
    HRESULT hr=am_graph->QueryInterface(IID_IMediaControl,
                                        (void**)&am_mediactrl);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

    IMediaPosition *am_mediapos=0;
    hr=am_graph->QueryInterface(IID_IMediaPosition, (void**)&am_mediapos);
    if (FAILED(hr))
    {
        am_mediactrl->Release();
        return SBERG_ERR_AMQUERYIFAILED;
    }

//陳� Stop playing, doing a rewind to start
    hr=am_mediactrl->Pause();
    if (FAILED(hr))
    {
        am_mediactrl->Release();
        am_mediapos->Release();
        return SBERG_ERR_AMFAILED;
    }

    hr=am_mediapos->put_CurrentPosition(0);

    am_mediapos->Release();
    am_mediapos=0;

    if (FAILED(hr))
    {
        am_mediactrl->Release();
        return SBERG_ERR_AMFAILED;
    }

    hr=am_mediactrl->StopWhenReady();

    am_mediactrl->Release();
    am_mediactrl=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    flags &= ~(SBERG_PLAYER_PLAYING | SBERG_PLAYER_PAUSED);

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - pause
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::pause()
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

    if (!(get_flags() & SBERG_PLAYER_PLAYING))
        return SBERG_ERR_NOTPLAYING;

    if (flags & SBERG_PLAYER_PAUSED)
        return SBERG_ERR_NONE;

//陳� Get media control interface
    IMediaControl *am_mediactrl=0;
    HRESULT hr=am_graph->QueryInterface(IID_IMediaControl,
                                        (void**)&am_mediactrl);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Pause
    hr=am_mediactrl->Pause();

    OAFilterState state;
    am_mediactrl->GetState(INFINITE, &state);

    am_mediactrl->Release();
    am_mediactrl=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    flags |= SBERG_PLAYER_PAUSED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - resume
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::resume()
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

    if (!(get_flags() & SBERG_PLAYER_PLAYING))
        return SBERG_ERR_NOTPLAYING;

    if (!(flags & SBERG_PLAYER_PAUSED))
        return SBERG_ERR_NONE;

//陳� Get media control interface
    IMediaControl *am_mediactrl=0;
    HRESULT hr=am_graph->QueryInterface(IID_IMediaControl,
                                        (void**)&am_mediactrl);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Resume playback
    hr=am_mediactrl->Run();

    OAFilterState state;
    am_mediactrl->GetState(INFINITE, &state);

    am_mediactrl->Release();
    am_mediactrl=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    flags &= ~SBERG_PLAYER_PAUSED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - set_position
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::set_position(ulong ms)
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

//陳� Get media control & position interfaces
    IMediaControl *am_mediactrl=0;
    HRESULT hr=am_graph->QueryInterface(IID_IMediaControl,
                                        (void**)&am_mediactrl);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

    IMediaPosition *am_mediapos=0;
    hr=am_graph->QueryInterface(IID_IMediaPosition, (void**)&am_mediapos);
    if (FAILED(hr))
    {
        am_mediactrl->Release();
        return SBERG_ERR_AMQUERYIFAILED;
    }

//陳� Set position
    hr=am_mediapos->put_CurrentPosition(ms / 1000.0f);

    am_mediapos->Release();
    am_mediapos=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    OAFilterState state;
    am_mediactrl->GetState(INFINITE, &state);

    am_mediactrl->Release();
    am_mediactrl=0;

    flags &= ~(SBERG_PLAYER_PLAYING | SBERG_PLAYER_PAUSED);

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - get_position
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong SpielbergAMPlayer::get_position() const
{
    if (!am_graph)
        return 0;

//陳� Get media position interface
    IMediaPosition *am_mediapos=0;
    HRESULT hr=am_graph->QueryInterface(IID_IMediaPosition,
                                        (void**)&am_mediapos);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Get position
    REFTIME time;
    hr = am_mediapos->get_CurrentPosition(&time);

    am_mediapos->Release();
    am_mediapos=0;

    if (FAILED(hr))
        return 0;

    return ulong(time * 1000.0f);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - get_info
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::get_info(SpielbergInfo *info) const
{
    if (!info)
        return SBERG_ERR_INVALIDPARMS;

    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

    memset(info,0,sizeof(SpielbergInfo));

//陳� Get media position interface
    IMediaPosition *am_mediapos=0;
    HRESULT hr=am_graph->QueryInterface(IID_IMediaPosition,
                                        (void**)&am_mediapos);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Get duration of stream
    REFTIME time;
    hr = am_mediapos->get_Duration(&time);

    am_mediapos->Release();
    am_mediapos=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    info->duration = ulong(time * 1000.0f);

//陳� Get basic video interface
    IBasicVideo *am_video=0;
    hr = am_graph->QueryInterface(IID_IBasicVideo, (void**)&am_video);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Get width and height of video
    long w, h;
    hr = am_video->GetVideoSize(&w,&h);
    if (FAILED(hr))
    {
        am_video->Release();
        return SBERG_ERR_AMFAILED;
    }

    info->width = ushort(w);
    info->height = ushort(h);

    am_video->Release();
    am_video=0;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - get_flags
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
dword SpielbergAMPlayer::get_flags()
{
    if (!am_graph)
        return flags;

//陳� Get media event interface
    IMediaEvent *am_mediaevt;
    HRESULT hr=am_graph->QueryInterface(IID_IMediaEvent,
                                        (void**)&am_mediaevt);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Check events
    long code, lparm1, lparm2;

    hr = am_mediaevt->GetEvent(&code, &lparm1, &lparm2, 0);
    if (SUCCEEDED(hr))
    {
        switch (code)
        {
            case EC_COMPLETE:
            case EC_ERRORABORT:
            case EC_USERABORT:
                stop();
                break;
        }
    }

    am_mediaevt->Release();

    return flags;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - display
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void SpielbergAMPlayer::display()
{
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - get_window_styles
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::get_window_styles(long *style,
                                                     long *styleex)
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

//陳� Get video window interface
    IVideoWindow *am_vwindow=0;
    HRESULT hr = am_graph->QueryInterface(IID_IVideoWindow,
                                          (void**)&am_vwindow);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Get window parameters
    if (style)
    {
        hr=am_vwindow->get_WindowStyle(style);
    }
    if (styleex)
    {
        hr=am_vwindow->get_WindowStyleEx(styleex);
    }

    am_vwindow->Release();
    am_vwindow=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - set_window_styles
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::set_window_styles(long style,
                                                     long styleex)
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

//陳� Get video window interface
    IVideoWindow *am_vwindow=0;
    HRESULT hr = am_graph->QueryInterface(IID_IVideoWindow,
                                          (void**)&am_vwindow);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Set window parameters
    hr=am_vwindow->put_WindowStyle(style);
    hr=am_vwindow->put_WindowStyleEx(styleex);

    am_vwindow->Release();
    am_vwindow=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - get_window_pos
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::get_window_pos(long *x, long *y)
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

//陳� Get video window interface
    IVideoWindow *am_vwindow=0;
    HRESULT hr = am_graph->QueryInterface(IID_IVideoWindow,
                                          (void**)&am_vwindow);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Get window parameters
    if (x)
    {
        hr=am_vwindow->get_Left(x);
    }
    if (y)
    {
        hr=am_vwindow->get_Top(y);
    }

    am_vwindow->Release();
    am_vwindow=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - set_window_pos
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::set_window_pos(long x, long y)
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

//陳� Get video window interface
    IVideoWindow *am_vwindow=0;
    HRESULT hr = am_graph->QueryInterface(IID_IVideoWindow,
                                          (void**)&am_vwindow);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Set window parameters
    hr=am_vwindow->put_Left(x);
    am_vwindow->put_Top(y);

    am_vwindow->Release();
    am_vwindow=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - set_source_rect
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::set_source_rect(long x, long y,
                                                   long w, long h)
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

//陳� Get basic video interface
    IBasicVideo *am_video=0;
    HRESULT hr = am_graph->QueryInterface(IID_IBasicVideo, (void**)&am_video);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Set destination rectangle
    hr=am_video->SetSourcePosition(x, y, w, h);

    am_video->Release();
    am_video=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - set_dest_rect
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMPlayer::set_dest_rect(long x, long y,
                                                 long w, long h)
{
    if (!am_graph)
        return SBERG_ERR_UNINITIALIZED;

//陳� Get basic video interface
    IBasicVideo *am_video=0;
    HRESULT hr = am_graph->QueryInterface(IID_IBasicVideo, (void**)&am_video);
    if (FAILED(hr))
        return SBERG_ERR_AMQUERYIFAILED;

//陳� Set destination rectangle
    hr=am_video->SetDestinationPosition(x, y, w, h);

    am_video->Release();
    am_video=0;

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    return SBERG_ERR_NONE;
}

//葦� End of module - sbrgamp.cpp 憶�

