/*
check if one string is permutation of other or not.
*/
#include<iostream>
#include<algorithm>// for std::sort()
bool isPermutation(std::string str1, std::string str2)
{
    if(str1.length() != str2.length())
        return false;
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    if(str1 == str2)
        return true;
    else
        return false;
}
int main()
{
    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    if (isPermutation(str1, str2))
        std::cout<<"Permutation";
    else
        std::cout<<"Not Permutation";
    std::cout<<std::endl;
    return 0;
}
