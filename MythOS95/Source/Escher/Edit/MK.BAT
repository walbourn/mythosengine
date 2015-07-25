@echo off
echo 같같같굉 Escher '95 Terrain Editor 껑같같같같같같같같같같같같같같같같같�
call nmake /f ESHTEDIT.MAK CFG="Win32 Release"
if ERRORLEVEL 1 goto error
echo 같같같굉 Escher '95 Terrain Editor - Done 껑같같같같같같같같같같같같같같
goto exit
:error
echo  E r r o r 
:exit
