/* 
 * File:   SOrdreInstructionSet.h
 * Author: karsten
 *
 * Created on 5. september 2014, 17:51
 */

#ifndef INSTRUCTIONSET_H
#define	INSTRUCTIONSET_H
namespace wkl {
namespace inst{
	enum Enum{
		NOP			= 0x00000000,
		FUN		    = 0x00100000,
		EOP         = 0x00010000, //i
		jmpR        = 0x00310000,
		jmpA_1      = 0x00320000,
        cjmpA_1     = 0x00330000,
		jmpRC       = 0x00340000,
		jmpAC       = 0x00350000,
		cjmp2NeqA_1 = 0x00360000, //i
		pushN       = 0x00050000,
		pushS0N     = 0x00150000,
        pushN_1     = 0x00060000, //i
		popN        = 0x00070000, //i
		call        = 0x00400000, 
		ret         = 0x00410000,
		popPC       = 0x00420000,
		pushPC      = 0x00430000, 
		pushRPC     = 0x00440000, 
		pushUIndx	= 0x00450000, 
		cmpS0S1     = 0x000A0000,
		cmpS0R      = 0x000B0000,
		cmpS0A      = 0x000C0000,		
		pushRS_1    = 0x000D0000,
		pushS0A     = 0x000E0000,
        cpN_DS2     = 0x00500000, //i
		cpN_DRS2    = 0x00510000,
		cpN_RDS2    = 0x00520000, //i
		cpEN_DS2	= 0x00600000, //i
		
		cpRIS2_T    = 0x00560000, //copy rel S0 [S1] to top
		cpAIS2_T    = 0x00550000, //copy abs S0 [S1] to top
		cpEIS2_T	= 0x00620000, //copy env[S0][S1] to top
		cpT_EN   	= 0x00630000, //copy top to env [N]
		
		cpI_DS2     = 0x00530000, 
		cpI_RDS2    = 0x00540000,
		cpEI_DS2	= 0x00610000, 

		addS01      = 0x00200000,
		minusS01    = 0x00210000,	 
		addS01dS1   = 0x00220000, //i
		minusS01dS1 = 0x00230000, //i
		eqS01dS1    = 0x00240000, //i
		neqS01dS1   = 0x00250000, //i
		
		
		sysCall     = 0x00F00000, //i
	};
}
}

#endif	/* INSTRUCTIONSET_H */

