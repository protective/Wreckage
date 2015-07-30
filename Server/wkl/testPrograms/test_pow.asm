no instruction =39

function                line
__activate_target__     1


line	opcode			arg	
000000	0X01 (...EOP...)
0X0001	0X10 (...FUN...)	0X03
0X0002	0X06 (pushN_1)	0X01
0X0003		  	(value)        0X00000016
0X0004	0X06 (pushN_1)	0X01
0X0005		  	(value)        0X0000002A
0X0006	0X06 (pushN_1)	0X01
0X0007		  	(value)        0X00000018
0X0008	0X05 (pushN)	0X01
0X0009	0X50 (cpN_DS2)	0X01
0X000A		  	(Rel dest)     0000000000
0X000B		  	(Rel src)      0X00000002
0X000C	0X45 (pushUIndx)
0X000D		  	(Rel src)      0000000000
0X000E	0X06 (pushN_1)	0X01
0X000F		  	(value)        0000000000
0X0010	0X32 (jmpA_1)	0000
0X0011		  	(Line)         0X0022
0X0012	0X06 (pushN_1)	0X01
0X0013		  	(value)        0000000000
0X0014	0X56 (cpRIS2_T)	0X01
0X0015		  	(Rel src)      0X00000003
0X0016	0X06 (pushN_1)	0X01
0X0017		  	(value)        0X0000029A
0X0018	0X06 (pushN_1)	0X01
0X0019		  	(value)        0X0000029B
0X001A	0X05 (pushN)	0X01
0X001B	0X50 (cpN_DS2)	0X01
0X001C		  	(Rel dest)     0000000000
0X001D		  	(Rel src)      0X00000003
0X001E	0X07 (popN)	0X04
0X001F	0X06 (pushN_1)	0X01
0X0020		  	(value)        0X00000001
0X0021	0X22 (addS01dS1)
0X0022	0X36 (cjmp2NeqA_1)
0X0023		  	(Line)         0X0012
0X0024	0X07 (popN)	0X03
0X0025	0X07 (popN)	0X03
0X0026	0X42 (popPC)

