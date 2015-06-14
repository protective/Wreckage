define(function( require )
{

    var container, stats;

    var camera, scene, renderer, objects;
    
	var raycaster = new THREE.Raycaster();
	var mouse = new THREE.Vector2(),
	offset = new THREE.Vector3(),
	INTERSECTED, SELECTED;

    var particleLight, pointLight;
    var dae;

    var clock = new THREE.Clock();
    var morphs = [];

    var models = [];
	
    var UIOnClickCallBack = null;
    container = document.createElement( 'div' );
    function initWebGL() {
   
		if ( ! Detector.webgl ) Detector.addGetWebGLMessage();



			
			document.body.appendChild( container );

			camera = new THREE.PerspectiveCamera( 50, window.innerWidth / window.innerHeight, 1, 2000 );
			camera.position.set( 2, 4, 5 );

			scene = new THREE.Scene();
			scene.fog = new THREE.FogExp2( 0x000000, 0.035 );


			// Add the COLLADA

			//scene.add( dae );

			// Lights

			scene.add( new THREE.AmbientLight( 0xcccccc ) );

			pointLight = new THREE.PointLight( 0xff4400, 5, 30 );
			pointLight.position.set( 5, 0, 0 );
			scene.add( pointLight );

			// Renderer

			renderer = new THREE.WebGLRenderer();
			renderer.setPixelRatio( window.devicePixelRatio );
			renderer.setSize( window.innerWidth, window.innerHeight );
			container.appendChild( renderer.domElement );
			
			renderer.domElement.addEventListener( 'mousemove', onDocumentMouseMove, false );
			renderer.domElement.addEventListener( 'mousedown', onDocumentMouseDown, false );
			renderer.domElement.addEventListener( 'mouseup', onDocumentMouseUp, false );
			// Stats

			stats = new Stats();
			container.appendChild( stats.domElement );

			// Events

			window.addEventListener( 'resize', onWindowResize, false );


        animate();
    }
    
    
    function enshureLoad (model, f) {
        if (models[0] == null) {
            var loader = new THREE.JSONLoader();
            loader.load( model, function ( _geometry, _materials ) {
            
                var material = _materials[ 0 ];
			    material.morphTargets = true;
			    material.color.setHex( 0xffaaaa );
			    
			    var _faceMaterial = new THREE.MeshFaceMaterial( _materials );
			    
                models[0] = {geometry: _geometry, faceMaterial: _faceMaterial};
                if (f)                
                    f(_geometry, _faceMaterial);
            });
        }else{
            if (f)                
                f(models[0].geometry, models[0].faceMaterial);
        }
        
    }

    function addObj (obj) {
        
            var x = obj.x; 
		    var y = obj.y; 
		    var z = obj.z; 
            enshureLoad('models/monster.js', function(geometry, faceMaterial) {
            
            
            // random placement in a grid
                var i = 1;


				morph = new THREE.MorphAnimMesh( geometry, faceMaterial );
                morph.obj = obj;
				// one second duration

				morph.duration = 1000;

				// random animation offset

				morph.time = 1000 * Math.random();

				var s = THREE.Math.randFloat( 0.00075, 0.001 );
				morph.scale.set( s, s, s );

				morph.position.set( x, 0, z );
				morph.rotation.y = THREE.Math.randFloat( -0.25, 0.25 );

				morph.matrixAutoUpdate = false;
				morph.updateMatrix();

				scene.add( morph );

				morphs.push( morph );

		} );            
    
    
    }
    
    function addScene(element){
    	scene.add(element);
    }


	function onWindowResize( event ) {

		renderer.setSize( window.innerWidth, window.innerHeight );

		camera.aspect = window.innerWidth / window.innerHeight;
		camera.updateProjectionMatrix();

	}
			
			
	function animate() {

		requestAnimationFrame( animate );

		var delta = clock.getDelta();

		// animate Collada model

		THREE.AnimationHandler.update( delta );

		if ( morphs.length ) {

			for ( var i = 0; i < morphs.length; i ++ )
				morphs[ i ].updateAnimation( 1000 * delta );

		}

		render();
		stats.update();

	}

	function onDocumentMouseMove( event ) {

		event.preventDefault();

		mouse.x = ( event.clientX / window.innerWidth ) * 2 - 1;
		mouse.y = - ( event.clientY / window.innerHeight ) * 2 + 1;


	}
	function onDocumentMouseDown( event ) {
	
		event.preventDefault();

		var vector = new THREE.Vector3( mouse.x, mouse.y, 0.5 ).unproject( camera );

		var raycaster = new THREE.Raycaster( camera.position, vector.sub( camera.position ).normalize() );

		var intersects = raycaster.intersectObjects( morphs );

		if ( intersects.length > 0 ) {

			intersects[ 0 ].object.obj.onClick();

		}
	}

	function onDocumentMouseUp( event ) {

		event.preventDefault();
	}
	function render() {

		var timer = Date.now() * 0.0005;

		camera.position.x = Math.cos( 0 ) * 10;
		camera.position.y = 4;
		camera.position.z = Math.sin( 0 ) * 10;

		camera.lookAt( scene.position );

		renderer.render( scene, camera );

	}

	function setOnClickCallback(callback){
		UIOnClickCallBack = callback;
	}
	

	return {
		initWebGL : initWebGL,
		addObj : addObj,
		render : render,
		'setOnClickCallback': setOnClickCallback,
		'addElement' : addScene,
		'container' : container
		
	}
});
