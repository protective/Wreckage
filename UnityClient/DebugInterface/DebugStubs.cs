public class Vector3 {
	public Vector3(int x, int y,int z, int d){
		this.x = x;
		this.y = y;
		this.z = z;
		this.d = d;
	}
	int x;
	int y;
	int z;
	int d;
	public override string ToString(){
		return "x=" + x.ToString () + " y=" + y.ToString () + " z=" + z.ToString () + " d=" + d.ToString ();

	}
}