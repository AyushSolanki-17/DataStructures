#include <stdio.h>
#include <stdlib.h>
#define N 5 // Size of Stack

int top = -1;   // Top Pointer

/*
 *  push(int s[],int x)
 *  --------------------------------------
 *      Pushes(Inserts) an element into Stack.
 *  Params:
 *          s[]: Stack Array.
 *          x: Element to be inserted.
 */
void push(int s[], int x)
{
    if (top >= N)
    {
        printf("Stack Overflow");
        exit(0);
    }
    top += 1;
    s[top] = x;
    printf("\nElement %d pushed...", x, top);
}

/*
 *  pop(int s[])
 *  --------------------------------------
 *      Pops(Deletes) an element into Stack.
 *  Params:
 *          s[]: Stack Array.
 */
void pop(int s[])
{
    if (top < 0)
    {
        printf("\nStack Underflow");
        exit(0);
    }
    printf("\nElement %d popped...", s[top]);
    top--;
}

/*
 *  peep(int s[],int i)
 *  --------------------------------------
 *      Gets Ith element from top of the stack.
 *  Params:
 *          s[]: Stack Array.
 *          i: Element to be peeped.
 */
void peep(int s[], int i)
{
    if (top < i)
    {
        printf("\nStack Underflow %d",i);
        exit(0);
    }
    printf("\n%d Element is %d", i, s[top - i]);
}

/*
 *  change(int s[], int x, int i)
 *  --------------------------------------
 *      Changes Ith element with X into Stack.
 *  Params:
 *          s[]: Stack Array.
 *          x: Element to be inserted.
 *          i: Element to be replaced.
 */
void change(int s[], int x, int i)
{
    if (top<i)
    {
        printf("\nStack Underflow %d",i);
        exit(0);
    }
    s[top - i] = x;
    printf("\n%d Element is replaced with %d...", i, x);
}

/*
 *  display(int s[])
 *  --------------------------------------
 *      Displays all the elements of stack.
 *  Params:
 *          s[]: Stack Array.
 */
void display(int s[])
{
    printf("\nElements of Stack are: ");
    for (int i = top; i >= 0; i--)
    {
        printf(" %d ", s[i]);
    }
}

void main()
{
    // stack variable holds stack. choice variable holds user's choice.
    // ele variable will hold element to be inserted. pos will hold position of element to be replaced. 
    int stack[N], choice, ele,pos;
    while (1)
    {
        printf("\n1) PUSH");
        printf("\n2) POP");
        printf("\n3) PEEP");
        printf("\n4) CHANGE");
        printf("\n5) DISPLAY");
        printf("\n6) EXIT");
        printf("\nEnter a choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter element to be Inserted: ");
                scanf("%d",&ele);
                push(stack,ele);
                break;

            case 2:
                pop(stack);
                break;

            case 3:
                printf("\nEnter element to be Peeped: ");
                scanf("%d",&ele);
                peep(stack,ele);
                break;
            case 4:
                printf("\nEnter Position of element to be Replaced: ");
                scanf("%d",&pos);
                printf("\nEnter new element: ");
                scanf("%d",&ele);
                change(stack,ele,pos);
                break;
            case 5:
                display(stack);
                break;
            default:
                exit(0);
                break;
        }
    }
}