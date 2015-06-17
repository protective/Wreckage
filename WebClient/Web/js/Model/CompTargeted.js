define( ['require','jquery-ui'], function( require)
{
	function CompTargeted(obj)
	{
		this.obj = obj;
	}

	CompTargeted.prototype.getKeyValues = function() {
		
		return {'compName': 'CompTargeted', 'timer' : 1};
		
	}
	
	return function Init()
	{
		this.compTargeted = new CompTargeted(this);
	};
});

