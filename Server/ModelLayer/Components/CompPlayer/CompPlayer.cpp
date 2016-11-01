
#include "CompPlayer.h"

#include "../../../Processor/Processor.h"

#include "../../Signals/SignalEnterDevClient.h"

CompPlayer::CompPlayer(SObj* obj) :
SComponent(COMPID::player, obj){
	init();
}

CompPlayer::CompPlayer(const CompPlayer& orig, SObj* obj) :
SComponent(COMPID::player, obj){
	init();
}



void CompPlayer::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){

	}
}

void CompPlayer::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
	}
}



void CompPlayer::init(){

}

CompPlayer::~CompPlayer() {
}

