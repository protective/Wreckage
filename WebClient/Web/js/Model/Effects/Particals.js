define(function ( require ) {
	
	var webGL = require('webGL');
	
	function dmg_animation(obj){
		var particleGroup = new SPE.Group({
				texture: {
		            value: THREE.ImageUtils.loadTexture('textures/smokeparticle.png')
		    }
		});
		
		emitter = new SPE.Emitter({
			type: SPE.distributions.SPHERE,
			particleCount: 1000,
			duration: 0.1,
		    maxAge: {
		        value: 0.5,
		        spread: 0.3
		    },
			position: {
		        value: new THREE.Vector3(obj.x, obj.y, obj.z),
		        radius: 1
		    },
		
			acceleration: {
				value: new THREE.Vector3( 0, 0, 0 ),
				distribution: SPE.distributions.BOX
		    },
		
			velocity: {
				value: new THREE.Vector3( 1 )
		    },
		
		    color: {
		        value: [ new THREE.Color('white'), new THREE.Color('red') ]
		    },
		
		    size: {
		        value: 0.7
		    }
		});
	
		particleGroup.addEmitter( emitter );
		particleGroup.mesh['animateTime'] = 1500;
		particleGroup.mesh['updateAnimation'] = function(delta) {
			particleGroup.tick( delta );
			this.animateTime -= delta * 1000
		}
			
		webGL.sceneAddDamageNotification(particleGroup.mesh);	
	}
	
	return {'dmg_animation' : dmg_animation};
});