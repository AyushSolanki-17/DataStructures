#include <stdio.h>

/*
 *  swap(int *n1,int *n2)
 *  --------------------------------------
 *      Swaps the value of n1 and n2.
 *  Params:
 *          *n1 = Location of n1
 *          *n2 = Location of n2 
 */
void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

/*
 *  BubbleSort(int arr[],int n)
 *  --------------------------------------
 *      Sorts the given array of n elements with Buuble Sort Technique.
 *  Params:
 *          arr[] = Array to be sorted
 *          n = Number of elements in array 
 */
void BubbleSort(int arr[],int n)
{
    int pass,exch,temp;
    // Looping over the array.
    for(pass = 0;pass<=n-1;pass++)
    {
        // exch variable is used to measure passes so that algo can end if array is sorted early.
        exch = 0;
        // looping till the last element.
        for(int i=0;i<n-1-pass;i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(&arr[i],&arr[i+1]);
                exch++;
            }
        }
        // If no exch have been made then algo is sorted so break the loop. 
        if(exch==0)
        {
            break;
        }
    }
}
void main()
{
    int arr[] = {29,17,10,5,11,3};

    printf("Before Sorting:\n");

    // Calculating size of the array
    int n = sizeof(arr)/sizeof(arr[1]);
    
    for(int j=0;j<n;j++)
    {
        printf(" %d ",arr[j]);
    }

    BubbleSort(arr,n);

    printf("\nAfter Sorting:\n");
    
    for(int j=0;j<n;j++)
    {
        printf(" %d ",arr[j]);
    }
} 