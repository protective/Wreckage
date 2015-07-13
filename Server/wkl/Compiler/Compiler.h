/* 
 * File:   CommandCompiler.h
 * Author: karsten
 *
 * Created on 5. september 2014, 17:47
 */

#ifndef COMPILER_H
#define	COMPILER_H

#include "../Utils/Visitor.h"
#include "InstructionSet.h"
namespace wkl{
namespace varloc{
	enum Enum {
		rel = 1,
		abs = 2,
		env = 3
	};
}
typedef struct vTableEntry{
    vTableEntry(string p_name, uint32_t p_pos, varloc::Enum p_rel){
		name = p_name;
		pos = p_pos;
		rel = p_rel;
		size = 1;
		systemCall = 0;
    }
    vTableEntry(string p_name, uint32_t p_pos, varloc::Enum p_rel, uint32_t p_size){
		name = p_name;
		pos = p_pos;
		rel = p_rel;
		size = p_size;
		systemCall = 0;
    }
	vTableEntry(string p_name, uint32_t p_pos, varloc::Enum p_rel, uint32_t p_size, uint32_t p_systemCall){
		name = p_name;
		pos = p_pos;
		rel = p_rel;
		size = p_size;
		systemCall = p_systemCall;
    }
    vTableEntry(const vTableEntry& v){
		name = v.name;
		pos = v.pos;
		rel = v.rel;
		size = v.size;
		systemCall = v.systemCall;
    }
    string name;
    uint32_t pos;
	varloc::Enum rel;
    uint32_t size;
	uint32_t systemCall;
}vTableEntry;

namespace Step{
	enum Enum{
		allocation = 1,
		main = 2
	};
}

typedef uint32_t INSTRUCTION;
#define OPCODE(X) (X & 0x00FF0000)
#define ARG(X) (X & 0x0000FFFF)
typedef vector<INSTRUCTION> PROGRAM;
class Program;
class Compiler : public Visitor {
public: 
	Compiler(string programPath);
	virtual uint32_t compile(Program* program);
	PROGRAM& program(){return _program;}
    //list<systemCallFunc> getGlobalSystemCallLibs();
	virtual void visit(Node* node){};
	virtual void visit(Terminal* node){};
	virtual void visit(NodeAssignExpr* node);
	virtual void visit(NodeTupAssignStmt* node);
	virtual void visit(NodeExpr* node){};
	virtual void visit(NodeExprStmt* node);
	virtual void visit(NodeRtnStmt* node){}
	virtual void visit(NodeIfStmt* node);
	virtual void visit(NodeWhileStmt* node);
	virtual void visit(NodeLiteralExpr* node);
	virtual void visit(NodeStmt* node){};
	virtual void visit(NodeVardeclStmt* node);
	virtual	void visit(NodeOutdeclStmt* node){}
	virtual void visit(NodeIndeclStmt* node);
	virtual void visit(NodeVariable* node);
	virtual void visit(NodeAttributeAccessVariable* node){}
	virtual void visit(NodeVariableExpr* node);
	virtual void visit(Identifier* node){};
	virtual void visit(IntegerLiteral* node);
	virtual void visit(BinaryOperatorExpr* node);
	virtual void visit(NodeArg* node);
	virtual void visit(NodeTupDref* node){}
	virtual void visit(NodeCallExpr* node);
	virtual void visit(TypeDenoter* node){}
	virtual void visit(NodeTop* node){}
	virtual void visit(NodeVardecTop* node);
	virtual void visit(NodeParam* node);
	virtual void visit(NodeMethod* node);
	void finalize();
	virtual ~Compiler();
private:
	uint32_t _mainFunctionPC;
	Step::Enum _step;
	bool _inStatic;
	vTableEntry* vtableFind(string id);
	string _programPath;
	PROGRAM _program;

	uint32_t relpos(uint32_t pos){
		//stack location start at 1
		return _scopeRef.back() - pos;
	}
	list<uint32_t> _scopeRef;
	list<vTableEntry> _vtable;
	//  codepoint, jmppoint
	map<uint32_t, string> _lables;
	map<uint32_t, uint32_t> _interruptHandlers;
	void emitPopStack(uint32_t size);
	void emitPopStackIgnore(uint32_t size);

	void emitPushStack(uint32_t value, uint32_t size);
	void emitPopTopStackToLoc(uint32_t pos, uint32_t size);
	void emitTopStackToLoc(uint32_t pos, bool rel, uint32_t size);
	void emitTopStackIndexToLoc(uint32_t pos, varloc::Enum loc, uint32_t index);
	void emitPushLocToTopStack(uint32_t pos, uint32_t size, varloc::Enum rel);
	void emitPushTopStackNtimesToStack(uint32_t size);
	void emitCall(string name);
	void emitPushPC();
	uint32_t emitPushRPC();
	void emitNOP();
	void emitEOP();
	void emitReturn();
	void emitBOAddPush();
	void emitBOMinusPush();
	void emitBOAddPop();
	void emitBOMinusPop();
	void emitSysCall(uint32_t pos, uint32_t functionId);
	uint32_t emitJumpToRef();
    uint32_t emitCondJumpToRef();
	uint32_t emitJumpToRef(uint32_t ref);
    uint32_t emitCondJumpToRef(uint32_t ref);	
};
}
#endif	/* COMPILER_H */
