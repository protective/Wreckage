define( ['require','jquery-ui'], function( require)
{
	/**
	 * Cast constructor
	 */
	function CompTargeted(obj)
	{
		this.obj = obj;
	}

	
	CompTargeted.prototype.getHTMLContentTable = function (parrent){
		
    	var button = document.createElement('button');
    	button.className = "ko";
    	button["title"] = "CompTargeted";
    	button["data-toggle"] = "popover";
    	button["data-content"]= "Content";
    	button.innerText = "CompTargeted";
    	parrent.appendChild(button);
    	$('.ko').popover();
    	
    	return button;
	}
	
	return function Init()
	{
		this.compTargeted = new CompTargeted(this);
	};
});

