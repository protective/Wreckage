using System;
using System.Text;

public static class MessageHandler {
	public static void dispatchMsg(String msg){
		switch (msg.Trim()) {
		case "connect":
			Mainclass.writeOut ("recived connect");
			AsynchronousClient.StartClient ();
			break;
		case "disconnect":
			Mainclass.writeOut ("recived disconnect");
			AsynchronousClient.disconnect ();
			break;
		}

	}
}