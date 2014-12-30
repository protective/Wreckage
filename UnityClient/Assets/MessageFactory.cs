using System;

public class Message{

	public virtual void execute (){}
}


public class MessageFactory{

	private const int SerialComp = 9;
	private const int COMPIDmodelStatic = 13;

	private const int ModelStaticObjEnter = 1;
	private const int ModelStaticObjExit = 2;

	public static int passNetwork(byte[] message){

		switch (BitConverter.ToInt32 (message,0)) {
			case SerialComp:
			{
				switch(BitConverter.ToInt32 (message,12)){

					case COMPIDmodelStatic:
					{

						switch (BitConverter.ToInt32 (message, 16)) {
							case ModelStaticObjEnter:
							{
								handleMessage(new MessageObjEnter (message));
								break;
							}
							case ModelStaticObjExit:
							{

								break;
							}
						}
						break;

					} 
				}

				break;
			}

		}
		return 0;
	}

	public static void handleMessage(Message msg){
		System.Console.WriteLine ("handleMessage");
		msg.execute ();
	}

}