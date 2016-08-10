#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int i;
    int len = argc - 1;
    int array[len];
    if(argc < 2)
        return 0;
    /*read unsorted numbers*/
    for (i=0; i<len; i++)
    {
        array[i] = atoi(argv[i+1]);
    }
    printf("before insert sorted: ");
    for(i=0;i<len;i++)
    { 
        printf("%d ", array[i]); }
        printf("\n"); /*outer loop, from the 2nd number to the end*/ for(i=1; i<len; i++ ) { int j = i-1; int key = array[i]; /*inner loop, compare key[i] to numbers before it*/ /*after one inner loop, array[0] to array[i] become sequential*/ for(; j >= 0; j--)
        {
            if(key < array[j])
            {
                array[j+1] = array[j];
            }
            else
            {
                break;
            }
        }
        /* this is the correct spot of key[i]*/
        array[j+1] = key;
    }
    
    printf("after insert sorted: ");
    for(i=0;i<len;i++)
    {
        printf("%d ", array[i]);
    }
    printf(",O is N*N\n");
    return 1;
}
