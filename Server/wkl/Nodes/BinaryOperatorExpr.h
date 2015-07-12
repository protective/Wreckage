/* 
 * File:   BinaryOperatorExpr.h
 * Author: karsten
 *
 * Created on 12. september 2014, 19:42
 */

#ifndef SORDERBINARYOPERATOREXPR_H
#define	SORDERBINARYOPERATOREXPR_H
#include "NodeExpr.h"
#include "../Terminals/Terminal.h"
class BinaryOperatorExpr : public NodeExpr{
public:
	BinaryOperatorExpr(NodeExpr* firstOperand, Terminal* appliedOperator, NodeExpr* secondOperand) : NodeExpr(appliedOperator->pos()){
		this->_firstOperand = firstOperand;
		this->_secondOperand = secondOperand;
		this->_appliedOperator = appliedOperator;
	}
	
	virtual TypeDenoter* getType(){return _firstOperand->getType();}

	/** Get the first operand */
	NodeExpr* firstOperand(){
		return _firstOperand;
	}
	/** Get the second operand */
	NodeExpr* secondOperand(){
		return _secondOperand;
	}
	/** Get the operator applied */
	Terminal* appliedOperator(){
		return _appliedOperator;
	}
	void accept(Visitor* v);
private:
	NodeExpr* _firstOperand;
	NodeExpr* _secondOperand;
	Terminal* _appliedOperator;
};

#endif	/* SORDERBINARYOPERATOREXPR_H */

