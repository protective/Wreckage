/* 
 * File:   NodeExpr.h
 * Author: karsten
 *
 * Created on 4. september 2014, 23:31
 */

#ifndef SORDERNODEEXPR_H
#define	SORDERNODEEXPR_H

#include "Node.h"
#include "../Utils/SourcePosition.h"
#include "../Types/TypeDenoter.h"
class NodeExpr : public Node {
public:
	NodeExpr(SourcePosition pos) : _pos(pos){
	}
    	/** Get the position of the expression */
	SourcePosition pos(){
		return _pos;
	}
    
	virtual TypeDenoter* getType(){return NULL;}
	//virtual void setType(TypeDenoter* type){_type = type;}	
	virtual void accept(Visitor* v);
	virtual ~NodeExpr(){}
private:
	SourcePosition _pos;
	//TypeDenoter* _type;
};

#endif	/* SORDERNODEEXPR_H */

