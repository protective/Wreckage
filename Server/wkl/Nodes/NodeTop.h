/* 
 * File:   TopNode.h
 * Author: karsten
 *
 * Created on 19. september 2014, 18:34
 */

#ifndef NODETOP_H
#define	NODETOP_H

#include "Node.h"

namespace wkl {
class NodeTop : public Node{
public:
	NodeTop(NodeTop* next = NULL) {
		_next = next;
	}

	NodeTop* next(){return _next;}
	void setNext(NodeTop* next){_next = next;}
	void accept(Visitor* v);
private:
	NodeTop* _next;
};
}

#endif	/* NODETOPE_H */

