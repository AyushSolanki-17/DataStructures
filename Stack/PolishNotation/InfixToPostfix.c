#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define N 25 // Size of Stack

int top = -1;   // Top Pointer

static int loc = -1;

/*
 *  push(char s[],char x)
 *  --------------------------------------
 *      Pushes(Inserts) an element into Stack.
 *  Params:
 *          s[]: Stack Array.
 *          x: Element to be inserted.
 */
void push(char s[], char x)
{
    if (top >= N)
    {
        printf("Stack Overflow");
        exit(0);
    }
    top += 1;
    s[top] = x;
    //printf("\nElement %c pushed...", x, top);
}

/*
 *  pop(char s[])
 *  --------------------------------------
 *      Pops(Deletes) an element into Stack.
 *  Params:
 *          s[]: Stack Array.
 */
char pop(char s[])
{
    if (top < 0)
    {
        printf("\nStack Underflow");
        return 0;
    }
    else
    {   
        top--;
        //printf("\n%c Popped",s[top+1]);
        return s[top+1];
    }
}

int rankFunction(char c)
{
    if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    {
        return -1;
    }
    else if (isalpha(c))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stackPrecedence(char c)
{
    if (isalpha(c))
    {
        return 8;
    }
    else if (c=='+'||c=='-')
    {
        return 2;
    }
    else if (c=='*'||c=='/')
    {
        return 4;
    }
    else if (c=='^')
    {
        return 5;
    }
    else if (c=='(')
    {
        return 0;
    }
}

int inputPrecedence(char c)
{
    if (isalpha(c))
    {
        return 7;
    }
    else if (c=='+'||c=='-')
    {
        return 1;
    }
    else if (c=='*'||c=='/')
    {
        return 3;
    }
    else if (c=='^')
    {
        return 6;
    }
    else if (c=='(')
    {
        return 9;
    }
    else if(c==')')
    {
        return 0;
    }
}

char nextChar(char infix[])
{
    loc++;
    //printf("\nNext Char %c",infix[loc]);
    return infix[loc];
}
void main()
{
    char stack[50];
    char polish[50]="",infix[50];
    int rank=0;
    char next, temp[2];
    printf("Enter Infix Expression : ");
    scanf("%s",infix);
    push(stack,'(');
    strcat(infix,")");
    strcat(infix," ");
    next = nextChar(infix);
    while (next != ' ')
    {
        if (top<0)
        {
            printf("\nInvalid at Top");
            exit(0);
        }
        while (stackPrecedence(stack[top])>inputPrecedence(next))
        {
            temp[0] = pop(stack);
            temp[1] = '\0';
            strcat(polish,temp);
            rank += rankFunction(temp[0]);
            if (rank<1)
            {
                printf("Rank %d",rank);
                exit(0);
            }
        }
        
        if (stackPrecedence(stack[top])!=inputPrecedence(next))
        {
            push(stack,next);
        }
        else
        {
            pop(stack);
        }
        next = nextChar(infix);
    }
    if (rank!=1)
    {
        printf("Invalid at rank end %d",rank);
    }
    else
    {
        printf("\n\tReverse Polish Expression: %s",polish);
    }   
}