#include "Compiler.h"



void Compiler::emitNOP(){
	program().push_back(inst::NOP);
}

void Compiler::emitFUN(uint32_t functionId){
	program().push_back(inst::FUN | functionId);
}

void Compiler::emitEOP(){
	program().push_back(inst::EOP);
}
void Compiler::emitPopStack(uint32_t size){
	if(size){
		//coppy top stack to the rel loc 
		program().push_back(inst::popN | size);
		this->_scopeRef.back() -= size;
	}
}
void Compiler::emitPopStackIgnore(uint32_t size){
	if(size){
		//coppy top stack to the rel loc 
		program().push_back(inst::popN | size);
	}
}

void Compiler::emitPopTopStackToLoc(uint32_t pos, uint32_t size){
    //coppy top stack to the rel loc
    program().push_back(inst::cpN_DS2 | size);
    program().push_back(relpos(pos)); //copy to
    program().push_back(0x00); //copy from
    
    //pop top of stack
    program().push_back(inst::popN | size);
    this->_scopeRef.back() -= size;
}

void Compiler::emitTopStackToLoc(uint32_t pos, bool rel, uint32_t size){

    //coppy top stack to the rel loc 
    program().push_back((rel ? inst::cpN_DS2: inst::cpN_DRS2) | size);
    program().push_back(rel ? relpos(pos): pos); //copy to
    program().push_back(0x00); //copy from
}


void Compiler::emitTopStackIndexToLoc(uint32_t pos, varloc::Enum loc, uint32_t index){

    //coppy top stack at index to the rel loc 
	inst::Enum ins;
	uint32_t toPos;
	switch (loc) {
		case varloc::abs:{
			ins = inst::cpI_RDS2;
			toPos = pos;
			break;}
		case varloc::rel:{
			ins = inst::cpI_DS2;
			toPos = relpos(pos);
			break;}
		case varloc::env:{
			ins = inst::cpEI_DS2;
			toPos = pos;
			break;}
	}

    program().push_back( ins  | index);
	program().push_back(toPos); //copy to
	program().push_back(0); //copy from
}

void Compiler::emitPushStack(uint32_t value, uint32_t size){
    program().push_back(inst::pushN_1 | size);
    program().push_back(value); //value to push
    _scopeRef.back()+= size;
}

void Compiler::emitPushTopStackNtimesToStack( uint32_t size){
    program().push_back(inst::pushS0N | size);
    _scopeRef.back()+= size;
}
void Compiler::emitCall(string name){
	program().push_back(inst::jmpA_1);
	program().push_back(0);
	_lables[program().size() -1] = name;
	return;

}

void Compiler::emitPushPC(){
	program().push_back(inst::pushPC);
	return;
}
uint32_t Compiler::emitPushRPC(){
	program().push_back(inst::pushRPC);
	program().push_back(0x00);
    return program().size() - 1;
}
void Compiler::emitReturn(){
	/*
	 
	 */
	_scopeRef.back()-= 1; //push old pc
	program().push_back(inst::popPC);


}

void Compiler::emitSysCall(uint32_t pos, uint32_t functionId){
	program().push_back(inst::sysCall | functionId);
	program().push_back(relpos(pos));
}

void Compiler::emitPushLocToTopStack(uint32_t pos, uint32_t size, varloc::Enum rel){
    
    //coppy loc to top stact
    program().push_back(inst::pushN | size);
    _scopeRef.back() += size;
	inst::Enum ins;
	uint32_t fromPos;
	switch (rel) {
		case varloc::abs:{
			ins = inst::cpN_RDS2;
			fromPos = pos;
			break;}
		case varloc::rel:{
			ins = inst::cpN_DS2;
			fromPos = relpos(pos);
			break;}
		case varloc::env:{
			ins = inst::cpEN_DS2;
			fromPos = pos;
			break;}
	}
    program().push_back( ins  | size);
    program().push_back(size - 1); //copy to
    program().push_back(fromPos); //copy from
}

uint32_t Compiler::emitJumpToRef(){
    program().push_back(inst::jmpA_1);
    program().push_back(0x00);
    return program().size() - 1;
}

uint32_t Compiler::emitCondJumpToRef(){
    program().push_back(inst::cjmpA_1);
    program().push_back(0x00);
    return program().size() - 1;
}

uint32_t Compiler::emitJumpToRef(uint32_t ref){
    program().push_back(inst::jmpA_1);
    program().push_back(ref);
    return ref;
}

uint32_t Compiler::emitCondJumpToRef(uint32_t ref){
    program().push_back(inst::cjmpA_1);
    program().push_back(ref);
    return ref;
}

void Compiler::emitBOAddPush(){
	program().push_back(inst::addS01);
	_scopeRef.back() += 1;
}

void Compiler::emitBOMinusPush(){
	program().push_back(inst::minusS01);
	_scopeRef.back() += 1;
}

void Compiler::emitBOAddPop(){
	program().push_back(inst::addS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOMinusPop(){
	program().push_back(inst::minusS01dS1);
	_scopeRef.back() -= 1;
}
