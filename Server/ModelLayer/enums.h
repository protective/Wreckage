
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
		powerStatsReq,
		powerStatsRsp,
		casterStatsReq,
		casterStatsRsp,
		activatePowerOnt,
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
		attackRoll,
		whitedamageRoll,
		whiteDamage,
		hitP,
	};
}
#endif	/* ENUMS_H */

