
#include "CompSpellBook.h"


#include "../../Signals/SignalEnterDevClient.h"

CompSpellBook::CompSpellBook() :
SComponent(COMPID::spellbook){
	init();
}

CompSpellBook::CompSpellBook(const CompSpellBook& orig) :
SComponent(COMPID::spellbook){
	init();
}

void CompSpellBook::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::enterDevClient:{
			SignalEnterDevClient* s = (SignalEnterDevClient*)data;
			this->sendFull(s->_clientId);
			break;
		}
	}
}

void CompSpellBook::acceptMessage(MESSAGE::Enum type, Message* data){

}

void CompSpellBook::init(){

}

CompSpellBook::~CompSpellBook() {
}

