import asyncio
import re
import sys
import io
from queue import Queue, Empty
from asyncio.locks import Event
from cgitb import reset
pToc = Queue()
restart = Event()
restart.clear()
port = ""
proc = None

@asyncio.coroutine
def handle_pTocQueue(pToc, writer):
	global restart
	try:
		while not restart.is_set():
			try: 
				line = (pToc.get_nowait())
				writer.write(line)
				print("deamon >> client: " + str(line))
				sys.stdout.flush()
				yield from writer.drain()

			except Empty:
				yield from asyncio.sleep(1.0)
	except Exception as e:
		print(e)
		
@asyncio.coroutine
def handle_cTop(reader):
	global proc
	global restart
	try:
		while True:
			message = yield from reader.read(100)
			print("Despatcher >> Deamon " + str(message))
			if not restart.is_set() and proc != None and len(message) > 0: 
				print("Deamon >> Process " + str(message))
				sys.stdout.flush()
				proc.stdin.write(message)
				yield from proc.stdin.drain()
				print("deamon >> Process DONE: " + str(message))
				sys.stdout.flush()
			else:
				restart.set()
				break
	except Exception as e:
		print(e)
		pass

	
@asyncio.coroutine
def handle_clients(reader, writer):
	global pToc
	global restart
	print("handle_clients")
	sys.stdout.flush()
	ptoc = handle_pTocQueue(pToc, writer)
	ctop = handle_cTop(reader)
	yield from asyncio.gather(ptoc,ctop)
	print("do reset deamon")
	sys.stdout.flush()
	

@asyncio.coroutine
def monitorState(proc):
	global restart
	print(type(restart))
	print(restart.is_set())
	yield from restart.wait()
	
	proc.terminate()


@asyncio.coroutine
def streamToQueue(stream):
	global pToc
	while True:
		print("rdy to read from process")
		sys.stdout.flush()
		data = yield from stream.read(100)
		if len(data) == 0:
			break
		pToc.put(data)
		print("process >> deamon: " + str(data))
		sys.stdout.flush()

@asyncio.coroutine
def handle_resource():
	global pToc
	global restart
	global proc
	while True:
		print("restart resources")
		sys.stdout.flush()
		restart.clear()
		create = asyncio.create_subprocess_exec(childName, stdin=asyncio.subprocess.PIPE, stdout=asyncio.subprocess.PIPE)
		proc = yield from create
		taksStream = streamToQueue(proc.stdout)
		taksMonitor = monitorState(proc)
		
		yield from asyncio.gather(taksMonitor,taksStream)
		# Wait for the subprocess exit
		yield from proc.wait()
		yield from asyncio.sleep(1)
	return True

try:
	childName = sys.argv[1]
	port = int(sys.argv[2])
except Exception as e:
	print(str(e))
	sys.stdout.flush()
	exit(1)

print("deamon")
sys.stdout.flush()
 
loop = asyncio.get_event_loop()

coro = asyncio.start_server(handle_clients, '127.0.0.1', port, loop=loop)
server = loop.run_until_complete(coro)

asyncio.async(handle_resource())


try:
	loop.run_forever()
except KeyboardInterrupt:
	pass

# Close the server
server.close()
loop.run_until_complete(server.wait_closed())
loop.close()

