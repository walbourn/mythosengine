
                                 Jb
                                 $$$c
               $$$$$$$$$$$$$$$$$$$$$$b       d$$$$$$$$$$$$$$$$$$$$$P
              .$$$$$$$$$$$$$$$$$$$$$$$$.     $$$$$$$$$$$$$$$$$$$$$$
              ^""""""$$$$$P""""3$$$$$$$$c   d$$$$$""""$$$$$$"""""""
                    4$$$$$"    $$$$$$$$$$b  $$$$$F   .$$$$$F
                    $$$$$P    4$$$$$$$$$$$$$$$$$$    d$$$$$
                   4$$$$$"    $$$$$$$$$$$$$$$$$$P    $$$$$F
                   $$$$$$    4$$$$$""$$$$$$$$$$$    d$$$$$
                  4$$$$$"    $$$$$$  ^$$$$$$$$$P    $$$$$F
                  $$$$$$    4$$$$$%    *$$$$$$$"   J$$$$$
                 4$$$$$%    $$$$$$      ^$$$$$P    $$$$$F
                 """"""     """"""        *$$$"    """"""
                                           "$$
                                            ^%
  
                           Turner - Networking Library
  
                      Microsoft Windows 95/98/NT Version
  
    Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
  
 ---------------------------------------------------------------------------

  THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
  OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
  PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
  LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
  OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

                         http://www.mythos-engine.org/

 ---------------------------------------------------------------------------

                              _Library Status_

  Notes by: Chuck Walbourn
  Updated:  July 6, 1999

  Changes for this release --------------------------------------------------

  - Updated for new DirectPlay4A interface.

  - The recieve routine no longer returns data to the caller as you must
    implement handle_msg() and handle_chat() in order to use TurnerNetwork.
    The system will allocate the memory required to store messages for
    the Recieve.

  - Lots of additional functions exposed and the interface has been broken
    out into TurnerClassic and TurnerNetwork to simplify learning the
    commands.  Also renamed 'creator' to more logical 'host' since you
    can have migrating hosts.

  - Most virtuals have changed parameter lists and these will compile
    without warnings in dervied code, BUT WILL NOT OPERATE.  You should
    therefore check each overload in classes derived from TurnerNetwork to
    make sure you have matching signatures.



  Proposed future changes ---------------------------------------------------

  - A TurnerSecureNetwork class should be derived from TurnerNetwork
    to add secure session support with both encrypted and/or signed
    sending.

*** END OF FILE ***
