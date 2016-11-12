
#ifndef COMPSPELLBOOK_H
#define	COMPSPELLBOOK_H

#include "../SComponent.h"

#include "../../../wkl/Compiler/systemCallLib.h"
#include "../../../wkl/ProgramExecutor.h"

#include "../../../wkl/Program.h"
class SObj;


class CompSpellBook  : public SComponent {
public:
    struct Power {
        SObj* obj;
        uint16_t level;
        uint32_t trainedFlags;
    };
	CompSpellBook(SObj* obj);
	CompSpellBook(const CompSpellBook& orig, SObj* obj);
	CompSpellBook(SObj* obj, OBJID id, pqxx::connection& con);
	CompSpellBook* clone(SObj* obj){return new CompSpellBook(*this, obj);}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	void virtual acceptNetwork(SerialInputPayload* data);

	void sendFull(uint32_t clientId);
	void sendBeginCast(OBJID powerId, OBJID target, uint32_t beginTime, uint32_t endTime);
	void sendCast(OBJID powerId, OBJID target, GFXTYPE::Enum gfxType, uint8_t gfxRef);
	virtual map<uint32_t, wkl::systemCallFunc> getSyscalls();

	//addFunctions
	void addPower(OBJID power);
    //removeFunctions
	void removePower(OBJID power);

	void virtual dbInit();
	void static dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompSpellBook();
private:
	virtual void init();

    map<OBJID, CompSpellBook::Power> _powers;

	list<OBJID> _castList;
	uint32_t _beginTime;
	uint32_t _castTime;
	uint8_t _gfxId;

	//systemCalls implemented by this component
	static wkl::Variable consumeMana(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable channel(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable cast(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable cast_final(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
};

#endif	/* COMPSPELLBOOK_H */

