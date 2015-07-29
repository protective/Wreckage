define( ['require','jquery-ui'], function( require)
{
	function CompProgramable(obj)
	{
		this.obj = obj;
	}

	CompProgramable.prototype.getKeyValues = function() {
		
		return {'compName': 'CompProgramable',
			'entries' : {}
			};
		
	}
	
	return function Init()
	{
		this.compProgramable = new CompProgramable(this);
	};
});
