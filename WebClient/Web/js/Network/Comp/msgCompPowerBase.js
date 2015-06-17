define(function ( require ) {

    var SerialComp = require('Network/Comp/SerialComp');
    var objManager = require("../../objManager");
    
    var full = function(objId, block) {
    
        var obj = objManager.gotObjEnter(objId);
        
        lenName = new Uint16Array(block.slice(0,2))[0];
        lenDesciption = new Uint16Array(block.slice(2,4))[0];
        
        namearr = new Uint8Array(block.slice(4,4 + lenName));
        descarr = new Uint8Array(block.slice(4 + lenName ,4 + lenName + lenDesciption));
        
        var namestr = String.fromCharCode.apply(null, namearr);
        var descstr = String.fromCharCode.apply(null, descarr);
        require('Model/CompPowerBase').call(obj, namestr, descstr);
    }

    var messageHandles = {1 : full};

    function decode(obj, block){
        var op = new Uint32Array(block.slice(0,4))[0];
        messageHandles[op](obj, block.slice(4));
    }

    return function msg() {
        SerialComp.hook(15, decode);
    };
});
