#include<iostream>
#include<fstream>

void reverse_lines(std::ifstream& input)
{
    std::string line;
    if (std::getline(input, line))
    {
        // there is a line
        reverse_lines(input);
        std::cout<<line<<std::endl;  // backtracking
    }
}

int main()
{
    std::string path = "./../python/textfile.md";
    std::ifstream reading_file;
    reading_file.open(path);
    reverse_lines(reading_file);
}
