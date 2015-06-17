define( ['require','jquery-ui'], function( require)
{
	function CompPowerUseCheck(obj)
	{
		this.obj = obj;
	}

	CompPowerUseCheck.prototype.getKeyValues = function() {
		
		return {'compName': 'CompPowerUseCheck', 'timer' : 1};
		
	}
	
	return function Init()
	{
		this.compPowerUseCheck = new CompPowerUseCheck(this);
	};
});
