define(function ( require ) {

    //var objManager = require("objManager");
    var webSocket = require('Network/webSocket');

    var objManager = require("../objManager");
    var webGL = require('webGL');
    var UIDamageNotification = require('UI/UIDamageNotification');
    
    var UIBuffBar = require('UI/UIBuffBar');
 
    var targetStatChange = function(block, len) {
    	
        var statType = new Uint32Array(block.slice(0,4))[0];
        var target = new Uint32Array(block.slice(4,8))[0];  
        var caster = new Uint32Array(block.slice(8,12))[0];
        var result = new Uint32Array(block.slice(12,16))[0];
        var oldVal = new Int32Array(block.slice(16,20))[0];
        var newVal = new Int32Array(block.slice(20,24))[0];
       
        var obj = objManager.getObjById(target);
        if(statType == 1){
        var damageHealingDone = oldVal - newVal;
	        UIDamageNotification.createDamangeNotification(obj, damageHealingDone, result);
	    }
        obj.setData(statType, newVal)
        //.;
    };

    var targetGainBuff= function(block, len) {

        var target = new Uint32Array(block.slice(0,4))[0];
        var caster = new Uint32Array(block.slice(4,8))[0];  
        var buffIndex = new Uint32Array(block.slice(8,12))[0];
        var duration = new Uint32Array(block.slice(12,16))[0];
        var maxDuration = new Uint32Array(block.slice(16,20))[0];
        var charges = new Uint32Array(block.slice(20,24))[0];
        var imageIndex = new Uint32Array(block.slice(24,28))[0];
        var nameSIndex = new Uint32Array(block.slice(28,32))[0];
               
        UIBuffBar.addBuff(target,
        		caster,
        		buffIndex,
        		duration,
        		maxDuration,
        		charges,
        		imageIndex,
        		nameSIndex)
    };
    
    var targetLoseBuff= function(block, len) {

        var target = new Uint32Array(block.slice(0,4))[0];
        var buffIndex = new Uint32Array(block.slice(4,8))[0];
      
        UIBuffBar.removeBuff(target, buffIndex)
    };
    
    return function msghook() {
    	webSocket.hook( 13, targetStatChange);
    	webSocket.hook( 14, targetGainBuff);
    	webSocket.hook( 15, targetLoseBuff);
    };
});
