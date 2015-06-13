
#ifndef OBJSERIAL_H
#define	OBJSERIAL_H

#include "../Network/Serialize.h"

#include "../ModelLayer/SObj.h"

struct SerialDataKeyVal{
    uint32_t _key;
	int32_t _val;
};

struct SerialObjAll : public SerialData{
	SerialObjAll(SObj* obj, uint32_t size):
	SerialData(SerialType::SerialObjAll, size){
		_id = obj->getId();
		_xitems = obj->getDataSize();
	}
	static uint32_t getMallocSize(SObj* obj){return
			sizeof(SerialObjAll)
			+ sizeof(int32_t) * obj->getDataSize() * 2;}
	
	static uint32_t pack(char* dest, SObj* obj,uint32_t size){
		
		SerialObjAll s(obj,size);
		memcpy(dest,&s,sizeof(SerialObjAll));
		dest+= sizeof(SerialObjAll);
		uint32_t* key = (uint32_t*)dest;
		int i = 0;
		for (map<OBJDATA::Enum, int32_t>::iterator it = obj->getData().begin(); it != obj->getData().end(); it++){
			key[i++] = (uint32_t)it->first;
			key[i++] = (int32_t)it->second;
		}
	}

	OBJID _id;
    uint32_t _xitems;
}__attribute__((__packed__));


#endif	/* OBJSERIAL_H */

