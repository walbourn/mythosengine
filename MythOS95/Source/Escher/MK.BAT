@echo off
if %1.==tools. goto tools
echo °°°°°°±² Escher '95 ²±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
cd obj
call nmake /nologo %1 %2 %3 %4 %5 %6 %7 %8 %9
cd ..
if ERRORLEVEL 1 goto error
echo °°°°°°±² Escher '95 - Done ²±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
goto exit
:tools
echo °°°°°°±² Escher '95 Tools ²±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
echo ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
echo These depend on released libraries                                     ³
echo ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Tool
cd tool
deltree /Y winrel
call mk release
cd ..
if ERRORLEVEL 1 goto error
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Terrain Editor
cd edit
deltree /Y winrel
call mk release
cd ..
if ERRORLEVEL 1 goto error
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Utilities
cd util
call mk clean
call mk release
cd ..
if ERRORLEVEL 1 goto error
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Exporter
if %WATCOM%.==. goto skipexp
cd export
call mk clean
call mk release
cd ..
if ERRORLEVEL 1 goto error
goto done
:skipexp
echo  Skipping Exporter build, which needs Watcom 
:done
echo °°°°°°±² Escher '95 Tools - Done ²±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
goto exit
:error
echo  E r r o r 
:exit
