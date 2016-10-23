
#ifndef INPUTSERIAL_H
#define	INPUTSERIAL_H

#include "../GShare/GGlobals.h"

typedef uint16_t inputOP;
typedef uint16_t inputLen;

#define SERIAL_INPUT_MAX_LEN 512
namespace SERIALINPUT{
	/** Identifiers for each serializable type
	  */
	enum Enum{
		/** Dummy entry for serialization of incomplete types
		  */
		Invalid = 0,
        SerialInputCastPower= 1,
		SerialIndputSetCompValue = 2,
        SerialIndputAddCompValue = 3,
        SerialIndputRemoveCompValue = 4
	};
}

struct SerialInputPayload{

	inputOP _type;
	inputLen _size;
}__attribute__((__packed__));

struct SerialInputCastPower : public SerialInputPayload{ //id = 1
    OBJID _power;
	OBJID _target;
}__attribute__((__packed__));

struct SerialIndputSetCompValue : public SerialInputPayload{ //id = 2
    uint32_t _compId;
}__attribute__((__packed__));

struct SerialIndputAddCompValue : public SerialInputPayload{ //id = 3
    uint32_t _compId;
}__attribute__((__packed__));

struct SerialIndputRemoveCompValue : public SerialInputPayload{ //id = 4
    uint32_t _compId;
}__attribute__((__packed__));

#endif	/* SERIALIZE_H */

