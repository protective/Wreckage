define( function( require )
{
	
	
	var webSocket = require('Network/webSocket');
	
	
	/**
	 * Cast constructor
	 */
	function CompSpellBook(obj)
	{
		this.obj = obj;
		this.tick       =  0;
	}

	CompSpellBook.prototype.castSpellTarget = function castSpellTarget(target){
		webSocket.handlers["castSpellTarget"](this.obj, target, 0); 
	}
	
	
	return function Init()
	{
		this.compSpellBook = new CompSpellBook(this);
	};
});