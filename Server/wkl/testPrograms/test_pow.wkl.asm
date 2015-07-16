no instruction =55

function           line
__hit__            18
__cast__           18
__activate_target__18
__hit__            2
__cast__           2
__activate_target__2


line	opcode			arg	
000000	0X01 (...EOP...)
0X0001	0000 (...NOP...)
0X0002	0X06 (pushN_1)	0X01
0X0003		  	(value)        0X0000EEEE
0X0004	0X05 (pushN)	0X01
0X0005	0X60 (cpEN_DS2)	0X01
0X0006		  	(Rel dest)     0000000000
0X0007		  	(Env src)      0X00000002
0X0008	0X06 (pushN_1)	0X01
0X0009		  	(value)        0X00000004
0X000A	0X06 (pushN_1)	0X01
0X000B		  	(value)        0X000003E8
0X000C	0XF0 (sysCall)	0X05
0X000D		  	(Stack)        0X00000004
0X000E	0X07 (popN)	0X03
0X000F	0X07 (popN)	0X01
0X0010	0X42 (popPC)
0X0011	0000 (...NOP...)
0X0012	0X06 (pushN_1)	0X01
0X0013		  	(value)        0X00000004
0X0014	0X06 (pushN_1)	0X01
0X0015		  	(value)        0X0000002D
0X0016	0X06 (pushN_1)	0X01
0X0017		  	(value)        0X00000001
0X0018	0X06 (pushN_1)	0X01
0X0019		  	(value)        0X00000006
0X001A	0X06 (pushN_1)	0X01
0X001B		  	(value)        0X00000007
0X001C	0X06 (pushN_1)	0X01
0X001D		  	(value)        0000000000
0X001E	0X06 (pushN_1)	0X01
0X001F		  	(value)        0X0000EEEE
0X0020	0X05 (pushN)	0X01
0X0021	0X60 (cpEN_DS2)	0X01
0X0022		  	(Rel dest)     0000000000
0X0023		  	(Env src)      0X00000003
0X0024	0X06 (pushN_1)	0X01
0X0025		  	(value)        0X00000001
0X0026	0X06 (pushN_1)	0X01
0X0027		  	(value)        0X00000006
0X0028	0X22 (addS01dS1)
0X0029	0X06 (pushN_1)	0X01
0X002A		  	(value)        0X00000063
0X002B	0XF0 (sysCall)	0X01
0X002C		  	(Stack)        0X00000004
0X002D	0X07 (popN)	0X03
0X002E	0X53 (cpI_DS2)	0000
0X002F		  	(Rel dest)     0X00000004
0X0030		  	(Rel src)      0000000000
0X0031	0X53 (cpI_DS2)	0X01
0X0032		  	(Rel dest)     0X00000001
0X0033		  	(Rel src)      0000000000
0X0034	0X07 (popN)	0X01
0X0035	0X07 (popN)	0X06
0X0036	0X42 (popPC)

