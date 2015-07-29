#include "systemCallLib.h"

#include "../Program.h"

namespace wkl {
	

	//systemCallBack_t systemCallLib[] = 

	namespace systemCallLib{

		map<uint32_t, systemCallBack_t> lib = {
			{phycicalDamage, "_wkl_phycicalDamage"},
			{burnMana, "_wkl_burnMana"},
			{hitTarget, "_wkl_hitTarget"},
			{consume, "_wkl_consume"},
			{channel, "_wkl_channel"},
			{checkrange, "_wkl_checkrange"},
			{getObjInRange, "_wkl_getObjInRange"}
		};

	}
	namespace systemCallBackLib{
		
		map<uint32_t, systemCallBackEntry_t> lib = {
			{__hit__, "__hit__"},
			{__cast__, "__cast__"},
			{__activate_target__, "__activate_target__"}
		};
	}

	namespace systemEnvLib{
		
		map<uint32_t, systemCallBack_t> lib = {
			{wkl_level, "wkl_level"},
			{wkl_target, "wkl_target"},
			{wkl_missChance, "wkl_missChance"},
			{wkl_critChance, "wkl_critChance"}
		};
	}

};