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
    
    function encodeAddPower(obj, powerId) {
    	var buffer = new ArrayBuffer(26);
    	var dv = new DataView(buffer, 0);
    	dv.setUint32(0, 7, true); //cmdindput
    	dv.setUint32(4, 26, true); //length
    	dv.setUint32(8, obj.id, true); //InputObj
    	dv.setUint16(12, 3, true); //AddCompValue
    	dv.setUint16(14, 10, true); //inputlength
    	dv.setUint32(16, 4, true); //compid
    	dv.setUint16(20, 1, true); //knownpowers
    	dv.setUint32(22, powerId, true); //powerobjid

    	webSocket.send(buffer);
    }

    function encodeRemovePower(obj, powerId) {
    	var buffer = new ArrayBuffer(26);
    	var dv = new DataView(buffer, 0);
    	dv.setUint32(0, 7, true); //cmdindput
    	dv.setUint32(4, 26, true); //length
    	dv.setUint32(8, obj.id, true); //InputObj
    	dv.setUint16(12, 4, true); //RemoveCompValue
    	dv.setUint16(14, 10, true); //inputlength
    	dv.setUint32(16, 4, true); //compid
    	dv.setUint16(20, 1, true); //knownpowers
    	dv.setUint32(22, powerId, true); //powerobjid

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
        	if (powerid == 0)
        		powerid = templatePowerid;
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
