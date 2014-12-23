#if unity
using UnityEngine;
#endif

using System.Net;
using System.Net.Sockets;
using System.Collections;
using System.Threading;
using System;

using System.Text;
#if unity

#else
public class Debug {

	public static void Log(string debug){
		System.Console.WriteLine(debug);

	}
}
#endif
#if unity
public class NetWorkConnect : MonoBehaviour{
	
	// Use this for initialization
	void Start () {
		AsynchronousClient.StartClient ();
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
#endif

public class StateObject {
	
	// Client socket.
	public Socket workSocket = null;
	// Size of receive buffer.
	public const int BufferSize = 256;
	// Receive buffer.
	public byte[] buffer = new byte[BufferSize];
	// Received data string.
	public StringBuilder sb = new StringBuilder();

}

public class AsynchronousClient {
	
	// ManualResetEvent instances signal completion.
	private static ManualResetEvent connectDone = 
		new ManualResetEvent(false);
	private static ManualResetEvent sendDone = 
		new ManualResetEvent(false);
	private static ManualResetEvent receiveDone = 
		new ManualResetEvent(false);
	
	// The response from the remote device.
	private static string response = String.Empty;

	public static StateObject connectionObj = null;

	public static void StartClient() {
		// Connect to a remote device.
		try {
			Console.WriteLine("StartClient");
			// Establish the remote endpoint for the socket.
			// The name of the 
			// remote device is "host.contoso.com".
			//IPHostEntry ipHostInfo =  new IPHostEntry();
			IPAddress ipAddress = IPAddress.Parse("127.0.0.1");
			IPEndPoint remoteEP = new IPEndPoint(ipAddress, 11142);
			
			// Create a TCP/IP socket.
			Socket client = new Socket(AddressFamily.InterNetwork,
			                           SocketType.Stream, ProtocolType.Tcp);

			// Connect to the remote endpoint.
			client.BeginConnect( remoteEP, 
			                    new AsyncCallback(ConnectCallback), client);

			//connectDone.WaitOne();
			Console.WriteLine("BeginConnect", response);

			connectDone.WaitOne();
			Console.WriteLine("done wait", response);

			
		} catch (Exception e) {
			Console.WriteLine(e.ToString());
		}
	}

	public static void disconnect(){
		if (connectionObj != null) {
			connectionObj.workSocket.BeginDisconnect(false, new AsyncCallback(DisconnectCallback), connectionObj.workSocket);

		}
	} 
	private static void DisconnectCallback(IAsyncResult ar) {
		Console.WriteLine("DisconnectCallback");
		AsynchronousSocketListener.Send ("disconnected\n");
		connectionObj = null;
	}

	private static void ConnectCallback(IAsyncResult ar) {
		Console.WriteLine("hest");
		try {
			// Retrieve the socket from the state object.
			Socket client = (Socket) ar.AsyncState;
			
			// Complete the connection.
			client.EndConnect(ar);
			
			Console.WriteLine("Socket connected to {0}",
			                  client.RemoteEndPoint.ToString());
			AsynchronousSocketListener.Send("connected\n");
			// Signal that the connection has been made.



			connectDone.Set();
			Receive(client);
		} catch (Exception e) {
			Console.WriteLine(e.ToString());
		}
	}
	
	private static void Receive(Socket client) {
		try {
			// Create the state object.
			StateObject state = new StateObject();
			state.workSocket = client;

			connectionObj = state;

			// Begin receiving the data from the remote device.
			client.BeginReceive( state.buffer, 0, StateObject.BufferSize, 0,
			                    new AsyncCallback(ReceiveCallback), state);
		} catch (Exception e) {
			Console.WriteLine(e.ToString());
		}
	}
	
	private static void ReceiveCallback( IAsyncResult ar ) {
		try {
			// Retrieve the state object and the client socket 
			// from the asynchronous state object.
			StateObject state = (StateObject) ar.AsyncState;
			Socket client = state.workSocket;
			
			// Read data from the remote device.
			int bytesRead = client.EndReceive(ar);
			Debug.Log("length " + bytesRead.ToString());
			if (bytesRead > 0) {
				// There might be more data, so store the data received so far.

				byte[] recByte = new byte[bytesRead];

				StringBuilder hex = new StringBuilder();
				for(int i = 0; i < bytesRead; i++){
					hex.AppendFormat("{0:x2}", state.buffer[i]);
				}

				string temp = "server rec " + response.Length + ": " + hex;
				Debug.Log(temp);
				// Signal that all bytes have been received.
				receiveDone.Set();
			}


		} catch (Exception e) {
			Console.WriteLine(e.ToString());
		}
	}
	
	private static void Send(Socket client, string data) {
		// Convert the string data to byte data using ASCII encoding.
		byte[] byteData = Encoding.ASCII.GetBytes(data);
		
		// Begin sending the data to the remote device.
		client.BeginSend(byteData, 0, byteData.Length, 0,
		                 new AsyncCallback(SendCallback), client);
	}
	
	private static void SendCallback(IAsyncResult ar) {
		try {
			// Retrieve the socket from the state object.
			Socket client = (Socket) ar.AsyncState;
			
			// Complete sending the data to the remote device.
			int bytesSent = client.EndSend(ar);
			Console.WriteLine("Sent {0} bytes to server.", bytesSent);
			
			// Signal that all bytes have been sent.
			sendDone.Set();
		} catch (Exception e) {
			Console.WriteLine(e.ToString());
		}
	}


}
