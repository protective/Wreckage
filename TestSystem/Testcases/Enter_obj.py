


unity = None
server = None


def requiredResourses():
	return {'db': 1, 'unity':1, 'server':1}

def preamble():
	global unity
	global server
	
def postamble():
	global unity
	global server
	
def postMortom():
	print("test it dead")

def setUnityResourses(unity2):
	global unity
	print("setUnityResourses")
	unity = unity2[0]

def setServerResourses(server2):
	global server
	print("setServerResourses")
	server = server2[0]

def testRun():
	global unity
	global server

	print("run test")
	server.send("start")
	server.recv("Server Active", 15)
	
	unity.send("connect")
	unity.recv("connected", 5)


	unity.recv("ObjEnter", 5)
	unity.recv("ObjEnter", 5)
	unity.recv("ObjEnter", 5)

	unity.send("disconnect")
	unity.recv("disconnected", 5)

	server.send("close")
	#server.recv("exit", 5)

