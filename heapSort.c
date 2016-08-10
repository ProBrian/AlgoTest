#include <stdio.h> 
#include <stdlib.h>

#define PARENT(i) ((i)/2)
#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)

int heapSize;
/*make array[pos]'s sub tree became a max heap*/
void maxHeapify(int* array, int pos)
{
    int left = LEFT(pos);
    int right = RIGHT(pos);
    int largest = 0;

    if ((array[pos-1] < array[left-1]) && (left <= heapSize))
    {
        largest = left;
    }
    else
    {
        largest = pos;
    }

    
    if ((array[largest-1] < array[right-1]) && (right <= heapSize))
    {
        largest = right;
    }

    if (largest != pos)
    {
        int temp = array[largest-1];
        array[largest-1] = array[pos-1];
        array[pos-1] = temp;
        maxHeapify(array, largest);
    }
}

/* build a max heap*/
void buildMaxHeap(int* array, int size)
{
    int i;
    heapSize = size;

    for (i=(size/2); i>0; i--)
    {
        maxHeapify(array, i);
    }
}

/* sort a max heap*/
void sortMaxHeap(int* array, int size)
{
    int i;

    for (i=size; i>1; i--)
    {
        int temp = array[i-1];
        array[i-1] = array[0];
        array[0] = temp;
        heapSize--;
        maxHeapify(array, 1);
    }
}

int main(int argc, char** argv)
{
    int len = argc -1;
    int array[len];
    int i;
    printf("Heap sort\nUnsorted array:"); 
    for(i=0; i<len; i++)
    {
        array[i] = atoi(argv[i+1]);
        printf("%d ", array[i]);
    }
    printf("\n");
    
    buildMaxHeap(array, len);
    sortMaxHeap(array, len);
    printf("Sorted array :"); 
    for(i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 1;
}

