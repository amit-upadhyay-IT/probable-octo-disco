/*
perform basic string compression using the counts of repeated characters.
*/

#include<iostream>
#include<cstring>
std::string compressBad(std::string str)
{
    std::string mystr = "";
    int count = 1;
    char last = str[0];
    for (int i = 0; i < str.length();++i)
    {
        if(str[i] == last)
            count++;
        else
        {
            std::string lastS(1, last);
            std::string countS = std::to_string(count);
            mystr.append(lastS);
            mystr.append(countS);
            //mystr = mystr + last + count;
            count = 1;
            last = str[i];
        }
    }
    std::string lastS = last+"";
    std::string countS = std::to_string(count);
    mystr.append(lastS);
    mystr.append(countS);
    return mystr;        
    //return mystr+last+count;
}
int main()
{
    std::string str;
    std::getline(std::cin, str);
    std::string str2 = compressBad(str);
    std::cout<<str2;
    /*if (str.length() < str2.length())
        std::cout<<str;
    else
        std::cout<<str2;*/
    std::cout<<std::endl;
    return 0;
}
