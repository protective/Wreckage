/* 
 * File:   enums.h
 * Author: karsten
 *
 * Created on 13. oktober 2014, 23:37
 */

#ifndef ENUMS_H
#define	ENUMS_H
namespace model {
	namespace COMPID {
		enum Enum {
			invalid = 0,
			killable = 1,
			caster = 2,
			targetable = 3,

		};
	}
	namespace SIGNAL {
		enum Enum {
			invalid = 0,
			castTarget = 1,
			castPos = 2,
			takeDamage = 3,
			loseMana = 4,
		};
	}
}
#endif	/* ENUMS_H */

