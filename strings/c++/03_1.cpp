/*
 * check if one string is rotation of other or not.
 * */
#include<iostream>
#include<string.h>

char* rotateOnce(char *s, int l)
{
    int i;
    char temp = s[0];
    for (i = 0; i < l-1; ++i)
    {
        s[i] = s[i+1];
    }
    s[i] = temp;
    return s;
}

bool checkRotation(char *s1, char *s2, int l1, int l2)
{
    if (l1 != l2)
        return false;
    for (int i = 0; i < l1; ++i)
    {
        if (strcmp(rotateOnce(s1, l1), s2) == 0)// match found
            return true;
    }
    return false;
}

int main ()
{
    char *s1 = new char[100];
    char *s2 = new char[100];
    std::cout<<"Enter string 1:\n";
    std::cin.getline(s1, sizeof(s1));
    std::cout<<"Enter string 2:\n";
    std::cin.getline(s2, sizeof(s2));
    if (checkRotation(s1, s2, strlen(s1), strlen(s2)))
        std::cout<<"YES\n";
    else
        std::cout<<"NO\n";
    return 0;
}
