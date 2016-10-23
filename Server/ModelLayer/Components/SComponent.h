/* 
 * File:   SComponent.h
 * Author: karsten
 *
 * Created on 13. oktober 2014, 23:09
 */

#ifndef SCOMPONENT_H
#define	SCOMPONENT_H
#include "../../BInclude.h"

#include "../enums.h"
#include "../Network/InputSerial.h"
#include "../Network/Serialize.h"
#include "../../NetworkLayer/NetworkControler.h"

#include "../../wkl/Compiler/systemCallLib.h"

#include "../Signals/Signal.h"

#include "../Messages/Message.h"

#include "../SObj.h"
#include <pqxx/pqxx>
#define COMPFLAGINIT  0x01
#define COMPFLAGDIRTY 0x02
class SComponent {
	friend SObj;
public:
	
	SComponent(COMPID::Enum type){
		_obj = NULL;
		_type = type;
		_flags = 0;
	}
	SComponent(const SComponent& orig){
		_obj = orig._obj;
		_type = orig._type;
		_flags= orig._flags;
				
	}
    virtual SComponent* clone() = 0;

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data) {};
	void virtual acceptMessage(MESSAGE::Enum type, Message* data) {};
	void virtual acceptNetwork(SerialInputPayload* data){}
	void sendMessage(MESSAGE::Enum type, Message* data){}
	
	bool isInit(){return (_flags & COMPFLAGINIT) ? true : false;}
	void virtual dbTableInit(){}
	void virtual dbSave(){}
	void virtual dbDelete(){}
	void virtual dbLoad(){}
	COMPID::Enum getType(){return _type;}
	uint32_t serialize(const char*){}
	SObj* getObj(){return _obj;};
	list<OBJDATA::Enum>& getDataAccesUssage(){return _objDataAcces;}
	virtual map<uint32_t, wkl::systemCallFunc> getSyscalls(){return map<uint32_t, wkl::systemCallFunc>();}
	virtual ~SComponent(){}
protected:
	void virtual dbInit(){}
	SObj* _obj;
	COMPID::Enum _type;	
	uint32_t _flags;
	list<OBJDATA::Enum> _objDataAcces;
	virtual void init(){}
private:
	
	void setObj(SObj* obj){
		if(_obj)
			cerr<<"ERROR component obj change not allowed"<<endl;
		_obj = obj;
	}

};


#endif	/* SCOMPONENT_H */

