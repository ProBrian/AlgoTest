#include <stdio.h>
#include <stdlib.h>

int merge(int* array, int start, int end, int barrier)
{
    int i,j,k;
    int arrayL[barrier-start+1], arrayR[end-barrier];
    /*Assign left and right array, each of them are ordered asc*/
    for(i=0; i<barrier-start+1; i++)
    {
        arrayL[i] = array[start+i];
    }
//    arrayL[i] = 65535;
    for(i=0; i<end-barrier;i++)
    {
        arrayR[i] = array[barrier+i+1];
    }
//    arrayR[i] = 65535; 
    for(i=j=0,k=start; k<end+1;k++)
    {
        if(j>=(end-barrier) || (arrayL[i] <= arrayR[j] && (i<barrier-start+1)))
        {
            array[k] = arrayL[i];
            i++;
        }
        else if(i>=(barrier-start+1) || (arrayL[i] > arrayR[j] && (j<end-barrier)))
        {
            array[k] = arrayR[j];
            j++;
        }
    }
    return 1;
}

int mergeSort(int* array, int start, int end)
{
    int middle;
    if(start < end)
    {
        middle = (start + end) / 2;
        mergeSort(array, start, middle);
        mergeSort(array, middle+1, end);
        merge(array, start, end, middle);
    }
    return 1;
}

int main(int argc, char** argv)
{
    int len = argc - 1;
    int array[len];
    int i;
    printf("Merge Sort\nUnsorted array:");
    for(i=0; i< len; i++)
    {
        array[i] = atoi(argv[i+1]);
        printf("%d ", array[i]);
    }
    printf("\n");
    /*Merge sort part*/
    mergeSort(array, 0, len-1);
    printf("Sorted array :");
    for(i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 1;
}
