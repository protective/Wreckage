import sys
import multiprocessing as mp
import argparse

parser = argparse.ArgumentParser(description='Start a test campaign.')
parser.add_argument('-c', '--campaign', help='Test campaign to run')

args = parser.parse_args()
print(args)
