define( ['require','jquery-ui'], function( require)
{
	function CompReSpawnable(obj)
	{
		this.obj = obj;
	}

	CompReSpawnable.prototype.getHTMLContentTable = function (parrent){
		
    	var button = document.createElement('button');
    	button.className = "ko";
    	button["title"] = "CompReSpawnable";
    	button["data-toggle"] = "popover";
    	button["data-content"]= "Content";
    	button.innerText = "CompReSpawnable";
    	parrent.appendChild(button);
    	$('.ko').popover();
    	
    	return button;
	}
	
	return function Init()
	{
		this.compReSpawnable = new CompReSpawnable(this);
	};
});
