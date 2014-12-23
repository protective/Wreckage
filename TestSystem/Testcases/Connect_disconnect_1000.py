


unity = None



def requiredResourses():
	return {'db': 1, 'unity':1, 'server':1}

def preamble():
	global unity
	print("connect test setup" )
	print("preamble" + str(unity))
	
def postamble():
	global unity
	print("postAbmle")
	print("connect test setup" )
	print("postamble" + str(unity))
	
def postMortom():
	print("test it dead")

def setUnityResourses(unity2):
	global unity
	print("set unity type=" + str(type(unity2[0])))

	unity = unity2[0]

def testRun():
	global unity
	print("run testcase")

	for i in range(1,100):
		unity.send("connect")
		unity.recv("connected", 10)

		unity.send("disconnect")
		unity.recv("disconnected", 10)

	print("Test passed")	


