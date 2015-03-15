import asyncio
import re

class Resource:

	def __init__(self, host, port, location, attributes):
		self.host = host
		self.port = port
		self.user = None
		self.status = "INIT"
		self.softwareHash = ""
		self.location = location
		self.attributes = attributes

	def prepare(self, softwareHash):
		self.softwareHash = softwareHash


resources = []

def createNewResources(host, port, location, attributes):

	resources.append(Resource(host, port, location, attributes))

createNewResources(1111,2222,"/home/karsten/Wreckage/Server/dist/Debug/GNU-Linux-x86/server", "SERVER")
createNewResources(1111,2223,"/home/karsten/Wreckage/UnityClient/bin/unityScriptInterface", "CLIENT")

@asyncio.coroutine
def decodeReqeust(message):
	
	decode = re.search("(req);([0-9A-Fa-f]*);(.*)",message)
	cmd, softwareHash, testHeads = decode.groups()[:]
	
	
	if cmd == "req":
		status = "INIT"
		
		#todo check Hash
		haveSoftware = True
		
		if haveSoftware == False:
			data = "Error: hash not found"
			writer.write(data)
			yield from writer.drain()	
			return
			
		gotAll = False
		while gotAll == False:

			temp = {}	
			needSoftware = False
			loopCheck = True
			for toFind in re.findall("([A-Za-z]*):(\d+);?", testHeads):
				temp[toFind] = []
				#prefere resourses with the same software hash first
				for r in sorted(resources, key=lambda x: 0 if x.softwareHash == softwareHash else 1):
					if r.status == "INIT" and re.match(toFind[0], r.attributes) != None:
						temp[toFind].append(r)
						
				if len(temp[toFind]) < int(toFind[1]):
					loopCheck = False
					break	
			if loopCheck == False:
				yield from asyncio.sleep(1.0)
				continue
			
			#we are here. We got it all
			gotAll = True
			#Allocate
			if haveSoftware == True:
				resources.remove(temp)
			
			#Prepaire
			for r in temp:
				r.prepare(softwareHash)
				
			#writer.write(data)
			#yield from writer.drain()		


@asyncio.coroutine
def handle_echo(reader, writer):
	while True:
		message = yield from reader.readline()
		if len(message) > 0:
			yield from decodeReqeust(message.decode().strip())

			addr = writer.get_extra_info('peername')
			print("Received %r from %r" % (message, addr))
		else:
			try:
				writer.close()
			except Exception as e:
				print(e)
			break;


@asyncio.coroutine
def handle_testhead(resource):
	# Create the subprocess, redirect the standard output into a pipe
	create = asyncio.create_subprocess_exec("python3.4", "ResourceDaemon.py"  , str(resource.location),  str(resource.port), stdout=asyncio.subprocess.PIPE)
	proc = yield from create

	# Read one line of output
	line = ""
	print("deamon up")
	while True:
		data = yield from proc.stdout.readline()
		line = data.decode('ascii').rstrip()
		print("port =" + str(resource.port) +  " " + str(line) )
	# Wait for the subprocess exit
	yield from proc.wait()
	return line



loop = asyncio.get_event_loop()
coro = asyncio.start_server(handle_echo, '127.0.0.1', 8888, loop=loop)
server = loop.run_until_complete(coro)

for r in resources:
	asyncio.async(handle_testhead(r))

# Serve requests until CTRL+c is pressed
print('Serving on {}'.format(server.sockets[0].getsockname()))
try:
	loop.run_forever()
except KeyboardInterrupt:
	pass

# Close the server
server.close()
loop.run_until_complete(server.wait_closed())
loop.close()
