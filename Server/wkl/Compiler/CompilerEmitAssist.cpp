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
	if(size != 0 && size <= 0xFFFF){
		//coppy top stack to the rel loc 
		program().push_back(inst::popN | size);
		this->_scopeRef.back() -= size;
	}else if (size > 0xFFFF){
		cerr<<"ERROR Compiler::emitPopStack invalid size is "<<size<<endl;
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
    program().push_back(inst::cpN_RDRS2 | size);
	program().push_back(0x00); //copy from
    program().push_back(relpos(pos)); //copy to
    
    
    //pop top of stack
    program().push_back(inst::popN | size);
    this->_scopeRef.back() -= size;
}

void Compiler::emitTopStackToLoc(uint32_t pos, bool rel, uint32_t size){

    //coppy top stack to the rel loc 
    program().push_back((rel ? inst::cpN_RDRS2: inst::cpN_RDAS2) | size);
	program().push_back(0x00); //copy from
    program().push_back(rel ? relpos(pos): pos); //copy to
    
}

void Compiler::emitTopStackToEnv(uint32_t envId){
    program().push_back(inst::cpN_RED2);
	program().push_back(0); //copy from
	program().push_back(envId); //copy to
}

void Compiler::emitTopStackIndexToLoc(uint32_t pos, varloc::Enum loc, uint32_t index){

    //coppy top stack at index to the rel loc 
	inst::Enum ins;
	uint32_t toPos;
	switch (loc) {
		case varloc::abs:{
			ins = inst::cp_RSIAD2;
			toPos = pos;
			break;}
		case varloc::rel:{
			ins = inst::cp_RSIRD2;
			toPos = relpos(pos);
			break;}
		case varloc::env:{
			cerr<<"error emitTopStackIndexToLoc"<<endl;
			return;
			break;}
	}

    program().push_back(ins);
	program().push_back(0); //copy from
	program().push_back(index); //copy from index
	program().push_back(toPos); //copy to

}

void Compiler::emitLocRIndexToTopStack(uint32_t pos, varloc::Enum loc, uint32_t rIndexVar){
    //coppy top stack at index to the rel loc 
	inst::Enum ins;
	uint32_t fromPos;
	switch (loc) {
		case varloc::abs:{
			ins = inst::cp_ASsvIRD2;
			fromPos = pos;
			break;}
		case varloc::rel:{
			ins = inst::cp_RSsvIRD2;
			fromPos = relpos(pos);
			break;}
		case varloc::env:{
			cerr<<"error emitLocRIndexToTopStack"<<endl;
			return;
			break;}
	}
	program().push_back(ins); //rel stack to use as index variable
	program().push_back(fromPos); //copy from
	program().push_back(rIndexVar); //copy from index value at stack offset rIndexVar
	program().push_back(0); //copy to
	
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
	_scopeRef.back() +=1;
	return;
}

uint32_t Compiler::emitPushRPC(){
	program().push_back(inst::pushRPC);
	program().push_back(0x00);
	_scopeRef.back() +=1;
    return program().size() - 1;
}

void Compiler::emitPushUIndx(uint32_t rel){
	program().push_back(inst::pushUIndx);
	program().push_back(rel);
	_scopeRef.back() += 1;
	return;
}

void Compiler::emitReturn(){
	program().push_back(inst::popPC);
	_scopeRef.back() -= 1; //push old pc
}

void Compiler::emitSysCall(uint32_t pos, uint32_t functionId){
	program().push_back(inst::sysCall | functionId);
	program().push_back(relpos(pos));
}

void Compiler::emitMvMapFromTopStack(uint32_t mapSize){
	program().push_back(inst::mvMapAL | mapSize);
}

void Compiler::emitPushLocToTopStack(uint32_t pos, varloc::Enum rel){
    
    //copy loc to top stack
    program().push_back(inst::pushN | 0x01);
    _scopeRef.back() += 1;
	inst::Enum ins;
	uint32_t fromPos;
	switch (rel) {
		case varloc::abs:{
			ins = inst::cpN_ADRS2;
			fromPos = pos;
			break;}
		case varloc::rel:{
			ins = inst::cpN_RDRS2;
			fromPos = relpos(pos);
			break;}
		case varloc::env:{
			ins = inst::cpN_ERD2;
			fromPos = pos;
			break;}
		case varloc::con:{
			ins = inst::cpCO_DS2;
			fromPos = pos;
			break;}
	}
    program().push_back(ins);
	program().push_back(fromPos); //copy from
    program().push_back(0); //copy to
    
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

uint32_t Compiler::emitCond2NEQJumpToRef(uint32_t ref){
    program().push_back(inst::cjmp2NeqA_1);
    program().push_back(ref);
    return ref;
}

void Compiler::emitBOAddPush(){
	program().push_back(inst::addS01);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOMinusPush(){
	program().push_back(inst::minusS01);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOAddPop(){
	program().push_back(inst::addS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOMinusPop(){
	program().push_back(inst::minusS01dS1);
	_scopeRef.back() -= 1;
}



void Compiler::emitBOMultiPop(){
	program().push_back(inst::multiS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBODeviPop(){
	program().push_back(inst::deviS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOModuloPop(){
	program().push_back(inst::moduloS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBitAndPop(){
	program().push_back(inst::bitandS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBitOrPop(){
	program().push_back(inst::bitorS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitAndPop(){
	program().push_back(inst::andS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitOrPop(){
	program().push_back(inst::orS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOLEEQPop(){	
	program().push_back(inst::leeqS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOLEPop(){
	program().push_back(inst::leS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOGTEQPop(){	
	program().push_back(inst::gteqS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOGTPop(){
	program().push_back(inst::gtS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBOEQPop(){	
	program().push_back(inst::eqS01dS1);
	_scopeRef.back() -= 1;
}

void Compiler::emitBONEQPop(){
	program().push_back(inst::neqS01dS1);
	_scopeRef.back() -= 1;
}