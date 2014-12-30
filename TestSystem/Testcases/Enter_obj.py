


unity = None



def requiredResourses():
	return {'db': 1, 'unity':1, 'server':1}

def preamble():
	global unity
	
def postamble():
	global unity

	
def postMortom():
	print("test it dead")

def setUnityResourses(unity2):
	global unity

	unity = unity2[0]

def testRun():
	global unity

	unity.send("connect")
	unity.recv("connected", 5)


	unity.recv("ObjEnter", 5)
	unity.recv("ObjEnter", 5)
	unity.recv("ObjEnter", 5)

	unity.send("disconnect")
	unity.recv("disconnected", 5)



