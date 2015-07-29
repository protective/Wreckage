
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

static uint32_t rangePos(SPos& pos1, SPos& pos2){
	int32_t p1x = pos1.x()/100;
	int32_t p2x = pos2.x()/100;
	int32_t p1y = pos1.y()/100;
	int32_t p2y = pos2.y()/100;

	return sqrt(((p1x - p2x)*(p1x - p2x)) + ((p1y - p2y)*(p1y - p2y)));

}

struct SerialPOS {
	int32_t _x;
	int32_t _y;
	int32_t _z;
	uint16_t _d;
};

#endif	/* SPOS_H */

