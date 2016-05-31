from multiprocessing import Process, Lock
from multiprocessing.sharedctypes import Value, Array
from operator import itemgetter
import operator
import time
import random

def bubble(A):
	print len(A)
	for i in range(len(A)):
		for k in range(len(A)-1, i, -1):
			if(A[k][0] < A[k-1][0]):
				swap(A,k,k-1)
				
def swap(A,x,y):
	temp = A[x]
	A[x] = A[y]
	A[y] = temp
	
def maxItemLength(a):
    maxLen = 0
    rows = len(a)
    cols = len(a[0])
    for row in xrange(rows):
        for col in xrange(cols):
            maxLen = max(maxLen, len(str(a[row][col])))
    return maxLen

def print2dList(a):
    if (a == []):
        print []
        return
    rows = len(a)
    cols = len(a[0])
    fieldWidth = maxItemLength(a)
    for row in xrange(rows):
        if (row > 0): print "\n",
        for col in xrange(cols):
            if (col > 0): print "",
            format = "%" + str(fieldWidth) + "s"
            print format % str(a[row][col]),
        print "",
    print ""

if __name__ == '__main__':
	
	#n = int(input("Enter number of nodes: "))

	#Open and read file
	with open("test1.txt") as textFile:
	    checks = [line.split() for line in textFile]
	
	print "STARTING LIST"
	print2dList(checks)
	print "*******************"
#	col = 1
#	colList = [ checks[i][col] for i in xrange(len(checks)) ]
	#print colList
	
#	bubble(checks)
	checks.sort(cmp = lambda x,y: cmp(x[0],y[0]))
	print2dList(checks)
	

	

		
	
	


	
	
