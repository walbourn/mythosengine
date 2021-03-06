@echo off
if %1.==tools. goto tools
echo 같같같굉 Escher 95 껑같같같같같같같같같같같같같같같같같같같같같같같같같�
cd obj
call nmake /nologo %1 %2 %3 %4 %5 %6 %7 %8 %9
cd ..
if ERRORLEVEL 1 goto error
echo 같같같굉 Escher 95 - Done 껑같같같같같같같같같같같같같같같같같같같같같같
goto exit
:tools
echo 같같같굉 Escher 95 Tools 껑같같같같같같같같같같같같같같같같같같같같같같�
echo 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
echo These depend on released libraries                                     �
echo 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
rem 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴 Tool
cd tool
deltree /Y winrel
call mk release
cd ..
if ERRORLEVEL 1 goto error
rem 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴 Terrain Editor
cd edit
deltree /Y winrel
call mk release
cd ..
if ERRORLEVEL 1 goto error
rem 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴� Utilities
cd util
call mk clean
call mk release
cd ..
if ERRORLEVEL 1 goto error
rem 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴 Exporter
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
echo 같같같굉 Escher 95 Tools - Done 껑같같같같같같같같같같같같같같같같같같같
goto exit
:error
echo  E r r o r 
:exit
