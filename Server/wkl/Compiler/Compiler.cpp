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


uint32_t Compiler::compile(Program* program, ostream& outAsm){
	cerr<<"execute Compiler"<<endl;
	
	for (auto& it : systemCallLib::lib) {
		vTableEntry temp(it.second, it.first, varloc::abs, 0, it.first);
		_vtable.push_back(temp);	
	}

	for (auto& it : systemEnvLib::lib) {
		vTableEntry temp(it.second, it.first, varloc::env, 0, 0);
		_vtable.push_back(temp);
	}
	
	
	stringstream s(_programPath);
	s<<_programPath;
	cerr<<s.str()<<endl;
	
	
	stringstream input;
	if(_fromFile){
		ifstream file(s.str().c_str());
		while (!file.eof()){
			int c = file.get();
			cerr<<"c="<<c<<endl;
			if(c>=0 && c != 4)
				input.put(c);
		}
	}else{
		cerr<<_programSrc<<endl;
		input.write(_programSrc.c_str(),_programSrc.size());
		//input.setstate(ios_base::eofbit);
	}
	
	Lexer lexer(&input);
	
	Node* result = parse(&lexer);

	
	s.str("");
	s.clear();
	s<<_programPath<<".dot";
	cerr<<s.str()<<endl;
	//ofstream dotfile(s.str().c_str());
	//DotBuilder dot(dotfile);
	//dot.visit(result);
	//result->accept(&dot);
	//dot.finalise();
	//dotfile.flush();
	
	
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
    _scopeRef.push_back(0);
    if(node->condition()){
        node->condition()->accept(this);
    }
	_scopeRef.pop_back();
    uint32_t h = emitCondJumpToRef();
	emitPopStackIgnore(1);
    if(node->elseBlock()){
        _scopeRef.push_back(0);
        node->elseBlock()->accept(this);
		emitPopStack(_scopeRef.back());
        _scopeRef.pop_back();
        

    }
    uint32_t g = emitJumpToRef();
    program().at(h) = program().size();
	emitPopStackIgnore(1);
    if(node->ifBlock()){
        _scopeRef.push_back(0);
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
			node->block()->accept(this);
			emitPopStack(_scopeRef.back());
			_scopeRef.pop_back();
			emitReturn();
		}
	}
	if(node->next())
		node->next()->accept(this);
	
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
    if(!node->expr()){
        emitPushStack(0x00, 1);
    }
    vTableEntry v(node->variable()->name(),_scopeRef.back(), varloc::rel);
    _vtable.push_back(v);
    if(node->next())
        node->next()->accept(this);
}

void Compiler::visit(NodeIndeclStmt* node){
    
	//TODO check that variable is in env
	
    if(node->next())
        node->next()->accept(this);
}

void Compiler::visit(NodeParam* node){
	_scopeRef.back()+=1;
	vTableEntry v(node->id()->name(),_scopeRef.back(), varloc::rel);
    _vtable.push_back(v);
	cerr<<"paramnode "<<node->id()->name() <<" ref "<< _scopeRef.back()<<endl;
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
	
	emitPushLocToTopStack(ve->pos,1, ve->rel);


}

void Compiler::visit(NodeArg* node){
	node->expr()->accept(this);
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
		node->args()->accept(this);
		emitSysCall(s, ve->systemCall);
		
		emitPopStack(_scopeRef.back() - oldref);
		_scopeRef.pop_back();
		
	}else{
		emitPushStack(0x00FF,1);
		uint32_t h = emitPushRPC();
		
		_scopeRef.push_back(_scopeRef.back());
		if(node->args())
			node->args()->accept(this);
		_scopeRef.pop_back();
		emitCall(ve->name);
		program().at(h) = program().size();
		//emitPopStack(_scopeRef.back());
		
	}
		
	
}



Compiler::~Compiler() {
}
