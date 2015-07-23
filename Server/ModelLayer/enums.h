
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
		powerDealDamage = 10,
		powerActivateInstant = 11,
		targeted = 12,
		modelStatic = 13,
		position = 14,
		powerBase = 15,

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
		ProjectileStats,
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
		systemBroadcast
				
	};
}

namespace STATS {
	enum Enum {
		invalid = 0,
		hp,
		maxhp,
		level,
		parryP,
		blockP,
		hitP,
		dodgeP,
		
	};
}

namespace PROJECTILESTATS {
	enum Enum {
		invalid = 0,
		type,
		level,
		critP,
		missP,
		attack,
		whiteDamage,
		whiteDamageCrit,
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

namespace PowerKeys {
	enum Enum {
		invalid = 0,
		targetMode = 1,
		target = 2,
		targetType = 3,
		targetRange = 4,
		
		
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

namespace outKeys {
	enum Enum {
		invalid = 0,
		result = 1,
		damageDone = 2,
		healingDone = 3,
		pos = 4
		
	};
}


#endif	/* ENUMS_H */

