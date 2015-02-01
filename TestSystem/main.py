import sys
import multiprocessing as mp
import argparse
import re
import subprocess
from threading import Thread
import os
from libs.UnityResource import UnityResource
from libs.ServerResource import ServerResource
from threading import Semaphore
from queue import Queue, Empty

import time

activeTests = []

def enqueue_output(out, queue):
	try:
		for line in iter(out.readline, b''):
		    queue.put(line.decode("utf-8"))
		out.close()
	except IOError:
		pass



def RunTest():
	while (not testqueue.empty()) or len(activeTests) > 0:
		time.sleep(1)

		initiatingNew = False
		
		for p in activeTests[:]:
			#print(p[2])
			try:
				msg = "ok"
				while(msg != ""):
					try:
						msg = p[1].get_nowait() # or q.get(timeout=.1)
					except Empty:
						msg = ""
						#print("communication timeout")
					finally:
						if(p[2][1] == "INIT"):
							
							r = re.compile("TEST INIT NO RESOURCES\n", re.DOTALL)
							if(r.match(msg)):
								print("MAIN NO RES")
								p[2][1] = "TERMINATE"
								initiatingNew = False
						
							r = re.compile("TEST INIT OK\n", re.DOTALL)
							if(r.match(msg)):
								p[2][1] = "RUNNING"
								msg = ""
								initiatingNew = False

						if(p[2][1] == "RUNNING"):
					
							r = re.compile("PASS\n", re.DOTALL)
							if(r.match(msg)):
								print(str(p[2][0]) + " " + str("PASS"))
							
							r = re.compile("FAIL\n", re.DOTALL)
							if(r.match(msg)):
								print(str(p[2][0]) + " " + str("FAIL"))

							r = re.compile("COMPLETE\n", re.DOTALL)
							if(r.match(msg)):
								#print(str(p[2][0]) + " " + str("COMPLETE"))
								p[2][1] = "TERMINATE"
							
						if(last[2][1] == "TERMINATE"):
							try:
								p[0].kill()
							except OSError:
								pass
	
							msg = ""
							activeTests.remove(p)
							
							
			except KeyboardInterrupt:
				pass
			except Exception as e:
				print(e)

		if initiatingNew == True:
			continue

		#Create new testprocessores
		
		try:
			test = testqueue.get(False)
			
			last = None
			if(test == None):
				continue
			try:
				print("begin test " + str(test[0]) + "_" + str(test[1]))
				initiatingNew = True
				p = subprocess.Popen(["python3", "TestRunner.py", "-t", test[0]], stdout=subprocess.PIPE)
				q = Queue()
				t = Thread(target=enqueue_output, args=(p.stdout, q))
				t.daemon = True # thread dies with the program
				t.start()
				
				last = [p, q, [str(test[0]) + "_" + str(test[1]), "INIT"]]
				
				activeTests.append(last)
			except KeyboardInterrupt:
				pass
			except Exception as e:
				print(e)
				continue
			testqueue.task_done()
		except Empty:
			pass	


		

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
	testqueue = Queue()
	
	l = f.readline();
	while(l):
		testCase = re.match("[ |\t]*([^ |^\t]*)[ |\t]*(\d+)[ |\t]*\n", l)
		if(testCase != None):
			for i in range(0, int(testCase.group(2))):
				testqueue.put((testCase.group(1), i))
	#testqueue.put("ServerProjectileHit")
		l = f.readline();


	RunTest()

except (KeyboardInterrupt, SystemExit):
	pass

