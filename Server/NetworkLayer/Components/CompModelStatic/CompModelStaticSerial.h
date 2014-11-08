
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
		this->pos = *pos;
	}
	SPos pos;
    uint32_t modelId;
};

struct SerialObjExit : public SerialComp{
	SerialObjExit(OBJID objId, SPos* pos, uint32_t fadetime):
	SerialComp(objId, COMPID::modelStatic, (uint32_t)SerialCompModelStatic::ObjExit, sizeof(SerialObjExit)){
		this->fadetime = fadetime; 
		this->pos = *pos;
	}
	SPos pos;
    uint32_t fadetime;
};


#endif	/* COMPMODELSTATICSERIAL_H */

