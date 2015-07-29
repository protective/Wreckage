/* 
 * File:   SWorld.cpp
 * Author: karsten
 * 
 * Created on 22. maj 2011, 16:24
 */

#include "SWorld.h"

#include "../Tasks/Task.h"
#include "../Processor/Processor.h"
#include "Destiny/Destiny.h"

SWorld::SWorld(Processor* processors) {
	_processors = processors;
	_time = SDL_GetTicks();
	_destiny = new Destiny();
}

void SWorld::addGrid(SGrid* grid){
	this->grids[grid->_id] = grid;
}

void SWorld::proces(uint32_t deltaT){
	_time = SDL_GetTicks();
	
}

map<uint32_t, SGrid*>& SWorld::getGrids(){
	return this->grids;
}

SWorld::~SWorld() {
}

