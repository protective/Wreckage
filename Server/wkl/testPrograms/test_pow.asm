no instruction =29

function                line
__activate_target__     1


line	opcode			arg	
000000	0X01 (...EOP...)
0X0001	0X10 (...FUN...)	0X03
0X0002	0X06 (pushN_1)	0X01
0X0003		  	(value)        0X00000016
0X0004	0X05 (pushN)	0X01
0X0005	0X50 (cpN_DS2)	0X01
0X0006		  	(Rel dest)     0000000000
0X0007		  	(Rel src)      0X00000001
0X0008	0X33 (cjmpA_1)	0000
0X0009		  	(Line)         0X000D
0X000A	0X07 (popN)	0X01
0X000B	0X32 (jmpA_1)	0000
0X000C		  	(Line)         0X001B
0X000D	0X07 (popN)	0X01
0X000E	0X05 (pushN)	0X01
0X000F	0X50 (cpN_DS2)	0X01
0X0010		  	(Rel dest)     0000000000
0X0011		  	(Rel src)      0X00000001
0X0012	0X63 (cpT_EN)
0X0013		  	(Env dest)     0X00000005
0X0014	0X07 (popN)	0X01
0X0015	0X06 (pushN_1)	0X01
0X0016		  	(value)        0X0000002A
0X0017	0X63 (cpT_EN)
0X0018		  	(Env dest)     0X00000006
0X0019	0X07 (popN)	0X01
0X001A	0X07 (popN)	0X01
0X001B	0X07 (popN)	0X01
0X001C	0X42 (popPC)

