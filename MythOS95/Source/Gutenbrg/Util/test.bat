@echo off
del *.iff
del ..\test\3x6.iff
del ..\test\5x8.iff
del ..\test\7x12.iff
del ..\test\8x13.iff
del ..\test\9x15.iff
del ..\test\12x24.iff
del ..\test\test.iff
if %1.==bdf. goto bdf
if %1.==arial. goto arial
if %1.==courier. goto courier
if %1.==timesnr. goto timesnr
if %1.==oldstyle. goto oldstyle
if %1.==scrawl. goto scrawl
if %1.==ttarial. goto ttarial
if %1.==ttcourier. goto ttcourier
if %1.==tttimesnr. goto tttimesnr
if %1.==ttfreehand. goto ttfreehand
goto error
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ UNIX BDF
:bdf
obj\gfont -q 5x8.bdf
obj\gfont -q 8x13.bdf
obj\gfont -q 9x15.bdf
obj\gfont -q 12x24.bdf
goto done
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Arial
:arial
obj\gfont -q arial.bmp 3x6.iff -n 3x6 -w3 -h6 -x1 -y11 -p1 -s33 -c94 -r47 
obj\gfont -q arial.bmp 5x8.iff -n 5x8 -w5 -h8 -x1 -y44 -p1 -s33 -c94 -r47 
obj\gfont -q arial.bmp 7x12.iff -n 7x12 -w7 -h12 -x1 -y83 -p1 -s33 -c94 -r47 
obj\gfont -q arial.bmp 9x15.iff -n 9x15 -w9 -h15 -x1 -y130 -p1 -s33 -c94 -r47 
obj\gfont -q arial.bmp 12x24.iff -n 12x24 -w12 -h24 -x1 -y183 -p1 -s33 -c94 -r47 
goto done
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Courier
:courier
obj\gfont -q courier.bmp 5x8.iff -n 5x8 -w5 -h8 -x1 -y44 -p1 -s33 -c94 -r47 
obj\gfont -q courier.bmp 7x12.iff -n 7x12 -w7 -h12 -x1 -y83 -p1 -s33 -c94 -r47 
obj\gfont -q courier.bmp 9x15.iff -n 9x15 -w9 -h15 -x1 -y130 -p1 -s33 -c94 -r47 
goto done
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ New Times Roman
:timesnr
obj\gfont -q timesnr.bmp 3x6.iff -n 3x6 -w3 -h6 -x1 -y11 -p1 -s33 -c94 -r47 
obj\gfont -q timesnr.bmp 5x8.iff -n 5x8 -w5 -h8 -x1 -y44 -p1 -s33 -c94 -r47 
obj\gfont -q timesnr.bmp 7x12.iff -n 7x12 -w7 -h12 -x1 -y83 -p1 -s33 -c94 -r47 
obj\gfont -q timesnr.bmp 9x15.iff -n 9x15 -w9 -h15 -x1 -y130 -p1 -s33 -c94 -r47 
goto done
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Old Style
:oldstyle
obj\gfont -q oldstyle.bmp 9x15.iff -n 9x15 -w9 -h15 -x1 -y130 -p1 -s33 -c94 -r47 
obj\gfont -q oldstyle.bmp 12x24.iff -n 12x24 -w12 -h24 -x1 -y183 -p1 -s33 -c94 -r47 
goto done
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Scrawl
:scrawl
obj\gfont -q scrawl.bmp 7x12.iff -n 7x12 -w7 -h12 -x1 -y83 -p1 -s33 -c94 -r47 
obj\gfont -q scrawl.bmp 9x15.iff -n 9x15 -w9 -h15 -x1 -y130 -p1 -s33 -c94 -r47 
obj\gfont -q scrawl.bmp 12x24.iff -n 12x24 -w12 -h24 -x1 -y183 -p1 -s33 -c94 -r47 
goto done
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ TrueType Arial
:ttarial
obj\gfont -q "Arial" 3x6.iff -n 3x6 -h6
obj\gfont -q "Arial" 5x8.iff -n 5x8 -h8
obj\gfont -q "Arial" 7x12.iff -n 7x12 -h12
obj\gfont -q "Arial" 8x13.iff -n 8x13 -h13
obj\gfont -q "Arial" 9x15.iff -n 9x15 -h15
obj\gfont -q "Arial" 12x24.iff -n 12x24 -h24
goto done
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ TrueType Courier New
:ttcourier
obj\gfont -q "Courier New" 3x6.iff -n 3x6 -h6
obj\gfont -q "Courier New" 5x8.iff -n 5x8 -h8
obj\gfont -q "Courier New" 7x12.iff -n 7x12 -h12
obj\gfont -q "Courier New" 8x13.iff -n 8x13 -h13
obj\gfont -q "Courier New" 9x15.iff -n 9x15 -h15
obj\gfont -q "Courier New" 12x24.iff -n 12x24 -h24
goto done
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ TrueType Times New Roman
:tttimesnr
obj\gfont -q "Times New Roman" 3x6.iff -n 3x6 -h6
obj\gfont -q "Times New Roman" 5x8.iff -n 5x8 -h8
obj\gfont -q "Times New Roman" 7x12.iff -n 7x12 -h12
obj\gfont -q "Times New Roman" 8x13.iff -n 8x13 -h13
obj\gfont -q "Times New Roman" 9x15.iff -n 9x15 -h15
obj\gfont -q "Times New Roman" 12x24.iff -n 12x24 -h24
goto done
rem ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ TrueType Freehand 521 BT
:ttfreehand
obj\gfont -q "Freehand 521 BT" 3x6.iff -n 3x6 -h6
obj\gfont -q "Freehand 521 BT" 5x8.iff -n 5x8 -h8
obj\gfont -q "Freehand 521 BT" 7x12.iff -n 7x12 -h12
obj\gfont -q "Freehand 521 BT" 8x13.iff -n 8x13 -h13
obj\gfont -q "Freehand 521 BT" 9x15.iff -n 9x15 -h15
obj\gfont -q "Freehand 521 BT" 12x24.iff -n 12x24 -h24
goto done
:done
obj\gstring -q test.cst
copy 3x6.iff ..\test
copy 5x8.iff ..\test
copy 7x12.iff ..\test
copy 8x13.iff ..\test
copy 9x15.iff ..\test
copy 12x24.iff ..\test
copy test.iff ..\test
cd ..\test
call gt
cd ..\util
goto exit
:error
echo Expected 'bdf', 'arial', 'courier', 'timesnr', 'oldstyle', or 'scrawl'
:exit
