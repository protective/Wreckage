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

	typedef string systemCallBackEntry_t;

	typedef string systemEnvEntry_t;
	namespace systemCallLib{
		
		enum Enum {
			phycicalDamage = 1,
			burnMana,
			hitTarget,
			consume,
			channel,
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
			__tick_buff__
					
		};
		
		extern map<uint32_t, systemCallBackEntry_t> lib;
	}
	namespace systemEnvLib {
	
		enum Enum {
			wkl_level = 1,
			wkl_target,
			wkl_missChance,
			wkl_critChance,
			wkl_buffId,
			wkl_buffTickCounter,
			wkl_buffTickTime,
		};	
		
		extern map<uint32_t, systemCallBack_t> lib;
	}
	//void initSystemCallLib(){
	//	systemCallLib["doPhycicalDamage"] = 1;
	//}
};
#endif	/* SYSTEMCALLLIB_H */

