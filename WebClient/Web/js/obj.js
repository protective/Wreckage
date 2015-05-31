
define(function ( require ) {

    function Obj(id) {
    
        if (!(this instanceof Obj)) {
            throw new TypeError("Obj constructor cannot be called as a function.");
        }
        
        this.onClick = function (){
            alert("clicked");
        };
    
        this.id = id;    
    }
    
    
    
    return Obj;

});


