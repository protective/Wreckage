

define(function ( require ) {

    var Obj = require("obj");
    var webSocket = require('Network/webSocket');
    
    //var webGL = require('webGL');

    var _list = {};
    
    
    
    function addObj( obj ){
        _list.push(obj);
    }
    
    function removeObj( obj ){
    
    }
    
    function getObjById(id) {
        if(id in _list)
            return _list[id];
        else
            return _list[id] = new Obj(id);
    }

    function Obj( id ) {
        this.id = id;    
    }
    

    return {
            'addObj': addObj,
            'getObjById': getObjById
    };

});
