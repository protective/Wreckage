define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'UI/UIMain',
        'obj',
        'text!templates/spell.html'
        ], function ( require ) {
	
    var webGL = require('webGL');
    var UIMain = require('UI/UIMain');
    var Obj = require('obj');
    
    var texture = THREE.ImageUtils.loadTexture( "textures/Sword.png" );
    var material = new THREE.SpriteMaterial( { map: texture, useScreenCoordinates: true , color: 0xffffff, fog: true } );
    
    var spellHtml = require('text!templates/spell.html');
    
    var Xslot = 0;
    
    var powerlist = {};
    
    function createSpellBookPanel() {
    	
    }
    
    function addAvilPower(powerId) {
    
        var a = {'spellId' : powerId};
        var b = _.template(spellHtml)(a);
        
        var parser = new DOMParser(),
        doc = parser.parseFromString(b, "text/html");
        
        var overlay = doc.firstChild;

        UIMain.maindiv.appendChild(overlay);
        
    	var img = ($('#objId'+ powerId + '.spellBox').find('#spellImage'))[0];
        var newImg = new Image;
        newImg.onload = function() {
        	img.src = this.src;
        }
        newImg.src = 'textures/Sword.png';
    	var borderDiv = ($('#objId'+ powerId + '.spellBox').find('div'))[0];

        var uiSpellBtnObject = {
        		'setActive': function()
        						{
				        			borderDiv.className = "spellBoxActive";
				        		}
        		
        };
        powerlist[powerId] = uiSpellBtnObject;
    }

    
    function activatePower(compPowerBase) {
    
    }
    function rmPower(compPowerBase) {
    
    }
    
    Obj.prototype.activateSpell = function (obj, target, powerId, beginTime, endTime) {
    	var a = powerlist[powerId];
    	a.setActive();
    }
    
    return {
    	'addAvilPower' : addAvilPower,
    	'activatePower' : activatePower,
    	'rmPower' : rmPower};
    		
});