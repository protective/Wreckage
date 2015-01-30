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
	
		try:
			while True:
				line = self.p.stdout.readline().decode("utf-8")
				#print("\"" + str(line) + "\"")
				self.queue.put(line)

		except (KeyboardInterrupt, SystemExit):
			print("server readThread exit")
			self.deallocate()
		except Exception as e:
			print(e)
			self.readFail = True
			
			

	def __init__(self, host, port):
		print("init server")
		self.host = host
		self.port = port
		
		self.p = None
		self.queue = None
		self.readFail = False
		self.reset()
	
	def close(self):
		try:
			if(self.p != None):
				self.p.kill()
			self.p = None	
		except Exception as e:
			print(e)
			pass
		
			
	def reset(self):
		print("reset server")
		time.sleep(1)
		try:
			if(self.p != None):
				self.p.kill()

			self.queue = Queue()
			self.p = None	
			self.connect()
			
			self.recThread = Thread(target = self.reader, args=())
			self.recThread.setDaemon( True)
			self.recThread.start();
		except KeyboardInterrupt:
			pass
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
			self.reset()

	def send(self, message):
		try:
			if(self.readFail == False):
				totaltsent = 0
				##print("sent="+ str(message))
				##self.p.communicate(message)
				#print("done")
				print("Server << " + message)
				return
		except (KeyboardInterrupt):
			return
		except Exception as e:
			print(e)
		raise Exception("Test Failed Server message " + str(message) + " not sent on server")

	def recv(self, regX, timeout):
		try:	
			r = re.compile(regX)
			end = time.time() + timeout
			while( end > time.time() and self.readFail == False):
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
		except Exception as e:
			print(e)

		raise Exception("Test Failed Server message " + str(regX) + " not received on server")
		return False
	

