
from libs.UnityResource import UnityResource
import imp
import time

class TestRunner:

	testname = ""
	def __init__(self, testname):
		self.testname = testname
		testcase = str(self.testname)
		self.X = imp.load_source(testcase, "Testcases/"+ testcase +".py")	

	def allocResources(self):
		#try:
		toAlloc = self.X.requiredResourses()
		#except AttributeError:
		#	print("ERROR testcase \"" + str(self.testname) + "\" do not implement the requiredResourses method")
		#except Exception as e:
		#	print("fail to alloc required Resourses", e)

		ures = []
		if 'unity' in toAlloc and toAlloc['unity'] > 0:
			print("holy")
			for unity in range(0, toAlloc['unity']):
				print("priest")				
				ures.append(self.loadUnityRes())

		#	try:
			toAlloc = self.X.setUnityResourses(ures)
		#	except AttributeError:
		#		print("ERROR testcase \"" + str(self.testname) + "\" do not implement the setUnity method")
		#	except Exception as e:
		#		print("fail to alloc required Resourses", e)

				


	def begin(self):
		#try:
		self.X.preamble()
		#except AttributeError:
		#	print("ERROR testcase \"" + str(self.testname) + "\" do not implement the testSetup method")
		#except Exception:
		#	print("fail to alloc required Resourses")
		self.X.testRun()

		self.X.postamble()


	def loadUnityRes(self):
		try:
			c = UnityResource("127.0.0.1", 7001)
			return c
		except Exception:
			print("fail to start resource")
			return FALSE

