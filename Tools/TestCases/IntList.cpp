#include <IntList.h>

#include <string>

namespace testCases
{

std::vector<int> parseIntList(std::string_view text)
{
    std::vector<int> list;
    for (std::size_t pos = 0; pos != std::string_view::npos;)
    {
        list.push_back(std::stoi(std::string{text.substr(pos)}));
        pos = text.find_first_not_of("0123456789", pos);
        if (pos != std::string_view::npos)
        {
            ++pos;
        }
    }
    return list;
}

}    // namespace testCases
