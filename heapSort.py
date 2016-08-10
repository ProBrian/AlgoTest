#!/usr/bin/python
#FileName: heapSort.py 

import sys

def maxHeapify(array, pos):
    left = pos * 2
    right = pos * 2 + 1
    global heapSize

    if (left <= heapSize) and (int(array[pos-1]) < int(array[left-1])):
        largest = left
    else:
        largest = pos

    if (right <= heapSize) and (int(array[largest-1]) < int(array[right-1])):
        largest = right

    if largest != pos:
        temp = array[pos-1]
        array[pos-1] = array[largest-1]
        array[largest-1] = temp
        maxHeapify(array, largest)

def buildMaxHeap(array, size):
    for i in range(size/2, 0, -1):
        maxHeapify(array, i)

def sortMaxHeap(array, size):
    global heapSize
    for i in range(size, 1, -1):
        temp = array[i-1]
        array[i-1] = array[0]
        array[0] = temp
        heapSize = heapSize - 1
        maxHeapify(array, 1)


sArray = []
for i in range(1, len(sys.argv)):
    sArray.append(sys.argv[i])
print 'before sorting: ', sArray

heapSize = len(sArray)
buildMaxHeap(sArray, heapSize)
sortMaxHeap(sArray, heapSize)
print 'sorted array:', sArray


