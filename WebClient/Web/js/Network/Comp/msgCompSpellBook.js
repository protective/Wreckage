define(function ( require ) {

	var webSocket = require('Network/webSocket');
    var SerialComp = require('Network/Comp/SerialComp');	
    var objManager = require("../../objManager");
      

    function encodeCastSpellTarget(caster, target, spellId){
       
    	spellId = 16777223;
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
    
    var full = function(objId, block) {
        var obj = objManager.gotObjEnter(objId);
        require('Model/CompSpellBook').call(obj);
    }
    
    var messageHandles = {1 : full};

    function decode(obj, block){
        var op = new Uint32Array(block.slice(0,4))[0];
        messageHandles[op](obj, block.slice(4));
    }
    
    return function msgSpellBook() {
    	webSocket.hook("castSpellTarget", encodeCastSpellTarget )
    	SerialComp.hook(4, decode);
    };
});
