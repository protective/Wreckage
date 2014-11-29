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
				SerialComp = 9,
				SerialObjEnter = 10,
				SerialObjExit = 11,
				
				SerialCmdCreateObj = 100,
			
	};
}

struct SerialData{
	
	SerialData(SerialType::Enum _type, uint32_t _size){
		this->_type = _type;
		this->_size = _size;
	}
	
	/** Type identifier of the serialized object
	  */
	SerialType::Enum _type;

	/** Size of the buffer used for serialization of this object
	  */
	uint32_t _size;
}__attribute__((__packed__));


struct SerialTime : public SerialData{
    uint32_t time;
    uint32_t local;
};

struct SerialReqJoin : public SerialData{ 
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

struct SerialAddComponent : public SerialData{
    uint32_t _unitId;
    uint32_t _compid;
};

struct SerialInput : public SerialData{
    OBJID _unitId;
};

struct SerialCmdCreateObj : public SerialData{
    OBJID _unitId;
};

#endif	/* SERIALIZE_H */

