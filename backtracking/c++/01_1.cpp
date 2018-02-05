#include<iostream>
#include<cstring>
#include<set>

int cnt = 0;

void permute_string_helper(std::string str, std::string chosen, std::set<std::string> &seti)
{
    // base case
    if (str.length() == 0)
    {
        cnt++;
        const bool b = seti.find(chosen) != seti.end();
        if (!b)
        {
            std::cout<<chosen<<std::endl;
            seti.insert(chosen);
        }
    }
    else
    {
        for (int i = 0; i < str.length(); ++i)
        {
            // chose
            char c = str[i];
            chosen += c;
            str.erase(i, 1);
            // explore
            permute_string_helper(str, chosen, seti);
            // un-chose
            str.insert(i, 1, c);
            chosen.erase(chosen.length() - 1, 1);
        }
    }
}


void permute_string(std::string str)
{
    std::string chosen = "";
    std::set<std::string> seti;
    permute_string_helper(str, chosen, seti);
    /*
    std::set<std::string>::iterator it;
    for (auto f : seti)
        std::cout<<f;
    */
    std::cout<<"\nlength = "<<seti.size()<<std::endl;
}


int main()
{
    std::string str;
    std::cout<<"\nEnter a string\n";
    std::cin>>str;
    permute_string(str);
    std::cout<<std::endl<<cnt<<std::endl;
}
