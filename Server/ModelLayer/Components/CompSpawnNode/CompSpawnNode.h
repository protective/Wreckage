
#ifndef COMPSPAWNNODE_H
#define	COMPSPAWNNODE_H

#include "../SComponent.h"
class CompSpawnNode : public SComponent  {
public:
	CompSpawnNode();
	CompSpawnNode(const CompSpawnNode& orig);
	CompSpawnNode(pqxx::connection& con);
	
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data) {};
	
	void virtual init();
	void virtual dbInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	virtual ~CompSpawnNode();
private:
	TIME _spawnTime;
	OBJTPID _spwanTemplate;
	OBJID _spawn;
};

#endif	/* COMPSPAWNNODE_H */

