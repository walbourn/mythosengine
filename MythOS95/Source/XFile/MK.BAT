@echo off
if %1.==tools. goto tools
echo °°°°°°±² XFile 95 ²±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
cd obj
call nmake /nologo %1 %2 %3 %4 %5 %6 %7 %8 %9
cd ..
if ERRORLEVEL 1 goto error
echo °°°°°°±² XFile 95 - Done ²±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
goto exit
:tools
echo °°°°°°±² XFile 95 Tools ²±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
echo ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
echo These depend on released libraries                                     ³
echo ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
cd util
call mk clean
call mk release
cd ..
if ERRORLEVEL 1 goto error
echo °°°°°°±² XFile 95 Tools - Done ²±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
goto exit
:error
echo  E r r o r 
:exit
