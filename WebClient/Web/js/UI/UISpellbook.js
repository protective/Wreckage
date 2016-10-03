define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'UI/UIMain',
        'obj',
        'text!templates/spell.html',
        'text!templates/spellbar.html'
        ], function ( require ) {
	
    var webGL = require('webGL');
    var UIMain = require('UI/UIMain');
    var Obj = require('obj');
    
    var texture = THREE.ImageUtils.loadTexture( "textures/Sword.png" );
    var material = new THREE.SpriteMaterial( { map: texture, useScreenCoordinates: true , color: 0xffffff, fog: true } );
    
    var spellHtml = require('text!templates/spell.html');
    var spellbarHtml = require('text!templates/spellbar.html');
    var Xslot = 0;
    
    var powerlist = {};
    var spellbar = null;
    var ui_obj = null;
    function createSpellBookPanel(obj) {

    	ui_obj = obj;
        var b = _.template(spellbarHtml)({});
        
        var parser = new DOMParser(),
        doc = parser.parseFromString(b, "text/html");
        
        var overlay = doc.childNodes[0].childNodes[1].childNodes[0];
        spellbar = overlay;
        UIMain.maindiv.appendChild(overlay);
    }
    
    function addAvilPower(powerId) {
    
        var a = {'spellId' : powerId};
        var b = _.template(spellHtml)(a);
        
        var parser = new DOMParser(),
        doc = parser.parseFromString(b, "text/html");
        
        var powerDiv = doc.childNodes[0].childNodes[1].childNodes[0];
        
        var node = spellbar.rows[0].insertCell(0);
        node.appendChild(powerDiv);
        
    	var img = ($('#objId'+ powerId + '.spellBox').find('#spellImage'))[0];
        var newImg = new Image;
        newImg.onload = function() {
        	img.src = this.src;
        }
        newImg.src = 'textures/Sword.png';
    	var borderDiv = ($('#objId'+ powerId + '.spellBox'))[0];

        var uiSpellBtnObject = {
        		'setActive': function()
				{
        			borderDiv.classList.remove("spellBoxReady");
        			borderDiv.classList.add("spellBoxActive");
        		},
				'setReady': function()
				{
					borderDiv.classList.remove("spellBoxActive");
					borderDiv.classList.add("spellBoxReady");
				}
        		
        };
        
        img.addEventListener("click", function() {
        	ui_obj.compSpellBook.castSpellTarget(
        			UIMain.getPlayerTarget(), powerId);
	
        }, true);
        
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
    
    Obj.prototype.castSpell = function (obj, target, powerId, effectId, hardpoint) {
    	var a = powerlist[powerId];
    	a.setReady();
    }
    return {
    	'addAvilPower' : addAvilPower,
    	'activatePower' : activatePower,
    	'rmPower' : rmPower,
    	'createSpellBookPanel': createSpellBookPanel};
    		
});