@echo off
echo 같같같굉 PalTool '95  껑같같같같같같같같같같같같같같같같같같같같같같같같
call nmake /f PALTOOL.MAK CFG="Win32 Release"
if ERRORLEVEL 1 goto error
echo 같같같굉 PalTool '95 - Done 껑같같같같같같같같같같같같같같같같같같같같같
goto exit
:error
echo  E r r o r 
:exit
