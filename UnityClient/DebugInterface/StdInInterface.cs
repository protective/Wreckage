
using System.Collections;
using System.Threading;
using System;
using System.Text;

public class AStdIn {

	public AStdIn() {
	}

	public Thread StartListening(int port) {
		AStdIn workerObject = new AStdIn();
		return  new Thread( workerObject.ReceiveCallback);

	}
		

	public void ReceiveCallback() {

		try {
			while (true){
				Mainclass.writeOut("ReceiveCallback");
				string s = Console.In.ReadLine();
				Mainclass.writeOut("Rec from controler " + s .Length + ": " + s);
				MessageHandler.dispatchMsg(s);
			}
		} catch (Exception e) {
			Console.WriteLine(e.ToString());
		}
	}

}
	