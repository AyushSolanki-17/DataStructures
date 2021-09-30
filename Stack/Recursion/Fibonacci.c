#include<stdio.h>

/*
 *  factorial(int n)
 *  --------------------------------------
 *      Prints fibonacci series till number n.
 *  Params:
 *          n: Number till fibonacci series is to be printed.
 */
void fibonacci(int n)
{
    static int n1=0,n2=1,n3;
    if (n>0)
    {
        n3 = n1+n2;
        if(n1==0 && n2==1)
        {
            printf(" %d %d",n1,n2);
        }
        printf(" %d",n3);
        n1 = n2;
        n2 = n3;
        fibonacci(n-1);
    }
    
}
void main()
{
    fibonacci(10);
}
