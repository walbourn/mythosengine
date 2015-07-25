@echo off
echo 같같같굉 Paltool 껑같같같같같같같같같같같같같같같같같같같같같같같같�
if %1.==clean. goto clean
call nmake /f Paltool.MAK CFG="Paltool - Win32 Release"
if ERRORLEVEL 1 goto error
if %1.==release. goto rel
goto cont
:clean
deltree /Y winrel
goto cont
:rel
if %MYTH95ROOT%.==. goto def
copy winrel\*.exe %MYTH95ROOT%\Bin
goto cont
:def
copy winrel\*.exe \MythOS95\Bin
:cont
echo 같같같굉 Paltool - Done 껑같같같같같같같같같같같같같같같같같같같같같
goto exit
:error
echo  E r r o r 
:exit
