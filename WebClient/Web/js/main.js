
define(function ( require ) {

    var webSocket = require('Network/webSocket');
    
    //var SerialComp = require('Network/Comp/SerialComp')
    var msgObjEnter = require('Network/Comp/modelStatic/msgObjEnter');
    var msgSpellBook = require('Network/Comp/spellBook/msgSpellBook');
        
    msgObjEnter.call();
    msgSpellBook.call();
    
    webSocket.connect();
    
    
    var UIMain = require('UI/UIMain');
    
    var webGL = require('webGL');
    
    
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
