using System;
using System.Collections.Generic;
using System.Text;



public class CmdInputSpellBook : CmdInput{


	private const int SerialInputCastPower = 1;

	public static void SendInputCastPower(int obj, int power, int target){
		List<byte> cmd = new List<byte>();
	
		byte[] OBJid = BitConverter.GetBytes ((uint)obj);
		byte[] type = BitConverter.GetBytes ((ushort)SerialInputCastPower);
		byte[] PowerOBJ = BitConverter.GetBytes ((uint)power);
		byte[] PowerTarget = BitConverter.GetBytes ((uint)target);
		int len = sizeof(ushort) + type.Length + PowerOBJ.Length + PowerTarget.Length;
		byte[] lenfield = BitConverter.GetBytes ((ushort)len);

		Mainclass.writeOut ("len " + type.Length);
		Mainclass.writeOut ("len " + PowerOBJ.Length);
		Mainclass.writeOut ("len " + PowerTarget.Length);
		Mainclass.writeOut ("len " + lenfield.Length);

		cmd.AddRange (OBJid);
		cmd.AddRange (type);
		cmd.AddRange (lenfield);
		cmd.AddRange (PowerOBJ);
		cmd.AddRange (PowerTarget);

		//cmd.AddRange(packCmdInpt (len, obj));


		//AsynchronousClient.Send (cmd.ToArray ());


		StringBuilder hex = new StringBuilder(cmd.Count * 2);
		foreach (byte b in cmd.ToArray ())
			hex.AppendFormat("{0:x2}", b);


		Mainclass.writeOut("sent 0x" + hex.ToString ());
	
	}

}