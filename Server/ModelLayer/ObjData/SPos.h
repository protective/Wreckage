
#ifndef SPOS_H
#define	SPOS_H
#include "../../BInclude.h"

struct SerialObjDataPos;
class SPos {
public:
	SPos(){}
	SPos(int32_t x, int32_t y, int32_t z, uint16_t d);
	
	int32_t x(){return _x;}
	int32_t y(){return _y;}
	int32_t z(){return _z;}
	uint16_t d(){return _d;}
	
	SPos(const SPos& orig);
	SPos(SerialObjDataPos* sp);
	virtual ~SPos();
private:
	int32_t _x;
	int32_t _y;
	int32_t _z;
	uint16_t _d;
};

#endif	/* SPOS_H */

