#include<stdio.h>
#include<stdlib.h>
#define ROWS 3;
#define COLUMNS 4;

int **createMatrix(int rows, int columns)
{
    int **matrix;
    matrix = (int **)malloc(sizeof(int)*rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int)*columns);
    }
    return matrix;
}
void addMatrix(int rows, int columns, int **m1,int **m2, int **m3)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            m3[i][j]=m1[i][j]+m2[i][j];
        }   
    }
}
void subMatrix(int rows, int columns, int **m1,int **m2, int **m3)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            m3[i][j]=m1[i][j]-m2[i][j];
        }   
    }
}

void printMatrix(int rows,int columns, int **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        printf("\n");
        for (int j = 0; j < columns; j++)
        {
            printf(" %d ",matrix[i][j]);
        }   
    }
}
void main()
{
    int rows,columns;
    int **m1,**m2,**m3;
    printf("\nEnter number of rows of matrix: ");
    scanf("%d",&rows);
    printf("\nEnter number of columns of matrix: ");
    scanf("%d",&columns);
    m1= createMatrix(rows,columns);
    m2= createMatrix(rows,columns);
    printf("\nEnter Elements of Matrix 1 : ");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("\nEnter Value for element(%d,%d) : ",i,j);
            scanf("%d",&m1[i][j]);
        }
    }
    printf("\nEnter Elements of Matrix 2 : ");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("\nEnter Value for element(%d,%d) : ",i,j);
            scanf("%d",&m2[i][j]);
        }
    }
    int choice;
    printf("\nPress\t1) For Matrix Addtion\t2) For Matrix Subtraction");
    scanf("%d",&choice);
    m3=createMatrix(rows,columns);
    switch (choice)
    {
        case 1:
            addMatrix(rows,columns,m1,m2,m3);
            break;
        case 2:
            subMatrix(rows,columns,m1,m2,m3);
            break;
    }
    printMatrix(rows,columns,m3);

}