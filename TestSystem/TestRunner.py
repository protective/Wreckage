
from libs.UnityResource import UnityResource
import imp

class TestRunner:


	def begin(self):
		testname = "Connect_disconnect_1000"
		testcase = str(testname)
		X = imp.load_source(testcase, "Testcases/"+ testcase +".py")
		X.testSetup()
		print ("hest")
		
	def loadUnityRes(self):
		try:
			c = UnityResource()
			return c
		except Exception:
			print("fail to start resouece")
			return FALSE
		

t = TestRunner()
t.begin()
