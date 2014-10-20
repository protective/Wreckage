
#ifndef ENUMS_H
#define	ENUMS_H

namespace COMPID {
	enum Enum {
		invalid = 0,
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

