import sys
import multiprocessing as mp
import argparse

import subprocess
from TestRunner import TestRunner


parser = argparse.ArgumentParser(description='Start a test campaign.')
parser.add_argument('-c', '--campaign', help='Test campaign to run')

args = parser.parse_args()

print(args)


testname = "Connect_disconnect"

print (subprocess.call(["python3", "TestRunner" + str(testname) + ".py"]))


