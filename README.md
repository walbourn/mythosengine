![MythOS](https://raw.githubusercontent.com/wiki/walbourn/mythosengine/images/mythos.bmp)

Copyright (c) 1994-1999 by Dan Higdon, Tim Little, Chuck Walbourn
 
The "MythOS collection" is a set of C++ game libraries developed in the mid-1990s at Charybdis Enterprises, a now defunct independent game developer in Austin, TX. The libraries were used to build the game engines for Interactive Magic's _iM1A2 Abrams_ and _iPanzer '44_, and Atari's _Ares Rising_.

When the company was shut down in 1998, the MythOS library was released as open source. This release does not contain any of the engine code for any of the titles.

# Development Tools

The MythOS libraries were initially developed with Watcom C++ targeting the DOS/4GW DOS extender, but then transitioned to Windows 95 and Microsoft Visual C++ 4, 5, and 6. The 1.8 version of the library used DirectX 6.1.

# Components

* **Bach** - Sound library
* **Bozo** - Task switcher (Fiber-like implementation for DOS, defuct for Windows)
* **Chronos** - Timer services
* **Escher** - 3D graphics system
* **Felix** - Fixed-point support
* **Gutenberg** - Font and string support
* **Ivory** - Memory-management
* **Max** - Event and input system
* **Newton** - Physics system
* **Pane** - Windowing library
* **SimGine** - Simulator application framework
* **Spielberg** - Animation player
* **System**
* **Turner** - Network system
* **Util**
* **VanGogh** - 2D graphics system
* **XFile** - File system

# Build Instructions

* Open a "VS2013 x86 Native Tools Command Prompt"
* set the environment variable ``MYTH95ROOT``
* Run ``build.bat``

For example

    set MYTH95ROOT=d:\CHARYBDS\MythOS95
    cd MythOS95\Source
    build

To do a clean rebuild, ``del /s *.obj``

## Notices

All content and source code for this package are subject to the terms of the [MIT License](http://opensource.org/licenses/MIT).
