@echo off
if %1.==tools. goto tools
echo 같같같굉 Gutenberg 95 껑같같같같같같같같같같같같같같같같같같같같같같같같
cd obj
call nmake /nologo %1 %2 %3 %4 %5 %6 %7 %8 %9
cd ..
if ERRORLEVEL 1 goto error
echo 같같같굉 Gutenberg 95 - Done 껑같같같같같같같같같같같같같같같같같같같같�
goto exit
:tools
echo 같같같굉 Gutenberg 95 Tools 껑같같같같같같같같같같같같같같같같같같같같같
echo 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
echo These depend on released libraries                                     �
echo 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
cd util
call mk clean
call mk release
cd ..
if ERRORLEVEL 1 goto error
echo 같같같굉 Gutenberg 95 Tools - Done 껑같같같같같같같같같같같같같같같같같�
goto exit
:error
echo  E r r o r 
:exit
