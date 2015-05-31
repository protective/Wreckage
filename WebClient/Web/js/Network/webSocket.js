define(function ( require ) {

	    function Packets( )
	    {
		    this.callback = null;
	    }

	    Packets.list = [];



        var ws = null;
        var handlers = {};

        function connect(){
            ws = new WebSocket("ws://192.168.1.180:11143");

            ws.onopen = function()
            {
                // Web Socket is connected, send data using send()
                //ws.send("Message to send");
                //alert("Message is sent...");
            };

            ws.onmessage = function (evt) 
            { 
                var receivedMsg;

                var fr = new FileReader();
                fr.onload = function () {
                receivedMsg = this.result;

                    var type = new Uint32Array(receivedMsg.slice(0,4))[0];
                    var len = new Uint32Array(receivedMsg.slice(4,8))[0];
                    handlers[type](receivedMsg.slice(8));
                
                };
                fr.readAsArrayBuffer(evt.data);



                //alert("Message is received...");
            };

            ws.onclose = function()
            { 
                // websocket is closed.
                alert("Connection is closed..."); 

            };      
        }
        

        
        function hook(type, callback) {
                handlers[type] = callback;
        }
        
        function send(msg) {
            ws.send(msg);
        }  
    
    return {'hook' : hook,
            'connect' : connect};
});
