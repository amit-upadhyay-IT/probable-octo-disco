#include<iostream>
#include<stdio.h>
#include<string.h>

std::string* removeDup(std::string s)
{
    int hash[256] = {0};
    int k = 0;
    std::string *ex =  new std::string();
    for (int i = 0; i < s.size(); ++i)
    {
        if (hash[s[i]] == 0)
        {
            ex.push_back(s[i]);// = s[i];
            //ex[k++] = s[i];
            //std::cout<<ex[k-1];
        }
    hash[s[i]] = 1;
    std::cout<<ex<<std::endl;
    }
    std::cout<<ex<<std::endl;
    return ex;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);
    std::string *ss;

    ss = removeDup(s);
    std::cout<<ss<<std::endl;
    return 0;
}
