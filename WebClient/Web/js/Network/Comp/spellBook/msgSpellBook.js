define(function ( require ) {

	var webSocket = require('Network/webSocket');
  

    function encodeCastSpellTarget(caster, target, spellId){
       
    	alert("send " + caster.id + " " + target.id + " " + spellId);
    	webSocket.send("xyz");
    }
    
    return function msgSpellBook() {
    	webSocket.hook("castSpellTarget", encodeCastSpellTarget )
    };
});
