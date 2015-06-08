define( ['jquery'], function( jQuery )
{
	
    var webSocket = require('Network/webSocket');
    
    
    
    var _handlers = {};
    
    $(document).keydown(function(e) {
    	
    	if (e.which in _handlers){
    		_handlers[e.which](e);
    	}
    	
    	
    	
        switch(e.which) {
            case 37: // left
            break;

            case 38: // up
            break;

            case 39: // right
            break;

            case 40: // down
            break;

            default: return; // exit this handler for other keys
        }
        e.preventDefault(); // prevent the default action (scroll / move caret)
    });
    
    
    
    function hookKey(key, callback){
    	_handlers[key] = callback;
    }
     
    return {'hookKey' : hookKey};
});