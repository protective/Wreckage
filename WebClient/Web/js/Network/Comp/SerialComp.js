define(function ( require ) {

     
    
    var webSocket = require('Network/webSocket');


    var componentHandles = {};
    
    function hook(type,callback){
        webSocket.hook(0x09, decode )
        componentHandles[type] = callback;
    }
    
    function decode(block, len){
        
        var objId = new Uint32Array(block.slice(0,4))[0];
        var type = new Uint32Array(block.slice(4,8))[0];

        componentHandles[type](objId, block.slice(8));
    }
    
    function encode(  ){
       
        alert("got msg obj enter");
    }
   
    
    return {'hook' : hook};
});
