/*
check if one string is rotation of other string using only one call to isSubstring() method.
*/

#include<iostream>

bool isSubstring(std::string, std::string);
bool isRotation(std::string, std::string);

int main()
{
    std::string s1, s2;
    std::cout<<"Enter first string\n";
    std::getline(std::cin, s1);
    std::cout<<"Enter second string \n";
    std::getline(std::cin, s2);
    isRotation(s1, s2)?std::cout<<"YES":std::cout<<"NO";
}

bool isRotation(std::string s1, std::string s2)
{
    std::string s1s1 = s1+s1;
    return (isSubstring(s1s1, s2));
}

bool isSubstring(std::string s1, std::string s2)
{
    int counter = 0;
    int i, j;
    for (i = 0, j = 0; i < s1.length() && j < s2.length(); ++i)
    {
         if (s2[j] == s1[i])
         {
             j++;
             counter++;
         }
         else
         {
             j = 0;
             counter = 0;
         }
    }
    return (counter == s2.length());
}
