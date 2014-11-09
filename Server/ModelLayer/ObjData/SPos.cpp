
#include "SPos.h"

SPos::SPos(int32_t x, int32_t y, int32_t z, uint16_t d) {
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

