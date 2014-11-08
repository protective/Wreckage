
#ifndef SPOS_H
#define	SPOS_H
#include "../../BInclude.h"

class SPos {
public:
	SPos(){}
	SPos(uint32_t x, uint32_t y, uint32_t z, uint16_t d);
	SPos(const SPos& orig);
	virtual ~SPos();
private:
	uint32_t _x;
	uint32_t _y;
	uint32_t _z;
	uint16_t _d;
};

#endif	/* SPOS_H */

