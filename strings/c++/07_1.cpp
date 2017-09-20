/*
 * find the first non-repeating characters in given string
 * */
#include<iostream>
#include<cstring>

char getFirstNonRepeating(char *str, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int flag = true;
        char c = str[i];
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
                if (c == str[j])
                    flag = false;
        }
        if (flag)
            return c;
    }
    return '\0';
}

int main()
{
    char *str = new char[1000];
    std::cin.getline(str, 1000);// 1000 is the size of input buffer created
    char ch = getFirstNonRepeating(str, strlen(str));
    if (ch != '\0')
        std::cout<<ch<<std::endl;
    else
        std::cout<<"Each character is repeating\n";
    return 0;
}

// time is n^2 and space is constant
