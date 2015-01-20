using System;
using System.Collections.Generic;

public class CmdInput{

	private const int SerialTypeInput = 7;

	protected static List<byte> packCmdInpt(int len, int objid){
		List<byte> cmd = new List<byte>();
		if (len < 4)
			return cmd;

	 	byte[] type = BitConverter.GetBytes ((ushort)SerialTypeInput);
		byte[] objIdField = BitConverter.GetBytes ((uint)objid);
		len += sizeof(ushort) + type.Length + objIdField.Length;
		byte[] lenfield = BitConverter.GetBytes ((ushort)len);

		cmd.AddRange (type);
		cmd.AddRange (lenfield);
		cmd.AddRange (objIdField);

		return cmd;
	}

}