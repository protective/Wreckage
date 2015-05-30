define(function ( require ) {

     
     
    var objManager = require("objManager")
    var componentHandles = {
        13 : require("Network/Comp/modelStatic/msgObjEnter")
    
    };
    
    function decode(len, block){
        
        var objId = new Uint32Array(block.slice(0,4))[0];
        var type = new Uint32Array(block.slice(4,8))[0];

        componentHandles[type].decode(len,objManager.getObjById(objId), block.slice(8));
    }
    
    function encode(  ){
       
        alert("got msg obj enter");
    }
   
    
    return {
            'encode': encode,
            'decode': decode
    };
});
