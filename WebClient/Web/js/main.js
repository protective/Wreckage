
define(function ( require ) {

    var webSocket = require('Network/webSocket');
    
    //var SerialComp = require('Network/Comp/SerialComp')
    require('Network/Comp/msgObjEnter').call();
    require('Network/Comp/msgCompSpellBook').call();
    require('Network/Comp/msgCompTargeted').call();
    require('Network/Comp/msgCompPowerUseCheck').call();
    require('Network/Comp/msgCompPowerDealDamage').call();
    require('Network/Comp/msgCompPowerActivateInstant').call();
    require('Network/Comp/msgCompPowerBase').call();
    require('Network/Comp/msgCompReSpawnable').call();
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
