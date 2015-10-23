define(function ( require ) {
	
    var webGL = require('webGL');
    var texture = THREE.ImageUtils.loadTexture( "textures/Sword.png" );
    var material = new THREE.SpriteMaterial( { map: texture, useScreenCoordinates: true , color: 0xffffff, fog: true } );
    
    var bufflist = {};
    
    function addBuff(target,
    		caster,
    		buffIndex,
    		duration,
    		maxduration,
    		charges,
    		imageIndex,
    		nameSIndex) {
    	
    	/*TODO implement */
    	var sprite = new THREE.Sprite( material );
    	
    	var width = material.map.image.width;
		var height = material.map.image.height;
    	
    	sprite.position.set(0, 300, 1);
    	sprite.scale.set(width, height, 1 );
    	bufflist[buffIndex] = sprite;
        sprite['animateTime'] = 3000;
        sprite['updateAnimation'] = function(delta) {
        
        }
        sprite['onClick'] = function(event) {
        	//TODO remove if buff
        	
        }
        webGL.sceneAddUISprite(sprite);
    	
    }
    	
    function removeBuff(target, buffIndex){
    	
    	webGL.sceneRemoveUISprite(bufflist[buffIndex]);
    }
    
    return {
    	'addBuff' : addBuff,
    	'removeBuff' : removeBuff
    	};
    
});