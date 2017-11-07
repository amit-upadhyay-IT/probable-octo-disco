#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int matchSubstr(char *str1, char *str2, int first, int last)
{
    int flag = 1;
    int i, j;
    for (i = first, j = 0; i <= last; ++i, j++)
    {
        if (str1[i] != str2[j])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    char str1[] = "abbabbaaabba";
    char str2[] = "abba";

    int n = strlen(str1);
    int m = strlen(str2);

    int cnt = 0, i;
    int cf;

    for (i = 0; i <= n-m; ++i)
    {
        cf = matchSubstr(str1, str2, i, i+m);
        if (cf)
        {
            cnt++;
            printf("\nThe first occurrence is at position %d\n", i);
        }
    }
    printf("\nThus there are overall %d occurrence of %s in %s\n", cnt, str2, str2);

    return 0;
}
