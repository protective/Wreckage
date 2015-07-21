define(function ( require ) {

	
    var webSocket = require('Network/webSocket');
    var UIKeyInput = require('UI/UIKeyInput');
    
    var CompSpellBook = require('Model/CompSpellBook');
    var objManager = require('objManager');
    var webGL = require('webGL');
    var Obj = require('obj');
    var _panels = {};
    

    
    var _playerTarget = null;
    
    var maindiv = webGL.container;
    
    require('UI/UINaveBar')(maindiv);
    
    //
    
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
    
    webGL.setOnClickCallback(setTarget);
 
    return {'init' : function(){
    	objManager.hook('PlayerObjEnter', setPlayerUnit);
    },
    	
    		'maindiv' : maindiv,
    		'setTarget' : setTarget,
    		'addPanel': addPanel};
});