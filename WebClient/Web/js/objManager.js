

define(function ( require ) {

    var Obj = require("obj");
    var webSocket = require('Network/webSocket');

    //var webGL = require('webGL');

    var _list = {};
    var _nextCreateObjRef = 0;
    var _createObjCallback = {};
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

    function getObjs(){
        return _list;
    }

    function getTemplateObjs() {
    	var ret = {};
        for (var ob in _list) {
            if (_list[ob].isTemplate)
                ret[_list[ob].id] = _list[ob]
        }
        return ret;
    }
    
    function createObj(callback) {
        _nextCreateObjRef += 1;
        _createObjCallback[_nextCreateObjRef] = callback;
        webSocket.handlers.modCreateObj(_nextCreateObjRef);
    }

    function modAddCompPowerBase(obj, callback) {
        //15 CompPowerBase
        obj.onGainComp(15, callback, true);
        webSocket.handlers.modAddCompPowerBase(obj, 15);
    }

    function gotObjCreated(objId, objCreateRef){
        if (objCreateRef in _createObjCallback) {
            tmpObj = new Obj(objId);
            _list[objId] = tmpObj;
            _createObjCallback[objCreateRef](tmpObj);
        }
    }

    function gotObjEnter(objId){
    	var tmpObj = getObjById(objId);

    	if(tmpObj == null){
            tmpObj = new Obj(objId);
            _list[objId] = tmpObj;
            for (var i in _UIEventCallback["ObjEnter"]){
                _UIEventCallback["ObjEnter"][i](tmpObj);
            }
            if(objId == 16777221 ){
	        for (var i in _UIEventCallback["PlayerObjEnter"]) {
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
            'gotObjCreated' : gotObjCreated,
            'hook' : hook,
            'getObjs' : getObjs,
            'getTemplateObjs' : getTemplateObjs,
            'createObj': createObj,
            'modAddCompPowerBase': modAddCompPowerBase
    };

});
