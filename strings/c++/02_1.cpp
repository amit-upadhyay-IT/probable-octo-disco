/*
 * print unique characters in a string
 * */
#include<iostream>
#include<cstring>

bool search_in_arr(char *unique_set, char c)
{
    for (int i = 0; i < strlen(unique_set); ++i)
    {
        if (unique_set[i] == c)
            return true;
    }
    return false;
}

void insert_in_set(char *unique_set, char ch)
{
    int len = strlen(unique_set);
    unique_set[len] = ch;
}

int check_unique(std::string str, char *unique_set)
{
    for (int i = 0; i< str.length(); ++i)
    {
        if (!search_in_arr(unique_set, str[i]))
        {
            insert_in_set(unique_set, str[i]);
        }
    }
}

void print_unique_arr(char * unique_set)
{
    for (int i = 0; i < strlen(unique_set); ++i)
    {
        std::cout<<unique_set[i];
    }
    std::cout<<std::endl;
}

int main()
{
    std::string str;
    char unique_set[256] = {'\0'};

    std::getline(std::cin, str);

    check_unique(str, unique_set);
    print_unique_arr(unique_set);
    return 0;
}

// T.C = O(n)
// S.C = O(n)
