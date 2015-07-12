
#ifndef NODEINDECLSTMT_H
#define	NODEINDECLSTMT_H

#include "NodeStmt.h"
#include "../Terminals/Identifier.h"

class NodeIndeclStmt : public NodeStmt {
public:
	NodeIndeclStmt(Identifier* id, NodeIndeclStmt* next):
	NodeStmt(next){
		_id = id;
	}
	Identifier* variable(){
		return this->_id;
	}

	virtual void accept(Visitor* v);
	virtual TypeDenoter* getType(){return NULL;}
	virtual void setType(TypeDenoter* type){}
	virtual ~NodeIndeclStmt(){}
private:
	Identifier* _id;
};

#endif	/* NODEINDECLSTMT_H */

