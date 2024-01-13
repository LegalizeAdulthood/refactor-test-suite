#include <iostream>
#include <string>

int main()
{
    while (std::cin)
    {
        std::string line;
        std::getline(std::cin, line);
        if (line.empty())
        {
            continue;
        }
        auto nonSpace = line.find_first_not_of(" \t");
        if (nonSpace == std::string::npos)
        {
            continue;
        }
        if (line.substr(nonSpace, 2) == "//")
        {
            continue;
        }
        std::cout << line << '\n';
    }
    return 0;
}
