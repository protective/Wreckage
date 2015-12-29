
#include "Variable.h"
namespace wkl{
	VObject::VObject(VObject* vo)
	{
		map<Variable, Variable> m = map<Variable, Variable>(vo->_vector);
		_vector = m;
	};
	
	VObject* VObject::clone(){
			return new VObject(this);
		};
}
