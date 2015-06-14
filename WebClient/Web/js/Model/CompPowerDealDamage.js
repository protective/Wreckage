define( ['require','jquery-ui'], function( require)
{
	function CompPowerDealDamage(obj)
	{
		this.obj = obj;
	}

	CompPowerDealDamage.prototype.getHTMLContentTable = function (parrent){
		
    	var button = document.createElement('button');
    	button.className = "ko";
    	button["title"] = "CompPowerDealDamage";
    	button["data-toggle"] = "popover";
    	button["data-content"]= "Content";
    	button.innerText = "CompPowerDealDamage";
    	parrent.appendChild(button);
    	$('.ko').popover();
    	
    	return button;
	}
	
	return function Init()
	{
		this.compPowerDealDamage = new CompPowerDealDamage(this);
	};
});
