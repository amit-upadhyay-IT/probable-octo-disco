/*
 * finding product array
 * */
#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int * getLeftArray(int *arr, int n)
{
    int *left_product = malloc(sizeof (int) * n);
    int p = 1, i;
    for (i = 0; i < n; ++i)
    {
        p = p * arr[i];
        left_product[i] = p;
    }
    return left_product;
}

int * getRightArray(int *arr, int n)
{
    int *rightProduct = malloc(sizeof(int) * n);
    int p = 1, i;
    for (i = n-1; i >= 0; --i)
    {
        p = p * arr[i];
        rightProduct[i] = p;
    }
    return rightProduct;
}

int *getProductArray(int *leftProduct, int *rightProduct, int n)
{
    int *productArray = malloc(sizeof(int) * n);
    int i;
    for (i = 0; i < n; ++i)
    {
        if (i == 0)
            productArray[i] = rightProduct[i+1];
        else if (i == n-1)
            productArray[i] = leftProduct[i-1];
        else
            productArray[i] = leftProduct[i-1] * rightProduct[i+1];
    }
    return productArray;
}

int main()
{
    int i, *arr, n;
    printf("\nEnter n\n");
    scanf("%d", &n);
    arr = malloc(sizeof(int)*n);
    printf("\nEnter elements\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int *leftProduct = getLeftArray(arr, n);
    int *rightProduct = getRightArray(arr, n);

    int *productArray = getProductArray(leftProduct, rightProduct, n);
    printArray(productArray, n);
    return 0;
}
// T.C = O(n)
// S.C = O(n)
