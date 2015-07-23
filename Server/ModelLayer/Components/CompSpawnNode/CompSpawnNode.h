
#ifndef COMPSPAWNNODE_H
#define	COMPSPAWNNODE_H

#include "../SComponent.h"
struct SerialCompSpawnNode;
class CompSpawnNode : public SComponent  {
public:
	CompSpawnNode();
	CompSpawnNode(TIME spawnTime, OBJTPID spwanTemplate, OBJID spawn);
	CompSpawnNode(const CompSpawnNode& orig);
	CompSpawnNode(SObj* obj, OBJID id, pqxx::connection& con);	
	CompSpawnNode(SerialCompSpawnNode* sc, int32_t* size);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompSpawnNode();
private:
	virtual void init();
	void spawn(TIME spawnTime);
	TIME _spawnTime;
	OBJTPID _spawnTemplate;
	OBJID _spawn;
	
	//NONSERIAL
	bool __initDone;
};

struct SerialCompSpawnNode : SerialObjComp{
	TIME _spawnTime;
	OBJTPID _spawnTemplate;
	OBJID _spawn;
};

#endif	/* COMPSPAWNNODE_H */

