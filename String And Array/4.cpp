/*
program to replace all spaces in a string with '%20'. use inplace algo.
*/
#include<iostream>
#include<cstring>
int countSpaceLength(char *str, int len)
{
    int sCount = 0;
    for(int i = 0; i < len; ++i)
    {
        if(str[i] == ' ')
            sCount++;
    }
    return sCount;
}
int main()
{
    char str[500];
    std::cin.getline(str, sizeof(str));
    std::cout<<std::endl;
    int sLen = strlen(str);
    int sCount = countSpaceLength(str, sLen);
    int newStringLen = sLen + (2*sCount);
    str[newStringLen] = '\0';
    for(int i = sLen-1; i >= 0; --i)
    {
         if(str[i] == ' ')
         {
            str[newStringLen - 1] = '0';
            str[newStringLen - 2] = '2';
            str[newStringLen - 3] = '%';
            newStringLen -= 3;
         }
         else
         {
            str[newStringLen - 1] = str[i];
            newStringLen -= 1;
         }
    }
    std::cout<<"New String Formed "<<std::endl<<str<<std::endl;
    return 0;
}
