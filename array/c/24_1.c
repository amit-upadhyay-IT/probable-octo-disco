#include<stdio.h>
#include<stdlib.h>

void printMatrix(int **mat, int n)
{
    printf("\nMatrix is : \n");
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
                    printf("%d\t",mat[i][j]);
        printf("\n");
    }
}

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void swap2D(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void reverseRows(int **mat, int n)
{
    int i, j, k;
    for (i = 0; i < n; ++i)
        for (j = 0, k = n-1; j < n/2; ++j, --k)
            swap(mat[i], j, k);
}

void transposeMatrix(int **mat, int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = i; j < n; ++j)
            swap2D(&mat[i][j], &mat[j][i]);
}


int main()
{
    int n, i, j;
    printf("\nEnter n:\n");
    scanf("%d", &n);
    int **mat = malloc(sizeof(int*)*n);
    for (i = 0; i < n; ++i)
        mat[i] = malloc(sizeof(int)*n);

    printf("\nEnter matrix elements : \n");
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &mat[i][j]);

    printMatrix(mat, n);

    reverseRows(mat, n);
    transposeMatrix(mat, n);
    printMatrix(mat, n);
    printf("\n");
    return 0;
}
