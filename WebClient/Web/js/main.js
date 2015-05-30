
define(function (require) {


    var webGL = require('webGL');
    var networkSock = require('Network/webSocket')
    
    webGL.initWebGL();
    //webGL.addObj();
    webGL.render();

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
