
unity = None
server = None
import struct
import codecs
def hexEncode(format, value):
	return codecs.encode(struct.pack(format, value),'hex').decode("utf-8")



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


	unitId = 16777221
	powerId = 16777224
	targetId = 16777221

	unity.send("cmd castPower "+ str(unitId) + " " + str(powerId) + " " + str(targetId))

	s =  hexEncode('<I', unitId)
	s = s + hexEncode('<H', 1) #type
	s = s + hexEncode('<H', 4 + 8) #len
	s = s + hexEncode('<I', powerId)
	s = s + hexEncode('<I', targetId)

	unity.recv("sent 0x.*" + s, 5)


	unity.send("disconnect")
	unity.recv("disconnected", 5)

	server.send("close")
	#server.recv("exit", 5)

