@echo off
echo 같같같굉 Bozo Tester 껑같같같같같같같같같같같같같같같같같같같같같같같같�
cd obj
nmaker /nologo %1 %2 %3 %4 %5 %6 %7 %8 %9
cd ..
if ERRORLEVEL 1 goto error
echo 같같같굉 Bozo Tester - Done 껑같같같같같같같같같같같같같같같같같같같같같
goto exit
:error
echo  E r r o r 
:exit
