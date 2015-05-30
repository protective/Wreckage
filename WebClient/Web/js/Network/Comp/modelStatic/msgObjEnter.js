define(function ( require ) {


    objManager = require("objManager");
    var webGL = require('webGL');



    var objEnter = function(obj, block) {
    
        var x = new Uint32Array(block.slice(0,4))[0];
        var y = new Uint32Array(block.slice(4,8))[0];
        var z = new Uint32Array(block.slice(8,12))[0];
        
        obj['x'] = x / 50;
        obj['y'] = y / 50;
        obj['z'] = z / 50;
        webGL.addObj( obj.x, obj.y, obj.z);
    }

    var messageHandles = {1 : objEnter};
    

    function decode(len, obj, block){
    
        var op = new Uint32Array(block.slice(0,4))[0];
        messageHandles[op](obj, block.slice(4));
    }
    
    function encode(  ){
       
        alert("got msg obj enter");
    }
    return {
            'encode': encode,
            'decode': decode
    };
});
