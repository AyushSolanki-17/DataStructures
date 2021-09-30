#include<stdio.h>
/*
 *  TowerOfHanoi(int n,char source[],char destination[],char intermediate[])
 *  --------------------------------------
 *      Solves Tower of hanoi problem.
 *  Params:
 *          n: Number of disks.
 *          source[]: Name of Source rod.
 *          destination[]: Name of Destination rod.
 *          intermediate[]: Name of Intermediate rod.
 */
void TowerOfHanoi(int n,char source[],char destination[],char intermediate[])
{
    if(n==1)
    {
        printf("\nMove Disk %d from %s to %s",n,source,destination);
    }
    else
    {
        TowerOfHanoi(n-1,source,intermediate,destination);
        printf("\nMove Disk %d from %s to %s",n,source,destination);
        TowerOfHanoi(n-1,intermediate,destination,source);
    }
}
int main(int argc, char const *argv[])
{
    TowerOfHanoi(4,"Source","Destination","Intermediate");
    return 0;
}
