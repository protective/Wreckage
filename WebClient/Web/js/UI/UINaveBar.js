define(['require', 'jquery', 'jquery-ui' , 'bootstrap',
        'Model/CompSpellBook',
        'Model/CompTargeted',
        'obj',
        'text!templates/navbar.html'],function ( require) {

	var navBar = require('text!templates/navbar.html');

	
	function UI_show_templates(){
		
		alert("hest");
	}

    function init(maindiv){
    	
    	var parser = new DOMParser();
    	var host = parser.parseFromString(navBar, "text/html");
    	maindiv.appendChild(host.firstChild);

    	$("body").on("click", "#UIshowtemplates", function(e){
    		UI_show_templates(); return false; });
    	
    }
    

 
    return init;
});