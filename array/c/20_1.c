#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[] = {1, 0, 2, 0, 1, 0, 3, 1, 0, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d", size);

    printf("\n");
    return 0;
}
