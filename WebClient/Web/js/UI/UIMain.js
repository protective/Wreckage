define(function ( require ) {

	
    var webSocket = require('Network/webSocket');
    var UIKeyInput = require('UI/UIKeyInput');
    var UIBuffBar = require('UI/UIBuffBar');
    var CompSpellBook = require('Model/CompSpellBook');
    var objManager = require('objManager');
    var webGL = require('webGL');
    var Obj = require('obj');
    var _panels = {};
    

    var _playerId = null;
    var _playerTarget = null;
    var ret = {'maindiv': webGL.container};

    require('UI/UINaveBar')(ret);
    require('UI/Panels/UIPowerListPanel')(ret);
    require('UI/Panels/UIDevObjInfoPanel')(ret);
    
    function castspell() {
    	_playerObj.compSpellBook.castSpellTarget(_playerTarget);
    }

    function setPlayerUnit(obj) {
    	_playerObj = obj;
    	UIKeyInput.hookKey(81,castspell);
    	//UIKeyInput.hookKey(87,setCompPowerBaseProgram);
    }
     
    function setTarget(obj) {
    	_playerTarget = obj;
    }
    Obj.prototype.targetMe = setTarget;
    
    function addPanel(id, panel) {
    	_panels[id] = panel;
    }
    
    function getPlayerTarget(){
    	return _playerTarget;
    }
    
    webGL.setOnClickCallback(setTarget);
 
    ret['init'] = function(){
    	objManager.hook('PlayerObjEnter', setPlayerUnit);};

    ret['setTarget'] = setTarget;
    ret['addPanel'] = addPanel;
    ret['getPlayerTarget'] = getPlayerTarget;
    
    return ret
});