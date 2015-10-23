/* 
 * File:   SGrid.cpp
 * Author: karsten
 * 
 * Created on 22. maj 2011, 16:42
 */

#include "SGrid.h"
#include "SWorld.h"

SGrid::SGrid(uint32_t id) {
	this->_id = id;
	
	_spaceHight = 10;
	_spaceWight = 10;
	//cerr<<"init grid"<<endl;
}

SGrid::SGrid(uint32_t id, uint32_t spaceWight, uint32_t spaceHight) {
	this->_id = id;
	_spaceHight = spaceHight;
	_spaceWight = spaceWight;
	//cerr<<"init grid"<<endl;
}

SGrid::~SGrid() {
}

