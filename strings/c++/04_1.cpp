/*
 * reverse the words in a given sentence
 * */
#include<iostream>
#include<cstring>

void reverseString(char *s, int firstIndex, int lastIndex)
{
    for (int i = firstIndex; i < lastIndex/2; ++i)
    {
        std::swap(s[firstIndex], s[lastIndex]);
    }
}

void reverseWords(char *s, int len)
{
//    std::cout<<"first check\n"<<s<<std::endl;
    int firstNonZero = 0;
    reverseString(s, 0, len);
//    std::cout<<"second check\n"<<s<<std::endl;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == ' ')
        {
            reverseString(s, firstNonZero, i);
            firstNonZero = i+1;
        }
    }
}

int main()
{
    char* s = new char[1000];
    std::cout<<"\nEnter string\n";
    std::cin.getline(s, sizeof(1000));
  //  reverseWords(s, strlen(s));
    std::cout<<s<<std::endl;
    return 0;
}
