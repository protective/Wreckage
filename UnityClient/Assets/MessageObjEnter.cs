using System;


public class MessageObjEnter : Message{

	public MessageObjEnter(int objId,int modelType,Vector3 position){
		this.objId = objId;
		this.fadetime = modelType;
		this.position = position;

	}

	public MessageObjEnter(byte[] message){
		this.objId = BitConverter.ToInt32 (message, 8);
		this.fadetime = BitConverter.ToInt32 (message, 34);
		this.position = new Vector3(BitConverter.ToInt32 (message, 20),BitConverter.ToInt32 (message, 24), BitConverter.ToInt32 (message, 28),BitConverter.ToInt16 (message, 32));

	}

	public override void execute(){
		System.Console.WriteLine("ObjEnter id=" + this.objId.ToString() + " modelID=" + this.modelType.ToString() + " " + this.position.ToString() + "");
		AsynchronousSocketListener.Send("ObjEnter id=" + this.objId.ToString() + " modelID=" + this.modelType.ToString() + " " + this.position.ToString() + "\n");
	}

	int objId;
	int fadetime;
	Vector3 position;

}