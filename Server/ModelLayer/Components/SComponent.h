/* 
 * File:   SComponent.h
 * Author: karsten
 *
 * Created on 13. oktober 2014, 23:09
 */

#ifndef SCOMPONENT_H
#define	SCOMPONENT_H

class SComponent {
public:
	SComponent();
	void acceptSignal(SIGNAL::Enum type, Signal* data){}
	virtual ~SComponent();
private:


};


#endif	/* SCOMPONENT_H */

