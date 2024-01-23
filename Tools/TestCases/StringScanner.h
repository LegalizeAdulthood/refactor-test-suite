#pragma once

#include <string>
#include <string_view>

namespace testCases
{

template <typename String>
class StringScanner
{
public:
    using Position = typename String::size_type;

    StringScanner(const String &text) :
        m_text(text)
    {
    }

    StringScanner &find(const std::string_view &text)
    {
        if (m_pos != String::npos)
        {
            m_pos = m_text.find(text, m_pos);
        }
        return *this;
    }
    StringScanner &find_first_of(char ch)
    {
        if (m_pos != String::npos)
        {
            m_pos = m_text.find_first_of(ch, m_pos);
        }
        return *this;
    }
    StringScanner &find_first_not_of(char ch)
    {
        if (m_pos != String::npos)
        {
            m_pos = m_text.find_first_not_of(ch, m_pos);
        }
        return *this;
    }

    Position getPos() const
    {
        return m_pos;
    }

private:
    const String &m_text;
    Position m_pos{};
};

}    // namespace testCases
