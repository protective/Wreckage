
define(function () {

    function Obj(id) {
    
        if (!(this instanceof Obj)) {
            throw new TypeError("Obj constructor cannot be called as a function.");
        }
    
        this.id = id;    
    }
    
    
    
    return Obj;

});


