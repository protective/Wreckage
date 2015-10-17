define( function( require )
{
	var webSocket = require('Network/webSocket');

	function CompSpellBook(obj, powers)
	{
		this.obj = obj;
		this.tick = 0;
		this.powers = powers;
	}
	
	CompSpellBook.prototype.getKeyValues = function() {
		
		return {'compName': 'CompSpellBook', 'timer' : 1};
		
	}
	
	CompSpellBook.prototype.castSpellTarget = function castSpellTarget(target){
		webSocket.handlers["castSpellTarget"](this.obj, target, 0); 
	}
	
	
	return function Init()
	{
		this.compSpellBook = new CompSpellBook(this);
	};
});