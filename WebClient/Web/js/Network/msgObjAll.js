define(function ( require ) {

    //var objManager = require("objManager");
    var webSocket = require('Network/webSocket');

    var objManager = require("../objManager");

    var ObjAll = function(block, len) {

        var objId = new Uint32Array(block.slice(0,4))[0];
        var xitem = new Uint32Array(block.slice(4,8))[0];
        var isTemplate = new Uint8Array(block.slice(8,9))[0];
        var obj = objManager.gotObjEnter(objId);
        obj['isTemplate'] = isTemplate ? true: false;
        for (var i = 9; i < len ; i+=8){
            var key = new Uint32Array(block.slice(i  ,i+4))[0];
        	var val = new Int32Array(block.slice(i+4,i+8))[0];        	
        	obj.data[key] = val;
    	}
    };

    function modCreateObj(objCreateRef) {
        var buffer = new ArrayBuffer(18);

        var dv = new DataView(buffer, 0);
        dv.setUint32(0, 100, true);
        dv.setUint32(4, 18, true);
        dv.setUint32(8, 0, true);
        dv.setUint32(12, objCreateRef, true);
        dv.setUint8(16, 1, true); //template = true
        dv.setUint8(17, 0, true); //persistent = false
        webSocket.send(buffer);
    }

    function modAddCompPowerBase(obj, compId) {
        var buffer = new ArrayBuffer(16);

        var dv = new DataView(buffer, 0);
        dv.setUint32(0, 6, true);
        dv.setUint32(4, 16, true);
        dv.setUint32(8, obj.id, true);
        dv.setUint32(12, compId, true);

        webSocket.send(buffer);
    }

    return function msgObjAll() {
        webSocket.hook("modAddCompPowerBase", modAddCompPowerBase);
        webSocket.hook("modCreateObj", modCreateObj);
        webSocket.hook(12, ObjAll);
    };
});
