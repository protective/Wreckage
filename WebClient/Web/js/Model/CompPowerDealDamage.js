define( ['require','jquery-ui'], function( require)
{
	function CompPowerDealDamage(obj)
	{
		this.obj = obj;
	}

	CompPowerDealDamage.prototype.getKeyValues = function() {
		
		return {'compName': 'CompPowerDealDamage', 'timer' : 1};
		
	}
	
	return function Init()
	{
		this.compPowerDealDamage = new CompPowerDealDamage(this);
	};
});
