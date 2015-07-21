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

	var tmp3 = $('body');
	tmp3.on('keydown', '.mytextarea', function(event) {
		/*
		var target = event.target;
		
        if (event.keyCode === 9) { // tab was pressed

            // get caret position/selection
            var val = target.value,
                start = target.selectionStart,
                end = target.selectionEnd;

            // set textarea value to: text before caret + tab + text after caret
            target.value = val.substring(0, start) + '\t' + val.substring(end);

            // put caret at right position again
            target.selectionStart = target.selectionEnd = start + 1;

            // prevent the focus lose
            return false;

        }
        */
	});
	
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
    	                      'compReSpawnable',
    	                      'compPowerBase'];
    	for (var i in tempComponents){
        	if(tempComponents[i] in obj){

	    		var row = table.insertRow(0);
	        	var cell1 = row.insertCell(0);
	        	
	        	var button = document.createElement('button');
	        	button.id = obj.id + '_' + i ;
	        	button["title"] = "hest";
	        	button["data-toggle"] = "popover";
	        	
	        	button.keyval = {'id' : button.id,
	        			'keyval' : obj[tempComponents[i]].getKeyValues()}; 	
	        	
	        	button.myhest = function(){alert(1);};

	        	button.innerText = tempComponents[i];
	        	cell1.appendChild(button);
	        	var tmp = $('#' + obj.id + '_' + i);
	        	tmp.popover({
	                'html' : true,
	                content: function() {
	                	var yy = _.template(keyValueTable)(this.keyval);
	                    return yy;
	                }});
            	var tmp2 = $('body');

            	tmp2.on('click', '#comsave'+ button.id, function() {
            		
            		for (var j in button.keyval['keyval']['entries']){
            			if (button.keyval['keyval']['entries'][j]['save']){
            				var value = $('#comfield' + j + button.id)[0].value;    
            				
            				button.keyval['keyval']['entries'][j]['save'].call(obj[tempComponents[i]], value);
            			}
            		}
            		//button.keyval.sendProgramSrc(this.value)
            		
            	} );
	        	
	        	
	        	
        	}
    	}

    	$('.devObjView').draggable();
    	obj.UIDevObjInfoPanel = overlay;

    };
    

 
    return {};
});