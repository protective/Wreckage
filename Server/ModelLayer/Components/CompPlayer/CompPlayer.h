
#ifndef COMPPLAYER_H
#define	COMPPLAYER_H

#include "../SComponent.h"

class CompPlayer  : public SComponent {
public:
	CompPlayer();
	CompPlayer(const CompPlayer& orig);
	CompPlayer(SObj* obj, OBJID id, pqxx::connection& con);
	CompPlayer* clone(){return new CompPlayer( *this );}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void sendFull(uint32_t clientId);
	
	void virtual dbInit();
	void static dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPlayer();
private:
	virtual void init();

};

#endif	/* COMPPLAYER_H */

