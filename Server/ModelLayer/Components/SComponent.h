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
#include "../SObj.h"

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
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data) = 0;
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

