/* 
 * File:   SComponent.h
 * Author: karsten
 *
 * Created on 13. oktober 2014, 23:09
 */

#ifndef SCOMPONENT_H
#define	SCOMPONENT_H
#include "../enums.h"
#include "../Signals/Signal.h"
#include "../Messages/Message.h"
#include "../SObj.h"
#include <pqxx/pqxx>
class SComponent {
	friend SObj;
public:
	
	SComponent(COMPID::Enum type){
		_obj = NULL;
		_type = type;
	}
	SComponent(SObj* obj, COMPID::Enum type){
		_type = type;
		obj->addComponent(this);
	}
	
	SComponent* loadComponent(COMPID::Enum type, pqxx::connection& con){
	
	
	}
	
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data) {};
	void virtual acceptMessage(MESSAGE::Enum type, Message* data) {};
	
	void sendMessage(MESSAGE::Enum type, Message* data){
	
	
	}
	void virtual dbInit(){}
	void virtual dbSave(){}
	void virtual dbLoad(){}
	
	virtual ~SComponent(){}
protected:
	SObj* _obj;
	COMPID::Enum _type;	
private:
	void setObj(SObj* obj){
		if(_obj)
			cerr<<"ERROR component obj change not allowed"<<endl;
		_obj = obj;
		init();
	}
	void virtual init() = 0;
};


#endif	/* SCOMPONENT_H */

