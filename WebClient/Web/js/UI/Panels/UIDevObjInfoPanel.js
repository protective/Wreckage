define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'UI/UIMain',
        'Model/CompSpellBook',
        'Model/CompTargeted',
        'obj',
        'text!templates/keyValueTable.html'],function ( require) {

    var _panels = {};
    
    var UIMain = require('UI/UIMain');
    var CompSpellBook = require('Model/CompSpellBook');
    var CompTargeted = require('Model/CompTargeted');
    var Obj = require('obj');

	var keyValueTable = require('text!templates/keyValueTable.html');

    
    Obj.prototype.createObjInfoPanel = function (obj) {
    	
    	if('UIDevObjInfoPanel' in obj)
    		UIMain.maindiv.removeChild(obj.UIDevObjInfoPanel);
    		
    	
    	var overlay = document.createElement('div');
    	overlay.className  = "devObjView";
    	UIMain.maindiv.appendChild(overlay);
    	

    	var table = document.createElement('TABLE');

    	overlay.appendChild(table);
    	
    	var tempComponents = ['compTargeted',
    	                      'compSpellBook',
    	                      'compPowerDealDamage',
    	                      'compPowerActivateInstant',
    	                      'compPowerUseCheck',
    	                      'compReSpawnable'];
    	for (var i in tempComponents){
        	if(tempComponents[i] in obj){

	    		var row = table.insertRow(0);
	        	var cell1 = row.insertCell(0);
	        	
	        	var button = document.createElement('button');
	        	button.className = "ko";
	        	button["title"] = "hest";
	        	button["data-toggle"] = "popover";
	        	
	    		var keyval = {'keyval' : obj[tempComponents[i]].getKeyValues()}; 	

	    		
	    		var yy = _.template(keyValueTable)(keyval);
	        	
	        	//button["data-content"]= yy;
	        	button.innerText = "CompReSpawnable";
	        	cell1.appendChild(button);
	        	$('.ko').popover({
	                'html' : true,
	                content: function() {
	                    return yy;
	                }});
	        	
        	}
    	}

    	$('.devObjView').draggable();
    	obj.UIDevObjInfoPanel = overlay;

    };
    

 
    return {};
});