define(function ( require ) {

	var webSocket = require('Network/webSocket');
  

    function encodeCastSpellTarget(caster, target, spellId){
       
    	alert("send " + caster.id + " " + target.id + " " + spellId);
    	
    	spellId = 16777224;
    	var buffer = new ArrayBuffer(24);
    	var base = new Uint32Array(buffer);
    	base[0] = 7; //cmdindput
    	base[1] = 24; //length
    	base[2] = spellId; //InputObj
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
    
    return function msgSpellBook() {
    	webSocket.hook("castSpellTarget", encodeCastSpellTarget )
    };
});
