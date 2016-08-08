/*
Reverse a null terminated string.
*/

/*
// for a non null terminated string.
#include<iostream>
void reverseString(std::string str)
{
    int len = str.length();
    for(int i = 0; i < len/2; ++i)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }

    std::cout<<"Reverse of String is : "<<std::endl<<str<<std::endl;
}
int main()
{
    std::string str;
    std::getline(std::cin, str);
    reverseString(str);
    return 0;
}
*/
