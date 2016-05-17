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
        
		//
		//00 00 00 01  x01 Src Rel
		//00 00 00 10  x02 Dest Rel
		//00 00 01 00  x04 Dest mode=env
		
		//00 01 00 00  x10 Src mode=env
		//00 10 00 00  x20 Src mode=const

		//01 00 00 00  x40 arg=Dest index
		//10 00 00 00  x80 arg=src index
		
		cpN_ADAS2   = 0x00900000, //i copy N from abs scr to abs dest arg=N
		cpN_ADRS2   = 0x02900000, //i copy N from abs scr to rel dest arg=N
		cpN_RDAS2   = 0x01900000, //i copy N from rel scr to abs dest arg=N
		cpN_RDRS2   = 0x03900000, //i copy N from rel scr to rel dest arg=N

		cpN_EAD2    = 0x90900000, //copy env scr to abs dest
		cpN_ERD2    = 0x92900000, //copy env scr to rel dest
		cpN_AED2    = 0x04900000, //copy abs scr to env dest
		cpN_RED2    = 0x05900000, //copy rel scr to env dest
		
		cp_ASIAD2   = 0x00A00000, //copy abs src index to abs dest
		cp_ASIRD2   = 0x02A00000, //copy abs src index to rel dest
		cp_RSIAD2   = 0x01A00000, //copy rel src index to abs dest
		cp_RSIRD2   = 0x03A00000, //copy rel src index to rel dest

		cp_ASsvIAD2 = 0x00A10000, //copy abs src stackVal index to abs dest
		cp_ASsvIRD2 = 0x02A10000, //copy abs src stackVal index to rel dest
		cp_RSsvIAD2 = 0x01A10000, //copy rel src stackVal index to abs dest
		cp_RSsvIRD2 = 0x03A10000, //copy rel src stackVal index to rel dest
		
		//cpRIS2_T    = 0x00560000, //copy rel S0 [S1] to top
		cpAIS2_T    = 0x00650000, //copy abs S0 [S1] to top
		cpEIS2_T	= 0x00620000, //copy env[S0][S1] to top

		
		
		//cpI_DS2     = 0x00530000, //top stack to rel loc
		cpI_RDS2    = 0x00640000, //top stack to abs loc
		cpEI_DS2	= 0x00610000, //top stack to loc 

		cpCO_DS2	= 0x00700000, //i copy const to dest
		
		mvMapAL     = 0x00800000,
		addS01      = 0x00200000,
		minusS01    = 0x00210000,	 
		addS01dS1   = 0x00220000, //i
		minusS01dS1 = 0x00230000, //i
		multiS01dS1 = 0x00240000, //i
		deviS01dS1  = 0x00250000, //i
		moduloS01dS1= 0x00260000, //i
		leeqS01dS1  = 0x00270000, //i
		leS01dS1    = 0x00280000, //i
		gteqS01dS1  = 0x00290000, //i		
		gtS01dS1    = 0x002A0000, //i
		eqS01dS1    = 0x002C0000, //i	
		neqS01dS1   = 0x002D0000, //i
		
		andS01dS1   = 0x00500000, //i
		orS01dS1    = 0x00510000, //i	
		bitandS01dS1= 0x00520000, //i
		bitorS01dS1 = 0x00530000, //i			
		sysCall     = 0x00F00000, //i
	};
}
}

#endif	/* INSTRUCTIONSET_H */

