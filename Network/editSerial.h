
#ifndef EDITSERIAL_H
#define	EDITSERIAL_H

#include "../GShare/GGlobals.h"

typedef uint16_t inputOP;
typedef uint16_t inputLen;

#define SERIAL_EDIT_MAX_LEN 512

namespace SerialEdit{
	namespace op {
		enum Enum{
			Invalid = 0,
			CreateObj= 1,
			DeleteObj= 2,
		};
	};

struct header{
	inputOP _type;
	inputLen _size;
}__attribute__((__packed__));


struct DeleteObj : public header{
    OBJID _id;
};

}

#endif	/* EDITSERIAL_H */


