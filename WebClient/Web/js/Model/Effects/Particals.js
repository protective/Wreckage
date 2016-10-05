define(function ( require ) {

	var webGL = require('webGL');

	var anim = {
	1: { //firebolt1
		animtime: 1500,
		particleCount: 1000,
		duration: 0.1,
		maxAge: {
	        value: 0.5,
	        spread: 0.3
    	},
		velocity: {dist: SPE.distributions.SPHERE, x: 1, y: 0, z: 0},
    	color_start: {r: 255, g: 255, b: 255},
    	color_end: {r: 255, g: 0, b: 0},
	    size: { value: [0.7, 0.1]}		
	},
	4: { //frostblast1
		animtime: 6000,
		particleCount: 200,
		duration: 0.01,
		maxAge: {
	        value: 0.2,
	        spread: 0.1
    	},
    	velocity: {dist: SPE.distributions.SPHERE, x: -8, y: 0, z: 0},
    	color_start: {r: 50, g: 50, b: 255},
    	color_end: {r: 0, g: 0, b: 255},
	    size: { value: [0.3, 0.5]}	
	},
	5: { //renew1
		animtime: 11000,
		particleCount: 50,
		duration: 7.00,
		maxAge: {
	        value: 4.0,
	        spread: 0.4
    	},
    	velocity: {dist: SPE.distributions.BOX, x: 0, y: 1, z: 0},
    	color_start: {r: 10, g: 220, b: 10},
    	color_end: {r: 10, g: 240, b: 10},
	    size: { value: [0.3, 0.1]}	
	}
	};

	function dmg_animation(obj, effect, hardpoint){

		var data = anim[effect];

		var particleGroup = new SPE.Group({
				maxParticleCount: 1000,
				texture: {
		            value: THREE.ImageUtils.loadTexture('textures/smokeparticle.png')
		    }
		});

		emitter = new SPE.Emitter({
			type: SPE.distributions.SPHERE,
			
			particleCount: data.particleCount,
			duration: data.duration,
			maxAge: data.maxAge,
			position: {
		        value: new THREE.Vector3(obj.x, obj.y, obj.z),
		        radius: 1
		    },

			acceleration: {
				value: new THREE.Vector3( 0, 0, 0 ),
				distribution: SPE.distributions.BOX
		    },

			velocity: {
				distribution: data.velocity.dist,
				value: new THREE.Vector3(
					data.velocity.x,
					data.velocity.y,
					data.velocity.z)
			},

		    color: {
		        value: [ new THREE.Color(
		        		data.color_start.r,
		        		data.color_start.g,
		        		data.color_start.b),
		        		 new THREE.Color(
        				data.color_end.r,
		        		data.color_end.g,
		        		data.color_end.b) ]
		    },

		    size: data.size
		});

		particleGroup.addEmitter( emitter );
		particleGroup.mesh['animateTime'] = data.animtime;
		particleGroup.mesh['updateAnimation'] = function(delta) {
			particleGroup.tick( delta );
			this.animateTime -= delta * 1000
		}
	
		webGL.sceneAddDamageNotification(particleGroup.mesh);	
	}

	return {'dmg_animation' : dmg_animation};
});