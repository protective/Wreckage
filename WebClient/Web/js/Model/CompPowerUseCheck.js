define( ['require','jquery-ui'], function( require)
{
	function CompPowerUseCheck(obj)
	{
		this.obj = obj;
	}

	CompPowerUseCheck.prototype.getHTMLContentTable = function (parrent){
		
    	var button = document.createElement('button');
    	button.className = "ko";
    	button["title"] = "CompPowerUseCheck";
    	button["data-toggle"] = "popover";
    	button["data-content"]= "Content";
    	button.innerText = "CompPowerUseCheck";
    	parrent.appendChild(button);
    	$('.ko').popover();
    	
    	return button;
	}
	
	return function Init()
	{
		this.compPowerUseCheck = new CompPowerUseCheck(this);
	};
});
