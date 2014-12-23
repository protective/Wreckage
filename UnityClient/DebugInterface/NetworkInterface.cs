using System.Net;
using System.Net.Sockets;
using System.Collections;
using System.Threading;
using System;
using System.Text;

public class AsynchronousSocketListener {
	// Thread signal.
	private static ManualResetEvent connectDone = 
		new ManualResetEvent(false);
	private static ManualResetEvent sendDone = 
		new ManualResetEvent(false);
	private static ManualResetEvent receiveDone = 
		new ManualResetEvent(false);


	// The response from the remote device.
	private static string response = String.Empty;
	private static StateObject connectedDebug;

	public AsynchronousSocketListener() {
	}

	public static void StartListening(int port) {
		// Connect to a remote device.

		// Establish the remote endpoint for the socket.
		// The name of the 
		// remote device is "host.contoso.com".
		//IPHostEntry ipHostInfo =  new IPHostEntry();
		IPAddress ipAddress = IPAddress.Parse("127.0.0.1");
		IPEndPoint remoteEP = new IPEndPoint(ipAddress, port);

		// Create a TCP/IP socket.
		Socket listener = new Socket(AddressFamily.InterNetwork,
			SocketType.Stream, ProtocolType.Tcp );

		// Bind the socket to the local endpoint and listen for incoming connections.
		//try {
			listener.Bind(remoteEP);
			listener.Listen(100);

			while (true) {
				// Set the event to nonsignaled state.
				connectDone.Reset();

				// Start an asynchronous socket to listen for connections.
				Console.WriteLine("Waiting for a connection...");
				listener.BeginAccept( 
					new AsyncCallback(AcceptCallback),
					listener );

				// Wait until a connection is made before continuing.
				connectDone.WaitOne();
			}

		//} catch (Exception e) {
		//	Console.WriteLine(e.ToString());
		//}

	}

	public static void AcceptCallback(IAsyncResult ar) {
		// Signal the main thread to continue.
		connectDone.Set();

		// Get the socket that handles the client request.
		Socket listener = (Socket) ar.AsyncState;
		Socket handler = listener.EndAccept(ar);

		// Create the state object.
		StateObject state = new StateObject();
		connectedDebug = state;
		state.workSocket = handler;
		handler.BeginReceive( state.buffer, 0, StateObject.BufferSize, 0,
			new AsyncCallback(ReceiveCallback), state);
	}


	public static void ReceiveCallback(IAsyncResult ar) {
		StateObject state = (StateObject) ar.AsyncState;
		Socket client = state.workSocket;

		// Read data from the remote device.
		int bytesRead = client.EndReceive(ar);
		Debug.Log("length " + bytesRead.ToString());
		if (bytesRead > 0) {

			byte[] recByte = new byte[bytesRead];

			StringBuilder hex = new StringBuilder ();
			StringBuilder cha = new StringBuilder ();
			for (int i = 0; i < bytesRead; i++) {
				hex.AppendFormat ("{0:x2}", state.buffer [i]);
			}
			String s = System.Text.Encoding.Default.GetString(state.buffer);
			s = s.TrimEnd ('\0');
			MessageHandler.dispatchMsg(s);
			Array.Clear (state.buffer, 0, StateObject.BufferSize -1);
			string temp = "Rec from controler " + response.Length + ": " + s;
			Debug.Log(temp);
			// Signal that all bytes have been received.
			//receiveDone.Set();

			client.BeginReceive( state.buffer, 0, StateObject.BufferSize, 0,
				new AsyncCallback(ReceiveCallback), state);
		}

	}

	public static void Send(String data) {
		if (connectedDebug != null)
			Send (connectedDebug.workSocket, data);
	}


	private static void Send(Socket handler, String data) {
		// Convert the string data to byte data using ASCII encoding.
		byte[] byteData = Encoding.ASCII.GetBytes(data);

		// Begin sending the data to the remote device.
		handler.BeginSend(byteData, 0, byteData.Length, 0,
			new AsyncCallback(SendCallback), handler);
	}

	private static void SendCallback(IAsyncResult ar) {
		try {
			// Retrieve the socket from the state object.
			Socket handler = (Socket) ar.AsyncState;

			// Complete sending the data to the remote device.
			int bytesSent = handler.EndSend(ar);
			Console.WriteLine("Sent {0} bytes controler.", bytesSent);

		} catch (Exception e) {
			Console.WriteLine(e.ToString());
		}
	}

}
	