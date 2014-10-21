
#include "CompSpellBook.h"

CompSpellBook::CompSpellBook() :
SComponent(COMPID::spellbook){
	
}

CompSpellBook::CompSpellBook(const CompSpellBook& orig) :
SComponent(COMPID::spellbook){

}


void CompSpellBook::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompSpellBook::acceptMessage(MESSAGE::Enum type, Message* data){

}


void CompSpellBook::init(){
}

CompSpellBook::~CompSpellBook() {
}

