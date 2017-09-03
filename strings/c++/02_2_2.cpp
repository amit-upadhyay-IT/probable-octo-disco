#include<iostream>
#include<stdio.h>
#include<string.h>

void removeDup(std::string s, char *ex)
{
    int hash[256] = {0};
    int k = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (hash[s[i]] == 0)
            ex[k++] = s[i];
        hash[s[i]] = 1;
    }
    ex[k] = '\0';
}

int main()
{
    std::string s;
    std::getline(std::cin, s);
    //std::string ss;
    char ss[1000];

    removeDup(s, ss);
    printf("%s\n", ss);
    //std::cout<<ss<<std::endl;
    return 0;
}
