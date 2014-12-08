from libs.TestResource import TestResource
import socket

class UnityResource (TestResource):

	def __init__(self, host, port):
		self.host = host
		self.port = port
		self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.connect()
	
	def connect(self):
		self.sock.connect((self.host, self.port))

	def send(self, message):
		print("send TestResouece")

	def recv(self):
		print("recv TestResouece")

