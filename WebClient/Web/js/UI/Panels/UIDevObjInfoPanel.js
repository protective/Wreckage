define(['require', 'jquery', 'jquery-ui' , 'bootstrap',
        'UI/UIMain',
        'Model/CompSpellBook',
        'Model/CompTargeted',
        'obj'],function ( require) {

    var _panels = {};
    
    var UIMain = require('UI/UIMain');
    var CompSpellBook = require('Model/CompSpellBook');
    var CompTargeted = require('Model/CompTargeted');
    var Obj = require('obj');
           
    Obj.prototype.createObjInfoPanel = function (obj) {
    	
    	if('UIDevObjInfoPanel' in obj)
    		UIMain.maindiv.removeChild(obj.UIDevObjInfoPanel);
    		
    	
    	var overlay = document.createElement('div');
    	overlay.className  = "devObjView";
    	UIMain.maindiv.appendChild(overlay);
    	
    	var table = document.createElement("TABLE");
    	overlay.appendChild(table);
    	
    	var tempComponents = ['compTargeted', 'compSpellBook'];
    	for (var i in tempComponents){
        	if(tempComponents[i] in obj){

	    		var row = table.insertRow(0);
	        	var cell1 = row.insertCell(0);
	    		obj[tempComponents[i]].getHTMLContentTable(cell1); 	
        	}
    	}

    	$('.devObjView').draggable();
    	obj.UIDevObjInfoPanel = overlay;

    };
    

 
    return {};
});