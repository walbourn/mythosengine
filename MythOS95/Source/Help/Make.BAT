@if exist mythos.err del mythos.err > nul
@start /w d:\msdev6\common\tools\hcrtf -x mythos.hpj
@if exist mythos.err type mythos.err
