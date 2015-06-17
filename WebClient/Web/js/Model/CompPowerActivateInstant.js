define( ['require','jquery-ui'], function( require)
{
	function CompPowerActivateInstant(obj)
	{
		this.obj = obj;
	}

	CompPowerActivateInstant.prototype.getKeyValues = function() {
		
		return {'compName': 'CompPowerActivateInstant', 'timer' : 1};
		
	}
	
	return function Init()
	{
		this.compPowerActivateInstant = new CompPowerActivateInstant(this);
	};
});
