#include<iostream>
#include<cstring>

void make_string_unique(char *str, int *char_set)
{
    char_set[str[0]] = 1;
    int i = 1, j = 1;

    while (i < strlen(str))
    {
        while (char_set[str[j]] && j < strlen(str))
        {
            j++;
        }
        str[i] = str[j];
        char_set[str[j]] = 1;
        i++; j++;
    }
    str[i] = '\0';

    std::cout<<str<<std::endl;
}

int main()
{
    char str[500];
    int char_set[256] = {0};

    std::cin.getline(str, sizeof(str));
    //std::getline(std::cin, str);

    //std::cout<<str[str.length()+4];
    std::cout<<std::endl;
    make_string_unique(str, char_set);
}
