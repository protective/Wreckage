
#ifndef ENUMS_H
#define	ENUMS_H

#include "../../GShare/Enums.h"


namespace COMPID {
	enum Enum {
		invalid = 0,
		spellbook = 4,
		powerUseCheck = 5,
		powerActivateTimed = 6,
		spawnNode = 7,
		reSpawnable = 8,
		abilityInput = 9,
		player = 10,
		powerActivateInstant = 11,
		targeted = 12,
		modelStatic = 13,
		position = 14,
		powerBase = 15,
		programable = 16
	};
}
namespace SIGNAL {
	enum Enum {
		invalid = 0,
		castTarget,
		castPos,
		takeDamage,
		loseMana,
		process,
		fireTarget,
		killed,
		powerHit,
		enterClient,
		exitClient,
		enterDevClient,
		runProgram,
		created
	};
}

namespace MESSAGE {
	enum Enum {
		invalid = 0,
		process,
		castTarget,
		castPos,
		takeDamage,
		loseMana,
		applyPower,
		killed, //the unit sending this messeage is dead
		HeartBeatReq,
		HeartBeatRsp,
		programFunctionSleep,
		powerCheck,
		powerCheckRsp,
		powerStats,
		powerStatsRsp,
		casterStatsReq,
		casterStatsRsp,
		activatePowerOnt,
		requestRefObj,
		objDeleted,
		programCallback,
		systemBroadcast,
		destInRangeReq,
		destInRangeRsp,
		destUpdate,
		programSleepWake,
		reCloneComp
				
	};
}

namespace OBJDATA {
	enum Enum {
		invalid = 0,
		hp,
		level,
		AC,
		maxhp,
		hitP,
		dodgeP,
		parryP,
		blockP,
		target,
		owner,
		position,
		mana,
		maxMana,
	};
}


namespace DAMAGETYPES {
	enum Enum {
		invalid = 0,
		pircing,
		slashing,
		crushing,
		
	};
}

namespace powerResults {
	enum Enum {
		invalid = 0,
		hit,
		miss,
		crit
	};
}


#endif	/* ENUMS_H */

