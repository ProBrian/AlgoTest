#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct maxIndex
{
    int flagLeft;
    int flagRight;
    int sum;
}maxIndex;

int levelL=0;
int levelR=0;

/* find max subarray crossing left and right array */
int findSubarrayCrossingMid(int* array, int left, int right, int mid, maxIndex* index)
{
    int i;
    int flagLeft = mid;
    int flagRight = mid;
    int sumLeft = 0;
    int sumRight = 0;
    int sum = 0;

    for(i=mid; i>=left; i--)
    {
        sum+=array[i];
        if((sum>sumLeft) || (i==mid))
        {
            sumLeft = sum;
            flagLeft = i;
        }
    }
    sum = 0;
    for(i=mid+1;i<=right;i++)
    {
        sum+=array[i];
        if((sum>sumRight) || (i==mid+1))
        {
            sumRight = sum;
            flagRight = i;
        }
    }

    index->sum = sumLeft + sumRight;
    index->flagLeft = flagLeft;
    index->flagRight = flagRight;

    return 1;
}

/* find max subarray */
int findSubarray(int* array, int left, int right, maxIndex* index)
{
    int mid = (left + right) / 2; 
    if(left == right)
    {
        index->flagLeft = left;
        index->flagRight = right;
        index->sum = array[left];
        return 1;
    }
    maxIndex indexLeft, indexRight, indexCross;
    memset(&indexLeft, 0x0, sizeof(maxIndex)); 
    memset(&indexRight, 0x0, sizeof(maxIndex)); 
    memset(&indexCross, 0x0, sizeof(maxIndex)); 
    levelL++;
    findSubarray(array, left, mid, &indexLeft);
    levelL--;
    levelR++;
    findSubarray(array, mid+1, right, &indexRight);
    levelR--;
    findSubarrayCrossingMid(array, left, right, mid, &indexCross);

    if((indexLeft.sum>=indexRight.sum) && (indexLeft.sum>=indexCross.sum))
    {
        index->flagLeft = indexLeft.flagLeft;
        index->flagRight = indexLeft.flagRight;
        index->sum = indexLeft.sum;
    }
    else if((indexRight.sum>=indexLeft.sum) && (indexRight.sum>=indexCross.sum))
    {
        index->flagLeft = indexRight.flagLeft;
        index->flagRight = indexRight.flagRight;
        index->sum = indexRight.sum;
    }
    else
    {
        index->flagLeft = indexCross.flagLeft;
        index->flagRight = indexCross.flagRight;
        index->sum = indexCross.sum;
    }
    return 1;
}

int main(int argc, char** argv)
{
    int len=argc-1;
    int array[len];
    int i;
    maxIndex index;
    memset(&index, 0x0, sizeof(maxIndex)); 
    printf("input array: ");
    for(i=0;i<len;i++)
    {
        array[i]=atoi(argv[i+1]);
        printf("%d ", array[i]);
    }
    printf("\n");
    findSubarray(array, 0, len-1, &index);
    printf("Max subarry is from index %d to %d, sum is %d\n", index.flagLeft, index.flagRight, index.sum);
}

