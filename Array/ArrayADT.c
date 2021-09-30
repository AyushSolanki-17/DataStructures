#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int totalSize;
    int usedSize;
    int *arr;
};

/*
 *  createArray(struct Array *a,int tSize)
 *  --------------------------------------
 *      Creates and array inside the structure  provided.
 *  Params:
 *          *a: Address of the strucutre object created.
 *          tSize: Size of the array you want.
 */
void createArray(struct Array *a,int tSize)
{
    a->totalSize = tSize;
    a->usedSize = 0;
    a->arr = (int *)malloc(tSize*sizeof(int));
}

/*
 *  traverseArray(struct Array *a)
 *  --------------------------------------
 *      Accesses each and every element availble in the array.
 *  Params:
 *          *a: Address of the strucutre object created.
 */
void traverseArray(struct Array *a)
{
    if (a->usedSize<=0)
    {
        printf("Array has no element");
    }
    else
    {
        printf("Elements of Array are : \n");
        for (int i = 0; i < a->usedSize; i++)
        {
            printf(" %d ",a->arr[i]);
        }
    }
}

/*
 *  insertAt(struct Array *a,int e,int p)
 *  --------------------------------------
 *      Insertes the element at given position in array.
 *  Params:
 *          *a: Address of the strucutre object created.
 *           e: Element to be inserted.
 *           p: Position at which array element should be inserted. 
 *                          If posiion is provided as -1 elemnet will be inserted at end of array. 
 */
void insertAt(struct Array *a,int e,int p)
{
    int availableSize = a->totalSize - a->usedSize;
    //printf(" %d ",availableSize);
    if(availableSize<=0)
    {
        a->totalSize += 1;
        int *temp = a->arr;
        a->arr = (int *)malloc(a->totalSize*sizeof(int));
        a->arr = temp;
    }
    if (p==-1)
    {   
        a->arr[a->usedSize] = e;
        a->usedSize+=1;
    }
    else if(p>=0)
    {
        for (int i = a->totalSize; i >=p ; i--)
        {
            a->arr[i+1]= a->arr[i];
        }
        a->arr[p] = e;
        a->usedSize+=1;
    }    
    else
    {
        printf("Cannot Insert Element at given position");
    }
}
/*
 *  deleteAt(struct Array *a,int p)
 *  --------------------------------------
 *      Deletes the element from given position of array.
 *  Params:
 *          *a: Address of the strucutre object created.
 *           p: Position at which array element should be deleted.  
 */
void deleteAt(struct Array *a,int p)
{
    int del = a->arr[p];
    for (int i = p; i <= a->usedSize-1; i++)
    {
        a->arr[i] = a->arr[i+1];
    }
    a->usedSize-=1;
}

// Extra Operations
/*
 *  createAndInsert(struct Array *a)
 *  --------------------------------------
 *      Creates and Inserts elements inside the array dynamically.
 *  Params:
 *          *a: Address of the strucutre object created.  
 */
void createAndInsert(struct Array *a)
{
    int n;
    printf("How much elements you want in array: ");
    scanf("%d",&n);
    createArray(a,n);
    int e;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter element for position %d: ",i);
        scanf("%d",&e);
        insertAt(a,e,-1);
    }   
}


void main()
{
    struct Array a1;
    createAndInsert(&a1);
    traverseArray(&a1);  
}
