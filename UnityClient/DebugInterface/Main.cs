using System.Net;
using System.Net.Sockets;
using System.Collections;
using System.Threading;
using System;
using System.Text;



public class Mainclass {

	static void Main(string[] args)
	{

		// Display the number of command line arguments:
		System.Console.WriteLine (args.Length);
		if (args.Length >= 0){
			AsynchronousSocketListener.StartListening (7002);
		}else {
			System.Console.WriteLine ("to few arguments");
			return;
		}

		//AsynchronousClient.StartClient ();

		while (true) {

		}
	}
}