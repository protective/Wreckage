define(function ( require ) {

    var SerialComp = require('Network/Comp/SerialComp');
    var objManager = require("../../../objManager");
    
    var full = function(objId, block) {
    
        var obj = objManager.gotObjEnter(objId);
        require('Model/CompTargeted').call(obj);
    }

    var messageHandles = {1 : full};

    function decode(obj, block){
        var op = new Uint32Array(block.slice(0,4))[0];
        messageHandles[op](obj, block.slice(4));
    }

    return function msgCompTargeted() {
        SerialComp.hook(12, decode);
    };
});
