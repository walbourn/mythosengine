@echo off
if %watcom%.==. goto needwtc
echo 같같같굉 Escher Exporter 껑같같같같같같같같같같같같같같같같같같같같같같�
cd obj
call nmake /nologo %1 %2 %3 %4 %5 %6 %7 %8 %9
cd ..
if ERRORLEVEL 1 goto error
echo 같같같굉 Escher Exporter - Done 껑같같같같같같같같같같같같같같같같같같같
goto exit
:needwtc
echo  Watcom compiler (and IPAS4 toolkit) needed to build the exporter 
goto exit
:error
echo  E r r o r 
:exit
