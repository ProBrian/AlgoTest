#!/usr/bin/python
#Filename: merge.py

import sys

sArray = []
for i in range(1, len(sys.argv)):
    sArray.append(sys.argv[i])
print 'Merge, unsorted array: ', sArray

def merge(array, start, end, barrier):
    arrayL = []
    arrayR = []
    for i in range(0, barrier-start+1):
        arrayL.append(array[start+i])
    for i in range(0, end-barrier):
        arrayR.append(array[barrier+i+1])
    i=0
    j=0
    for k in range(start, end+1):
        if (i>barrier-start) or ((j< end-barrier) and (arrayR[j]<arrayL[i])):
            array[k] = arrayR[j]
            j=j+1
        elif(j>end-barrier-1) or ((i<barrier-start+1) and
                (arrayL[i]<arrayR[j])):
            array[k] = arrayL[i]
            i=i+1

def mergeSort(array, start, end):
    if start < end:
        middle = (start+end)/2
        mergeSort(array, start, middle)
        mergeSort(array, middle+1, end)
        merge(array, start, end, middle)


mergeSort(sArray, 0, len(sArray)-1)
print 'sorted array: ', sArray

