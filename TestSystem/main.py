import sys
import multiprocessing as mp
import argparse

import subprocess
import threading
from threading import Semaphore
from queue import Queue
from TestRunner import TestRunner

resourseLock = Semaphore(1)

def workerRunTest():
	while not testqueue.empty():
		test = testqueue.get()
		runner = TestRunner(test)
		
		resourseLock.acquire(blocking=True)
		runner.allocResources()
		resourseLock.release()
		runner.begin()
		testqueue.task_done()

parser = argparse.ArgumentParser(description='Start a test campaign.')
parser.add_argument('-c', '--campaign', help='Test campaign to run')

args = parser.parse_args()

print(args)

testqueue = Queue()

testqueue.put("Connect_disconnect_1000")

print("begin")
for i in range(0, 1):
	t = threading.Thread(target=workerRunTest)
	t.deamon = True
	t.start()
print("end")

testqueue.join()


print("ALL DONE")
exit(1)


