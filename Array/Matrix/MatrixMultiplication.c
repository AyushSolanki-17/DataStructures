#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int rows, int columns)
{
    int **matrix;
    matrix = (int **)malloc(sizeof(int) * rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * columns);
    }
    return matrix;
}
void matrixMultiplication(int rows, int columns, int **m1, int **m2, int **m3)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            m3[i][j]=0;
            for (int k = 0; k < columns; k++)
            {
                m3[i][j]+=m1[i][k]*m2[k][j];
            }   
        }
    }
}

void printMatrix(int rows, int columns, int **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        printf("\n");
        for (int j = 0; j < columns; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
    }
}
void main()
{
    int matrix1Rows, matrix1columns, matrix2Rows, matrix2columns;
    int **m1, **m2, **m3;
    printf("\nEnter number of rows of matrix 1: ");
    scanf("%d", &matrix1Rows);
    printf("\nEnter number of columns of matrix 1: ");
    scanf("%d", &matrix1columns);
    printf("\nEnter number of rows of matrix 2: ");
    scanf("%d", &matrix2Rows);
    printf("\nEnter number of columns of matrix 2: ");
    scanf("%d", &matrix2columns);
    if (matrix1columns == matrix2Rows)
    {
        m1 = createMatrix(matrix1Rows, matrix1columns);
        m2 = createMatrix(matrix2Rows, matrix2columns);
        m3 = createMatrix(matrix1Rows, matrix2columns);
        printf("\nEnter Elements of Matrix 1 : ");
        for (int i = 0; i < matrix1Rows; i++)
        {
            for (int j = 0; j < matrix1columns; j++)
            {
                printf("\nEnter Value for element(%d,%d) : ", i, j);
                scanf("%d", &m1[i][j]);
            }
        }
        printf("\nEnter Elements of Matrix 2 : ");
        for (int i = 0; i < matrix2Rows; i++)
        {
            for (int j = 0; j < matrix2columns; j++)
            {
                printf("\nEnter Value for element(%d,%d) : ", i, j);
                scanf("%d", &m2[i][j]);
            }
        }
        matrixMultiplication(matrix1columns,matrix2Rows,m1,m2,m3);
        printMatrix(matrix1columns,matrix2Rows,m3);

    }
}