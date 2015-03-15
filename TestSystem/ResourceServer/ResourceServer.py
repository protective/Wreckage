import asyncio
import re
from asyncio.locks import Event

class Resource:

	def __init__(self, host, port, location, attributes):
		self.host = host
		self.port = port
		self.user = None
		self.status = "INIT"
		self.softwareHash = "abc"
		self.location = location
		self.attributes = attributes
		self.start = Event()
		self.started = Event()
		self.terminate = Event()
		self.terminated = Event()
		self.terminated.set()

	@asyncio.coroutine
	def prepare(self, softwareHash):
		#self.softwareHash = softwareHash
		
		yield from self.terminated.wait()
		self.terminated.clear()
		
		self.start.set()
		yield from self.started.wait()
		self.started.clear()
		return str(self.host) + ":" + str(self.port)

	@asyncio.coroutine
	def handle_start(self, proc):
		while True:
			yield from self.start.wait()
			proc.stdin.write("start\n".encode('ascii'))
			yield from proc.stdin.drain()
			self.start.clear()
			
	@asyncio.coroutine
	def handle_terminate(self, proc):	
		while True:
			yield from self.terminate.wait()
			proc.stdin.write("stop\n".encode('ascii'))
			yield from proc.stdin.drain()
			self.terminate.clear()
						
	@asyncio.coroutine
	def handle_testhead(self):
		
		# Create the subprocess, redirect the standard output into a pipe
		create = asyncio.create_subprocess_exec("python3.4", "ResourceDaemon.py"  , str(self.location),  str(self.port),stdin=asyncio.subprocess.PIPE, stdout=asyncio.subprocess.PIPE)
		proc = yield from create
	
		# Read one line of output
		line = ""
		print("deamon up")
		asyncio.async(self.handle_start(proc))
		asyncio.async(self.handle_terminate(proc))
		while True:

			print("deamon start")
			while True:
				data = yield from proc.stdout.readline()
				line = data.decode('ascii').rstrip()
				if line.strip() == "INFO resources started":
					self.started.set()
				if line.strip() == "INFO resources stopped":
					self.terminated.set()
				print("port =" + str(self.port) +  " " + str(line) )
			# Wait for the subprocess exit
			yield from proc.wait()
		return line
	
	
resources = []

def createNewResources(host, port, location, attributes):

	resources.append(Resource(host, port, location, attributes))

createNewResources(1111,2222,"/home/karsten/Wreckage/Server/dist/Debug/GNU-Linux-x86/server", "server")
createNewResources(1111,2223,"/home/karsten/Wreckage/UnityClient/bin/unityScriptInterface", "client")

@asyncio.coroutine
def decodeReqeust(message, writer):
	print("MESSAGE  =" + str(message))
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
		print("hest1")
		while gotAll == False:
			
			temp = {}	
			needSoftware = False
			loopCheck = True
			for toFind in re.findall("([A-Za-z]*):(\d+);?", testHeads):
				print("hest2")
				print(toFind)
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
			print("hest3")
			#we are here. We got it all
			gotAll = True
			#Allocate
			if haveSoftware == True:
				resources.remove(temp)
			
			#Prepaire
			data = ""
			print(temp)
			for r in temp:
				
				result = yield from r.prepare(softwareHash)
				data += result +"," 
			writer.write(data + "\n")
			yield from writer.drain()		


@asyncio.coroutine
def handle_echo(reader, writer):
	while True:
		message = yield from reader.readline()
		if len(message) > 0:
			yield from decodeReqeust(message.decode().strip(), writer)

			addr = writer.get_extra_info('peername')
			print("Received %r from %r" % (message, addr))
		else:
			try:
				writer.close()
			except Exception as e:
				print(e)
			break;






loop = asyncio.get_event_loop()
coro = asyncio.start_server(handle_echo, '127.0.0.1', 8888, loop=loop)
server = loop.run_until_complete(coro)

for r in resources:
	asyncio.async(Resource.handle_testhead(r))

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
