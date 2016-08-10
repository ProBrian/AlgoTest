#!/usr/bin/python
#Filename: maxSubarray.py

import sys

class index:
    lf = 0
    rt = 0
    sum = 0

def findSubarrayCrossingMid(array, left, right, mid):
    sum = 0
    sumL = 0
    sumR = 0
    flagL = 0
    flagR = 0
    for i in range(mid, left-1, -1):
        sum = sum + int(array[i])
        if (sum > sumL) or (i ==  mid):
            sumL = sum
            flagL = i
    sum = 0
    for i in range(mid+1, right+1):
        sum = sum + int(array[i])
        if (sum > sumR) or (i == mid+1):
            sumR = sum
            flagR = i
    
    maxIndex = index()
    maxIndex.lf = flagL
    maxIndex.rt = flagR
    maxIndex.sum = sumL + sumR
    return maxIndex

def findSubarray(array, left, right):
    if left == right:
        maxIndex = index()
        maxIndex.lf = left
        maxIndex.rt = right
        maxIndex.sum = int(array[left])
        return maxIndex
    mid = (left+right)/2
    indexL = index()
    indexR = index()
    indexC = index()
    indexL = findSubarray(array, left, mid)
    indexR = findSubarray(array, mid+1, right)
    indexC = findSubarrayCrossingMid(array, left, right, mid)
    
    if (indexL.sum >= indexR.sum) and (indexL.sum >= indexC.sum):
        return indexL
    if (indexR.sum >= indexL.sum) and (indexR.sum >= indexC.sum):
        return indexR
    else:
        return indexC

sArray = []
for i in range(1, len(sys.argv)):
    sArray.append(sys.argv[i])
print 'before finding: ', sArray

sIndex = index()
sIndex = findSubarray(sArray, 0, len(sArray)-1)
print 'max subarray between %s and %s, sum is %s' % (sIndex.lf, sIndex.rt,
        sIndex.sum)


