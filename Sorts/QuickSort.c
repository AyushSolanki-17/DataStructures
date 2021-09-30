#include<stdio.h>

void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int lb,int ub)
{
    int key = arr[lb];
    int i=lb,j=ub,temp,flag=1;
    while(flag)
    {
        while (arr[i]<=key)
        {
            i++;
        }
        while (arr[j]>key)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
        else
        {
            flag=0;
        }
        
    } 
    swap(&arr[lb],&arr[j]);
    return j;
}

void QuickSort(int arr[], int lb,int ub)
{
    if(lb<ub)
    {
        int x = partition(arr,lb,ub);
        QuickSort(arr,lb,x-1);
        QuickSort(arr,x+1,ub);
    }
}

void main()
{
    int arr[] = {7,46,10,5,92,22,1,15,18};
    QuickSort(arr,0,8);
    for (int i = 0; i < 9; i++)
    {
        printf(" %d ",arr[i]);
    }
    
}
