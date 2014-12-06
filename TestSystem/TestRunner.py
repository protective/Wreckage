
from libs.UnityResource import UnityResource
import imp
import time

class TestRunner:

	testname = ""
	def __init__(self, testname):
		self.testname = testname
	
	def allocResources(self):
		testcase = str(self.testname)
		X = imp.load_source(testcase, "Testcases/"+ testcase +".py")
		X.testSetup()
		print("ko")
		time.sleep(4)
		print ("hest")
		
	def begin(self):
		print("begin test")

	def loadUnityRes(self):
		try:
			c = UnityResource()
			return c
		except Exception:
			print("fail to start resouece")
			return FALSE

