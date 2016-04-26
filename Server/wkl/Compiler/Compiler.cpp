#include "Compiler.h"
#include "systemCallLib.h"
#include "../Lexer.h"
#include "../Utils/DotBuilder.h"
#include "ProgramPrinter.h"
#include "../Program.h"

Compiler::Compiler(string programPath, bool fromFile) {
	_programPath = programPath;
	_inStatic = true;
	_fromFile = fromFile;
	if(!_fromFile)
		_programSrc = programPath;
	_step = Step::allocation;
}

Compiler::Compiler(string programScr) {
	_programSrc = programScr;
	_inStatic = true;
	_step = Step::allocation;
	_fromFile = false;
	
}

uint32_t Compiler::compile(Program* program, ostream& outAsm ){
	this->compile(program, outAsm, NULL);
}

uint32_t Compiler::compile(Program* program, ostream& outAsm , ostream* outDot){
	
	for (auto& it : systemCallLib::lib) {
		vTableEntry temp(it.second, it.first, varloc::abs, 0, it.first);
		_vtable.push_back(temp);	
	}
	
	for (auto& it : systemConst::systemConst) {
		vTableEntry temp(it.second, it.first, varloc::con, 0, it.first);
		_vtable.push_back(temp);	
	}
	_freeEnvPos = 0;
	for (auto& it : systemEnvLib::lib) {
		vTableEntry temp(it.second, it.first, varloc::env, 0, 0);
		if(it.first >= _freeEnvPos)
			_freeEnvPos = it.first + 1;
		_vtable.push_back(temp);
	}
	
	
	stringstream s(_programPath);
	s<<_programPath;
	//cerr<<s.str()<<endl;
	
	
	stringstream input;
	if(_fromFile){
		ifstream file(s.str().c_str());
		while (!file.eof()){
			int c = file.get();
			if(c>=0 && c != 4)
				input.put(c);
		}
	}else{
		input.write(_programSrc.c_str(),_programSrc.size());
		//input.setstate(ios_base::eofbit);
	}
	
	Lexer lexer(&input);
	
	Node* result = parse(&lexer);

	

	if(outDot){
		DotBuilder dot(*outDot);
		dot.visit(result);
		result->accept(&dot);
		dot.finalise();
		(*outDot).flush();
	}
	
	//TypeChecker typecheck;
	
	//result->accept(&typecheck);
	s.str("");
	s.clear();

	_scopeRef.push_back(1);
	result->accept(this);
	_step = Step::main;
	//emitPushStack(0xAAAA,1);
	//emitPushPC();
	//emitCall("main");
	emitEOP();	
	result->accept(this);
	this->finalize();
	
	s.str("");
	s.clear();
	s<<_programPath<<".asm";	
	//ofstream asmPrinter(s.str().c_str());
	wkl::printProgram(outAsm,_program, _interruptHandlers);
	program->_interruptHandlers = _interruptHandlers;
	program->_program = _program;
	//_processor->getPrograms()[_programPath] = p;
	return 1;
}
vTableEntry* Compiler::vtableFind(string id){
    for(list<vTableEntry>::reverse_iterator it = _vtable.rbegin(); it != _vtable.rend(); it++){
        if((*it).name == id){
            return &(*it);
        }
    }
	cerr<<"vtable not found looking for ("<<id<<")"<<endl;
	return NULL;
}

void Compiler::finalize(){
	for(map<uint32_t, string>::iterator it = _lables.begin(); it != _lables.end(); it++){
		if(vtableFind(it->second))
			_program[it->first] = vtableFind(it->second)->pos;
		else
			cerr<<"undeclared function>>"<<it->second<<endl;
	}
}

void Compiler::visit(NodeIfStmt* node){
    
    /*
     * 
     *   eval E
     *   conjump <h>
	 *	 pop E
     *   jump <g>
     *-h
	 *	 pop E
     *   ifblock   
     *   pop
     *-g 
     * 
     *   eval E
     *   conjump <h>
     *   elseblock
     *   pop
     *   jump <g>
     *-h
     *   ifblock   
     *   pop
     *-g
     */
    _scopeRef.push_back(_scopeRef.back());
    if(node->condition()){
        node->condition()->accept(this);
    }
	_scopeRef.pop_back();
    uint32_t h = emitCondJumpToRef();
	emitPopStackIgnore(1);
    if(node->elseBlock()){
        _scopeRef.push_back(_scopeRef.back());
        node->elseBlock()->accept(this);
		emitPopStack(_scopeRef.back());
        _scopeRef.pop_back();
        

    }
    uint32_t g = emitJumpToRef();
    program().at(h) = program().size();
	emitPopStackIgnore(1);
    if(node->ifBlock()){
        _scopeRef.push_back(_scopeRef.back());
		node->ifBlock()->accept(this);
		emitPopStack(_scopeRef.back());
        _scopeRef.pop_back();

    }
	program().at(g) = program().size();
	if(node->next()){
		node->next()->accept(this);
	}
}


void Compiler::visit(NodeWhileStmt* node){
   /*
     *   jump <g>
     *-h
	 *   pop E
     *   block   
     *   pop
     *-g 
     *   eval E
     *   conjump <h>
	 *	 pop E
     */
    
	uint32_t g = emitJumpToRef();
	uint32_t h = program().size();
	emitPopStackIgnore(1);
	if(node->body()){
		_scopeRef.push_back(_scopeRef.back());
		 node->body()->accept(this);
		uint32_t oldRef = _scopeRef.back();
		_scopeRef.pop_back();
		emitPopStack(oldRef - _scopeRef.back());	
    }
	program().at(g) = program().size();
	_scopeRef.push_back(0);
	if(node->condition()){
        node->condition()->accept(this);
    }
	_scopeRef.pop_back();
    emitCondJumpToRef(h);
	emitPopStackIgnore(1);
	if(node->next()){
		node->next()->accept(this);
	}
}

void Compiler::visit(NodeForEachStmt* node){
   /*
     *   eval E
	 *   Push uindex E
	 *   Push i = 0
	 *   jump <g>
     *-h
	 *   dec var = E[i]
     *   block   
     *   pop var
	 *   add 1
     *-g 
     *   conjump2topNeq <h>
     *   pop E
	 *   pop uindex E
	 *   pop i
     */
	uint32_t tmp1 = _scopeRef.back();
	_scopeRef.push_back(_scopeRef.back());
	/*Eval E **********************/
	uint32_t E;
	if(node->expr()){

		 node->expr()->accept(this);
		 E = _scopeRef.back();
    }else 
		return; //ERROR
	/******************************/
	/*push uindex E ***************/
	emitPushUIndx(0);
	/*push i = 0 ******************/
	emitPushStack(0x00, 1);
	/*jump <g> ********************/
	uint32_t g = emitJumpToRef();
	/*-h ***********/ 
	uint32_t h = program().size();
	/*dec var = E[i] (new scope)***/
	uint32_t tmp2 = _scopeRef.back();
	_scopeRef.push_back(_scopeRef.back());
    emitPushStack(0x00, 1);
	emitLocRIndexToTopStack(E, varloc::rel, 1);
    vTableEntry v(node->var()->name(), _scopeRef.back(), varloc::rel);
    _vtable.push_back(v);
	/*Block*********************/
	if(node->block()){
		node->block()->accept(this);
    }
	uint32_t oldRef = _scopeRef.back();
	_scopeRef.pop_back();
	emitPopStackIgnore(oldRef - _scopeRef.back());	
	/*TODO Add one to index*********************/
	emitPushStack(0x01,1);
	emitBOAddPop();
	/*-g ***********/
	program().at(g) = program().size();
	/*conjump2topNeq*********************/
	emitCond2NEQJumpToRef(h);
	
	/*pop E uindex E and i*********************/
	uint32_t oldRef2 = _scopeRef.back();
	_scopeRef.pop_back();
	emitPopStackIgnore(oldRef2 - _scopeRef.back());
	
	/*DONE*********************/
	if(node->next()){
		node->next()->accept(this);
	}
}

void Compiler::visit(NodeParam* node){
	_scopeRef.back()+=1;
	vTableEntry v(node->id()->name(),_scopeRef.back(), varloc::rel);
    _vtable.push_back(v);
	cerr<<"paramnode "<<node->id()->name() <<" ref "<< _scopeRef.back()<<endl;
	if(node->next())
        node->next()->accept(this);
}


void Compiler::visit(NodeMethod* node){
	if(_step == Step::main){
		
		if(node->variable()->name() == "main"){
			_mainFunctionPC = program().size();
		}
		vTableEntry v(node->variable()->name(),program().size(),varloc::abs);
		_vtable.push_back(v);
		
		for (auto& it : systemCallBackLib::lib) {
			if (it.second == node->variable()->name()){
				cerr<<"found interrupt handler"<<endl;
				_interruptHandlers[it.first] = program().size();
				emitFUN(it.first);
				break;
			}			
		}
		
		if(node->block()){
			_scopeRef.push_back(0);
			if(node->param())
				node->param()->accept(this);
			//pc ontop of 
			_scopeRef.back()+=1;
			
			uint32_t old = _scopeRef.back();

			node->block()->accept(this);
			emitPopStack(_scopeRef.back() - old);
			_scopeRef.pop_back();
			emitReturn();
		}
	}
	if(node->next())
		node->next()->accept(this);
	
}

void Compiler::visit(NodeCallExpr* node){
	vTableEntry* ve = NULL;
	ve = this->vtableFind(node->callee()->var()->id()->name());
	if(!ve){
        return;
    }
	if(ve->systemCall){
		uint32_t s = _scopeRef.back();
		emitPushStack(0xEEEE,1);
		uint32_t oldref = _scopeRef.back();
		_scopeRef.push_back(_scopeRef.back());

		if(node->args())
			node->args()->accept(this);

		emitSysCall(s, ve->systemCall);
		
		emitPopStack(_scopeRef.back() - oldref);
		_scopeRef.pop_back();
		
	}else{
		emitPushStack(0x00FF,1);
		
		_scopeRef.push_back(_scopeRef.back());
		if(node->args())
			node->args()->accept(this);
		
		uint32_t h = emitPushRPC();
		
		emitCall(ve->name);
		program().at(h) = program().size();
		emitPopStack(_scopeRef.back());
		_scopeRef.pop_back();
	}
}

 void Compiler::visit(NodeVardecTop* node){
	if(_step == Step::allocation){
		_inStatic = true;
		if(node->expr()){
			node->expr()->accept(this);
		}
		if(!node->expr()){
			emitPushStack(0x00, 1);
		}
		vTableEntry v(node->variable()->name(),_scopeRef.back()-1,varloc::abs);
		_vtable.push_back(v);
	}
	if(node->next())
		node->next()->accept(this);
	
}

void Compiler::visit(NodeVardeclStmt* node){
    
    if(node->expr()){
        node->expr()->accept(this);
    }

	vTableEntry* ve = NULL;
    ve = this->vtableFind(node->variable()->name());
    if(ve){
		 if(node->expr())
			emitTopStackToLoc(ve->pos, ve->rel, 1);
    }else{
		vTableEntry v(node->variable()->name(),_scopeRef.back(), varloc::rel);
		_vtable.push_back(v);
		if(!node->expr()){
			emitPushStack(0x00, 1);
		}
	}

    if(node->next())
        node->next()->accept(this);
}

void Compiler::visit(NodeIndeclStmt* node){
    
	//TODO check that variable is in env
	
    if(node->next())
        node->next()->accept(this);
}

void Compiler::visit(NodeOutdeclStmt* node){
    
	//TODO check that variable is in env
	if(node->expr()){
		node->expr()->accept(this);
		vTableEntry* ve = NULL;
		ve = this->vtableFind(node->variable()->name());
		if(!ve){
			vTableEntry v(node->variable()->name(), _freeEnvPos++, varloc::env);
			_vtable.push_back(v);
			ve = this->vtableFind(node->variable()->name());
		}
		emitTopStackToEnv(ve->pos);
		emitPopStack(1);
	}
    if(node->next())
        node->next()->accept(this);
}


void Compiler::visit(NodeExprStmt* node){

    if(node->expr()){

        node->expr()->accept(this);
    }
	
    emitPopStack(1);
    
    if(node->next())
        node->next()->accept(this);
}


void Compiler::visit(NodeAssignExpr* node){
    
    node->value()->accept(this);
    
    vTableEntry* ve = NULL;
    ve = this->vtableFind(node->assignee()->id()->name());
    if(!ve){
        return;
    }
    emitTopStackToLoc(ve->pos, ve->rel, 1);

}

void Compiler::visit(NodeTupAssignStmt* node){
    
    
    
    vTableEntry* ve = NULL;
	NodeTupDref* tup = node->assignee();
	while(tup){
		ve = this->vtableFind(tup->var()->id()->name());
		if(!ve){
			emitPushStack(0x00, 1);
			vTableEntry v(tup->var()->id()->name(),_scopeRef.back(), varloc::rel);
			_vtable.push_back(v);
		}
		tup = tup->next();
	}
	
	node->expr()->accept(this);

	tup = node->assignee();
	int i = 0;
	while(tup){
		ve = this->vtableFind(tup->var()->id()->name());
		if(ve){
			emitTopStackIndexToLoc(ve->pos, ve->rel, i);
		}else{ //variable in scope
			return;
		}
		i++;
		tup = tup->next();
	}
	
	emitPopStack(1);
	
	if(node->next())
        node->next()->accept(this);

}

void Compiler::visit(NodeLiteralExpr* node){
    //not much to do
    node->literal()->accept(this);
};

void Compiler::visit(IntegerLiteral* node){
    emitPushStack(node->value(),1);
}

void Compiler::visit(BinaryOperatorExpr* node){
	node->firstOperand()->accept(this);
	node->secondOperand()->accept(this);
	switch(node->appliedOperator()->token()){
		case TOKEN_plus:{
			emitBOAddPop();
			break;
		}
		case TOKEN_minus:{
			emitBOMinusPop();
			break;
		}
		case TOKEN_eq:{
			emitBOEQPop();
			break;
		}
		case TOKEN_neq:{
			emitBONEQPop();
			break;
		}
	}
}

void Compiler::visit(NodeVariableExpr* node){

	node->var()->accept(this);
}

void Compiler::visit(NodeVariable* node){

    vTableEntry* ve = NULL;
    ve = this->vtableFind(node->id()->name());
    if(!ve){
        cerr<<"ERROR visit NodeVariable"<<endl;
        return;
    }

	emitPushLocToTopStack(ve->pos, ve->rel);

}

void Compiler::visit(NodeArg* node){
	node->expr()->accept(this);
	if(node->next())
		node->next()->accept(this);
}

void Compiler::visit(NodeDictExpr* node) {
	uint32_t size = 0;
	NodePair* tmpnext = node->pair();
	while (tmpnext){
		size++;
		tmpnext = tmpnext->next();
	}
	
	emitPushStack(0,1);
	if(node->pair())
		node->pair()->accept(this);

	emitMvMapFromTopStack(size);
	emitPopStack(size * 2);
}

void Compiler::visit(NodePair* node) {
	node->exprKey()->accept(this);
	node->exprVal()->accept(this);

	if(node->next())
		node->next()->accept(this);
}



Compiler::~Compiler() {
}
