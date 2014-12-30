public class MessageObjExit : Message{

	MessageObjExit(int objId,int modelType,Vector3 position){
		this.objId = objId;
		this.modelType = modelType;
		this.position = position;

	}


	public void execute(){
		AsynchronousSocketListener.Send("ObjExit\n");
	}


	int objId;
	int modelType;
	Vector3 position;

}