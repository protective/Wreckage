define(function ( require ) {

    //var objManager = require("objManager");
    var webSocket = require('Network/webSocket');

    var objManager = require("../objManager");
    
    var ObjAll = function(block, len) {
    
        var objId = new Uint32Array(block.slice(0,4))[0];
        var xitem = new Uint32Array(block.slice(4,8))[0];
        var obj = objManager.gotObjEnter(objId);
        
        for (var i = 8; i < len ; i+=8){
            var key = new Uint32Array(block.slice(i  ,i+4))[0];
        	var val = new Int32Array(block.slice(i+4,i+8))[0];        	
        	obj.data[key] = val;
    	}
    };

    
    function encode(  ){
       
        alert("got msg obj enter");
    }
    return function msgObjAll() {
    	webSocket.hook( 12, ObjAll);
    };
});
