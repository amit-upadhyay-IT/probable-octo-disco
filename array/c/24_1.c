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
    printf("\n");
    return 0;
}
