define(function ( require ) {
	
    var webGL = require('webGL');
    var Particals = require('Model/Effects/Particals');
    
    function makeTextSprite( message, parameters )
    {
        if ( parameters === undefined ) parameters = {};
        var fontface = parameters.hasOwnProperty("fontface") ? parameters["fontface"] : "Arial";
        var fontsize = parameters.hasOwnProperty("fontsize") ? parameters["fontsize"] : 18;
        var borderThickness = parameters.hasOwnProperty("borderThickness") ? parameters["borderThickness"] : 4;
        var borderColor = parameters.hasOwnProperty("borderColor") ?parameters["borderColor"] : { r:0, g:0, b:0, a:1.0 };
        var backgroundColor = parameters.hasOwnProperty("backgroundColor") ?parameters["backgroundColor"] : { r:255, g:255, b:255, a:1.0 };
        var textColor = parameters.hasOwnProperty("textColor") ?parameters["textColor"] : { r:0, g:0, b:0, a:1.0 };

        var canvas = document.createElement('canvas');
        var context = canvas.getContext('2d');
        context.font = "Bold " + fontsize + "px " + fontface;
        var metrics = context.measureText( message );
        var textWidth = metrics.width;

        context.fillStyle   = "rgba(" + backgroundColor.r + "," + backgroundColor.g + "," + backgroundColor.b + "," + backgroundColor.a + ")";
        context.strokeStyle = "rgba(" + borderColor.r + "," + borderColor.g + "," + borderColor.b + "," + borderColor.a + ")";

        context.lineWidth = borderThickness;
        roundRect(context, borderThickness/2, borderThickness/2, (textWidth + borderThickness) * 1.1, fontsize * 1.4 + borderThickness, 8);

        context.fillStyle = "rgba("+textColor.r+", "+textColor.g+", "+textColor.b+", 1.0)";
        context.fillText( message, borderThickness, fontsize + borderThickness);

        var texture = new THREE.Texture(canvas);
        texture.minFilter = THREE.LinearFilter;
        texture.needsUpdate = true;

        var spriteMaterial = new THREE.SpriteMaterial( { map: texture, useScreenCoordinates: false, transparent: true} );
        var sprite = new THREE.Sprite( spriteMaterial );
        sprite.scale.set(0.5 * fontsize, 0.25 * fontsize, 0.75 * fontsize);
        
        sprite['animateTime'] = 3000;
        sprite['updateAnimation'] = function(delta) {
        	var fontsize = 24;
        	var a = 1;
        	this.animateTime -= delta * 1000
			fontsize = (24 * (this.animateTime / 3000));
			a = ( (this.animateTime / 3000));
			//this.scale.set(0.5 * fontsize, 0.25 * fontsize, 0.75 * fontsize);
			this.material.opacity = a;
			this.position.y += 0.003 * delta * 1000;
        }
        
        return sprite;  
    }
    // function for drawing rounded rectangles
    function roundRect(ctx, x, y, w, h, r) 
    {
        ctx.beginPath();
        ctx.moveTo(x+r, y);
        ctx.lineTo(x+w-r, y);
        ctx.quadraticCurveTo(x+w, y, x+w, y+r);
        ctx.lineTo(x+w, y+h-r);
        ctx.quadraticCurveTo(x+w, y+h, x+w-r, y+h);
        ctx.lineTo(x+r, y+h);
        ctx.quadraticCurveTo(x, y+h, x, y+h-r);
        ctx.lineTo(x, y+r);
        ctx.quadraticCurveTo(x, y, x+r, y);
        ctx.closePath();
        ctx.fill();
    	ctx.stroke();   
    }
    
    
    
    
    function createDamangeNotification(obj, value, result) {
    	var Color = (value < 0) ? {r:0, g:255, b:0} : {r:255, g:0, b:0};
    	var spritey = makeTextSprite( value, 
    			{ fontsize: 24, textColor : Color, borderColor: {r:255, g:0, b:0, a:0}, backgroundColor: {r:255, g:100, b:100, a:0} } );
    		spritey.position.set(obj.x, obj.y, obj.z);
    	webGL.sceneAddDamageNotification(spritey);
    }
    
 
    return {'createDamangeNotification' : createDamangeNotification};
    		
});