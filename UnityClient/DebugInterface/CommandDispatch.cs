using System;
using System.Text;

public static class MessageHandler {
	public static void dispatchMsg(String msg){
		Mainclass.writeOutErr("unity error" + msg);
		msg = msg.Trim();
		switch (msg.IndexOf (' ') == -1 ? msg : msg.Remove(msg.IndexOf (' '))) {
		case "connect":
			Mainclass.writeOut ("recived connect");
			AsynchronousClient.StartClient ();
			break;
		case "disconnect":
			Mainclass.writeOut ("recived disconnect");
			AsynchronousClient.disconnect ();
			break;
		case "cmd":
			handleCmd (msg.Substring (msg.IndexOf (' ')));
			break;
		}

	}

	private static void handleCmd(String msg){
		msg = msg.Trim();
		switch (msg.IndexOf (' ') == -1 ? msg : msg.Remove(msg.IndexOf (' '))) {

		case "castPower":
			string[] args = msg.Split (' ');
			CmdInputSpellBook.SendInputCastPower (int.Parse(args[1]), int.Parse(args[2]), int.Parse(args[3]));
			break;
		}


	}
}