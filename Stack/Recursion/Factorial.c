#include<stdio.h>

/*
 *  int factorial(int n)
 *  --------------------------------------
 *      Returns factorial of n.
 *  Params:
 *          n: Number whose factorial is to be found.
 */
int factorial(int n)
{
    if(n==1)
    {
        return(1);
    }
    return n*factorial(n-1);
}

void main(int argc, char const *argv[])
{
    printf("Factorial of 3 is %d",factorial(3));
}
