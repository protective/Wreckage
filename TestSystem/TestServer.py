from libs.UnityResource import UnityResource
from libs.ServerResource import ServerResource

import re
import select
import socket
import sys
from queue import Queue, Empty

def loadUnityRes(port):
	#try:
	c = UnityResource("127.0.0.1", port)

	return c
	#except Exception:
	#	print("ERROR fail to start resource")
	#	return False


def loadServerRes(port):
	#try:
	c = ServerResource("127.0.0.1", port)
	return c
	#except Exception:
	#	print("ERROR fail to start resource")
	#	return False


def handleIO():

	# Wait for at least one of the sockets to be ready for processing
	print ('waiting for the next event')
	events = poller.poll(TIMEOUT)

	for fd, flag in events:

		# Retrieve the actual socket from its file descriptor
		s = fd_to_socket[fd]

		# Handle inputs
		if flag & (select.POLLIN | select.POLLPRI):

			if s is server:
				# A "readable" server socket is ready to accept a connection
				connection, client_address = s.accept()
				#print >>sys.stderr, 'new connection from', client_address
				connection.setblocking(0)
				fd_to_socket[ connection.fileno() ] = connection
				poller.register(connection, READ_ONLY)

				# Give the connection a queue for data we want to send
				ind_message_queues[connection] = Queue()
				out_message_queues[connection] = Queue()
			else:
				data = s.recv(1024)

				if data:
					# A readable client socket has data
					print >>sys.stderr, 'received "%s" from %s' % (data, s.getpeername())
					ind_message_queues[s].put(data)
					# Add output channel for response
					poller.modify(s, READ_WRITE)
				else:
					# Interpret empty result as closed connection
					print >>sys.stderr, 'closing', client_address, 'after reading no data'
					# Stop listening for input on the connection
					poller.unregister(s)
					s.close()

					# Remove message queue
					del ind_message_queues[s]
					del out_message_queues[s]
				
		elif flag & select.POLLHUP:
			# Client hung up
			print >>sys.stderr, 'closing', client_address, 'after receiving HUP'
			# Stop listening for input on the connection
			poller.unregister(s)
			s.close()
		elif flag & select.POLLOUT:
			# Socket is ready to send data, if there is any to send.
			try:
				next_msg = out_message_queues[s].get_nowait()
			except Empty:
				# No messages waiting so stop checking for writability.
				print >>sys.stderr, 'output queue for', s.getpeername(), 'is empty'
				poller.modify(s, READ_ONLY)
			else:
				print >>sys.stderr, 'sending "%s" to %s' % (next_msg, s.getpeername())
				s.send(next_msg)
		elif flag & select.POLLERR:
			print >>sys.stderr, 'handling exceptional condition for', s.getpeername()
			# Stop listening for input on the connection
			poller.unregister(s)
			s.close()

			# Remove message queue
			del ind_message_queues[s]
			del out_message_queues[s]

def handleRequests():

	for k, q in ind_message_queues:
		try:
		
			v = q.get_nowait()
			print (str(k) + str(v))
			serverCount = 0
			unityCount = 0

			temp = re.match(".*ServerRes:(\d+).*", v)
			if(temp != None):
				serverCount = int(temp.group(1))

			temp = re.match(".*UnityRes:(\d+).*", v)
			if(temp != None):
				unityCount = int(temp.group(1))
	
			if len(serversRes) >= serverCount and len(unityRes) >= unityCount:
			#TODO return the ips and ports
				out_message_queues[k].put("YOU SHALL HAVE IT")
			else:
				out_message_queues[k].put("YOU SHALL NOT PASS")
		except Empty:
			continue


# Create a TCP/IP socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setblocking(0)

# Bind the socket to the port
server_address = ('', 2000)
#print >>sys.stderr, 'starting up on %s port %s' % server_address
server.bind(server_address)

# Listen for incoming connections
server.listen(5)

# Keep up with the queues of outgoing messages
ind_message_queues = {}
out_message_queues = {}


# Do not block forever (milliseconds)
TIMEOUT = 1000

# Commonly used flag setes
READ_ONLY = select.POLLIN | select.POLLPRI | select.POLLHUP | select.POLLERR
READ_WRITE = READ_ONLY | select.POLLOUT

# Set up the poller
poller = select.poll()
poller.register(server, READ_ONLY)

# Map file descriptors to socket objects
fd_to_socket = { server.fileno(): server,}


serversRes = []

serversRes.append(('127.0.0.1',30001))

unityRes = []
unityRes.append(('127.0.0.1',40001))


try:
	while True:
		handleIO()
		handleRequests()
except KeyboardInterrupt:
	pass










