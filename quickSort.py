#!/usr/bin/python
#FileName: quickSort.py

import sys

def partition(array, start, end):
    x = array[end]
    i = start
    for j in range(start, end):
        if int(array[j]) < int(x):
            temp = array[j]
            array[j] = array[i]
            array[i] = temp
            i = i + 1
    array[end] = array[i]
    array[i] = x
    return i

def quickSort(array, start, end):
    if start >= end:
        return
    div = partition(array, start, end)
    quickSort(array, start, div-1)
    quickSort(array, div+1, end)

sArray = []
for i in range(1, len(sys.argv)):
    sArray.append(sys.argv[i])
print 'before sort', sArray

quickSort(sArray, 0, len(sArray)-1)
print 'sorted array:', sArray

