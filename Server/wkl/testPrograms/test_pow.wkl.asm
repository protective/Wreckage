no instruction =39

function           line
__hit__            2


line	opcode			arg	
000000	0X01 (...EOP...)
0X0001	0000 (...NOP...)
0X0002	0X06 (pushN_1)	0X01
0X0003		  	(value)        0X00000004
0X0004	0X06 (pushN_1)	0X01
0X0005		  	(value)        0X0000002D
0X0006	0X06 (pushN_1)	0X01
0X0007		  	(value)        0X00000001
0X0008	0X06 (pushN_1)	0X01
0X0009		  	(value)        0X00000006
0X000A	0X06 (pushN_1)	0X01
0X000B		  	(value)        0X00000007
0X000C	0X06 (pushN_1)	0X01
0X000D		  	(value)        0000000000
0X000E	0X06 (pushN_1)	0X01
0X000F		  	(value)        0X0000EEEE
0X0010	0X05 (pushN)	0X01
0X0011	0X60 (cpEN_DS2)	0X01
0X0012		  	(Rel dest)     0000000000
0X0013		  	(Env src)      0X00000002
0X0014	0X06 (pushN_1)	0X01
0X0015		  	(value)        0X00000001
0X0016	0X06 (pushN_1)	0X01
0X0017		  	(value)        0X00000006
0X0018	0X22 (addS01dS1)
0X0019	0X06 (pushN_1)	0X01
0X001A		  	(value)        0X00000063
0X001B	0XF0 (sysCall)	0X01
0X001C		  	(Stack)        0X00000004
0X001D	0X07 (popN)	0X03
0X001E	0X53 (cpI_DS2)	0000
0X001F		  	(Rel dest)     0X00000004
0X0020		  	(Rel src)      0000000000
0X0021	0X53 (cpI_DS2)	0X01
0X0022		  	(Rel dest)     0X00000001
0X0023		  	(Rel src)      0000000000
0X0024	0X07 (popN)	0X01
0X0025	0X07 (popN)	0X06
0X0026	0X42 (popPC)

