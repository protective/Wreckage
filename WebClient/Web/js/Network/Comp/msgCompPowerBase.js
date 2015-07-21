define(function ( require ) {

	var webSocket = require('Network/webSocket');
    var SerialComp = require('Network/Comp/SerialComp');
    var objManager = require("../../objManager");
    
    
    function encodeSetProgram(obj, programSrc){
        
    	len = programSrc.length;

    	var buffer = new ArrayBuffer(26 + len);
    	
    	var dv = new DataView(buffer, 0);
    	dv.setUint32(0, 7, true);
    	dv.setUint32(4, 26 + len, true);
    	dv.setUint32(8, obj.id, true);
    	
    	dv.setUint16(12, 2, true);//setfield //2
    	dv.setUint16(14, 14 + len, true); //inputlength //2
    	
    	dv.setUint32(16, 15, true); //compid
    	dv.setUint16(20, 3, true); //fieldId == program //3

    	dv.setUint32(22, len, true); //textLen
    	
		for (var i=0; i<programSrc.length; i++) {
			if(programSrc.charCodeAt(i) <= 255)
				dv.setUint8(26 + i, programSrc.charCodeAt(i));
			else
				dv.setUint8(26 + i, 0);
		}	
    	
    	webSocket.send(buffer);
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
    	webSocket.hook("CompPowerBaseSetProgram", encodeSetProgram )

        SerialComp.hook(15, decode);
    };
});
