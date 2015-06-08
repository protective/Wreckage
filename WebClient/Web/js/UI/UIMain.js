define(function ( require ) {

	
    var webSocket = require('Network/webSocket');
    var UIKeyInput = require('UI/UIKeyInput');
    var CompSpellBook = require('Model/CompSpellBook');
    var objManager = require('objManager');
    var webGL = require('webGL');
    var Obj = require('obj');
    
    
    var _playerObj = null;
    var _playerTarget = null;
    
    
    objManager.hook('PlayerObjEnter', setPlayerUnit)
    
    function castspell() {
    	_playerObj.compSpellBook.castSpellTarget(_playerTarget);
    }
    
    function setPlayerUnit(obj) {
    	_playerObj = obj;
    	UIKeyInput.hookKey(81,castspell);	
    }
     
    function setTarget(obj) {
    	_playerTarget = obj;
    }
    Obj.prototype.targetMe = setTarget;
    
    webGL.setOnClickCallback(setTarget);
 
    return {'setTarget' : setTarget};
});