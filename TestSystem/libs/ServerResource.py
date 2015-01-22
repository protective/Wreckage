import sys
from libs.TestResource import TestResource
from threading import Thread
from queue import Queue, Empty
import socket
import re
import io
import time
import os
import signal
import subprocess


class ServerResource (TestResource):

	def reader(self):
		while True:
			try:
				line = self.p.stdout.readline().decode("utf-8")
				#print("\"" + str(line) + "\"")
				self.queue.put(line)

			except (KeyboardInterrupt, SystemExit):
				self.deallocate()
			

	def __init__(self, host, port):
		self.host = host
		self.port = port
		self.p = None
		self.connect()
		self.queue = Queue()	
		self.recThread = Thread(target = self.reader, args=())
		self.recThread.setDaemon( True)
		self.recThread.start();

		


	def deallocate(self):
		print("dealocate server")
		try:
			self.p.kill()
		except Exception as e:
			print(e)
			pass

	def connect(self):
		try:
			self.p = subprocess.Popen("/home/karsten/Wreckage/Server/dist/Debug/GNU-Linux-x86/server", stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		except KeyboardInterrupt:
			pass
		except Exception as e:
			print(e)

	def send(self, message):
		totaltsent = 0
		##print("sent="+ str(message))
		##self.p.communicate(message)
		#print("done")
		print("Server << " + message)

	def recv(self, regX, timeout):
		try:	
			r = re.compile(regX)
			end = time.time() + timeout
			while( end > time.time()):
				try: 
					line = ( self.queue.get_nowait())
					print("Server >> " + str(line.replace("\n","")))

					if(r.match(line)):
						return True

				except Empty:
					time.sleep(0.1)
					continue
		except (KeyboardInterrupt):
			return False

		raise Exception("Test Failed Server message " + str(regX) + " not received on server")
		return False
	

