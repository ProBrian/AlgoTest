#include <stdio.h> 
#include <stdlib.h>

int partion(int* array, int start, int end)
{
    int i= start;
    int j;
    int x = array[end];

    for (j=start; j<end; j++)
    {
        if (array[j] < x)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }

    array[end] = array[i];
    array[i] = x;
    return i;
}

int quickSort(int* array, int start, int end)
{
    if (start >= end)
        return;

    int div = partion(array, start, end);
    quickSort(array, start, div-1);
    quickSort(array, div+1, end);
}

int main(int argc, char** argv)
{
    int len = argc -1;
    int array[len];
    int i;
    printf("quick sort\nUnsorted array:"); 
    for(i=0; i<len; i++)
    {
        array[i] = atoi(argv[i+1]);
        printf("%d ", array[i]);
    }
    printf("\n");
    
    quickSort(array, 0, len-1);
    printf("Sorted array :"); 
    for(i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 1;
}
