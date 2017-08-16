/*
 * printing only unique characters in a string
 * */

#include<iostream>

void hashing(std::string str, int *char_set)
{
    for (int i = 0; i < str.length(); ++i)
    {
        char_set[str[i]]++;
    }
}

void print_string(std::string str, int *char_set)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (char_set[str[i]])
        {
            std::cout<<str[i];
            char_set[str[i]] = 0;
        }
    }
    std::cout<<std::endl;
}

int main()
{
    int char_set[256] = {0};
    std::string str;

    std::getline(std::cin, str);

    hashing(str, char_set);
    print_string(str, char_set);
    return 0;
}

// T.C = O(n)
// S.C = O(1) -> creating hash for only 256 elements
