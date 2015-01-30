import sys
import multiprocessing as mp
import argparse
import re
import subprocess
import threading
import os
from libs.UnityResource import UnityResource
from libs.ServerResource import ServerResource
from threading import Semaphore
import queue

import time

activeTests = []


def RunTest():
	while (not testqueue.empty()) or len(activeTests) > 0:
		time.sleep(1)
		try:
			test = testqueue.get(False)
		except queue.Empty:
			test = None
			
		sucess = False
		for p, t in activeTests:
			try:
				msg = p.communicate(timeout=2)[0].decode("utf-8")
				if(msg == "PASS"):
					print(str(t) + str("PASS"))
				if(msg == "FAIL"):
					print(str(t) + str("FAIL"))
			except ValueError as e:
				print("Test commication fail " + str(e))
				activeTests.remove((p,t))
			except KeyboardInterrupt:
				pass
			except Exception as e:
				print(e)
							
				
		last = None
		if(test == None):
			continue
		try:
		# 
			print("begin test " + test)
			last = subprocess.Popen(["python3", "TestRunner.py", "-t", test], stdout=subprocess.PIPE)
			activeTests.append((last, test))
		except KeyboardInterrupt:
			pass
		except Exception as e:
			print(e)
			continue
		try:
			try:
				msg = last.communicate(timeout=15)[0].decode("utf-8")
				print(type(msg))
				if(msg == "TEST INIT NO RESOURCES"):
					print("MAIN NO RES")
					raise subprocess.TimeoutExpired
				print("done")
			except subprocess.TimeoutExpired:
				print("failed to start test")
				last.kill()
				activeTests.remove((last, test))
		except KeyboardInterrupt:
			pass
		except Exception as e:
			print(e)

		testqueue.task_done()

parser = argparse.ArgumentParser(description='Start a test campaign.')
parser.add_argument('-c', '--campaign', help='Test campaign to run')

args = parser.parse_args()
print(args)
try:
	f = open(args.campaign)
except (IOError):
	print("CRITICAL campaign not found")
	exit(1)

try:
	testqueue = queue.Queue()
	
	l = f.readline();
	while(l):
		print("line=" + l)
		testCase = re.match("[ |\t]*([^ |^\t]*)[ |\t]*(\d+)[ |\t]*\n", l)
		if(testCase != None):
			for i in range(0, int(testCase.group(2))):
				testqueue.put(testCase.group(1))
	#testqueue.put("ServerProjectileHit")
		l = f.readline();


	RunTest()

except (KeyboardInterrupt, SystemExit):
	pass

