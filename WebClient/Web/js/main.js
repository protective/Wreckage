
define(function (require) {
    var objManager = require('webGL');
    
    objManager.initWebGL();
    objManager.addObj();
    //objManager.render();

});

/*
require({
    baseUrl: './js/',
    paths: {
        jquery: 'jquery-1.11.2.min'
    }
},
['objManager'],
function(objManager) {
    alert("begin objManager")
    objManager.render(); 
 
 
});

*/
