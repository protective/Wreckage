/* 
 * File:   systemCallLib.h
 * Author: karsten
 *
 * Created on 11. juli 2015, 11:13
 */

#ifndef SYSTEMCALLLIB_H
#define	SYSTEMCALLLIB_H

#include <string>
#include <inttypes.h>
#include <map>
#include "../Utils/Variable.h"

using namespace std;

class SObj;
namespace wkl {
	class ProgramExecutor;
	typedef Variable (*systemCallFunc)(SObj* _this, ProgramExecutor* programExe, void*);
	
	typedef string systemCallBack_t;
	
	typedef string systemConst_t;	

	typedef string systemCallBackEntry_t;

	typedef string systemEnvEntry_t;
	namespace systemCallLib{
		
		enum Enum {
			phycicalDamage = 1,
			burnMana,
			hitTarget,
			consumeMana,
			consume,
			channel,
			cast,
			checkrange,
			getObjInRange,
			gainBuff,
			updateBuff,
			loseBuff,
			sleep,
		};
		
		extern map<uint32_t, systemCallBack_t> lib;
	}
	namespace systemCallBackLib {
		
		enum Enum {
			__hit__ = 1,
			__cast__,
			__activate_target__,
			__gain_buff__,
			__lose_buff__,
			__tick_buff__,
			__on_gain_buff__,
			__on_lose_buff__,
			__on_heal__,
			__on_hit__,
			__on_damage__,
			__on_begin_cast__,
			__on_cast__
					
		};
		
		extern map<uint32_t, systemCallBackEntry_t> lib;
	}
	namespace systemEnvLib {
	
		enum Enum {
			wkl_powerId = 1,
			wkl_level,
			wkl_target,
			wkl_missChance,
			wkl_critChance,
			wkl_buffId,
			wkl_buffTickCounter,
			wkl_buffTickTime,
		};	
		
		extern map<uint32_t, systemCallBack_t> lib;
	}
	
	namespace systemConst {
	
		enum Enum {
			wkl_c_mana = 1,
			wkl_c_hp = 2
		};	
		
		extern map<uint32_t, systemConst_t> systemConst;
		extern map<uint32_t, Variable> systemConstValues;
	}	
	
	//void initSystemCallLib(){
	//	systemCallLib["doPhycicalDamage"] = 1;
	//}
};
#endif	/* SYSTEMCALLLIB_H */

