define(function ( require ) {

	var webSocket = require('Network/webSocket');
    var SerialComp = require('Network/Comp/SerialComp');
    var objManager = require("../../objManager");

    function encodeSetStr(obj, field, value){

        len = value.length;

        var buffer = new ArrayBuffer(26 + len);

    	var dv = new DataView(buffer, 0);
        dv.setUint32(0, 7, true);
        dv.setUint32(4, 26 + len, true);
        dv.setUint32(8, obj.id, true);
        dv.setUint16(12, 2, true);//setfield //2
        dv.setUint16(14, 14 + len, true); //inputlength //2
        dv.setUint32(16, 15, true); //compid
        dv.setUint16(20, field, true); //fieldId == program //3
        dv.setUint32(22, len, true); //textLen

	    for (var i=0; i < value.length; i++) {
			if(value.charCodeAt(i) <= 255)
				dv.setUint8(26 + i, value.charCodeAt(i));
			else
				dv.setUint8(26 + i, 0);
		}	
    	webSocket.send(buffer);
    }

    function encodeSetProgram(obj, programSrc){
        encodeSetStr(obj, 3, programSrc);
    }

    function encodeSetName(obj, name){
        encodeSetStr(obj, 1, name);
    }

    function encodeSetDescription(obj, description){
        encodeSetStr(obj, 2, description);
    }

    function saveAll(obj, name, description, programSrc){
        encodeSetProgram(obj, programSrc);
        encodeSetName(obj, name);
        encodeSetDescription(obj, description);
    }

    var full = function(objId, block) {

        var obj = objManager.gotObjEnter(objId);

        lenName = new Uint16Array(block.slice(0,2))[0];
        lenDesciption = new Uint16Array(block.slice(2,4))[0];
        lenProgramSrc = new Uint16Array(block.slice(4,6))[0];

        namearr = new Uint8Array(block.slice(6, 6 + lenName));
        descarr = new Uint8Array(block.slice(6 + lenName ,6 + lenName + lenDesciption));
        programSrcarr = new Uint8Array(block.slice(6 + lenName + lenDesciption ,6 + lenName + lenDesciption + lenProgramSrc));

        var namestr = String.fromCharCode.apply(null, namearr);
        var descstr = String.fromCharCode.apply(null, descarr);
        var programSrcstr = String.fromCharCode.apply(null, programSrcarr);
        require('Model/CompPowerBase').call(obj, namestr, descstr, programSrcstr);
    }

    var messageHandles = {1 : full};

    function decode(obj, block){
        var op = new Uint32Array(block.slice(0,4))[0];
        messageHandles[op](obj, block.slice(4));
    }

    return function msg() {
        webSocket.hook("CompPowerBaseSave", saveAll);
        SerialComp.hook(15, decode);
    };
});
