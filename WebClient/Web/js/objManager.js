

define(function ( require ) {

    var obj = require(obj)


    var _list = [];
    
    
    
    function addObj( obj ){
        _list.push(obj);
    }
    
    function removeObj( obj ){
    
    }

    function Obj( id ) {
        this.id = id;    
    }
    
    
    function render( gl, modelView, projection ){
    
        for (i = 0; i < _list.length; i++) {
        
            //_list[i].render(modelVIew, projection);
        
        }
    
    }
    

});
