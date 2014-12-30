
#ifndef COMPMODELSTATICSERIAL_H
#define	COMPMODELSTATICSERIAL_H

#include "../CompSerialize.h"

#include "../../../ModelLayer/ObjData/SPos.h"

namespace SerialCompModelStatic{
	/** Identifiers for each serializable type
	  */
	enum Enum{
		/** Dummy entry for serialization of incomplete types
		  */
		Invalid = 0,
		ObjEnter = 1,
		ObjExit  = 2,
		
	};
}

struct SerialObjEnter : public SerialComp{
	SerialObjEnter(OBJID objId, SPos* pos, uint32_t modelId):
	SerialComp(objId, COMPID::modelStatic, (uint32_t)SerialCompModelStatic::ObjEnter, sizeof(SerialObjEnter)){
		this->modelId = modelId;
		this->pos._x = pos->x();
		this->pos._y = pos->y();
		this->pos._z = pos->z();
		this->pos._d = pos->d();
		cerr<<"hh x="<<pos->x()<<" y="<<pos->y()<<" z="<<pos->z()<<" d="<<pos->d()<<endl;

	}
	SerialPOS pos;
    uint32_t modelId;
}__attribute__((__packed__));

struct SerialObjExit : public SerialComp{
	SerialObjExit(OBJID objId, SPos* pos, uint32_t fadetime):
	SerialComp(objId, COMPID::modelStatic, (uint32_t)SerialCompModelStatic::ObjExit, sizeof(SerialObjExit)){
		this->fadetime = fadetime; 
		this->pos._x = pos->x();
		this->pos._y = pos->y();
		this->pos._z = pos->z();
		this->pos._d = pos->d();
	}
	SerialPOS pos;
    uint32_t fadetime;
}__attribute__((__packed__));


#endif	/* COMPMODELSTATICSERIAL_H */

