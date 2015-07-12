/* 
 * File:   Enums.h
 * Author: karsten
 *
 * Created on 23. maj 2011, 21:51
 */

#ifndef SHAREENUMS_H
#define	SHAREENUMS_H
#include <string.h>

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
	};
}


namespace SubscriptionLevel{
	enum Enum{
		lowFreq = 0,
		highFreq = 1,
		details = 2,
		Init = 3,
	};
}


#endif	/* SHAREENUMS_H */

