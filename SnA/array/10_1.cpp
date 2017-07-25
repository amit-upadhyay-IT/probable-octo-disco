#include<iostream>
#include<fstream>
#include<stdlib.h>

void print_array(int *arr)
{
    int i;
    for (i = 0; arr[i] != 2; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int binary_search_first(int *arr, int start, int end, int x)
{
    int mid, result = -1;
    while (start <  end)
    {
         mid = (start + end)/2;
         if (arr[mid] == x)
         {
             end = mid - 1;
             result = mid;
         }
         else if (x < arr[mid])
             end = mid - 1;
         else
             start = mid + 1;
    }
    return result;
}

int get_first_1_occ(int *arr)
{
    int flag = 0, i = 1;
    try
    {
        while (1)
        {
            if (arr[i] == 1)
            {
                flag = 1;
                break;
            }
            i *= 2;
        }
        if (flag)
            return binary_search_first(arr, i/2, i, 1);
    }
    catch(const char* msg)
    {
        std::cerr<<msg<<std::endl;
    }
    return -1;
}

int main()
{
    char content;
    int *arr = (int *)malloc(100000*sizeof(int));
    std::ifstream fin;
    fin.open("zero_one");
    int k = 0;
    while (fin>>content)
        arr[k++] = content - '0';
    fin.close();
    //print_array(arr);
    int ret_val = get_first_1_occ(arr);
    if (ret_val != -1)
        printf("\n%d is the index of first occurrence of one\n");
    else
        printf("\nIt seems there is no occurrence of one\n");
    return 0;
}
