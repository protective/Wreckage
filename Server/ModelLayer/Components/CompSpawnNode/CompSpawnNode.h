
#ifndef COMPSPAWNNODE_H
#define	COMPSPAWNNODE_H

#include "../SComponent.h"
class CompSpawnNode : public SComponent  {
public:
	CompSpawnNode();
	CompSpawnNode(TIME spawnTime, OBJTPID spwanTemplate, OBJID spawn);
	CompSpawnNode(const CompSpawnNode& orig);
	CompSpawnNode(OBJID id, pqxx::connection& con);	
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	virtual ~CompSpawnNode();
private:
	virtual void init();
	TIME _spawnTime;
	OBJTPID _spawnTemplate;
	OBJID _spawn;
	
	//NONSERIAL
	TIME __timeout;
};

#endif	/* COMPSPAWNNODE_H */

