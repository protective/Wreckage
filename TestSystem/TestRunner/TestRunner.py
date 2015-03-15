
import asyncio
import argparse
import imp
import time
import traceback
import queue
import time
import sys
from libs.ServerResource import ServerResource
from queue import Queue, Empty
from threading import Thread
from threading import Event
class TestRunner:

	testname = ""
	resAllocStatus = Event()
	allocatedResoueces = {}
	def __init__(self, testname):
		self.testname = testname
		testcase = str(self.testname)
		self.X = imp.load_source(testcase, "Testcases/"+ testcase +".py")
		self.allocatedResoueces = {}

	def begin(self):
	
		print("begin")
		thread = Thread(target = self.run_test, args = ())

		message = 'Hello World!'
		self.loop = asyncio.get_event_loop()
		asyncio.async(self.run_Resources())

		try:
			thread.start()
			self.loop.run_forever()
		except KeyboardInterrupt:
			pass
		
		thread.join()
		return True

	@asyncio.coroutine
	def testServerReq(self, req):
		print("TODO STUB")
		server = self.loadServerRes( 2222)
		print("create server res type= " + str(type(server)) + "   " + str(server))
		server.reader, server.writer = yield from server.res
		asyncio.async(ServerResource.asyncSend(server))
		asyncio.async(ServerResource.asyncRead(server))
		
		print("TODO STUB")
		unity = self.loadUnityRes( 2223)
		print("create unity res type= " + str(type(unity)) + "   " + str(unity))
		unity.reader, unity.writer = yield from unity.res
		asyncio.async(ServerResource.asyncSend(unity))
		asyncio.async(ServerResource.asyncRead(unity))
		
		
		return {'server' : [server], 'unity' : [unity]}

	
	def loadUnityRes(self, port):
		return ServerResource("127.0.0.1" , port)
	
	
	def loadServerRes(self, port):
		return ServerResource("127.0.0.1" , port)


	@asyncio.coroutine
	def run_Resources(self):
		print("RUN resources")
		#connect to Resource Server
		resource_server = yield from asyncio.open_connection('127.0.0.1', 8888)

		toAlloc = self.X.requiredResourses()
		print("ALLOC resources")
		self.allocatedResoueces = yield from self.testServerReq(toAlloc)
		print("SET resources")
		
		if 'unity' in self.allocatedResoueces:
			self.X.setUnityResourses(self.allocatedResoueces['unity'])

		if 'server' in self.allocatedResoueces:
			self.X.setServerResourses(self.allocatedResoueces['server'])
		
		self.resAllocStatus.set()
		return True 
							
	def deallocateResources(self):
		for l in self.allocatedResoueces.values():
			for res in l:
				res.close()	

	def run_test(self):
		print("RUN test wait")
		self.resAllocStatus.wait()
		print("RUN test GO!")
		self.resAllocStatus.clear()
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
			print(traceback.format_exc())
			print(e)
			print("FAIL")

		try:
			self.X.postamble()
		except Exception as e:
			print(traceback.format_exc())
			print(e)
			print("FAIL")		
		
		self.deallocateResources()
		print("COMPLETE close loop")
		self.loop.stop()
		while(self.loop.is_running() == True):
			time.sleep(1)
		self.loop.close()
		
		
parser = argparse.ArgumentParser(description='Start a test case')
parser.add_argument('-t', '--testcase', help='Test case to run')

args = parser.parse_args()

tr = TestRunner(args.testcase)

tr.begin()




