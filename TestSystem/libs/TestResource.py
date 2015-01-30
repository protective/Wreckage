class TestResource (object):
	def __init__(self):
		print("Init TestResouece")

	def send(self, message):
		print("send TestResouece")

	def recv(self):
		print("recv TestResouece")

	def reset(self):
		print("reset TestResouece")
		
	def close(self):
		print("close TestResouece")
