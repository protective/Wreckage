
#include "ComponentFactory.h"

#include "../SObj.h"
#include "../Network/Serialize.h"

#include "CompSpawnNode/CompSpawnNode.h"
#include "CompReSpawnable/CompReSpawnable.h"
#include "CompSpellBook/CompSpellBook.h"
#include "CompPowerUseCheck/CompPowerUseCheck.h"
#include "CompPowerActivateTimed/CompPowerActivateTimed.h"
#include "CompAbilityInput/CompAbilityInput.h"
#include "CompPlayer/CompPlayer.h"
#include "CompPowerActivateInstant/CompPowerActivateInstant.h"
#include "CompTargeted/CompTargeted.h"
#include "CompModelStatic/CompModelStatic.h"
#include "CompPosition/CompPosition.h"
#include "CompPowerBase/CompPowerBase.h"
#include "CompProgramable/CompProgramable.h"

SComponent* createComponent(SObj* obj, COMPID::Enum type, OBJID id, pqxx::connection& con){
	switch(type){
		case COMPID::spellbook: {
			return new CompSpellBook(obj, id, con);
		}
		case COMPID::powerUseCheck: {
			return new CompPowerUseCheck(obj, id, con);
		}
		case COMPID::powerActivateTimed: {
			return new CompPowerActivateTimed(obj, id, con);
		}
		case COMPID::spawnNode: {
			return new CompSpawnNode(obj, id, con);
		}
		case COMPID::reSpawnable: {
			return new CompReSpawnable(obj, id, con);
		}
		case COMPID::abilityInput: {
			return new CompAbilityInput(obj, id, con);
		}
		case COMPID::player: {
			return new CompPlayer(obj, id, con);
		}		
		case COMPID::powerActivateInstant: {
			return new CompPowerActivateInstant(obj, id, con);
		}
		case COMPID::targeted: {
			return new CompTargeted(obj, id, con);
		}
		case COMPID::modelStatic: {
			return new CompModelStatic(obj, id, con);
		}
		case COMPID::position: {
			return new CompPosition(obj, id, con);
		}
		case COMPID::powerBase: {
			return new CompPowerBase(obj, id, con);
		}
		case COMPID::programable: {
			return new CompProgramable(obj, id, con);
		}	
		default:{
			cerr<<"ERROR ComponentFactory::createComponent component not known"<<endl;			
		}
	}
}

SComponent* createComponent(SerialObjComp* sc, int32_t* size, SObj* obj){
	SComponent* temp = NULL;
	switch(sc->_compType){
		case COMPID::spawnNode: {
			//temp = new CompSpawnNode((SerialCompSpawnNode*)sc, size);
			break;
		}
		case COMPID::powerBase: {
			//temp = new CompPowerBase();
			break;
		}
		default:{
			cerr<<"WARNING factory createComponent unserialized component"<<endl;
		}
	}
	if(*size > 0)
		return temp;
	else if(temp)
		delete temp;
	return NULL;
}

SComponent* createComponent(uint32_t compId, SObj* obj){
	SComponent* temp = NULL;
	switch(compId){
		case COMPID::powerBase: {
			temp = new CompPowerBase(obj);
			break;
		}
		default:{
			cerr<<"WARNING factory createComponent unserialized component"<<endl;
		}
	}
	return temp;

}