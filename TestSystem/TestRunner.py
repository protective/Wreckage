
from libs.UnityResource import UnityResource
from libs.ServerResource import ServerResource
import argparse
import imp
import time
import traceback
import queue
import time

class TestRunner:

	testname = ""
	def __init__(self, testname):
		self.testname = testname
		testcase = str(self.testname)
		self.X = imp.load_source(testcase, "Testcases/"+ testcase +".py")
		self.allocatedures = []
		self.allocatedsres = []
		self.allocResources()
		print("TEST INIT NO RESOURCES")
		self.begin()

	def allocResources(self):
		#try:

		toAlloc = self.X.requiredResourses()

		ures = []
		restypes = [('unity',loadUnityRes), ('server',loadServerRes)]
		
		if 'unity' in toAlloc and toAlloc['unity'] > 0:
			for unity in range(0, toAlloc['unity']):
				self.allocatedures.append(loadUnityRes(20004))

				
		sres = []
		if 'server' in toAlloc and toAlloc['server'] > 0:
			for server in range(0, toAlloc['server']):					
				self.allocatedsres.append(loadServerRes(100023))


		self.X.setUnityResourses(self.allocatedures)
		self.X.setServerResourses(self.allocatedsres)

		print("true")

		return True
				
	def deallocateResources(self):
		for unity in self.allocatedures:
			unity.close()

		for server in self.allocatedsres:		
			server.close()	

	def begin(self):
		try:
			self.X.preamble()
		except AttributeError:
			print("ERROR testcase \"" + str(self.testname) + "\" do not implement the testSetup method")
		except Exception:
			print("fail to alloc required Resourses")
			print(traceback.format_exc())
		
		

		print("RUN " + str(self.testname))

		try:
			self.X.testRun()
			print("PASS")
		except KeyboardInterrupt:
			print("RUN testcase interrupted")
		except Exception as e:
			print(e)
			print("FAIL")

		try:
			self.X.postamble()
		except Exception as e:
			print(e)
			print("FAIL")		
		
		self.deallocateResources()

def loadUnityRes(port):
	#try:
	c = UnityResource("127.0.0.1", port)

	return c
	#except Exception:
	#	print("ERROR fail to start resource")
	#	return False


def loadServerRes(port):
	#try:
	c = ServerResource("127.0.0.1", port)
	return c
	#except Exception:
	#	print("ERROR fail to start resource")
	#	return False


parser = argparse.ArgumentParser(description='Start a test case')
parser.add_argument('-t', '--testcase', help='Test case to run')

args = parser.parse_args()

t = TestRunner(args.testcase)

