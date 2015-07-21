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
	
	CompPowerBase.prototype.sendProgramSrc = function(programSrc) {
		webSocket.handlers['CompPowerBaseSetProgram'](this.obj, programSrc);
		this.programSrc = programSrc;
		//alert("send");
	}
	
	CompPowerBase.prototype.getKeyValues = function() {
		
		return {'compName' : 'CompPowerBase',
			'entries' : {
				'powerName': {'value' : this.powerName},
				'description' : {'value' : this.description},
				'programSrc' : {'value' : this.programSrc ,'save' : this.sendProgramSrc
				}
			}
		};
			
	}
	
	return function Init(powerName, description, programSrc)
	{
		this.compPowerBase = new CompPowerBase(this, powerName, description, programSrc);
	};
});
