/* 
 * File:   SGrid.h
 * Author: karsten
 *
 * Created on 22. maj 2011, 16:42
 */

#ifndef SGRID_H
#define	SGRID_H
#include "../BInclude.h"

class SGrid{
public:
	SGrid(uint32_t id);
	SGrid(uint32_t id, uint32_t spaceWight, uint32_t spaceHight);
	virtual uint32_t getId(){return _id;}
	virtual SGrid* getGrid(){return this;}

	uint32_t _id;
	uint32_t getWight(){return this->_spaceWight;}
	uint32_t getHight(){return this->_spaceHight;}
	void setWight(uint32_t value){this->_spaceWight = value;}
	void setHight(uint32_t value){ this->_spaceHight = value;}
	virtual ~SGrid();
private:
	uint32_t _spaceWight;
	uint32_t _spaceHight;
};
#endif	/* SGRID_H */

