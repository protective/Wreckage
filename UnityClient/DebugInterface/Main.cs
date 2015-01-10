using System.Net;
using System.Net.Sockets;
using System.Collections;
using System.Threading;
using System;
using System.Text;



public class Mainclass {

	static void Main(string[] args)
	{
		Console.WriteLine("test");
		Console.Out.Flush();

		// Display the number of command line arguments:
		System.Console.WriteLine (args.Length);

		AStdIn stdinProcessor = new AStdIn ();
		Thread stdlisten = stdinProcessor.StartListening (7003);
		stdlisten.Start ();

		if (args.Length >= 1){
			AsynchronousSocketListener.StartListening (7002);
		}else {
			System.Console.WriteLine ("to few arguments default to 7002");
			AsynchronousSocketListener.StartListening (7002);
		}


		//AsynchronousClient.StartClient ();

		while (true) {

		}
		stdlisten.Join ();
	}

	public static void writeOut(string s){
		Console.WriteLine(s);
		Console.Out.Flush();
	}
}