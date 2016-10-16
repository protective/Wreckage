define(function ( require ) {

    //var objManager = require("objManager");
    var webSocket = require('Network/webSocket');

    var objManager = require("../objManager");
    var webGL = require('webGL');
    var UIDamageNotification = require('UI/UIDamageNotification');
    var Particals = require('Model/Effects/Particals');
    
    var UIBuffBar = require('UI/UIBuffBar');
 
    var targetStatChange = function(block, len) {
    	var result = new Uint32Array(block.slice(0,4))[0];  
        var target = new Uint32Array(block.slice(4,8))[0];  
        var caster = new Uint32Array(block.slice(8,12))[0];
        var noStats = new Uint8Array(block.slice(12,13))[0];
        var noEffect = new Uint8Array(block.slice(13,14))[0];
        var gfxref = new Uint8Array(block.slice(14,15))[0];
        var obj = objManager.getObjById(target);
        
        var _ssize = 12;
        for (i = 0; i < noStats; i++) {
            var statType = new Uint32Array(block.slice(15 + (_ssize * i), 19 + (_ssize * i)))[0];
            var oldVal = new Int32Array(block.slice(19 + (_ssize * i), 23 + (_ssize * i)))[0];
            var newVal = new Int32Array(block.slice(23 + (_ssize * i), 27 + (_ssize * i)))[0];	
            if(statType == 1){
            	var damageHealingDone = oldVal - newVal;
    	        UIDamageNotification.createDamangeNotification(obj, damageHealingDone, result);
    	    }
        }
        var offset = 15 + (noStats * _ssize);
        var _esize = 9;
        for (i = 0; i < noStats; i++) {
            var effect = new Uint32Array(block.slice(0 + (_esize * i) + offset, 4 + (_esize * i) + offset))[0];
            var hardpoint = new Uint8Array(block.slice(4 + (_esize * i) + offset, 5 + (_esize * i) + offset))[0];	
            Particals.dmg_animation(obj, effect, hardpoint);
    	    
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
    
    var beginCast = function(block, len) {

        var caster = new Uint32Array(block.slice(0,4))[0];
        var powerId = new Uint32Array(block.slice(4,8))[0];
        var target = new Uint32Array(block.slice(8,12))[0];
        var beginTime = new Uint32Array(block.slice(12,16))[0];
        var endTime = new Uint32Array(block.slice(16,20))[0];
        var obj = objManager.getObjById(caster);
        
        obj.activateCastBar(obj, target, powerId, beginTime, endTime);
        obj.activateSpell(obj, target, powerId, beginTime, endTime);
    };
    
    var cast = function(block, len) {

        var caster = new Uint32Array(block.slice(0,4))[0];
        var powerId = new Uint32Array(block.slice(4,8))[0];
        var target = new Uint32Array(block.slice(8,12))[0];
        var gfxRef = new Uint8Array(block.slice(12,13))[0];
        var gfxNoEffects = new Uint8Array(block.slice(13,14))[0];
        var effectId = 0;
        var hardpoint = 0;
        if (gfxNoEffects == 1){
        	effectId = new Uint32Array(block.slice(14,18))[0];
        	hardpoint = new Uint8Array(block.slice(18,19))[0];
        }
        var obj = objManager.getObjById(caster);
        
        obj.castSpell(obj, target, powerId, effectId, hardpoint);
    };
    
    return function msghook() {
        webSocket.hook(13, targetStatChange);
        webSocket.hook(14, targetGainBuff);
        webSocket.hook(15, targetLoseBuff);
        webSocket.hook(16, beginCast);
        webSocket.hook(17, cast);
    };
});
