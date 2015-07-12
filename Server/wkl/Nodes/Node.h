/* 
 * File:   Node.h
 * Author: karsten
 *
 * Created on 3. september 2014, 22:20
 */

#ifndef SORDERNODE_H
#define	SORDERNODE_H



class NodeStmt;
class Visitor;

class Node {
public:
	Node(){}
	virtual void accept(Visitor* v);
	//virtual NodeStmt* getNodeStmt(){return NULL;}
	virtual ~Node(){}
private:

};

#endif	/* SORDERNODE_H */

