;อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
;
;
;            _,'|             _.-''``-...___..--';)
;           /_ \'.      __..-' ,      ,--...--'''
;          <\    .`--'''       `     /'     
;           `-';'               ;   ; ;  Felix the Fixed-point Library
;     __...--''     ___...--_..'  .;.'
;    (,__....----'''       (,..--''
;
;                      Microsoft Windows '95 Version
;   
;           Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
;                           All Rights Reserved.
;
;ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
;
;           *** Charybdis Enterprises, Inc. Company Confidential ***
;
;  This file and all associated files are the company proprietary property
;        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
;
; CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
; TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
; IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
; AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
; INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
;
;ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
;
; flxdata.asm
;
;     This file has all of the Felix constant data for table lookup
;     functions.
;
;อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

.486p

        OPTION SCOPED                   ; Enable local labels.



;ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ
;
;                                 Data
;
;ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ

       ASSUME  ds:_DATA
_DATA  SEGMENT PARA PUBLIC USE32 'DATA'

        public Flx16_sin_data
Flx16_sin_data:                 ; table resolution is .5 degrees.
        dd      0
        dd      572             
        dd      1144            ; 1
        dd      1716            
        dd      2287            ; 2
        dd      2859            
        dd      3430            ; 3
        dd      4001            
        dd      4572            ; 4
        dd      5142
        dd      5712            ; 5
        dd      6281
        dd      6850            ; 6
        dd      7419
        dd      7987            ; 7
        dd      8554
        dd      9121            ; 8
        dd      9687            
        dd      10252           ; 9
        dd      10817
        dd      11380           ; 10
        dd      11942
        dd      12505           ; 11
        dd      13066
        dd      13626           ; 12
        dd      14185
        dd      14742           ; 13
        dd      15299           
        dd      15855           ; 14
        dd      16409           
        dd      16962           ; 15
        dd      17514
        dd      18064           ; 16
        dd      18613
        dd      19161           ; 17
        dd      19707
        dd      20252           ; 18
        dd      20795
        dd      21336           ; 19
        dd      21876
        dd      22415           ; 20
        dd      22951
        dd      23486           ; 21
        dd      24019   
        dd      24550           ; 22
        dd      25080
        dd      25607           ; 23
        dd      26132
        dd      26656           ; 24
        dd      27177           
        dd      27696           ; 25
        dd      28214
        dd      28729           ; 26
        dd      29242
        dd      29753           ; 27
        dd      30261
        dd      30767           ; 28
        dd      31271           
        dd      31772           ; 29
        dd      32271   
        dd      32768           ; 30
        dd      33262
        dd      33754           ; 31
        dd      34242   
        dd      34729           ; 32
        dd      35212
        dd      35693           ; 33
        dd      36172
        dd      36647           ; 34
        dd      37120
        dd      37590           ; 35
        dd      38057   
        dd      38521           ; 36
        dd      38982
        dd      39441           ; 37
        dd      39896
        dd      40348           ; 38
        dd      40797
        dd      41243           ; 39
        dd      41686
        dd      42126           ; 40
        dd      42562
        dd      42995           ; 41
        dd      43425
        dd      43852           ; 42
        dd      44275
        dd      44695           ; 43
        dd      45112
        dd      45525           ; 44
        dd      45935
        dd      46341           ; 45
        dd      46744
        dd      47143           ; 46
        dd      47538
        dd      47930           ; 47
        dd      48318
        dd      48703           ; 48
        dd      49084
        dd      49461           ; 49
        dd      49834
        dd      50203           ; 50
        dd      50569
        dd      50931           ; 51
        dd      51289
        dd      51643           ; 52
        dd      51993           
        dd      52339           ; 53
        dd      52682
        dd      53020           ; 54
        dd      53354
        dd      53684           ; 55
        dd      54010
        dd      54332           ; 56
        dd      54650
        dd      54963           ; 57
        dd      55273
        dd      55578           ; 58
        dd      55879
        dd      56175           ; 59
        dd      56468
        dd      56756           ; 60
        dd      57040
        dd      57319           ; 61
        dd      57594
        dd      57865           ; 62
        dd      58131
        dd      58393           ; 63
        dd      58650
        dd      58903           ; 64
        dd      59152
        dd      59396           ; 65
        dd      59635
        dd      59870           ; 66
        dd      60100
        dd      60326           ; 67
        dd      60547
        dd      60763           ; 68
        dd      60975
        dd      61183           ; 69
        dd      61385
        dd      61584           ; 70
        dd      61777           
        dd      61966           ; 71
        dd      62149
        dd      62328           ; 72
        dd      62503
        dd      62672           ; 73
        dd      62837
        dd      62997           ; 74
        dd      63152           
        dd      63303           ; 75
        dd      63449
        dd      63589           ; 76
        dd      63725
        dd      63856           ; 77
        dd      63983
        dd      64104           ; 78
        dd      64220
        dd      64332           ; 79
        dd      64439
        dd      64540           ; 80
        dd      64637
        dd      64729           ; 81
        dd      64816
        dd      64898           ; 82
        dd      64975
        dd      65048           ; 83
        dd      65115
        dd      65177           ; 84
        dd      65234
        dd      65287           ; 85
        dd      65334
        dd      65376           ; 86
        dd      65414
        dd      65446           ; 87
        dd      65477           
        dd      65496           ; 88
        dd      65514
        dd      65526           ; 89
        dd      65534           
        dd      65536           ; 90

        public Flx16_sqrt_table
Flx16_sqrt_table:
        dd   0000000h
        dd   0040000h
        dd   005a827h
        dd   006ed9eh
        dd   0080000h
        dd   008f1bbh
        dd   009cc47h
        dd   00a953fh
        dd   00b504fh
        dd   00c0000h
        dd   00ca62ch
        dd   00d4439h
        dd   00ddb3dh
        dd   00e6c15h
        dd   00ef775h
        dd   00f7defh
        dd   0100000h
        dd   0107e0fh
        dd   010f876h
        dd   0116f83h
        dd   011e377h
        dd   012548eh
        dd   012c2fch
        dd   0132eeeh
        dd   013988eh
        dd   0140000h
        dd   0146565h
        dd   014c8dch
        dd   0152a7fh
        dd   0158a68h
        dd   015e8adh
        dd   0164564h
        dd   016a09eh
        dd   016fa6eh
        dd   01752e5h
        dd   017aa10h
        dd   0180000h
        dd   01854bfh
        dd   018a85ch
        dd   018fae0h
        dd   0194c58h
        dd   0199ccch
        dd   019ec47h
        dd   01a3ad1h
        dd   01a8872h
        dd   01ad533h
        dd   01b211bh
        dd   01b6c30h
        dd   01bb67ah
        dd   01c0000h
        dd   01c48c6h
        dd   01c90d2h
        dd   01cd82bh
        dd   01d1ed5h
        dd   01d64d5h
        dd   01daa2fh
        dd   01deeeah
        dd   01e3307h
        dd   01e768dh
        dd   01eb97eh
        dd   01efbdeh
        dd   01f3db2h
        dd   01f7efbh
        dd   01fbfbfh
        dd   0200000h
        dd   0203fc0h
        dd   0207f03h
        dd   020bdcdh
        dd   020fc1eh
        dd   02139fbh
        dd   0217766h
        dd   021b460h
        dd   021f0edh
        dd   0222d0fh
        dd   02268c7h
        dd   022a419h
        dd   022df06h
        dd   0231990h
        dd   02353b9h
        dd   0238d82h
        dd   023c6efh
        dd   0240000h
        dd   02438b6h
        dd   0247115h
        dd   024a91dh
        dd   024e0d0h
        dd   025182fh
        dd   0254f3ch
        dd   02585f8h
        dd   025bc65h
        dd   025f284h
        dd   0262856h
        dd   0265ddch
        dd   0269319h
        dd   026c80ch
        dd   026fcb7h
        dd   027311ch
        dd   027653ah
        dd   0279915h
        dd   027ccabh
        dd   0280000h
        dd   0283312h
        dd   02865e4h
        dd   0289877h
        dd   028cacah
        dd   028fce0h
        dd   0292eb9h
        dd   0296056h
        dd   02991b8h
        dd   029c2dfh
        dd   029f3cdh
        dd   02a2482h
        dd   02a54ffh
        dd   02a8544h
        dd   02ab554h
        dd   02ae52dh
        dd   02b14d1h
        dd   02b4440h
        dd   02b737ch
        dd   02ba285h
        dd   02bd15bh
        dd   02c0000h
        dd   02c2e73h
        dd   02c5cb5h
        dd   02c8ac8h
        dd   02cb8abh
        dd   02ce65fh
        dd   02d13e4h
        dd   02d413ch
        dd   02d6e67h
        dd   02d9b65h
        dd   02dc837h
        dd   02df4ddh
        dd   02e2158h
        dd   02e4da8h
        dd   02e79ceh
        dd   02ea5cah
        dd   02ed19ch
        dd   02efd46h
        dd   02f28c8h
        dd   02f5421h
        dd   02f7f53h
        dd   02faa5eh
        dd   02fd542h
        dd   0300000h
        dd   0302a97h
        dd   030550ah
        dd   0307f57h
        dd   030a97fh
        dd   030d383h
        dd   030fd63h
        dd   031271fh
        dd   03150b8h
        dd   0317a2eh
        dd   031a381h
        dd   031ccb2h
        dd   031f5c1h
        dd   0321eaeh
        dd   032477ah
        dd   0327026h
        dd   03298b0h
        dd   032c11ah
        dd   032e964h
        dd   033118eh
        dd   0333999h
        dd   0336184h
        dd   0338951h
        dd   033b0ffh
        dd   033d88eh
        dd   0340000h
        dd   0342753h
        dd   0344e89h
        dd   03475a2h
        dd   0349c9dh
        dd   034c37ch
        dd   034ea3fh
        dd   03510e5h
        dd   035376fh
        dd   0355dddh
        dd   035842fh
        dd   035aa66h
        dd   035d082h
        dd   035f683h
        dd   0361c6ah
        dd   0364236h
        dd   03667e7h
        dd   0368d7fh
        dd   036b2fdh
        dd   036d861h
        dd   036fdach
        dd   03722ddh
        dd   03747f6h
        dd   0376cf5h
        dd   03791dch
        dd   037b6abh
        dd   037db61h
        dd   0380000h
        dd   0382486h
        dd   03848f5h
        dd   0386d4ch
        dd   038918ch
        dd   038b5b4h
        dd   038d9c6h
        dd   038fdc1h
        dd   03921a5h
        dd   0394572h
        dd   039692ah
        dd   0398ccbh
        dd   039b056h
        dd   039d3cbh
        dd   039f72bh
        dd   03a1a75h
        dd   03a3daah
        dd   03a60c9h
        dd   03a83d4h
        dd   03aa6c9h
        dd   03ac9aah
        dd   03aec76h
        dd   03b0f2dh
        dd   03b31d0h
        dd   03b545fh
        dd   03b76dah
        dd   03b9941h
        dd   03bbb94h
        dd   03bddd4h
        dd   03c0000h
        dd   03c2218h
        dd   03c441dh
        dd   03c660fh
        dd   03c87eeh
        dd   03ca9bah
        dd   03ccb73h
        dd   03ced1ah
        dd   03d0eaeh
        dd   03d3030h
        dd   03d519fh
        dd   03d72fch
        dd   03d9447h
        dd   03db580h
        dd   03dd6a7h
        dd   03df7bdh
        dd   03e18c1h
        dd   03e39b3h
        dd   03e5a94h
        dd   03e7b64h
        dd   03e9c22h
        dd   03ebccfh
        dd   03edd6ch
        dd   03efdf7h
        dd   03f1e72h
        dd   03f3edch
        dd   03f5f36h
        dd   03f7f7eh
        dd   03f9fb7h
        dd   03fbfdfh
        dd   03fdff7h
        dd   0400000h
        dd   0401ff8h
        dd   0403fe0h
        dd   0405fb8h
        dd   0407f80h
        dd   0409f39h
        dd   040bee3h
        dd   040de7dh
        dd   040fe07h
        dd   0411d83h
        dd   0413cefh
        dd   0415c4ch
        dd   0417b9ah
        dd   0419ad9h
        dd   041ba09h
        dd   041d92ah
        dd   041f83dh
        dd   0421741h
        dd   0423637h
        dd   042551eh
        dd   04273f7h
        dd   04292c1h
        dd   042b17dh
        dd   042d02ch
        dd   042eecch
        dd   0430d5eh
        dd   0432be2h
        dd   0434a58h
        dd   04368c1h
        dd   043871ch
        dd   043a569h
        dd   043c3a8h
        dd   043e1dbh
        dd   0440000h
        dd   0441e17h
        dd   0443c21h
        dd   0445a1eh
        dd   044780eh
        dd   04495f1h
        dd   044b3c7h
        dd   044d18fh
        dd   044ef4bh
        dd   0450cfbh
        dd   0452a9dh
        dd   0454833h
        dd   04565bch
        dd   0458339h
        dd   045a0a9h
        dd   045be0ch
        dd   045db64h
        dd   045f8afh
        dd   04615edh
        dd   0463320h
        dd   0465046h
        dd   0466d61h
        dd   0468a6fh
        dd   046a772h
        dd   046c468h
        dd   046e153h
        dd   046fe32h
        dd   0471b05h
        dd   04737cdh
        dd   0475489h
        dd   0477139h
        dd   0478ddeh
        dd   047aa77h
        dd   047c705h
        dd   047e388h
        dd   0480000h
        dd   0481c6ch
        dd   04838cdh
        dd   0485522h
        dd   048716dh
        dd   0488dadh
        dd   048a9e2h
        dd   048c60ch
        dd   048e22bh
        dd   048fe3fh
        dd   0491a48h
        dd   0493646h
        dd   049523ah
        dd   0496e24h
        dd   0498a02h
        dd   049a5d6h
        dd   049c1a0h
        dd   049dd5fh
        dd   049f914h
        dd   04a14beh
        dd   04a305eh
        dd   04a4bf4h
        dd   04a6780h
        dd   04a8301h
        dd   04a9e78h
        dd   04ab9e6h
        dd   04ad549h
        dd   04af0a2h
        dd   04b0bf1h
        dd   04b2736h
        dd   04b4271h
        dd   04b5da3h
        dd   04b78cbh
        dd   04b93e9h
        dd   04baefdh
        dd   04bca07h
        dd   04be508h
        dd   04c0000h
        dd   04c1aedh
        dd   04c35d1h
        dd   04c50ach
        dd   04c6b7eh
        dd   04c8646h
        dd   04ca104h
        dd   04cbbb9h
        dd   04cd665h
        dd   04cf108h
        dd   04d0ba2h
        dd   04d2632h
        dd   04d40b9h
        dd   04d5b37h
        dd   04d75ach
        dd   04d9018h
        dd   04daa7bh
        dd   04dc4d5h
        dd   04ddf27h
        dd   04df96fh
        dd   04e13aeh
        dd   04e2de5h
        dd   04e4813h
        dd   04e6238h
        dd   04e7c54h
        dd   04e9668h
        dd   04eb073h
        dd   04eca75h
        dd   04ee46fh
        dd   04efe61h
        dd   04f184ah
        dd   04f322ah
        dd   04f4c02h
        dd   04f65d1h
        dd   04f7f98h
        dd   04f9957h
        dd   04fb30eh
        dd   04fccbch
        dd   04fe662h
        dd   0500000h
        dd   0501995h
        dd   0503322h
        dd   0504ca8h
        dd   0506625h
        dd   0507f9ah
        dd   0509907h
        dd   050b26ch
        dd   050cbc9h
        dd   050e51eh
        dd   050fe6bh
        dd   05117b0h
        dd   05130eeh
        dd   0514a23h
        dd   0516351h
        dd   0517c77h
        dd   0519595h
        dd   051aeabh
        dd   051c7bah
        dd   051e0c1h
        dd   051f9c1h
        dd   05212b9h
        dd   0522ba9h
        dd   0524492h
        dd   0525d73h
        dd   052764dh
        dd   0528f1fh
        dd   052a7e9h
        dd   052c0adh
        dd   052d969h
        dd   052f21dh
        dd   0530acah
        dd   0532370h
        dd   0533c0fh
        dd   05354a6h
        dd   0536d36h
        dd   05385bfh
        dd   0539e41h
        dd   053b6bbh
        dd   053cf2eh
        dd   053e79ah
        dd   0540000h
        dd   054185dh
        dd   05430b4h
        dd   0544904h
        dd   054614dh
        dd   054798fh
        dd   05491cah
        dd   054a9feh
        dd   054c22bh
        dd   054da52h
        dd   054f271h
        dd   0550a89h
        dd   055229bh
        dd   0553aa6h
        dd   05552aah
        dd   0556aa8h
        dd   055829eh
        dd   0559a8eh
        dd   055b277h
        dd   055ca5ah
        dd   055e236h
        dd   055fa0bh
        dd   05611dah
        dd   05629a2h
        dd   0564164h
        dd   056591fh
        dd   05670d3h
        dd   0568881h
        dd   056a029h
        dd   056b7cah
        dd   056cf65h
        dd   056e6f9h
        dd   056fe87h
        dd   057160eh
        dd   0572d90h
        dd   057450ah
        dd   0575c7fh
        dd   05773edh
        dd   0578b55h
        dd   057a2b7h
        dd   057ba12h
        dd   057d168h
        dd   057e8b7h
        dd   0580000h
        dd   0581742h
        dd   0582e7fh
        dd   05845b5h
        dd   0585ce6h
        dd   0587410h
        dd   0588b34h
        dd   058a253h
        dd   058b96bh
        dd   058d07dh
        dd   058e789h
        dd   058fe8fh
        dd   0591590h
        dd   0592c8ah
        dd   059437eh
        dd   0595a6dh
        dd   0597156h
        dd   0598838h
        dd   0599f15h
        dd   059b5ech
        dd   059ccbeh
        dd   059e389h
        dd   059fa4fh
        dd   05a110fh
        dd   05a27c9h
        dd   05a3e7eh
        dd   05a552dh
        dd   05a6bd6h
        dd   05a8279h
        dd   05a9917h
        dd   05aafafh
        dd   05ac642h
        dd   05adcceh
        dd   05af356h
        dd   05b09d8h
        dd   05b2054h
        dd   05b36cah
        dd   05b4d3ch
        dd   05b63a7h
        dd   05b7a0dh
        dd   05b906eh
        dd   05ba6c9h
        dd   05bbd1fh
        dd   05bd36fh
        dd   05be9bah
        dd   05c0000h
        dd   05c1640h
        dd   05c2c7ah
        dd   05c42b0h
        dd   05c58e0h
        dd   05c6f0ah
        dd   05c8530h
        dd   05c9b50h
        dd   05cb16bh
        dd   05cc780h
        dd   05cdd91h
        dd   05cf39ch
        dd   05d09a1h
        dd   05d1fa2h
        dd   05d359dh
        dd   05d4b94h
        dd   05d6185h
        dd   05d7771h
        dd   05d8d58h
        dd   05da339h
        dd   05db916h
        dd   05dceedh
        dd   05de4c0h
        dd   05dfa8dh
        dd   05e1055h
        dd   05e2618h
        dd   05e3bd7h
        dd   05e5190h
        dd   05e6744h
        dd   05e7cf3h
        dd   05e929dh
        dd   05ea843h
        dd   05ebde3h
        dd   05ed37fh
        dd   05ee915h
        dd   05efea7h
        dd   05f1433h
        dd   05f29bbh
        dd   05f3f3eh
        dd   05f54bch
        dd   05f6a35h
        dd   05f7faah
        dd   05f9519h
        dd   05faa84h
        dd   05fbfeah
        dd   05fd54bh
        dd   05feaa8h
        dd   0600000h
        dd   0601552h
        dd   0602aa1h
        dd   0603feah
        dd   060552fh
        dd   0606a6fh
        dd   0607fabh
        dd   06094e1h
        dd   060aa14h
        dd   060bf41h
        dd   060d46ah
        dd   060e98eh
        dd   060feaeh
        dd   06113c9h
        dd   06128dfh
        dd   0613df1h
        dd   06152feh
        dd   0616807h
        dd   0617d0bh
        dd   061920bh
        dd   061a706h
        dd   061bbfdh
        dd   061d0efh
        dd   061e5ddh
        dd   061fac6h
        dd   0620fabh
        dd   062248bh
        dd   0623967h
        dd   0624e3eh
        dd   0626311h
        dd   06277e0h
        dd   0628caah
        dd   062a170h
        dd   062b632h
        dd   062caefh
        dd   062dfa7h
        dd   062f45ch
        dd   063090ch
        dd   0631db8h
        dd   063325fh
        dd   0634702h
        dd   0635ba1h
        dd   063703ch
        dd   06384d2h
        dd   0639964h
        dd   063adf2h
        dd   063c27ch
        dd   063d701h
        dd   063eb83h
        dd   0640000h
        dd   0641478h
        dd   06428edh
        dd   0643d5dh
        dd   06451cah
        dd   0646632h
        dd   0647a96h
        dd   0648ef5h
        dd   064a351h
        dd   064b7a9h
        dd   064cbfch
        dd   064e04ch
        dd   064f497h
        dd   06508deh
        dd   0651d21h
        dd   0653160h
        dd   065459bh
        dd   06559d2h
        dd   0656e05h
        dd   0658234h
        dd   065965fh
        dd   065aa86h
        dd   065bea9h
        dd   065d2c8h
        dd   065e6e3h
        dd   065fafah
        dd   0660f0dh
        dd   066231dh
        dd   0663728h
        dd   0664b2fh
        dd   0665f32h
        dd   0667332h
        dd   066872dh
        dd   0669b25h
        dd   066af19h
        dd   066c309h
        dd   066d6f5h
        dd   066eaddh
        dd   066fec1h
        dd   06712a2h
        dd   067267fh
        dd   0673a57h
        dd   0674e2ch
        dd   06761feh
        dd   06775cbh
        dd   0678995h
        dd   0679d5bh
        dd   067b11dh
        dd   067c4dbh
        dd   067d896h
        dd   067ec4ch
        dd   0680000h
        dd   06813afh
        dd   068275bh
        dd   0683b02h
        dd   0684ea7h
        dd   0686247h
        dd   06875e4h
        dd   068897dh
        dd   0689d13h
        dd   068b0a5h
        dd   068c433h
        dd   068d7bdh
        dd   068eb44h
        dd   068fec7h
        dd   0691247h
        dd   06925c3h
        dd   069393bh
        dd   0694cb0h
        dd   0696022h
        dd   069738fh
        dd   06986f9h
        dd   0699a60h
        dd   069adc3h
        dd   069c122h
        dd   069d47eh
        dd   069e7d6h
        dd   069fb2bh
        dd   06a0e7ch
        dd   06a21cah
        dd   06a3514h
        dd   06a485bh
        dd   06a5b9eh
        dd   06a6edeh
        dd   06a821ah
        dd   06a9553h
        dd   06aa888h
        dd   06abbbah
        dd   06acee8h
        dd   06ae213h
        dd   06af53bh
        dd   06b085fh
        dd   06b1b80h
        dd   06b2e9dh
        dd   06b41b7h
        dd   06b54cdh
        dd   06b67e0h
        dd   06b7af0h
        dd   06b8dfch
        dd   06ba105h
        dd   06bb40bh
        dd   06bc70dh
        dd   06bda0ch
        dd   06bed07h
        dd   06c0000h
        dd   06c12f4h
        dd   06c25e6h
        dd   06c38d4h
        dd   06c4bbfh
        dd   06c5ea7h
        dd   06c718bh
        dd   06c846ch
        dd   06c974ah
        dd   06caa24h
        dd   06cbcfbh
        dd   06ccfcfh
        dd   06ce2a0h
        dd   06cf56dh
        dd   06d0838h
        dd   06d1affh
        dd   06d2dc2h
        dd   06d4083h
        dd   06d5340h
        dd   06d65fah
        dd   06d78b1h
        dd   06d8b65h
        dd   06d9e15h
        dd   06db0c2h
        dd   06dc36ch
        dd   06dd613h
        dd   06de8b7h
        dd   06dfb58h
        dd   06e0df5h
        dd   06e2090h
        dd   06e3327h
        dd   06e45bbh
        dd   06e584ch
        dd   06e6adah
        dd   06e7d64h
        dd   06e8fech
        dd   06ea270h
        dd   06eb4f2h
        dd   06ec770h
        dd   06ed9ebh
        dd   06eec63h
        dd   06efed8h
        dd   06f114ah
        dd   06f23b9h
        dd   06f3625h
        dd   06f488eh
        dd   06f5af4h
        dd   06f6d56h
        dd   06f7fb6h
        dd   06f9213h
        dd   06fa46ch
        dd   06fb6c3h
        dd   06fc917h
        dd   06fdb67h
        dd   06fedb5h
        dd   0700000h
        dd   0701247h
        dd   070248ch
        dd   07036ceh
        dd   070490ch
        dd   0705b48h
        dd   0706d81h
        dd   0707fb7h
        dd   07091eah
        dd   070a41ah
        dd   070b647h
        dd   070c871h
        dd   070da98h
        dd   070ecbch
        dd   070fedeh
        dd   07110fch
        dd   0712318h
        dd   0713530h
        dd   0714746h
        dd   0715959h
        dd   0716b69h
        dd   0717d76h
        dd   0718f80h
        dd   071a188h
        dd   071b38ch
        dd   071c58eh
        dd   071d78dh
        dd   071e989h
        dd   071fb82h
        dd   0720d78h
        dd   0721f6bh
        dd   072315ch
        dd   072434ah
        dd   0725535h
        dd   072671dh
        dd   0727903h
        dd   0728ae5h
        dd   0729cc5h
        dd   072aea2h
        dd   072c07ch
        dd   072d254h
        dd   072e429h
        dd   072f5fbh
        dd   07307cah
        dd   0731996h
        dd   0732b60h
        dd   0733d27h
        dd   0734eebh
        dd   07360adh
        dd   073726bh
        dd   0738427h
        dd   07395e1h
        dd   073a797h
        dd   073b94bh
        dd   073cafch
        dd   073dcabh
        dd   073ee56h
        dd   0740000h
        dd   07411a6h
        dd   074234ah
        dd   07434ebh
        dd   0744689h
        dd   0745825h
        dd   07469beh
        dd   0747b54h
        dd   0748ce8h
        dd   0749e79h
        dd   074b007h
        dd   074c193h
        dd   074d31ch
        dd   074e4a3h
        dd   074f626h
        dd   07507a8h
        dd   0751926h
        dd   0752aa2h
        dd   0753c1ch
        dd   0754d93h
        dd   0755f07h
        dd   0757078h
        dd   07581e8h
        dd   0759354h
        dd   075a4beh
        dd   075b625h
        dd   075c78ah
        dd   075d8ech
        dd   075ea4ch
        dd   075fba9h
        dd   0760d03h
        dd   0761e5bh
        dd   0762fb0h
        dd   0764103h
        dd   0765254h
        dd   07663a1h
        dd   07674edh
        dd   0768635h
        dd   076977ch
        dd   076a8bfh
        dd   076ba00h
        dd   076cb3fh
        dd   076dc7bh
        dd   076edb5h
        dd   076feech
        dd   0771021h
        dd   0772153h
        dd   0773283h
        dd   07743b0h
        dd   07754dbh
        dd   0776603h
        dd   0777729h
        dd   077884ch
        dd   077996dh
        dd   077aa8ch
        dd   077bba8h
        dd   077ccc1h
        dd   077ddd9h
        dd   077eeedh
        dd   0780000h
        dd   078110fh
        dd   078221dh
        dd   0783328h
        dd   0784430h
        dd   0785537h
        dd   078663ah
        dd   078773ch
        dd   078883bh
        dd   0789937h
        dd   078aa31h
        dd   078bb29h
        dd   078cc1fh
        dd   078dd12h
        dd   078ee02h
        dd   078fef1h
        dd   0790fddh
        dd   07920c6h
        dd   07931adh
        dd   0794292h
        dd   0795375h
        dd   0796455h
        dd   0797533h
        dd   079860eh
        dd   07996e7h
        dd   079a7beh
        dd   079b892h
        dd   079c965h
        dd   079da34h
        dd   079eb02h
        dd   079fbcdh
        dd   07a0c96h
        dd   07a1d5ch
        dd   07a2e21h
        dd   07a3ee3h
        dd   07a4fa2h
        dd   07a6060h
        dd   07a711bh
        dd   07a81d4h
        dd   07a928ah
        dd   07aa33eh
        dd   07ab3f0h
        dd   07ac4a0h
        dd   07ad54dh
        dd   07ae5f9h
        dd   07af6a1h
        dd   07b0748h
        dd   07b17edh
        dd   07b288fh
        dd   07b392fh
        dd   07b49cch
        dd   07b5a68h
        dd   07b6b01h
        dd   07b7b98h
        dd   07b8c2dh
        dd   07b9cbfh
        dd   07bad4fh
        dd   07bbdddh
        dd   07bce69h
        dd   07bdef3h
        dd   07bef7ah
        dd   07c0000h
        dd   07c1083h
        dd   07c2103h
        dd   07c3182h
        dd   07c41feh
        dd   07c5279h
        dd   07c62f1h
        dd   07c7367h
        dd   07c83dah
        dd   07c944ch
        dd   07ca4bbh
        dd   07cb529h
        dd   07cc594h
        dd   07cd5fdh
        dd   07ce663h
        dd   07cf6c8h
        dd   07d072ah
        dd   07d178bh
        dd   07d27e9h
        dd   07d3845h
        dd   07d489fh
        dd   07d58f6h
        dd   07d694ch
        dd   07d799fh
        dd   07d89f1h
        dd   07d9a40h
        dd   07daa8dh
        dd   07dbad8h
        dd   07dcb21h
        dd   07ddb68h
        dd   07debadh
        dd   07dfbefh
        dd   07e0c30h
        dd   07e1c6eh
        dd   07e2caah
        dd   07e3ce5h
        dd   07e4d1dh
        dd   07e5d53h
        dd   07e6d87h
        dd   07e7db9h
        dd   07e8de8h
        dd   07e9e16h
        dd   07eae42h
        dd   07ebe6ch
        dd   07ece93h
        dd   07edeb9h
        dd   07eeedch
        dd   07efefdh
        dd   07f0f1dh
        dd   07f1f3ah
        dd   07f2f55h
        dd   07f3f6fh
        dd   07f4f86h
        dd   07f5f9bh
        dd   07f6faeh
        dd   07f7fbfh
        dd   07f8fceh
        dd   07f9fdbh
        dd   07fafe6h
        dd   07fbfefh
        dd   07fcff6h
        dd   07fdffbh
        dd   07feffeh
        dd   0800000h
        dd   0800fffh
        dd   0801ffch
        dd   0802ff7h
        dd   0803ff0h
        dd   0804fe7h
        dd   0805fdch
        dd   0806fcfh
        dd   0807fc0h
        dd   0808fafh
        dd   0809f9ch
        dd   080af87h
        dd   080bf70h
        dd   080cf58h
        dd   080df3dh
        dd   080ef20h
        dd   080ff01h
        dd   0810ee1h
        dd   0811ebeh
        dd   0812e9ah
        dd   0813e73h
        dd   0814e4bh
        dd   0815e21h
        dd   0816df4h
        dd   0817dc6h
        dd   0818d96h
        dd   0819d64h
        dd   081ad30h
        dd   081bcfah
        dd   081ccc2h
        dd   081dc88h
        dd   081ec4dh
        dd   081fc0fh
        dd   0820bd0h
        dd   0821b8eh
        dd   0822b4bh
        dd   0823b06h
        dd   0824abfh
        dd   0825a76h
        dd   0826a2bh
        dd   08279deh
        dd   082898fh
        dd   082993fh
        dd   082a8ech
        dd   082b898h
        dd   082c842h
        dd   082d7eah
        dd   082e790h
        dd   082f734h
        dd   08306d6h
        dd   0831677h
        dd   0832615h
        dd   08335b2h
        dd   083454dh
        dd   08354e6h
        dd   083647dh
        dd   0837412h
        dd   08383a6h
        dd   0839338h
        dd   083a2c7h
        dd   083b255h
        dd   083c1e1h
        dd   083d16ch
        dd   083e0f4h
        dd   083f07bh
        dd   0840000h
        dd   0840f82h
        dd   0841f04h
        dd   0842e83h
        dd   0843e00h
        dd   0844d7ch
        dd   0845cf6h
        dd   0846c6eh
        dd   0847be4h
        dd   0848b59h
        dd   0849acch
        dd   084aa3ch
        dd   084b9abh
        dd   084c919h
        dd   084d884h
        dd   084e7eeh
        dd   084f756h
        dd   08506bch
        dd   0851620h
        dd   0852583h
        dd   08534e4h
        dd   0854443h
        dd   08553a0h
        dd   08562fbh
        dd   0857255h
        dd   08581adh
        dd   0859103h
        dd   085a058h
        dd   085afaah
        dd   085befbh
        dd   085ce4ah
        dd   085dd98h
        dd   085ece3h
        dd   085fc2dh
        dd   0860b75h
        dd   0861abch
        dd   0862a01h
        dd   0863944h
        dd   0864885h
        dd   08657c4h
        dd   0866702h
        dd   086763eh
        dd   0868578h
        dd   08694b1h
        dd   086a3e8h
        dd   086b31dh
        dd   086c250h
        dd   086d182h
        dd   086e0b2h
        dd   086efe0h
        dd   086ff0dh
        dd   0870e38h
        dd   0871d61h
        dd   0872c88h
        dd   0873baeh
        dd   0874ad2h
        dd   08759f4h
        dd   0876915h
        dd   0877834h
        dd   0878751h
        dd   087966dh
        dd   087a587h
        dd   087b49fh
        dd   087c3b6h
        dd   087d2cbh
        dd   087e1deh
        dd   087f0f0h
        dd   0880000h
        dd   0880f0eh
        dd   0881e1ah
        dd   0882d25h
        dd   0883c2eh
        dd   0884b36h
        dd   0885a3ch
        dd   0886940h
        dd   0887843h
        dd   0888744h
        dd   0889643h
        dd   088a541h
        dd   088b43dh
        dd   088c337h
        dd   088d230h
        dd   088e127h
        dd   088f01ch
        dd   088ff10h
        dd   0890e03h
        dd   0891cf3h
        dd   0892be2h
        dd   0893acfh
        dd   08949bbh
        dd   08958a5h
        dd   089678eh
        dd   0897674h
        dd   089855ah
        dd   089943dh
        dd   089a31fh
        dd   089b200h
        dd   089c0dfh
        dd   089cfbch
        dd   089de97h
        dd   089ed71h
        dd   089fc4ah
        dd   08a0b20h
        dd   08a19f6h
        dd   08a28c9h
        dd   08a379bh
        dd   08a466ch
        dd   08a553bh
        dd   08a6408h
        dd   08a72d3h
        dd   08a819eh
        dd   08a9066h
        dd   08a9f2dh
        dd   08aadf2h
        dd   08abcb6h
        dd   08acb78h
        dd   08ada39h
        dd   08ae8f8h
        dd   08af7b6h
        dd   08b0672h
        dd   08b152ch
        dd   08b23e5h
        dd   08b329ch
        dd   08b4152h
        dd   08b5006h
        dd   08b5eb9h
        dd   08b6d6ah
        dd   08b7c19h
        dd   08b8ac7h
        dd   08b9974h
        dd   08ba81eh
        dd   08bb6c8h
        dd   08bc570h
        dd   08bd416h
        dd   08be2bbh
        dd   08bf15eh
        dd   08c0000h
        dd   08c0ea0h
        dd   08c1d3eh
        dd   08c2bdbh
        dd   08c3a77h
        dd   08c4911h
        dd   08c57aah
        dd   08c6641h
        dd   08c74d6h
        dd   08c836ah
        dd   08c91fdh
        dd   08ca08dh
        dd   08caf1dh
        dd   08cbdabh
        dd   08ccc37h
        dd   08cdac2h
        dd   08ce94ch
        dd   08cf7d4h
        dd   08d065ah
        dd   08d14dfh
        dd   08d2363h
        dd   08d31e5h
        dd   08d4065h
        dd   08d4ee4h
        dd   08d5d61h
        dd   08d6bdeh
        dd   08d7a58h
        dd   08d88d1h
        dd   08d9749h
        dd   08da5bfh
        dd   08db433h
        dd   08dc2a7h
        dd   08dd118h
        dd   08ddf88h
        dd   08dedf7h
        dd   08dfc64h
        dd   08e0ad0h
        dd   08e193bh
        dd   08e27a3h
        dd   08e360bh
        dd   08e4471h
        dd   08e52d5h
        dd   08e6138h
        dd   08e6f9ah
        dd   08e7dfah
        dd   08e8c59h
        dd   08e9ab6h
        dd   08ea912h
        dd   08eb76ch
        dd   08ec5c5h
        dd   08ed41dh
        dd   08ee273h
        dd   08ef0c7h
        dd   08eff1ah
        dd   08f0d6ch
        dd   08f1bbch
        dd   08f2a0bh
        dd   08f3859h
        dd   08f46a5h
        dd   08f54efh
        dd   08f6338h
        dd   08f7180h
        dd   08f7fc6h
        dd   08f8e0bh
        dd   08f9c4fh
        dd   08faa91h
        dd   08fb8d1h
        dd   08fc711h
        dd   08fd54fh
        dd   08fe38bh
        dd   08ff1c6h
        dd   0900000h
        dd   0900e38h
        dd   0901c6eh
        dd   0902aa4h
        dd   09038d8h
        dd   090470ah
        dd   090553ch
        dd   090636bh
        dd   090719ah
        dd   0907fc7h
        dd   0908df2h
        dd   0909c1dh
        dd   090aa45h
        dd   090b86dh
        dd   090c693h
        dd   090d4b8h
        dd   090e2dbh
        dd   090f0fdh
        dd   090ff1eh
        dd   0910d3dh
        dd   0911b5ah
        dd   0912977h
        dd   0913792h
        dd   09145ach
        dd   09153c4h
        dd   09161dbh
        dd   0916ff1h
        dd   0917e05h
        dd   0918c18h
        dd   0919a29h
        dd   091a839h
        dd   091b648h
        dd   091c456h
        dd   091d262h
        dd   091e06ch
        dd   091ee76h
        dd   091fc7eh
        dd   0920a84h
        dd   092188ah
        dd   092268eh
        dd   0923490h
        dd   0924292h
        dd   0925092h
        dd   0925e90h
        dd   0926c8dh
        dd   0927a89h
        dd   0928884h
        dd   092967dh
        dd   092a475h
        dd   092b26ch
        dd   092c061h
        dd   092ce55h
        dd   092dc48h
        dd   092ea39h
        dd   092f829h
        dd   0930618h
        dd   0931405h
        dd   09321f1h
        dd   0932fdch
        dd   0933dc5h
        dd   0934badh
        dd   0935994h
        dd   093677ah
        dd   093755eh
        dd   0938341h
        dd   0939122h
        dd   0939f02h
        dd   093ace1h
        dd   093babfh
        dd   093c89bh
        dd   093d676h
        dd   093e450h
        dd   093f228h
        dd   0940000h
        dd   0940dd5h
        dd   0941baah
        dd   094297dh
        dd   094374fh
        dd   0944520h
        dd   09452efh
        dd   09460bdh
        dd   0946e8ah
        dd   0947c56h
        dd   0948a20h
        dd   09497e9h
        dd   094a5b1h
        dd   094b377h
        dd   094c13ch
        dd   094cf00h
        dd   094dcc3h
        dd   094ea84h
        dd   094f844h
        dd   0950603h
        dd   09513c0h
        dd   095217dh
        dd   0952f38h
        dd   0953cf1h
        dd   0954aaah
        dd   0955861h
        dd   0956617h
        dd   09573cch
        dd   095817fh
        dd   0958f31h
        dd   0959ce2h
        dd   095aa92h
        dd   095b840h
        dd   095c5edh
        dd   095d399h
        dd   095e144h
        dd   095eeedh
        dd   095fc96h
        dd   0960a3dh
        dd   09617e2h
        dd   0962587h
        dd   096332ah
        dd   09640cch
        dd   0964e6dh
        dd   0965c0ch
        dd   09669aah
        dd   0967748h
        dd   09684e3h
        dd   096927eh
        dd   096a017h
        dd   096adafh
        dd   096bb46h
        dd   096c8dch
        dd   096d670h
        dd   096e404h
        dd   096f196h
        dd   096ff26h
        dd   0970cb6h
        dd   0971a44h
        dd   09727d2h
        dd   097355dh
        dd   09742e8h
        dd   0975072h
        dd   0975dfah
        dd   0976b81h
        dd   0977907h
        dd   097868ch
        dd   097940fh
        dd   097a191h
        dd   097af12h
        dd   097bc92h
        dd   097ca11h
        dd   097d78eh
        dd   097e50bh
        dd   097f286h
        dd   0980000h
        dd   0980d78h
        dd   0981af0h
        dd   0982866h
        dd   09835dbh
        dd   098434fh
        dd   09850c2h
        dd   0985e33h
        dd   0986ba3h
        dd   0987913h
        dd   0988681h
        dd   09893edh
        dd   098a159h
        dd   098aec3h
        dd   098bc2dh
        dd   098c995h
        dd   098d6fch
        dd   098e461h
        dd   098f1c6h
        dd   098ff29h
        dd   0990c8ch
        dd   09919edh
        dd   099274ch
        dd   09934abh
        dd   0994209h
        dd   0994f65h
        dd   0995cc0h
        dd   0996a1ah
        dd   0997773h
        dd   09984cbh
        dd   0999221h
        dd   0999f77h
        dd   099accbh
        dd   099ba1eh
        dd   099c770h
        dd   099d4c1h
        dd   099e211h
        dd   099ef5fh
        dd   099fcach
        dd   09a09f9h
        dd   09a1744h
        dd   09a248dh
        dd   09a31d6h
        dd   09a3f1eh
        dd   09a4c64h
        dd   09a59aah
        dd   09a66eeh
        dd   09a7431h
        dd   09a8173h
        dd   09a8eb3h
        dd   09a9bf3h
        dd   09aa932h
        dd   09ab66fh
        dd   09ac3abh
        dd   09ad0e6h
        dd   09ade20h
        dd   09aeb59h
        dd   09af891h
        dd   09b05c7h
        dd   09b12fdh
        dd   09b2031h
        dd   09b2d64h
        dd   09b3a96h
        dd   09b47c7h
        dd   09b54f7h
        dd   09b6226h
        dd   09b6f53h
        dd   09b7c80h
        dd   09b89abh
        dd   09b96d5h
        dd   09ba3ffh
        dd   09bb127h
        dd   09bbe4eh
        dd   09bcb73h
        dd   09bd898h
        dd   09be5bch
        dd   09bf2deh
        dd   09c0000h
        dd   09c0d20h
        dd   09c1a3fh
        dd   09c275dh
        dd   09c347ah
        dd   09c4196h
        dd   09c4eb1h
        dd   09c5bcah
        dd   09c68e3h
        dd   09c75fah
        dd   09c8311h
        dd   09c9026h
        dd   09c9d3ah
        dd   09caa4dh
        dd   09cb75fh
        dd   09cc470h
        dd   09cd180h
        dd   09cde8fh
        dd   09ceb9ch
        dd   09cf8a9h
        dd   09d05b4h
        dd   09d12bfh
        dd   09d1fc8h
        dd   09d2cd0h
        dd   09d39d7h
        dd   09d46deh
        dd   09d53e3h
        dd   09d60e6h
        dd   09d6de9h
        dd   09d7aebh
        dd   09d87ech
        dd   09d94ebh
        dd   09da1eah
        dd   09daee7h
        dd   09dbbe4h
        dd   09dc8dfh
        dd   09dd5d9h
        dd   09de2d3h
        dd   09defcbh
        dd   09dfcc2h
        dd   09e09b8h
        dd   09e16adh
        dd   09e23a1h
        dd   09e3094h
        dd   09e3d85h
        dd   09e4a76h
        dd   09e5766h
        dd   09e6454h
        dd   09e7142h
        dd   09e7e2eh
        dd   09e8b1ah
        dd   09e9804h
        dd   09ea4edh
        dd   09eb1d6h
        dd   09ebebdh
        dd   09ecba3h
        dd   09ed888h
        dd   09ee56ch
        dd   09ef24fh
        dd   09eff31h
        dd   09f0c12h
        dd   09f18f2h
        dd   09f25d1h
        dd   09f32afh
        dd   09f3f8ch
        dd   09f4c68h
        dd   09f5942h
        dd   09f661ch
        dd   09f72f5h
        dd   09f7fcch
        dd   09f8ca3h
        dd   09f9978h
        dd   09fa64dh
        dd   09fb320h
        dd   09fbff3h
        dd   09fccc4h
        dd   09fd994h
        dd   09fe664h
        dd   09ff332h
        dd   0a00000h
        dd   0a00ccch
        dd   0a01997h
        dd   0a02661h
        dd   0a0332bh
        dd   0a03ff3h
        dd   0a04cbah
        dd   0a05980h
        dd   0a06645h
        dd   0a07309h
        dd   0a07fcch
        dd   0a08c8fh
        dd   0a09950h
        dd   0a0a610h
        dd   0a0b2cfh
        dd   0a0bf8dh
        dd   0a0cc4ah
        dd   0a0d906h
        dd   0a0e5c1h
        dd   0a0f27bh
        dd   0a0ff34h
        dd   0a10bech
        dd   0a118a3h
        dd   0a12559h
        dd   0a1320eh
        dd   0a13ec2h
        dd   0a14b75h
        dd   0a15827h
        dd   0a164d8h
        dd   0a17188h
        dd   0a17e37h
        dd   0a18ae5h
        dd   0a19792h
        dd   0a1a43eh
        dd   0a1b0e9h
        dd   0a1bd93h
        dd   0a1ca3ch
        dd   0a1d6e4h
        dd   0a1e38bh
        dd   0a1f031h
        dd   0a1fcd6h
        dd   0a2097ah
        dd   0a2161eh
        dd   0a222c0h
        dd   0a22f61h
        dd   0a23c01h
        dd   0a248a0h
        dd   0a2553eh
        dd   0a261dch
        dd   0a26e78h
        dd   0a27b13h
        dd   0a287adh
        dd   0a29447h
        dd   0a2a0dfh
        dd   0a2ad76h
        dd   0a2ba0dh
        dd   0a2c6a2h
        dd   0a2d337h
        dd   0a2dfcah
        dd   0a2ec5dh
        dd   0a2f8eeh
        dd   0a3057fh
        dd   0a3120eh
        dd   0a31e9dh
        dd   0a32b2ah
        dd   0a337b7h
        dd   0a34443h
        dd   0a350ceh
        dd   0a35d57h
        dd   0a369e0h
        dd   0a37668h
        dd   0a382efh
        dd   0a38f75h
        dd   0a39bfah
        dd   0a3a87eh
        dd   0a3b501h
        dd   0a3c183h
        dd   0a3ce04h
        dd   0a3da85h
        dd   0a3e704h
        dd   0a3f382h
        dd   0a40000h
        dd   0a40c7ch
        dd   0a418f7h
        dd   0a42572h
        dd   0a431ebh
        dd   0a43e64h
        dd   0a44adch
        dd   0a45752h
        dd   0a463c8h
        dd   0a4703dh
        dd   0a47cb1h
        dd   0a48924h
        dd   0a49596h
        dd   0a4a207h
        dd   0a4ae77h
        dd   0a4bae6h
        dd   0a4c754h
        dd   0a4d3c2h
        dd   0a4e02eh
        dd   0a4ec9ah
        dd   0a4f904h
        dd   0a5056eh
        dd   0a511d6h
        dd   0a51e3eh
        dd   0a52aa5h
        dd   0a5370ah
        dd   0a5436fh
        dd   0a54fd3h
        dd   0a55c36h
        dd   0a56899h
        dd   0a574fah
        dd   0a5815ah
        dd   0a58db9h
        dd   0a59a18h
        dd   0a5a675h
        dd   0a5b2d2h
        dd   0a5bf2dh
        dd   0a5cb88h
        dd   0a5d7e2h
        dd   0a5e43bh
        dd   0a5f093h
        dd   0a5fceah
        dd   0a60940h
        dd   0a61595h
        dd   0a621eah
        dd   0a62e3dh
        dd   0a63a8fh
        dd   0a646e1h
        dd   0a65332h
        dd   0a65f81h
        dd   0a66bd0h
        dd   0a6781eh
        dd   0a6846bh
        dd   0a690b7h
        dd   0a69d02h
        dd   0a6a94dh
        dd   0a6b596h
        dd   0a6c1deh
        dd   0a6ce26h
        dd   0a6da6dh
        dd   0a6e6b2h
        dd   0a6f2f7h
        dd   0a6ff3bh
        dd   0a70b7eh
        dd   0a717c0h
        dd   0a72402h
        dd   0a73042h
        dd   0a73c82h
        dd   0a748c0h
        dd   0a754feh
        dd   0a7613bh
        dd   0a76d76h
        dd   0a779b1h
        dd   0a785ech
        dd   0a79225h
        dd   0a79e5dh
        dd   0a7aa94h
        dd   0a7b6cbh
        dd   0a7c301h
        dd   0a7cf35h
        dd   0a7db69h
        dd   0a7e79ch
        dd   0a7f3ceh
        dd   0a80000h
        dd   0a80c30h
        dd   0a8185fh
        dd   0a8248eh
        dd   0a830bbh
        dd   0a83ce8h
        dd   0a84914h
        dd   0a8553fh
        dd   0a86169h
        dd   0a86d93h
        dd   0a879bbh
        dd   0a885e3h
        dd   0a89209h
        dd   0a89e2fh
        dd   0a8aa54h
        dd   0a8b678h
        dd   0a8c29bh
        dd   0a8cebdh
        dd   0a8dadfh
        dd   0a8e6ffh
        dd   0a8f31fh
        dd   0a8ff3eh
        dd   0a90b5ch
        dd   0a91779h
        dd   0a92395h
        dd   0a92fb0h
        dd   0a93bcbh
        dd   0a947e4h
        dd   0a953fdh
        dd   0a96015h
        dd   0a96c2ch
        dd   0a97842h
        dd   0a98457h
        dd   0a9906bh
        dd   0a99c7fh
        dd   0a9a892h
        dd   0a9b4a4h
        dd   0a9c0b4h
        dd   0a9ccc5h
        dd   0a9d8d4h
        dd   0a9e4e2h
        dd   0a9f0f0h
        dd   0a9fcfch
        dd   0aa0908h
        dd   0aa1513h
        dd   0aa211dh
        dd   0aa2d27h
        dd   0aa392fh
        dd   0aa4537h
        dd   0aa513dh
        dd   0aa5d43h
        dd   0aa6948h
        dd   0aa754ch
        dd   0aa8150h
        dd   0aa8d52h
        dd   0aa9954h
        dd   0aaa555h
        dd   0aab155h
        dd   0aabd54h
        dd   0aac952h
        dd   0aad550h
        dd   0aae14ch
        dd   0aaed48h
        dd   0aaf943h
        dd   0ab053dh
        dd   0ab1136h
        dd   0ab1d2eh
        dd   0ab2926h
        dd   0ab351dh
        dd   0ab4113h
        dd   0ab4d08h
        dd   0ab58fch
        dd   0ab64efh
        dd   0ab70e2h
        dd   0ab7cd3h
        dd   0ab88c4h
        dd   0ab94b4h
        dd   0aba0a4h
        dd   0abac92h
        dd   0abb880h
        dd   0abc46ch
        dd   0abd058h
        dd   0abdc43h
        dd   0abe82dh
        dd   0abf417h
        dd   0ac0000h
        dd   0ac0be7h
        dd   0ac17ceh
        dd   0ac23b4h
        dd   0ac2f9ah
        dd   0ac3b7eh
        dd   0ac4762h
        dd   0ac5345h
        dd   0ac5f27h
        dd   0ac6b08h
        dd   0ac76e8h
        dd   0ac82c8h
        dd   0ac8ea7h
        dd   0ac9a85h
        dd   0aca662h
        dd   0acb23eh
        dd   0acbe19h
        dd   0acc9f4h
        dd   0acd5ceh
        dd   0ace1a7h
        dd   0aced7fh
        dd   0acf957h
        dd   0ad052dh
        dd   0ad1103h
        dd   0ad1cd8h
        dd   0ad28ach
        dd   0ad3480h
        dd   0ad4052h
        dd   0ad4c24h
        dd   0ad57f5h
        dd   0ad63c5h
        dd   0ad6f94h
        dd   0ad7b63h
        dd   0ad8731h
        dd   0ad92feh
        dd   0ad9ecah
        dd   0adaa95h
        dd   0adb660h
        dd   0adc229h
        dd   0adcdf2h
        dd   0add9bbh
        dd   0ade582h
        dd   0adf148h
        dd   0adfd0eh
        dd   0ae08d3h
        dd   0ae1497h
        dd   0ae205bh
        dd   0ae2c1dh
        dd   0ae37dfh
        dd   0ae43a0h
        dd   0ae4f60h
        dd   0ae5b20h
        dd   0ae66deh
        dd   0ae729ch
        dd   0ae7e59h
        dd   0ae8a15h
        dd   0ae95d1h
        dd   0aea18bh
        dd   0aead45h
        dd   0aeb8feh
        dd   0aec4b7h
        dd   0aed06eh
        dd   0aedc25h
        dd   0aee7dbh
        dd   0aef390h
        dd   0aeff44h
        dd   0af0af8h
        dd   0af16abh
        dd   0af225dh
        dd   0af2e0eh
        dd   0af39beh
        dd   0af456eh
        dd   0af511dh
        dd   0af5ccbh
        dd   0af6878h
        dd   0af7425h
        dd   0af7fd1h
        dd   0af8b7ch
        dd   0af9726h
        dd   0afa2d0h
        dd   0afae78h
        dd   0afba20h
        dd   0afc5c7h
        dd   0afd16eh
        dd   0afdd13h
        dd   0afe8b8h
        dd   0aff45ch
        dd   0b00000h
        dd   0b00ba2h
        dd   0b01744h
        dd   0b022e5h
        dd   0b02e85h
        dd   0b03a24h
        dd   0b045c3h
        dd   0b05161h
        dd   0b05cfeh
        dd   0b0689bh
        dd   0b07436h
        dd   0b07fd1h
        dd   0b08b6bh
        dd   0b09705h
        dd   0b0a29dh
        dd   0b0ae35h
        dd   0b0b9cch
        dd   0b0c562h
        dd   0b0d0f8h
        dd   0b0dc8dh
        dd   0b0e821h
        dd   0b0f3b4h
        dd   0b0ff46h
        dd   0b10ad8h
        dd   0b11669h
        dd   0b121f9h
        dd   0b12d89h
        dd   0b13918h
        dd   0b144a6h
        dd   0b15033h
        dd   0b15bbfh
        dd   0b1674bh
        dd   0b172d6h
        dd   0b17e60h
        dd   0b189eah
        dd   0b19572h
        dd   0b1a0fah
        dd   0b1ac81h
        dd   0b1b808h
        dd   0b1c38eh
        dd   0b1cf13h
        dd   0b1da97h
        dd   0b1e61ah
        dd   0b1f19dh
        dd   0b1fd1fh
        dd   0b208a0h
        dd   0b21421h
        dd   0b21fa1h
        dd   0b22b20h
        dd   0b2369eh
        dd   0b2421bh
        dd   0b24d98h
        dd   0b25914h
        dd   0b26490h
        dd   0b2700ah
        dd   0b27b84h
        dd   0b286fdh
        dd   0b29276h
        dd   0b29dedh
        dd   0b2a964h
        dd   0b2b4dah
        dd   0b2c050h
        dd   0b2cbc4h
        dd   0b2d738h
        dd   0b2e2ach
        dd   0b2ee1eh
        dd   0b2f990h
        dd   0b30501h
        dd   0b31071h
        dd   0b31be1h
        dd   0b32750h
        dd   0b332beh
        dd   0b33e2bh
        dd   0b34998h
        dd   0b35504h
        dd   0b3606fh
        dd   0b36bd9h
        dd   0b37743h
        dd   0b382ach
        dd   0b38e14h
        dd   0b3997ch
        dd   0b3a4e3h
        dd   0b3b049h
        dd   0b3bbaeh
        dd   0b3c713h
        dd   0b3d277h
        dd   0b3dddah
        dd   0b3e93dh
        dd   0b3f49eh
        dd   0b40000h
        dd   0b40b60h
        dd   0b416bfh
        dd   0b4221eh
        dd   0b42d7dh
        dd   0b438dah
        dd   0b44437h
        dd   0b44f93h
        dd   0b45aeeh
        dd   0b46649h
        dd   0b471a3h
        dd   0b47cfch
        dd   0b48854h
        dd   0b493ach
        dd   0b49f03h
        dd   0b4aa5ah
        dd   0b4b5afh
        dd   0b4c104h
        dd   0b4cc58h
        dd   0b4d7ach
        dd   0b4e2ffh
        dd   0b4ee51h
        dd   0b4f9a2h
        dd   0b504f3h
        dd   0b51043h
        dd   0b51b92h
        dd   0b526e0h
        dd   0b5322eh
        dd   0b53d7bh
        dd   0b548c8h
        dd   0b55414h
        dd   0b55f5fh
        dd   0b56aa9h
        dd   0b575f3h
        dd   0b5813bh
        dd   0b58c84h
        dd   0b597cbh
        dd   0b5a312h
        dd   0b5ae58h
        dd   0b5b99dh
        dd   0b5c4e2h
        dd   0b5d026h
        dd   0b5db6ah
        dd   0b5e6ach
        dd   0b5f1eeh
        dd   0b5fd2fh
        dd   0b60870h
        dd   0b613b0h
        dd   0b61eefh
        dd   0b62a2dh
        dd   0b6356bh
        dd   0b640a8h
        dd   0b64be4h
        dd   0b65720h
        dd   0b6625bh
        dd   0b66d95h
        dd   0b678cfh
        dd   0b68408h
        dd   0b68f40h
        dd   0b69a78h
        dd   0b6a5aeh
        dd   0b6b0e5h
        dd   0b6bc1ah
        dd   0b6c74fh
        dd   0b6d283h
        dd   0b6ddb6h
        dd   0b6e8e9h
        dd   0b6f41bh
        dd   0b6ff4ch
        dd   0b70a7dh
        dd   0b715adh
        dd   0b720dch
        dd   0b72c0bh
        dd   0b73739h
        dd   0b74266h
        dd   0b74d93h
        dd   0b758bfh
        dd   0b763eah
        dd   0b76f14h
        dd   0b77a3eh
        dd   0b78567h
        dd   0b79090h
        dd   0b79bb8h
        dd   0b7a6dfh
        dd   0b7b205h
        dd   0b7bd2bh
        dd   0b7c850h
        dd   0b7d375h
        dd   0b7de98h
        dd   0b7e9bbh
        dd   0b7f4deh
        dd   0b80000h
        dd   0b80b21h
        dd   0b81641h
        dd   0b82161h
        dd   0b82c80h
        dd   0b8379eh
        dd   0b842bch
        dd   0b84dd9h
        dd   0b858f5h
        dd   0b86411h
        dd   0b86f2ch
        dd   0b87a46h
        dd   0b88560h
        dd   0b89079h
        dd   0b89b91h
        dd   0b8a6a9h
        dd   0b8b1c0h
        dd   0b8bcd6h
        dd   0b8c7ech
        dd   0b8d301h
        dd   0b8de15h
        dd   0b8e929h
        dd   0b8f43ch
        dd   0b8ff4eh
        dd   0b90a60h
        dd   0b91571h
        dd   0b92081h
        dd   0b92b91h
        dd   0b936a0h
        dd   0b941afh
        dd   0b94cbch
        dd   0b957c9h
        dd   0b962d6h
        dd   0b96de2h
        dd   0b978edh
        dd   0b983f7h
        dd   0b98f01h
        dd   0b99a0ah
        dd   0b9a513h
        dd   0b9b01ah
        dd   0b9bb22h
        dd   0b9c628h
        dd   0b9d12eh
        dd   0b9dc33h
        dd   0b9e738h
        dd   0b9f23ch
        dd   0b9fd3fh
        dd   0ba0841h
        dd   0ba1343h
        dd   0ba1e45h
        dd   0ba2945h
        dd   0ba3445h
        dd   0ba3f45h
        dd   0ba4a43h
        dd   0ba5541h
        dd   0ba603fh
        dd   0ba6b3bh
        dd   0ba7638h
        dd   0ba8133h
        dd   0ba8c2eh
        dd   0ba9728h
        dd   0baa221h
        dd   0baad1ah
        dd   0bab813h
        dd   0bac30ah
        dd   0bace01h
        dd   0bad8f7h
        dd   0bae3edh
        dd   0baeee2h
        dd   0baf9d6h
        dd   0bb04cah
        dd   0bb0fbdh
        dd   0bb1ab0h
        dd   0bb25a1h
        dd   0bb3093h
        dd   0bb3b83h
        dd   0bb4673h
        dd   0bb5162h
        dd   0bb5c51h
        dd   0bb673fh
        dd   0bb722ch
        dd   0bb7d19h
        dd   0bb8805h
        dd   0bb92f0h
        dd   0bb9ddbh
        dd   0bba8c5h
        dd   0bbb3afh
        dd   0bbbe98h
        dd   0bbc980h
        dd   0bbd467h
        dd   0bbdf4eh
        dd   0bbea35h
        dd   0bbf51ah
        dd   0bc0000h
        dd   0bc0ae4h
        dd   0bc15c8h
        dd   0bc20abh
        dd   0bc2b8eh
        dd   0bc366fh
        dd   0bc4151h
        dd   0bc4c31h
        dd   0bc5711h
        dd   0bc61f1h
        dd   0bc6cd0h
        dd   0bc77aeh
        dd   0bc828bh
        dd   0bc8d68h
        dd   0bc9845h
        dd   0bca320h
        dd   0bcadfbh
        dd   0bcb8d6h
        dd   0bcc3afh
        dd   0bcce89h
        dd   0bcd961h
        dd   0bce439h
        dd   0bcef10h
        dd   0bcf9e7h
        dd   0bd04bdh
        dd   0bd0f92h
        dd   0bd1a67h
        dd   0bd253bh
        dd   0bd300fh
        dd   0bd3ae2h
        dd   0bd45b4h
        dd   0bd5086h
        dd   0bd5b57h
        dd   0bd6628h
        dd   0bd70f7h
        dd   0bd7bc7h
        dd   0bd8695h
        dd   0bd9163h
        dd   0bd9c31h
        dd   0bda6feh
        dd   0bdb1cah
        dd   0bdbc95h
        dd   0bdc760h
        dd   0bdd22ah
        dd   0bddcf4h
        dd   0bde7bdh
        dd   0bdf286h
        dd   0bdfd4eh
        dd   0be0815h
        dd   0be12dch
        dd   0be1da2h
        dd   0be2867h
        dd   0be332ch
        dd   0be3df0h
        dd   0be48b4h
        dd   0be5377h
        dd   0be5e39h
        dd   0be68fbh
        dd   0be73bch
        dd   0be7e7ch
        dd   0be893ch
        dd   0be93fch
        dd   0be9ebbh
        dd   0bea979h
        dd   0beb436h
        dd   0bebef3h
        dd   0bec9afh
        dd   0bed46bh
        dd   0bedf26h
        dd   0bee9e1h
        dd   0bef49bh
        dd   0beff54h
        dd   0bf0a0dh
        dd   0bf14c5h
        dd   0bf1f7ch
        dd   0bf2a33h
        dd   0bf34e9h
        dd   0bf3f9fh
        dd   0bf4a54h
        dd   0bf5509h
        dd   0bf5fbdh
        dd   0bf6a70h
        dd   0bf7523h
        dd   0bf7fd5h
        dd   0bf8a86h
        dd   0bf9537h
        dd   0bf9fe7h
        dd   0bfaa97h
        dd   0bfb546h
        dd   0bfbff5h
        dd   0bfcaa3h
        dd   0bfd550h
        dd   0bfdffdh
        dd   0bfeaa9h
        dd   0bff555h
        dd   0c00000h
        dd   0c00aaah
        dd   0c01554h
        dd   0c01ffdh
        dd   0c02aa5h
        dd   0c0354dh
        dd   0c03ff5h
        dd   0c04a9ch
        dd   0c05542h
        dd   0c05fe8h
        dd   0c06a8dh
        dd   0c07531h
        dd   0c07fd5h
        dd   0c08a78h
        dd   0c0951bh
        dd   0c09fbdh
        dd   0c0aa5fh
        dd   0c0b500h
        dd   0c0bfa0h
        dd   0c0ca40h
        dd   0c0d4dfh
        dd   0c0df7dh
        dd   0c0ea1bh
        dd   0c0f4b9h
        dd   0c0ff56h
        dd   0c109f2h
        dd   0c1148eh
        dd   0c11f29h
        dd   0c129c3h
        dd   0c1345dh
        dd   0c13ef7h
        dd   0c1498fh
        dd   0c15428h
        dd   0c15ebfh
        dd   0c16956h
        dd   0c173edh
        dd   0c17e82h
        dd   0c18918h
        dd   0c193ach
        dd   0c19e41h
        dd   0c1a8d4h
        dd   0c1b367h
        dd   0c1bdfah
        dd   0c1c88bh
        dd   0c1d31dh
        dd   0c1ddadh
        dd   0c1e83dh
        dd   0c1f2cdh
        dd   0c1fd5ch
        dd   0c207eah
        dd   0c21278h
        dd   0c21d05h
        dd   0c22792h
        dd   0c2321eh
        dd   0c23ca9h
        dd   0c24734h
        dd   0c251bfh
        dd   0c25c49h
        dd   0c266d2h
        dd   0c2715ah
        dd   0c27be3h
        dd   0c2866ah
        dd   0c290f1h
        dd   0c29b77h
        dd   0c2a5fdh
        dd   0c2b082h
        dd   0c2bb07h
        dd   0c2c58bh
        dd   0c2d00fh
        dd   0c2da92h
        dd   0c2e514h
        dd   0c2ef96h
        dd   0c2fa17h
        dd   0c30498h
        dd   0c30f18h
        dd   0c31997h
        dd   0c32416h
        dd   0c32e95h
        dd   0c33913h
        dd   0c34390h
        dd   0c34e0dh
        dd   0c35889h
        dd   0c36305h
        dd   0c36d80h
        dd   0c377fah
        dd   0c38274h
        dd   0c38cedh
        dd   0c39766h
        dd   0c3a1deh
        dd   0c3ac56h
        dd   0c3b6cdh
        dd   0c3c144h
        dd   0c3cbbah
        dd   0c3d62fh
        dd   0c3e0a4h
        dd   0c3eb19h
        dd   0c3f58ch
        dd   0c40000h
        dd   0c40a72h
        dd   0c414e4h
        dd   0c41f56h
        dd   0c429c7h
        dd   0c43437h
        dd   0c43ea7h
        dd   0c44916h
        dd   0c45385h
        dd   0c45df3h
        dd   0c46861h
        dd   0c472ceh
        dd   0c47d3bh
        dd   0c487a7h
        dd   0c49212h
        dd   0c49c7dh
        dd   0c4a6e7h
        dd   0c4b151h
        dd   0c4bbbah
        dd   0c4c623h
        dd   0c4d08bh
        dd   0c4daf3h
        dd   0c4e55ah
        dd   0c4efc0h
        dd   0c4fa26h
        dd   0c5048ch
        dd   0c50ef1h
        dd   0c51955h
        dd   0c523b9h
        dd   0c52e1ch
        dd   0c5387fh
        dd   0c542e1h
        dd   0c54d42h
        dd   0c557a3h
        dd   0c56204h
        dd   0c56c64h
        dd   0c576c3h
        dd   0c58122h
        dd   0c58b80h
        dd   0c595deh
        dd   0c5a03bh
        dd   0c5aa98h
        dd   0c5b4f4h
        dd   0c5bf4fh
        dd   0c5c9aah
        dd   0c5d405h
        dd   0c5de5fh
        dd   0c5e8b8h
        dd   0c5f311h
        dd   0c5fd6ah
        dd   0c607c1h
        dd   0c61219h
        dd   0c61c6fh
        dd   0c626c5h
        dd   0c6311bh
        dd   0c63b70h
        dd   0c645c5h
        dd   0c65019h
        dd   0c65a6ch
        dd   0c664bfh
        dd   0c66f11h
        dd   0c67963h
        dd   0c683b5h
        dd   0c68e05h
        dd   0c69856h
        dd   0c6a2a5h
        dd   0c6acf5h
        dd   0c6b743h
        dd   0c6c191h
        dd   0c6cbdfh
        dd   0c6d62ch
        dd   0c6e079h
        dd   0c6eac4h
        dd   0c6f510h
        dd   0c6ff5bh
        dd   0c709a5h
        dd   0c713efh
        dd   0c71e38h
        dd   0c72881h
        dd   0c732c9h
        dd   0c73d11h
        dd   0c74758h
        dd   0c7519fh
        dd   0c75be5h
        dd   0c7662bh
        dd   0c77070h
        dd   0c77ab4h
        dd   0c784f8h
        dd   0c78f3ch
        dd   0c7997fh
        dd   0c7a3c1h
        dd   0c7ae03h
        dd   0c7b845h
        dd   0c7c285h
        dd   0c7ccc6h
        dd   0c7d706h
        dd   0c7e145h
        dd   0c7eb84h
        dd   0c7f5c2h
        dd   0c80000h
        dd   0c80a3dh
        dd   0c81479h
        dd   0c81eb5h
        dd   0c828f1h
        dd   0c8332ch
        dd   0c83d67h
        dd   0c847a1h
        dd   0c851dah
        dd   0c85c13h
        dd   0c8664ch
        dd   0c87084h
        dd   0c87abbh
        dd   0c884f2h
        dd   0c88f28h
        dd   0c8995eh
        dd   0c8a394h
        dd   0c8adc8h
        dd   0c8b7fdh
        dd   0c8c231h
        dd   0c8cc64h
        dd   0c8d697h
        dd   0c8e0c9h
        dd   0c8eafbh
        dd   0c8f52ch
        dd   0c8ff5ch
        dd   0c9098dh
        dd   0c913bch
        dd   0c91debh
        dd   0c9281ah
        dd   0c93248h
        dd   0c93c76h
        dd   0c946a3h
        dd   0c950cfh
        dd   0c95afbh
        dd   0c96527h
        dd   0c96f52h
        dd   0c9797dh
        dd   0c983a7h
        dd   0c98dd0h
        dd   0c997f9h
        dd   0c9a221h
        dd   0c9ac49h
        dd   0c9b671h
        dd   0c9c098h
        dd   0c9cabeh
        dd   0c9d4e4h
        dd   0c9df09h
        dd   0c9e92eh
        dd   0c9f353h
        dd   0c9fd77h
        dd   0ca079ah
        dd   0ca11bdh
        dd   0ca1bdfh
        dd   0ca2601h
        dd   0ca3022h
        dd   0ca3a43h
        dd   0ca4463h
        dd   0ca4e83h
        dd   0ca58a3h
        dd   0ca62c1h
        dd   0ca6ce0h
        dd   0ca76fdh
        dd   0ca811bh
        dd   0ca8b37h
        dd   0ca9554h
        dd   0ca9f6fh
        dd   0caa98bh
        dd   0cab3a5h
        dd   0cabdc0h
        dd   0cac7d9h
        dd   0cad1f3h
        dd   0cadc0bh
        dd   0cae624h
        dd   0caf03bh
        dd   0cafa53h
        dd   0cb0469h
        dd   0cb0e80h
        dd   0cb1895h
        dd   0cb22abh
        dd   0cb2cbfh
        dd   0cb36d4h
        dd   0cb40e7h
        dd   0cb4afah
        dd   0cb550dh
        dd   0cb5f1fh
        dd   0cb6931h
        dd   0cb7342h
        dd   0cb7d53h
        dd   0cb8763h
        dd   0cb9173h
        dd   0cb9b82h
        dd   0cba591h
        dd   0cbaf9fh
        dd   0cbb9adh
        dd   0cbc3bah
        dd   0cbcdc7h
        dd   0cbd7d3h
        dd   0cbe1dfh
        dd   0cbebeah
        dd   0cbf5f5h
        dd   0cc0000h
        dd   0cc0a09h
        dd   0cc1413h
        dd   0cc1e1bh
        dd   0cc2824h
        dd   0cc322ch
        dd   0cc3c33h
        dd   0cc463ah
        dd   0cc5040h
        dd   0cc5a46h
        dd   0cc644bh
        dd   0cc6e50h
        dd   0cc7854h
        dd   0cc8258h
        dd   0cc8c5ch
        dd   0cc965fh
        dd   0cca061h
        dd   0ccaa63h
        dd   0ccb464h
        dd   0ccbe65h
        dd   0ccc866h
        dd   0ccd266h
        dd   0ccdc65h
        dd   0cce664h
        dd   0ccf063h
        dd   0ccfa61h
        dd   0cd045eh
        dd   0cd0e5bh
        dd   0cd1858h
        dd   0cd2254h
        dd   0cd2c50h
        dd   0cd364bh
        dd   0cd4045h
        dd   0cd4a3fh
        dd   0cd5439h
        dd   0cd5e32h
        dd   0cd682bh
        dd   0cd7223h
        dd   0cd7c1bh
        dd   0cd8612h
        dd   0cd9009h
        dd   0cd99ffh
        dd   0cda3f5h
        dd   0cdadeah
        dd   0cdb7dfh
        dd   0cdc1d3h
        dd   0cdcbc7h
        dd   0cdd5bbh
        dd   0cddfadh
        dd   0cde9a0h
        dd   0cdf392h
        dd   0cdfd83h
        dd   0ce0774h
        dd   0ce1165h
        dd   0ce1b55h
        dd   0ce2544h
        dd   0ce2f33h
        dd   0ce3922h
        dd   0ce4310h
        dd   0ce4cfeh
        dd   0ce56ebh
        dd   0ce60d7h
        dd   0ce6ac4h
        dd   0ce74afh
        dd   0ce7e9ah
        dd   0ce8885h
        dd   0ce926fh
        dd   0ce9c59h
        dd   0cea643h
        dd   0ceb02bh
        dd   0ceba14h
        dd   0cec3fch
        dd   0cecde3h
        dd   0ced7cah
        dd   0cee1b1h
        dd   0ceeb97h
        dd   0cef57ch
        dd   0ceff61h
        dd   0cf0946h
        dd   0cf132ah
        dd   0cf1d0eh
        dd   0cf26f1h
        dd   0cf30d3h
        dd   0cf3ab6h
        dd   0cf4497h
        dd   0cf4e79h
        dd   0cf5859h
        dd   0cf623ah
        dd   0cf6c1ah
        dd   0cf75f9h
        dd   0cf7fd8h
        dd   0cf89b6h
        dd   0cf9394h
        dd   0cf9d72h
        dd   0cfa74fh
        dd   0cfb12ch
        dd   0cfbb08h
        dd   0cfc4e3h
        dd   0cfcebfh
        dd   0cfd899h
        dd   0cfe274h
        dd   0cfec4dh
        dd   0cff627h
        dd   0d00000h
        dd   0d009d8h
        dd   0d013b0h
        dd   0d01d87h
        dd   0d0275eh
        dd   0d03135h
        dd   0d03b0bh
        dd   0d044e0h
        dd   0d04eb6h
        dd   0d0588ah
        dd   0d0625eh
        dd   0d06c32h
        dd   0d07605h
        dd   0d07fd8h
        dd   0d089abh
        dd   0d0937ch
        dd   0d09d4eh
        dd   0d0a71fh
        dd   0d0b0efh
        dd   0d0babfh
        dd   0d0c48fh
        dd   0d0ce5eh
        dd   0d0d82dh
        dd   0d0e1fbh
        dd   0d0ebc9h
        dd   0d0f596h
        dd   0d0ff63h
        dd   0d1092fh
        dd   0d112fbh
        dd   0d11cc6h
        dd   0d12691h
        dd   0d1305ch
        dd   0d13a26h
        dd   0d143f0h
        dd   0d14db9h
        dd   0d15781h
        dd   0d1614ah
        dd   0d16b11h
        dd   0d174d9h
        dd   0d17ea0h
        dd   0d18866h
        dd   0d1922ch
        dd   0d19bf1h
        dd   0d1a5b6h
        dd   0d1af7bh
        dd   0d1b93fh
        dd   0d1c303h
        dd   0d1ccc6h
        dd   0d1d689h
        dd   0d1e04bh
        dd   0d1ea0dh
        dd   0d1f3ceh
        dd   0d1fd8fh
        dd   0d20750h
        dd   0d21110h
        dd   0d21acfh
        dd   0d2248fh
        dd   0d22e4dh
        dd   0d2380ch
        dd   0d241c9h
        dd   0d24b87h
        dd   0d25544h
        dd   0d25f00h
        dd   0d268bch
        dd   0d27277h
        dd   0d27c33h
        dd   0d285edh
        dd   0d28fa7h
        dd   0d29961h
        dd   0d2a31ah
        dd   0d2acd3h
        dd   0d2b68ch
        dd   0d2c044h
        dd   0d2c9fbh
        dd   0d2d3b2h
        dd   0d2dd69h
        dd   0d2e71fh
        dd   0d2f0d4h
        dd   0d2fa8ah
        dd   0d3043fh
        dd   0d30df3h
        dd   0d317a7h
        dd   0d3215ah
        dd   0d32b0dh
        dd   0d334c0h
        dd   0d33e72h
        dd   0d34824h
        dd   0d351d5h
        dd   0d35b86h
        dd   0d36536h
        dd   0d36ee6h
        dd   0d37895h
        dd   0d38244h
        dd   0d38bf3h
        dd   0d395a1h
        dd   0d39f4fh
        dd   0d3a8fch
        dd   0d3b2a9h
        dd   0d3bc55h
        dd   0d3c601h
        dd   0d3cfadh
        dd   0d3d958h
        dd   0d3e302h
        dd   0d3ecadh
        dd   0d3f656h
        dd   0d40000h
        dd   0d409a8h
        dd   0d41351h
        dd   0d41cf9h
        dd   0d426a0h
        dd   0d43047h
        dd   0d439eeh
        dd   0d44394h
        dd   0d44d3ah
        dd   0d456dfh
        dd   0d46084h
        dd   0d46a29h
        dd   0d473cdh
        dd   0d47d70h
        dd   0d48713h
        dd   0d490b6h
        dd   0d49a58h
        dd   0d4a3fah
        dd   0d4ad9bh
        dd   0d4b73ch
        dd   0d4c0ddh
        dd   0d4ca7dh
        dd   0d4d41dh
        dd   0d4ddbch
        dd   0d4e75bh
        dd   0d4f0f9h
        dd   0d4fa97h
        dd   0d50434h
        dd   0d50dd1h
        dd   0d5176eh
        dd   0d5210ah
        dd   0d52aa6h
        dd   0d53441h
        dd   0d53ddch
        dd   0d54777h
        dd   0d55111h
        dd   0d55aaah
        dd   0d56443h
        dd   0d56ddch
        dd   0d57774h
        dd   0d5810ch
        dd   0d58aa4h
        dd   0d5943ah
        dd   0d59dd1h
        dd   0d5a767h
        dd   0d5b0fdh
        dd   0d5ba92h
        dd   0d5c427h
        dd   0d5cdbbh
        dd   0d5d74fh
        dd   0d5e0e3h
        dd   0d5ea76h
        dd   0d5f409h
        dd   0d5fd9bh
        dd   0d6072dh
        dd   0d610beh
        dd   0d61a4fh
        dd   0d623e0h
        dd   0d62d70h
        dd   0d63700h
        dd   0d6408fh
        dd   0d64a1eh
        dd   0d653ach
        dd   0d65d3ah
        dd   0d666c8h
        dd   0d67055h
        dd   0d679e2h
        dd   0d6836eh
        dd   0d68cfah
        dd   0d69685h
        dd   0d6a010h
        dd   0d6a99bh
        dd   0d6b325h
        dd   0d6bcafh
        dd   0d6c638h
        dd   0d6cfc1h
        dd   0d6d949h
        dd   0d6e2d1h
        dd   0d6ec59h
        dd   0d6f5e0h
        dd   0d6ff67h
        dd   0d708edh
        dd   0d71273h
        dd   0d71bf9h
        dd   0d7257eh
        dd   0d72f03h
        dd   0d73887h
        dd   0d7420bh
        dd   0d74b8eh
        dd   0d75511h
        dd   0d75e94h
        dd   0d76816h
        dd   0d77198h
        dd   0d77b19h
        dd   0d7849ah
        dd   0d78e1ah
        dd   0d7979ah
        dd   0d7a11ah
        dd   0d7aa99h
        dd   0d7b418h
        dd   0d7bd96h
        dd   0d7c714h
        dd   0d7d092h
        dd   0d7da0fh
        dd   0d7e38ch
        dd   0d7ed08h
        dd   0d7f684h
        dd   0d80000h
        dd   0d8097bh
        dd   0d812f5h
        dd   0d81c6fh
        dd   0d825e9h
        dd   0d82f63h
        dd   0d838dch
        dd   0d84254h
        dd   0d84bcch
        dd   0d85544h
        dd   0d85ebbh
        dd   0d86832h
        dd   0d871a9h
        dd   0d87b1fh
        dd   0d88494h
        dd   0d88e0ah
        dd   0d8977fh
        dd   0d8a0f3h
        dd   0d8aa67h
        dd   0d8b3dbh
        dd   0d8bd4eh
        dd   0d8c6c1h
        dd   0d8d033h
        dd   0d8d9a5h
        dd   0d8e316h
        dd   0d8ec87h
        dd   0d8f5f8h
        dd   0d8ff68h
        dd   0d908d8h
        dd   0d91248h
        dd   0d91bb7h
        dd   0d92526h
        dd   0d92e94h
        dd   0d93802h
        dd   0d9416fh
        dd   0d94adch
        dd   0d95449h
        dd   0d95db5h
        dd   0d96721h
        dd   0d9708ch
        dd   0d979f7h
        dd   0d98362h
        dd   0d98ccch
        dd   0d99636h
        dd   0d99f9fh
        dd   0d9a908h
        dd   0d9b271h
        dd   0d9bbd9h
        dd   0d9c540h
        dd   0d9cea8h
        dd   0d9d80fh
        dd   0d9e175h
        dd   0d9eadbh
        dd   0d9f441h
        dd   0d9fda6h
        dd   0da070bh
        dd   0da1070h
        dd   0da19d4h
        dd   0da2337h
        dd   0da2c9bh
        dd   0da35feh
        dd   0da3f60h
        dd   0da48c2h
        dd   0da5224h
        dd   0da5b85h
        dd   0da64e6h
        dd   0da6e46h
        dd   0da77a6h
        dd   0da8106h
        dd   0da8a65h
        dd   0da93c4h
        dd   0da9d22h
        dd   0daa681h
        dd   0daafdeh
        dd   0dab93bh
        dd   0dac298h
        dd   0dacbf5h
        dd   0dad551h
        dd   0dadeach
        dd   0dae808h
        dd   0daf162h
        dd   0dafabdh
        dd   0db0417h
        dd   0db0d70h
        dd   0db16cah
        dd   0db2023h
        dd   0db297bh
        dd   0db32d3h
        dd   0db3c2bh
        dd   0db4582h
        dd   0db4ed9h
        dd   0db582fh
        dd   0db6185h
        dd   0db6adbh
        dd   0db7430h
        dd   0db7d85h
        dd   0db86d9h
        dd   0db902eh
        dd   0db9981h
        dd   0dba2d4h
        dd   0dbac27h
        dd   0dbb57ah
        dd   0dbbecch
        dd   0dbc81eh
        dd   0dbd16fh
        dd   0dbdac0h
        dd   0dbe410h
        dd   0dbed60h
        dd   0dbf6b0h
        dd   0dc0000h
        dd   0dc094eh
        dd   0dc129dh
        dd   0dc1bebh
        dd   0dc2539h
        dd   0dc2e86h
        dd   0dc37d3h
        dd   0dc4120h
        dd   0dc4a6ch
        dd   0dc53b8h
        dd   0dc5d03h
        dd   0dc664eh
        dd   0dc6f99h
        dd   0dc78e3h
        dd   0dc822dh
        dd   0dc8b76h
        dd   0dc94bfh
        dd   0dc9e08h
        dd   0dca750h
        dd   0dcb098h
        dd   0dcb9e0h
        dd   0dcc327h
        dd   0dccc6dh
        dd   0dcd5b4h
        dd   0dcdefah
        dd   0dce83fh
        dd   0dcf184h
        dd   0dcfac9h
        dd   0dd040dh
        dd   0dd0d51h
        dd   0dd1695h
        dd   0dd1fd8h
        dd   0dd291bh
        dd   0dd325dh
        dd   0dd3b9fh
        dd   0dd44e1h
        dd   0dd4e22h
        dd   0dd5763h
        dd   0dd60a4h
        dd   0dd69e4h
        dd   0dd7324h
        dd   0dd7c63h
        dd   0dd85a2h
        dd   0dd8ee0h
        dd   0dd981fh
        dd   0dda15ch
        dd   0ddaa9ah
        dd   0ddb3d7h
        dd   0ddbd13h
        dd   0ddc650h
        dd   0ddcf8ch
        dd   0ddd8c7h
        dd   0dde202h
        dd   0ddeb3dh
        dd   0ddf477h
        dd   0ddfdb1h
        dd   0de06ebh
        dd   0de1024h
        dd   0de195dh
        dd   0de2295h
        dd   0de2bcdh
        dd   0de3505h
        dd   0de3e3ch
        dd   0de4773h
        dd   0de50a9h
        dd   0de59dfh
        dd   0de6315h
        dd   0de6c4bh
        dd   0de7580h
        dd   0de7eb4h
        dd   0de87e8h
        dd   0de911ch
        dd   0de9a50h
        dd   0dea383h
        dd   0deacb5h
        dd   0deb5e8h
        dd   0debf1ah
        dd   0dec84bh
        dd   0ded17ch
        dd   0dedaadh
        dd   0dee3deh
        dd   0deed0eh
        dd   0def63dh
        dd   0deff6dh
        dd   0df089bh
        dd   0df11cah
        dd   0df1af8h
        dd   0df2426h
        dd   0df2d53h
        dd   0df3680h
        dd   0df3fadh
        dd   0df48d9h
        dd   0df5205h
        dd   0df5b31h
        dd   0df645ch
        dd   0df6d86h
        dd   0df76b1h
        dd   0df7fdbh
        dd   0df8904h
        dd   0df922eh
        dd   0df9b57h
        dd   0dfa47fh
        dd   0dfada7h
        dd   0dfb6cfh
        dd   0dfbff6h
        dd   0dfc91dh
        dd   0dfd244h
        dd   0dfdb6ah
        dd   0dfe490h
        dd   0dfedb6h
        dd   0dff6dbh
        dd   0e00000h
        dd   0e00924h
        dd   0e01248h
        dd   0e01b6ch
        dd   0e0248fh
        dd   0e02db2h
        dd   0e036d4h
        dd   0e03ff6h
        dd   0e04918h
        dd   0e0523ah
        dd   0e05b5bh
        dd   0e0647bh
        dd   0e06d9ch
        dd   0e076bbh
        dd   0e07fdbh
        dd   0e088fah
        dd   0e09219h
        dd   0e09b37h
        dd   0e0a456h
        dd   0e0ad73h
        dd   0e0b691h
        dd   0e0bfadh
        dd   0e0c8cah
        dd   0e0d1e6h
        dd   0e0db02h
        dd   0e0e41eh
        dd   0e0ed39h
        dd   0e0f653h
        dd   0e0ff6eh
        dd   0e10888h
        dd   0e111a2h
        dd   0e11abbh
        dd   0e123d4h
        dd   0e12cech
        dd   0e13604h
        dd   0e13f1ch
        dd   0e14834h
        dd   0e1514bh
        dd   0e15a61h
        dd   0e16378h
        dd   0e16c8eh
        dd   0e175a3h
        dd   0e17eb9h
        dd   0e187cdh
        dd   0e190e2h
        dd   0e199f6h
        dd   0e1a30ah
        dd   0e1ac1dh
        dd   0e1b530h
        dd   0e1be43h
        dd   0e1c755h
        dd   0e1d067h
        dd   0e1d979h
        dd   0e1e28ah
        dd   0e1eb9bh
        dd   0e1f4abh
        dd   0e1fdbch
        dd   0e206cbh
        dd   0e20fdbh
        dd   0e218eah
        dd   0e221f8h
        dd   0e22b07h
        dd   0e23415h
        dd   0e23d22h
        dd   0e24630h
        dd   0e24f3ch
        dd   0e25849h
        dd   0e26155h
        dd   0e26a61h
        dd   0e2736ch
        dd   0e27c77h
        dd   0e28582h
        dd   0e28e8ch
        dd   0e29796h
        dd   0e2a0a0h
        dd   0e2a9a9h
        dd   0e2b2b2h
        dd   0e2bbbbh
        dd   0e2c4c3h
        dd   0e2cdcbh
        dd   0e2d6d2h
        dd   0e2dfd9h
        dd   0e2e8e0h
        dd   0e2f1e6h
        dd   0e2faech
        dd   0e303f2h
        dd   0e30cf7h
        dd   0e315fch
        dd   0e31f01h
        dd   0e32805h
        dd   0e33109h
        dd   0e33a0ch
        dd   0e34310h
        dd   0e34c12h
        dd   0e35515h
        dd   0e35e17h
        dd   0e36719h
        dd   0e3701ah
        dd   0e3791bh
        dd   0e3821ch
        dd   0e38b1ch
        dd   0e3941ch
        dd   0e39d1bh
        dd   0e3a61bh
        dd   0e3af1ah
        dd   0e3b818h
        dd   0e3c116h
        dd   0e3ca14h
        dd   0e3d312h
        dd   0e3dc0fh
        dd   0e3e50bh
        dd   0e3ee08h
        dd   0e3f704h
        dd   0e40000h
        dd   0e408fbh
        dd   0e411f6h
        dd   0e41af0h
        dd   0e423ebh
        dd   0e42ce5h
        dd   0e435deh
        dd   0e43ed7h
        dd   0e447d0h
        dd   0e450c9h
        dd   0e459c1h
        dd   0e462b9h
        dd   0e46bb0h
        dd   0e474a7h
        dd   0e47d9eh
        dd   0e48694h
        dd   0e48f8ah
        dd   0e49880h
        dd   0e4a175h
        dd   0e4aa6ah
        dd   0e4b35fh
        dd   0e4bc53h
        dd   0e4c547h
        dd   0e4ce3bh
        dd   0e4d72eh
        dd   0e4e021h
        dd   0e4e914h
        dd   0e4f206h
        dd   0e4faf8h
        dd   0e503e9h
        dd   0e50cdah
        dd   0e515cbh
        dd   0e51ebbh
        dd   0e527ach
        dd   0e5309bh
        dd   0e5398bh
        dd   0e5427ah
        dd   0e54b68h
        dd   0e55457h
        dd   0e55d45h
        dd   0e56632h
        dd   0e56f20h
        dd   0e5780dh
        dd   0e580f9h
        dd   0e589e6h
        dd   0e592d2h
        dd   0e59bbdh
        dd   0e5a4a8h
        dd   0e5ad93h
        dd   0e5b67eh
        dd   0e5bf68h
        dd   0e5c852h
        dd   0e5d13bh
        dd   0e5da24h
        dd   0e5e30dh
        dd   0e5ebf6h
        dd   0e5f4deh
        dd   0e5fdc6h
        dd   0e606adh
        dd   0e60f94h
        dd   0e6187bh
        dd   0e62161h
        dd   0e62a47h
        dd   0e6332dh
        dd   0e63c12h
        dd   0e644f7h
        dd   0e64ddch
        dd   0e656c0h
        dd   0e65fa4h
        dd   0e66888h
        dd   0e6716bh
        dd   0e67a4eh
        dd   0e68331h
        dd   0e68c13h
        dd   0e694f5h
        dd   0e69dd7h
        dd   0e6a6b8h
        dd   0e6af99h
        dd   0e6b879h
        dd   0e6c15ah
        dd   0e6ca3ah
        dd   0e6d319h
        dd   0e6dbf8h
        dd   0e6e4d7h
        dd   0e6edb6h
        dd   0e6f694h
        dd   0e6ff72h
        dd   0e7084fh
        dd   0e7112ch
        dd   0e71a09h
        dd   0e722e6h
        dd   0e72bc2h
        dd   0e7349eh
        dd   0e73d79h
        dd   0e74654h
        dd   0e74f2fh
        dd   0e75809h
        dd   0e760e3h
        dd   0e769bdh
        dd   0e77297h
        dd   0e77b70h
        dd   0e78448h
        dd   0e78d21h
        dd   0e795f9h
        dd   0e79ed1h
        dd   0e7a7a8h
        dd   0e7b07fh
        dd   0e7b956h
        dd   0e7c22ch
        dd   0e7cb02h
        dd   0e7d3d8h
        dd   0e7dcadh
        dd   0e7e582h
        dd   0e7ee57h
        dd   0e7f72bh
        dd   0e80000h
        dd   0e808d3h
        dd   0e811a7h
        dd   0e81a7ah
        dd   0e8234ch
        dd   0e82c1fh
        dd   0e834f1h
        dd   0e83dc2h
        dd   0e84694h
        dd   0e84f65h
        dd   0e85835h
        dd   0e86106h
        dd   0e869d6h
        dd   0e872a5h
        dd   0e87b75h
        dd   0e88444h
        dd   0e88d12h
        dd   0e895e1h
        dd   0e89eafh
        dd   0e8a77ch
        dd   0e8b04ah
        dd   0e8b917h
        dd   0e8c1e3h
        dd   0e8cab0h
        dd   0e8d37ch
        dd   0e8dc47h
        dd   0e8e513h
        dd   0e8eddeh
        dd   0e8f6a9h
        dd   0e8ff73h
        dd   0e9083dh
        dd   0e91107h
        dd   0e919d0h
        dd   0e92299h
        dd   0e92b62h
        dd   0e9342ah
        dd   0e93cf2h
        dd   0e945bah
        dd   0e94e81h
        dd   0e95748h
        dd   0e9600fh
        dd   0e968d5h
        dd   0e9719bh
        dd   0e97a61h
        dd   0e98326h
        dd   0e98bebh
        dd   0e994b0h
        dd   0e99d75h
        dd   0e9a639h
        dd   0e9aefch
        dd   0e9b7c0h
        dd   0e9c083h
        dd   0e9c946h
        dd   0e9d208h
        dd   0e9dacah
        dd   0e9e38ch
        dd   0e9ec4dh
        dd   0e9f50fh
        dd   0e9fdcfh
        dd   0ea0690h
        dd   0ea0f50h
        dd   0ea1810h
        dd   0ea20cfh
        dd   0ea298eh
        dd   0ea324dh
        dd   0ea3b0ch
        dd   0ea43cah
        dd   0ea4c88h
        dd   0ea5545h
        dd   0ea5e02h
        dd   0ea66bfh
        dd   0ea6f7ch
        dd   0ea7838h
        dd   0ea80f4h
        dd   0ea89b0h
        dd   0ea926bh
        dd   0ea9b26h
        dd   0eaa3e0h
        dd   0eaac9bh
        dd   0eab555h
        dd   0eabe0eh
        dd   0eac6c8h
        dd   0eacf80h
        dd   0ead839h
        dd   0eae0f1h
        dd   0eae9a9h
        dd   0eaf261h
        dd   0eafb19h
        dd   0eb03d0h
        dd   0eb0c86h
        dd   0eb153dh
        dd   0eb1df3h
        dd   0eb26a8h
        dd   0eb2f5eh
        dd   0eb3813h
        dd   0eb40c8h
        dd   0eb497ch
        dd   0eb5230h
        dd   0eb5ae4h
        dd   0eb6398h
        dd   0eb6c4bh
        dd   0eb74feh
        dd   0eb7db0h
        dd   0eb8662h
        dd   0eb8f14h
        dd   0eb97c6h
        dd   0eba077h
        dd   0eba928h
        dd   0ebb1d9h
        dd   0ebba89h
        dd   0ebc339h
        dd   0ebcbe8h
        dd   0ebd498h
        dd   0ebdd47h
        dd   0ebe5f5h
        dd   0ebeea4h
        dd   0ebf752h
        dd   0ec0000h
        dd   0ec08adh
        dd   0ec115ah
        dd   0ec1a07h
        dd   0ec22b3h
        dd   0ec2b5fh
        dd   0ec340bh
        dd   0ec3cb7h
        dd   0ec4562h
        dd   0ec4e0dh
        dd   0ec56b7h
        dd   0ec5f61h
        dd   0ec680bh
        dd   0ec70b5h
        dd   0ec795eh
        dd   0ec8207h
        dd   0ec8ab0h
        dd   0ec9358h
        dd   0ec9c00h
        dd   0eca4a8h
        dd   0ecad4fh
        dd   0ecb5f6h
        dd   0ecbe9dh
        dd   0ecc743h
        dd   0eccfe9h
        dd   0ecd88fh
        dd   0ece135h
        dd   0ece9dah
        dd   0ecf27fh
        dd   0ecfb23h
        dd   0ed03c7h
        dd   0ed0c6bh
        dd   0ed150fh
        dd   0ed1db2h
        dd   0ed2655h
        dd   0ed2ef8h
        dd   0ed379ah
        dd   0ed403ch
        dd   0ed48deh
        dd   0ed517fh
        dd   0ed5a20h
        dd   0ed62c1h
        dd   0ed6b61h
        dd   0ed7401h
        dd   0ed7ca1h
        dd   0ed8541h
        dd   0ed8de0h
        dd   0ed967fh
        dd   0ed9f1dh
        dd   0eda7bch
        dd   0edb059h
        dd   0edb8f7h
        dd   0edc194h
        dd   0edca31h
        dd   0edd2ceh
        dd   0eddb6ah
        dd   0ede406h
        dd   0edeca2h
        dd   0edf53eh
        dd   0edfdd9h
        dd   0ee0674h
        dd   0ee0f0eh
        dd   0ee17a8h
        dd   0ee2042h
        dd   0ee28dch
        dd   0ee3175h
        dd   0ee3a0eh
        dd   0ee42a7h
        dd   0ee4b3fh
        dd   0ee53d7h
        dd   0ee5c6fh
        dd   0ee6506h
        dd   0ee6d9dh
        dd   0ee7634h
        dd   0ee7ecah
        dd   0ee8761h
        dd   0ee8ff6h
        dd   0ee988ch
        dd   0eea121h
        dd   0eea9b6h
        dd   0eeb24bh
        dd   0eebadfh
        dd   0eec373h
        dd   0eecc07h
        dd   0eed49ah
        dd   0eedd2dh
        dd   0eee5c0h
        dd   0eeee52h
        dd   0eef6e5h
        dd   0eeff76h
        dd   0ef0808h
        dd   0ef1099h
        dd   0ef192ah
        dd   0ef21bbh
        dd   0ef2a4bh
        dd   0ef32dbh
        dd   0ef3b6bh
        dd   0ef43fah
        dd   0ef4c89h
        dd   0ef5518h
        dd   0ef5da6h
        dd   0ef6635h
        dd   0ef6ec2h
        dd   0ef7750h
        dd   0ef7fddh
        dd   0ef886ah
        dd   0ef90f7h
        dd   0ef9983h
        dd   0efa20fh
        dd   0efaa9bh
        dd   0efb326h
        dd   0efbbb2h
        dd   0efc43ch
        dd   0efccc7h
        dd   0efd551h
        dd   0efdddbh
        dd   0efe665h
        dd   0efeeeeh
        dd   0eff777h
        dd   0f00000h
        dd   0f00888h
        dd   0f01110h
        dd   0f01998h
        dd   0f0221fh
        dd   0f02aa6h
        dd   0f0332dh
        dd   0f03bb4h
        dd   0f0443ah
        dd   0f04cc0h
        dd   0f05546h
        dd   0f05dcbh
        dd   0f06650h
        dd   0f06ed5h
        dd   0f07759h
        dd   0f07fddh
        dd   0f08861h
        dd   0f090e5h
        dd   0f09968h
        dd   0f0a1ebh
        dd   0f0aa6eh
        dd   0f0b2f0h
        dd   0f0bb72h
        dd   0f0c3f4h
        dd   0f0cc75h
        dd   0f0d4f6h
        dd   0f0dd77h
        dd   0f0e5f8h
        dd   0f0ee78h
        dd   0f0f6f8h
        dd   0f0ff78h
        dd   0f107f7h
        dd   0f11076h
        dd   0f118f5h
        dd   0f12173h
        dd   0f129f1h
        dd   0f1326fh
        dd   0f13aedh
        dd   0f1436ah
        dd   0f14be7h
        dd   0f15463h
        dd   0f15ce0h
        dd   0f1655ch
        dd   0f16dd8h
        dd   0f17653h
        dd   0f17eceh
        dd   0f18749h
        dd   0f18fc4h
        dd   0f1983eh
        dd   0f1a0b8h
        dd   0f1a932h
        dd   0f1b1abh
        dd   0f1ba24h
        dd   0f1c29dh
        dd   0f1cb15h
        dd   0f1d38dh
        dd   0f1dc05h
        dd   0f1e47dh
        dd   0f1ecf4h
        dd   0f1f56bh
        dd   0f1fde2h
        dd   0f20658h
        dd   0f20eceh
        dd   0f21744h
        dd   0f21fbah
        dd   0f2282fh
        dd   0f230a4h
        dd   0f23918h
        dd   0f2418dh
        dd   0f24a01h
        dd   0f25275h
        dd   0f25ae8h
        dd   0f2635bh
        dd   0f26bceh
        dd   0f27441h
        dd   0f27cb3h
        dd   0f28525h
        dd   0f28d97h
        dd   0f29608h
        dd   0f29e79h
        dd   0f2a6eah
        dd   0f2af5ah
        dd   0f2b7cbh
        dd   0f2c03bh
        dd   0f2c8aah
        dd   0f2d11ah
        dd   0f2d989h
        dd   0f2e1f7h
        dd   0f2ea66h
        dd   0f2f2d4h
        dd   0f2fb42h
        dd   0f303afh
        dd   0f30c1dh
        dd   0f3148ah
        dd   0f31cf6h
        dd   0f32563h
        dd   0f32dcfh
        dd   0f3363bh
        dd   0f33ea6h
        dd   0f34712h
        dd   0f34f7dh
        dd   0f357e7h
        dd   0f36052h
        dd   0f368bch
        dd   0f37125h
        dd   0f3798fh
        dd   0f381f8h
        dd   0f38a61h
        dd   0f392cah
        dd   0f39b32h
        dd   0f3a39ah
        dd   0f3ac02h
        dd   0f3b469h
        dd   0f3bcd0h
        dd   0f3c537h
        dd   0f3cd9eh
        dd   0f3d604h
        dd   0f3de6ah
        dd   0f3e6d0h
        dd   0f3ef35h
        dd   0f3f79bh
        dd   0f40000h
        dd   0f40864h
        dd   0f410c8h
        dd   0f4192ch
        dd   0f42190h
        dd   0f429f3h
        dd   0f43257h
        dd   0f43ab9h
        dd   0f4431ch
        dd   0f44b7eh
        dd   0f453e0h
        dd   0f45c42h
        dd   0f464a3h
        dd   0f46d05h
        dd   0f47565h
        dd   0f47dc6h
        dd   0f48626h
        dd   0f48e86h
        dd   0f496e6h
        dd   0f49f45h
        dd   0f4a7a4h
        dd   0f4b003h
        dd   0f4b862h
        dd   0f4c0c0h
        dd   0f4c91eh
        dd   0f4d17ch
        dd   0f4d9d9h
        dd   0f4e236h
        dd   0f4ea93h
        dd   0f4f2efh
        dd   0f4fb4ch
        dd   0f503a8h
        dd   0f50c03h
        dd   0f5145fh
        dd   0f51cbah
        dd   0f52515h
        dd   0f52d6fh
        dd   0f535cah
        dd   0f53e24h
        dd   0f5467dh
        dd   0f54ed7h
        dd   0f55730h
        dd   0f55f89h
        dd   0f567e1h
        dd   0f57039h
        dd   0f57891h
        dd   0f580e9h
        dd   0f58940h
        dd   0f59198h
        dd   0f599eeh
        dd   0f5a245h
        dd   0f5aa9bh
        dd   0f5b2f1h
        dd   0f5bb47h
        dd   0f5c39dh
        dd   0f5cbf2h
        dd   0f5d447h
        dd   0f5dc9bh
        dd   0f5e4efh
        dd   0f5ed43h
        dd   0f5f597h
        dd   0f5fdebh
        dd   0f6063eh
        dd   0f60e91h
        dd   0f616e3h
        dd   0f61f36h
        dd   0f62788h
        dd   0f62fdah
        dd   0f6382bh
        dd   0f6407ch
        dd   0f648cdh
        dd   0f6511eh
        dd   0f6596eh
        dd   0f661beh
        dd   0f66a0eh
        dd   0f6725eh
        dd   0f67aadh
        dd   0f682fch
        dd   0f68b4bh
        dd   0f69399h
        dd   0f69be7h
        dd   0f6a435h
        dd   0f6ac82h
        dd   0f6b4d0h
        dd   0f6bd1dh
        dd   0f6c56ah
        dd   0f6cdb6h
        dd   0f6d602h
        dd   0f6de4eh
        dd   0f6e69ah
        dd   0f6eee5h
        dd   0f6f730h
        dd   0f6ff7bh
        dd   0f707c5h
        dd   0f71010h
        dd   0f7185ah
        dd   0f720a3h
        dd   0f728edh
        dd   0f73136h
        dd   0f7397fh
        dd   0f741c7h
        dd   0f74a0fh
        dd   0f75257h
        dd   0f75a9fh
        dd   0f762e7h
        dd   0f76b2eh
        dd   0f77375h
        dd   0f77bbbh
        dd   0f78402h
        dd   0f78c48h
        dd   0f7948dh
        dd   0f79cd3h
        dd   0f7a518h
        dd   0f7ad5dh
        dd   0f7b5a2h
        dd   0f7bde6h
        dd   0f7c62ah
        dd   0f7ce6eh
        dd   0f7d6b2h
        dd   0f7def5h
        dd   0f7e738h
        dd   0f7ef7bh
        dd   0f7f7bdh
        dd   0f80000h
        dd   0f80841h
        dd   0f81083h
        dd   0f818c4h
        dd   0f82106h
        dd   0f82946h
        dd   0f83187h
        dd   0f839c7h
        dd   0f84207h
        dd   0f84a47h
        dd   0f85286h
        dd   0f85ac6h
        dd   0f86305h
        dd   0f86b43h
        dd   0f87382h
        dd   0f87bc0h
        dd   0f883fdh
        dd   0f88c3bh
        dd   0f89478h
        dd   0f89cb5h
        dd   0f8a4f2h
        dd   0f8ad2eh
        dd   0f8b56bh
        dd   0f8bda6h
        dd   0f8c5e2h
        dd   0f8ce1dh
        dd   0f8d659h
        dd   0f8de93h
        dd   0f8e6ceh
        dd   0f8ef08h
        dd   0f8f742h
        dd   0f8ff7ch
        dd   0f907b5h
        dd   0f90fefh
        dd   0f91827h
        dd   0f92060h
        dd   0f92898h
        dd   0f930d1h
        dd   0f93908h
        dd   0f94140h
        dd   0f94977h
        dd   0f951aeh
        dd   0f959e5h
        dd   0f9621bh
        dd   0f96a52h
        dd   0f97288h
        dd   0f97abdh
        dd   0f982f3h
        dd   0f98b28h
        dd   0f9935dh
        dd   0f99b91h
        dd   0f9a3c6h
        dd   0f9abfah
        dd   0f9b42dh
        dd   0f9bc61h
        dd   0f9c494h
        dd   0f9ccc7h
        dd   0f9d4fah
        dd   0f9dd2ch
        dd   0f9e55eh
        dd   0f9ed90h
        dd   0f9f5c2h
        dd   0f9fdf3h
        dd   0fa0624h
        dd   0fa0e55h
        dd   0fa1686h
        dd   0fa1eb6h
        dd   0fa26e6h
        dd   0fa2f16h
        dd   0fa3745h
        dd   0fa3f74h
        dd   0fa47a3h
        dd   0fa4fd2h
        dd   0fa5800h
        dd   0fa602fh
        dd   0fa685ch
        dd   0fa708ah
        dd   0fa78b7h
        dd   0fa80e4h
        dd   0fa8911h
        dd   0fa913eh
        dd   0fa996ah
        dd   0faa196h
        dd   0faa9c2h
        dd   0fab1edh
        dd   0faba18h
        dd   0fac243h
        dd   0faca6eh
        dd   0fad298h
        dd   0fadac3h
        dd   0fae2ech
        dd   0faeb16h
        dd   0faf33fh
        dd   0fafb69h
        dd   0fb0391h
        dd   0fb0bbah
        dd   0fb13e2h
        dd   0fb1c0ah
        dd   0fb2432h
        dd   0fb2c59h
        dd   0fb3481h
        dd   0fb3ca8h
        dd   0fb44ceh
        dd   0fb4cf5h
        dd   0fb551bh
        dd   0fb5d41h
        dd   0fb6566h
        dd   0fb6d8ch
        dd   0fb75b1h
        dd   0fb7dd6h
        dd   0fb85fah
        dd   0fb8e1fh
        dd   0fb9643h
        dd   0fb9e67h
        dd   0fba68ah
        dd   0fbaeadh
        dd   0fbb6d0h
        dd   0fbbef3h
        dd   0fbc716h
        dd   0fbcf38h
        dd   0fbd75ah
        dd   0fbdf7bh
        dd   0fbe79dh
        dd   0fbefbeh
        dd   0fbf7dfh
        dd   0fc0000h
        dd   0fc0820h
        dd   0fc1040h
        dd   0fc1860h
        dd   0fc207fh
        dd   0fc289fh
        dd   0fc30beh
        dd   0fc38ddh
        dd   0fc40fbh
        dd   0fc4919h
        dd   0fc5137h
        dd   0fc5955h
        dd   0fc6173h
        dd   0fc6990h
        dd   0fc71adh
        dd   0fc79cah
        dd   0fc81e6h
        dd   0fc8a02h
        dd   0fc921eh
        dd   0fc9a3ah
        dd   0fca255h
        dd   0fcaa71h
        dd   0fcb28bh
        dd   0fcbaa6h
        dd   0fcc2c0h
        dd   0fccadbh
        dd   0fcd2f4h
        dd   0fcdb0eh
        dd   0fce327h
        dd   0fceb40h
        dd   0fcf359h
        dd   0fcfb72h
        dd   0fd038ah
        dd   0fd0ba2h
        dd   0fd13bah
        dd   0fd1bd1h
        dd   0fd23e9h
        dd   0fd2c00h
        dd   0fd3416h
        dd   0fd3c2dh
        dd   0fd4443h
        dd   0fd4c59h
        dd   0fd546fh
        dd   0fd5c84h
        dd   0fd649ah
        dd   0fd6caeh
        dd   0fd74c3h
        dd   0fd7cd8h
        dd   0fd84ech
        dd   0fd8d00h
        dd   0fd9513h
        dd   0fd9d27h
        dd   0fda53ah
        dd   0fdad4dh
        dd   0fdb55fh
        dd   0fdbd72h
        dd   0fdc584h
        dd   0fdcd96h
        dd   0fdd5a7h
        dd   0fdddb9h
        dd   0fde5cah
        dd   0fdeddbh
        dd   0fdf5ebh
        dd   0fdfdfbh
        dd   0fe060ch
        dd   0fe0e1bh
        dd   0fe162bh
        dd   0fe1e3ah
        dd   0fe2649h
        dd   0fe2e58h
        dd   0fe3667h
        dd   0fe3e75h
        dd   0fe4683h
        dd   0fe4e91h
        dd   0fe569eh
        dd   0fe5eabh
        dd   0fe66b8h
        dd   0fe6ec5h
        dd   0fe76d2h
        dd   0fe7edeh
        dd   0fe86eah
        dd   0fe8ef6h
        dd   0fe9701h
        dd   0fe9f0ch
        dd   0fea717h
        dd   0feaf22h
        dd   0feb72ch
        dd   0febf37h
        dd   0fec740h
        dd   0fecf4ah
        dd   0fed754h
        dd   0fedf5dh
        dd   0fee766h
        dd   0feef6eh
        dd   0fef777h
        dd   0feff7fh
        dd   0ff0787h
        dd   0ff0f8fh
        dd   0ff1796h
        dd   0ff1f9dh
        dd   0ff27a4h
        dd   0ff2fabh
        dd   0ff37b1h
        dd   0ff3fb7h
        dd   0ff47bdh
        dd   0ff4fc3h
        dd   0ff57c8h
        dd   0ff5fcdh
        dd   0ff67d2h
        dd   0ff6fd7h
        dd   0ff77dbh
        dd   0ff7fdfh
        dd   0ff87e3h
        dd   0ff8fe7h
        dd   0ff97eah
        dd   0ff9fedh
        dd   0ffa7f0h
        dd   0ffaff3h
        dd   0ffb7f5h
        dd   0ffbff7h
        dd   0ffc7f9h
        dd   0ffcffbh
        dd   0ffd7fch
        dd   0ffdffdh
        dd   0ffe7feh
        dd   0ffefffh
        dd   0fff7ffh
                    
_DATA  ENDS         
       end          
                    
;ฐฑฒ End of module - flxdata.asm ฒฑฐ
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
