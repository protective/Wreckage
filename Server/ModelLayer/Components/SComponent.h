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

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data) {};
	void virtual acceptMessage(MESSAGE::Enum type, Message* data) {};
	
	void sendMessage(MESSAGE::Enum type, Message* data){

	}
	
	bool isInit(){return (_flags & COMPFLAGINIT) ? true : false;}
	void virtual dbTableInit(){}
	void virtual dbSave(){}
	void virtual dbLoad(){}
	COMPID::Enum getType(){return _type;}
	list<OBJDATA::Enum>& getDataAccesUssage(){return _objDataAcces;}
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

