define( ['require','jquery-ui'], function( require)
{
	function CompPowerActivateInstant(obj)
	{
		this.obj = obj;
	}

	CompPowerActivateInstant.prototype.getHTMLContentTable = function (parrent){
		
    	var button = document.createElement('button');
    	button.className = "ko";
    	button["title"] = "CompPowerActivateInstant";
    	button["data-toggle"] = "popover";
    	button["data-content"]= "Content";
    	button.innerText = "CompPowerActivateInstant";
    	parrent.appendChild(button);
    	$('.ko').popover();
    	
    	return button;
	}
	
	return function Init()
	{
		this.compPowerActivateInstant = new CompPowerActivateInstant(this);
	};
});
