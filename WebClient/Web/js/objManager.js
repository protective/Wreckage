

define(function ( require ) {

    var Obj = require("obj");
    var webSocket = require('Network/webSocket');
    
    //var webGL = require('webGL');

    var _list = {};
    
    var _UIEventCallback = {};
    _UIEventCallback["ObjEnter"] = [];
    _UIEventCallback["PlayerObjEnter"] = [];
    _UIEventCallback["ObjPosUpdate"] = [];
    
    function addObj( obj ){
        _list.push(obj);
    }
    
    function removeObj( obj ){
    
    }
    
    function hook(event, callback){
    	_UIEventCallback[event].push(callback);
    }
    
    function gotObjEnter(objId){
    	var tmpObj = getObjById(objId);
    	
    	if(tmpObj == null){
    		tmpObj = new Obj(objId);
    		_list[objId] = tmpObj;
	    	for (var i in _UIEventCallback["ObjEnter"]){
	    		_UIEventCallback["ObjEnter"][i](tmpObj);
	    	}
	    	if(objId == 16777224 ){
		    	for (var i in _UIEventCallback["PlayerObjEnter"]){
		    		_UIEventCallback["PlayerObjEnter"][i](tmpObj);
		    	}	    		
	    	}	
    	}else{
	    	for (var i in _UIEventCallback["ObjPosUpdate"]){
	    		_UIEventCallback["ObjPosUpdate"][i](tmpObj);
	    	}
    	}
    	return tmpObj;
    }
    
    function gotObjFull(objId){
    	
    	
    }

    
    function getObjById(id) {
        if(id in _list)
            return _list[id];
        return null;
    }

    function Obj( id ) {
        this.id = id;    
    }
    

    return {
            'addObj': addObj,
            'getObjById': getObjById,
            'gotObjEnter' : gotObjEnter,
            'hook' : hook
    };

});
