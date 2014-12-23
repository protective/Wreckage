using System;
using System.Text;

public static class MessageHandler {
	public static void dispatchMsg(String msg){
		switch (msg.Trim()) {
		case "connect":
			Debug.Log ("recived connect");
			AsynchronousClient.StartClient ();
			break;
		case "disconnect":
			Debug.Log ("recived disconnect");
			AsynchronousClient.disconnect ();
			break;
		}

	}
}