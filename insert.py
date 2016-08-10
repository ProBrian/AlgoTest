#!/usr/bin/python
#Filename: insert.py

import sys

sArray = []
for i in range(1, len(sys.argv)):
    sArray.append(sys.argv[i])
print 'unsorted array', sArray

for i in range(1, len(sArray)):
    key = sArray[i]
    j = i-1
    while ((j>=0) and (key < sArray[j])):
        sArray[j+1] = sArray[j]
        j=j-1
    # in C, j will become -1 after a "j--", but in python it's not,
    # so here we don't use for loop
    sArray[j+1] = key
        
print 'sorted array', sArray

