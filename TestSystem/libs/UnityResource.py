import sys
from libs.TestResource import TestResource
from threading import Thread
from queue import Queue, Empty
import socket
import re
import io
import time



class UnityResource (TestResource):

	def reader(self):
		print("reader sock recv")
		while True:		
			line = self.sock.recv(1024).decode()
			self.queue.put(line)

	def __init__(self, host, port):
		self.host = host
		self.port = port
		self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.connect()
		print("connected")
		self.recThread = Thread(target = self.reader, args=())
		self.recThread.deamon = True
		self.recThread.start();

		print("tread started")
		self.queue = Queue()	



	def connect(self):
		self.sock.connect((self.host, self.port))

	def send(self, message):
		totaltsent = 0
		self.sock.send(message.encode())
		print("send Unity " + str(message))


		

	def recv(self, regX, timeout):
		r = re.compile(regX)
		end = time.time() + timeout
		buff = io.StringIO()

		while( end > time.time()):
			try: buff.write( self.queue.get_nowait())
			except Empty:
				time.sleep(0.1)
				continue
			else:

				line = buff.getvalue()
				if(r.match(line)):
					return True


		raise Exception("Test Failed message " + str(regX) + " not received")
		return False
	

