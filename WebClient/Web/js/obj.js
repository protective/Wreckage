
define(function ( require ) {

	
	var webGL = require('webGL');
	//var UIDevObjInfoPanel = require('UI/Panels/UIDevObjInfoPanel');
	
    function Obj(id) {
    	this.onclickCallbacks = [];
        if (!(this instanceof Obj)) {
            throw new TypeError("Obj constructor cannot be called as a function.");
        }
        
        this.UIcalls = {};
        this.onClick = function (){
        	if (this.targetMe != null)
        		this.targetMe(this);
        	
        	//this.UIcalls['createObjInfoPanel'](obj);
        	this.createObjInfoPanel(this);
        	//UIDevObjInfoPanel.createObjInfoPanel(obj);

        };
    
        this.id = id;
        this.data = {}
        //TODO this should be dynamic
        //as not all unit have all components
		require('Model/CompSpellBook').call(this);
    }
    
    return Obj;

});


