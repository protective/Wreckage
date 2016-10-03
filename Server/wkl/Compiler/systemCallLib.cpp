#include "systemCallLib.h"

#include "../Program.h"
#include "../../../Server/ModelLayer/enums.h"
namespace wkl {

	namespace systemCallLib{

		map<uint32_t, systemCallBack_t> lib = {
			{phycicalDamage, "_wkl_phycicalDamage"},
			{burnMana, "_wkl_burnMana"},
			{hitTarget, "_wkl_hitTarget"},
			{consumeMana, "_wkl_consumeMana"},
			{consume, "_wkl_consume"},
			{cast, "_wkl_cast"},
			{channel, "_wkl_channel"},
			{checkrange, "_wkl_checkrange"},
			{getObjInRange, "_wkl_getObjInRange"},
			{gainBuff, "_wkl_gainBuff"},
			{updateBuff, "_wkl_updateBuff"},
			{loseBuff, "_wkl_loseBuff"},
			{sleep, "_wkl_sleep"},
			{min, "min"},
			{max, "max"}			
		};

	}
	namespace systemCallBackLib{
		
		map<uint32_t, systemCallBackEntry_t> lib = {
			{__hit__, "__hit__"},
			{__cast__, "__cast__"},
			{__activate_target__, "__activate_target__"},
			{__gain_buff__, "__gain_buff__"},
			{__lose_buff__, "__lose_buff__"},
			{__tick_buff__, "__tick_buff__"},
			{__on_gain_buff__, "__on_gain_buff__"},
			{__on_lose_buff__, "__on_lose_buff__"},
			{__on_heal__, "__on_heal__"},
			{__on_hit__, "__on_hit__"},
			{__on_damage__, "__on_damage__"},
			{__on_begin_cast__, "__on_begin_cast__"},
			{__on_cast__, "__on_cast__"}
			
		};
	}

	namespace systemEnvLib{
		
		map<uint32_t, systemCallBack_t> lib = {
			{wkl_level, "wkl_level"},
			{wkl_target, "wkl_target"},
			{wkl_missChance, "wkl_missChance"},
			{wkl_critChance, "wkl_critChance"},
			{wkl_buffId, "wkl_buffId"},
			{wkl_buffTickCounter, "wkl_buffTickCounter"},
			{wkl_buffTickTime, "wkl_buffTickTime"},
			{wkl_gfx_cast, "wkl_gfx_cast"},
			{wkl_gfx_travel, "wkl_gfx_travel"},
			{wkl_gfx_hit, "wkl_gfx_hit"},
			{wkl_gfx_buffgain, "wkl_gfx_buffgain"},
			{wkl_gfx_buffanimate, "wkl_gfx_buffanimate"},
			{wkl_gfx_bufflose, "wkl_gfx_bufflose"}
		};
	}
	
	namespace systemConst{
		
		map<uint32_t, systemConst_t> systemConst = {
			{wkl_c_mana, "wkl_c_mana"},
			{wkl_c_hp, "wkl_c_hp"}
		};
		
		map<uint32_t, Variable> systemConstValues = {
			{wkl_c_mana, Variable(OBJDATA::mana)},
			{wkl_c_hp, Variable(OBJDATA::hp)}
		};
	}
};