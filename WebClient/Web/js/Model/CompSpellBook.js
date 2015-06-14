define( function( require )
{
	var webSocket = require('Network/webSocket');

	function CompSpellBook(obj)
	{
		this.obj = obj;
		this.tick       =  0;
	}
	
	CompSpellBook.prototype.getHTMLContentTable = function (parrent){
		
    	var button = document.createElement('button');
    	button.className = "ko";
    	button["title"] = "CompSpellBook";
    	button["data-toggle"] = "popover";
    	button["data-content"]= "Content";
    	button.innerText = "CompSpellBook";
    	parrent.appendChild(button);
    	$('.ko').popover();
    	
    	return button;
	}
	
	CompSpellBook.prototype.castSpellTarget = function castSpellTarget(target){
		webSocket.handlers["castSpellTarget"](this.obj, target, 0); 
	}
	
	
	return function Init()
	{
		this.compSpellBook = new CompSpellBook(this);
	};
});