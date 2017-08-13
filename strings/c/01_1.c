/*
 * get maximum occurred character in a string
 *
 * Approach used: BRUTE FORCE
 * */
#include<stdio.h>
#include<string.h>

char get_max_char(char *str)
{
    char max_char, curr_char;
    int max_cnt = 0, curr_cnt = 0, i, j;
    for (i = 0; i < strlen(str); ++i)
    {
        curr_char = str[i];
        for (j = i+1; j < strlen(str); ++j)
        {
            if (curr_char == str[j])
                curr_cnt++;
        }
        if (max_cnt < curr_cnt)
        {
            max_cnt = curr_cnt;
            max_char = curr_char;
        }
        curr_cnt = 0;
    }
    return max_char;
}

int get_char_cnt(char c, char *str)
{
    int cnt = 0;
    int i, len = strlen(str);
    for (i = 0; i < len; ++i)
    {
        if (c == str[i])
            cnt++;
    }
    return cnt;
}

int main()
{
    char str[1000];
    //fgets(str, 1000, stdin);
    scanf("%[^\n]%*c", str);

    char max_char = get_max_char(str);
    int char_cnt = get_char_cnt(max_char, str);

    printf("\nThe maximum character is %c and it's count is %d\n", max_char, char_cnt);
    return 0;
}

// T.C = O(n^2)
// S.C = O(1)
