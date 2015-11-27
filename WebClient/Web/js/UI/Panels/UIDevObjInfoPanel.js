define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'UI/UIMain',
        'Model/CompSpellBook',
        'Model/CompTargeted',
        'obj',
        'text!templates/keyValueTable.html',
        'text!templates/hpbar.html'],function ( require) {

    var _panels = {};
    
    var UIMain = require('UI/UIMain');
    var CompSpellBook = require('Model/CompSpellBook');
    var CompTargeted = require('Model/CompTargeted');
    var Obj = require('obj');

	var keyValueTable = require('text!templates/keyValueTable.html');
	var hpBarTable = require('text!templates/hpbar.html');

	var tmp3 = $('body');
	tmp3.on('keydown', '.mytextarea', function(event) {

	});

    Obj.prototype.createHpPanel = function (obj) {
    	if('UIDevObjHpPanel' in obj)
    		return;
        var a = {'id' : obj.id};
        this.UIbars = _.template(hpBarTable)(a);

        var parser = new DOMParser()
        , doc = parser.parseFromString(this.UIbars, "text/html");

        var overlay = doc.firstChild;
        UIMain.maindiv.appendChild(overlay);

        obj.UIDevObjHpPanel = overlay;
        
        
        obj.UIDevObjHpPanel.updateHp = function(value){
        	if(2 in obj.data && obj.data[2] > 0){
	        	var tmp = $('#objId'+ obj.id + '.rcorners1').find('#hpbar');
	        	var tmp2 = $('#objId'+ obj.id + '.rcorners1').find('#hpbarlab');
	        	tmp2[0].textContent = value;
	        	var p = 100 - ((value / obj.data[2]) * 100);
	        	p = Math.min(Math.max(p, 0),100);
	        	tmp[0].style['padding-right'] = p +'%';
        	}
        };
        
        obj.UIDevObjHpPanel.updateHp(obj.data[1]);
    }
    	
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
    	                      'compPowerBase',
    	                      'compProgramable'];
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
	        	button.compName = tempComponents[i];
	        	button.myhest = function(){alert(1);};

	        	button.innerHTML = tempComponents[i];
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
            		var compName = button.compName;
            		for (var j in button.keyval['keyval']['entries']){
            			if (button.keyval['keyval']['entries'][j]['save']){
            				var value = $('#comfield' + j + button.id)[0].value;    
            				
            				button.keyval['keyval']['entries'][j]['save'].call(obj[compName], value);
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