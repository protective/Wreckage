import asyncio

import sys
from libs.TestResource import TestResource
from queue import Queue, Empty
import socket
import re
import io
import time
import os


class ServerResource (TestResource):
	res = None
	reader = None
	writer = None
	@asyncio.coroutine
	def asyncRead(self):
		try:
			while True:
				line =  yield from self.reader.readline()
				line = line.decode("utf-8")
				#print("\"" + str(line) + "\"")
				self.resQueue.put(line)

		except (KeyboardInterrupt, SystemExit):
			print("server readThread exit")
			self.close()
		except Exception as e:
			print(e)
		
			
	@asyncio.coroutine
	def asyncSend(self):
		try:
			while True:
				try: 
					line = (self.sendQueue.get_nowait())
					self.writer.write(line.encode("utf-8"))
					print("Test " +str(self.port) + ">>" + str(line))
					yield from self.writer.drain() 
					#self.resQueue.put(line)
				except Empty:
					yield from asyncio.sleep(1.0)
					continue
		except (KeyboardInterrupt, SystemExit):
			print("server readThread exit")
			self.close()
		except Exception as e:
			print(e)			
	
	def __init__(self, host, port):
		print("init server")
		self.host = host
		self.port = port
		
		self.res = asyncio.open_connection(host, port)
		print(type(self.res))
		self.sendQueue = None
		self.resQueue = None
		self.reset()
	
	
	def close(self):
		try:
			print("Closing resource")
			if(self.writer != None):
				self.writer.close()
			print("done closing")
		except Exception as e:
			print(e)
			pass
		
			
	def reset(self):
		print("reset server")
		self.sendQueue = Queue()
		self.resQueue = Queue()

	def connect(self):
		print("connect TODO?")

	def send(self, message):
		try:
			if(message[-1:] != "\n"):
				message += "\n"
			self.sendQueue.put(message)
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
			while( end > time.time()):
				try: 
					line = (self.resQueue.get_nowait())
					print("Test " + str(self.port) + "<< " + str(line.replace("\n","")))

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
	

