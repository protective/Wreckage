using System;



public class MessageObjExit : Message{



	MessageObjExit(int objId,int modelType,Vector3 position){
		this.objId = objId;
		this.modelType = modelType;
		this.position = position;

	}

	public MessageObjExit(byte[] message){
		this.objId = BitConverter.ToInt32 (message, 8);
		this.modelType = BitConverter.ToInt32 (message, 34);
		this.position = new Vector3(BitConverter.ToInt32 (message, 20),BitConverter.ToInt32 (message, 24), BitConverter.ToInt32 (message, 28),BitConverter.ToInt16 (message, 32));

	}

	public override void execute(){
		System.Console.WriteLine("ObjExit id=" + this.objId.ToString() + " fadetime=" + this.modelType.ToString() + " " + this.position.ToString() + "");
		AsynchronousSocketListener.Send("ObjExit id=" + this.objId.ToString() + " fadetime=" + this.modelType.ToString() + " " + this.position.ToString() + "\n");
	}


	int objId;
	int modelType;
	Vector3 position;

}