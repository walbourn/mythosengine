@echo off
if .%1==.tools goto tools
if .%1==.tests goto tests
if .%1==.examples goto examples
rem ÄÄÄÄ Ivory 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd ivory
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Felix 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd felix
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ XFile 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd xfile
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Chronos 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd chronos
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Bozo 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd bozo
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Max 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd max
call mk %1
if ERRORLEVEL 1 goto error
cd ..      
rem ÄÄÄÄ Van Gogh 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd vangogh
call mk %1
if ERRORLEVEL 1 goto error
cd ..      
rem ÄÄÄÄ Escher 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd escher
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Gutenberg 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd gutenbrg
call mk %1
if ERRORLEVEL 1 goto error
cd ..      
rem ÄÄÄÄ Turner 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
rem cd turner
rem call mk %1
rem if ERRORLEVEL 1 goto error
rem cd ..
rem ÄÄÄÄ Newton 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd newton
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Bach 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
rem cd bach
rem call mk %1
rem if ERRORLEVEL 1 goto error
rem cd ..
rem ÄÄÄÄ Spielberg 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd spielbrg
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Pane 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd pane
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ System 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd system
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ SimGine ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
rem cd simgine
rem call mk %1
rem if ERRORLEVEL 1 goto error
rem cd ..
goto exit
rem *************************************************************************
rem *************************** Tools ***************************************
rem *************************************************************************
:tools
rem ÄÄÄÄ XFile 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd xfile
call mk tools
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Max 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd max
call mk tools
if ERRORLEVEL 1 goto error
cd ..      
rem ÄÄÄÄ Van Gogh 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd vangogh
call mk tools
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Escher 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd escher
call mk tools
if ERRORLEVEL 1 goto error
cd ..
rem ÄÄÄÄ Gutenberg 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd gutenbrg
call mk tools
if ERRORLEVEL 1 goto error
cd ..      
rem ÄÄÄÄ MythOS 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd util
call mk tools
if ERRORLEVEL 1 goto error
cd ..
goto exit
rem *************************************************************************
rem *************************** Tests ***************************************
rem *************************************************************************
:tests
rem ÄÄÄÄ Ivory 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd ivory\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Felix 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd felix\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ XFile 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd xfile\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Chronos 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd chronos\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Bozo 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd bozo\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Max 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd max\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Van Gogh 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd vangogh\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Escher 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd escher\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Gutenberg 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd gutenbrg\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Turner 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
rem cd turner\test
rem call mk clean
rem call mk
rem if ERRORLEVEL 1 goto error
rem cd ..\..
rem ÄÄÄÄ Newton 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd newton\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Bach 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd bach\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Spielberg 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd spielbrg\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ System 95 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd system\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ SimGine ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
rem cd simgine\test
rem call mk clean
rem call mk
rem if ERRORLEVEL 1 goto error
rem cd ..\..
goto exit
rem *************************************************************************
rem *************************** Examples ************************************
rem *************************************************************************
:examples
rem ÄÄÄÄ 3D Viewer ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd examples\viewer
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ LLander ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd examples\llander
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ÄÄÄÄ Script ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
cd examples\script
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
:error
:exit
