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


class UnityResource (TestResource):

	def reader(self):
		while True:
			try:
				line = self.p.stdout.readline()
				self.queue.put(line.decode("utf-8"))

			except (KeyboardInterrupt, SystemExit):
				self.deallocate()
			
			

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
		print("dealocate unity")
		try:
			print("kill" + str(self.p.pid))
			#os.killpg(self.p.pid, signal.SIGTERM)
			self.p.kill()
		except Exception as e:
			print(e)
			pass

	def connect(self):
		try:
			self.p = subprocess.Popen("/home/karsten/Wreckage/UnityClient/bin/unityScriptInterface", stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
		except KeyboardInterrupt:
			pass
		except Exception as e:
			print(e)

	def send(self, message):
		try:
			totaltsent = 0
			print("send")
			message += str("\n")
			print(message)
			self.p.stdin.write(message.encode("utf-8"))
			self.p.stdin.flush()
			print("done sent" )
		except (KeyboardInterrupt):
			return False

	def recv(self, regX, timeout):
		try:
			r = re.compile(regX)
		
			end = time.time() + timeout
			while( end > time.time()):
				try: 
					line = ( self.queue.get_nowait())
					print("Unity >> " + str(line.replace("\n","")))
					if(r.match(line)):
						return True

				except Empty:
					time.sleep(0.1)
					continue
		except (KeyboardInterrupt):
			return False

		raise Exception("Test Failed message " + str(regX) + " not received on unity")
		return False
	

