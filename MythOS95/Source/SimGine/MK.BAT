@echo off
echo °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
echo °°°°°°°°°±²                                                   ²±°°°°°°°°
echo °°°°°°°°°±²                S I M    G I N E                   ²±°°°°°°°°
echo °°°°°°°°°±²                                                   ²±°°°°°°°°
echo °°°°°°°°°±² Copyright (C) 1997 by Charybdis Enterprises, Inc. ²±°°°°°°°°
echo °°°°°°°°°±²                                                   ²±°°°°°°°°
echo °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
cd obj
call nmake /nologo %1 %2 %3 %4 %5 %6 %7 %8 %9
cd ..
if ERRORLEVEL 1 goto error
echo °°°°°°±² SimGine - Done ²±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
goto exit
:error
echo  E r r o r 
:exit
