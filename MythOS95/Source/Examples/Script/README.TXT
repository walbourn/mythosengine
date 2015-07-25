 
                                 /\    /\
                                /  \  /  \
                               /    \/    \
                              /  /\    /\  \
                             /  /  \  /  Y T H O S
                            /  /    \/    \  \
                           /  /            \  \
                          /__/              \__\
 
                     Microsoft Windows 95/NT Version

             Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
                            All Rights Reserved.

 ---------------------------------------------------------------------------
 
            *** Charybdis Enterprises, Inc. Company Confidential ***
 
   This file and all associated files are the company proprietary property
         of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
 
  CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
  TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
  IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
  AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
  INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

  This example application is a component of the MythOS(tm) entertainment
  and multi-media development library.

  MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                               3D SCRIPT EXAMPLE

 Notes by: Chuck Walbourn
 Updated: January 2, 1998


 ---------------------------------------------------------------------------
 DESCRIPTION

 This example implements a simple scripting system for 3D objects.  The
 script language includes creation, modifcation, and animation of cameras,
 lights, mesh objects, and particle generators.



 ---------------------------------------------------------------------------
 PARAMETERS

 The parameters are taken from the SCRIPT.INI file.  The [Screen] section
 specifies information about the Van Gogh viewport, screen device, and
 palette to use.  The [Startup] section controls additional startup
 parameters.


 ---------------------------------------------------------------------------
 CONTROLS

 The controls can be changed by editing the SCREVT.CEL file.  They are
 currently setup as follows:

 Esc or Alt+Q       Quits
 Space              Continue from pause or waitkey.


 ---------------------------------------------------------------------------
 SCRIPT LANGUAGE

 The Charybdis Script File language is used to control the objects, lighting,
 viewpoint, and animation rendered onto the screen.  Comments are '//' to
 end of file (C++ style) and the commands are acted upon as they are
 parsed (interpreted instead of compiled).

 The basic commands are 'create', 'modify', and 'animate' plus a few
 special commands.  The 'create' statement instantiates new cameras,
 lights, and drawabables and sets one or more of their attributes.  The
 'modify' statement changes the attributes of an existing instance, which
 if performed at different times results in motion.  The 'animate' statement
 adds per-frame adjustment logic to drawables for automatic dynamic movement
 over time (may be extended in future to affect lights and cameras).


 Note: The brace symbols are used to indicate optional list of values in
       the grammer and are enlosed in single-quotes ('{', '}') to indicate
       usage as terminal symbols.  The symbols [, ] indicate optional
       components of a statement.  The symbol | indiciates multiple
       mappings for non-terminal symbol which are names enclosed in
       brackets <>.

       <name> :- "string"
       <file> :- "filename and path"
       <float> :- floating-point number
       <integer> :- integer number

 CAMERAS

    <create> :- create camera=<name> [ file=<file> ] '{' <camera-body> '}'

        Creates or loads a new camera instance from disk.

    <modify> :- modify camera=<name> '{' <camera-body> '}'

        Modifies a camera instance.

    <camera-body> :- shade={wire | flat | solid | smooth | specular};
                     | bfculling={on | off | yes | no};
                     | textured={on | off | yes | no};
                     | perspective={on | off | yes | no};
                     | alpha={on | off | yes | no};
                     | show_all_lines={on | off | yes | no};
                     | position=<float>,<float>,<float>;
                     | top=<float>,<float>,<float>;
                     | direction=<float>,<float>,<float>;
                     | lookat=<float>,<float>,<float>;
                     | factor=<float>;
                     | fov=<float>;
                     | hither=<float>;
                     | yon=<float>;
                     | aspect_ratio=<float>;
                     | bcolor=<integer>,<integer>,<integer>;
                     | bitmap=<file>;
                     | haze={<float>,<float> | on | off | yes | no};
                     | rotatex=<float>;
                     | rotatey=<float>;
                     | rotatez=<float>;
                     | yaw=<float>;
                     | pitch=<float>;
                     | roll=<float>;
                     | translate=<float>,<float>,<float>;
                     | move=<float>,<float>,<float>;
                     | <empty>

        Defines an attribute or applies an operation to the camera.

    viewpoint <name>;

        Attaches the named camera to the viewport.


 LIGHTS

    <create> :- create light=<name>
                [ type={ambient | vector | point | atten | spot
                        | fastpoint | fastatten | fastspot} ]
                [ file=<file> ] '{' <light-body> '}'

        Creates or loads a new light instance from disk.

    <modify> :- modify light=<name> '{' <light-body> '}'

        Modifies a light instance.

    <light-body> :- intensity=<integer>;
                    | active={on | off | yes | no};
                    | darklight={on | off | yes | no};

                    (not valid for vector or ambient)
                    | position=<float>,<float>,<float>;
                    | translate=<float>,<float>,<float>;

                    (only valid for vector, spot, and fastspot)
                    | direction=<float>,<float>,<float>;
                    | rotatex=<float>;
                    | rotatey=<float>;
                    | rotatez=<float>;

                    (only valid for atten, spot, fastatten, or fastspot)
                    | attenuated={on | off | yes | no};
                    | inner=<float>;
                    | outer=<float>;

                    (only valid for spot or fastspot)
                    | hotspot=<float>;
                    | falloff=<float>;

                    | <empty>


        Defines an attribute or applies an operation to the light.

    activate <name>;
    deactivate <name>;

        Turns on or off a light.


 DRAWABLES

    <create> :- create drawable=<name>
                [ type={mesh | particle} ]
                [ maxcount=<integer> ]
                [ file=<file> ] '{' <drawable-body> '}'

        Creates or loads a new drawable instance from disk.

    <modify> :- modify drawable=<name> '{' <drawable-body> '}'

        Modifies a drawable instance.

    <drawable-body> :- position=<float>,<float>,<float>;
                       | visible={on | off | yes | no};
                       | translate=<float>,<float>,<float>;
                       | move=<float>,<float>,<float>;
                       | direction=<float>,<float>,<float>;
                       | top=<float>,<float>,<float>;
                       | rotatex=<float>;
                       | rotatey=<float>;
                       | rotatez=<float>;
                       | yaw=<float>;
                       | pitch=<float>;
                       | roll=<float>;

                       (only valid for particles)
                       | shape={dots | pyramids};
                       | sphere=<float>;
                       | circle=<float>,<float>;
                       | rectangle=<float>,<float>,<float>;
                       | parts=<float> [,<float>];
                       | speed=<float> [,<float>];
                       | size=<float> [,<float>];
                       | life=<float> [,<float>];
                       | color=<integer>,<integer>,<integer>
                               [,<integer>,<integer>,<integer> ];
                       | alpha=<integer> [,<integer>];
                       | acceleration=<float>,<float>,<float>;

                       | <empty>

        Defines an attribute or applies an operation to the drawable.

    animate drawable=<name> { <drawable-anim> }

        Adds animation information to the drawable which is processed based
        on the interval time (in seconds).  If a speed, target, or
        accleration is given, then a physics object is attached to
        the drawable for treating the drawable's position as a 

    <drawable-anim> :- speed=<float>;
                       | velocity=<float>,<float>,<float>;
                       | acceleration=<float>,<float>,<float>;
                       | rotatex=<float>;
                       | rotatey=<float>;
                       | rotatez=<float>;
                       | yaw=<float>;
                       | pitch=<float>;
                       | roll=<float>;

        Rotateions are in degrees/second and cannot be combined with speed
        or acceleration.

    show <name>;
    hide <name>;

        Makes the drawable visible or hidden.

    halt drawable=<name>;

        Stops any animation on the object.


 MISC

    render{=<integer>};

        Renders the next N frames (by default N is 1).

    wait=<integer>;

        Waits for the given number of milliseconds (rendering while waiting).

    waitkey{=<integer>};

        Waits for the NEXT key (usually <space>) to be pressed or
        until the number of optional number of milliseconds has passed
        (rendering while waiting).
    
    save{=<file>};

        Performs a screen-capture and saves to a given file or the next
        snap-shot filename if none given.

    include=<file>;

        Includes a script within the script file.


 ---------------------------------------------------------------------------
 LIBRARIES

 This makes use of the MythOS System class to initailize the libraries, but
 most of the calls used are those to setup Van Gogh and the use of Escher's
 basic drawable and camera control routines.  Max is used for the
 event processing and Newton is used for the physics based animation.

*** END OF FILE ***
