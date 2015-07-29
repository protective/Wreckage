
#ifndef DESTINY_H
#define	DESTINY_H

#include "../Messages/Message.h"
#include "../ObjData/SPos.h"

class Destiny {
public:
	Destiny();
	void message(MESSAGE::Enum type, Message* data);
	virtual ~Destiny();
private:
	map<OBJID, SPos> _index;
};

#endif	/* DESTINY_H */

