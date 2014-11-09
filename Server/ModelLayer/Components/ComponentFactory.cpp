
#include "ComponentFactory.h"

#include "../SObj.h"
#include "CompSpawnNode/CompSpawnNode.h"
#include "CompReSpawnable/CompReSpawnable.h"
#include "CompSpellBook/CompSpellBook.h"
#include "CompPowerUseCheck/CompPowerUseCheck.h"
#include "CompPowerActivateTimed/CompPowerActivateTimed.h"
#include "CompAbilityInput/CompAbilityInput.h"
#include "CompPowerDealDamage/CompPowerDealDamage.h"
#include "CompPowerActivateInstant/CompPowerActivateInstant.h"
#include "CompTargeted/CompTargeted.h"
#include "CompModelStatic/CompModelStatic.h"
#include "CompPosition/CompPosition.h"

SComponent* createComponent(SObj* obj, COMPID::Enum type, OBJID id, pqxx::connection& con){
	switch(type){
		case COMPID::spellbook: {
			return new CompSpellBook(obj, id,con);
		}
		case COMPID::powerUseCheck: {
			return new CompPowerUseCheck(obj, id,con);
		}
		case COMPID::powerActivateTimed: {
			return new CompPowerActivateTimed(obj, id,con);
		}
		case COMPID::spawnNode: {
			return new CompSpawnNode(obj, id,con);
		}
		case COMPID::reSpawnable: {
			return new CompReSpawnable(obj, id,con);
		}
		case COMPID::abilityInput: {
			return new CompAbilityInput(obj, id,con);
		}
		case COMPID::powerDealDamage: {
			return new CompPowerDealDamage(obj, id,con);
		}		
		case COMPID::powerActivateInstant: {
			return new CompPowerActivateInstant(obj, id,con);
		}
		case COMPID::targeted: {
			return new CompTargeted(obj, id,con);
		}
		case COMPID::modelStatic: {
			return new CompModelStatic(obj, id,con);
		}
		case COMPID::position: {
			return new CompPosition(obj, id,con);
		}	
		default:{
			cerr<<"ERROR ComponentFactory::createComponent component not known"<<endl;			
		}
	}
}

