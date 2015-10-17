define(function ( require ) {
	
    var webGL = require('webGL');
    
    
    var texture = THREE.ImageUtils.loadTexture( "textures/Sword.png" );
    var material = new THREE.SpriteMaterial( { map: texture, useScreenCoordinates: true , color: 0xffffff, fog: true } );
    
    var Xslot = 0;
    
    var powerlist = [];
    
    function createSpellBookPanel() {
    	
    }
    
    function addAvilPower(powerId) {
    	var sprite = new THREE.Sprite( material );
    	
    	var width = material.map.image.width;
		var height = material.map.image.height;
    	
    	sprite.position.set(Xslot, 200, 1);
    	sprite.scale.set(width, height, 1 );
    	Xslot+=65;
    	powerlist.push(sprite);
        sprite['animateTime'] = 3000;
        sprite['updateAnimation'] = function(delta) {
        
        }
        sprite['onClick'] = function(event) {
        	//TODO cast power
        	
        }
        webGL.sceneAddUISprite(sprite);
    }
    
    function activatePower(compPowerBase) {
    
    }
    function rmPower(compPowerBase) {
    
    }
    return {
    	'addAvilPower' : addAvilPower,
    	'activatePower' : activatePower,
    	'rmPower' : rmPower};
    		
});