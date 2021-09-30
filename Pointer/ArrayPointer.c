#include<stdio.h>


int main(int argc, char const *argv[])
{
    int *ptr;
    int arr[5]={1,2,3,4,5};

    ptr = &arr[0];
    ptr++;
    ptr++;

    printf(" %d %u ",*ptr,ptr);
    
    return 0;
}
