from libs.TestResource import TestResource

class UnityResource (TestResource):
	def send(self, message):
		print("send TestResouece")

	def recv(self):
		print("recv TestResouece")

