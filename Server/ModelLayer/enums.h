
#ifndef ENUMS_H
#define	ENUMS_H

namespace OBJDATA {
	enum Enum {
		invalid = 0,
		hp,
		maxhp,
		hitP,
		dodgeP,
		target,
		owner,
	};
}


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
		hitP,
		dodgeP,
		
	};
}

namespace PROJECTILESTATS {
	enum Enum {
		invalid = 0,
		level,
		hitP,
	};
}
#endif	/* ENUMS_H */

