#include<iostream>

int main()
{
    std::string s1, s2;
    std::cout<<"Enter first string\n";
    std::getline(std::cin, s1);
    std::cout<<"Enter second string \n";
    std::getline(std::cin, s2);

}

bool isSubstring(std::string s1, std::string s2)
{
    int counter = 0;
    int i, j;
    for (i = 0, j = 0; i < s1.length(); ++i)
    {
         if (s2[j] == s1[i])
         {

         }
    }
}
