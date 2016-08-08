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

#include<iostream>
// always try to manipulate the string from the end
void reverseString(char* str)
{
    // we can move to the end pointer of the char string then we can start swapping
    // characters from the start of the string with the end of string until the pointers
    // meet in middle.

    char *end = str;
    char temp;
    if(str)
    {
        while (*end)// moving to the end of the string
            ++end;
        --end;// set one char back, since last char is null

        // now swapping characters

        while (str < end)
        {
            temp = *str;
            *str++ = *end;
            *end-- = temp;
        }
    }

}
int main()
{
    char str[200];
    std::cin.getline(str, sizeof(str));
    reverseString(str);
    std::cout<<"Reverse is : "<<str<<std::endl;
    return 0;
}
