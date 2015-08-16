
define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        ],function ( require ) {

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
        	this.createHpPanel(this);
        	//UIDevObjInfoPanel.createObjInfoPanel(obj);

        };


        this.id = id;
        this.data = {}
        this.data[2] = 100;
        this.setData = function(type, value){
        	
        	this.data[type] = value;
        	
        	if (type == 1){
        		if('UIDevObjHpPanel' in this)
        			this.UIDevObjHpPanel.updateHp(value);
        	}
        }
        //TODO this should be dynamic
        //as not all unit have all components
		//require('Model/CompSpellBook').call(this);
    }
    
    return Obj;

});


