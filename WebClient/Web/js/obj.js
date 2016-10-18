
define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'text!templates/spell.html'
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
            }else if (type == 12) {
            	if('UIDevObjHpPanel' in this)
                    this.UIDevObjHpPanel.updateMana(value);
            }
        }

        var _gainCompCallbacks = {};

        this.onGainComp = function (compId, callback, singleshot) {
            if (!(compId in _gainCompCallbacks))
            	_gainCompCallbacks[compId] = []
            _gainCompCallbacks[compId].push({'callback': callback,
            								   'singleshot': singleshot});    	
        };

        this.gainComp = function(compId) {
            if (compId in _gainCompCallbacks) {

            	for (i in _gainCompCallbacks[compId]) {
            		_gainCompCallbacks[compId][i]['callback'](this);                
            	}
            	_gainCompCallbacks[compId].filter(function( dict ) {
            	    return dict.singleshot == false;
            	});
            }};
    }
    return Obj;
});


