/* 
 * File:   stack.h
 * Author: karsten
 *
 * Created on 12. juli 2015, 00:28
 */

#ifndef STACK_H
#define	STACK_H
#include <vector>
#include "Variable.h"
namespace wkl{
class stack {
public:
	stack();
	stack(const stack& orig);
	
	void push_back(Variable* v) {_stack.push_back(v);}
	void pop_back() {
		delete _stack.back();
		_stack.pop_back();}
	virtual ~stack();
private:
	vector<Variable*> _stack;
};
}
#endif	/* STACK_H */

