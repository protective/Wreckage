/* 
 * File:   Serialize.h
 * Author: karsten
 *
 * Created on 23. april 2011, 11:17
 */

#ifndef SERIALIZE_H
#define	SERIALIZE_H

#include "../GShare/GGlobals.h"
namespace SerialType{
	/** Identifiers for each serializable type
	  */
	enum Enum{
		/** Dummy entry for serialization of incomplete types
		  */
		Invalid = 0,
                SerialTime= 1,
                SerialReqJoin = 5,
				SerialAddComponent = 6,
				SerialInput = 7,
	};
}

struct SerialData{
	/** Type identifier of the serialized object
	  */
	SerialType::Enum _type;

	/** Size of the buffer used for serialization of this object
	  */
	uint32_t _size;
}__attribute__((__packed__));


struct SerialTime : public SerialData{ //id = 1
    uint32_t time;
    uint32_t local;
};

struct SerialReqJoin : public SerialData{ //id = 5
    uint32_t _unitId;
    uint32_t _pass;
};

struct SerialCompSpawnNode{
	TIME _spawnTime;
	OBJTPID _spawnTemplate;
	OBJID _spawn;
};

struct SerialCompReSpawnable{
	OBJID _spawner;
};

struct SerialAddComponent : public SerialData{ //id = 5
    uint32_t _unitId;
    uint32_t _compid;
};

struct SerialInput : public SerialData{ //id = 5
    OBJID _unitId;
};

#endif	/* SERIALIZE_H */

