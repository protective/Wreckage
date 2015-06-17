define(['require', 'jquery', 'jquery-ui' , 'bootstrap',
        'Model/CompSpellBook',
        'Model/CompTargeted',
        'objManager',
        'obj',
        'text!templates/navbar.html'],function ( require) {

	var navBar = require('text!templates/navbar.html');

	var objManager = require('objManager');
	//var Obj = require('obj');
	
	function UI_show_templates(){
		//alert("hest");
		var tmp = objManager.getObjs();
		for (var ob in tmp){
			tmp[ob].createObjInfoPanel(tmp[ob]);
		}
		
	}

    function init(maindiv){
    	
    	var parser = new DOMParser();
    	var host = parser.parseFromString(navBar, "text/html");
    	maindiv.appendChild(host.firstChild);

    	$("body").on("click", "#UIshowtemplates", function(e){
    		UI_show_templates()});
    	
    }
    

 
    return init;
});