/* 
 * File:   SWorld.h
 * Author: karsten
 *
 * Created on 22. maj 2011, 16:24
 */

#ifndef SWORLD_H
#define	SWORLD_H
#include "../BInclude.h"
#include "SGrid.h"
class Processor;
class SWorld {
public:
	SWorld(Processor* processors);
	uint32_t getTime(){return _time;}
	void addGrid(SGrid* grid);
	void proces(uint32_t deltaD);

	map<uint32_t, SGrid*>& getGrids();
	Processor* getProcessor(){return _processors;}
	virtual ~SWorld();
private:
	map<uint32_t, SGrid*> grids;
	uint32_t _time;
	Processor* _processors;
};

#endif	/* SWORLD_H */

