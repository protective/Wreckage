import sys
from libs.TestResource import TestResource
from threading import Thread
from queue import Queue, Empty
import socket
import re
import io
import time
import os
import subprocess


class ServerResource (TestResource):

	def reader(self):
		while True:
			try:
				print("try read")
				line = self.p.communicate().stdout
				print("done read")
				self.queue.put(line)

			except (KeyboardInterrupt, SystemExit):
				sys.exit()
			

	def __init__(self, host, port):
		self.host = host
		self.port = port
		self.p = None
		self.connect()

		self.recThread = Thread(target = self.reader, args=())
		self.recThread.setDaemon( True)
		self.recThread.start();

		self.queue = Queue()	


	def deallocate(self):
		self.sock.close()

	def connect(self):
		self.p = subprocess.Popen("/home/karsten/Wreckage/Server/dist/Debug/GNU-Linux-x86/server", stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		print("server running")

	def send(self, message):
		totaltsent = 0
		##print("sent="+ str(message))
		##self.p.communicate(message)
		#print("done")

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
	

