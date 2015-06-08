
define(function ( require ) {

	
    function Obj(id) {
    	this.onclickCallbacks = [];
        if (!(this instanceof Obj)) {
            throw new TypeError("Obj constructor cannot be called as a function.");
        }
        
        this.onClick = function (){
        	if (this.targetMe != null)
        		this.targetMe(this);
        };
    
        this.id = id;
        
        //TODO this should be dynamic
        //as not all unit have all components
		require('Model/CompSpellBook').call(this);
    }
    
    
    
    
    
    return Obj;

});


