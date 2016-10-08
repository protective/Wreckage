define( ['require','jquery-ui'], function( require)
{
	var webSocket = require('Network/webSocket');

	function CompPowerBase(obj, powerName, description, programSrc)
	{
		this.obj = obj;
		this.powerName = powerName;
		this.description = description;
		this.programSrc = programSrc;
	}

	CompPowerBase.prototype.saveAll = function(name, description, programSrc) {
		webSocket.handlers['CompPowerBaseSave'](this.obj, name, description, programSrc);
		this.programSrc = programSrc;
		this.description = description;
		this.programSrc = programSrc;

	}

	CompPowerBase.prototype.getKeyValues = function() {

		return {'compName' : 'CompPowerBase',
			'entries' : {
				'powerName': {'value' : this.powerName},
				'description' : {'value' : this.description},
				'programSrc' : {'value' : this.programSrc ,'save' : this.programSrc
				}
			}
		};

	}

	return function Init(powerName, description, programSrc)
	{
		this.compPowerBase = new CompPowerBase(this, powerName, description, programSrc);
	};
});
