#include<iostream>

void make_string_unique(std::string str, int *char_set)
{
    char_set[str[0]] = 1;
    int i = 1, j = 1;

    while (i < str.length())
    {
        while (char_set[str[j]] && j < str.length())
        {
            j++;
        }
        str[i] = str[j];
        char_set[str[j]] = 1;
        i++; j++;
    }

    std::cout<<str<<std::endl;
}

int main()
{
    std::string str;
    int char_set[256] = {0};

    std::getline(std::cin, str);

    std::cout<<str[str.length()+4];
    std::cout<<std::endl;
    make_string_unique(str, char_set);
}
