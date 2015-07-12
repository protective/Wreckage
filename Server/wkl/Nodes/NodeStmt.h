/* 
 * File:   NodeStmt.h
 * Author: karsten
 *
 * Created on 4. september 2014, 23:21
 */

#ifndef SORDERNODESTMT_H
#define	SORDERNODESTMT_H

#include "Node.h"


class NodeStmt : public Node {
public:
	NodeStmt(NodeStmt* next){
		_next = next;
	}

	virtual void accept(Visitor* v);
	void setNext(NodeStmt* next){
		_next = next;
	}
	
	NodeStmt* next(){return _next;}
	
	virtual ~NodeStmt(){}
protected:
	NodeStmt* _next;
};

#endif	/* SORDERNODESTMT_H */

