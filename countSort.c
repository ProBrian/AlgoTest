#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    int array[100];
    int len;
    int i=0;
    printf("input the max value of this array:\n");
    scanf("%d", &a);
    fflush(stdin);
    printf("input the number array need to be sort: \n");
    do{
        sscanf("%d", &array[i++]);
        len++;
    }while(getchar() != '\n');

    printf("max value: %d, Unsorted array:", a);
    for(i=0; i< len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    /*Merge sort part*/
    /*
    mergeSort(array, 0, len-1);
    printf("Sorted array :");
    for(i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 1;
    */
}
