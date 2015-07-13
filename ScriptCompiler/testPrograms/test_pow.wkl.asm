no instruction =44

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
0X0013		  	(Env src)      0000000000
0X0014	0X05 (pushN)	0X01
0X0015	0X60 (cpEN_DS2)	0X01
0X0016		  	(Rel dest)     0000000000
0X0017		  	(Env src)      0X00000001
0X0018	0X05 (pushN)	0X01
0X0019	0X60 (cpEN_DS2)	0X01
0X001A		  	(Rel dest)     0000000000
0X001B		  	(Env src)      0X00000002
0X001C	0X05 (pushN)	0X01
0X001D	0X60 (cpEN_DS2)	0X01
0X001E		  	(Rel dest)     0000000000
0X001F		  	(Env src)      0X00000003
0X0020	0XF0 (sysCall)	0X01
0X0021		  	(Stack)        0X00000005
0X0022	0X07 (popN)	0X04
0X0023	0X53 (cpI_DS2)	0000
0X0024		  	(Rel dest)     0X00000004
0X0025		  	(Rel src)      0000000000
0X0026	0X53 (cpI_DS2)	0X01
0X0027		  	(Rel dest)     0X00000001
0X0028		  	(Rel src)      0000000000
0X0029	0X07 (popN)	0X01
0X002A	0X07 (popN)	0X06
0X002B	0X42 (popPC)

