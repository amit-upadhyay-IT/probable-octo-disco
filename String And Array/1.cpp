/*
 * Design an algo to determinal if a string has all unique characters or not
 * */
#include<iostream>
bool isUnique(std::string);
int main()
{
    std::string str;
    std::getline(std::cin, str);

    if (isUnique(str))
        std::cout<<"All Unique characters in the entered string "<<std::endl;
    else
        std::cout<<"Repeated characters present in the entered string "<<std::endl;

    return 0;
}
bool isUnique(std::string str)
{
    bool char_set[256] = {false};
    if (str.length() > 128) // considering the character set is ASCII
        return false;
    for(int i = 0; i < str.length(); ++i)
    {
         if (char_set[str[i]]) // the char is already present
             return false;
         char_set[str[i]] = true;
    }
    return true;
}
