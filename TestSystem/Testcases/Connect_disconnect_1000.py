


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
	print("set")
	unity = unity2

def testRun():
	print("run testcase")



