/*
 * find two repeating elements in a given array
 * approach 3
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long getArraySum(int *arr, int n)
{
    int sum = 0, i;
    for (i = 0; i < n; ++i)
        sum = sum + arr[i];
    return sum;
}

long long getArrayMult(int *arr, int n)
{
    long long mul = 1, i;
    for (i = 0; i < n; ++i)
    {
        if (arr[i] != 0)
            mul = mul * arr[i];
    }
    return mul;
}

int fact(int n)
{
    if (n == 1)
        return 1;
    return (n)*fact(n-1);
}

int main()
{
    int arr[] = {1, 4, 5, 3, 2, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]) - 2;// because we have n+2 elements in array

    int arraySum = getArraySum(arr, n+2);
    int naturalSum = (n*(n+1))/2;
    int twoRepSum = arraySum - naturalSum;

    int arrayMul = getArrayMult(arr, n+2);
    int naturalMul = fact(n);
    int twoRepProd = arrayMul/naturalMul;

    int twoRepDif = sqrt(pow(twoRepSum, 2) - 4*twoRepProd);

    int firstNum = (twoRepSum + twoRepDif)/2;
    int secondNum = twoRepSum - firstNum;

//    printf("arraySum = %d\n naturalSum = %d\n twoRepSum = %d\n arrayMul = %d\n naturalMul = %d\n twoRepProd = %d\n twoRepDif = %d\n",\
            arraySum, naturalSum, twoRepSum, arrayMul, naturalMul, twoRepProd, twoRepDif);

    printf("First Num = %d, Second Num = %d\n", firstNum, secondNum);

    printf("\n");
    return 0;
}

// time is o(n), but this is not preferable as multiplication of large number
// may be time consuming, also for large number of elements calculating
// factorial is difficult
// sometimes we may also not be able to store multiplication result into
// premetive data type
