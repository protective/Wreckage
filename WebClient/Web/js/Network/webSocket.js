define(function ( require ) {


    
    var ws = new WebSocket("ws://192.168.1.180:11143");
    var handlers = {0x09 : require('Network/Comp/SerialComp')};

    ws.onopen = function()
    {
        // Web Socket is connected, send data using send()
        ws.send("Message to send");
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
            handlers[type].decode(len,receivedMsg.slice(8));
        
        };
        fr.readAsArrayBuffer(evt.data);



        //alert("Message is received...");
    };

    ws.onclose = function()
    { 
        // websocket is closed.
        alert("Connection is closed..."); 

    };

});
