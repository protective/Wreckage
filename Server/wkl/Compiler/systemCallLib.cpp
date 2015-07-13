#include "systemCallLib.h"
namespace wkl {
	

	systemCallBack_t systemCallLib[] = {{1, "doPhycicalDamage"},{0, ""}};

	systemCallBack_t systemCallBackLib[] = {{1, "__hit__"},{0, ""}};

	systemCallBack_t systemEnvLib[] = {
		{1, "wkl_level"},
		{2, "wkl_attack"},
		{3, "wkl_missChance"},
		{4, "wkl_critChance"},
		{0, ""}
		};

};