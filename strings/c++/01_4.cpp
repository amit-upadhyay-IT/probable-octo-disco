#include<iostream>


int make_hash_table(int *char_set, std::string str)
{
    int max_cnt = 0;
    int i = 0;
    while (i < str.length())
    {
        char_set[str[i]]++;

        if (max_cnt < char_set[str[i]])
            max_cnt = char_set[str[i]];
        i++;
    }
    return max_cnt;
}

int main()
{
    std::string str;
    int char_set[256] = {0};
    std::getline(std::cin, str);
    //std::cout<<std::endl<<str<<std::endl;
    int max_cnt = make_hash_table(char_set, str);
    std::cout<<std::endl<<"The maximum count is "<<max_cnt<<std::endl;
    return 0;
}
