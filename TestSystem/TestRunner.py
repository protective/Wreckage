

import argparse
import imp
import time
import traceback
import queue
import time
import sys

class TestRunner:

	testname = ""
	def __init__(self, testname):
		self.testname = testname
		testcase = str(self.testname)
		self.X = imp.load_source(testcase, "Testcases/"+ testcase +".py")
		self.allocatedures = []
		self.allocatedsres = []
		if self.allocResources():
			print("TEST INIT OK")
		else:
			print("TEST INIT NO RESOURCES")
		sys.stdout.flush()
		self.begin()

	def allocResources(self):
		#try:

		toAlloc = self.X.requiredResourses()

		
		restypes = [('unity',loadUnityRes), ('server',loadServerRes)]
		
		
		allocatedResoueces = testServerReq(toAlloc)
		if(allocatedResoueces == None)
			return False
		
		
		ures = []
		if 'unity' in allocatedResoueces:
			for unity in allocatedResoueces['unity']:
				self.allocatedures.append(unity)

				
		sres = []
		if 'server' in allocatedResoueces :
			for server in allocatedResoueces['server']:					
				self.allocatedsres.append(server)


		self.X.setUnityResourses(self.allocatedures)
		self.X.setServerResourses(self.allocatedsres)

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
		print("COMPLETE")

def testServerReq(req):
	print("TODO")

def loadUnityRes(port):
	#try:
	c = TestResource()

	return c
	#except Exception:
	#	print("ERROR fail to start resource")
	#	return False


def loadServerRes(port):
	#try:
	c = TestResource()
	return c
	#except Exception:
	#	print("ERROR fail to start resource")
	#	return False


parser = argparse.ArgumentParser(description='Start a test case')
parser.add_argument('-t', '--testcase', help='Test case to run')

args = parser.parse_args()

t = TestRunner(args.testcase)

