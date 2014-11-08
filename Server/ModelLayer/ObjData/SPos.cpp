
#include "SPos.h"

SPos::SPos(uint32_t x, uint32_t y, uint32_t z, uint16_t d) {
	_x = x;
	_y = y;
	_z = z;
	_d = d;
}

SPos::SPos(const SPos& orig) {
	_x = orig._x;
	_y = orig._y;
	_z = orig._z;
	_d = orig._d;
}

SPos::~SPos() {
}

