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
	
	typedef Variable (*systemCallFunc)(SObj* obj, map<uint32_t, Variable> envContext, void*);
	
	typedef struct systemCallEntry{
		uint32_t _id;
		string _name;
	}systemCallBack_t;	

	extern systemCallBack_t systemCallLib[];
	
	extern systemCallBack_t systemCallBackLib[];
	
	extern systemCallBack_t systemEnvLib[];
	//void initSystemCallLib(){
	//	systemCallLib["doPhycicalDamage"] = 1;
	//}
};
#endif	/* SYSTEMCALLLIB_H */

