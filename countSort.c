#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void countSort(int* array, int len, int max)
{
    int i,j;
    int counter[max+1];
    int sArray[len];//this array need not to initialize
    memset(counter, 0x0, (max+1)*sizeof(int));
    /*count every number's count*/
    for (i=0; i< len; i++)
    {
        counter[array[i]]++;
    }
    
    for (i=1;i<=max;i++)
    {
        counter[i] += counter[i-1];
    }

    for (i=0; i<len; i++)
    {
        j = array[i];
        sArray[counter[j] - 1] = array[i];
        array[i]--;
    }
    memcpy(array, sArray, len*sizeof(int));
}

int main(void)
{
    int a;
    int array[100];
    int len=0;
    int i=0;
    printf("input the max positive value of this array:\n");
    scanf("%d", &a);
    fflush(stdin);
    printf("input the number array(positive) need to be sort: \n");

    do{
        scanf("%d", &array[i++]);
        len++;
    }while(getchar() != '\n');

    printf("max value: %d, Unsorted array:", a);
    for(i=0; i< len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    countSort(array, len, a);

    printf("Sorted array :");
    for(i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 1;
}
