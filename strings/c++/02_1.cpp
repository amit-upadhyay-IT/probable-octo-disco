/*
 * print unique characters in a string
 * read char by char in string and insert them into an array
 * before inserting them check if they are already present in that array
 * if they are then don't insert otherwise insert.
 * using hashmap would be even better
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
    char unique_set[256] = {'\0'};//  initializing them with null is helpful because we don't need to take care for making the last character as null

    std::getline(std::cin, str);

    check_unique(str, unique_set);
    print_unique_arr(unique_set);
    return 0;
}

// T.C = O(n)
// S.C = O(n)
