
#include "CompPlayer.h"

#include "../../../Processor/Processor.h"

#include "../../Signals/SignalEnterDevClient.h"

CompPlayer::CompPlayer() :
SComponent(COMPID::player){
	init();
}

CompPlayer::CompPlayer(const CompPlayer& orig) :
SComponent(COMPID::player){
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

