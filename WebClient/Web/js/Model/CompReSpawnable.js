define( ['require','jquery-ui'], function( require)
{
	function CompReSpawnable(obj)
	{
		this.obj = obj;
	}
	
	CompReSpawnable.prototype.getKeyValues = function() {
		
		return {'compName': 'CompReSpawnable', 'timer' : 1};
		
	}
	
	
	return function Init()
	{
		this.compReSpawnable = new CompReSpawnable(this);
	};
});
