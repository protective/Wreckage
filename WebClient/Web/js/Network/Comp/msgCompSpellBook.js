define(function ( require ) {

	var webSocket = require('Network/webSocket');
    var SerialComp = require('Network/Comp/SerialComp');	
    var objManager = require("../../objManager");
    var UISpellbook = require('UI/UISpellbook');
    

    function encodeCastSpellTarget(caster, target, spellId){
       
    	spellId = spellId;
    	var buffer = new ArrayBuffer(24);
    	var base = new Uint32Array(buffer);
    	base[0] = 7; //cmdindput
    	base[1] = 24; //length
    	base[2] = caster.id; //InputObj
    	var cast16View = new Uint16Array(buffer, 12);
    	cast16View[0] = 1 //castPower
    	cast16View[1] = 8 //inputlength
    	var data32View = new Uint32Array(buffer, 16);
    	data32View[0] = spellId //powerobjid
    	data32View[1] = target.id //target
    	var cast16View2 = new Uint16Array(buffer);
    	var data32View2 = new Uint32Array(buffer);
    	webSocket.send(buffer);
    }
    
    function encodeAddPower(spellbook, powerId) {
    	spellId = spellId;
    	var buffer = new ArrayBuffer(22);
    	var base = new Uint32Array(buffer);
    	base[0] = 7; //cmdindput
    	base[1] = 24; //length
    	base[2] = spellbook.id; //InputObj
    	var cast16View = new Uint16Array(buffer, 12);
    	cast16View[0] = 3 //AddCompValue
    	cast16View[1] = 6 //inputlength
    	cast16View[2] = 1 //knownpowers
    	var data32View = new Uint32Array(buffer, 18);
    	data32View[0] = powerId //powerobjid

    	webSocket.send(buffer);
    }

    function encodeRemovePower(spellbook, powerId) {
    	spellId = spellId;
    	var buffer = new ArrayBuffer(22);
    	var base = new Uint32Array(buffer);
    	base[0] = 7; //cmdindput
    	base[1] = 24; //length
    	base[2] = spellbook.id; //InputObj
    	var cast16View = new Uint16Array(buffer, 12);
    	cast16View[0] = 4 //RemoveCompValue
    	cast16View[1] = 6 //inputlength
    	cast16View[2] = 1 //knownpowers
    	var data32View = new Uint32Array(buffer, 18);
    	data32View[0] = powerId //powerobjid

    	webSocket.send(buffer);
    }    
    
    var full = function(obj, block) {
    	var size = 14;
        UISpellbook.createSpellBookPanel(obj);
        var dv = new DataView(block, 0);
        var len = dv.getUint16(0, true);
        var powers = new Array();
        for (var i = 0; i< len; i++ ){
        	var powerid = dv.getUint32(2 + (i * size), true);
        	var templatePowerid = dv.getUint32(6 + (i * size), true);
        	var powerFlags = dv.getUint32(10 + (i * size), true);
        	var powerlevel = dv.getUint16(14 + (i * size), true);
        	powers[powerid] = {
        			'template': templatePowerid,
        			'flags': powerFlags,
        			'level': powerlevel};
        	UISpellbook.addAvilPower(powerid);
        }
        require('Model/CompSpellBook').call(obj, powers);
    }
    
    var messageHandles = {1 : full};

    function decode(obj, block){
        var op = new Uint32Array(block.slice(0,4))[0];
        messageHandles[op](obj, block.slice(4));
    }
    
    return function msgSpellBook() {
    	webSocket.hook("castSpellTarget", encodeCastSpellTarget);
    	webSocket.hook("sendAddPower", encodeAddPower);
    	webSocket.hook("sendRemovePower", encodeRemovePower);
    	SerialComp.hook(4, decode);
    };
});
