define(function ( require ) {

    //var objManager = require("objManager");
    var webGL = require('webGL');
    var SerialComp = require('Network/Comp/SerialComp');
    //var Obj = require("obj");
    var objManager = require("../../../objManager");
    
    var objEnter = function(objId, block) {
    
        var x = new Uint32Array(block.slice(0,4))[0];
        var y = new Uint32Array(block.slice(4,8))[0];
        var z = new Uint32Array(block.slice(8,12))[0];
        
        var obj = objManager.getObjById(objId);
        obj['x'] = x / 50;
        obj['y'] = y / 50;
        obj['z'] = z / 50;
        
        
        webGL.addObj(obj);
    }

    var messageHandles = {1 : objEnter};

    function decode(obj, block){
    
        var op = new Uint32Array(block.slice(0,4))[0];
        messageHandles[op](obj, block.slice(4));
    }
    
    function encode(  ){
       
        alert("got msg obj enter");
    }
    return function msgObjEnter() {
        SerialComp.hook( 13, decode);
    };
});
