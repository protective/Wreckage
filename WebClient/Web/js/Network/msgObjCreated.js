define(function ( require ) {

    var webSocket = require('Network/webSocket');
    var objManager = require("../objManager");

    var ObjCreated = function(block, len) {

        var objId = new Uint32Array(block.slice(0,4))[0];
        var createRef = new Uint32Array(block.slice(4,8))[0];
        objManager.gotObjCreated(objId, createRef);
    };

    return function msgObjAll() {
    	webSocket.hook(18, ObjCreated);
    };
});
