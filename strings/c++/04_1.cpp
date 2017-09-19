/*
 * reverse the words in a given sentence
 * */
#include<iostream>
#include<cstring>

void revStr(char *s, int i, int j)
{
    if (i >= j)
        return ;
    for (int k = i; k <= (i+j)/2; ++k)
    {
        std::swap(s[k], s[i+j-k]);
    }
}

void reverseString(char *s, int firstIndex, int lastIndex)
{
    if (firstIndex >= lastIndex)
        return ;
    for (int i = firstIndex, j = lastIndex-1; i <= (lastIndex+firstIndex)/2; ++i, --j)
    {
        std::swap(s[i], s[j]);
    }
}

void reverseWords(char *s, int len)
{
    std::cout<<len<<std::endl;
    int firstNonZero = 0;
    revStr(s, 0, len-1);
    std::cout<<"second check\n"<<s<<std::endl;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == ' ')
        {
            revStr(s, firstNonZero, i-1);
            firstNonZero = i+1;
        }
        else if (s[i+1] == '\0')
            revStr(s, firstNonZero, i);
    }
}

int main()
{
    char* s = new char[1000];
    std::cout<<"\nEnter string\n";
    std::cin.getline(s, 1000);
    reverseWords(s, strlen(s));
    std::cout<<s<<std::endl;
    return 0;
}

// Time : O(n^2)
// space is constant
