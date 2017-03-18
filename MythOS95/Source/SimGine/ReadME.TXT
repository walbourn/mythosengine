 ---------------------------------------------------------------------------

                              S I M   G I N E

             __               ___   ______,-------
           __==__,------------/|\--|      | .-.-.|    ___________
         (|     |--------------|---|------| '-`-`|  _/___________\_
         (|_____|      _       _   |   _  | 6000 | |               |
          |__\\_|`-._/___\___/___\_|_/___\|      | |               |
         __/ |===|--|_____|_|_____|_|___  |\_____|=|_______________|
      |=|[_]==[_]    \ _ /   \ _ /   \ _ /          [_]   [_]   [_]
 ---------------------------------------------------------------------------

                     A Simluator Framework for MythOS(tm)

                      Microsoft Windows 95/98/NT Version

    Copyright (c) 1997-1999 by Dan Higdon, Tim Little, and Chuck Walbourn

 ---------------------------------------------------------------------------

 THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
 OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
 PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
 LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
 OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

                        http://www.mythos-engine.org/

 ---------------------------------------------------------------------------

  This library is a component of the MythOS(tm) entertainment and multi-
  media development library.

 MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                             _Library Status_

 Notes by: Chuck Walbourn
 Updated: October 12, 1998

 Changes for this release --------------------------------------------------

 o All model objects release() members do a remove() so be sure to call
   the base version of release in your overriddes.

 o Expanded Audio support with some basic interfaces and additional startup
   parameters.

 o Updated with Direct3D target.

 o SimState::panic() now does a process exit to ensure immediate
   termination.

 o Fixed minor bugs.

*** END OF FILE ***
