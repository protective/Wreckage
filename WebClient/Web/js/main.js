
define(function ( require ) {

    var webSocket = require('Network/webSocket');
    
    //var SerialComp = require('Network/Comp/SerialComp')
    require('Network/Comp/modelStatic/msgObjEnter').call();
    require('Network/Comp/spellBook/msgSpellBook').call();
    require('Network/Comp/targeted/msgCompTargeted').call();
    require('Network/msgObjAll').call();
           

    webSocket.connect();
    
    
    var UIMain = require('UI/UIMain');
	require('UI/Panels/UIDevObjInfoPanel');
	
    var webGL = require('webGL');
    
    
    webGL.initWebGL();
    UIMain.init();
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
