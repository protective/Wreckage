define( ['require','jquery-ui'], function( require)
{
	function CompPowerBase(obj, powerName, description)
	{
		this.obj = obj;
		this.powerName = powerName;
		this.description = description;
	}

	CompPowerBase.prototype.getKeyValues = function() {
		
		return {'powerName': this.powerName, 'description' : this.description};
		
	}
	
	return function Init(powerName, description)
	{
		this.compPowerBase = new CompPowerBase(this, powerName, description);
	};
});
